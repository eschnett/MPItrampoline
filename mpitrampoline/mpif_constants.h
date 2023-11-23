      include "mpiabif_constants.h"

!     Define MPI constants

!     A.1.1 Defined Constants

!     Variable Address Size
!     Define these first because they are used in other definitions.

      integer MPI_ADDRESS_KIND
      parameter (MPI_ADDRESS_KIND = MPIABI_ADDRESS_KIND)
      integer MPI_COUNT_KIND
      parameter (MPI_COUNT_KIND = MPIABI_COUNT_KIND)
      integer MPI_INTEGER_KIND
      parameter (MPI_INTEGER_KIND = MPIABI_INTEGER_KIND)
      integer MPI_OFFSET_KIND
      parameter (MPI_OFFSET_KIND = MPIABI_OFFSET_KIND)

!     Error classes

      integer MPI_SUCCESS
      parameter (MPI_SUCCESS = MPIABI_SUCCESS)
      integer MPI_ERR_BUFFER
      parameter (MPI_ERR_BUFFER = MPIABI_ERR_BUFFER)
      integer MPI_ERR_COUNT
      parameter (MPI_ERR_COUNT = MPIABI_ERR_COUNT)
      integer MPI_ERR_TYPE
      parameter (MPI_ERR_TYPE = MPIABI_ERR_TYPE)
      integer MPI_ERR_TAG
      parameter (MPI_ERR_TAG = MPIABI_ERR_TAG)
      integer MPI_ERR_COMM
      parameter (MPI_ERR_COMM = MPIABI_ERR_COMM)
      integer MPI_ERR_RANK
      parameter (MPI_ERR_RANK = MPIABI_ERR_RANK)
      integer MPI_ERR_REQUEST
      parameter (MPI_ERR_REQUEST = MPIABI_ERR_REQUEST)
      integer MPI_ERR_ROOT
      parameter (MPI_ERR_ROOT = MPIABI_ERR_ROOT)
      integer MPI_ERR_GROUP
      parameter (MPI_ERR_GROUP = MPIABI_ERR_GROUP)
      integer MPI_ERR_OP
      parameter (MPI_ERR_OP = MPIABI_ERR_OP)
      integer MPI_ERR_TOPOLOGY
      parameter (MPI_ERR_TOPOLOGY = MPIABI_ERR_TOPOLOGY)
      integer MPI_ERR_DIMS
      parameter (MPI_ERR_DIMS = MPIABI_ERR_DIMS)
      integer MPI_ERR_ARG
      parameter (MPI_ERR_ARG = MPIABI_ERR_ARG)
      integer MPI_ERR_UNKNOWN
      parameter (MPI_ERR_UNKNOWN = MPIABI_ERR_UNKNOWN)
      integer MPI_ERR_TRUNCATE
      parameter (MPI_ERR_TRUNCATE = MPIABI_ERR_TRUNCATE)
      integer MPI_ERR_OTHER
      parameter (MPI_ERR_OTHER = MPIABI_ERR_OTHER)
      integer MPI_ERR_INTERN
      parameter (MPI_ERR_INTERN = MPIABI_ERR_INTERN)
      integer MPI_ERR_PENDING
      parameter (MPI_ERR_PENDING = MPIABI_ERR_PENDING)
      integer MPI_ERR_IN_STATUS
      parameter (MPI_ERR_IN_STATUS = MPIABI_ERR_IN_STATUS)
      integer MPI_ERR_ACCESS
      parameter (MPI_ERR_ACCESS = MPIABI_ERR_ACCESS)
      integer MPI_ERR_AMODE
      parameter (MPI_ERR_AMODE = MPIABI_ERR_AMODE)
      integer MPI_ERR_ASSERT
      parameter (MPI_ERR_ASSERT = MPIABI_ERR_ASSERT)
      integer MPI_ERR_BAD_FILE
      parameter (MPI_ERR_BAD_FILE = MPIABI_ERR_BAD_FILE)
      integer MPI_ERR_BASE
      parameter (MPI_ERR_BASE = MPIABI_ERR_BASE)
      integer MPI_ERR_CONVERSION
      parameter (MPI_ERR_CONVERSION = MPIABI_ERR_CONVERSION)
      integer MPI_ERR_DISP
      parameter (MPI_ERR_DISP = MPIABI_ERR_DISP)
      integer MPI_ERR_DUP_DATAREP
      parameter (MPI_ERR_DUP_DATAREP = MPIABI_ERR_DUP_DATAREP)
      integer MPI_ERR_FILE_EXISTS
      parameter (MPI_ERR_FILE_EXISTS = MPIABI_ERR_FILE_EXISTS)
      integer MPI_ERR_FILE_IN_USE
      parameter (MPI_ERR_FILE_IN_USE = MPIABI_ERR_FILE_IN_USE)
      integer MPI_ERR_FILE
      parameter (MPI_ERR_FILE = MPIABI_ERR_FILE)
      integer MPI_ERR_INFO_KEY
      parameter (MPI_ERR_INFO_KEY = MPIABI_ERR_INFO_KEY)
      integer MPI_ERR_INFO_NOKEY
      parameter (MPI_ERR_INFO_NOKEY = MPIABI_ERR_INFO_NOKEY)
      integer MPI_ERR_INFO_VALUE
      parameter (MPI_ERR_INFO_VALUE = MPIABI_ERR_INFO_VALUE)
      integer MPI_ERR_INFO
      parameter (MPI_ERR_INFO = MPIABI_ERR_INFO)
      integer MPI_ERR_IO
      parameter (MPI_ERR_IO = MPIABI_ERR_IO)
      integer MPI_ERR_KEYVAL
      parameter (MPI_ERR_KEYVAL = MPIABI_ERR_KEYVAL)
      integer MPI_ERR_LOCKTYPE
      parameter (MPI_ERR_LOCKTYPE = MPIABI_ERR_LOCKTYPE)
      integer MPI_ERR_NAME
      parameter (MPI_ERR_NAME = MPIABI_ERR_NAME)
      integer MPI_ERR_NO_MEM
      parameter (MPI_ERR_NO_MEM = MPIABI_ERR_NO_MEM)
      integer MPI_ERR_NOT_SAME
      parameter (MPI_ERR_NOT_SAME = MPIABI_ERR_NOT_SAME)
      integer MPI_ERR_NO_SPACE
      parameter (MPI_ERR_NO_SPACE = MPIABI_ERR_NO_SPACE)
      integer MPI_ERR_NO_SUCH_FILE
      parameter (MPI_ERR_NO_SUCH_FILE = MPIABI_ERR_NO_SUCH_FILE)
      integer MPI_ERR_PORT
      parameter (MPI_ERR_PORT = MPIABI_ERR_PORT)
      integer MPI_ERR_PROC_ABORTED
      parameter (MPI_ERR_PROC_ABORTED = MPIABI_ERR_PROC_ABORTED)
      integer MPI_ERR_QUOTA
      parameter (MPI_ERR_QUOTA = MPIABI_ERR_QUOTA)
      integer MPI_ERR_READ_ONLY
      parameter (MPI_ERR_READ_ONLY = MPIABI_ERR_READ_ONLY)
      integer MPI_ERR_RMA_ATTACH
      parameter (MPI_ERR_RMA_ATTACH = MPIABI_ERR_RMA_ATTACH)
      integer MPI_ERR_RMA_CONFLICT
      parameter (MPI_ERR_RMA_CONFLICT = MPIABI_ERR_RMA_CONFLICT)
      integer MPI_ERR_RMA_RANGE
      parameter (MPI_ERR_RMA_RANGE = MPIABI_ERR_RMA_RANGE)
      integer MPI_ERR_RMA_SHARED
      parameter (MPI_ERR_RMA_SHARED = MPIABI_ERR_RMA_SHARED)
      integer MPI_ERR_RMA_SYNC
      parameter (MPI_ERR_RMA_SYNC = MPIABI_ERR_RMA_SYNC)
      integer MPI_ERR_RMA_FLAVOR
      parameter (MPI_ERR_RMA_FLAVOR = MPIABI_ERR_RMA_FLAVOR)
      integer MPI_ERR_SERVICE
      parameter (MPI_ERR_SERVICE = MPIABI_ERR_SERVICE)
      integer MPI_ERR_SESSION
      parameter (MPI_ERR_SESSION = MPIABI_ERR_SESSION)
      integer MPI_ERR_SIZE
      parameter (MPI_ERR_SIZE = MPIABI_ERR_SIZE)
      integer MPI_ERR_SPAWN
      parameter (MPI_ERR_SPAWN = MPIABI_ERR_SPAWN)
      integer MPI_ERR_UNSUPPORTED_DATAREP
      parameter (MPI_ERR_UNSUPPORTED_DATAREP =                          &
     &     MPIABI_ERR_UNSUPPORTED_DATAREP)
      integer MPI_ERR_UNSUPPORTED_OPERATION
      parameter (MPI_ERR_UNSUPPORTED_OPERATION =                        &
     &     MPIABI_ERR_UNSUPPORTED_OPERATION)
      integer MPI_ERR_VALUE_TOO_LARGE
      parameter (MPI_ERR_VALUE_TOO_LARGE = MPIABI_ERR_VALUE_TOO_LARGE)
      integer MPI_ERR_WIN
      parameter (MPI_ERR_WIN = MPIABI_ERR_WIN)
      integer MPI_ERR_ERRHANDLER
      parameter (MPI_ERR_ERRHANDLER = MPIABI_ERR_ERRHANDLER)
      integer MPI_T_ERR_CANNOT_INIT
      parameter (MPI_T_ERR_CANNOT_INIT = MPIABI_T_ERR_CANNOT_INIT)
      integer MPI_T_ERR_NOT_ACCESSIBLE
      parameter (MPI_T_ERR_NOT_ACCESSIBLE = MPIABI_T_ERR_NOT_ACCESSIBLE)
      integer MPI_T_ERR_NOT_INITIALIZED
      parameter (MPI_T_ERR_NOT_INITIALIZED =                            &
     &     MPIABI_T_ERR_NOT_INITIALIZED)
      integer MPI_T_ERR_NOT_SUPPORTED
      parameter (MPI_T_ERR_NOT_SUPPORTED = MPIABI_T_ERR_NOT_SUPPORTED)
      integer MPI_T_ERR_MEMORY
      parameter (MPI_T_ERR_MEMORY = MPIABI_T_ERR_MEMORY)
      integer MPI_T_ERR_INVALID
      parameter (MPI_T_ERR_INVALID = MPIABI_T_ERR_INVALID)
      integer MPI_T_ERR_INVALID_INDEX
      parameter (MPI_T_ERR_INVALID_INDEX = MPIABI_T_ERR_INVALID_INDEX)
      integer MPI_T_ERR_INVALID_ITEM
      parameter (MPI_T_ERR_INVALID_ITEM = MPIABI_T_ERR_INVALID_ITEM)
      integer MPI_T_ERR_INVALID_SESSION
      parameter (MPI_T_ERR_INVALID_SESSION =                            &
     &     MPIABI_T_ERR_INVALID_SESSION)
      integer MPI_T_ERR_INVALID_HANDLE
      parameter (MPI_T_ERR_INVALID_HANDLE = MPIABI_T_ERR_INVALID_HANDLE)
      integer MPI_T_ERR_INVALID_NAME
      parameter (MPI_T_ERR_INVALID_NAME = MPIABI_T_ERR_INVALID_NAME)
      integer MPI_T_ERR_OUT_OF_HANDLES
      parameter (MPI_T_ERR_OUT_OF_HANDLES = MPIABI_T_ERR_OUT_OF_HANDLES)
      integer MPI_T_ERR_OUT_OF_SESSIONS
      parameter (MPI_T_ERR_OUT_OF_SESSIONS =                            &
     &     MPIABI_T_ERR_OUT_OF_SESSIONS)
      integer MPI_T_ERR_CVAR_SET_NOT_NOW
      parameter (MPI_T_ERR_CVAR_SET_NOT_NOW =                           &
     &     MPIABI_T_ERR_CVAR_SET_NOT_NOW)
      integer MPI_T_ERR_CVAR_SET_NEVER
      parameter (MPI_T_ERR_CVAR_SET_NEVER = MPIABI_T_ERR_CVAR_SET_NEVER)
      integer MPI_T_ERR_PVAR_NO_WRITE
      parameter (MPI_T_ERR_PVAR_NO_WRITE = MPIABI_T_ERR_PVAR_NO_WRITE)
      integer MPI_T_ERR_PVAR_NO_STARTSTOP
      parameter (MPI_T_ERR_PVAR_NO_STARTSTOP =                          &
     &     MPIABI_T_ERR_PVAR_NO_STARTSTOP)
      integer MPI_T_ERR_PVAR_NO_ATOMIC
      parameter (MPI_T_ERR_PVAR_NO_ATOMIC = MPIABI_T_ERR_PVAR_NO_ATOMIC)
      integer MPI_ERR_LASTCODE
      parameter (MPI_ERR_LASTCODE = MPIABI_ERR_LASTCODE)

