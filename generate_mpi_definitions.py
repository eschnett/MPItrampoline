#!/usr/bin/env python3

import re
from string import Template

from mpi_constants import constants
from mpi_functions import functions
from mpi_constants_fortran import constants_fortran
from mpi_functions_fortran import functions_fortran

print()
print("// C constants")
for (tp, nm) in constants:
    subs = {'mpi_tp': tp,
            'mpi_nm': nm}
    print(Template("$mpi_tp $mpi_nm;").substitute(subs))

print()
print("// C functions")
for (tp, nm, args, flags) in functions:
    subs = {'mpi_tp': tp,
            'abi_tp': re.sub(r"MPI_", "MPIABI_", tp),
            'mpi_nm': nm,
            'abi_nm': re.sub(r"MPI_", "MPIABI_", nm)}
    for (i, (atp, anm)) in enumerate(args):
        subs['mpi_atp{0}'.format(i)] = atp
        subs['abi_atp{0}'.format(i)] = re.sub(r"MPI_", "MPIABI_", atp)
        subs['anm{0}'.format(i)] = anm
    tmpl = []
    tmpl.append("$abi_tp (* $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") = NULL;")
    tmpl.append("extern inline $mpi_tp $mpi_nm(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(");")
    print(Template("\n".join(tmpl)).substitute(subs))

print()
print("// Fortran constants")
for (tp, nm) in constants_fortran:
    subs = {'mpi_tp': re.sub(r"MPI_\w+", "MPIABI_Fint", tp),
            'mpi_nm': nm.lower() + "_"}
    print(Template("$mpi_tp $mpi_nm;").
          substitute(subs))

print()
print("// Fortran functions")
for (tp, nm, args) in functions_fortran:
    subs = {'abi_tp': re.sub(r"MPI_\w+", "MPIABI_Fint", tp),
            'mpi_nm': nm.lower() + "_",
            'abi_nm': re.sub(r"MPI_", "MPIABI_", nm).lower() + "_"}
    for (i, (atp, anm)) in enumerate(args):
        subs['mpi_atp{0}'.format(i)] = re.sub(r"MPI_\w+", "MPIABI_Fint", atp)
        subs['abi_atp{0}'.format(i)] = re.sub(r"MPI_\w+", "MPIABI_Fint", atp)
        subs['anm{0}'.format(i)] = anm
    tmpl = []
    tmpl.append("$abi_tp (* $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") = NULL;")
    tmpl.append("$abi_tp $mpi_nm(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") {")
    tmpl.append("  return (* $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("    $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append("  );")
    tmpl.append("}")
    print(Template("\n".join(tmpl)).substitute(subs))
