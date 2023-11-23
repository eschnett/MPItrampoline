#ifndef MPIABI_CONSTANTS_H
#define MPIABI_CONSTANTS_H

#include "mpiabi_types.h"

// Define MPIABI constants

// A.1.1 Defined Constants

// Error classes

enum {
  MPIABI_SUCCESS = 0,                    // arXiv:2308.11214
  MPIABI_ERR_BUFFER = 1,                 // arXiv:2308.11214
  MPIABI_ERR_COUNT = 2,                  // arXiv:2308.11214
  MPIABI_ERR_TYPE = 3,                   // arXiv:2308.11214
  MPIABI_ERR_TAG = 4,                    // arXiv:2308.11214
  MPIABI_ERR_COMM = 5,                   // arXiv:2308.11214
  MPIABI_ERR_RANK = 6,                   // arXiv:2308.11214
  MPIABI_ERR_REQUEST = 7,                // arXiv:2308.11214
  MPIABI_ERR_ROOT = 8,                   // arXiv:2308.11214
  MPIABI_ERR_GROUP = 9,                  // arXiv:2308.11214
  MPIABI_ERR_OP = 10,                    // arXiv:2308.11214
  MPIABI_ERR_TOPOLOGY = 11,              // arXiv:2308.11214
  MPIABI_ERR_DIMS = 12,                  // arXiv:2308.11214
  MPIABI_ERR_ARG = 13,                   // arXiv:2308.11214
  MPIABI_ERR_UNKNOWN = 14,               // arXiv:2308.11214
  MPIABI_ERR_TRUNCATE = 15,              // arXiv:2308.11214
  MPIABI_ERR_OTHER = 16,                 // arXiv:2308.11214
  MPIABI_ERR_INTERN = 17,                // arXiv:2308.11214
  MPIABI_ERR_PENDING = 18,               // arXiv:2308.11214
  MPIABI_ERR_IN_STATUS = 19,             // arXiv:2308.11214
  MPIABI_ERR_ACCESS = 20,                // arXiv:2308.11214
  MPIABI_ERR_AMODE = 21,                 // arXiv:2308.11214
  MPIABI_ERR_ASSERT = 22,                // arXiv:2308.11214
  MPIABI_ERR_BAD_FILE = 23,              // arXiv:2308.11214
  MPIABI_ERR_BASE = 24,                  // arXiv:2308.11214
  MPIABI_ERR_CONVERSION = 25,            // arXiv:2308.11214
  MPIABI_ERR_DISP = 26,                  // arXiv:2308.11214
  MPIABI_ERR_DUP_DATAREP = 27,           // arXiv:2308.11214
  MPIABI_ERR_FILE_EXISTS = 28,           // arXiv:2308.11214
  MPIABI_ERR_FILE_IN_USE = 29,           // arXiv:2308.11214
  MPIABI_ERR_FILE = 30,                  // arXiv:2308.11214
  MPIABI_ERR_INFO_KEY = 31,              // arXiv:2308.11214
  MPIABI_ERR_INFO_NOKEY = 32,            // arXiv:2308.11214
  MPIABI_ERR_INFO_VALUE = 33,            // arXiv:2308.11214
  MPIABI_ERR_INFO = 34,                  // arXiv:2308.11214
  MPIABI_ERR_IO = 35,                    // arXiv:2308.11214
  MPIABI_ERR_KEYVAL = 36,                // arXiv:2308.11214
  MPIABI_ERR_LOCKTYPE = 37,              // arXiv:2308.11214
  MPIABI_ERR_NAME = 38,                  // arXiv:2308.11214
  MPIABI_ERR_NO_MEM = 39,                // arXiv:2308.11214
  MPIABI_ERR_NOT_SAME = 40,              // arXiv:2308.11214
  MPIABI_ERR_NO_SPACE = 41,              // arXiv:2308.11214
  MPIABI_ERR_NO_SUCH_FILE = 42,          // arXiv:2308.11214
  MPIABI_ERR_PORT = 43,                  // arXiv:2308.11214
  MPIABI_ERR_PROC_ABORTED = 44,          // arXiv:2308.11214
  MPIABI_ERR_QUOTA = 45,                 // arXiv:2308.11214
  MPIABI_ERR_READ_ONLY = 46,             // arXiv:2308.11214
  MPIABI_ERR_RMA_ATTACH = 47,            // arXiv:2308.11214
  MPIABI_ERR_RMA_CONFLICT = 48,          // arXiv:2308.11214
  MPIABI_ERR_RMA_RANGE = 49,             // arXiv:2308.11214
  MPIABI_ERR_RMA_SHARED = 50,            // arXiv:2308.11214
  MPIABI_ERR_RMA_SYNC = 51,              // arXiv:2308.11214
  MPIABI_ERR_RMA_FLAVOR = 52,            // arXiv:2308.11214
  MPIABI_ERR_SERVICE = 53,               // arXiv:2308.11214
  MPIABI_ERR_SESSION = 54,               // arXiv:2308.11214
  MPIABI_ERR_SIZE = 55,                  // arXiv:2308.11214
  MPIABI_ERR_SPAWN = 56,                 // arXiv:2308.11214
  MPIABI_ERR_UNSUPPORTED_DATAREP = 57,   // arXiv:2308.11214
  MPIABI_ERR_UNSUPPORTED_OPERATION = 58, // arXiv:2308.11214
  MPIABI_ERR_VALUE_TOO_LARGE = 59,       // arXiv:2308.11214
  MPIABI_ERR_WIN = 60,                   // arXiv:2308.11214
  MPIABI_ERR_ERRHANDLER = 61,            // arXiv:2308.11214
  MPIABI_T_ERR_CANNOT_INIT = 1000,       // arXiv:2308.11214
  MPIABI_T_ERR_NOT_ACCESSIBLE = 1001,    // arXiv:2308.11214
  MPIABI_T_ERR_NOT_INITIALIZED = 1002,   // arXiv:2308.11214
  MPIABI_T_ERR_NOT_SUPPORTED = 1003,     // arXiv:2308.11214
  MPIABI_T_ERR_MEMORY = 1004,            // arXiv:2308.11214
  MPIABI_T_ERR_INVALID = 1005,           // arXiv:2308.11214
  MPIABI_T_ERR_INVALID_INDEX = 1006,     // arXiv:2308.11214
  MPIABI_T_ERR_INVALID_ITEM = 1007,      // arXiv:2308.11214
  MPIABI_T_ERR_INVALID_SESSION = 1008,   // arXiv:2308.11214
  MPIABI_T_ERR_INVALID_HANDLE = 1009,    // arXiv:2308.11214
  MPIABI_T_ERR_INVALID_NAME = 1010,      // arXiv:2308.11214
  MPIABI_T_ERR_OUT_OF_HANDLES = 1011,    // arXiv:2308.11214
  MPIABI_T_ERR_OUT_OF_SESSIONS = 1012,   // arXiv:2308.11214
  MPIABI_T_ERR_CVAR_SET_NOT_NOW = 1013,  // arXiv:2308.11214
  MPIABI_T_ERR_CVAR_SET_NEVER = 1014,    // arXiv:2308.11214
  MPIABI_T_ERR_PVAR_NO_WRITE = 1015,     // arXiv:2308.11214
  MPIABI_T_ERR_PVAR_NO_STARTSTOP = 1016, // arXiv:2308.11214
  MPIABI_T_ERR_PVAR_NO_ATOMIC = 1017,    // arXiv:2308.11214
  MPIABI_ERR_LASTCODE = 0x3fff,          // arXiv:2308.11214
};

