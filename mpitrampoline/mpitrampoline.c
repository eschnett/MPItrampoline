#include "mpiabi_function_pointers.h"

#include <mpiabi_version.h>

#include <dlfcn.h>

#include <stdio.h>
#include <stdlib.h>

const int mpirampoline_version_major = MPITRAMPOLINE_VERSION_MAJOR;
const int mpirampoline_version_minor = MPITRAMPOLINE_VERSION_MINOR;
const int mpirampoline_version_patch = MPITRAMPOLINE_VERSION_PATCH;

const char *const mpitrampoline_version = MPITRAMPOLINE_VERSION;

int mpiwrapper_version_major = -1;
int mpiwrapper_version_minor = -1;
int mpiwrapper_version_patch = -1;

int mpiabi_loaded_version_major = -1;
int mpiabi_loaded_version_minor = -1;
int mpiabi_loaded_version_patch = -1;

static bool did_init_mpitrampoline = false;

int (*MPIABI_Bsend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                        int dest, int tag, MPIABI_Comm comm);

static void *load_library(const char *const libname) {
  void *handle;
  handle = dlopen(libname, dlopen_flags | RTLD_LOCAL | RTLD_DEEPBIND);
  if (!handle) {
    fprintf(stderr, "MPItrampoline: Could not dlopen library \"%s\"\n",
            libname);
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "MPItrampoline: dlerror: %s\n", error);
    exit(1);
  }
  return handle;
}

static void *get_symbol(void *handle, const char *name) {
  void *ptr = dlsym(handle, name);
  if (!ptr) {
    fprintf(stderr, "MPItrampoline: Could not resolve symbol \"%s\"\n", name);
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "MPItrampoline: dlerror: %s\n", error);
    exit(1);
  }
  return ptr;
}

static void mpitrampoline_init() {
  if (did_init_mpitrampoline)
    return;
  did_init_mpitrampoline = true;

  void *handle = load_library("/usr/local/lib/libmpiwrapper.so");

  mpiwrapper_version_major =
      *(int const *)get_symbol(handle, "mpiwrapper_version_major");
  mpiwrapper_version_minor =
      *(int const *)get_symbol(handle, "mpiwrapper_version_minor");
  mpiwrapper_version_patch =
      *(int const *)get_symbol(handle, "mpiwrapper_version_patch");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Loaded MPIwrapper %d.%d.%d\n",
            mpiwrapper_version_major, mpiwrapper_version_minor,
            mpiwrapper_version_patch);

  mpiabi_loaded_version_major =
      *(int const *)get_symbol(handle, "mpiabi_version_major");
  mpiabi_loaded_version_minor =
      *(int const *)get_symbol(handle, "mpiabi_version_minor");
  mpiabi_loaded_version_patch =
      *(int const *)get_symbol(handle, "mpiabi_version_patch");
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Found MPI ABI version %d.%d.%d\n",
            mpiabi_loaded_version_major, mpiabi_loaded_version_minor,
            mpiabi_loaded_version_patch);

  if (mpiabi_loaded_version_major != mpiabi_version_major ||
      mpiabi_loaded_version_minor < mpiabi_version_minor) {
    fprintf(
        stderr,
        "MPItrampoline: MPI ABI version mismatch:\n"
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

  MPIABI_Init = *(void *)get_symbol(handle, "MPIABI_Init");
}

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
mpitrampoline_init_auto() {
  fprintf(stderr, "[MPItrampoline] This is MPItrampoline %d.%d.%d\n",
          MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR,
          MPITRAMPOLINE_VERSION_PATCH);
  fprintf(stderr, "[MPItrampoline] Requiring MPI ABI version %d.%d.%d\n",
          MPIABI_VERSION_MAJOR, MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH);

  mpitrampoline_init();
}
