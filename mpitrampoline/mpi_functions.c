#include "mpi_functions.h"

// Define MPI functions

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

extern inline int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);
extern inline int MPI_Bsend_c(const void *buf, MPI_Count count,
                              MPI_Datatype datatype, int dest, int tag,
                              MPI_Comm comm);
extern inline int MPI_Bsend_init(const void *buf, int count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Bsend_init_c(const void *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int tag,
                                   MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Buffer_attach(void *buffer, int size);
extern inline int MPI_Buffer_attach_c(void *buffer, MPI_Count size);
extern inline int MPI_Buffer_detach(void *buffer_addr, int *size);
extern inline int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size);
extern inline int MPI_Buffer_flush(void);
extern inline int MPI_Buffer_iflush(MPI_Request *request);
extern inline int MPI_Cancel(MPI_Request *request);
extern inline int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size);
extern inline int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer,
                                           MPI_Count size);
extern inline int MPI_Comm_detach_buffer(MPI_Comm comm, void *buffer_addr,
                                         int *size);
extern inline int MPI_Comm_detach_buffer_c(MPI_Comm comm, void *buffer_addr,
                                           MPI_Count *size);
extern inline int MPI_Comm_flush_buffer(MPI_Comm comm);
extern inline int MPI_Comm_iflush_buffer(MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype,
                                int *count);
extern inline int MPI_Get_count_c(const MPI_Status *status,
                                  MPI_Datatype datatype, MPI_Count *count);
extern inline int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);
extern inline int MPI_Ibsend_c(const void *buf, MPI_Count count,
                               MPI_Datatype datatype, int dest, int tag,
                               MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                              MPI_Message *message, MPI_Status *status);
extern inline int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                             MPI_Message *message, MPI_Request *request);
extern inline int MPI_Imrecv_c(void *buf, MPI_Count count,
                               MPI_Datatype datatype, MPI_Message *message,
                               MPI_Request *request);
extern inline int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                             MPI_Status *status);
extern inline int MPI_Irecv(void *buf, int count, MPI_Datatype datatype,
                            int source, int tag, MPI_Comm comm,
                            MPI_Request *request);
extern inline int MPI_Irecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                              int source, int tag, MPI_Comm comm,
                              MPI_Request *request);
extern inline int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);
extern inline int MPI_Irsend_c(const void *buf, MPI_Count count,
                               MPI_Datatype datatype, int dest, int tag,
                               MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Isend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm,
                            MPI_Request *request);
extern inline int MPI_Isend_c(const void *buf, MPI_Count count,
                              MPI_Datatype datatype, int dest, int tag,
                              MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Isendrecv(const void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, int dest, int sendtag,
                                void *recvbuf, int recvcount,
                                MPI_Datatype recvtype, int source, int recvtag,
                                MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Isendrecv_c(const void *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, int dest, int sendtag,
                                  void *recvbuf, MPI_Count recvcount,
                                  MPI_Datatype recvtype, int source,
                                  int recvtag, MPI_Comm comm,
                                  MPI_Request *request);
extern inline int MPI_Isendrecv_replace(void *buf, int count,
                                        MPI_Datatype datatype, int dest,
                                        int sendtag, int source, int recvtag,
                                        MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Isendrecv_replace_c(void *buf, MPI_Count count,
                                          MPI_Datatype datatype, int dest,
                                          int sendtag, int source, int recvtag,
                                          MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Issend(const void *buf, int count, MPI_Datatype datatype,
                             int dest, int tag, MPI_Comm comm,
                             MPI_Request *request);
extern inline int MPI_Issend_c(const void *buf, MPI_Count count,
                               MPI_Datatype datatype, int dest, int tag,
                               MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Mprobe(int source, int tag, MPI_Comm comm,
                             MPI_Message *message, MPI_Status *status);
extern inline int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                            MPI_Message *message, MPI_Status *status);
extern inline int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                              MPI_Message *message, MPI_Status *status);
extern inline int MPI_Probe(int source, int tag, MPI_Comm comm,
                            MPI_Status *status);
extern inline int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Status *status);
extern inline int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                             int source, int tag, MPI_Comm comm,
                             MPI_Status *status);
extern inline int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                                int source, int tag, MPI_Comm comm,
                                MPI_Request *request);
extern inline int MPI_Recv_init_c(void *buf, MPI_Count count,
                                  MPI_Datatype datatype, int source, int tag,
                                  MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Request_free(MPI_Request *request);
extern inline int MPI_Request_get_status(MPI_Request request, int *flag,
                                         MPI_Status *status);
extern inline int
MPI_Request_get_status_all(int count, const MPI_Request array_of_requests[],
                           int *flag, MPI_Status array_of_statuses[]);
extern inline int
MPI_Request_get_status_any(int count, const MPI_Request array_of_requests[],
                           int *index, int *flag, MPI_Status *status);
extern inline int
MPI_Request_get_status_some(int incount, const MPI_Request array_of_requests[],
                            int *outcount, int array_of_indices[],
                            MPI_Status array_of_statuses[]);
extern inline int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);
extern inline int MPI_Rsend_c(const void *buf, MPI_Count count,
                              MPI_Datatype datatype, int dest, int tag,
                              MPI_Comm comm);
extern inline int MPI_Rsend_init(const void *buf, int count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Rsend_init_c(const void *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int tag,
                                   MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Send(const void *buf, int count, MPI_Datatype datatype,
                           int dest, int tag, MPI_Comm comm);
extern inline int MPI_Send_c(const void *buf, MPI_Count count,
                             MPI_Datatype datatype, int dest, int tag,
                             MPI_Comm comm);
extern inline int MPI_Send_init(const void *buf, int count,
                                MPI_Datatype datatype, int dest, int tag,
                                MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Send_init_c(const void *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int tag,
                                  MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Sendrecv(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, int dest, int sendtag,
                               void *recvbuf, int recvcount,
                               MPI_Datatype recvtype, int source, int recvtag,
                               MPI_Comm comm, MPI_Status *status);
extern inline int MPI_Sendrecv_c(const void *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, int dest, int sendtag,
                                 void *recvbuf, MPI_Count recvcount,
                                 MPI_Datatype recvtype, int source, int recvtag,
                                 MPI_Comm comm, MPI_Status *status);
extern inline int MPI_Sendrecv_replace(void *buf, int count,
                                       MPI_Datatype datatype, int dest,
                                       int sendtag, int source, int recvtag,
                                       MPI_Comm comm, MPI_Status *status);
extern inline int MPI_Sendrecv_replace_c(void *buf, MPI_Count count,
                                         MPI_Datatype datatype, int dest,
                                         int sendtag, int source, int recvtag,
                                         MPI_Comm comm, MPI_Status *status);
extern inline int MPI_Session_attach_buffer(MPI_Session session, void *buffer,
                                            int size);
extern inline int MPI_Session_attach_buffer_c(MPI_Session session, void *buffer,
                                              MPI_Count size);
extern inline int MPI_Session_detach_buffer(MPI_Session session,
                                            void *buffer_addr, int *size);
extern inline int MPI_Session_detach_buffer_c(MPI_Session session,
                                              void *buffer_addr,
                                              MPI_Count *size);
extern inline int MPI_Session_flush_buffer(MPI_Session session);
extern inline int MPI_Session_iflush_buffer(MPI_Session session,
                                            MPI_Request *request);
extern inline int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype,
                            int dest, int tag, MPI_Comm comm);
extern inline int MPI_Ssend_c(const void *buf, MPI_Count count,
                              MPI_Datatype datatype, int dest, int tag,
                              MPI_Comm comm);
extern inline int MPI_Ssend_init(const void *buf, int count,
                                 MPI_Datatype datatype, int dest, int tag,
                                 MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ssend_init_c(const void *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int tag,
                                   MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Start(MPI_Request *request);
extern inline int MPI_Startall(int count, MPI_Request array_of_requests[]);
extern inline int MPI_Status_get_error(MPI_Status *status, int *err);
extern inline int MPI_Status_get_source(MPI_Status *status, int *source);
extern inline int MPI_Status_get_tag(MPI_Status *status, int *tag);
extern inline int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status);
extern inline int MPI_Test_cancelled(const MPI_Status *status, int *flag);
extern inline int MPI_Testall(int count, MPI_Request array_of_requests[],
                              int *flag, MPI_Status array_of_statuses[]);
extern inline int MPI_Testany(int count, MPI_Request array_of_requests[],
                              int *index, int *flag, MPI_Status *status);
extern inline int MPI_Testsome(int incount, MPI_Request array_of_requests[],
                               int *outcount, int array_of_indices[],
                               MPI_Status array_of_statuses[]);
extern inline int MPI_Wait(MPI_Request *request, MPI_Status *status);
extern inline int MPI_Waitall(int count, MPI_Request array_of_requests[],
                              MPI_Status array_of_statuses[]);
extern inline int MPI_Waitany(int count, MPI_Request array_of_requests[],
                              int *index, MPI_Status *status);
extern inline int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                               int *outcount, int array_of_indices[],
                               MPI_Status array_of_statuses[]);

// A.3.2 Partitioned Communication C Bindings

extern inline int MPI_Parrived(MPI_Request request, int partition, int *flag);
extern inline int MPI_Pready(int partition, MPI_Request request);
extern inline int MPI_Pready_list(int length, const int array_of_partitions[],
                                  MPI_Request request);
extern inline int MPI_Pready_range(int partition_low, int partition_high,
                                   MPI_Request request);
extern inline int MPI_Precv_init(void *buf, int partitions, MPI_Count count,
                                 MPI_Datatype datatype, int source, int tag,
                                 MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request);
extern inline int MPI_Psend_init(const void *buf, int partitions,
                                 MPI_Count count, MPI_Datatype datatype,
                                 int dest, int tag, MPI_Comm comm,
                                 MPI_Info info, MPI_Request *request);

// A.3.3 Datatypes C Bindings

extern inline MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp);
extern inline MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2);
extern inline int MPI_Get_address(const void *location, MPI_Aint *address);
extern inline int MPI_Get_elements(const MPI_Status *status,
                                   MPI_Datatype datatype, int *count);
extern inline int MPI_Get_elements_c(const MPI_Status *status,
                                     MPI_Datatype datatype, MPI_Count *count);
extern inline int MPI_Pack(const void *inbuf, int incount,
                           MPI_Datatype datatype, void *outbuf, int outsize,
                           int *position, MPI_Comm comm);
extern inline int MPI_Pack_c(const void *inbuf, MPI_Count incount,
                             MPI_Datatype datatype, void *outbuf,
                             MPI_Count outsize, MPI_Count *position,
                             MPI_Comm comm);
extern inline int MPI_Pack_external(const char datarep[], const void *inbuf,
                                    int incount, MPI_Datatype datatype,
                                    void *outbuf, MPI_Aint outsize,
                                    MPI_Aint *position);
extern inline int MPI_Pack_external_c(const char datarep[], const void *inbuf,
                                      MPI_Count incount, MPI_Datatype datatype,
                                      void *outbuf, MPI_Count outsize,
                                      MPI_Count *position);
extern inline int MPI_Pack_external_size(const char datarep[],
                                         MPI_Count incount,
                                         MPI_Datatype datatype, MPI_Aint *size);
extern inline int MPI_Pack_external_size_c(const char datarep[],
                                           MPI_Count incount,
                                           MPI_Datatype datatype,
                                           MPI_Count *size);
extern inline int MPI_Pack_size_c(MPI_Count incount, MPI_Datatype datatype,
                                  MPI_Comm comm, MPI_Count *size);
extern inline int MPI_Type_commit(MPI_Datatype *datatype);
extern inline int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                                      MPI_Datatype *newtype);
extern inline int MPI_Type_contiguous_c(MPI_Count count, MPI_Datatype oldtype,
                                        MPI_Datatype *newtype);
