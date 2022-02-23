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
            'abi_tp': re.sub(r"MPI(X?)_", r"MPI\1ABI_", tp),
            'mpi_nm': nm,
            'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm)}
    for (i, (atp, anm)) in enumerate(args):
        subs['mpi_atp{0}'.format(i)] = atp
        subs['abi_atp{0}'.format(i)] = re.sub(r"MPI(X?)_", r"MPI\1ABI_", atp)
        subs['anm{0}'.format(i)] = anm
    tmpl = []

    tmpl.append("$abi_tp (* P$abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") = NULL;")

    tmpl.append("$abi_tp (* $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") = NULL;")

    # tmpl.append("extern inline $mpi_tp P$mpi_nm(")
    # for (i, (atp, anm)) in enumerate(args):
    #     tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    # tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    # tmpl.append(");")

    tmpl.append("$mpi_tp P$mpi_nm(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") {")
    rcast = "($mpi_tp)".format(i) if re.search(r"MPI(X?)_", tp) else ""
    tmpl.append("  return "+rcast+"(*P$abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        acast = "($abi_atp{0})".format(i) if re.search(r"MPI(X?)_", atp) else ""
        tmpl.append("    "+acast+"$anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append("  );")
    tmpl.append("}")

    tmpl.append("$mpi_tp $mpi_nm(")
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

    print(Template("\n".join(tmpl)).substitute(subs))

print()
print("// Fortran constants")
for (tp, nm) in constants_fortran:
    subs = {'mpi_tp': re.sub(r"MPI(X?)_\w+", r"MPI\1ABI_Fint", tp),
            'mpi_nm': nm.lower() + "_"}
    print(Template("$mpi_tp $mpi_nm;").
          substitute(subs))

print()
print("// Fortran functions")
for (tp, nm, args) in functions_fortran:
    subs = {'abi_tp': re.sub(r"MPI(X?)_\w+", r"MPIABI_Fint", tp),
            'mpi_nm': nm.lower() + "_",
            'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm).lower() + "_"}
    for (i, (atp, anm)) in enumerate(args):
        subs['mpi_atp{0}'.format(i)] = re.sub(r"MPI(X?)_\w+", r"MPIABI_Fint", atp)
        subs['abi_atp{0}'.format(i)] = re.sub(r"MPI(X?)_\w+", r"MPIABI_Fint", atp)
        subs['anm{0}'.format(i)] = anm
    tmpl = []

    tmpl.append("$abi_tp (* $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") = NULL;")

    tmpl.append("$abi_tp (* p$abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $abi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") = NULL;")

    tmpl.append("$abi_tp $mpi_nm(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") {")
    for (i, (atp, anm)) in enumerate(args):
        if atp == "const MPI_Status *" or atp == "MPI_Status *":
            tmpl.append("  if ($anm{0} == mpi_status_ignore_)".format(i))
            tmpl.append("    $anm{0} = mpiabi_status_ignore_;".format(i))
    tmpl.append("  return (* $abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("    $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append("  );")
    tmpl.append("}")

    tmpl.append("$abi_tp p$mpi_nm(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append(") {")
    for (i, (atp, anm)) in enumerate(args):
        if atp == "const MPI_Status *" or atp == "MPI_Status *":
            tmpl.append("  if ($anm{0} == mpi_status_ignore_)".format(i))
            tmpl.append("    $anm{0} = mpiabi_status_ignore_;".format(i))
    tmpl.append("  return (* p$abi_nm)(")
    for (i, (atp, anm)) in enumerate(args):
        tmpl.append("    $anm{0},".format(i))
    tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
    tmpl.append("  );")
    tmpl.append("}")

    print(Template("\n".join(tmpl)).substitute(subs))