// Buffer Address Constants

#define MPIABI_BOTTOM ((void *)0)           // arXiv:2308.11214
#define MPIABI_BUFFER_AUTOMATIC ((void *)2) // [nonstandard]
#define MPIABI_IN_PLACE ((void *)1)         // arXiv:2308.11214

// Assorted Constants

enum {
  MPIABI_PROC_NULL = -2,        // arXiv:2308.11214
  MPIABI_ANY_SOURCE = -1,       // arXiv:2308.11214
  MPIABI_ANY_TAG = -101,        // arXiv:2308.11214
  MPIABI_UNDEFINED = -601,      // arXiv:2308.11214
  MPIABI_BSEND_OVERHEAD = 512,  // arXiv:2308.11214
  MPIABI_KEYVAL_INVALID = -401, // arXiv:2308.11214
  MPIABI_LOCK_EXCLUSIVE = -901, // arXiv:2308.11214
  MPIABI_LOCK_SHARED = -902,    // arXiv:2308.11214
  MPIABI_ROOT = -3,             // arXiv:2308.11214
};

// No Process Message Handle

#define MPIABI_MESSAGE_NO_PROC                                                 \
  ((MPIABI_Message)0b000100010101) // arXiv:2308.11214

// Fortran Support Method Specific Constants

// Status array size and reserved index values

// Fortran status array size and reserved index values

enum {
  MPIABI_F_STATUS_SIZE = 8, // arXiv:2308.11214
  MPIABI_F_SOURCE = 0,      // arXiv:2308.11214
  MPIABI_F_TAG = 1,         // arXiv:2308.11214
  MPIABI_F_ERROR = 2,       // arXiv:2308.11214
};

// Variable Address Size

// Error-handling specifiers

#define MPIABI_ERRORS_ARE_FATAL                                                \
  ((MPIABI_Errhandler)0b000100011001) // arXiv:2308.11214
#define MPIABI_ERRORS_ABORT                                                    \
  ((MPIABI_Errhandler)0b000100011011) // arXiv:2308.11214