extern inline int MPI_Type_create_darray(int size, int rank, int ndims,
                                         const int array_of_gsizes[],
                                         const int array_of_distribs[],
                                         const int array_of_dargs[],
                                         const int array_of_psizes[], int order,
                                         MPI_Datatype oldtype,
                                         MPI_Datatype *newtype);
extern inline int MPI_Type_create_darray_c(int size, int rank, int ndims,
                                           const MPI_Count array_of_gsizes[],
                                           const int array_of_distribs[],
                                           const int array_of_dargs[],
                                           const int array_of_psizes[],
                                           int order, MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);
extern inline int
MPI_Type_create_hindexed(int count, const int array_of_blocklengths[],
                         const MPI_Aint array_of_displacements[],
                         MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int
MPI_Type_create_hindexed_block(int count, int blocklength,
                               const MPI_Aint array_of_displacements[],
                               MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int
MPI_Type_create_hindexed_block_c(MPI_Count count, MPI_Count blocklength,
                                 const MPI_Count array_of_displacements[],
                                 MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int
MPI_Type_create_hindexed_c(MPI_Count count,
                           const MPI_Count array_of_blocklengths[],
                           const MPI_Count array_of_displacements[],
                           MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int MPI_Type_create_hvector(int count, int blocklength,
                                          MPI_Aint stride, MPI_Datatype oldtype,
                                          MPI_Datatype *newtype);
extern inline int MPI_Type_create_hvector_c(MPI_Count count,
                                            MPI_Count blocklength,
                                            MPI_Count stride,
                                            MPI_Datatype oldtype,
                                            MPI_Datatype *newtype);
extern inline int
MPI_Type_create_indexed_block(int count, int blocklength,
                              const int array_of_displacements[],
                              MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int
MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                const MPI_Count array_of_displacements[],
                                MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                          MPI_Aint extent,
                                          MPI_Datatype *newtype);
extern inline int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb,
                                            MPI_Count extent,
                                            MPI_Datatype *newtype);
extern inline int
MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                       const MPI_Aint array_of_displacements[],
                       const MPI_Datatype array_of_types[],
                       MPI_Datatype *newtype);
extern inline int MPI_Type_create_struct_c(
    MPI_Count count, const MPI_Count array_of_blocklengths[],
    const MPI_Count array_of_displacements[],
    const MPI_Datatype array_of_types[], MPI_Datatype *newtype);
extern inline int MPI_Type_create_subarray(int ndims,
                                           const int array_of_sizes[],
                                           const int array_of_subsizes[],
                                           const int array_of_starts[],
                                           int order, MPI_Datatype oldtype,
                                           MPI_Datatype *newtype);
extern inline int
MPI_Type_create_subarray_c(int ndims, const MPI_Count array_of_sizes[],
                           const MPI_Count array_of_subsizes[],
                           const MPI_Count array_of_starts[], int order,
                           MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int MPI_Type_free(MPI_Datatype *datatype);
extern inline int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                        int max_addresses, int max_datatypes,
                                        int array_of_integers[],
                                        MPI_Aint array_of_addresses[],
                                        MPI_Datatype array_of_datatypes[]);
extern inline int MPI_Type_get_contents_c(
    MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses,
    MPI_Count max_large_counts, MPI_Count max_datatypes,
    int array_of_integers[], MPI_Aint array_of_addresses[],
    MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[]);
extern inline int MPI_Type_get_envelope(MPI_Datatype datatype,
                                        int *num_integers, int *num_addresses,
                                        int *num_datatypes, int *combiner);
extern inline int
MPI_Type_get_envelope_c(MPI_Datatype datatype, MPI_Count *num_integers,
                        MPI_Count *num_addresses, MPI_Count *num_large_counts,
                        MPI_Count *num_datatypes, int *combiner);
extern inline int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                                      MPI_Aint *extent);
extern inline int MPI_Type_get_extent_c(MPI_Datatype datatype, MPI_Count *lb,
                                        MPI_Count *extent);
extern inline int MPI_Type_get_true_extent(MPI_Datatype datatype,
                                           MPI_Aint *true_lb,
                                           MPI_Aint *true_extent);
extern inline int MPI_Type_get_true_extent_c(MPI_Datatype datatype,
                                             MPI_Count *true_lb,
                                             MPI_Count *true_extent);
extern inline int MPI_Type_indexed(int count, const int array_of_blocklengths[],
                                   const int array_of_displacements[],
                                   MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int MPI_Type_indexed_c(MPI_Count count,
                                     const MPI_Count array_of_blocklengths[],
                                     const MPI_Count array_of_displacements[],
                                     MPI_Datatype oldtype,
                                     MPI_Datatype *newtype);
extern inline int MPI_Type_size(MPI_Datatype datatype, int *size);
extern inline int MPI_Type_size_c(MPI_Datatype datatype, MPI_Count *size);
extern inline int MPI_Type_vector(int count, int blocklength, int stride,
                                  MPI_Datatype oldtype, MPI_Datatype *newtype);
extern inline int MPI_Type_vector_c(MPI_Count count, MPI_Count blocklength,
                                    MPI_Count stride, MPI_Datatype oldtype,
                                    MPI_Datatype *newtype);
extern inline int MPI_Unpack(const void *inbuf, int insize, int *position,
                             void *outbuf, int outcount, MPI_Datatype datatype,
                             MPI_Comm comm);
extern inline int MPI_Unpack_c(const void *inbuf, MPI_Count insize,
                               MPI_Count *position, void *outbuf,
                               MPI_Count outcount, MPI_Datatype datatype,
                               MPI_Comm comm);
extern inline int MPI_Unpack_external(const char datarep[], const void *inbuf,
                                      MPI_Aint insize, MPI_Aint *position,
                                      void *outbuf, int outcount,
                                      MPI_Datatype datatype);
extern inline int MPI_Unpack_external_c(const char datarep[], const void *inbuf,
                                        MPI_Count insize, MPI_Count *position,
                                        void *outbuf, MPI_Count outcount,
                                        MPI_Datatype datatype);

// A.3.4 Collective Communication C Bindings

extern inline int MPI_Allgather(const void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm);
extern inline int MPI_Allgather_c(const void *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Count recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm);
extern inline int MPI_Allgather_init(const void *sendbuf, int sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request);
extern inline int MPI_Allgather_init_c(const void *sendbuf, MPI_Count sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       MPI_Count recvcount,
                                       MPI_Datatype recvtype, MPI_Comm comm,
                                       MPI_Info info, MPI_Request *request);
extern inline int MPI_Allgatherv(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const int recvcounts[], const int displs[],
                                 MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const MPI_Count recvcounts[],
                                   const MPI_Aint displs[],
                                   MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Allgatherv_init(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const int recvcounts[],
                                      const int displs[], MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Info info,
                                      MPI_Request *request);
extern inline int MPI_Allgatherv_init_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request);
extern inline int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                                MPI_Datatype datatype, MPI_Op op,
                                MPI_Comm comm);
extern inline int MPI_Allreduce_c(const void *sendbuf, void *recvbuf,
                                  MPI_Count count, MPI_Datatype datatype,
                                  MPI_Op op, MPI_Comm comm);
extern inline int MPI_Allreduce_init(const void *sendbuf, void *recvbuf,
                                     int count, MPI_Datatype datatype,
                                     MPI_Op op, MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request);
extern inline int MPI_Allreduce_init_c(const void *sendbuf, void *recvbuf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Op op, MPI_Comm comm, MPI_Info info,
                                       MPI_Request *request);
extern inline int MPI_Alltoall(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm);
extern inline int MPI_Alltoall_c(const void *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Count recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm);
extern inline int MPI_Alltoall_init(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request);
extern inline int MPI_Alltoall_init_c(const void *sendbuf, MPI_Count sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      MPI_Count recvcount,
                                      MPI_Datatype recvtype, MPI_Comm comm,
                                      MPI_Info info, MPI_Request *request);
extern inline int MPI_Alltoallv(const void *sendbuf, const int sendcounts[],
                                const int sdispls[], MPI_Datatype sendtype,
                                void *recvbuf, const int recvcounts[],
                                const int rdispls[], MPI_Datatype recvtype,
                                MPI_Comm comm);
extern inline int
MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Alltoallv_init(const void *sendbuf,
                                     const int sendcounts[],
                                     const int sdispls[], MPI_Datatype sendtype,
                                     void *recvbuf, const int recvcounts[],
                                     const int rdispls[], MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request);
extern inline int
MPI_Alltoallv_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                     const MPI_Aint sdispls[], MPI_Datatype sendtype,
                     void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], MPI_Datatype recvtype,
                     MPI_Comm comm, MPI_Info info, MPI_Request *request);
