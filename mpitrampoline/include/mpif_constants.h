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

!     Status array size and reserved index values

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

!     Communicator split type constants

      integer MPI_COMM_TYPE_SHARED
      parameter (MPI_COMM_TYPE_SHARED = MPIABI_COMM_TYPE_SHARED)
      integer MPI_COMM_TYPE_HW_UNGUIDED
      parameter (MPI_COMM_TYPE_HW_UNGUIDED =                            &
     &     MPIABI_COMM_TYPE_HW_UNGUIDED)
      integer MPI_COMM_TYPE_HW_GUIDED
      parameter (MPI_COMM_TYPE_HW_GUIDED = MPIABI_COMM_TYPE_HW_GUIDED)
      integer MPI_COMM_TYPE_RESOURCE_GUIDED
      parameter (MPI_COMM_TYPE_RESOURCE_GUIDED =                        &
     &     MPIABI_COMM_TYPE_RESOURCE_GUIDED)

!     Results of communicator and group comparisons

      integer MPI_IDENT
      parameter (MPI_IDENT = MPIABI_IDENT)
      integer MPI_CONGRUENT
      parameter (MPI_CONGRUENT = MPIABI_CONGRUENT)
      integer MPI_SIMILAR
      parameter (MPI_SIMILAR = MPIABI_SIMILAR)
      integer MPI_UNEQUAL
      parameter (MPI_UNEQUAL = MPIABI_UNEQUAL)

!     Environmental inquiry info key

      integer MPI_INFO_ENV
      parameter (MPI_INFO_ENV = MPIABI_INFO_ENV)

!     Environmental inquiry keys

      integer MPI_TAG_UB
      parameter (MPI_TAG_UB = MPIABI_TAG_UB)
      integer MPI_IO
      parameter (MPI_IO = MPIABI_IO)
      integer MPI_HOST
      parameter (MPI_HOST = MPIABI_HOST)
      integer MPI_WTIME_IS_GLOBAL
      parameter (MPI_WTIME_IS_GLOBAL = MPIABI_WTIME_IS_GLOBAL)

!  Collective Operations

      integer MPI_MAX
      parameter (MPI_MAX = MPIABI_MAX)
      integer MPI_MIN
      parameter (MPI_MIN = MPIABI_MIN)
      integer MPI_SUM
      parameter (MPI_SUM = MPIABI_SUM)
      integer MPI_PROD
      parameter (MPI_PROD = MPIABI_PROD)
      integer MPI_MAXLOC
      parameter (MPI_MAXLOC = MPIABI_MAXLOC)
      integer MPI_MINLOC
      parameter (MPI_MINLOC = MPIABI_MINLOC)
      integer MPI_BAND
      parameter (MPI_BAND = MPIABI_BAND)
      integer MPI_BOR
      parameter (MPI_BOR = MPIABI_BOR)
      integer MPI_BXOR
      parameter (MPI_BXOR = MPIABI_BXOR)
      integer MPI_LAND
      parameter (MPI_LAND = MPIABI_LAND)
      integer MPI_LOR
      parameter (MPI_LOR = MPIABI_LOR)
      integer MPI_LXOR
      parameter (MPI_LXOR = MPIABI_LXOR)
      integer MPI_REPLACE
      parameter (MPI_REPLACE = MPIABI_REPLACE)
      integer MPI_NO_OP
      parameter (MPI_NO_OP = MPIABI_NO_OP)

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

!     Topologies

      integer MPI_GRAPH
      parameter (MPI_GRAPH = MPIABI_GRAPH)
      integer MPI_CART
      parameter (MPI_CART = MPIABI_CART)
      integer MPI_DIST_GRAPH
      parameter (MPI_DIST_GRAPH = MPIABI_DIST_GRAPH)

!     Predefined functions

!     MPI_COMM_NULL_COPY_FN
!     MPI_COMM_DUP_FN
!     MPI_COMM_NULL_DELETE_FN