!     Buffer Address Constants

      integer MPI_BOTTOM(1)
      pointer (MPIABI_BOTTOM_PTR, MPI_BOTTOM)
      integer MPI_BUFFER_AUTOMATIC(1)
      pointer (MPIABI_BUFFER_AUTOMATIC_PTR, MPI_BUFFER_AUTOMATIC)
      integer MPI_IN_PLACE(1)
      pointer (MPIABI_IN_PLACE_PTR, MPI_IN_PLACE)

!     Assorted Constants

      integer MPI_PROC_NULL
      parameter (MPI_PROC_NULL = MPIABI_PROC_NULL)
      integer MPI_ANY_SOURCE
      parameter (MPI_ANY_SOURCE = MPIABI_ANY_SOURCE)
      integer MPI_ANY_TAG
      parameter (MPI_ANY_TAG = MPIABI_ANY_TAG)
      integer MPI_UNDEFINED
      parameter (MPI_UNDEFINED = MPIABI_UNDEFINED)
      integer MPI_BSEND_OVERHEAD
      parameter (MPI_BSEND_OVERHEAD = MPIABI_BSEND_OVERHEAD)
      integer MPI_KEYVAL_INVALID
      parameter (MPI_KEYVAL_INVALID = MPIABI_KEYVAL_INVALID)
      integer MPI_LOCK_EXCLUSIVE
      parameter (MPI_LOCK_EXCLUSIVE = MPIABI_LOCK_EXCLUSIVE)
      integer MPI_LOCK_SHARED
      parameter (MPI_LOCK_SHARED = MPIABI_LOCK_SHARED)
      integer MPI_ROOT
      parameter (MPI_ROOT = MPIABI_ROOT)

