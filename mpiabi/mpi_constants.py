constants = [
    ("int", "MPI_ANY_SOURCE"),                                  # mpich: -2; openmpi: -1
    ("int", "MPI_ANY_TAG"),                                     # mpich: -1; openmpi: -1
    ("int", "MPI_PROC_NULL"),                                   # mpich: -1; openmpi: -2
    ("int", "MPI_ROOT"),                                        # mpich: -3; openmpi: -4

    ("int", "MPI_CART"),                                        # mpich: 2; openmpi: 1
    ("int", "MPI_DIST_GRAPH"),                                  # mpich: 3; openmpi: 3
    ("int", "MPI_GRAPH"),                                       # mpich: 1; openmpi: 2

    # Results of compare operations
    ("int", "MPI_CONGRUENT"),                                   # mpich: 1; openmpi: 1
    ("int", "MPI_IDENT"),                                       # mpich: 0; openmpi: 0
    ("int", "MPI_SIMILAR"),                                     # mpich: 2; openmpi: 2
    ("int", "MPI_UNEQUAL"),                                     # mpich: 3; openmpi: 3

    # Predefined constants
    ("int", "MPI_BSEND_OVERHEAD"),                              # openmpi: 128
    ("int", "MPI_KEYVAL_INVALID"),                              # mpich: 0x24000000; openmpi: -1
    ("int", "MPI_UNDEFINED"),                                   # mpich: -32766;     openmpi: -32766

    # Key values
    ("int", "MPI_APPNUM"),                                      # mpich: 0x6440000d; openmpi: 4
    ("int", "MPI_HOST"),                                        # mpich: 0x64400003; openmpi: 1
    ("int", "MPI_IO"),                                          # mpich: 0x64400005; openmpi: 2
    ("int", "MPI_LASTUSEDCODE"),                                # mpich: 0x6440000b; openmpi: 5
    ("int", "MPI_TAG_UB"),                                      # mpich: 0x64400001; openmpi: 0
    ("int", "MPI_UNIVERSE_SIZE"),                               # mpich: 0x64400009; openmpi: 6
    ("int", "MPI_WIN_BASE"),                                    # mpich: 0x66000001; openmpi: 7
    ("int", "MPI_WIN_CREATE_FLAVOR"),                           # mpich: 0x66000007; openmpi: 10
    ("int", "MPI_WIN_DISP_UNIT"),                               # mpich: 0x66000005; openmpi: 9
    ("int", "MPI_WIN_MODEL"),                                   # mpich: 0x66000009; openmpi: 11
    ("int", "MPI_WIN_SIZE"),                                    # mpich: 0x66000003; openmpi: 8
    ("int", "MPI_WTIME_IS_GLOBAL"),                             # mpich: 0x64400007; openmpi: 3

    ("int", "MPI_COMBINER_CONTIGUOUS"),                         # mpich: 3;  openmpi: 2
    ("int", "MPI_COMBINER_DARRAY"),                             # mpich: 14; openmpi: 13
    ("int", "MPI_COMBINER_DUP"),                                # mpich: 2;  openmpi: 1
    ("int", "MPI_COMBINER_F90_COMPLEX"),                        # mpich: 16; openmpi: 15
    ("int", "MPI_COMBINER_F90_INTEGER"),                        # mpich: 17; openmpi: 16
    ("int", "MPI_COMBINER_F90_REAL"),                           # mpich: 15; openmpi: 14
    ("int", "MPI_COMBINER_HINDEXED"),                           # mpich: 9;  openmpi: 8
    ("int", "MPI_COMBINER_HINDEXED_BLOCK"),                     # mpich: 10; openmpi: 9
    # ("int", "MPI_COMBINER_HINDEXED_INTEGER"),                 # mpich: 8;  openmpi: 7
    ("int", "MPI_COMBINER_HVECTOR"),                            # mpich: 6;  openmpi: 5
    # ("int", "MPI_COMBINER_HVECTOR_INTEGER"),                  # mpich: 5;  openmpi: 4
    ("int", "MPI_COMBINER_INDEXED"),                            # mpich: 7;  openmpi: 6
    ("int", "MPI_COMBINER_INDEXED_BLOCK"),                      # mpich: 19; openmpi: 18
    ("int", "MPI_COMBINER_NAMED"),                              # mpich: 1;  openmpi: 0
    ("int", "MPI_COMBINER_RESIZED"),                            # mpich: 18; openmpi: 17
    ("int", "MPI_COMBINER_STRUCT"),                             # mpich: 12; openmpi: 11
    # ("int", "MPI_COMBINER_STRUCT_INTEGER"),                   # mpich: 11; openmpi: 10
    ("int", "MPI_COMBINER_SUBARRAY"),                           # mpich: 13; openmpi: 12
    ("int", "MPI_COMBINER_VECTOR"),                             # mpich: 4;  openmpi: 3

    ("int", "MPI_COMM_TYPE_SHARED"),                            # mpich: 1; openmpi: 0

    # File operation constants
    ("int", "MPI_DISTRIBUTE_BLOCK"),                            # mpich: 121;    openmpi: 0
    ("int", "MPI_DISTRIBUTE_CYCLIC"),                           # mpich: 122;    openmpi: 1
    ("int", "MPI_DISTRIBUTE_DFLT_DARG"),                        # mpich: -49767; openmpi: -1
    ("int", "MPI_DISTRIBUTE_NONE"),                             # mpich: 123;    openmpi: 2

    # mpich: small integers (below less than 100)
    # openmpi: small integers (below less than 100)
    ("int", "MPI_ERR_ACCESS"),
    ("int", "MPI_ERR_AMODE"),
    ("int", "MPI_ERR_ARG"),
    ("int", "MPI_ERR_ASSERT"),
    ("int", "MPI_ERR_BAD_FILE"),
    ("int", "MPI_ERR_BASE"),
    ("int", "MPI_ERR_BUFFER"),
    ("int", "MPI_ERR_COMM"),
    ("int", "MPI_ERR_CONVERSION"),
    ("int", "MPI_ERR_COUNT"),
    ("int", "MPI_ERR_DIMS"),
    ("int", "MPI_ERR_DISP"),
    ("int", "MPI_ERR_DUP_DATAREP"),
    ("int", "MPI_ERR_FILE"),
    ("int", "MPI_ERR_FILE_EXISTS"),
    ("int", "MPI_ERR_FILE_IN_USE"),
    ("int", "MPI_ERR_GROUP"),
    ("int", "MPI_ERR_INFO"),
    ("int", "MPI_ERR_INFO_KEY"),
    ("int", "MPI_ERR_INFO_NOKEY"),
    ("int", "MPI_ERR_INFO_VALUE"),
    ("int", "MPI_ERR_INTERN"),
    ("int", "MPI_ERR_IN_STATUS"),
    ("int", "MPI_ERR_IO"),
    ("int", "MPI_ERR_KEYVAL"),
    ("int", "MPI_ERR_LASTCODE"),                                # mpich: 0x3fffffff; openmpi: 92
    ("int", "MPI_ERR_LOCKTYPE"),
    ("int", "MPI_ERR_NAME"),
    ("int", "MPI_ERR_NOT_SAME"),
    ("int", "MPI_ERR_NO_MEM"),
    ("int", "MPI_ERR_NO_SPACE"),
    ("int", "MPI_ERR_NO_SUCH_FILE"),
    ("int", "MPI_ERR_OP"),
    ("int", "MPI_ERR_OTHER"),
    ("int", "MPI_ERR_PENDING"),
    ("int", "MPI_ERR_PORT"),
    ("int", "MPI_ERR_QUOTA"),
    ("int", "MPI_ERR_RANK"),
    ("int", "MPI_ERR_READ_ONLY"),
    ("int", "MPI_ERR_REQUEST"),
    ("int", "MPI_ERR_RMA_ATTACH"),
    ("int", "MPI_ERR_RMA_CONFLICT"),
    ("int", "MPI_ERR_RMA_FLAVOR"),
    ("int", "MPI_ERR_RMA_RANGE"),
    ("int", "MPI_ERR_RMA_SHARED"),
    ("int", "MPI_ERR_RMA_SYNC"),
    ("int", "MPI_ERR_ROOT"),
    ("int", "MPI_ERR_SERVICE"),
    ("int", "MPI_ERR_SIZE"),
    ("int", "MPI_ERR_SPAWN"),
    ("int", "MPI_ERR_TAG"),
    ("int", "MPI_ERR_TOPOLOGY"),
    ("int", "MPI_ERR_TRUNCATE"),
    ("int", "MPI_ERR_TYPE"),
    ("int", "MPI_ERR_UNKNOWN"),
    ("int", "MPI_ERR_UNSUPPORTED_DATAREP"),
    ("int", "MPI_ERR_UNSUPPORTED_OPERATION"),
    ("int", "MPI_ERR_WIN"),
    ("int", "MPI_SUCCESS"),                                     # mpich: 0; openmpi: 0

    ("int", "MPI_LOCK_EXCLUSIVE"),                              # mpich: 234; openmpi: 1
    ("int", "MPI_LOCK_SHARED"),                                 # mpich: 235; openmpi: 2

    ("int", "MPI_MODE_APPEND"),                                 # openmpi: 128
    ("int", "MPI_MODE_CREATE"),                                 # openmpi: 1
    ("int", "MPI_MODE_DELETE_ON_CLOSE"),                        # openmpi: 16
    ("int", "MPI_MODE_EXCL"),                                   # openmpi: 64
    ("int", "MPI_MODE_NOCHECK"),                                # mpich: 1024;  openmpi: 1
    ("int", "MPI_MODE_NOPRECEDE"),                              # mpich: 8192;  openmpi: 2
    ("int", "MPI_MODE_NOPUT"),                                  # mpich: 4096;  openmpi: 4
    ("int", "MPI_MODE_NOSTORE"),                                # mpich: 2048;  openmpi: 8
    ("int", "MPI_MODE_NOSUCCEED"),                              # mpich: 16384; openmpi: 16
    ("int", "MPI_MODE_RDONLY"),                                 # openmpi: 2
    ("int", "MPI_MODE_RDWR"),                                   # openmpi: 8
    ("int", "MPI_MODE_SEQUENTIAL"),                             # openmpi: 256
    ("int", "MPI_MODE_UNIQUE_OPEN"),                            # openmpi: 32
    ("int", "MPI_MODE_WRONLY"),                                 # openmpi: 4

    # File operation constants
    ("int", "MPI_ORDER_C"),                                     # mpich: 56; openmpi: 0
    ("int", "MPI_ORDER_FORTRAN"),                               # mpich: 57; openmpi: 1

    # File operation constants
    ("int", "MPI_SEEK_CUR"),                                    # openmpi: 602
    ("int", "MPI_SEEK_END"),                                    # openmpi: 604
    ("int", "MPI_SEEK_SET"),                                    # openmpi: 600

    # Thread support
    ("int", "MPI_THREAD_FUNNELED"),                             # mpich: 1; openmpi: 1
    ("int", "MPI_THREAD_MULTIPLE"),                             # mpich: 3; openmpi: 3
    ("int", "MPI_THREAD_SERIALIZED"),                           # mpich: 2; openmpi: 2
    ("int", "MPI_THREAD_SINGLE"),                               # mpich: 0; openmpi: 0

    # File operation constants
    ("int", "MPI_TYPECLASS_COMPLEX"),                           # mpich: 3; openmpi: 3
    ("int", "MPI_TYPECLASS_INTEGER"),                           # mpich: 2; openmpi: 1
    ("int", "MPI_TYPECLASS_REAL"),                              # mpich: 1; openmpi: 2

    # Windows
    ("int", "MPI_WIN_FLAVOR_ALLOCATE"),                         # mpich: 2; openmpi: 2
    ("int", "MPI_WIN_FLAVOR_CREATE"),                           # mpich: 1; openmpi: 1
    ("int", "MPI_WIN_FLAVOR_DYNAMIC"),                          # mpich: 3; openmpi: 3
    ("int", "MPI_WIN_FLAVOR_SHARED"),                           # mpich: 4; openmpi: 4
    ("int", "MPI_WIN_SEPARATE"),                                # mpich: 1; openmpi: 1
    ("int", "MPI_WIN_UNIFIED"),                                 # mpich: 2; openmpi: 0

    ("char **", "MPI_ARGV_NULL"),                               # mpich: 0; openmpi: 0

    ("char ***", "MPI_ARGVS_NULL"),                             # mpich: 0; openmpi: 0

    ("int *", "MPI_ERRCODES_IGNORE"),                           # mpich: 0
    ("int *", "MPI_UNWEIGHTED"),                                # mpich: object address; openmpi: 2
    ("int *", "MPI_WEIGHTS_EMPTY"),                             # mpich: object address; openmpi: 3

    ("void *", "MPI_BOTTOM"),                                   # mpich: 0; openmpi: 1

    ("void *", "MPI_IN_PLACE"),                                 # mpich: -1; openmpi: 1

    ("MPI_Comm", "MPI_COMM_NULL"),                              # mpich: 0x04000000
    ("MPI_Comm", "MPI_COMM_SELF"),                              # mpich: 0x44000001
    ("MPI_Comm", "MPI_COMM_WORLD"),                             # mpich: 0x44000000

    ("MPI_Comm_copy_attr_function *", "MPI_COMM_DUP_FN"),
    ("MPI_Comm_copy_attr_function *", "MPI_COMM_NULL_COPY_FN"), # mpich: 0

    ("MPI_Comm_delete_attr_function *", "MPI_COMM_NULL_DELETE_FN"), # mpich: 0

    ("MPI_Copy_function *", "MPI_DUP_FN"),
    ("MPI_Copy_function *", "MPI_NULL_COPY_FN"),                # mpich: 0

    ("MPI_Datarep_conversion_function *", "MPI_CONVERSION_FN_NULL"), # openmpi: 0

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
    ("MPI_Datatype", "MPI_DATATYPE_NULL"),                      # mpich: 0x0c000000
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
    ("MPI_Datatype", "MPI_LONG_LONG"),                          # mpich: MPI_LONG_LONG_INT
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

    ("MPI_Delete_function *", "MPI_NULL_DELETE_FN"),             # mpich: 0

    ("MPI_Errhandler", "MPI_ERRHANDLER_NULL"),                   # mpich: 0x14000000
    ("MPI_Errhandler", "MPI_ERRORS_ARE_FATAL"),                  # mpich: 0x54000000
    ("MPI_Errhandler", "MPI_ERRORS_RETURN"),                     # mpich: 0x54000001

    ("MPI_File", "MPI_FILE_NULL"),

    ("MPI_Fint *", "MPI_F_STATUS_IGNORE"),
    ("MPI_Fint *", "MPI_F_STATUSES_IGNORE"),
    # ("MPI_F08_status *", "MPI_F08_STATUS_IGNORE"),
    # ("MPI_F08_status *", "MPI_F08_STATUSES_IGNORE"),

    ("MPI_Group", "MPI_GROUP_EMPTY"),                           # mpich: 0x48000000
    ("MPI_Group", "MPI_GROUP_NULL"),                            # mpich: 0x08000000

    ("MPI_Info", "MPI_INFO_ENV"),                               # mpich: 0x5c000001
    ("MPI_Info", "MPI_INFO_NULL"),                              # mpich: 0x1c000000

    ("MPI_Message", "MPI_MESSAGE_NO_PROC"),                     # mpich: 0x6c000000
    ("MPI_Message", "MPI_MESSAGE_NULL"),                        # mpich: 0x2c000000

    # File operation constants
    ("MPI_Offset", "MPI_DISPLACEMENT_CURRENT"),                 # openmpi: -54278278

    ("MPI_Op", "MPI_BAND"),                                     # mpich: 0x58000006
    ("MPI_Op", "MPI_BOR"),                                      # mpich: 0x58000008
    ("MPI_Op", "MPI_BXOR"),                                     # mpich: 0x5800000a
    ("MPI_Op", "MPI_LAND"),                                     # mpich: 0x58000005
    ("MPI_Op", "MPI_LOR"),                                      # mpich: 0x58000007
    ("MPI_Op", "MPI_LXOR"),                                     # mpich: 0x58000009
    ("MPI_Op", "MPI_MAX"),                                      # mpich: 0x58000001
    ("MPI_Op", "MPI_MAXLOC"),                                   # mpich: 0x5800000c
    ("MPI_Op", "MPI_MIN"),                                      # mpich: 0x58000002
    ("MPI_Op", "MPI_MINLOC"),                                   # mpich: 0x5800000b
    ("MPI_Op", "MPI_NO_OP"),                                    # mpich: 0x5800000e
    ("MPI_Op", "MPI_OP_NULL"),                                  # mpich: 0x18000000
    ("MPI_Op", "MPI_PROD"),                                     # mpich: 0x58000004
    ("MPI_Op", "MPI_REPLACE"),                                  # mpich: 0x5800000d
    ("MPI_Op", "MPI_SUM"),                                      # mpich: 0x58000003

    ("MPI_Request", "MPI_REQUEST_NULL"),                        # mpich: 0x2c000000

    ("MPI_Status *", "MPI_STATUS_IGNORE"),                      # mpich: 1; openmpi: 0
    ("MPI_Status *", "MPI_STATUSES_IGNORE"),                    # mpich: 1; openmpi: 0

    ("MPI_Type_copy_attr_function *", "MPI_TYPE_DUP_FN"),       # mpich: 0
    ("MPI_Type_copy_attr_function *", "MPI_TYPE_NULL_COPY_FN"), # mpich: 0

    ("MPI_Type_delete_attr_function *", "MPI_TYPE_NULL_DELETE_FN"),

    ("MPI_Win", "MPI_WIN_NULL"),                                # mpich: 0x20000000

    ("MPI_Win_copy_attr_function *", "MPI_WIN_DUP_FN"),
    ("MPI_Win_copy_attr_function *", "MPI_WIN_NULL_COPY_FN"),   # mpich: 0

    ("MPI_Win_delete_attr_function *", "MPI_WIN_NULL_DELETE_FN"), # mpich: 0
]
