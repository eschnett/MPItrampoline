#ifndef MPI_CONSTANTS_H
#define MPI_CONSTANTS_H

#include "mpi_types.h"

#include <mpiabi_constants.h>

// Define MPI constants

// A.1.1 Defined Constants

// Error classes

enum {
  MPI_SUCCESS = MPIABI_SUCCESS,
  MPI_ERR_BUFFER = MPIABI_ERR_BUFFER,
  MPI_ERR_COUNT = MPIABI_ERR_COUNT,
  MPI_ERR_TYPE = MPIABI_ERR_TYPE,
  MPI_ERR_TAG = MPIABI_ERR_TAG,
  MPI_ERR_COMM = MPIABI_ERR_COMM,
  MPI_ERR_RANK = MPIABI_ERR_RANK,
  MPI_ERR_REQUEST = MPIABI_ERR_REQUEST,
  MPI_ERR_ROOT = MPIABI_ERR_ROOT,
  MPI_ERR_GROUP = MPIABI_ERR_GROUP,
  MPI_ERR_OP = MPIABI_ERR_OP,
  MPI_ERR_TOPOLOGY = MPIABI_ERR_TOPOLOGY,
  MPI_ERR_DIMS = MPIABI_ERR_DIMS,
  MPI_ERR_ARG = MPIABI_ERR_ARG,
  MPI_ERR_UNKNOWN = MPIABI_ERR_UNKNOWN,
  MPI_ERR_TRUNCATE = MPIABI_ERR_TRUNCATE,
  MPI_ERR_OTHER = MPIABI_ERR_OTHER,
  MPI_ERR_INTERN = MPIABI_ERR_INTERN,
  MPI_ERR_PENDING = MPIABI_ERR_PENDING,
  MPI_ERR_IN_STATUS = MPIABI_ERR_IN_STATUS,
  MPI_ERR_ACCESS = MPIABI_ERR_ACCESS,
  MPI_ERR_AMODE = MPIABI_ERR_AMODE,
  MPI_ERR_ASSERT = MPIABI_ERR_ASSERT,
  MPI_ERR_BAD_FILE = MPIABI_ERR_BAD_FILE,
  MPI_ERR_BASE = MPIABI_ERR_BASE,
  MPI_ERR_CONVERSION = MPIABI_ERR_CONVERSION,
  MPI_ERR_DISP = MPIABI_ERR_DISP,
  MPI_ERR_DUP_DATAREP = MPIABI_ERR_DUP_DATAREP,
  MPI_ERR_FILE_EXISTS = MPIABI_ERR_FILE_EXISTS,
  MPI_ERR_FILE_IN_USE = MPIABI_ERR_FILE_IN_USE,
  MPI_ERR_FILE = MPIABI_ERR_FILE,
  MPI_ERR_INFO_KEY = MPIABI_ERR_INFO_KEY,
  MPI_ERR_INFO_NOKEY = MPIABI_ERR_INFO_NOKEY,
  MPI_ERR_INFO_VALUE = MPIABI_ERR_INFO_VALUE,
  MPI_ERR_INFO = MPIABI_ERR_INFO,
  MPI_ERR_IO = MPIABI_ERR_IO,
  MPI_ERR_KEYVAL = MPIABI_ERR_KEYVAL,
  MPI_ERR_LOCKTYPE = MPIABI_ERR_LOCKTYPE,
  MPI_ERR_NAME = MPIABI_ERR_NAME,
  MPI_ERR_NO_MEM = MPIABI_ERR_NO_MEM,
  MPI_ERR_NOT_SAME = MPIABI_ERR_NOT_SAME,
  MPI_ERR_NO_SPACE = MPIABI_ERR_NO_SPACE,
  MPI_ERR_NO_SUCH_FILE = MPIABI_ERR_NO_SUCH_FILE,
  MPI_ERR_PORT = MPIABI_ERR_PORT,
  MPI_ERR_PROC_ABORTED = MPIABI_ERR_PROC_ABORTED,
  MPI_ERR_QUOTA = MPIABI_ERR_QUOTA,
  MPI_ERR_READ_ONLY = MPIABI_ERR_READ_ONLY,
  MPI_ERR_RMA_ATTACH = MPIABI_ERR_RMA_ATTACH,
  MPI_ERR_RMA_CONFLICT = MPIABI_ERR_RMA_CONFLICT,
  MPI_ERR_RMA_RANGE = MPIABI_ERR_RMA_RANGE,
  MPI_ERR_RMA_SHARED = MPIABI_ERR_RMA_SHARED,
  MPI_ERR_RMA_SYNC = MPIABI_ERR_RMA_SYNC,
  MPI_ERR_RMA_FLAVOR = MPIABI_ERR_RMA_FLAVOR,
  MPI_ERR_SERVICE = MPIABI_ERR_SERVICE,
  MPI_ERR_SESSION = MPIABI_ERR_SESSION,
  MPI_ERR_SIZE = MPIABI_ERR_SIZE,
  MPI_ERR_SPAWN = MPIABI_ERR_SPAWN,
  MPI_ERR_UNSUPPORTED_DATAREP = MPIABI_ERR_UNSUPPORTED_DATAREP,
  MPI_ERR_UNSUPPORTED_OPERATION = MPIABI_ERR_UNSUPPORTED_OPERATION,
  MPI_ERR_VALUE_TOO_LARGE = MPIABI_ERR_VALUE_TOO_LARGE,
  MPI_ERR_WIN = MPIABI_ERR_WIN,
  MPI_ERR_ERRHANDLER = MPIABI_ERR_ERRHANDLER,
  MPI_T_ERR_CANNOT_INIT = MPIABI_T_ERR_CANNOT_INIT,
  MPI_T_ERR_NOT_ACCESSIBLE = MPIABI_T_ERR_NOT_ACCESSIBLE,
  MPI_T_ERR_NOT_INITIALIZED = MPIABI_T_ERR_NOT_INITIALIZED,
  MPI_T_ERR_NOT_SUPPORTED = MPIABI_T_ERR_NOT_SUPPORTED,
  MPI_T_ERR_MEMORY = MPIABI_T_ERR_MEMORY,
  MPI_T_ERR_INVALID = MPIABI_T_ERR_INVALID,
  MPI_T_ERR_INVALID_INDEX = MPIABI_T_ERR_INVALID_INDEX,
  MPI_T_ERR_INVALID_ITEM = MPIABI_T_ERR_INVALID_ITEM,
  MPI_T_ERR_INVALID_SESSION = MPIABI_T_ERR_INVALID_SESSION,
  MPI_T_ERR_INVALID_HANDLE = MPIABI_T_ERR_INVALID_HANDLE,
  MPI_T_ERR_INVALID_NAME = MPIABI_T_ERR_INVALID_NAME,
  MPI_T_ERR_OUT_OF_HANDLES = MPIABI_T_ERR_OUT_OF_HANDLES,
  MPI_T_ERR_OUT_OF_SESSIONS = MPIABI_T_ERR_OUT_OF_SESSIONS,
  MPI_T_ERR_CVAR_SET_NOT_NOW = MPIABI_T_ERR_CVAR_SET_NOT_NOW,
  MPI_T_ERR_CVAR_SET_NEVER = MPIABI_T_ERR_CVAR_SET_NEVER,
  MPI_T_ERR_PVAR_NO_WRITE = MPIABI_T_ERR_PVAR_NO_WRITE,
  MPI_T_ERR_PVAR_NO_STARTSTOP = MPIABI_T_ERR_PVAR_NO_STARTSTOP,
  MPI_T_ERR_PVAR_NO_ATOMIC = MPIABI_T_ERR_PVAR_NO_ATOMIC,
  MPI_ERR_LASTCODE = MPIABI_ERR_LASTCODE,
};

