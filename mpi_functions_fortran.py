# The section names follow the MPI 3.1 standard.

functions_fortran = [

    # 3.2 Blocking Send and Receive Operations

    ("void", "MPI_Send", [
        ("const void *", "buf"),
        ("MPI_Fint *", "count"),
        ("MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "dest"),
        ("MPI_Fint *", "tag"),
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Recv", [
        ("const void *", "buf"),
        ("MPI_Fint *", "count"),
        ("MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "source"),
        ("MPI_Fint *", "tag"),
        ("MPI_Comm *", "comm"),
        ("MPI_Status *", "status"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Get_count", [
        ("MPI_Status *", "status"),
        ("MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "count"),
        ("MPI_Fint *", "ierror"),
    ]),

    # 6.4 Communicator Management

    ("void", "MPI_Comm_size", [
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Comm_rank", [
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "rank"),
        ("MPI_Fint *", "ierror"),
    ]),

    # ...

    # 8.6 Times and Synchronization

    ("double", "MPI_Wtime", [
    ]),

    ("double", "MPI_Wtick", [
    ]),

    # 8.7 Startup

    ("void", "MPI_Init", [
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Finalize", [
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Initialized", [
        ("MPI_Fint *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Abort", [
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "errorcode"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Finalized", [
        ("MPI_Fint *", "flag"),
        ("MPI_Fint *", "ierror"),
    ]),

    ########################################

    ("void", "MPI_Comm_dup", [
        ("MPI_Comm *", "comm"),
        ("MPI_Comm *", "newcomm"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Type_size", [
        ("MPI_Datatype *", "datatype"),
        ("MPI_Fint *", "size"),
        ("MPI_Fint *", "ierror"),
    ]),

    ("void", "MPI_Allreduce", [
        ("const void *", "sendbuf"),
        ("void *", "recvbuf"),
        ("MPI_Fint *", "count"),
        ("MPI_Datatype *", "datatype"),
        ("MPI_Op *", "op"),
        ("MPI_Comm *", "comm"),
        ("MPI_Fint *", "ierror"),
    ]),

]
