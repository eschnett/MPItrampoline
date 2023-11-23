!     Define MPIABI constants

!     A.1.1 Defined Constants

!     Variable Address Size
!     Define these first because they are used in other definitions.

      integer MPIABI_INTEGER_DUMMY
      parameter (MPIABI_INTEGER_DUMMY = 0)
      integer MPIABI_ADDRESS_KIND
      parameter (MPIABI_ADDRESS_KIND = kind(loc(MPIABI_INTEGER_DUMMY)))
      integer MPIABI_COUNT_KIND
      parameter (MPIABI_COUNT_KIND = MPIABI_ADDRESS_KIND)
      integer MPIABI_INTEGER_KIND
      parameter (MPIABI_INTEGER_KIND = kind(0))
      integer MPIABI_OFFSET_KIND
      parameter (MPIABI_OFFSET_KIND = MPIABI_ADDRESS_KIND)

!     Error classes

      integer MPIABI_SUCCESS
      parameter (MPIABI_SUCCESS = 0)
      integer MPIABI_ERR_BUFFER
      parameter (MPIABI_ERR_BUFFER = 1)
      integer MPIABI_ERR_COUNT
      parameter (MPIABI_ERR_COUNT = 2)
      integer MPIABI_ERR_TYPE
      parameter (MPIABI_ERR_TYPE = 3)
      integer MPIABI_ERR_TAG
      parameter (MPIABI_ERR_TAG = 4)
      integer MPIABI_ERR_COMM
      parameter (MPIABI_ERR_COMM = 5)
      integer MPIABI_ERR_RANK
      parameter (MPIABI_ERR_RANK = 6)
      integer MPIABI_ERR_REQUEST
      parameter (MPIABI_ERR_REQUEST = 7)
      integer MPIABI_ERR_ROOT
      parameter (MPIABI_ERR_ROOT = 8)
      integer MPIABI_ERR_GROUP
      parameter (MPIABI_ERR_GROUP = 9)
      integer MPIABI_ERR_OP
      parameter (MPIABI_ERR_OP = 10)
      integer MPIABI_ERR_TOPOLOGY
      parameter (MPIABI_ERR_TOPOLOGY = 11)
      integer MPIABI_ERR_DIMS
      parameter (MPIABI_ERR_DIMS = 12)
      integer MPIABI_ERR_ARG
      parameter (MPIABI_ERR_ARG = 13)
      integer MPIABI_ERR_UNKNOWN
      parameter (MPIABI_ERR_UNKNOWN = 14)
      integer MPIABI_ERR_TRUNCATE
      parameter (MPIABI_ERR_TRUNCATE = 15)
      integer MPIABI_ERR_OTHER
      parameter (MPIABI_ERR_OTHER = 16)
      integer MPIABI_ERR_INTERN
      parameter (MPIABI_ERR_INTERN = 17)
      integer MPIABI_ERR_PENDING
      parameter (MPIABI_ERR_PENDING = 18)
      integer MPIABI_ERR_IN_STATUS
      parameter (MPIABI_ERR_IN_STATUS = 19)
      integer MPIABI_ERR_ACCESS
      parameter (MPIABI_ERR_ACCESS = 20)
      integer MPIABI_ERR_AMODE
      parameter (MPIABI_ERR_AMODE = 21)
      integer MPIABI_ERR_ASSERT
      parameter (MPIABI_ERR_ASSERT = 22)
      integer MPIABI_ERR_BAD_FILE
      parameter (MPIABI_ERR_BAD_FILE = 23)
      integer MPIABI_ERR_BASE
      parameter (MPIABI_ERR_BASE = 24)
      integer MPIABI_ERR_CONVERSION
      parameter (MPIABI_ERR_CONVERSION = 25)
      integer MPIABI_ERR_DISP
      parameter (MPIABI_ERR_DISP = 26)
      integer MPIABI_ERR_DUP_DATAREP
      parameter (MPIABI_ERR_DUP_DATAREP = 27)
      integer MPIABI_ERR_FILE_EXISTS
      parameter (MPIABI_ERR_FILE_EXISTS = 28)
      integer MPIABI_ERR_FILE_IN_USE
      parameter (MPIABI_ERR_FILE_IN_USE = 29)
      integer MPIABI_ERR_FILE
      parameter (MPIABI_ERR_FILE = 30)
      integer MPIABI_ERR_INFO_KEY
      parameter (MPIABI_ERR_INFO_KEY = 31)
      integer MPIABI_ERR_INFO_NOKEY
      parameter (MPIABI_ERR_INFO_NOKEY = 32)
      integer MPIABI_ERR_INFO_VALUE
      parameter (MPIABI_ERR_INFO_VALUE = 33)
      integer MPIABI_ERR_INFO
      parameter (MPIABI_ERR_INFO = 34)
      integer MPIABI_ERR_IO
      parameter (MPIABI_ERR_IO = 35)
      integer MPIABI_ERR_KEYVAL
      parameter (MPIABI_ERR_KEYVAL = 36)
      integer MPIABI_ERR_LOCKTYPE
      parameter (MPIABI_ERR_LOCKTYPE = 37)
      integer MPIABI_ERR_NAME
      parameter (MPIABI_ERR_NAME = 38)
      integer MPIABI_ERR_NO_MEM
      parameter (MPIABI_ERR_NO_MEM = 39)
      integer MPIABI_ERR_NOT_SAME
      parameter (MPIABI_ERR_NOT_SAME = 40)
      integer MPIABI_ERR_NO_SPACE
      parameter (MPIABI_ERR_NO_SPACE = 41)
      integer MPIABI_ERR_NO_SUCH_FILE
      parameter (MPIABI_ERR_NO_SUCH_FILE = 42)
      integer MPIABI_ERR_PORT
      parameter (MPIABI_ERR_PORT = 43)
      integer MPIABI_ERR_PROC_ABORTED
      parameter (MPIABI_ERR_PROC_ABORTED = 44)
      integer MPIABI_ERR_QUOTA
      parameter (MPIABI_ERR_QUOTA = 45)
      integer MPIABI_ERR_READ_ONLY
      parameter (MPIABI_ERR_READ_ONLY = 46)
      integer MPIABI_ERR_RMA_ATTACH
      parameter (MPIABI_ERR_RMA_ATTACH = 47)
      integer MPIABI_ERR_RMA_CONFLICT
      parameter (MPIABI_ERR_RMA_CONFLICT = 48)
      integer MPIABI_ERR_RMA_RANGE
      parameter (MPIABI_ERR_RMA_RANGE = 49)
      integer MPIABI_ERR_RMA_SHARED
      parameter (MPIABI_ERR_RMA_SHARED = 50)
      integer MPIABI_ERR_RMA_SYNC
      parameter (MPIABI_ERR_RMA_SYNC = 51)
      integer MPIABI_ERR_RMA_FLAVOR
      parameter (MPIABI_ERR_RMA_FLAVOR = 52)
      integer MPIABI_ERR_SERVICE
      parameter (MPIABI_ERR_SERVICE = 53)
      integer MPIABI_ERR_SESSION
      parameter (MPIABI_ERR_SESSION = 54)
      integer MPIABI_ERR_SIZE
      parameter (MPIABI_ERR_SIZE = 55)
      integer MPIABI_ERR_SPAWN
      parameter (MPIABI_ERR_SPAWN = 56)
      integer MPIABI_ERR_UNSUPPORTED_DATAREP
      parameter (MPIABI_ERR_UNSUPPORTED_DATAREP = 57)
      integer MPIABI_ERR_UNSUPPORTED_OPERATION
      parameter (MPIABI_ERR_UNSUPPORTED_OPERATION = 58)
      integer MPIABI_ERR_VALUE_TOO_LARGE
      parameter (MPIABI_ERR_VALUE_TOO_LARGE = 59)
      integer MPIABI_ERR_WIN
      parameter (MPIABI_ERR_WIN = 60)
      integer MPIABI_ERR_ERRHANDLER
      parameter (MPIABI_ERR_ERRHANDLER = 61)
      integer MPIABI_T_ERR_CANNOT_INIT
      parameter (MPIABI_T_ERR_CANNOT_INIT = 1000)
      integer MPIABI_T_ERR_NOT_ACCESSIBLE
      parameter (MPIABI_T_ERR_NOT_ACCESSIBLE = 1001)
      integer MPIABI_T_ERR_NOT_INITIALIZED
      parameter (MPIABI_T_ERR_NOT_INITIALIZED = 1002)
      integer MPIABI_T_ERR_NOT_SUPPORTED
      parameter (MPIABI_T_ERR_NOT_SUPPORTED = 1003)
      integer MPIABI_T_ERR_MEMORY
      parameter (MPIABI_T_ERR_MEMORY = 1004)
      integer MPIABI_T_ERR_INVALID
      parameter (MPIABI_T_ERR_INVALID = 1005)
      integer MPIABI_T_ERR_INVALID_INDEX
      parameter (MPIABI_T_ERR_INVALID_INDEX = 1006)
      integer MPIABI_T_ERR_INVALID_ITEM
      parameter (MPIABI_T_ERR_INVALID_ITEM = 1007)
      integer MPIABI_T_ERR_INVALID_SESSION
      parameter (MPIABI_T_ERR_INVALID_SESSION = 1008)
      integer MPIABI_T_ERR_INVALID_HANDLE
      parameter (MPIABI_T_ERR_INVALID_HANDLE = 1009)
      integer MPIABI_T_ERR_INVALID_NAME
      parameter (MPIABI_T_ERR_INVALID_NAME = 1010)
      integer MPIABI_T_ERR_OUT_OF_HANDLES
      parameter (MPIABI_T_ERR_OUT_OF_HANDLES = 1011)
      integer MPIABI_T_ERR_OUT_OF_SESSIONS
      parameter (MPIABI_T_ERR_OUT_OF_SESSIONS = 1012)
      integer MPIABI_T_ERR_CVAR_SET_NOT_NOW
      parameter (MPIABI_T_ERR_CVAR_SET_NOT_NOW = 1013)
      integer MPIABI_T_ERR_CVAR_SET_NEVER
      parameter (MPIABI_T_ERR_CVAR_SET_NEVER = 1014)
      integer MPIABI_T_ERR_PVAR_NO_WRITE
      parameter (MPIABI_T_ERR_PVAR_NO_WRITE = 1015)
      integer MPIABI_T_ERR_PVAR_NO_STARTSTOP
      parameter (MPIABI_T_ERR_PVAR_NO_STARTSTOP = 1016)
      integer MPIABI_T_ERR_PVAR_NO_ATOMIC
      parameter (MPIABI_T_ERR_PVAR_NO_ATOMIC = 1017)
      integer MPIABI_ERR_LASTCODE
      parameter (MPIABI_ERR_LASTCODE = 16383)