// Buffer Address Constants

#define MPI_BOTTOM MPIABI_BOTTOM
#define MPI_BUFFER_AUTOMATIC MPIABI_BUFFER_AUTOMATIC
#define MPI_IN_PLACE MPIABI_IN_PLACE

// Assorted Constants

enum {
  MPI_PROC_NULL = MPIABI_PROC_NULL,
  MPI_ANY_SOURCE = MPIABI_ANY_SOURCE,
  MPI_ANY_TAG = MPIABI_ANY_TAG,
  MPI_UNDEFINED = MPIABI_UNDEFINED,
  MPI_BSEND_OVERHEAD = MPIABI_BSEND_OVERHEAD,
  MPI_KEYVAL_INVALID = MPIABI_KEYVAL_INVALID,
  MPI_LOCK_EXCLUSIVE = MPIABI_LOCK_EXCLUSIVE,
  MPI_LOCK_SHARED = MPIABI_LOCK_SHARED,
  MPI_ROOT = MPIABI_ROOT,
};

// No Process Message Handle

#define MPI_MESSAGE_NO_PROC MPIABI_MESSAGE_NO_PROC

// Fortran Support Method Specific Constants

// Status array size and reserved index values

// Fortran status array size and reserved index values

enum {
  MPI_F_STATUS_SIZE = MPIABI_F_STATUS_SIZE,
  MPI_F_SOURCE = MPIABI_F_SOURCE,
  MPI_F_TAG = MPIABI_F_TAG,
  MPI_F_ERROR = MPIABI_F_ERROR,
};

