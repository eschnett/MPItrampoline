#!/usr/bin/env python3

import re
from string import Template

from mpi_constants import constants
from mpi_functions import functions
from mpi_constants_fortran import constants_fortran
from mpi_functions_fortran import functions_fortran

print()
print("  // C constants")
for (tp, nm) in constants:
    subs = {'mpi_tp': tp,
            'mpi_nm': nm,
            'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm)}
    print(Template("  $mpi_nm = *($mpi_tp const *)get_symbol(handle, \"$abi_nm\");").substitute(subs))

print()
print("  // C functions")
for (tp, nm, args, flags) in functions:
    subs = {'mpi_tp': tp,
            'abi_tp': re.sub(r"MPI(X?)_", r"MPI\1ABI_", tp),
            'mpi_nm': nm,
            'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm)}
    for (i, (atp, anm)) in enumerate(args):
        subs['mpi_atp{0}'.format(i)] = atp
        subs['abi_atp{0}'.format(i)] = re.sub(r"MPI(X?)_", r"MPI\1ABI_", atp)
        subs['anm{0}'.format(i)] = anm
    print(Template("  $abi_nm = get_symbol(handle, \"$abi_nm\");").substitute(subs))

print()
print("  // Fortran constants")
for (tp, nm) in constants_fortran:
    subs = {'abi_tp': re.sub(r"MPI(X?)_\w+", r"MPI\1ABI_Fint", tp),
            'mpi_nm': nm.lower() + "_",
            'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm).lower() + "_"}
    print(Template("  $mpi_nm = *($abi_tp const*)get_symbol(handle, \"$abi_nm\");").substitute(subs))

print()
print("  // Fortran functions")
for (tp, nm, args) in functions_fortran:
    subs = {'abi_tp': re.sub(r"MPI(X?)_\w+", r"MPI\1ABI_Fint", tp),
            'mpi_nm': nm.lower() + "_",
            'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm).lower() + "_"}
    print(Template("  $abi_nm = get_symbol(handle, \"$abi_nm\");").substitute(subs))
