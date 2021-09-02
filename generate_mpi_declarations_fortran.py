#!/usr/bin/env python3

import re
from string import Template

from mpi_constants_fortran import constants_fortran
from mpi_functions_fortran import functions_fortran

def wrap(line):
    lines = []
    while len(line) > 72:
        lines.append(line[0:72] + "&")
        line = "     &" + line[72:]
    lines.append(line)
    return "\n".join(lines)

print()
print("!     Fortran constants")
for (tp, nm) in constants_fortran:
    subs = {'mpi_nm': nm}
    tmpl = []
    tmpl.append("      integer $mpi_nm")
    tmpl.append("      common /$mpi_nm/ $mpi_nm")
    print("\n".join(map(lambda line: wrap(Template(line).substitute(subs)), tmpl)))

print()
print("!     Fortran functions")
for (tp, nm, args) in functions_fortran:
    subs = {'mpi_nm': nm}
    tmpl = []
    tmpl.append("      external $mpi_nm")
    print("\n".join(map(lambda line: wrap(Template(line).substitute(subs)), tmpl)))
