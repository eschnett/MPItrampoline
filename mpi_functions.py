# The section names and function parameter names follow the MPI 3.1 standard

functions = [

    # 3.2 Blocking Send and Receive Operations

    ("int", "MPI_Send", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Recv", [
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Get_count", [
        ("MPI_Status *", "status"),
        ("MPI_Datatype", "datatype"),
        ("int *", "count"),
    ], None),

    # 3.4 Communication Modes

    ("int", "MPI_Bsend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Ssend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Rsend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
    ], None),

    # 3.6 Buffer Allocation and Usage

    ("int", "MPI_Buffer_attach", [
        ("void *", "buffer"),
        ("int", "size"),
    ], None),

    ("int", "MPI_Buffer_detach", [
        ("void *", "buffer_addr"),
        ("int *", "size"),
    ], None),

    # 3.7 Nonblocking Communication

    ("int", "MPI_Isend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ibsend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Issend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Irsend", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Irecv", [
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Wait", [
        ("MPI_Request *", "request"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Test", [
        ("MPI_Request *", "request"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Request_free", [
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Waitany", [
        ("int", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "index"),
        ("MPI_Status *", "status"),
    ], "manual"),

    ("int", "MPI_Testany", [
        ("int", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "index"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
    ], "manual"),

    ("int", "MPI_Waitall", [
        ("int", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("MPI_Status *", "array_of_statuses"),
    ], "manual"),

    ("int", "MPI_Testall", [
        ("int", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "flag"),
        ("MPI_Status *", "array_of_statuses"),
    ], "manual"),

    ("int", "MPI_Waitsome", [
        ("int", "incount"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "outcount"),
        ("int *", "array_of_indices"),
        ("MPI_Status *", "array_of_statuses"),
    ], "manual"),

    ("int", "MPI_Testsome", [
        ("int", "incount"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "outcount"),
        ("int *", "array_of_indices"),
        ("MPI_Status *", "array_of_statuses"),
    ], "manual"),

    ("int", "MPI_Request_get_status", [
        ("MPI_Request", "request"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
    ], None),

    # 3.8 Probe and Cancel

    ("int", "MPI_Iprobe", [
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Probe", [
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Improbe", [
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("int *", "flag"),
        ("MPI_Message *", "message"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Mprobe", [
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Message *", "message"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Mrecv", [
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Message *", "message"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Imrecv", [
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Message *", "message"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Cancel", [
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Test_cancelled", [
        ("const MPI_Status *", "status"),
        ("int *", "flag"),
    ], None),

    # 3.9 Persistent Communication Requests

    ("int", "MPI_Send_init", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Bsend_init", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ssend_init", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Rsend_init", [
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Recv_init", [
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "source"),
        ("int", "tag"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Start", [
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Startall", [
        ("int", "count"),
        ("MPI_Request *", "array_of_requests"),
    ], "manual"),

    # 3.10 Send-Receive

    ("int", "MPI_Sendrecv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("int", "dest"),
        ("int", "sendtag"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "source"),
        ("int", "recvtag"),
        ("MPI_Comm", "comm"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_Sendrecv_replace", [
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "dest"),
        ("int", "sendtag"),
        ("int", "source"),
        ("int", "recvtag"),
        ("MPI_Comm", "comm"),
        ("MPI_Status *", "status"),
    ], None),

    # 4.1 Derived Datatypes

    ("int", "MPI_Type_contiguous", [
        ("int", "count"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_vector", [
        ("int", "count"),
        ("int", "blocklength"),
        ("int", "stride"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_hvector", [
        ("int", "count"),
        ("int", "blocklength"),
        ("MPI_Aint", "stride"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_indexed", [
        ("int", "count"),
        ("const int *", "array_of_blocklengths"),
        ("const int *", "array_of_displacements"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_hindexed", [
        ("int", "count"),
        ("const int *", "array_of_blocklengths"),
        ("const MPI_Aint *", "array_of_displacements"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_indexed_block", [
        ("int", "count"),
        ("int", "blocklength"),
        ("const int *", "array_of_displacements"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_hindexed_block", [
        ("int", "count"),
        ("int", "blocklength"),
        ("const MPI_Aint *", "array_of_displacements"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_struct", [
        ("int", "count"),
        ("const int *", "array_of_blocklengths"),
        ("const MPI_Aint *", "array_of_displacements"),
        ("const MPI_Datatype *", "array_of_types"),
        ("MPI_Datatype *", "newtype"),
    ], "manual"),

    ("int", "MPI_Type_create_subarray", [
        ("int", "ndims"),
        ("const int *", "array_of_sizes"),
        ("const int *", "array_of_subsizes"),
        ("const int *", "array_of_starts"),
        ("int", "ordder"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_darray", [
        ("int", "size"),
        ("int", "rank"),
        ("int", "ndims"),
        ("const int *", "array_of_gsizes"),
        ("const int *", "array_of_distribs"),
        ("const int *", "array_of_dargs"),
        ("const int *", "array_of_psizes"),
        ("int", "order"),
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Get_address", [
        ("const void *", "location"),
        ("MPI_Aint *", "address"),
    ], None),

    ("MPI_Aint", "MPI_Aint_add", [
        ("MPI_Aint", "base"),
        ("MPI_Aint", "disp"),
    ], None),

    ("MPI_Aint", "MPI_Aint_diff", [
        ("MPI_Aint", "addr1"),
        ("MPI_Aint", "addr2"),
    ], None),

    ("int", "MPI_Type_size", [
        ("MPI_Datatype", "datatype"),
        ("int *", "size"),
    ], None),

    ("int", "MPI_Type_size_x", [
        ("MPI_Datatype", "datatype"),
        ("MPI_Count *", "size"),
    ], None),

    ("int", "MPI_Type_get_extent", [
        ("MPI_Datatype", "datatype"),
        ("MPI_Aint *", "lb"),
        ("MPI_Aint *", "extent"),
    ], None),

    ("int", "MPI_Type_get_extent_x", [
        ("MPI_Datatype", "datatype"),
        ("MPI_Count *", "lb"),
        ("MPI_Count *", "extent"),
    ], None),

    ("int", "MPI_Type_create_resized", [
        ("MPI_Datatype", "oldtype"),
        ("MPI_Aint", "lb"),
        ("MPI_Aint", "extent"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_get_true_extent", [
        ("MPI_Datatype", "datatype"),
        ("MPI_Aint *", "true_lb"),
        ("MPI_Aint *", "true_extent"),
    ], None),

    ("int", "MPI_Type_get_true_extent_x", [
        ("MPI_Datatype", "datatype"),
        ("MPI_Count *", "true_lb"),
        ("MPI_Count *", "true_extent"),
    ], None),

    ("int", "MPI_Type_commit", [
        ("MPI_Datatype *", "datatype"),
    ], None),

    ("int", "MPI_Type_free", [
        ("MPI_Datatype *", "datatype"),
    ], None),

    ("int", "MPI_Type_dup", [
        ("MPI_Datatype", "oldtype"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Get_elements", [
        ("const MPI_Status *", "status"),
        ("MPI_Datatype", "datatype"),
        ("int *", "count"),
    ], None),

    ("int", "MPI_Get_elements_x", [
        ("const MPI_Status *", "status"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Count *", "count"),
    ], None),

    ("int", "MPI_Type_get_envelope", [
        ("MPI_Datatype", "datatype"),
        ("int *", "num_integers"),
        ("int *", "num_addresses"),
        ("int *", "num_datatypes"),
        ("int *", "combiner"),
    ], None),

    ("int", "MPI_Type_get_contents", [
        ("MPI_Datatype", "datatype"),
        ("int", "max_integers"),
        ("int", "max_addresses"),
        ("int", "max_datatypes"),
        ("int *", "array_of_integers"),
        ("MPI_Aint *", "array_of_addresses"),
        ("MPI_Datatype *", "array_of_datatypes"),
    ], "manual"),

    # 4.2 Pack and Unpack

    ("int", "MPI_Pack", [
        ("const void *", "inbuf"),
        ("int", "incount"),
        ("MPI_Datatype", "datatype"),
        ("void *", "outbuf"),
        ("int", "outsize"),
        ("int *", "position"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Unpack", [
        ("const void *", "inbuf"),
        ("int", "insize"),
        ("int *", "position"),
        ("void *", "outbuf"),
        ("int", "outcount"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Pack_size", [
        ("int", "incount"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Comm", "comm"),
        ("int *", "size"),
    ], None),

    # 4.3 Canonical MPI_PACK and MPI_UNPACK

    ("int", "MPI_Pack_external", [
        ("const char *", "datarep"),
        ("const void *", "inbuf"),
        ("int", "incount"),
        ("MPI_Datatype", "datatype"),
        ("void *", "outbuf"),
        ("MPI_Aint", "outsize"),
        ("MPI_Aint *", "position"),
    ], None),

    ("int", "MPI_Unpack_external", [
        ("const char *", "datarep"),
        ("const void *", "inbuf"),
        ("MPI_Aint", "insize"),
        ("MPI_Aint *", "position"),
        ("void *", "outbuf"),
        ("int", "outcount"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_Pack_external_size", [
        ("const char *", "datarep"),
        ("int", "incount"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Aint *", "size"),
    ], None),

    # 5.3 Barrier Synchronization

    ("int", "MPI_Barrier", [
        ("MPI_Comm", "comm"),
    ], None),

    # 5.4 Broadcast

    ("int", "MPI_Bcast", [
        ("void *", "buffer"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
    ], None),

    # 5.5 Gather

    ("int", "MPI_Gather", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Gatherv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
    ], None),

    # 5.6 Scatter

    ("int", "MPI_Scatter", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Scatterv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
    ], None),

    # 5.7 Gather-to-all

    ("int", "MPI_Allgather", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Allgatherv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    # 5.8 All-to-All Scatter/Gather

    ("int", "MPI_Alltoall", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Alltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Alltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("MPI_Comm", "comm"),
    ], "manual"),

    # 5.9 Global Reduction Operations

    ("int", "MPI_Reduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Op_create", [
        ("MPI_User_function *", "user_fn"),
        ("int", "commute"),
        ("MPI_Op *", "op"),
    ], "manual"),

    ("int", "MPI_Op_free", [
        ("MPI_Op *", "op"),
    ], "manual"),

    ("int", "MPI_Allreduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Op_commutative", [
        ("MPI_Op", "op"),
        ("int *", "commute"),
    ], None),

    ("int", "MPI_Reduce_local", [
        ("const void *", "inbuf"),
        ("void *", "inoutbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
    ], None),

    # 5.10 Reduce-Scatter

    ("int", "MPI_Reduce_scatter_block", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Reduce_scatter", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
    ], None),

    # 5.11 Scan

    ("int", "MPI_Scan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Exscan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
    ], None),

    # 5.12 Nonblocking Collective Operations

    ("int", "MPI_Ibarrier", [
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ibcast", [
        ("void *", "buffer"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Igather", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Igatherv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iscatter", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iscatterv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iallgather", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iallgatherv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ialltoall", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ialltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ialltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], "manual"),

    ("int", "MPI_Ireduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iallreduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ireduce_scatter_block", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ireduce_scatter", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iscan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Iexscan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Op", "op"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    # 6.3 Group Management

    ("int", "MPI_Group_size", [
        ("MPI_Group", "group"),
        ("int *", "size"),
    ], None),

    ("int", "MPI_Group_rank", [
        ("MPI_Group", "group"),
        ("int *", "rank"),
    ], None),

    ("int", "MPI_Group_translate_ranks", [
        ("MPI_Group", "group1"),
        ("int", "n"),
        ("const int *", "ranks1"),
        ("MPI_Group", "group2"),
        ("int *", "ranks2"),
    ], None),

    ("int", "MPI_Group_compare", [
        ("MPI_Group", "group1"),
        ("MPI_Group", "group2"),
        ("int *", "result"),
    ], None),

    ("int", "MPI_Comm_group", [
        ("MPI_Comm", "comm"),
        ("MPI_Group *", "group"),
    ], None),

    ("int", "MPI_Group_union", [
        ("MPI_Group", "group1"),
        ("MPI_Group", "group2"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_intersection", [
        ("MPI_Group", "group1"),
        ("MPI_Group", "group2"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_difference", [
        ("MPI_Group", "group1"),
        ("MPI_Group", "group2"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_incl", [
        ("MPI_Group", "group"),
        ("int", "n"),
        ("const int *", "ranks"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_excl", [
        ("MPI_Group", "group"),
        ("int", "n"),
        ("const int *", "ranks"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_range_incl", [
        ("MPI_Group", "group"),
        ("int", "n"),
        ("MPIABI_array_int_3 *", "ranges"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_range_excl", [
        ("MPI_Group", "group"),
        ("int", "n"),
        ("MPIABI_array_int_3 *", "ranges"),
        ("MPI_Group *", "newgroup"),
    ], None),

    ("int", "MPI_Group_free", [
        ("MPI_Group *", "group"),
    ], None),

    # 6.4 Communicator Management

    ("int", "MPI_Comm_size", [
        ("MPI_Comm", "comm"),
        ("int *", "size"),
    ], None),

    ("int", "MPI_Comm_rank", [
        ("MPI_Comm", "comm"),
        ("int *", "rank"),
    ], None),

    ("int", "MPI_Comm_compare", [
        ("MPI_Comm", "comm1"),
        ("MPI_Comm", "comm2"),
        ("int *", "result"),
    ], None),

    ("int", "MPI_Comm_dup", [
        ("MPI_Comm", "comm"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_dup_with_info", [
        ("MPI_Comm", "comm"),
        ("MPI_Info", "info"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_idup", [
        ("MPI_Comm", "comm"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Comm_create", [
        ("MPI_Comm", "comm"),
        ("MPI_Group", "group"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_create_group", [
        ("MPI_Comm", "comm"),
        ("MPI_Group", "group"),
        ("int", "tag"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_split", [
        ("MPI_Comm", "comm"),
        ("int", "color"),
        ("int", "key"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_split_type", [
        ("MPI_Comm", "comm"),
        ("int", "split_type"),
        ("int", "key"),
        ("MPI_Info", "info"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_free", [
        ("MPI_Comm *", "comm"),
    ], None),

    ("int", "MPI_Comm_set_info", [
        ("MPI_Comm", "comm"),
        ("MPI_Info", "info"),
    ], None),

    ("int", "MPI_Comm_get_info", [
        ("MPI_Comm", "comm"),
        ("MPI_Info *", "info"),
    ], None),

    # 6.6 Inter-Communication

    ("int", "MPI_Comm_test_inter", [
        ("MPI_Comm", "comm"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Comm_remote_size", [
        ("MPI_Comm", "comm"),
        ("int *", "size"),
    ], None),

    ("int", "MPI_Comm_remote_group", [
        ("MPI_Comm", "comm"),
        ("MPI_Group *", "group"),
    ], None),

    ("int", "MPI_Intercomm_create", [
        ("MPI_Comm", "local_comm"),
        ("int", "local_leader"),
        ("MPI_Comm", "peer_comm"),
        ("int", "remote_leader"),
        ("int", "tag"),
        ("MPI_Comm *", "newintercomm"),
    ], None),

    ("int", "MPI_Intercomm_merge", [
        ("MPI_Comm", "intercomm"),
        ("int", "high"),
        ("MPI_Comm *", "newintracomm"),
    ], None),

    # 6.7 Communicators

    ("int", "MPI_Comm_create_keyval", [
        ("MPI_Comm_copy_attr_function *", "comm_copy_attr_fn"),
        ("MPI_Comm_delete_attr_function *", "comm_delete_attr_fn"),
        ("int *", "comm_keyval"),
        ("void *", "extra_state"),
    ], None),

    ("int", "MPI_Comm_free_keyval", [
        ("int *", "comm_keyval"),
    ], None),

    ("int", "MPI_Comm_set_attr", [
        ("MPI_Comm", "comm"),
        ("int", "comm_keyval"),
        ("void *", "attribute_val"),
    ], None),

    ("int", "MPI_Comm_get_attr", [
        ("MPI_Comm", "comm"),
        ("int", "comm_keyval"),
        ("void *", "attribute_val"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Comm_delete_attr", [
        ("MPI_Comm", "comm"),
        ("int", "comm_keyval"),
    ], None),

    ("int", "MPI_Win_create_keyval", [
        ("MPI_Win_copy_attr_function *", "win_copy_attr_fn"),
        ("MPI_Win_delete_attr_function *", "win_delete_attr_fn"),
        ("int *", "win_keyval"),
        ("void *", "extra_state"),
    ], None),

    ("int", "MPI_Win_free_keyval", [
        ("int *", "win_keyval"),
    ], None),

    ("int", "MPI_Win_set_attr", [
        ("MPI_Win", "win"),
        ("int", "win_keyval"),
        ("void *", "attribute_val"),
    ], None),

    ("int", "MPI_Win_get_attr", [
        ("MPI_Win", "win"),
        ("int", "win_keyval"),
        ("void *", "attribute_val"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Win_delete_attr", [
        ("MPI_Win", "win"),
        ("int", "win_keyval"),
    ], None),

    ("int", "MPI_Type_create_keyval", [
        ("MPI_Type_copy_attr_function *", "type_copy_attr_fn"),
        ("MPI_Type_delete_attr_function *", "type_delete_attr_fn"),
        ("int *", "type_keyval"),
        ("void *", "extra_state"),
    ], None),

    ("int", "MPI_Type_free_keyval", [
        ("int *", "type_keyval"),
    ], None),

    ("int", "MPI_Type_set_attr", [
        ("MPI_Datatype", "type"),
        ("int", "type_keyval"),
        ("void *", "attribute_val"),
    ], None),

    ("int", "MPI_Type_get_attr", [
        ("MPI_Datatype", "type"),
        ("int", "type_keyval"),
        ("void *", "attribute_val"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Type_delete_attr", [
        ("MPI_Datatype", "type"),
        ("int", "type_keyval"),
    ], None),

    # 6.8 Naming Objects

    ("int", "MPI_Comm_set_name", [
        ("MPI_Comm", "comm"),
        ("const char *", "comm_name"),
    ], None),

    ("int", "MPI_Comm_get_name", [
        ("MPI_Comm", "comm"),
        ("char *", "comm_name"),
        ("int *", "resultlen"),
    ], None),

    ("int", "MPI_Type_set_name", [
        ("MPI_Datatype", "type"),
        ("const char *", "type_name"),
    ], None),

    ("int", "MPI_Type_get_name", [
        ("MPI_Datatype", "type"),
        ("char *", "type_name"),
        ("int *", "resultlen"),
    ], None),

    ("int", "MPI_Win_set_name", [
        ("MPI_Win", "win"),
        ("const char *", "win_name"),
    ], None),

    ("int", "MPI_Win_get_name", [
        ("MPI_Win", "win"),
        ("char *", "win_name"),
        ("int *", "resultlen"),
    ], None),

    # 7.5 Topology Constructors

    ("int", "MPI_Cart_create", [
        ("MPI_Comm", "comm_old"),
        ("int", "ndims"),
        ("const int *", "dims"),
        ("const int *", "periods"),
        ("int", "reorder"),
        ("MPI_Comm *", "comm_cart"),
    ], None),

    ("int", "MPI_Dims_create", [
        ("int", "nnodes"),
        ("int", "ndims"),
        ("int *", "dims"),
    ], None),

    ("int", "MPI_Graph_create", [
        ("MPI_Comm", "comm_old"),
        ("int", "nnodes"),
        ("const int *", "index"),
        ("const int *", "edges"),
        ("int", "reorder"),
        ("MPI_Comm *", "comm_graph"),
    ], None),

    ("int", "MPI_Dist_graph_create_adjacent", [
        ("MPI_Comm", "comm_old"),
        ("int", "indegree"),
        ("const int *", "sources"),
        ("const int *", "sourceweights"),
        ("int", "outdegree"),
        ("const int *", "destinations"),
        ("const int *", "destweights"),
        ("MPI_Info", "info"),
        ("int", "reorder"),
        ("MPI_Comm *", "comm_dist_graph"),
    ], None),

    ("int", "MPI_Dist_graph_create", [
        ("MPI_Comm", "comm_old"),
        ("int", "n"),
        ("const int *", "sources"),
        ("const int *", "degrees"),
        ("const int *", "destinations"),
        ("const int *", "weights"),
        ("MPI_Info", "info"),
        ("int", "reorder"),
        ("MPI_Comm *", "comm_dist_graph"),
    ], None),

    ("int", "MPI_Topo_test", [
        ("MPI_Comm", "comm"),
        ("int *", "status"),
    ], None),

    ("int", "MPI_Graphdims_get", [
        ("MPI_Comm", "comm"),
        ("int *", "nnodes"),
        ("int *", "nedges"),
    ], None),

    ("int", "MPI_Graph_get", [
        ("MPI_Comm", "comm"),
        ("int", "maxindex"),
        ("int", "maxedges"),
        ("int *", "index"),
        ("int *", "edges"),
    ], None),

    ("int", "MPI_Cartdim_get", [
        ("MPI_Comm", "comm"),
        ("int *", "ndims"),
    ], None),

    ("int", "MPI_Cart_get", [
        ("MPI_Comm", "comm"),
        ("int", "maxdims"),
        ("int *", "dims"),
        ("int *", "periods"),
        ("int *", "coords"),
    ], None),

    ("int", "MPI_Cart_rank", [
        ("MPI_Comm", "comm"),
        ("const int *", "coords"),
        ("int *", "rank"),
    ], None),

    ("int", "MPI_Cart_coords", [
        ("MPI_Comm", "comm"),
        ("int", "rank"),
        ("int", "maxdims"),
        ("int *", "coords"),
    ], None),

    ("int", "MPI_Graph_neighbors_count", [
        ("MPI_Comm", "comm"),
        ("int", "rank"),
        ("int *", "nneighbors"),
    ], None),

    ("int", "MPI_Graph_neighbors", [
        ("MPI_Comm", "comm"),
        ("int", "rank"),
        ("int", "maxneighbors"),
        ("int *", "neighbors"),
    ], None),

    ("int", "MPI_Dist_graph_neighbors_count", [
        ("MPI_Comm", "comm"),
        ("int *", "indegree"),
        ("int *", "outdegree"),
        ("int *", "weighted"),
    ], None),

    ("int", "MPI_Dist_graph_neighbors", [
        ("MPI_Comm", "comm"),
        ("int", "maxindeegree"),
        ("int *", "sources"),
        ("int *", "wourceweights"),
        ("int", "maxoutdegree"),
        ("int *", "destinations"),
        ("int *", "destweights"),
    ], None),

    ("int", "MPI_Cart_shift", [
        ("MPI_Comm", "comm"),
        ("int", "direction"),
        ("int", "disp"),
        ("int *", "rank_source"),
        ("int *", "rank_dest"),
    ], None),

    ("int", "MPI_Cart_sub", [
        ("MPI_Comm", "comm"),
        ("const int *", "remain_dims"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Cart_map", [
        ("MPI_Comm", "comm"),
        ("int", "ndims"),
        ("const int *", "dims"),
        ("const int *", "periods"),
        ("int *", "newrank"),
    ], None),

    ("int", "MPI_Graph_map", [
        ("MPI_Comm", "comm"),
        ("int", "nnodes"),
        ("const int *", "index"),
        ("const int *", "edges"),
        ("int *", "newrank"),
    ], None),

    # 7.6 Neighborhood Collective Communication on Procerss Topologies

    ("int", "MPI_Neighbor_allgather", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Neighbor_allgatherv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Neighbor_alltoall", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "senddtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Neighbor_alltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("MPI_Datatype", "senddtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
    ], None),

    ("int", "MPI_Neighbor_alltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const MPI_Aint *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const MPI_Aint *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("MPI_Comm", "comm"),
    ], "manual"),

    # 7.7 Nonblocking Neighborhood Communication on Process Topologies

    ("int", "MPI_Ineighbor_allgather", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ineighbor_allgatherv", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ineighbor_alltoall", [
        ("const void *", "sendbuf"),
        ("int", "sendcount"),
        ("MPI_Datatype", "senddtype"),
        ("void *", "recvbuf"),
        ("int", "recvcount"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ineighbor_alltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("MPI_Datatype", "senddtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("MPI_Datatype", "recvtype"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Ineighbor_alltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const MPI_Aint *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const MPI_Aint *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("MPI_Comm", "comm"),
        ("MPI_Request *", "request"),
    ], "manual"),

    # 8.1 Implementation Information

    ("int", "MPI_Get_version", [
        ("int *", "version"),
        ("int *", "subversion"),
    ], None),

    ("int", "MPI_Get_library_version",[
        ("char *", "version"),
        ("int *", "resultlen"),
    ], "manual"),

    ("int", "MPI_Get_processor_name", [
        ("char *", "name"),
        ("int *", "resultlen"),
    ], None),

    # 8.2 Memory Allocation

    ("int", "MPI_Alloc_mem", [
        ("MPI_Aint", "size"),
        ("MPI_Info", "info"),
        ("void *", "baseptr"),
    ], None),

    ("int", "MPI_Free_mem", [
        ("void *", "base"),
    ], None),

    # 8.3 Error Handling

    ("int", "MPI_Comm_create_errhandler", [
        ("MPI_Comm_errhandler_function *", "comm_errhandler_fn"),
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_Comm_set_errhandler", [
        ("MPI_Comm", "comm"),
        ("MPI_Errhandler", "errhandler"),
    ], None),

    ("int", "MPI_Comm_get_errhandler", [
        ("MPI_Comm", "comm"),
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_Win_create_errhandler", [
        ("MPI_Win_errhandler_function *", "win_errhandler_fn"),
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_Win_set_errhandler", [
        ("MPI_Win", "win"),
        ("MPI_Errhandler", "errhandler"),
    ], None),

    ("int", "MPI_Win_get_errhandler",
     [("MPI_Win", "win"),
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_File_create_errhandler", [
        ("MPI_File_errhandler_function *", "file_errhandler_fn"),
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_File_set_errhandler", [
        ("MPI_File", "file"),
        ("MPI_Errhandler", "errhandler"),
    ], None),

    ("int", "MPI_File_get_errhandler", [
        ("MPI_File", "file"),
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_Errhandler_free", [
        ("MPI_Errhandler *", "errhandler"),
    ], None),

    ("int", "MPI_Error_string", [
        ("int", "errorcode"),
        ("char *", "string"),
        ("int *", "resultlen"),
    ], None),

    # 8.4 Error Codes and Classes

    ("int", "MPI_Error_class", [
        ("int", "errorcode"),
        ("int *", "errorclass"),
    ], None),

    # 8.5 Error Classes", "Error Codes", "and Error Handlers

    ("int", "MPI_Add_error_class", [
        ("int *", "errorclass"),
    ], None),

    ("int", "MPI_Add_error_code", [
        ("int", "errorclass"),
        ("int *", "errorcode"),
    ], None),

    ("int", "MPI_Add_error_string", [
        ("int", "errorcode"),
        ("const char *", "string"),
    ], None),

    ("int", "MPI_Comm_call_errhandler", [
        ("MPI_Comm", "comm"),
        ("int", "errorcode"),
    ], None),

    ("int", "MPI_Win_call_errhandler", [
        ("MPI_Win", "win"),
        ("int", "errorcode"),
    ], None),

    ("int", "MPI_File_call_errhandler", [
        ("MPI_File", "file"),
        ("int", "errorcode"),
    ], None),

    # 8.6 Times and Synchronization

    ("double", "MPI_Wtime", [], None),

    ("double", "MPI_Wtick", [], None),

    # 8.7 Startup

    ("int", "MPI_Init", [
        ("int *", "argc"),
        ("char ***", "argv"),
    ], None),

    ("int", "MPI_Finalize", [], None),

    ("int", "MPI_Initialized", [
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Abort", [
        ("MPI_Comm", "comm"),
        ("int", "errorcode"),
    ], None),

    ("int", "MPI_Finalized", [
        ("int *", "flag"),
    ], None),

    # 9 The Info Object

    ("int", "MPI_Info_create", [
        ("MPI_Info *", "info"),
    ], None),

    ("int", "MPI_Info_set", [
        ("MPI_Info", "info"),
        ("const char *", "key"),
        ("const char *", "value"),
    ], None),

    ("int", "MPI_Info_delete", [
        ("MPI_Info", "info"),
        ("const char *", "key"),
    ], None),

    ("int", "MPI_Info_get", [
        ("MPI_Info", "info"),
        ("const char *", "key"),
        ("int", "valuelen"),
        ("char *", "value"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Info_get_valuelen", [
        ("MPI_Info", "info"),
        ("const char *", "key"),
        ("int *", "valuelen"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Info_get_nkeys", [
        ("MPI_Info", "info"),
        ("int *", "nkeys"),
    ], None),

    ("int", "MPI_Info_get_nthkey", [
        ("MPI_Info", "info"),
        ("int", "n"),
        ("char *", "key"),
    ], None),

    ("int", "MPI_Info_dup", [
        ("MPI_Info", "info"),
        ("MPI_Info *", "newinfo"),
    ], None),

    ("int", "MPI_Info_free", [
        ("MPI_Info *", "info"),
    ], None),

    # 10.3 Process Manager Interface

    ("int", "MPI_Comm_spawn", [
        ("const char *", "command"),
        ("char **", "argv"),
        ("int", "maxprocs"),
        ("MPI_Info", "info"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Comm *", "intercomm"),
        ("int *", "array_off_errcodes"),
    ], None),

    ("int", "MPI_Comm_get_parent", [
        ("MPI_Comm *", "parent"),
    ], None),

    ("int", "MPI_Comm_spawn_multiple", [
        ("int", "count"),
        ("char **", "array_of_commands"),
        ("char ***", "array_of_argv"),
        ("const int *", "array_of_maxprocs"),
        ("const MPI_Info *", "array_of_info"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Comm *", "intercomm"),
        ("int *", "array_of_errcodes"),
    ], "manual"),

    # 10.4 Establishing Communication

    ("int", "MPI_Open_port", [
        ("MPI_Info", "info"),
        ("char *", "port_name"),
    ], None),

    ("int", "MPI_Close_port", [
        ("const char *", "port_name"),
    ], None),

    ("int", "MPI_Comm_accept", [
        ("const char *", "port_name"),
        ("MPI_Info", "info"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Comm_connect", [
        ("const char *", "port_name"),
        ("MPI_Info", "info"),
        ("int", "root"),
        ("MPI_Comm", "comm"),
        ("MPI_Comm *", "newcomm"),
    ], None),

    ("int", "MPI_Publish_name", [
        ("const char *", "service_name"),
        ("MPI_Info", "info"),
        ("const char *", "port_name"),
    ], None),

    ("int", "MPI_Unpublish_name", [
        ("const char *", "service_name"),
        ("MPI_Info", "info"),
        ("const char *", "port_name"),
    ], None),

    ("int", "MPI_Lookup_name", [
        ("const char *", "service_name"),
        ("MPI_Info", "info"),
        ("char *", "port_name"),
    ], None),

    # 10.5 Other Functionality

    ("int", "MPI_Comm_disconnect", [
        ("MPI_Comm *", "comm"),
    ], None),

    ("int", "MPI_Comm_join", [
        ("int", "fd"),
        ("MPI_Comm *", "intercomm"),
    ], None),

    # 11.2 Initialization

    ("int", "MPI_Win_create", [
        ("void *", "base"),
        ("MPI_Aint", "size"),
        ("int", "disp_unit"),
        ("MPI_Info", "info"),
        ("MPI_Comm", "comm"),
        ("MPI_Win *", "win"),
    ], None),

    ("int", "MPI_Win_allocate", [
        ("MPI_Aint", "size"),
        ("int", "disp_unit"),
        ("MPI_Info", "info"),
        ("MPI_Comm", "comm"),
        ("void *", "baseptr"),
        ("MPI_Win *", "win"),
    ], None),

    ("int", "MPI_Win_allocate_shared", [
        ("MPI_Aint", "size"),
        ("int", "disp_unit"),
        ("MPI_Info", "info"),
        ("MPI_Comm", "comm"),
        ("void *", "baseptr"),
        ("MPI_Win *", "win"),
    ], None),

    ("int", "MPI_Win_shared_query", [
        ("MPI_Win", "win"),
        ("int", "rank"),
        ("MPI_Aint *", "size"),
        ("int *", "disp_unit"),
        ("void *", "baseptr"),
    ], None),

    ("int", "MPI_Win_create_dynamic", [
        ("MPI_Info", "info"),
        ("MPI_Comm", "comm"),
        ("MPI_Win *", "win"),
    ], None),

    ("int", "MPI_Win_attach", [
        ("MPI_Win", "win"),
        ("void *", "base"),
        ("MPI_Aint", "size"),
    ], None),

    ("int", "MPI_Win_detach", [
        ("MPI_Win", "win"),
        ("const void *", "base"),
    ], None),

    ("int", "MPI_Win_free", [
        ("MPI_Win *", "win"),
    ], None),

    ("int", "MPI_Win_get_group", [
        ("MPI_Win", "win"),
        ("MPI_Group *", "group"),
    ], None),

    ("int", "MPI_Win_set_info", [
        ("MPI_Win", "win"),
        ("MPI_Info", "info"),
    ], None),

    ("int", "MPI_Win_get_info", [
        ("MPI_Win", "win"),
        ("MPI_Info *", "info_used"),
    ], None),

    # 11.3 Communication Calls

    ("int", "MPI_Put", [
        ("const void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Get", [
        ("void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Accumulate", [
        ("const void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Op", "op"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Get_accumulate", [
        ("const void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("void *", "result_addr"),
        ("int", "result_count"),
        ("MPI_Datatype", "result_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Op", "op"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Fetch_and_op", [
        ("const void *", "origin_addr"),
        ("void *", "result_addr"),
        ("MPI_Datatype", "datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("MPI_Op", "op"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Compare_and_swap", [
        ("const void *", "origin_addr"),
        ("const void *", "compare_addr"),
        ("void *", "result_addr"),
        ("MPI_Datatype", "datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Rput", [
        ("const void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Win", "win"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Rget", [
        ("void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Win", "win"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Raccumulate", [
        ("const void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Op", "op"),
        ("MPI_Win", "win"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_Rget_accumulate", [
        ("const void *", "origin_addr"),
        ("int", "origin_count"),
        ("MPI_Datatype", "origin_datatype"),
        ("void *", "result_addr"),
        ("int", "result_count"),
        ("MPI_Datatype", "result_datatype"),
        ("int", "target_rank"),
        ("MPI_Aint", "target_disp"),
        ("int", "target_count"),
        ("MPI_Datatype", "target_datatype"),
        ("MPI_Op", "op"),
        ("MPI_Win", "win"),
        ("MPI_Request *", "request"),
    ], None),

    # 11.5 Synchronization Calls

    ("int", "MPI_Win_fence", [
        ("int", "assert"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_start", [
        ("MPI_Group", "group"),
        ("int", "assert"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_complete", [
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_post", [
        ("MPI_Group", "group"),
        ("int", "assert"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_wait", [
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_test", [
        ("MPI_Win", "win"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_Win_lock", [
        ("int", "lock_type"),
        ("int", "rank"),
        ("int", "assert"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_lock_all", [
        ("int", "assert"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_unlock", [
        ("int", "rank"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_unlock_all", [
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_flush", [
        ("int", "rank"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_flush_all", [
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_flush_local", [
        ("int", "rank"),
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_flush_local_all", [
        ("MPI_Win", "win"),
    ], None),

    ("int", "MPI_Win_sync", [
        ("MPI_Win", "win"),
    ], None),

    # 12.2 Generalized Requests

    #if 0
    # TODO: Handle status correctly
    ("int", "MPI_Grequest_start", [
        ("MPI_Grequest_query_function *", "query_fn"),
        ("MPI_Grequest_free_function *", "free_fn"),
        ("MPI_Grequest_cancel_function *", "cancel_fn"),
        ("void *", "extra_state"),
        ("MPI_Request *", "request"),
    ], None),
    #endif

    ("int", "MPI_Grequest_complete", [
        ("MPI_Request", "request"),
    ], None),

    # 12.3 Associating Information with Status

    ("int", "MPI_Status_set_elements", [
        ("MPI_Status *", "status"),
        ("MPI_Datatype", "datatype"),
        ("int", "count"),
    ], None),

    ("int", "MPI_Status_set_elements_x", [
        ("MPI_Status *", "status"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Count", "count"),
    ], None),

    ("int", "MPI_Status_set_cancelled", [
        ("MPI_Status *", "status"),
        ("int", "flag"),
    ], None),

    # 12.4 MPI and Threads

    ("int", "MPI_Init_thread", [
        ("int *", "argc"),
        ("char * * *", "argv"),
        ("int", "required"),
        ("int *", "provided"),
    ], None),

    ("int", "MPI_Query_thread", [
        ("int *", "provided"),
    ], None),

    ("int", "MPI_Is_thread_main", [
        ("int *", "flag"),
    ], None),

    # 13.2 File Manipulation

    ("int", "MPI_File_open", [
        ("MPI_Comm", "comm"),
        ("const char *", "filename"),
        ("int", "amode"),
        ("MPI_Info", "info"),
        ("MPI_File *", "fh"),
    ], None),

    ("int", "MPI_File_close", [
        ("MPI_File *", "fh"),
    ], None),

    ("int", "MPI_File_delete", [
        ("const char *", "filename"),
        ("MPI_Info", "info"),
    ], None),

    ("int", "MPI_File_set_size", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "size"),
    ], None),

    ("int", "MPI_File_preallocate", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "size"),
    ], None),

    ("int", "MPI_File_get_size", [
        ("MPI_File", "fh"),
        ("MPI_Offset *", "size"),
    ], None),

    ("int", "MPI_File_get_group", [
        ("MPI_File", "fh"),
        ("MPI_Group *", "group"),
    ], None),

    ("int", "MPI_File_get_amode", [
        ("MPI_File", "fh"),
        ("int *", "amode"),
    ], None),

    ("int", "MPI_File_set_info", [
        ("MPI_File", "fh"),
        ("MPI_Info", "info"),
    ], None),

    ("int", "MPI_File_get_info", [
        ("MPI_File", "fh"),
        ("MPI_Info *", "info_used"),
    ], None),

    # 13.3 File View

    ("int", "MPI_File_set_view", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "disp"),
        ("MPI_Datatype", "etype"),
        ("MPI_Datatype", "filetype"),
        ("const char *", "datarep"),
        ("MPI_Info", "info"),
    ], None),

    ("int", "MPI_File_get_view", [
        ("MPI_File", "fh"),
        ("MPI_Offset *", "disp"),
        ("MPI_Datatype *", "etype"),
        ("MPI_Datatype *", "filetype"),
        ("char *", "datarep"),
    ], None),

    # 13.4 Data Access

    ("int", "MPI_File_read_at", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_read_at_all", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_at", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_at_all", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_iread_at", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iread_at_all", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iwrite_at", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iwrite_at_all", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_read", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_read_all", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_all", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_iread", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iread_all", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iwrite", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iwrite_all", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_seek", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("int", "whence"),
    ], None),

    ("int", "MPI_File_get_position", [
        ("MPI_File", "fh"),
        ("MPI_Offset *", "offset"),
    ], None),

    ("int", "MPI_File_get_byte_offset", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("MPI_Offset *", "disp"),
    ], None),

    ("int", "MPI_File_read_shared", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_shared", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_iread_shared", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_iwrite_shared", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Request *", "request"),
    ], None),

    ("int", "MPI_File_read_ordered", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_ordered", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_seek_shared", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("int", "whence"),
    ], None),

    ("int", "MPI_File_get_position_shared", [
        ("MPI_File", "fh"),
        ("MPI_Offset *", "offset"),
    ], None),

    ("int", "MPI_File_read_at_all_begin", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_File_read_at_all_end", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_at_all_begin", [
        ("MPI_File", "fh"),
        ("MPI_Offset", "offset"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_File_write_at_all_end", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_read_all_begin", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_File_read_all_end", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_all_begin", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_File_write_all_end", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_read_ordered_begin", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_File_read_ordered_end", [
        ("MPI_File", "fh"),
        ("void *", "buf"),
        ("MPI_Status *", "status"),
    ], None),

    ("int", "MPI_File_write_ordered_begin", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("int", "count"),
        ("MPI_Datatype", "datatype"),
    ], None),

    ("int", "MPI_File_write_ordered_end", [
        ("MPI_File", "fh"),
        ("const void *", "buf"),
        ("MPI_Status *", "status"),
    ], None),

    # 13.5 File Interoperability

    ("int", "MPI_File_get_type_extent", [
        ("MPI_File", "fh"),
        ("MPI_Datatype", "datatype"),
        ("MPI_Aint *", "extent"),
    ], None),

    #if 0
    # TODO: Handle conversions
    ("int", "MPI_Register_datarep", [
        ("const char *", "datarep"),
        ("MPI_Datarep_conversion_function *", "read_conversion_fn"),
        ("MPI_Datarep_conversion_function *", "write_conversion_fn"),
        ("MPI_Datarep_extent_function *", "dtype_file_extent_fn"),
        ("void *", "extra_state"),
    ], None),
    #endif

    # 13.6 Consistency and Semantics

    ("int", "MPI_File_set_atomicity", [
        ("MPI_File", "fh"),
        ("int", "flag"),
    ], None),

    ("int", "MPI_File_get_atomicity", [
        ("MPI_File", "fh"),
        ("int *", "flag"),
    ], None),

    ("int", "MPI_File_sync", [
        ("MPI_File", "fh"),
    ], None),

    # 17.1 Additional Support for Fortran Numeric Intrinsic Types

    # Fortran 90-related functions. These routines are available only when
    # Fortran 90 support is enabled.

    ("int", "MPI_Type_create_f90_real", [
        ("int", "precision"),
        ("int", "range"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_f90_complex", [
        ("int", "precision"),
        ("int", "range"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_create_f90_integer", [
        ("int", "range"),
        ("MPI_Datatype *", "newtype"),
    ], None),

    ("int", "MPI_Type_match_size", [
        ("int", "typeclass"),
        ("int", "size"),
        ("MPI_Datatype *", "datatype"),
    ], None),

    # 17.2 Language Interoperability

    ("MPI_Comm", "MPI_Comm_f2c", [
        ("MPI_Fint", "comm"),
    ], None),

    ("MPI_Fint", "MPI_Comm_c2f", [
        ("MPI_Comm", "comm"),
    ], None),

    ("MPI_Datatype", "MPI_Type_f2c", [
        ("MPI_Fint", "datatype"),
    ], None),

    ("MPI_Fint", "MPI_Type_c2f", [
        ("MPI_Datatype", "datatype"),
    ], None),

    ("MPI_Group", "MPI_Group_f2c", [
        ("MPI_Fint", "group"),
    ], None),

    ("MPI_Fint", "MPI_Group_c2f", [
        ("MPI_Group", "group"),
    ], None),

    ("MPI_Request", "MPI_Request_f2c", [
        ("MPI_Fint", "request"),
    ], None),

    ("MPI_Fint", "MPI_Request_c2f", [
        ("MPI_Request", "request"),
    ], None),

    ("MPI_File", "MPI_File_f2c", [
        ("MPI_Fint", "file"),
    ], None),

    ("MPI_Fint", "MPI_File_c2f", [
        ("MPI_File", "file"),
    ], None),

    ("MPI_Win", "MPI_Win_f2c", [
        ("MPI_Fint", "win"),
    ], None),

    ("MPI_Fint", "MPI_Win_c2f", [
        ("MPI_Win", "win"),
    ], None),

    ("MPI_Op", "MPI_Op_f2c", [
        ("MPI_Fint", "op"),
    ], None),

    ("MPI_Fint", "MPI_Op_c2f", [
        ("MPI_Op", "op"),
    ], None),

    ("MPI_Info", "MPI_Info_f2c", [
        ("MPI_Fint", "info"),
    ], None),

    ("MPI_Fint", "MPI_Info_c2f", [
        ("MPI_Info", "info"),
    ], None),

    ("MPI_Errhandler", "MPI_Errhandler_f2c", [
        ("MPI_Fint", "info"),
    ], None),

    ("MPI_Fint", "MPI_Errhandler_c2f", [
        ("MPI_Errhandler", "info"),
    ], None),

    ("MPI_Message", "MPI_Message_f2c", [
        ("MPI_Fint", "message"),
    ], None),

    ("MPI_Fint", "MPI_Message_c2f", [
        ("MPI_Message", "message"),
    ], None),

    ("int", "MPI_Status_f2c", [
        ("const MPI_Fint *", "f_status"),
        ("MPI_Status *", "c_status"),
    ], None),

    ("int", "MPI_Status_c2f", [
        ("const MPI_Status *", "c_status"),
        ("MPI_Fint *", "f_status"),
    ], None),

    # MPIX

    ("int", "MPIX_Query_cuda_support", [
    ], "manual"),

    ("int", "MPIX_Query_hip_support", [
    ], "manual"),

    ("int", "MPIX_Query_ze_support", [
    ], "manual"),

    # TODO
    #
    # ("int", "MPI_Status_f082c"), [
    #     ("const MPI_F08_Status *", "f08_status"),
    #     ("MPI_Status *", "c_status"),
    # ], None),
    #
    # ("int", "MPI_Status_c2f08"), [
    #     ("const MPI_Status *", "c_status"),
    #     ("MPI_F08_Status *", "f08_status"),
    # ], None),
    #
    # ("int", "MPI_Status_f2f08", [
    #     ("MPI_Fint *", "f_status"),
    #     ("MPI_F08_Status *", "f08_status"),
    # ], None),
    #
    # ("int", "MPI_Status_f082f"), [
    #     ("const MPI_F08_Status *", "f08_status"),
    #     ("MPI_Fint *", "f_status"),
    # ], None),

    # ("int", "MPI_Pcontrol", [
    #     ("int", "level"),
    #     ("...", ""),
    # ], "manual"),

]