extern inline int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                                const int sdispls[],
                                const MPI_Datatype sendtypes[], void *recvbuf,
                                const int recvcounts[], const int rdispls[],
                                const MPI_Datatype recvtypes[], MPI_Comm comm);
extern inline int MPI_Alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm);
extern inline int
MPI_Alltoallw_init(const void *sendbuf, const int sendcounts[],
                   const int sdispls[], const MPI_Datatype sendtypes[],
                   void *recvbuf, const int recvcounts[], const int rdispls[],
                   const MPI_Datatype recvtypes[], MPI_Comm comm, MPI_Info info,
                   MPI_Request *request);
extern inline int
MPI_Alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                     const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                     void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                     MPI_Comm comm, MPI_Info info, MPI_Request *request);
extern inline int MPI_Barrier(MPI_Comm comm);
extern inline int MPI_Barrier_init(MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request);
extern inline int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
                            int root, MPI_Comm comm);
extern inline int MPI_Bcast_c(void *buffer, MPI_Count count,
                              MPI_Datatype datatype, int root, MPI_Comm comm);
extern inline int MPI_Bcast_init(void *buffer, int count, MPI_Datatype datatype,
                                 int root, MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request);
extern inline int MPI_Bcast_init_c(void *buffer, MPI_Count count,
                                   MPI_Datatype datatype, int root,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request);
extern inline int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
extern inline int MPI_Exscan_c(const void *sendbuf, void *recvbuf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm);
extern inline int MPI_Exscan_init(const void *sendbuf, void *recvbuf, int count,
                                  MPI_Datatype datatype, MPI_Op op,
                                  MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request);
extern inline int MPI_Exscan_init_c(const void *sendbuf, void *recvbuf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request);
extern inline int MPI_Gather(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype, int root,
                             MPI_Comm comm);
extern inline int MPI_Gather_c(const void *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               int root, MPI_Comm comm);
extern inline int MPI_Gather_init(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  int root, MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request);
extern inline int MPI_Gather_init_c(const void *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    int root, MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request);
extern inline int MPI_Gatherv(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const int recvcounts[], const int displs[],
                              MPI_Datatype recvtype, int root, MPI_Comm comm);
extern inline int MPI_Gatherv_c(const void *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                const MPI_Count recvcounts[],
                                const MPI_Aint displs[], MPI_Datatype recvtype,
                                int root, MPI_Comm comm);
extern inline int MPI_Gatherv_init(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const int recvcounts[], const int displs[],
                                   MPI_Datatype recvtype, int root,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request);
extern inline int MPI_Gatherv_init_c(const void *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const MPI_Count recvcounts[],
                                     const MPI_Aint displs[],
                                     MPI_Datatype recvtype, int root,
                                     MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request);
extern inline int MPI_Iallgather(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iallgatherv(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  const int recvcounts[], const int displs[],
                                  MPI_Datatype recvtype, MPI_Comm comm,
                                  MPI_Request *request);
extern inline int MPI_Iallgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    const MPI_Count recvcounts[],
                                    const MPI_Aint displs[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Request *request);
extern inline int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iallreduce_c(const void *sendbuf, void *recvbuf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Op op, MPI_Comm comm,
                                   MPI_Request *request);
extern inline int MPI_Ialltoall(const void *sendbuf, int sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ialltoall_c(const void *sendbuf, MPI_Count sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Count recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                                 const int sdispls[], MPI_Datatype sendtype,
                                 void *recvbuf, const int recvcounts[],
                                 const int rdispls[], MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Request *request);
extern inline int
MPI_Ialltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                 const MPI_Aint sdispls[], MPI_Datatype sendtype, void *recvbuf,
                 const MPI_Count recvcounts[], const MPI_Aint rdispls[],
                 MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                                 const int sdispls[],
                                 const MPI_Datatype sendtypes[], void *recvbuf,
                                 const int recvcounts[], const int rdispls[],
                                 const MPI_Datatype recvtypes[], MPI_Comm comm,
                                 MPI_Request *request);
extern inline int
MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[],
                 const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                 void *recvbuf, const MPI_Count recvcounts[],
                 const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                 MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype,
                             int root, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ibcast_c(void *buffer, MPI_Count count,
                               MPI_Datatype datatype, int root, MPI_Comm comm,
                               MPI_Request *request);
extern inline int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Request *request);
extern inline int MPI_Iexscan_c(const void *sendbuf, void *recvbuf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Igather(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Igather_c(const void *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Count recvcount, MPI_Datatype recvtype,
                                int root, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Igatherv(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Request *request);
extern inline int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Count recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 int root, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, int root,
                              MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ireduce_c(const void *sendbuf, void *recvbuf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Op op, int root, MPI_Comm comm,
                                MPI_Request *request);
extern inline int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                                      const int recvcounts[],
                                      MPI_Datatype datatype, MPI_Op op,
                                      MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                            int recvcount,
                                            MPI_Datatype datatype, MPI_Op op,
                                            MPI_Comm comm,
                                            MPI_Request *request);
extern inline int
MPI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                            MPI_Count recvcount, MPI_Datatype datatype,
                            MPI_Op op, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf,
                                        const MPI_Count recvcounts[],
                                        MPI_Datatype datatype, MPI_Op op,
                                        MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request);
extern inline int MPI_Iscan_c(const void *sendbuf, void *recvbuf,
                              MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                              MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iscatter(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPI_Datatype recvtype, int root,
                               MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iscatter_c(const void *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 MPI_Count recvcount, MPI_Datatype recvtype,
                                 int root, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                                const int displs[], MPI_Datatype sendtype,
                                void *recvbuf, int recvcount,
                                MPI_Datatype recvtype, int root, MPI_Comm comm,
                                MPI_Request *request);
extern inline int
MPI_Iscatterv_c(const void *sendbuf, const MPI_Count sendcounts[],
                const MPI_Aint displs[], MPI_Datatype sendtype, void *recvbuf,
                MPI_Count recvcount, MPI_Datatype recvtype, int root,
                MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Op_commutative(MPI_Op op, int *commute);
extern inline int MPI_Op_create(MPI_User_function *user_fn, int commute,
                                MPI_Op *op);
extern inline int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute,
                                  MPI_Op *op);
extern inline int MPI_Op_free(MPI_Op *op);
extern inline int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
                             MPI_Datatype datatype, MPI_Op op, int root,
                             MPI_Comm comm);
extern inline int MPI_Reduce_c(const void *sendbuf, void *recvbuf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Op op, int root, MPI_Comm comm);
extern inline int MPI_Reduce_init(const void *sendbuf, void *recvbuf, int count,
                                  MPI_Datatype datatype, MPI_Op op, int root,
                                  MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request);
extern inline int MPI_Reduce_init_c(const void *sendbuf, void *recvbuf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Op op, int root, MPI_Comm comm,
                                    MPI_Info info, MPI_Request *request);
extern inline int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                                   MPI_Datatype datatype, MPI_Op op);
extern inline int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf,
                                     MPI_Count count, MPI_Datatype datatype,
                                     MPI_Op op);
