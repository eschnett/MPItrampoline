// We follow the naming conventions of MPICH. (Thank you, MPICH
// developers!)

// The section names follow the MPI 3.1 standard.

// 3.2 Blocking Send and Receive Operations
FUNCTION(int, Send,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm))
FUNCTION(int, Recv,
         (void *buf, int count, MT(Datatype) datatype, int source, int tag,
          MT(Comm) comm, MT(StatusPtr) status),
         (buf, count, (MP(Datatype))datatype, source, tag, (MP(Comm))comm,
          (MP(StatusPtr))status))
FUNCTION(int, Get_count,
         (MT(StatusPtr) status, MT(Datatype) datatype, int *count),
         ((MP(StatusPtr))status, (MP(Datatype))datatype, count))

// 3.4 Communication Modes
FUNCTION(int, Bsend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm))
FUNCTION(int, Ssend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm))
FUNCTION(int, Rsend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm))

// 3.6 Buffer Allocation and Usage
FUNCTION(int, Buffer_attach, (void *buffer, int size), (buffer, size))
FUNCTION(int, Buffer_detach, (void *buffer_addr, int *size),
         (buffer_addr, size))

// 3.7 Nonblocking Communication
FUNCTION(int, Isend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Ibsend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Issend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Irsend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Irecv,
         (void *buf, int count, MT(Datatype) datatype, int source, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, source, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Wait, (MT(Request) * request, MT(StatusPtr) status),
         ((MP(Request) *)request, (MP(StatusPtr))status))
FUNCTION(int, Test, (MT(Request) * request, int *flag, MT(StatusPtr) status),
         ((MP(Request) *)request, flag, (MP(StatusPtr))status))
FUNCTION(int, Request_free, (MT(Request) * request), ((MP(Request) *)request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Waitany,
         (int count, MT(Request) array_of_requests[], int *indx,
          MT(StatusPtr) status),
         (count, (MP(Request) *)array_of_requests, indx, (MP(StatusPtr))status))
FUNCTION(int, Testany,
         (int count, MT(Request) array_of_requests[], int *indx, int *flag,
          MT(StatusPtr) status),
         (count, (MP(Request) *)array_of_requests, indx, flag,
          (MP(StatusPtr))status))
FUNCTION(int, Waitall,
         (int count, MT(Request) array_of_requests[], MT(StatusPtr) status),
         (count, (MP(Request) *)array_of_requests, (MP(StatusPtr))status))
FUNCTION(int, Testall,
         (int count, MT(Request) array_of_requests[], int *flag,
          MT(StatusPtr) status),
         (count, (MP(Request) *)array_of_requests, flag, (MP(StatusPtr))status))
FUNCTION(int, Waitsome,
         (int incount, MT(Request) array_of_requests[], int *outcount,
          int array_of_indices[], MT(Status) array_of_statuses[]),
         (incount, (MP(Request) *)array_of_requests, outcount, array_of_indices,
          (MP(Status) *)array_of_statuses))
FUNCTION(int, Testsome,
         (int incount, MT(Request) array_of_requests[], int *outcount,
          int array_of_indices[], MT(Status) array_of_statuses[]),
         (incount, (MP(Request) *)array_of_requests, outcount, array_of_indices,
          (MP(Status) *)array_of_statuses))
#endif

// 3.8 Probe and Cancel
FUNCTION(int, Iprobe,
         (int source, int tag, MT(Comm) comm, int *flag, MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, flag, (MP(StatusPtr))status))
FUNCTION(int, Probe, (int source, int tag, MT(Comm) comm, MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, (MP(StatusPtr))status))
FUNCTION(int, Improbe,
         (int source, int tag, MT(Comm) comm, int *flag, MT(Message) * message,
          MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, flag, (MP(Message) *)message,
          (MP(StatusPtr))status))
FUNCTION(int, Mprobe,
         (int source, int tag, MT(Comm) comm, MT(Message) * message,
          MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, (MP(Message) *)message,
          (MP(StatusPtr))status))
FUNCTION(int, Mrecv,
         (void *buf, int count, MT(Datatype) datatype, MT(Message) * message,
          MT(StatusPtr) status),
         (buf, count, (MP(Datatype))datatype, (MP(Message) *)message,
          (MP(StatusPtr))status))
FUNCTION(int, Imrecv,
         (void *buf, int count, MT(Datatype) datatype, MT(Message) * message,
          MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, (MP(Message) *)message,
          (MP(Request) *)request))
FUNCTION(int, Cancel, (MT(Request) * request), ((MP(Request) *)request))
FUNCTION(int, Test_cancelled, (MT(const_StatusPtr) status, int *flag),
         ((MP(const_StatusPtr))status, flag))

// 3.9 Persistent Communication Requests
FUNCTION(int, Send_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Bsend_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Ssend_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Rsend_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Recv_init,
         (void *buf, int count, MT(Datatype) datatype, int source, int tag,
          MT(Comm) comm, MT(Request) * request),
         (buf, count, (MP(Datatype))datatype, source, tag, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Start, (MT(Request) * request), ((MP(Request) *)request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Startall, (int count, MT(Request) array_of_requests[]),
         (count, (MP(Request) *)array_of_requests))
#endif

// 3.10 Send-Receive
FUNCTION(int, Sendrecv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype, int dest,
          int sendtag, void *recvbuf, int recvcount, MT(Datatype) recvtype,
          int source, int recvtag, MT(Comm) comm, MT(StatusPtr) status),
         (sendbuf, sendcount, (MP(Datatype))sendtype, dest, sendtag, recvbuf,
          recvcount, (MP(Datatype))recvtype, source, recvtag, (MP(Comm))comm,
          (MP(StatusPtr))status))
FUNCTION(int, Sendrecv_replace,
         (void *buf, int count, MT(Datatype) datatype, int dest, int sendtag,
          int source, int recvtag, MT(Comm) comm, MT(StatusPtr) status),
         (buf, count, (MP(Datatype))datatype, dest, sendtag, source, recvtag,
          (MP(Comm))comm, (MP(StatusPtr))status))

// 4.1 Derived Datatypes
FUNCTION(int, Type_contiguous,
         (int count, MT(Datatype) oldtype, MT(Datatype) * newtype),
         (count, (MP(Datatype))oldtype, (MP(Datatype) *)newtype))
FUNCTION(int, Type_vector,
         (int count, int blocklength, int stride, MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (count, blocklength, stride, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_hvector,
         (int count, int blocklength, MT(Aint) stride, MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (count, blocklength, (MP(Aint))stride, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_hvector,
//          (int count, int blocklength, MT(Aint) stride, MT(Datatype) oldtype,
//           MT(Datatype) * newtype),
//          (count, blocklength, (MP(Aint))stride, (MP(Datatype))oldtype,
//           (MP(Datatype) *)newtype))
FUNCTION(int, Type_indexed,
         (int count, const int *array_of_blocklengths,
          const int *array_of_displacements, MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (count, array_of_blocklengths, array_of_displacements,
          (MP(Datatype))oldtype, (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_hindexed,
         (int count, const int array_of_blocklengths[],
          const MT(Aint) array_of_displacements[], MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (count, array_of_blocklengths,
          (const MP(Aint) *)array_of_displacements, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_hindexed,
//          (int count, int *array_of_blocklengths,
//           MT(Aint) * array_of_displacements, MT(Datatype) oldtype,
//           MT(Datatype) * newtype),
//          (count, array_of_blocklengths, (MP(Aint) *)array_of_displacements,
//           (MP(Datatype))oldtype, (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_indexed_block,
         (int count, int blocklength, const int array_of_displacements[],
          MT(Datatype) oldtype, MT(Datatype) * newtype),
         (count, blocklength, array_of_displacements, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_hindexed_block,
         (int count, int blocklength, const MT(Aint) array_of_displacements[],
          MT(Datatype) oldtype, MT(Datatype) * newtype),
         (count, blocklength, (const MP(Aint) *)array_of_displacements,
          (MP(Datatype))oldtype, (MP(Datatype) *)newtype))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Type_create_struct,
         (int count, const int array_of_blocklengths[],
          const MT(Aint) array_of_displacements[],
          const MT(Datatype) array_of_types[], MT(Datatype) * newtype),
         (count, array_of_blocklengths,
          (const MP(Aint) *)array_of_displacements,
          (const MP(Datatype) *)array_of_types, (MP(Datatype) *)newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_struct,
//          (int count, int *array_of_blocklengths,
//           MT(Aint) * array_of_displacements, MT(Datatype) * array_of_types,
//           MT(Datatype) * newtype),
//          (count, array_of_blocklengths, (MP(Aint) *)array_of_displacements,
//           (MP(Datatype) *)array_of_types, (MP(Datatype) *)newtype))
#endif
FUNCTION(int, Type_create_subarray,
         (int ndims, const int array_of_sizes[], const int array_of_subsizes[],
          const int array_of_starts[], int ordder, MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (ndims, array_of_sizes, array_of_subsizes, array_of_starts, ordder,
          (MP(Datatype))oldtype, (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_darray,
         (int size, int rank, int ndims, const int array_of_gsizes[],
          const int array_of_distribs[], const int array_of_dargs[],
          const int array_of_psizes[], int order, MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
          array_of_psizes, order, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))
FUNCTION(int, Get_address, (const void *location, MT(Aint) * address),
         (location, (MP(Aint) *)address))
FUNCTION(MT(Aint), Aint_add, (MT(Aint) base, MT(Aint) disp),
         ((MP(Aint))base, (MP(Aint))disp))
FUNCTION(MT(Aint), Aint_diff, (MT(Aint) addr1, MT(Aint) addr2),
         ((MP(Aint))addr1, (MP(Aint))addr2))
FUNCTION(int, Type_size, (MT(Datatype) datatype, int *size),
         ((MP(Datatype))datatype, size))
FUNCTION(int, Type_size_x, (MT(Datatype) datatype, MT(Count) * size),
         ((MP(Datatype))datatype, (MP(Count) *)size))
FUNCTION(int, Type_get_extent,
         (MT(Datatype) datatype, MT(Aint) * lb, MT(Aint) * extent),
         ((MP(Datatype))datatype, (MP(Aint) *)lb, (MP(Aint) *)extent))
FUNCTION(int, Type_get_extent_x,
         (MT(Datatype) datatype, MT(Count) * lb, MT(Count) * extent),
         ((MP(Datatype))datatype, (MP(Count) *)lb, (MP(Count) *)extent))
FUNCTION(int, Type_create_resized,
         (MT(Datatype) oldtype, MT(Aint) lb, MT(Aint) extent,
          MT(Datatype) * newtype),
         ((MP(Datatype))oldtype, (MP(Aint))lb, (MP(Aint))extent,
          (MP(Datatype) *)newtype))
FUNCTION(int, Type_get_true_extent,
         (MT(Datatype) datatype, MT(Aint) * true_lb, MT(Aint) * true_extent),
         ((MP(Datatype))datatype, (MP(Aint) *)true_lb, (MP(Aint) *)true_extent))
FUNCTION(int, Type_get_true_extent_x,
         (MT(Datatype) datatype, MT(Count) * true_lb, MT(Count) * true_extent),
         ((MP(Datatype))datatype, (MP(Count) *)true_lb,
          (MP(Count) *)true_extent))
FUNCTION(int, Type_commit, (MT(Datatype) * datatype),
         ((MP(Datatype) *)datatype))
FUNCTION(int, Type_free, (MT(Datatype) * datatype), ((MP(Datatype) *)datatype))
FUNCTION(int, Type_dup, (MT(Datatype) oldtype, MT(Datatype) * newtype),
         ((MP(Datatype))oldtype, (MP(Datatype) *)newtype))
FUNCTION(int, Get_elements,
         (MT(const_StatusPtr) status, MT(Datatype) datatype, int *count),
         ((MP(const_StatusPtr))status, (MP(Datatype))datatype, count))
FUNCTION(int, Get_elements_x,
         (MT(const_StatusPtr) status, MT(Datatype) datatype, MT(Count) * count),
         ((MP(const_StatusPtr))status, (MP(Datatype))datatype,
          (MP(Count) *)count))
FUNCTION(int, Type_get_envelope,
         (MT(Datatype) datatype, int *num_integers, int *num_addresses,
          int *num_datatypes, int *combiner),
         ((MP(Datatype))datatype, num_integers, num_addresses, num_datatypes,
          combiner))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Type_get_contents,
         (MT(Datatype) datatype, int max_integers, int max_addresses,
          int max_datatypes, int array_of_integers[],
          MT(Aint) array_of_addresses[], MT(Datatype) array_of_datatypes[]),
         ((MP(Datatype))datatype, max_integers, max_addresses, max_datatypes,
          array_of_integers, (MP(Aint) *)array_of_addresses,
          (MP(Datatype) *)array_of_datatypes))
#endif
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Address, (void *location, MT(Aint) * address),
//          (location, (MP(Aint) *)address))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_extent, (MT(Datatype) datatype, MT(Aint) * extent),
//          ((MP(Datatype))datatype, (MP(Aint) *)extent))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_lb, (MT(Datatype) datatype, MT(Aint) * displacement),
//          ((MP(Datatype))datatype, (MP(Aint) *)displacement))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_ub, (MT(Datatype) datatype, MT(Aint) * displacement),
//          ((MP(Datatype))datatype, (MP(Aint) *)displacement))

// 4.2 Pack and Unpack
FUNCTION(int, Pack,
         (const void *inbuf, int incount, MT(Datatype) datatype, void *outbuf,
          int outsize, int *position, MT(Comm) comm),
         (inbuf, incount, (MP(Datatype))datatype, outbuf, outsize, position,
          (MP(Comm))comm))
FUNCTION(int, Unpack,
         (const void *inbuf, int insize, int *position, void *outbuf,
          int outcount, MT(Datatype) datatype, MT(Comm) comm),
         (inbuf, insize, position, outbuf, outcount, (MP(Datatype))datatype,
          (MP(Comm))comm))
FUNCTION(int, Pack_size,
         (int incount, MT(Datatype) datatype, MT(Comm) comm, int *size),
         (incount, (MP(Datatype))datatype, (MP(Comm))comm, size))

// 4.3 Canonical MPI_PACK and MPI_UNPACK
FUNCTION(int, Pack_external,
         (const char datarep[], const void *inbuf, int incount,
          MT(Datatype) datatype, void *outbuf, MT(Aint) outsize,
          MT(Aint) * position),
         (datarep, inbuf, incount, (MP(Datatype))datatype, outbuf,
          (MP(Aint))outsize, (MP(Aint) *)position))
FUNCTION(int, Unpack_external,
         (const char datarep[], const void *inbuf, MT(Aint) insize,
          MT(Aint) * position, void *outbuf, int outcount,
          MT(Datatype) datatype),
         (datarep, inbuf, (MP(Aint))insize, (MP(Aint) *)position, outbuf,
          outcount, (MP(Datatype))datatype))
FUNCTION(int, Pack_external_size,
         (const char datarep[], int incount, MT(Datatype) datatype,
          MT(Aint) * size),
         (datarep, incount, (MP(Datatype))datatype, (MP(Aint) *)size))

// 5.3 Barrier Synchronization
FUNCTION(int, Barrier, (MT(Comm) comm), ((MP(Comm))comm))

// 5.4 Broadcast
FUNCTION(int, Bcast,
         (void *buffer, int count, MT(Datatype) datatype, int root,
          MT(Comm) comm),
         (buffer, count, (MP(Datatype))datatype, root, (MP(Comm))comm))

// 5.5 Gather
FUNCTION(int, Gather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, int root,
          MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, root, (MP(Comm))comm))
FUNCTION(int, Gatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int *recvcounts, const int *displs,
          MT(Datatype) recvtype, int root, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, root, (MP(Comm))comm))

// 5.6 Scatter
FUNCTION(int, Scatter,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, int root,
          MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, root, (MP(Comm))comm))
FUNCTION(int, Scatterv,
         (const void *sendbuf, const int *sendcounts, const int *displs,
          MT(Datatype) sendtype, void *recvbuf, int recvcount,
          MT(Datatype) recvtype, int root, MT(Comm) comm),
         (sendbuf, sendcounts, displs, (MP(Datatype))sendtype, recvbuf,
          recvcount, (MP(Datatype))recvtype, root, (MP(Comm))comm))

// 5.7 Gather-to-all
FUNCTION(int, Allgather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm))
FUNCTION(int, Allgatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int *recvcounts, const int *displs,
          MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, (MP(Comm))comm))

// 5.8 All-to-All Scatter/Gather
FUNCTION(int, Alltoall,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm))
FUNCTION(int, Alltoallv,
         (const void *sendbuf, const int *sendcounts, const int *sdispls,
          MT(Datatype) sendtype, void *recvbuf, const int *recvcounts,
          const int *rdispls, MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcounts, sdispls, (MP(Datatype))sendtype, recvbuf,
          recvcounts, rdispls, (MP(Datatype))recvtype, (MP(Comm))comm))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Alltoallw,
         (const void *sendbuf, const int sendcounts[], const int sdispls[],
          const MT(Datatype) sendtypes[], void *recvbuf, const int recvcounts[],
          const int rdispls[], const MT(Datatype) recvtypes[], MT(Comm) comm),
         (sendbuf, sendcounts, sdispls, (MP(Datatype) *)sendtypes, recvbuf,
          recvcounts, rdispls, (const MP(Datatype) *)recvtypes, (MP(Comm))comm))
#endif

// 5.9 Global Reduction Operations
FUNCTION(int, Reduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, int root, MT(Comm) comm),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op, root,
          (MP(Comm))comm))
FUNCTION(int, Op_create,
         (MT(User_function) * user_fn, int commute, MT(Op) * op),
         ((MP(User_function) *)user_fn, commute, (MP(Op) *)op))
FUNCTION(int, Op_free, (MT(Op) * op), ((MP(Op) *)op))
FUNCTION(int, Allreduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm))
FUNCTION(int, Reduce_local,
         (const void *inbuf, void *inoutbuf, int count, MT(Datatype) datatype,
          MT(Op) op),
         (inbuf, inoutbuf, count, (MP(Datatype))datatype, (MP(Op))op))
FUNCTION(int, Op_commutative, (MT(Op) op, int *commute), ((MP(Op))op, commute))

// 5.10 Reduce-Scatter
FUNCTION(int, Reduce_scatter_block,
         (const void *sendbuf, void *recvbuf, int recvcount,
          MT(Datatype) datatype, MT(Op) op, MT(Comm) comm),
         (sendbuf, recvbuf, recvcount, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm))
FUNCTION(int, Reduce_scatter,
         (const void *sendbuf, void *recvbuf, const int recvcounts[],
          MT(Datatype) datatype, MT(Op) op, MT(Comm) comm),
         (sendbuf, recvbuf, recvcounts, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm))

// 5.11 Scan
FUNCTION(int, Scan,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm))
FUNCTION(int, Exscan,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm))

// 5.12 Nonblocking Collective Operations
FUNCTION(int, Ibarrier, (MT(Comm) comm, MT(Request) * request),
         ((MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Ibcast,
         (void *buffer, int count, MT(Datatype) datatype, int root,
          MT(Comm) comm, MT(Request) * request),
         (buffer, count, (MP(Datatype))datatype, root, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Igather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, int root,
          MT(Comm) comm, MT(Request) * request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, root, (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Igatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int *recvcounts, const int *displs,
          MT(Datatype) recvtype, int root, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, root, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Iscatter,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, int root,
          MT(Comm) comm, MT(Request) * request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, root, (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Iscatterv,
         (const void *sendbuf, const int *sendcounts, const int *displs,
          MT(Datatype) sendtype, void *recvbuf, int recvcount,
          MT(Datatype) recvtype, int root, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, sendcounts, displs, (MP(Datatype))sendtype, recvbuf,
          recvcount, (MP(Datatype))recvtype, root, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Iallgather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Iallgatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int *recvcounts, const int *displs,
          MT(Datatype) recvtype, MT(Comm) comm, MT(Request) * request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, (MP(Comm))comm,
          (MP(Request) *)request))
FUNCTION(int, Ialltoall,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Ialltoallv,
         (const void *sendbuf, const int *sendcounts, const int *sdispls,
          MT(Datatype) sendtype, void *recvbuf, const int *recvcounts,
          const int *rdispls, MT(Datatype) recvtype, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, sendcounts, sdispls, (MP(Datatype))sendtype, recvbuf,
          recvcounts, rdispls, (MP(Datatype))recvtype, (MP(Comm))comm,
          (MP(Request) *)request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Ialltoallw,
         (const void *sendbuf, const int sendcounts[], const int sdispls[],
          const MT(Datatype) sendtypes[], void *recvbuf, const int recvcounts[],
          const int rdispls[], const MT(Datatype) recvtypes[], MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, sendcounts, sdispls, (MP(Datatype) *)sendtypes, recvbuf,
          recvcounts, rdispls, (const MP(Datatype) *)recvtypes, (MP(Comm))comm,
          (MP(Request) *)request))
#endif
FUNCTION(int, Ireduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, int root, MT(Comm) comm, MT(Request) * request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op, root,
          (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Iallreduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm, MT(Request) * request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Ireduce_scatter_block,
         (const void *sendbuf, void *recvbuf, int recvcount,
          MT(Datatype) datatype, MT(Op) op, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, recvbuf, recvcount, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Ireduce_scatter,
         (const void *sendbuf, void *recvbuf, const int recvcounts[],
          MT(Datatype) datatype, MT(Op) op, MT(Comm) comm,
          MT(Request) * request),
         (sendbuf, recvbuf, recvcounts, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Iscan,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm, MT(Request) * request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(Request) *)request))
FUNCTION(int, Iexscan,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm, MT(Request) * request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(Request) *)request))

// 6.3 Group Management
FUNCTION(int, Group_size, (MT(Group) group, int *size),
         ((MP(Group))group, size))
FUNCTION(int, Group_rank, (MT(Group) group, int *rank),
         ((MP(Group))group, rank))
FUNCTION(int, Group_translate_ranks,
         (MT(Group) group1, int n, const int ranks1[], MT(Group) group2,
          int ranks2[]),
         ((MP(Group))group1, n, ranks1, (MP(Group))group2, ranks2))
FUNCTION(int, Group_compare, (MT(Group) group1, MT(Group) group2, int *result),
         ((MP(Group))group1, (MP(Group))group2, result))
FUNCTION(int, Comm_group, (MT(Comm) comm, MT(Group) * group),
         ((MP(Comm))comm, (MP(Group) *)group))
FUNCTION(int, Group_union,
         (MT(Group) group1, MT(Group) group2, MT(Group) * newgroup),
         ((MP(Group))group1, (MP(Group))group2, (MP(Group) *)newgroup))
FUNCTION(int, Group_intersection,
         (MT(Group) group1, MT(Group) group2, MT(Group) * newgroup),
         ((MP(Group))group1, (MP(Group))group2, (MP(Group) *)newgroup))
FUNCTION(int, Group_difference,
         (MT(Group) group1, MT(Group) group2, MT(Group) * newgroup),
         ((MP(Group))group1, (MP(Group))group2, (MP(Group) *)newgroup))
FUNCTION(int, Group_incl,
         (MT(Group) group, int n, const int ranks[], MT(Group) * newgroup),
         ((MP(Group))group, n, ranks, (MP(Group) *)newgroup))
FUNCTION(int, Group_excl,
         (MT(Group) group, int n, const int ranks[], MT(Group) * newgroup),
         ((MP(Group))group, n, ranks, (MP(Group) *)newgroup))
FUNCTION(int, Group_range_incl,
         (MT(Group) group, int n, int ranges[][3], MT(Group) * newgroup),
         ((MP(Group))group, n, ranges, (MP(Group) *)newgroup))
FUNCTION(int, Group_range_excl,
         (MT(Group) group, int n, int ranges[][3], MT(Group) * newgroup),
         ((MP(Group))group, n, ranges, (MP(Group) *)newgroup))
FUNCTION(int, Group_free, (MT(Group) * group), ((MP(Group) *)group))

// 6.4 Communicator Management
FUNCTION(int, Comm_size, (MT(Comm) comm, int *size), ((MP(Comm))comm, size))
FUNCTION(int, Comm_rank, (MT(Comm) comm, int *rank), ((MP(Comm))comm, rank))
FUNCTION(int, Comm_compare, (MT(Comm) comm1, MT(Comm) comm2, int *result),
         ((MP(Comm))comm1, (MP(Comm))comm2, result))
FUNCTION(int, Comm_dup, (MT(Comm) comm, MT(Comm) * newcomm),
         ((MP(Comm))comm, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_dup_with_info,
         (MT(Comm) comm, MT(Info) info, MT(Comm) * newcomm),
         ((MP(Comm))comm, (MP(Info))info, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_idup,
         (MT(Comm) comm, MT(Comm) * newcomm, MT(Request) * request),
         ((MP(Comm))comm, (MP(Comm) *)newcomm, (MP(Request) *)request))
FUNCTION(int, Comm_create, (MT(Comm) comm, MT(Group) group, MT(Comm) * newcomm),
         ((MP(Comm))comm, (MP(Group))group, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_create_group,
         (MT(Comm) comm, MT(Group) group, int tag, MT(Comm) * newcomm),
         ((MP(Comm))comm, (MP(Group))group, tag, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_split,
         (MT(Comm) comm, int color, int key, MT(Comm) * newcomm),
         ((MP(Comm))comm, color, key, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_split_type,
         (MT(Comm) comm, int split_type, int key, MT(Info) info,
          MT(Comm) * newcomm),
         ((MP(Comm))comm, split_type, key, (MP(Info))info, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_free, (MT(Comm) * comm), ((MP(Comm) *)comm))
FUNCTION(int, Comm_set_info, (MT(Comm) comm, MT(Info) info),
         ((MP(Comm))comm, (MP(Info))info))
FUNCTION(int, Comm_get_info, (MT(Comm) comm, MT(Info) * info),
         ((MP(Comm))comm, (MP(Info) *)info))

// 6.6 Inter-Communication
FUNCTION(int, Comm_test_inter, (MT(Comm) comm, int *flag),
         ((MP(Comm))comm, flag))
FUNCTION(int, Comm_remote_size, (MT(Comm) comm, int *size),
         ((MP(Comm))comm, size))
FUNCTION(int, Comm_remote_group, (MT(Comm) comm, MT(Group) * group),
         ((MP(Comm))comm, (MP(Group) *)group))
FUNCTION(int, Intercomm_create,
         (MT(Comm) local_comm, int local_leader, MT(Comm) peer_comm,
          int remote_leader, int tag, MT(Comm) * newintercomm),
         ((MP(Comm))local_comm, local_leader, (MP(Comm))peer_comm,
          remote_leader, tag, (MP(Comm) *)newintercomm))
FUNCTION(int, Intercomm_merge,
         (MT(Comm) intercomm, int high, MT(Comm) * newintracomm),
         ((MP(Comm))intercomm, high, (MP(Comm) *)newintracomm))

// note: i checked the standard; we are complete from the top to here

// 6.7 Communicators
FUNCTION(int, Comm_create_keyval,
         (MT(Comm_copy_attr_function) * comm_copy_attr_fn,
          MT(Comm_delete_attr_function) * comm_delete_attr_fn, int *comm_keyval,
          void *extra_state),
         ((MP(Comm_copy_attr_function) *)comm_copy_attr_fn,
          (MP(Comm_delete_attr_function) *)comm_delete_attr_fn, comm_keyval,
          extra_state))
FUNCTION(int, Comm_free_keyval, (int *comm_keyval), (comm_keyval))
FUNCTION(int, Comm_set_attr,
         (MT(Comm) comm, int comm_keyval, void *attribute_val),
         ((MP(Comm))comm, comm_keyval, attribute_val))
FUNCTION(int, Comm_get_attr,
         (MT(Comm) comm, int comm_keyval, void *attribute_val, int *flag),
         ((MP(Comm))comm, comm_keyval, attribute_val, flag))
FUNCTION(int, Comm_delete_attr, (MT(Comm) comm, int comm_keyval),
         ((MP(Comm))comm, comm_keyval))
FUNCTION(int, Win_create_keyval,
         (MT(Win_copy_attr_function) * win_copy_attr_fn,
          MT(Win_delete_attr_function) * win_delete_attr_fn, int *win_keyval,
          void *extra_state),
         ((MP(Win_copy_attr_function) *)win_copy_attr_fn,
          (MP(Win_delete_attr_function) *)win_delete_attr_fn, win_keyval,
          extra_state))
FUNCTION(int, Win_free_keyval, (int *win_keyval), (win_keyval))
FUNCTION(int, Win_set_attr, (MT(Win) win, int win_keyval, void *attribute_val),
         ((MP(Win))win, win_keyval, attribute_val))
FUNCTION(int, Win_get_attr,
         (MT(Win) win, int win_keyval, void *attribute_val, int *flag),
         ((MP(Win))win, win_keyval, attribute_val, flag))
FUNCTION(int, Win_delete_attr, (MT(Win) win, int win_keyval),
         ((MP(Win))win, win_keyval))
FUNCTION(int, Type_create_keyval,
         (MT(Type_copy_attr_function) * type_copy_attr_fn,
          MT(Type_delete_attr_function) * type_delete_attr_fn, int *type_keyval,
          void *extra_state),
         ((MP(Type_copy_attr_function) *)type_copy_attr_fn,
          (MP(Type_delete_attr_function) *)type_delete_attr_fn, type_keyval,
          extra_state))
FUNCTION(int, Type_free_keyval, (int *type_keyval), (type_keyval))
FUNCTION(int, Type_set_attr,
         (MT(Datatype) type, int type_keyval, void *attribute_val),
         ((MP(Datatype))type, type_keyval, attribute_val))
FUNCTION(int, Type_get_attr,
         (MT(Datatype) type, int type_keyval, void *attribute_val, int *flag),
         ((MP(Datatype))type, type_keyval, attribute_val, flag))
FUNCTION(int, Type_delete_attr, (MT(Datatype) type, int type_keyval),
         ((MP(Datatype))type, type_keyval))

// 13.2 File Manipulation
FUNCTION(int, File_open,
         (MT(Comm) comm, const char *filename, int amode, MT(Info) info,
          MT(File) * fh),
         ((MP(Comm))comm, filename, amode, (MP(Info))info, (MP(File) *)fh))
FUNCTION(int, File_close, (MT(File) * fh), ((MP(File) *)fh))
FUNCTION(int, File_delete, (const char *filename, MT(Info) info),
         (filename, (MP(Info))info))
FUNCTION(int, File_set_size, (MT(File) fh, MT(Offset) size),
         ((MP(File))fh, (MP(Offset))size))
FUNCTION(int, File_preallocate, (MT(File) fh, MT(Offset) size),
         ((MP(File))fh, (MP(Offset))size))
FUNCTION(int, File_get_size, (MT(File) fh, MT(Offset) * size),
         ((MP(File))fh, (MP(Offset) *)size))
FUNCTION(int, File_get_group, (MT(File) fh, MT(Group) * group),
         ((MP(File))fh, (MP(Group) *)group))
FUNCTION(int, File_get_amode, (MT(File) fh, int *amode), ((MP(File))fh, amode))
FUNCTION(int, File_set_info, (MT(File) fh, MT(Info) info),
         ((MP(File))fh, (MP(Info))info))
FUNCTION(int, File_get_info, (MT(File) fh, MT(Info) * info_used),
         ((MP(File))fh, (MP(Info) *)info_used))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(int, Comm_set_errhandler, (MT(Comm) comm, MT(Errhandler) errhandler),
         ((MP(Comm))comm, (MP(Errhandler))errhandler))
FUNCTION(int, Error_string, (int errorcode, char *string, int *resultlen),
         (errorcode, string, resultlen))
FUNCTION(int, Info_dup, (MT(Info) info, MT(Info) * newinfo),
         ((MP(Info))info, (MP(Info) *)newinfo))
FUNCTION(int, Info_free, (MT(Info) * info), ((MP(Info) *)info))

FUNCTION(int, Info_get_nkeys, (MT(Info) info, int *nkeys),
         ((MP(Info))info, nkeys))
FUNCTION(int, Info_get_nthkey, (MT(Info) info, int n, char *key),
         ((MP(Info))info, n, key))
FUNCTION(int, Info_get,
         (MT(Info) info, const char *key, int valuelen, char *value, int *flag),
         ((MP(Info))info, key, valuelen, value, flag))

FUNCTION(int, File_set_atomicity, (MT(File) fh, int flag), ((MP(File))fh, flag))
FUNCTION(int, File_get_atomicity, (MT(File) fh, int *flag),
         ((MP(File))fh, flag))
FUNCTION(int, File_sync, (MT(File) fh), ((MP(File))fh))

FUNCTION(int, File_set_view,
         (MT(File) fh, MT(Offset) disp, MT(Datatype) etype,
          MT(Datatype) filetype, const char *datarep, MT(Info) info),
         ((MP(File))fh, (MP(Offset))disp, (MP(Datatype))etype,
          (MP(Datatype))filetype, datarep, (MP(Info))info))
FUNCTION(int, File_get_view,
         (MT(File) fh, MT(Offset) * disp, MT(Datatype) * etype,
          MT(Datatype) * filetype, char *datarep),
         ((MP(File))fh, (MP(Offset) *)disp, (MP(Datatype) *)etype,
          (MP(Datatype) *)filetype, datarep))

FUNCTION(int, File_read_at,
         (MT(File) fh, MT(Offset) offset, void *buf, int count,
          MT(Datatype) datatype, MT(StatusPtr) status),
         ((MP(File))fh, (MP(Offset))offset, buf, count, (MP(Datatype))datatype,
          (MP(StatusPtr))status))
FUNCTION(int, File_read_at_all,
         (MT(File) fh, MT(Offset) offset, void *buf, int count,
          MT(Datatype) datatype, MT(StatusPtr) status),
         ((MP(File))fh, (MP(Offset))offset, buf, count, (MP(Datatype))datatype,
          (MP(StatusPtr))status))
FUNCTION(int, File_write_at,
         (MT(File) fh, MT(Offset) offset, const void *buf, int count,
          MT(Datatype) datatype, MT(StatusPtr) status),
         ((MP(File))fh, (MP(Offset))offset, buf, count, (MP(Datatype))datatype,
          (MP(StatusPtr))status))
FUNCTION(int, File_write_at_all,
         (MT(File) fh, MT(Offset) offset, const void *buf, int count,
          MT(Datatype) datatype, MT(StatusPtr) status),
         ((MP(File))fh, (MP(Offset))offset, buf, count, (MP(Datatype))datatype,
          (MP(StatusPtr))status))

FUNCTION(int, Status_set_elements_x,
         (MT(StatusPtr) status, MT(Datatype) datatype, MT(Count) count),
         ((MP(StatusPtr))status, (MP(Datatype))datatype, (MP(Count))count))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(MT(Fint), Comm_c2f, (MT(Comm) comm), ((MP(Comm))comm))
FUNCTION(MT(Comm), Comm_f2c, (MT(Fint) comm), (comm))
FUNCTION(MT(Fint), File_c2f, (MT(File) file), ((MP(File))file))
FUNCTION(MT(File), File_f2c, (MT(Fint) file), (file))
FUNCTION(MT(Fint), Group_c2f, (MT(Group) group), ((MP(Group))group))
FUNCTION(MT(Group), Group_f2c, (MT(Fint) group), (group))
FUNCTION(MT(Fint), Info_c2f, (MT(Info) info), ((MP(Info))info))
FUNCTION(MT(Info), Info_f2c, (MT(Fint) info), (info))
FUNCTION(MT(Fint), Message_c2f, (MT(Message) message), ((MP(Message))message))
FUNCTION(MT(Message), Message_f2c, (MT(Fint) message), (message))
FUNCTION(MT(Fint), Op_c2f, (MT(Op) op), ((MP(Op))op))
FUNCTION(MT(Op), Op_f2c, (MT(Fint) op), (op))
FUNCTION(MT(Fint), Request_c2f, (MT(Request) request), ((MP(Request))request))
FUNCTION(MT(Request), Request_f2c, (MT(Fint) request), (request))
FUNCTION(MT(Fint), Type_c2f, (MT(Datatype) datatype), ((MP(Datatype))datatype))
FUNCTION(MT(Datatype), Type_f2c, (MT(Fint) datatype), (datatype))
FUNCTION(MT(Fint), Win_c2f, (MT(Win) win), ((MP(Win))win))
FUNCTION(MT(Win), Win_f2c, (MT(Fint) win), (win))
FUNCTION(int, Status_c2f, (MT(const_StatusPtr) c_status, MT(Fint) * f_status),
         ((MP(const_StatusPtr))c_status, f_status))
FUNCTION(int, Status_f2c, (const MT(Fint) * f_status, MT(StatusPtr) c_status),
         (f_status, (MP(StatusPtr))c_status))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(double, Wtick, (), ())
FUNCTION(double, Wtime, (), ())

FUNCTION(int, Abort, (MT(Comm) comm, int errorcode),
         ((MP(Comm))comm, errorcode))
FUNCTION(int, Finalize, (), ())
FUNCTION(int, Finalized, (int *flag), (flag))
FUNCTION(int, Init, (int *argc, char ***argv), (argc, argv))
FUNCTION(int, Init_thread,
         (int *argc, char ***argv, int required, int *provided),
         (argc, argv, required, provided))
FUNCTION(int, Initialized, (int *flag), (flag))

FUNCTION(int, Get_processor_name, (char *name, int *resultlen),
         (name, resultlen))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Get_version, (int *version, int *subversion),
         (version, subversion))
#endif
FUNCTION(int, Get_library_version, (char *version, int *resultlen),
         (version, resultlen))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(int, Close_port, (const char *port_name), (port_name))
FUNCTION(int, Comm_accept,
         (const char *port_name, MT(Info) info, int root, MT(Comm) comm,
          MT(Comm) * newcomm),
         (port_name, (MP(Info))info, root, (MP(Comm))comm, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_connect,
         (const char *port_name, MT(Info) info, int root, MT(Comm) comm,
          MT(Comm) * newcomm),
         (port_name, (MP(Info))info, root, (MP(Comm))comm, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_disconnect, (MT(Comm) * comm), ((MP(Comm) *)comm))
FUNCTION(int, Comm_get_parent, (MT(Comm) * parent), ((MP(Comm) *)parent))
FUNCTION(int, Comm_join, (int fd, MT(Comm) * intercomm),
         (fd, (MP(Comm) *)intercomm))
FUNCTION(int, Comm_spawn,
         (const char *command, char *argv[], int maxprocs, MT(Info) info,
          int root, MT(Comm) comm, MT(Comm) * intercomm,
          int array_of_errcodes[]),
         (command, argv, maxprocs, (MP(Info))info, root, (MP(Comm))comm,
          (MP(Comm) *)intercomm, array_of_errcodes))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Comm_spawn_multiple,
         (int count, char *array_of_commands[], char **array_of_argv[],
          const int array_of_maxprocs[], const MT(Info) array_of_info[],
          int root, MT(Comm) comm, MT(Comm) * intercomm,
          int array_of_errcodes[]),
         (count, array_of_commands, array_of_argv, array_of_maxprocs,
          (const MP(Info) *)array_of_info, root, (MP(Comm))comm,
          (MP(Comm) *)intercomm, array_of_errcodes))
#endif
FUNCTION(int, Lookup_name,
         (const char *service_name, MT(Info) info, char *port_name),
         (service_name, (MP(Info))info, port_name))
FUNCTION(int, Open_port, (MT(Info) info, char *port_name),
         ((MP(Info))info, port_name))
FUNCTION(int, Publish_name,
         (const char *service_name, MT(Info) info, const char *port_name),
         (service_name, (MP(Info))info, port_name))
FUNCTION(int, Unpublish_name,
         (const char *service_name, MT(Info) info, const char *port_name),
         (service_name, (MP(Info))info, port_name))

FUNCTION(int, Is_thread_main, (int *flag), (flag))
FUNCTION(int, Query_thread, (int *provided), (provided))

/* One-Sided Communications */
FUNCTION(int, Accumulate,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Op) op,
          MT(Win) win),
         (origin_addr, origin_count, (MP(Datatype))origin_datatype, target_rank,
          (MP(Aint))target_disp, target_count, (MP(Datatype))target_datatype,
          (MP(Op))op, (MP(Win))win))
FUNCTION(int, Get,
         (void *origin_addr, int origin_count, MT(Datatype) origin_datatype,
          int target_rank, MT(Aint) target_disp, int target_count,
          MT(Datatype) target_datatype, MT(Win) win),
         (origin_addr, origin_count, (MP(Datatype))origin_datatype, target_rank,
          (MP(Aint))target_disp, target_count, (MP(Datatype))target_datatype,
          (MP(Win))win))
FUNCTION(int, Put,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Win) win),
         (origin_addr, origin_count, (MP(Datatype))origin_datatype, target_rank,
          (MP(Aint))target_disp, target_count, (MP(Datatype))target_datatype,
          (MP(Win))win))
FUNCTION(int, Win_complete, (MT(Win) win), ((MP(Win))win))
FUNCTION(int, Win_create,
         (void *base, MT(Aint) size, int disp_unit, MT(Info) info,
          MT(Comm) comm, MT(Win) * win),
         (base, (MP(Aint))size, disp_unit, (MP(Info))info, (MP(Comm))comm,
          (MP(Win) *)win))
FUNCTION(int, Win_fence, (int assert, MT(Win) win), (assert, (MP(Win))win))
FUNCTION(int, Win_free, (MT(Win) * win), ((MP(Win) *)win))
FUNCTION(int, Win_get_group, (MT(Win) win, MT(Group) * group),
         ((MP(Win))win, (MP(Group) *)group))
FUNCTION(int, Win_lock, (int lock_type, int rank, int assert, MT(Win) win),
         (lock_type, rank, assert, (MP(Win))win))
FUNCTION(int, Win_post, (MT(Group) group, int assert, MT(Win) win),
         ((MP(Group))group, assert, (MP(Win))win))
FUNCTION(int, Win_start, (MT(Group) group, int assert, MT(Win) win),
         ((MP(Group))group, assert, (MP(Win))win))
FUNCTION(int, Win_test, (MT(Win) win, int *flag), ((MP(Win))win, flag))
FUNCTION(int, Win_unlock, (int rank, MT(Win) win), (rank, (MP(Win))win))
FUNCTION(int, Win_wait, (MT(Win) win), ((MP(Win))win))

/* Fortran 90-related functions.  These routines are available only if
   Fortran 90 support is enabled
*/
FUNCTION(int, Type_create_f90_integer, (int range, MT(Datatype) * newtype),
         (range, (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_f90_real,
         (int precision, int range, MT(Datatype) * newtype),
         (precision, range, (MP(Datatype) *)newtype))
FUNCTION(int, Type_create_f90_complex,
         (int precision, int range, MT(Datatype) * newtype),
         (precision, range, (MP(Datatype) *)newtype))

#if 0
/* MPI-3 One-Sided Communication Routines */
int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm,
                     void *baseptr, MPI_Win *win) MPICH_API_PUBLIC;
int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info,
                            MPI_Comm comm, void *baseptr,
                            MPI_Win *win) MPICH_API_PUBLIC;
int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size, int *disp_unit,
                         void *baseptr) MPICH_API_PUBLIC;
int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm,
                           MPI_Win *win) MPICH_API_PUBLIC;
int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) MPICH_API_PUBLIC;
int MPI_Win_detach(MPI_Win win, const void *base) MPICH_API_PUBLIC;
int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) MPICH_API_PUBLIC;
int MPI_Win_set_info(MPI_Win win, MPI_Info info) MPICH_API_PUBLIC;
int MPI_Get_accumulate(const void *origin_addr, int origin_count,
                       MPI_Datatype origin_datatype, void *result_addr,
                       int result_count, MPI_Datatype result_datatype,
                       int target_rank, MPI_Aint target_disp, int target_count,
                       MPI_Datatype target_datatype, MPI_Op op, MPI_Win win)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 3)
        MPICH_ATTR_POINTER_WITH_TYPE_TAG(4, 6) MPICH_API_PUBLIC;
int MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                     MPI_Datatype datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Op op, MPI_Win win)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 3) MPICH_API_PUBLIC;
int MPI_Compare_and_swap(const void *origin_addr, const void *compare_addr,
                         void *result_addr, MPI_Datatype datatype,
                         int target_rank, MPI_Aint target_disp, MPI_Win win)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 4)
        MPICH_ATTR_POINTER_WITH_TYPE_TAG(2, 4)
            MPICH_ATTR_POINTER_WITH_TYPE_TAG(3, 4) MPICH_API_PUBLIC;
int MPI_Rput(const void *origin_addr, int origin_count,
             MPI_Datatype origin_datatype, int target_rank,
             MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 3) MPICH_API_PUBLIC;
int MPI_Rget(void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
             int target_rank, MPI_Aint target_disp, int target_count,
             MPI_Datatype target_datatype, MPI_Win win, MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 3) MPICH_API_PUBLIC;
int MPI_Raccumulate(const void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                    MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 3) MPICH_API_PUBLIC;
int MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                        MPI_Datatype origin_datatype, void *result_addr,
                        int result_count, MPI_Datatype result_datatype,
                        int target_rank, MPI_Aint target_disp, int target_count,
                        MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                        MPI_Request *request)
    MPICH_ATTR_POINTER_WITH_TYPE_TAG(1, 3)
        MPICH_ATTR_POINTER_WITH_TYPE_TAG(4, 6) MPICH_API_PUBLIC;
int MPI_Win_lock_all(int assert, MPI_Win win) MPICH_API_PUBLIC;
int MPI_Win_unlock_all(MPI_Win win) MPICH_API_PUBLIC;
int MPI_Win_flush(int rank, MPI_Win win) MPICH_API_PUBLIC;
int MPI_Win_flush_all(MPI_Win win) MPICH_API_PUBLIC;
int MPI_Win_flush_local(int rank, MPI_Win win) MPICH_API_PUBLIC;
int MPI_Win_flush_local_all(MPI_Win win) MPICH_API_PUBLIC;
int MPI_Win_sync(MPI_Win win) MPICH_API_PUBLIC;
#endif

////////////////////////////////////////////////////////////////////////////////

FUNCTION(int, Info_create, (MT(Info) * info), ((MP(Info) *)info))
