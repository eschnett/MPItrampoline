#!/usr/bin/env python3

# import os
import re
from string import Template
import sys

sys.path.append("../mpiabi")

from mpi_constants import constants
from mpi_functions import functions
from mpi_constants_fortran import constants_fortran
from mpi_functions_fortran import functions_fortran

support_profiling = True
have_weak_symbols = False

def wrap(line):
    lines = []
    while len(line) > 72:
        lines.append(line[0:72] + "&")
        line = "     &" + line[72:]
    lines.append(line)
    return "\n".join(lines)

# os.makedirs("include", exist_ok=True)

with open("include/mpi_decl_constants_c.h", "w") as file:
    file.write("// Declare C MPI constants\n")
    file.write("\n")
    for (tp, nm) in constants:
        subs = {'mpi_tp': tp,
                'mpi_nm': nm}
        file.write(Template("extern $mpi_tp MPITRAMPOLINE_CONST $mpi_nm;\n").substitute(subs))

with open("include/mpi_decl_functions_c.h", "w") as file:
    file.write("// Declare C MPI functions\n")
    file.write("\n")
    for (tp, nm, args, flags) in functions:
        subs = {'mpi_tp': tp,
                'abi_tp': re.sub(r"MPI(X?)_", r"MPI\1ABI_", tp),
                'mpi_nm': nm,
                'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm)}
        for (i, (atp, anm)) in enumerate(args):
            subs['mpi_atp{0}'.format(i)] = atp
            subs['abi_atp{0}'.format(i)] = re.sub(r"MPI(X?)_", r"MPI\1ABI_", atp)
            subs['anm{0}'.format(i)] = anm

        tmpl = []
        tmpl.append("extern $abi_tp (* MPITRAMPOLINE_CONST $abi_nm)(")
        for (i, (atp, anm)) in enumerate(args):
            tmpl.append("  $abi_atp{0} $anm{0},".format(i))
        tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
        tmpl.append(");")

        if not support_profiling:

            # We declare the MPI functions inline if we don't have to support the
            # PMPI interface
            tmpl.append("inline $mpi_tp P$mpi_nm(")
            for (i, (atp, anm)) in enumerate(args):
                tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append(") {")
            rcast = "($mpi_tp)".format(i) if re.search(r"MPI(X?)_", tp) else ""
            tmpl.append("  return "+rcast+"(*$abi_nm)(")
            for (i, (atp, anm)) in enumerate(args):
                acast = "($abi_atp{0})".format(i) if re.search(r"MPI(X?)_", atp) else ""
                tmpl.append("    "+acast+"$anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append("  );")
            tmpl.append("}")

        else:

            if have_weak_symbols:
                tmpl.append("#pragma weak $mpi_nm = P$mpi_nm")
            else:
                tmpl.append("$mpi_tp $mpi_nm(")
                for (i, (atp, anm)) in enumerate(args):
                    tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
                tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
                tmpl.append(");")

            tmpl.append("$mpi_tp P$mpi_nm(")
            for (i, (atp, anm)) in enumerate(args):
                tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append(");")

        file.write(Template("\n".join(tmpl)).substitute(subs))
        file.write("\n")

with open("include/mpi_decl_constants_fortran.h", "w") as file:
    file.write("!     Declare Fortran MPI constants\n")
    file.write("\n")
    for (tp, nm) in constants_fortran:
        subs = {'mpi_nm': nm}
        tmpl = []

        tmpl.append("      integer $mpi_nm")
        tmpl.append("      common /$mpi_nm/ $mpi_nm")

        file.write("\n".join(map(lambda line: wrap(Template(line).substitute(subs)), tmpl)))
        file.write("\n")

with open("include/mpi_decl_functions_fortran.h", "w") as file:
    file.write("!     Declare Fortran MPI functions\n")
    file.write("\n")
    for (tp, nm, args) in functions_fortran:
        subs = {'mpi_nm': nm}
        tmpl = []

        tmpl.append("      external $mpi_nm")
        if tp != "void":
            if tp == "double":
                tmpl.append("      double precision $mpi_nm")
            elif tp == "MPI_Aint":
                tmpl.append("      integer(MPI_ADDRESS_KIND) $mpi_nm")
            else:
                assert False

        file.write("\n".join(map(lambda line: wrap(Template(line).substitute(subs)), tmpl)))
        file.write("\n")