// Variable Address Size

// Error-handling specifiers

#define MPI_ERRORS_ARE_FATAL MPIABI_ERRORS_ARE_FATAL
#define MPI_ERRORS_ABORT MPIABI_ERRORS_ABORT
#define MPI_ERRORS_RETURN MPIABI_ERRORS_RETURN

// Maximum Sizes for Strings

enum {
  MPI_MAX_DATAREP_STRING = MPIABI_MAX_DATAREP_STRING,
  MPI_MAX_ERROR_STRING = MPIABI_MAX_ERROR_STRING,
  MPI_MAX_INFO_KEY = MPIABI_MAX_INFO_KEY,
  MPI_MAX_INFO_VAL = MPIABI_MAX_INFO_VAL,
  MPI_MAX_LIBRARY_VERSION_STRING = MPIABI_MAX_LIBRARY_VERSION_STRING,
  MPI_MAX_OBJECT_NAME = MPIABI_MAX_OBJECT_NAME,
  MPI_MAX_PORT_NAME = MPIABI_MAX_PORT_NAME,
  MPI_MAX_PROCESSOR_NAME = MPIABI_MAX_PROCESSOR_NAME,
  MPI_MAX_PSET_NAME_LEN = MPIABI_MAX_PSET_NAME_LEN,
  MPI_MAX_STRINGTAG_LEN = MPIABI_MAX_STRINGTAG_LEN,
};

// Named Predefined Datatypes

// [C types]

#define MPI_CHAR MPIABI_CHAR
#define MPI_SHORT MPIABI_SHORT
#define MPI_INT MPIABI_INT
#define MPI_LONG MPIABI_LONG
#define MPI_LONG_LONG_INT MPIABI_LONG_LONG_INT
#define MPI_LONG_LONG MPIABI_LONG_LONG
#define MPI_SIGNED_CHAR MPIABI_SIGNED_CHAR
#define MPI_UNSIGNED_CHAR MPIABI_UNSIGNED_CHAR
#define MPI_UNSIGNED_SHORT MPIABI_UNSIGNED_SHORT
#define MPI_UNSIGNED MPIABI_UNSIGNED
#define MPI_UNSIGNED_LONG MPIABI_UNSIGNED_LONG
#define MPI_UNSIGNED_LONG_LONG MPIABI_UNSIGNED_LONG_LONG
#define MPI_FLOAT MPIABI_FLOAT
#define MPI_DOUBLE MPIABI_DOUBLE
#define MPI_LONG_DOUBLE MPIABI_LONG_DOUBLE
#define MPI_WCHAR MPIABI_WCHAR
#define MPI_C_BOOL MPIABI_C_BOOL
#define MPI_INT8_T MPIABI_INT8_T
#define MPI_INT16_T MPIABI_INT16_T
#define MPI_INT32_T MPIABI_INT32_T
#define MPI_INT64_T MPIABI_INT64_T
#define MPI_UINT8_T MPIABI_UINT8_T
#define MPI_UINT16_T MPIABI_UINT16_T
#define MPI_UINT32_T MPIABI_UINT32_T
#define MPI_UINT64_T MPIABI_UINT64_T
#define MPI_AINT MPIABI_AINT
#define MPI_COUNT MPIABI_COUNT
#define MPI_OFFSET MPIABI_OFFSET
#define MPI_C_COMPLEX MPIABI_C_COMPLEX
#define MPI_C_FLOAT_COMPLEX MPIABI_C_FLOAT_COMPLEX
#define MPI_C_DOUBLE_COMPLEX MPIABI_C_DOUBLE_COMPLEX
#define MPI_C_LONG_DOUBLE_COMPLEX MPIABI_C_LONG_DOUBLE_COMPLEX
#define MPI_BYTE MPIABI_BYTE
#define MPI_PACKED MPIABI_PACKED