!     No Process Message Handle

      integer MPI_MESSAGE_NO_PROC
      parameter (MPI_MESSAGE_NO_PROC = MPIABI_MESSAGE_NO_PROC)

!     Fortran Support Method Specific Constants

      logical MPI_SUBARRAYS_SUPPORTED
      parameter (MPI_SUBARRAYS_SUPPORTED = MPIABI_SUBARRAYS_SUPPORTED)
      logical MPI_ASYNC_PROTECTS_NONBLOCKING
      parameter (MPI_ASYNC_PROTECTS_NONBLOCKING =                       &
     &     MPIABI_ASYNC_PROTECTS_NONBLOCKING)

!     / Status array size and reserved index values

      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = MPIABI_STATUS_SIZE)
      integer MPI_SOURCE
      parameter (MPI_SOURCE = MPIABI_SOURCE)
      integer MPI_TAG
      parameter (MPI_TAG = MPIABI_TAG)
      integer MPI_ERROR
      parameter (MPI_ERROR = MPIABI_ERROR)

!     Fortran status array size and reserved index values

!     Variable Address Size
!     These have already been defined above.

!     Error-handling specifiers

      integer MPI_ERRORS_ARE_FATAL
      parameter (MPI_ERRORS_ARE_FATAL = MPIABI_ERRORS_ARE_FATAL)
      integer MPI_ERRORS_ABORT
      parameter (MPI_ERRORS_ABORT = MPIABI_ERRORS_ABORT)
      integer MPI_ERRORS_RETURN
      parameter (MPI_ERRORS_RETURN = MPIABI_ERRORS_RETURN)

!     Maximum Sizes for Strings

      integer MPI_MAX_DATAREP_STRING
      parameter (MPI_MAX_DATAREP_STRING = MPIABI_MAX_DATAREP_STRING)
      integer MPI_MAX_ERROR_STRING
      parameter (MPI_MAX_ERROR_STRING = MPIABI_MAX_ERROR_STRING)
      integer MPI_MAX_INFO_KEY
      parameter (MPI_MAX_INFO_KEY = MPIABI_MAX_INFO_KEY)
      integer MPI_MAX_INFO_VAL
      parameter (MPI_MAX_INFO_VAL = MPIABI_MAX_INFO_VAL)
      integer MPI_MAX_LIBRARY_VERSION_STRING
      parameter (MPI_MAX_LIBRARY_VERSION_STRING =                       &
     &     MPIABI_MAX_LIBRARY_VERSION_STRING)
      integer MPI_MAX_OBJECT_NAME
      parameter (MPI_MAX_OBJECT_NAME = MPIABI_MAX_OBJECT_NAME)
      integer MPI_MAX_PORT_NAME
      parameter (MPI_MAX_PORT_NAME = MPIABI_MAX_PORT_NAME)
      integer MPI_MAX_PROCESSOR_NAME
      parameter (MPI_MAX_PROCESSOR_NAME = MPIABI_MAX_PROCESSOR_NAME)
      integer MPI_MAX_PSET_NAME_LEN
      parameter (MPI_MAX_PSET_NAME_LEN = MPIABI_MAX_PSET_NAME_LEN)
      integer MPI_MAX_STRINGTAG_LEN
      parameter (MPI_MAX_STRINGTAG_LEN = MPIABI_MAX_STRINGTAG_LEN)

