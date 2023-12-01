#include "mpiwrapper.h"

#include <mpiabi.h>

#include <mpi.h>
#ifdef HAVE_MPI_EXT_H
#include <mpi-ext.h>
#endif

#include <pthread.h>

#include <assert.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

#define MPI_VERSION_NUMBER (100 * MPI_VERSION + MPI_SUBVERSION)

// #if MPI_VERSION_NUMBER >= 400
// // All is fine
// #else
// #error "MPItrampoline requires at least MPI standard 4.0"
// #endif

// Fake MPI 4 support, just enough to make the compiler happy

#ifndef HAVE_MPI_BUFFER_AUTOMATIC
#define MPI_BUFFER_AUTOMATIC MPIABI_BUFFER_AUTOMATIC
#endif

#ifndef HAVE_MPI_COMM_TYPE_HW_GUIDED
#define MPI_COMM_TYPE_HW_GUIDED MPIABI_COMM_TYPE_HW_GUIDED
#endif

#ifndef HAVE_MPI_COMM_TYPE_HW_UNGUIDED
#define MPI_COMM_TYPE_HW_UNGUIDED MPIABI_COMM_TYPE_HW_UNGUIDED
#endif

#ifndef HAVE_MPI_COMM_TYPE_RESOURCE_GUIDED
#define MPI_COMM_TYPE_RESOURCE_GUIDED MPIABI_COMM_TYPE_RESOURCE_GUIDED
#endif

#ifndef HAVE_SIZEOF_MPI_SESSION
#define MPI_Session MPI_Comm
#define MPI_SESSION_NULL MPI_COMM_NULL
#endif

#ifndef HAVE_SIZEOF_MPI_USER_FUNCTION_C
#define MPI_User_function_c MPI_User_function
#endif

////////////////////////////////////////////////////////////////////////////////

// Consistency checks

#if SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
_Static_assert(sizeof(MPI_Aint) == sizeof(MPIABI_Aint), "");
#endif

#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T
_Static_assert(sizeof(MPI_Count) == sizeof(MPIABI_Count), "");
#endif

#if SIZEOF_MPI_OFFSET == SIZEOF_PTRDIFF_T
_Static_assert(sizeof(MPI_Offset) == sizeof(MPIABI_Offset), "");
#endif

// Version numbers

const int mpiwrapper_version_major = MPIWRAPPER_VERSION_MAJOR;
const int mpiwrapper_version_minor = MPIWRAPPER_VERSION_MINOR;
const int mpiwrapper_version_patch = MPIWRAPPER_VERSION_PATCH;

const char *const mpiwrapper_version = MPIWRAPPER_VERSION;

const int mpiabi_version_major = MPIABI_VERSION_MAJOR;
const int mpiabi_version_minor = MPIABI_VERSION_MINOR;
const int mpiabi_version_patch = MPIABI_VERSION_PATCH;

// Conversions between MPI and MPIABI

// We do not translate `MPI_BOTTOM`. We assume this constant is zero
// in all implementations.
_Static_assert((uintptr_t)MPI_BOTTOM == 0, "");
// We do not translate `MPI_ARGVS_NULL` nor `MPI_ARGV_NULL`. We assume
// these constants are zero in all implementations.
_Static_assert((uintptr_t)MPIABI_ARGVS_NULL == 0, "");
_Static_assert((uintptr_t)MPIABI_ARGV_NULL == 0, "");

#define MAX_RESERVED_HANDLE 0b111111111111
static inline bool handle_is_reserved(uintptr_t abi_handle) {
  return abi_handle <= MAX_RESERVED_HANDLE;
}
static inline uintptr_t abi2mpi_unreserved(uintptr_t abi_handle) {
  assert(!handle_is_reserved(abi_handle));
  uintptr_t mpi_handle = abi_handle - (MAX_RESERVED_HANDLE + 1);
  return mpi_handle;
}
static inline uintptr_t mpi2abi_unreserved(uintptr_t mpi_handle) {
  uintptr_t abi_handle = mpi_handle + (MAX_RESERVED_HANDLE + 1);
  assert(!handle_is_reserved(abi_handle));
  return abi_handle;
}

static int mpi2abi_combiner(int combiner) {
  switch (combiner) {
  case MPI_COMBINER_CONTIGUOUS:
    return MPIABI_COMBINER_CONTIGUOUS;
  case MPI_COMBINER_DARRAY:
    return MPIABI_COMBINER_DARRAY;
  case MPI_COMBINER_DUP:
    return MPIABI_COMBINER_DUP;
  case MPI_COMBINER_F90_COMPLEX:
    return MPIABI_COMBINER_F90_COMPLEX;
  case MPI_COMBINER_F90_INTEGER:
    return MPIABI_COMBINER_F90_INTEGER;
  case MPI_COMBINER_F90_REAL:
    return MPIABI_COMBINER_F90_REAL;
  case MPI_COMBINER_HINDEXED:
    return MPIABI_COMBINER_HINDEXED;
  case MPI_COMBINER_HVECTOR:
    return MPIABI_COMBINER_HVECTOR;
  case MPI_COMBINER_INDEXED_BLOCK:
    return MPIABI_COMBINER_INDEXED_BLOCK;
  case MPI_COMBINER_HINDEXED_BLOCK:
    return MPIABI_COMBINER_HINDEXED_BLOCK;
  case MPI_COMBINER_INDEXED:
    return MPIABI_COMBINER_INDEXED;
  case MPI_COMBINER_NAMED:
    return MPIABI_COMBINER_NAMED;
  case MPI_COMBINER_RESIZED:
    return MPIABI_COMBINER_RESIZED;
  case MPI_COMBINER_STRUCT:
    return MPIABI_COMBINER_STRUCT;
  case MPI_COMBINER_SUBARRAY:
    return MPIABI_COMBINER_SUBARRAY;
  case MPI_COMBINER_VECTOR:
    return MPIABI_COMBINER_VECTOR;
  default:
    assert(false);
  }
}

static int mpi2abi_count(int count) {
  if (count == MPI_UNDEFINED)
    return MPIABI_UNDEFINED;
  return count;
}

static int abi2mpi_distrib(int distrib) {
  switch (distrib) {
  case MPIABI_DISTRIBUTE_BLOCK:
    return MPI_DISTRIBUTE_BLOCK;
  case MPIABI_DISTRIBUTE_CYCLIC:
    return MPI_DISTRIBUTE_CYCLIC;
  case MPIABI_DISTRIBUTE_NONE:
    return MPI_DISTRIBUTE_NONE;
  default:
    assert(false);
  }
}

static int abi2mpi_errorcode(int errorcode) {
  // Fast path
  if (__builtin_expect(errorcode == MPIABI_SUCCESS, true))
    return MPIABI_SUCCESS;
  switch (errorcode) {
  case MPIABI_ERR_ACCESS:
    return MPI_ERR_ACCESS;
  case MPIABI_ERR_AMODE:
    return MPI_ERR_AMODE;
  case MPIABI_ERR_ARG:
    return MPI_ERR_ARG;
  case MPIABI_ERR_ASSERT:
    return MPI_ERR_ASSERT;
  case MPIABI_ERR_BAD_FILE:
    return MPI_ERR_BAD_FILE;
  case MPIABI_ERR_BASE:
    return MPI_ERR_BASE;
  case MPIABI_ERR_BUFFER:
    return MPI_ERR_BUFFER;
  case MPIABI_ERR_COMM:
    return MPI_ERR_COMM;
  case MPIABI_ERR_CONVERSION:
    return MPI_ERR_CONVERSION;
  case MPIABI_ERR_COUNT:
    return MPI_ERR_COUNT;
  case MPIABI_ERR_DIMS:
    return MPI_ERR_DIMS;
  case MPIABI_ERR_DISP:
    return MPI_ERR_DISP;
  case MPIABI_ERR_DUP_DATAREP:
    return MPI_ERR_DUP_DATAREP;
  case MPIABI_ERR_FILE:
    return MPI_ERR_FILE;
  case MPIABI_ERR_FILE_EXISTS:
    return MPI_ERR_FILE_EXISTS;
  case MPIABI_ERR_FILE_IN_USE:
    return MPI_ERR_FILE_IN_USE;
  case MPIABI_ERR_GROUP:
    return MPI_ERR_GROUP;
  case MPIABI_ERR_INFO:
    return MPI_ERR_INFO;
  case MPIABI_ERR_INFO_KEY:
    return MPI_ERR_INFO_KEY;
  case MPIABI_ERR_INFO_NOKEY:
    return MPI_ERR_INFO_NOKEY;
  case MPIABI_ERR_INFO_VALUE:
    return MPI_ERR_INFO_VALUE;
  case MPIABI_ERR_INTERN:
    return MPI_ERR_INTERN;
  case MPIABI_ERR_IN_STATUS:
    return MPI_ERR_IN_STATUS;
  case MPIABI_ERR_IO:
    return MPI_ERR_IO;
  case MPIABI_ERR_KEYVAL:
    return MPI_ERR_KEYVAL;
  case MPIABI_ERR_LOCKTYPE:
    return MPI_ERR_LOCKTYPE;
  case MPIABI_ERR_NAME:
    return MPI_ERR_NAME;
  case MPIABI_ERR_NOT_SAME:
    return MPI_ERR_NOT_SAME;
  case MPIABI_ERR_NO_MEM:
    return MPI_ERR_NO_MEM;
  case MPIABI_ERR_NO_SPACE:
    return MPI_ERR_NO_SPACE;
  case MPIABI_ERR_NO_SUCH_FILE:
    return MPI_ERR_NO_SUCH_FILE;
  case MPIABI_ERR_OP:
    return MPI_ERR_OP;
  case MPIABI_ERR_OTHER:
    return MPI_ERR_OTHER;
  case MPIABI_ERR_PENDING:
    return MPI_ERR_PENDING;
  case MPIABI_ERR_PORT:
    return MPI_ERR_PORT;
#if MPI_VERSION_NUMBER >= 400
  case MPIABI_ERR_PROC_ABORTED:
    return MPI_ERR_PROC_ABORTED;
#endif
  case MPIABI_ERR_QUOTA:
    return MPI_ERR_QUOTA;
  case MPIABI_ERR_RANK:
    return MPI_ERR_RANK;
  case MPIABI_ERR_READ_ONLY:
    return MPI_ERR_READ_ONLY;
  case MPIABI_ERR_REQUEST:
    return MPI_ERR_REQUEST;
  case MPIABI_ERR_RMA_ATTACH:
    return MPI_ERR_RMA_ATTACH;
  case MPIABI_ERR_RMA_CONFLICT:
    return MPI_ERR_RMA_CONFLICT;
  case MPIABI_ERR_RMA_FLAVOR:
    return MPI_ERR_RMA_FLAVOR;
  case MPIABI_ERR_RMA_RANGE:
    return MPI_ERR_RMA_RANGE;
  case MPIABI_ERR_RMA_SHARED:
    return MPI_ERR_RMA_SHARED;
  case MPIABI_ERR_RMA_SYNC:
    return MPI_ERR_RMA_SYNC;
  case MPIABI_ERR_ROOT:
    return MPI_ERR_ROOT;
  case MPIABI_ERR_SERVICE:
    return MPI_ERR_SERVICE;
#if MPI_VERSION_NUMBER >= 400
  case MPIABI_ERR_SESSION:
    return MPI_ERR_SESSION;
#endif
  case MPIABI_ERR_SIZE:
    return MPI_ERR_SIZE;
  case MPIABI_ERR_SPAWN:
    return MPI_ERR_SPAWN;
  case MPIABI_ERR_TAG:
    return MPI_ERR_TAG;
  case MPIABI_ERR_TOPOLOGY:
    return MPI_ERR_TOPOLOGY;
  case MPIABI_ERR_TRUNCATE:
    return MPI_ERR_TRUNCATE;
  case MPIABI_ERR_TYPE:
    return MPI_ERR_TYPE;
  case MPIABI_ERR_UNKNOWN:
    return MPI_ERR_UNKNOWN;
  case MPIABI_ERR_UNSUPPORTED_DATAREP:
    return MPI_ERR_UNSUPPORTED_DATAREP;
  case MPIABI_ERR_UNSUPPORTED_OPERATION:
    return MPI_ERR_UNSUPPORTED_OPERATION;
#if MPI_VERSION_NUMBER >= 400
  case MPIABI_ERR_VALUE_TOO_LARGE:
    return MPI_ERR_VALUE_TOO_LARGE;
#endif
  case MPIABI_ERR_WIN:
    return MPI_ERR_WIN;
  default:
    // unknown error code
    // assert(false);
    return errorcode;
  }
}

static int mpi2abi_errorcode(int errorcode) {
  // Fast path
  if (__builtin_expect(errorcode == MPI_SUCCESS, true))
    return MPIABI_SUCCESS;
  switch (errorcode) {
  case MPI_ERR_ACCESS:
    return MPIABI_ERR_ACCESS;
  case MPI_ERR_AMODE:
    return MPIABI_ERR_AMODE;
  case MPI_ERR_ARG:
    return MPIABI_ERR_ARG;
  case MPI_ERR_ASSERT:
    return MPIABI_ERR_ASSERT;
  case MPI_ERR_BAD_FILE:
    return MPIABI_ERR_BAD_FILE;
  case MPI_ERR_BASE:
    return MPIABI_ERR_BASE;
  case MPI_ERR_BUFFER:
    return MPIABI_ERR_BUFFER;
  case MPI_ERR_COMM:
    return MPIABI_ERR_COMM;
  case MPI_ERR_CONVERSION:
    return MPIABI_ERR_CONVERSION;
  case MPI_ERR_COUNT:
    return MPIABI_ERR_COUNT;
  case MPI_ERR_DIMS:
    return MPIABI_ERR_DIMS;
  case MPI_ERR_DISP:
    return MPIABI_ERR_DISP;
  case MPI_ERR_DUP_DATAREP:
    return MPIABI_ERR_DUP_DATAREP;
  case MPI_ERR_FILE:
    return MPIABI_ERR_FILE;
  case MPI_ERR_FILE_EXISTS:
    return MPIABI_ERR_FILE_EXISTS;
  case MPI_ERR_FILE_IN_USE:
    return MPIABI_ERR_FILE_IN_USE;
  case MPI_ERR_GROUP:
    return MPIABI_ERR_GROUP;
  case MPI_ERR_INFO:
    return MPIABI_ERR_INFO;
  case MPI_ERR_INFO_KEY:
    return MPIABI_ERR_INFO_KEY;
  case MPI_ERR_INFO_NOKEY:
    return MPIABI_ERR_INFO_NOKEY;
  case MPI_ERR_INFO_VALUE:
    return MPIABI_ERR_INFO_VALUE;
  case MPI_ERR_INTERN:
    return MPIABI_ERR_INTERN;
  case MPI_ERR_IN_STATUS:
    return MPIABI_ERR_IN_STATUS;
  case MPI_ERR_IO:
    return MPIABI_ERR_IO;
  case MPI_ERR_KEYVAL:
    return MPIABI_ERR_KEYVAL;
  case MPI_ERR_LOCKTYPE:
    return MPIABI_ERR_LOCKTYPE;
  case MPI_ERR_NAME:
    return MPIABI_ERR_NAME;
  case MPI_ERR_NOT_SAME:
    return MPIABI_ERR_NOT_SAME;
  case MPI_ERR_NO_MEM:
    return MPIABI_ERR_NO_MEM;
  case MPI_ERR_NO_SPACE:
    return MPIABI_ERR_NO_SPACE;
  case MPI_ERR_NO_SUCH_FILE:
    return MPIABI_ERR_NO_SUCH_FILE;
  case MPI_ERR_OP:
    return MPIABI_ERR_OP;
  case MPI_ERR_OTHER:
    return MPIABI_ERR_OTHER;
  case MPI_ERR_PENDING:
    return MPIABI_ERR_PENDING;
  case MPI_ERR_PORT:
    return MPIABI_ERR_PORT;
#if MPI_VERSION_NUMBER >= 400
  case MPI_ERR_PROC_ABORTED:
    return MPIABI_ERR_PROC_ABORTED;
#endif
  case MPI_ERR_QUOTA:
    return MPIABI_ERR_QUOTA;
  case MPI_ERR_RANK:
    return MPIABI_ERR_RANK;
  case MPI_ERR_READ_ONLY:
    return MPIABI_ERR_READ_ONLY;
  case MPI_ERR_REQUEST:
    return MPIABI_ERR_REQUEST;
  case MPI_ERR_RMA_ATTACH:
    return MPIABI_ERR_RMA_ATTACH;
  case MPI_ERR_RMA_CONFLICT:
    return MPIABI_ERR_RMA_CONFLICT;
  case MPI_ERR_RMA_FLAVOR:
    return MPIABI_ERR_RMA_FLAVOR;
  case MPI_ERR_RMA_RANGE:
    return MPIABI_ERR_RMA_RANGE;
  case MPI_ERR_RMA_SHARED:
    return MPIABI_ERR_RMA_SHARED;
  case MPI_ERR_RMA_SYNC:
    return MPIABI_ERR_RMA_SYNC;
  case MPI_ERR_ROOT:
    return MPIABI_ERR_ROOT;
  case MPI_ERR_SERVICE:
    return MPIABI_ERR_SERVICE;
#if MPI_VERSION_NUMBER >= 400
  case MPI_ERR_SESSION:
    return MPIABI_ERR_SESSION;
#endif
  case MPI_ERR_SIZE:
    return MPIABI_ERR_SIZE;
  case MPI_ERR_SPAWN:
    return MPIABI_ERR_SPAWN;
  case MPI_ERR_TAG:
    return MPIABI_ERR_TAG;
  case MPI_ERR_TOPOLOGY:
    return MPIABI_ERR_TOPOLOGY;
  case MPI_ERR_TRUNCATE:
    return MPIABI_ERR_TRUNCATE;
  case MPI_ERR_TYPE:
    return MPIABI_ERR_TYPE;
  case MPI_ERR_UNKNOWN:
    return MPIABI_ERR_UNKNOWN;
  case MPI_ERR_UNSUPPORTED_DATAREP:
    return MPIABI_ERR_UNSUPPORTED_DATAREP;
  case MPI_ERR_UNSUPPORTED_OPERATION:
    return MPIABI_ERR_UNSUPPORTED_OPERATION;
#if MPI_VERSION_NUMBER >= 400
  case MPI_ERR_VALUE_TOO_LARGE:
    return MPIABI_ERR_VALUE_TOO_LARGE;
#endif
  case MPI_ERR_WIN:
    return MPIABI_ERR_WIN;
  default:
    // unknown error code
    // assert(false);
    return errorcode;
  }
}

static int abi2mpi_keyval(int keyval) {
  switch (keyval) {
  case MPIABI_KEYVAL_INVALID:
    return MPI_KEYVAL_INVALID;
  case MPIABI_TAG_UB:
    return MPI_TAG_UB;
  case MPIABI_IO:
    return MPI_IO;
  case MPIABI_HOST:
    return MPI_HOST;
  case MPIABI_WTIME_IS_GLOBAL:
    return MPI_WTIME_IS_GLOBAL;
  case MPIABI_APPNUM:
    return MPI_APPNUM;
  case MPIABI_LASTUSEDCODE:
    return MPI_LASTUSEDCODE;
  case MPIABI_UNIVERSE_SIZE:
    return MPI_UNIVERSE_SIZE;
  case MPIABI_WIN_BASE:
    return MPI_WIN_BASE;
  case MPIABI_WIN_DISP_UNIT:
    return MPI_WIN_DISP_UNIT;
  case MPIABI_WIN_SIZE:
    return MPI_WIN_SIZE;
  case MPIABI_WIN_CREATE_FLAVOR:
    return MPI_WIN_CREATE_FLAVOR;
  case MPIABI_WIN_MODEL:
    return MPI_WIN_MODEL;
  default:
    return keyval;
  }
}

static int mpi2abi_keyval(int keyval) {
  switch (keyval) {
  case MPI_KEYVAL_INVALID:
    return MPIABI_KEYVAL_INVALID;
  case MPI_TAG_UB:
    return MPIABI_TAG_UB;
  case MPI_IO:
    return MPIABI_IO;
  case MPI_HOST:
    return MPIABI_HOST;
  case MPI_WTIME_IS_GLOBAL:
    return MPIABI_WTIME_IS_GLOBAL;
  case MPI_APPNUM:
    return MPIABI_APPNUM;
  case MPI_LASTUSEDCODE:
    return MPIABI_LASTUSEDCODE;
  case MPI_UNIVERSE_SIZE:
    return MPIABI_UNIVERSE_SIZE;
  case MPI_WIN_BASE:
    return MPIABI_WIN_BASE;
  case MPI_WIN_DISP_UNIT:
    return MPIABI_WIN_DISP_UNIT;
  case MPI_WIN_SIZE:
    return MPIABI_WIN_SIZE;
  case MPI_WIN_CREATE_FLAVOR:
    return MPIABI_WIN_CREATE_FLAVOR;
  case MPI_WIN_MODEL:
    return MPIABI_WIN_MODEL;
  default:
    return keyval;
  }
}

static int abi2mpi_mode(int abi_mode) {
  int mpi_mode = 0;
  if (abi_mode & MPIABI_MODE_APPEND)
    mpi_mode |= MPI_MODE_APPEND;
  if (abi_mode & MPIABI_MODE_CREATE)
    mpi_mode |= MPI_MODE_CREATE;
  if (abi_mode & MPIABI_MODE_DELETE_ON_CLOSE)
    mpi_mode |= MPI_MODE_DELETE_ON_CLOSE;
  if (abi_mode & MPIABI_MODE_EXCL)
    mpi_mode |= MPI_MODE_EXCL;
  if (abi_mode & MPIABI_MODE_NOCHECK)
    mpi_mode |= MPI_MODE_NOCHECK;
  if (abi_mode & MPIABI_MODE_NOPRECEDE)
    mpi_mode |= MPI_MODE_NOPRECEDE;
  if (abi_mode & MPIABI_MODE_NOPUT)
    mpi_mode |= MPI_MODE_NOPUT;
  if (abi_mode & MPIABI_MODE_NOSTORE)
    mpi_mode |= MPI_MODE_NOSTORE;
  if (abi_mode & MPIABI_MODE_NOSUCCEED)
    mpi_mode |= MPI_MODE_NOSUCCEED;
  if (abi_mode & MPIABI_MODE_RDONLY)
    mpi_mode |= MPI_MODE_RDONLY;
  if (abi_mode & MPIABI_MODE_RDWR)
    mpi_mode |= MPI_MODE_RDWR;
  if (abi_mode & MPIABI_MODE_SEQUENTIAL)
    mpi_mode |= MPI_MODE_SEQUENTIAL;
  if (abi_mode & MPIABI_MODE_UNIQUE_OPEN)
    mpi_mode |= MPI_MODE_UNIQUE_OPEN;
  if (abi_mode & MPIABI_MODE_WRONLY)
    mpi_mode |= MPI_MODE_WRONLY;
  return mpi_mode;
}

static int abi2mpi_order(int order) {
  switch (order) {
  case MPIABI_ORDER_C:
    return MPI_ORDER_C;
  case MPIABI_ORDER_FORTRAN:
    return MPI_ORDER_FORTRAN;
  default:
    assert(false);
  }
}

static int abi2mpi_proc(int proc) {
  switch (proc) {
  case MPIABI_ANY_SOURCE:
    return MPI_ANY_SOURCE;
  case MPIABI_PROC_NULL:
    return MPI_PROC_NULL;
  default:
    assert(proc >= 0);
    return proc;
  }
}

static int mpi2abi_proc(int proc) {
  switch (proc) {
  case MPI_ANY_SOURCE:
    return MPIABI_ANY_SOURCE;
  case MPI_PROC_NULL:
    return MPIABI_PROC_NULL;
  default:
    assert(proc >= 0);
    return proc;
  }
}

static int abi2mpi_root(int root) {
  switch (root) {
  case MPIABI_ROOT:
    return MPI_ROOT;
  default:
    assert(root >= 0);
    return root;
  }
}

static int abi2mpi_tag(int tag) {
  switch (tag) {
  case MPIABI_ANY_TAG:
    return MPI_ANY_TAG;
  default:
    assert(tag >= 0);
    return tag;
  }
}

static int mpi2abi_tag(int tag) {
  switch (tag) {
  case MPI_ANY_TAG:
    return MPIABI_ANY_TAG;
  default:
    assert(tag >= 0);
    return tag;
  }
}

static int abi2mpi_threadlevel(int threadlevel) {
  switch (threadlevel) {
  case MPIABI_THREAD_FUNNELED:
    return MPI_THREAD_FUNNELED;
  case MPIABI_THREAD_MULTIPLE:
    return MPI_THREAD_MULTIPLE;
  case MPIABI_THREAD_SERIALIZED:
    return MPI_THREAD_SERIALIZED;
  case MPIABI_THREAD_SINGLE:
    return MPI_THREAD_SINGLE;
    return MPIABI_ANY_TAG;
  default:
    assert(false);
  }
}

static int mpi2abi_threadlevel(int threadlevel) {
  switch (threadlevel) {
  case MPI_THREAD_FUNNELED:
    return MPIABI_THREAD_FUNNELED;
  case MPI_THREAD_MULTIPLE:
    return MPIABI_THREAD_MULTIPLE;
  case MPI_THREAD_SERIALIZED:
    return MPIABI_THREAD_SERIALIZED;
  case MPI_THREAD_SINGLE:
    return MPIABI_THREAD_SINGLE;
    return MPIABI_ANY_TAG;
  default:
    assert(false);
  }
}

static int abi2mpi_whence(int whence) {
  switch (whence) {
  case MPIABI_SEEK_CUR:
    return MPI_SEEK_CUR;
  case MPIABI_SEEK_END:
    return MPI_SEEK_END;
  case MPIABI_SEEK_SET:
    return MPI_SEEK_SET;
  default:
    assert(false);
  }
}

static const void *abi2mpi_buffer(const void *buffer) {
  if (buffer == MPIABI_IN_PLACE)
    return MPI_IN_PLACE;
  return buffer;
}

static MPI_Comm abi2mpi_comm(MPIABI_Comm comm) {
  if (!handle_is_reserved((uintptr_t)comm))
    return (MPI_Comm)abi2mpi_unreserved((uintptr_t)comm);
  switch ((uintptr_t)comm) {
  case (uintptr_t)MPIABI_COMM_NULL:
    return MPI_COMM_NULL;
  case (uintptr_t)MPIABI_COMM_SELF:
    return MPI_COMM_SELF;
  case (uintptr_t)MPIABI_COMM_WORLD:
    return MPI_COMM_WORLD;
  default:
    assert(false);
  }
}

static MPIABI_Comm mpi2abi_comm(MPI_Comm comm) {
  if (comm == MPI_COMM_NULL)
    return MPIABI_COMM_NULL;
  if (comm == MPI_COMM_SELF)
    return MPIABI_COMM_SELF;
  if (comm == MPI_COMM_WORLD)
    return MPIABI_COMM_WORLD;
  return (MPIABI_Comm)mpi2abi_unreserved((uintptr_t)comm);
}

static MPI_Datatype abi2mpi_datatype(MPIABI_Datatype datatype) {
  if (!handle_is_reserved((uintptr_t)datatype))
    return (MPI_Datatype)abi2mpi_unreserved((uintptr_t)datatype);
  switch ((uintptr_t)datatype) {
  case (uintptr_t)MPIABI_DATATYPE_NULL:
    return MPI_DATATYPE_NULL;
  // [C types]
  case (uintptr_t)MPIABI_CHAR:
    return MPI_CHAR;
  case (uintptr_t)MPIABI_SHORT:
    return MPI_SHORT;
  case (uintptr_t)MPIABI_INT:
    return MPI_INT;
  case (uintptr_t)MPIABI_LONG:
    return MPI_LONG;
  case (uintptr_t)MPIABI_LONG_LONG_INT:
    return MPI_LONG_LONG_INT;
  // case (uintptr_t)MPIABI_LONG_LONG:
  //   return MPI_LONG_LONG;
  case (uintptr_t)MPIABI_SIGNED_CHAR:
    return MPI_SIGNED_CHAR;
  case (uintptr_t)MPIABI_UNSIGNED_CHAR:
    return MPI_UNSIGNED_CHAR;
  case (uintptr_t)MPIABI_UNSIGNED_SHORT:
    return MPI_UNSIGNED_SHORT;
  case (uintptr_t)MPIABI_UNSIGNED:
    return MPI_UNSIGNED;
  case (uintptr_t)MPIABI_UNSIGNED_LONG:
    return MPI_UNSIGNED_LONG;
  case (uintptr_t)MPIABI_UNSIGNED_LONG_LONG:
    return MPI_UNSIGNED_LONG_LONG;
  case (uintptr_t)MPIABI_FLOAT:
    return MPI_FLOAT;
  case (uintptr_t)MPIABI_DOUBLE:
    return MPI_DOUBLE;
  case (uintptr_t)MPIABI_LONG_DOUBLE:
    return MPI_LONG_DOUBLE;
  case (uintptr_t)MPIABI_WCHAR:
    return MPI_WCHAR;
  case (uintptr_t)MPIABI_C_BOOL:
    return MPI_C_BOOL;
  case (uintptr_t)MPIABI_INT8_T:
    return MPI_INT8_T;
  case (uintptr_t)MPIABI_INT16_T:
    return MPI_INT16_T;
  case (uintptr_t)MPIABI_INT32_T:
    return MPI_INT32_T;
  case (uintptr_t)MPIABI_INT64_T:
    return MPI_INT64_T;
  case (uintptr_t)MPIABI_UINT8_T:
    return MPI_UINT8_T;
  case (uintptr_t)MPIABI_UINT16_T:
    return MPI_UINT16_T;
  case (uintptr_t)MPIABI_UINT32_T:
    return MPI_UINT32_T;
  case (uintptr_t)MPIABI_UINT64_T:
    return MPI_UINT64_T;
  case (uintptr_t)MPIABI_AINT:
    return MPI_AINT;
  case (uintptr_t)MPIABI_COUNT:
    return MPI_COUNT;
  case (uintptr_t)MPIABI_OFFSET:
    return MPI_OFFSET;
  case (uintptr_t)MPIABI_C_COMPLEX:
    return MPI_C_COMPLEX;
    // case (uintptr_t)MPIABI_C_FLOAT_COMPLEX:
    //   return MPI_C_FLOAT_COMPLEX;
  case (uintptr_t)MPIABI_C_DOUBLE_COMPLEX:
    return MPI_C_DOUBLE_COMPLEX;
  case (uintptr_t)MPIABI_C_LONG_DOUBLE_COMPLEX:
    return MPI_C_LONG_DOUBLE_COMPLEX;
  case (uintptr_t)MPIABI_BYTE:
    return MPI_BYTE;
  case (uintptr_t)MPIABI_PACKED:
    return MPI_PACKED;
    // [Fortran types]
  case (uintptr_t)MPIABI_INTEGER:
    return MPI_INTEGER;
  case (uintptr_t)MPIABI_REAL:
    return MPI_REAL;
  case (uintptr_t)MPIABI_DOUBLE_PRECISION:
    return MPI_DOUBLE_PRECISION;
  case (uintptr_t)MPIABI_COMPLEX:
    return MPI_COMPLEX;
  case (uintptr_t)MPIABI_LOGICAL:
    return MPI_LOGICAL;
  case (uintptr_t)MPIABI_CHARACTER:
    return MPI_CHARACTER;
    // [C++ types]
  case (uintptr_t)MPIABI_CXX_BOOL:
    return MPI_CXX_BOOL;
  case (uintptr_t)MPIABI_CXX_FLOAT_COMPLEX:
    return MPI_CXX_FLOAT_COMPLEX;
  case (uintptr_t)MPIABI_CXX_DOUBLE_COMPLEX:
    return MPI_CXX_DOUBLE_COMPLEX;
  case (uintptr_t)MPIABI_CXX_LONG_DOUBLE_COMPLEX:
    return MPI_CXX_LONG_DOUBLE_COMPLEX;
    // [Optional datatypes (Fortran)]
  case (uintptr_t)MPIABI_DOUBLE_COMPLEX:
    return MPI_DOUBLE_COMPLEX;
#ifdef HAVE_MPI_INTEGER1
  case (uintptr_t)MPIABI_INTEGER1:
    return MPI_INTEGER1;
#endif
#ifdef HAVE_MPI_INTEGER2
  case (uintptr_t)MPIABI_INTEGER2:
    return MPI_INTEGER2;
#endif
#ifdef HAVE_MPI_INTEGER4
  case (uintptr_t)MPIABI_INTEGER4:
    return MPI_INTEGER4;
#endif
#ifdef HAVE_MPI_INTEGER8
  case (uintptr_t)MPIABI_INTEGER8:
    return MPI_INTEGER8;
#endif
#ifdef HAVE_MPI_INTEGER16
  case (uintptr_t)MPIABI_INTEGER16:
    return MPI_INTEGER16;
#endif
#ifdef HAVE_MPI_REAL2
  case (uintptr_t)MPIABI_REAL2:
    return MPI_REAL2;
#endif
#ifdef HAVE_MPI_REAL4
  case (uintptr_t)MPIABI_REAL4:
    return MPI_REAL4;
#endif
#ifdef HAVE_MPI_REAL8
  case (uintptr_t)MPIABI_REAL8:
    return MPI_REAL8;
#endif
#ifdef HAVE_MPI_REAL16
  case (uintptr_t)MPIABI_REAL16:
    return MPI_REAL16;
#endif
#ifdef HAVE_MPI_COMPLEX2
  case (uintptr_t)MPIABI_COMPLEX2:
    return MPI_COMPLEX2;
#endif
#ifdef HAVE_MPI_COMPLEX4
  case (uintptr_t)MPIABI_COMPLEX4:
    return MPI_COMPLEX4;
#endif
#ifdef HAVE_MPI_COMPLEX8
  case (uintptr_t)MPIABI_COMPLEX8:
    return MPI_COMPLEX8;
#endif
#ifdef HAVE_MPI_COMPLEX16
  case (uintptr_t)MPIABI_COMPLEX16:
    return MPI_COMPLEX16;
#endif
#ifdef HAVE_MPI_COMPLEX32
  case (uintptr_t)MPIABI_COMPLEX32:
    return MPI_COMPLEX32;
#endif
    // [Extensions]
#ifdef HAVE_MPI_REAL1
  case (uintptr_t)MPIABI_REAL1:
    return MPI_REAL1;
#endif
#ifdef HAVE_MPI_LOGICAL1
  case (uintptr_t)MPIABI_LOGICAL1:
    return MPI_LOGICAL1;
#endif
#ifdef HAVE_MPI_LOGICAL2
  case (uintptr_t)MPIABI_LOGICAL2:
    return MPI_LOGICAL2;
#endif
#ifdef HAVE_MPI_LOGICAL4
  case (uintptr_t)MPIABI_LOGICAL4:
    return MPI_LOGICAL4;
#endif
#ifdef HAVE_MPI_LOGICAL8
  case (uintptr_t)MPIABI_LOGICAL8:
    return MPI_LOGICAL8;
#endif
    // [Datatypes for reduction functions (C)]
  case (uintptr_t)MPIABI_FLOAT_INT:
    return MPI_FLOAT_INT;
  case (uintptr_t)MPIABI_DOUBLE_INT:
    return MPI_DOUBLE_INT;
  case (uintptr_t)MPIABI_LONG_INT:
    return MPI_LONG_INT;
  case (uintptr_t)MPIABI_2INT:
    return MPI_2INT;
  case (uintptr_t)MPIABI_SHORT_INT:
    return MPI_SHORT_INT;
  case (uintptr_t)MPIABI_LONG_DOUBLE_INT:
    return MPI_LONG_DOUBLE_INT;
    // [Datatypes for reduction functions (Fortran)]
  case (uintptr_t)MPIABI_2REAL:
    return MPI_2REAL;
  case (uintptr_t)MPIABI_2DOUBLE_PRECISION:
    return MPI_2DOUBLE_PRECISION;
  case (uintptr_t)MPIABI_2INTEGER:
    return MPI_2INTEGER;
    // [Removed constructs]
#ifdef HAVE_MPI_LB
  case (uintptr_t)MPIABI_LB:
    return MPI_LB;
#endif
#ifdef HAVE_MPI_UB
  case (uintptr_t)MPIABI_UB:
    return MPI_UB;
#endif
  default:
    assert(false);
  }
}