!     MPIABI_WIN_NULL_COPY_FN
!     MPIABI_WIN_DUP_FN
!     MPIABI_WIN_NULL_DELETE_FN
!
!     MPIABI_TYPE_NULL_COPY_FN
!     MPIABI_TYPE_DUP_FN
!     MPIABI_TYPE_NULL_DELETE_FN
!
!     MPIABI_CONVERSION_FN_NULL
!     MPIABI_CONVERSION_FN_NULL_C

!     Deprecated predefined functions
!
!     MPIABI_NULL_COPY_FN
!     MPIABI_DUP_FN
!     MPIABI_NULL_DELETE_FN

!     Predefined Attribute Keys

      integer MPI_APPNUM
      parameter (MPI_APPNUM = MPIABI_APPNUM)
      integer MPI_LASTUSEDCODE
      parameter (MPI_LASTUSEDCODE = MPIABI_LASTUSEDCODE)
      integer MPI_UNIVERSE_SIZE
      parameter (MPI_UNIVERSE_SIZE = MPIABI_UNIVERSE_SIZE)
      integer MPI_WIN_BASE
      parameter (MPI_WIN_BASE = MPIABI_WIN_BASE)
      integer MPI_WIN_DISP_UNIT
      parameter (MPI_WIN_DISP_UNIT = MPIABI_WIN_DISP_UNIT)
      integer MPI_WIN_SIZE
      parameter (MPI_WIN_SIZE = MPIABI_WIN_SIZE)
      integer MPI_WIN_CREATE_FLAVOR
      parameter (MPI_WIN_CREATE_FLAVOR = MPIABI_WIN_CREATE_FLAVOR)
      integer MPI_WIN_MODEL
      parameter (MPI_WIN_MODEL = MPIABI_WIN_MODEL)

!     MPI Window Create Flavors

      integer MPI_WIN_FLAVOR_CREATE
      parameter (MPI_WIN_FLAVOR_CREATE = MPIABI_WIN_FLAVOR_CREATE)
      integer MPI_WIN_FLAVOR_ALLOCATE
      parameter (MPI_WIN_FLAVOR_ALLOCATE = MPIABI_WIN_FLAVOR_ALLOCATE)
      integer MPI_WIN_FLAVOR_DYNAMIC
      parameter (MPI_WIN_FLAVOR_DYNAMIC = MPIABI_WIN_FLAVOR_DYNAMIC)
      integer MPI_WIN_FLAVOR_SHARED
      parameter (MPI_WIN_FLAVOR_SHARED = MPIABI_WIN_FLAVOR_SHARED)

!     MPI Window Models

      integer MPI_WIN_SEPARATE
      parameter (MPI_WIN_SEPARATE = MPIABI_WIN_SEPARATE)
      integer MPI_WIN_UNIFIED
      parameter (MPI_WIN_UNIFIED = MPIABI_WIN_UNIFIED)

