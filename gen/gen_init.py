#!/usr/bin/env python3

import os
import re
from string import Template
import sys

sys.path.append(os.path.join(os.path.dirname(__file__), "..", "mpiabi"))

from mpi_constants import constants
from mpi_functions import functions
from mpi_constants_fortran import constants_fortran
from mpi_functions_fortran import functions_fortran

support_profiling = True
have_weak_symbols = False

with open("src/mpi_init_constants_c.h", "w") as file:
    file.write("// Initialize C MPI constants")
    file.write("\n")
    for (tp, nm) in constants:
        subs = {'mpi_tp': tp,
                'mpi_nm': nm,
                'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm)}
        file.write(Template("$mpi_nm = *($mpi_tp const *)get_symbol(handle, \"$abi_nm\");\n").substitute(subs))

with open("src/mpi_init_functions_c.h", "w") as file:
    file.write("// Initialize C MPI functions\n")
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
        file.write(Template("$abi_nm = get_symbol(handle, \"$abi_nm\");\n").substitute(subs))

with open("src/mpi_init_constants_fortran.h", "w") as file:
    file.write("// Initialize Fortran MPI constants\n")
    file.write("\n")
    for (tp, nm) in constants_fortran:
        subs = {'abi_tp': re.sub(r"MPI(X?)_\w+", r"MPI\1ABI_Fint", tp),
                'mpi_nm': nm.lower() + "_",
                'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm).lower() + "_"}
        file.write(Template("$mpi_nm = *($abi_tp const*)get_symbol(handle, \"$abi_nm\");\n").substitute(subs))

with open("src/mpi_init_functions_fortran.h", "w") as file:
    file.write("// Initialize Fortran MPI functions\n")
    file.write("\n")
    for (tp, nm, args) in functions_fortran:
        subs = {'abi_tp': re.sub(r"MPI(X?)_\w+", r"MPI\1ABI_Fint", tp),
                'mpi_nm': nm.lower() + "_",
                'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm).lower() + "_"}
        file.write(Template("$abi_nm = get_symbol(handle, \"$abi_nm\");\n").substitute(subs))
