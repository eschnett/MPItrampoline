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
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_hindexed,
//          (int count, int *array_of_blocklengths,
//           MT(Aint) * array_of_displacements, MT(Datatype) oldtype,
//           MT(Datatype) * newtype),
//          (count, array_of_blocklengths, (MP(Aint) *)array_of_displacements,
//           (MP(Datatype))oldtype, (MP(Datatype) *)newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_struct,
//          (int count, int *array_of_blocklengths,
//           MT(Aint) * array_of_displacements, MT(Datatype) * array_of_types,
//           MT(Datatype) * newtype),
//          (count, array_of_blocklengths, (MP(Aint) *)array_of_displacements,
//           (MP(Datatype) *)array_of_types, (MP(Datatype) *)newtype))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Address, (void *location, MT(Aint) * address),
//          (location, (MP(Aint) *)address))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_extent, (MT(Datatype) datatype, MT(Aint) * extent),
//          ((MP(Datatype))datatype, (MP(Aint) *)extent))
FUNCTION(int, Type_size, (MT(Datatype) datatype, int *size),
         ((MP(Datatype))datatype, size))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_lb, (MT(Datatype) datatype, MT(Aint) * displacement),
//          ((MP(Datatype))datatype, (MP(Aint) *)displacement))
// Does not exist in OpenMPI 4.1.1
// FUNCTION(int, Type_ub, (MT(Datatype) datatype, MT(Aint) * displacement),
//          ((MP(Datatype))datatype, (MP(Aint) *)displacement))
FUNCTION(int, Type_commit, (MT(Datatype) * datatype),
         ((MP(Datatype) *)datatype))
FUNCTION(int, Type_free, (MT(Datatype) * datatype), ((MP(Datatype) *)datatype))
FUNCTION(int, Get_elements,
         (MT(const_StatusPtr) status, MT(Datatype) datatype, int *count),
         ((MP(const_StatusPtr))status, (MP(Datatype))datatype, count))

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
#ifndef SKIP_MANUAL_FUNCTIONS
FUNCTION(int, Op_create,
         (MT(User_function) * user_fn, int commute, MT(Op) * op),
         ((MP(User_function) *)user_fn, commute, (MP(Op) *)op))
FUNCTION(int, Op_free, (MT(Op) * op), ((MP(Op) *)op))
#endif
FUNCTION(int, Allreduce,
         (const void *sendbuf, void *recvbuf, int count, MT(Datatype) datatype,
          MT(Op) op, MT(Comm) comm),
         (sendbuf, recvbuf, count, (MP(Datatype))datatype, (MP(Op))op,
          (MP(Comm))comm))

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

