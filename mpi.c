#define _GNU_SOURCE
#define MPITRAMPOLINE_CONST

#include "mpi.h"

#ifdef __linux__
#include <link.h>
#endif
#include <dlfcn.h>

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void mpitrampoline_initialize_fortran90_();
void mpitrampoline_initialize_fortran08_();

////////////////////////////////////////////////////////////////////////////////

const char *const mpitrampoline_version = MPITRAMPOLINE_VERSION;
const int mpitrampoline_version_major = MPITRAMPOLINE_VERSION_MAJOR;
const int mpitrampoline_version_minor = MPITRAMPOLINE_VERSION_MINOR;
const int mpitrampoline_version_patch = MPITRAMPOLINE_VERSION_PATCH;

const int mpiabi_version_major = MPIABI_VERSION_MAJOR;
const int mpiabi_version_minor = MPIABI_VERSION_MINOR;
const int mpiabi_version_patch = MPIABI_VERSION_PATCH;

int mpiwrapper_version_major = -1;
int mpiwrapper_version_minor = -1;
int mpiwrapper_version_patch = -1;

int mpiabi_loaded_version_major = -1;
int mpiabi_loaded_version_minor = -1;
int mpiabi_loaded_version_patch = -1;

extern inline int MPI_Pcontrol(int level, ...);

////////////////////////////////////////////////////////////////////////////////

#include "mpi_definitions.h"

extern inline int MPI_Pcontrol(int level, ...);

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
  if (verbose) {
    fprintf(stderr, "[MPItrampoline] This is MPItrampoline %d.%d.%d\n",
            MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR,
            MPITRAMPOLINE_VERSION_PATCH);
    fprintf(stderr, "[MPItrampoline] Requiring MPI ABI version %d.%d.%d\n",
            MPIABI_VERSION_MAJOR, MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH);
  }

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
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Using MPIwrapper library \"%s\"\n",
            libname);

  // On Linux (with glibc), we use `dlmopen` or `RTLD_DEEPBIND` to
  // ensure that the loaded `mpiwrapper.so` looks for its MPI
  // symbols only in its dependencies (the "real" MPI library), and
  // not in MPItrampoline. If this happens, the resulting recursion
  // leads to a stack overflow and thus a segfault.
  //
  // The respective mechanism on macOS is to use two-level namespaces
  // for the plugin `mpiwrapper.so`. This is a link-time option for
  // `mpiwrapper.so`, and is also the default (`-twolevel_namespace`).
  // If `libmpiwrapper.so` is accidentally built with the linker
  // option `-flat_namespace`, things break as described above.

  const char *const dlopen_binding_str = getenv("MPITRAMPOLINE_DLOPEN_BINDING");
  enum dlopen_binding_t { dlopen_binding_lazy, dlopen_binding_now };
  enum dlopen_binding_t dlopen_binding;
  if (dlopen_binding_str == NULL || strcmp(dlopen_binding_str, "lazy") == 0) {
    dlopen_binding = dlopen_binding_lazy;
  } else if (strcmp(dlopen_binding_str, "now") == 0) {
    dlopen_binding = dlopen_binding_now;
  } else {
    fprintf(stderr,
            "The environment variable MPITRAMPOLINE_DLOPEN_BINDING is set to "
            "\"%s\".\n"
            "Only the values \"lazy\" (default) and \"now\" are allowed.",
            dlopen_binding_str);
    exit(1);
  }

  int dlopen_flags;
  switch (dlopen_binding) {
  case dlopen_binding_lazy:
    if (verbose)
      fprintf(stderr, "Using RTLD_LAZY\n");
    dlopen_flags = RTLD_LAZY;
    break;
  case dlopen_binding_now:
    if (verbose)
      fprintf(stderr, "Using RTLD_NOW\n");
    dlopen_flags = RTLD_NOW;
    break;
  default:
    assert(0);
  }

  void *handle = NULL;

#ifdef __APPLE__

  handle = dlopen(libname, dlopen_flags | RTLD_LOCAL | RTLD_FIRST);

