#include "mpitrampoline.h"
#include "mpiabi_function_pointers.h"

#include <mpiabi_version.h>

#ifdef __linux__
#include <link.h>
#endif
#include <dlfcn.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int mpitrampoline_version_major = MPITRAMPOLINE_VERSION_MAJOR;
const int mpitrampoline_version_minor = MPITRAMPOLINE_VERSION_MINOR;
const int mpitrampoline_version_patch = MPITRAMPOLINE_VERSION_PATCH;

const char *const mpitrampoline_version = MPITRAMPOLINE_VERSION;

const int mpiabi_version_major = MPIABI_VERSION_MAJOR;
const int mpiabi_version_minor = MPIABI_VERSION_MINOR;
const int mpiabi_version_patch = MPIABI_VERSION_PATCH;

int mpiwrapper_version_major = -1;
int mpiwrapper_version_minor = -1;
int mpiwrapper_version_patch = -1;

int mpiabi_loaded_version_major = -1;
int mpiabi_loaded_version_minor = -1;
int mpiabi_loaded_version_patch = -1;

static bool did_init_mpitrampoline = false;

static void *load_library(const char *const libname) {
  void *handle;

#ifdef __APPLE__

  fprintf(stderr, "[MPItrampoline] Calling dlopen\n");
  handle = dlopen(libname, RTLD_LOCAL);

#elif __linux__

  fprintf(stderr, "[MPItrampoline] Calling dlopen\n");
  handle = dlopen(libname, RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);

#else
#error "Unsupported operating system"
#endif

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
#warning "TODO"
  fprintf(stderr, "MPItrampoline: Symbol \"%s\" resolved to %p\n", name, ptr);
  if (!ptr) {
    fprintf(stderr, "MPItrampoline: Could not resolve symbol \"%s\"\n", name);
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "MPItrampoline: dlerror: %s\n", error);
    exit(1);
  }
  return ptr;
}

static void mpitrampoline_init(void) {
  if (did_init_mpitrampoline)
    return;
  did_init_mpitrampoline = true;

  const char *const libname = getenv("MPITRAMPOLINE_LIB");
  if (!libname || libname[0] == '\0') {
    fprintf(stderr,
            "[MPItrampoline] Environment variable \"MPITRAMPOLINE_LIB\" is not "
            "set, cannot load MPIwrapper library\n");
    exit(1);
  }

  void *handle = load_library(libname);

  mpiwrapper_version_major =
      *(int const *)get_symbol(handle, "mpiwrapper_version_major");
  mpiwrapper_version_minor =
      *(int const *)get_symbol(handle, "mpiwrapper_version_minor");
  mpiwrapper_version_patch =
      *(int const *)get_symbol(handle, "mpiwrapper_version_patch");
  fprintf(stderr, "[MPItrampoline] Loaded MPIwrapper %d.%d.%d\n",
          mpiwrapper_version_major, mpiwrapper_version_minor,
          mpiwrapper_version_patch);

  mpiabi_loaded_version_major =
      *(int const *)get_symbol(handle, "mpiabi_version_major");
  mpiabi_loaded_version_minor =
      *(int const *)get_symbol(handle, "mpiabi_version_minor");
  mpiabi_loaded_version_patch =
      *(int const *)get_symbol(handle, "mpiabi_version_patch");
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

  MPIABI_Init_ptr = (int (*)(int *, char ***))get_symbol(handle, "MPIABI_Init");
}

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
mpitrampoline_init_auto(void) {
  fprintf(stderr, "[MPItrampoline] This is MPItrampoline %d.%d.%d\n",
          MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR,
          MPITRAMPOLINE_VERSION_PATCH);
  fprintf(stderr, "[MPItrampoline] Requiring MPI ABI version %d.%d.%d\n",
          MPIABI_VERSION_MAJOR, MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH);

  mpitrampoline_init();
}

// We define the common symbols here in this file to ensure that this
// file is linked into the executable, so that
// `mpitrampoline_init_auto` is actually run

#include "mpiabi_function_pointers.c"