// [Fortran types]

#define MPI_INTEGER MPIABI_INTEGER
#define MPI_REAL MPIABI_REAL
#define MPI_DOUBLE_PRECISION MPIABI_DOUBLE_PRECISION
#define MPI_COMPLEX MPIABI_COMPLEX
#define MPI_LOGICAL MPIABI_LOGICAL
#define MPI_CHARACTER MPIABI_CHARACTER

// [C++ types]

#define MPI_CXX_BOOL MPIABI_CXX_BOOL
#define MPI_CXX_FLOAT_COMPLEX MPIABI_CXX_FLOAT_COMPLEX
#define MPI_CXX_DOUBLE_COMPLEX MPIABI_CXX_DOUBLE_COMPLEX
#define MPI_CXX_LONG_DOUBLE_COMPLEX MPIABI_CXX_LONG_DOUBLE_COMPLEX

// [Optional datatypes (Fortran)]

#define MPI_DOUBLE_COMPLEX MPIABI_DOUBLE_COMPLEX
#define MPI_INTEGER1 MPIABI_INTEGER1
#define MPI_INTEGER2 MPIABI_INTEGER2
#define MPI_INTEGER4 MPIABI_INTEGER4
#define MPI_INTEGER8 MPIABI_INTEGER8
#define MPI_INTEGER16 MPIABI_INTEGER16
#define MPI_REAL2 MPIABI_REAL2
#define MPI_REAL4 MPIABI_REAL4
#define MPI_REAL8 MPIABI_REAL8
#define MPI_REAL16 MPIABI_REAL16
#define MPI_COMPLEX4 MPIABI_COMPLEX4
#define MPI_COMPLEX8 MPIABI_COMPLEX8
#define MPI_COMPLEX16 MPIABI_COMPLEX16
#define MPI_COMPLEX32 MPIABI_COMPLEX32

// [Extensions]

#define MPI_REAL1 MPIABI_REAL1
#define MPI_COMPLEX2 MPIABI_COMPLEX2
#define MPI_LOGICAL1 MPIABI_LOGICAL1
#define MPI_LOGICAL2 MPIABI_LOGICAL2
#define MPI_LOGICAL4 MPIABI_LOGICAL4
#define MPI_LOGICAL8 MPIABI_LOGICAL8
#define MPI_LOGICAL16 MPIABI_LOGICAL16

// [Datatypes for reduction functions (C)]

#define MPI_FLOAT_INT MPIABI_FLOAT_INT
#define MPI_DOUBLE_INT MPIABI_DOUBLE_INT
#define MPI_LONG_INT MPIABI_LONG_INT
#define MPI_2INT MPIABI_2INT
#define MPI_SHORT_INT MPIABI_SHORT_INT
#define MPI_LONG_DOUBLE_INT MPIABI_LONG_DOUBLE_INT

// [Datatypes for reduction functions (Fortran)]

#define MPI_2REAL MPIABI_2REAL
#define MPI_2DOUBLE_PRECISION MPIABI_2DOUBLE_PRECISION
#define MPI_2INTEGER MPIABI_2INTEGER

// [Removed constructs]

#define MPI_LB MPIABI_LB
#define MPI_UB MPIABI_UB

// Reserved communicators

#define MPI_COMM_WORLD MPIABI_COMM_WORLD
#define MPI_COMM_SELF MPIABI_COMM_SELF

// Communicator split type constants
enum {
  MPI_COMM_TYPE_SHARED = MPIABI_COMM_TYPE_SHARED,
  MPI_COMM_TYPE_HW_UNGUIDED = MPIABI_COMM_TYPE_HW_UNGUIDED,
  MPI_COMM_TYPE_HW_GUIDED = MPIABI_COMM_TYPE_HW_GUIDED,
  MPI_COMM_TYPE_RESOURCE_GUIDED = MPIABI_COMM_TYPE_RESOURCE_GUIDED,
};

// Results of communicator and group comparisons

enum {
  MPI_IDENT = MPIABI_IDENT,
  MPI_CONGRUENT = MPIABI_CONGRUENT,
  MPI_SIMILAR = MPIABI_SIMILAR,
  MPI_UNEQUAL = MPIABI_UNEQUAL,
};

