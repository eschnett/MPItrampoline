constants_fortran = [
    ("MPI_Fint", "MPI_ANY_SOURCE"),
    ("MPI_Fint", "MPI_ANY_TAG"),
    ("MPI_Fint", "MPI_PROC_NULL"),
    ("MPI_Fint", "MPI_ROOT"),

    ("MPI_Fint", "MPI_CART"),
    ("MPI_Fint", "MPI_DIST_GRAPH"),
    ("MPI_Fint", "MPI_GRAPH"),

    # Results of compare operations
    ("MPI_Fint", "MPI_CONGRUENT"),
    ("MPI_Fint", "MPI_IDENT"),
    ("MPI_Fint", "MPI_SIMILAR"),
    ("MPI_Fint", "MPI_UNEQUAL"),

    ("MPI_Fint", "MPI_ERROR"),
    ("MPI_Fint", "MPI_SOURCE"),
    ("MPI_Fint", "MPI_TAG"),

    # Predefined constants
    ("MPI_Fint", "MPI_BSEND_OVERHEAD"),
    ("MPI_Fint", "MPI_KEYVAL_INVALID"),
    ("MPI_Fint", "MPI_UNDEFINED"),

    ("MPI_Fint", "MPI_COMBINER_CONTIGUOUS"),
    ("MPI_Fint", "MPI_COMBINER_DARRAY"),
    ("MPI_Fint", "MPI_COMBINER_DUP"),
    ("MPI_Fint", "MPI_COMBINER_F90_COMPLEX"),
    ("MPI_Fint", "MPI_COMBINER_F90_INTEGER"),
    ("MPI_Fint", "MPI_COMBINER_F90_REAL"),
    ("MPI_Fint", "MPI_COMBINER_HINDEXED"),
    ("MPI_Fint", "MPI_COMBINER_HINDEXED_BLOCK"),
    # ("MPI_Fint", "MPI_COMBINER_HINDEXED_INTEGER"),
    ("MPI_Fint", "MPI_COMBINER_HVECTOR"),
    # ("MPI_Fint", "MPI_COMBINER_HVECTOR_INTEGER"),
    ("MPI_Fint", "MPI_COMBINER_INDEXED"),
    ("MPI_Fint", "MPI_COMBINER_INDEXED_BLOCK"),
    ("MPI_Fint", "MPI_COMBINER_NAMED"),
    ("MPI_Fint", "MPI_COMBINER_RESIZED"),
    ("MPI_Fint", "MPI_COMBINER_STRUCT"),
    # ("MPI_Fint", "MPI_COMBINER_STRUCT_INTEGER"),
    ("MPI_Fint", "MPI_COMBINER_SUBARRAY"),
    ("MPI_Fint", "MPI_COMBINER_VECTOR"),

    ("MPI_Fint", "MPI_COMM_TYPE_SHARED"),

    # File operation constants
    ("MPI_Fint", "MPI_DISTRIBUTE_BLOCK"),
    ("MPI_Fint", "MPI_DISTRIBUTE_CYCLIC"),
    ("MPI_Fint", "MPI_DISTRIBUTE_DFLT_DARG"),
    ("MPI_Fint", "MPI_DISTRIBUTE_NONE"),

    ("MPI_Fint", "MPI_ERR_ACCESS"),
    ("MPI_Fint", "MPI_ERR_AMODE"),
    ("MPI_Fint", "MPI_ERR_ARG"),
    ("MPI_Fint", "MPI_ERR_ASSERT"),
    ("MPI_Fint", "MPI_ERR_BAD_FILE"),
    ("MPI_Fint", "MPI_ERR_BASE"),
    ("MPI_Fint", "MPI_ERR_BUFFER"),
    ("MPI_Fint", "MPI_ERR_COMM"),
    ("MPI_Fint", "MPI_ERR_CONVERSION"),
    ("MPI_Fint", "MPI_ERR_COUNT"),
    ("MPI_Fint", "MPI_ERR_DIMS"),
    ("MPI_Fint", "MPI_ERR_DISP"),
    ("MPI_Fint", "MPI_ERR_DUP_DATAREP"),
    ("MPI_Fint", "MPI_ERR_FILE"),
    ("MPI_Fint", "MPI_ERR_FILE_EXISTS"),
    ("MPI_Fint", "MPI_ERR_FILE_IN_USE"),
    ("MPI_Fint", "MPI_ERR_GROUP"),
    ("MPI_Fint", "MPI_ERR_INFO"),
    ("MPI_Fint", "MPI_ERR_INFO_KEY"),
    ("MPI_Fint", "MPI_ERR_INFO_NOKEY"),
    ("MPI_Fint", "MPI_ERR_INFO_VALUE"),
    ("MPI_Fint", "MPI_ERR_INTERN"),
    ("MPI_Fint", "MPI_ERR_IN_STATUS"),
    ("MPI_Fint", "MPI_ERR_IO"),
    ("MPI_Fint", "MPI_ERR_KEYVAL"),
    ("MPI_Fint", "MPI_ERR_LOCKTYPE"),
    ("MPI_Fint", "MPI_ERR_NAME"),
    ("MPI_Fint", "MPI_ERR_NOT_SAME"),
    ("MPI_Fint", "MPI_ERR_NO_MEM"),
    ("MPI_Fint", "MPI_ERR_NO_SPACE"),
    ("MPI_Fint", "MPI_ERR_NO_SUCH_FILE"),
    ("MPI_Fint", "MPI_ERR_OP"),
    ("MPI_Fint", "MPI_ERR_OTHER"),
    ("MPI_Fint", "MPI_ERR_PENDING"),
    ("MPI_Fint", "MPI_ERR_PORT"),
    ("MPI_Fint", "MPI_ERR_QUOTA"),
    ("MPI_Fint", "MPI_ERR_RANK"),
    ("MPI_Fint", "MPI_ERR_READ_ONLY"),
    ("MPI_Fint", "MPI_ERR_REQUEST"),
    ("MPI_Fint", "MPI_ERR_RMA_ATTACH"),
    ("MPI_Fint", "MPI_ERR_RMA_CONFLICT"),
    ("MPI_Fint", "MPI_ERR_RMA_FLAVOR"),
    ("MPI_Fint", "MPI_ERR_RMA_RANGE"),
    ("MPI_Fint", "MPI_ERR_RMA_SHARED"),
    ("MPI_Fint", "MPI_ERR_RMA_SYNC"),
    ("MPI_Fint", "MPI_ERR_ROOT"),
    ("MPI_Fint", "MPI_ERR_SERVICE"),
    ("MPI_Fint", "MPI_ERR_SIZE"),
    ("MPI_Fint", "MPI_ERR_SPAWN"),
    ("MPI_Fint", "MPI_ERR_TAG"),
    ("MPI_Fint", "MPI_ERR_TOPOLOGY"),
    ("MPI_Fint", "MPI_ERR_TRUNCATE"),
    ("MPI_Fint", "MPI_ERR_TYPE"),
    ("MPI_Fint", "MPI_ERR_UNKNOWN"),
    ("MPI_Fint", "MPI_ERR_UNSUPPORTED_DATAREP"),
    ("MPI_Fint", "MPI_ERR_UNSUPPORTED_OPERATION"),
    ("MPI_Fint", "MPI_ERR_WIN"),
    ("MPI_Fint", "MPI_SUCCESS"),

    ("MPI_Fint", "MPI_LOCK_EXCLUSIVE"),
    ("MPI_Fint", "MPI_LOCK_SHARED"),

    ("MPI_Fint", "MPI_MODE_APPEND"),
    ("MPI_Fint", "MPI_MODE_CREATE"),
    ("MPI_Fint", "MPI_MODE_DELETE_ON_CLOSE"),
    ("MPI_Fint", "MPI_MODE_EXCL"),
    ("MPI_Fint", "MPI_MODE_NOCHECK"),
    ("MPI_Fint", "MPI_MODE_NOPRECEDE"),
    ("MPI_Fint", "MPI_MODE_NOPUT"),
    ("MPI_Fint", "MPI_MODE_NOSTORE"),
    ("MPI_Fint", "MPI_MODE_NOSUCCEED"),
    ("MPI_Fint", "MPI_MODE_RDONLY"),
    ("MPI_Fint", "MPI_MODE_RDWR"),
    ("MPI_Fint", "MPI_MODE_SEQUENTIAL"),
    ("MPI_Fint", "MPI_MODE_UNIQUE_OPEN"),
    ("MPI_Fint", "MPI_MODE_WRONLY"),

    # File operation constants
    ("MPI_Fint", "MPI_ORDER_C"),
    ("MPI_Fint", "MPI_ORDER_FORTRAN"),

    # File operation constants
    ("MPI_Fint", "MPI_SEEK_CUR"),
    ("MPI_Fint", "MPI_SEEK_END"),
    ("MPI_Fint", "MPI_SEEK_SET"),

    # Thread support
    ("MPI_Fint", "MPI_THREAD_SINGLE"),
    ("MPI_Fint", "MPI_THREAD_FUNNELED"),
    ("MPI_Fint", "MPI_THREAD_SERIALIZED"),
    ("MPI_Fint", "MPI_THREAD_MULTIPLE"),

    # File operation constants
    ("MPI_Fint", "MPI_TYPECLASS_COMPLEX"),
    ("MPI_Fint", "MPI_TYPECLASS_INTEGER"),
    ("MPI_Fint", "MPI_TYPECLASS_REAL"),

    # Windows
    ("MPI_Fint", "MPI_WIN_FLAVOR_ALLOCATE"),
    ("MPI_Fint", "MPI_WIN_FLAVOR_CREATE"),
    ("MPI_Fint", "MPI_WIN_FLAVOR_DYNAMIC"),
    ("MPI_Fint", "MPI_WIN_FLAVOR_SHARED"),
    ("MPI_Fint", "MPI_WIN_SEPARATE"),
    ("MPI_Fint", "MPI_WIN_UNIFIED"),

    # (Declared manually)
    # ("char **", "MPI_ARGV_NULL"),
    # ("char ***", "MPI_ARGVS_NULL"),

    # (Declared manually)
    # ("int *", "MPI_ERRCODES_IGNORE"),
    # ("int *", "MPI_UNWEIGHTED"),
    # ("int *", "MPI_WEIGHTS_EMPTY"),

    # (Declared manually)
    # ("void *", "MPI_BOTTOM"),

    # (Declared manually)
    # ("void *", "MPI_IN_PLACE"),

    ("MPI_Comm", "MPI_COMM_NULL"),
    ("MPI_Comm", "MPI_COMM_SELF"),
    ("MPI_Comm", "MPI_COMM_WORLD"),

    # ("MPI_Comm_copy_attr_function *", "MPI_COMM_DUP_FN"),
    # ("MPI_Comm_copy_attr_function *", "MPI_COMM_NULL_COPY_FN"),

    # ("MPI_Comm_delete_attr_function *", "MPI_COMM_NULL_DELETE_FN"),

    # ("MPI_Copy_function *", "MPI_DUP_FN"),
    # ("MPI_Copy_function *", "MPI_NULL_COPY_FN"),

    # ("MPI_Datarep_conversion_function *", "MPI_CONVERSION_FN_NULL"),

    # ("MPI_Datatype", "MPI_2COMPLEX"),
    # ("MPI_Datatype", "MPI_2DOUBLE"),
    # ("MPI_Datatype", "MPI_2DOUBLE_COMPLEX"),
    ("MPI_Datatype", "MPI_2DOUBLE_PRECISION"),
    # ("MPI_Datatype", "MPI_2FLOAT"),
    ("MPI_Datatype", "MPI_2INT"),
    ("MPI_Datatype", "MPI_2INTEGER"),
    ("MPI_Datatype", "MPI_2REAL"),
    ("MPI_Datatype", "MPI_AINT"),
    ("MPI_Datatype", "MPI_BYTE"),
    ("MPI_Datatype", "MPI_CHAR"),
    ("MPI_Datatype", "MPI_CHARACTER"),
    ("MPI_Datatype", "MPI_COMPLEX"),
    ("MPI_Datatype", "MPI_COMPLEX16"),
    ("MPI_Datatype", "MPI_COMPLEX32"),
    # ("MPI_Datatype", "MPI_COMPLEX4"),
    ("MPI_Datatype", "MPI_COMPLEX8"),
    ("MPI_Datatype", "MPI_COUNT"),
    ("MPI_Datatype", "MPI_CXX_BOOL"),
    ("MPI_Datatype", "MPI_CXX_DOUBLE_COMPLEX"),
    ("MPI_Datatype", "MPI_CXX_FLOAT_COMPLEX"),
    ("MPI_Datatype", "MPI_CXX_LONG_DOUBLE_COMPLEX"),
    ("MPI_Datatype", "MPI_C_BOOL"),
    ("MPI_Datatype", "MPI_C_COMPLEX"),
    ("MPI_Datatype", "MPI_C_DOUBLE_COMPLEX"),
    ("MPI_Datatype", "MPI_C_FLOAT_COMPLEX"),
    ("MPI_Datatype", "MPI_C_LONG_DOUBLE_COMPLEX"),
    ("MPI_Datatype", "MPI_DATATYPE_NULL"),
    ("MPI_Datatype", "MPI_DOUBLE"),
    ("MPI_Datatype", "MPI_DOUBLE_COMPLEX"),
    ("MPI_Datatype", "MPI_DOUBLE_INT"),
    ("MPI_Datatype", "MPI_DOUBLE_PRECISION"),
    ("MPI_Datatype", "MPI_FLOAT"),
    ("MPI_Datatype", "MPI_FLOAT_INT"),
    ("MPI_Datatype", "MPI_INT"),
    ("MPI_Datatype", "MPI_INT16_T"),
    ("MPI_Datatype", "MPI_INT32_T"),
    ("MPI_Datatype", "MPI_INT64_T"),
    ("MPI_Datatype", "MPI_INT8_T"),
    ("MPI_Datatype", "MPI_INTEGER"),
    ("MPI_Datatype", "MPI_INTEGER1"),
    # ("MPI_Datatype", "MPI_INTEGER16"),
    ("MPI_Datatype", "MPI_INTEGER2"),
    ("MPI_Datatype", "MPI_INTEGER4"),
    ("MPI_Datatype", "MPI_INTEGER8"),
    # ("MPI_Datatype", "MPI_LB"),
    ("MPI_Datatype", "MPI_LOGICAL"),
    # ("MPI_Datatype", "MPI_LOGICAL1"),
    # ("MPI_Datatype", "MPI_LOGICAL2"),
    # ("MPI_Datatype", "MPI_LOGICAL4"),
    # ("MPI_Datatype", "MPI_LOGICAL8"),
    ("MPI_Datatype", "MPI_LONG"),
    ("MPI_Datatype", "MPI_LONG_DOUBLE"),
    ("MPI_Datatype", "MPI_LONG_DOUBLE_INT"),
    ("MPI_Datatype", "MPI_LONG_INT"),
    ("MPI_Datatype", "MPI_LONG_LONG"),
    ("MPI_Datatype", "MPI_LONG_LONG_INT"),
    ("MPI_Datatype", "MPI_OFFSET"),
    ("MPI_Datatype", "MPI_PACKED"),
    ("MPI_Datatype", "MPI_REAL"),
    ("MPI_Datatype", "MPI_REAL16"),
    # ("MPI_Datatype", "MPI_REAL2"),
    ("MPI_Datatype", "MPI_REAL4"),
    ("MPI_Datatype", "MPI_REAL8"),
    ("MPI_Datatype", "MPI_SHORT"),
    ("MPI_Datatype", "MPI_SHORT_INT"),
    ("MPI_Datatype", "MPI_SIGNED_CHAR"),
    # ("MPI_Datatype", "MPI_UB"),
    ("MPI_Datatype", "MPI_UINT16_T"),
    ("MPI_Datatype", "MPI_UINT32_T"),
    ("MPI_Datatype", "MPI_UINT64_T"),
    ("MPI_Datatype", "MPI_UINT8_T"),
    ("MPI_Datatype", "MPI_UNSIGNED"),
    ("MPI_Datatype", "MPI_UNSIGNED_CHAR"),
    ("MPI_Datatype", "MPI_UNSIGNED_LONG"),
    ("MPI_Datatype", "MPI_UNSIGNED_LONG_LONG"),
    ("MPI_Datatype", "MPI_UNSIGNED_SHORT"),
    ("MPI_Datatype", "MPI_WCHAR"),

    # ("MPI_Delete_function *", "MPI_NULL_DELETE_FN"),

    ("MPI_Errhandler", "MPI_ERRHANDLER_NULL"),
    ("MPI_Errhandler", "MPI_ERRORS_ARE_FATAL"),
    ("MPI_Errhandler", "MPI_ERRORS_RETURN"),

    ("MPI_File", "MPI_FILE_NULL"),

    ("MPI_Group", "MPI_GROUP_EMPTY"),
    ("MPI_Group", "MPI_GROUP_NULL"),

    ("MPI_Info", "MPI_INFO_ENV"),
    ("MPI_Info", "MPI_INFO_NULL"),

    ("MPI_Message", "MPI_MESSAGE_NO_PROC"),
    ("MPI_Message", "MPI_MESSAGE_NULL"),

    # File operation constants
    ("MPI_Offset", "MPI_DISPLACEMENT_CURRENT"),

    ("MPI_Op", "MPI_BAND"),
    ("MPI_Op", "MPI_BOR"),
    ("MPI_Op", "MPI_BXOR"),
    ("MPI_Op", "MPI_LAND"),
    ("MPI_Op", "MPI_LOR"),
    ("MPI_Op", "MPI_LXOR"),
    ("MPI_Op", "MPI_MAX"),
    ("MPI_Op", "MPI_MAXLOC"),
    ("MPI_Op", "MPI_MIN"),
    ("MPI_Op", "MPI_MINLOC"),
    ("MPI_Op", "MPI_NO_OP"),
    ("MPI_Op", "MPI_OP_NULL"),
    ("MPI_Op", "MPI_PROD"),
    ("MPI_Op", "MPI_REPLACE"),
    ("MPI_Op", "MPI_SUM"),

    ("MPI_Request", "MPI_REQUEST_NULL"),

    # (Declared manually)
    # ("MPI_Status *", "MPI_STATUS_IGNORE"),
    # ("MPI_Status *", "MPI_STATUSES_IGNORE"),

    # ("MPI_Type_copy_attr_function *", "MPI_TYPE_DUP_FN"),
    # ("MPI_Type_copy_attr_function *", "MPI_TYPE_NULL_COPY_FN"),

    # ("MPI_Type_delete_attr_function *", "MPI_TYPE_NULL_DELETE_FN"),

    ("MPI_Win", "MPI_WIN_NULL"),

    # ("MPI_Win_copy_attr_function *", "MPI_WIN_DUP_FN"),
    # ("MPI_Win_copy_attr_function *", "MPI_WIN_NULL_COPY_FN"),

    # ("MPI_Win_delete_attr_function *", "MPI_WIN_NULL_DELETE_FN"),
]
