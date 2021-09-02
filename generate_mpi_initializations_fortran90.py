#!/usr/bin/env python3

import re
from string import Template

from mpi_constants_fortran import constants_fortran

print()
print("  ! Fortran constants")

# Declarations
for (tp, nm) in constants_fortran:
    subs = {'mpi_nm': nm,
            'mpt_nm': re.sub(r"MPI_", "MPItrampoline_", nm)}
    tmpl = []
    tmpl.append("  integer $mpt_nm")
    tmpl.append("  common /$mpi_nm/ $mpt_nm")
    print(Template("\n".join(tmpl)).substitute(subs))

# Definitions
for (tp, nm) in constants_fortran:
    subs = {'mpi_nm': nm,
            'mpt_nm': re.sub(r"MPI_", "MPItrampoline_", nm)}
    tmpl = []
    tmpl.append("  $mpi_nm = $mpt_nm")
    print(Template("\n".join(tmpl)).substitute(subs))
