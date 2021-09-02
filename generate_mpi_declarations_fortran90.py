#!/usr/bin/env python3

import re
from string import Template

from mpi_constants_fortran import constants_fortran
# from mpi_functions_fortran import functions_fortran

print()
print("  ! Fortran constants")
for (tp, nm) in constants_fortran:
    subs = {'mpi_nm': nm}
    print(Template("  integer $mpi_nm").substitute(subs))

# print()
# print("  ! Fortran functions")
# for (tp, nm, args) in functions_fortran:
#     subs = {'mpi_nm': nm}
#     tmpl = []
#     tmpl.append("  external $mpi_nm")
#     print("\n".join(map(lambda line: Template(line).substitute(subs), tmpl)))