#elif __linux__

  const char *const dlopen_mode_str = getenv("MPITRAMPOLINE_DLOPEN_MODE");
  enum dlopen_mode_t { dlopen_mode_dlmopen, dlopen_mode_dlopen };
  enum dlopen_mode_t dlopen_mode;
  if (dlopen_mode_str == NULL || strcmp(dlopen_mode_str, "dlmopen") == 0) {
    dlopen_mode = dlopen_mode_dlmopen;
  } else if (strcmp(dlopen_mode_str, "dlopen") == 0) {
    dlopen_mode = dlopen_mode_dlopen;
  } else {
    fprintf(
        stderr,
        "The environment variable MPITRAMPOLINE_DLOPEN_MODE is set to \"%s\".\n"
        "Only the values \"dlmopen\" (default) and \"dlopen\" are allowed.",
        dlopen_mode_str);
    exit(1);
  }

  switch (dlopen_mode) {
  case dlopen_mode_dlmopen:
    // Using `dlmopen` is more reliable than using `dlopen` with
    // `RTLD_DEEPBIND`. Unfortunately, this doesn't always work -- it
    // doesn't always load all the (transitive) dependencies of the
    // loaded library. I assume this is due to configuration errors in
    // the way `libwrapper.so` or its dependencies (the "real" MPI
    // libraries) are built.
    if (verbose)
      fprintf(stderr, "Calling dlmopen\n");
    handle = dlmopen(LM_ID_NEWLM, libname, dlopen_flags);
    break;
  case dlopen_mode_dlopen:
    if (verbose)
      fprintf(stderr, "Calling dlopen\n");
    handle = dlopen(libname, dlopen_flags | RTLD_LOCAL | RTLD_DEEPBIND);
    break;
  default:
    assert(0);
  }

#else
#error "Unsupported operating system"
#endif

  if (!handle) {
    fprintf(stderr, "Could not dlopen MPI wrapper library \"%s\"\n", libname);
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "dlerror: %s\n", error);
    exit(1);
  }

#ifdef __linux__
  {
    Lmid_t lmid;
    const int ierr - dlinfo(handle, RTLD_DI_LMID, &lmid);
    if (ierr) {
      fprintf(stderr, "Could not determine link map id\n");
      const char *const error = dlerror();
      if (error)
        fprintf(stderr, "dlerror: %s\n", error);
      exit(1);
    }
  }
#endif

  mpiwrapper_version_major =
      *(int const *)dlsym1(handle, "mpiwrapper_version_major");
  mpiwrapper_version_minor =
      *(int const *)dlsym1(handle, "mpiwrapper_version_minor");
  mpiwrapper_version_patch =
      *(int const *)dlsym1(handle, "mpiwrapper_version_patch");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Loaded MPIwrapper %d.%d.%d\n",
            mpiwrapper_version_major, mpiwrapper_version_minor,
            mpiwrapper_version_patch);

  mpiabi_loaded_version_major =
      *(int const *)dlsym1(handle, "mpiabi_version_major");
  mpiabi_loaded_version_minor =
      *(int const *)dlsym1(handle, "mpiabi_version_minor");
  mpiabi_loaded_version_patch =
      *(int const *)dlsym1(handle, "mpiabi_version_patch");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Found MPI ABI version %d.%d.%d\n",
            mpiabi_loaded_version_major, mpiabi_loaded_version_minor,
            mpiabi_loaded_version_patch);

  if (mpiabi_loaded_version_major != mpiabi_loaded_version_major ||
      mpiabi_loaded_version_minor < mpiabi_loaded_version_minor) {
    fprintf(
        stderr,
        "MPI ABI version mismatch:\n"
        "This version of MPItrampoline requires MPI ABI version %d.%d.%d, "
        "but the loaded MPIwrapper only provides MPI ABI version %d.%d.%d.\n"
        "This is MPItrampoline version %d.%d.%d.\n"
        "You loaded MPIwrapper version %d.%d.%d from file \"%s\".\n",
        mpiabi_version_major, mpiabi_version_minor, mpiabi_version_patch,
        mpiabi_loaded_version_major, mpiabi_loaded_version_minor,
        mpiabi_loaded_version_patch, mpitrampoline_version_major,
        mpitrampoline_version_minor, mpitrampoline_version_patch,
        mpiwrapper_version_major, mpiwrapper_version_minor,
        mpiwrapper_version_patch, libname);
    exit(1);
  }

  void (*const mpiwrapper_export_fortran_constants)() =
      dlsym1(handle, "mpiwrapper_export_fortran_constants_");
  (*mpiwrapper_export_fortran_constants)();

#include "mpi_initializations.h"

  mpitrampoline_initialize_fortran90_();
  mpitrampoline_initialize_fortran08_();

  if (verbose) {
    char library_version[MPI_MAX_LIBRARY_VERSION_STRING];
    int resultlen;
    MPI_Get_library_version(library_version, &resultlen);
    fprintf(stderr, "[MPItrampoline] MPI library version:\n%s\n",
            library_version);
  }

  if (verbose)
    fprintf(stderr, "[MPItrampoline] Initialization complete.\n");
}