// Environmental inquiry info key

#define MPI_INFO_ENV MPIABI_INFO_ENV

// Environmental inquiry keys

enum {
  MPI_TAG_UB = MPIABI_TAG_UB,
  MPI_IO = MPIABI_IO,
  MPI_HOST = MPIABI_HOST,
  MPI_WTIME_IS_GLOBAL = MPIABI_WTIME_IS_GLOBAL,
};

// Collective Operations

#define MPI_MAX MPIABI_MAX
#define MPI_MIN MPIABI_MIN
#define MPI_SUM MPIABI_SUM
#define MPI_PROD MPIABI_PROD
#define MPI_MAXLOC MPIABI_MAXLOC
#define MPI_MINLOC MPIABI_MINLOC
#define MPI_BAND MPIABI_BAND
#define MPI_BOR MPIABI_BOR
#define MPI_BXOR MPIABI_BXOR
#define MPI_LAND MPIABI_LAND
#define MPI_LOR MPIABI_LOR
#define MPI_LXOR MPIABI_LXOR
#define MPI_REPLACE MPIABI_REPLACE
#define MPI_NO_OP MPIABI_NO_OP

// Null Handles

#define MPI_GROUP_NULL MPIABI_GROUP_NULL
#define MPI_COMM_NULL MPIABI_COMM_NULL
#define MPI_DATATYPE_NULL MPIABI_DATATYPE_NULL
#define MPI_REQUEST_NULL MPIABI_REQUEST_NULL
#define MPI_OP_NULL MPIABI_OP_NULL
#define MPI_ERRHANDLER_NULL MPIABI_ERRHANDLER_NULL
#define MPI_FILE_NULL MPIABI_FILE_NULL
#define MPI_INFO_NULL MPIABI_INFO_NULL
#define MPI_SESSION_NULL MPIABI_SESSION_NULL
#define MPI_WIN_NULL MPIABI_WIN_NULL
#define MPI_MESSAGE_NULL MPIABI_MESSAGE_NULL

// Empty group

#define MPI_GROUP_EMPTY MPIABI_GROUP_EMPTY

// Topologies

enum {
  MPI_GRAPH = MPIABI_GRAPH,
  MPI_CART = MPIABI_CART,
  MPI_DIST_GRAPH = MPIABI_DIST_GRAPH,
};

// Predefined functions

#define MPI_COMM_NULL_COPY_FN MPIABI_COMM_NULL_COPY_FN
#define MPI_COMM_DUP_FN MPIABI_COMM_DUP_FN
#define MPI_COMM_NULL_DELETE_FN MPIABI_COMM_NULL_DELETE_FN

#define MPI_WIN_NULL_COPY_FN MPIABI_WIN_NULL_COPY_FN
#define MPI_WIN_DUP_FN MPIABI_WIN_DUP_FN
#define MPI_WIN_NULL_DELETE_FN MPIABI_WIN_NULL_DELETE_FN

#define MPI_TYPE_NULL_COPY_FN MPIABI_TYPE_NULL_COPY_FN
#define MPI_TYPE_DUP_FN MPIABI_TYPE_DUP_FN
#define MPI_TYPE_NULL_DELETE_FN MPIABI_TYPE_NULL_DELETE_FN

#define MPI_CONVERSION_FN_NULL MPIABI_CONVERSION_FN_NULL
#define MPI_CONVERSION_FN_NULL_C MPIABI_CONVERSION_FN_NULL_C

// Deprecated predefined functions

#define MPI_NULL_COPY_FN MPIABI_NULL_COPY_FN
#define MPI_DUP_FN MPIABI_DUP_FN
#define MPI_NULL_DELETE_FN MPIABI_NULL_DELETE_FN

// Predefined Attribute Keys

enum {
  MPI_APPNUM = MPIABI_APPNUM,
  MPI_LASTUSEDCODE = MPIABI_LASTUSEDCODE,
  MPI_UNIVERSE_SIZE = MPIABI_UNIVERSE_SIZE,
  MPI_WIN_BASE = MPIABI_WIN_BASE,
  MPI_WIN_DISP_UNIT = MPIABI_WIN_DISP_UNIT,
  MPI_WIN_SIZE = MPIABI_WIN_SIZE,
  MPI_WIN_CREATE_FLAVOR = MPIABI_WIN_CREATE_FLAVOR,
  MPI_WIN_MODEL = MPIABI_WIN_MODEL,
};

