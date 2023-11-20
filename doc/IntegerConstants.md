```c
enum {
    // Status indexing - must match MPI_Status definition
    MPI_F_SOURCE        = 0,
    MPI_F_TAG           = 1,
    MPI_F_ERROR         = 2,
    // Fortran status array size and reserved index values (in C)
    MPI_F_STATUS_SIZE   = 8
};
```

```c
// Error classes
enum {
    MPI_SUCCESS                         = 0,
    MPI_ERR_BUFFER                      = 1,
    MPI_ERR_COUNT                       = 2,
    MPI_ERR_TYPE                        = 3,
    MPI_ERR_TAG                         = 4,
    MPI_ERR_COMM                        = 5,
    MPI_ERR_RANK                        = 6,
    MPI_ERR_REQUEST                     = 7,
    MPI_ERR_ROOT                        = 8,
    MPI_ERR_GROUP                       = 9,
    MPI_ERR_OP                          = 10,
    MPI_ERR_TOPOLOGY                    = 11,
    MPI_ERR_DIMS                        = 12,
    MPI_ERR_ARG                         = 13,
    MPI_ERR_UNKNOWN                     = 14,
    MPI_ERR_TRUNCATE                    = 15,
    MPI_ERR_OTHER                       = 16,
    MPI_ERR_INTERN                      = 17,
    MPI_ERR_PENDING                     = 18,
    MPI_ERR_IN_STATUS                   = 19,
    MPI_ERR_ACCESS                      = 20,
    MPI_ERR_AMODE                       = 21,
    MPI_ERR_ASSERT                      = 22,
    MPI_ERR_BAD_FILE                    = 23,
    MPI_ERR_BASE                        = 24,
    MPI_ERR_CONVERSION                  = 25,
    MPI_ERR_DISP                        = 26,
    MPI_ERR_DUP_DATAREP                 = 27,
    MPI_ERR_FILE_EXISTS                 = 28,
    MPI_ERR_FILE_IN_USE                 = 29,
    MPI_ERR_FILE                        = 30,
    MPI_ERR_INFO_KEY                    = 31,
    MPI_ERR_INFO_NOKEY                  = 32,
    MPI_ERR_INFO_VALUE                  = 33,
    MPI_ERR_INFO                        = 34,
    MPI_ERR_IO                          = 35,
    MPI_ERR_KEYVAL                      = 36,
    MPI_ERR_LOCKTYPE                    = 37,
    MPI_ERR_NAME                        = 38,
    MPI_ERR_NO_MEM                      = 39,
    MPI_ERR_NOT_SAME                    = 40,
    MPI_ERR_NO_SPACE                    = 41,
    MPI_ERR_NO_SUCH_FILE                = 42,
    MPI_ERR_PORT                        = 43,
    MPI_ERR_PROC_ABORTED                = 44,
    MPI_ERR_QUOTA                       = 45,
    MPI_ERR_READ_ONLY                   = 46,
    MPI_ERR_RMA_ATTACH                  = 47,
    MPI_ERR_RMA_CONFLICT                = 48,
    MPI_ERR_RMA_RANGE                   = 49,
    MPI_ERR_RMA_SHARED                  = 50,
    MPI_ERR_RMA_SYNC                    = 51,
    MPI_ERR_RMA_FLAVOR                  = 52,
    MPI_ERR_SERVICE                     = 53,
    MPI_ERR_SESSION                     = 54,
    MPI_ERR_SIZE                        = 55,
    MPI_ERR_SPAWN                       = 56,
    MPI_ERR_UNSUPPORTED_DATAREP         = 57,
    MPI_ERR_UNSUPPORTED_OPERATION       = 58,
    MPI_ERR_VALUE_TOO_LARGE             = 59,
    MPI_ERR_WIN                         = 60,
    MPI_ERR_ERRHANDLER                  = 61,
    MPI_T_ERR_CANNOT_INIT               = 1000,
    MPI_T_ERR_NOT_ACCESSIBLE            = 1001,
    MPI_T_ERR_NOT_INITIALIZED           = 1002,
    MPI_T_ERR_NOT_SUPPORTED             = 1003,
    MPI_T_ERR_MEMORY                    = 1004,
    MPI_T_ERR_INVALID                   = 1005,
    MPI_T_ERR_INVALID_INDEX             = 1006,
    MPI_T_ERR_INVALID_ITEM              = 1007,
    MPI_T_ERR_INVALID_SESSION           = 1008,
    MPI_T_ERR_INVALID_HANDLE            = 1009,
    MPI_T_ERR_INVALID_NAME              = 1010,
    MPI_T_ERR_OUT_OF_HANDLES            = 1011,
    MPI_T_ERR_OUT_OF_SESSIONS           = 1012,
    MPI_T_ERR_CVAR_SET_NOT_NOW          = 1013,
    MPI_T_ERR_CVAR_SET_NEVER            = 1014,
    MPI_T_ERR_PVAR_NO_WRITE             = 1015,
    MPI_T_ERR_PVAR_NO_STARTSTOP         = 1016,
    MPI_T_ERR_PVAR_NO_ATOMIC            = 1017,
    MPI_ERR_LASTCODE                    = 0x3fff // half of the minimum required value of INT_MAX
};
```