#define MPIABI_ERRORS_RETURN                                                   \
  ((MPIABI_Errhandler)0b000100011010) // arXiv:2308.11214

// Maximum Sizes for Strings

enum {
  MPIABI_MAX_DATAREP_STRING = 128,
  MPIABI_MAX_ERROR_STRING = 512,
  MPIABI_MAX_INFO_KEY = 255,
  MPIABI_MAX_INFO_VAL = 1024,
  MPIABI_MAX_LIBRARY_VERSION_STRING = 8192,
  MPIABI_MAX_OBJECT_NAME = 128,
  MPIABI_MAX_PORT_NAME = 1024,
  MPIABI_MAX_PROCESSOR_NAME = 256,
  MPIABI_MAX_PSET_NAME_LEN = 256,
  MPIABI_MAX_STRINGTAG_LEN = 256,
};

// Named Predefined Datatypes

// [C types]

#define MPIABI_CHAR ((MPIABI_Datatype)0b001001000011)  // arXiv:2308.11214
#define MPIABI_SHORT ((MPIABI_Datatype)0b001000001000) // arXiv:2308.11214
#define MPIABI_INT ((MPIABI_Datatype)0b001000001001)   // arXiv:2308.11214
#define MPIABI_LONG ((MPIABI_Datatype)0b001000001010)  // arXiv:2308.11214
#define MPIABI_LONG_LONG_INT                                                   \
  ((MPIABI_Datatype)0b001000001011)                          // arXiv:2308.11214
#define MPIABI_LONG_LONG MPIABI_LONG_LONG_INT                // arXiv:2308.11214
#define MPIABI_SIGNED_CHAR ((MPIABI_Datatype)0b001001000100) // arXiv:2308.11214
#define MPIABI_UNSIGNED_CHAR                                                   \
  ((MPIABI_Datatype)0b001001000101) // arXiv:2308.11214
#define MPIABI_UNSIGNED_SHORT                                                  \
  ((MPIABI_Datatype)0b001000001100)                       // arXiv:2308.11214
#define MPIABI_UNSIGNED ((MPIABI_Datatype)0b001000001101) // arXiv:2308.11214
#define MPIABI_UNSIGNED_LONG                                                   \
  ((MPIABI_Datatype)0b001000001110) // arXiv:2308.11214
#define MPIABI_UNSIGNED_LONG_LONG                                              \
  ((MPIABI_Datatype)0b001000001111)                          // arXiv:2308.11214
#define MPIABI_FLOAT ((MPIABI_Datatype)0b001001010010)       // arXiv:2308.11214
#define MPIABI_DOUBLE ((MPIABI_Datatype)0b001001011010)      // arXiv:2308.11214
#define MPIABI_LONG_DOUBLE ((MPIABI_Datatype)0b001000100000) // arXiv:2308.11214
#define MPIABI_WCHAR ((MPIABI_Datatype)0b001000111100)       // arXiv:2308.11214
#define MPIABI_C_BOOL ((MPIABI_Datatype)0b001000111000)      // arXiv:2308.11214
#define MPIABI_INT8_T ((MPIABI_Datatype)0b001001000000)      // arXiv:2308.11214
#define MPIABI_INT16_T ((MPIABI_Datatype)0b001001001000)     // arXiv:2308.11214
#define MPIABI_INT32_T ((MPIABI_Datatype)0b001001010000)     // arXiv:2308.11214
#define MPIABI_INT64_T ((MPIABI_Datatype)0b001001011000)     // arXiv:2308.11214
#define MPIABI_UINT8_T ((MPIABI_Datatype)0b001001000001)     // arXiv:2308.11214
#define MPIABI_UINT16_T ((MPIABI_Datatype)0b001001001001)    // arXiv:2308.11214
#define MPIABI_UINT32_T ((MPIABI_Datatype)0b001001010001)    // arXiv:2308.11214
#define MPIABI_UINT64_T ((MPIABI_Datatype)0b001001011001)    // arXiv:2308.11214
#define MPIABI_AINT ((MPIABI_Datatype)0b001000000001)        // arXiv:2308.11214
#define MPIABI_COUNT ((MPIABI_Datatype)0b001000000010)       // arXiv:2308.11214
#define MPIABI_OFFSET ((MPIABI_Datatype)0b001000000011)      // arXiv:2308.11214
#define MPIABI_C_COMPLEX ((MPIABI_Datatype)0b001001011011)   // arXiv:2308.11214
#define MPIABI_C_FLOAT_COMPLEX MPIABI_C_COMPLEX              // arXiv:2308.11214
#define MPIABI_C_DOUBLE_COMPLEX                                                \
  ((MPIABI_Datatype)0b001000010110) // arXiv:2308.11214