static MPIABI_Datatype mpi2abi_datatype(MPI_Datatype datatype) {
  if (datatype == MPI_DATATYPE_NULL)
    return MPIABI_DATATYPE_NULL;
  // [C types]
  if (datatype == MPI_CHAR)
    return MPIABI_CHAR;
  if (datatype == MPI_SHORT)
    return MPIABI_SHORT;
  if (datatype == MPI_INT)
    return MPIABI_INT;
  if (datatype == MPI_LONG)
    return MPIABI_LONG;
  if (datatype == MPI_LONG_LONG_INT)
    return MPIABI_LONG_LONG_INT;
  if (datatype == MPI_LONG_LONG)
    return MPIABI_LONG_LONG;
  if (datatype == MPI_SIGNED_CHAR)
    return MPIABI_SIGNED_CHAR;
  if (datatype == MPI_UNSIGNED_CHAR)
    return MPIABI_UNSIGNED_CHAR;
  if (datatype == MPI_UNSIGNED_SHORT)
    return MPIABI_UNSIGNED_SHORT;
  if (datatype == MPI_UNSIGNED)
    return MPIABI_UNSIGNED;
  if (datatype == MPI_UNSIGNED_LONG)
    return MPIABI_UNSIGNED_LONG;
  if (datatype == MPI_UNSIGNED_LONG_LONG)
    return MPIABI_UNSIGNED_LONG_LONG;
  if (datatype == MPI_FLOAT)
    return MPIABI_FLOAT;
  if (datatype == MPI_DOUBLE)
    return MPIABI_DOUBLE;
  if (datatype == MPI_LONG_DOUBLE)
    return MPIABI_LONG_DOUBLE;
  if (datatype == MPI_WCHAR)
    return MPIABI_WCHAR;
  if (datatype == MPI_C_BOOL)
    return MPIABI_C_BOOL;
  if (datatype == MPI_INT8_T)
    return MPIABI_INT8_T;
  if (datatype == MPI_INT16_T)
    return MPIABI_INT16_T;
  if (datatype == MPI_INT32_T)
    return MPIABI_INT32_T;
  if (datatype == MPI_INT64_T)
    return MPIABI_INT64_T;
  if (datatype == MPI_UINT8_T)
    return MPIABI_UINT8_T;
  if (datatype == MPI_UINT16_T)
    return MPIABI_UINT16_T;
  if (datatype == MPI_UINT32_T)
    return MPIABI_UINT32_T;
  if (datatype == MPI_UINT64_T)
    return MPIABI_UINT64_T;
  if (datatype == MPI_AINT)
    return MPIABI_AINT;
  if (datatype == MPI_COUNT)
    return MPIABI_COUNT;
  if (datatype == MPI_OFFSET)
    return MPIABI_OFFSET;
  if (datatype == MPI_C_COMPLEX)
    return MPIABI_C_COMPLEX;
  if (datatype == MPI_C_FLOAT_COMPLEX)
    return MPIABI_C_FLOAT_COMPLEX;
  if (datatype == MPI_C_DOUBLE_COMPLEX)
    return MPIABI_C_DOUBLE_COMPLEX;
  if (datatype == MPI_C_LONG_DOUBLE_COMPLEX)
    return MPIABI_C_LONG_DOUBLE_COMPLEX;
  if (datatype == MPI_BYTE)
    return MPIABI_BYTE;
  if (datatype == MPI_PACKED)
    return MPIABI_PACKED;
  // [Fortran types]
  if (datatype == MPI_INTEGER)
    return MPIABI_INTEGER;
  if (datatype == MPI_REAL)
    return MPIABI_REAL;
  if (datatype == MPI_DOUBLE_PRECISION)
    return MPIABI_DOUBLE_PRECISION;
  if (datatype == MPI_COMPLEX)
    return MPIABI_COMPLEX;
  if (datatype == MPI_LOGICAL)
    return MPIABI_LOGICAL;
  if (datatype == MPI_CHARACTER)
    return MPIABI_CHARACTER;
  // [C++ types]
  if (datatype == MPI_CXX_BOOL)
    return MPIABI_CXX_BOOL;
  if (datatype == MPI_CXX_FLOAT_COMPLEX)
    return MPIABI_CXX_FLOAT_COMPLEX;
  if (datatype == MPI_CXX_DOUBLE_COMPLEX)
    return MPIABI_CXX_DOUBLE_COMPLEX;
  if (datatype == MPI_CXX_LONG_DOUBLE_COMPLEX)
    return MPIABI_CXX_LONG_DOUBLE_COMPLEX;
  // [Optional datatypes (Fortran)]
  if (datatype == MPI_DOUBLE_COMPLEX)
    return MPIABI_DOUBLE_COMPLEX;
#ifdef HAVE_MPI_INTEGER1
  if (datatype == MPI_INTEGER1)
    return MPIABI_INTEGER1;
#endif
#ifdef HAVE_MPI_INTEGER2
  if (datatype == MPI_INTEGER2)
    return MPIABI_INTEGER2;
#endif
#ifdef HAVE_MPI_INTEGER4
  if (datatype == MPI_INTEGER4)
    return MPIABI_INTEGER4;
#endif
#ifdef HAVE_MPI_INTEGER8
  if (datatype == MPI_INTEGER8)
    return MPIABI_INTEGER8;
#endif
#ifdef HAVE_MPI_INTEGER16
  if (datatype == MPI_INTEGER16)
    return MPIABI_INTEGER16;
#endif
#ifdef HAVE_MPI_REAL2
  if (datatype == MPI_REAL2)
    return MPIABI_REAL2;
#endif
#ifdef HAVE_MPI_REAL4
  if (datatype == MPI_REAL4)
    return MPIABI_REAL4;
#endif
#ifdef HAVE_MPI_REAL8
  if (datatype == MPI_REAL8)
    return MPIABI_REAL8;
#endif
#ifdef HAVE_MPI_REAL16
  if (datatype == MPI_REAL16)
    return MPIABI_REAL16;
#endif
#ifdef HAVE_MPI_COMPLEX4
  if (datatype == MPI_COMPLEX4)
    return MPIABI_COMPLEX4;
#endif
#ifdef HAVE_MPI_COMPLEX8
  if (datatype == MPI_COMPLEX8)
    return MPIABI_COMPLEX8;
#endif
#ifdef HAVE_MPI_COMPLEX16
  if (datatype == MPI_COMPLEX16)
    return MPIABI_COMPLEX16;
#endif
#ifdef HAVE_MPI_COMPLEX32
  if (datatype == MPI_COMPLEX32)
    return MPIABI_COMPLEX32;
#endif
// [Extensions]
#ifdef HAVE_MPI_REAL1
  if (datatype == MPI_REAL1)
    return MPIABI_REAL1;
#endif
#ifdef HAVE_MPI_COMPLEX2
  if (datatype == MPI_COMPLEX2)
    return MPIABI_COMPLEX2;
#endif
#ifdef HAVE_MPI_LOGICAL1
  if (datatype == MPI_LOGICAL1)
    return MPIABI_LOGICAL1;
#endif
#ifdef HAVE_MPI_LOGICAL2
  if (datatype == MPI_LOGICAL2)
    return MPIABI_LOGICAL2;
#endif
#ifdef HAVE_MPI_LOGICAL4
  if (datatype == MPI_LOGICAL4)
    return MPIABI_LOGICAL4;
#endif
#ifdef HAVE_MPI_LOGICAL8
  if (datatype == MPI_LOGICAL8)
    return MPIABI_LOGICAL8;
#endif
#ifdef HAVE_MPI_LOGICAL16
  if (datatype == MPI_LOGICAL16)
    return MPIABI_LOGICAL16;
#endif
  // [Datatypes for reduction functions (C)]
  if (datatype == MPI_FLOAT_INT)
    return MPIABI_FLOAT_INT;
  if (datatype == MPI_DOUBLE_INT)
    return MPIABI_DOUBLE_INT;
  if (datatype == MPI_LONG_INT)
    return MPIABI_LONG_INT;
  if (datatype == MPI_2INT)
    return MPIABI_2INT;
  if (datatype == MPI_SHORT_INT)
    return MPIABI_SHORT_INT;
  if (datatype == MPI_LONG_DOUBLE_INT)
    return MPIABI_LONG_DOUBLE_INT;
  // [Datatypes for reduction functions (Fortran)]
  if (datatype == MPI_2REAL)
    return MPIABI_2REAL;
  if (datatype == MPI_2DOUBLE_PRECISION)
    return MPIABI_2DOUBLE_PRECISION;
  if (datatype == MPI_2INTEGER)
    return MPIABI_2INTEGER;
    // [Removed constructs]
#ifdef HAVE_MPI_LB
  if (datatype == MPI_LB)
    return MPIABI_LB;
#endif
#ifdef HAVE_MPI_UB
  if (datatype == MPI_UB)
    return MPIABI_UB;
#endif
  return (MPIABI_Datatype)mpi2abi_unreserved((uintptr_t)datatype);
}

static MPI_Errhandler abi2mpi_errhandler(MPIABI_Errhandler errhandler) {
  if (!handle_is_reserved((uintptr_t)errhandler))
    return (MPI_Errhandler)abi2mpi_unreserved((uintptr_t)errhandler);
  switch ((uintptr_t)errhandler) {
  case (uintptr_t)MPIABI_ERRHANDLER_NULL:
    return MPI_ERRHANDLER_NULL;
#if MPI_VERSION_NUMBER >= 400
  case (uintptr_t)MPIABI_ERRORS_ABORT:
    return MPI_ERRORS_ABORT;
#endif
  case (uintptr_t)MPIABI_ERRORS_ARE_FATAL:
    return MPI_ERRORS_ARE_FATAL;
  case (uintptr_t)MPIABI_ERRORS_RETURN:
    return MPI_ERRORS_RETURN;
  default:
    assert(false);
  }
}

static MPIABI_Errhandler mpi2abi_errhandler(MPI_Errhandler errhandler) {
  if (errhandler == MPI_ERRHANDLER_NULL)
    return MPIABI_ERRHANDLER_NULL;
#if MPI_VERSION_NUMBER >= 400
  if (errhandler == MPI_ERRORS_ABORT)
    return MPIABI_ERRORS_ABORT;
#endif
  if (errhandler == MPI_ERRORS_ARE_FATAL)
    return MPIABI_ERRORS_ARE_FATAL;
  if (errhandler == MPI_ERRORS_RETURN)
    return MPIABI_ERRORS_RETURN;
  return (MPIABI_Errhandler)mpi2abi_unreserved((uintptr_t)errhandler);
}

static MPI_File abi2mpi_file(MPIABI_File file) {
  if (!handle_is_reserved((uintptr_t)file))
    return (MPI_File)abi2mpi_unreserved((uintptr_t)file);
  switch ((uintptr_t)file) {
  case (uintptr_t)MPIABI_FILE_NULL:
    return MPI_FILE_NULL;
  default:
    assert(false);
  }
}

static MPIABI_File mpi2abi_file(MPI_File file) {
  if (file == MPI_FILE_NULL)
    return MPIABI_FILE_NULL;
  return (MPIABI_File)mpi2abi_unreserved((uintptr_t)file);
}

static MPI_Group abi2mpi_group(MPIABI_Group group) {
  if (!handle_is_reserved((uintptr_t)group))
    return (MPI_Group)abi2mpi_unreserved((uintptr_t)group);
  switch ((uintptr_t)group) {
  case (uintptr_t)MPIABI_GROUP_EMPTY:
    return MPI_GROUP_EMPTY;
  case (uintptr_t)MPIABI_GROUP_NULL:
    return MPI_GROUP_NULL;
  default:
    assert(false);
  }
}

static MPIABI_Group mpi2abi_group(MPI_Group group) {
  if (group == MPI_GROUP_EMPTY)
    return MPIABI_GROUP_EMPTY;
  if (group == MPI_GROUP_NULL)
    return MPIABI_GROUP_NULL;
  return (MPIABI_Group)mpi2abi_unreserved((uintptr_t)group);
}

static MPI_Info abi2mpi_info(MPIABI_Info info) {
  if (!handle_is_reserved((uintptr_t)info))
    return (MPI_Info)abi2mpi_unreserved((uintptr_t)info);
  switch ((uintptr_t)info) {
  case (uintptr_t)MPIABI_INFO_ENV:
    return MPI_INFO_ENV;
  case (uintptr_t)MPIABI_INFO_NULL:
    return MPI_INFO_NULL;
  default:
    assert(false);
  }
}

static MPIABI_Info mpi2abi_info(MPI_Info info) {
  if (info == MPI_INFO_ENV)
    return MPIABI_INFO_ENV;
  if (info == MPI_INFO_NULL)
    return MPIABI_INFO_NULL;
  return (MPIABI_Info)mpi2abi_unreserved((uintptr_t)info);
}

static MPI_Message abi2mpi_message(MPIABI_Message message) {
  if (!handle_is_reserved((uintptr_t)message))
    return (MPI_Message)abi2mpi_unreserved((uintptr_t)message);
  switch ((uintptr_t)message) {
  case (uintptr_t)MPIABI_MESSAGE_NO_PROC:
    return MPI_MESSAGE_NO_PROC;
  case (uintptr_t)MPIABI_MESSAGE_NULL:
    return MPI_MESSAGE_NULL;
  default:
    assert(false);
  }
}

static MPIABI_Message mpi2abi_message(MPI_Message message) {
  if (message == MPI_MESSAGE_NO_PROC)
    return MPIABI_MESSAGE_NO_PROC;
  if (message == MPI_MESSAGE_NULL)
    return MPIABI_MESSAGE_NULL;
  assert((uintptr_t)message > MAX_RESERVED_HANDLE);
  return (MPIABI_Message)mpi2abi_unreserved((uintptr_t)message);
}

static MPI_Op abi2mpi_op(MPIABI_Op op) {
  if (!handle_is_reserved((uintptr_t)op))
    return (MPI_Op)abi2mpi_unreserved((uintptr_t)op);
  switch ((uintptr_t)op) {
  case (uintptr_t)MPIABI_OP_NULL:
    return MPI_OP_NULL;
  case (uintptr_t)MPIABI_MAX:
    return MPI_MAX;
  case (uintptr_t)MPIABI_MIN:
    return MPI_MIN;
  case (uintptr_t)MPIABI_SUM:
    return MPI_SUM;
  case (uintptr_t)MPIABI_PROD:
    return MPI_PROD;
  case (uintptr_t)MPIABI_MAXLOC:
    return MPI_MAXLOC;
  case (uintptr_t)MPIABI_MINLOC:
    return MPI_MINLOC;
  case (uintptr_t)MPIABI_BAND:
    return MPI_BAND;
  case (uintptr_t)MPIABI_BOR:
    return MPI_BOR;
  case (uintptr_t)MPIABI_BXOR:
    return MPI_BXOR;
  case (uintptr_t)MPIABI_LAND:
    return MPI_LAND;
  case (uintptr_t)MPIABI_LOR:
    return MPI_LOR;
  case (uintptr_t)MPIABI_LXOR:
    return MPI_LXOR;
  case (uintptr_t)MPIABI_REPLACE:
    return MPI_REPLACE;
  case (uintptr_t)MPIABI_NO_OP:
    return MPI_NO_OP;
  default:
    assert(false);
  }
}

static MPIABI_Op mpi2abi_op(MPI_Op op) {
  if (op == MPI_OP_NULL)
    return MPIABI_OP_NULL;
  if (op == MPI_MAX)
    return MPIABI_MAX;
  if (op == MPI_MIN)
    return MPIABI_MIN;
  if (op == MPI_SUM)
    return MPIABI_SUM;
  if (op == MPI_PROD)
    return MPIABI_PROD;
  if (op == MPI_MAXLOC)
    return MPIABI_MAXLOC;
  if (op == MPI_MINLOC)
    return MPIABI_MINLOC;
  if (op == MPI_BAND)
    return MPIABI_BAND;
  if (op == MPI_BOR)
    return MPIABI_BOR;
  if (op == MPI_BXOR)
    return MPIABI_BXOR;
  if (op == MPI_LAND)
    return MPIABI_LAND;
  if (op == MPI_LOR)
    return MPIABI_LOR;
  if (op == MPI_LXOR)
    return MPIABI_LXOR;
  if (op == MPI_REPLACE)
    return MPIABI_REPLACE;
  if (op == MPI_NO_OP)
    return MPIABI_NO_OP;
  return (MPIABI_Op)mpi2abi_unreserved((uintptr_t)op);
}

static MPI_Request abi2mpi_request(MPIABI_Request request) {
  if (!handle_is_reserved((uintptr_t)request))
    return (MPI_Request)abi2mpi_unreserved((uintptr_t)request);
  switch ((uintptr_t)request) {
  case (uintptr_t)MPIABI_REQUEST_NULL:
    return MPI_REQUEST_NULL;
  default:
    assert(false);
  }
}

static MPIABI_Request mpi2abi_request(MPI_Request request) {
  if (request == MPI_REQUEST_NULL)
    return MPIABI_REQUEST_NULL;
  return (MPIABI_Request)mpi2abi_unreserved((uintptr_t)request);
}

static MPI_Session abi2mpi_session(MPIABI_Session session) {
  if (!handle_is_reserved((uintptr_t)session))
    return (MPI_Session)abi2mpi_unreserved((uintptr_t)session);
  switch ((uintptr_t)session) {
  case (uintptr_t)MPIABI_SESSION_NULL:
    return MPI_SESSION_NULL;
  default:
    assert(false);
  }
}

static MPIABI_Session mpi2abi_session(MPI_Session session) {
  if (session == MPI_SESSION_NULL)
    return MPIABI_SESSION_NULL;
  return (MPIABI_Session)mpi2abi_unreserved((uintptr_t)session);
}

static MPI_Win abi2mpi_win(MPIABI_Win win) {
  if (!handle_is_reserved((uintptr_t)win))
    return (MPI_Win)abi2mpi_unreserved((uintptr_t)win);
  switch ((uintptr_t)win) {
  case (uintptr_t)MPIABI_WIN_NULL:
    return MPI_WIN_NULL;
  default:
    assert(false);
  }
}

static MPIABI_Win mpi2abi_win(MPI_Win win) {
  if (win == MPI_WIN_NULL)
    return MPIABI_WIN_NULL;
  return (MPIABI_Win)mpi2abi_unreserved((uintptr_t)win);
}

static MPI_Status abi2mpi_status(MPIABI_Status abi_status) {
  MPI_Status mpi_status;
  // Copy named status fields
  mpi_status.MPI_SOURCE = abi2mpi_proc(abi_status.MPI_SOURCE);
  mpi_status.MPI_TAG = abi2mpi_tag(abi_status.MPI_TAG);
  mpi_status.MPI_ERROR = abi2mpi_errorcode(abi_status.MPI_ERROR);
  // Copy internal status fields
  _Static_assert(sizeof(MPI_Status) <= sizeof(MPIABI_Status), "");
  _Static_assert(sizeof(MPI_Status) % sizeof(int) == 0, "");
  _Static_assert(offsetof(MPI_Status, MPI_SOURCE) % sizeof(int) == 0, "");
  _Static_assert(offsetof(MPI_Status, MPI_TAG) % sizeof(int) == 0, "");
  _Static_assert(offsetof(MPI_Status, MPI_ERROR) % sizeof(int) == 0, "");
  size_t src = 0;
  for (size_t dest = 0; dest < sizeof(MPI_Status) / sizeof(int); ++dest)
    if (dest != offsetof(MPI_Status, MPI_SOURCE) / sizeof(int) &&
        dest != offsetof(MPI_Status, MPI_TAG) / sizeof(int) &&
        dest != offsetof(MPI_Status, MPI_ERROR) / sizeof(int))
      ((int *)&mpi_status)[dest] = abi_status.mpi_reserved[src++];
  return mpi_status;
}

static MPIABI_Status mpi2abi_status(MPI_Status mpi_status) {
  MPIABI_Status abi_status;
  // Copy named status fields
  abi_status.MPI_SOURCE = mpi2abi_proc(mpi_status.MPI_SOURCE);
  abi_status.MPI_TAG = mpi2abi_tag(mpi_status.MPI_TAG);
  abi_status.MPI_ERROR = mpi2abi_errorcode(mpi_status.MPI_ERROR);
  // Copy internal status fields
  _Static_assert(sizeof(MPI_Status) <= sizeof(MPIABI_Status), "");
  _Static_assert(sizeof(MPI_Status) % sizeof(int) == 0, "");
  _Static_assert(offsetof(MPI_Status, MPI_SOURCE) % sizeof(int) == 0, "");
  _Static_assert(offsetof(MPI_Status, MPI_TAG) % sizeof(int) == 0, "");
  _Static_assert(offsetof(MPI_Status, MPI_ERROR) % sizeof(int) == 0, "");
  size_t dest = 0;
  for (size_t src = 0; src < sizeof(MPI_Status) / sizeof(int); ++src)
    if (src != offsetof(MPI_Status, MPI_SOURCE) / sizeof(int) &&
        src != offsetof(MPI_Status, MPI_TAG) / sizeof(int) &&
        src != offsetof(MPI_Status, MPI_ERROR) / sizeof(int))
      abi_status.mpi_reserved[dest++] = ((const int *)&mpi_status)[src];
  return abi_status;
}

// Convert an `MPIABI_Status*` to an `MPI_Status*`. To avoid
// allocating memory, this reuses the storage for the `MPIABI_Status`
// object. We assume that `sizeof(MPIABI_Status) >=
// sizeof(MPI_Status)`.
static MPI_Status *abi2mpi_statusptr(MPIABI_Status *abi_status) {
  if (abi_status == MPIABI_STATUS_IGNORE)
    return MPI_STATUS_IGNORE;
  *(MPI_Status *)abi_status = abi2mpi_status(*abi_status);
  return (MPI_Status *)abi_status;
}

// Same as `abi2mpi_statusptr`, but skip initializing the `MPI_Status`
// object because the `MPIABI_Status` object is expected to be
// undefined.
static MPI_Status *abi2mpi_statusptr_uninitialized(MPIABI_Status *abi_status) {
  if (abi_status == MPIABI_STATUS_IGNORE)
    return MPI_STATUS_IGNORE;
  return (MPI_Status *)abi_status;
}

// Convert an `MPI_Status*` to an `MPIABI_Status*`. To avoid
// allocating memory, this reuses the storage for the `MPI_Status`
// object. We assume that the storage allocated for the `MPI_Status`
// object is large enough. This is the case if the `MPI_Status` is a
// reinterpreted `MPIABI_Status` as returned by `abi2mpi_statusptr`.
static MPIABI_Status *mpi2abi_statusptr(MPI_Status *mpi_status) {
  if (mpi_status == MPI_STATUS_IGNORE)
    return MPIABI_STATUS_IGNORE;
  *(MPIABI_Status *)mpi_status = mpi2abi_status(*mpi_status);
  return (MPIABI_Status *)mpi_status;
}

////////////////////////////////////////////////////////////////////////////////

// Prototype because this function is called by other functions

int MPIABI_Comm_size(MPIABI_Comm comm, int *rank);

////////////////////////////////////////////////////////////////////////////////

// A C lambda function (aka callback)

struct lambda {
  void (*function)(void *argument);
  void *argument;
};

////////////////////////////////////////////////////////////////////////////////

// We need to attach actions to MPI requests. These actions are run
// when the MPI request has completed. They are run after the MPI
// request has completed but before the MPIABI request has completed.

// This does not work for persistent requests.

#define MAX_NUM_REQUEST_ACTIONS 10
static atomic_int num_request_actions = 0;
static pthread_mutex_t request_actions_mutex = PTHREAD_MUTEX_INITIALIZER;
static MPIABI_Request request_action_keys[MAX_NUM_REQUEST_ACTIONS] = {
    MPIABI_REQUEST_NULL, MPIABI_REQUEST_NULL, MPIABI_REQUEST_NULL,
    MPIABI_REQUEST_NULL, MPIABI_REQUEST_NULL, MPIABI_REQUEST_NULL,
    MPIABI_REQUEST_NULL, MPIABI_REQUEST_NULL, MPIABI_REQUEST_NULL,
    MPIABI_REQUEST_NULL,
};
static struct lambda request_action_values[MAX_NUM_REQUEST_ACTIONS];

static void request_action_insert(MPIABI_Request request,
                                  struct lambda action) {
  pthread_mutex_lock(&request_actions_mutex);
  const int my_action =
      atomic_fetch_add_explicit(&num_request_actions, 1, memory_order_relaxed);
  assert(my_action < MAX_NUM_REQUEST_ACTIONS);
  request_action_keys[my_action] = request;
  request_action_values[my_action] = action;
  pthread_mutex_unlock(&request_actions_mutex);
}

static void request_action_find(MPIABI_Request request, bool *restrict found,
                                struct lambda *restrict action) {
  *found = false;
  pthread_mutex_lock(&request_actions_mutex);
  for (int my_action = 0; my_action < num_request_actions; ++my_action) {
    if (request_action_keys[my_action] == request) {
      *found = true;
      *action = request_action_values[my_action];
      const int other_action =
          atomic_load_explicit(&num_request_actions, memory_order_relaxed) - 1;
      if (my_action < other_action) {
        request_action_keys[my_action] = request_action_keys[other_action];
        request_action_values[my_action] = request_action_values[other_action];
      }
      atomic_store_explicit(&num_request_actions, other_action,
                            memory_order_relaxed);
      break;
    }
  }
  pthread_mutex_unlock(&request_actions_mutex);
}

static void request_action_apply_slow(MPIABI_Request request) {
  bool found;
  struct lambda action;
  request_action_find(request, &found, &action);
  if (found)
    action.function(action.argument);
}

static inline bool request_actions_empty() {
  return __builtin_expect(atomic_load(&num_request_actions) == 0, true);
}

static inline void request_action_apply(MPIABI_Request request) {
  if (request == MPIABI_REQUEST_NULL)
    return;
  if (__builtin_expect(atomic_load(&num_request_actions) == 0, true))
    return;
  request_action_apply_slow(request);
}

////////////////////////////////////////////////////////////////////////////////

// Define MPIABI functions

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