extern inline int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                                     const int recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm);
extern inline int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                           int recvcount, MPI_Datatype datatype,
                                           MPI_Op op, MPI_Comm comm);
extern inline int MPI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                             MPI_Count recvcount,
                                             MPI_Datatype datatype, MPI_Op op,
                                             MPI_Comm comm);
extern inline int
MPI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf, int recvcount,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Info info, MPI_Request *request);
extern inline int
MPI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf,
                                MPI_Count recvcount, MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm, MPI_Info info,
                                MPI_Request *request);
extern inline int MPI_Reduce_scatter_c(const void *sendbuf, void *recvbuf,
                                       const MPI_Count recvcounts[],
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPI_Comm comm);
extern inline int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf,
                                          const int recvcounts[],
                                          MPI_Datatype datatype, MPI_Op op,
                                          MPI_Comm comm, MPI_Info info,
                                          MPI_Request *request);
extern inline int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf,
                                            const MPI_Count recvcounts[],
                                            MPI_Datatype datatype, MPI_Op op,
                                            MPI_Comm comm, MPI_Info info,
                                            MPI_Request *request);
extern inline int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);
extern inline int MPI_Scan_c(const void *sendbuf, void *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm);
extern inline int MPI_Scan_init(const void *sendbuf, void *recvbuf, int count,
                                MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                                MPI_Info info, MPI_Request *request);
extern inline int MPI_Scan_init_c(const void *sendbuf, void *recvbuf,
                                  MPI_Count count, MPI_Datatype datatype,
                                  MPI_Op op, MPI_Comm comm, MPI_Info info,
                                  MPI_Request *request);
extern inline int MPI_Scatter(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype, int root,
                              MPI_Comm comm);
extern inline int MPI_Scatter_c(const void *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Count recvcount, MPI_Datatype recvtype,
                                int root, MPI_Comm comm);
extern inline int MPI_Scatter_init(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   int root, MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request);
extern inline int MPI_Scatter_init_c(const void *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Count recvcount, MPI_Datatype recvtype,
                                     int root, MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request);
extern inline int MPI_Scatterv(const void *sendbuf, const int sendcounts[],
                               const int displs[], MPI_Datatype sendtype,
                               void *recvbuf, int recvcount,
                               MPI_Datatype recvtype, int root, MPI_Comm comm);
extern inline int MPI_Scatterv_c(const void *sendbuf,
                                 const MPI_Count sendcounts[],
                                 const MPI_Aint displs[], MPI_Datatype sendtype,
                                 void *recvbuf, MPI_Count recvcount,
                                 MPI_Datatype recvtype, int root,
                                 MPI_Comm comm);
extern inline int MPI_Scatterv_init(const void *sendbuf, const int sendcounts[],
                                    const int displs[], MPI_Datatype sendtype,
                                    void *recvbuf, int recvcount,
                                    MPI_Datatype recvtype, int root,
                                    MPI_Comm comm, MPI_Info info,
                                    MPI_Request *request);
extern inline int
MPI_Scatterv_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                    const MPI_Aint displs[], MPI_Datatype sendtype,
                    void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype,
                    int root, MPI_Comm comm, MPI_Info info,
                    MPI_Request *request);
extern inline int MPI_Type_get_value_index(MPI_Datatype value_type,
                                           MPI_Datatype index_type,
                                           MPI_Datatype *pair_type);

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

extern inline int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result);
extern inline int MPI_Comm_create(MPI_Comm comm, MPI_Group group,
                                  MPI_Comm *newcomm);
extern inline int MPI_Comm_create_from_group(MPI_Group group,
                                             const char *stringtag,
                                             MPI_Info info,
                                             MPI_Errhandler errhandler,
                                             MPI_Comm *newcomm);
extern inline int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                        MPI_Comm *newcomm);
extern inline int
MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                       MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                       int *comm_keyval, void *extra_state);
extern inline int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);
extern inline int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
extern inline int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                         MPI_Comm *newcomm);
extern inline int MPI_Comm_free(MPI_Comm *comm);
extern inline int MPI_Comm_get_name(MPI_Comm comm, char *comm_name,
                                    int *resultlen);
extern inline int MPI_Comm_free_keyval(int *comm_keyval);
extern inline int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                                    void *attribute_val, int *flag);
extern inline int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used);
extern inline int MPI_Comm_group(MPI_Comm comm, MPI_Group *group);
extern inline int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                                MPI_Request *request);
extern inline int MPI_Comm_idup_with_info(MPI_Comm comm, MPI_Info info,
                                          MPI_Comm *newcomm,
                                          MPI_Request *request);
extern inline int MPI_Comm_rank(MPI_Comm comm, int *rank);
extern inline int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);
extern inline int MPI_Comm_remote_size(MPI_Comm comm, int *size);
extern inline int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                                    void *attribute_val);
extern inline int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info);
extern inline int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name);
extern inline int MPI_Comm_size(MPI_Comm comm, int *size);
extern inline int MPI_Comm_split(MPI_Comm comm, int color, int key,
                                 MPI_Comm *newcomm);
extern inline int MPI_Group_free(MPI_Group *group);
extern inline int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                                      MPI_Info info, MPI_Comm *newcomm);
extern inline int MPI_Comm_test_inter(MPI_Comm comm, int *flag);
extern inline int MPI_Group_compare(MPI_Group group1, MPI_Group group2,
                                    int *result);
extern inline int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                       MPI_Group *newgroup);
extern inline int MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                                 MPI_Group *newgroup);
extern inline int MPI_Group_from_session_pset(MPI_Session session,
                                              const char *pset_name,
                                              MPI_Group *newgroup);
extern inline int MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                                 MPI_Group *newgroup);
extern inline int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                         MPI_Group *newgroup);
extern inline int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                       MPI_Group *newgroup);
extern inline int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                       MPI_Group *newgroup);
extern inline int MPI_Group_rank(MPI_Group group, int *rank);
extern inline int MPI_Group_size(MPI_Group group, int *size);
extern inline int MPI_Group_translate_ranks(MPI_Group group1, int n,
                                            const int ranks1[],
                                            MPI_Group group2, int ranks2[]);
extern inline int MPI_Group_union(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup);
extern inline int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                       MPI_Comm peer_comm, int remote_leader,
                                       int tag, MPI_Comm *newintercomm);
extern inline int MPI_Intercomm_create_from_groups(
    MPI_Group local_group, int local_leader, MPI_Group remote_group,
    int remote_leader, const char *stringtag, MPI_Info info,
    MPI_Errhandler errhandler, MPI_Comm *newintercomm);
extern inline int MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                                      MPI_Comm *newintracomm);
extern inline int
MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                       MPI_Type_delete_attr_function *type_delete_attr_fn,
                       int *type_keyval, void *extra_state);
extern inline int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval);
extern inline int MPI_Type_free_keyval(int *type_keyval);
extern inline int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                                    void *attribute_val, int *flag);
extern inline int MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                                    int *resultlen);
extern inline int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                                    void *attribute_val);
extern inline int MPI_Type_set_name(MPI_Datatype datatype,
                                    const char *type_name);
extern inline int
MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                      MPI_Win_delete_attr_function *win_delete_attr_fn,
                      int *win_keyval, void *extra_state);
extern inline int MPI_Win_delete_attr(MPI_Win win, int win_keyval);
extern inline int MPI_Win_free_keyval(int *win_keyval);
extern inline int MPI_Win_get_attr(MPI_Win win, int win_keyval,
                                   void *attribute_val, int *flag);
extern inline int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen);
extern inline int MPI_Win_set_attr(MPI_Win win, int win_keyval,
                                   void *attribute_val);
extern inline int MPI_Win_set_name(MPI_Win win, const char *win_name);

// A.3.6 Virtual Topologies for MPI Processes C Bindings

extern inline int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
                                  int coords[]);
extern inline int MPI_Cart_create(MPI_Comm comm_old, int ndims,
                                  const int dims[], const int periods[],
                                  int reorder, MPI_Comm *comm_cart);
extern inline int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[],
                               int periods[], int coords[]);
extern inline int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                               const int periods[], int *newrank);
extern inline int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank);
extern inline int MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                                 int *rank_source, int *rank_dest);
extern inline int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[],
                               MPI_Comm *newcomm);
extern inline int MPI_Cartdim_get(MPI_Comm comm, int *ndims);
extern inline int MPI_Dims_create(int nnodes, int ndims, int dims[]);
extern inline int MPI_Dist_graph_create(MPI_Comm comm_old, int n,
                                        const int sources[],
                                        const int degrees[],
                                        const int destinations[],
                                        const int weights[], MPI_Info info,
                                        int reorder, MPI_Comm *comm_dist_graph);
extern inline int
MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                               const int sources[], const int sourceweights[],
                               int outdegree, const int destinations[],
                               const int destweights[], MPI_Info info,
                               int reorder, MPI_Comm *comm_dist_graph);