#define MPIABI_C_LONG_DOUBLE_COMPLEX                                           \
  ((MPIABI_Datatype)0b001000100100)                     // arXiv:2308.11214
#define MPIABI_BYTE ((MPIABI_Datatype)0b001001000111)   // arXiv:2308.11214
#define MPIABI_PACKED ((MPIABI_Datatype)0b001000000111) // arXiv:2308.11214

// [Fortran types]

#define MPIABI_INTEGER ((MPIABI_Datatype)0b001000011000) // arXiv:2308.11214
#define MPIABI_REAL ((MPIABI_Datatype)0b001000011010)    // arXiv:2308.11214
#define MPIABI_DOUBLE_PRECISION                                                \
  ((MPIABI_Datatype)0b001000011100)                        // arXiv:2308.11214
#define MPIABI_COMPLEX ((MPIABI_Datatype)0b001000011011)   // arXiv:2308.11214
#define MPIABI_LOGICAL ((MPIABI_Datatype)0b001000011001)   // arXiv:2308.11214
#define MPIABI_CHARACTER ((MPIABI_Datatype)0b001011000011) // arXiv:2308.11214

// [C++ types]

#define MPIABI_CXX_BOOL ((MPIABI_Datatype)0b001000111001) // arXiv:2308.11214
#define MPIABI_CXX_FLOAT_COMPLEX                                               \
  ((MPIABI_Datatype)0b001000010011) // arXiv:2308.11214
#define MPIABI_CXX_DOUBLE_COMPLEX                                              \
  ((MPIABI_Datatype)0b001000010111) // arXiv:2308.11214
#define MPIABI_CXX_LONG_DOUBLE_COMPLEX                                         \
  ((MPIABI_Datatype)0b001000100101) // arXiv:2308.11214

// [Optional datatypes (Fortran)]

#define MPIABI_DOUBLE_COMPLEX                                                  \
  ((MPIABI_Datatype)0b001000011101)                        // arXiv:2308.11214
#define MPIABI_INTEGER1 ((MPIABI_Datatype)0b001011000000)  // arXiv:2308.11214
#define MPIABI_INTEGER2 ((MPIABI_Datatype)0b001011001000)  // arXiv:2308.11214
#define MPIABI_INTEGER4 ((MPIABI_Datatype)0b001011010000)  // arXiv:2308.11214
#define MPIABI_INTEGER8 ((MPIABI_Datatype)0b001011011000)  // arXiv:2308.11214
#define MPIABI_INTEGER16 ((MPIABI_Datatype)0b001011100000) // arXiv:2308.11214
#define MPIABI_REAL2 ((MPIABI_Datatype)0b001011001010)     // arXiv:2308.11214
#define MPIABI_REAL4 ((MPIABI_Datatype)0b001011010010)     // arXiv:2308.11214
#define MPIABI_REAL8 ((MPIABI_Datatype)0b001011011010)     // arXiv:2308.11214
#define MPIABI_REAL16 ((MPIABI_Datatype)0b001000100010)    // arXiv:2308.11214
#define MPIABI_COMPLEX4 ((MPIABI_Datatype)0b001011010011)  // arXiv:2308.11214
#define MPIABI_COMPLEX8 ((MPIABI_Datatype)0b001011011011)  // arXiv:2308.11214
#define MPIABI_COMPLEX16 ((MPIABI_Datatype)0b001011100011) // arXiv:2308.11214
#define MPIABI_COMPLEX32 ((MPIABI_Datatype)0b001011101011) // arXiv:2308.11214

// [Extensions]

#define MPIABI_REAL1 ((MPIABI_Datatype)0b001011000010)     // arXiv:2308.11214
#define MPIABI_COMPLEX2 ((MPIABI_Datatype)0b001011001011)  // arXiv:2308.11214
#define MPIABI_LOGICAL1 ((MPIABI_Datatype)0b001011000001)  // arXiv:2308.11214
#define MPIABI_LOGICAL2 ((MPIABI_Datatype)0b001011001001)  // arXiv:2308.11214
#define MPIABI_LOGICAL4 ((MPIABI_Datatype)0b001011010001)  // arXiv:2308.11214
#define MPIABI_LOGICAL8 ((MPIABI_Datatype)0b001011011001)  // arXiv:2308.11214
#define MPIABI_LOGICAL16 ((MPIABI_Datatype)0b001011100001) // arXiv:2308.11214

// [Datatypes for reduction functions (C)]

#define MPIABI_FLOAT_INT ((MPIABI_Datatype)0b001000101000)  // arXiv:2308.11214
#define MPIABI_DOUBLE_INT ((MPIABI_Datatype)0b001000101001) // arXiv:2308.11214
#define MPIABI_LONG_INT ((MPIABI_Datatype)0b001000101010)   // arXiv:2308.11214
#define MPIABI_2INT ((MPIABI_Datatype)0b001000101011)       // arXiv:2308.11214
#define MPIABI_SHORT_INT ((MPIABI_Datatype)0b001000101100)  // arXiv:2308.11214
#define MPIABI_LONG_DOUBLE_INT                                                 \
  ((MPIABI_Datatype)0b001000101101) // arXiv:2308.11214