// MPI Window Create Flavors

enum {
  MPI_WIN_FLAVOR_CREATE = MPIABI_WIN_FLAVOR_CREATE,
  MPI_WIN_FLAVOR_ALLOCATE = MPIABI_WIN_FLAVOR_ALLOCATE,
  MPI_WIN_FLAVOR_DYNAMIC = MPIABI_WIN_FLAVOR_DYNAMIC,
  MPI_WIN_FLAVOR_SHARED = MPIABI_WIN_FLAVOR_SHARED,
};

// MPI Window Models

enum {
  MPI_WIN_SEPARATE = MPIABI_WIN_SEPARATE,
  MPI_WIN_UNIFIED = MPIABI_WIN_UNIFIED,
};

// Mode Constants

enum {
  MPI_MODE_APPEND = MPIABI_MODE_APPEND,
  MPI_MODE_CREATE = MPIABI_MODE_CREATE,
  MPI_MODE_DELETE_ON_CLOSE = MPIABI_MODE_DELETE_ON_CLOSE,
  MPI_MODE_EXCL = MPIABI_MODE_EXCL,
  MPI_MODE_NOCHECK = MPIABI_MODE_NOCHECK,
  MPI_MODE_NOPRECEDE = MPIABI_MODE_NOPRECEDE,
  MPI_MODE_NOPUT = MPIABI_MODE_NOPUT,
  MPI_MODE_NOSTORE = MPIABI_MODE_NOSTORE,
  MPI_MODE_NOSUCCEED = MPIABI_MODE_NOSUCCEED,
  MPI_MODE_RDONLY = MPIABI_MODE_RDONLY,
  MPI_MODE_RDWR = MPIABI_MODE_RDWR,
  MPI_MODE_SEQUENTIAL = MPIABI_MODE_SEQUENTIAL,
  MPI_MODE_UNIQUE_OPEN = MPIABI_MODE_UNIQUE_OPEN,
  MPI_MODE_WRONLY = MPIABI_MODE_WRONLY,
};

// Datatype Decoding Constants

enum {
  MPI_COMBINER_CONTIGUOUS = MPIABI_COMBINER_CONTIGUOUS,
  MPI_COMBINER_DARRAY = MPIABI_COMBINER_DARRAY,
  MPI_COMBINER_DUP = MPIABI_COMBINER_DUP,
  MPI_COMBINER_F90_COMPLEX = MPIABI_COMBINER_F90_COMPLEX,
  MPI_COMBINER_F90_INTEGER = MPIABI_COMBINER_F90_INTEGER,
  MPI_COMBINER_F90_REAL = MPIABI_COMBINER_F90_REAL,
  MPI_COMBINER_HINDEXED = MPIABI_COMBINER_HINDEXED,
  MPI_COMBINER_HVECTOR = MPIABI_COMBINER_HVECTOR,
  MPI_COMBINER_INDEXED_BLOCK = MPIABI_COMBINER_INDEXED_BLOCK,
  MPI_COMBINER_HINDEXED_BLOCK = MPIABI_COMBINER_HINDEXED_BLOCK,
  MPI_COMBINER_INDEXED = MPIABI_COMBINER_INDEXED,
  MPI_COMBINER_NAMED = MPIABI_COMBINER_NAMED,
  MPI_COMBINER_RESIZED = MPIABI_COMBINER_RESIZED,
  MPI_COMBINER_STRUCT = MPIABI_COMBINER_STRUCT,
  MPI_COMBINER_SUBARRAY = MPIABI_COMBINER_SUBARRAY,
  MPI_COMBINER_VECTOR = MPIABI_COMBINER_VECTOR,
};

// Threads Constants

enum {
  MPI_THREAD_FUNNELED = MPIABI_THREAD_FUNNELED,
  MPI_THREAD_MULTIPLE = MPIABI_THREAD_MULTIPLE,
  MPI_THREAD_SERIALIZED = MPIABI_THREAD_SERIALIZED,
  MPI_THREAD_SINGLE = MPIABI_THREAD_SINGLE,
};

// File Operation Constants, Part 1

#define MPI_DISPLACEMENT_CURRENT MPIABI_DISPLACEMENT_CURRENT

// File Operation Constants, Part 2