extern inline int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                           int sources[], int sourceweights[],
                                           int maxoutdegree, int destinations[],
                                           int destweights[]);
extern inline int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                                 int *outdegree, int *weighted);
extern inline int MPI_Graph_create(MPI_Comm comm_old, int nnodes,
                                   const int index[], const int edges[],
                                   int reorder, MPI_Comm *comm_graph);
extern inline int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges,
                                int index[], int edges[]);
extern inline int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[],
                                const int edges[], int *newrank);
extern inline int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                                      int neighbors[]);
extern inline int MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
                                            int *nneighbors);
extern inline int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);
extern inline int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          int recvcount, MPI_Datatype recvtype,
                                          MPI_Comm comm, MPI_Request *request);
extern inline int
MPI_Ineighbor_allgather_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          MPI_Count recvcount, MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           const int recvcounts[],
                                           const int displs[],
                                           MPI_Datatype recvtype, MPI_Comm comm,
                                           MPI_Request *request);
extern inline int MPI_Ineighbor_allgatherv_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
    MPI_Datatype recvtype, MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         int recvcount, MPI_Datatype recvtype,
                                         MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ineighbor_alltoall_c(const void *sendbuf,
                                           MPI_Count sendcount,
                                           MPI_Datatype sendtype, void *recvbuf,
                                           MPI_Count recvcount,
                                           MPI_Datatype recvtype, MPI_Comm comm,
                                           MPI_Request *request);
extern inline int
MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                        const int sdispls[], MPI_Datatype sendtype,
                        void *recvbuf, const int recvcounts[],
                        const int rdispls[], MPI_Datatype recvtype,
                        MPI_Comm comm, MPI_Request *request);
extern inline int
MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                          const MPI_Aint sdispls[], MPI_Datatype sendtype,
                          void *recvbuf, const MPI_Count recvcounts[],
                          const MPI_Aint rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request);
extern inline int MPI_Ineighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request);
extern inline int MPI_Ineighbor_alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request);
extern inline int MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Neighbor_allgather_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm);
extern inline int
MPI_Neighbor_allgather_init(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
                            MPI_Request *request);
extern inline int MPI_Neighbor_allgather_init_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm,
    MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          const int recvcounts[],
                                          const int displs[],
                                          MPI_Datatype recvtype, MPI_Comm comm);
extern inline int
MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const MPI_Count recvcounts[], const MPI_Aint displs[],
                          MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Neighbor_allgatherv_init(
    const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf,
    const int recvcounts[], const int displs[], MPI_Datatype recvtype,
    MPI_Comm comm, MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_allgatherv_init_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        int recvcount, MPI_Datatype recvtype,
                                        MPI_Comm comm);
extern inline int MPI_Neighbor_alltoall_c(const void *sendbuf,
                                          MPI_Count sendcount,
                                          MPI_Datatype sendtype, void *recvbuf,
                                          MPI_Count recvcount,
                                          MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Neighbor_alltoall_init(const void *sendbuf, int sendcount,
                                             MPI_Datatype sendtype,
                                             void *recvbuf, int recvcount,
                                             MPI_Datatype recvtype,
                                             MPI_Comm comm, MPI_Info info,
                                             MPI_Request *request);
extern inline int MPI_Neighbor_alltoall_init_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, MPI_Count recvcount, MPI_Datatype recvtype, MPI_Comm comm,
    MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_alltoallv(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm);
extern inline int MPI_Neighbor_alltoallv_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm);
extern inline int
MPI_Neighbor_alltoallv_init(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_alltoallv_init_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
    MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm);
extern inline int MPI_Neighbor_alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm);
extern inline int MPI_Neighbor_alltoallw_init(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Info info, MPI_Request *request);
extern inline int MPI_Neighbor_alltoallw_init_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Info info, MPI_Request *request);
extern inline int MPI_Topo_test(MPI_Comm comm, int *status);

// A.3.7 MPI Environmental Management C Bindings

extern inline int MPI_Add_error_class(int *errorclass);
extern inline int MPI_Add_error_code(int errorclass, int *errorcode);
extern inline int MPI_Add_error_string(int errorcode, const char *string);
extern inline int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr);
extern inline int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);
extern inline int
MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn,
                           MPI_Errhandler *errhandler);
extern inline int MPI_Comm_get_errhandler(MPI_Comm comm,
                                          MPI_Errhandler *errhandler);
extern inline int MPI_Comm_set_errhandler(MPI_Comm comm,
                                          MPI_Errhandler errhandler);
extern inline int MPI_Errhandler_free(MPI_Errhandler *errhandler);
extern inline int MPI_Error_class(int errorcode, int *errorclass);
extern inline int MPI_Error_string(int errorcode, char *string, int *resultlen);
extern inline int MPI_File_call_errhandler(MPI_File fh, int errorcode);
extern inline int
MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn,
                           MPI_Errhandler *errhandler);
extern inline int MPI_File_get_errhandler(MPI_File file,
                                          MPI_Errhandler *errhandler);
extern inline int MPI_File_set_errhandler(MPI_File file,
                                          MPI_Errhandler errhandler);
extern inline int MPI_Free_mem(void *base);
extern inline int MPI_Get_hw_resource_info(MPI_Info *hw_info);
extern inline int MPI_Get_library_version(char *version, int *resultlen);
extern inline int MPI_Get_processor_name(char *name, int *resultlen);
extern inline int MPI_Get_version(int *version, int *subversion);
extern inline int MPI_Remove_error_class(int errorclass);
extern inline int MPI_Remove_error_code(int errorcode);
extern inline int MPI_Remove_error_string(int errorcode);
extern inline int MPI_Session_call_errhandler(MPI_Session session,
                                              int errorcode);
extern inline int MPI_Session_create_errhandler(
    MPI_Session_errhandler_function *session_errhandler_fn,
    MPI_Errhandler *errhandler);
extern inline int MPI_Session_get_errhandler(MPI_Session session,
                                             MPI_Errhandler *errhandler);
extern inline int MPI_Session_set_errhandler(MPI_Session session,
                                             MPI_Errhandler errhandler);
extern inline int MPI_Win_call_errhandler(MPI_Win win, int errorcode);
extern inline int
MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn,
                          MPI_Errhandler *errhandler);
extern inline int MPI_Win_get_errhandler(MPI_Win win,
                                         MPI_Errhandler *errhandler);
extern inline int MPI_Win_set_errhandler(MPI_Win win,
                                         MPI_Errhandler errhandler);
double MPI_Wtick(void);
double MPI_Wtime(void);

// A.3.8 The Info Object C Bindings

extern inline int MPI_Info_create(MPI_Info *info);
extern inline int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info);
extern inline int MPI_Info_delete(MPI_Info info, const char *key);
extern inline int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo);
extern inline int MPI_Info_free(MPI_Info *info);
extern inline int MPI_Info_get_nkeys(MPI_Info info, int *nkeys);
extern inline int MPI_Info_get_nthkey(MPI_Info info, int n, char *key);
extern inline int MPI_Info_get_string(MPI_Info info, const char *key,
                                      int *buflen, char *value, int *flag);
extern inline int MPI_Info_set(MPI_Info info, const char *key,
                               const char *value);

// A.3.9 Process Creation and Management C Bindings

extern inline int MPI_Abort(MPI_Comm comm, int errorcode);
extern inline int MPI_Close_port(const char *port_name);
extern inline int MPI_Comm_accept(const char *port_name, MPI_Info info,
                                  int root, MPI_Comm comm, MPI_Comm *newcomm);
extern inline int MPI_Comm_connect(const char *port_name, MPI_Info info,
                                   int root, MPI_Comm comm, MPI_Comm *newcomm);
extern inline int MPI_Comm_disconnect(MPI_Comm *comm);
extern inline int MPI_Comm_get_parent(MPI_Comm *parent);
extern inline int MPI_Comm_join(int fd, MPI_Comm *intercomm);
extern inline int MPI_Comm_spawn(const char *command, char *argv[],
                                 int maxprocs, MPI_Info info, int root,
                                 MPI_Comm comm, MPI_Comm *intercomm,
                                 int array_of_errcodes[]);
extern inline int
MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                        char **array_of_argv[], const int array_of_maxprocs[],
                        const MPI_Info array_of_info[], int root, MPI_Comm comm,
                        MPI_Comm *intercomm, int array_of_errcodes[]);
extern inline int MPI_Finalize(void);
extern inline int MPI_Finalized(int *flag);
extern inline int MPI_Init(int *argc, char ***argv);
extern inline int MPI_Init_thread(int *argc, char ***argv, int required,
                                  int *provided);
extern inline int MPI_Initialized(int *flag);
extern inline int MPI_Is_thread_main(int *flag);
extern inline int MPI_Lookup_name(const char *service_name, MPI_Info info,
                                  char *port_name);
extern inline int MPI_Open_port(MPI_Info info, char *port_name);
extern inline int MPI_Publish_name(const char *service_name, MPI_Info info,
                                   const char *port_name);
