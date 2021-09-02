#!/usr/bin/env python3

import re
from string import Template

from mpi_constants import constants
from mpi_functions import functions

print()
print("// C constants")
for (tp, nm) in constants:
    subs = {'mpi_tp': tp,
            'mpi_nm': nm}
    print(Template("extern $mpi_tp MPITRAMPOLINE_CONST $mpi_nm;").substitute(subs))

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
    tmpl.append("extern $abi_tp (* MPITRAMPOLINE_CONST $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(");")
    tmpl.append("inline $mpi_tp $mpi_nm(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") {")
    rcast = "($mpi_tp)".format(i) if re.search(r"MPI_", tp) else ""
    tmpl.append("  return "+rcast+"(*$abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        acast = "($abi_atp{0})".format(i) if re.search(r"MPI_", atp) else ""
        tmpl.append("    "+acast+"$anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append("  );")
    tmpl.append("}")
    print(Template("\n".join(tmpl)).substitute(subs))