enum {
  MPI_DISTRIBUTE_BLOCK = MPIABI_DISTRIBUTE_BLOCK,
  MPI_DISTRIBUTE_CYCLIC = MPIABI_DISTRIBUTE_CYCLIC,
  MPI_DISTRIBUTE_DFLT_DARG = MPIABI_DISTRIBUTE_DFLT_DARG,
  MPI_DISTRIBUTE_NONE = MPIABI_DISTRIBUTE_NONE,
  MPI_ORDER_C = MPIABI_ORDER_C,
  MPI_ORDER_FORTRAN = MPIABI_ORDER_FORTRAN,
  MPI_SEEK_CUR = MPIABI_SEEK_CUR,
  MPI_SEEK_END = MPIABI_SEEK_END,
  MPI_SEEK_SET = MPIABI_SEEK_SET,
};

// F90 Datatype Matching Constants

enum {
  MPI_TYPECLASS_COMPLEX = MPIABI_TYPECLASS_COMPLEX,
  MPI_TYPECLASS_INTEGER = MPIABI_TYPECLASS_INTEGER,
  MPI_TYPECLASS_REAL = MPIABI_TYPECLASS_REAL,
};

// Constants Specifying Empty or Ignored Input

#define MPI_ARGVS_NULL MPIABI_ARGVS_NULL
#define MPI_ARGV_NULL MPIABI_ARGV_NULL
#define MPI_ERRCODES_IGNORE MPIABI_ERRCODES_IGNORE
#define MPI_STATUSES_IGNORE MPIABI_STATUSES_IGNORE
#define MPI_STATUS_IGNORE MPIABI_STATUS_IGNORE
#define MPI_UNWEIGHTED MPIABI_UNWEIGHTED
#define MPI_WEIGHTS_EMPTY MPIABI_WEIGHTS_EMPTY

// C Constants Specifying Ignored Input (no Fortran)

#define MPI_F_STATUSES_IGNORE MPIABI_F_STATUSES_IGNORE
#define MPI_F_STATUS_IGNORE MPIABI_F_STATUS_IGNORE

#define MPI_F08_STATUSES_IGNORE MPIABI_F08_STATUSES_IGNORE
#define MPI_F08_STATUS_IGNORE MPIABI_F08_STATUS_IGNORE

// C preprocessor Constants and Fortran Parameters
enum {
  MPI_SUBVERSION = MPIABI_SUBVERSION,
  MPI_VERSION = MPIABI_VERSION,
};

// Null handles used in the MPI tool information interface

#define MPI_T_ENUM_NULL MPIABI_T_ENUM_NULL
#define MPI_T_CVAR_HANDLE_NULL MPIABI_T_CVAR_HANDLE_NULL
#define MPI_T_PVAR_HANDLE_NULL MPIABI_T_PVAR_HANDLE_NULL
#define MPI_T_PVAR_SESSION_NULL MPIABI_T_PVAR_SESSION_NULL

// Verbosity Levels in the MPI tool information interface

enum {
  MPI_T_VERBOSITY_USER_BASIC = MPIABI_T_VERBOSITY_USER_BASIC,
  MPI_T_VERBOSITY_USER_DETAIL = MPIABI_T_VERBOSITY_USER_DETAIL,
  MPI_T_VERBOSITY_USER_ALL = MPIABI_T_VERBOSITY_USER_ALL,
  MPI_T_VERBOSITY_TUNER_BASIC = MPIABI_T_VERBOSITY_TUNER_BASIC,
  MPI_T_VERBOSITY_TUNER_DETAIL = MPIABI_T_VERBOSITY_TUNER_DETAIL,
  MPI_T_VERBOSITY_TUNER_ALL = MPIABI_T_VERBOSITY_TUNER_ALL,
  MPI_T_VERBOSITY_MPIDEV_BASIC = MPIABI_T_VERBOSITY_MPIDEV_BASIC,
  MPI_T_VERBOSITY_MPIDEV_DETAIL = MPIABI_T_VERBOSITY_MPIDEV_DETAIL,
  MPI_T_VERBOSITY_MPIDEV_ALL = MPIABI_T_VERBOSITY_MPIDEV_ALL,
};

// Constants to identify associations of variables in the MPI tool information
// interface