```c
// Buffer Address Constants
#define MPI_BOTTOM          ((void*)0)
#define MPI_IN_PLACE        ((void*)1)

// Constants Specifying Empty or Ignored Input
#define MPI_ARGV_NULL       ((char**)0)
#define MPI_ARGVS_NULL      ((char***)0)
#define MPI_ERRCODES_IGNORE ((int*)0)
#define MPI_STATUS_IGNORE   ((MPI_Status*)0)
#define MPI_STATUSES_IGNORE ((MPI_Status**)0)
#define MPI_UNWEIGHTED      ((int*)2)
#define MPI_WEIGHTS_EMPTY   ((int*)3)

// Other constants
#define MPI_BSEND_OVERHEAD                   512 // MPICH=96, OMPI=128

// String size constants
#define MPI_MAX_DATAREP_STRING               128 // MPICH=OMPI=128 (MPICH has it in `mpio.h`)
#define MPI_MAX_ERROR_STRING                 512 // MPICH was bigger
#define MPI_MAX_INFO_KEY                     256 // MPICH was bigger
#define MPI_MAX_INFO_VAL                    1024 // MPICH was bigger
#define MPI_MAX_LIBRARY_VERSION_STRING      8192 // MPICH was bigger
#define MPI_MAX_OBJECT_NAME                  128 // MPICH was bigger
#define MPI_MAX_PORT_NAME                   1024 // OMPI was bigger
#define MPI_MAX_PROCESSOR_NAME               256 // OMPI was bigger
#define MPI_MAX_STRINGTAG_LEN               1024 // OMPI was bigger (v5.0+)
#define MPI_MAX_PSET_NAME_LEN                512 // OMPI was bigger (v5.0+)
```

```c
// Mode Constants
// must be powers-of-2 to support OR-ing
enum {
    // Files
    MPI_MODE_APPEND             = 1,
    MPI_MODE_CREATE             = 2,
    MPI_MODE_DELETE_ON_CLOSE    = 4,
    MPI_MODE_EXCL               = 8,
    MPI_MODE_RDONLY             = 16,
    MPI_MODE_RDWR               = 32,
    MPI_MODE_SEQUENTIAL         = 64,
    MPI_MODE_UNIQUE_OPEN        = 128,
    MPI_MODE_WRONLY             = 256,
    // Windows
    MPI_MODE_NOCHECK            = 1024,
    MPI_MODE_NOPRECEDE          = 2048,
    MPI_MODE_NOPUT              = 4096,
    MPI_MODE_NOSTORE            = 8192,
    MPI_MODE_NOSUCCEED          = 16384
};
```