!     Mode Constants

      integer MPI_MODE_APPEND
      parameter (MPI_MODE_APPEND = MPIABI_MODE_APPEND)
      integer MPI_MODE_CREATE
      parameter (MPI_MODE_CREATE = MPIABI_MODE_CREATE)
      integer MPI_MODE_DELETE_ON_CLOSE
      parameter (MPI_MODE_DELETE_ON_CLOSE = MPIABI_MODE_DELETE_ON_CLOSE)
      integer MPI_MODE_EXCL
      parameter (MPI_MODE_EXCL = MPIABI_MODE_EXCL)
      integer MPI_MODE_NOCHECK
      parameter (MPI_MODE_NOCHECK = MPIABI_MODE_NOCHECK)
      integer MPI_MODE_NOPRECEDE
      parameter (MPI_MODE_NOPRECEDE = MPIABI_MODE_NOPRECEDE)
      integer MPI_MODE_NOPUT
      parameter (MPI_MODE_NOPUT = MPIABI_MODE_NOPUT)
      integer MPI_MODE_NOSTORE
      parameter (MPI_MODE_NOSTORE = MPIABI_MODE_NOSTORE)
      integer MPI_MODE_NOSUCCEED
      parameter (MPI_MODE_NOSUCCEED = MPIABI_MODE_NOSUCCEED)
      integer MPI_MODE_RDONLY
      parameter (MPI_MODE_RDONLY = MPIABI_MODE_RDONLY)
      integer MPI_MODE_RDWR
      parameter (MPI_MODE_RDWR = MPIABI_MODE_RDWR)
      integer MPI_MODE_SEQUENTIAL
      parameter (MPI_MODE_SEQUENTIAL = MPIABI_MODE_SEQUENTIAL)
      integer MPI_MODE_UNIQUE_OPEN
      parameter (MPI_MODE_UNIQUE_OPEN = MPIABI_MODE_UNIQUE_OPEN)
      integer MPI_MODE_WRONLY
      parameter (MPI_MODE_WRONLY = MPIABI_MODE_WRONLY)

!     Datatype Decoding Constants

      integer MPI_COMBINER_CONTIGUOUS
      parameter (MPI_COMBINER_CONTIGUOUS = MPIABI_COMBINER_CONTIGUOUS)
      integer MPI_COMBINER_DARRAY
      parameter (MPI_COMBINER_DARRAY = MPIABI_COMBINER_DARRAY)
      integer MPI_COMBINER_DUP
      parameter (MPI_COMBINER_DUP = MPIABI_COMBINER_DUP)
      integer MPI_COMBINER_F90_COMPLEX
      parameter (MPI_COMBINER_F90_COMPLEX = MPIABI_COMBINER_F90_COMPLEX)
      integer MPI_COMBINER_F90_INTEGER
      parameter (MPI_COMBINER_F90_INTEGER = MPIABI_COMBINER_F90_INTEGER)
      integer MPI_COMBINER_F90_REAL
      parameter (MPI_COMBINER_F90_REAL = MPIABI_COMBINER_F90_REAL)
      integer MPI_COMBINER_HINDEXED
      parameter (MPI_COMBINER_HINDEXED = MPIABI_COMBINER_HINDEXED)
      integer MPI_COMBINER_HVECTOR
      parameter (MPI_COMBINER_HVECTOR = MPIABI_COMBINER_HVECTOR)
      integer MPI_COMBINER_INDEXED_BLOCK
      parameter (MPI_COMBINER_INDEXED_BLOCK =                           &
     &     MPIABI_COMBINER_INDEXED_BLOCK)
      integer MPI_COMBINER_HINDEXED_BLOCK
      parameter (MPI_COMBINER_HINDEXED_BLOCK =                          &
     &     MPIABI_COMBINER_HINDEXED_BLOCK)
      integer MPI_COMBINER_INDEXED
      parameter (MPI_COMBINER_INDEXED = MPIABI_COMBINER_INDEXED)
      integer MPI_COMBINER_NAMED
      parameter (MPI_COMBINER_NAMED = MPIABI_COMBINER_NAMED)
      integer MPI_COMBINER_RESIZED
      parameter (MPI_COMBINER_RESIZED = MPIABI_COMBINER_RESIZED)
      integer MPI_COMBINER_STRUCT
      parameter (MPI_COMBINER_STRUCT = MPIABI_COMBINER_STRUCT)
      integer MPI_COMBINER_SUBARRAY
      parameter (MPI_COMBINER_SUBARRAY = MPIABI_COMBINER_SUBARRAY)
      integer MPI_COMBINER_VECTOR
      parameter (MPI_COMBINER_VECTOR = MPIABI_COMBINER_VECTOR)