enum {
  MPI_T_BIND_NO_OBJECT = MPIABI_T_BIND_NO_OBJECT,
  MPI_T_BIND_MPI_COMM = MPIABI_T_BIND_MPI_COMM,
  MPI_T_BIND_MPI_DATATYPE = MPIABI_T_BIND_MPI_DATATYPE,
  MPI_T_BIND_MPI_ERRHANDLER = MPIABI_T_BIND_MPI_ERRHANDLER,
  MPI_T_BIND_MPI_FILE = MPIABI_T_BIND_MPI_FILE,
  MPI_T_BIND_MPI_GROUP = MPIABI_T_BIND_MPI_GROUP,
  MPI_T_BIND_MPI_OP = MPIABI_T_BIND_MPI_OP,
  MPI_T_BIND_MPI_REQUEST = MPIABI_T_BIND_MPI_REQUEST,
  MPI_T_BIND_MPI_WIN = MPIABI_T_BIND_MPI_WIN,
  MPI_T_BIND_MPI_MESSAGE = MPIABI_T_BIND_MPI_MESSAGE,
  MPI_T_BIND_MPI_INFO = MPIABI_T_BIND_MPI_INFO,
  MPI_T_BIND_MPI_SESSION = MPIABI_T_BIND_MPI_SESSION,
};

// Constants describing the scope of a control variable in the MPI tool
// information interface

enum {
  MPI_T_SCOPE_CONSTANT = MPIABI_T_SCOPE_CONSTANT,
  MPI_T_SCOPE_READONLY = MPIABI_T_SCOPE_READONLY,
  MPI_T_SCOPE_LOCAL = MPIABI_T_SCOPE_LOCAL,
  MPI_T_SCOPE_GROUP = MPIABI_T_SCOPE_GROUP,
  MPI_T_SCOPE_GROUP_EQ = MPIABI_T_SCOPE_GROUP_EQ,
  MPI_T_SCOPE_ALL = MPIABI_T_SCOPE_ALL,
  MPI_T_SCOPE_ALL_EQ = MPIABI_T_SCOPE_ALL_EQ,
};

// Additional constants used

#define MPI_T_PVAR_ALL_HANDLES

// Performance variables classes used by the MPI tool information interface

enum {
  MPI_T_PVAR_CLASS_STATE = MPIABI_T_PVAR_CLASS_STATE,
  MPI_T_PVAR_CLASS_LEVEL = MPIABI_T_PVAR_CLASS_LEVEL,
  MPI_T_PVAR_CLASS_SIZE = MPIABI_T_PVAR_CLASS_SIZE,
  MPI_T_PVAR_CLASS_PERCENTAGE = MPIABI_T_PVAR_CLASS_PERCENTAGE,
  MPI_T_PVAR_CLASS_HIGHWATERMARK = MPIABI_T_PVAR_CLASS_HIGHWATERMARK,
  MPI_T_PVAR_CLASS_LOWWATERMARK = MPIABI_T_PVAR_CLASS_LOWWATERMARK,
  MPI_T_PVAR_CLASS_COUNTER = MPIABI_T_PVAR_CLASS_COUNTER,
  MPI_T_PVAR_CLASS_AGGREGATE = MPIABI_T_PVAR_CLASS_AGGREGATE,
  MPI_T_PVAR_CLASS_TIMER = MPIABI_T_PVAR_CLASS_TIMER,
  MPI_T_PVAR_CLASS_GENERIC = MPIABI_T_PVAR_CLASS_GENERIC,
};

// Source event ordering guarantees in the MPI tool information interface

#define MPI_T_SOURCE_ORDERED MPIABI_T_SOURCE_ORDERED
#define MPI_T_SOURCE_UNORDERED MPIABI_T_SOURCE_UNORDERED

// Callback safety requirement levels used in the MPI tool information interface

#define MPI_T_CB_REQUIRE_NONE MPIABI_T_CB_REQUIRE_NONE
#define MPI_T_CB_REQUIRE_MPI_RESTRICTED MPIABI_T_CB_REQUIRE_MPI_RESTRICTED
#define MPI_T_CB_REQUIRE_THREAD_SAFE MPIABI_T_CB_REQUIRE_THREAD_SAFE
#define MPI_T_CB_REQUIRE_ASYNC_SIGNAL_SAFE MPIABI_T_CB_REQUIRE_ASYNC_SIGNAL_SAFE

#endif // #ifndef MPI_CONSTANTS_H