!     Named Predefined Datatypes

!     [C types]

      integer MPI_CHAR
      parameter (MPI_CHAR = MPIABI_CHAR)
      integer MPI_SHORT
      parameter (MPI_SHORT = MPIABI_SHORT)
      integer MPI_INT
      parameter (MPI_INT = MPIABI_INT)
      integer MPI_LONG
      parameter (MPI_LONG = MPIABI_LONG)
      integer MPI_LONG_LONG_INT
      parameter (MPI_LONG_LONG_INT = MPIABI_LONG_LONG_INT)
      integer MPI_LONG_LONG
      parameter (MPI_LONG_LONG = MPIABI_LONG_LONG)
      integer MPI_SIGNED_CHAR
      parameter (MPI_SIGNED_CHAR = MPIABI_SIGNED_CHAR)
      integer MPI_UNSIGNED_CHAR
      parameter (MPI_UNSIGNED_CHAR = MPIABI_UNSIGNED_CHAR)
      integer MPI_UNSIGNED_SHORT
      parameter (MPI_UNSIGNED_SHORT = MPIABI_UNSIGNED_SHORT)
      integer MPI_UNSIGNED
      parameter (MPI_UNSIGNED = MPIABI_UNSIGNED)
      integer MPI_UNSIGNED_LONG
      parameter (MPI_UNSIGNED_LONG = MPIABI_UNSIGNED_LONG)
      integer MPI_UNSIGNED_LONG_LONG
      parameter (MPI_UNSIGNED_LONG_LONG = MPIABI_UNSIGNED_LONG_LONG)
      integer MPI_FLOAT
      parameter (MPI_FLOAT = MPIABI_FLOAT)
      integer MPI_DOUBLE
      parameter (MPI_DOUBLE = MPIABI_DOUBLE)
      integer MPI_LONG_DOUBLE
      parameter (MPI_LONG_DOUBLE = MPIABI_LONG_DOUBLE)
      integer MPI_WCHAR
      parameter (MPI_WCHAR = MPIABI_WCHAR)
      integer MPI_C_BOOL
      parameter (MPI_C_BOOL = MPIABI_C_BOOL)
      integer MPI_INT8_T
      parameter (MPI_INT8_T = MPIABI_INT8_T)
      integer MPI_INT16_T
      parameter (MPI_INT16_T = MPIABI_INT16_T)
      integer MPI_INT32_T
      parameter (MPI_INT32_T = MPIABI_INT32_T)
      integer MPI_INT64_T
      parameter (MPI_INT64_T = MPIABI_INT64_T)
      integer MPI_UINT8_T
      parameter (MPI_UINT8_T = MPIABI_UINT8_T)
      integer MPI_UINT16_T
      parameter (MPI_UINT16_T = MPIABI_UINT16_T)
      integer MPI_UINT32_T
      parameter (MPI_UINT32_T = MPIABI_UINT32_T)
      integer MPI_UINT64_T
      parameter (MPI_UINT64_T = MPIABI_UINT64_T)
      integer MPI_AINT
      parameter (MPI_AINT = MPIABI_AINT)
      integer MPI_COUNT
      parameter (MPI_COUNT = MPIABI_COUNT)
      integer MPI_OFFSET
      parameter (MPI_OFFSET = MPIABI_OFFSET)
      integer MPI_C_COMPLEX
      parameter (MPI_C_COMPLEX = MPIABI_C_COMPLEX)
      integer MPI_C_FLOAT_COMPLEX
      parameter (MPI_C_FLOAT_COMPLEX = MPIABI_C_FLOAT_COMPLEX)
      integer MPI_C_DOUBLE_COMPLEX
      parameter (MPI_C_DOUBLE_COMPLEX = MPIABI_C_DOUBLE_COMPLEX)
      integer MPI_C_LONG_DOUBLE_COMPLEX
      parameter (MPI_C_LONG_DOUBLE_COMPLEX =                            &
     &     MPIABI_C_LONG_DOUBLE_COMPLEX)
      integer MPI_BYTE
      parameter (MPI_BYTE = MPIABI_BYTE)
      integer MPI_PACKED
      parameter (MPI_PACKED = MPIABI_PACKED)

!     [Fortran types]

      integer MPI_INTEGER
      parameter (MPI_INTEGER = MPIABI_INTEGER)
      integer MPI_REAL
      parameter (MPI_REAL = MPIABI_REAL)
      integer MPI_DOUBLE_PRECISION
      parameter (MPI_DOUBLE_PRECISION = MPIABI_DOUBLE_PRECISION)
      integer MPI_COMPLEX
      parameter (MPI_COMPLEX = MPIABI_COMPLEX)
      integer MPI_LOGICAL
      parameter (MPI_LOGICAL = MPIABI_LOGICAL)
      integer MPI_CHARACTER
      parameter (MPI_CHARACTER = MPIABI_CHARACTER)

!     [C++ types]

      integer MPI_CXX_BOOL
      parameter (MPI_CXX_BOOL = MPIABI_CXX_BOOL)
      integer MPI_CXX_FLOAT_COMPLEX
      parameter (MPI_CXX_FLOAT_COMPLEX = MPIABI_CXX_FLOAT_COMPLEX)
      integer MPI_CXX_DOUBLE_COMPLEX
      parameter (MPI_CXX_DOUBLE_COMPLEX = MPIABI_CXX_DOUBLE_COMPLEX)
      integer MPI_CXX_LONG_DOUBLE_COMPLEX
      parameter (MPI_CXX_LONG_DOUBLE_COMPLEX =                          &
     &     MPIABI_CXX_LONG_DOUBLE_COMPLEX)