extern inline int MPI_Query_thread(int *provided);
extern inline int MPI_Session_finalize(MPI_Session *session);
extern inline int MPI_Session_get_info(MPI_Session session,
                                       MPI_Info *info_used);
extern inline int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info,
                                           int n, int *pset_len,
                                           char *pset_name);
extern inline int MPI_Session_get_num_psets(MPI_Session session, MPI_Info info,
                                            int *npset_names);
extern inline int MPI_Session_get_pset_info(MPI_Session session,
                                            const char *pset_name,
                                            MPI_Info *info);
extern inline int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler,
                                   MPI_Session *session);
extern inline int MPI_Unpublish_name(const char *service_name, MPI_Info info,
                                     const char *port_name);

// A.3.10 One-Sided Communications C Bindings

extern inline int MPI_Accumulate(const void *origin_addr, int origin_count,
                                 MPI_Datatype origin_datatype, int target_rank,
                                 MPI_Aint target_disp, int target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win);
extern inline int
MPI_Accumulate_c(const void *origin_addr, MPI_Count origin_count,
                 MPI_Datatype origin_datatype, int target_rank,
                 MPI_Aint target_disp, MPI_Count target_count,
                 MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
extern inline int MPI_Compare_and_swap(const void *origin_addr,
                                       const void *compare_addr,
                                       void *result_addr, MPI_Datatype datatype,
                                       int target_rank, MPI_Aint target_disp,
                                       MPI_Win win);
extern inline int MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                                   MPI_Datatype datatype, int target_rank,
                                   MPI_Aint target_disp, MPI_Op op,
                                   MPI_Win win);
extern inline int MPI_Get(void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Win win);
extern inline int
MPI_Get_accumulate(const void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, void *result_addr,
                   int result_count, MPI_Datatype result_datatype,
                   int target_rank, MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);
extern inline int
MPI_Get_accumulate_c(const void *origin_addr, MPI_Count origin_count,
                     MPI_Datatype origin_datatype, void *result_addr,
                     MPI_Count result_count, MPI_Datatype result_datatype,
                     int target_rank, MPI_Aint target_disp,
                     MPI_Count target_count, MPI_Datatype target_datatype,
                     MPI_Op op, MPI_Win win);
extern inline int MPI_Get_c(void *origin_addr, MPI_Count origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Count target_count,
                            MPI_Datatype target_datatype, MPI_Win win);
extern inline int MPI_Put(const void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Win win);
extern inline int MPI_Put_c(const void *origin_addr, MPI_Count origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Count target_count,
                            MPI_Datatype target_datatype, MPI_Win win);
extern inline int MPI_Raccumulate(const void *origin_addr, int origin_count,
                                  MPI_Datatype origin_datatype, int target_rank,
                                  MPI_Aint target_disp, int target_count,
                                  MPI_Datatype target_datatype, MPI_Op op,
                                  MPI_Win win, MPI_Request *request);
extern inline int MPI_Raccumulate_c(const void *origin_addr,
                                    MPI_Count origin_count,
                                    MPI_Datatype origin_datatype,
                                    int target_rank, MPI_Aint target_disp,
                                    MPI_Count target_count,
                                    MPI_Datatype target_datatype, MPI_Op op,
                                    MPI_Win win, MPI_Request *request);
extern inline int MPI_Rget(void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win,
                           MPI_Request *request);
extern inline int MPI_Rget_accumulate(
    const void *origin_addr, int origin_count, MPI_Datatype origin_datatype,
    void *result_addr, int result_count, MPI_Datatype result_datatype,
    int target_rank, MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win, MPI_Request *request);
extern inline int
MPI_Rget_accumulate_c(const void *origin_addr, MPI_Count origin_count,
                      MPI_Datatype origin_datatype, void *result_addr,
                      MPI_Count result_count, MPI_Datatype result_datatype,
                      int target_rank, MPI_Aint target_disp,
                      MPI_Count target_count, MPI_Datatype target_datatype,
                      MPI_Op op, MPI_Win win, MPI_Request *request);
extern inline int MPI_Rget_c(void *origin_addr, MPI_Count origin_count,
                             MPI_Datatype origin_datatype, int target_rank,
                             MPI_Aint target_disp, MPI_Count target_count,
                             MPI_Datatype target_datatype, MPI_Win win,
                             MPI_Request *request);
extern inline int MPI_Rput(const void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Win win,
                           MPI_Request *request);
extern inline int MPI_Rput_c(const void *origin_addr, MPI_Count origin_count,
                             MPI_Datatype origin_datatype, int target_rank,
                             MPI_Aint target_disp, MPI_Count target_count,
                             MPI_Datatype target_datatype, MPI_Win win,
                             MPI_Request *request);
extern inline int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                                   MPI_Comm comm, void *baseptr, MPI_Win *win);
extern inline int MPI_Win_allocate_c(MPI_Aint size, MPI_Aint disp_unit,
                                     MPI_Info info, MPI_Comm comm,
                                     void *baseptr, MPI_Win *win);
extern inline int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit,
                                          MPI_Info info, MPI_Comm comm,
                                          void *baseptr, MPI_Win *win);
extern inline int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit,
                                            MPI_Info info, MPI_Comm comm,
                                            void *baseptr, MPI_Win *win);
extern inline int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size);
extern inline int MPI_Win_complete(MPI_Win win);
extern inline int MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                                 MPI_Info info, MPI_Comm comm, MPI_Win *win);
extern inline int MPI_Win_create_c(void *base, MPI_Aint size,
                                   MPI_Aint disp_unit, MPI_Info info,
                                   MPI_Comm comm, MPI_Win *win);
extern inline int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm,
                                         MPI_Win *win);
extern inline int MPI_Win_detach(MPI_Win win, const void *base);
extern inline int MPI_Win_fence(int assert, MPI_Win win);
extern inline int MPI_Win_flush(int rank, MPI_Win win);
extern inline int MPI_Win_flush_all(MPI_Win win);
extern inline int MPI_Win_flush_local(int rank, MPI_Win win);
extern inline int MPI_Win_flush_local_all(MPI_Win win);
extern inline int MPI_Win_free(MPI_Win *win);
extern inline int MPI_Win_get_group(MPI_Win win, MPI_Group *group);
extern inline int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used);
extern inline int MPI_Win_lock(int lock_type, int rank, int assert,
                               MPI_Win win);
extern inline int MPI_Win_lock_all(int assert, MPI_Win win);
extern inline int MPI_Win_post(MPI_Group group, int assert, MPI_Win win);
extern inline int MPI_Win_set_info(MPI_Win win, MPI_Info info);
extern inline int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                       int *disp_unit, void *baseptr);
extern inline int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size,
                                         MPI_Aint *disp_unit, void *baseptr);
extern inline int MPI_Win_start(MPI_Group group, int assert, MPI_Win win);
extern inline int MPI_Win_sync(MPI_Win win);
extern inline int MPI_Win_test(MPI_Win win, int *flag);
extern inline int MPI_Win_unlock(int rank, MPI_Win win);
extern inline int MPI_Win_unlock_all(MPI_Win win);
extern inline int MPI_Win_wait(MPI_Win win);

// A.3.11 External Interfaces C Bindings

extern inline int MPI_Grequest_complete(MPI_Request request);
extern inline int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                                     MPI_Grequest_free_function *free_fn,
                                     MPI_Grequest_cancel_function *cancel_fn,
                                     void *extra_state, MPI_Request *request);
extern inline int MPI_Status_set_cancelled(MPI_Status *status, int flag);
extern inline int MPI_Status_set_elements(MPI_Status *status,
                                          MPI_Datatype datatype, int count);
extern inline int MPI_Status_set_elements_c(MPI_Status *status,
                                            MPI_Datatype datatype,
                                            MPI_Count count);
extern inline int MPI_Status_set_error(MPI_Status *status, int err);
extern inline int MPI_Status_set_source(MPI_Status *status, int source);
extern inline int MPI_Status_set_tag(MPI_Status *status, int tag);

// A.3.12 I/O C Bindings

extern inline int MPI_File_close(MPI_File *fh);
extern inline int MPI_File_delete(const char *filename, MPI_Info info);
extern inline int MPI_File_get_amode(MPI_File fh, int *amode);
extern inline int MPI_File_get_atomicity(MPI_File fh, int *flag);
extern inline int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                           MPI_Offset *disp);
extern inline int MPI_File_get_group(MPI_File fh, MPI_Group *group);
extern inline int MPI_File_get_info(MPI_File fh, MPI_Info *info_used);
extern inline int MPI_File_get_position(MPI_File fh, MPI_Offset *offset);
extern inline int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset);
extern inline int MPI_File_get_size(MPI_File fh, MPI_Offset *size);
extern inline int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                           MPI_Aint *extent);
extern inline int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype,
                                             MPI_Count *extent);
extern inline int MPI_File_get_view(MPI_File fh, MPI_Offset *disp,
                                    MPI_Datatype *etype, MPI_Datatype *filetype,
                                    char *datarep);
extern inline int MPI_File_iread(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request);
extern inline int MPI_File_iread_all(MPI_File fh, void *buf, int count,
                                     MPI_Datatype datatype,
                                     MPI_Request *request);
