#define _GNU_SOURCE
#define MPITRAMPOLINE_CONST

#include "mpi.h"
#include "mpi_defaults.h"

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

////////////////////////////////////////////////////////////////////////////////

#include "mpi_defn_constants_c.h"
#include "mpi_defn_functions_c.h"

extern inline int PMPI_Pcontrol(int level, ...);
int MPI_Pcontrol(int level, ...) { return MPI_SUCCESS; }

#ifdef ENABLE_FORTRAN

// Sentinel values

char **mpiabi_argv_null_ptr_;
char ***mpiabi_argvs_null_ptr_;

MPI_Fint *mpiabi_bottom_ptr_;

MPI_Fint *mpiabi_errcodes_ignore_ptr_;

MPI_Fint *mpiabi_in_place_ptr_;

MPI_Fint *mpiabi_status_ignore_ptr_;
MPI_Fint *mpiabi_statuses_ignore_ptr_;

MPI_Fint *mpiabi_unweighted_ptr_;

MPI_Fint *mpiabi_weights_empty_ptr_;

#include "mpi_defn_constants_fortran.h"
#include "mpi_defn_functions_fortran.h"

void mpitrampoline_init_mpi_f08_();
#endif

////////////////////////////////////////////////////////////////////////////////

static void abort_with_error() {
  fprintf(stderr,
          "MPItrampoline: ERROR: The environment variable "
          "MPITRAMPOLINE_LIB is not set.\n"
          "MPI functions are not available.\n"
          "Set MPITRAMPOLINE_LIB to point to a wrapped MPI library.\n"
          "See <https://github.com/eschnett/MPItrampoline> for details.\n");
  exit(1);
}

static const char *get_default(const char *const varname) {
  const char *var = NULL;
  if (strcmp(varname, "MPITRAMPOLINE_DELAY_INIT") == 0)
    var = MPITRAMPOLINE_DEFAULT_DELAY_INIT;
  else if (strcmp(varname, "MPITRAMPOLINE_DLOPEN_BINDING") == 0)
    var = MPITRAMPOLINE_DEFAULT_DLOPEN_BINDING;
  else if (strcmp(varname, "MPITRAMPOLINE_DLOPEN_MODE") == 0)
    var = MPITRAMPOLINE_DEFAULT_DLOPEN_MODE;
  else if (strcmp(varname, "MPITRAMPOLINE_LIB") == 0)
    var = MPITRAMPOLINE_DEFAULT_LIB;
  else if (strcmp(varname, "MPITRAMPOLINE_PRELOAD") == 0)
    var = MPITRAMPOLINE_DEFAULT_PRELOAD;
  else if (strcmp(varname, "MPITRAMPOLINE_VERBOSE") == 0)
    var = MPITRAMPOLINE_DEFAULT_VERBOSE;
  if (var && var[0] == '\0')
    var = NULL;
  return var;
}

static bool verbose = false;

static const char *mpitrampoline_dir = NULL;

// This path is correct only if MPItrampoline is built as shared
// library. If MPItrarmpoline is built as static library, then the
// path corresponds to the executable. This function also expects that
// MPItrampoline is installed into a `lib` directory. If not, then the
// path will point to the wrong directory.
static void set_mpitrampoline_dir() {
  Dl_info info;
  const int iret = dladdr(&mpiwrapper_version_major, &info);
  if (!iret) {
    fprintf(stderr, "MPItrampoline: Cannot determine path of mpitrampoline\n");
    exit(1);
  }
  char *const buf = strdup(info.dli_fname);
  // Remove last two components
  for (int i = 0; i < 2; ++i) {
    char *const slash = strrchr(buf, '/');
    if (!slash)
      break;
    *slash = '\0';
  }
  mpitrampoline_dir = buf;
  if (verbose)
    fprintf(stderr, "[MPItrampoline] mpitrampoline is installed in \"%s\"\n",
            mpitrampoline_dir);
}

// Generic string append functions
static void mem_alloc(char **restrict buf, size_t *restrict buf_len,
                      size_t *restrict buf_pos) {
  *buf_len = 1000;
  *buf = malloc(*buf_len);
  *buf_pos = 0;
}
static void mem_append(char **restrict buf, size_t *restrict buf_len,
                       size_t *restrict buf_pos, const char *restrict str,
                       const size_t str_len) {
  if (*buf_pos + str_len > *buf_len) {
    *buf_len += *buf_pos + str_len;
    *buf = realloc(*buf, *buf_len);
  }
  memcpy(*buf + *buf_pos, str, str_len);
  *buf_pos += str_len;
}

