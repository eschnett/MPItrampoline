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
#define MP(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  RTYPE(*MPItrampoline_##NAME) PTYPES = NULL;                                  \
  RTYPE MPI_##NAME PTYPES { return MPItrampoline_##NAME PNAMES; }
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT
#undef MP

#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME) TYPE mpi_##NAME##_;
#include "mpi-constants-f.inc"
#undef CONSTANT
#undef MT

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  RTYPE(*mpitrampoline_##NAME##_) PTYPES = NULL;                               \
  RTYPE mpi_##NAME##_ PTYPES { return mpitrampoline_##NAME##_ PNAMES; }
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
    fprintf(stderr,
            "Set the environment variable MPITRAMPOLINE_LIB to point to a "
            "wrapped MPI library.\n"
            "See <https://github.com/eschnett/MPItrampoline> for details.\n");
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
  MPI_##NAME = *(TYPE const *)dlsym1(handle, "WPI_" #NAME);
#include "mpi-constants.inc"
#undef CONSTANT
#undef MT

  // Read C function pointers
#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  MPItrampoline_##NAME = dlsym1(handle, "WPI_" #NAME);
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT

  void (*const mpiwrapper_export_fortran_constants)() =
      dlsym1(handle, "mpiwrapper_export_fortran_constants_");
  mpiwrapper_export_fortran_constants();

  // Read Fortran constants
#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME)                                                   \
  mpi_##NAME##_ = *(TYPE const *)dlsym1(handle, "wpi_" #NAME "_");
#include "mpi-constants-f.inc"
#undef CONSTANT
#undef MT

  // Read Fortran function pointers
#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  mpitrampoline_##NAME##_ = dlsym1(handle, "wpi_" #NAME "_");
#include "mpi-functions-f.inc"
#undef FUNCTION
#undef MT
}
