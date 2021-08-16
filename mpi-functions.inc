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
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Ibsend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Issend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Irsend,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Irecv,
         (void *buf, int count, MT(Datatype) datatype, int source, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, source, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Wait, (MT(RequestPtr) request, MT(StatusPtr) status),
         ((MP(RequestPtr))request, (MP(StatusPtr))status))
FUNCTION(int, Test, (MT(RequestPtr) request, int *flag, MT(StatusPtr) status),
         ((MP(RequestPtr))request, flag, (MP(StatusPtr))status))
FUNCTION(int, Request_free, (MT(RequestPtr) request), ((MP(RequestPtr))request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Waitany,
         (int count, MT(Request) array_of_requests[], int *indx,
          MT(StatusPtr) status),
         (count, (MP(RequestPtr))array_of_requests, indx,
          (MP(StatusPtr))status))
FUNCTION(int, Testany,
         (int count, MT(Request) array_of_requests[], int *indx, int *flag,
          MT(StatusPtr) status),
         (count, (MP(RequestPtr))array_of_requests, indx, flag,
          (MP(StatusPtr))status))
FUNCTION(int, Waitall,
         (int count, MT(Request) array_of_requests[], MT(StatusPtr) status),
         (count, (MP(RequestPtr))array_of_requests, (MP(StatusPtr))status))
FUNCTION(int, Testall,
         (int count, MT(Request) array_of_requests[], int *flag,
          MT(StatusPtr) status),
         (count, (MP(RequestPtr))array_of_requests, flag,
          (MP(StatusPtr))status))
FUNCTION(int, Waitsome,
         (int incount, MT(Request) array_of_requests[], int *outcount,
          int array_of_indices[], MT(Status) array_of_statuses[]),
         (incount, (MP(RequestPtr))array_of_requests, outcount,
          array_of_indices, (MP(StatusPtr))array_of_statuses))
FUNCTION(int, Testsome,
         (int incount, MT(Request) array_of_requests[], int *outcount,
          int array_of_indices[], MT(Status) array_of_statuses[]),
         (incount, (MP(RequestPtr))array_of_requests, outcount,
          array_of_indices, (MP(StatusPtr))array_of_statuses))
#endif

// 3.8 Probe and Cancel
FUNCTION(int, Iprobe,
         (int source, int tag, MT(Comm) comm, int *flag, MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, flag, (MP(StatusPtr))status))
FUNCTION(int, Probe, (int source, int tag, MT(Comm) comm, MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, (MP(StatusPtr))status))
FUNCTION(int, Improbe,
         (int source, int tag, MT(Comm) comm, int *flag, MT(MessagePtr) message,
          MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, flag, (MP(MessagePtr))message,
          (MP(StatusPtr))status))
FUNCTION(int, Mprobe,
         (int source, int tag, MT(Comm) comm, MT(MessagePtr) message,
          MT(StatusPtr) status),
         (source, tag, (MP(Comm))comm, (MP(MessagePtr))message,
          (MP(StatusPtr))status))
FUNCTION(int, Mrecv,
         (void *buf, int count, MT(Datatype) datatype, MT(MessagePtr) message,
          MT(StatusPtr) status),
         (buf, count, (MP(Datatype))datatype, (MP(MessagePtr))message,
          (MP(StatusPtr))status))
FUNCTION(int, Imrecv,
         (void *buf, int count, MT(Datatype) datatype, MT(MessagePtr) message,
          MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, (MP(MessagePtr))message,
          (MP(RequestPtr))request))
FUNCTION(int, Cancel, (MT(RequestPtr) request), ((MP(RequestPtr))request))
FUNCTION(int, Test_cancelled, (MT(const_StatusPtr) status, int *flag),
         ((MP(const_StatusPtr))status, flag))

// 3.9 Persistent Communication Requests
FUNCTION(int, Send_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Bsend_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Ssend_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Rsend_init,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Recv_init,
         (void *buf, int count, MT(Datatype) datatype, int source, int tag,
          MT(Comm) comm, MT(RequestPtr) request),
         (buf, count, (MP(Datatype))datatype, source, tag, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Start, (MT(RequestPtr) request), ((MP(RequestPtr))request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Startall, (int count, MT(Request) array_of_requests[]),
         (count, (MP(RequestPtr))array_of_requests))
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
         (int count, MT(Datatype) oldtype, MT(DatatypePtr) newtype),
         (count, (MP(Datatype))oldtype, (MP(DatatypePtr))newtype))
FUNCTION(int, Type_vector,
         (int count, int blocklength, int stride, MT(Datatype) oldtype,
          MT(DatatypePtr) newtype),
         (count, blocklength, stride, (MP(Datatype))oldtype,
          (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_hvector,
         (int count, int blocklength, MT(Aint) stride, MT(Datatype) oldtype,
          MT(DatatypePtr) newtype),
         (count, blocklength, (MP(Aint))stride, (MP(Datatype))oldtype,
          (MP(DatatypePtr))newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_hvector,
//          (int count, int blocklength, MT(Aint) stride, MT(Datatype) oldtype,
//           MT(DatatypePtr) newtype),
//          (count, blocklength, (MP(Aint))stride, (MP(Datatype))oldtype,
//           (MP(DatatypePtr))newtype))
FUNCTION(int, Type_indexed,
         (int count, const int *array_of_blocklengths,
          const int *array_of_displacements, MT(Datatype) oldtype,
          MT(DatatypePtr) newtype),
         (count, array_of_blocklengths, array_of_displacements,
          (MP(Datatype))oldtype, (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_hindexed,
         (int count, const int array_of_blocklengths[],
          const MT(Aint) array_of_displacements[], MT(Datatype) oldtype,
          MT(DatatypePtr) newtype),
         (count, array_of_blocklengths,
          (const MP(Aint) *)array_of_displacements, (MP(Datatype))oldtype,
          (MP(DatatypePtr))newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_hindexed,
//          (int count, int *array_of_blocklengths,
//           MT(Aint)* array_of_displacements, MT(Datatype) oldtype,
//           MT(DatatypePtr) newtype),
//          (count, array_of_blocklengths, (MP(Aint)*)array_of_displacements,
//           (MP(Datatype))oldtype, (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_indexed_block,
         (int count, int blocklength, const int array_of_displacements[],
          MT(Datatype) oldtype, MT(DatatypePtr) newtype),
         (count, blocklength, array_of_displacements, (MP(Datatype))oldtype,
          (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_hindexed_block,
         (int count, int blocklength, const MT(Aint) array_of_displacements[],
          MT(Datatype) oldtype, MT(DatatypePtr) newtype),
         (count, blocklength, (const MP(Aint) *)array_of_displacements,
          (MP(Datatype))oldtype, (MP(DatatypePtr))newtype))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Type_create_struct,
         (int count, const int array_of_blocklengths[],
          const MT(Aint) array_of_displacements[],
          const MT(Datatype) array_of_types[], MT(DatatypePtr) newtype),
         (count, array_of_blocklengths,
          (const MP(Aint) *)array_of_displacements,
          (const MP(DatatypePtr))array_of_types, (MP(DatatypePtr))newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_struct,
//          (int count, int *array_of_blocklengths,
//           MT(Aint)* array_of_displacements, MT(DatatypePtr) array_of_types,
//           MT(DatatypePtr) newtype),
//          (count, array_of_blocklengths, (MP(Aint)*)array_of_displacements,
//           (MP(DatatypePtr))array_of_types, (MP(DatatypePtr))newtype))
#endif
FUNCTION(int, Type_create_subarray,
         (int ndims, const int array_of_sizes[], const int array_of_subsizes[],
          const int array_of_starts[], int ordder, MT(Datatype) oldtype,
          MT(DatatypePtr) newtype),
         (ndims, array_of_sizes, array_of_subsizes, array_of_starts, ordder,
          (MP(Datatype))oldtype, (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_darray,
         (int size, int rank, int ndims, const int array_of_gsizes[],
          const int array_of_distribs[], const int array_of_dargs[],
          const int array_of_psizes[], int order, MT(Datatype) oldtype,
          MT(DatatypePtr) newtype),
         (size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
          array_of_psizes, order, (MP(Datatype))oldtype,
          (MP(DatatypePtr))newtype))
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
          MT(DatatypePtr) newtype),
         ((MP(Datatype))oldtype, (MP(Aint))lb, (MP(Aint))extent,
          (MP(DatatypePtr))newtype))
FUNCTION(int, Type_get_true_extent,
         (MT(Datatype) datatype, MT(Aint) * true_lb, MT(Aint) * true_extent),
         ((MP(Datatype))datatype, (MP(Aint) *)true_lb, (MP(Aint) *)true_extent))
FUNCTION(int, Type_get_true_extent_x,
         (MT(Datatype) datatype, MT(Count) * true_lb, MT(Count) * true_extent),
         ((MP(Datatype))datatype, (MP(Count) *)true_lb,
          (MP(Count) *)true_extent))
FUNCTION(int, Type_commit, (MT(DatatypePtr) datatype),
         ((MP(DatatypePtr))datatype))
FUNCTION(int, Type_free, (MT(DatatypePtr) datatype),
         ((MP(DatatypePtr))datatype))
FUNCTION(int, Type_dup, (MT(Datatype) oldtype, MT(DatatypePtr) newtype),
         ((MP(Datatype))oldtype, (MP(DatatypePtr))newtype))
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
          (MP(DatatypePtr))array_of_datatypes))
#endif
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Address, (void *location, MT(Aint)* address),
//          (location, (MP(Aint)*)address))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_extent, (MT(Datatype) datatype, MT(Aint)* extent),
//          ((MP(Datatype))datatype, (MP(Aint)*)extent))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_lb, (MT(Datatype) datatype, MT(Aint)* displacement),
//          ((MP(Datatype))datatype, (MP(Aint)*)displacement))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_ub, (MT(Datatype) datatype, MT(Aint)* displacement),
//          ((MP(Datatype))datatype, (MP(Aint)*)displacement))

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
         (sendbuf, sendcounts, sdispls, (MP(DatatypePtr))sendtypes, recvbuf,
          recvcounts, rdispls, (const MP(DatatypePtr))recvtypes,
          (MP(Comm))comm))
#endif

// 5.9 Global Reduction Operations
FUNCTION(int, Reduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, int root, MT(Comm) comm),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op, root,
          (MP(Comm))comm))
FUNCTION(int, Op_create,
         (MT(User_function) * user_fn, int commute, MT(OpPtr) op),
         ((MP(User_function) *)user_fn, commute, (MP(OpPtr))op))
FUNCTION(int, Op_free, (MT(OpPtr) op), ((MP(OpPtr))op))
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
FUNCTION(int, Ibarrier, (MT(Comm) comm, MT(RequestPtr) request),
         ((MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Ibcast,
         (void *buffer, int count, MT(Datatype) datatype, int root,
          MT(Comm) comm, MT(RequestPtr) request),
         (buffer, count, (MP(Datatype))datatype, root, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Igather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, int root,
          MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, root, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Igatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int *recvcounts, const int *displs,
          MT(Datatype) recvtype, int root, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, root, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Iscatter,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, int root,
          MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, root, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Iscatterv,
         (const void *sendbuf, const int *sendcounts, const int *displs,
          MT(Datatype) sendtype, void *recvbuf, int recvcount,
          MT(Datatype) recvtype, int root, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcounts, displs, (MP(Datatype))sendtype, recvbuf,
          recvcount, (MP(Datatype))recvtype, root, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Iallgather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Iallgatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int *recvcounts, const int *displs,
          MT(Datatype) recvtype, MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Ialltoall,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Ialltoallv,
         (const void *sendbuf, const int *sendcounts, const int *sdispls,
          MT(Datatype) sendtype, void *recvbuf, const int *recvcounts,
          const int *rdispls, MT(Datatype) recvtype, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcounts, sdispls, (MP(Datatype))sendtype, recvbuf,
          recvcounts, rdispls, (MP(Datatype))recvtype, (MP(Comm))comm,
          (MP(RequestPtr))request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Ialltoallw,
         (const void *sendbuf, const int sendcounts[], const int sdispls[],
          const MT(Datatype) sendtypes[], void *recvbuf, const int recvcounts[],
          const int rdispls[], const MT(Datatype) recvtypes[], MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcounts, sdispls, (MP(DatatypePtr))sendtypes, recvbuf,
          recvcounts, rdispls, (const MP(DatatypePtr))recvtypes, (MP(Comm))comm,
          (MP(RequestPtr))request))
#endif
FUNCTION(int, Ireduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, int root, MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op, root,
          (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Iallreduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Ireduce_scatter_block,
         (const void *sendbuf, void *recvbuf, int recvcount,
          MT(Datatype) datatype, MT(Op) op, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, recvbuf, recvcount, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Ireduce_scatter,
         (const void *sendbuf, void *recvbuf, const int recvcounts[],
          MT(Datatype) datatype, MT(Op) op, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, recvbuf, recvcounts, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Iscan,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Iexscan,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm, (MP(RequestPtr))request))

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
FUNCTION(int, Comm_group, (MT(Comm) comm, MT(GroupPtr) group),
         ((MP(Comm))comm, (MP(GroupPtr))group))
FUNCTION(int, Group_union,
         (MT(Group) group1, MT(Group) group2, MT(GroupPtr) newgroup),
         ((MP(Group))group1, (MP(Group))group2, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_intersection,
         (MT(Group) group1, MT(Group) group2, MT(GroupPtr) newgroup),
         ((MP(Group))group1, (MP(Group))group2, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_difference,
         (MT(Group) group1, MT(Group) group2, MT(GroupPtr) newgroup),
         ((MP(Group))group1, (MP(Group))group2, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_incl,
         (MT(Group) group, int n, const int ranks[], MT(GroupPtr) newgroup),
         ((MP(Group))group, n, ranks, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_excl,
         (MT(Group) group, int n, const int ranks[], MT(GroupPtr) newgroup),
         ((MP(Group))group, n, ranks, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_range_incl,
         (MT(Group) group, int n, int ranges[][3], MT(GroupPtr) newgroup),
         ((MP(Group))group, n, ranges, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_range_excl,
         (MT(Group) group, int n, int ranges[][3], MT(GroupPtr) newgroup),
         ((MP(Group))group, n, ranges, (MP(GroupPtr))newgroup))
FUNCTION(int, Group_free, (MT(GroupPtr) group), ((MP(GroupPtr))group))

// 6.4 Communicator Management
FUNCTION(int, Comm_size, (MT(Comm) comm, int *size), ((MP(Comm))comm, size))
FUNCTION(int, Comm_rank, (MT(Comm) comm, int *rank), ((MP(Comm))comm, rank))
FUNCTION(int, Comm_compare, (MT(Comm) comm1, MT(Comm) comm2, int *result),
         ((MP(Comm))comm1, (MP(Comm))comm2, result))
FUNCTION(int, Comm_dup, (MT(Comm) comm, MT(CommPtr) newcomm),
         ((MP(Comm))comm, (MP(CommPtr))newcomm))
FUNCTION(int, Comm_dup_with_info,
         (MT(Comm) comm, MT(Info) info, MT(CommPtr) newcomm),
         ((MP(Comm))comm, (MP(Info))info, (MP(CommPtr))newcomm))
FUNCTION(int, Comm_idup,
         (MT(Comm) comm, MT(CommPtr) newcomm, MT(RequestPtr) request),
         ((MP(Comm))comm, (MP(CommPtr))newcomm, (MP(RequestPtr))request))
FUNCTION(int, Comm_create,
         (MT(Comm) comm, MT(Group) group, MT(CommPtr) newcomm),
         ((MP(Comm))comm, (MP(Group))group, (MP(CommPtr))newcomm))
FUNCTION(int, Comm_create_group,
         (MT(Comm) comm, MT(Group) group, int tag, MT(CommPtr) newcomm),
         ((MP(Comm))comm, (MP(Group))group, tag, (MP(CommPtr))newcomm))
FUNCTION(int, Comm_split,
         (MT(Comm) comm, int color, int key, MT(CommPtr) newcomm),
         ((MP(Comm))comm, color, key, (MP(CommPtr))newcomm))
FUNCTION(int, Comm_split_type,
         (MT(Comm) comm, int split_type, int key, MT(Info) info,
          MT(CommPtr) newcomm),
         ((MP(Comm))comm, split_type, key, (MP(Info))info,
          (MP(CommPtr))newcomm))
FUNCTION(int, Comm_free, (MT(CommPtr) comm), ((MP(CommPtr))comm))
FUNCTION(int, Comm_set_info, (MT(Comm) comm, MT(Info) info),
         ((MP(Comm))comm, (MP(Info))info))
FUNCTION(int, Comm_get_info, (MT(Comm) comm, MT(InfoPtr) info),
         ((MP(Comm))comm, (MP(InfoPtr))info))

// 6.6 Inter-Communication
FUNCTION(int, Comm_test_inter, (MT(Comm) comm, int *flag),
         ((MP(Comm))comm, flag))
FUNCTION(int, Comm_remote_size, (MT(Comm) comm, int *size),
         ((MP(Comm))comm, size))
FUNCTION(int, Comm_remote_group, (MT(Comm) comm, MT(GroupPtr) group),
         ((MP(Comm))comm, (MP(GroupPtr))group))
FUNCTION(int, Intercomm_create,
         (MT(Comm) local_comm, int local_leader, MT(Comm) peer_comm,
          int remote_leader, int tag, MT(CommPtr) newintercomm),
         ((MP(Comm))local_comm, local_leader, (MP(Comm))peer_comm,
          remote_leader, tag, (MP(CommPtr))newintercomm))
FUNCTION(int, Intercomm_merge,
         (MT(Comm) intercomm, int high, MT(CommPtr) newintracomm),
         ((MP(Comm))intercomm, high, (MP(CommPtr))newintracomm))

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

// 6.8 Naming Objects
FUNCTION(int, Comm_set_name, (MT(Comm) comm, const char *comm_name),
         ((MP(Comm))comm, comm_name))
FUNCTION(int, Comm_get_name, (MT(Comm) comm, char *comm_name, int *resultlen),
         ((MP(Comm))comm, comm_name, resultlen))
FUNCTION(int, Type_set_name, (MT(Datatype) type, const char *type_name),
         ((MP(Datatype))type, type_name))
FUNCTION(int, Type_get_name,
         (MT(Datatype) type, char *type_name, int *resultlen),
         ((MP(Datatype))type, type_name, resultlen))
FUNCTION(int, Win_set_name, (MT(Win) win, const char *win_name),
         ((MP(Win))win, win_name))
FUNCTION(int, Win_get_name, (MT(Win) win, char *win_name, int *resultlen),
         ((MP(Win))win, win_name, resultlen))

// 7.5 Topology Constructors
FUNCTION(int, Cart_create,
         (MT(Comm) comm_old, int ndims, const int dims[], const int periods[],
          int reorder, MT(CommPtr) comm_cart),
         ((MP(Comm))comm_old, ndims, dims, periods, reorder,
          (MP(CommPtr))comm_cart))
FUNCTION(int, Dims_create, (int nnodes, int ndims, int dims[]),
         (nnodes, ndims, dims))
FUNCTION(int, Graph_create,
         (MT(Comm) comm_old, int nnodes, const int index[], const int edges[],
          int reorder, MT(CommPtr) comm_graph),
         ((MP(Comm))comm_old, nnodes, index, edges, reorder,
          (MP(CommPtr))comm_graph))
FUNCTION(int, Dist_graph_create_adjacent,
         (MT(Comm) comm_old, int indegree, const int sources[],
          const int sourceweights[], int outdegree, const int destinations[],
          const int destweights[], MT(Info) info, int reorder,
          MT(CommPtr) comm_dist_graph),
         ((MP(Comm))comm_old, indegree, sources, sourceweights, outdegree,
          destinations, destweights, (MP(Info))info, reorder,
          (MP(CommPtr))comm_dist_graph))
FUNCTION(int, Dist_graph_create,
         (MT(Comm) comm_old, int n, const int sources[], const int degrees[],
          const int destinations[], const int weights[], MT(Info) info,
          int reorder, MT(CommPtr) comm_dist_graph),
         ((MP(Comm))comm_old, n, sources, degrees, destinations, weights,
          (MP(Info))info, reorder, (MP(CommPtr))comm_dist_graph))
FUNCTION(int, Topo_test, (MT(Comm) comm, int *status), ((MP(Comm))comm, status))
FUNCTION(int, Graphdims_get, (MT(Comm) comm, int *nnodes, int *nedges),
         ((MP(Comm))comm, nnodes, nedges))
FUNCTION(int, Graph_get,
         (MT(Comm) comm, int maxindex, int maxedges, int index[], int edges[]),
         ((MP(Comm))comm, maxindex, maxedges, index, edges))
FUNCTION(int, Cartdim_get, (MT(Comm) comm, int *ndims), ((MP(Comm))comm, ndims))
FUNCTION(int, Cart_get,
         (MT(Comm) comm, int maxdims, int dims[], int periods[], int coords[]),
         ((MP(Comm))comm, maxdims, dims, periods, coords))
FUNCTION(int, Cart_rank, (MT(Comm) comm, const int coords[], int *rank),
         ((MP(Comm))comm, coords, rank))
FUNCTION(int, Cart_coords, (MT(Comm) comm, int rank, int maxdims, int coords[]),
         ((MP(Comm))comm, rank, maxdims, coords))
FUNCTION(int, Graph_neighbors_count, (MT(Comm) comm, int rank, int *nneighbors),
         ((MP(Comm))comm, rank, nneighbors))
FUNCTION(int, Graph_neighbors,
         (MT(Comm) comm, int rank, int maxneighbors, int neighbors[]),
         ((MP(Comm))comm, rank, maxneighbors, neighbors))
FUNCTION(int, Dist_graph_neighbors_count,
         (MT(Comm) comm, int *indegree, int *outdegree, int *weighted),
         ((MP(Comm))comm, indegree, outdegree, weighted))
FUNCTION(int, Dist_graph_neighbors,
         (MT(Comm) comm, int maxindeegree, int sources[], int wourceweights[],
          int maxoutdegree, int destinations[], int destweights[]),
         ((MP(Comm))comm, maxindeegree, sources, wourceweights, maxoutdegree,
          destinations, destweights))
FUNCTION(int, Cart_shift,
         (MT(Comm) comm, int direction, int disp, int *rank_source,
          int *rank_dest),
         ((MP(Comm))comm, direction, disp, rank_source, rank_dest))
FUNCTION(int, Cart_sub,
         (MT(Comm) comm, const int remain_dims[], MT(CommPtr) newcomm),
         ((MP(Comm))comm, remain_dims, (MP(CommPtr))newcomm))
FUNCTION(int, Cart_map,
         (MT(Comm) comm, int ndims, const int dims[], const int periods[],
          int *newrank),
         ((MP(Comm))comm, ndims, dims, periods, newrank))
FUNCTION(int, Graph_map,
         (MT(Comm) comm, int nnodes, const int index[], const int edges[],
          int *newrank),
         ((MP(Comm))comm, nnodes, index, edges, newrank))

// 7.6 Neighborhood Collective Communication on Procerss Topologies
FUNCTION(int, Neighbor_allgather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm))
FUNCTION(int, Neighbor_allgatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int recvcounts[], const int displs[],
          MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, (MP(Comm))comm))
FUNCTION(int, Neighbor_alltoall,
         (const void *sendbuf, int sendcount, MT(Datatype) senddtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcount, (MP(Datatype))senddtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm))
FUNCTION(int, Neighbor_alltoallv,
         (const void *sendbuf, const int sendcounts[], const int sdispls[],
          MT(Datatype) senddtype, void *recvbuf, const int recvcounts[],
          const int rdispls[], MT(Datatype) recvtype, MT(Comm) comm),
         (sendbuf, sendcounts, sdispls, (MP(Datatype))senddtype, recvbuf,
          recvcounts, rdispls, (MP(Datatype))recvtype, (MP(Comm))comm))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Neighbor_alltoallw,
         (const void *sendbuf, const int sendcounts[], const MT(Aint) sdispls[],
          const MT(Datatype) sendtypes[], void *recvbuf, const int recvcounts[],
          const MT(Aint) rdispls[], const MT(Datatype) recvtypes[],
          MT(Comm) comm),
         (sendbuf, sendcounts, (const MP(Aint) *)sdispls,
          (const MP(DatatypePtr))sendtypes, recvbuf, recvcounts,
          (const MP(Aint) *)rdispls, (const MP(DatatypePtr))recvtypes,
          (MP(Comm))comm))
#endif

// 7.7 Nonblocking Neighborhood Communication on Process Topologies
FUNCTION(int, Ineighbor_allgather,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Ineighbor_allgatherv,
         (const void *sendbuf, int sendcount, MT(Datatype) sendtype,
          void *recvbuf, const int recvcounts[], const int displs[],
          MT(Datatype) recvtype, MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))sendtype, recvbuf, recvcounts,
          displs, (MP(Datatype))recvtype, (MP(Comm))comm,
          (MP(RequestPtr))request))
FUNCTION(int, Ineighbor_alltoall,
         (const void *sendbuf, int sendcount, MT(Datatype) senddtype,
          void *recvbuf, int recvcount, MT(Datatype) recvtype, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcount, (MP(Datatype))senddtype, recvbuf, recvcount,
          (MP(Datatype))recvtype, (MP(Comm))comm, (MP(RequestPtr))request))
FUNCTION(int, Ineighbor_alltoallv,
         (const void *sendbuf, const int sendcounts[], const int sdispls[],
          MT(Datatype) senddtype, void *recvbuf, const int recvcounts[],
          const int rdispls[], MT(Datatype) recvtype, MT(Comm) comm,
          MT(RequestPtr) request),
         (sendbuf, sendcounts, sdispls, (MP(Datatype))senddtype, recvbuf,
          recvcounts, rdispls, (MP(Datatype))recvtype, (MP(Comm))comm,
          (MP(RequestPtr))request))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Ineighbor_alltoallw,
         (const void *sendbuf, const int sendcounts[], const MT(Aint) sdispls[],
          const MT(Datatype) sendtypes[], void *recvbuf, const int recvcounts[],
          const MT(Aint) rdispls[], const MT(Datatype) recvtypes[],
          MT(Comm) comm, MT(RequestPtr) request),
         (sendbuf, sendcounts, (const MP(Aint) *)sdispls,
          (const MP(DatatypePtr))sendtypes, recvbuf, recvcounts,
          (const MP(Aint) *)rdispls, (const MP(DatatypePtr))recvtypes,
          (MP(Comm))comm, (MP(RequestPtr))request))
#endif

// 8.1 Implementation Information

#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Get_version, (int *version, int *subversion),
         (version, subversion))
#endif
FUNCTION(int, Get_library_version, (char *version, int *resultlen),
         (version, resultlen))
FUNCTION(int, Get_processor_name, (char *name, int *resultlen),
         (name, resultlen))

// 8.2 Memory Allocation
FUNCTION(int, Alloc_mem, (MT(Aint) size, MT(Info) info, void *baseptr),
         ((MP(Aint))size, (MP(Info))info, baseptr))
FUNCTION(int, Free_mem, (void *base), (base))

// 8.3 Error Handling
FUNCTION(int, Comm_create_errhandler,
         (MT(Comm_errhandler_function) * comm_errhandler_fn,
          MT(ErrhandlerPtr) errhandler),
         ((MP(Comm_errhandler_function) *)comm_errhandler_fn,
          (MP(ErrhandlerPtr))errhandler))
FUNCTION(int, Comm_set_errhandler, (MT(Comm) comm, MT(Errhandler) errhandler),
         ((MP(Comm))comm, (MP(Errhandler))errhandler))
FUNCTION(int, Comm_get_errhandler,
         (MT(Comm) comm, MT(ErrhandlerPtr) errhandler),
         ((MP(Comm))comm, (MP(ErrhandlerPtr))errhandler))
FUNCTION(int, Win_create_errhandler,
         (MT(Win_errhandler_function) * win_errhandler_fn,
          MT(ErrhandlerPtr) errhandler),
         ((MP(Win_errhandler_function) *)win_errhandler_fn,
          (MP(ErrhandlerPtr))errhandler))
FUNCTION(int, Win_set_errhandler, (MT(Win) win, MT(Errhandler) errhandler),
         ((MP(Win))win, (MP(Errhandler))errhandler))
FUNCTION(int, Win_get_errhandler, (MT(Win) win, MT(ErrhandlerPtr) errhandler),
         ((MP(Win))win, (MP(ErrhandlerPtr))errhandler))
FUNCTION(int, File_create_errhandler,
         (MT(File_errhandler_function) * file_errhandler_fn,
          MT(ErrhandlerPtr) errhandler),
         ((MP(File_errhandler_function) *)file_errhandler_fn,
          (MP(ErrhandlerPtr))errhandler))
FUNCTION(int, File_set_errhandler, (MT(File) file, MT(Errhandler) errhandler),
         ((MP(File))file, (MP(Errhandler))errhandler))
FUNCTION(int, File_get_errhandler,
         (MT(File) file, MT(ErrhandlerPtr) errhandler),
         ((MP(File))file, (MP(ErrhandlerPtr))errhandler))
FUNCTION(int, Errhandler_free, (MT(ErrhandlerPtr) errhandler),
         ((MP(ErrhandlerPtr))errhandler))

// 8.4 Error Codes and Classes
FUNCTION(int, Error_class, (int errorcode, int *errorclass),
         (errorcode, errorclass))

// 8.5 Error Classes, Error Codes, and Error Handlers
FUNCTION(int, Add_error_class, (int *errorclass), (errorclass))
FUNCTION(int, Add_error_code, (int errorclass, int *errorcode),
         (errorclass, errorcode))
FUNCTION(int, Add_error_string, (int errorcode, const char *string),
         (errorcode, string))
FUNCTION(int, Comm_call_errhandler, (MT(Comm) comm, int errorcode),
         ((MP(Comm))comm, errorcode))
FUNCTION(int, Win_call_errhandler, (MT(Win) win, int errorcode),
         ((MP(Win))win, errorcode))
FUNCTION(int, File_call_errhandler, (MT(File) file, int errorcode),
         ((MP(File))file, errorcode))

// 8.6 Times and Synchronization
FUNCTION(double, Wtime, (), ())
FUNCTION(double, Wtick, (), ())

// 8.7 Startup
FUNCTION(int, Init, (int *argc, char ***argv), (argc, argv))
FUNCTION(int, Finalize, (), ())
FUNCTION(int, Initialized, (int *flag), (flag))
FUNCTION(int, Abort, (MT(Comm) comm, int errorcode),
         ((MP(Comm))comm, errorcode))
FUNCTION(int, Finalized, (int *flag), (flag))

// 9 The Info Object
FUNCTION(int, Info_create, (MT(InfoPtr) info), ((MP(InfoPtr))info))
FUNCTION(int, Info_set, (MT(Info) info, const char *key, const char *value),
         ((MP(Info))info, key, value))
FUNCTION(int, Info_delete, (MT(Info) info, const char *key),
         ((MP(Info))info, key))
FUNCTION(int, Info_get,
         (MT(Info) info, const char *key, int valuelen, char *value, int *flag),
         ((MP(Info))info, key, valuelen, value, flag))
FUNCTION(int, Info_get_valuelen,
         (MT(Info) info, const char *key, int *valuelen, int *flag),
         ((MP(Info))info, key, valuelen, flag))
FUNCTION(int, Info_get_nkeys, (MT(Info) info, int *nkeys),
         ((MP(Info))info, nkeys))
FUNCTION(int, Info_get_nthkey, (MT(Info) info, int n, char *key),
         ((MP(Info))info, n, key))
FUNCTION(int, Info_dup, (MT(Info) info, MT(InfoPtr) newinfo),
         ((MP(Info))info, (MP(InfoPtr))newinfo))
FUNCTION(int, Info_free, (MT(InfoPtr) info), ((MP(InfoPtr))info))

// 10.3 Process Manager Interface
FUNCTION(int, Comm_spawn,
         (const char *command, char *argv[], int maxprocs, MT(Info) info,
          int root, MT(Comm) comm, MT(CommPtr) intercomm,
          int array_off_errcodes[]),
         (command, argv, maxprocs, (MP(Info))info, root, (MP(Comm))comm,
          (MP(CommPtr))intercomm, array_off_errcodes))
FUNCTION(int, Comm_get_parent, (MT(CommPtr) parent), ((MP(CommPtr))parent))
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Comm_spawn_multiple,
         (int count, char *array_of_commands[], char **array_of_argv[],
          const int array_of_maxprocs[], const MT(Info) array_of_info[],
          int root, MT(Comm) comm, MT(CommPtr) intercomm,
          int array_of_errcodes[]),
         (count, array_of_commands, array_of_argv, array_of_maxprocs,
          (const MP(InfoPtr))array_of_info, root, (MP(Comm))comm,
          (MP(CommPtr))intercomm, array_of_errcodes))
#endif

// 10.4 Establishing Communication
FUNCTION(int, Open_port, (MT(Info) info, char *port_name),
         ((MP(Info))info, port_name))
FUNCTION(int, Close_port, (const char *port_name), (port_name))
FUNCTION(int, Comm_accept,
         (const char *port_name, MT(Info) info, int root, MT(Comm) comm,
          MT(CommPtr) newcomm),
         (port_name, (MP(Info))info, root, (MP(Comm))comm,
          (MP(CommPtr))newcomm))
FUNCTION(int, Comm_connect,
         (const char *port_name, MT(Info) info, int root, MT(Comm) comm,
          MT(CommPtr) newcomm),
         (port_name, (MP(Info))info, root, (MP(Comm))comm,
          (MP(CommPtr))newcomm))
FUNCTION(int, Publish_name,
         (const char *service_name, MT(Info) info, const char *port_name),
         (service_name, (MP(Info))info, port_name))
FUNCTION(int, Unpublish_name,
         (const char *service_name, MT(Info) info, const char *port_name),
         (service_name, (MP(Info))info, port_name))
FUNCTION(int, Lookup_name,
         (const char *service_name, MT(Info) info, char *port_name),
         (service_name, (MP(Info))info, port_name))

// 10.5 Other Functionality
FUNCTION(int, Comm_disconnect, (MT(CommPtr) comm), ((MP(CommPtr))comm))
FUNCTION(int, Comm_join, (int fd, MT(CommPtr) intercomm),
         (fd, (MP(CommPtr))intercomm))

// 11.2 Initialization
FUNCTION(int, Win_create,
         (void *base, MT(Aint) size, int disp_unit, MT(Info) info,
          MT(Comm) comm, MT(WinPtr) win),
         (base, size, disp_unit, info, comm, win))
FUNCTION(int, Win_allocate,
         (MT(Aint) size, int disp_unit, MT(Info) info, MT(Comm) comm,
          void *baseptr, MT(WinPtr) win),
         (size, disp_unit, info, comm, baseptr, win))
FUNCTION(int, Win_allocate_shared,
         (MT(Aint) size, int disp_unit, MT(Info) info, MT(Comm) comm,
          void *baseptr, MT(WinPtr) win),
         (size, disp_unit, info, comm, baseptr, win))
FUNCTION(int, Win_shared_query,
         (MT(Win) win, int rank, MT(Aint) * size, int *disp_unit,
          void *baseptr),
         (win, rank, size, disp_unit, baseptr))
FUNCTION(int, Win_create_dynamic,
         (MT(Info) info, MT(Comm) comm, MT(WinPtr) win), (info, comm, win))
FUNCTION(int, Win_attach, (MT(Win) win, void *base, MT(Aint) size),
         (win, base, size))
FUNCTION(int, Win_detach, (MT(Win) win, const void *base), (win, base))
FUNCTION(int, Win_free, (MT(WinPtr) win), (win))
FUNCTION(int, Win_get_group, (MT(Win) win, MT(GroupPtr) group), (win, group))
FUNCTION(int, Win_set_info, (MT(Win) win, MT(Info) info), (win, info))
FUNCTION(int, Win_get_info, (MT(Win) win, MT(InfoPtr) info_used),
         (win, info_used))

// 11.3 Communication Calls
FUNCTION(int, Put,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Win) win),
         (origin_addr, origin_count, origin_datatype, target_rank, target_disp,
          target_count, target_datatype, win))
FUNCTION(int, Get,
         (void *origin_addr, int origin_count, MT(Datatype) origin_datatype,
          int target_rank, MT(Aint) target_disp, int target_count,
          MT(Datatype) target_datatype, MT(Win) win),
         (origin_addr, origin_count, origin_datatype, target_rank, target_disp,
          target_count, target_datatype, win))
FUNCTION(int, Accumulate,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Op) op,
          MT(Win) win),
         (origin_addr, origin_count, origin_datatype, target_rank, target_disp,
          target_count, target_datatype, op, win))
FUNCTION(int, Get_accumulate,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, void *result_addr, int result_count,
          MT(Datatype) result_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Op) op,
          MT(Win) win),
         (origin_addr, origin_count, origin_datatype, result_addr, result_count,
          result_datatype, target_rank, target_disp, target_count,
          target_datatype, op, win))
FUNCTION(int, Fetch_and_op,
         (const void *origin_addr, void *result_addr, MT(Datatype) datatype,
          int target_rank, MT(Aint) target_disp, MT(Op) op, MT(Win) win),
         (origin_addr, result_addr, datatype, target_rank, target_disp, op,
          win))
FUNCTION(int, Compare_and_swap,
         (const void *origin_addr, const void *compare_addr, void *result_addr,
          MT(Datatype) datatype, int target_rank, MT(Aint) target_disp,
          MT(Win) win),
         (origin_addr, compare_addr, result_addr, datatype, target_rank,
          target_disp, win))
FUNCTION(int, Rput,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Win) win,
          MT(RequestPtr) request),
         (origin_addr, origin_count, origin_datatype, target_rank, target_disp,
          target_count, target_datatype, win, request))
FUNCTION(int, Rget,
         (void *origin_addr, int origin_count, MT(Datatype) origin_datatype,
          int target_rank, MT(Aint) target_disp, int target_count,
          MT(Datatype) target_datatype, MT(Win) win, MT(RequestPtr) request),
         (origin_addr, origin_count, origin_datatype, target_rank, target_disp,
          target_count, target_datatype, win, request))
FUNCTION(int, Raccumulate,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Op) op,
          MT(Win) win, MT(RequestPtr) request),
         (origin_addr, origin_count, origin_datatype, target_rank, target_disp,
          target_count, target_datatype, op, win, request))
FUNCTION(int, Rget_accumulate,
         (const void *origin_addr, int origin_count,
          MT(Datatype) origin_datatype, void *result_addr, int result_count,
          MT(Datatype) result_datatype, int target_rank, MT(Aint) target_disp,
          int target_count, MT(Datatype) target_datatype, MT(Op) op,
          MT(Win) win, MT(RequestPtr) request),
         (origin_addr, origin_count, origin_datatype, result_addr, result_count,
          result_datatype, target_rank, target_disp, target_count,
          target_datatype, op, win, request))

// 11.5 Synchronization Calls
FUNCTION(int, Win_fence, (int assert, MT(Win) win), (assert, win))
FUNCTION(int, Win_start, (MT(Group) group, int assert, MT(Win) win),
         (group, assert, win))
FUNCTION(int, Win_complete, (MT(Win) win), (win))
FUNCTION(int, Win_wait, (MT(Win) win), (win))
FUNCTION(int, Win_test, (MT(Win) win, int *flag), (win, flag))
FUNCTION(int, Win_lock, (int lock_type, int rank, int assert, MT(Win) win),
         (lock_type, rank, assert, win))
FUNCTION(int, Win_lock_all, (int assert, MT(Win) win), (assert, win))
FUNCTION(int, Win_unlock, (int rank, MT(Win) win), (rank, win))
FUNCTION(int, Win_unlock_all, (MT(Win) win), (win))
FUNCTION(int, Win_flush, (int rank, MT(Win) win), (rank, win))
FUNCTION(int, Win_flush_all, (MT(Win) win), (win))
FUNCTION(int, Win_flush_local, (int rank, MT(Win) win), (rank, win))
FUNCTION(int, Win_flush_local_all, (MT(Win) win), (win))
FUNCTION(int, Win_sync, (MT(Win) win), (win))

// ES: i checked the standard; we are complete from the top to here

// 13.2 File Manipulation
FUNCTION(int, File_open,
         (MT(Comm) comm, const char *filename, int amode, MT(Info) info,
          MT(FilePtr) fh),
         ((MP(Comm))comm, filename, amode, (MP(Info))info, (MP(FilePtr))fh))
FUNCTION(int, File_close, (MT(FilePtr) fh), ((MP(FilePtr))fh))
FUNCTION(int, File_delete, (const char *filename, MT(Info) info),
         (filename, (MP(Info))info))
FUNCTION(int, File_set_size, (MT(File) fh, MT(Offset) size),
         ((MP(File))fh, (MP(Offset))size))
FUNCTION(int, File_preallocate, (MT(File) fh, MT(Offset) size),
         ((MP(File))fh, (MP(Offset))size))
FUNCTION(int, File_get_size, (MT(File) fh, MT(Offset) * size),
         ((MP(File))fh, (MP(Offset) *)size))
FUNCTION(int, File_get_group, (MT(File) fh, MT(GroupPtr) group),
         ((MP(File))fh, (MP(GroupPtr))group))
FUNCTION(int, File_get_amode, (MT(File) fh, int *amode), ((MP(File))fh, amode))
FUNCTION(int, File_set_info, (MT(File) fh, MT(Info) info),
         ((MP(File))fh, (MP(Info))info))
FUNCTION(int, File_get_info, (MT(File) fh, MT(InfoPtr) info_used),
         ((MP(File))fh, (MP(InfoPtr))info_used))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(int, Error_string, (int errorcode, char *string, int *resultlen),
         (errorcode, string, resultlen))

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
         (MT(File) fh, MT(Offset) * disp, MT(DatatypePtr) etype,
          MT(DatatypePtr) filetype, char *datarep),
         ((MP(File))fh, (MP(Offset) *)disp, (MP(DatatypePtr))etype,
          (MP(DatatypePtr))filetype, datarep))

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

FUNCTION(int, Init_thread,
         (int *argc, char ***argv, int required, int *provided),
         (argc, argv, required, provided))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(int, Is_thread_main, (int *flag), (flag))
FUNCTION(int, Query_thread, (int *provided), (provided))

/* One-Sided Communications */
FUNCTION(int, Win_post, (MT(Group) group, int assert, MT(Win) win),
         ((MP(Group))group, assert, (MP(Win))win))

/* Fortran 90-related functions.  These routines are available only if
   Fortran 90 support is enabled
*/
FUNCTION(int, Type_create_f90_integer, (int range, MT(DatatypePtr) newtype),
         (range, (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_f90_real,
         (int precision, int range, MT(DatatypePtr) newtype),
         (precision, range, (MP(DatatypePtr))newtype))
FUNCTION(int, Type_create_f90_complex,
         (int precision, int range, MT(DatatypePtr) newtype),
         (precision, range, (MP(DatatypePtr))newtype))

////////////////////////////////////////////////////////////////////////////////

#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Pcontrol, (const int level, ...), (level))
#endif