extern inline int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count,
                                       MPI_Datatype datatype,
                                       MPI_Request *request);
extern inline int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                                    int count, MPI_Datatype datatype,
                                    MPI_Request *request);
extern inline int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset,
                                        void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request);
extern inline int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset,
                                          void *buf, MPI_Count count,
                                          MPI_Datatype datatype,
                                          MPI_Request *request);
extern inline int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf,
                                      MPI_Count count, MPI_Datatype datatype,
                                      MPI_Request *request);
extern inline int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Request *request);
extern inline int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Request *request);
extern inline int MPI_File_iread_shared_c(MPI_File fh, void *buf,
                                          MPI_Count count,
                                          MPI_Datatype datatype,
                                          MPI_Request *request);
extern inline int MPI_File_iwrite(MPI_File fh, const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request);
extern inline int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count,
                                      MPI_Datatype datatype,
                                      MPI_Request *request);
extern inline int MPI_File_iwrite_all_c(MPI_File fh, const void *buf,
                                        MPI_Count count, MPI_Datatype datatype,
                                        MPI_Request *request);
extern inline int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset,
                                     const void *buf, int count,
                                     MPI_Datatype datatype,
                                     MPI_Request *request);
extern inline int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset,
                                         const void *buf, int count,
                                         MPI_Datatype datatype,
                                         MPI_Request *request);
extern inline int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset,
                                           const void *buf, MPI_Count count,
                                           MPI_Datatype datatype,
                                           MPI_Request *request);
extern inline int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset,
                                       const void *buf, MPI_Count count,
                                       MPI_Datatype datatype,
                                       MPI_Request *request);
extern inline int MPI_File_iwrite_c(MPI_File fh, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Request *request);
extern inline int MPI_File_iwrite_shared(MPI_File fh, const void *buf,
                                         int count, MPI_Datatype datatype,
                                         MPI_Request *request);
extern inline int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf,
                                           MPI_Count count,
                                           MPI_Datatype datatype,
                                           MPI_Request *request);
extern inline int MPI_File_open(MPI_Comm comm, const char *filename, int amode,
                                MPI_Info info, MPI_File *fh);
extern inline int MPI_File_preallocate(MPI_File fh, MPI_Offset size);
extern inline int MPI_File_read(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status);
extern inline int MPI_File_read_all(MPI_File fh, void *buf, int count,
                                    MPI_Datatype datatype, MPI_Status *status);
extern inline int MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                          MPI_Datatype datatype);
extern inline int MPI_File_read_all_begin_c(MPI_File fh, void *buf,
                                            MPI_Count count,
                                            MPI_Datatype datatype);
extern inline int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count,
                                      MPI_Datatype datatype,
                                      MPI_Status *status);
extern inline int MPI_File_read_all_end(MPI_File fh, void *buf,
                                        MPI_Status *status);
extern inline int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                                   int count, MPI_Datatype datatype,
                                   MPI_Status *status);
extern inline int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
                                       void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status);
extern inline int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
                                             void *buf, int count,
                                             MPI_Datatype datatype);
extern inline int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset,
                                               void *buf, MPI_Count count,
                                               MPI_Datatype datatype);
extern inline int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset,
                                         void *buf, MPI_Count count,
                                         MPI_Datatype datatype,
                                         MPI_Status *status);
extern inline int MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                           MPI_Status *status);
extern inline int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf,
                                     MPI_Count count, MPI_Datatype datatype,
                                     MPI_Status *status);
extern inline int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count,
                                  MPI_Datatype datatype, MPI_Status *status);
extern inline int MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);
extern inline int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                              MPI_Datatype datatype);
extern inline int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf,
                                                MPI_Count count,
                                                MPI_Datatype datatype);
extern inline int MPI_File_read_ordered_c(MPI_File fh, void *buf,
                                          MPI_Count count,
                                          MPI_Datatype datatype,
                                          MPI_Status *status);
extern inline int MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                            MPI_Status *status);
extern inline int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype,
                                       MPI_Status *status);
extern inline int MPI_File_read_shared_c(MPI_File fh, void *buf,
                                         MPI_Count count, MPI_Datatype datatype,
                                         MPI_Status *status);
extern inline int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);
extern inline int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset,
                                       int whence);
extern inline int MPI_File_set_atomicity(MPI_File fh, int flag);
extern inline int MPI_File_set_info(MPI_File fh, MPI_Info info);
extern inline int MPI_File_set_size(MPI_File fh, MPI_Offset size);
extern inline int MPI_File_set_view(MPI_File fh, MPI_Offset disp,
                                    MPI_Datatype etype, MPI_Datatype filetype,
                                    const char *datarep, MPI_Info info);
extern inline int MPI_File_sync(MPI_File fh);
extern inline int MPI_File_write(MPI_File fh, const void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status);
extern inline int MPI_File_write_all(MPI_File fh, const void *buf, int count,
                                     MPI_Datatype datatype, MPI_Status *status);
extern inline int MPI_File_write_all_begin(MPI_File fh, const void *buf,
                                           int count, MPI_Datatype datatype);
extern inline int MPI_File_write_all_begin_c(MPI_File fh, const void *buf,
                                             MPI_Count count,
                                             MPI_Datatype datatype);
extern inline int MPI_File_write_all_c(MPI_File fh, const void *buf,
                                       MPI_Count count, MPI_Datatype datatype,
                                       MPI_Status *status);
extern inline int MPI_File_write_all_end(MPI_File fh, const void *buf,
                                         MPI_Status *status);
extern inline int MPI_File_write_at(MPI_File fh, MPI_Offset offset,
                                    const void *buf, int count,
                                    MPI_Datatype datatype, MPI_Status *status);
extern inline int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
                                        const void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);
extern inline int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                              const void *buf, int count,
                                              MPI_Datatype datatype);
extern inline int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset,
                                                const void *buf,
                                                MPI_Count count,
                                                MPI_Datatype datatype);
extern inline int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset,
                                          const void *buf, MPI_Count count,
                                          MPI_Datatype datatype,
                                          MPI_Status *status);
extern inline int MPI_File_write_at_all_end(MPI_File fh, const void *buf,
                                            MPI_Status *status);
extern inline int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset,
                                      const void *buf, MPI_Count count,
                                      MPI_Datatype datatype,
                                      MPI_Status *status);
extern inline int MPI_File_write_c(MPI_File fh, const void *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Status *status);
extern inline int MPI_File_write_ordered(MPI_File fh, const void *buf,
                                         int count, MPI_Datatype datatype,
                                         MPI_Status *status);
extern inline int MPI_File_write_ordered_begin(MPI_File fh, const void *buf,
                                               int count,
                                               MPI_Datatype datatype);
extern inline int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf,
                                                 MPI_Count count,
                                                 MPI_Datatype datatype);
extern inline int MPI_File_write_ordered_c(MPI_File fh, const void *buf,
                                           MPI_Count count,
                                           MPI_Datatype datatype,
                                           MPI_Status *status);
extern inline int MPI_File_write_ordered_end(MPI_File fh, const void *buf,
                                             MPI_Status *status);
extern inline int MPI_File_write_shared(MPI_File fh, const void *buf, int count,
                                        MPI_Datatype datatype,
                                        MPI_Status *status);
extern inline int MPI_File_write_shared_c(MPI_File fh, const void *buf,
                                          MPI_Count count,
                                          MPI_Datatype datatype,
                                          MPI_Status *status);
extern inline int MPI_Register_datarep(
    const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
extern inline int MPI_Register_datarep_c(
    const char *datarep, MPI_Datarep_conversion_function_c *read_conversion_fn,
    MPI_Datarep_conversion_function_c *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

// A.3.13 Language Bindings C Bindings

extern inline MPI_Fint MPI_Comm_c2f(MPI_Comm comm);
extern inline MPI_Comm MPI_Comm_f2c(MPI_Fint comm);
extern inline MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler errhandler);
extern inline MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint errhandler);
extern inline MPI_Fint MPI_File_c2f(MPI_File file);
extern inline MPI_File MPI_File_f2c(MPI_Fint file);
extern inline MPI_Fint MPI_Group_c2f(MPI_Group group);
extern inline MPI_Group MPI_Group_f2c(MPI_Fint group);
extern inline MPI_Fint MPI_Info_c2f(MPI_Info info);
extern inline MPI_Info MPI_Info_f2c(MPI_Fint info);
extern inline MPI_Fint MPI_Message_c2f(MPI_Message message);
extern inline MPI_Message MPI_Message_f2c(MPI_Fint message);
extern inline MPI_Fint MPI_Op_c2f(MPI_Op op);
extern inline MPI_Op MPI_Op_f2c(MPI_Fint op);
extern inline MPI_Fint MPI_Request_c2f(MPI_Request request);
extern inline MPI_Request MPI_Request_f2c(MPI_Fint request);
extern inline MPI_Fint MPI_Session_c2f(MPI_Session session);
extern inline MPI_Session MPI_Session_f2c(MPI_Fint session);
extern inline int MPI_Status_f082f(const MPI_F08_status *f08_status,
                                   MPI_Fint *f_status);