static const char *expand_template(const char *const var,
                                   const char *const template,
                                   const char *const value) {
  if (!strstr(var, template))
    return var;

  if (!value) {
    fprintf(
        stderr,
        "MPItrampoline: Cannot expand template \"%s\" because value is NULL\n",
        template);
    exit(1);
  }
  const size_t template_len = strlen(template);
  const size_t value_len = strlen(value);
  size_t var_pos = 0;
  char *buf;
  size_t buf_len, buf_pos;
  mem_alloc(&buf, &buf_len, &buf_pos);

  for (;;) {
    // Find template
    const char *const tmpl = strstr(&var[var_pos], template);
    // Copy characters up to template, or all remaining characters
    const size_t ncopy = tmpl ? tmpl - &var[var_pos] : strlen(&var[var_pos]);
    mem_append(&buf, &buf_len, &buf_pos, &var[var_pos], ncopy);
    var_pos += ncopy;
    // We are done if no template was found
    if (!tmpl)
      break;
    // Copy template
    mem_append(&buf, &buf_len, &buf_pos, value, value_len);
    var_pos += template_len;
  }
  // Add trailing NUL character
  mem_append(&buf, &buf_len, &buf_pos, "", 1);

  // We don't record whether strdup was called. We assume that this
  // function `get_config` is called only a few times during
  // startup, and that the memory leak is small enough to not
  // matter.
  return buf;
}

static const char *get_config(const char *const varname) {
  // Get configuration setting
  const char *var = NULL;
  if (!var)
    // Check environment variable
    var = getenv(varname);
  if (!var) {
    // Check global variable in main application
    void *const symptr = dlsym(RTLD_DEFAULT, varname);
    if (symptr)
      var = *(const char **)symptr;
  }
  if (!var)
    // Check default setting
    var = get_default(varname);
  if (!var)
    return NULL;

  // Expand path to MPItrampoline
  var = expand_template(var, "@MPITRAMPOLINE_DIR@", mpitrampoline_dir);

  return var;
}

static void set_verbose() {
  const char *const verbose_str = get_config("MPITRAMPOLINE_VERBOSE");
  verbose = verbose_str && *verbose_str != '\0';
}

enum dlopen_mode_t {
  dlopen_mode_error,
  dlopen_mode_dlmopen,
  dlopen_mode_dlopen
};
static enum dlopen_mode_t dlopen_mode = dlopen_mode_error;

void set_dlopen_mode() {
  const char *const dlopen_mode_str = get_config("MPITRAMPOLINE_DLOPEN_MODE");
  if (dlopen_mode_str == NULL || strcmp(dlopen_mode_str, "dlopen") == 0) {
    dlopen_mode = dlopen_mode_dlopen;
  } else if (strcmp(dlopen_mode_str, "dlmopen") == 0) {
    dlopen_mode = dlopen_mode_dlmopen;
  } else {
    fprintf(stderr,
            "MPItrampoline: The environment variable MPITRAMPOLINE_DLOPEN_MODE "
            "is set to \"%s\".\n"
            "Only the values \"dlopen\" (default) and \"dlmopen\" are allowed.",
            dlopen_mode_str);
    exit(1);
  }
}

enum dlopen_binding_t {
  dlopen_binding_error,
  dlopen_binding_lazy,
  dlopen_binding_now
};
static enum dlopen_binding_t dlopen_binding = dlopen_binding_error;

void set_dlopen_binding() {
  const char *const dlopen_binding_str =
      get_config("MPITRAMPOLINE_DLOPEN_BINDING");
  if (dlopen_binding_str == NULL || strcmp(dlopen_binding_str, "lazy") == 0) {
    dlopen_binding = dlopen_binding_lazy;
  } else if (strcmp(dlopen_binding_str, "now") == 0) {
    dlopen_binding = dlopen_binding_now;
  } else {
    fprintf(stderr,
            "MPItrampoline: The environment variable "
            "MPITRAMPOLINE_DLOPEN_BINDING is set to \"%s\".\n"
            "Only the values \"lazy\" (default) and \"now\" are allowed.",
            dlopen_binding_str);
    exit(1);
  }
}

