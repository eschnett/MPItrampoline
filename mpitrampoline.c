#define _GNU_SOURCE

#define MPITRAMPOLINE_EXTERN_CONST(const)
#include "mpi.h"

#include <dlfcn.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void mpitrampoline_mpi_init_();
void mpitrampoline_mpi_f08_init_();

////////////////////////////////////////////////////////////////////////////////

const char *const mpitrampoline_version = MPITRAMPOLINE_VERSION;
const int mpitrampoline_version_major = MPITRAMPOLINE_VERSION_MAJOR;
const int mpitrampoline_version_minor = MPITRAMPOLINE_VERSION_MINOR;
const int mpitrampoline_version_patch = MPITRAMPOLINE_VERSION_PATCH;

const int mpiabi_version_required_major = MPIABI_VERSION_REQUIRED_MAJOR;
const int mpiabi_version_required_minor = MPIABI_VERSION_REQUIRED_MINOR;
const int mpiabi_version_required_patch = MPIABI_VERSION_REQUIRED_PATCH;

int MPIWRAPPER_VERSION_MAJOR = -1;
int MPIWRAPPER_VERSION_MINOR = -1;
int MPIWRAPPER_VERSION_PATCH = -1;

int MPIABI_VERSION_MAJOR = -1;
int MPIABI_VERSION_MINOR = -1;
int MPIABI_VERSION_PATCH = -1;

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
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "dlerror: %s\n", error);
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
init_mpitrampoline() {
  const bool verbose = getenv("MPITRAMPOLINE_VERBOSE");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] This is MPItrampoline %d.%d.%d\n",
            MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR,
            MPITRAMPOLINE_VERSION_PATCH);

  const char *const libname = getenv("MPITRAMPOLINE_LIB");
  if (!libname) {
    fprintf(stderr,
            "WARNING: The environment variable MPITRAMPOLINE_LIB is not set.\n"
            "MPI functions will not be available.\n"
            "Set MPITRAMPOLINE_LIB to point to a wrapped MPI library.\n"
            "See <https://github.com/eschnett/MPItrampoline> for details.\n");
    // Don't abort when MPITRAMPOLINE_LIB is unset. It is convenient
    // to let `configure` or similar tools run small executables.
    sleep(1);
    // exit(1);
    return;
  }
  if (verbose) {
    fprintf(stderr, "[MPItrampoline] Using MPIwrapper library \"%s\"\n",
            libname);
    fprintf(stderr, "[MPItrampoline] Requiring MPI ABI version %d.%d.%d\n",
            MPIABI_VERSION_REQUIRED_MAJOR, MPIABI_VERSION_REQUIRED_MINOR,
            MPIABI_VERSION_REQUIRED_PATCH);
  }

#ifdef __APPLE__
  void *handle = dlopen(libname, RTLD_LAZY | RTLD_LOCAL | RTLD_FIRST);
#else
  // void *handle = dlopen(libname, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
  void *handle = dlmopen(LM_ID_NEWLM, libname, RTLD_LAZY);
#endif
  if (!handle) {
    fprintf(stderr, "Could not dlopen MPI wrapper library \"%s\"\n", libname);
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "dlerror: %s\n", error);
    exit(1);
  }

  MPIWRAPPER_VERSION_MAJOR =
      *(int const *)dlsym1(handle, "mpiwrapper_version_major");
  MPIWRAPPER_VERSION_MINOR =
      *(int const *)dlsym1(handle, "mpiwrapper_version_minor");
  MPIWRAPPER_VERSION_PATCH =
      *(int const *)dlsym1(handle, "mpiwrapper_version_patch");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Loaded MPIwrapper %d.%d.%d\n",
            MPIWRAPPER_VERSION_MAJOR, MPIWRAPPER_VERSION_MINOR,
            MPIWRAPPER_VERSION_PATCH);

  MPIABI_VERSION_MAJOR = *(int const *)dlsym1(handle, "MPIABI_VERSION_MAJOR");
  MPIABI_VERSION_MINOR = *(int const *)dlsym1(handle, "MPIABI_VERSION_MINOR");
  MPIABI_VERSION_PATCH = *(int const *)dlsym1(handle, "MPIABI_VERSION_PATCH");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Found MPI ABI version %d.%d.%d\n",
            MPIABI_VERSION_MAJOR, MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH);

  if (MPIABI_VERSION_MAJOR != MPIABI_VERSION_REQUIRED_MAJOR ||
      MPIABI_VERSION_MINOR < MPIABI_VERSION_REQUIRED_MINOR) {
    fprintf(
        stderr,
        "MPI ABI version mismatch:\n"
        "This version of MPItrampoline requires MPI ABI version %d.%d.%d, "
        "but the loaded MPIwrapper only provides MPI ABI version %d.%d.%d.\n"
        "This is MPItrampoline version %d.%d.%d.\n"
        "You loaded MPIwrapper version %d.%d.%d from file \"%s\".\n",
        MPIABI_VERSION_REQUIRED_MAJOR, MPIABI_VERSION_REQUIRED_MINOR,
        MPIABI_VERSION_REQUIRED_PATCH, MPIABI_VERSION_MAJOR,
        MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH, MPITRAMPOLINE_VERSION_MAJOR,
        MPITRAMPOLINE_VERSION_MINOR, MPITRAMPOLINE_VERSION_PATCH,
        MPIWRAPPER_VERSION_MAJOR, MPIWRAPPER_VERSION_MINOR,
        MPIWRAPPER_VERSION_PATCH, libname);
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

  if (verbose)
    fprintf(stderr, "[MPItrampoline] Initialization complete.\n");
}