!     Buffer Address Constants

!     We use Cray pointers to handle sentinel values. Unfortunately
!     these might not be supported everywhere, and if they are, they
!     require special compiler options.
      integer MPIABI_BOTTOM(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_BOTTOM_PTR
      pointer (MPIABI_BOTTOM_PTR, MPIABI_BOTTOM)
      common /MPIABI_BOTTOM_PTR/ MPIABI_BOTTOM_PTR
      integer MPIABI_BUFFER_AUTOMATIC(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_BUFFER_AUTOMATIC_PTR
      pointer (MPIABI_BUFFER_AUTOMATIC_PTR, MPIABI_BUFFER_AUTOMATIC)
      common /MPIABI_BUFFER_AUTOMATIC_PTR/ MPIABI_BUFFER_AUTOMATIC_PTR
      integer MPIABI_IN_PLACE(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_IN_PLACE_PTR
      pointer (MPIABI_IN_PLACE_PTR, MPIABI_IN_PLACE)
      common /MPIABI_IN_PLACE_PTR/ MPIABI_IN_PLACE_PTR

!     Assorted Constants

      integer MPIABI_PROC_NULL
      parameter (MPIABI_PROC_NULL = -2)
      integer MPIABI_ANY_SOURCE
      parameter (MPIABI_ANY_SOURCE = -1)
      integer MPIABI_ANY_TAG
      parameter (MPIABI_ANY_TAG = -101)
      integer MPIABI_UNDEFINED
      parameter (MPIABI_UNDEFINED = -601)
      integer MPIABI_BSEND_OVERHEAD
      parameter (MPIABI_BSEND_OVERHEAD = 512)
      integer MPIABI_KEYVAL_INVALID
      parameter (MPIABI_KEYVAL_INVALID = -401)
      integer MPIABI_LOCK_EXCLUSIVE
      parameter (MPIABI_LOCK_EXCLUSIVE = -901)
      integer MPIABI_LOCK_SHARED
      parameter (MPIABI_LOCK_SHARED = -902)
      integer MPIABI_ROOT
      parameter (MPIABI_ROOT = -3)

!     No Process Message Handle

      integer MPIABI_MESSAGE_NO_PROC
      parameter (MPIABI_MESSAGE_NO_PROC = int(b'000100010101'))

!     Fortran Support Method Specific Constants

      logical MPIABI_SUBARRAYS_SUPPORTED
      parameter (MPIABI_SUBARRAYS_SUPPORTED = .false.)
      logical MPIABI_ASYNC_PROTECTS_NONBLOCKING
      parameter (MPIABI_ASYNC_PROTECTS_NONBLOCKING = .false.)

!     / Status array size and reserved index values

      integer MPIABI_STATUS_SIZE
      parameter (MPIABI_STATUS_SIZE = 8)
      integer MPIABI_SOURCE
      parameter (MPIABI_SOURCE = 1)
      integer MPIABI_TAG
      parameter (MPIABI_TAG = 2)
      integer MPIABI_ERROR
      parameter (MPIABI_ERROR = 3)

!     Fortran status array size and reserved index values

!     Variable Address Size
!     These have already been defined above.

!     Error-handling specifiers

      integer MPIABI_ERRORS_ARE_FATAL
      parameter (MPIABI_ERRORS_ARE_FATAL = int(b'000100011001'))
      integer MPIABI_ERRORS_ABORT
      parameter (MPIABI_ERRORS_ABORT = int(b'000100011011'))
      integer MPIABI_ERRORS_RETURN
      parameter (MPIABI_ERRORS_RETURN = int(b'000100011010'))

!     Maximum Sizes for Strings

      integer MPIABI_MAX_DATAREP_STRING
      parameter (MPIABI_MAX_DATAREP_STRING = 128 - 1)
      integer MPIABI_MAX_ERROR_STRING
      parameter (MPIABI_MAX_ERROR_STRING = 512 - 1)
      integer MPIABI_MAX_INFO_KEY
      parameter (MPIABI_MAX_INFO_KEY = 255 - 1)
      integer MPIABI_MAX_INFO_VAL
      parameter (MPIABI_MAX_INFO_VAL = 1024 - 1)
      integer MPIABI_MAX_LIBRARY_VERSION_STRING
      parameter (MPIABI_MAX_LIBRARY_VERSION_STRING = 8192 - 1)
      integer MPIABI_MAX_OBJECT_NAME
      parameter (MPIABI_MAX_OBJECT_NAME = 128 - 1)
      integer MPIABI_MAX_PORT_NAME
      parameter (MPIABI_MAX_PORT_NAME = 1024 - 1)
      integer MPIABI_MAX_PROCESSOR_NAME
      parameter (MPIABI_MAX_PROCESSOR_NAME = 256 - 1)
      integer MPIABI_MAX_PSET_NAME_LEN
      parameter (MPIABI_MAX_PSET_NAME_LEN = 256 - 1)
      integer MPIABI_MAX_STRINGTAG_LEN
      parameter (MPIABI_MAX_STRINGTAG_LEN = 256 - 1)

!     Named Predefined Datatypes

!     [C types]

      integer MPIABI_CHAR
      parameter (MPIABI_CHAR = int(b'001001000011'))
      integer MPIABI_SHORT
      parameter (MPIABI_SHORT = int(b'001000001000'))
      integer MPIABI_INT
      parameter (MPIABI_INT = int(b'001000001001'))
      integer MPIABI_LONG
      parameter (MPIABI_LONG = int(b'001000001010'))
      integer MPIABI_LONG_LONG_INT
      parameter (MPIABI_LONG_LONG_INT = int(b'001000001011'))
      integer MPIABI_LONG_LONG
      parameter (MPIABI_LONG_LONG = MPIABI_LONG_LONG_INT)
      integer MPIABI_SIGNED_CHAR
      parameter (MPIABI_SIGNED_CHAR = int(b'001001000100'))
      integer MPIABI_UNSIGNED_CHAR
      parameter (MPIABI_UNSIGNED_CHAR = int(b'001001000101'))
      integer MPIABI_UNSIGNED_SHORT
      parameter (MPIABI_UNSIGNED_SHORT = int(b'001000001100'))
      integer MPIABI_UNSIGNED
      parameter (MPIABI_UNSIGNED = int(b'001000001101'))
      integer MPIABI_UNSIGNED_LONG
      parameter (MPIABI_UNSIGNED_LONG = int(b'001000001110'))
      integer MPIABI_UNSIGNED_LONG_LONG
      parameter (MPIABI_UNSIGNED_LONG_LONG = int(b'001000001111'))
      integer MPIABI_FLOAT
      parameter (MPIABI_FLOAT = int(b'001001010010'))
      integer MPIABI_DOUBLE
      parameter (MPIABI_DOUBLE = int(b'001001011010'))
      integer MPIABI_LONG_DOUBLE
      parameter (MPIABI_LONG_DOUBLE = int(b'001000100000'))
      integer MPIABI_WCHAR
      parameter (MPIABI_WCHAR = int(b'001000111100'))
      integer MPIABI_C_BOOL
      parameter (MPIABI_C_BOOL = int(b'001000111000'))
      integer MPIABI_INT8_T
      parameter (MPIABI_INT8_T = int(b'001001000000'))
      integer MPIABI_INT16_T
      parameter (MPIABI_INT16_T = int(b'001001001000'))
      integer MPIABI_INT32_T
      parameter (MPIABI_INT32_T = int(b'001001010000'))
      integer MPIABI_INT64_T
      parameter (MPIABI_INT64_T = int(b'001001011000'))
      integer MPIABI_UINT8_T
      parameter (MPIABI_UINT8_T = int(b'001001000001'))
      integer MPIABI_UINT16_T
      parameter (MPIABI_UINT16_T = int(b'001001001001'))
      integer MPIABI_UINT32_T
      parameter (MPIABI_UINT32_T = int(b'001001010001'))
      integer MPIABI_UINT64_T
      parameter (MPIABI_UINT64_T = int(b'001001011001'))
      integer MPIABI_AINT
      parameter (MPIABI_AINT = int(b'001000000001'))
      integer MPIABI_COUNT
      parameter (MPIABI_COUNT = int(b'001000000010'))
      integer MPIABI_OFFSET
      parameter (MPIABI_OFFSET = int(b'001000000011'))
      integer MPIABI_C_COMPLEX
      parameter (MPIABI_C_COMPLEX = int(b'001001011011'))
      integer MPIABI_C_FLOAT_COMPLEX
      parameter (MPIABI_C_FLOAT_COMPLEX = MPIABI_C_COMPLEX)
      integer MPIABI_C_DOUBLE_COMPLEX
      parameter (MPIABI_C_DOUBLE_COMPLEX = int(b'001000010110'))
      integer MPIABI_C_LONG_DOUBLE_COMPLEX
      parameter (MPIABI_C_LONG_DOUBLE_COMPLEX = int(b'001000100100'))
      integer MPIABI_BYTE
      parameter (MPIABI_BYTE = int(b'001001000111'))
      integer MPIABI_PACKED
      parameter (MPIABI_PACKED = int(b'001000000111'))

!     [Fortran types]

      integer MPIABI_INTEGER
      parameter (MPIABI_INTEGER = int(b'001000011000'))
      integer MPIABI_REAL
      parameter (MPIABI_REAL = int(b'001000011010'))
      integer MPIABI_DOUBLE_PRECISION
      parameter (MPIABI_DOUBLE_PRECISION = int(b'001000011100'))
      integer MPIABI_COMPLEX
      parameter (MPIABI_COMPLEX = int(b'001000011011'))
      integer MPIABI_LOGICAL
      parameter (MPIABI_LOGICAL = int(b'001000011001'))
      integer MPIABI_CHARACTER
      parameter (MPIABI_CHARACTER = int(b'001011000011'))

!     [C++ types]

      integer MPIABI_CXX_BOOL
      parameter (MPIABI_CXX_BOOL = int(b'001000111001'))
      integer MPIABI_CXX_FLOAT_COMPLEX
      parameter (MPIABI_CXX_FLOAT_COMPLEX = int(b'001000010011'))
      integer MPIABI_CXX_DOUBLE_COMPLEX
      parameter (MPIABI_CXX_DOUBLE_COMPLEX = int(b'001000010111'))
      integer MPIABI_CXX_LONG_DOUBLE_COMPLEX
      parameter (MPIABI_CXX_LONG_DOUBLE_COMPLEX = int(b'001000100101'))

!     [Optional datatypes (Fortran)]

      integer MPIABI_DOUBLE_COMPLEX
      parameter (MPIABI_DOUBLE_COMPLEX = int(b'001000011101'))
      integer MPIABI_INTEGER1
      parameter (MPIABI_INTEGER1 = int(b'001011000000')) 
      integer MPIABI_INTEGER2
      parameter (MPIABI_INTEGER2 = int(b'001011001000'))  
      integer MPIABI_INTEGER4
      parameter (MPIABI_INTEGER4 = int(b'001011010000'))  
      integer MPIABI_INTEGER8
      parameter (MPIABI_INTEGER8 = int(b'001011011000'))  
      integer MPIABI_INTEGER16
      parameter (MPIABI_INTEGER16 = int(b'001011100000')) 
      integer MPIABI_REAL2
      parameter (MPIABI_REAL2 = int(b'001011001010'))     
      integer MPIABI_REAL4
      parameter (MPIABI_REAL4 = int(b'001011010010'))     
      integer MPIABI_REAL8
      parameter (MPIABI_REAL8 = int(b'001011011010'))     
      integer MPIABI_REAL16
      parameter (MPIABI_REAL16 = int(b'001000100010'))    
      integer MPIABI_COMPLEX4
      parameter (MPIABI_COMPLEX4 = int(b'001011010011'))  
      integer MPIABI_COMPLEX8
      parameter (MPIABI_COMPLEX8 = int(b'001011011011'))  
      integer MPIABI_COMPLEX16
      parameter (MPIABI_COMPLEX16 = int(b'001011100011')) 
      integer MPIABI_COMPLEX32
      parameter (MPIABI_COMPLEX32 = int(b'001011101011')) 

!     [Extensions]

      integer MPIABI_REAL1
      parameter (MPIABI_REAL1 = int(b'001011000010'))     
      integer MPIABI_COMPLEX2
      parameter (MPIABI_COMPLEX2 = int(b'001011001011'))  
      integer MPIABI_LOGICAL1
      parameter (MPIABI_LOGICAL1 = int(b'001011000001'))  
      integer MPIABI_LOGICAL2
      parameter (MPIABI_LOGICAL2 = int(b'001011001001'))  
      integer MPIABI_LOGICAL4
      parameter (MPIABI_LOGICAL4 = int(b'001011010001'))  
      integer MPIABI_LOGICAL8
      parameter (MPIABI_LOGICAL8 = int(b'001011011001'))  
      integer MPIABI_LOGICAL16
      parameter (MPIABI_LOGICAL16 = int(b'001011100001')) 

!     [Datatypes for reduction functions (C)]

      integer MPIABI_FLOAT_INT
      parameter (MPIABI_FLOAT_INT = int(b'001000101000'))  
      integer MPIABI_DOUBLE_INT
      parameter (MPIABI_DOUBLE_INT = int(b'001000101001')) 
      integer MPIABI_LONG_INT
      parameter (MPIABI_LONG_INT = int(b'001000101010'))   
      integer MPIABI_2INT
      parameter (MPIABI_2INT = int(b'001000101011'))       
      integer MPIABI_SHORT_INT
      parameter (MPIABI_SHORT_INT = int(b'001000101100'))  
      integer MPIABI_LONG_DOUBLE_INT
      parameter (MPIABI_LONG_DOUBLE_INT = int(b'001000101101'))

!     [Datatypes for reduction functions (Fortran)]

      integer MPIABI_2REAL
      parameter (MPIABI_2REAL = int(b'001000110000'))
      integer MPIABI_2DOUBLE_PRECISION
      parameter (MPIABI_2DOUBLE_PRECISION = int(b'001000110001'))
      integer MPIABI_2INTEGER
      parameter (MPIABI_2integer = int(b'001000110010'))

!     [Removed constructs]

!     [nonstandard]
      integer MPIABI_LB
      parameter (MPIABI_LB = int(b'001000000100'))
!     [nonstandard]
      integer MPIABI_UB
      parameter (MPIABI_UB = int(b'001000000101'))

!     Reserved communicators

      integer MPIABI_COMM_WORLD
      parameter (MPIABI_COMM_WORLD = int(b'000100000001'))
      integer MPIABI_COMM_SELF
      parameter (MPIABI_COMM_SELF = int(b'000100000010'))

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

      integer MPIABI_GROUP_NULL
      parameter (MPIABI_GROUP_NULL = int(b'000100000100'))
      integer MPIABI_COMM_NULL
      parameter (MPIABI_COMM_NULL = int(b'000100000000'))
      integer MPIABI_DATATYPE_NULL
      parameter (MPIABI_DATATYPE_NULL = int(b'001000000000'))
      integer MPIABI_REQUEST_NULL
      parameter (MPIABI_REQUEST_NULL = int(b'000100100000'))
      integer MPIABI_OP_NULL
      parameter (MPIABI_OP_NULL = int(b'000000100000'))
      integer MPIABI_ERRHANDLER_NULL
      parameter (MPIABI_ERRHANDLER_NULL = int(b'000100011000'))
      integer MPIABI_FILE_NULL
      parameter (MPIABI_FILE_NULL = int(b'000100001100'))
      integer MPIABI_INFO_NULL
      parameter (MPIABI_INFO_NULL = int(b'000100110000'))
      integer MPIABI_SESSION_NULL
      parameter (MPIABI_SESSION_NULL = int(b'000100010000'))
      integer MPIABI_WIN_NULL
      parameter (MPIABI_WIN_NULL = int(b'000100001000'))
      integer MPIABI_MESSAGE_NULL
      parameter (MPIABI_MESSAGE_NULL = int(b'000100010100'))

!     Empty group

      integer MPIABI_GROUP_EMPTY
      parameter (MPIABI_GROUP_EMPTY = int(b'000100000101'))

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

      integer MPIABI_ARGVS_NULL(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_ARGVS_NULL_PTR
      pointer (MPIABI_ARGVS_NULL_PTR, MPIABI_ARGVS_NULL)
      common /MPIABI_ARGVS_NULL_PTR/ MPIABI_ARGVS_NULL_PTR
      integer MPIABI_ARGV_NULL(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_ARGV_NULL_PTR
      pointer (MPIABI_ARGV_NULL_PTR, MPIABI_ARGV_NULL)
      common /MPIABI_ARGV_NULL_PTR/ MPIABI_ARGV_NULL_PTR
      integer MPIABI_ERRCODES_IGNORE(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_ERRCODES_IGNORE_PTR
      pointer (MPIABI_ERRCODES_IGNORE_PTR, MPIABI_ERRCODES_IGNORE)
      common /MPIABI_ERRCODES_IGNORE_PTR/ MPIABI_ERRCODES_IGNORE_PTR
      integer MPIABI_STATUSES_IGNORE(MPIABI_STATUS_SIZE)
      integer(MPIABI_ADDRESS_KIND) MPIABI_STATUSES_IGNORE_PTR
      pointer (MPIABI_STATUSES_IGNORE_PTR, MPIABI_STATUSES_IGNORE)
      common /MPIABI_STATUSES_IGNORE_PTR/ MPIABI_STATUSES_IGNORE_PTR
      integer MPIABI_STATUS_IGNORE(MPIABI_STATUS_SIZE)
      integer(MPIABI_ADDRESS_KIND) MPIABI_STATUS_IGNORE_PTR
      pointer (MPIABI_STATUS_IGNORE_PTR, MPIABI_STATUS_IGNORE)
      common /MPIABI_STATUS_IGNORE_PTR/ MPIABI_STATUS_IGNORE_PTR
      integer MPIABI_UNWEIGHTED(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_UNWEIGHTED_PTR
      pointer (MPIABI_UNWEIGHTED_PTR, MPIABI_UNWEIGHTED)
      common /MPIABI_UNWEIGHTED_PTR/ MPIABI_UNWEIGHTED_PTR
      integer MPIABI_WEIGHTS_EMPTY(1)
      integer(MPIABI_ADDRESS_KIND) MPIABI_WEIGHTS_EMPTY_PTR
      pointer (MPIABI_WEIGHTS_EMPTY_PTR, MPIABI_WEIGHTS_EMPTY)
      common /MPIABI_WEIGHTS_EMPTY_PTR/ MPIABI_WEIGHTS_EMPTY_PTR

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
