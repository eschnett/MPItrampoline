# The section names follow the MPI 3.1 standard.

functions_fortran = [

    # 3.2 Blocking Send and Receive Operations

    ("void", "MPI_Send", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Recv", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_count", [
        ("const MPI_Status *", "status"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "count"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 3.4 Communication Modes

    ("void", "MPI_Bsend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ssend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Rsend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 3.6 Buffer Allocation and Usage

    ("void", "MPI_Buffer_attach", [
        ("void *", "buffer"),
        ("const MPI_Fint *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Buffer_detach", [
        ("void *", "buffer_addr"),
        ("MPI_Fint *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 3.7 Nonblocking Communication

    ("void", "MPI_Isend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ibsend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Issend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Irsend", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Irecv", [
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Wait", [
        ("MPI_Request *", "request"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Test", [
        ("MPI_Request *", "request"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Request_free", [
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Waitany", [
        ("const MPI_Fint *", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "index"),
        ("MPI_Status *", "status"),
    ]),

    ("void", "MPI_Testany", [
        ("const MPI_Fint *", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "index"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
    ]),

    ("void", "MPI_Waitall", [
        ("const MPI_Fint *", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("MPI_Status *", "array_of_statuses"),
    ]),

    ("void", "MPI_Testall", [
        ("const MPI_Fint *", "count"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "flag"),
        ("MPI_Status *", "array_of_statuses"),
    ]),

    ("void", "MPI_Waitsome", [
        ("const MPI_Fint *", "incount"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "outcount"),
        ("int *", "array_of_indices"),
        ("MPI_Status *", "array_of_statuses"),
    ]),

    ("void", "MPI_Testsome", [
        ("const MPI_Fint *", "incount"),
        ("MPI_Request *", "array_of_requests"),
        ("int *", "outcount"),
        ("int *", "array_of_indices"),
        ("MPI_Status *", "array_of_statuses"),
    ]),

    ("void", "MPI_Request_get_status", [
        ("const MPI_Request *", "request"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 3.8 Probe and Cancel

    ("void", "MPI_Iprobe", [
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("int *", "flag"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Probe", [
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Improbe", [
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("int *", "flag"),
        ("MPI_Message *", "message"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Mprobe", [
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Message *", "message"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Mrecv", [
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Message *", "message"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Imrecv", [
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Message *", "message"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cancel", [
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Test_cancelled", [
        ("const MPI_Status *", "status"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 3.9 Persistent Communication Requests

    ("void", "MPI_Send_init", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Bsend_init", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ssend_init", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Rsend_init", [
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Recv_init", [
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "tag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Start", [
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Startall", [
        ("const MPI_Fint *", "count"),
        ("MPI_Request *", "array_of_requests"),
    ]),

    # 3.10 Send-Receive

    ("void", "MPI_Sendrecv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "sendtag"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "recvtag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Sendrecv_replace", [
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "dest"),
        ("const MPI_Fint *", "sendtag"),
        ("const MPI_Fint *", "source"),
        ("const MPI_Fint *", "recvtag"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

################################################################################

    # 4.1 Derived Datatypes

    ("void", "MPI_Type_contiguous", [
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_vector", [
        ("const MPI_Fint *", "count"),
        ("const MPI_Fint *", "blocklength"),
        ("const MPI_Fint *", "stride"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_hvector", [
        ("const MPI_Fint *", "count"),
        ("const MPI_Fint *", "blocklength"),
        ("const MPI_Aint *", "stride"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_indexed", [
        ("const MPI_Fint *", "count"),
        ("const int *", "array_of_blocklengths"),
        ("const int *", "array_of_displacements"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_hindexed", [
        ("const MPI_Fint *", "count"),
        ("const int *", "array_of_blocklengths"),
        ("const MPI_Aint *", "array_of_displacements"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_indexed_block", [
        ("const MPI_Fint *", "count"),
        ("const MPI_Fint *", "blocklength"),
        ("const int *", "array_of_displacements"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_hindexed_block", [
        ("const MPI_Fint *", "count"),
        ("const MPI_Fint *", "blocklength"),
        ("const MPI_Aint *", "array_of_displacements"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_struct", [
        ("const MPI_Fint *", "count"),
        ("const int *", "array_of_blocklengths"),
        ("const MPI_Aint *", "array_of_displacements"),
        ("const MPI_Datatype *", "array_of_types"),
        ("MPI_Datatype *", "newtype"),
    ]),

    ("void", "MPI_Type_create_subarray", [
        ("const MPI_Fint *", "ndims"),
        ("const int *", "array_of_sizes"),
        ("const int *", "array_of_subsizes"),
        ("const int *", "array_of_starts"),
        ("const MPI_Fint *", "ordder"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_darray", [
        ("const MPI_Fint *", "size"),
        ("const MPI_Fint *", "rank"),
        ("const MPI_Fint *", "ndims"),
        ("const int *", "array_of_gsizes"),
        ("const int *", "array_of_distribs"),
        ("const int *", "array_of_dargs"),
        ("const int *", "array_of_psizes"),
        ("const MPI_Fint *", "order"),
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_address", [
        ("const void *", "location"),
        ("MPI_Aint *", "address"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("MPI_Aint", "MPI_Aint_add", [
        ("const MPI_Aint *", "base"),
        ("const MPI_Aint *", "disp"),
    ]),

    ("MPI_Aint", "MPI_Aint_diff", [
        ("const MPI_Aint *", "addr1"),
        ("const MPI_Aint *", "addr2"),
    ]),

    ("void", "MPI_Type_size", [
        ("const MPI_Datatype *", "datatype"),
        ("int *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_size_x", [
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Count *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_extent", [
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Aint *", "lb"),
        ("MPI_Aint *", "extent"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_extent_x", [
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Count *", "lb"),
        ("MPI_Count *", "extent"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_resized", [
        ("const MPI_Datatype *", "oldtype"),
        ("const MPI_Aint *", "lb"),
        ("const MPI_Aint *", "extent"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_true_extent", [
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Aint *", "true_lb"),
        ("MPI_Aint *", "true_extent"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_true_extent_x", [
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Count *", "true_lb"),
        ("MPI_Count *", "true_extent"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_commit", [
        ("MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_free", [
        ("MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_dup", [
        ("const MPI_Datatype *", "oldtype"),
        ("MPI_Datatype *", "newtype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_elements", [
        ("const MPI_Status *", "status"),
        ("const MPI_Datatype *", "datatype"),
        ("int *", "count"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_elements_x", [
        ("const MPI_Status *", "status"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Count *", "count"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_envelope", [
        ("const MPI_Datatype *", "datatype"),
        ("int *", "num_integers"),
        ("int *", "num_addresses"),
        ("int *", "num_datatypes"),
        ("int *", "combiner"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_contents", [
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "max_integers"),
        ("const MPI_Fint *", "max_addresses"),
        ("const MPI_Fint *", "max_datatypes"),
        ("int *", "array_of_integers"),
        ("MPI_Aint *", "array_of_addresses"),
        ("MPI_Datatype *", "array_of_datatypes"),
    ]),

    # 4.2 Pack and Unpack

    ("void", "MPI_Pack", [
        ("const void *", "inbuf"),
        ("const MPI_Fint *", "incount"),
        ("const MPI_Datatype *", "datatype"),
        ("void *", "outbuf"),
        ("const MPI_Fint *", "outsize"),
        ("int *", "position"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Unpack", [
        ("const void *", "inbuf"),
        ("const MPI_Fint *", "insize"),
        ("int *", "position"),
        ("void *", "outbuf"),
        ("const MPI_Fint *", "outcount"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Pack_size", [
        ("const MPI_Fint *", "incount"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Comm *", "comm"),
        ("int *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 4.3 Canonical MPI_PACK and MPI_UNPACK

    ("void", "MPI_Pack_external", [
        ("const char *", "datarep"),
        ("const void *", "inbuf"),
        ("const MPI_Fint *", "incount"),
        ("const MPI_Datatype *", "datatype"),
        ("void *", "outbuf"),
        ("const MPI_Aint *", "outsize"),
        ("MPI_Aint *", "position"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Unpack_external", [
        ("const char *", "datarep"),
        ("const void *", "inbuf"),
        ("const MPI_Aint *", "insize"),
        ("MPI_Aint *", "position"),
        ("void *", "outbuf"),
        ("const MPI_Fint *", "outcount"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Pack_external_size", [
        ("const char *", "datarep"),
        ("const MPI_Fint *", "incount"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Aint *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.3 Barrier Synchronization

    ("void", "MPI_Barrier", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.4 Broadcast

    ("void", "MPI_Bcast", [
        ("void *", "buffer"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.5 Gather

    ("void", "MPI_Gather", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Gatherv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.6 Scatter

    ("void", "MPI_Scatter", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Scatterv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.7 Gather-to-all

    ("void", "MPI_Allgather", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Allgatherv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.8 All-to-All Scatter/Gather

    ("void", "MPI_Alltoall", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Alltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Alltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("const MPI_Comm *", "comm"),
    ]),

    # 5.9 Global Reduction Operations

    ("void", "MPI_Reduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Op_create", [
        ("MPI_User_function *", "user_fn"),
        ("const MPI_Fint *", "commute"),
        ("MPI_Op *", "op"),
    ]),

    ("void", "MPI_Op_free", [
        ("MPI_Op *", "op"),
    ]),

    ("void", "MPI_Allreduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Op_commutative", [
        ("const MPI_Op *", "op"),
        ("int *", "commute"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Reduce_local", [
        ("const void *", "inbuf"),
        ("void *", "inoutbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.10 Reduce-Scatter

    ("void", "MPI_Reduce_scatter_block", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Reduce_scatter", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.11 Scan

    ("void", "MPI_Scan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Exscan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 5.12 Nonblocking Collective Operations

    ("void", "MPI_Ibarrier", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ibcast", [
        ("void *", "buffer"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Igather", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Igatherv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iscatter", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iscatterv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iallgather", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iallgatherv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ialltoall", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ialltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ialltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
    ]),

    ("void", "MPI_Ireduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iallreduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ireduce_scatter_block", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ireduce_scatter", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iscan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Iexscan", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 6.3 Group Management

    ("void", "MPI_Group_size", [
        ("const MPI_Group *", "group"),
        ("int *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_rank", [
        ("const MPI_Group *", "group"),
        ("int *", "rank"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_translate_ranks", [
        ("const MPI_Group *", "group1"),
        ("const MPI_Fint *", "n"),
        ("const int *", "ranks1"),
        ("const MPI_Group *", "group2"),
        ("int *", "ranks2"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_compare", [
        ("const MPI_Group *", "group1"),
        ("const MPI_Group *", "group2"),
        ("int *", "result"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_group", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Group *", "group"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_union", [
        ("const MPI_Group *", "group1"),
        ("const MPI_Group *", "group2"),
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_intersection", [
        ("const MPI_Group *", "group1"),
        ("const MPI_Group *", "group2"),
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_difference", [
        ("const MPI_Group *", "group1"),
        ("const MPI_Group *", "group2"),
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_incl", [
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "n"),
        ("const int *", "ranks"),
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_excl", [
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "n"),
        ("const int *", "ranks"),
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_range_incl", [
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "n"),
        ("MPI_Fint *", "ranges"),         # int[3]
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_range_excl", [
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "n"),
        ("MPI_Fint *", "ranges"),         # int[3]
        ("MPI_Group *", "newgroup"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Group_free", [
        ("MPI_Group *", "group"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 6.4 Communicator Management

    ("void", "MPI_Comm_size", [
        ("const MPI_Comm *", "comm"),
        ("int *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_rank", [
        ("const MPI_Comm *", "comm"),
        ("int *", "rank"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_compare", [
        ("const MPI_Comm *", "comm1"),
        ("const MPI_Comm *", "comm2"),
        ("int *", "result"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_dup", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_dup_with_info", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Info *", "info"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_idup", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_create", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Group *", "group"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_create_group", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "tag"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_split", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "color"),
        ("const MPI_Fint *", "key"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_split_type", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "split_type"),
        ("const MPI_Fint *", "key"),
        ("const MPI_Info *", "info"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_free", [
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_set_info", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_get_info", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 6.6 Inter-Communication

    ("void", "MPI_Comm_test_inter", [
        ("const MPI_Comm *", "comm"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_remote_size", [
        ("const MPI_Comm *", "comm"),
        ("int *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_remote_group", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Group *", "group"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Intercomm_create", [
        ("const MPI_Comm *", "local_comm"),
        ("const MPI_Fint *", "local_leader"),
        ("const MPI_Comm *", "peer_comm"),
        ("const MPI_Fint *", "remote_leader"),
        ("const MPI_Fint *", "tag"),
        ("MPI_Comm *", "newintercomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Intercomm_merge", [
        ("const MPI_Comm *", "intercomm"),
        ("const MPI_Fint *", "high"),
        ("MPI_Comm *", "newintracomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 6.7 Communicators

    ("void", "MPI_Comm_create_keyval", [
        ("MPI_Comm_copy_attr_function *", "comm_copy_attr_fn"),
        ("MPI_Comm_delete_attr_function *", "comm_delete_attr_fn"),
        ("int *", "comm_keyval"),
        ("void *", "extra_state"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_free_keyval", [
        ("int *", "comm_keyval"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_set_attr", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "comm_keyval"),
        ("void *", "attribute_val"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_get_attr", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "comm_keyval"),
        ("void *", "attribute_val"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_delete_attr", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "comm_keyval"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_create_keyval", [
        ("MPI_Win_copy_attr_function *", "win_copy_attr_fn"),
        ("MPI_Win_delete_attr_function *", "win_delete_attr_fn"),
        ("int *", "win_keyval"),
        ("void *", "extra_state"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_free_keyval", [
        ("int *", "win_keyval"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_set_attr", [
        ("const MPI_Win *", "win"),
        ("const MPI_Fint *", "win_keyval"),
        ("void *", "attribute_val"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_get_attr", [
        ("const MPI_Win *", "win"),
        ("const MPI_Fint *", "win_keyval"),
        ("void *", "attribute_val"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_delete_attr", [
        ("const MPI_Win *", "win"),
        ("const MPI_Fint *", "win_keyval"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_create_keyval", [
        ("MPI_Type_copy_attr_function *", "type_copy_attr_fn"),
        ("MPI_Type_delete_attr_function *", "type_delete_attr_fn"),
        ("int *", "type_keyval"),
        ("void *", "extra_state"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_free_keyval", [
        ("int *", "type_keyval"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_set_attr", [
        ("const MPI_Datatype *", "type"),
        ("const MPI_Fint *", "type_keyval"),
        ("void *", "attribute_val"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_attr", [
        ("const MPI_Datatype *", "type"),
        ("const MPI_Fint *", "type_keyval"),
        ("void *", "attribute_val"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_delete_attr", [
        ("const MPI_Datatype *", "type"),
        ("const MPI_Fint *", "type_keyval"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 6.8 Naming Objects

    ("void", "MPI_Comm_set_name", [
        ("const MPI_Comm *", "comm"),
        ("const char *", "comm_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_get_name", [
        ("const MPI_Comm *", "comm"),
        ("char *", "comm_name"),
        ("int *", "resultlen"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_set_name", [
        ("const MPI_Datatype *", "type"),
        ("const char *", "type_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_get_name", [
        ("const MPI_Datatype *", "type"),
        ("char *", "type_name"),
        ("int *", "resultlen"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_set_name", [
        ("const MPI_Win *", "win"),
        ("const char *", "win_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_get_name", [
        ("const MPI_Win *", "win"),
        ("char *", "win_name"),
        ("int *", "resultlen"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 7.5 Topology Constructors

    ("void", "MPI_Cart_create", [
        ("const MPI_Comm *", "comm_old"),
        ("const MPI_Fint *", "ndims"),
        ("const int *", "dims"),
        ("const int *", "periods"),
        ("const MPI_Fint *", "reorder"),
        ("MPI_Comm *", "comm_cart"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Dims_create", [
        ("const MPI_Fint *", "nnodes"),
        ("const MPI_Fint *", "ndims"),
        ("int *", "dims"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Graph_create", [
        ("const MPI_Comm *", "comm_old"),
        ("const MPI_Fint *", "nnodes"),
        ("const int *", "index"),
        ("const int *", "edges"),
        ("const MPI_Fint *", "reorder"),
        ("MPI_Comm *", "comm_graph"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Dist_graph_create_adjacent", [
        ("const MPI_Comm *", "comm_old"),
        ("const MPI_Fint *", "indegree"),
        ("const int *", "sources"),
        ("const int *", "sourceweights"),
        ("const MPI_Fint *", "outdegree"),
        ("const int *", "destinations"),
        ("const int *", "destweights"),
        ("const MPI_Info *", "info"),
        ("const MPI_Fint *", "reorder"),
        ("MPI_Comm *", "comm_dist_graph"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Dist_graph_create", [
        ("const MPI_Comm *", "comm_old"),
        ("const MPI_Fint *", "n"),
        ("const int *", "sources"),
        ("const int *", "degrees"),
        ("const int *", "destinations"),
        ("const int *", "weights"),
        ("const MPI_Info *", "info"),
        ("const MPI_Fint *", "reorder"),
        ("MPI_Comm *", "comm_dist_graph"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Topo_test", [
        ("const MPI_Comm *", "comm"),
        ("int *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Graphdims_get", [
        ("const MPI_Comm *", "comm"),
        ("int *", "nnodes"),
        ("int *", "nedges"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Graph_get", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "maxindex"),
        ("const MPI_Fint *", "maxedges"),
        ("int *", "index"),
        ("int *", "edges"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cartdim_get", [
        ("const MPI_Comm *", "comm"),
        ("int *", "ndims"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cart_get", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "maxdims"),
        ("int *", "dims"),
        ("int *", "periods"),
        ("int *", "coords"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cart_rank", [
        ("const MPI_Comm *", "comm"),
        ("const int *", "coords"),
        ("int *", "rank"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cart_coords", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "rank"),
        ("const MPI_Fint *", "maxdims"),
        ("int *", "coords"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Graph_neighbors_count", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "rank"),
        ("int *", "nneighbors"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Graph_neighbors", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "rank"),
        ("const MPI_Fint *", "maxneighbors"),
        ("int *", "neighbors"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Dist_graph_neighbors_count", [
        ("const MPI_Comm *", "comm"),
        ("int *", "indegree"),
        ("int *", "outdegree"),
        ("int *", "weighted"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Dist_graph_neighbors", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "maxindeegree"),
        ("int *", "sources"),
        ("int *", "wourceweights"),
        ("const MPI_Fint *", "maxoutdegree"),
        ("int *", "destinations"),
        ("int *", "destweights"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cart_shift", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "direction"),
        ("const MPI_Fint *", "disp"),
        ("int *", "rank_source"),
        ("int *", "rank_dest"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cart_sub", [
        ("const MPI_Comm *", "comm"),
        ("const int *", "remain_dims"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Cart_map", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "ndims"),
        ("const int *", "dims"),
        ("const int *", "periods"),
        ("int *", "newrank"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Graph_map", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "nnodes"),
        ("const int *", "index"),
        ("const int *", "edges"),
        ("int *", "newrank"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 7.6 Neighborhood Collective Communication on Procerss Topologies

    ("void", "MPI_Neighbor_allgather", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Neighbor_allgatherv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Neighbor_alltoall", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "senddtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Neighbor_alltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "senddtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Neighbor_alltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const MPI_Aint *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const MPI_Aint *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("const MPI_Comm *", "comm"),
    ]),

    # 7.7 Nonblocking Neighborhood Communication on Process Topologies

    ("void", "MPI_Ineighbor_allgather", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ineighbor_allgatherv", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "sendtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "displs"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ineighbor_alltoall", [
        ("const void *", "sendbuf"),
        ("const MPI_Fint *", "sendcount"),
        ("const MPI_Datatype *", "senddtype"),
        ("void *", "recvbuf"),
        ("const MPI_Fint *", "recvcount"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ineighbor_alltoallv", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const int *", "sdispls"),
        ("const MPI_Datatype *", "senddtype"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const int *", "rdispls"),
        ("const MPI_Datatype *", "recvtype"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Ineighbor_alltoallw", [
        ("const void *", "sendbuf"),
        ("const int *", "sendcounts"),
        ("const MPI_Aint *", "sdispls"),
        ("const MPI_Datatype *", "sendtypes"),
        ("void *", "recvbuf"),
        ("const int *", "recvcounts"),
        ("const MPI_Aint *", "rdispls"),
        ("const MPI_Datatype *", "recvtypes"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Request *", "request"),
    ]),

    # 8.1 Implementation Information

    ("void", "MPI_Get_version", [
        ("int *", "version"),
        ("int *", "subversion"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_library_version",[
        ("char *", "version"),
        ("int *", "resultlen"),
    ]),

    ("void", "MPI_Get_processor_name", [
        ("char *", "name"),
        ("int *", "resultlen"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 8.2 Memory Allocation

    ("void", "MPI_Alloc_mem", [
        ("const MPI_Aint *", "size"),
        ("const MPI_Info *", "info"),
        ("void *", "baseptr"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Free_mem", [
        ("void *", "base"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 8.3 Error Handling

    ("void", "MPI_Comm_create_errhandler", [
        ("MPI_Comm_errhandler_function *", "comm_errhandler_fn"),
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_set_errhandler", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_get_errhandler", [
        ("const MPI_Comm *", "comm"),
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_create_errhandler", [
        ("MPI_Win_errhandler_function *", "win_errhandler_fn"),
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_set_errhandler", [
        ("const MPI_Win *", "win"),
        ("const MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_get_errhandler",
     [("const MPI_Win *", "win"),
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_create_errhandler", [
        ("MPI_File_errhandler_function *", "file_errhandler_fn"),
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_set_errhandler", [
        ("const MPI_File *", "file"),
        ("const MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_errhandler", [
        ("const MPI_File *", "file"),
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Errhandler_free", [
        ("MPI_Errhandler *", "errhandler"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Error_string", [
        ("const MPI_Fint *", "errorcode"),
        ("char *", "string"),
        ("int *", "resultlen"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 8.4 Error Codes and Classes

    ("void", "MPI_Error_class", [
        ("const MPI_Fint *", "errorcode"),
        ("int *", "errorclass"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 8.5 Error Classes", "Error Codes", "and Error Handlers

    ("void", "MPI_Add_error_class", [
        ("int *", "errorclass"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Add_error_code", [
        ("const MPI_Fint *", "errorclass"),
        ("int *", "errorcode"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Add_error_string", [
        ("const MPI_Fint *", "errorcode"),
        ("const char *", "string"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_call_errhandler", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "errorcode"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_call_errhandler", [
        ("const MPI_Win *", "win"),
        ("const MPI_Fint *", "errorcode"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_call_errhandler", [
        ("const MPI_File *", "file"),
        ("const MPI_Fint *", "errorcode"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 8.6 Times and Synchronization

    ("double", "MPI_Wtime", [
    ]),

    ("double", "MPI_Wtick", [
    ]),

    # 8.7 Startup

    ("void", "MPI_Init", [
        ("int *", "argc"),
        ("char ***", "argv"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Finalize", []),

    ("void", "MPI_Initialized", [
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Abort", [
        ("const MPI_Comm *", "comm"),
        ("const MPI_Fint *", "errorcode"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Finalized", [
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 9 The Info Object

    ("void", "MPI_Info_create", [
        ("MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_set", [
        ("const MPI_Info *", "info"),
        ("const char *", "key"),
        ("const char *", "value"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_delete", [
        ("const MPI_Info *", "info"),
        ("const char *", "key"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_get", [
        ("const MPI_Info *", "info"),
        ("const char *", "key"),
        ("const MPI_Fint *", "valuelen"),
        ("char *", "value"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_get_valuelen", [
        ("const MPI_Info *", "info"),
        ("const char *", "key"),
        ("int *", "valuelen"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_get_nkeys", [
        ("const MPI_Info *", "info"),
        ("int *", "nkeys"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_get_nthkey", [
        ("const MPI_Info *", "info"),
        ("const MPI_Fint *", "n"),
        ("char *", "key"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_dup", [
        ("const MPI_Info *", "info"),
        ("MPI_Info *", "newinfo"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Info_free", [
        ("MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 10.3 Process Manager Interface

    ("void", "MPI_Comm_spawn", [
        ("const char *", "command"),
        ("char **", "argv"),
        ("const MPI_Fint *", "maxprocs"),
        ("const MPI_Info *", "info"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Comm *", "intercomm"),
        ("int *", "array_off_errcodes"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_get_parent", [
        ("MPI_Comm *", "parent"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_spawn_multiple", [
        ("const MPI_Fint *", "count"),
        ("char **", "array_of_commands"),
        ("char ***", "array_of_argv"),
        ("const int *", "array_of_maxprocs"),
        ("const MPI_Info *", "array_of_info"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Comm *", "intercomm"),
        ("int *", "array_of_errcodes"),
    ]),

    # 10.4 Establishing Communication

    ("void", "MPI_Open_port", [
        ("const MPI_Info *", "info"),
        ("char *", "port_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Close_port", [
        ("const char *", "port_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_accept", [
        ("const char *", "port_name"),
        ("const MPI_Info *", "info"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_connect", [
        ("const char *", "port_name"),
        ("const MPI_Info *", "info"),
        ("const MPI_Fint *", "root"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Publish_name", [
        ("const char *", "service_name"),
        ("const MPI_Info *", "info"),
        ("const char *", "port_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Unpublish_name", [
        ("const char *", "service_name"),
        ("const MPI_Info *", "info"),
        ("const char *", "port_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Lookup_name", [
        ("const char *", "service_name"),
        ("const MPI_Info *", "info"),
        ("char *", "port_name"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 10.5 Other Functionality

    ("void", "MPI_Comm_disconnect", [
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_join", [
        ("const MPI_Fint *", "fd"),
        ("MPI_Comm *", "intercomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 11.2 Initialization

    ("void", "MPI_Win_create", [
        ("void *", "base"),
        ("const MPI_Aint *", "size"),
        ("const MPI_Fint *", "disp_unit"),
        ("const MPI_Info *", "info"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_allocate", [
        ("const MPI_Aint *", "size"),
        ("const MPI_Fint *", "disp_unit"),
        ("const MPI_Info *", "info"),
        ("const MPI_Comm *", "comm"),
        ("void *", "baseptr"),
        ("MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_allocate_shared", [
        ("const MPI_Aint *", "size"),
        ("const MPI_Fint *", "disp_unit"),
        ("const MPI_Info *", "info"),
        ("const MPI_Comm *", "comm"),
        ("void *", "baseptr"),
        ("MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_shared_query", [
        ("const MPI_Win *", "win"),
        ("const MPI_Fint *", "rank"),
        ("MPI_Aint *", "size"),
        ("int *", "disp_unit"),
        ("void *", "baseptr"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_create_dynamic", [
        ("const MPI_Info *", "info"),
        ("const MPI_Comm *", "comm"),
        ("MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_attach", [
        ("const MPI_Win *", "win"),
        ("void *", "base"),
        ("const MPI_Aint *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_detach", [
        ("const MPI_Win *", "win"),
        ("const void *", "base"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_free", [
        ("MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_get_group", [
        ("const MPI_Win *", "win"),
        ("MPI_Group *", "group"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_set_info", [
        ("const MPI_Win *", "win"),
        ("const MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_get_info", [
        ("const MPI_Win *", "win"),
        ("MPI_Info *", "info_used"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 11.3 Communication Calls

    ("void", "MPI_Put", [
        ("const void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get", [
        ("void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Accumulate", [
        ("const void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_accumulate", [
        ("const void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("void *", "result_addr"),
        ("const MPI_Fint *", "result_count"),
        ("const MPI_Datatype *", "result_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Fetch_and_op", [
        ("const void *", "origin_addr"),
        ("void *", "result_addr"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Op *", "op"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Compare_and_swap", [
        ("const void *", "origin_addr"),
        ("const void *", "compare_addr"),
        ("void *", "result_addr"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Rput", [
        ("const void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Win *", "win"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Rget", [
        ("void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Win *", "win"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Raccumulate", [
        ("const void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Win *", "win"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Rget_accumulate", [
        ("const void *", "origin_addr"),
        ("const MPI_Fint *", "origin_count"),
        ("const MPI_Datatype *", "origin_datatype"),
        ("void *", "result_addr"),
        ("const MPI_Fint *", "result_count"),
        ("const MPI_Datatype *", "result_datatype"),
        ("const MPI_Fint *", "target_rank"),
        ("const MPI_Aint *", "target_disp"),
        ("const MPI_Fint *", "target_count"),
        ("const MPI_Datatype *", "target_datatype"),
        ("const MPI_Op *", "op"),
        ("const MPI_Win *", "win"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 11.5 Synchronization Calls

    ("void", "MPI_Win_fence", [
        ("const MPI_Fint *", "assert"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_start", [
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "assert"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_complete", [
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_post", [
        ("const MPI_Group *", "group"),
        ("const MPI_Fint *", "assert"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_wait", [
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_test", [
        ("const MPI_Win *", "win"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_lock", [
        ("const MPI_Fint *", "lock_type"),
        ("const MPI_Fint *", "rank"),
        ("const MPI_Fint *", "assert"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_lock_all", [
        ("const MPI_Fint *", "assert"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_unlock", [
        ("const MPI_Fint *", "rank"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_unlock_all", [
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_flush", [
        ("const MPI_Fint *", "rank"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_flush_all", [
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_flush_local", [
        ("const MPI_Fint *", "rank"),
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_flush_local_all", [
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Win_sync", [
        ("const MPI_Win *", "win"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 12.2 Generalized Requests

    # TODO: Handle status correctly
    # ("void", "MPI_Grequest_start", [
    #     ("MPI_Grequest_query_function *", "query_fn"),
    #     ("MPI_Grequest_free_function *", "free_fn"),
    #     ("MPI_Grequest_cancel_function *", "cancel_fn"),
    #     ("void *", "extra_state"),
    #     ("MPI_Request *", "request"),
    #     ("MPI_Fint *", "ierror"),
    # ]),

    ("void", "MPI_Grequest_complete", [
        ("const MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 12.3 Associating Information with Status

    ("void", "MPI_Status_set_elements", [
        ("MPI_Status *", "status"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Fint *", "count"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Status_set_elements_x", [
        ("MPI_Status *", "status"),
        ("const MPI_Datatype *", "datatype"),
        ("const MPI_Count *", "count"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Status_set_cancelled", [
        ("MPI_Status *", "status"),
        ("const MPI_Fint *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 12.4 MPI and Threads

    ("void", "MPI_Init_thread", [
        ("int *", "argc"),
        ("char * * *", "argv"),
        ("const MPI_Fint *", "required"),
        ("int *", "provided"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Query_thread", [
        ("int *", "provided"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Is_thread_main", [
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 13.2 File Manipulation

    ("void", "MPI_File_open", [
        ("const MPI_Comm *", "comm"),
        ("const char *", "filename"),
        ("const MPI_Fint *", "amode"),
        ("const MPI_Info *", "info"),
        ("MPI_File *", "fh"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_close", [
        ("MPI_File *", "fh"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_delete", [
        ("const char *", "filename"),
        ("const MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_set_size", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_preallocate", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_size", [
        ("const MPI_File *", "fh"),
        ("MPI_Offset *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_group", [
        ("const MPI_File *", "fh"),
        ("MPI_Group *", "group"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_amode", [
        ("const MPI_File *", "fh"),
        ("int *", "amode"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_set_info", [
        ("const MPI_File *", "fh"),
        ("const MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_info", [
        ("const MPI_File *", "fh"),
        ("MPI_Info *", "info_used"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 13.3 File View

    ("void", "MPI_File_set_view", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "disp"),
        ("const MPI_Datatype *", "etype"),
        ("const MPI_Datatype *", "filetype"),
        ("const char *", "datarep"),
        ("const MPI_Info *", "info"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_view", [
        ("const MPI_File *", "fh"),
        ("MPI_Offset *", "disp"),
        ("MPI_Datatype *", "etype"),
        ("MPI_Datatype *", "filetype"),
        ("char *", "datarep"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 13.4 Data Access

    ("void", "MPI_File_read_at", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_at_all", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_at", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_at_all", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iread_at", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iread_at_all", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iwrite_at", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iwrite_at_all", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_all", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_all", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iread", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iread_all", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iwrite", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iwrite_all", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_seek", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const MPI_Fint *", "whence"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_position", [
        ("const MPI_File *", "fh"),
        ("MPI_Offset *", "offset"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_byte_offset", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("MPI_Offset *", "disp"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_shared", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_shared", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iread_shared", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_iwrite_shared", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Request *", "request"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_ordered", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_ordered", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_seek_shared", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const MPI_Fint *", "whence"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_position_shared", [
        ("const MPI_File *", "fh"),
        ("MPI_Offset *", "offset"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_at_all_begin", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_at_all_end", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_at_all_begin", [
        ("const MPI_File *", "fh"),
        ("const MPI_Offset *", "offset"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_at_all_end", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_all_begin", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_all_end", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_all_begin", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_all_end", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_ordered_begin", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_read_ordered_end", [
        ("const MPI_File *", "fh"),
        ("void *", "buf"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_ordered_begin", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("const MPI_Fint *", "count"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_write_ordered_end", [
        ("const MPI_File *", "fh"),
        ("const void *", "buf"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 13.5 File Interoperability

    ("void", "MPI_File_get_type_extent", [
        ("const MPI_File *", "fh"),
        ("const MPI_Datatype *", "datatype"),
        ("MPI_Aint *", "extent"),
        ("MPI_Fint *", "ierror"),
    ]),

    # TODO: Handle conversions
    # ("void", "MPI_Register_datarep", [
    #     ("const char *", "datarep"),
    #     ("MPI_Datarep_conversion_function *", "read_conversion_fn"),
    #     ("MPI_Datarep_conversion_function *", "write_conversion_fn"),
    #     ("MPI_Datarep_extent_function *", "dtype_file_extent_fn"),
    #     ("void *", "extra_state"),
    #     ("MPI_Fint *", "ierror"),
    # ]),

    # 13.6 Consistency and Semantics

    ("void", "MPI_File_set_atomicity", [
        ("const MPI_File *", "fh"),
        ("const MPI_Fint *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_get_atomicity", [
        ("const MPI_File *", "fh"),
        ("int *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_File_sync", [
        ("const MPI_File *", "fh"),
        ("MPI_Fint *", "ierror"),
    ]),

]
