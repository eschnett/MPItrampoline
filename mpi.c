#include "mpi.h"

#include <dlfcn.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mpitrampoline_mpi_init_();
void mpitrampoline_mpi_f08_init_();

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
  extern inline RTYPE MPI_##NAME PTYPES;
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT
#undef MP

#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME) MPI_Fint mpi_##NAME##_;
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

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
init_mpiwrapper() {
  const char *const libname = getenv("MPITRAMPOLINE_LIB");
  if (!libname) {
    fprintf(stderr,
            "WARNING: The environment variable MPITRAMPOLINE_LIB is not set.\n"
            "MPI functions will not be available.\n"
            "Set MPITRAMPOLINE_LIB to point to a wrapped MPI library.\n"
            "See <https://github.com/eschnett/MPItrampoline> for details.\n");
    sleep(1);
    // exit(1);
    return;
  }

#ifdef __APPLE__
  void *handle = dlopen(libname, RTLD_LAZY | RTLD_LOCAL | RTLD_FIRST);
#else
  void *handle = dlopen(libname, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
#endif
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
  mpi_##NAME##_ = *(MPI_Fint const *)dlsym1(handle, "wpi_" #NAME "_");
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

  mpitrampoline_mpi_init_();
  mpitrampoline_mpi_f08_init_();
}