extern inline int MPI_Status_c2f(const MPI_Status *c_status,
                                 MPI_Fint *f_status);
extern inline int MPI_Status_c2f08(const MPI_Status *c_status,
                                   MPI_F08_status *f08_status);
extern inline int MPI_Status_f082c(const MPI_F08_status *f08_status,
                                   MPI_Status *c_status);
extern inline int MPI_Status_f2c(const MPI_Fint *f_status,
                                 MPI_Status *c_status);
extern inline int MPI_Status_f2f08(const MPI_Fint *f_status,
                                   MPI_F08_status *f08_status);
extern inline MPI_Fint MPI_Type_c2f(MPI_Datatype datatype);
extern inline int MPI_Type_create_f90_complex(int p, int r,
                                              MPI_Datatype *newtype);
extern inline int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype);
extern inline int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype);
extern inline MPI_Datatype MPI_Type_f2c(MPI_Fint datatype);
extern inline int MPI_Type_match_size(int typeclass, int size,
                                      MPI_Datatype *datatype);
extern inline MPI_Fint MPI_Win_c2f(MPI_Win win);
extern inline MPI_Win MPI_Win_f2c(MPI_Fint win);

// A.3.14 Tools / Profiling Interface C Bindings

extern inline int MPI_Pcontrol(const int level, ...);

// A.3.15 Tools / MPI Tool Information Interface C Bindings

extern inline int MPI_T_category_changed(int *update_number);
extern inline int MPI_T_category_get_categories(int cat_index, int len,
                                                int indices[]);
extern inline int MPI_T_category_get_cvars(int cat_index, int len,
                                           int indices[]);
extern inline int MPI_T_category_get_events(int cat_index, int len,
                                            int indices[]);
extern inline int MPI_T_category_get_index(const char *name, int *cat_index);
extern inline int MPI_T_category_get_info(int cat_index, char *name,
                                          int *name_len, char *desc,
                                          int *desc_len, int *num_cvars,
                                          int *num_pvars, int *num_categories);
extern inline int MPI_T_category_get_num(int *num_cat);
extern inline int MPI_T_category_get_num_events(int cat_index, int *num_events);
extern inline int MPI_T_category_get_pvars(int cat_index, int len,
                                           int indices[]);
extern inline int MPI_T_cvar_get_index(const char *name, int *cvar_index);
// extern inline int MPI_T_cvar_get_info(int cvar_index, char *name, int
// *name_len,
//                                       int *verbosity, MPI_Datatype *datatype,
//                                       MPI_T_enum *enumtype, char *desc,
//                                       int *desc_len, int *bind, int *scope);
extern inline int MPI_T_cvar_get_num(int *num_cvar);
// extern inline int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
//                                           MPI_T_cvar_handle *handle,
//                                           int *count);
// extern inline int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle);
// extern inline int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf);
// extern inline int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void
// *buf); extern inline int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num,
// char *name,
//                                       int *name_len);
// extern inline int MPI_T_enum_get_item(MPI_T_enum enumtype, int index,
//                                       int *value, char *name, int *name_len);
// extern inline int
// MPI_T_event_callback_get_info(MPI_T_event_registration event_registration,
//                               MPI_T_cb_safety cb_safety, MPI_Info
//                               *info_used);
// extern inline int
// MPI_T_event_callback_set_info(MPI_T_event_registration event_registration,
//                               MPI_T_cb_safety cb_safety, MPI_Info info);
// extern inline int MPI_T_event_copy(MPI_T_event_instance event_instance,
//                                    void *buffer);
extern inline int MPI_T_event_get_index(const char *name, int *event_index);
// extern inline int MPI_T_event_get_info(int event_index, char *name,
//                                        int *name_len, int *verbosity,
//                                        MPI_Datatype array_of_datatypes[],
//                                        MPI_Aint array_of_displacements[],
//                                        int *num_elements, MPI_T_enum
//                                        *enumtype, MPI_Info *info, char *desc,
//                                        int *desc_len, int *bind);
extern inline int MPI_T_event_get_num(int *num_events);
// extern inline int MPI_T_event_get_source(MPI_T_event_instance event_instance,
//                                          int *source_index);
// extern inline int MPI_T_event_get_timestamp(MPI_T_event_instance
// event_instance,
//                                             MPI_Count *event_timestamp);
// extern inline int
// MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
//                          MPI_T_event_registration *event_registration);
// extern inline int
// MPI_T_event_handle_free(MPI_T_event_registration event_registration,
//                         void *user_data,
//                         MPI_T_event_free_cb_function free_cb_function);
// extern inline int
// MPI_T_event_handle_get_info(MPI_T_event_registration event_registration,
//                             MPI_Info *info_used);
// extern inline int
// MPI_T_event_handle_set_info(MPI_T_event_registration event_registration,
//                             MPI_Info info);
// extern inline int MPI_T_event_read(MPI_T_event_instance event_instance,
//                                    int element_index, void *buffer);
// extern inline int MPI_T_event_register_callback(
//     MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety,
//     MPI_Info info, void *user_data, MPI_T_event_cb_function
//     event_cb_function);
// extern inline int MPI_T_event_set_dropped_handler(
//     MPI_T_event_registration event_registration,
//     MPI_T_event_dropped_cb_function dropped_cb_function);
extern inline int MPI_T_finalize(void);
extern inline int MPI_T_init_thread(int required, int *provided);
extern inline int MPI_T_pvar_get_index(const char *name, int var_class,
                                       int *pvar_index);
// extern inline int MPI_T_pvar_get_info(int pvar_index, char *name, int
// *name_len,
//                            int *verbosity, int *var_class,
//                            MPI_Datatype *datatype, MPI_T_enum
//                            *enumtype, char *desc, int *desc_len, int *bind,
//                            int *readonly, int *continuous, int *atomic);
extern inline int MPI_T_pvar_get_num(int *num_pvar);
// extern inline int MPI_T_pvar_handle_alloc(MPI_T_pvar_session pe_session, int
// pvar_index,
//                                void *obj_handle, MPI_T_pvar_handle
//                                *handle, int *count);
// extern inline int MPI_T_pvar_handle_free(MPI_T_pvar_session pe_session,
//                               MPI_T_pvar_handle *handle);
// extern inline int MPI_T_pvar_read(MPI_T_pvar_session pe_session,
//                        MPI_T_pvar_handle handle, void *buf);
// extern inline int MPI_T_pvar_readreset(MPI_T_pvar_session pe_session,
//                             MPI_T_pvar_handle handle, void *buf);
// extern inline int MPI_T_pvar_reset(MPI_T_pvar_session pe_session,
//                         MPI_T_pvar_handle handle);
// extern inline int MPI_T_pvar_session_create(MPI_T_pvar_session *pe_session);
// extern inline int MPI_T_pvar_session_free(MPI_T_pvar_session *pe_session);
// extern inline int MPI_T_pvar_start(MPI_T_pvar_session pe_session,
//                         MPI_T_pvar_handle handle);
// extern inline int MPI_T_pvar_stop(MPI_T_pvar_session pe_session,
//                        MPI_T_pvar_handle handle);
// extern inline int MPI_T_pvar_write(MPI_T_pvar_session pe_session,
//                         MPI_T_pvar_handle handle, const void *buf);
// extern inline int MPI_T_source_get_info(int source_index, char *name, int
// *name_len,
//                              char *desc, int *desc_len,
//                              MPI_T_source_order *ordering,
//                              MPI_Count *ticks_per_second,
//                              MPI_Count *max_ticks, MPI_Info *info);
extern inline int MPI_T_source_get_num(int *num_sources);
extern inline int MPI_T_source_get_timestamp(int source_index,
                                             MPI_Count *timestamp);

// A.3.16 Deprecated C Bindings

extern inline int MPI_Attr_delete(MPI_Comm comm, int keyval);
extern inline int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                               int *flag);
extern inline int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val);
extern inline int MPI_Get_elements_x(const MPI_Status *status,
                                     MPI_Datatype datatype, MPI_Count *count);
extern inline int MPI_Info_get(MPI_Info info, const char *key, int valuelen,
                               char *value, int *flag);
extern inline int MPI_Info_get_valuelen(MPI_Info info, const char *key,
                                        int *valuelen, int *flag);
extern inline int MPI_Keyval_create(MPI_Copy_function *copy_fn,
                                    MPI_Delete_function *delete_fn, int *keyval,
                                    void *extra_state);
extern inline int MPI_Keyval_free(int *keyval);
extern inline int MPI_Status_set_elements_x(MPI_Status *status,
                                            MPI_Datatype datatype,
                                            MPI_Count count);
extern inline int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                        MPI_Count *extent);
extern inline int MPI_Type_get_true_extent_x(MPI_Datatype datatype,
                                             MPI_Count *true_lb,
                                             MPI_Count *true_extent);
extern inline int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size);

// MPIX

extern inline int MPIX_Query_cuda_support(void);
extern inline int MPIX_Query_hip_support(void);
extern inline int MPIX_Query_rocm_support(void);
extern inline int MPIX_Query_ze_support(void);