!     Threads Constants

      integer MPI_THREAD_FUNNELED
      parameter (MPI_THREAD_FUNNELED = MPIABI_THREAD_FUNNELED)
      integer MPI_THREAD_MULTIPLE
      parameter (MPI_THREAD_MULTIPLE = MPIABI_THREAD_MULTIPLE)
      integer MPI_THREAD_SERIALIZED
      parameter (MPI_THREAD_SERIALIZED = MPIABI_THREAD_SERIALIZED)
      integer MPI_THREAD_SINGLE
      parameter (MPI_THREAD_SINGLE = MPIABI_THREAD_SINGLE)

!     File Operation Constants, Part 1

      integer MPI_DISPLACEMENT_CURRENT
      parameter (MPI_DISPLACEMENT_CURRENT = MPIABI_DISPLACEMENT_CURRENT)

!     File Operation Constants, Part 2

      integer MPI_DISTRIBUTE_BLOCK
      parameter (MPI_DISTRIBUTE_BLOCK = MPIABI_DISTRIBUTE_BLOCK)
      integer MPI_DISTRIBUTE_CYCLIC
      parameter (MPI_DISTRIBUTE_CYCLIC = MPIABI_DISTRIBUTE_CYCLIC)
      integer MPI_DISTRIBUTE_DFLT_DARG
      parameter (MPI_DISTRIBUTE_DFLT_DARG = MPIABI_DISTRIBUTE_DFLT_DARG)
      integer MPI_DISTRIBUTE_NONE
      parameter (MPI_DISTRIBUTE_NONE = MPIABI_DISTRIBUTE_NONE)
      integer MPI_ORDER_C
      parameter (MPI_ORDER_C = MPIABI_ORDER_C)
      integer MPI_ORDER_FORTRAN
      parameter (MPI_ORDER_FORTRAN = MPIABI_ORDER_FORTRAN)
      integer MPI_SEEK_CUR
      parameter (MPI_SEEK_CUR = MPIABI_SEEK_CUR)
      integer MPI_SEEK_END
      parameter (MPI_SEEK_END = MPIABI_SEEK_END)
      integer MPI_SEEK_SET
      parameter (MPI_SEEK_SET = MPIABI_SEEK_SET)

!     F90 Datatype Matching Constants

      integer MPI_TYPECLASS_COMPLEX
      parameter (MPI_TYPECLASS_COMPLEX = MPIABI_TYPECLASS_COMPLEX)
      integer MPI_TYPECLASS_INTEGER
      parameter (MPI_TYPECLASS_INTEGER = MPIABI_TYPECLASS_INTEGER)
      integer MPI_TYPECLASS_REAL
      parameter (MPI_TYPECLASS_REAL = MPIABI_TYPECLASS_REAL)

!     Constants Specifying Empty or Ignored Input

      integer MPI_ARGVS_NULL
      pointer (MPIABI_ARGVS_NULL_PTR, MPI_ARGVS_NULL)
      integer MPI_ARGV_NULL
      pointer (MPIABI_ARGV_NULL_PTR, MPI_ARGV_NULL)
      integer MPI_ERRCODES_IGNORE
      pointer (MPIABI_ERRCODES_IGNORE_PTR, MPI_ERRCODES_IGNORE)
      integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE)
      pointer (MPIABI_STATUSES_IGNORE_PTR, MPI_STATUSES_IGNORE)
      integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
      pointer (MPIABI_STATUS_IGNORE_PTR, MPI_STATUS_IGNORE)
      integer MPI_UNWEIGHTED
      pointer (MPIABI_UNWEIGHTED_PTR, MPI_UNWEIGHTED)
      integer MPI_WEIGHTS_EMPTY
      pointer (MPIABI_WEIGHTS_EMPTY_PTR, MPI_WEIGHTS_EMPTY)

!     C Constants Specifying Ignored Input (no Fortran)

!     C preprocessor Constants and Fortran Parameters

      integer MPI_SUBVERSION
      parameter (MPI_SUBVERSION = MPIABI_SUBVERSION)
      integer MPI_VERSION
      parameter (MPI_VERSION = MPIABI_VERSION)