// TODO

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
FUNCTION(int, Comm_create, (MT(Comm) comm, MT(Group) group, MT(Comm) * newcomm),
         ((MP(Comm))comm, (MP(Group))group, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_split,
         (MT(Comm) comm, int color, int key, MT(Comm) * newcomm),
         ((MP(Comm))comm, color, key, (MP(Comm) *)newcomm))
FUNCTION(int, Comm_free, (MT(Comm) * comm), ((MP(Comm) *)comm))
FUNCTION(int, Comm_test_inter, (MT(Comm) comm, int *flag),
         ((MP(Comm))comm, flag))
FUNCTION(int, Comm_remote_size, (MT(Comm) comm, int *size),
         ((MP(Comm))comm, size))
FUNCTION(int, Comm_remote_group, (MT(Comm) comm, MT(Group) * group),
         ((MP(Comm))comm, (MP(Group) *)group))

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

FUNCTION(MT(Comm), Comm_f2c, (MT(Fint) comm), ((MP(Fint))comm))

FUNCTION(int, Comm_set_errhandler, (MT(Comm) comm, MT(Errhandler) errhandler),
         ((MP(Comm))comm, (MP(Errhandler))errhandler))
FUNCTION(int, Error_string, (int errorcode, char *string, int *resultlen),
         (errorcode, string, resultlen))
FUNCTION(int, Info_dup, (MT(Info) info, MT(Info) * newinfo),
         ((MP(Info))info, (MP(Info) *)newinfo))
FUNCTION(int, Comm_create_keyval,
         (MT(Comm_copy_attr_function) * comm_copy_attr_fn,
          MT(Comm_delete_attr_function) * comm_delete_attr_fn, int *comm_keyval,
          void *extra_state),
         ((MP(Comm_copy_attr_function) *)comm_copy_attr_fn,
          (MP(Comm_delete_attr_function) *)comm_delete_attr_fn, comm_keyval,
          extra_state))
FUNCTION(int, Info_free, (MT(Info) * info), ((MP(Info) *)info))
FUNCTION(int, Comm_set_attr,
         (MT(Comm) comm, int comm_keyval, void *attribute_val),
         ((MP(Comm))comm, comm_keyval, attribute_val))
FUNCTION(int, Comm_free_keyval, (int *comm_keyval), (comm_keyval))

FUNCTION(int, Info_get_nkeys, (MT(Info) info, int *nkeys),
         ((MP(Info))info, nkeys))
FUNCTION(int, Info_get_nthkey, (MT(Info) info, int n, char *key),
         ((MP(Info))info, n, key))
FUNCTION(int, Info_get,
         (MT(Info) info, const char *key, int valuelen, char *value, int *flag),
         ((MP(Info))info, key, valuelen, value, flag))

FUNCTION(int, Type_create_hvector,
         (int count, int blocklength, MT(Aint) stride, MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (count, blocklength, (MP(Aint))stride, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))
#warning "handle this array correctly"
FUNCTION(int, Type_create_struct,
         (int count, const int array_of_blocklengths[],
          const MT(Aint) array_of_displacements[],
          const MT(Datatype) array_of_types[], MT(Datatype) * newtype),
         (count, array_of_blocklengths,
          (const MP(Aint) *)array_of_displacements,
          (const MP(Datatype) *)array_of_types, (MP(Datatype) *)newtype))
FUNCTION(int, Type_get_extent,
         (MT(Datatype) datatype, MT(Aint) * lb, MT(Aint) * extent),
         ((MP(Datatype))datatype, (MP(Aint) *)lb, (MP(Aint) *)extent))

#warning "handle this array correctly"
FUNCTION(int, Type_create_hindexed,
         (int count, const int array_of_blocklengths[],
          const MT(Aint) array_of_displacements[], MT(Datatype) oldtype,
          MT(Datatype) * newtype),
         (count, array_of_blocklengths,
          (const MP(Aint) *)array_of_displacements, (MP(Datatype))oldtype,
          (MP(Datatype) *)newtype))

FUNCTION(MT(Aint), Aint_add, (MT(Aint) base, MT(Aint) disp),
         ((MP(Aint))base, (MP(Aint))disp))
FUNCTION(MT(Aint), Aint_diff, (MT(Aint) addr1, MT(Aint) addr2),
         ((MP(Aint))addr1, (MP(Aint))addr2))

////////////////////////////////////////////////////////////////////////////////

FUNCTION(double, Wtick, (), ())
FUNCTION(double, Wtime, (), ())

FUNCTION(int, Abort, (MT(Comm) comm, int errorcode),
         ((MP(Comm))comm, errorcode))
FUNCTION(int, Finalize, (), ())
FUNCTION(int, Finalized, (int *flag), (flag))
FUNCTION(int, Init, (int *argc, char ***argv), (argc, argv))
FUNCTION(int, Initialized, (int *flag), (flag))

FUNCTION(int, Get_processor_name, (char *name, int *resultlen),
         (name, resultlen))
FUNCTION(int, Get_version, (int *version, int *subversion),
         (version, subversion))
FUNCTION(int, Get_library_version, (char *version, int *resultlen),
         (version, resultlen))