// [Datatypes for reduction functions (Fortran)]

#define MPIABI_2REAL ((MPIABI_Datatype)0b001000110000) // arXiv:2308.11214
#define MPIABI_2DOUBLE_PRECISION                                               \
  ((MPIABI_Datatype)0b001000110001)                       // arXiv:2308.11214
#define MPIABI_2INTEGER ((MPIABI_Datatype)0b001000110010) // arXiv:2308.11214

// [Removed constructs]

#define MPIABI_LB ((MPIABI_Datatype)0b001000000100) // [nonstandard]
#define MPIABI_UB ((MPIABI_Datatype)0b001000000101) // [nonstandard]

// Reserved communicators

#define MPIABI_COMM_WORLD ((MPIABI_Comm)0b000100000001) // arXiv:2308.11214
#define MPIABI_COMM_SELF ((MPIABI_Comm)0b000100000010)  // arXiv:2308.11214

// Communicator split type constants
enum {
  MPIABI_COMM_TYPE_SHARED = -1001,          // arXiv:2308.11214
  MPIABI_COMM_TYPE_HW_UNGUIDED = -1002,     // arXiv:2308.11214
  MPIABI_COMM_TYPE_HW_GUIDED = -1003,       // arXiv:2308.11214
  MPIABI_COMM_TYPE_RESOURCE_GUIDED = -1004, // [nonstandard]
};

// Results of communicator and group comparisons

enum {
  MPIABI_IDENT = -701,     // arXiv:2308.11214
  MPIABI_CONGRUENT = -702, // arXiv:2308.11214
  MPIABI_SIMILAR = -703,   // arXiv:2308.11214
  MPIABI_UNEQUAL = -704,   // arXiv:2308.11214
};

// Environmental inquiry info key

#define MPIABI_INFO_ENV ((MPIABI_Info)0b000100110001) // [nonstandard]

// Environmental inquiry keys

enum {
  MPIABI_TAG_UB = -201,          // arXiv:2308.11214
  MPIABI_IO = -202,              // arXiv:2308.11214
  MPIABI_HOST = -203,            // arXiv:2308.11214 [deprecated]
  MPIABI_WTIME_IS_GLOBAL = -204, // arXiv:2308.11214
};

// Collective Operations

#define MPIABI_MAX ((MPIABI_Op)0b000000100011)     // arXiv:2308.11214
#define MPIABI_MIN ((MPIABI_Op)0b000000100010)     // arXiv:2308.11214
#define MPIABI_SUM ((MPIABI_Op)0b000000100001)     // arXiv:2308.11214
#define MPIABI_PROD ((MPIABI_Op)0b000000100100)    // arXiv:2308.11214
#define MPIABI_MAXLOC ((MPIABI_Op)0b000000111001)  // arXiv:2308.11214
#define MPIABI_MINLOC ((MPIABI_Op)0b000000111000)  // arXiv:2308.11214
#define MPIABI_BAND ((MPIABI_Op)0b000000101000)    // arXiv:2308.11214
#define MPIABI_BOR ((MPIABI_Op)0b000000101001)     // arXiv:2308.11214
#define MPIABI_BXOR ((MPIABI_Op)0b000000101010)    // arXiv:2308.11214
#define MPIABI_LAND ((MPIABI_Op)0b000000110000)    // arXiv:2308.11214
#define MPIABI_LOR ((MPIABI_Op)0b000000110001)     // arXiv:2308.11214
#define MPIABI_LXOR ((MPIABI_Op)0b000000110010)    // arXiv:2308.11214
#define MPIABI_REPLACE ((MPIABI_Op)0b000000111100) // arXiv:2308.11214
#define MPIABI_NO_OP ((MPIABI_Op)0b000000111101)   // arXiv:2308.11214

// Null Handles

#define MPIABI_GROUP_NULL ((MPIABI_Group)0b000100000100) // arXiv:2308.11214
#define MPIABI_COMM_NULL ((MPIABI_Comm)0b000100000000)   // arXiv:2308.11214
#define MPIABI_DATATYPE_NULL                                                   \
  ((MPIABI_Datatype)0b001000000000)                          // arXiv:2308.11214
#define MPIABI_REQUEST_NULL ((MPIABI_Request)0b000100100000) // arXiv:2308.11214
#define MPIABI_OP_NULL ((MPIABI_Op)0b000000100000)           // arXiv:2308.11214
#define MPIABI_ERRHANDLER_NULL                                                 \
  ((MPIABI_Errhandler)0b000100011000)                        // arXiv:2308.11214