!     [Optional datatypes (Fortran)]

      integer MPI_DOUBLE_COMPLEX
      parameter (MPI_DOUBLE_COMPLEX = MPIABI_DOUBLE_COMPLEX)
      integer MPI_INTEGER1
      parameter (MPI_INTEGER1 = MPIABI_INTEGER1) 
      integer MPI_INTEGER2
      parameter (MPI_INTEGER2 = MPIABI_INTEGER2)  
      integer MPI_INTEGER4
      parameter (MPI_INTEGER4 = MPIABI_INTEGER4)  
      integer MPI_INTEGER8
      parameter (MPI_INTEGER8 = MPIABI_INTEGER8)  
      integer MPI_INTEGER16
      parameter (MPI_INTEGER16 = MPIABI_INTEGER16) 
      integer MPI_REAL2
      parameter (MPI_REAL2 = MPIABI_REAL2)     
      integer MPI_REAL4
      parameter (MPI_REAL4 = MPIABI_REAL4)     
      integer MPI_REAL8
      parameter (MPI_REAL8 = MPIABI_REAL8)     
      integer MPI_REAL16
      parameter (MPI_REAL16 = MPIABI_REAL16)    
      integer MPI_COMPLEX4
      parameter (MPI_COMPLEX4 = MPIABI_COMPLEX4)  
      integer MPI_COMPLEX8
      parameter (MPI_COMPLEX8 = MPIABI_COMPLEX8)  
      integer MPI_COMPLEX16
      parameter (MPI_COMPLEX16 = MPIABI_COMPLEX16) 
      integer MPI_COMPLEX32
      parameter (MPI_COMPLEX32 = MPIABI_COMPLEX32) 

!     [Extensions]

      integer MPI_REAL1
      parameter (MPI_REAL1 = MPIABI_REAL1)     
      integer MPI_COMPLEX2
      parameter (MPI_COMPLEX2 = MPIABI_COMPLEX2)  
      integer MPI_LOGICAL1
      parameter (MPI_LOGICAL1 = MPIABI_LOGICAL1)  
      integer MPI_LOGICAL2
      parameter (MPI_LOGICAL2 = MPIABI_LOGICAL2)  
      integer MPI_LOGICAL4
      parameter (MPI_LOGICAL4 = MPIABI_LOGICAL4)  
      integer MPI_LOGICAL8
      parameter (MPI_LOGICAL8 = MPIABI_LOGICAL8)  
      integer MPI_LOGICAL16
      parameter (MPI_LOGICAL16 = MPIABI_LOGICAL16) 

!     [Datatypes for reduction functions (C)]

      integer MPI_FLOAT_INT
      parameter (MPI_FLOAT_INT = MPIABI_FLOAT_INT)  
      integer MPI_DOUBLE_INT
      parameter (MPI_DOUBLE_INT = MPIABI_DOUBLE_INT) 
      integer MPI_LONG_INT
      parameter (MPI_LONG_INT = MPIABI_LONG_INT)   
      integer MPI_2INT
      parameter (MPI_2INT = MPIABI_2INT)       
      integer MPI_SHORT_INT
      parameter (MPI_SHORT_INT = MPIABI_SHORT_INT)  
      integer MPI_LONG_DOUBLE_INT
      parameter (MPI_LONG_DOUBLE_INT = MPIABI_LONG_DOUBLE_INT)

!     [Datatypes for reduction functions (Fortran)]

      integer MPI_2REAL
      parameter (MPI_2REAL = MPIABI_2REAL)
      integer MPI_2DOUBLE_PRECISION
      parameter (MPI_2DOUBLE_PRECISION = MPIABI_2DOUBLE_PRECISION)
      integer MPI_2INTEGER
      parameter (MPI_2integer = MPIABI_2integer)

!     [Removed constructs]

!     [nonstandard]
      integer MPI_LB
      parameter (MPI_LB = MPIABI_LB)
!     [nonstandard]
      integer MPI_UB
      parameter (MPI_UB = MPIABI_UB)

!     Reserved communicators

      integer MPI_COMM_WORLD
      parameter (MPI_COMM_WORLD = MPIABI_COMM_WORLD)
      integer MPI_COMM_SELF
      parameter (MPI_COMM_SELF = MPIABI_COMM_SELF)

! // Communicator split type constants
! enum {
!   MPIABI_COMM_TYPE_SHARED = -1001,          // arXiv:2308.11214
!   MPIABI_COMM_TYPE_HW_UNGUIDED = -1002,     // arXiv:2308.11214
!   MPIABI_COMM_TYPE_HW_GUIDED = -1003,       // arXiv:2308.11214
!   MPIABI_COMM_TYPE_RESOURCE_GUIDED = -1004, // [nonstandard]
! };
!
! // Results of communicator and group comparisons
!
! enum {
!   MPIABI_IDENT = -701,     // arXiv:2308.11214
!   MPIABI_CONGRUENT = -702, // arXiv:2308.11214
!   MPIABI_SIMILAR = -703,   // arXiv:2308.11214
!   MPIABI_UNEQUAL = -704,   // arXiv:2308.11214
! };
!
! // Environmental inquiry info key
!
! #define MPIABI_INFO_ENV ((MPIABI_Info)0b000100110001) // [nonstandard]
!
! // Environmental inquiry keys
!
! enum {
!   MPIABI_TAG_UB = -201,          // arXiv:2308.11214
!   MPIABI_IO = -202,              // arXiv:2308.11214
!   MPIABI_HOST = -203,            // arXiv:2308.11214 [deprecated]
!   MPIABI_WTIME_IS_GLOBAL = -204, // arXiv:2308.11214
! };
!
! // Collective Operations
!
! #define MPIABI_MAX ((MPIABI_Op)0b000000100011)     // arXiv:2308.11214
! #define MPIABI_MIN ((MPIABI_Op)0b000000100010)     // arXiv:2308.11214
! #define MPIABI_SUM ((MPIABI_Op)0b000000100001)     // arXiv:2308.11214
! #define MPIABI_PROD ((MPIABI_Op)0b000000100100)    // arXiv:2308.11214
! #define MPIABI_MAXLOC ((MPIABI_Op)0b000000111001)  // arXiv:2308.11214
! #define MPIABI_MINLOC ((MPIABI_Op)0b000000111000)  // arXiv:2308.11214
! #define MPIABI_BAND ((MPIABI_Op)0b000000101000)    // arXiv:2308.11214
! #define MPIABI_BOR ((MPIABI_Op)0b000000101001)     // arXiv:2308.11214
! #define MPIABI_BXOR ((MPIABI_Op)0b000000101010)    // arXiv:2308.11214
! #define MPIABI_LAND ((MPIABI_Op)0b000000110000)    // arXiv:2308.11214
! #define MPIABI_LOR ((MPIABI_Op)0b000000110001)     // arXiv:2308.11214
! #define MPIABI_LXOR ((MPIABI_Op)0b000000110010)    // arXiv:2308.11214
! #define MPIABI_REPLACE ((MPIABI_Op)0b000000111100) // arXiv:2308.11214
! #define MPIABI_NO_OP ((MPIABI_Op)0b000000111101)   // arXiv:2308.11214

