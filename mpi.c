#include "mpi.h"

#include <dlfcn.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

#define CONSTANT(TYPE, NAME) MPI_##TYPE MPI_##NAME;
#include "constants.inc"
#undef CONSTANT

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES) RTYPE(*MPI_##NAME) PTYPES = NULL;
#include "functions.inc"
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
    fprintf(stderr, "MPI wrapper library not set. Define the environment "
                    "variable MPITRAMPOLINE_LIB.\n");
    exit(1);
  }

  void *handle = dlopen(libname, RTLD_NOW);
  if (!handle) {
    fprintf(stderr, "Could not dlopen MPI wrapper library \"%s\".\n", libname);
    exit(1);
  }

  // Read constants
#define CONSTANT(TYPE, NAME)                                                   \
  MPI_##NAME = *(const MPI_##TYPE *)dlsym1(handle, "MPIWRAPPER_" #NAME);
#include "constants.inc"
#undef CONSTANT

  // Read function pointers
#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  MPI_##NAME = dlsym1(handle, "MPIwrapper_" #NAME);
#include "functions.inc"
#undef FUNCTION
#undef MT
}
