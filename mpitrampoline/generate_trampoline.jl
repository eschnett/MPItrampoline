include("../mpiabi/mpiabi_functions_fortran.jl")

function fortran(type::Typ, dim::Union{Nothing,Symbol}; hide_comm_size=false)
    if dim === nothing
        type === address && return "integer(MPI_ADDRESS_KIND)", ""
        type === buffer && return "integer", "(*)"
        type === buffer_inplace && return "integer", "(*)"
        type === count && return "integer(MPI_COUNT_KIND)", ""
        type === character && return "character(*)", ""
        type === double_precision && return "double precision", ""
        type === external && return "external", ""
        type === logical && return "logical", ""
        type === offset && return "integer(MPI_OFFSET_KIND)", ""
        type === status && return "integer", "(MPI_STATUS_SIZE)"
        @assert type !== argv
        @assert type !== argvs
        @assert type !== void
        @assert type !== weight
        return "integer", ""
    else
        dim = hide_comm_size && dim === :comm_size ? "*" : dim
        type === address && return "integer(MPI_ADDRESS_KIND)", "($dim)"
        type === argv && return "character(*)", "($dim)"
        type === argvs && return "character(*)", "(count, $dim)" # we cheat to know it's `count`
        @assert !(type === buffer)
        @assert !(type === buffer_inplace)
        type === character && return "character(*)", "($dim)"
        type === count && return "integer(MPI_COUNT_KIND)", "($dim)"
        type === double_precision && return "double precision", "($dim)"
        @assert !(type === external)
        type === logical && return "logical", "($dim)"
        type === offset && return "integer(MPI_OFFSET_KIND)", "($dim)"
        type === status && return "integer", "(MPI_STATUS_SIZE, $dim)"
        @assert type !== void
        return "integer", "($dim)"
    end
end

function c(type::Typ)
    type === address && return "MPI_Aint ", ""
    type === argv && return "char *", ""
    type === argvs && return "char *", ""
    type === buffer && return "void ", ""
    type === buffer_inplace && return "void ", ""
    type === count && return "MPI_Count ", ""
    type === character && return "char *", ""
    type === double_precision && return "double ", ""
    type === external && return "void (*", ")(void)"
    type === logical && return "MPI_Fint ", ""
    type === offset && return "MPI_Offset ", ""
    type === status && return "MPI_Fint ", "[MPI_F_STATUS_SIZE]"
    type === void && return "void ", ""
    type === weight && return "MPI_Fint ", ""
    return "MPI_Fint ", ""
end

mpi2abi(str) = replace(str, "MPI" => "MPIABI")

function format_line(line::AbstractString; is_cont::Bool=false, has_cont::Bool=false)
    line = " "^5 * (is_cont ? "&" : " ") * line
    if length(line) <= 72
        if has_cont
            line = line * " "^(72 - length(line)) * "&"
        end
    else
        pos = findfirst("::", line)
        @assert !isempty(pos)
        line1 = line[begin:(pos.stop)]
        line1indent = findfirst(!isspace, line1[6:end])
        line2 = " "^5 * "&" * " "^line1indent * line[(pos.stop + 1):end]
        @assert length(line2) <= 72
        line1 = line1 * " "^(72 - length(line1)) * "&"
        if has_cont
            line2 = line2 * " "^(72 - length(line2)) * "&"
        end
        line = line1 * "\n" * line2
    end
    return line
end

function generate_mpif_functions_h(io::IO)
    indent = "   "
    println(io, "!     MPI Fortran function bindings")
    println(io)
    println(io, "!     This file has been generated automatically")
    println(io, "!     by `mpitrampoline/generate_trampoline.jl`.")
    println(io, "!     Do not modify this file, changes will be overwritten.")
    println(io)
    println(io, format_line("interface"))
    println(io)
    for fun in functions
        # Function name
        funtype = fun.result === void ? "subroutine" : "function"
        funresult = fun.result === void ? "" : " result(result)"
        println(io, format_line("$funtype $(fun.name)("; has_cont=true))
        # Function argument names
        for (n, arg) in enumerate(fun.args)
            sep = n == length(fun.args) ? "" : ","
            println(io, format_line("$(indent)$(arg.name)$sep"; is_cont=true, has_cont=true))
        end
        println(io, format_line(")$funresult"; is_cont=true))
        println(io, format_line("$(indent)implicit none"))
        println(io, format_line("$(indent)include \"mpif_constants.h\""))
        # Function argument types
        for arg in fun.args
            type, dim = fortran(arg.type, arg.dim; hide_comm_size=true)
            intent = fortran(arg.intent)
            intent = isempty(intent) || arg.type === external ? "" : ", $intent"
            if arg.type === buffer
                println(io, "!dir\$ $(indent)ignore_tkr(tkr) $(arg.name)")
                println(io, "!gcc\$ $(indent)attributes no_arg_check :: $(arg.name)")
                if arg.intent === out
                    intent = ""
                end
            end
            println(io, format_line("$(indent)$type$intent :: $(arg.name)$dim"))
        end
        if fun.result !== void
            type, dim = fortran(fun.result, nothing)
            println(io, format_line("$(indent)$type :: result$dim"))
        end
        println(io, format_line("end $funtype $(fun.name)"))
        println(io)
    end
    println(io, format_line("end interface"))
    return nothing