#define MPIABI_FILE_NULL ((MPIABI_File)0b000100001100)       // arXiv:2308.11214
#define MPIABI_INFO_NULL ((MPIABI_Info)0b000100110000)       // arXiv:2308.11214
#define MPIABI_SESSION_NULL ((MPIABI_Session)0b000100010000) // arXiv:2308.11214
#define MPIABI_WIN_NULL ((MPIABI_Win)0b000100001000)         // arXiv:2308.11214
#define MPIABI_MESSAGE_NULL ((MPIABI_Message)0b000100010100) // arXiv:2308.11214

// Empty group

#define MPIABI_GROUP_EMPTY ((MPIABI_Group)0b000100000101) // arXiv:2308.11214

// Topologies

enum {
  MPIABI_GRAPH = -1801,      // arXiv:2308.11214
  MPIABI_CART = -1803,       // arXiv:2308.11214
  MPIABI_DIST_GRAPH = -1802, // arXiv:2308.11214
};

// Predefined functions

#define MPIABI_COMM_NULL_COPY_FN                                               \
  ((MPIABI_Comm_copy_attr_function)0) // arXiv:2308.11214
#define MPIABI_COMM_DUP_FN                                                     \
  ((MPIABI_Comm_copy_attr_function)1) // arXiv:2308.11214
#define MPIABI_COMM_NULL_DELETE_FN                                             \
  ((MPIABI_Comm_delete_attr_function)0) // arXiv:2308.11214

#define MPIABI_WIN_NULL_COPY_FN                                                \
  ((MPIABI_Win_copy_attr_function)0)                         // arXiv:2308.11214
#define MPIABI_WIN_DUP_FN ((MPIABI_Win_copy_attr_function)1) // arXiv:2308.11214
#define MPIABI_WIN_NULL_DELETE_FN                                              \
  ((MPIABI_Win_delete_attr_function)0) // arXiv:2308.11214

#define MPIABI_TYPE_NULL_COPY_FN                                               \
  ((MPIABI_Type_copy_attr_function)0) // arXiv:2308.11214
#define MPIABI_TYPE_DUP_FN                                                     \
  ((MPIABI_Type_copy_attr_function)1) // arXiv:2308.11214
#define MPIABI_TYPE_NULL_DELETE_FN                                             \
  ((MPIABI_Type_delete_attr_function)0) // arXiv:2308.11214

#define MPIABI_CONVERSION_FN_NULL                                              \
  ((MPIABI_Datarep_conversion_function)0) // arXiv:2308.11214
#define MPIABI_CONVERSION_FN_NULL_C                                            \
  ((MPIABI_Datarep_conversion_function_c)0) // arXiv:2308.11214

// Deprecated predefined functions

#define MPIABI_NULL_COPY_FN ((MPIABI_Copy_function)0)
#define MPIABI_DUP_FN ((MPIABI_Copy_function)1)
#define MPIABI_NULL_DELETE_FN ((MPIABI_Delete_function)0)

// Predefined Attribute Keys

enum {
  MPIABI_APPNUM = -205,            // arXiv:2308.11214
  MPIABI_LASTUSEDCODE = -206,      // arXiv:2308.11214
  MPIABI_UNIVERSE_SIZE = -207,     // arXiv:2308.11214
  MPIABI_WIN_BASE = -301,          // arXiv:2308.11214
  MPIABI_WIN_DISP_UNIT = -302,     // arXiv:2308.11214
  MPIABI_WIN_SIZE = -303,          // arXiv:2308.11214
  MPIABI_WIN_CREATE_FLAVOR = -304, // arXiv:2308.11214
  MPIABI_WIN_MODEL = -305,         // arXiv:2308.11214
};

// MPI Window Create Flavors

enum {
  MPIABI_WIN_FLAVOR_CREATE = -1102,   // arXiv:2308.11214
  MPIABI_WIN_FLAVOR_ALLOCATE = -1101, // arXiv:2308.11214
  MPIABI_WIN_FLAVOR_DYNAMIC = -1103,  // arXiv:2308.11214
  MPIABI_WIN_FLAVOR_SHARED = -1104,   // arXiv:2308.11214
};

// MPI Window Models

enum {
  MPIABI_WIN_SEPARATE = -1201, // arXiv:2308.11214
  MPIABI_WIN_UNIFIED = -1202,  // arXiv:2308.11214
};

// Mode Constants

