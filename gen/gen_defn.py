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
replace_sentinels = True

def generate_fortran_sentinel_checks(args):
    """Generate sentinel replacement code for Fortran wrapper functions.

    Detects Fortran-level sentinel values (Cray pointers from mpif.h) and
    replaces them with the corresponding C-level ABI constants so that
    the underlying MPI wrapper library recognises them.
    """
    checks = []
    for (i, (atp, anm)) in enumerate(args):
        # MPI_IN_PLACE: passed via sendbuf in collective operations
        if anm == "sendbuf" and "void" in atp:
            checks.append("  if ($anm{0} == (const void *)mpiabi_in_place_ptr_)".format(i))
            checks.append("    $anm{0} = MPI_IN_PLACE;".format(i))
        # MPI_STATUS_IGNORE / MPI_STATUSES_IGNORE
        if "MPI_Status" in atp:
            if anm == "status":
                checks.append("  if ($anm{0} == mpiabi_status_ignore_ptr_)".format(i))
                checks.append("    $anm{0} = (void *)MPI_STATUS_IGNORE;".format(i))
            elif anm == "array_of_statuses":
                checks.append("  if ($anm{0} == mpiabi_statuses_ignore_ptr_)".format(i))
                checks.append("    $anm{0} = (void *)MPI_STATUSES_IGNORE;".format(i))
    return checks

with open("src/mpi_defn_constants_c.h", "w") as file:
    file.write("// Define C MPI constants")
    file.write("\n")
    for (tp, nm) in constants:
        subs = {'mpi_tp': tp,
                'mpi_nm': nm}
        file.write(Template("$mpi_tp $mpi_nm = ($mpi_tp)0xdeadbeef;\n").substitute(subs))

with open("src/mpi_defn_functions_c.h", "w") as file:
    file.write("// Define C MPI functions\n")
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

        tmpl.append("$abi_tp (* $abi_nm)(")
        for (i, (atp, anm)) in enumerate(args):
            tmpl.append("  $abi_atp{0} $anm{0},".format(i))
        tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
        tmpl.append(") = NULL;")

        if not support_profiling:

            # We declare the MPI functions inline if we don't have to support the
            # PMPI interface
            tmpl.append("extern inline $mpi_tp P$mpi_nm(")
            for (i, (atp, anm)) in enumerate(args):
                tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append(");")

        else:

            if not have_weak_symbols:
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

            tmpl.append("$mpi_tp P$mpi_nm(")
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

        file.write("\n")
        file.write(Template("\n".join(tmpl)).substitute(subs))
        file.write("\n")

with open("src/mpi_defn_constants_fortran.h", "w") as file:
    file.write("// Define Fortran MPI constants\n")
    file.write("\n")
    for (tp, nm) in constants_fortran:
        subs = {'mpi_tp': re.sub(r"MPI(X?)_\w+", r"MPI\1ABI_Fint", tp),
                'abi_nm': re.sub(r"MPI(X?)_", r"MPI\1ABI_", nm).lower() + "_"}
        # Fortran common blocks with `-march=skylake-avx512` are aligned to 64 bytes
        file.write(Template("$mpi_tp $abi_nm __attribute__((__aligned__(64))) = (int)0xdeadbeef;\n").substitute(subs))

with open("src/mpi_defn_functions_fortran.h", "w") as file:
    file.write("// Define Fortran MPI functions\n")
    file.write("\n")
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

        if not support_profiling:

            tmpl.append("$abi_tp $mpi_nm(")
            for (i, (atp, anm)) in enumerate(args):
                tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append(") {")
            if replace_sentinels:
                tmpl.extend(generate_fortran_sentinel_checks(args))
            tmpl.append("  return (* $abi_nm)(")
            for (i, (atp, anm)) in enumerate(args):
                tmpl.append("    $anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append("  );")
            tmpl.append("}")

        else:

            if have_weak_symbols:
                tmpl.append("#pragma weak $mpi_nm = p$mpi_nm")
            else:
                tmpl.append("$abi_tp $mpi_nm(")
                for (i, (atp, anm)) in enumerate(args):
                    tmpl.append("  $mpi_atp{0} $anm{0},".format(i))
                tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
                tmpl.append(") {")
                if replace_sentinels:
                    tmpl.extend(generate_fortran_sentinel_checks(args))
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
            if replace_sentinels:
                tmpl.extend(generate_fortran_sentinel_checks(args))
            tmpl.append("  return (* $abi_nm)(")
            for (i, (atp, anm)) in enumerate(args):
                tmpl.append("    $anm{0},".format(i))
            tmpl[-1] = re.sub(r",?$", "", tmpl[-1])  # remove trailing comma of last argument
            tmpl.append("  );")
            tmpl.append("}")

        file.write("\n")
        file.write(Template("\n".join(tmpl)).substitute(subs))
        file.write("\n")