static int get_dlopen_flags() {
  int dlopen_flags;
  switch (dlopen_binding) {
  case dlopen_binding_lazy:
    if (verbose)
      fprintf(stderr, "[MPItrampoline] Using RTLD_LAZY\n");
    dlopen_flags = RTLD_LAZY;
    break;
  case dlopen_binding_now:
    if (verbose)
      fprintf(stderr, "[MPItrampoline] Using RTLD_NOW\n");
    dlopen_flags = RTLD_NOW;
    break;
  default:
    assert(0);
  }
  return dlopen_flags;
}

#ifdef __linux__
static bool have_dlopen_lmid = false;
static Lmid_t dlopen_lmid;
#endif

static void *load_library(const char *const libname) {
  const int dlopen_flags = get_dlopen_flags();

  void *handle = NULL;

#ifdef __APPLE__

  if (verbose)
    fprintf(stderr, "[MPItrampoline] Calling dlopen\n");
  handle = dlopen(libname, dlopen_flags | RTLD_LOCAL);

#elif __linux__

  switch (dlopen_mode) {
  case dlopen_mode_dlmopen:
    if (verbose)
      fprintf(stderr, "[MPItrampoline] Calling dlmopen\n");
    const Lmid_t lmid = have_dlopen_lmid ? dlopen_lmid : LM_ID_NEWLM;
    handle = dlmopen(lmid, libname, dlopen_flags);
    break;
  case dlopen_mode_dlopen:
    if (verbose)
      fprintf(stderr, "[MPItrampoline] Calling dlopen\n");
    handle = dlopen(libname, dlopen_flags | RTLD_LOCAL | RTLD_DEEPBIND);
    break;
  default:
    assert(0);
  }

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

#ifdef __linux__
  Lmid_t lmid;
  const int ierr = dlinfo(handle, RTLD_DI_LMID, &lmid);
  if (ierr) {
    fprintf(stderr, "MPItrampoline: Could not determine link map id\n");
    const char *const error = dlerror();
    if (error)
      fprintf(stderr, "MPItrampoline: dlerror: %s\n", error);
    exit(1);
  }

  if (have_dlopen_lmid) {
    assert(dlopen_lmid == lmid);
  } else {
    dlopen_lmid = lmid;
    have_dlopen_lmid = true;
  }
#endif

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

void mpitrampoline_init() {
  // Ensure that the library is initialized only once
  static bool did_init_mpitrampoline = false;
  if (did_init_mpitrampoline)
    return;
  did_init_mpitrampoline = true;

  set_verbose();
  if (verbose) {
    fprintf(stderr, "[MPItrampoline] This is MPItrampoline %d.%d.%d\n",
            MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR,
            MPITRAMPOLINE_VERSION_PATCH);
    fprintf(stderr, "[MPItrampoline] Requiring MPI ABI version %d.%d.%d\n",
            MPIABI_VERSION_MAJOR, MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH);
  }

  set_mpitrampoline_dir();

  // On Linux (with glibc), we use `dlmopen` or `RTLD_DEEPBIND` to
  // ensure that the loaded `mpiwrapper.so` looks for its MPI symbols
  // only in its dependencies (the "real" MPI library), and not in
  // MPItrampoline. If this happens, the resulting recursion leads to
  // a stack overflow and thus a segfault.
  //
  // Using `dlmopen` is more reliable than using `dlopen` with
  // `RTLD_DEEPBIND`. Unfortunately, this doesn't always work -- it
  // doesn't always load all the (transitive) dependencies of the
  // loaded library. I assume this is due to configuration errors in
  // the way `libwrapper.so` or its dependencies (the "real" MPI
  // libraries) are built.
  //
  // The respective mechanism on macOS is to use two-level namespaces
  // for the plugin `mpiwrapper.so`. This is a link-time option for
  // `mpiwrapper.so`, and is also the default (`-twolevel_namespace`).
  // If `libmpiwrapper.so` is accidentally built with the linker
  // option `-flat_namespace`, things break as described above.

  set_dlopen_mode();
  set_dlopen_binding();

  const char *const preload_str = get_config("MPITRAMPOLINE_PRELOAD");
  if (preload_str) {
    char *const preload = strdup(preload_str);
    const char *const delim = ":";
    for (char *stringp = preload, *libname;
         (libname = strsep(&stringp, delim));) {
      if (*libname != '\0') {
        if (verbose)
          fprintf(stderr, "[MPItrampoline] Preloading library \"%s\"\n",
                  libname);
        load_library(libname);
      }
    }
    free(preload);
  }

  const char *const libname = get_config("MPITRAMPOLINE_LIB");
  if (!libname) {
    // The environment variable MPITRAMPOLINE_LIB is not set. We
    // cannot provide an MPI implementation.
    //
    // Don't output a warning. Some configure scripts get confused by
    // this. Instead, abort with an error if an MPI function is
    // called. These four functions are the ones that can legally be
    // called in the beginning. All other MPI functions will lead to
    // segfaults.
    MPIABI_Finalized = (void *)abort_with_error;
    MPIABI_Init = (void *)abort_with_error;
    MPIABI_Init_thread = (void *)abort_with_error;
    MPIABI_Initialized = (void *)abort_with_error;
#if 0
    fprintf(stderr,
            "MPItrampoline: WARNING: The environment variable "
            "MPITRAMPOLINE_LIB is not set.\n"
            "MPI functions will not be available.\n"
            "Set MPITRAMPOLINE_LIB to point to a wrapped MPI library.\n"
            "See <https://github.com/eschnett/MPItrampoline> for details.\n");
    // Don't abort when MPITRAMPOLINE_LIB is unset. It is convenient
    // to let `configure` or similar tools run small executables.
    sleep(1);
    // exit(1);
#endif
    return;
  }
  if (verbose)
    fprintf(stderr, "[MPItrampoline] Using MPIwrapper library \"%s\"\n",
            libname);

  void *handle = load_library(libname);

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

  void (*const mpiwrapper_export_fortran_constants)() =
      get_symbol(handle, "mpiwrapper_export_fortran_constants_");
  (*mpiwrapper_export_fortran_constants)();

#include "mpi_init_constants_c.h"
#include "mpi_init_functions_c.h"

#ifdef ENABLE_FORTRAN

  mpiabi_argv_null_ptr_ = *(char ***)get_symbol(handle, "mpiabi_argv_null_");
  mpiabi_argvs_null_ptr_ = *(char ****)get_symbol(handle, "mpiabi_argvs_null_");
  mpiabi_bottom_ptr_ = *(MPIABI_Fint **)get_symbol(handle, "mpiabi_bottom_");
  mpiabi_errcodes_ignore_ptr_ =
      *(MPIABI_Fint **)get_symbol(handle, "mpiabi_errcodes_ignore_");
  mpiabi_in_place_ptr_ =
      *(MPIABI_Fint **)get_symbol(handle, "mpiabi_in_place_");
  mpiabi_status_ignore_ptr_ =
      *(MPIABI_Fint **)get_symbol(handle, "mpiabi_status_ignore_");
  mpiabi_statuses_ignore_ptr_ =
      *(MPIABI_Fint **)get_symbol(handle, "mpiabi_statuses_ignore_");
  mpiabi_unweighted_ptr_ =
      *(MPIABI_Fint **)get_symbol(handle, "mpiabi_unweighted_");
  mpiabi_weights_empty_ptr_ =
      *(MPIABI_Fint **)get_symbol(handle, "mpiabi_weights_empty_");

#include "mpi_init_constants_fortran.h"
#include "mpi_init_functions_fortran.h"

  // Set up high-level Fortran constants
  mpitrampoline_init_mpi_f08_();

#endif

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

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
mpitrampoline_init_auto() {
  set_verbose();
  if (verbose) {
    fprintf(stderr, "[MPItrampoline] This is MPItrampoline %d.%d.%d\n",
            MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR,
            MPITRAMPOLINE_VERSION_PATCH);
    fprintf(stderr, "[MPItrampoline] Requiring MPI ABI version %d.%d.%d\n",
            MPIABI_VERSION_MAJOR, MPIABI_VERSION_MINOR, MPIABI_VERSION_PATCH);
  }

  const char *const delay_init_str = get_config("MPITRAMPOLINE_DELAY_INIT");
  const bool delay_init = delay_init_str && *delay_init_str != '\0';
  if (delay_init) {
    if (verbose)
      fprintf(stderr, "[MPItrampoline] Delaying initialization; waiting for "
                      "explicit initialization\n");
    return;
  }

  mpitrampoline_init();
}