end

function generate_mpiabi_function_pointers_fortran_h(io::IO)
    indent = "  "
    println(io, "// MPIABI Fortran function pointers")
    println(io)
    println(io, "// This file has been generated automatically")
    println(io, "// by `mpitrampoline/generate_trampoline.jl`.")
    println(io, "// Do not modify this file, changes will be overwritten.")
    println(io)
    println(io, "#include <mpiabi_types.h>")
    println(io)
    for fun in functions
        # Function name
        type, suffix = c(fun.result)
        @assert isempty(suffix)
        println(io, "extern $(mpi2abi(type))(*$(lowercase(mpi2abi(string(fun.name))))_ptr)(")
        # Function arguments names
        for (n, arg) in enumerate(fun.args)
            sep = n == length(fun.args) ? "" : ","
            type, suffix = c(arg.type)
            if arg.intent === in_
                type = "const $type*"
            else
                type = "$type*"
            end
            println(io, "$(indent)$(mpi2abi(type))$(arg.name)$(mpi2abi(suffix))$sep")
        end
        println(io, ");")
        println(io)
    end
    return nothing
end

function generate_mpiabi_function_pointers_fortran_c(io::IO)
    indent = "  "
    println(io, "// MPIABI Fortran function pointers")
    println(io)
    println(io, "// This file has been generated automatically")
    println(io, "// by `mpitrampoline/generate_trampoline.jl`.")
    println(io, "// Do not modify this file, changes will be overwritten.")
    println(io)
    println(io, "#include \"mpiabi_function_pointers_fortran.h\"")
    println(io)
    for fun in functions
        # Function name
        type, suffix = c(fun.result)
        @assert isempty(suffix)
        println(io, "$(mpi2abi(type))(*$(lowercase(mpi2abi(string(fun.name))))_ptr)(")
        # Function arguments names
        for (n, arg) in enumerate(fun.args)
            sep = n == length(fun.args) ? "" : ","
            type, suffix = c(arg.type)
            if arg.intent === in_
                type = "const $type*"
            else
                type = "$type*"
            end
            println(io, "$(indent)$(mpi2abi(type))$(arg.name)$(mpi2abi(suffix))$sep")
        end
        println(io, ");")
        println(io)
    end
    return nothing
end

function generate_mpiabi_set_function_pointers_fortran_c(io::IO)
    indent = "  "
    println(io, "// MPIABI Set Fortran function pointers")
    println(io)
    println(io, "// This file has been generated automatically")
    println(io, "// by `mpitrampoline/generate_trampoline.jl`.")
    println(io, "// Do not modify this file, changes will be overwritten.")
    println(io)
    for fun in functions
        # Function name
        name = lowercase(mpi2abi(string(fun.name)))
        println(io, "$(name)_ptr = get_symbol(handle, \"$(name)_\");")
    end
    return nothing
end

function generate_mpi_functions_fortran_c(io::IO)
    indent = "  "
    println(io, "// MPI Fortran function wrappers")
    println(io)
    println(io, "// This file has been generated automatically")
    println(io, "// by `mpitrampoline/generate_trampoline.jl`.")
    println(io, "// Do not modify this file, changes will be overwritten.")
    println(io)
    println(io, "#include \"mpi.h\"")
    println(io, "#include \"mpiabi_function_pointers_fortran.h\"")
    println(io)
    for fun in functions
        # Function name
        type, suffix = c(fun.result)
        @assert isempty(suffix)
        println(io, "$type$(lowercase(string(fun.name)))_(")
        # Function arguments names
        for (n, arg) in enumerate(fun.args)
            sep = n == length(fun.args) ? "" : ","
            type, suffix = c(arg.type)
            if arg.intent === in_
                type = "const $type*"
            else
                type = "$type*"
            end
            println(io, "$(indent)$type$(arg.name)$suffix$sep")
        end
        println(io, ") {")
        # Forward call
        println(io, "$(indent)return (*$(lowercase(mpi2abi(string(fun.name))))_ptr)(")
        for (n, arg) in enumerate(fun.args)
            sep = n == length(fun.args) ? "" : ","
            println(io, "$(indent)$(indent)$(arg.name)$sep")
        end
        println(io, "$(indent));")
        println(io, "}")
        println(io)
    end
    return nothing
end

open("mpif_functions.h", "w") do fh
    generate_mpif_functions_h(fh)
    nothing
end
open("mpiabi_function_pointers_fortran.h", "w") do fh
    generate_mpiabi_function_pointers_fortran_h(fh)
    nothing
end
open("mpiabi_function_pointers_fortran.c", "w") do fh
    generate_mpiabi_function_pointers_fortran_c(fh)
    nothing
end
open("mpiabi_set_function_pointers_fortran.c", "w") do fh
    generate_mpiabi_set_function_pointers_fortran_c(fh)
    nothing
end
open("mpi_functions_fortran.c", "w") do fh
    generate_mpi_functions_fortran_c(fh)
    nothing
end

nothing