```c
enum {
    // rank sentinels - must be negative
    MPI_ANY_SOURCE      = -1,
    MPI_PROC_NULL       = -2,
    MPI_ROOT            = -3,

    // tag sentinels - should be negative
    MPI_ANY_TAG         = -101,

    // These apply to MPI_COMM_WORLD
    MPI_TAG_UB          = -201,
    MPI_IO              = -202,
    MPI_HOST            = -203,
    MPI_WTIME_IS_GLOBAL = -204,
    MPI_APPNUM          = -205,
    MPI_LASTUSEDCODE    = -206,
    MPI_UNIVERSE_SIZE   = -207,

    // Predefined Attribute Keys
    // These apply to Windows
    MPI_WIN_BASE            = -301,
    MPI_WIN_DISP_UNIT       = -302,
    MPI_WIN_SIZE            = -303,
    MPI_WIN_CREATE_FLAVOR   = -304,
    MPI_WIN_MODEL           = -305,

    // attribute constant - should be negative
    MPI_KEYVAL_INVALID  = -401,

    // special displacement for sequential access file - should be negative
    MPI_DISPLACEMENT_CURRENT = -501,

    // multi-purpose sentinel - must be negative
    MPI_UNDEFINED       = -601,

    //Results of communicator and group comparisons
    MPI_IDENT       = -701,
    MPI_CONGRUENT   = -702,
    MPI_SIMILAR     = -703,
    MPI_UNEQUAL     = -704,

    // Environmental inquiry keys and Predefined Attribute Keys
    // Threads Constants
    // These values are monotonic; i.e., SINGLE < FUNNELED < SERIALIZED < MULTIPLE.
    MPI_THREAD_MULTIPLE     = -801,
    MPI_THREAD_SERIALIZED   = -802,
    MPI_THREAD_FUNNELED     = -803,
    MPI_THREAD_SINGLE       = -804,

    // RMA lock constants - arbitrary values
    MPI_LOCK_EXCLUSIVE  = -901,
    MPI_LOCK_SHARED     = -902,

    // Communicator split type constants - arbitrary values
    MPI_COMM_TYPE_SHARED        = -1001,
    MPI_COMM_TYPE_HW_UNGUIDED   = -1002,
    MPI_COMM_TYPE_HW_GUIDED     = -1003,

    // MPI Window Create Flavors
    MPI_WIN_FLAVOR_ALLOCATE = -1101,
    MPI_WIN_FLAVOR_CREATE   = -1102,
    MPI_WIN_FLAVOR_DYNAMIC  = -1103,
    MPI_WIN_FLAVOR_SHARED   = -1104,

    // MPI Window Models
    MPI_WIN_SEPARATE    = -1201,
    MPI_WIN_UNIFIED     = -1202,

    // Datatype Decoding Constants
    MPI_COMBINER_NAMED              = -1301,
    MPI_COMBINER_DUP                = -1302,
    MPI_COMBINER_CONTIGUOUS         = -1303,
    MPI_COMBINER_VECTOR             = -1304,
    MPI_COMBINER_HVECTOR            = -1305,
    MPI_COMBINER_INDEXED            = -1306,
    MPI_COMBINER_HINDEXED           = -1307,
    MPI_COMBINER_INDEXED_BLOCK      = -1308,
    MPI_COMBINER_HINDEXED_BLOCK     = -1309,
    MPI_COMBINER_STRUCT             = -1310,
    MPI_COMBINER_SUBARRAY           = -1311,
    MPI_COMBINER_DARRAY             = -1312,
    MPI_COMBINER_F90_REAL           = -1313,
    MPI_COMBINER_F90_COMPLEX        = -1314,
    MPI_COMBINER_F90_INTEGER        = -1315,
    MPI_COMBINER_RESIZED            = -1316,

    // File Operation Constants (?)
    MPI_DISTRIBUTE_BLOCK        = -1401,
    MPI_DISTRIBUTE_CYCLIC       = -1402,
    MPI_DISTRIBUTE_DFLT_DARG    = -1403,
    MPI_DISTRIBUTE_NONE         = -1404,

    MPI_ORDER_C                 = -1501,
    MPI_ORDER_FORTRAN           = -1502,

    MPI_SEEK_CUR                = -1601,
    MPI_SEEK_END                = -1602,
    MPI_SEEK_SET                = -1603,

    // F90 Datatype Matching Constants
    MPI_TYPECLASS_REAL          = -1701,
    MPI_TYPECLASS_COMPLEX       = -1702,
    MPI_TYPECLASS_INTEGER       = -1703,

    // MPI_Topo_test
    MPI_GRAPH                   = -1801,
    MPI_DIST_GRAPH              = -1802,
    MPI_CART                    = -1803
}
```

```c
#define MPI_NULL_COPY_FN         ((MPI_Copy_function*)0x0)
#define MPI_DUP_FN               ((MPI_Copy_function*)0x1)
#define MPI_NULL_DELETE_FN       ((MPI_Delete_function*)0x0)
#define MPI_COMM_NULL_COPY_FN    ((MPI_Comm_copy_attr_function*)0x0)
#define MPI_COMM_DUP_FN          ((MPI_Comm_copy_attr_function*)0x1)
#define MPI_COMM_NULL_DELETE_FN  ((MPI_Comm_delete_attr_function*)0x0)
#define MPI_TYPE_NULL_COPY_FN    ((MPI_Type_copy_attr_function*)0x0)
#define MPI_TYPE_DUP_FN          ((MPI_Type_copy_attr_function*)0x1)
#define MPI_TYPE_NULL_DELETE_FN  ((MPI_Type_delete_attr_function*)0x0)
#define MPI_WIN_NULL_COPY_FN     ((MPI_Win_copy_attr_function*)0x0)
#define MPI_WIN_DUP_FN           ((MPI_Win_copy_attr_function*)0x1)
#define MPI_WIN_NULL_DELETE_FN   ((MPI_Win_delete_attr_function*)0x0)
#define MPI_CONVERSION_FN_NULL   ((MPI_Datarep_conversion_function)0x0)
#define MPI_CONVERSION_FN_NULL_C ((MPI_Datarep_conversion_function_c)0x0)
```
