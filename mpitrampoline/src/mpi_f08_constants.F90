module mpi_f08_constants
  use mpi_f08_types

  use mpi, only: &
       !
       ! Variable Address Size
       MPI_ADDRESS_KIND, &
       MPI_COUNT_KIND, &
       MPI_INTEGER_KIND, &
       MPI_OFFSET_KIND, &
       ! Error classes
       MPI_SUCCESS, &
       MPI_ERR_BUFFER, &
       MPI_ERR_COUNT, &
       MPI_ERR_TYPE, &
       MPI_ERR_TAG, &
       MPI_ERR_COMM, &
       MPI_ERR_RANK, &
       MPI_ERR_REQUEST, &
       MPI_ERR_ROOT, &
       MPI_ERR_GROUP, &
       MPI_ERR_OP, &
       MPI_ERR_TOPOLOGY, &
       MPI_ERR_DIMS, &
       MPI_ERR_ARG, &
       MPI_ERR_UNKNOWN, &
       MPI_ERR_TRUNCATE, &
       MPI_ERR_OTHER, &
       MPI_ERR_INTERN, &
       MPI_ERR_PENDING, &
       MPI_ERR_IN_STATUS, &
       MPI_ERR_ACCESS, &
       MPI_ERR_AMODE, &
       MPI_ERR_ASSERT, &
       MPI_ERR_BAD_FILE, &
       MPI_ERR_BASE, &
       MPI_ERR_CONVERSION, &
       MPI_ERR_DISP, &
       MPI_ERR_DUP_DATAREP, &
       MPI_ERR_FILE_EXISTS, &
       MPI_ERR_FILE_IN_USE, &
       MPI_ERR_FILE, &
       MPI_ERR_INFO_KEY, &
       MPI_ERR_INFO_NOKEY, &
       MPI_ERR_INFO_VALUE, &
       MPI_ERR_INFO, &
       MPI_ERR_IO, &
       MPI_ERR_KEYVAL, &
       MPI_ERR_LOCKTYPE, &
       MPI_ERR_NAME, &
       MPI_ERR_NO_MEM, &
       MPI_ERR_NOT_SAME, &
       MPI_ERR_NO_SPACE, &
       MPI_ERR_NO_SUCH_FILE, &
       MPI_ERR_PORT, &
       MPI_ERR_PROC_ABORTED, &
       MPI_ERR_QUOTA, &
       MPI_ERR_READ_ONLY, &
       MPI_ERR_RMA_ATTACH, &
       MPI_ERR_RMA_CONFLICT, &
       MPI_ERR_RMA_RANGE, &
       MPI_ERR_RMA_SHARED, &
       MPI_ERR_RMA_SYNC, &
       MPI_ERR_RMA_FLAVOR, &
       MPI_ERR_SERVICE, &
       MPI_ERR_SESSION, &
       MPI_ERR_SIZE, &
       MPI_ERR_SPAWN, &
       MPI_ERR_UNSUPPORTED_DATAREP, &
       MPI_ERR_UNSUPPORTED_OPERATION, &
       MPI_ERR_VALUE_TOO_LARGE, &
       MPI_ERR_WIN, &
       MPI_ERR_ERRHANDLER, &
       MPI_T_ERR_CANNOT_INIT, &
       MPI_T_ERR_NOT_ACCESSIBLE, &
       MPI_T_ERR_NOT_INITIALIZED, &
       MPI_T_ERR_NOT_SUPPORTED, &
       MPI_T_ERR_MEMORY, &
       MPI_T_ERR_INVALID, &
       MPI_T_ERR_INVALID_INDEX, &
       MPI_T_ERR_INVALID_ITEM, &
       MPI_T_ERR_INVALID_SESSION, &
       MPI_T_ERR_INVALID_HANDLE, &
       MPI_T_ERR_INVALID_NAME, &
       MPI_T_ERR_OUT_OF_HANDLES, &
       MPI_T_ERR_OUT_OF_SESSIONS, &
       MPI_T_ERR_CVAR_SET_NOT_NOW, &
       MPI_T_ERR_CVAR_SET_NEVER, &
       MPI_T_ERR_PVAR_NO_WRITE, &
       MPI_T_ERR_PVAR_NO_STARTSTOP, &
       MPI_T_ERR_PVAR_NO_ATOMIC, &
       MPI_ERR_LASTCODE, &
       ! Buffer Address Constants
       MPI_BOTTOM, &
       MPI_BUFFER_AUTOMATIC, &
       MPI_IN_PLACE, &
       ! Assorted Constants
       MPI_PROC_NULL, &
       MPI_ANY_SOURCE, &
       MPI_ANY_TAG, &
       MPI_UNDEFINED, &
       MPI_BSEND_OVERHEAD, &
       MPI_KEYVAL_INVALID, &
       MPI_LOCK_EXCLUSIVE, &
       MPI_LOCK_SHARED, &
       MPI_ROOT, &
       ! Fortran Support Method Specific Constants
       MPI_SUBARRAYS_SUPPORTED, &
       MPI_ASYNC_PROTECTS_NONBLOCKING, &
       ! Status array size and reserved index values
       MPI_STATUS_SIZE, &
       MPI_SOURCE, &
       MPI_TAG, &
       MPI_ERROR, &
       ! Fortran status array size and reserved index values
       ! Maximum Sizes for Strings
       MPI_MAX_DATAREP_STRING, &
       MPI_MAX_ERROR_STRING, &
       MPI_MAX_INFO_KEY, &
       MPI_MAX_INFO_VAL, &
       MPI_MAX_LIBRARY_VERSION_STRING, &
       MPI_MAX_OBJECT_NAME, &
       MPI_MAX_PORT_NAME, &
       MPI_MAX_PROCESSOR_NAME, &
       MPI_MAX_PSET_NAME_LEN, &
       MPI_MAX_STRINGTAG_LEN, &
       ! Communicator split type constants
       MPI_COMM_TYPE_SHARED, &
       MPI_COMM_TYPE_HW_UNGUIDED, &
       MPI_COMM_TYPE_HW_GUIDED, &
       MPI_COMM_TYPE_RESOURCE_GUIDED, &
       ! Results of communicator and group comparisons
       MPI_IDENT, &
       MPI_CONGRUENT, &
       MPI_SIMILAR, &
       MPI_UNEQUAL, &
       ! Environmental inquiry keys
       MPI_TAG_UB, &
       MPI_IO, &
       MPI_HOST, &
       MPI_WTIME_IS_GLOBAL, &
       ! Topologies
       MPI_GRAPH, &
       MPI_CART, &
       MPI_DIST_GRAPH, &
       ! Predefined Attribute Keys
       MPI_APPNUM, &
       MPI_LASTUSEDCODE, &
       MPI_UNIVERSE_SIZE, &
       MPI_WIN_BASE, &
       MPI_WIN_DISP_UNIT, &
       MPI_WIN_SIZE, &
       MPI_WIN_CREATE_FLAVOR, &
       MPI_WIN_MODEL, &
       ! MPI Window Create Flavors
       MPI_WIN_FLAVOR_CREATE, &
       MPI_WIN_FLAVOR_ALLOCATE, &
       MPI_WIN_FLAVOR_DYNAMIC, &
       MPI_WIN_FLAVOR_SHARED, &
       ! MPI Window Models
       MPI_WIN_SEPARATE, &
       MPI_WIN_UNIFIED, &
       ! Mode Constants
       MPI_MODE_APPEND, &
       MPI_MODE_CREATE, &
       MPI_MODE_DELETE_ON_CLOSE, &
       MPI_MODE_EXCL, &
       MPI_MODE_NOCHECK, &
       MPI_MODE_NOPRECEDE, &
       MPI_MODE_NOPUT, &
       MPI_MODE_NOSTORE, &
       MPI_MODE_NOSUCCEED, &
       MPI_MODE_RDONLY, &
       MPI_MODE_RDWR, &
       MPI_MODE_SEQUENTIAL, &
       MPI_MODE_UNIQUE_OPEN, &
       MPI_MODE_WRONLY, &
       ! Datatype Decoding Constants
       MPI_COMBINER_CONTIGUOUS, &
       MPI_COMBINER_DARRAY, &
       MPI_COMBINER_DUP, &
       MPI_COMBINER_F90_COMPLEX, &
       MPI_COMBINER_F90_INTEGER, &
       MPI_COMBINER_F90_REAL, &
       MPI_COMBINER_HINDEXED, &
       MPI_COMBINER_HVECTOR, &
       MPI_COMBINER_INDEXED_BLOCK, &
       MPI_COMBINER_HINDEXED_BLOCK, &
       MPI_COMBINER_INDEXED, &
       MPI_COMBINER_NAMED, &
       MPI_COMBINER_RESIZED, &
       MPI_COMBINER_STRUCT, &
       MPI_COMBINER_SUBARRAY, &
       MPI_COMBINER_VECTOR, &
       ! Threads Constants 
       MPI_THREAD_FUNNELED, &
       MPI_THREAD_MULTIPLE, &
       MPI_THREAD_SERIALIZED, &
       MPI_THREAD_SINGLE, &
       ! File Operation Constants, Part 1
       MPI_DISPLACEMENT_CURRENT, &
       ! File Operation Constants, Part 2
       MPI_DISTRIBUTE_BLOCK, &
       MPI_DISTRIBUTE_CYCLIC, &
       MPI_DISTRIBUTE_DFLT_DARG, &
       MPI_DISTRIBUTE_NONE, &
       MPI_ORDER_C, &
       MPI_ORDER_FORTRAN, &
       MPI_SEEK_CUR, &
       MPI_SEEK_END, &
       MPI_SEEK_SET, &
       ! F90 Datatype Matching Constants
       MPI_TYPECLASS_COMPLEX, &
       MPI_TYPECLASS_INTEGER, &
       MPI_TYPECLASS_REAL, &
       ! Constants Specifying Empty or Ignored Input
       MPI_ARGVS_NULL, &
       MPI_ARGV_NULL, &
       MPI_ERRCODES_IGNORE, &
       !  MPI_STATUSES_IGNORE
       !  MPI_STATUS_IGNORE
       MPI_UNWEIGHTED, &
       MPI_WEIGHTS_EMPTY, &
       ! C Constants Specifying Ignored Input (no Fortran)
       ! C preprocessor Constants and Fortran Parameters
       MPI_SUBVERSION, &
       MPI_VERSION, &
       ! MPItrampoline version
       MPITRAMPOLINE_VERSION_MAJOR, &
       MPITRAMPOLINE_VERSION_MINOR, &
       MPITRAMPOLINE_VERSION_PATCH, &
       !
       ! Comm
       wrapped_MPI_COMM_NULL => MPI_COMM_NULL, &
       wrapped_MPI_COMM_SELF => MPI_COMM_SELF, &
       wrapped_MPI_COMM_WORLD => MPI_COMM_WORLD, &
       ! Datatype
       wrapped_MPI_DATATYPE_NULL => MPI_DATATYPE_NULL, &
       wrapped_MPI_CHAR => MPI_CHAR, &
       wrapped_MPI_SHORT => MPI_SHORT, &
       wrapped_MPI_INT => MPI_INT, &
       wrapped_MPI_LONG => MPI_LONG, &
       wrapped_MPI_LONG_LONG_INT => MPI_LONG_LONG_INT, &
       wrapped_MPI_LONG_LONG => MPI_LONG_LONG, &
       wrapped_MPI_SIGNED_CHAR => MPI_SIGNED_CHAR, &
       wrapped_MPI_UNSIGNED_CHAR => MPI_UNSIGNED_CHAR, &
       wrapped_MPI_UNSIGNED_SHORT => MPI_UNSIGNED_SHORT, &
       wrapped_MPI_UNSIGNED => MPI_UNSIGNED, &
       wrapped_MPI_UNSIGNED_LONG => MPI_UNSIGNED_LONG, &
       wrapped_MPI_UNSIGNED_LONG_LONG => MPI_UNSIGNED_LONG_LONG, &
       wrapped_MPI_FLOAT => MPI_FLOAT, &
       wrapped_MPI_DOUBLE => MPI_DOUBLE, &
       wrapped_MPI_LONG_DOUBLE => MPI_LONG_DOUBLE, &
       wrapped_MPI_WCHAR => MPI_WCHAR, &
       wrapped_MPI_C_BOOL => MPI_C_BOOL, &
       wrapped_MPI_INT8_T => MPI_INT8_T, &
       wrapped_MPI_INT16_T => MPI_INT16_T, &
       wrapped_MPI_INT32_T => MPI_INT32_T, &
       wrapped_MPI_INT64_T => MPI_INT64_T, &
       wrapped_MPI_UINT8_T => MPI_UINT8_T, &
       wrapped_MPI_UINT16_T => MPI_UINT16_T, &
       wrapped_MPI_UINT32_T => MPI_UINT32_T, &
       wrapped_MPI_UINT64_T => MPI_UINT64_T, &
       wrapped_MPI_AINT => MPI_AINT, &
       wrapped_MPI_COUNT => MPI_COUNT, &
       wrapped_MPI_OFFSET => MPI_OFFSET, &
       wrapped_MPI_C_COMPLEX => MPI_C_COMPLEX, &
       wrapped_MPI_C_FLOAT_COMPLEX => MPI_C_FLOAT_COMPLEX, &
       wrapped_MPI_C_DOUBLE_COMPLEX => MPI_C_DOUBLE_COMPLEX, &
       wrapped_MPI_C_LONG_DOUBLE_COMPLEX => MPI_C_LONG_DOUBLE_COMPLEX, &
       wrapped_MPI_BYTE => MPI_BYTE, &
       wrapped_MPI_PACKED => MPI_PACKED, &
       wrapped_MPI_INTEGER => MPI_INTEGER, &
       wrapped_MPI_REAL => MPI_REAL, &
       wrapped_MPI_DOUBLE_PRECISION => MPI_DOUBLE_PRECISION, &
       wrapped_MPI_COMPLEX => MPI_COMPLEX, &
       wrapped_MPI_LOGICAL => MPI_LOGICAL, &
       wrapped_MPI_CHARACTER => MPI_CHARACTER, &
       wrapped_MPI_CXX_BOOL => MPI_CXX_BOOL, &
       wrapped_MPI_CXX_FLOAT_COMPLEX => MPI_CXX_FLOAT_COMPLEX, &
       wrapped_MPI_CXX_DOUBLE_COMPLEX => MPI_CXX_DOUBLE_COMPLEX, &
       wrapped_MPI_CXX_LONG_DOUBLE_COMPLEX => MPI_CXX_LONG_DOUBLE_COMPLEX, &
       wrapped_MPI_DOUBLE_COMPLEX => MPI_DOUBLE_COMPLEX, &
       wrapped_MPI_INTEGER1 => MPI_INTEGER1, &
       wrapped_MPI_INTEGER2 => MPI_INTEGER2, &
       wrapped_MPI_INTEGER4 => MPI_INTEGER4, &
       wrapped_MPI_INTEGER8 => MPI_INTEGER8, &
       wrapped_MPI_INTEGER16 => MPI_INTEGER16, &
       wrapped_MPI_REAL2 => MPI_REAL2, &
       wrapped_MPI_REAL4 => MPI_REAL4, &
       wrapped_MPI_REAL8 => MPI_REAL8, &
       wrapped_MPI_REAL16 => MPI_REAL16, &
       wrapped_MPI_COMPLEX2 => MPI_COMPLEX2, &
       wrapped_MPI_COMPLEX4 => MPI_COMPLEX4, &
       wrapped_MPI_COMPLEX8 => MPI_COMPLEX8, &
       wrapped_MPI_COMPLEX16 => MPI_COMPLEX16, &
       wrapped_MPI_COMPLEX32 => MPI_COMPLEX32, &
       wrapped_MPI_REAL1 => MPI_REAL1, &
       wrapped_MPI_LOGICAL1 => MPI_LOGICAL1, &
       wrapped_MPI_LOGICAL2 => MPI_LOGICAL2, &
       wrapped_MPI_LOGICAL4 => MPI_LOGICAL4, &
       wrapped_MPI_LOGICAL8 => MPI_LOGICAL8, &
       wrapped_MPI_FLOAT_INT => MPI_FLOAT_INT, &
       wrapped_MPI_DOUBLE_INT => MPI_DOUBLE_INT, &
       wrapped_MPI_LONG_INT => MPI_LONG_INT, &
       wrapped_MPI_2INT => MPI_2INT, &
       wrapped_MPI_SHORT_INT => MPI_SHORT_INT, &
       wrapped_MPI_LONG_DOUBLE_INT => MPI_LONG_DOUBLE_INT, &
       wrapped_MPI_2REAL => MPI_2REAL, &
       wrapped_MPI_2DOUBLE_PRECISION => MPI_2DOUBLE_PRECISION, &
       wrapped_MPI_2INTEGER => MPI_2INTEGER, &
       wrapped_MPI_LB => MPI_LB, &
       wrapped_MPI_UB => MPI_UB, &
       ! Errhandler
       wrapped_MPI_ERRHANDLER_NULL => MPI_ERRHANDLER_NULL, &
       wrapped_MPI_ERRORS_ABORT => MPI_ERRORS_ABORT, &
       wrapped_MPI_ERRORS_ARE_FATAL => MPI_ERRORS_ARE_FATAL, &
       wrapped_MPI_ERRORS_RETURN => MPI_ERRORS_RETURN, &
       ! File
       wrapped_MPI_FILE_NULL => MPI_FILE_NULL, &
       ! Group
       wrapped_MPI_GROUP_EMPTY => MPI_GROUP_EMPTY, &
       wrapped_MPI_GROUP_NULL => MPI_GROUP_NULL, &
       ! Info
       wrapped_MPI_INFO_ENV => MPI_INFO_ENV, &
       wrapped_MPI_INFO_NULL => MPI_INFO_NULL, &
       ! Message
       wrapped_MPI_MESSAGE_NO_PROC => MPI_MESSAGE_NO_PROC, &
       wrapped_MPI_MESSAGE_NULL => MPI_MESSAGE_NULL, &
       ! Op
       wrapped_MPI_OP_NULL => MPI_OP_NULL, &
       wrapped_MPI_MAX => MPI_MAX, &
       wrapped_MPI_MIN => MPI_MIN, &
       wrapped_MPI_SUM => MPI_SUM, &
       wrapped_MPI_PROD => MPI_PROD, &
       wrapped_MPI_MAXLOC => MPI_MAXLOC, &
       wrapped_MPI_MINLOC => MPI_MINLOC, &
       wrapped_MPI_BAND => MPI_BAND, &
       wrapped_MPI_BOR => MPI_BOR, &
       wrapped_MPI_BXOR => MPI_BXOR, &
       wrapped_MPI_LAND => MPI_LAND, &
       wrapped_MPI_LOR => MPI_LOR, &
       wrapped_MPI_LXOR => MPI_LXOR, &
       wrapped_MPI_REPLACE => MPI_REPLACE, &
       wrapped_MPI_NO_OP => MPI_NO_OP, &
       ! Request
       wrapped_MPI_REQUEST_NULL => MPI_REQUEST_NULL, &
       ! Session
       wrapped_MPI_SESSION_NULL => MPI_SESSION_NULL, &
       ! Win
       wrapped_MPI_WIN_NULL => MPI_WIN_NULL
  
  implicit none
  private
  save

  ! Variable Address Size

  public :: MPI_ADDRESS_KIND
  public :: MPI_COUNT_KIND
  public :: MPI_INTEGER_KIND
  public :: MPI_OFFSET_KIND

  ! Error classes

  public :: MPI_SUCCESS
  public :: MPI_ERR_BUFFER
  public :: MPI_ERR_COUNT
  public :: MPI_ERR_TYPE
  public :: MPI_ERR_TAG
  public :: MPI_ERR_COMM
  public :: MPI_ERR_RANK
  public :: MPI_ERR_REQUEST
  public :: MPI_ERR_ROOT
  public :: MPI_ERR_GROUP
  public :: MPI_ERR_OP
  public :: MPI_ERR_TOPOLOGY
  public :: MPI_ERR_DIMS
  public :: MPI_ERR_ARG
  public :: MPI_ERR_UNKNOWN
  public :: MPI_ERR_TRUNCATE
  public :: MPI_ERR_OTHER
  public :: MPI_ERR_INTERN
  public :: MPI_ERR_PENDING
  public :: MPI_ERR_IN_STATUS
  public :: MPI_ERR_ACCESS
  public :: MPI_ERR_AMODE
  public :: MPI_ERR_ASSERT
  public :: MPI_ERR_BAD_FILE
  public :: MPI_ERR_BASE
  public :: MPI_ERR_CONVERSION
  public :: MPI_ERR_DISP
  public :: MPI_ERR_DUP_DATAREP
  public :: MPI_ERR_FILE_EXISTS
  public :: MPI_ERR_FILE_IN_USE
  public :: MPI_ERR_FILE
  public :: MPI_ERR_INFO_KEY
  public :: MPI_ERR_INFO_NOKEY
  public :: MPI_ERR_INFO_VALUE
  public :: MPI_ERR_INFO
  public :: MPI_ERR_IO
  public :: MPI_ERR_KEYVAL
  public :: MPI_ERR_LOCKTYPE
  public :: MPI_ERR_NAME
  public :: MPI_ERR_NO_MEM
  public :: MPI_ERR_NOT_SAME
  public :: MPI_ERR_NO_SPACE
  public :: MPI_ERR_NO_SUCH_FILE
  public :: MPI_ERR_PORT
  public :: MPI_ERR_PROC_ABORTED
  public :: MPI_ERR_QUOTA
  public :: MPI_ERR_READ_ONLY
  public :: MPI_ERR_RMA_ATTACH
  public :: MPI_ERR_RMA_CONFLICT
  public :: MPI_ERR_RMA_RANGE
  public :: MPI_ERR_RMA_SHARED
  public :: MPI_ERR_RMA_SYNC
  public :: MPI_ERR_RMA_FLAVOR
  public :: MPI_ERR_SERVICE
  public :: MPI_ERR_SESSION
  public :: MPI_ERR_SIZE
  public :: MPI_ERR_SPAWN
  public :: MPI_ERR_UNSUPPORTED_DATAREP
  public :: MPI_ERR_UNSUPPORTED_OPERATION
  public :: MPI_ERR_VALUE_TOO_LARGE
  public :: MPI_ERR_WIN
  public :: MPI_ERR_ERRHANDLER
  public :: MPI_T_ERR_CANNOT_INIT
  public :: MPI_T_ERR_NOT_ACCESSIBLE
  public :: MPI_T_ERR_NOT_INITIALIZED
  public :: MPI_T_ERR_NOT_SUPPORTED
  public :: MPI_T_ERR_MEMORY
  public :: MPI_T_ERR_INVALID
  public :: MPI_T_ERR_INVALID_INDEX
  public :: MPI_T_ERR_INVALID_ITEM
  public :: MPI_T_ERR_INVALID_SESSION
  public :: MPI_T_ERR_INVALID_HANDLE
  public :: MPI_T_ERR_INVALID_NAME
  public :: MPI_T_ERR_OUT_OF_HANDLES
  public :: MPI_T_ERR_OUT_OF_SESSIONS
  public :: MPI_T_ERR_CVAR_SET_NOT_NOW
  public :: MPI_T_ERR_CVAR_SET_NEVER
  public :: MPI_T_ERR_PVAR_NO_WRITE
  public :: MPI_T_ERR_PVAR_NO_STARTSTOP
  public :: MPI_T_ERR_PVAR_NO_ATOMIC
  public :: MPI_ERR_LASTCODE

  ! Buffer Address Constants
  public :: MPI_BOTTOM
  public :: MPI_BUFFER_AUTOMATIC
  public :: MPI_IN_PLACE

  ! Assorted Constants
  public :: MPI_PROC_NULL
  public :: MPI_ANY_SOURCE
  public :: MPI_ANY_TAG
  public :: MPI_UNDEFINED
  public :: MPI_BSEND_OVERHEAD
  public :: MPI_KEYVAL_INVALID
  public :: MPI_LOCK_EXCLUSIVE
  public :: MPI_LOCK_SHARED
  public :: MPI_ROOT

  ! Fortran Support Method Specific Constants
  public :: MPI_SUBARRAYS_SUPPORTED
  public :: MPI_ASYNC_PROTECTS_NONBLOCKING

  ! Status array size and reserved index values
  public :: MPI_STATUS_SIZE
  public :: MPI_SOURCE
  public :: MPI_TAG
  public :: MPI_ERROR

  ! Fortran status array size and reserved index values

  ! Variable Address Size
  ! These have already been defined above.

  ! Maximum Sizes for Strings
  public :: MPI_MAX_DATAREP_STRING
  public :: MPI_MAX_ERROR_STRING
  public :: MPI_MAX_INFO_KEY
  public :: MPI_MAX_INFO_VAL
  public :: MPI_MAX_LIBRARY_VERSION_STRING
  public :: MPI_MAX_OBJECT_NAME
  public :: MPI_MAX_PORT_NAME
  public :: MPI_MAX_PROCESSOR_NAME
  public :: MPI_MAX_PSET_NAME_LEN
  public :: MPI_MAX_STRINGTAG_LEN

  ! Communicator split type constants
  public :: MPI_COMM_TYPE_SHARED
  public :: MPI_COMM_TYPE_HW_UNGUIDED
  public :: MPI_COMM_TYPE_HW_GUIDED
  public :: MPI_COMM_TYPE_RESOURCE_GUIDED

  ! Results of communicator and group comparisons
  public :: MPI_IDENT
  public :: MPI_CONGRUENT
  public :: MPI_SIMILAR
  public :: MPI_UNEQUAL

  ! Environmental inquiry keys
  public :: MPI_TAG_UB
  public :: MPI_IO
  public :: MPI_HOST
  public :: MPI_WTIME_IS_GLOBAL

  ! Topologies
  public :: MPI_GRAPH
  public :: MPI_CART
  public :: MPI_DIST_GRAPH

  ! Predefined Attribute Keys
  public :: MPI_APPNUM
  public :: MPI_LASTUSEDCODE
  public :: MPI_UNIVERSE_SIZE
  public :: MPI_WIN_BASE
  public :: MPI_WIN_DISP_UNIT
  public :: MPI_WIN_SIZE
  public :: MPI_WIN_CREATE_FLAVOR
  public :: MPI_WIN_MODEL

  ! MPI Window Create Flavors
  public :: MPI_WIN_FLAVOR_CREATE
  public :: MPI_WIN_FLAVOR_ALLOCATE
  public :: MPI_WIN_FLAVOR_DYNAMIC
  public :: MPI_WIN_FLAVOR_SHARED

  ! MPI Window Models
  public :: MPI_WIN_SEPARATE
  public :: MPI_WIN_UNIFIED

  ! Mode Constants
  public :: MPI_MODE_APPEND
  public :: MPI_MODE_CREATE
  public :: MPI_MODE_DELETE_ON_CLOSE
  public :: MPI_MODE_EXCL
  public :: MPI_MODE_NOCHECK
  public :: MPI_MODE_NOPRECEDE
  public :: MPI_MODE_NOPUT
  public :: MPI_MODE_NOSTORE
  public :: MPI_MODE_NOSUCCEED
  public :: MPI_MODE_RDONLY
  public :: MPI_MODE_RDWR
  public :: MPI_MODE_SEQUENTIAL
  public :: MPI_MODE_UNIQUE_OPEN
  public :: MPI_MODE_WRONLY

  ! Datatype Decoding Constants
  public :: MPI_COMBINER_CONTIGUOUS
  public :: MPI_COMBINER_DARRAY
  public :: MPI_COMBINER_DUP
  public :: MPI_COMBINER_F90_COMPLEX
  public :: MPI_COMBINER_F90_INTEGER
  public :: MPI_COMBINER_F90_REAL
  public :: MPI_COMBINER_HINDEXED
  public :: MPI_COMBINER_HVECTOR
  public :: MPI_COMBINER_INDEXED_BLOCK
  public :: MPI_COMBINER_HINDEXED_BLOCK
  public :: MPI_COMBINER_INDEXED
  public :: MPI_COMBINER_NAMED
  public :: MPI_COMBINER_RESIZED
  public :: MPI_COMBINER_STRUCT
  public :: MPI_COMBINER_SUBARRAY
  public :: MPI_COMBINER_VECTOR

  ! Threads Constants
  public :: MPI_THREAD_FUNNELED
  public :: MPI_THREAD_MULTIPLE
  public :: MPI_THREAD_SERIALIZED
  public :: MPI_THREAD_SINGLE

  ! File Operation Constants, Part 1
  public :: MPI_DISPLACEMENT_CURRENT

  ! File Operation Constants, Part 2
  public :: MPI_DISTRIBUTE_BLOCK
  public :: MPI_DISTRIBUTE_CYCLIC
  public :: MPI_DISTRIBUTE_DFLT_DARG
  public :: MPI_DISTRIBUTE_NONE
  public :: MPI_ORDER_C
  public :: MPI_ORDER_FORTRAN
  public :: MPI_SEEK_CUR
  public :: MPI_SEEK_END
  public :: MPI_SEEK_SET

  ! F90 Datatype Matching Constants
  public :: MPI_TYPECLASS_COMPLEX
  public :: MPI_TYPECLASS_INTEGER
  public :: MPI_TYPECLASS_REAL

  ! Constants Specifying Empty or Ignored Input
  public :: MPI_ARGVS_NULL
  public :: MPI_ARGV_NULL
  public :: MPI_ERRCODES_IGNORE
  ! public :: MPI_STATUSES_IGNORE
  ! public :: MPI_STATUS_IGNORE
  public :: MPI_UNWEIGHTED
  public :: MPI_WEIGHTS_EMPTY

  ! C Constants Specifying Ignored Input (no Fortran)

  ! C preprocessor Constants and Fortran Parameters
  public :: MPI_SUBVERSION
  public :: MPI_VERSION

  ! MPItrampoline version
  public :: MPITRAMPOLINE_VERSION_MAJOR
  public :: MPITRAMPOLINE_VERSION_MINOR
  public :: MPITRAMPOLINE_VERSION_PATCH

  ! Comm

  type(MPI_Comm), parameter, public :: MPI_COMM_NULL = MPI_Comm(wrapped_MPI_COMM_NULL)
  type(MPI_Comm), parameter, public :: MPI_COMM_SELF = MPI_Comm(wrapped_MPI_COMM_SELF)
  type(MPI_Comm), parameter, public :: MPI_COMM_WORLD = MPI_Comm(wrapped_MPI_COMM_WORLD)

  ! Datatype

  type(MPI_Datatype), parameter, public :: MPI_DATATYPE_NULL = MPI_Datatype(wrapped_MPI_DATATYPE_NULL)
  type(MPI_Datatype), parameter, public :: MPI_CHAR = MPI_Datatype(wrapped_MPI_CHAR)
  type(MPI_Datatype), parameter, public :: MPI_SHORT = MPI_Datatype(wrapped_MPI_SHORT)
  type(MPI_Datatype), parameter, public :: MPI_INT = MPI_Datatype(wrapped_MPI_INT)
  type(MPI_Datatype), parameter, public :: MPI_LONG = MPI_Datatype(wrapped_MPI_LONG)
  type(MPI_Datatype), parameter, public :: MPI_LONG_LONG_INT = MPI_Datatype(wrapped_MPI_LONG_LONG_INT)
  type(MPI_Datatype), parameter, public :: MPI_LONG_LONG = MPI_Datatype(wrapped_MPI_LONG_LONG)
  type(MPI_Datatype), parameter, public :: MPI_SIGNED_CHAR = MPI_Datatype(wrapped_MPI_SIGNED_CHAR)
  type(MPI_Datatype), parameter, public :: MPI_UNSIGNED_CHAR = MPI_Datatype(wrapped_MPI_UNSIGNED_CHAR)
  type(MPI_Datatype), parameter, public :: MPI_UNSIGNED_SHORT = MPI_Datatype(wrapped_MPI_UNSIGNED_SHORT)
  type(MPI_Datatype), parameter, public :: MPI_UNSIGNED = MPI_Datatype(wrapped_MPI_UNSIGNED)
  type(MPI_Datatype), parameter, public :: MPI_UNSIGNED_LONG = MPI_Datatype(wrapped_MPI_UNSIGNED_LONG)
  type(MPI_Datatype), parameter, public :: MPI_UNSIGNED_LONG_LONG = MPI_Datatype(wrapped_MPI_UNSIGNED_LONG_LONG)
  type(MPI_Datatype), parameter, public :: MPI_FLOAT = MPI_Datatype(wrapped_MPI_FLOAT)
  type(MPI_Datatype), parameter, public :: MPI_DOUBLE = MPI_Datatype(wrapped_MPI_DOUBLE)
  type(MPI_Datatype), parameter, public :: MPI_LONG_DOUBLE = MPI_Datatype(wrapped_MPI_LONG_DOUBLE)
  type(MPI_Datatype), parameter, public :: MPI_WCHAR = MPI_Datatype(wrapped_MPI_WCHAR)
  type(MPI_Datatype), parameter, public :: MPI_C_BOOL = MPI_Datatype(wrapped_MPI_C_BOOL)
  type(MPI_Datatype), parameter, public :: MPI_INT8_T = MPI_Datatype(wrapped_MPI_INT8_T)
  type(MPI_Datatype), parameter, public :: MPI_INT16_T = MPI_Datatype(wrapped_MPI_INT16_T)
  type(MPI_Datatype), parameter, public :: MPI_INT32_T = MPI_Datatype(wrapped_MPI_INT32_T)
  type(MPI_Datatype), parameter, public :: MPI_INT64_T = MPI_Datatype(wrapped_MPI_INT64_T)
  type(MPI_Datatype), parameter, public :: MPI_UINT8_T = MPI_Datatype(wrapped_MPI_UINT8_T)
  type(MPI_Datatype), parameter, public :: MPI_UINT16_T = MPI_Datatype(wrapped_MPI_UINT16_T)
  type(MPI_Datatype), parameter, public :: MPI_UINT32_T = MPI_Datatype(wrapped_MPI_UINT32_T)
  type(MPI_Datatype), parameter, public :: MPI_UINT64_T = MPI_Datatype(wrapped_MPI_UINT64_T)
  type(MPI_Datatype), parameter, public :: MPI_AINT = MPI_Datatype(wrapped_MPI_AINT)
  type(MPI_Datatype), parameter, public :: MPI_COUNT = MPI_Datatype(wrapped_MPI_COUNT)
  type(MPI_Datatype), parameter, public :: MPI_OFFSET = MPI_Datatype(wrapped_MPI_OFFSET)
  type(MPI_Datatype), parameter, public :: MPI_C_COMPLEX = MPI_Datatype(wrapped_MPI_C_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_C_FLOAT_COMPLEX = MPI_Datatype(wrapped_MPI_C_FLOAT_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_C_DOUBLE_COMPLEX = MPI_Datatype(wrapped_MPI_C_DOUBLE_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_C_LONG_DOUBLE_COMPLEX = MPI_Datatype(wrapped_MPI_C_LONG_DOUBLE_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_BYTE = MPI_Datatype(wrapped_MPI_BYTE)
  type(MPI_Datatype), parameter, public :: MPI_PACKED = MPI_Datatype(wrapped_MPI_PACKED)
  type(MPI_Datatype), parameter, public :: MPI_INTEGER = MPI_Datatype(wrapped_MPI_INTEGER)
  type(MPI_Datatype), parameter, public :: MPI_REAL = MPI_Datatype(wrapped_MPI_REAL)
  type(MPI_Datatype), parameter, public :: MPI_DOUBLE_PRECISION = MPI_Datatype(wrapped_MPI_DOUBLE_PRECISION)
  type(MPI_Datatype), parameter, public :: MPI_COMPLEX = MPI_Datatype(wrapped_MPI_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_LOGICAL = MPI_Datatype(wrapped_MPI_LOGICAL)
  type(MPI_Datatype), parameter, public :: MPI_CHARACTER = MPI_Datatype(wrapped_MPI_CHARACTER)
  type(MPI_Datatype), parameter, public :: MPI_CXX_BOOL = MPI_Datatype(wrapped_MPI_CXX_BOOL)
  type(MPI_Datatype), parameter, public :: MPI_CXX_FLOAT_COMPLEX = MPI_Datatype(wrapped_MPI_CXX_FLOAT_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_CXX_DOUBLE_COMPLEX = MPI_Datatype(wrapped_MPI_CXX_DOUBLE_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_CXX_LONG_DOUBLE_COMPLEX = MPI_Datatype(wrapped_MPI_CXX_LONG_DOUBLE_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_DOUBLE_COMPLEX = MPI_Datatype(wrapped_MPI_DOUBLE_COMPLEX)
  type(MPI_Datatype), parameter, public :: MPI_INTEGER1 = MPI_Datatype(wrapped_MPI_INTEGER1)
  type(MPI_Datatype), parameter, public :: MPI_INTEGER2 = MPI_Datatype(wrapped_MPI_INTEGER2)
  type(MPI_Datatype), parameter, public :: MPI_INTEGER4 = MPI_Datatype(wrapped_MPI_INTEGER4)
  type(MPI_Datatype), parameter, public :: MPI_INTEGER8 = MPI_Datatype(wrapped_MPI_INTEGER8)
  type(MPI_Datatype), parameter, public :: MPI_INTEGER16 = MPI_Datatype(wrapped_MPI_INTEGER16)
  type(MPI_Datatype), parameter, public :: MPI_REAL2 = MPI_Datatype(wrapped_MPI_REAL2)
  type(MPI_Datatype), parameter, public :: MPI_REAL4 = MPI_Datatype(wrapped_MPI_REAL4)
  type(MPI_Datatype), parameter, public :: MPI_REAL8 = MPI_Datatype(wrapped_MPI_REAL8)
  type(MPI_Datatype), parameter, public :: MPI_REAL16 = MPI_Datatype(wrapped_MPI_REAL16)
  type(MPI_Datatype), parameter, public :: MPI_COMPLEX2 = MPI_Datatype(wrapped_MPI_COMPLEX2)
  type(MPI_Datatype), parameter, public :: MPI_COMPLEX4 = MPI_Datatype(wrapped_MPI_COMPLEX4)
  type(MPI_Datatype), parameter, public :: MPI_COMPLEX8 = MPI_Datatype(wrapped_MPI_COMPLEX8)
  type(MPI_Datatype), parameter, public :: MPI_COMPLEX16 = MPI_Datatype(wrapped_MPI_COMPLEX16)
  type(MPI_Datatype), parameter, public :: MPI_COMPLEX32 = MPI_Datatype(wrapped_MPI_COMPLEX32)
  type(MPI_Datatype), parameter, public :: MPI_REAL1 = MPI_Datatype(wrapped_MPI_REAL1)
  type(MPI_Datatype), parameter, public :: MPI_LOGICAL1 = MPI_Datatype(wrapped_MPI_LOGICAL1)
  type(MPI_Datatype), parameter, public :: MPI_LOGICAL2 = MPI_Datatype(wrapped_MPI_LOGICAL2)
  type(MPI_Datatype), parameter, public :: MPI_LOGICAL4 = MPI_Datatype(wrapped_MPI_LOGICAL4)
  type(MPI_Datatype), parameter, public :: MPI_LOGICAL8 = MPI_Datatype(wrapped_MPI_LOGICAL8)
  type(MPI_Datatype), parameter, public :: MPI_FLOAT_INT = MPI_Datatype(wrapped_MPI_FLOAT_INT)
  type(MPI_Datatype), parameter, public :: MPI_DOUBLE_INT = MPI_Datatype(wrapped_MPI_DOUBLE_INT)
  type(MPI_Datatype), parameter, public :: MPI_LONG_INT = MPI_Datatype(wrapped_MPI_LONG_INT)
  type(MPI_Datatype), parameter, public :: MPI_2INT = MPI_Datatype(wrapped_MPI_2INT)
  type(MPI_Datatype), parameter, public :: MPI_SHORT_INT = MPI_Datatype(wrapped_MPI_SHORT_INT)
  type(MPI_Datatype), parameter, public :: MPI_LONG_DOUBLE_INT = MPI_Datatype(wrapped_MPI_LONG_DOUBLE_INT)
  type(MPI_Datatype), parameter, public :: MPI_2REAL = MPI_Datatype(wrapped_MPI_2REAL)
  type(MPI_Datatype), parameter, public :: MPI_2DOUBLE_PRECISION = MPI_Datatype(wrapped_MPI_2DOUBLE_PRECISION)
  type(MPI_Datatype), parameter, public :: MPI_2INTEGER = MPI_Datatype(wrapped_MPI_2INTEGER)
  type(MPI_Datatype), parameter, public :: MPI_LB = MPI_Datatype(wrapped_MPI_LB)
  type(MPI_Datatype), parameter, public :: MPI_UB = MPI_Datatype(wrapped_MPI_UB)

  ! Errhandler

  type(MPI_Errhandler), parameter, public :: MPI_ERRHANDLER_NULL = MPI_Errhandler(wrapped_MPI_ERRHANDLER_NULL)
  type(MPI_Errhandler), parameter, public :: MPI_ERRORS_ABORT = MPI_Errhandler(wrapped_MPI_ERRORS_ABORT)
  type(MPI_Errhandler), parameter, public :: MPI_ERRORS_ARE_FATAL = MPI_Errhandler(wrapped_MPI_ERRORS_ARE_FATAL)
  type(MPI_Errhandler), parameter, public :: MPI_ERRORS_RETURN = MPI_Errhandler(wrapped_MPI_ERRORS_RETURN)

  ! File

  type(MPI_File), parameter, public :: MPI_FILE_NULL = MPI_File(wrapped_MPI_FILE_NULL)

  ! Group

  type(MPI_Group), parameter, public :: MPI_GROUP_EMPTY = MPI_Group(wrapped_MPI_GROUP_EMPTY)
  type(MPI_Group), parameter, public :: MPI_GROUP_NULL = MPI_Group(wrapped_MPI_GROUP_NULL)

  ! Info

  type(MPI_Info), parameter, public :: MPI_INFO_ENV = MPI_Info(wrapped_MPI_INFO_ENV)
  type(MPI_Info), parameter, public :: MPI_INFO_NULL = MPI_Info(wrapped_MPI_INFO_NULL)

  ! Message

  type(MPI_Message), parameter, public :: MPI_MESSAGE_NO_PROC = MPI_Message(wrapped_MPI_MESSAGE_NO_PROC)
  type(MPI_Message), parameter, public :: MPI_MESSAGE_NULL = MPI_Message(wrapped_MPI_MESSAGE_NULL)

  ! Op

  type(MPI_Op), parameter, public :: MPI_OP_NULL = MPI_Op(wrapped_MPI_OP_NULL)
  type(MPI_Op), parameter, public :: MPI_MAX = MPI_Op(wrapped_MPI_MAX)
  type(MPI_Op), parameter, public :: MPI_MIN = MPI_Op(wrapped_MPI_MIN)
  type(MPI_Op), parameter, public :: MPI_SUM = MPI_Op(wrapped_MPI_SUM)
  type(MPI_Op), parameter, public :: MPI_PROD = MPI_Op(wrapped_MPI_PROD)
  type(MPI_Op), parameter, public :: MPI_MAXLOC = MPI_Op(wrapped_MPI_MAXLOC)
  type(MPI_Op), parameter, public :: MPI_MINLOC = MPI_Op(wrapped_MPI_MINLOC)
  type(MPI_Op), parameter, public :: MPI_BAND = MPI_Op(wrapped_MPI_BAND)
  type(MPI_Op), parameter, public :: MPI_BOR = MPI_Op(wrapped_MPI_BOR)
  type(MPI_Op), parameter, public :: MPI_BXOR = MPI_Op(wrapped_MPI_BXOR)
  type(MPI_Op), parameter, public :: MPI_LAND = MPI_Op(wrapped_MPI_LAND)
  type(MPI_Op), parameter, public :: MPI_LOR = MPI_Op(wrapped_MPI_LOR)
  type(MPI_Op), parameter, public :: MPI_LXOR = MPI_Op(wrapped_MPI_LXOR)
  type(MPI_Op), parameter, public :: MPI_REPLACE = MPI_Op(wrapped_MPI_REPLACE)
  type(MPI_Op), parameter, public :: MPI_NO_OP = MPI_Op(wrapped_MPI_NO_OP)

  ! Request

  type(MPI_Request), parameter, public :: MPI_REQUEST_NULL = MPI_Request(wrapped_MPI_REQUEST_NULL)

  ! Session

  type(MPI_Session), parameter, public :: MPI_SESSION_NULL = MPI_Session(wrapped_MPI_SESSION_NULL)

  ! Win

  type(MPI_Win), parameter, public :: MPI_WIN_NULL = MPI_Win(wrapped_MPI_WIN_NULL)

  ! Status

  public :: MPI_STATUS_IGNORE
  type(MPI_Status) :: MPI_STATUS_IGNORE
  pointer (MPIABI_STATUS_IGNORE_PTR, MPI_STATUS_IGNORE)
  public :: MPI_STATUSES_IGNORE
  type(MPI_Status) :: MPI_STATUSES_IGNORE(1)
  pointer (MPIABI_STATUSES_IGNORE_PTR, MPI_STATUSES_IGNORE)

end module mpi_f08_constants