!     Null Handles

      integer MPI_GROUP_NULL
      parameter (MPI_GROUP_NULL = MPIABI_GROUP_NULL)
      integer MPI_COMM_NULL
      parameter (MPI_COMM_NULL = MPIABI_COMM_NULL)
      integer MPI_DATATYPE_NULL
      parameter (MPI_DATATYPE_NULL = MPIABI_DATATYPE_NULL)
      integer MPI_REQUEST_NULL
      parameter (MPI_REQUEST_NULL = MPIABI_REQUEST_NULL)
      integer MPI_OP_NULL
      parameter (MPI_OP_NULL = MPIABI_OP_NULL)
      integer MPI_ERRHANDLER_NULL
      parameter (MPI_ERRHANDLER_NULL = MPIABI_ERRHANDLER_NULL)
      integer MPI_FILE_NULL
      parameter (MPI_FILE_NULL = MPIABI_FILE_NULL)
      integer MPI_INFO_NULL
      parameter (MPI_INFO_NULL = MPIABI_INFO_NULL)
      integer MPI_SESSION_NULL
      parameter (MPI_SESSION_NULL = MPIABI_SESSION_NULL)
      integer MPI_WIN_NULL
      parameter (MPI_WIN_NULL = MPIABI_WIN_NULL)
      integer MPI_MESSAGE_NULL
      parameter (MPI_MESSAGE_NULL = MPIABI_MESSAGE_NULL)

!     Empty group

      integer MPI_GROUP_EMPTY
      parameter (MPI_GROUP_EMPTY = MPIABI_GROUP_EMPTY)