enum {
  MPIABI_MODE_APPEND = 1,          // arXiv:2308.11214
  MPIABI_MODE_CREATE = 2,          // arXiv:2308.11214
  MPIABI_MODE_DELETE_ON_CLOSE = 4, // arXiv:2308.11214
  MPIABI_MODE_EXCL = 8,            // arXiv:2308.11214
  MPIABI_MODE_NOCHECK = 1024,      // arXiv:2308.11214
  MPIABI_MODE_NOPRECEDE = 2048,    // arXiv:2308.11214
  MPIABI_MODE_NOPUT = 4096,        // arXiv:2308.11214
  MPIABI_MODE_NOSTORE = 8192,      // arXiv:2308.11214
  MPIABI_MODE_NOSUCCEED = 16384,   // arXiv:2308.11214
  MPIABI_MODE_RDONLY = 16,         // arXiv:2308.11214
  MPIABI_MODE_RDWR = 32,           // arXiv:2308.11214
  MPIABI_MODE_SEQUENTIAL = 64,     // arXiv:2308.11214
  MPIABI_MODE_UNIQUE_OPEN = 128,   // arXiv:2308.11214
  MPIABI_MODE_WRONLY = 256,        // arXiv:2308.11214
};

// Datatype Decoding Constants

enum {
  MPIABI_COMBINER_CONTIGUOUS = -1303,     // arXiv:2308.11214
  MPIABI_COMBINER_DARRAY = -1312,         // arXiv:2308.11214
  MPIABI_COMBINER_DUP = -1302,            // arXiv:2308.11214
  MPIABI_COMBINER_F90_COMPLEX = -1314,    // arXiv:2308.11214
  MPIABI_COMBINER_F90_INTEGER = -1315,    // arXiv:2308.11214
  MPIABI_COMBINER_F90_REAL = -1313,       // arXiv:2308.11214
  MPIABI_COMBINER_HINDEXED = -1307,       // arXiv:2308.11214
  MPIABI_COMBINER_HVECTOR = -1305,        // arXiv:2308.11214
  MPIABI_COMBINER_INDEXED_BLOCK = -1308,  // arXiv:2308.11214
  MPIABI_COMBINER_HINDEXED_BLOCK = -1309, // arXiv:2308.11214
  MPIABI_COMBINER_INDEXED = -1306,        // arXiv:2308.11214
  MPIABI_COMBINER_NAMED = -1301,          // arXiv:2308.11214
  MPIABI_COMBINER_RESIZED = -1316,        // arXiv:2308.11214
  MPIABI_COMBINER_STRUCT = -1310,         // arXiv:2308.11214
  MPIABI_COMBINER_SUBARRAY = -1311,       // arXiv:2308.11214
  MPIABI_COMBINER_VECTOR = -1304,         // arXiv:2308.11214
};

// Threads Constants

enum {
  MPIABI_THREAD_FUNNELED = -803,   // arXiv:2308.11214
  MPIABI_THREAD_MULTIPLE = -801,   // arXiv:2308.11214
  MPIABI_THREAD_SERIALIZED = -802, // arXiv:2308.11214
  MPIABI_THREAD_SINGLE = -804,     // arXiv:2308.11214
};

// File Operation Constants, Part 1

#define MPIABI_DISPLACEMENT_CURRENT ((MPIABI_Offset)-501) // arXiv:2308.11214

// File Operation Constants, Part 2

enum {
  MPIABI_DISTRIBUTE_BLOCK = -1401,     // arXiv:2308.11214
  MPIABI_DISTRIBUTE_CYCLIC = -1402,    // arXiv:2308.11214
  MPIABI_DISTRIBUTE_DFLT_DARG = -1403, // arXiv:2308.11214
  MPIABI_DISTRIBUTE_NONE = -1404,      // arXiv:2308.11214
  MPIABI_ORDER_C = -1501,              // arXiv:2308.11214
  MPIABI_ORDER_FORTRAN = -1502,        // arXiv:2308.11214
  MPIABI_SEEK_CUR = -1601,             // arXiv:2308.11214
  MPIABI_SEEK_END = -1602,             // arXiv:2308.11214
  MPIABI_SEEK_SET = -1603,             // arXiv:2308.11214
};

// F90 Datatype Matching Constants

enum {
  MPIABI_TYPECLASS_COMPLEX = -1702, // arXiv:2308.11214
  MPIABI_TYPECLASS_INTEGER = -1703, // arXiv:2308.11214
  MPIABI_TYPECLASS_REAL = -1701,    // arXiv:2308.11214
};

// Constants Specifying Empty or Ignored Input

#define MPIABI_ARGVS_NULL ((char ***)0)             // arXiv:2308.11214
#define MPIABI_ARGV_NULL ((char **)0)               // arXiv:2308.11214
#define MPIABI_ERRCODES_IGNORE ((int *)0)           // arXiv:2308.11214
#define MPIABI_STATUSES_IGNORE ((MPIABI_Status *)0) // arXiv:2308.11214
#define MPIABI_STATUS_IGNORE ((MPIABI_Status *)0)   // arXiv:2308.11214
#define MPIABI_UNWEIGHTED ((int *)2)                // arXiv:2308.11214
#define MPIABI_WEIGHTS_EMPTY ((int *)3)             // arXiv:2308.11214

