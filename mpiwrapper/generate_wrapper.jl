include("../mpiabi/mpiabi_functions_fortran.jl")

ishandle(type::Typ) = type in [comm, datatype, errhandler, file, group, info, message, session, op, request, win]
istyped(type::Typ) = type in [errorcode, proc, tag]
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

@enum ArgConversion noconv onthefly inplace withtemp conv_argv conv_argvs conv_buffer conv_status conv_weight
function arg_conversion(arg::Arg)
    arg.type === argv && return conv_argv
    arg.type === argvs && return conv_argvs
    arg.type === buffer_inplace && return conv_buffer
    arg.type === status && return conv_status
    arg.type === weight && return conv_weight
    arg.type in [buffer, character, integer, logical, void] && return noconv
    (ishandle(arg.type) || istyped(arg.type) || arg.type in [address, count, maybe_undefined, offset]) &&
        arg.dim === nothing &&
        arg.intent === in_ &&
        return onthefly
    # We could handle the `arg.dim !== nothing` case in-place, but that is probably less efficient
    (ishandle(arg.type) || istyped(arg.type)) && arg.dim == nothing && return inplace
    return withtemp
end

mpi2abi(str) = replace(str, "MPI" => "MPIABI")

function generate_mpiwrapper_functions_f90(io::IO)
    indent = "   "
    println(io, "! MPI Fortran function wrappers")
    println(io)
    println(io, "! This file has been generated automatically")
    println(io, "! by `mpiwrapper/generate_wrappers.jl`.")
    println(io, "! Do not modify this file, changes will be overwritten.")
    println(io)
    for fun in functions
        # Function name
        funtype = fun.result === void ? "subroutine" : "function"
        funresult = fun.result === void ? "" : " result(result)"
        println(io, mpi2abi("$funtype $(fun.name)( &"))
        # Function argument names
        for (n, arg) in enumerate(fun.args)
            sep = n == length(fun.args) ? "" : ","
            println(io, "$(indent)$(arg.name)$sep &")
        end
        println(io, ")$funresult")
        println(io, "$(indent)use mpiwrapper")
        println(io, "$(indent)implicit none")
        # Function argument types
        for arg in fun.args
            type, dim = fortran(arg.type, arg.dim; hide_comm_size=true)
            intent = fortran(arg.intent)
            intent = isempty(intent) || arg.type === external ? "" : ", $intent"
            # if arg.type === buffer
            #     println(io, "$(indent)!dir\$ ignore_tkr(tkr) $(arg.name)")
            #     println(io, "$(indent)!gcc\$ attributes no_arg_check :: $(arg.name)")
            #     if arg.intent === out
            #         intent = ""
            #     end
            # end
            println(io, mpi2abi("$(indent)$type$intent :: $(arg.name)$dim"))
        end
        if fun.result !== void
            type, dim = fortran(fun.result, nothing)
            println(io, mpi2abi("$(indent)$type :: result$dim"))
        end
        if fun.version > v"0"
            version = 100 * fun.version.major + fun.version.minor
            println(io, "#if MPI_VERSION_NUMBER < $version")
            if fun.version == v"99999"
                println(io, "$(indent)write(0, '(\"The Fortran function $(fun.name) is not available in MPItrampoline\")')")
            else
                println(
                    io,
                    "$(indent)write(0, '(\"The Fortran function $(fun.name) is not available in the wrapped MPI implementation\")')",
                )
            end
            println(io, "$(indent)call MPI_Abort(MPI_COMM_SELF, 1, ierror)")
            println(io, "$(indent)stop")
            println(io, "#else")
        end
        # Declare temporary variables
        need_comm_size = false
        need_loop_index = false
        for arg in fun.args
            if arg_conversion(arg) in [conv_buffer, conv_weight]
                @assert arg.dim !== nothing
                type, dim = fortran(arg.type, arg.dim)
                println(io, "$(indent)integer(MPI_ADDRESS_KIND) :: ptr_$(arg.name)")
                println(io, "$(indent)$type :: wrap_$(arg.name)$dim")
                println(io, "$(indent)pointer(ptr_$(arg.name), wrap_$(arg.name))")
            elseif arg_conversion(arg) === conv_status
                type, dim = fortran(arg.type, arg.dim)
                println(io, "$(indent)integer(MPI_ADDRESS_KIND) :: ptr_$(arg.name)")
                println(io, "$(indent)$type :: wrap_$(arg.name)$dim")
                println(io, "$(indent)pointer(ptr_$(arg.name), wrap_$(arg.name))")
                println(io, "$(indent)$type :: tmp_$(arg.name)$dim")
            elseif arg_conversion(arg) === withtemp
                type, dim = fortran(arg.type, arg.dim)
                if arg.dim === :comm_size
                    println(io, "$(indent)$type, allocatable :: wrap_$(arg.name)(:)")
                    need_comm_size = true
                else
                    println(io, "$(indent)$type :: wrap_$(arg.name)$dim")
                end
                need_loop_index = need_loop_index || arg.dim !== nothing
            end
        end
        if need_comm_size
            println(io, "$(indent)integer :: comm_size")
        end
        if need_loop_index
            println(io, "$(indent)integer :: i")
        end
        # Allocate temporary variables
        if need_comm_size
            println(io, "$(indent)call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)")
            println(io, "$(indent)if (ierror /= MPI_SUCCESS) then")
            println(io, "$(indent)$(indent)ierror = mpi2abi_errorcode(ierror)")
            println(io, "$(indent)$(indent)return")
            println(io, "$(indent)end if")
            for arg in fun.args
                if arg_conversion(arg) === withtemp
                    if arg.dim === :comm_size
                        println(io, "$(indent)allocate(wrap_$(arg.name)(comm_size))")
                    end
                end
            end
        end
        # Copy inputs into temporary variables
        for arg in fun.args
            if arg.intent in [in_, inout, unclear]
                if arg_conversion(arg) in [conv_buffer, conv_weight]
                    @assert arg.dim !== nothing
                    println(io, "$(indent)ptr_$(arg.name) = abi2mpi_$(arg.type)_ptr(loc($(arg.name)))")
                elseif arg_conversion(arg) === conv_status
                    @assert arg.dim === nothing
                    println(io, "$(indent)ptr_$(arg.name) = abi2mpi_status_ptr($(arg.name), tmp_$(arg.name))")
                elseif arg_conversion(arg) === inplace
                    @assert arg.dim === nothing
                    println(io, "$(indent)$(arg.name) = abi2mpi_$(arg.type)($(arg.name))")
                elseif arg_conversion(arg) === withtemp
                    if arg.dim === nothing
                        println(io, "$(indent)wrap_$(arg.name) = abi2mpi_$(arg.type)($(arg.name))")
                    else
                        println(io, "$(indent)do i = 1, $(arg.dim)")
                        println(io, "$(indent)$(indent)wrap_$(arg.name)(i) = abi2mpi_$(arg.type)($(arg.name)(i))")
                        println(io, "$(indent)end do")
                    end
                end
            else
                if arg.type === status
                    if arg.dim === nothing
                        println(io, "$(indent)ptr_$(arg.name) = abi2mpi_status_ptr_uninitialized($(arg.name), tmp_$(arg.name))")
                    else
                        println(
                            io,
                            "$(indent)ptr_$(arg.name) = abi2mpi_statuses_ptr_uninitialized($(arg.name), tmp_$(arg.name), $(arg.dim))",
                        )
                    end
                end
            end
        end
        # Forward call
        call = fun.result === void ? "call " : "result = "
        println(io, "$(indent)$call$(fun.name)( &")
        # Forward call arguments
        for (n, arg) in enumerate(fun.args)
            name = arg.name
            if arg_conversion(arg) in [withtemp, conv_buffer, conv_status, conv_weight]
                name = "wrap_$name"
            end
            if arg_conversion(arg) === onthefly
                name = "abi2mpi_$(arg.type)($name)"
            end
            sep = n == length(fun.args) ? "" : ","
            println(io, "$(indent)$(indent)$name$sep &")
        end
        println(io, "$(indent))")
        # Convert outputs
        for arg in fun.args
            if arg.intent in [out, inout, unclear]
                cond = arg.cond !== nothing ? "if ($(arg.cond)) " : ""
                if arg_conversion(arg) === conv_buffer
                    # no conversion necessary
                    @assert arg.dim === nothing
                elseif arg_conversion(arg) === conv_status
                    if arg.dim === nothing
                        println(io, "$(indent)$(cond)call mpi2abi_status_ptr(wrap_$(arg.name), $(arg.name))")
                    else
                        dim = arg.useddim !== nothing ? arg.useddim : arg.dim
                        println(io, "$(indent)$(cond)call mpi2abi_statuses_ptr(wrap_$(arg.name), $(arg.name), $dim)")
                    end
                elseif arg_conversion(arg) === conv_weight
                    # no conversion necessary
                    @assert arg.dim !== nothing
                elseif arg_conversion(arg) === inplace
                    @assert arg.dim === nothing
                    println(io, "$(indent)$(cond)$(arg.name) = mpi2abi_$(arg.type)($(arg.name))")
                elseif arg_conversion(arg) === withtemp
                    if arg.dim === nothing
                        println(io, "$(indent)$(cond)$(arg.name) = mpi2abi_$(arg.type)(wrap_$(arg.name))")
                    else
                        dim = arg.useddim !== nothing ? arg.useddim : arg.dim
                        println(io, "$(indent)do i = 1, $dim")
                        println(io, "$(indent)$(indent)$(cond)$(arg.name)(i) = mpi2abi_$(arg.type)(wrap_$(arg.name)(i))")
                        println(io, "$(indent)end do")
                    end
                end
            end
        end
        # Deallocate temporary variables
        if need_comm_size
            for arg in fun.args
                if arg_conversion(arg) === withtemp
                    if arg.dim === :comm_size
                        println(io, "$(indent)deallocate(wrap_$(arg.name))")
                    end
                end
            end
        end
        if fun.version > v"0"
            println(io, "#endif")
        end
        println(io, mpi2abi("end $funtype $(fun.name)"))
        println(io)
    end
    return nothing
end

open("mpiwrapper_functions.F90", "w") do fh
    generate_mpiwrapper_functions_f90(fh)
    nothing
end