! // Topologies
!
! enum {
!   MPIABI_GRAPH = -1801,      // arXiv:2308.11214
!   MPIABI_CART = -1803,       // arXiv:2308.11214
!   MPIABI_DIST_GRAPH = -1802, // arXiv:2308.11214
! };
!
! // Predefined functions
!
! #define MPIABI_COMM_NULL_COPY_FN                                               \
!   ((MPIABI_Comm_copy_attr_function)0) // arXiv:2308.11214
! #define MPIABI_COMM_DUP_FN                                                     \
!   ((MPIABI_Comm_copy_attr_function)1) // arXiv:2308.11214
! #define MPIABI_COMM_NULL_DELETE_FN                                             \
!   ((MPIABI_Comm_delete_attr_function)0) // arXiv:2308.11214
!
! #define MPIABI_WIN_NULL_COPY_FN                                                \
!   ((MPIABI_Win_copy_attr_function)0)                         // arXiv:2308.11214
! #define MPIABI_WIN_DUP_FN ((MPIABI_Win_copy_attr_function)1) // arXiv:2308.11214
! #define MPIABI_WIN_NULL_DELETE_FN                                              \
!   ((MPIABI_Win_delete_attr_function)0) // arXiv:2308.11214
!
! #define MPIABI_TYPE_NULL_COPY_FN                                               \
!   ((MPIABI_Type_copy_attr_function)0) // arXiv:2308.11214
! #define MPIABI_TYPE_DUP_FN                                                     \
!   ((MPIABI_Type_copy_attr_function)1) // arXiv:2308.11214
! #define MPIABI_TYPE_NULL_DELETE_FN                                             \
!   ((MPIABI_Type_delete_attr_function)0) // arXiv:2308.11214
!
! #define MPIABI_CONVERSION_FN_NULL                                              \
!   ((MPIABI_Datarep_conversion_function)0) // arXiv:2308.11214
! #define MPIABI_CONVERSION_FN_NULL_C                                            \
!   ((MPIABI_Datarep_conversion_function_c)0) // arXiv:2308.11214
!
! // Deprecated predefined functions
!
! #define MPIABI_NULL_COPY_FN ((MPIABI_Copy_function)0)
! #define MPIABI_DUP_FN ((MPIABI_Copy_function)1)
! #define MPIABI_NULL_DELETE_FN ((MPIABI_Delete_function)0)
!
! // Predefined Attribute Keys
!
! enum {
!   MPIABI_APPNUM = -205,            // arXiv:2308.11214
!   MPIABI_LASTUSEDCODE = -206,      // arXiv:2308.11214
!   MPIABI_UNIVERSE_SIZE = -207,     // arXiv:2308.11214
!   MPIABI_WIN_BASE = -301,          // arXiv:2308.11214
!   MPIABI_WIN_DISP_UNIT = -302,     // arXiv:2308.11214
!   MPIABI_WIN_SIZE = -303,          // arXiv:2308.11214
!   MPIABI_WIN_CREATE_FLAVOR = -304, // arXiv:2308.11214
!   MPIABI_WIN_MODEL = -305,         // arXiv:2308.11214
! };
!
! // MPI Window Create Flavors
!
! enum {
!   MPIABI_WIN_FLAVOR_CREATE = -1102,   // arXiv:2308.11214
!   MPIABI_WIN_FLAVOR_ALLOCATE = -1101, // arXiv:2308.11214
!   MPIABI_WIN_FLAVOR_DYNAMIC = -1103,  // arXiv:2308.11214
!   MPIABI_WIN_FLAVOR_SHARED = -1104,   // arXiv:2308.11214
! };
!
! // MPI Window Models
!
! enum {
!   MPIABI_WIN_SEPARATE = -1201, // arXiv:2308.11214
!   MPIABI_WIN_UNIFIED = -1202,  // arXiv:2308.11214
! };
!
! // Mode Constants
!
! enum {
!   MPIABI_MODE_APPEND = 1,          // arXiv:2308.11214
!   MPIABI_MODE_CREATE = 2,          // arXiv:2308.11214
!   MPIABI_MODE_DELETE_ON_CLOSE = 4, // arXiv:2308.11214
!   MPIABI_MODE_EXCL = 8,            // arXiv:2308.11214
!   MPIABI_MODE_NOCHECK = 1024,      // arXiv:2308.11214
!   MPIABI_MODE_NOPRECEDE = 2048,    // arXiv:2308.11214
!   MPIABI_MODE_NOPUT = 4096,        // arXiv:2308.11214
!   MPIABI_MODE_NOSTORE = 8192,      // arXiv:2308.11214
!   MPIABI_MODE_NOSUCCEED = 16384,   // arXiv:2308.11214
!   MPIABI_MODE_RDONLY = 16,         // arXiv:2308.11214
!   MPIABI_MODE_RDWR = 32,           // arXiv:2308.11214
!   MPIABI_MODE_SEQUENTIAL = 64,     // arXiv:2308.11214
!   MPIABI_MODE_UNIQUE_OPEN = 128,   // arXiv:2308.11214
!   MPIABI_MODE_WRONLY = 256,        // arXiv:2308.11214
! };
!
! // Datatype Decoding Constants
!
! enum {
!   MPIABI_COMBINER_CONTIGUOUS = -1303,     // arXiv:2308.11214
!   MPIABI_COMBINER_DARRAY = -1312,         // arXiv:2308.11214
!   MPIABI_COMBINER_DUP = -1302,            // arXiv:2308.11214
!   MPIABI_COMBINER_F90_COMPLEX = -1314,    // arXiv:2308.11214
!   MPIABI_COMBINER_F90_INTEGER = -1315,    // arXiv:2308.11214
!   MPIABI_COMBINER_F90_REAL = -1313,       // arXiv:2308.11214
!   MPIABI_COMBINER_HINDEXED = -1307,       // arXiv:2308.11214
!   MPIABI_COMBINER_HVECTOR = -1305,        // arXiv:2308.11214
!   MPIABI_COMBINER_INDEXED_BLOCK = -1308,  // arXiv:2308.11214
!   MPIABI_COMBINER_HINDEXED_BLOCK = -1309, // arXiv:2308.11214
!   MPIABI_COMBINER_INDEXED = -1306,        // arXiv:2308.11214
!   MPIABI_COMBINER_NAMED = -1301,          // arXiv:2308.11214
!   MPIABI_COMBINER_RESIZED = -1316,        // arXiv:2308.11214
!   MPIABI_COMBINER_STRUCT = -1310,         // arXiv:2308.11214
!   MPIABI_COMBINER_SUBARRAY = -1311,       // arXiv:2308.11214
!   MPIABI_COMBINER_VECTOR = -1304,         // arXiv:2308.11214
! };
!
! // Threads Constants
!
! enum {
!   MPIABI_THREAD_FUNNELED = -803,   // arXiv:2308.11214
!   MPIABI_THREAD_MULTIPLE = -801,   // arXiv:2308.11214
!   MPIABI_THREAD_SERIALIZED = -802, // arXiv:2308.11214
!   MPIABI_THREAD_SINGLE = -804,     // arXiv:2308.11214
! };
!
! // File Operation Constants, Part 1
!
! #define MPIABI_DISPLACEMENT_CURRENT ((MPIABI_Offset)-501) // arXiv:2308.11214
!
! // File Operation Constants, Part 2
!
! enum {
!   MPIABI_DISTRIBUTE_BLOCK = -1401,     // arXiv:2308.11214
!   MPIABI_DISTRIBUTE_CYCLIC = -1402,    // arXiv:2308.11214
!   MPIABI_DISTRIBUTE_DFLT_DARG = -1403, // arXiv:2308.11214
!   MPIABI_DISTRIBUTE_NONE = -1404,      // arXiv:2308.11214
!   MPIABI_ORDER_C = -1501,              // arXiv:2308.11214
!   MPIABI_ORDER_FORTRAN = -1502,        // arXiv:2308.11214
!   MPIABI_SEEK_CUR = -1601,             // arXiv:2308.11214
!   MPIABI_SEEK_END = -1602,             // arXiv:2308.11214
!   MPIABI_SEEK_SET = -1603,             // arXiv:2308.11214
! };
!
! // F90 Datatype Matching Constants
!
! enum {
!   MPIABI_TYPECLASS_COMPLEX = -1702, // arXiv:2308.11214
!   MPIABI_TYPECLASS_INTEGER = -1703, // arXiv:2308.11214
!   MPIABI_TYPECLASS_REAL = -1701,    // arXiv:2308.11214
! };