// C Constants Specifying Ignored Input (no Fortran)

#define MPIABI_F_STATUSES_IGNORE ((MPIABI_Fint *))
#define MPIABI_F_STATUS_IGNORE ((MPIABI_Fint *))

#define MPIABI_F08_STATUSES_IGNORE ((MPIABI_F08_status *))
#define MPIABI_F08_STATUS_IGNORE ((MPIABI_F08_status *))

// C preprocessor Constants and Fortran Parameters

#define MPIABI_SUBVERSION 1
#define MPIABI_VERSION 4

// Null handles used in the MPI tool information interface

#define MPIABI_T_ENUM_NULL ((MPIABI_T_enum))
#define MPIABI_T_CVAR_HANDLE_NULL ((MPIABI_T_cvar_handle))
#define MPIABI_T_PVAR_HANDLE_NULL ((MPIABI_T_pvar_handle))
#define MPIABI_T_PVAR_SESSION_NULL ((MPIABI_T_pvar_session))

// Verbosity Levels in the MPI tool information interface

enum {
  MPIABI_T_VERBOSITY_USER_BASIC, // [nonstandard]
  MPIABI_T_VERBOSITY_USER_DETAIL,
  MPIABI_T_VERBOSITY_USER_ALL,
  MPIABI_T_VERBOSITY_TUNER_BASIC,
  MPIABI_T_VERBOSITY_TUNER_DETAIL,
  MPIABI_T_VERBOSITY_TUNER_ALL,
  MPIABI_T_VERBOSITY_MPIDEV_BASIC,
  MPIABI_T_VERBOSITY_MPIDEV_DETAIL,
  MPIABI_T_VERBOSITY_MPIDEV_ALL,
};

// Constants to identify associations of variables in the MPI tool information
// interface

enum {
  MPIABI_T_BIND_NO_OBJECT, // [nonstandard]
  MPIABI_T_BIND_MPI_COMM,
  MPIABI_T_BIND_MPI_DATATYPE,
  MPIABI_T_BIND_MPI_ERRHANDLER,
  MPIABI_T_BIND_MPI_FILE,
  MPIABI_T_BIND_MPI_GROUP,
  MPIABI_T_BIND_MPI_OP,
  MPIABI_T_BIND_MPI_REQUEST,
  MPIABI_T_BIND_MPI_WIN,
  MPIABI_T_BIND_MPI_MESSAGE,
  MPIABI_T_BIND_MPI_INFO,
  MPIABI_T_BIND_MPI_SESSION,
};

// Constants describing the scope of a control variable in the MPI tool
// information interface

enum {
  MPIABI_T_SCOPE_CONSTANT, // [nonstandard]
  MPIABI_T_SCOPE_READONLY,
  MPIABI_T_SCOPE_LOCAL,
  MPIABI_T_SCOPE_GROUP,
  MPIABI_T_SCOPE_GROUP_EQ,
  MPIABI_T_SCOPE_ALL,
  MPIABI_T_SCOPE_ALL_EQ,
};

// Additional constants used

#define MPIABI_T_PVAR_ALL_HANDLES ((MPIABI_T_pvar_handle))

// Performance variables classes used by the MPI tool information interface

enum {
  MPIABI_T_PVAR_CLASS_STATE, // [nonstandard]
  MPIABI_T_PVAR_CLASS_LEVEL,
  MPIABI_T_PVAR_CLASS_SIZE,
  MPIABI_T_PVAR_CLASS_PERCENTAGE,
  MPIABI_T_PVAR_CLASS_HIGHWATERMARK,
  MPIABI_T_PVAR_CLASS_LOWWATERMARK,
  MPIABI_T_PVAR_CLASS_COUNTER,
  MPIABI_T_PVAR_CLASS_AGGREGATE,
  MPIABI_T_PVAR_CLASS_TIMER,
  MPIABI_T_PVAR_CLASS_GENERIC,
};

// Source event ordering guarantees in the MPI tool information interface

#define MPIABI_T_SOURCE_ORDERED ((MPIABI_T_source_order))
#define MPIABI_T_SOURCE_UNORDERED ((MPIABI_T_source_order))

// Callback safety requirement levels used in the MPI tool information interface

#define MPIABI_T_CB_REQUIRE_NONE ((MPIABI_T_cb_safety))
#define MPIABI_T_CB_REQUIRE_MPI_RESTRICTED ((MPIABI_T_cb_safety))
#define MPIABI_T_CB_REQUIRE_THREAD_SAFE ((MPIABI_T_cb_safety))
#define MPIABI_T_CB_REQUIRE_ASYNC_SIGNAL_SAFE ((MPIABI_T_cb_safety))

#endif // #ifndef MPIABI_CONSTANTS_H