int MPIABI_Bsend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
                 int tag, MPIABI_Comm comm) {
  int ierr =
      MPI_Bsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                abi2mpi_tag(tag), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bsend_c(const void *buf, MPIABI_Count count,
                   MPIABI_Datatype datatype, int dest, int tag,
                   MPIABI_Comm comm) {
  int ierr =
      MPI_Bsend_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                  abi2mpi_tag(tag), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bsend_init(const void *buf, int count, MPIABI_Datatype datatype,
                      int dest, int tag, MPIABI_Comm comm,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Bsend_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                     abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bsend_init_c(const void *buf, MPIABI_Count count,
                        MPIABI_Datatype datatype, int dest, int tag,
                        MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Bsend_init_c(buf, count, abi2mpi_datatype(datatype),
                              abi2mpi_proc(dest), abi2mpi_tag(tag),
                              abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Buffer_attach(void *buffer, int size) {
  if (buffer == MPIABI_BUFFER_AUTOMATIC)
    buffer = MPI_BUFFER_AUTOMATIC;
  int ierr = MPI_Buffer_attach(buffer, size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Buffer_attach_c(void *buffer, MPIABI_Count size) {
  if (buffer == MPIABI_BUFFER_AUTOMATIC)
    buffer = MPI_BUFFER_AUTOMATIC;
  int ierr = MPI_Buffer_attach_c(buffer, size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Buffer_detach(void *buffer_addr, int *size) {
  int ierr = MPI_Buffer_detach(buffer_addr, size);
  if (*(void **)buffer_addr == MPI_BUFFER_AUTOMATIC)
    *(void **)buffer_addr = MPIABI_BUFFER_AUTOMATIC;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Buffer_detach_c(void *buffer_addr, MPIABI_Count *size) {
  MPI_Count mpi_size;
  int ierr = MPI_Buffer_detach_c(buffer_addr, &mpi_size);
  if (*(void **)buffer_addr == MPI_BUFFER_AUTOMATIC)
    *(void **)buffer_addr = MPIABI_BUFFER_AUTOMATIC;
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Buffer_flush(void) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Buffer_flush();
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Buffer_iflush(MPIABI_Request *request) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Request mpi_request;
  int ierr = MPI_Buffer_iflush(&mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Cancel(MPIABI_Request *request) {
  MPI_Request mpi_request = abi2mpi_request(*request);
  int ierr = MPI_Cancel(&mpi_request);
  request_action_apply(*request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_attach_buffer(MPIABI_Comm comm, void *buffer, int size) {
#if MPI_VERSION_NUMBER >= 410
  if (buffer == MPIABI_BUFFER_AUTOMATIC)
    buffer = MPI_BUFFER_AUTOMATIC;
  int ierr = MPI_Comm_attach_buffer(abi2mpi_comm(comm), buffer, size);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Comm_attach_buffer_c(MPIABI_Comm comm, void *buffer,
                                MPIABI_Count size) {
#if MPI_VERSION_NUMBER >= 410
  if (buffer == MPIABI_BUFFER_AUTOMATIC)
    buffer = MPI_BUFFER_AUTOMATIC;
  int ierr = MPI_Comm_attach_buffer_c(abi2mpi_comm(comm), buffer, size);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Comm_detach_buffer(MPIABI_Comm comm, void *buffer_addr, int *size) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Comm_detach_buffer(abi2mpi_comm(comm), buffer_addr, size);
  if (*(void **)buffer_addr == MPI_BUFFER_AUTOMATIC)
    *(void **)buffer_addr = MPIABI_BUFFER_AUTOMATIC;
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Comm_detach_buffer_c(MPIABI_Comm comm, void *buffer_addr,
                                MPIABI_Count *size) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Count mpi_size;
  int ierr =
      MPI_Comm_detach_buffer_c(abi2mpi_comm(comm), buffer_addr, &mpi_size);
  if (*(void **)buffer_addr == MPI_BUFFER_AUTOMATIC)
    *(void **)buffer_addr = MPIABI_BUFFER_AUTOMATIC;
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Comm_flush_buffer(MPIABI_Comm comm) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Comm_flush_buffer(abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Comm_iflush_buffer(MPIABI_Comm comm, MPIABI_Request *request) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Request mpi_request;
  int ierr = MPI_Comm_iflush_buffer(abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Get_count(const MPIABI_Status *status, MPIABI_Datatype datatype,
                     int *count) {
  const MPI_Status mpi_status = abi2mpi_status(*status);
  int ierr = MPI_Get_count(&mpi_status, abi2mpi_datatype(datatype), count);
  *count = mpi2abi_count(*count);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_count_c(const MPIABI_Status *status, MPIABI_Datatype datatype,
                       MPIABI_Count *count) {
  const MPI_Status mpi_status = abi2mpi_status(*status);
  MPI_Count mpi_count;
  int ierr =
      MPI_Get_count_c(&mpi_status, abi2mpi_datatype(datatype), &mpi_count);
  *count = mpi_count;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ibsend(const void *buf, int count, MPIABI_Datatype datatype,
                  int dest, int tag, MPIABI_Comm comm,
                  MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Ibsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                 abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ibsend_c(const void *buf, MPIABI_Count count,
                    MPIABI_Datatype datatype, int dest, int tag,
                    MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Ibsend_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                   abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Improbe(int source, int tag, MPIABI_Comm comm, int *flag,
                   MPIABI_Message *message, MPIABI_Status *status) {
  MPI_Message mpi_message;
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Improbe(abi2mpi_proc(source), abi2mpi_tag(tag),
                         abi2mpi_comm(comm), flag, &mpi_message, mpi_status);
  *message = mpi2abi_message(mpi_message);
  if (*flag)
    mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Imrecv(void *buf, int count, MPIABI_Datatype datatype,
                  MPIABI_Message *message, MPIABI_Request *request) {
  MPI_Message mpi_message;
  MPI_Request mpi_request;
  int ierr = MPI_Imrecv(buf, count, abi2mpi_datatype(datatype), &mpi_message,
                        &mpi_request);
  *message = mpi2abi_message(mpi_message);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Imrecv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
                    MPIABI_Message *message, MPIABI_Request *request) {
  MPI_Message mpi_message;
  MPI_Request mpi_request;
  int ierr = MPI_Imrecv_c(buf, count, abi2mpi_datatype(datatype), &mpi_message,
                          &mpi_request);
  *message = mpi2abi_message(mpi_message);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iprobe(int source, int tag, MPIABI_Comm comm, int *flag,
                  MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Iprobe(abi2mpi_proc(source), abi2mpi_tag(tag),
                        abi2mpi_comm(comm), flag, mpi_status);
  if (*flag)
    mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Irecv(void *buf, int count, MPIABI_Datatype datatype, int source,
                 int tag, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Irecv(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source),
                abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Irecv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
                   int source, int tag, MPIABI_Comm comm,
                   MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Irecv_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source),
                  abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Irsend(const void *buf, int count, MPIABI_Datatype datatype,
                  int dest, int tag, MPIABI_Comm comm,
                  MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Irsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                 abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Irsend_c(const void *buf, MPIABI_Count count,
                    MPIABI_Datatype datatype, int dest, int tag,
                    MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Irsend_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                   abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Isend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
                 int tag, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Isend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Isend_c(const void *buf, MPIABI_Count count,
                   MPIABI_Datatype datatype, int dest, int tag,
                   MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Isend_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                  abi2mpi_tag(tag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Isendrecv(const void *sendbuf, int sendcount,
                     MPIABI_Datatype sendtype, int dest, int sendtag,
                     void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                     int source, int recvtag, MPIABI_Comm comm,
                     MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Isendrecv(sendbuf, sendcount, abi2mpi_datatype(sendtype),
                    abi2mpi_proc(dest), sendtag, recvbuf, recvcount,
                    abi2mpi_datatype(recvtype), abi2mpi_proc(source),
                    abi2mpi_tag(recvtag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Isendrecv_c(const void *sendbuf, MPIABI_Count sendcount,
                       MPIABI_Datatype sendtype, int dest, int sendtag,
                       void *recvbuf, MPIABI_Count recvcount,
                       MPIABI_Datatype recvtype, int source, int recvtag,
                       MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Isendrecv_c(sendbuf, sendcount, abi2mpi_datatype(sendtype),
                      abi2mpi_proc(dest), sendtag, recvbuf, recvcount,
                      abi2mpi_datatype(recvtype), abi2mpi_proc(source),
                      abi2mpi_tag(recvtag), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Isendrecv_replace(void *buf, int count, MPIABI_Datatype datatype,
                             int dest, int sendtag, int source, int recvtag,
                             MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Isendrecv_replace(buf, count, abi2mpi_datatype(datatype),
                                   abi2mpi_proc(dest), sendtag,
                                   abi2mpi_proc(source), abi2mpi_tag(recvtag),
                                   abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Isendrecv_replace_c(void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype, int dest, int sendtag,
                               int source, int recvtag, MPIABI_Comm comm,
                               MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Isendrecv_replace_c(buf, count, abi2mpi_datatype(datatype),
                                     abi2mpi_proc(dest), sendtag,
                                     abi2mpi_proc(source), abi2mpi_tag(recvtag),
                                     abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Issend(const void *buf, int count, MPIABI_Datatype datatype,
                  int dest, int tag, MPIABI_Comm comm,
                  MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Issend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                 tag, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Issend_c(const void *buf, MPIABI_Count count,
                    MPIABI_Datatype datatype, int dest, int tag,
                    MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Issend_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                   tag, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Mprobe(int source, int tag, MPIABI_Comm comm,
                  MPIABI_Message *message, MPIABI_Status *status) {
  MPI_Message mpi_message;
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Mprobe(abi2mpi_proc(source), abi2mpi_tag(tag),
                        abi2mpi_comm(comm), &mpi_message, mpi_status);
  *message = mpi2abi_message(mpi_message);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Mrecv(void *buf, int count, MPIABI_Datatype datatype,
                 MPIABI_Message *message, MPIABI_Status *status) {
  MPI_Message mpi_message;
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Mrecv(buf, count, abi2mpi_datatype(datatype), &mpi_message,
                       mpi_status);
  *message = mpi2abi_message(mpi_message);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Mrecv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
                   MPIABI_Message *message, MPIABI_Status *status) {
  MPI_Message mpi_message;
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Mrecv_c(buf, count, abi2mpi_datatype(datatype), &mpi_message,
                         mpi_status);
  *message = mpi2abi_message(mpi_message);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Probe(int source, int tag, MPIABI_Comm comm, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Probe(abi2mpi_proc(source), abi2mpi_tag(tag),
                       abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Recv(void *buf, int count, MPIABI_Datatype datatype, int source,
                int tag, MPIABI_Comm comm, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr =
      MPI_Recv(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source),
               abi2mpi_tag(tag), abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Recv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
                  int source, int tag, MPIABI_Comm comm,
                  MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr =
      MPI_Recv_c(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source),
                 abi2mpi_tag(tag), abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Recv_init(void *buf, int count, MPIABI_Datatype datatype, int source,
                     int tag, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Recv_init(buf, count, abi2mpi_datatype(datatype),
                           abi2mpi_proc(source), abi2mpi_tag(tag),
                           abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Recv_init_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
                       int source, int tag, MPIABI_Comm comm,
                       MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Recv_init_c(buf, count, abi2mpi_datatype(datatype),
                             abi2mpi_proc(source), abi2mpi_tag(tag),
                             abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Request_free(MPIABI_Request *request) {
  MPI_Request mpi_request = abi2mpi_request(*request);
  int ierr = MPI_Request_free(&mpi_request);
  request_action_apply(*request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Request_get_status(MPIABI_Request request, int *flag,
                              MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Request_get_status(abi2mpi_request(request), flag, mpi_status);
  if (*flag)
    mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Request_get_status_all(int count,
                                  const MPIABI_Request array_of_requests[],
                                  int *flag,
                                  MPIABI_Status array_of_statuses[]) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Request array_of_mpi_requests[count];
  for (int n = 0; n < count; ++n)
    array_of_mpi_requests[n] = abi2mpi_request(array_of_requests[n]);
  bool ignore_statuses = array_of_statuses == MPIABI_STATUSES_IGNORE;
  int ierr = MPI_Request_get_status_all(
      count, array_of_mpi_requests, flag,
      ignore_statuses ? MPI_STATUSES_IGNORE : (MPI_Status *)array_of_statuses);
  if (!ignore_statuses && *flag)
    for (int n = count - 1; n >= 0; --n)
      array_of_statuses[n] =
          mpi2abi_status(((MPI_Status *)array_of_statuses)[n]);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Request_get_status_any(int count,
                                  const MPIABI_Request array_of_requests[],
                                  int *index, int *flag,
                                  MPIABI_Status *status) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Request array_of_mpi_requests[count];
  for (int n = 0; n < count; ++n)
    array_of_mpi_requests[n] = abi2mpi_request(array_of_requests[n]);
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Request_get_status_any(count, array_of_mpi_requests, index,
                                        flag, mpi_status);
  if (*flag)
    mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Request_get_status_some(int incount,
                                   const MPIABI_Request array_of_requests[],
                                   int *outcount, int array_of_indices[],
                                   MPIABI_Status array_of_statuses[]) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Request array_of_mpi_requests[incount];
  for (int n = 0; n < incount; ++n)
    array_of_mpi_requests[n] = abi2mpi_request(array_of_requests[n]);
  bool ignore_statuses = array_of_statuses == MPIABI_STATUSES_IGNORE;
  int ierr = MPI_Request_get_status_some(
      incount, array_of_mpi_requests, outcount, array_of_indices,
      ignore_statuses ? MPI_STATUSES_IGNORE : (MPI_Status *)array_of_statuses);
  *outcount = mpi2abi_count(*outcount);
  if (!ignore_statuses && *outcount != MPIABI_UNDEFINED)
    for (int n = *outcount - 1; n >= 0; --n)
      array_of_statuses[n] =
          mpi2abi_status(((MPI_Status *)array_of_statuses)[n]);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Rsend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
                 int tag, MPIABI_Comm comm) {
  int ierr = MPI_Rsend(buf, count, abi2mpi_datatype(datatype),
                       abi2mpi_proc(dest), tag, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rsend_c(const void *buf, MPIABI_Count count,
                   MPIABI_Datatype datatype, int dest, int tag,
                   MPIABI_Comm comm) {
  int ierr = MPI_Rsend_c(buf, count, abi2mpi_datatype(datatype),
                         abi2mpi_proc(dest), tag, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rsend_init(const void *buf, int count, MPIABI_Datatype datatype,
                      int dest, int tag, MPIABI_Comm comm,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Rsend_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                     tag, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rsend_init_c(const void *buf, MPIABI_Count count,
                        MPIABI_Datatype datatype, int dest, int tag,
                        MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rsend_init_c(buf, count, abi2mpi_datatype(datatype),
                              abi2mpi_proc(dest), tag, abi2mpi_comm(comm),
                              &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Send(const void *buf, int count, MPIABI_Datatype datatype, int dest,
                int tag, MPIABI_Comm comm) {
  int ierr = MPI_Send(buf, count, abi2mpi_datatype(datatype),
                      abi2mpi_proc(dest), tag, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Send_c(const void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
                  int dest, int tag, MPIABI_Comm comm) {
  int ierr = MPI_Send_c(buf, count, abi2mpi_datatype(datatype),
                        abi2mpi_proc(dest), tag, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Send_init(const void *buf, int count, MPIABI_Datatype datatype,
                     int dest, int tag, MPIABI_Comm comm,
                     MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Send_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                    tag, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Send_init_c(const void *buf, MPIABI_Count count,
                       MPIABI_Datatype datatype, int dest, int tag,
                       MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Send_init_c(buf, count, abi2mpi_datatype(datatype),
                             abi2mpi_proc(dest), tag, abi2mpi_comm(comm),
                             &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Sendrecv(const void *sendbuf, int sendcount,
                    MPIABI_Datatype sendtype, int dest, int sendtag,
                    void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                    int source, int recvtag, MPIABI_Comm comm,
                    MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Sendrecv(sendbuf, sendcount, abi2mpi_datatype(sendtype),
                          abi2mpi_proc(dest), sendtag, recvbuf, recvcount,
                          abi2mpi_datatype(recvtype), abi2mpi_proc(source),
                          abi2mpi_tag(recvtag), abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Sendrecv_c(const void *sendbuf, MPIABI_Count sendcount,
                      MPIABI_Datatype sendtype, int dest, int sendtag,
                      void *recvbuf, MPIABI_Count recvcount,
                      MPIABI_Datatype recvtype, int source, int recvtag,
                      MPIABI_Comm comm, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr =
      MPI_Sendrecv_c(sendbuf, sendcount, abi2mpi_datatype(sendtype),
                     abi2mpi_proc(dest), sendtag, recvbuf, recvcount,
                     abi2mpi_datatype(recvtype), abi2mpi_proc(source),
                     abi2mpi_tag(recvtag), abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Sendrecv_replace(void *buf, int count, MPIABI_Datatype datatype,
                            int dest, int sendtag, int source, int recvtag,
                            MPIABI_Comm comm, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Sendrecv_replace(buf, count, abi2mpi_datatype(datatype),
                                  abi2mpi_proc(dest), sendtag,
                                  abi2mpi_proc(source), abi2mpi_tag(recvtag),
                                  abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Sendrecv_replace_c(void *buf, MPIABI_Count count,
                              MPIABI_Datatype datatype, int dest, int sendtag,
                              int source, int recvtag, MPIABI_Comm comm,
                              MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Sendrecv_replace_c(buf, count, abi2mpi_datatype(datatype),
                                    abi2mpi_proc(dest), sendtag,
                                    abi2mpi_proc(source), abi2mpi_tag(recvtag),
                                    abi2mpi_comm(comm), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_attach_buffer(MPIABI_Session session, void *buffer,
                                 int size) {
#if MPI_VERSION_NUMBER >= 410
  if (buffer == MPIABI_BUFFER_AUTOMATIC)
    buffer = MPI_BUFFER_AUTOMATIC;
  int ierr = MPI_Session_attach_buffer(abi2mpi_session(session), buffer, size);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Session_attach_buffer_c(MPIABI_Session session, void *buffer,
                                   MPIABI_Count size) {
#if MPI_VERSION_NUMBER >= 410
  if (buffer == MPIABI_BUFFER_AUTOMATIC)
    buffer = MPI_BUFFER_AUTOMATIC;
  int ierr =
      MPI_Session_attach_buffer_c(abi2mpi_session(session), buffer, size);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Session_detach_buffer(MPIABI_Session session, void *buffer_addr,
                                 int *size) {
#if MPI_VERSION_NUMBER >= 410
  int ierr =
      MPI_Session_detach_buffer(abi2mpi_session(session), buffer_addr, size);
  if (*(void **)buffer_addr == MPI_BUFFER_AUTOMATIC)
    *(void **)buffer_addr = MPIABI_BUFFER_AUTOMATIC;
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Session_detach_buffer_c(MPIABI_Session session, void *buffer_addr,
                                   MPIABI_Count *size) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Count mpi_size;
  int ierr = MPI_Session_detach_buffer_c(abi2mpi_session(session), buffer_addr,
                                         &mpi_size);
  if (*(void **)buffer_addr == MPI_BUFFER_AUTOMATIC)
    *(void **)buffer_addr = MPIABI_BUFFER_AUTOMATIC;
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Session_flush_buffer(MPIABI_Session session) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Session_flush_buffer(abi2mpi_session(session));
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Session_iflush_buffer(MPIABI_Session session,
                                 MPIABI_Request *request) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Request mpi_request;
  int ierr = MPI_Session_iflush_buffer(abi2mpi_session(session), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Ssend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
                 int tag, MPIABI_Comm comm) {
  int ierr = MPI_Ssend(buf, count, abi2mpi_datatype(datatype),
                       abi2mpi_proc(dest), tag, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ssend_c(const void *buf, MPIABI_Count count,
                   MPIABI_Datatype datatype, int dest, int tag,
                   MPIABI_Comm comm) {
  int ierr = MPI_Ssend_c(buf, count, abi2mpi_datatype(datatype),
                         abi2mpi_proc(dest), tag, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ssend_init(const void *buf, int count, MPIABI_Datatype datatype,
                      int dest, int tag, MPIABI_Comm comm,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Ssend_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest),
                     tag, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ssend_init_c(const void *buf, MPIABI_Count count,
                        MPIABI_Datatype datatype, int dest, int tag,
                        MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ssend_init_c(buf, count, abi2mpi_datatype(datatype),
                              abi2mpi_proc(dest), tag, abi2mpi_comm(comm),
                              &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Start(MPIABI_Request *request) {
  MPI_Request mpi_request = abi2mpi_request(*request);
  int ierr = MPI_Start(&mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Startall(int count, MPIABI_Request array_of_requests[]) {
  for (int n = 0; n < count; ++n)
    ((MPI_Request *)array_of_requests)[n] =
        abi2mpi_request(array_of_requests[n]);
  int ierr = MPI_Startall(count, (MPI_Request *)array_of_requests);
  for (int n = count - 1; n >= 0; --n)
    array_of_requests[n] =
        mpi2abi_request(((MPI_Request *)array_of_requests)[n]);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Status_get_error(MPIABI_Status *status, int *err) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Status mpi_status = abi2mpi_status(*status);
  int ierr = MPI_Status_get_error(&mpi_status, err);
  *err = mpi2abi_errorcode(*err);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Status_get_source(MPIABI_Status *status, int *source) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Status mpi_status = abi2mpi_status(*status);
  int ierr = MPI_Status_get_source(&mpi_status, source);
  *source = mpi2abi_proc(*source);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Status_get_tag(MPIABI_Status *status, int *tag) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Status mpi_status = abi2mpi_status(*status);
  int ierr = MPI_Status_get_tag(&mpi_status, tag);
  *tag = mpi2abi_tag(*tag);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Test(MPIABI_Request *request, int *flag, MPIABI_Status *status) {
  MPI_Request mpi_request = abi2mpi_request(*request);
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Test(&mpi_request, flag, mpi_status);
  if (*flag) {
    request_action_apply(*request);
    *request = mpi2abi_request(mpi_request);
    mpi2abi_statusptr(mpi_status);
  }
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Test_cancelled(const MPIABI_Status *status, int *flag) {
  MPI_Status mpi_status = abi2mpi_status(*status);
  int ierr = MPI_Test_cancelled(&mpi_status, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Testall(int count, MPIABI_Request array_of_requests[], int *flag,
                   MPIABI_Status array_of_statuses[]) {
  MPI_Request mpi_array_of_requests[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_requests[n] = abi2mpi_request(array_of_requests[n]);
  bool ignore_statuses = array_of_statuses == MPIABI_STATUSES_IGNORE;
  int ierr = MPI_Testall(count, mpi_array_of_requests, flag,
                         ignore_statuses ? MPI_STATUSES_IGNORE
                                         : (MPI_Status *)array_of_statuses);
  if (*flag) {
    const bool skip_request_actions = request_actions_empty();
    for (int n = 0; n < count; ++n) {
      if (!skip_request_actions)
        request_action_apply(array_of_requests[n]);
      array_of_requests[n] = mpi2abi_request(mpi_array_of_requests[n]);
    }
    if (!ignore_statuses)
      for (int n = count - 1; n >= 0; --n)
        array_of_statuses[n] =
            mpi2abi_status(((MPI_Status *)array_of_statuses)[n]);
  }
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Testany(int count, MPIABI_Request array_of_requests[], int *index,
                   int *flag, MPIABI_Status *status) {
  MPI_Request mpi_array_of_requests[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_requests[n] = abi2mpi_request(array_of_requests[n]);
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Testany(count, mpi_array_of_requests, index, flag, mpi_status);
  if (*flag) {
    request_action_apply(array_of_requests[*index]);
    array_of_requests[*index] = mpi2abi_request(mpi_array_of_requests[*index]);
    mpi2abi_statusptr(mpi_status);
  }
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Testsome(int incount, MPIABI_Request array_of_requests[],
                    int *outcount, int array_of_indices[],
                    MPIABI_Status array_of_statuses[]) {
  MPI_Request mpi_array_of_requests[incount];
  for (int n = 0; n < incount; ++n)
    mpi_array_of_requests[n] = abi2mpi_request(array_of_requests[n]);
  bool ignore_statuses = array_of_statuses == MPIABI_STATUSES_IGNORE;
  int ierr = MPI_Testsome(
      incount, mpi_array_of_requests, outcount, array_of_indices,
      ignore_statuses ? MPI_STATUSES_IGNORE : (MPI_Status *)array_of_statuses);
  *outcount = mpi2abi_count(*outcount);
  if (*outcount != MPIABI_UNDEFINED && *outcount > 0) {
    const bool skip_request_actions = request_actions_empty();
    for (int n = 0; n < *outcount; ++n) {
      const int index = array_of_indices[n];
      if (!skip_request_actions)
        request_action_apply(array_of_requests[index]);
      array_of_requests[index] = mpi2abi_request(mpi_array_of_requests[index]);
    }
    if (!ignore_statuses)
      for (int n = *outcount - 1; n >= 0; --n)
        array_of_statuses[n] =
            mpi2abi_status(((MPI_Status *)array_of_statuses)[n]);
  }
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Wait(MPIABI_Request *request, MPIABI_Status *status) {
  MPI_Request mpi_request = abi2mpi_request(*request);
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Wait(&mpi_request, mpi_status);
  request_action_apply(*request);
  *request = mpi2abi_request(mpi_request);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Waitall(int count, MPIABI_Request array_of_requests[],
                   MPIABI_Status array_of_statuses[]) {
  MPI_Request mpi_array_of_requests[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_requests[n] = abi2mpi_request(array_of_requests[n]);
  bool ignore_statuses = array_of_statuses == MPIABI_STATUSES_IGNORE;
  int ierr = MPI_Waitall(count, mpi_array_of_requests,
                         ignore_statuses ? MPI_STATUSES_IGNORE
                                         : (MPI_Status *)array_of_statuses);
  const bool skip_request_actions = request_actions_empty();
  for (int n = 0; n < count; ++n) {
    if (!skip_request_actions)
      request_action_apply(array_of_requests[n]);
    array_of_requests[n] = mpi2abi_request(mpi_array_of_requests[n]);
  }
  if (!ignore_statuses)
    for (int n = count - 1; n >= 0; --n)
      array_of_statuses[n] =
          mpi2abi_status(((MPI_Status *)array_of_statuses)[n]);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Waitany(int count, MPIABI_Request array_of_requests[], int *index,
                   MPIABI_Status *status) {
  MPI_Request mpi_array_of_requests[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_requests[n] = abi2mpi_request(array_of_requests[n]);
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_Waitany(count, mpi_array_of_requests, index, mpi_status);
  request_action_apply(array_of_requests[*index]);
  array_of_requests[*index] = mpi2abi_request(mpi_array_of_requests[*index]);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Waitsome(int incount, MPIABI_Request array_of_requests[],
                    int *outcount, int array_of_indices[],
                    MPIABI_Status array_of_statuses[]) {
  MPI_Request mpi_array_of_requests[incount];
  for (int n = 0; n < incount; ++n)
    mpi_array_of_requests[n] = abi2mpi_request(array_of_requests[n]);
  bool ignore_statuses = array_of_statuses == MPIABI_STATUSES_IGNORE;
  int ierr = MPI_Waitsome(
      incount, mpi_array_of_requests, outcount, array_of_indices,
      ignore_statuses ? MPI_STATUSES_IGNORE : (MPI_Status *)array_of_statuses);
  *outcount = mpi2abi_count(*outcount);
  if (*outcount != MPIABI_UNDEFINED && *outcount > 0) {
    const bool skip_request_actions = request_actions_empty();
    for (int n = 0; n < *outcount; ++n) {
      const int index = array_of_indices[n];
      if (!skip_request_actions)
        request_action_apply(array_of_requests[index]);
      array_of_requests[index] = mpi2abi_request(mpi_array_of_requests[index]);
    }
    if (!ignore_statuses)
      for (int n = *outcount - 1; n >= 0; --n)
        array_of_statuses[n] =
            mpi2abi_status(((MPI_Status *)array_of_statuses)[n]);
  }
  return mpi2abi_errorcode(ierr);
}

// A.3.2 Partitioned Communication C Bindings

int MPIABI_Parrived(MPIABI_Request request, int partition, int *flag) {
  int ierr = MPI_Parrived(abi2mpi_request(request), partition, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pready(int partition, MPIABI_Request request) {
  int ierr = MPI_Pready(partition, abi2mpi_request(request));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pready_list(int length, const int array_of_partitions[],
                       MPIABI_Request request) {
  int ierr =
      MPI_Pready_list(length, array_of_partitions, abi2mpi_request(request));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pready_range(int partition_low, int partition_high,
                        MPIABI_Request request) {
  int ierr =
      MPI_Pready_range(partition_low, partition_high, abi2mpi_request(request));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Precv_init(void *buf, int partitions, MPIABI_Count count,
                      MPIABI_Datatype datatype, int source, int tag,
                      MPIABI_Comm comm, MPIABI_Info info,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Precv_init(
      buf, partitions, count, abi2mpi_datatype(datatype), abi2mpi_proc(source),
      abi2mpi_tag(tag), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Psend_init(const void *buf, int partitions, MPIABI_Count count,
                      MPIABI_Datatype datatype, int dest, int tag,
                      MPIABI_Comm comm, MPIABI_Info info,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Psend_init(buf, partitions, count, abi2mpi_datatype(datatype),
                            abi2mpi_proc(dest), tag, abi2mpi_comm(comm),
                            abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

// A.3.3 Datatypes C Bindings

MPIABI_Aint MPIABI_Aint_add(MPIABI_Aint base, MPIABI_Aint disp) {
  return MPI_Aint_add(base, disp);
}

MPIABI_Aint MPIABI_Aint_diff(MPIABI_Aint addr1, MPIABI_Aint addr2) {
  return MPI_Aint_diff(addr1, addr2);
}

int MPIABI_Get_address(const void *location, MPIABI_Aint *address) {
  MPI_Aint mpi_address;
  int ierr = MPI_Get_address(location, &mpi_address);
  *address = mpi_address;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_elements(const MPIABI_Status *status, MPIABI_Datatype datatype,
                        int *count) {
  const MPI_Status mpi_status = abi2mpi_status(*status);
  int ierr = MPI_Get_elements(&mpi_status, abi2mpi_datatype(datatype), count);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_elements_c(const MPIABI_Status *status, MPIABI_Datatype datatype,
                          MPIABI_Count *count) {
  const MPI_Status mpi_status = abi2mpi_status(*status);
  MPI_Count mpi_count;
  int ierr =
      MPI_Get_elements_c(&mpi_status, abi2mpi_datatype(datatype), &mpi_count);
  *count = mpi_count;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack(const void *inbuf, int incount, MPIABI_Datatype datatype,
                void *outbuf, int outsize, int *position, MPIABI_Comm comm) {
  int ierr = MPI_Pack(inbuf, incount, abi2mpi_datatype(datatype), outbuf,
                      outsize, position, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_c(const void *inbuf, MPIABI_Count incount,
                  MPIABI_Datatype datatype, void *outbuf, MPIABI_Count outsize,
                  MPIABI_Count *position, MPIABI_Comm comm) {
  MPI_Count mpi_position = *position;
  int ierr = MPI_Pack_c(inbuf, incount, abi2mpi_datatype(datatype), outbuf,
                        outsize, &mpi_position, abi2mpi_comm(comm));
  *position = mpi_position;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_external(const char datarep[], const void *inbuf, int incount,
                         MPIABI_Datatype datatype, void *outbuf,
                         MPIABI_Aint outsize, MPIABI_Aint *position) {
  MPI_Aint mpi_position = *position;
  int ierr =
      MPI_Pack_external(datarep, inbuf, incount, abi2mpi_datatype(datatype),
                        outbuf, outsize, &mpi_position);
  *position = mpi_position;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_external_c(const char datarep[], const void *inbuf,
                           MPIABI_Count incount, MPIABI_Datatype datatype,
                           void *outbuf, MPIABI_Count outsize,
                           MPIABI_Count *position) {
  MPI_Count mpi_position = *position;
  int ierr =
      MPI_Pack_external_c(datarep, inbuf, incount, abi2mpi_datatype(datatype),
                          outbuf, outsize, &mpi_position);
  *position = mpi_position;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_external_size(const char datarep[], MPIABI_Count incount,
                              MPIABI_Datatype datatype, MPIABI_Aint *size) {
  MPI_Aint mpi_size;
  int ierr = MPI_Pack_external_size(datarep, incount,
                                    abi2mpi_datatype(datatype), &mpi_size);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_external_size_c(const char datarep[], MPIABI_Count incount,
                                MPIABI_Datatype datatype, MPIABI_Count *size) {
  MPI_Count mpi_size;
  int ierr = MPI_Pack_external_size_c(datarep, incount,
                                      abi2mpi_datatype(datatype), &mpi_size);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_size(int incount, MPIABI_Datatype datatype, MPIABI_Comm comm,
                     int *size) {
  int ierr = MPI_Pack_size(incount, abi2mpi_datatype(datatype),
                           abi2mpi_comm(comm), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Pack_size_c(MPIABI_Count incount, MPIABI_Datatype datatype,
                       MPIABI_Comm comm, MPIABI_Count *size) {

  MPI_Count mpi_size;
  int ierr = MPI_Pack_size_c(incount, abi2mpi_datatype(datatype),
                             abi2mpi_comm(comm), &mpi_size);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_commit(MPIABI_Datatype *datatype) {
  MPI_Datatype mpi_datatype = abi2mpi_datatype(*datatype);
  int ierr = MPI_Type_commit(&mpi_datatype);
  *datatype = mpi2abi_datatype(mpi_datatype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_contiguous(int count, MPIABI_Datatype oldtype,
                           MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr =
      MPI_Type_contiguous(count, abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_contiguous_c(MPIABI_Count count, MPIABI_Datatype oldtype,
                             MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr =
      MPI_Type_contiguous_c(count, abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_darray(int size, int rank, int ndims,
                              const int array_of_gsizes[],
                              const int array_of_distribs[],
                              const int array_of_dargs[],
                              const int array_of_psizes[], int order,
                              MPIABI_Datatype oldtype,
                              MPIABI_Datatype *newtype) {
  int mpi_array_of_distribs[ndims];
  for (int n = 0; n < ndims; ++n)
    mpi_array_of_distribs[n] = abi2mpi_distrib(array_of_distribs[n]);
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_darray(size, rank, ndims, array_of_gsizes,
                                    mpi_array_of_distribs, array_of_dargs,
                                    array_of_psizes, abi2mpi_order(order),
                                    abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_darray_c(int size, int rank, int ndims,
                                const MPIABI_Count array_of_gsizes[],
                                const int array_of_distribs[],
                                const int array_of_dargs[],
                                const int array_of_psizes[], int order,
                                MPIABI_Datatype oldtype,
                                MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_gsizes[ndims];
  for (int n = 0; n < ndims; ++n)
    mpi_array_of_gsizes[n] = array_of_gsizes[n];
  int mpi_array_of_distribs[ndims];
  for (int n = 0; n < ndims; ++n)
    mpi_array_of_distribs[n] = abi2mpi_distrib(array_of_distribs[n]);
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_darray_c(size, rank, ndims, mpi_array_of_gsizes,
                                      mpi_array_of_distribs, array_of_dargs,
                                      array_of_psizes, abi2mpi_order(order),
                                      abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_hindexed(int count, const int array_of_blocklengths[],
                                const MPIABI_Aint array_of_displacements[],
                                MPIABI_Datatype oldtype,
                                MPIABI_Datatype *newtype) {
  MPI_Aint mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_hindexed(count, array_of_blocklengths,
                                      mpi_array_of_displacements,
                                      abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_hindexed_block(
    int count, int blocklength, const MPIABI_Aint array_of_displacements[],
    MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
  MPI_Aint mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_hindexed_block(
      count, blocklength, mpi_array_of_displacements, abi2mpi_datatype(oldtype),
      &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_hindexed_block_c(
    MPIABI_Count count, MPIABI_Count blocklength,
    const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
    MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_hindexed_block_c(
      count, blocklength, mpi_array_of_displacements, abi2mpi_datatype(oldtype),
      &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_hindexed_c(MPIABI_Count count,
                                  const MPIABI_Count array_of_blocklengths[],
                                  const MPIABI_Count array_of_displacements[],
                                  MPIABI_Datatype oldtype,
                                  MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_blocklengths[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_blocklengths[n] = array_of_blocklengths[n];
  MPI_Count mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_hindexed_c(
      count, mpi_array_of_blocklengths, mpi_array_of_displacements,
      abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_hvector(int count, int blocklength, MPIABI_Aint stride,
                               MPIABI_Datatype oldtype,
                               MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_hvector(count, blocklength, stride,
                                     abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_hvector_c(MPIABI_Count count, MPIABI_Count blocklength,
                                 MPIABI_Count stride, MPIABI_Datatype oldtype,
                                 MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_hvector_c(count, blocklength, stride,
                                       abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_indexed_block(int count, int blocklength,
                                     const int array_of_displacements[],
                                     MPIABI_Datatype oldtype,
                                     MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr =
      MPI_Type_create_indexed_block(count, blocklength, array_of_displacements,
                                    abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_indexed_block_c(
    MPIABI_Count count, MPIABI_Count blocklength,
    const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
    MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_indexed_block_c(
      count, blocklength, mpi_array_of_displacements, abi2mpi_datatype(oldtype),
      &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_resized(MPIABI_Datatype oldtype, MPIABI_Aint lb,
                               MPIABI_Aint extent, MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_resized(abi2mpi_datatype(oldtype), lb, extent,
                                     &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_resized_c(MPIABI_Datatype oldtype, MPIABI_Count lb,
                                 MPIABI_Count extent,
                                 MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_resized_c(abi2mpi_datatype(oldtype), lb, extent,
                                       &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_struct(int count, const int array_of_blocklengths[],
                              const MPIABI_Aint array_of_displacements[],
                              const MPIABI_Datatype array_of_types[],
                              MPIABI_Datatype *newtype) {
  MPI_Aint mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_array_of_types[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_types[n] = abi2mpi_datatype(array_of_types[n]);
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_struct(count, array_of_blocklengths,
                                    mpi_array_of_displacements,
                                    mpi_array_of_types, &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_struct_c(MPIABI_Count count,
                                const MPIABI_Count array_of_blocklengths[],
                                const MPIABI_Count array_of_displacements[],
                                const MPIABI_Datatype array_of_types[],
                                MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_blocklengths[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_blocklengths[n] = array_of_blocklengths[n];
  MPI_Count mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_array_of_types[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_types[n] = abi2mpi_datatype(array_of_types[n]);
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_struct_c(count, mpi_array_of_blocklengths,
                                      mpi_array_of_displacements,
                                      mpi_array_of_types, &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_subarray(int ndims, const int array_of_sizes[],
                                const int array_of_subsizes[],
                                const int array_of_starts[], int order,
                                MPIABI_Datatype oldtype,
                                MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes,
                                      array_of_starts, abi2mpi_order(order),
                                      abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_create_subarray_c(int ndims,
                                  const MPIABI_Count array_of_sizes[],
                                  const MPIABI_Count array_of_subsizes[],
                                  const MPIABI_Count array_of_starts[],
                                  int order, MPIABI_Datatype oldtype,
                                  MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_sizes[ndims];
  for (int n = 0; n < ndims; ++n)
    mpi_array_of_sizes[n] = array_of_sizes[n];
  MPI_Count mpi_array_of_subsizes[ndims];
  for (int n = 0; n < ndims; ++n)
    mpi_array_of_subsizes[n] = array_of_subsizes[n];
  MPI_Count mpi_array_of_starts[ndims];
  for (int n = 0; n < ndims; ++n)
    mpi_array_of_starts[n] = array_of_starts[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_create_subarray_c(
      ndims, mpi_array_of_sizes, mpi_array_of_subsizes, mpi_array_of_starts,
      abi2mpi_order(order), abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_dup(MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_dup(abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_free(MPIABI_Datatype *datatype) {
  MPI_Datatype mpi_datatype = abi2mpi_datatype(*datatype);
  int ierr = MPI_Type_free(&mpi_datatype);
  *datatype = mpi2abi_datatype(mpi_datatype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_contents(MPIABI_Datatype datatype, int max_integers,
                             int max_addresses, int max_datatypes,
                             int array_of_integers[],
                             MPIABI_Aint array_of_addresses[],
                             MPIABI_Datatype array_of_datatypes[]) {
  int ierr = MPI_Type_get_contents(
      abi2mpi_datatype(datatype), max_integers, max_addresses, max_datatypes,
      array_of_integers, (MPI_Aint *)array_of_addresses,
      (MPI_Datatype *)array_of_datatypes);
  for (int n = max_addresses - 1; n >= 0; --n)
    array_of_addresses[n] = ((MPI_Aint *)array_of_addresses)[n];
  for (int n = max_datatypes - 1; n >= 0; --n)
    array_of_datatypes[n] =
        mpi2abi_datatype(((MPI_Datatype *)array_of_datatypes)[n]);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_contents_c(
    MPIABI_Datatype datatype, MPIABI_Count max_integers,
    MPIABI_Count max_addresses, MPIABI_Count max_large_counts,
    MPIABI_Count max_datatypes, int array_of_integers[],
    MPIABI_Aint array_of_addresses[], MPIABI_Count array_of_large_counts[],
    MPIABI_Datatype array_of_datatypes[]) {
  int ierr = MPI_Type_get_contents_c(
      abi2mpi_datatype(datatype), max_integers, max_addresses, max_large_counts,
      max_datatypes, array_of_integers, (MPI_Aint *)array_of_addresses,
      (MPI_Count *)array_of_large_counts, (MPI_Datatype *)array_of_datatypes);
  for (int n = max_addresses - 1; n >= 0; --n)
    array_of_addresses[n] = ((MPI_Aint *)array_of_addresses)[n];
  for (int n = max_large_counts - 1; n >= 0; --n)
    array_of_large_counts[n] = ((MPI_Count *)array_of_large_counts)[n];
  for (int n = max_datatypes - 1; n >= 0; --n)
    array_of_datatypes[n] =
        mpi2abi_datatype(((MPI_Datatype *)array_of_datatypes)[n]);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_envelope(MPIABI_Datatype datatype, int *num_integers,
                             int *num_addresses, int *num_datatypes,
                             int *combiner) {
  int ierr = MPI_Type_get_envelope(abi2mpi_datatype(datatype), num_integers,
                                   num_addresses, num_datatypes, combiner);
  *combiner = mpi2abi_combiner(*combiner);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_envelope_c(MPIABI_Datatype datatype,
                               MPIABI_Count *num_integers,
                               MPIABI_Count *num_addresses,
                               MPIABI_Count *num_large_counts,
                               MPIABI_Count *num_datatypes, int *combiner) {
  MPI_Count mpi_num_integers;
  MPI_Count mpi_num_addresses;
  MPI_Count mpi_num_large_counts;
  MPI_Count mpi_num_datatypes;
  int ierr = MPI_Type_get_envelope_c(
      abi2mpi_datatype(datatype), &mpi_num_integers, &mpi_num_addresses,
      &mpi_num_large_counts, &mpi_num_datatypes, combiner);
  *num_integers = mpi_num_integers;
  *num_addresses = mpi_num_addresses;
  *num_large_counts = mpi_num_large_counts;
  *num_datatypes = mpi_num_datatypes;
  *combiner = mpi2abi_combiner(*combiner);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_extent(MPIABI_Datatype datatype, MPIABI_Aint *lb,
                           MPIABI_Aint *extent) {
  MPI_Aint mpi_lb;
  MPI_Aint mpi_extent;
  int ierr =
      MPI_Type_get_extent(abi2mpi_datatype(datatype), &mpi_lb, &mpi_extent);
  *lb = mpi_lb;
  *extent = mpi_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_extent_c(MPIABI_Datatype datatype, MPIABI_Count *lb,
                             MPIABI_Count *extent) {
  MPI_Count mpi_lb;
  MPI_Count mpi_extent;
  int ierr =
      MPI_Type_get_extent_c(abi2mpi_datatype(datatype), &mpi_lb, &mpi_extent);
  *lb = mpi_lb;
  *extent = mpi_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_true_extent(MPIABI_Datatype datatype, MPIABI_Aint *true_lb,
                                MPIABI_Aint *true_extent) {
  MPI_Aint mpi_true_lb;
  MPI_Aint mpi_true_extent;
  int ierr = MPI_Type_get_true_extent(abi2mpi_datatype(datatype), &mpi_true_lb,
                                      &mpi_true_extent);
  *true_lb = mpi_true_lb;
  *true_extent = mpi_true_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_true_extent_c(MPIABI_Datatype datatype,
                                  MPIABI_Count *true_lb,
                                  MPIABI_Count *true_extent) {

  MPI_Count mpi_true_lb;
  MPI_Count mpi_true_extent;
  int ierr = MPI_Type_get_true_extent_c(abi2mpi_datatype(datatype),
                                        &mpi_true_lb, &mpi_true_extent);
  *true_lb = mpi_true_lb;
  *true_extent = mpi_true_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_indexed(int count, const int array_of_blocklengths[],
                        const int array_of_displacements[],
                        MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr =
      MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements,
                       abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_indexed_c(MPIABI_Count count,
                          const MPIABI_Count array_of_blocklengths[],
                          const MPIABI_Count array_of_displacements[],
                          MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
  MPI_Count mpi_array_of_blocklengths[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_blocklengths[n] = array_of_blocklengths[n];
  MPI_Count mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_indexed_c(count, mpi_array_of_blocklengths,
                                mpi_array_of_displacements,
                                abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_size(MPIABI_Datatype datatype, int *size) {
  int ierr = MPI_Type_size(abi2mpi_datatype(datatype), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_size_c(MPIABI_Datatype datatype, MPIABI_Count *size) {
  MPI_Count mpi_size;
  int ierr = MPI_Type_size_c(abi2mpi_datatype(datatype), &mpi_size);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_vector(int count, int blocklength, int stride,
                       MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_vector(count, blocklength, stride,
                             abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_vector_c(MPIABI_Count count, MPIABI_Count blocklength,
                         MPIABI_Count stride, MPIABI_Datatype oldtype,
                         MPIABI_Datatype *newtype) {
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_vector_c(count, blocklength, stride,
                               abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Unpack(const void *inbuf, int insize, int *position, void *outbuf,
                  int outcount, MPIABI_Datatype datatype, MPIABI_Comm comm) {
  int ierr = MPI_Unpack(inbuf, insize, position, outbuf, outcount,
                        abi2mpi_datatype(datatype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Unpack_c(const void *inbuf, MPIABI_Count insize,
                    MPIABI_Count *position, void *outbuf, MPIABI_Count outcount,
                    MPIABI_Datatype datatype, MPIABI_Comm comm) {
  MPI_Count mpi_position;
  int ierr = MPI_Unpack_c(inbuf, insize, &mpi_position, outbuf, outcount,
                          abi2mpi_datatype(datatype), abi2mpi_comm(comm));
  *position = mpi_position;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Unpack_external(const char datarep[], const void *inbuf,
                           MPIABI_Aint insize, MPIABI_Aint *position,
                           void *outbuf, int outcount,
                           MPIABI_Datatype datatype) {
  MPI_Aint mpi_position = *position;
  int ierr = MPI_Unpack_external(datarep, inbuf, insize, &mpi_position, outbuf,
                                 outcount, abi2mpi_datatype(datatype));
  *position = mpi_position;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Unpack_external_c(const char datarep[], const void *inbuf,
                             MPIABI_Count insize, MPIABI_Count *position,
                             void *outbuf, MPIABI_Count outcount,
                             MPIABI_Datatype datatype) {
  MPI_Count mpi_position = *position;
  int ierr =
      MPI_Unpack_external_c(datarep, inbuf, insize, &mpi_position, outbuf,
                            outcount, abi2mpi_datatype(datatype));
  *position = mpi_position;
  return mpi2abi_errorcode(ierr);
}

// A.3.4 Collective Communication C Bindings

int MPIABI_Allgather(const void *sendbuf, int sendcount,
                     MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                     MPIABI_Datatype recvtype, MPIABI_Comm comm) {
  int ierr = MPI_Allgather(abi2mpi_buffer(sendbuf), sendcount,
                           abi2mpi_datatype(sendtype), recvbuf, recvcount,
                           abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgather_c(const void *sendbuf, MPIABI_Count sendcount,
                       MPIABI_Datatype sendtype, void *recvbuf,
                       MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                       MPIABI_Comm comm) {
  int ierr = MPI_Allgather_c(abi2mpi_buffer(sendbuf), sendcount,
                             abi2mpi_datatype(sendtype), recvbuf, recvcount,
                             abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgather_init(const void *sendbuf, int sendcount,
                          MPIABI_Datatype sendtype, void *recvbuf,
                          int recvcount, MPIABI_Datatype recvtype,
                          MPIABI_Comm comm, MPIABI_Info info,
                          MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Allgather_init(abi2mpi_buffer(sendbuf), sendcount,
                                abi2mpi_datatype(sendtype), recvbuf, recvcount,
                                abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
                                abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgather_init_c(const void *sendbuf, MPIABI_Count sendcount,
                            MPIABI_Datatype sendtype, void *recvbuf,
                            MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                            MPIABI_Comm comm, MPIABI_Info info,
                            MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Allgather_init_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgatherv(const void *sendbuf, int sendcount,
                      MPIABI_Datatype sendtype, void *recvbuf,
                      const int recvcounts[], const int displs[],
                      MPIABI_Datatype recvtype, MPIABI_Comm comm) {
  int ierr = MPI_Allgatherv(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcounts, displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
                        MPIABI_Datatype sendtype, void *recvbuf,
                        const MPIABI_Count recvcounts[],
                        const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
                        MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  int ierr = MPI_Allgatherv_c(abi2mpi_buffer(sendbuf), sendcount,
                              abi2mpi_datatype(sendtype), recvbuf,
                              mpi_recvcounts, mpi_displs,
                              abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgatherv_init(const void *sendbuf, int sendcount,
                           MPIABI_Datatype sendtype, void *recvbuf,
                           const int recvcounts[], const int displs[],
                           MPIABI_Datatype recvtype, MPIABI_Comm comm,
                           MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Allgatherv_init(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcounts, displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allgatherv_init_c(const void *sendbuf, MPIABI_Count sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             const MPIABI_Count recvcounts[],
                             const MPIABI_Aint displs[],
                             MPIABI_Datatype recvtype, MPIABI_Comm comm,
                             MPIABI_Info info, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Allgatherv_init_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_displs, abi2mpi_datatype(recvtype),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                     MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm) {
  int ierr = MPI_Allreduce(abi2mpi_buffer(sendbuf), recvbuf, count,
                           abi2mpi_datatype(datatype), abi2mpi_op(op),
                           abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allreduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                       MPIABI_Datatype datatype, MPIABI_Op op,
                       MPIABI_Comm comm) {
  int ierr = MPI_Allreduce_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                             abi2mpi_datatype(datatype), abi2mpi_op(op),
                             abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allreduce_init(const void *sendbuf, void *recvbuf, int count,
                          MPIABI_Datatype datatype, MPIABI_Op op,
                          MPIABI_Comm comm, MPIABI_Info info,
                          MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Allreduce_init(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Allreduce_init_c(const void *sendbuf, void *recvbuf,
                            MPIABI_Count count, MPIABI_Datatype datatype,
                            MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info,
                            MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Allreduce_init_c(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoall(const void *sendbuf, int sendcount,
                    MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                    MPIABI_Datatype recvtype, MPIABI_Comm comm) {
  int ierr = MPI_Alltoall(abi2mpi_buffer(sendbuf), sendcount,
                          abi2mpi_datatype(sendtype), recvbuf, recvcount,
                          abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoall_c(const void *sendbuf, MPIABI_Count sendcount,
                      MPIABI_Datatype sendtype, void *recvbuf,
                      MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                      MPIABI_Comm comm) {
  int ierr = MPI_Alltoall_c(abi2mpi_buffer(sendbuf), sendcount,
                            abi2mpi_datatype(sendtype), recvbuf, recvcount,
                            abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoall_init(const void *sendbuf, int sendcount,
                         MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPIABI_Datatype recvtype, MPIABI_Comm comm,
                         MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Alltoall_init(abi2mpi_buffer(sendbuf), sendcount,
                               abi2mpi_datatype(sendtype), recvbuf, recvcount,
                               abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
                               abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoall_init_c(const void *sendbuf, MPIABI_Count sendcount,
                           MPIABI_Datatype sendtype, void *recvbuf,
                           MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                           MPIABI_Comm comm, MPIABI_Info info,
                           MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Alltoall_init_c(abi2mpi_buffer(sendbuf), sendcount,
                                 abi2mpi_datatype(sendtype), recvbuf, recvcount,
                                 abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
                                 abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallv(const void *sendbuf, const int sendcounts[],
                     const int sdispls[], MPIABI_Datatype sendtype,
                     void *recvbuf, const int recvcounts[], const int rdispls[],
                     MPIABI_Datatype recvtype, MPIABI_Comm comm) {
  int ierr =
      MPI_Alltoallv(abi2mpi_buffer(sendbuf), sendcounts, sdispls,
                    abi2mpi_datatype(sendtype), recvbuf, recvcounts, rdispls,
                    abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                       const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype,
                       void *recvbuf, const MPIABI_Count recvcounts[],
                       const MPIABI_Aint rdispls[], MPIABI_Datatype recvtype,
                       MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  int ierr = MPI_Alltoallv_c(abi2mpi_buffer(sendbuf), mpi_sendcounts,
                             mpi_sdispls, abi2mpi_datatype(sendtype), recvbuf,
                             mpi_recvcounts, mpi_rdispls,
                             abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallv_init(const void *sendbuf, const int sendcounts[],
                          const int sdispls[], MPIABI_Datatype sendtype,
                          void *recvbuf, const int recvcounts[],
                          const int rdispls[], MPIABI_Datatype recvtype,
                          MPIABI_Comm comm, MPIABI_Info info,
                          MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Alltoallv_init(
      abi2mpi_buffer(sendbuf), sendcounts, sdispls, abi2mpi_datatype(sendtype),
      recvbuf, recvcounts, rdispls, abi2mpi_datatype(recvtype),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallv_init_c(const void *sendbuf,
                            const MPIABI_Count sendcounts[],
                            const MPIABI_Aint sdispls[],
                            MPIABI_Datatype sendtype, void *recvbuf,
                            const MPIABI_Count recvcounts[],
                            const MPIABI_Aint rdispls[],
                            MPIABI_Datatype recvtype, MPIABI_Comm comm,
                            MPIABI_Info info, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Alltoallv_init_c(
      abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_sdispls,
      abi2mpi_datatype(sendtype), recvbuf, mpi_recvcounts, mpi_rdispls,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), abi2mpi_info(info),
      &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallw(const void *sendbuf, const int sendcounts[],
                     const int sdispls[], const MPIABI_Datatype sendtypes[],
                     void *recvbuf, const int recvcounts[], const int rdispls[],
                     const MPIABI_Datatype recvtypes[], MPIABI_Comm comm) {
  int size;
  int ierr = MPIABI_Comm_size(comm, &size);
  if (ierr)
    return ierr;
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  ierr = MPI_Alltoallw(abi2mpi_buffer(sendbuf), sendcounts, sdispls,
                       mpi_sendtypes, recvbuf, recvcounts, rdispls,
                       mpi_recvtypes, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallw_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                       const MPIABI_Aint sdispls[],
                       const MPIABI_Datatype sendtypes[], void *recvbuf,
                       const MPIABI_Count recvcounts[],
                       const MPIABI_Aint rdispls[],
                       const MPIABI_Datatype recvtypes[], MPIABI_Comm comm) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  int ierr = MPI_Alltoallw_c(
      abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_sdispls, mpi_sendtypes,
      recvbuf, mpi_recvcounts, mpi_rdispls, mpi_recvtypes, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallw_init(const void *sendbuf, const int sendcounts[],
                          const int sdispls[],
                          const MPIABI_Datatype sendtypes[], void *recvbuf,
                          const int recvcounts[], const int rdispls[],
                          const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
                          MPIABI_Info info, MPIABI_Request *request) {
  int size;
  int ierr = MPIABI_Comm_size(comm, &size);
  if (ierr)
    return ierr;
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  ierr = MPI_Alltoallw_init(abi2mpi_buffer(sendbuf), sendcounts, sdispls,
                            mpi_sendtypes, recvbuf, recvcounts, rdispls,
                            mpi_recvtypes, abi2mpi_comm(comm),
                            abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alltoallw_init_c(const void *sendbuf,
                            const MPIABI_Count sendcounts[],
                            const MPIABI_Aint sdispls[],
                            const MPIABI_Datatype sendtypes[], void *recvbuf,
                            const MPIABI_Count recvcounts[],
                            const MPIABI_Aint rdispls[],
                            const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
                            MPIABI_Info info, MPIABI_Request *request) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  int ierr = MPI_Alltoallw_init_c(
      abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_sdispls, mpi_sendtypes,
      recvbuf, mpi_recvcounts, mpi_rdispls, mpi_recvtypes, abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Barrier(MPIABI_Comm comm) {
  int ierr = MPI_Barrier(abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Barrier_init(MPIABI_Comm comm, MPIABI_Info info,
                        MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr =
      MPI_Barrier_init(abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bcast(void *buffer, int count, MPIABI_Datatype datatype, int root,
                 MPIABI_Comm comm) {
  int ierr = MPI_Bcast(buffer, count, abi2mpi_datatype(datatype),
                       abi2mpi_root(root), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bcast_c(void *buffer, MPIABI_Count count, MPIABI_Datatype datatype,
                   int root, MPIABI_Comm comm) {
  int ierr = MPI_Bcast_c(buffer, count, abi2mpi_datatype(datatype),
                         abi2mpi_root(root), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bcast_init(void *buffer, int count, MPIABI_Datatype datatype,
                      int root, MPIABI_Comm comm, MPIABI_Info info,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Bcast_init(buffer, count, abi2mpi_datatype(datatype),
                            abi2mpi_root(root), abi2mpi_comm(comm),
                            abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Bcast_init_c(void *buffer, MPIABI_Count count,
                        MPIABI_Datatype datatype, int root, MPIABI_Comm comm,
                        MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Bcast_init_c(buffer, count, abi2mpi_datatype(datatype),
                              abi2mpi_root(root), abi2mpi_comm(comm),
                              abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Exscan(const void *sendbuf, void *recvbuf, int count,
                  MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm) {
  int ierr = MPI_Exscan(abi2mpi_buffer(sendbuf), recvbuf, count,
                        abi2mpi_datatype(datatype), abi2mpi_op(op),
                        abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Exscan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                    MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm) {
  int ierr = MPI_Exscan_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                          abi2mpi_datatype(datatype), abi2mpi_op(op),
                          abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Exscan_init(const void *sendbuf, void *recvbuf, int count,
                       MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                       MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Exscan_init(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Exscan_init_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                         MPIABI_Datatype datatype, MPIABI_Op op,
                         MPIABI_Comm comm, MPIABI_Info info,
                         MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Exscan_init_c(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gather(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                  int root, MPIABI_Comm comm) {
  int ierr =
      MPI_Gather(abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype),
                 recvbuf, recvcount, abi2mpi_datatype(recvtype),
                 abi2mpi_root(root), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gather_c(const void *sendbuf, MPIABI_Count sendcount,
                    MPIABI_Datatype sendtype, void *recvbuf,
                    MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
                    MPIABI_Comm comm) {
  int ierr = MPI_Gather_c(abi2mpi_buffer(sendbuf), sendcount,
                          abi2mpi_datatype(sendtype), recvbuf, recvcount,
                          abi2mpi_datatype(recvtype), abi2mpi_root(root),
                          abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gather_init(const void *sendbuf, int sendcount,
                       MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                       MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                       MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Gather_init(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_root(root),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gather_init_c(const void *sendbuf, MPIABI_Count sendcount,
                         MPIABI_Datatype sendtype, void *recvbuf,
                         MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                         int root, MPIABI_Comm comm, MPIABI_Info info,
                         MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Gather_init_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_root(root),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gatherv(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
                   void *recvbuf, const int recvcounts[], const int displs[],
                   MPIABI_Datatype recvtype, int root, MPIABI_Comm comm) {
  int ierr = MPI_Gatherv(abi2mpi_buffer(sendbuf), sendcount,
                         abi2mpi_datatype(sendtype), recvbuf, recvcounts,
                         displs, abi2mpi_datatype(recvtype), abi2mpi_root(root),
                         abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gatherv_c(const void *sendbuf, MPIABI_Count sendcount,
                     MPIABI_Datatype sendtype, void *recvbuf,
                     const MPIABI_Count recvcounts[],
                     const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
                     int root, MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  int ierr = MPI_Gatherv_c(abi2mpi_buffer(sendbuf), sendcount,
                           abi2mpi_datatype(sendtype), recvbuf, mpi_recvcounts,
                           mpi_displs, abi2mpi_datatype(recvtype),
                           abi2mpi_root(root), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gatherv_init(const void *sendbuf, int sendcount,
                        MPIABI_Datatype sendtype, void *recvbuf,
                        const int recvcounts[], const int displs[],
                        MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                        MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Gatherv_init(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcounts, displs, abi2mpi_datatype(recvtype), abi2mpi_root(root),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Gatherv_init_c(const void *sendbuf, MPIABI_Count sendcount,
                          MPIABI_Datatype sendtype, void *recvbuf,
                          const MPIABI_Count recvcounts[],
                          const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
                          int root, MPIABI_Comm comm, MPIABI_Info info,
                          MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Gatherv_init_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_displs, abi2mpi_datatype(recvtype),
      abi2mpi_root(root), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iallgather(const void *sendbuf, int sendcount,
                      MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                      MPIABI_Datatype recvtype, MPIABI_Comm comm,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iallgather(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iallgather_c(const void *sendbuf, MPIABI_Count sendcount,
                        MPIABI_Datatype sendtype, void *recvbuf,
                        MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                        MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iallgather_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iallgatherv(const void *sendbuf, int sendcount,
                       MPIABI_Datatype sendtype, void *recvbuf,
                       const int recvcounts[], const int displs[],
                       MPIABI_Datatype recvtype, MPIABI_Comm comm,
                       MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iallgatherv(abi2mpi_buffer(sendbuf), sendcount,
                             abi2mpi_datatype(sendtype), recvbuf, recvcounts,
                             displs, abi2mpi_datatype(recvtype),
                             abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iallgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
                         MPIABI_Datatype sendtype, void *recvbuf,
                         const MPIABI_Count recvcounts[],
                         const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
                         MPIABI_Comm comm, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Iallgatherv_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_displs, abi2mpi_datatype(recvtype),
      abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                      MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                      MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iallreduce(abi2mpi_buffer(sendbuf), recvbuf, count,
                            abi2mpi_datatype(datatype), abi2mpi_op(op),
                            abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iallreduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                        MPIABI_Datatype datatype, MPIABI_Op op,
                        MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iallreduce_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                              abi2mpi_datatype(datatype), abi2mpi_op(op),
                              abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ialltoall(const void *sendbuf, int sendcount,
                     MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                     MPIABI_Datatype recvtype, MPIABI_Comm comm,
                     MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ialltoall(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ialltoall_c(const void *sendbuf, MPIABI_Count sendcount,
                       MPIABI_Datatype sendtype, void *recvbuf,
                       MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                       MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ialltoall_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                      const int sdispls[], MPIABI_Datatype sendtype,
                      void *recvbuf, const int recvcounts[],
                      const int rdispls[], MPIABI_Datatype recvtype,
                      MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ialltoallv(abi2mpi_buffer(sendbuf), sendcounts, sdispls,
                            abi2mpi_datatype(sendtype), recvbuf, recvcounts,
                            rdispls, abi2mpi_datatype(recvtype),
                            abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ialltoallv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                        const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype,
                        void *recvbuf, const MPIABI_Count recvcounts[],
                        const MPIABI_Aint rdispls[], MPIABI_Datatype recvtype,
                        MPIABI_Comm comm, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Ialltoallv_c(
      abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_sdispls,
      abi2mpi_datatype(sendtype), recvbuf, mpi_recvcounts, mpi_rdispls,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                      const int sdispls[], const MPIABI_Datatype sendtypes[],
                      void *recvbuf, const int recvcounts[],
                      const int rdispls[], const MPIABI_Datatype recvtypes[],
                      MPIABI_Comm comm, MPIABI_Request *request) {
  int size;
  int ierr = MPIABI_Comm_size(comm, &size);
  if (ierr)
    return ierr;
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  ierr = MPI_Ialltoallw(abi2mpi_buffer(sendbuf), sendcounts, sdispls,
                        mpi_sendtypes, recvbuf, recvcounts, rdispls,
                        mpi_recvtypes, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ialltoallw_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                        const MPIABI_Aint sdispls[],
                        const MPIABI_Datatype sendtypes[], void *recvbuf,
                        const MPIABI_Count recvcounts[],
                        const MPIABI_Aint rdispls[],
                        const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
                        MPIABI_Request *request) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  int ierr =
      MPI_Ialltoallw_c(abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_sdispls,
                       mpi_sendtypes, recvbuf, mpi_recvcounts, mpi_rdispls,
                       mpi_recvtypes, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ibarrier(MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ibarrier(abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ibcast(void *buffer, int count, MPIABI_Datatype datatype, int root,
                  MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ibcast(buffer, count, abi2mpi_datatype(datatype),
                        abi2mpi_root(root), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ibcast_c(void *buffer, MPIABI_Count count, MPIABI_Datatype datatype,
                    int root, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ibcast_c(buffer, count, abi2mpi_datatype(datatype),
                          abi2mpi_root(root), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                   MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                   MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iexscan(abi2mpi_buffer(sendbuf), recvbuf, count,
                         abi2mpi_datatype(datatype), abi2mpi_op(op),
                         abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iexscan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                     MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                     MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iexscan_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                           abi2mpi_datatype(datatype), abi2mpi_op(op),
                           abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Igather(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                   int root, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Igather(abi2mpi_buffer(sendbuf), sendcount,
                         abi2mpi_datatype(sendtype), recvbuf, recvcount,
                         abi2mpi_datatype(recvtype), abi2mpi_root(root),
                         abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Igather_c(const void *sendbuf, MPIABI_Count sendcount,
                     MPIABI_Datatype sendtype, void *recvbuf,
                     MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
                     MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Igather_c(abi2mpi_buffer(sendbuf), sendcount,
                           abi2mpi_datatype(sendtype), recvbuf, recvcount,
                           abi2mpi_datatype(recvtype), abi2mpi_root(root),
                           abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Igatherv(const void *sendbuf, int sendcount,
                    MPIABI_Datatype sendtype, void *recvbuf,
                    const int recvcounts[], const int displs[],
                    MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                    MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Igatherv(abi2mpi_buffer(sendbuf), sendcount,
                          abi2mpi_datatype(sendtype), recvbuf, recvcounts,
                          displs, abi2mpi_datatype(recvtype),
                          abi2mpi_root(root), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Igatherv_c(const void *sendbuf, MPIABI_Count sendcount,
                      MPIABI_Datatype sendtype, void *recvbuf,
                      const MPIABI_Count recvcounts[],
                      const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
                      int root, MPIABI_Comm comm, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Igatherv_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_displs, abi2mpi_datatype(recvtype),
      abi2mpi_root(root), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                   MPIABI_Datatype datatype, MPIABI_Op op, int root,
                   MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ireduce(abi2mpi_buffer(sendbuf), recvbuf, count,
                         abi2mpi_datatype(datatype), abi2mpi_op(op),
                         abi2mpi_root(root), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ireduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                     MPIABI_Datatype datatype, MPIABI_Op op, int root,
                     MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ireduce_c(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_root(root), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                           const int recvcounts[], MPIABI_Datatype datatype,
                           MPIABI_Op op, MPIABI_Comm comm,
                           MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ireduce_scatter(abi2mpi_buffer(sendbuf), recvbuf, recvcounts,
                                 abi2mpi_datatype(datatype), abi2mpi_op(op),
                                 abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                 int recvcount, MPIABI_Datatype datatype,
                                 MPIABI_Op op, MPIABI_Comm comm,
                                 MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ireduce_scatter_block(
      abi2mpi_buffer(sendbuf), recvbuf, recvcount, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                   MPIABI_Count recvcount,
                                   MPIABI_Datatype datatype, MPIABI_Op op,
                                   MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ireduce_scatter_block_c(
      abi2mpi_buffer(sendbuf), recvbuf, recvcount, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf,
                             const MPIABI_Count recvcounts[],
                             MPIABI_Datatype datatype, MPIABI_Op op,
                             MPIABI_Comm comm, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
#endif
  MPI_Request mpi_request;
  int ierr =
      MPI_Ireduce_scatter_c(abi2mpi_buffer(sendbuf), recvbuf, mpi_recvcounts,
                            abi2mpi_datatype(datatype), abi2mpi_op(op),
                            abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iscan(const void *sendbuf, void *recvbuf, int count,
                 MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                 MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iscan(abi2mpi_buffer(sendbuf), recvbuf, count,
                       abi2mpi_datatype(datatype), abi2mpi_op(op),
                       abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iscan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                   MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                   MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iscan_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                         abi2mpi_datatype(datatype), abi2mpi_op(op),
                         abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iscatter(const void *sendbuf, int sendcount,
                    MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                    MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                    MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iscatter(abi2mpi_buffer(sendbuf), sendcount,
                          abi2mpi_datatype(sendtype), recvbuf, recvcount,
                          abi2mpi_datatype(recvtype), abi2mpi_root(root),
                          abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iscatter_c(const void *sendbuf, MPIABI_Count sendcount,
                      MPIABI_Datatype sendtype, void *recvbuf,
                      MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                      int root, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iscatter_c(abi2mpi_buffer(sendbuf), sendcount,
                            abi2mpi_datatype(sendtype), recvbuf, recvcount,
                            abi2mpi_datatype(recvtype), abi2mpi_root(root),
                            abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iscatterv(const void *sendbuf, const int sendcounts[],
                     const int displs[], MPIABI_Datatype sendtype,
                     void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                     int root, MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Iscatterv(abi2mpi_buffer(sendbuf), sendcounts, displs,
                           abi2mpi_datatype(sendtype), recvbuf, recvcount,
                           abi2mpi_datatype(recvtype), abi2mpi_root(root),
                           abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Iscatterv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                       const MPIABI_Aint displs[], MPIABI_Datatype sendtype,
                       void *recvbuf, MPIABI_Count recvcount,
                       MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                       MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr =
      MPI_Iscatterv_c(abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_displs,
                      abi2mpi_datatype(sendtype), recvbuf, recvcount,
                      abi2mpi_datatype(recvtype), abi2mpi_root(root),
                      abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Op_commutative(MPIABI_Op op, int *commute) {
  int ierr = MPI_Op_commutative(abi2mpi_op(op), commute);
  return mpi2abi_errorcode(ierr);
}

#define MAX_NUM_OP_WRAPPERS 10
static atomic_int num_op_wrappers = 0;
static MPIABI_User_function *user_fns[MAX_NUM_OP_WRAPPERS] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};
static void wrap_user_fn_impl(int op_wrapper_num, void *invec, void *inoutvec,
                              int *len, MPI_Datatype *datatype) {
  MPIABI_Datatype abi_datatype = mpi2abi_datatype(*datatype);
  user_fns[op_wrapper_num](invec, inoutvec, len, &abi_datatype);
}
#define DEFINE_WRAP_USER_FN(N)                                                 \
  static void wrap_user_fn_##N(void *invec, void *inoutvec, int *len,          \
                               MPI_Datatype *datatype) {                       \
    wrap_user_fn_impl(N, invec, inoutvec, len, datatype);                      \
  }
DEFINE_WRAP_USER_FN(0)
DEFINE_WRAP_USER_FN(1)
DEFINE_WRAP_USER_FN(2)
DEFINE_WRAP_USER_FN(3)
DEFINE_WRAP_USER_FN(4)
DEFINE_WRAP_USER_FN(5)
DEFINE_WRAP_USER_FN(6)
DEFINE_WRAP_USER_FN(7)
DEFINE_WRAP_USER_FN(8)
DEFINE_WRAP_USER_FN(9)
#undef DEFINE_WRAP_USER_FN
static MPI_User_function *const wrap_user_fn[MAX_NUM_OP_WRAPPERS] = {
    wrap_user_fn_0, wrap_user_fn_1, wrap_user_fn_2, wrap_user_fn_3,
    wrap_user_fn_4, wrap_user_fn_5, wrap_user_fn_6, wrap_user_fn_7,
    wrap_user_fn_8, wrap_user_fn_9,
};

int MPIABI_Op_create(MPIABI_User_function *user_fn, int commute,
                     MPIABI_Op *op) {
  MPI_Op mpi_op;
  int op_wrapper_num = atomic_fetch_add(&num_op_wrappers, 1);
  assert(op_wrapper_num < MAX_NUM_OP_WRAPPERS);
  user_fns[op_wrapper_num] = user_fn;
  int ierr = MPI_Op_create(wrap_user_fn[op_wrapper_num], commute, &mpi_op);
  *op = mpi2abi_op(mpi_op);
  return mpi2abi_errorcode(ierr);
}

#define MAX_NUM_OP_WRAPPERS_C 10
static atomic_int num_op_wrappers_c = 0;
static MPIABI_User_function_c *user_fns_c[MAX_NUM_OP_WRAPPERS_C] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};
static void wrap_user_fn_c_impl(int op_wrapper_num, void *invec, void *inoutvec,
                                MPI_Count *len, MPI_Datatype *datatype) {
  MPIABI_Count abi_len = *len;
  MPIABI_Datatype abi_datatype = mpi2abi_datatype(*datatype);
  user_fns_c[op_wrapper_num](invec, inoutvec, &abi_len, &abi_datatype);
}
#define DEFINE_WRAP_USER_FN_C(N)                                               \
  static void wrap_user_fn_c_##N(void *invec, void *inoutvec, MPI_Count *len,  \
                                 MPI_Datatype *datatype) {                     \
    wrap_user_fn_c_impl(N, invec, inoutvec, len, datatype);                    \
  }
DEFINE_WRAP_USER_FN_C(0)
DEFINE_WRAP_USER_FN_C(1)
DEFINE_WRAP_USER_FN_C(2)
DEFINE_WRAP_USER_FN_C(3)
DEFINE_WRAP_USER_FN_C(4)
DEFINE_WRAP_USER_FN_C(5)
DEFINE_WRAP_USER_FN_C(6)
DEFINE_WRAP_USER_FN_C(7)
DEFINE_WRAP_USER_FN_C(8)
DEFINE_WRAP_USER_FN_C(9)
#undef DEFINE_WRAP_USER_FN_C
static MPI_User_function_c *const wrap_user_fn_c[MAX_NUM_OP_WRAPPERS] = {
    wrap_user_fn_c_0, wrap_user_fn_c_1, wrap_user_fn_c_2, wrap_user_fn_c_3,
    wrap_user_fn_c_4, wrap_user_fn_c_5, wrap_user_fn_c_6, wrap_user_fn_c_7,
    wrap_user_fn_c_8, wrap_user_fn_c_9,
};

int MPIABI_Op_create_c(MPIABI_User_function_c *user_fn, int commute,
                       MPIABI_Op *op) {
  MPI_Op mpi_op;
  int op_wrapper_num = atomic_fetch_add(&num_op_wrappers_c, 1);
  assert(op_wrapper_num < MAX_NUM_OP_WRAPPERS_C);
  user_fns_c[op_wrapper_num] = user_fn;
  int ierr = MPI_Op_create_c(wrap_user_fn_c[op_wrapper_num], commute, &mpi_op);
  *op = mpi2abi_op(mpi_op);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Op_free(MPIABI_Op *op) {
  MPI_Op mpi_op = abi2mpi_op(*op);
  // We do not free the wrapper functions because `MPI_Op` objects are
  // reference counted and can live on after they have been freed
  int ierr = MPI_Op_free(&mpi_op);
  *op = mpi2abi_op(mpi_op);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce(const void *sendbuf, void *recvbuf, int count,
                  MPIABI_Datatype datatype, MPIABI_Op op, int root,
                  MPIABI_Comm comm) {
  int ierr = MPI_Reduce(abi2mpi_buffer(sendbuf), recvbuf, count,
                        abi2mpi_datatype(datatype), abi2mpi_op(op),
                        abi2mpi_root(root), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                    MPIABI_Datatype datatype, MPIABI_Op op, int root,
                    MPIABI_Comm comm) {
  int ierr = MPI_Reduce_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                          abi2mpi_datatype(datatype), abi2mpi_op(op),
                          abi2mpi_root(root), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_init(const void *sendbuf, void *recvbuf, int count,
                       MPIABI_Datatype datatype, MPIABI_Op op, int root,
                       MPIABI_Comm comm, MPIABI_Info info,
                       MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Reduce_init(abi2mpi_buffer(sendbuf), recvbuf, count,
                             abi2mpi_datatype(datatype), abi2mpi_op(op),
                             abi2mpi_root(root), abi2mpi_comm(comm),
                             abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_init_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                         MPIABI_Datatype datatype, MPIABI_Op op, int root,
                         MPIABI_Comm comm, MPIABI_Info info,
                         MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Reduce_init_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                               abi2mpi_datatype(datatype), abi2mpi_op(op),
                               abi2mpi_root(root), abi2mpi_comm(comm),
                               abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                        MPIABI_Datatype datatype, MPIABI_Op op) {
  assert(inbuf != MPIABI_IN_PLACE);
  int ierr = MPI_Reduce_local(inbuf, inoutbuf, count,
                              abi2mpi_datatype(datatype), abi2mpi_op(op));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPIABI_Count count,
                          MPIABI_Datatype datatype, MPIABI_Op op) {
  assert(inbuf != MPIABI_IN_PLACE);
  int ierr = MPI_Reduce_local_c(inbuf, inoutbuf, count,
                                abi2mpi_datatype(datatype), abi2mpi_op(op));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                          const int recvcounts[], MPIABI_Datatype datatype,
                          MPIABI_Op op, MPIABI_Comm comm) {
  int ierr = MPI_Reduce_scatter(abi2mpi_buffer(sendbuf), recvbuf, recvcounts,
                                abi2mpi_datatype(datatype), abi2mpi_op(op),
                                abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                int recvcount, MPIABI_Datatype datatype,
                                MPIABI_Op op, MPIABI_Comm comm) {
  int ierr = MPI_Reduce_scatter_block(abi2mpi_buffer(sendbuf), recvbuf,
                                      recvcount, abi2mpi_datatype(datatype),
                                      abi2mpi_op(op), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                  MPIABI_Count recvcount,
                                  MPIABI_Datatype datatype, MPIABI_Op op,
                                  MPIABI_Comm comm) {
  int ierr = MPI_Reduce_scatter_block_c(abi2mpi_buffer(sendbuf), recvbuf,
                                        recvcount, abi2mpi_datatype(datatype),
                                        abi2mpi_op(op), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf,
                                     int recvcount, MPIABI_Datatype datatype,
                                     MPIABI_Op op, MPIABI_Comm comm,
                                     MPIABI_Info info,
                                     MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Reduce_scatter_block_init(
      abi2mpi_buffer(sendbuf), recvbuf, recvcount, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf,
                                       MPIABI_Count recvcount,
                                       MPIABI_Datatype datatype, MPIABI_Op op,
                                       MPIABI_Comm comm, MPIABI_Info info,
                                       MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Reduce_scatter_block_init_c(
      abi2mpi_buffer(sendbuf), recvbuf, recvcount, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_c(const void *sendbuf, void *recvbuf,
                            const MPIABI_Count recvcounts[],
                            MPIABI_Datatype datatype, MPIABI_Op op,
                            MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
#endif
  int ierr = MPI_Reduce_scatter_c(abi2mpi_buffer(sendbuf), recvbuf,
                                  mpi_recvcounts, abi2mpi_datatype(datatype),
                                  abi2mpi_op(op), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_init(const void *sendbuf, void *recvbuf,
                               const int recvcounts[], MPIABI_Datatype datatype,
                               MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info,
                               MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Reduce_scatter_init(
      abi2mpi_buffer(sendbuf), recvbuf, recvcounts, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf,
                                 const MPIABI_Count recvcounts[],
                                 MPIABI_Datatype datatype, MPIABI_Op op,
                                 MPIABI_Comm comm, MPIABI_Info info,
                                 MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Reduce_scatter_init_c(
      abi2mpi_buffer(sendbuf), recvbuf, mpi_recvcounts,
      abi2mpi_datatype(datatype), abi2mpi_op(op), abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scan(const void *sendbuf, void *recvbuf, int count,
                MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm) {
  int ierr =
      MPI_Scan(abi2mpi_buffer(sendbuf), recvbuf, count,
               abi2mpi_datatype(datatype), abi2mpi_op(op), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                  MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm) {
  int ierr = MPI_Scan_c(abi2mpi_buffer(sendbuf), recvbuf, count,
                        abi2mpi_datatype(datatype), abi2mpi_op(op),
                        abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scan_init(const void *sendbuf, void *recvbuf, int count,
                     MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                     MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Scan_init(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scan_init_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                       MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
                       MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Scan_init_c(
      abi2mpi_buffer(sendbuf), recvbuf, count, abi2mpi_datatype(datatype),
      abi2mpi_op(op), abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatter(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
                   void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                   int root, MPIABI_Comm comm) {
  int ierr = MPI_Scatter(abi2mpi_buffer(sendbuf), sendcount,
                         abi2mpi_datatype(sendtype), recvbuf, recvcount,
                         abi2mpi_datatype(recvtype), abi2mpi_root(root),
                         abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatter_c(const void *sendbuf, MPIABI_Count sendcount,
                     MPIABI_Datatype sendtype, void *recvbuf,
                     MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
                     MPIABI_Comm comm) {
  int ierr = MPI_Scatter_c(abi2mpi_buffer(sendbuf), sendcount,
                           abi2mpi_datatype(sendtype), recvbuf, recvcount,
                           abi2mpi_datatype(recvtype), abi2mpi_root(root),
                           abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatter_init(const void *sendbuf, int sendcount,
                        MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                        MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Scatter_init(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_root(root),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatter_init_c(const void *sendbuf, MPIABI_Count sendcount,
                          MPIABI_Datatype sendtype, void *recvbuf,
                          MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                          int root, MPIABI_Comm comm, MPIABI_Info info,
                          MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Scatter_init_c(
      abi2mpi_buffer(sendbuf), sendcount, abi2mpi_datatype(sendtype), recvbuf,
      recvcount, abi2mpi_datatype(recvtype), abi2mpi_root(root),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatterv(const void *sendbuf, const int sendcounts[],
                    const int displs[], MPIABI_Datatype sendtype, void *recvbuf,
                    int recvcount, MPIABI_Datatype recvtype, int root,
                    MPIABI_Comm comm) {
  int ierr = MPI_Scatterv(abi2mpi_buffer(sendbuf), sendcounts, displs,
                          abi2mpi_datatype(sendtype), recvbuf, recvcount,
                          abi2mpi_datatype(recvtype), abi2mpi_root(root),
                          abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatterv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                      const MPIABI_Aint displs[], MPIABI_Datatype sendtype,
                      void *recvbuf, MPIABI_Count recvcount,
                      MPIABI_Datatype recvtype, int root, MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  int ierr = MPI_Scatterv_c(abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_displs,
                            abi2mpi_datatype(sendtype), recvbuf, recvcount,
                            abi2mpi_datatype(recvtype), abi2mpi_root(root),
                            abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatterv_init(const void *sendbuf, const int sendcounts[],
                         const int displs[], MPIABI_Datatype sendtype,
                         void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
                         int root, MPIABI_Comm comm, MPIABI_Info info,
                         MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Scatterv_init(
      abi2mpi_buffer(sendbuf), sendcounts, displs, abi2mpi_datatype(sendtype),
      recvbuf, recvcount, abi2mpi_datatype(recvtype), abi2mpi_root(root),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Scatterv_init_c(const void *sendbuf, const MPIABI_Count sendcounts[],
                           const MPIABI_Aint displs[], MPIABI_Datatype sendtype,
                           void *recvbuf, MPIABI_Count recvcount,
                           MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                           MPIABI_Info info, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr =
      MPI_Scatterv_init_c(abi2mpi_buffer(sendbuf), mpi_sendcounts, mpi_displs,
                          abi2mpi_datatype(sendtype), recvbuf, recvcount,
                          abi2mpi_datatype(recvtype), abi2mpi_root(root),
                          abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_value_index(MPIABI_Datatype value_type,
                                MPIABI_Datatype index_type,
                                MPIABI_Datatype *pair_type) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Datatype mpi_pair_type;
  int ierr =
      MPI_Type_get_value_index(abi2mpi_datatype(value_type),
                               abi2mpi_datatype(index_type), &mpi_pair_type);
  *pair_type = mpi2abi_datatype(mpi_pair_type);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

int MPIABI_Comm_compare(MPIABI_Comm comm1, MPIABI_Comm comm2, int *result) {
  int ierr = MPI_Comm_compare(abi2mpi_comm(comm1), abi2mpi_comm(comm2), result);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_create(MPIABI_Comm comm, MPIABI_Group group,
                       MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr =
      MPI_Comm_create(abi2mpi_comm(comm), abi2mpi_group(group), &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_create_from_group(MPIABI_Group group, const char *stringtag,
                                  MPIABI_Info info,
                                  MPIABI_Errhandler errhandler,
                                  MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_create_from_group(
      abi2mpi_group(group), stringtag, abi2mpi_info(info),
      abi2mpi_errhandler(errhandler), &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_create_group(MPIABI_Comm comm, MPIABI_Group group, int tag,
                             MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_create_group(abi2mpi_comm(comm), abi2mpi_group(group),
                                   tag, &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

struct abi_Comm_create_keyval_state {
  MPIABI_Comm_copy_attr_function *abi_comm_copy_attr_fn;
  MPIABI_Comm_delete_attr_function *abi_comm_delete_attr_fn;
  void *abi_extra_state;
};
static int mpi_Comm_create_keyval_copy_attr_function(
    MPI_Comm oldcomm, int comm_keyval, void *extra_state,
    void *attribute_val_in, void *attribute_val_out, int *flag) {
  const struct abi_Comm_create_keyval_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_comm_copy_attr_fn(
      mpi2abi_comm(oldcomm), mpi2abi_keyval(comm_keyval),
      mpi_extra_state->abi_extra_state, attribute_val_in, attribute_val_out,
      flag);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Comm_create_keyval_delete_attr_function(MPI_Comm comm,
                                                       int comm_keyval,
                                                       void *attribute_val,
                                                       void *extra_state) {
  const struct abi_Comm_create_keyval_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_comm_delete_attr_fn(
      mpi2abi_comm(comm), mpi2abi_keyval(comm_keyval), attribute_val,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Comm_create_keyval(
    MPIABI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPIABI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state) {
  struct abi_Comm_create_keyval_state *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_comm_copy_attr_fn = comm_copy_attr_fn;
  mpi_extra_state->abi_comm_delete_attr_fn = comm_delete_attr_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  int ierr = MPI_Comm_create_keyval(mpi_Comm_create_keyval_copy_attr_function,
                                    mpi_Comm_create_keyval_delete_attr_function,
                                    comm_keyval, mpi_extra_state);
  *comm_keyval = mpi2abi_keyval(*comm_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_delete_attr(MPIABI_Comm comm, int comm_keyval) {
  int ierr =
      MPI_Comm_delete_attr(abi2mpi_comm(comm), abi2mpi_keyval(comm_keyval));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_dup(MPIABI_Comm comm, MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_dup(abi2mpi_comm(comm), &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_dup_with_info(MPIABI_Comm comm, MPIABI_Info info,
                              MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_dup_with_info(abi2mpi_comm(comm), abi2mpi_info(info),
                                    &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_free(MPIABI_Comm *comm) {
  MPI_Comm mpi_comm = abi2mpi_comm(*comm);
  int ierr = MPI_Comm_free(&mpi_comm);
  *comm = mpi2abi_comm(mpi_comm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_get_name(MPIABI_Comm comm, char *comm_name, int *resultlen) {
  int ierr = MPI_Comm_get_name(abi2mpi_comm(comm), comm_name, resultlen);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_free_keyval(int *comm_keyval) {
  int mpi_comm_keyval = abi2mpi_keyval(*comm_keyval);
  // We do not free the keyval wrappers
  int ierr = MPI_Comm_free_keyval(&mpi_comm_keyval);
  *comm_keyval = mpi2abi_keyval(mpi_comm_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_get_attr(MPIABI_Comm comm, int comm_keyval, void *attribute_val,
                         int *flag) {
  int ierr = MPI_Comm_get_attr(abi2mpi_comm(comm), abi2mpi_keyval(comm_keyval),
                               attribute_val, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_get_info(MPIABI_Comm comm, MPIABI_Info *info_used) {
  MPI_Info mpi_info_used;
  int ierr = MPI_Comm_get_info(abi2mpi_comm(comm), &mpi_info_used);
  *info_used = mpi2abi_info(mpi_info_used);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_group(MPIABI_Comm comm, MPIABI_Group *group) {
  MPI_Group mpi_group;
  int ierr = MPI_Comm_group(abi2mpi_comm(comm), &mpi_group);
  *group = mpi2abi_group(mpi_group);
  return mpi2abi_errorcode(ierr);
}

struct finish_Comm_idup_state {
  MPIABI_Comm *newcomm;
  MPI_Comm mpi_newcomm;
};
static void finish_Comm_idup(void *state1) {
  struct finish_Comm_idup_state *state = state1;
  *state->newcomm = mpi2abi_comm(state->mpi_newcomm);
  free(state);
}
int MPIABI_Comm_idup(MPIABI_Comm comm, MPIABI_Comm *newcomm,
                     MPIABI_Request *request) {
  struct finish_Comm_idup_state *finish_Comm_idup_state =
      malloc(sizeof *finish_Comm_idup_state);
  finish_Comm_idup_state->newcomm = newcomm;
  MPI_Request mpi_request;
  int ierr = MPI_Comm_idup(abi2mpi_comm(comm),
                           &finish_Comm_idup_state->mpi_newcomm, &mpi_request);
  *request = mpi2abi_request(mpi_request);
  struct lambda action = {finish_Comm_idup, finish_Comm_idup_state};
  request_action_insert(*request, action);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_idup_with_info(MPIABI_Comm comm, MPIABI_Info info,
                               MPIABI_Comm *newcomm, MPIABI_Request *request) {
  struct finish_Comm_idup_state *finish_Comm_idup_state =
      malloc(sizeof *finish_Comm_idup_state);
  finish_Comm_idup_state->newcomm = newcomm;
  MPI_Request mpi_request;
  int ierr = MPI_Comm_idup_with_info(abi2mpi_comm(comm), abi2mpi_info(info),
                                     &finish_Comm_idup_state->mpi_newcomm,
                                     &mpi_request);
  *request = mpi2abi_request(mpi_request);
  struct lambda action = {finish_Comm_idup, finish_Comm_idup_state};
  request_action_insert(*request, action);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_rank(MPIABI_Comm comm, int *rank) {
  int ierr = MPI_Comm_rank(abi2mpi_comm(comm), rank);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_remote_group(MPIABI_Comm comm, MPIABI_Group *group) {
  MPI_Group mpi_group;
  int ierr = MPI_Comm_remote_group(abi2mpi_comm(comm), &mpi_group);
  *group = mpi2abi_group(mpi_group);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_remote_size(MPIABI_Comm comm, int *size) {
  int ierr = MPI_Comm_remote_size(abi2mpi_comm(comm), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_set_attr(MPIABI_Comm comm, int comm_keyval,
                         void *attribute_val) {
  int ierr = MPI_Comm_set_attr(abi2mpi_comm(comm), abi2mpi_keyval(comm_keyval),
                               attribute_val);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_set_info(MPIABI_Comm comm, MPIABI_Info info) {
  int ierr = MPI_Comm_set_info(abi2mpi_comm(comm), abi2mpi_info(info));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_set_name(MPIABI_Comm comm, const char *comm_name) {
  int ierr = MPI_Comm_set_name(abi2mpi_comm(comm), comm_name);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_size(MPIABI_Comm comm, int *size) {
  int ierr = MPI_Comm_size(abi2mpi_comm(comm), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_split(MPIABI_Comm comm, int color, int key,
                      MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_split(abi2mpi_comm(comm), color, key, &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_free(MPIABI_Group *group) {
  MPI_Group mpi_group = abi2mpi_group(*group);
  int ierr = MPI_Group_free(&mpi_group);
  *group = mpi2abi_group(mpi_group);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_split_type(MPIABI_Comm comm, int split_type, int key,
                           MPIABI_Info info, MPIABI_Comm *newcomm) {
  int mpi_split_type;
  switch (split_type) {
  case MPIABI_COMM_TYPE_SHARED:
    mpi_split_type = MPI_COMM_TYPE_SHARED;
    break;
  case MPIABI_COMM_TYPE_HW_UNGUIDED:
    mpi_split_type = MPI_COMM_TYPE_HW_UNGUIDED;
    break;
  case MPIABI_COMM_TYPE_HW_GUIDED:
    mpi_split_type = MPI_COMM_TYPE_HW_GUIDED;
    break;
#if MPI_VERSION_NUMBER >= 400
  case MPIABI_COMM_TYPE_RESOURCE_GUIDED:
    mpi_split_type = MPI_COMM_TYPE_RESOURCE_GUIDED;
    break;
#endif
  default:
    assert(false);
  }
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_split_type(abi2mpi_comm(comm), mpi_split_type, key,
                                 abi2mpi_info(info), &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_test_inter(MPIABI_Comm comm, int *flag) {
  int ierr = MPI_Comm_test_inter(abi2mpi_comm(comm), flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_compare(MPIABI_Group group1, MPIABI_Group group2,
                         int *result) {
  int ierr =
      MPI_Group_compare(abi2mpi_group(group1), abi2mpi_group(group2), result);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_difference(MPIABI_Group group1, MPIABI_Group group2,
                            MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr = MPI_Group_difference(abi2mpi_group(group1), abi2mpi_group(group2),
                                  &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_excl(MPIABI_Group group, int n, const int ranks[],
                      MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr = MPI_Group_excl(abi2mpi_group(group), n, ranks, &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_from_session_pset(MPIABI_Session session,
                                   const char *pset_name,
                                   MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr = MPI_Group_from_session_pset(abi2mpi_session(session), pset_name,
                                         &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_incl(MPIABI_Group group, int n, const int ranks[],
                      MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr = MPI_Group_incl(abi2mpi_group(group), n, ranks, &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_intersection(MPIABI_Group group1, MPIABI_Group group2,
                              MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr = MPI_Group_intersection(abi2mpi_group(group1),
                                    abi2mpi_group(group2), &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_range_excl(MPIABI_Group group, int n, int ranges[][3],
                            MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr =
      MPI_Group_range_excl(abi2mpi_group(group), n, ranges, &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_range_incl(MPIABI_Group group, int n, int ranges[][3],
                            MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr =
      MPI_Group_range_incl(abi2mpi_group(group), n, ranges, &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_rank(MPIABI_Group group, int *rank) {
  int ierr = MPI_Group_rank(abi2mpi_group(group), rank);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_size(MPIABI_Group group, int *size) {
  int ierr = MPI_Group_size(abi2mpi_group(group), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_translate_ranks(MPIABI_Group group1, int n, const int ranks1[],
                                 MPIABI_Group group2, int ranks2[]) {
  int ierr = MPI_Group_translate_ranks(abi2mpi_group(group1), n, ranks1,
                                       abi2mpi_group(group2), ranks2);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Group_union(MPIABI_Group group1, MPIABI_Group group2,
                       MPIABI_Group *newgroup) {
  MPI_Group mpi_newgroup;
  int ierr = MPI_Group_union(abi2mpi_group(group1), abi2mpi_group(group2),
                             &mpi_newgroup);
  *newgroup = mpi2abi_group(mpi_newgroup);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Intercomm_create(MPIABI_Comm local_comm, int local_leader,
                            MPIABI_Comm peer_comm, int remote_leader, int tag,
                            MPIABI_Comm *newintercomm) {
  MPI_Comm mpi_newintercomm;
  int ierr = MPI_Intercomm_create(abi2mpi_comm(local_comm), local_leader,
                                  abi2mpi_comm(peer_comm), remote_leader, tag,
                                  &mpi_newintercomm);
  *newintercomm = mpi2abi_comm(mpi_newintercomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Intercomm_create_from_groups(
    MPIABI_Group local_group, int local_leader, MPIABI_Group remote_group,
    int remote_leader, const char *stringtag, MPIABI_Info info,
    MPIABI_Errhandler errhandler, MPIABI_Comm *newintercomm) {
  MPI_Comm mpi_newintercomm;
  int ierr = MPI_Intercomm_create_from_groups(
      abi2mpi_group(local_group), local_leader, abi2mpi_group(remote_group),
      remote_leader, stringtag, abi2mpi_info(info),
      abi2mpi_errhandler(errhandler), &mpi_newintercomm);
  *newintercomm = mpi2abi_comm(mpi_newintercomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Intercomm_merge(MPIABI_Comm intercomm, int high,
                           MPIABI_Comm *newintracomm) {
  MPI_Comm mpi_newintracomm;
  int ierr =
      MPI_Intercomm_merge(abi2mpi_comm(intercomm), high, &mpi_newintracomm);
  *newintracomm = mpi2abi_comm(mpi_newintracomm);
  return mpi2abi_errorcode(ierr);
}

struct abi_Type_create_keyval_state {
  MPIABI_Type_copy_attr_function *abi_type_copy_attr_fn;
  MPIABI_Type_delete_attr_function *abi_type_delete_attr_fn;
  void *abi_extra_state;
};
static int mpi_Type_create_keyval_copy_attr_function(
    MPI_Datatype oldtype, int type_keyval, void *extra_state,
    void *attribute_val_in, void *attribute_val_out, int *flag) {
  const struct abi_Type_create_keyval_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_type_copy_attr_fn(
      mpi2abi_datatype(oldtype), mpi2abi_keyval(type_keyval),
      mpi_extra_state->abi_extra_state, attribute_val_in, attribute_val_out,
      flag);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Type_create_keyval_delete_attr_function(MPI_Datatype type,
                                                       int type_keyval,
                                                       void *attribute_val,
                                                       void *extra_state) {
  const struct abi_Type_create_keyval_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_type_delete_attr_fn(
      mpi2abi_datatype(type), mpi2abi_keyval(type_keyval), attribute_val,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Type_create_keyval(
    MPIABI_Type_copy_attr_function *type_copy_attr_fn,
    MPIABI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state) {
  struct abi_Type_create_keyval_state *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_type_copy_attr_fn = type_copy_attr_fn;
  mpi_extra_state->abi_type_delete_attr_fn = type_delete_attr_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  int ierr = MPI_Type_create_keyval(mpi_Type_create_keyval_copy_attr_function,
                                    mpi_Type_create_keyval_delete_attr_function,
                                    type_keyval, mpi_extra_state);
  *type_keyval = mpi2abi_keyval(*type_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_delete_attr(MPIABI_Datatype datatype, int type_keyval) {
  int ierr = MPI_Type_delete_attr(abi2mpi_datatype(datatype),
                                  abi2mpi_keyval(type_keyval));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_free_keyval(int *type_keyval) {
  // We do not free the keyval wrappers
  int mpi_type_keyval = abi2mpi_keyval(*type_keyval);
  int ierr = MPI_Type_free_keyval(&mpi_type_keyval);
  *type_keyval = mpi2abi_keyval(mpi_type_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_attr(MPIABI_Datatype datatype, int type_keyval,
                         void *attribute_val, int *flag) {
  int ierr =
      MPI_Type_get_attr(abi2mpi_datatype(datatype), abi2mpi_keyval(type_keyval),
                        attribute_val, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_name(MPIABI_Datatype datatype, char *type_name,
                         int *resultlen) {
  int ierr =
      MPI_Type_get_name(abi2mpi_datatype(datatype), type_name, resultlen);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_set_attr(MPIABI_Datatype datatype, int type_keyval,
                         void *attribute_val) {
  int ierr = MPI_Type_set_attr(abi2mpi_datatype(datatype),
                               abi2mpi_keyval(type_keyval), attribute_val);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_set_name(MPIABI_Datatype datatype, const char *type_name) {
  int ierr = MPI_Type_set_name(abi2mpi_datatype(datatype), type_name);
  return mpi2abi_errorcode(ierr);
}

struct abi_Win_create_keyval_state {
  MPIABI_Win_copy_attr_function *abi_win_copy_attr_fn;
  MPIABI_Win_delete_attr_function *abi_win_delete_attr_fn;
  void *abi_extra_state;
};
static int mpi_Win_create_keyval_copy_attr_function(
    MPI_Win oldwin, int win_keyval, void *extra_state, void *attribute_val_in,
    void *attribute_val_out, int *flag) {
  const struct abi_Win_create_keyval_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_win_copy_attr_fn(
      mpi2abi_win(oldwin), mpi2abi_keyval(win_keyval),
      mpi_extra_state->abi_extra_state, attribute_val_in, attribute_val_out,
      flag);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Win_create_keyval_delete_attr_function(MPI_Win win,
                                                      int win_keyval,
                                                      void *attribute_val,
                                                      void *extra_state) {
  const struct abi_Win_create_keyval_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_win_delete_attr_fn(
      mpi2abi_win(win), mpi2abi_keyval(win_keyval), attribute_val,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Win_create_keyval(
    MPIABI_Win_copy_attr_function *win_copy_attr_fn,
    MPIABI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state) {
  struct abi_Win_create_keyval_state *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_win_copy_attr_fn = win_copy_attr_fn;
  mpi_extra_state->abi_win_delete_attr_fn = win_delete_attr_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  int ierr = MPI_Win_create_keyval(mpi_Win_create_keyval_copy_attr_function,
                                   mpi_Win_create_keyval_delete_attr_function,
                                   win_keyval, mpi_extra_state);
  *win_keyval = mpi2abi_keyval(*win_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_delete_attr(MPIABI_Win win, int win_keyval) {
  int ierr = MPI_Win_delete_attr(abi2mpi_win(win), abi2mpi_keyval(win_keyval));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_free_keyval(int *win_keyval) {
  int mpi_win_keyval = abi2mpi_keyval(*win_keyval);
  int ierr = MPI_Win_free_keyval(&mpi_win_keyval);
  *win_keyval = mpi2abi_keyval(mpi_win_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_get_attr(MPIABI_Win win, int win_keyval, void *attribute_val,
                        int *flag) {
  int ierr = MPI_Win_get_attr(abi2mpi_win(win), abi2mpi_keyval(win_keyval),
                              attribute_val, flag);
  switch (win_keyval) {
  case MPIABI_WIN_CREATE_FLAVOR:
    switch (*(int *)attribute_val) {
    case MPI_WIN_FLAVOR_CREATE:
      *(int *)attribute_val = MPIABI_WIN_FLAVOR_CREATE;
      break;
    case MPI_WIN_FLAVOR_ALLOCATE:
      *(int *)attribute_val = MPIABI_WIN_FLAVOR_ALLOCATE;
      break;
    case MPI_WIN_FLAVOR_DYNAMIC:
      *(int *)attribute_val = MPIABI_WIN_FLAVOR_DYNAMIC;
      break;
    case MPI_WIN_FLAVOR_SHARED:
      *(int *)attribute_val = MPIABI_WIN_FLAVOR_SHARED;
      break;
    default:
      assert(false);
    }
    break;
  case MPIABI_WIN_MODEL:
    switch (*(int *)attribute_val) {
    case MPI_WIN_SEPARATE:
      *(int *)attribute_val = MPIABI_WIN_SEPARATE;
      break;
    case MPI_WIN_UNIFIED:
      *(int *)attribute_val = MPIABI_WIN_UNIFIED;
      break;
    default:
      assert(0);
    }
    break;
  }
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_get_name(MPIABI_Win win, char *win_name, int *resultlen) {
  int ierr = MPI_Win_get_name(abi2mpi_win(win), win_name, resultlen);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_set_attr(MPIABI_Win win, int win_keyval, void *attribute_val) {
  int ierr = MPI_Win_set_attr(abi2mpi_win(win), abi2mpi_keyval(win_keyval),
                              attribute_val);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_set_name(MPIABI_Win win, const char *win_name) {
  int ierr = MPI_Win_set_name(abi2mpi_win(win), win_name);
  return mpi2abi_errorcode(ierr);
}

// A.3.6 Virtual Topologies for MPI Processes C Bindings

int MPIABI_Cart_coords(MPIABI_Comm comm, int rank, int maxdims, int coords[]) {
  int ierr = MPI_Cart_coords(abi2mpi_comm(comm), rank, maxdims, coords);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cart_create(MPIABI_Comm comm_old, int ndims, const int dims[],
                       const int periods[], int reorder,
                       MPIABI_Comm *comm_cart) {
  MPI_Comm mpi_comm_cart;
  int ierr = MPI_Cart_create(abi2mpi_comm(comm_old), ndims, dims, periods,
                             reorder, &mpi_comm_cart);
  *comm_cart = mpi2abi_comm(mpi_comm_cart);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cart_get(MPIABI_Comm comm, int maxdims, int dims[], int periods[],
                    int coords[]) {
  int ierr = MPI_Cart_get(abi2mpi_comm(comm), maxdims, dims, periods, coords);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cart_map(MPIABI_Comm comm, int ndims, const int dims[],
                    const int periods[], int *newrank) {
  int ierr = MPI_Cart_map(abi2mpi_comm(comm), ndims, dims, periods, newrank);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cart_rank(MPIABI_Comm comm, const int coords[], int *rank) {
  int ierr = MPI_Cart_rank(abi2mpi_comm(comm), coords, rank);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cart_shift(MPIABI_Comm comm, int direction, int disp,
                      int *rank_source, int *rank_dest) {
  int ierr = MPI_Cart_shift(abi2mpi_comm(comm), direction, disp, rank_source,
                            rank_dest);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cart_sub(MPIABI_Comm comm, const int remain_dims[],
                    MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Cart_sub(abi2mpi_comm(comm), remain_dims, &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Cartdim_get(MPIABI_Comm comm, int *ndims) {
  int ierr = MPI_Cartdim_get(abi2mpi_comm(comm), ndims);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Dims_create(int nnodes, int ndims, int dims[]) {
  int ierr = MPI_Dims_create(nnodes, ndims, dims);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Dist_graph_create(MPIABI_Comm comm_old, int n, const int sources[],
                             const int degrees[], const int destinations[],
                             const int weights[], MPIABI_Info info, int reorder,
                             MPIABI_Comm *comm_dist_graph) {
  const int *mpi_weights = weights == MPIABI_UNWEIGHTED      ? MPI_UNWEIGHTED
                           : weights == MPIABI_WEIGHTS_EMPTY ? MPI_WEIGHTS_EMPTY
                                                             : weights;
  MPI_Comm mpi_comm_dist_graph;
  int ierr = MPI_Dist_graph_create(
      abi2mpi_comm(comm_old), n, sources, degrees, destinations, mpi_weights,
      abi2mpi_info(info), reorder, &mpi_comm_dist_graph);
  *comm_dist_graph = mpi2abi_comm(mpi_comm_dist_graph);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Dist_graph_create_adjacent(MPIABI_Comm comm_old, int indegree,
                                      const int sources[],
                                      const int sourceweights[], int outdegree,
                                      const int destinations[],
                                      const int destweights[], MPIABI_Info info,
                                      int reorder,
                                      MPIABI_Comm *comm_dist_graph) {
  const int *mpi_sourceweights =
      sourceweights == MPIABI_UNWEIGHTED      ? MPI_UNWEIGHTED
      : sourceweights == MPIABI_WEIGHTS_EMPTY ? MPI_WEIGHTS_EMPTY
                                              : sourceweights;
  const int *mpi_destweights = destweights == MPIABI_UNWEIGHTED ? MPI_UNWEIGHTED
                               : destweights == MPIABI_WEIGHTS_EMPTY
                                   ? MPI_WEIGHTS_EMPTY
                                   : destweights;
  MPI_Comm mpi_comm_dist_graph;
  int ierr = MPI_Dist_graph_create_adjacent(
      abi2mpi_comm(comm_old), indegree, sources, mpi_sourceweights, outdegree,
      destinations, mpi_destweights, abi2mpi_info(info), reorder,
      &mpi_comm_dist_graph);
  *comm_dist_graph = mpi2abi_comm(mpi_comm_dist_graph);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Dist_graph_neighbors(MPIABI_Comm comm, int maxindegree,
                                int sources[], int sourceweights[],
                                int maxoutdegree, int destinations[],
                                int destweights[]) {
  int ierr = MPI_Dist_graph_neighbors(abi2mpi_comm(comm), maxindegree, sources,
                                      sourceweights, maxoutdegree, destinations,
                                      destweights);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Dist_graph_neighbors_count(MPIABI_Comm comm, int *indegree,
                                      int *outdegree, int *weighted) {
  int ierr = MPI_Dist_graph_neighbors_count(abi2mpi_comm(comm), indegree,
                                            outdegree, weighted);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Graph_create(MPIABI_Comm comm_old, int nnodes, const int index[],
                        const int edges[], int reorder,
                        MPIABI_Comm *comm_graph) {
  MPI_Comm mpi_comm_graph;
  int ierr = MPI_Graph_create(abi2mpi_comm(comm_old), nnodes, index, edges,
                              reorder, &mpi_comm_graph);
  *comm_graph = mpi2abi_comm(mpi_comm_graph);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Graph_get(MPIABI_Comm comm, int maxindex, int maxedges, int index[],
                     int edges[]) {
  int ierr =
      MPI_Graph_get(abi2mpi_comm(comm), maxindex, maxedges, index, edges);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Graph_map(MPIABI_Comm comm, int nnodes, const int index[],
                     const int edges[], int *newrank) {
  int ierr = MPI_Graph_map(abi2mpi_comm(comm), nnodes, index, edges, newrank);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Graph_neighbors(MPIABI_Comm comm, int rank, int maxneighbors,
                           int neighbors[]) {
  int ierr =
      MPI_Graph_neighbors(abi2mpi_comm(comm), rank, maxneighbors, neighbors);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Graph_neighbors_count(MPIABI_Comm comm, int rank, int *nneighbors) {
  int ierr = MPI_Graph_neighbors_count(abi2mpi_comm(comm), rank, nneighbors);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Graphdims_get(MPIABI_Comm comm, int *nnodes, int *nedges) {
  int ierr = MPI_Graphdims_get(abi2mpi_comm(comm), nnodes, nedges);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPIABI_Datatype recvtype,
                               MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_allgather(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_allgather_c(const void *sendbuf, MPIABI_Count sendcount,
                                 MPIABI_Datatype sendtype, void *recvbuf,
                                 MPIABI_Count recvcount,
                                 MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                 MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_allgather_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                MPIABI_Datatype sendtype, void *recvbuf,
                                const int recvcounts[], const int displs[],
                                MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_allgatherv(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcounts,
      displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_allgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
                                  MPIABI_Datatype sendtype, void *recvbuf,
                                  const MPIABI_Count recvcounts[],
                                  const MPIABI_Aint displs[],
                                  MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                  MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_allgatherv_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, mpi_recvcounts,
      mpi_displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                              MPIABI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPIABI_Datatype recvtype,
                              MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_alltoall(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_alltoall_c(const void *sendbuf, MPIABI_Count sendcount,
                                MPIABI_Datatype sendtype, void *recvbuf,
                                MPIABI_Count recvcount,
                                MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_alltoall_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                               const int sdispls[], MPIABI_Datatype sendtype,
                               void *recvbuf, const int recvcounts[],
                               const int rdispls[], MPIABI_Datatype recvtype,
                               MPIABI_Comm comm, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_alltoallv(
      sendbuf, sendcounts, sdispls, abi2mpi_datatype(sendtype), recvbuf,
      recvcounts, rdispls, abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
      &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_alltoallv_c(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
    const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_alltoallv_c(
      sendbuf, mpi_sendcounts, mpi_sdispls, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_rdispls, abi2mpi_datatype(recvtype),
      abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                               const MPIABI_Aint sdispls[],
                               const MPIABI_Datatype sendtypes[], void *recvbuf,
                               const int recvcounts[],
                               const MPIABI_Aint rdispls[],
                               const MPIABI_Datatype recvtypes[],
                               MPIABI_Comm comm, MPIABI_Request *request) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_alltoallw(
      sendbuf, sendcounts, sdispls, mpi_sendtypes, recvbuf, recvcounts, rdispls,
      mpi_recvtypes, abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Ineighbor_alltoallw_c(const void *sendbuf,
                                 const MPIABI_Count sendcounts[],
                                 const MPIABI_Aint sdispls[],
                                 const MPIABI_Datatype sendtypes[],
                                 void *recvbuf, const MPIABI_Count recvcounts[],
                                 const MPIABI_Aint rdispls[],
                                 const MPIABI_Datatype recvtypes[],
                                 MPIABI_Comm comm, MPIABI_Request *request) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  int ierr = MPI_Ineighbor_alltoallw_c(sendbuf, mpi_sendcounts, mpi_sdispls,
                                       mpi_sendtypes, recvbuf, mpi_recvcounts,
                                       mpi_rdispls, mpi_recvtypes,
                                       abi2mpi_comm(comm), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgather(const void *sendbuf, int sendcount,
                              MPIABI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPIABI_Datatype recvtype,
                              MPIABI_Comm comm) {
  int ierr = MPI_Neighbor_allgather(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgather_c(const void *sendbuf, MPIABI_Count sendcount,
                                MPIABI_Datatype sendtype, void *recvbuf,
                                MPIABI_Count recvcount,
                                MPIABI_Datatype recvtype, MPIABI_Comm comm) {
  int ierr = MPI_Neighbor_allgather_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgather_init(const void *sendbuf, int sendcount,
                                   MPIABI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPIABI_Datatype recvtype,
                                   MPIABI_Comm comm, MPIABI_Info info,
                                   MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_allgather_init(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), abi2mpi_info(info),
      &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgather_init_c(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, MPIABI_Count recvcount, MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_allgather_init_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), abi2mpi_info(info),
      &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPIABI_Datatype recvtype, MPIABI_Comm comm) {
  int ierr = MPI_Neighbor_allgatherv(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcounts,
      displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
                                 MPIABI_Datatype sendtype, void *recvbuf,
                                 const MPIABI_Count recvcounts[],
                                 const MPIABI_Aint displs[],
                                 MPIABI_Datatype recvtype, MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  int ierr = MPI_Neighbor_allgatherv_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, mpi_recvcounts,
      mpi_displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount,
                                    MPIABI_Datatype sendtype, void *recvbuf,
                                    const int recvcounts[], const int displs[],
                                    MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                    MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_allgatherv_init(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcounts,
      displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_allgatherv_init_c(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint displs[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_displs = (const MPI_Aint *)displs;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_displs[size];
  for (int n = 0; n < size; ++n)
    mpi_displs[n] = displs[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_allgatherv_init_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, mpi_recvcounts,
      mpi_displs, abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPIABI_Datatype recvtype,
                             MPIABI_Comm comm) {
  int ierr = MPI_Neighbor_alltoall(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoall_c(const void *sendbuf, MPIABI_Count sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                               MPIABI_Comm comm) {
  int ierr = MPI_Neighbor_alltoall_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoall_init(const void *sendbuf, int sendcount,
                                  MPIABI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPIABI_Datatype recvtype,
                                  MPIABI_Comm comm, MPIABI_Info info,
                                  MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_alltoall_init(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), abi2mpi_info(info),
      &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoall_init_c(const void *sendbuf, MPIABI_Count sendcount,
                                    MPIABI_Datatype sendtype, void *recvbuf,
                                    MPIABI_Count recvcount,
                                    MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                    MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_alltoall_init_c(
      sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount,
      abi2mpi_datatype(recvtype), abi2mpi_comm(comm), abi2mpi_info(info),
      &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                              const int sdispls[], MPIABI_Datatype sendtype,
                              void *recvbuf, const int recvcounts[],
                              const int rdispls[], MPIABI_Datatype recvtype,
                              MPIABI_Comm comm) {
  int ierr = MPI_Neighbor_alltoallv(
      sendbuf, sendcounts, sdispls, abi2mpi_datatype(sendtype), recvbuf,
      recvcounts, rdispls, abi2mpi_datatype(recvtype), abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallv_c(const void *sendbuf,
                                const MPIABI_Count sendcounts[],
                                const MPIABI_Aint sdispls[],
                                MPIABI_Datatype sendtype, void *recvbuf,
                                const MPIABI_Count recvcounts[],
                                const MPIABI_Aint rdispls[],
                                MPIABI_Datatype recvtype, MPIABI_Comm comm) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  int ierr = MPI_Neighbor_alltoallv_c(
      sendbuf, mpi_sendcounts, mpi_sdispls, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_rdispls, abi2mpi_datatype(recvtype),
      abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallv_init(const void *sendbuf, const int sendcounts[],
                                   const int sdispls[],
                                   MPIABI_Datatype sendtype, void *recvbuf,
                                   const int recvcounts[], const int rdispls[],
                                   MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                   MPIABI_Info info, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_alltoallv_init(
      sendbuf, sendcounts, sdispls, abi2mpi_datatype(sendtype), recvbuf,
      recvcounts, rdispls, abi2mpi_datatype(recvtype), abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallv_init_c(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
    const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request) {
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_alltoallv_init_c(
      sendbuf, mpi_sendcounts, mpi_sdispls, abi2mpi_datatype(sendtype), recvbuf,
      mpi_recvcounts, mpi_rdispls, abi2mpi_datatype(recvtype),
      abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                              const MPIABI_Aint sdispls[],
                              const MPIABI_Datatype sendtypes[], void *recvbuf,
                              const int recvcounts[],
                              const MPIABI_Aint rdispls[],
                              const MPIABI_Datatype recvtypes[],
                              MPIABI_Comm comm) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  int ierr = MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, mpi_sendtypes,
                                    recvbuf, recvcounts, rdispls, mpi_recvtypes,
                                    abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallw_c(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  int ierr = MPI_Neighbor_alltoallw_c(
      sendbuf, mpi_sendcounts, mpi_sdispls, mpi_sendtypes, recvbuf,
      mpi_recvcounts, mpi_rdispls, mpi_recvtypes, abi2mpi_comm(comm));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallw_init(
    const void *sendbuf, const int sendcounts[], const MPIABI_Aint sdispls[],
    const MPIABI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPIABI_Aint rdispls[], const MPIABI_Datatype recvtypes[],
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_alltoallw_init(
      sendbuf, sendcounts, sdispls, mpi_sendtypes, recvbuf, recvcounts, rdispls,
      mpi_recvtypes, abi2mpi_comm(comm), abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Neighbor_alltoallw_init_c(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request) {
  int size;
  int ierr1 = MPIABI_Comm_size(comm, &size);
  if (ierr1)
    return ierr1;
#if SIZEOF_MPI_COUNT == SIZEOF_PTRDIFF_T && SIZEOF_MPI_AINT == SIZEOF_PTRDIFF_T
  const MPI_Count *mpi_sendcounts = (const MPI_Count *)sendcounts;
  const MPI_Aint *mpi_sdispls = (const MPI_Aint *)sdispls;
  const MPI_Count *mpi_recvcounts = (const MPI_Count *)recvcounts;
  const MPI_Aint *mpi_rdispls = (const MPI_Aint *)rdispls;
#else
  MPI_Count mpi_sendcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_sendcounts[n] = sendcounts[n];
  MPI_Aint mpi_sdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_sdispls[n] = sdispls[n];
  MPI_Count mpi_recvcounts[size];
  for (int n = 0; n < size; ++n)
    mpi_recvcounts[n] = recvcounts[n];
  MPI_Aint mpi_rdispls[size];
  for (int n = 0; n < size; ++n)
    mpi_rdispls[n] = rdispls[n];
#endif
  MPI_Datatype mpi_sendtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_sendtypes[n] = abi2mpi_datatype(sendtypes[n]);
  MPI_Datatype mpi_recvtypes[size];
  for (int n = 0; n < size; ++n)
    mpi_recvtypes[n] = abi2mpi_datatype(recvtypes[n]);
  MPI_Request mpi_request;
  int ierr = MPI_Neighbor_alltoallw_init_c(
      sendbuf, mpi_sendcounts, mpi_sdispls, mpi_sendtypes, recvbuf,
      mpi_recvcounts, mpi_rdispls, mpi_recvtypes, abi2mpi_comm(comm),
      abi2mpi_info(info), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Topo_test(MPIABI_Comm comm, int *status) {
  int ierr = MPI_Topo_test(abi2mpi_comm(comm), status);
  switch (*status) {
  case MPI_GRAPH:
    *status = MPIABI_GRAPH;
    break;
  case MPI_CART:
    *status = MPIABI_CART;
    break;
  case MPI_DIST_GRAPH:
    *status = MPIABI_DIST_GRAPH;
    break;
  case MPI_UNDEFINED:
    *status = MPIABI_UNDEFINED;
    break;
  default:
    assert(false);
  }
  return mpi2abi_errorcode(ierr);
}

// A.3.7 MPI Environmental Management C Bindings

int MPIABI_Add_error_class(int *errorclass) {
  int ierr = MPI_Add_error_class(errorclass);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Add_error_code(int errorclass, int *errorcode) {
  int ierr = MPI_Add_error_code(errorclass, errorcode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Add_error_string(int errorcode, const char *string) {
  int ierr = MPI_Add_error_string(errorcode, string);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Alloc_mem(MPIABI_Aint size, MPIABI_Info info, void *baseptr) {
  int ierr = MPI_Alloc_mem(size, abi2mpi_info(info), baseptr);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_call_errhandler(MPIABI_Comm comm, int errorcode) {
  int ierr = MPI_Comm_call_errhandler(abi2mpi_comm(comm), errorcode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_create_errhandler(
    MPIABI_Comm_errhandler_function *comm_errhandler_fn,
    MPIABI_Errhandler *errhandler) {
  // This is not possible; errhandler calls cannot be forwarded
  assert(false);
}

int MPIABI_Comm_get_errhandler(MPIABI_Comm comm,
                               MPIABI_Errhandler *errhandler) {
  MPI_Errhandler mpi_errhandler;
  int ierr = MPI_Comm_get_errhandler(abi2mpi_comm(comm), &mpi_errhandler);
  *errhandler = mpi2abi_errhandler(mpi_errhandler);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_set_errhandler(MPIABI_Comm comm, MPIABI_Errhandler errhandler) {
  int ierr = MPI_Comm_set_errhandler(abi2mpi_comm(comm),
                                     abi2mpi_errhandler(errhandler));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Errhandler_free(MPIABI_Errhandler *errhandler) {
  MPI_Errhandler mpi_errhandler;
  int ierr = MPI_Errhandler_free(&mpi_errhandler);
  *errhandler = mpi2abi_errhandler(mpi_errhandler);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Error_class(int errorcode, int *errorclass) {
  int ierr = MPI_Error_class(errorcode, errorclass);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Error_string(int errorcode, char *string, int *resultlen) {
  int ierr = MPI_Error_string(errorcode, string, resultlen);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_call_errhandler(MPIABI_File fh, int errorcode) {
  int ierr = MPI_File_call_errhandler(abi2mpi_file(fh), errorcode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_create_errhandler(
    MPIABI_File_errhandler_function *file_errhandler_fn,
    MPIABI_Errhandler *errhandler) {
  // This is not possible; errhandler calls cannot be forwarded
  assert(false);
}

int MPIABI_File_get_errhandler(MPIABI_File file,
                               MPIABI_Errhandler *errhandler) {
  MPI_Errhandler mpi_errhandler;
  int ierr = MPI_File_get_errhandler(abi2mpi_file(file), &mpi_errhandler);
  *errhandler = mpi2abi_errhandler(mpi_errhandler);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_set_errhandler(MPIABI_File file, MPIABI_Errhandler errhandler) {
  int ierr = MPI_File_set_errhandler(abi2mpi_file(file),
                                     abi2mpi_errhandler(errhandler));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Free_mem(void *base) {
  int ierr = MPI_Free_mem(base);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_hw_resource_info(MPIABI_Info *hw_info) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Info mpi_hw_info;
  int ierr = MPI_Get_hw_resource_info(&mpi_hw_info);
  *hw_info = mpi2abi_info(mpi_hw_info);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Get_library_version(char *version, int *resultlen) {
  int ierr = MPI_Get_library_version(version, resultlen);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_processor_name(char *name, int *resultlen) {
  int ierr = MPI_Get_processor_name(name, resultlen);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_version(int *version, int *subversion) {
  int ierr = MPI_Get_version(version, subversion);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Remove_error_class(int errorclass) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Remove_error_class(errorclass);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Remove_error_code(int errorcode) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Remove_error_code(errorcode);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Remove_error_string(int errorcode) {
#if MPI_VERSION_NUMBER >= 410
  int ierr = MPI_Remove_error_string(errorcode);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Session_call_errhandler(MPIABI_Session session, int errorcode) {
  int ierr = MPI_Session_call_errhandler(abi2mpi_session(session), errorcode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_create_errhandler(
    MPIABI_Session_errhandler_function *session_errhandler_fn,
    MPIABI_Errhandler *errhandler) {
  // This is not possible; errhandler calls cannot be forwarded
  assert(false);
}

int MPIABI_Session_get_errhandler(MPIABI_Session session,
                                  MPIABI_Errhandler *errhandler) {
  MPI_Errhandler mpi_errhandler;
  int ierr =
      MPI_Session_get_errhandler(abi2mpi_session(session), &mpi_errhandler);
  *errhandler = mpi2abi_errhandler(mpi_errhandler);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_set_errhandler(MPIABI_Session session,
                                  MPIABI_Errhandler errhandler) {
  int ierr = MPI_Session_set_errhandler(abi2mpi_session(session),
                                        abi2mpi_errhandler(errhandler));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_call_errhandler(MPIABI_Win win, int errorcode) {
  int ierr = MPI_Win_call_errhandler(abi2mpi_win(win), errorcode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_create_errhandler(
    MPIABI_Win_errhandler_function *win_errhandler_fn,
    MPIABI_Errhandler *errhandler) {
  // This is not possible; errhandler calls cannot be forwarded
  assert(false);
}

int MPIABI_Win_get_errhandler(MPIABI_Win win, MPIABI_Errhandler *errhandler) {
  MPI_Errhandler mpi_errhandler;
  int ierr = MPI_Win_get_errhandler(abi2mpi_win(win), &mpi_errhandler);
  *errhandler = mpi2abi_errhandler(mpi_errhandler);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_set_errhandler(MPIABI_Win win, MPIABI_Errhandler errhandler) {
  int ierr =
      MPI_Win_set_errhandler(abi2mpi_win(win), abi2mpi_errhandler(errhandler));
  return mpi2abi_errorcode(ierr);
}

double MPIABI_Wtick(void) { return MPI_Wtick(); }

double MPIABI_Wtime(void) { return MPI_Wtime(); }

// A.3.8 The Info Object C Bindings

int MPIABI_Info_create(MPIABI_Info *info) {
  MPI_Info mpi_info;
  int ierr = MPI_Info_create(&mpi_info);
  *info = mpi2abi_info(mpi_info);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_create_env(int argc, char *argv[], MPIABI_Info *info) {
  MPI_Info mpi_info;
  int ierr = MPI_Info_create_env(argc, argv, &mpi_info);
  *info = mpi2abi_info(mpi_info);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_delete(MPIABI_Info info, const char *key) {
  int ierr = MPI_Info_delete(abi2mpi_info(info), key);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_dup(MPIABI_Info info, MPIABI_Info *newinfo) {
  MPI_Info mpi_newinfo;
  int ierr = MPI_Info_dup(abi2mpi_info(info), &mpi_newinfo);
  *newinfo = mpi2abi_info(mpi_newinfo);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_free(MPIABI_Info *info) {
  MPI_Info mpi_info = abi2mpi_info(*info);
  int ierr = MPI_Info_free(&mpi_info);
  *info = mpi2abi_info(mpi_info);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_get_nkeys(MPIABI_Info info, int *nkeys) {
  int ierr = MPI_Info_get_nkeys(abi2mpi_info(info), nkeys);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_get_nthkey(MPIABI_Info info, int n, char *key) {
  int ierr = MPI_Info_get_nthkey(abi2mpi_info(info), n, key);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_get_string(MPIABI_Info info, const char *key, int *buflen,
                           char *value, int *flag) {
  int ierr = MPI_Info_get_string(abi2mpi_info(info), key, buflen, value, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_set(MPIABI_Info info, const char *key, const char *value) {
  int ierr = MPI_Info_set(abi2mpi_info(info), key, value);
  return mpi2abi_errorcode(ierr);
}

// A.3.9 Process Creation and Management C Bindings

int MPIABI_Abort(MPIABI_Comm comm, int errorcode) {
  int ierr = MPI_Abort(abi2mpi_comm(comm), errorcode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Close_port(const char *port_name) {
  int ierr = MPI_Close_port(port_name);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_accept(const char *port_name, MPIABI_Info info, int root,
                       MPIABI_Comm comm, MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_accept(port_name, abi2mpi_info(info), root,
                             abi2mpi_comm(comm), &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_connect(const char *port_name, MPIABI_Info info, int root,
                        MPIABI_Comm comm, MPIABI_Comm *newcomm) {
  MPI_Comm mpi_newcomm;
  int ierr = MPI_Comm_connect(port_name, abi2mpi_info(info), root,
                              abi2mpi_comm(comm), &mpi_newcomm);
  *newcomm = mpi2abi_comm(mpi_newcomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_disconnect(MPIABI_Comm *comm) {
  MPI_Comm mpi_comm = abi2mpi_comm(*comm);
  int ierr = MPI_Comm_disconnect(&mpi_comm);
  *comm = mpi2abi_comm(mpi_comm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_get_parent(MPIABI_Comm *parent) {
  MPI_Comm mpi_parent;
  int ierr = MPI_Comm_get_parent(&mpi_parent);
  *parent = mpi2abi_comm(mpi_parent);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_join(int fd, MPIABI_Comm *intercomm) {
  MPI_Comm mpi_intercomm;
  int ierr = MPI_Comm_join(fd, &mpi_intercomm);
  *intercomm = mpi2abi_comm(mpi_intercomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_spawn(const char *command, char *argv[], int maxprocs,
                      MPIABI_Info info, int root, MPIABI_Comm comm,
                      MPIABI_Comm *intercomm, int array_of_errcodes[]) {
  MPI_Comm mpi_intercomm;
  int ierr =
      MPI_Comm_spawn(command, argv, maxprocs, abi2mpi_info(info), root,
                     abi2mpi_comm(comm), &mpi_intercomm, array_of_errcodes);
  *intercomm = mpi2abi_comm(mpi_intercomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Comm_spawn_multiple(int count, char *array_of_commands[],
                               char **array_of_argv[],
                               const int array_of_maxprocs[],
                               const MPIABI_Info array_of_info[], int root,
                               MPIABI_Comm comm, MPIABI_Comm *intercomm,
                               int array_of_errcodes[]) {
  MPI_Info mpi_array_of_info[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_info[n] = abi2mpi_info(array_of_info[n]);
  MPI_Comm mpi_intercomm;
  int ierr = MPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv,
                                     array_of_maxprocs, mpi_array_of_info, root,
                                     abi2mpi_comm(comm), &mpi_intercomm,
                                     array_of_errcodes);
  *intercomm = mpi2abi_comm(mpi_intercomm);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Finalize(void) {
  int ierr = MPI_Finalize();
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Finalized(int *flag) {
  int ierr = MPI_Finalized(flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Init(int *argc, char ***argv) {
  int ierr = MPI_Init(argc, argv);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Init_thread(int *argc, char ***argv, int required, int *provided) {
  int ierr =
      MPI_Init_thread(argc, argv, abi2mpi_threadlevel(required), provided);
  *provided = mpi2abi_threadlevel(*provided);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Initialized(int *flag) {
  int ierr = MPI_Initialized(flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Is_thread_main(int *flag) {
  int ierr = MPI_Is_thread_main(flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Lookup_name(const char *service_name, MPIABI_Info info,
                       char *port_name) {
  int ierr = MPI_Lookup_name(service_name, abi2mpi_info(info), port_name);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Open_port(MPIABI_Info info, char *port_name) {
  int ierr = MPI_Open_port(abi2mpi_info(info), port_name);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Publish_name(const char *service_name, MPIABI_Info info,
                        const char *port_name) {
  int ierr = MPI_Publish_name(service_name, abi2mpi_info(info), port_name);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Query_thread(int *provided) {
  int ierr = MPI_Query_thread(provided);
  *provided = mpi2abi_threadlevel(*provided);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_finalize(MPIABI_Session *session) {
  MPI_Session mpi_session = abi2mpi_session(*session);
  int ierr = MPI_Session_finalize(&mpi_session);
  *session = mpi2abi_session(mpi_session);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_get_info(MPIABI_Session session, MPIABI_Info *info_used) {
  MPI_Info mpi_info_used;
  int ierr = MPI_Session_get_info(abi2mpi_session(session), &mpi_info_used);
  *info_used = mpi2abi_info(mpi_info_used);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_get_nth_pset(MPIABI_Session session, MPIABI_Info info, int n,
                                int *pset_len, char *pset_name) {
  int ierr = MPI_Session_get_nth_pset(
      abi2mpi_session(session), abi2mpi_info(info), n, pset_len, pset_name);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_get_num_psets(MPIABI_Session session, MPIABI_Info info,
                                 int *npset_names) {
  int ierr = MPI_Session_get_num_psets(abi2mpi_session(session),
                                       abi2mpi_info(info), npset_names);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_get_pset_info(MPIABI_Session session, const char *pset_name,
                                 MPIABI_Info *info) {
  MPI_Info mpi_info;
  int ierr =
      MPI_Session_get_pset_info(abi2mpi_session(session), pset_name, &mpi_info);
  *info = mpi2abi_info(mpi_info);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Session_init(MPIABI_Info info, MPIABI_Errhandler errhandler,
                        MPIABI_Session *session) {
  MPI_Session mpi_session;
  int ierr = MPI_Session_init(abi2mpi_info(info),
                              abi2mpi_errhandler(errhandler), &mpi_session);
  *session = mpi2abi_session(mpi_session);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Unpublish_name(const char *service_name, MPIABI_Info info,
                          const char *port_name) {
  int ierr = MPI_Unpublish_name(service_name, abi2mpi_info(info), port_name);
  return mpi2abi_errorcode(ierr);
}

// A.3.10 One-Sided Communications C Bindings

int MPIABI_Accumulate(const void *origin_addr, int origin_count,
                      MPIABI_Datatype origin_datatype, int target_rank,
                      MPIABI_Aint target_disp, int target_count,
                      MPIABI_Datatype target_datatype, MPIABI_Op op,
                      MPIABI_Win win) {
  int ierr = MPI_Accumulate(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_op(op), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Accumulate_c(const void *origin_addr, MPIABI_Count origin_count,
                        MPIABI_Datatype origin_datatype, int target_rank,
                        MPIABI_Aint target_disp, MPIABI_Count target_count,
                        MPIABI_Datatype target_datatype, MPIABI_Op op,
                        MPIABI_Win win) {
  int ierr = MPI_Accumulate_c(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_op(op), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Compare_and_swap(const void *origin_addr, const void *compare_addr,
                            void *result_addr, MPIABI_Datatype datatype,
                            int target_rank, MPIABI_Aint target_disp,
                            MPIABI_Win win) {
  int ierr = MPI_Compare_and_swap(origin_addr, compare_addr, result_addr,
                                  abi2mpi_datatype(datatype), target_rank,
                                  target_disp, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Fetch_and_op(const void *origin_addr, void *result_addr,
                        MPIABI_Datatype datatype, int target_rank,
                        MPIABI_Aint target_disp, MPIABI_Op op, MPIABI_Win win) {
  int ierr = MPI_Fetch_and_op(origin_addr, result_addr,
                              abi2mpi_datatype(datatype), target_rank,
                              target_disp, abi2mpi_op(op), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get(void *origin_addr, int origin_count,
               MPIABI_Datatype origin_datatype, int target_rank,
               MPIABI_Aint target_disp, int target_count,
               MPIABI_Datatype target_datatype, MPIABI_Win win) {
  int ierr =
      MPI_Get(origin_addr, origin_count, abi2mpi_datatype(origin_datatype),
              target_rank, target_disp, target_count,
              abi2mpi_datatype(target_datatype), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_accumulate(const void *origin_addr, int origin_count,
                          MPIABI_Datatype origin_datatype, void *result_addr,
                          int result_count, MPIABI_Datatype result_datatype,
                          int target_rank, MPIABI_Aint target_disp,
                          int target_count, MPIABI_Datatype target_datatype,
                          MPIABI_Op op, MPIABI_Win win) {
  int ierr = MPI_Get_accumulate(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), result_addr,
      result_count, abi2mpi_datatype(result_datatype), target_rank, target_disp,
      target_count, abi2mpi_datatype(target_datatype), abi2mpi_op(op),
      abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_accumulate_c(const void *origin_addr, MPIABI_Count origin_count,
                            MPIABI_Datatype origin_datatype, void *result_addr,
                            MPIABI_Count result_count,
                            MPIABI_Datatype result_datatype, int target_rank,
                            MPIABI_Aint target_disp, MPIABI_Count target_count,
                            MPIABI_Datatype target_datatype, MPIABI_Op op,
                            MPIABI_Win win) {
  int ierr = MPI_Get_accumulate_c(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), result_addr,
      result_count, abi2mpi_datatype(result_datatype), target_rank, target_disp,
      target_count, abi2mpi_datatype(target_datatype), abi2mpi_op(op),
      abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_c(void *origin_addr, MPIABI_Count origin_count,
                 MPIABI_Datatype origin_datatype, int target_rank,
                 MPIABI_Aint target_disp, MPIABI_Count target_count,
                 MPIABI_Datatype target_datatype, MPIABI_Win win) {
  int ierr =
      MPI_Get_c(origin_addr, origin_count, abi2mpi_datatype(origin_datatype),
                target_rank, target_disp, target_count,
                abi2mpi_datatype(target_datatype), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Put(const void *origin_addr, int origin_count,
               MPIABI_Datatype origin_datatype, int target_rank,
               MPIABI_Aint target_disp, int target_count,
               MPIABI_Datatype target_datatype, MPIABI_Win win) {
  int ierr =
      MPI_Put(origin_addr, origin_count, abi2mpi_datatype(origin_datatype),
              target_rank, target_disp, target_count,
              abi2mpi_datatype(target_datatype), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Put_c(const void *origin_addr, MPIABI_Count origin_count,
                 MPIABI_Datatype origin_datatype, int target_rank,
                 MPIABI_Aint target_disp, MPIABI_Count target_count,
                 MPIABI_Datatype target_datatype, MPIABI_Win win) {
  int ierr =
      MPI_Put(origin_addr, origin_count, abi2mpi_datatype(origin_datatype),
              target_rank, target_disp, target_count,
              abi2mpi_datatype(target_datatype), abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Raccumulate(const void *origin_addr, int origin_count,
                       MPIABI_Datatype origin_datatype, int target_rank,
                       MPIABI_Aint target_disp, int target_count,
                       MPIABI_Datatype target_datatype, MPIABI_Op op,
                       MPIABI_Win win, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Raccumulate(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_op(op), abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Raccumulate_c(const void *origin_addr, MPIABI_Count origin_count,
                         MPIABI_Datatype origin_datatype, int target_rank,
                         MPIABI_Aint target_disp, MPIABI_Count target_count,
                         MPIABI_Datatype target_datatype, MPIABI_Op op,
                         MPIABI_Win win, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Raccumulate_c(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_op(op), abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rget(void *origin_addr, int origin_count,
                MPIABI_Datatype origin_datatype, int target_rank,
                MPIABI_Aint target_disp, int target_count,
                MPIABI_Datatype target_datatype, MPIABI_Win win,
                MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rget(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rget_accumulate(const void *origin_addr, int origin_count,
                           MPIABI_Datatype origin_datatype, void *result_addr,
                           int result_count, MPIABI_Datatype result_datatype,
                           int target_rank, MPIABI_Aint target_disp,
                           int target_count, MPIABI_Datatype target_datatype,
                           MPIABI_Op op, MPIABI_Win win,
                           MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rget_accumulate(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), result_addr,
      result_count, abi2mpi_datatype(result_datatype), target_rank, target_disp,
      target_count, abi2mpi_datatype(target_datatype), abi2mpi_op(op),
      abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rget_accumulate_c(const void *origin_addr, MPIABI_Count origin_count,
                             MPIABI_Datatype origin_datatype, void *result_addr,
                             MPIABI_Count result_count,
                             MPIABI_Datatype result_datatype, int target_rank,
                             MPIABI_Aint target_disp, MPIABI_Count target_count,
                             MPIABI_Datatype target_datatype, MPIABI_Op op,
                             MPIABI_Win win, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rget_accumulate_c(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), result_addr,
      result_count, abi2mpi_datatype(result_datatype), target_rank, target_disp,
      target_count, abi2mpi_datatype(target_datatype), abi2mpi_op(op),
      abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rget_c(void *origin_addr, MPIABI_Count origin_count,
                  MPIABI_Datatype origin_datatype, int target_rank,
                  MPIABI_Aint target_disp, MPIABI_Count target_count,
                  MPIABI_Datatype target_datatype, MPIABI_Win win,
                  MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rget_c(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rput(const void *origin_addr, int origin_count,
                MPIABI_Datatype origin_datatype, int target_rank,
                MPIABI_Aint target_disp, int target_count,
                MPIABI_Datatype target_datatype, MPIABI_Win win,
                MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rput(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Rput_c(const void *origin_addr, MPIABI_Count origin_count,
                  MPIABI_Datatype origin_datatype, int target_rank,
                  MPIABI_Aint target_disp, MPIABI_Count target_count,
                  MPIABI_Datatype target_datatype, MPIABI_Win win,
                  MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_Rput_c(
      origin_addr, origin_count, abi2mpi_datatype(origin_datatype), target_rank,
      target_disp, target_count, abi2mpi_datatype(target_datatype),
      abi2mpi_win(win), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_allocate(MPIABI_Aint size, int disp_unit, MPIABI_Info info,
                        MPIABI_Comm comm, void *baseptr, MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr = MPI_Win_allocate(size, disp_unit, abi2mpi_info(info),
                              abi2mpi_comm(comm), baseptr, &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_allocate_c(MPIABI_Aint size, MPIABI_Aint disp_unit,
                          MPIABI_Info info, MPIABI_Comm comm, void *baseptr,
                          MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr = MPI_Win_allocate(size, disp_unit, abi2mpi_info(info),
                              abi2mpi_comm(comm), baseptr, &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_allocate_shared(MPIABI_Aint size, int disp_unit,
                               MPIABI_Info info, MPIABI_Comm comm,
                               void *baseptr, MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr = MPI_Win_allocate_shared(size, disp_unit, abi2mpi_info(info),
                                     abi2mpi_comm(comm), baseptr, &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_allocate_shared_c(MPIABI_Aint size, MPIABI_Aint disp_unit,
                                 MPIABI_Info info, MPIABI_Comm comm,
                                 void *baseptr, MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr = MPI_Win_allocate_shared_c(size, disp_unit, abi2mpi_info(info),
                                       abi2mpi_comm(comm), baseptr, &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_attach(MPIABI_Win win, void *base, MPIABI_Aint size) {
  int ierr = MPI_Win_attach(abi2mpi_win(win), base, size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_complete(MPIABI_Win win) {
  int ierr = MPI_Win_complete(abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_create(void *base, MPIABI_Aint size, int disp_unit,
                      MPIABI_Info info, MPIABI_Comm comm, MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr = MPI_Win_create(base, size, disp_unit, abi2mpi_info(info),
                            abi2mpi_comm(comm), &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_create_c(void *base, MPIABI_Aint size, MPIABI_Aint disp_unit,
                        MPIABI_Info info, MPIABI_Comm comm, MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr = MPI_Win_create_c(base, size, disp_unit, abi2mpi_info(info),
                              abi2mpi_comm(comm), &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_create_dynamic(MPIABI_Info info, MPIABI_Comm comm,
                              MPIABI_Win *win) {
  MPI_Win mpi_win;
  int ierr =
      MPI_Win_create_dynamic(abi2mpi_info(info), abi2mpi_comm(comm), &mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_detach(MPIABI_Win win, const void *base) {
  int ierr = MPI_Win_detach(abi2mpi_win(win), base);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_fence(int assert, MPIABI_Win win) {
  int ierr = MPI_Win_fence(assert, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_flush(int rank, MPIABI_Win win) {
  int ierr = MPI_Win_flush(rank, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_flush_all(MPIABI_Win win) {
  int ierr = MPI_Win_flush_all(abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_flush_local(int rank, MPIABI_Win win) {
  int ierr = MPI_Win_flush_local(rank, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_flush_local_all(MPIABI_Win win) {
  int ierr = MPI_Win_flush_local_all(abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_free(MPIABI_Win *win) {
  MPI_Win mpi_win = abi2mpi_win(*win);
  int ierr = MPI_Win_free(&mpi_win);
  *win = mpi2abi_win(mpi_win);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_get_group(MPIABI_Win win, MPIABI_Group *group) {
  MPI_Group mpi_group;
  int ierr = MPI_Win_get_group(abi2mpi_win(win), &mpi_group);
  *group = mpi2abi_group(mpi_group);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_get_info(MPIABI_Win win, MPIABI_Info *info_used) {
  MPI_Info mpi_info_used;
  int ierr = MPI_Win_get_info(abi2mpi_win(win), &mpi_info_used);
  *info_used = mpi2abi_info(mpi_info_used);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_lock(int lock_type, int rank, int assert, MPIABI_Win win) {
  switch (lock_type) {
  case MPIABI_LOCK_EXCLUSIVE:
    lock_type = MPI_LOCK_EXCLUSIVE;
    break;
  case MPIABI_LOCK_SHARED:
    lock_type = MPI_LOCK_SHARED;
    break;
  default:
    assert(false);
  }
  int ierr = MPI_Win_lock(lock_type, rank, assert, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_lock_all(int assert, MPIABI_Win win) {
  int ierr = MPI_Win_lock_all(assert, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_post(MPIABI_Group group, int assert, MPIABI_Win win) {
  int ierr = MPI_Win_post(abi2mpi_group(group), assert, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_set_info(MPIABI_Win win, MPIABI_Info info) {
  int ierr = MPI_Win_set_info(abi2mpi_win(win), abi2mpi_info(info));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_shared_query(MPIABI_Win win, int rank, MPIABI_Aint *size,
                            int *disp_unit, void *baseptr) {
  MPI_Aint mpi_size;
  int ierr = MPI_Win_shared_query(abi2mpi_win(win), rank, &mpi_size, disp_unit,
                                  baseptr);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_shared_query_c(MPIABI_Win win, int rank, MPIABI_Aint *size,
                              MPIABI_Aint *disp_unit, void *baseptr) {
  MPI_Aint mpi_size;
  MPI_Aint mpi_disp_unit;
  int ierr = MPI_Win_shared_query_c(abi2mpi_win(win), rank, &mpi_size,
                                    &mpi_disp_unit, baseptr);
  *size = mpi_size;
  *disp_unit = mpi_disp_unit;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_start(MPIABI_Group group, int assert, MPIABI_Win win) {
  int ierr = MPI_Win_start(abi2mpi_group(group), assert, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_sync(MPIABI_Win win) {
  int ierr = MPI_Win_sync(abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_test(MPIABI_Win win, int *flag) {
  int ierr = MPI_Win_test(abi2mpi_win(win), flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_unlock(int rank, MPIABI_Win win) {
  int ierr = MPI_Win_unlock(rank, abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_unlock_all(MPIABI_Win win) {
  int ierr = MPI_Win_unlock_all(abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Win_wait(MPIABI_Win win) {
  int ierr = MPI_Win_wait(abi2mpi_win(win));
  return mpi2abi_errorcode(ierr);
}

// A.3.11 External Interfaces C Bindings

int MPIABI_Grequest_complete(MPIABI_Request request) {
  int ierr = MPI_Grequest_complete(abi2mpi_request(request));
  return mpi2abi_errorcode(ierr);
}

struct abi_Grequest_start_state {
  MPIABI_Grequest_query_function *abi_query_fn;
  MPIABI_Grequest_free_function *abi_free_fn;
  MPIABI_Grequest_cancel_function *abi_cancel_fn;
  void *abi_extra_state;
};
static int mpi_Grequest_query_function(void *extra_state, MPI_Status *status) {
  const struct abi_Grequest_start_state *mpi_extra_state = extra_state;
  MPIABI_Status *abi_status = mpi2abi_statusptr(status);
  int ierr = mpi_extra_state->abi_query_fn(mpi_extra_state->abi_extra_state,
                                           abi_status);
  abi2mpi_statusptr(abi_status);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Grequest_free_function(void *extra_state) {
  const struct abi_Grequest_start_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_free_fn(mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Grequest_cancel_function(void *extra_state, int complete) {
  const struct abi_Grequest_start_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_cancel_fn(mpi_extra_state->abi_extra_state,
                                            complete);
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Grequest_start(MPIABI_Grequest_query_function *query_fn,
                          MPIABI_Grequest_free_function *free_fn,
                          MPIABI_Grequest_cancel_function *cancel_fn,
                          void *extra_state, MPIABI_Request *request) {
  struct abi_Grequest_start_state *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_query_fn = query_fn;
  mpi_extra_state->abi_free_fn = free_fn;
  mpi_extra_state->abi_cancel_fn = cancel_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  MPI_Request mpi_request;
  int ierr = MPI_Grequest_start(
      mpi_Grequest_query_function, mpi_Grequest_free_function,
      mpi_Grequest_cancel_function, mpi_extra_state, &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Status_set_cancelled(MPIABI_Status *status, int flag) {
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr = MPI_Status_set_cancelled(mpi_status, flag);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Status_set_elements(MPIABI_Status *status, MPIABI_Datatype datatype,
                               int count) {
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr =
      MPI_Status_set_elements(mpi_status, abi2mpi_datatype(datatype), count);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Status_set_elements_c(MPIABI_Status *status,
                                 MPIABI_Datatype datatype, MPIABI_Count count) {
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr =
      MPI_Status_set_elements_c(mpi_status, abi2mpi_datatype(datatype), count);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Status_set_error(MPIABI_Status *status, int err) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr = MPI_Status_set_error(mpi_status, err);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Status_set_source(MPIABI_Status *status, int source) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr = MPI_Status_set_source(mpi_status, source);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

int MPIABI_Status_set_tag(MPIABI_Status *status, int tag) {
#if MPI_VERSION_NUMBER >= 410
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr = MPI_Status_set_tag(mpi_status, tag);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
#else
  assert(0);
#endif
}

// A.3.12 I/O C Bindings

int MPIABI_File_close(MPIABI_File *fh) {
  MPI_File mpi_fh = abi2mpi_file(*fh);
  int ierr = MPI_File_close(&mpi_fh);
  *fh = mpi2abi_file(mpi_fh);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_delete(const char *filename, MPIABI_Info info) {
  int ierr = MPI_File_delete(filename, abi2mpi_info(info));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_amode(MPIABI_File fh, int *amode) {
  int ierr = MPI_File_get_amode(abi2mpi_file(fh), amode);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_atomicity(MPIABI_File fh, int *flag) {
  int ierr = MPI_File_get_atomicity(abi2mpi_file(fh), flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_byte_offset(MPIABI_File fh, MPIABI_Offset offset,
                                MPIABI_Offset *disp) {
  MPI_Offset mpi_disp;
  int ierr = MPI_File_get_byte_offset(abi2mpi_file(fh), offset, &mpi_disp);
  *disp = mpi_disp;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_group(MPIABI_File fh, MPIABI_Group *group) {
  MPI_Group mpi_group;
  int ierr = MPI_File_get_group(abi2mpi_file(fh), &mpi_group);
  *group = mpi2abi_group(mpi_group);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_info(MPIABI_File fh, MPIABI_Info *info_used) {
  MPI_Info mpi_info_used;
  int ierr = MPI_File_get_info(abi2mpi_file(fh), &mpi_info_used);
  *info_used = mpi2abi_info(mpi_info_used);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_position(MPIABI_File fh, MPIABI_Offset *offset) {
  MPI_Offset mpi_offset;
  int ierr = MPI_File_get_position(abi2mpi_file(fh), &mpi_offset);
  *offset = mpi_offset;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_position_shared(MPIABI_File fh, MPIABI_Offset *offset) {
  MPI_Offset mpi_offset;
  int ierr = MPI_File_get_position_shared(abi2mpi_file(fh), &mpi_offset);
  *offset = mpi_offset;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_size(MPIABI_File fh, MPIABI_Offset *size) {
  MPI_Offset mpi_size;
  int ierr = MPI_File_get_size(abi2mpi_file(fh), &mpi_size);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_type_extent(MPIABI_File fh, MPIABI_Datatype datatype,
                                MPIABI_Aint *extent) {
  MPI_Aint mpi_extent;
  int ierr = MPI_File_get_type_extent(abi2mpi_file(fh),
                                      abi2mpi_datatype(datatype), &mpi_extent);
  *extent = mpi_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_type_extent_c(MPIABI_File fh, MPIABI_Datatype datatype,
                                  MPIABI_Count *extent) {
  MPI_Count mpi_extent;
  int ierr = MPI_File_get_type_extent_c(
      abi2mpi_file(fh), abi2mpi_datatype(datatype), &mpi_extent);
  *extent = mpi_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_get_view(MPIABI_File fh, MPIABI_Offset *disp,
                         MPIABI_Datatype *etype, MPIABI_Datatype *filetype,
                         char *datarep) {
  MPI_Offset mpi_disp;
  MPI_Datatype mpi_etype;
  MPI_Datatype mpi_filetype;
  int ierr = MPI_File_get_view(abi2mpi_file(fh), &mpi_disp, &mpi_etype,
                               &mpi_filetype, datarep);
  *disp = mpi_disp;
  *etype = mpi2abi_datatype(mpi_etype);
  *filetype = mpi2abi_datatype(mpi_filetype);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread(MPIABI_File fh, void *buf, int count,
                      MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread(abi2mpi_file(fh), buf, count,
                            abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_all(MPIABI_File fh, void *buf, int count,
                          MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_all(abi2mpi_file(fh), buf, count,
                                abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_all_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                            MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_all_c(abi2mpi_file(fh), buf, count,
                                  abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_at(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                         int count, MPIABI_Datatype datatype,
                         MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_at(abi2mpi_file(fh), offset, buf, count,
                               abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_at_all(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                             int count, MPIABI_Datatype datatype,
                             MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_at_all(abi2mpi_file(fh), offset, buf, count,
                                   abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_at_all_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                               MPIABI_Count count, MPIABI_Datatype datatype,
                               MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_at_all_c(abi2mpi_file(fh), offset, buf, count,
                                     abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_at_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                           MPIABI_Count count, MPIABI_Datatype datatype,
                           MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_at_c(abi2mpi_file(fh), offset, buf, count,
                                 abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                        MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_c(abi2mpi_file(fh), buf, count,
                              abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_shared(MPIABI_File fh, void *buf, int count,
                             MPIABI_Datatype datatype,
                             MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_shared(abi2mpi_file(fh), buf, count,
                                   abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iread_shared_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype,
                               MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iread_shared_c(abi2mpi_file(fh), buf, count,
                                     abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite(MPIABI_File fh, const void *buf, int count,
                       MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite(abi2mpi_file(fh), buf, count,
                             abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_all(MPIABI_File fh, const void *buf, int count,
                           MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_all(abi2mpi_file(fh), buf, count,
                                 abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_all_c(MPIABI_File fh, const void *buf,
                             MPIABI_Count count, MPIABI_Datatype datatype,
                             MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_all_c(abi2mpi_file(fh), buf, count,
                                   abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_at(MPIABI_File fh, MPIABI_Offset offset, const void *buf,
                          int count, MPIABI_Datatype datatype,
                          MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_at(abi2mpi_file(fh), offset, buf, count,
                                abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_at_all(MPIABI_File fh, MPIABI_Offset offset,
                              const void *buf, int count,
                              MPIABI_Datatype datatype,
                              MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_at_all(abi2mpi_file(fh), offset, buf, count,
                                    abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_at_all_c(MPIABI_File fh, MPIABI_Offset offset,
                                const void *buf, MPIABI_Count count,
                                MPIABI_Datatype datatype,
                                MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_at_all_c(abi2mpi_file(fh), offset, buf, count,
                                      abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_at_c(MPIABI_File fh, MPIABI_Offset offset,
                            const void *buf, MPIABI_Count count,
                            MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_at_c(abi2mpi_file(fh), offset, buf, count,
                                  abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_c(MPIABI_File fh, const void *buf, MPIABI_Count count,
                         MPIABI_Datatype datatype, MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_c(abi2mpi_file(fh), buf, count,
                               abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_shared(MPIABI_File fh, const void *buf, int count,
                              MPIABI_Datatype datatype,
                              MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_shared(abi2mpi_file(fh), buf, count,
                                    abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_iwrite_shared_c(MPIABI_File fh, const void *buf,
                                MPIABI_Count count, MPIABI_Datatype datatype,
                                MPIABI_Request *request) {
  MPI_Request mpi_request;
  int ierr = MPI_File_iwrite_shared_c(abi2mpi_file(fh), buf, count,
                                      abi2mpi_datatype(datatype), &mpi_request);
  *request = mpi2abi_request(mpi_request);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_open(MPIABI_Comm comm, const char *filename, int amode,
                     MPIABI_Info info, MPIABI_File *fh) {
  MPI_File mpi_fh;
  int ierr = MPI_File_open(abi2mpi_comm(comm), filename, abi2mpi_mode(amode),
                           abi2mpi_info(info), &mpi_fh);
  *fh = mpi2abi_file(mpi_fh);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_preallocate(MPIABI_File fh, MPIABI_Offset size) {
  int ierr = MPI_File_preallocate(abi2mpi_file(fh), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read(MPIABI_File fh, void *buf, int count,
                     MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read(abi2mpi_file(fh), buf, count,
                           abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_all(MPIABI_File fh, void *buf, int count,
                         MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_all(abi2mpi_file(fh), buf, count,
                               abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_all_begin(MPIABI_File fh, void *buf, int count,
                               MPIABI_Datatype datatype) {
  int ierr = MPI_File_read_all_begin(abi2mpi_file(fh), buf, count,
                                     abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_all_begin_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                                 MPIABI_Datatype datatype) {
  int ierr = MPI_File_read_all_begin_c(abi2mpi_file(fh), buf, count,
                                       abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_all_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                           MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_all_c(abi2mpi_file(fh), buf, count,
                                 abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_all_end(MPIABI_File fh, void *buf, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_all_end(abi2mpi_file(fh), buf, mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                        int count, MPIABI_Datatype datatype,
                        MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_at(abi2mpi_file(fh), offset, buf, count,
                              abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at_all(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                            int count, MPIABI_Datatype datatype,
                            MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_at_all(abi2mpi_file(fh), offset, buf, count,
                                  abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at_all_begin(MPIABI_File fh, MPIABI_Offset offset,
                                  void *buf, int count,
                                  MPIABI_Datatype datatype) {
  int ierr = MPI_File_read_at_all_begin(abi2mpi_file(fh), offset, buf, count,
                                        abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at_all_begin_c(MPIABI_File fh, MPIABI_Offset offset,
                                    void *buf, MPIABI_Count count,
                                    MPIABI_Datatype datatype) {
  int ierr = MPI_File_read_at_all_begin_c(abi2mpi_file(fh), offset, buf, count,
                                          abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at_all_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                              MPIABI_Count count, MPIABI_Datatype datatype,
                              MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_at_all_c(abi2mpi_file(fh), offset, buf, count,
                                    abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at_all_end(MPIABI_File fh, void *buf,
                                MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_at_all_end(abi2mpi_file(fh), buf, mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_at_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                          MPIABI_Count count, MPIABI_Datatype datatype,
                          MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_at(abi2mpi_file(fh), offset, buf, count,
                              abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                       MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read(abi2mpi_file(fh), buf, count,
                           abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_ordered(MPIABI_File fh, void *buf, int count,
                             MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_ordered(abi2mpi_file(fh), buf, count,
                                   abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_ordered_begin(MPIABI_File fh, void *buf, int count,
                                   MPIABI_Datatype datatype) {
  int ierr = MPI_File_read_ordered_begin(abi2mpi_file(fh), buf, count,
                                         abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_ordered_begin_c(MPIABI_File fh, void *buf,
                                     MPIABI_Count count,
                                     MPIABI_Datatype datatype) {
  int ierr = MPI_File_read_ordered_begin_c(abi2mpi_file(fh), buf, count,
                                           abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_ordered_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype,
                               MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_ordered_c(abi2mpi_file(fh), buf, count,
                                     abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_ordered_end(MPIABI_File fh, void *buf,
                                 MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_ordered_end(abi2mpi_file(fh), buf, mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_shared(MPIABI_File fh, void *buf, int count,
                            MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_shared(abi2mpi_file(fh), buf, count,
                                  abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_read_shared_c(MPIABI_File fh, void *buf, MPIABI_Count count,
                              MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_read_shared_c(abi2mpi_file(fh), buf, count,
                                    abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_seek(MPIABI_File fh, MPIABI_Offset offset, int whence) {
  int ierr = MPI_File_seek(abi2mpi_file(fh), offset, abi2mpi_whence(whence));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_seek_shared(MPIABI_File fh, MPIABI_Offset offset, int whence) {
  int ierr =
      MPI_File_seek_shared(abi2mpi_file(fh), offset, abi2mpi_whence(whence));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_set_atomicity(MPIABI_File fh, int flag) {
  int ierr = MPI_File_set_atomicity(abi2mpi_file(fh), flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_set_info(MPIABI_File fh, MPIABI_Info info) {
  int ierr = MPI_File_set_info(abi2mpi_file(fh), abi2mpi_info(info));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_set_size(MPIABI_File fh, MPIABI_Offset size) {
  int ierr = MPI_File_set_size(abi2mpi_file(fh), size);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_set_view(MPIABI_File fh, MPIABI_Offset disp,
                         MPIABI_Datatype etype, MPIABI_Datatype filetype,
                         const char *datarep, MPIABI_Info info) {
  if (disp == MPIABI_DISPLACEMENT_CURRENT)
    disp = MPI_DISPLACEMENT_CURRENT;
  int ierr = MPI_File_set_view(abi2mpi_file(fh), disp, abi2mpi_datatype(etype),
                               abi2mpi_datatype(filetype), datarep,
                               abi2mpi_info(info));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_sync(MPIABI_File fh) {
  int ierr = MPI_File_sync(abi2mpi_file(fh));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write(MPIABI_File fh, const void *buf, int count,
                      MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write(abi2mpi_file(fh), buf, count,
                            abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_all(MPIABI_File fh, const void *buf, int count,
                          MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_all(abi2mpi_file(fh), buf, count,
                                abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_all_begin(MPIABI_File fh, const void *buf, int count,
                                MPIABI_Datatype datatype) {
  int ierr = MPI_File_write_all_begin(abi2mpi_file(fh), buf, count,
                                      abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_all_begin_c(MPIABI_File fh, const void *buf,
                                  MPIABI_Count count,
                                  MPIABI_Datatype datatype) {
  int ierr = MPI_File_write_all_begin_c(abi2mpi_file(fh), buf, count,
                                        abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_all_c(MPIABI_File fh, const void *buf, MPIABI_Count count,
                            MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_all_c(abi2mpi_file(fh), buf, count,
                                  abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_all_end(MPIABI_File fh, const void *buf,
                              MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_all_end(abi2mpi_file(fh), buf, mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at(MPIABI_File fh, MPIABI_Offset offset, const void *buf,
                         int count, MPIABI_Datatype datatype,
                         MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_at(abi2mpi_file(fh), offset, buf, count,
                               abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at_all(MPIABI_File fh, MPIABI_Offset offset,
                             const void *buf, int count,
                             MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_at_all(abi2mpi_file(fh), offset, buf, count,
                                   abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at_all_begin(MPIABI_File fh, MPIABI_Offset offset,
                                   const void *buf, int count,
                                   MPIABI_Datatype datatype) {
  int ierr = MPI_File_write_at_all_begin(abi2mpi_file(fh), offset, buf, count,
                                         abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at_all_begin_c(MPIABI_File fh, MPIABI_Offset offset,
                                     const void *buf, MPIABI_Count count,
                                     MPIABI_Datatype datatype) {
  int ierr = MPI_File_write_at_all_begin_c(abi2mpi_file(fh), offset, buf, count,
                                           abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at_all_c(MPIABI_File fh, MPIABI_Offset offset,
                               const void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype,
                               MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_at_all_c(abi2mpi_file(fh), offset, buf, count,
                                     abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at_all_end(MPIABI_File fh, const void *buf,
                                 MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_at_all_end(abi2mpi_file(fh), buf, mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_at_c(MPIABI_File fh, MPIABI_Offset offset,
                           const void *buf, MPIABI_Count count,
                           MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_at_all_c(abi2mpi_file(fh), offset, buf, count,
                                     abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_c(MPIABI_File fh, const void *buf, MPIABI_Count count,
                        MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write(abi2mpi_file(fh), buf, count,
                            abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_ordered(MPIABI_File fh, const void *buf, int count,
                              MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_ordered(abi2mpi_file(fh), buf, count,
                                    abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_ordered_begin(MPIABI_File fh, const void *buf, int count,
                                    MPIABI_Datatype datatype) {
  int ierr = MPI_File_write_ordered_begin(abi2mpi_file(fh), buf, count,
                                          abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_ordered_begin_c(MPIABI_File fh, const void *buf,
                                      MPIABI_Count count,
                                      MPIABI_Datatype datatype) {
  int ierr = MPI_File_write_ordered_begin_c(abi2mpi_file(fh), buf, count,
                                            abi2mpi_datatype(datatype));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_ordered_c(MPIABI_File fh, const void *buf,
                                MPIABI_Count count, MPIABI_Datatype datatype,
                                MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_ordered_c(abi2mpi_file(fh), buf, count,
                                      abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_ordered_end(MPIABI_File fh, const void *buf,
                                  MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_ordered_end(abi2mpi_file(fh), buf, mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_shared(MPIABI_File fh, const void *buf, int count,
                             MPIABI_Datatype datatype, MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_shared(abi2mpi_file(fh), buf, count,
                                   abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_File_write_shared_c(MPIABI_File fh, const void *buf,
                               MPIABI_Count count, MPIABI_Datatype datatype,
                               MPIABI_Status *status) {
  MPI_Status *mpi_status = abi2mpi_statusptr_uninitialized(status);
  int ierr = MPI_File_write_shared_c(abi2mpi_file(fh), buf, count,
                                     abi2mpi_datatype(datatype), mpi_status);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

struct mpi_Register_datarep_state {
  MPIABI_Datarep_conversion_function *abi_read_conversion_fn;
  MPIABI_Datarep_conversion_function *abi_write_conversion_fn;
  MPIABI_Datarep_extent_function *abi_dtype_file_extent_fn;
  void *abi_extra_state;
};
static int mpi_Datarep_read_conversion_function(void *userbuf,
                                                MPI_Datatype datatype,
                                                int count, void *filebuf,
                                                MPI_Offset position,
                                                void *extra_state) {
  const struct mpi_Register_datarep_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_read_conversion_fn(
      userbuf, mpi2abi_datatype(datatype), count, filebuf, position,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Datarep_write_conversion_function(void *userbuf,
                                                 MPI_Datatype datatype,
                                                 int count, void *filebuf,
                                                 MPI_Offset position,
                                                 void *extra_state) {
  const struct mpi_Register_datarep_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_write_conversion_fn(
      userbuf, mpi2abi_datatype(datatype), count, filebuf, position,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Datarep_extent_function(MPI_Datatype datatype, MPI_Aint *extent,
                                       void *extra_state) {
  const struct mpi_Register_datarep_state *mpi_extra_state = extra_state;
  MPIABI_Aint abi_extent;
  int ierr = mpi_extra_state->abi_dtype_file_extent_fn(
      mpi2abi_datatype(datatype), &abi_extent,
      mpi_extra_state->abi_extra_state);
  *extent = abi_extent;
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Register_datarep(
    const char *datarep, MPIABI_Datarep_conversion_function *read_conversion_fn,
    MPIABI_Datarep_conversion_function *write_conversion_fn,
    MPIABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  struct mpi_Register_datarep_state *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_read_conversion_fn = read_conversion_fn;
  mpi_extra_state->abi_write_conversion_fn = write_conversion_fn;
  mpi_extra_state->abi_dtype_file_extent_fn = dtype_file_extent_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  int ierr = MPI_Register_datarep(datarep, mpi_Datarep_read_conversion_function,
                                  mpi_Datarep_write_conversion_function,
                                  mpi_Datarep_extent_function, mpi_extra_state);
  return mpi2abi_errorcode(ierr);
}

struct mpi_Register_datarep_state_c {
  MPIABI_Datarep_conversion_function_c *abi_read_conversion_fn;
  MPIABI_Datarep_conversion_function_c *abi_write_conversion_fn;
  MPIABI_Datarep_extent_function *abi_dtype_file_extent_fn;
  void *abi_extra_state;
};
static int
mpi_Datarep_read_conversion_function_c(void *userbuf, MPI_Datatype datatype,
                                       MPI_Count count, void *filebuf,
                                       MPI_Offset position, void *extra_state) {
  const struct mpi_Register_datarep_state_c *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_read_conversion_fn(
      userbuf, mpi2abi_datatype(datatype), count, filebuf, position,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Datarep_write_conversion_function_c(
    void *userbuf, MPI_Datatype datatype, MPI_Count count, void *filebuf,
    MPI_Offset position, void *extra_state) {
  const struct mpi_Register_datarep_state_c *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_write_conversion_fn(
      userbuf, mpi2abi_datatype(datatype), count, filebuf, position,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Datarep_extent_function_c(MPI_Datatype datatype,
                                         MPI_Aint *extent, void *extra_state) {
  const struct mpi_Register_datarep_state_c *mpi_extra_state = extra_state;
  MPIABI_Aint abi_extent;
  int ierr = mpi_extra_state->abi_dtype_file_extent_fn(
      mpi2abi_datatype(datatype), &abi_extent,
      mpi_extra_state->abi_extra_state);
  *extent = abi_extent;
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Register_datarep_c(
    const char *datarep,
    MPIABI_Datarep_conversion_function_c *read_conversion_fn,
    MPIABI_Datarep_conversion_function_c *write_conversion_fn,
    MPIABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  struct mpi_Register_datarep_state_c *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_read_conversion_fn = read_conversion_fn;
  mpi_extra_state->abi_write_conversion_fn = write_conversion_fn;
  mpi_extra_state->abi_dtype_file_extent_fn = dtype_file_extent_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  int ierr =
      MPI_Register_datarep_c(datarep, mpi_Datarep_read_conversion_function_c,
                             mpi_Datarep_write_conversion_function_c,
                             mpi_Datarep_extent_function_c, mpi_extra_state);
  return mpi2abi_errorcode(ierr);
}

// A.3.13 Language Bindings C Bindings

MPIABI_Fint MPIABI_Comm_c2f(MPIABI_Comm comm);
MPIABI_Comm MPIABI_Comm_f2c(MPIABI_Fint comm);
MPIABI_Fint MPIABI_Errhandler_c2f(MPIABI_Errhandler errhandler);
MPIABI_Errhandler MPIABI_Errhandler_f2c(MPIABI_Fint errhandler);
MPIABI_Fint MPIABI_File_c2f(MPIABI_File file);
MPIABI_File MPIABI_File_f2c(MPIABI_Fint file);
MPIABI_Fint MPIABI_Group_c2f(MPIABI_Group group);
MPIABI_Group MPIABI_Group_f2c(MPIABI_Fint group);
MPIABI_Fint MPIABI_Info_c2f(MPIABI_Info info);
MPIABI_Info MPIABI_Info_f2c(MPIABI_Fint info);
MPIABI_Fint MPIABI_Message_c2f(MPIABI_Message message);
MPIABI_Message MPIABI_Message_f2c(MPIABI_Fint message);
MPIABI_Fint MPIABI_Op_c2f(MPIABI_Op op);
MPIABI_Op MPIABI_Op_f2c(MPIABI_Fint op);
MPIABI_Fint MPIABI_Request_c2f(MPIABI_Request request);
MPIABI_Request MPIABI_Request_f2c(MPIABI_Fint request);
MPIABI_Fint MPIABI_Session_c2f(MPIABI_Session session);
MPIABI_Session MPIABI_Session_f2c(MPIABI_Fint session);
int MPIABI_Status_f082f(const MPIABI_F08_status *f08_status,
                        MPIABI_Fint *f_status);
int MPIABI_Status_c2f(const MPIABI_Status *c_status, MPIABI_Fint *f_status);
int MPIABI_Status_c2f08(const MPIABI_Status *c_status,
                        MPIABI_F08_status *f08_status);
int MPIABI_Status_f082c(const MPIABI_F08_status *f08_status,
                        MPIABI_Status *c_status);
int MPIABI_Status_f2c(const MPIABI_Fint *f_status, MPIABI_Status *c_status);
int MPIABI_Status_f2f08(const MPIABI_Fint *f_status,
                        MPIABI_F08_status *f08_status);
MPIABI_Fint MPIABI_Type_c2f(MPIABI_Datatype datatype);
int MPIABI_Type_create_f90_complex(int p, int r, MPIABI_Datatype *newtype);
int MPIABI_Type_create_f90_integer(int r, MPIABI_Datatype *newtype);
int MPIABI_Type_create_f90_real(int p, int r, MPIABI_Datatype *newtype);
MPIABI_Datatype MPIABI_Type_f2c(MPIABI_Fint datatype);
int MPIABI_Type_match_size(int typeclass, int size, MPIABI_Datatype *datatype);
MPIABI_Fint MPIABI_Win_c2f(MPIABI_Win win);
MPIABI_Win MPIABI_Win_f2c(MPIABI_Fint win);

// A.3.14 Tools / Profiling Interface C Bindings

int MPIABI_Pcontrol(const int level, ...) {
  // Variadic arguments cannot be forwarded
  return MPIABI_SUCCESS;
}

// A.3.15 Tools / MPI Tool Information Interface
// C Bindings

int MPIABI_T_category_changed(int *update_number);
int MPIABI_T_category_get_categories(int cat_index, int len, int indices[]);
int MPIABI_T_category_get_cvars(int cat_index, int len, int indices[]);
int MPIABI_T_category_get_events(int cat_index, int len, int indices[]);
int MPIABI_T_category_get_index(const char *name, int *cat_index);
int MPIABI_T_category_get_info(int cat_index, char *name, int *name_len,
                               char *desc, int *desc_len, int *num_cvars,
                               int *num_pvars, int *num_categories);
int MPIABI_T_category_get_num(int *num_cat);
int MPIABI_T_category_get_num_events(int cat_index, int *num_events);
int MPIABI_T_category_get_pvars(int cat_index, int len, int indices[]);
int MPIABI_T_cvar_get_index(const char *name, int *cvar_index);
int MPIABI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                           int *verbosity, MPIABI_Datatype *datatype,
                           MPIABI_T_enum *enumtype, char *desc, int *desc_len,
                           int *bind, int *scope);
int MPIABI_T_cvar_get_num(int *num_cvar);
int MPIABI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                               MPIABI_T_cvar_handle *handle, int *count);
int MPIABI_T_cvar_handle_free(MPIABI_T_cvar_handle *handle);
int MPIABI_T_cvar_read(MPIABI_T_cvar_handle handle, void *buf);
int MPIABI_T_cvar_write(MPIABI_T_cvar_handle handle, const void *buf);
int MPIABI_T_enum_get_info(MPIABI_T_enum enumtype, int *num, char *name,
                           int *name_len);
int MPIABI_T_enum_get_item(MPIABI_T_enum enumtype, int index, int *value,
                           char *name, int *name_len);
int MPIABI_T_event_callback_get_info(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_cb_safety cb_safety, MPIABI_Info *info_used);
int MPIABI_T_event_callback_set_info(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_cb_safety cb_safety, MPIABI_Info info);
int MPIABI_T_event_copy(MPIABI_T_event_instance event_instance, void *buffer);
int MPIABI_T_event_get_index(const char *name, int *event_index);
int MPIABI_T_event_get_info(int event_index, char *name, int *name_len,
                            int *verbosity,
                            MPIABI_Datatype array_of_datatypes[],
                            MPIABI_Aint array_of_displacements[],
                            int *num_elements, MPIABI_T_enum *enumtype,
                            MPIABI_Info *info, char *desc, int *desc_len,
                            int *bind);
int MPIABI_T_event_get_num(int *num_events);
int MPIABI_T_event_get_source(MPIABI_T_event_instance event_instance,
                              int *source_index);
int MPIABI_T_event_get_timestamp(MPIABI_T_event_instance event_instance,
                                 MPIABI_Count *event_timestamp);
int MPIABI_T_event_handle_alloc(
    int event_index, void *obj_handle, MPIABI_Info info,
    MPIABI_T_event_registration *event_registration);
int MPIABI_T_event_handle_free(
    MPIABI_T_event_registration event_registration, void *user_data,
    MPIABI_T_event_free_cb_function free_cb_function);
int MPIABI_T_event_handle_get_info(
    MPIABI_T_event_registration event_registration, MPIABI_Info *info_used);
int MPIABI_T_event_handle_set_info(
    MPIABI_T_event_registration event_registration, MPIABI_Info info);
int MPIABI_T_event_read(MPIABI_T_event_instance event_instance,
                        int element_index, void *buffer);
int MPIABI_T_event_register_callback(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_cb_safety cb_safety, MPIABI_Info info, void *user_data,
    MPIABI_T_event_cb_function event_cb_function);
int MPIABI_T_event_set_dropped_handler(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_event_dropped_cb_function dropped_cb_function);
int MPIABI_T_finalize(void);
int MPIABI_T_init_thread(int required, int *provided);
int MPIABI_T_pvar_get_index(const char *name, int var_class, int *pvar_index);
int MPIABI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                           int *verbosity, int *var_class,
                           MPIABI_Datatype *datatype, MPIABI_T_enum *enumtype,
                           char *desc, int *desc_len, int *bind, int *readonly,
                           int *continuous, int *atomic);
int MPIABI_T_pvar_get_num(int *num_pvar);
int MPIABI_T_pvar_handle_alloc(MPIABI_T_pvar_session pe_session, int pvar_index,
                               void *obj_handle, MPIABI_T_pvar_handle *handle,
                               int *count);
int MPIABI_T_pvar_handle_free(MPIABI_T_pvar_session pe_session,
                              MPIABI_T_pvar_handle *handle);
int MPIABI_T_pvar_read(MPIABI_T_pvar_session pe_session,
                       MPIABI_T_pvar_handle handle, void *buf);
int MPIABI_T_pvar_readreset(MPIABI_T_pvar_session pe_session,
                            MPIABI_T_pvar_handle handle, void *buf);
int MPIABI_T_pvar_reset(MPIABI_T_pvar_session pe_session,
                        MPIABI_T_pvar_handle handle);
int MPIABI_T_pvar_session_create(MPIABI_T_pvar_session *pe_session);
int MPIABI_T_pvar_session_free(MPIABI_T_pvar_session *pe_session);
int MPIABI_T_pvar_start(MPIABI_T_pvar_session pe_session,
                        MPIABI_T_pvar_handle handle);
int MPIABI_T_pvar_stop(MPIABI_T_pvar_session pe_session,
                       MPIABI_T_pvar_handle handle);
int MPIABI_T_pvar_write(MPIABI_T_pvar_session pe_session,
                        MPIABI_T_pvar_handle handle, const void *buf);
int MPIABI_T_source_get_info(int source_index, char *name, int *name_len,
                             char *desc, int *desc_len,
                             MPIABI_T_source_order *ordering,
                             MPIABI_Count *ticks_per_second,
                             MPIABI_Count *max_ticks, MPIABI_Info *info);
int MPIABI_T_source_get_num(int *num_sources);
int MPIABI_T_source_get_timestamp(int source_index, MPIABI_Count *timestamp);

// A.3.16 Deprecated C Bindings

int MPIABI_Attr_delete(MPIABI_Comm comm, int keyval) {
  int ierr = MPI_Attr_delete(abi2mpi_comm(comm), abi2mpi_keyval(keyval));
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Attr_get(MPIABI_Comm comm, int keyval, void *attribute_val,
                    int *flag) {
  int ierr = MPI_Attr_get(abi2mpi_comm(comm), abi2mpi_keyval(keyval),
                          attribute_val, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Attr_put(MPIABI_Comm comm, int keyval, void *attribute_val) {
  int ierr =
      MPI_Attr_put(abi2mpi_comm(comm), abi2mpi_keyval(keyval), attribute_val);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Get_elements_x(const MPIABI_Status *status, MPIABI_Datatype datatype,
                          MPIABI_Count *count) {
  const MPI_Status mpi_status = abi2mpi_status(*status);
  MPI_Count mpi_count;
  int ierr =
      MPI_Get_elements_x(&mpi_status, abi2mpi_datatype(datatype), &mpi_count);
  *count = mpi_count;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_get(MPIABI_Info info, const char *key, int valuelen,
                    char *value, int *flag) {
  int ierr = MPI_Info_get(abi2mpi_info(info), key, valuelen, value, flag);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Info_get_valuelen(MPIABI_Info info, const char *key, int *valuelen,
                             int *flag) {
  int ierr = MPI_Info_get_valuelen(abi2mpi_info(info), key, valuelen, flag);
  return mpi2abi_errorcode(ierr);
}

struct abi_Keyval_create_state {
  MPIABI_Copy_function *abi_copy_fn;
  MPIABI_Delete_function *abi_delete_fn;
  void *abi_extra_state;
};
static int mpi_Keyval_create_copy_function(MPI_Comm oldcomm, int keyval,
                                           void *extra_state,
                                           void *attribute_val_in,
                                           void *attribute_val_out, int *flag) {
  const struct abi_Keyval_create_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_copy_fn(
      mpi2abi_comm(oldcomm), mpi2abi_keyval(keyval),
      mpi_extra_state->abi_extra_state, attribute_val_in, attribute_val_out,
      flag);
  return abi2mpi_errorcode(ierr);
}
static int mpi_Keyval_create_delete_function(MPI_Comm comm, int keyval,
                                             void *attribute_val,
                                             void *extra_state) {
  const struct abi_Keyval_create_state *mpi_extra_state = extra_state;
  int ierr = mpi_extra_state->abi_delete_fn(
      mpi2abi_comm(comm), mpi2abi_keyval(keyval), attribute_val,
      mpi_extra_state->abi_extra_state);
  return abi2mpi_errorcode(ierr);
}
int MPIABI_Keyval_create(MPIABI_Copy_function *copy_fn,
                         MPIABI_Delete_function *delete_fn, int *keyval,
                         void *extra_state) {
  struct abi_Keyval_create_state *mpi_extra_state =
      malloc(sizeof *mpi_extra_state);
  mpi_extra_state->abi_copy_fn = copy_fn;
  mpi_extra_state->abi_delete_fn = delete_fn;
  mpi_extra_state->abi_extra_state = extra_state;
  int ierr = MPI_Keyval_create(mpi_Keyval_create_copy_function,
                               mpi_Keyval_create_delete_function, keyval,
                               mpi_extra_state);
  *keyval = mpi2abi_keyval(*keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Keyval_free(int *keyval) {
  int mpi_keyval = abi2mpi_keyval(*keyval);
  int ierr = MPI_Keyval_free(&mpi_keyval);
  *keyval = mpi2abi_keyval(mpi_keyval);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Status_set_elements_x(MPIABI_Status *status,
                                 MPIABI_Datatype datatype, MPIABI_Count count) {
  MPI_Status *mpi_status = abi2mpi_statusptr(status);
  int ierr =
      MPI_Status_set_elements_x(mpi_status, abi2mpi_datatype(datatype), count);
  mpi2abi_statusptr(mpi_status);
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_extent_x(MPIABI_Datatype datatype, MPIABI_Count *lb,
                             MPIABI_Count *extent) {
  MPI_Count mpi_lb;
  MPI_Count mpi_extent;
  int ierr =
      MPI_Type_get_extent_x(abi2mpi_datatype(datatype), &mpi_lb, &mpi_extent);
  *lb = mpi_lb;
  *extent = mpi_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_get_true_extent_x(MPIABI_Datatype datatype,
                                  MPIABI_Count *true_lb,
                                  MPIABI_Count *true_extent) {
  MPI_Count mpi_true_lb;
  MPI_Count mpi_true_extent;
  int ierr = MPI_Type_get_true_extent_x(abi2mpi_datatype(datatype),
                                        &mpi_true_lb, &mpi_true_extent);
  *true_lb = mpi_true_lb;
  *true_extent = mpi_true_extent;
  return mpi2abi_errorcode(ierr);
}

int MPIABI_Type_size_x(MPIABI_Datatype datatype, MPIABI_Count *size) {
  MPI_Count mpi_size;
  int ierr = MPI_Type_size_x(abi2mpi_datatype(datatype), &mpi_size);
  *size = mpi_size;
  return mpi2abi_errorcode(ierr);
}

// Removed C Bindings

// deprecated, use `MPI_Get_address` instead
int MPIABI_Address(void *location, MPIABI_Aint *address) {
#if 0
  MPI_Aint mpi_address;
  int ierr = MPI_Address(location, &mpi_address);
  *address = mpi_address;
  return mpi2abi_errorcode(ierr);
#endif
  return MPIABI_Get_address(location, address);
}

// deprecated, use `MPI_Type_create_hindexed` instead
int MPIABI_Type_hindexed(int count, int *array_of_blocklengths,
                         MPIABI_Aint *array_of_displacements,
                         MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
#if 0
  MPI_Aint mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_hindexed(count, array_of_blocklengths,
                               mpi_array_of_displacements,
                               abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
#endif
  return MPIABI_Type_create_hindexed(count, array_of_blocklengths,
                                     array_of_displacements, oldtype, newtype);
}

// deprecated, use `MPI_Type_create_hvector` instead
int MPIABI_Type_hvector(int count, int blocklength, MPIABI_Aint stride,
                        MPIABI_Datatype oldtype, MPIABI_Datatype *newtype) {
#if 0
  MPI_Datatype mpi_newtype;
  int ierr = MPI_Type_hvector(count, blocklength, stride,
                              abi2mpi_datatype(oldtype), &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
#endif
  return MPIABI_Type_create_hvector(count, blocklength, stride, oldtype,
                                    newtype);
}

// deprecated, use `MPI_Type_create_struct` instead
int MPIABI_Type_struct(int count, int *array_of_blocklengths,
                       MPIABI_Aint *array_of_displacements,
                       MPIABI_Datatype *array_of_types,
                       MPIABI_Datatype *newtype) {
#if 0
  MPI_Aint mpi_array_of_displacements[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_displacements[n] = array_of_displacements[n];
  MPI_Datatype mpi_newtype;
  MPI_Datatype mpi_array_of_types[count];
  for (int n = 0; n < count; ++n)
    mpi_array_of_types[n] = abi2mpi_datatype(array_of_types[n]);
  int ierr =
      MPI_Type_struct(count, array_of_blocklengths, mpi_array_of_displacements,
                      mpi_array_of_types, &mpi_newtype);
  *newtype = mpi2abi_datatype(mpi_newtype);
  return mpi2abi_errorcode(ierr);
#endif
  return MPIABI_Type_create_struct(count, array_of_blocklengths,
                                   array_of_displacements, array_of_types,
                                   newtype);
}

// deprecated, use `MPI_Type_get_extent` instead
int MPIABI_Type_extent(MPIABI_Datatype datatype, MPIABI_Aint *extent) {
#if 0
  MPI_Aint mpi_extent;
  int ierr = MPI_Type_extent(abi2mpi_datatype(datatype), &mpi_extent);
  *extent = mpi_extent;
  return mpi2abi_errorcode(ierr);
#endif
  MPIABI_Aint lb;
  return MPIABI_Type_get_extent(datatype, &lb, extent);
}

// deprecated, use `MPI_Type_get_extent` instead
int MPIABI_Type_lb(MPIABI_Datatype datatype, MPIABI_Aint *displacement) {
#if 0
  MPI_Aint mpi_displacement;
  int ierr = MPI_Type_lb(abi2mpi_datatype(datatype), &mpi_displacement);
  *displacement = mpi_displacement;
  return mpi2abi_errorcode(ierr);
#endif
  MPIABI_Aint extent;
  return MPIABI_Type_get_extent(datatype, displacement, &extent);
}

// deprecated, use `MPI_Type_get_extent` instead
int MPIABI_Type_ub(MPIABI_Datatype datatype, MPIABI_Aint *displacement) {
#if 0
  MPI_Aint mpi_displacement;
  int ierr = MPI_Type_ub(abi2mpi_datatype(datatype), &mpi_displacement);
  *displacement = mpi_displacement;
  return mpi2abi_errorcode(ierr);
#endif
  MPIABI_Aint lb, extent;
  int ierr = MPIABI_Type_get_extent(datatype, &lb, &extent);
  *displacement = lb + extent;
  return ierr;
}

// MPIX

int MPIXABI_Query_cuda_support() {
#ifdef HAVE_MPIX_QUERY_CUDA_SUPPORT
  return MPIX_Query_cuda_support();
#else
  return 0;
#endif
}

int MPIXABI_Query_hip_support() {
#ifdef HAVE_MPIX_QUERY_HIP_SUPPORT
  return MPIX_Query_hip_support();
#else
  return 0;
#endif
}

int MPIXABI_Query_rocm_support() {
#ifdef HAVE_MPIX_QUERY_ROCM_SUPPORT
  return MPIX_Query_rocm_support();
#else
  return 0;
#endif
}

int MPIXABI_Query_ze_support() {
#ifdef HAVE_MPIX_QUERY_ZE_SUPPORT
  return MPIX_Query_ze_support();
#else
  return 0;
#endif
}