!     Constants Specifying Empty or Ignored Input

      integer MPI_ARGVS_NULL(1)
      pointer (MPIABI_ARGVS_NULL_PTR, MPI_ARGVS_NULL)
      integer MPI_ARGV_NULL(1)
      pointer (MPIABI_ARGV_NULL_PTR, MPI_ARGV_NULL)
      integer MPI_ERRCODES_IGNORE(1)
      pointer (MPIABI_ERRCODES_IGNORE_PTR, MPI_ERRCODES_IGNORE)
      integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE)
      pointer (MPIABI_STATUSES_IGNORE_PTR, MPI_STATUSES_IGNORE)
      integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
      pointer (MPIABI_STATUS_IGNORE_PTR, MPI_STATUS_IGNORE)
      integer MPI_UNWEIGHTED(1)
      pointer (MPIABI_UNWEIGHTED_PTR, MPI_UNWEIGHTED)
      integer MPI_WEIGHTS_EMPTY(1)
      pointer (MPIABI_WEIGHTS_EMPTY_PTR, MPI_WEIGHTS_EMPTY)

! // C Constants Specifying Ignored Input (no Fortran)
!
! #define MPIABI_F_STATUSES_IGNORE ((MPIABI_Fint *))
! #define MPIABI_F_STATUS_IGNORE ((MPIABI_Fint *))
!
! #define MPIABI_F08_STATUSES_IGNORE ((MPIABI_F08_status *))
! #define MPIABI_F08_STATUS_IGNORE ((MPIABI_F08_status *))
!
! // C preprocessor Constants and Fortran Parameters
! enum {
!   MPIABI_SUBVERSION = 1,
!   MPIABI_VERSION = 4,
! };
!
! // Null handles used in the MPI tool information interface
!
! #define MPIABI_T_ENUM_NULL ((MPIABI_T_enum))
! #define MPIABI_T_CVAR_HANDLE_NULL ((MPIABI_T_cvar_handle))
! #define MPIABI_T_PVAR_HANDLE_NULL ((MPIABI_T_pvar_handle))
! #define MPIABI_T_PVAR_SESSION_NULL ((MPIABI_T_pvar_session))
!
! // Verbosity Levels in the MPI tool information interface
!
! enum {
!   MPIABI_T_VERBOSITY_USER_BASIC, // [nonstandard]
!   MPIABI_T_VERBOSITY_USER_DETAIL,
!   MPIABI_T_VERBOSITY_USER_ALL,
!   MPIABI_T_VERBOSITY_TUNER_BASIC,
!   MPIABI_T_VERBOSITY_TUNER_DETAIL,
!   MPIABI_T_VERBOSITY_TUNER_ALL,
!   MPIABI_T_VERBOSITY_MPIDEV_BASIC,
!   MPIABI_T_VERBOSITY_MPIDEV_DETAIL,
!   MPIABI_T_VERBOSITY_MPIDEV_ALL,
! };
!
! // Constants to identify associations of variables in the MPI tool information
! // interface
!
! enum {
!   MPIABI_T_BIND_NO_OBJECT, // [nonstandard]
!   MPIABI_T_BIND_MPI_COMM,
!   MPIABI_T_BIND_MPI_DATATYPE,
!   MPIABI_T_BIND_MPI_ERRHANDLER,
!   MPIABI_T_BIND_MPI_FILE,
!   MPIABI_T_BIND_MPI_GROUP,
!   MPIABI_T_BIND_MPI_OP,
!   MPIABI_T_BIND_MPI_REQUEST,
!   MPIABI_T_BIND_MPI_WIN,
!   MPIABI_T_BIND_MPI_MESSAGE,
!   MPIABI_T_BIND_MPI_INFO,
!   MPIABI_T_BIND_MPI_SESSION,
! };
!
! // Constants describing the scope of a control variable in the MPI tool
! // information interface
!
! enum {
!   MPIABI_T_SCOPE_CONSTANT, // [nonstandard]
!   MPIABI_T_SCOPE_READONLY,
!   MPIABI_T_SCOPE_LOCAL,
!   MPIABI_T_SCOPE_GROUP,
!   MPIABI_T_SCOPE_GROUP_EQ,
!   MPIABI_T_SCOPE_ALL,
!   MPIABI_T_SCOPE_ALL_EQ,
! };
!
! // Additional constants used
!
! #define MPIABI_T_PVAR_ALL_HANDLES ((MPIABI_T_pvar_handle))
!
! // Performance variables classes used by the MPI tool information interface
!
! enum {
!   MPIABI_T_PVAR_CLASS_STATE, // [nonstandard]
!   MPIABI_T_PVAR_CLASS_LEVEL,
!   MPIABI_T_PVAR_CLASS_SIZE,
!   MPIABI_T_PVAR_CLASS_PERCENTAGE,
!   MPIABI_T_PVAR_CLASS_HIGHWATERMARK,
!   MPIABI_T_PVAR_CLASS_LOWWATERMARK,
!   MPIABI_T_PVAR_CLASS_COUNTER,
!   MPIABI_T_PVAR_CLASS_AGGREGATE,
!   MPIABI_T_PVAR_CLASS_TIMER,
!   MPIABI_T_PVAR_CLASS_GENERIC,
! };
!
! // Source event ordering guarantees in the MPI tool information interface
!
! #define MPIABI_T_SOURCE_ORDERED ((MPIABI_T_source_order))
! #define MPIABI_T_SOURCE_UNORDERED ((MPIABI_T_source_order))
!
! // Callback safety requirement levels used in the MPI tool information interface
!
! #define MPIABI_T_CB_REQUIRE_NONE ((MPIABI_T_cb_safety))
! #define MPIABI_T_CB_REQUIRE_MPI_RESTRICTED ((MPIABI_T_cb_safety))
! #define MPIABI_T_CB_REQUIRE_THREAD_SAFE ((MPIABI_T_cb_safety))
! #define MPIABI_T_CB_REQUIRE_ASYNC_SIGNAL_SAFE ((MPIABI_T_cb_safety))
!
! #endif // #ifndef MPIABI_CONSTANTS_H
