#include "mpi.h"

#include <dlfcn.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME) TYPE MPI_##NAME;
#include "mpi-constants.inc"
#undef CONSTANT
#undef MT

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES) RTYPE(*MPI_##NAME) PTYPES = NULL;
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT

#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME) TYPE mpi_##NAME;
#include "mpi-constants-f.inc"
#undef CONSTANT
#undef MT

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  RTYPE(*mpitrampoline_##NAME) PTYPES = NULL;
#include "mpi-functions-f.inc"
#undef FUNCTION
#undef MT

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  RTYPE mpi_##NAME PTYPES { return mpitrampoline_##NAME PNAMES; }
#include "mpi-functions-f.inc"
#undef FUNCTION
#undef MT

////////////////////////////////////////////////////////////////////////////////

static void *dlsym1(void *handle, const char *name) {
  void *ptr = dlsym(handle, name);
  if (!ptr) {
    fprintf(stderr, "Could not resolve symbol \"%s\"\n", name);
    exit(1);
  }
  return ptr;
}

void __attribute__((__constructor__)) init_mpiwrapper() {
  const char *const libname = getenv("MPITRAMPOLINE_LIB");
  if (!libname) {
    fprintf(stderr, "MPI wrapper library not set. Set the environment variable "
                    "MPITRAMPOLINE_LIB.\n");
    exit(1);
  }

  void *handle = dlopen(libname, RTLD_LAZY | RTLD_LOCAL);
  if (!handle) {
    fprintf(stderr, "Could not dlopen MPI wrapper library \"%s\".\n", libname);
    exit(1);
  }

  // Read C constants
#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME)                                                   \
  MPI_##NAME = *(const TYPE *)dlsym1(handle, "MPIWRAPPER_" #NAME);
#include "mpi-constants.inc"
#undef CONSTANT
#undef MT

  // Read C function pointers
#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  MPI_##NAME = dlsym1(handle, "MPIwrapper_" #NAME);
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT

  void (*const mpiwrapper_export_fortran_constants)() =
      dlsym1(handle, "mpiwrapper_export_fortran_constants_");
  mpiwrapper_export_fortran_constants();

  // Read Fortran constants
#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME)                                                   \
  mpi_##NAME = *(const TYPE *)dlsym1(handle, "mpiwrapper_" #NAME);
#include "mpi-constants-f.inc"
#undef CONSTANT
#undef MT

  // Read Fortran function pointers
#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  mpitrampoline_##NAME = dlsym1(handle, "mpiwrapper_" #NAME);
#include "mpi-functions-f.inc"
#undef FUNCTION
#undef MT
}
