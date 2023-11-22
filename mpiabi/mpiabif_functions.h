!     Declare MPIABI functions

!     A.3 C Bindings

!     A.3.1 Point-to-Point Communication C Bindings

!     int MPIABI_Bsend(const void *buf, int count, MPIABI_Datatype datatype, int dest, int tag, MPIABI_Comm comm);
      external MPIABI_Bsend

! int MPIABI_Bsend_c(const void *buf, MPIABI_Count count,
!                    MPIABI_Datatype datatype, int dest, int tag,
!                    MPIABI_Comm comm);
! int MPIABI_Bsend_init(const void *buf, int count, MPIABI_Datatype datatype,
!                       int dest, int tag, MPIABI_Comm comm,
!                       MPIABI_Request *request);
! int MPIABI_Bsend_init_c(const void *buf, MPIABI_Count count,
!                         MPIABI_Datatype datatype, int dest, int tag,
!                         MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Buffer_attach(void *buffer, int size);
! int MPIABI_Buffer_attach_c(void *buffer, MPIABI_Count size);
! int MPIABI_Buffer_detach(void *buffer_addr, int *size);
! int MPIABI_Buffer_detach_c(void *buffer_addr, MPIABI_Count *size);
! int MPIABI_Buffer_flush(void);
! int MPIABI_Buffer_iflush(MPIABI_Request *request);
! int MPIABI_Cancel(MPIABI_Request *request);
! int MPIABI_Comm_attach_buffer(MPIABI_Comm comm, void *buffer, int size);
! int MPIABI_Comm_attach_buffer_c(MPIABI_Comm comm, void *buffer,
!                                 MPIABI_Count size);
! int MPIABI_Comm_detach_buffer(MPIABI_Comm comm, void *buffer_addr, int *size);
! int MPIABI_Comm_detach_buffer_c(MPIABI_Comm comm, void *buffer_addr,
!                                 MPIABI_Count *size);
! int MPIABI_Comm_flush_buffer(MPIABI_Comm comm);
! int MPIABI_Comm_iflush_buffer(MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Get_count(const MPIABI_Status *status, MPIABI_Datatype datatype,
!                      int *count);
! int MPIABI_Get_count_c(const MPIABI_Status *status, MPIABI_Datatype datatype,
!                        MPIABI_Count *count);
! int MPIABI_Ibsend(const void *buf, int count, MPIABI_Datatype datatype,
!                   int dest, int tag, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ibsend_c(const void *buf, MPIABI_Count count,
!                     MPIABI_Datatype datatype, int dest, int tag,
!                     MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Improbe(int source, int tag, MPIABI_Comm comm, int *flag,
!                    MPIABI_Message *message, MPIABI_Status *status);
! int MPIABI_Imrecv(void *buf, int count, MPIABI_Datatype datatype,
!                   MPIABI_Message *message, MPIABI_Request *request);
! int MPIABI_Imrecv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
!                     MPIABI_Message *message, MPIABI_Request *request);
! int MPIABI_Iprobe(int source, int tag, MPIABI_Comm comm, int *flag,
!                   MPIABI_Status *status);
! int MPIABI_Irecv(void *buf, int count, MPIABI_Datatype datatype, int source,
!                  int tag, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Irecv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
!                    int source, int tag, MPIABI_Comm comm,
!                    MPIABI_Request *request);
! int MPIABI_Irsend(const void *buf, int count, MPIABI_Datatype datatype,
!                   int dest, int tag, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Irsend_c(const void *buf, MPIABI_Count count,
!                     MPIABI_Datatype datatype, int dest, int tag,
!                     MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Isend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
!                  int tag, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Isend_c(const void *buf, MPIABI_Count count,
!                    MPIABI_Datatype datatype, int dest, int tag,
!                    MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Isendrecv(const void *sendbuf, int sendcount,
!                      MPIABI_Datatype sendtype, int dest, int sendtag,
!                      void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                      int source, int recvtag, MPIABI_Comm comm,
!                      MPIABI_Request *request);
! int MPIABI_Isendrecv_c(const void *sendbuf, MPIABI_Count sendcount,
!                        MPIABI_Datatype sendtype, int dest, int sendtag,
!                        void *recvbuf, MPIABI_Count recvcount,
!                        MPIABI_Datatype recvtype, int source, int recvtag,
!                        MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Isendrecv_replace(void *buf, int count, MPIABI_Datatype datatype,
!                              int dest, int sendtag, int source, int recvtag,
!                              MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Isendrecv_replace_c(void *buf, MPIABI_Count count,
!                                MPIABI_Datatype datatype, int dest, int sendtag,
!                                int source, int recvtag, MPIABI_Comm comm,
!                                MPIABI_Request *request);
! int MPIABI_Issend(const void *buf, int count, MPIABI_Datatype datatype,
!                   int dest, int tag, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Issend_c(const void *buf, MPIABI_Count count,
!                     MPIABI_Datatype datatype, int dest, int tag,
!                     MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Mprobe(int source, int tag, MPIABI_Comm comm,
!                   MPIABI_Message *message, MPIABI_Status *status);
! int MPIABI_Mrecv(void *buf, int count, MPIABI_Datatype datatype,
!                  MPIABI_Message *message, MPIABI_Status *status);
! int MPIABI_Mrecv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
!                    MPIABI_Message *message, MPIABI_Status *status);
! int MPIABI_Probe(int source, int tag, MPIABI_Comm comm, MPIABI_Status *status);
! int MPIABI_Recv(void *buf, int count, MPIABI_Datatype datatype, int source,
!                 int tag, MPIABI_Comm comm, MPIABI_Status *status);
! int MPIABI_Recv_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
!                   int source, int tag, MPIABI_Comm comm, MPIABI_Status *status);
! int MPIABI_Recv_init(void *buf, int count, MPIABI_Datatype datatype, int source,
!                      int tag, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Recv_init_c(void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
!                        int source, int tag, MPIABI_Comm comm,
!                        MPIABI_Request *request);
! int MPIABI_Request_free(MPIABI_Request *request);
! int MPIABI_Request_get_status(MPIABI_Request request, int *flag,
!                               MPIABI_Status *status);
! int MPIABI_Request_get_status_all(int count,
!                                   const MPIABI_Request array_of_requests[],
!                                   int *flag, MPIABI_Status array_of_statuses[]);
! int MPIABI_Request_get_status_any(int count,
!                                   const MPIABI_Request array_of_requests[],
!                                   int *index, int *flag, MPIABI_Status *status);
! int MPIABI_Request_get_status_some(int incount,
!                                    const MPIABI_Request array_of_requests[],
!                                    int *outcount, int array_of_indices[],
!                                    MPIABI_Status array_of_statuses[]);
! int MPIABI_Rsend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
!                  int tag, MPIABI_Comm comm);
! int MPIABI_Rsend_c(const void *buf, MPIABI_Count count,
!                    MPIABI_Datatype datatype, int dest, int tag,
!                    MPIABI_Comm comm);
! int MPIABI_Rsend_init(const void *buf, int count, MPIABI_Datatype datatype,
!                       int dest, int tag, MPIABI_Comm comm,
!                       MPIABI_Request *request);
! int MPIABI_Rsend_init_c(const void *buf, MPIABI_Count count,
!                         MPIABI_Datatype datatype, int dest, int tag,
!                         MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Send(const void *buf, int count, MPIABI_Datatype datatype, int dest,
!                 int tag, MPIABI_Comm comm);
! int MPIABI_Send_c(const void *buf, MPIABI_Count count, MPIABI_Datatype datatype,
!                   int dest, int tag, MPIABI_Comm comm);
! int MPIABI_Send_init(const void *buf, int count, MPIABI_Datatype datatype,
!                      int dest, int tag, MPIABI_Comm comm,
!                      MPIABI_Request *request);
! int MPIABI_Send_init_c(const void *buf, MPIABI_Count count,
!                        MPIABI_Datatype datatype, int dest, int tag,
!                        MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Sendrecv(const void *sendbuf, int sendcount,
!                     MPIABI_Datatype sendtype, int dest, int sendtag,
!                     void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                     int source, int recvtag, MPIABI_Comm comm,
!                     MPIABI_Status *status);
! int MPIABI_Sendrecv_c(const void *sendbuf, MPIABI_Count sendcount,
!                       MPIABI_Datatype sendtype, int dest, int sendtag,
!                       void *recvbuf, MPIABI_Count recvcount,
!                       MPIABI_Datatype recvtype, int source, int recvtag,
!                       MPIABI_Comm comm, MPIABI_Status *status);
! int MPIABI_Sendrecv_replace(void *buf, int count, MPIABI_Datatype datatype,
!                             int dest, int sendtag, int source, int recvtag,
!                             MPIABI_Comm comm, MPIABI_Status *status);
! int MPIABI_Sendrecv_replace_c(void *buf, MPIABI_Count count,
!                               MPIABI_Datatype datatype, int dest, int sendtag,
!                               int source, int recvtag, MPIABI_Comm comm,
!                               MPIABI_Status *status);
! int MPIABI_Session_attach_buffer(MPIABI_Session session, void *buffer,
!                                  int size);
! int MPIABI_Session_attach_buffer_c(MPIABI_Session session, void *buffer,
!                                    MPIABI_Count size);
! int MPIABI_Session_detach_buffer(MPIABI_Session session, void *buffer_addr,
!                                  int *size);
! int MPIABI_Session_detach_buffer_c(MPIABI_Session session, void *buffer_addr,
!                                    MPIABI_Count *size);
! int MPIABI_Session_flush_buffer(MPIABI_Session session);
! int MPIABI_Session_iflush_buffer(MPIABI_Session session,
!                                  MPIABI_Request *request);
! int MPIABI_Ssend(const void *buf, int count, MPIABI_Datatype datatype, int dest,
!                  int tag, MPIABI_Comm comm);
! int MPIABI_Ssend_c(const void *buf, MPIABI_Count count,
!                    MPIABI_Datatype datatype, int dest, int tag,
!                    MPIABI_Comm comm);
! int MPIABI_Ssend_init(const void *buf, int count, MPIABI_Datatype datatype,
!                       int dest, int tag, MPIABI_Comm comm,
!                       MPIABI_Request *request);
! int MPIABI_Ssend_init_c(const void *buf, MPIABI_Count count,
!                         MPIABI_Datatype datatype, int dest, int tag,
!                         MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Start(MPIABI_Request *request);
! int MPIABI_Startall(int count, MPIABI_Request array_of_requests[]);
! int MPIABI_Status_get_error(MPIABI_Status *status, int *err);
! int MPIABI_Status_get_source(MPIABI_Status *status, int *source);
! int MPIABI_Status_get_tag(MPIABI_Status *status, int *tag);
! int MPIABI_Test(MPIABI_Request *request, int *flag, MPIABI_Status *status);
! int MPIABI_Test_cancelled(const MPIABI_Status *status, int *flag);
! int MPIABI_Testall(int count, MPIABI_Request array_of_requests[], int *flag,
!                    MPIABI_Status array_of_statuses[]);
! int MPIABI_Testany(int count, MPIABI_Request array_of_requests[], int *index,
!                    int *flag, MPIABI_Status *status);
! int MPIABI_Testsome(int incount, MPIABI_Request array_of_requests[],
!                     int *outcount, int array_of_indices[],
!                     MPIABI_Status array_of_statuses[]);
! int MPIABI_Wait(MPIABI_Request *request, MPIABI_Status *status);
! int MPIABI_Waitall(int count, MPIABI_Request array_of_requests[],
!                    MPIABI_Status array_of_statuses[]);
! int MPIABI_Waitany(int count, MPIABI_Request array_of_requests[], int *index,
!                    MPIABI_Status *status);
! int MPIABI_Waitsome(int incount, MPIABI_Request array_of_requests[],
!                     int *outcount, int array_of_indices[],
!                     MPIABI_Status array_of_statuses[]);
! 
! // A.3.2 Partitioned Communication C Bindings
! 
! int MPIABI_Parrived(MPIABI_Request request, int partition, int *flag);
! int MPIABI_Pready(int partition, MPIABI_Request request);
! int MPIABI_Pready_list(int length, const int array_of_partitions[],
!                        MPIABI_Request request);
! int MPIABI_Pready_range(int partition_low, int partition_high,
!                         MPIABI_Request request);
! int MPIABI_Precv_init(void *buf, int partitions, MPIABI_Count count,
!                       MPIABI_Datatype datatype, int source, int tag,
!                       MPIABI_Comm comm, MPIABI_Info info,
!                       MPIABI_Request *request);
! int MPIABI_Psend_init(const void *buf, int partitions, MPIABI_Count count,
!                       MPIABI_Datatype datatype, int dest, int tag,
!                       MPIABI_Comm comm, MPIABI_Info info,
!                       MPIABI_Request *request);
! 
! // A.3.3 Datatypes C Bindings
! 
! MPIABI_Aint MPIABI_Aint_add(MPIABI_Aint base, MPIABI_Aint disp);
! MPIABI_Aint MPIABI_Aint_diff(MPIABI_Aint addr1, MPIABI_Aint addr2);
! int MPIABI_Get_address(const void *location, MPIABI_Aint *address);
! int MPIABI_Get_elements(const MPIABI_Status *status, MPIABI_Datatype datatype,
!                         int *count);
! int MPIABI_Get_elements_c(const MPIABI_Status *status, MPIABI_Datatype datatype,
!                           MPIABI_Count *count);
! int MPIABI_Pack(const void *inbuf, int incount, MPIABI_Datatype datatype,
!                 void *outbuf, int outsize, int *position, MPIABI_Comm comm);
! int MPIABI_Pack_c(const void *inbuf, MPIABI_Count incount,
!                   MPIABI_Datatype datatype, void *outbuf, MPIABI_Count outsize,
!                   MPIABI_Count *position, MPIABI_Comm comm);
! int MPIABI_Pack_external(const char datarep[], const void *inbuf, int incount,
!                          MPIABI_Datatype datatype, void *outbuf,
!                          MPIABI_Aint outsize, MPIABI_Aint *position);
! int MPIABI_Pack_external_c(const char datarep[], const void *inbuf,
!                            MPIABI_Count incount, MPIABI_Datatype datatype,
!                            void *outbuf, MPIABI_Count outsize,
!                            MPIABI_Count *position);
! int MPIABI_Pack_external_size(const char datarep[], MPIABI_Count incount,
!                               MPIABI_Datatype datatype, MPIABI_Aint *size);
! int MPIABI_Pack_external_size_c(const char datarep[], MPIABI_Count incount,
!                                 MPIABI_Datatype datatype, MPIABI_Count *size);
! int MPIABI_Pack_size_c(MPIABI_Count incount, MPIABI_Datatype datatype,
!                        MPIABI_Comm comm, MPIABI_Count *size);
! int MPIABI_Type_commit(MPIABI_Datatype *datatype);
! int MPIABI_Type_contiguous(int count, MPIABI_Datatype oldtype,
!                            MPIABI_Datatype *newtype);
! int MPIABI_Type_contiguous_c(MPIABI_Count count, MPIABI_Datatype oldtype,
!                              MPIABI_Datatype *newtype);
! int MPIABI_Type_create_darray(int size, int rank, int ndims,
!                               const int array_of_gsizes[],
!                               const int array_of_distribs[],
!                               const int array_of_dargs[],
!                               const int array_of_psizes[], int order,
!                               MPIABI_Datatype oldtype,
!                               MPIABI_Datatype *newtype);
! int MPIABI_Type_create_darray_c(int size, int rank, int ndims,
!                                 const MPIABI_Count array_of_gsizes[],
!                                 const int array_of_distribs[],
!                                 const int array_of_dargs[],
!                                 const int array_of_psizes[], int order,
!                                 MPIABI_Datatype oldtype,
!                                 MPIABI_Datatype *newtype);
! int MPIABI_Type_create_hindexed(int count, const int array_of_blocklengths[],
!                                 const MPIABI_Aint array_of_displacements[],
!                                 MPIABI_Datatype oldtype,
!                                 MPIABI_Datatype *newtype);
! int MPIABI_Type_create_hindexed_block(
!     int count, int blocklength, const MPIABI_Aint array_of_displacements[],
!     MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
! int MPIABI_Type_create_hindexed_block_c(
!     MPIABI_Count count, MPIABI_Count blocklength,
!     const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
!     MPIABI_Datatype *newtype);
! int MPIABI_Type_create_hindexed_c(MPIABI_Count count,
!                                   const MPIABI_Count array_of_blocklengths[],
!                                   const MPIABI_Count array_of_displacements[],
!                                   MPIABI_Datatype oldtype,
!                                   MPIABI_Datatype *newtype);
! int MPIABI_Type_create_hvector(int count, int blocklength, MPIABI_Aint stride,
!                                MPIABI_Datatype oldtype,
!                                MPIABI_Datatype *newtype);
! int MPIABI_Type_create_hvector_c(MPIABI_Count count, MPIABI_Count blocklength,
!                                  MPIABI_Count stride, MPIABI_Datatype oldtype,
!                                  MPIABI_Datatype *newtype);
! int MPIABI_Type_create_indexed_block(int count, int blocklength,
!                                      const int array_of_displacements[],
!                                      MPIABI_Datatype oldtype,
!                                      MPIABI_Datatype *newtype);
! int MPIABI_Type_create_indexed_block_c(
!     MPIABI_Count count, MPIABI_Count blocklength,
!     const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
!     MPIABI_Datatype *newtype);
! int MPIABI_Type_create_resized(MPIABI_Datatype oldtype, MPIABI_Aint lb,
!                                MPIABI_Aint extent, MPIABI_Datatype *newtype);
! int MPIABI_Type_create_resized_c(MPIABI_Datatype oldtype, MPIABI_Count lb,
!                                  MPIABI_Count extent, MPIABI_Datatype *newtype);
! int MPIABI_Type_create_struct(int count, const int array_of_blocklengths[],
!                               const MPIABI_Aint array_of_displacements[],
!                               const MPIABI_Datatype array_of_types[],
!                               MPIABI_Datatype *newtype);
! int MPIABI_Type_create_struct_c(MPIABI_Count count,
!                                 const MPIABI_Count array_of_blocklengths[],
!                                 const MPIABI_Count array_of_displacements[],
!                                 const MPIABI_Datatype array_of_types[],
!                                 MPIABI_Datatype *newtype);
! int MPIABI_Type_create_subarray(int ndims, const int array_of_sizes[],
!                                 const int array_of_subsizes[],
!                                 const int array_of_starts[], int order,
!                                 MPIABI_Datatype oldtype,
!                                 MPIABI_Datatype *newtype);
! int MPIABI_Type_create_subarray_c(int ndims,
!                                   const MPIABI_Count array_of_sizes[],
!                                   const MPIABI_Count array_of_subsizes[],
!                                   const MPIABI_Count array_of_starts[],
!                                   int order, MPIABI_Datatype oldtype,
!                                   MPIABI_Datatype *newtype);
! int MPIABI_Type_dup(MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
! int MPIABI_Type_free(MPIABI_Datatype *datatype);
! int MPIABI_Type_get_contents(MPIABI_Datatype datatype, int max_integers,
!                              int max_addresses, int max_datatypes,
!                              int array_of_integers[],
!                              MPIABI_Aint array_of_addresses[],
!                              MPIABI_Datatype array_of_datatypes[]);
! int MPIABI_Type_get_contents_c(
!     MPIABI_Datatype datatype, MPIABI_Count max_integers,
!     MPIABI_Count max_addresses, MPIABI_Count max_large_counts,
!     MPIABI_Count max_datatypes, int array_of_integers[],
!     MPIABI_Aint array_of_addresses[], MPIABI_Count array_of_large_counts[],
!     MPIABI_Datatype array_of_datatypes[]);
! int MPIABI_Type_get_envelope(MPIABI_Datatype datatype, int *num_integers,
!                              int *num_addresses, int *num_datatypes,
!                              int *combiner);
! int MPIABI_Type_get_envelope_c(MPIABI_Datatype datatype,
!                                MPIABI_Count *num_integers,
!                                MPIABI_Count *num_addresses,
!                                MPIABI_Count *num_large_counts,
!                                MPIABI_Count *num_datatypes, int *combiner);
! int MPIABI_Type_get_extent(MPIABI_Datatype datatype, MPIABI_Aint *lb,
!                            MPIABI_Aint *extent);
! int MPIABI_Type_get_extent_c(MPIABI_Datatype datatype, MPIABI_Count *lb,
!                              MPIABI_Count *extent);
! int MPIABI_Type_get_true_extent(MPIABI_Datatype datatype, MPIABI_Aint *true_lb,
!                                 MPIABI_Aint *true_extent);
! int MPIABI_Type_get_true_extent_c(MPIABI_Datatype datatype,
!                                   MPIABI_Count *true_lb,
!                                   MPIABI_Count *true_extent);
! int MPIABI_Type_indexed(int count, const int array_of_blocklengths[],
!                         const int array_of_displacements[],
!                         MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
! int MPIABI_Type_indexed_c(MPIABI_Count count,
!                           const MPIABI_Count array_of_blocklengths[],
!                           const MPIABI_Count array_of_displacements[],
!                           MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
! int MPIABI_Type_size(MPIABI_Datatype datatype, int *size);
! int MPIABI_Type_size_c(MPIABI_Datatype datatype, MPIABI_Count *size);
! int MPIABI_Type_vector(int count, int blocklength, int stride,
!                        MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
! int MPIABI_Type_vector_c(MPIABI_Count count, MPIABI_Count blocklength,
!                          MPIABI_Count stride, MPIABI_Datatype oldtype,
!                          MPIABI_Datatype *newtype);
! int MPIABI_Unpack(const void *inbuf, int insize, int *position, void *outbuf,
!                   int outcount, MPIABI_Datatype datatype, MPIABI_Comm comm);
! int MPIABI_Unpack_c(const void *inbuf, MPIABI_Count insize,
!                     MPIABI_Count *position, void *outbuf, MPIABI_Count outcount,
!                     MPIABI_Datatype datatype, MPIABI_Comm comm);
! int MPIABI_Unpack_external(const char datarep[], const void *inbuf,
!                            MPIABI_Aint insize, MPIABI_Aint *position,
!                            void *outbuf, int outcount,
!                            MPIABI_Datatype datatype);
! int MPIABI_Unpack_external_c(const char datarep[], const void *inbuf,
!                              MPIABI_Count insize, MPIABI_Count *position,
!                              void *outbuf, MPIABI_Count outcount,
!                              MPIABI_Datatype datatype);
! 
! // A.3.4 Collective Communication C Bindings
! 
! int MPIABI_Allgather(const void *sendbuf, int sendcount,
!                      MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                      MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Allgather_c(const void *sendbuf, MPIABI_Count sendcount,
!                        MPIABI_Datatype sendtype, void *recvbuf,
!                        MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                        MPIABI_Comm comm);
! int MPIABI_Allgather_init(const void *sendbuf, int sendcount,
!                           MPIABI_Datatype sendtype, void *recvbuf,
!                           int recvcount, MPIABI_Datatype recvtype,
!                           MPIABI_Comm comm, MPIABI_Info info,
!                           MPIABI_Request *request);
! int MPIABI_Allgather_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                             MPIABI_Datatype sendtype, void *recvbuf,
!                             MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                             MPIABI_Comm comm, MPIABI_Info info,
!                             MPIABI_Request *request);
! int MPIABI_Allgatherv(const void *sendbuf, int sendcount,
!                       MPIABI_Datatype sendtype, void *recvbuf,
!                       const int recvcounts[], const int displs[],
!                       MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Allgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
!                         MPIABI_Datatype sendtype, void *recvbuf,
!                         const MPIABI_Count recvcounts[],
!                         const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
!                         MPIABI_Comm comm);
! int MPIABI_Allgatherv_init(const void *sendbuf, int sendcount,
!                            MPIABI_Datatype sendtype, void *recvbuf,
!                            const int recvcounts[], const int displs[],
!                            MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                            MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Allgatherv_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                              MPIABI_Datatype sendtype, void *recvbuf,
!                              const MPIABI_Count recvcounts[],
!                              const MPIABI_Aint displs[],
!                              MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                              MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Allreduce(const void *sendbuf, void *recvbuf, int count,
!                      MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Allreduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                        MPIABI_Datatype datatype, MPIABI_Op op,
!                        MPIABI_Comm comm);
! int MPIABI_Allreduce_init(const void *sendbuf, void *recvbuf, int count,
!                           MPIABI_Datatype datatype, MPIABI_Op op,
!                           MPIABI_Comm comm, MPIABI_Info info,
!                           MPIABI_Request *request);
! int MPIABI_Allreduce_init_c(const void *sendbuf, void *recvbuf,
!                             MPIABI_Count count, MPIABI_Datatype datatype,
!                             MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info,
!                             MPIABI_Request *request);
! int MPIABI_Alltoall(const void *sendbuf, int sendcount,
!                     MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                     MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Alltoall_c(const void *sendbuf, MPIABI_Count sendcount,
!                       MPIABI_Datatype sendtype, void *recvbuf,
!                       MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                       MPIABI_Comm comm);
! int MPIABI_Alltoall_init(const void *sendbuf, int sendcount,
!                          MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                          MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                          MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Alltoall_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                            MPIABI_Datatype sendtype, void *recvbuf,
!                            MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                            MPIABI_Comm comm, MPIABI_Info info,
!                            MPIABI_Request *request);
! int MPIABI_Alltoallv(const void *sendbuf, const int sendcounts[],
!                      const int sdispls[], MPIABI_Datatype sendtype,
!                      void *recvbuf, const int recvcounts[], const int rdispls[],
!                      MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Alltoallv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                        const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype,
!                        void *recvbuf, const MPIABI_Count recvcounts[],
!                        const MPIABI_Aint rdispls[], MPIABI_Datatype recvtype,
!                        MPIABI_Comm comm);
! int MPIABI_Alltoallv_init(const void *sendbuf, const int sendcounts[],
!                           const int sdispls[], MPIABI_Datatype sendtype,
!                           void *recvbuf, const int recvcounts[],
!                           const int rdispls[], MPIABI_Datatype recvtype,
!                           MPIABI_Comm comm, MPIABI_Info info,
!                           MPIABI_Request *request);
! int MPIABI_Alltoallv_init_c(const void *sendbuf,
!                             const MPIABI_Count sendcounts[],
!                             const MPIABI_Aint sdispls[],
!                             MPIABI_Datatype sendtype, void *recvbuf,
!                             const MPIABI_Count recvcounts[],
!                             const MPIABI_Aint rdispls[],
!                             MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                             MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Alltoallw(const void *sendbuf, const int sendcounts[],
!                      const int sdispls[], const MPIABI_Datatype sendtypes[],
!                      void *recvbuf, const int recvcounts[], const int rdispls[],
!                      const MPIABI_Datatype recvtypes[], MPIABI_Comm comm);
! int MPIABI_Alltoallw_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                        const MPIABI_Aint sdispls[],
!                        const MPIABI_Datatype sendtypes[], void *recvbuf,
!                        const MPIABI_Count recvcounts[],
!                        const MPIABI_Aint rdispls[],
!                        const MPIABI_Datatype recvtypes[], MPIABI_Comm comm);
! int MPIABI_Alltoallw_init(const void *sendbuf, const int sendcounts[],
!                           const int sdispls[],
!                           const MPIABI_Datatype sendtypes[], void *recvbuf,
!                           const int recvcounts[], const int rdispls[],
!                           const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
!                           MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Alltoallw_init_c(const void *sendbuf,
!                             const MPIABI_Count sendcounts[],
!                             const MPIABI_Aint sdispls[],
!                             const MPIABI_Datatype sendtypes[], void *recvbuf,
!                             const MPIABI_Count recvcounts[],
!                             const MPIABI_Aint rdispls[],
!                             const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
!                             MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Barrier(MPIABI_Comm comm);
! int MPIABI_Barrier_init(MPIABI_Comm comm, MPIABI_Info info,
!                         MPIABI_Request *request);
! int MPIABI_Bcast(void *buffer, int count, MPIABI_Datatype datatype, int root,
!                  MPIABI_Comm comm);
! int MPIABI_Bcast_c(void *buffer, MPIABI_Count count, MPIABI_Datatype datatype,
!                    int root, MPIABI_Comm comm);
! int MPIABI_Bcast_init(void *buffer, int count, MPIABI_Datatype datatype,
!                       int root, MPIABI_Comm comm, MPIABI_Info info,
!                       MPIABI_Request *request);
! int MPIABI_Bcast_init_c(void *buffer, MPIABI_Count count,
!                         MPIABI_Datatype datatype, int root, MPIABI_Comm comm,
!                         MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Exscan(const void *sendbuf, void *recvbuf, int count,
!                   MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Exscan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                     MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Exscan_init(const void *sendbuf, void *recvbuf, int count,
!                        MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                        MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Exscan_init_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                          MPIABI_Datatype datatype, MPIABI_Op op,
!                          MPIABI_Comm comm, MPIABI_Info info,
!                          MPIABI_Request *request);
! int MPIABI_Gather(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
!                   void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                   int root, MPIABI_Comm comm);
! int MPIABI_Gather_c(const void *sendbuf, MPIABI_Count sendcount,
!                     MPIABI_Datatype sendtype, void *recvbuf,
!                     MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
!                     MPIABI_Comm comm);
! int MPIABI_Gather_init(const void *sendbuf, int sendcount,
!                        MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                        MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                        MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Gather_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                          MPIABI_Datatype sendtype, void *recvbuf,
!                          MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                          int root, MPIABI_Comm comm, MPIABI_Info info,
!                          MPIABI_Request *request);
! int MPIABI_Gatherv(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
!                    void *recvbuf, const int recvcounts[], const int displs[],
!                    MPIABI_Datatype recvtype, int root, MPIABI_Comm comm);
! int MPIABI_Gatherv_c(const void *sendbuf, MPIABI_Count sendcount,
!                      MPIABI_Datatype sendtype, void *recvbuf,
!                      const MPIABI_Count recvcounts[],
!                      const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
!                      int root, MPIABI_Comm comm);
! int MPIABI_Gatherv_init(const void *sendbuf, int sendcount,
!                         MPIABI_Datatype sendtype, void *recvbuf,
!                         const int recvcounts[], const int displs[],
!                         MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                         MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Gatherv_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                           MPIABI_Datatype sendtype, void *recvbuf,
!                           const MPIABI_Count recvcounts[],
!                           const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
!                           int root, MPIABI_Comm comm, MPIABI_Info info,
!                           MPIABI_Request *request);
! int MPIABI_Iallgather(const void *sendbuf, int sendcount,
!                       MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                       MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                       MPIABI_Request *request);
! int MPIABI_Iallgather_c(const void *sendbuf, MPIABI_Count sendcount,
!                         MPIABI_Datatype sendtype, void *recvbuf,
!                         MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                         MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Iallgatherv(const void *sendbuf, int sendcount,
!                        MPIABI_Datatype sendtype, void *recvbuf,
!                        const int recvcounts[], const int displs[],
!                        MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                        MPIABI_Request *request);
! int MPIABI_Iallgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
!                          MPIABI_Datatype sendtype, void *recvbuf,
!                          const MPIABI_Count recvcounts[],
!                          const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
!                          MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
!                       MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                       MPIABI_Request *request);
! int MPIABI_Iallreduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                         MPIABI_Datatype datatype, MPIABI_Op op,
!                         MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ialltoall(const void *sendbuf, int sendcount,
!                      MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                      MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                      MPIABI_Request *request);
! int MPIABI_Ialltoall_c(const void *sendbuf, MPIABI_Count sendcount,
!                        MPIABI_Datatype sendtype, void *recvbuf,
!                        MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                        MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ialltoallv(const void *sendbuf, const int sendcounts[],
!                       const int sdispls[], MPIABI_Datatype sendtype,
!                       void *recvbuf, const int recvcounts[],
!                       const int rdispls[], MPIABI_Datatype recvtype,
!                       MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ialltoallv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                         const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype,
!                         void *recvbuf, const MPIABI_Count recvcounts[],
!                         const MPIABI_Aint rdispls[], MPIABI_Datatype recvtype,
!                         MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ialltoallw(const void *sendbuf, const int sendcounts[],
!                       const int sdispls[], const MPIABI_Datatype sendtypes[],
!                       void *recvbuf, const int recvcounts[],
!                       const int rdispls[], const MPIABI_Datatype recvtypes[],
!                       MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ialltoallw_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                         const MPIABI_Aint sdispls[],
!                         const MPIABI_Datatype sendtypes[], void *recvbuf,
!                         const MPIABI_Count recvcounts[],
!                         const MPIABI_Aint rdispls[],
!                         const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
!                         MPIABI_Request *request);
! int MPIABI_Ibarrier(MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ibcast(void *buffer, int count, MPIABI_Datatype datatype, int root,
!                   MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ibcast_c(void *buffer, MPIABI_Count count, MPIABI_Datatype datatype,
!                     int root, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Iexscan(const void *sendbuf, void *recvbuf, int count,
!                    MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                    MPIABI_Request *request);
! int MPIABI_Iexscan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                      MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                      MPIABI_Request *request);
! int MPIABI_Igather(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
!                    void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                    int root, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Igather_c(const void *sendbuf, MPIABI_Count sendcount,
!                      MPIABI_Datatype sendtype, void *recvbuf,
!                      MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
!                      MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Igatherv(const void *sendbuf, int sendcount,
!                     MPIABI_Datatype sendtype, void *recvbuf,
!                     const int recvcounts[], const int displs[],
!                     MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                     MPIABI_Request *request);
! int MPIABI_Igatherv_c(const void *sendbuf, MPIABI_Count sendcount,
!                       MPIABI_Datatype sendtype, void *recvbuf,
!                       const MPIABI_Count recvcounts[],
!                       const MPIABI_Aint displs[], MPIABI_Datatype recvtype,
!                       int root, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ireduce(const void *sendbuf, void *recvbuf, int count,
!                    MPIABI_Datatype datatype, MPIABI_Op op, int root,
!                    MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ireduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                      MPIABI_Datatype datatype, MPIABI_Op op, int root,
!                      MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
!                            const int recvcounts[], MPIABI_Datatype datatype,
!                            MPIABI_Op op, MPIABI_Comm comm,
!                            MPIABI_Request *request);
! int MPIABI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
!                                  int recvcount, MPIABI_Datatype datatype,
!                                  MPIABI_Op op, MPIABI_Comm comm,
!                                  MPIABI_Request *request);
! int MPIABI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf,
!                                    MPIABI_Count recvcount,
!                                    MPIABI_Datatype datatype, MPIABI_Op op,
!                                    MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf,
!                              const MPIABI_Count recvcounts[],
!                              MPIABI_Datatype datatype, MPIABI_Op op,
!                              MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Iscan(const void *sendbuf, void *recvbuf, int count,
!                  MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                  MPIABI_Request *request);
! int MPIABI_Iscan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                    MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                    MPIABI_Request *request);
! int MPIABI_Iscatter(const void *sendbuf, int sendcount,
!                     MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                     MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                     MPIABI_Request *request);
! int MPIABI_Iscatter_c(const void *sendbuf, MPIABI_Count sendcount,
!                       MPIABI_Datatype sendtype, void *recvbuf,
!                       MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                       int root, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Iscatterv(const void *sendbuf, const int sendcounts[],
!                      const int displs[], MPIABI_Datatype sendtype,
!                      void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                      int root, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Iscatterv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                        const MPIABI_Aint displs[], MPIABI_Datatype sendtype,
!                        void *recvbuf, MPIABI_Count recvcount,
!                        MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                        MPIABI_Request *request);
! int MPIABI_Op_commutative(MPIABI_Op op, int *commute);
! int MPIABI_Op_create(MPIABI_User_function *user_fn, int commute, MPIABI_Op *op);
! int MPIABI_Op_create_c(MPIABI_User_function_c *user_fn, int commute,
!                        MPIABI_Op *op);
! int MPIABI_Op_free(MPIABI_Op *op);
! int MPIABI_Reduce(const void *sendbuf, void *recvbuf, int count,
!                   MPIABI_Datatype datatype, MPIABI_Op op, int root,
!                   MPIABI_Comm comm);
! int MPIABI_Reduce_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                     MPIABI_Datatype datatype, MPIABI_Op op, int root,
!                     MPIABI_Comm comm);
! int MPIABI_Reduce_init(const void *sendbuf, void *recvbuf, int count,
!                        MPIABI_Datatype datatype, MPIABI_Op op, int root,
!                        MPIABI_Comm comm, MPIABI_Info info,
!                        MPIABI_Request *request);
! int MPIABI_Reduce_init_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                          MPIABI_Datatype datatype, MPIABI_Op op, int root,
!                          MPIABI_Comm comm, MPIABI_Info info,
!                          MPIABI_Request *request);
! int MPIABI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
!                         MPIABI_Datatype datatype, MPIABI_Op op);
! int MPIABI_Reduce_local_c(const void *inbuf, void *inoutbuf, MPIABI_Count count,
!                           MPIABI_Datatype datatype, MPIABI_Op op);
! int MPIABI_Reduce_scatter(const void *sendbuf, void *recvbuf,
!                           const int recvcounts[], MPIABI_Datatype datatype,
!                           MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
!                                 int recvcount, MPIABI_Datatype datatype,
!                                 MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf,
!                                   MPIABI_Count recvcount,
!                                   MPIABI_Datatype datatype, MPIABI_Op op,
!                                   MPIABI_Comm comm);
! int MPIABI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf,
!                                      int recvcount, MPIABI_Datatype datatype,
!                                      MPIABI_Op op, MPIABI_Comm comm,
!                                      MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf,
!                                        MPIABI_Count recvcount,
!                                        MPIABI_Datatype datatype, MPIABI_Op op,
!                                        MPIABI_Comm comm, MPIABI_Info info,
!                                        MPIABI_Request *request);
! int MPIABI_Reduce_scatter_c(const void *sendbuf, void *recvbuf,
!                             const MPIABI_Count recvcounts[],
!                             MPIABI_Datatype datatype, MPIABI_Op op,
!                             MPIABI_Comm comm);
! int MPIABI_Reduce_scatter_init(const void *sendbuf, void *recvbuf,
!                                const int recvcounts[], MPIABI_Datatype datatype,
!                                MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info,
!                                MPIABI_Request *request);
! int MPIABI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf,
!                                  const MPIABI_Count recvcounts[],
!                                  MPIABI_Datatype datatype, MPIABI_Op op,
!                                  MPIABI_Comm comm, MPIABI_Info info,
!                                  MPIABI_Request *request);
! int MPIABI_Scan(const void *sendbuf, void *recvbuf, int count,
!                 MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Scan_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                   MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm);
! int MPIABI_Scan_init(const void *sendbuf, void *recvbuf, int count,
!                      MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                      MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Scan_init_c(const void *sendbuf, void *recvbuf, MPIABI_Count count,
!                        MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm,
!                        MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Scatter(const void *sendbuf, int sendcount, MPIABI_Datatype sendtype,
!                    void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                    int root, MPIABI_Comm comm);
! int MPIABI_Scatter_c(const void *sendbuf, MPIABI_Count sendcount,
!                      MPIABI_Datatype sendtype, void *recvbuf,
!                      MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
!                      MPIABI_Comm comm);
! int MPIABI_Scatter_init(const void *sendbuf, int sendcount,
!                         MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
!                         MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                         MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Scatter_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                           MPIABI_Datatype sendtype, void *recvbuf,
!                           MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                           int root, MPIABI_Comm comm, MPIABI_Info info,
!                           MPIABI_Request *request);
! int MPIABI_Scatterv(const void *sendbuf, const int sendcounts[],
!                     const int displs[], MPIABI_Datatype sendtype, void *recvbuf,
!                     int recvcount, MPIABI_Datatype recvtype, int root,
!                     MPIABI_Comm comm);
! int MPIABI_Scatterv_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                       const MPIABI_Aint displs[], MPIABI_Datatype sendtype,
!                       void *recvbuf, MPIABI_Count recvcount,
!                       MPIABI_Datatype recvtype, int root, MPIABI_Comm comm);
! int MPIABI_Scatterv_init(const void *sendbuf, const int sendcounts[],
!                          const int displs[], MPIABI_Datatype sendtype,
!                          void *recvbuf, int recvcount, MPIABI_Datatype recvtype,
!                          int root, MPIABI_Comm comm, MPIABI_Info info,
!                          MPIABI_Request *request);
! int MPIABI_Scatterv_init_c(const void *sendbuf, const MPIABI_Count sendcounts[],
!                            const MPIABI_Aint displs[], MPIABI_Datatype sendtype,
!                            void *recvbuf, MPIABI_Count recvcount,
!                            MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
!                            MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Type_get_value_index(MPIABI_Datatype value_type,
!                                 MPIABI_Datatype index_type,
!                                 MPIABI_Datatype *pair_type);
! 
! // A.3.5 Groups, Contexts, Communicators, and Caching C Bindings
! 
! int MPIABI_Comm_compare(MPIABI_Comm comm1, MPIABI_Comm comm2, int *result);
! int MPIABI_Comm_create(MPIABI_Comm comm, MPIABI_Group group,
!                        MPIABI_Comm *newcomm);
! int MPIABI_Comm_create_from_group(MPIABI_Group group, const char *stringtag,
!                                   MPIABI_Info info,
!                                   MPIABI_Errhandler errhandler,
!                                   MPIABI_Comm *newcomm);
! int MPIABI_Comm_create_group(MPIABI_Comm comm, MPIABI_Group group, int tag,
!                              MPIABI_Comm *newcomm);
! int MPIABI_Comm_create_keyval(
!     MPIABI_Comm_copy_attr_function *comm_copy_attr_fn,
!     MPIABI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
!     void *extra_state);
! int MPIABI_Comm_delete_attr(MPIABI_Comm comm, int comm_keyval);
! int MPIABI_Comm_dup(MPIABI_Comm comm, MPIABI_Comm *newcomm);
! int MPIABI_Comm_dup_with_info(MPIABI_Comm comm, MPIABI_Info info,
!                               MPIABI_Comm *newcomm);
! int MPIABI_Comm_free(MPIABI_Comm *comm);
! int MPIABI_Comm_get_name(MPIABI_Comm comm, char *comm_name, int *resultlen);
! int MPIABI_Comm_free_keyval(int *comm_keyval);
! int MPIABI_Comm_get_attr(MPIABI_Comm comm, int comm_keyval, void *attribute_val,
!                          int *flag);
! int MPIABI_Comm_get_info(MPIABI_Comm comm, MPIABI_Info *info_used);
! int MPIABI_Comm_group(MPIABI_Comm comm, MPIABI_Group *group);
! int MPIABI_Comm_idup(MPIABI_Comm comm, MPIABI_Comm *newcomm,
!                      MPIABI_Request *request);
! int MPIABI_Comm_idup_with_info(MPIABI_Comm comm, MPIABI_Info info,
!                                MPIABI_Comm *newcomm, MPIABI_Request *request);
! int MPIABI_Comm_rank(MPIABI_Comm comm, int *rank);
! int MPIABI_Comm_remote_group(MPIABI_Comm comm, MPIABI_Group *group);
! int MPIABI_Comm_remote_size(MPIABI_Comm comm, int *size);
! int MPIABI_Comm_set_attr(MPIABI_Comm comm, int comm_keyval,
!                          void *attribute_val);
! int MPIABI_Comm_set_info(MPIABI_Comm comm, MPIABI_Info info);
! int MPIABI_Comm_set_name(MPIABI_Comm comm, const char *comm_name);
! int MPIABI_Comm_size(MPIABI_Comm comm, int *size);
! int MPIABI_Comm_split(MPIABI_Comm comm, int color, int key,
!                       MPIABI_Comm *newcomm);
! int MPIABI_Group_free(MPIABI_Group *group);
! int MPIABI_Comm_split_type(MPIABI_Comm comm, int split_type, int key,
!                            MPIABI_Info info, MPIABI_Comm *newcomm);
! int MPIABI_Comm_test_inter(MPIABI_Comm comm, int *flag);
! int MPIABI_Group_compare(MPIABI_Group group1, MPIABI_Group group2, int *result);
! int MPIABI_Group_difference(MPIABI_Group group1, MPIABI_Group group2,
!                             MPIABI_Group *newgroup);
! int MPIABI_Group_excl(MPIABI_Group group, int n, const int ranks[],
!                       MPIABI_Group *newgroup);
! int MPIABI_Group_from_session_pset(MPIABI_Session session,
!                                    const char *pset_name,
!                                    MPIABI_Group *newgroup);
! int MPIABI_Group_incl(MPIABI_Group group, int n, const int ranks[],
!                       MPIABI_Group *newgroup);
! int MPIABI_Group_intersection(MPIABI_Group group1, MPIABI_Group group2,
!                               MPIABI_Group *newgroup);
! int MPIABI_Group_range_excl(MPIABI_Group group, int n, int ranges[][3],
!                             MPIABI_Group *newgroup);
! int MPIABI_Group_range_incl(MPIABI_Group group, int n, int ranges[][3],
!                             MPIABI_Group *newgroup);
! int MPIABI_Group_rank(MPIABI_Group group, int *rank);
! int MPIABI_Group_size(MPIABI_Group group, int *size);
! int MPIABI_Group_translate_ranks(MPIABI_Group group1, int n, const int ranks1[],
!                                  MPIABI_Group group2, int ranks2[]);
! int MPIABI_Group_union(MPIABI_Group group1, MPIABI_Group group2,
!                        MPIABI_Group *newgroup);
! int MPIABI_Intercomm_create(MPIABI_Comm local_comm, int local_leader,
!                             MPIABI_Comm peer_comm, int remote_leader, int tag,
!                             MPIABI_Comm *newintercomm);
! int MPIABI_Intercomm_create_from_groups(
!     MPIABI_Group local_group, int local_leader, MPIABI_Group remote_group,
!     int remote_leader, const char *stringtag, MPIABI_Info info,
!     MPIABI_Errhandler errhandler, MPIABI_Comm *newintercomm);
! int MPIABI_Intercomm_merge(MPIABI_Comm intercomm, int high,
!                            MPIABI_Comm *newintracomm);
! int MPIABI_Type_create_keyval(
!     MPIABI_Type_copy_attr_function *type_copy_attr_fn,
!     MPIABI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
!     void *extra_state);
! int MPIABI_Type_delete_attr(MPIABI_Datatype datatype, int type_keyval);
! int MPIABI_Type_free_keyval(int *type_keyval);
! int MPIABI_Type_get_attr(MPIABI_Datatype datatype, int type_keyval,
!                          void *attribute_val, int *flag);
! int MPIABI_Type_get_name(MPIABI_Datatype datatype, char *type_name,
!                          int *resultlen);
! int MPIABI_Type_set_attr(MPIABI_Datatype datatype, int type_keyval,
!                          void *attribute_val);
! int MPIABI_Type_set_name(MPIABI_Datatype datatype, const char *type_name);
! int MPIABI_Win_create_keyval(
!     MPIABI_Win_copy_attr_function *win_copy_attr_fn,
!     MPIABI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
!     void *extra_state);
! int MPIABI_Win_delete_attr(MPIABI_Win win, int win_keyval);
! int MPIABI_Win_free_keyval(int *win_keyval);
! int MPIABI_Win_get_attr(MPIABI_Win win, int win_keyval, void *attribute_val,
!                         int *flag);
! int MPIABI_Win_get_name(MPIABI_Win win, char *win_name, int *resultlen);
! int MPIABI_Win_set_attr(MPIABI_Win win, int win_keyval, void *attribute_val);
! int MPIABI_Win_set_name(MPIABI_Win win, const char *win_name);
! 
! // A.3.6 Virtual Topologies for MPI Processes C Bindings
! 
! int MPIABI_Cart_coords(MPIABI_Comm comm, int rank, int maxdims, int coords[]);
! int MPIABI_Cart_create(MPIABI_Comm comm_old, int ndims, const int dims[],
!                        const int periods[], int reorder,
!                        MPIABI_Comm *comm_cart);
! int MPIABI_Cart_get(MPIABI_Comm comm, int maxdims, int dims[], int periods[],
!                     int coords[]);
! int MPIABI_Cart_map(MPIABI_Comm comm, int ndims, const int dims[],
!                     const int periods[], int *newrank);
! int MPIABI_Cart_rank(MPIABI_Comm comm, const int coords[], int *rank);
! int MPIABI_Cart_shift(MPIABI_Comm comm, int direction, int disp,
!                       int *rank_source, int *rank_dest);
! int MPIABI_Cart_sub(MPIABI_Comm comm, const int remain_dims[],
!                     MPIABI_Comm *newcomm);
! int MPIABI_Cartdim_get(MPIABI_Comm comm, int *ndims);
! int MPIABI_Dims_create(int nnodes, int ndims, int dims[]);
! int MPIABI_Dist_graph_create(MPIABI_Comm comm_old, int n, const int sources[],
!                              const int degrees[], const int destinations[],
!                              const int weights[], MPIABI_Info info, int reorder,
!                              MPIABI_Comm *comm_dist_graph);
! int MPIABI_Dist_graph_create_adjacent(MPIABI_Comm comm_old, int indegree,
!                                       const int sources[],
!                                       const int sourceweights[], int outdegree,
!                                       const int destinations[],
!                                       const int destweights[], MPIABI_Info info,
!                                       int reorder,
!                                       MPIABI_Comm *comm_dist_graph);
! int MPIABI_Dist_graph_neighbors(MPIABI_Comm comm, int maxindegree,
!                                 int sources[], int sourceweights[],
!                                 int maxoutdegree, int destinations[],
!                                 int destweights[]);
! int MPIABI_Dist_graph_neighbors_count(MPIABI_Comm comm, int *indegree,
!                                       int *outdegree, int *weighted);
! int MPIABI_Graph_create(MPIABI_Comm comm_old, int nnodes, const int index[],
!                         const int edges[], int reorder,
!                         MPIABI_Comm *comm_graph);
! int MPIABI_Graph_get(MPIABI_Comm comm, int maxindex, int maxedges, int index[],
!                      int edges[]);
! int MPIABI_Graph_map(MPIABI_Comm comm, int nnodes, const int index[],
!                      const int edges[], int *newrank);
! int MPIABI_Graph_neighbors(MPIABI_Comm comm, int rank, int maxneighbors,
!                            int neighbors[]);
! int MPIABI_Graph_neighbors_count(MPIABI_Comm comm, int rank, int *nneighbors);
! int MPIABI_Graphdims_get(MPIABI_Comm comm, int *nnodes, int *nedges);
! int MPIABI_Ineighbor_allgather(const void *sendbuf, int sendcount,
!                                MPIABI_Datatype sendtype, void *recvbuf,
!                                int recvcount, MPIABI_Datatype recvtype,
!                                MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ineighbor_allgather_c(const void *sendbuf, MPIABI_Count sendcount,
!                                  MPIABI_Datatype sendtype, void *recvbuf,
!                                  MPIABI_Count recvcount,
!                                  MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                  MPIABI_Request *request);
! int MPIABI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
!                                 MPIABI_Datatype sendtype, void *recvbuf,
!                                 const int recvcounts[], const int displs[],
!                                 MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                 MPIABI_Request *request);
! int MPIABI_Ineighbor_allgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
!                                   MPIABI_Datatype sendtype, void *recvbuf,
!                                   const MPIABI_Count recvcounts[],
!                                   const MPIABI_Aint displs[],
!                                   MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                   MPIABI_Request *request);
! int MPIABI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
!                               MPIABI_Datatype sendtype, void *recvbuf,
!                               int recvcount, MPIABI_Datatype recvtype,
!                               MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ineighbor_alltoall_c(const void *sendbuf, MPIABI_Count sendcount,
!                                 MPIABI_Datatype sendtype, void *recvbuf,
!                                 MPIABI_Count recvcount,
!                                 MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                 MPIABI_Request *request);
! int MPIABI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
!                                const int sdispls[], MPIABI_Datatype sendtype,
!                                void *recvbuf, const int recvcounts[],
!                                const int rdispls[], MPIABI_Datatype recvtype,
!                                MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ineighbor_alltoallv_c(
!     const void *sendbuf, const MPIABI_Count sendcounts[],
!     const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
!     const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
!     MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[],
!                                const MPIABI_Aint sdispls[],
!                                const MPIABI_Datatype sendtypes[], void *recvbuf,
!                                const int recvcounts[],
!                                const MPIABI_Aint rdispls[],
!                                const MPIABI_Datatype recvtypes[],
!                                MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Ineighbor_alltoallw_c(const void *sendbuf,
!                                  const MPIABI_Count sendcounts[],
!                                  const MPIABI_Aint sdispls[],
!                                  const MPIABI_Datatype sendtypes[],
!                                  void *recvbuf, const MPIABI_Count recvcounts[],
!                                  const MPIABI_Aint rdispls[],
!                                  const MPIABI_Datatype recvtypes[],
!                                  MPIABI_Comm comm, MPIABI_Request *request);
! int MPIABI_Neighbor_allgather(const void *sendbuf, int sendcount,
!                               MPIABI_Datatype sendtype, void *recvbuf,
!                               int recvcount, MPIABI_Datatype recvtype,
!                               MPIABI_Comm comm);
! int MPIABI_Neighbor_allgather_c(const void *sendbuf, MPIABI_Count sendcount,
!                                 MPIABI_Datatype sendtype, void *recvbuf,
!                                 MPIABI_Count recvcount,
!                                 MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Neighbor_allgather_init(const void *sendbuf, int sendcount,
!                                    MPIABI_Datatype sendtype, void *recvbuf,
!                                    int recvcount, MPIABI_Datatype recvtype,
!                                    MPIABI_Comm comm, MPIABI_Info info,
!                                    MPIABI_Request *request);
! int MPIABI_Neighbor_allgather_init_c(const void *sendbuf,
!                                      MPIABI_Count sendcount,
!                                      MPIABI_Datatype sendtype, void *recvbuf,
!                                      MPIABI_Count recvcount,
!                                      MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                      MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
!                                MPIABI_Datatype sendtype, void *recvbuf,
!                                const int recvcounts[], const int displs[],
!                                MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Neighbor_allgatherv_c(const void *sendbuf, MPIABI_Count sendcount,
!                                  MPIABI_Datatype sendtype, void *recvbuf,
!                                  const MPIABI_Count recvcounts[],
!                                  const MPIABI_Aint displs[],
!                                  MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount,
!                                     MPIABI_Datatype sendtype, void *recvbuf,
!                                     const int recvcounts[], const int displs[],
!                                     MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                     MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Neighbor_allgatherv_init_c(
!     const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
!     void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint displs[],
!     MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Info info,
!     MPIABI_Request *request);
! int MPIABI_Neighbor_alltoall(const void *sendbuf, int sendcount,
!                              MPIABI_Datatype sendtype, void *recvbuf,
!                              int recvcount, MPIABI_Datatype recvtype,
!                              MPIABI_Comm comm);
! int MPIABI_Neighbor_alltoall_c(const void *sendbuf, MPIABI_Count sendcount,
!                                MPIABI_Datatype sendtype, void *recvbuf,
!                                MPIABI_Count recvcount, MPIABI_Datatype recvtype,
!                                MPIABI_Comm comm);
! int MPIABI_Neighbor_alltoall_init(const void *sendbuf, int sendcount,
!                                   MPIABI_Datatype sendtype, void *recvbuf,
!                                   int recvcount, MPIABI_Datatype recvtype,
!                                   MPIABI_Comm comm, MPIABI_Info info,
!                                   MPIABI_Request *request);
! int MPIABI_Neighbor_alltoall_init_c(const void *sendbuf, MPIABI_Count sendcount,
!                                     MPIABI_Datatype sendtype, void *recvbuf,
!                                     MPIABI_Count recvcount,
!                                     MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                     MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
!                               const int sdispls[], MPIABI_Datatype sendtype,
!                               void *recvbuf, const int recvcounts[],
!                               const int rdispls[], MPIABI_Datatype recvtype,
!                               MPIABI_Comm comm);
! int MPIABI_Neighbor_alltoallv_c(const void *sendbuf,
!                                 const MPIABI_Count sendcounts[],
!                                 const MPIABI_Aint sdispls[],
!                                 MPIABI_Datatype sendtype, void *recvbuf,
!                                 const MPIABI_Count recvcounts[],
!                                 const MPIABI_Aint rdispls[],
!                                 MPIABI_Datatype recvtype, MPIABI_Comm comm);
! int MPIABI_Neighbor_alltoallv_init(const void *sendbuf, const int sendcounts[],
!                                    const int sdispls[],
!                                    MPIABI_Datatype sendtype, void *recvbuf,
!                                    const int recvcounts[], const int rdispls[],
!                                    MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                    MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Neighbor_alltoallv_init_c(const void *sendbuf,
!                                      const MPIABI_Count sendcounts[],
!                                      const MPIABI_Aint sdispls[],
!                                      MPIABI_Datatype sendtype, void *recvbuf,
!                                      const MPIABI_Count recvcounts[],
!                                      const MPIABI_Aint rdispls[],
!                                      MPIABI_Datatype recvtype, MPIABI_Comm comm,
!                                      MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Neighbor_alltoallw(const void *sendbuf, const int sendcounts[],
!                               const MPIABI_Aint sdispls[],
!                               const MPIABI_Datatype sendtypes[], void *recvbuf,
!                               const int recvcounts[],
!                               const MPIABI_Aint rdispls[],
!                               const MPIABI_Datatype recvtypes[],
!                               MPIABI_Comm comm);
! int MPIABI_Neighbor_alltoallw_c(
!     const void *sendbuf, const MPIABI_Count sendcounts[],
!     const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
!     void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
!     const MPIABI_Datatype recvtypes[], MPIABI_Comm comm);
! int MPIABI_Neighbor_alltoallw_init(
!     const void *sendbuf, const int sendcounts[], const MPIABI_Aint sdispls[],
!     const MPIABI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
!     const MPIABI_Aint rdispls[], const MPIABI_Datatype recvtypes[],
!     MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
! int MPIABI_Neighbor_alltoallw_init_c(
!     const void *sendbuf, const MPIABI_Count sendcounts[],
!     const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
!     void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
!     const MPIABI_Datatype recvtypes[], MPIABI_Comm comm, MPIABI_Info info,
!     MPIABI_Request *request);
! int MPIABI_Topo_test(MPIABI_Comm comm, int *status);
! 
! // A.3.7 MPI Environmental Management C Bindings
! 
! int MPIABI_Add_error_class(int *errorclass);
! int MPIABI_Add_error_code(int errorclass, int *errorcode);
! int MPIABI_Add_error_string(int errorcode, const char *string);
! int MPIABI_Alloc_mem(MPIABI_Aint size, MPIABI_Info info, void *baseptr);
! int MPIABI_Comm_call_errhandler(MPIABI_Comm comm, int errorcode);
! int MPIABI_Comm_create_errhandler(
!     MPIABI_Comm_errhandler_function *comm_errhandler_fn,
!     MPIABI_Errhandler *errhandler);
! int MPIABI_Comm_get_errhandler(MPIABI_Comm comm, MPIABI_Errhandler *errhandler);
! int MPIABI_Comm_set_errhandler(MPIABI_Comm comm, MPIABI_Errhandler errhandler);
! int MPIABI_Errhandler_free(MPIABI_Errhandler *errhandler);
! int MPIABI_Error_class(int errorcode, int *errorclass);
! int MPIABI_Error_string(int errorcode, char *string, int *resultlen);
! int MPIABI_File_call_errhandler(MPIABI_File fh, int errorcode);
! int MPIABI_File_create_errhandler(
!     MPIABI_File_errhandler_function *file_errhandler_fn,
!     MPIABI_Errhandler *errhandler);
! int MPIABI_File_get_errhandler(MPIABI_File file, MPIABI_Errhandler *errhandler);
! int MPIABI_File_set_errhandler(MPIABI_File file, MPIABI_Errhandler errhandler);
! int MPIABI_Free_mem(void *base);
! int MPIABI_Get_hw_resource_info(MPIABI_Info *hw_info);
! int MPIABI_Get_library_version(char *version, int *resultlen);
! int MPIABI_Get_processor_name(char *name, int *resultlen);
! int MPIABI_Get_version(int *version, int *subversion);
! int MPIABI_Remove_error_class(int errorclass);
! int MPIABI_Remove_error_code(int errorcode);
! int MPIABI_Remove_error_string(int errorcode);
! int MPIABI_Session_call_errhandler(MPIABI_Session session, int errorcode);
! int MPIABI_Session_create_errhandler(
!     MPIABI_Session_errhandler_function *session_errhandler_fn,
!     MPIABI_Errhandler *errhandler);
! int MPIABI_Session_get_errhandler(MPIABI_Session session,
!                                   MPIABI_Errhandler *errhandler);
! int MPIABI_Session_set_errhandler(MPIABI_Session session,
!                                   MPIABI_Errhandler errhandler);
! int MPIABI_Win_call_errhandler(MPIABI_Win win, int errorcode);
! int MPIABI_Win_create_errhandler(
!     MPIABI_Win_errhandler_function *win_errhandler_fn,
!     MPIABI_Errhandler *errhandler);
! int MPIABI_Win_get_errhandler(MPIABI_Win win, MPIABI_Errhandler *errhandler);
! int MPIABI_Win_set_errhandler(MPIABI_Win win, MPIABI_Errhandler errhandler);
! double MPIABI_Wtick(void);
! double MPIABI_Wtime(void);
! 
! // A.3.8 The Info Object C Bindings
! 
! int MPIABI_Info_create(MPIABI_Info *info);
! int MPIABI_Info_create_env(int argc, char *argv[], MPIABI_Info *info);
! int MPIABI_Info_delete(MPIABI_Info info, const char *key);
! int MPIABI_Info_dup(MPIABI_Info info, MPIABI_Info *newinfo);
! int MPIABI_Info_free(MPIABI_Info *info);
! int MPIABI_Info_get_nkeys(MPIABI_Info info, int *nkeys);
! int MPIABI_Info_get_nthkey(MPIABI_Info info, int n, char *key);
! int MPIABI_Info_get_string(MPIABI_Info info, const char *key, int *buflen,
!                            char *value, int *flag);
! int MPIABI_Info_set(MPIABI_Info info, const char *key, const char *value);
! 
! // A.3.9 Process Creation and Management C Bindings
! 
! int MPIABI_Abort(MPIABI_Comm comm, int errorcode);
! int MPIABI_Close_port(const char *port_name);
! int MPIABI_Comm_accept(const char *port_name, MPIABI_Info info, int root,
!                        MPIABI_Comm comm, MPIABI_Comm *newcomm);
! int MPIABI_Comm_connect(const char *port_name, MPIABI_Info info, int root,
!                         MPIABI_Comm comm, MPIABI_Comm *newcomm);
! int MPIABI_Comm_disconnect(MPIABI_Comm *comm);
! int MPIABI_Comm_get_parent(MPIABI_Comm *parent);
! int MPIABI_Comm_join(int fd, MPIABI_Comm *intercomm);
! int MPIABI_Comm_spawn(const char *command, char *argv[], int maxprocs,
!                       MPIABI_Info info, int root, MPIABI_Comm comm,
!                       MPIABI_Comm *intercomm, int array_of_errcodes[]);
! int MPIABI_Comm_spawn_multiple(int count, char *array_of_commands[],
!                                char **array_of_argv[],
!                                const int array_of_maxprocs[],
!                                const MPIABI_Info array_of_info[], int root,
!                                MPIABI_Comm comm, MPIABI_Comm *intercomm,
!                                int array_of_errcodes[]);
! int MPIABI_Finalize(void);
! int MPIABI_Finalized(int *flag);
! int MPIABI_Init(int *argc, char ***argv);
! int MPIABI_Init_thread(int *argc, char ***argv, int required, int *provided);
! int MPIABI_Initialized(int *flag);
! int MPIABI_Is_thread_main(int *flag);
! int MPIABI_Lookup_name(const char *service_name, MPIABI_Info info,
!                        char *port_name);
! int MPIABI_Open_port(MPIABI_Info info, char *port_name);
! int MPIABI_Publish_name(const char *service_name, MPIABI_Info info,
!                         const char *port_name);
! int MPIABI_Query_thread(int *provided);
! int MPIABI_Session_finalize(MPIABI_Session *session);
! int MPIABI_Session_get_info(MPIABI_Session session, MPIABI_Info *info_used);
! int MPIABI_Session_get_nth_pset(MPIABI_Session session, MPIABI_Info info, int n,
!                                 int *pset_len, char *pset_name);
! int MPIABI_Session_get_num_psets(MPIABI_Session session, MPIABI_Info info,
!                                  int *npset_names);
! int MPIABI_Session_get_pset_info(MPIABI_Session session, const char *pset_name,
!                                  MPIABI_Info *info);
! int MPIABI_Session_init(MPIABI_Info info, MPIABI_Errhandler errhandler,
!                         MPIABI_Session *session);
! int MPIABI_Unpublish_name(const char *service_name, MPIABI_Info info,
!                           const char *port_name);
! 
! // A.3.10 One-Sided Communications C Bindings
! 
! int MPIABI_Accumulate(const void *origin_addr, int origin_count,
!                       MPIABI_Datatype origin_datatype, int target_rank,
!                       MPIABI_Aint target_disp, int target_count,
!                       MPIABI_Datatype target_datatype, MPIABI_Op op,
!                       MPIABI_Win win);
! int MPIABI_Accumulate_c(const void *origin_addr, MPIABI_Count origin_count,
!                         MPIABI_Datatype origin_datatype, int target_rank,
!                         MPIABI_Aint target_disp, MPIABI_Count target_count,
!                         MPIABI_Datatype target_datatype, MPIABI_Op op,
!                         MPIABI_Win win);
! int MPIABI_Compare_and_swap(const void *origin_addr, const void *compare_addr,
!                             void *result_addr, MPIABI_Datatype datatype,
!                             int target_rank, MPIABI_Aint target_disp,
!                             MPIABI_Win win);
! int MPIABI_Fetch_and_op(const void *origin_addr, void *result_addr,
!                         MPIABI_Datatype datatype, int target_rank,
!                         MPIABI_Aint target_disp, MPIABI_Op op, MPIABI_Win win);
! int MPIABI_Get(void *origin_addr, int origin_count,
!                MPIABI_Datatype origin_datatype, int target_rank,
!                MPIABI_Aint target_disp, int target_count,
!                MPIABI_Datatype target_datatype, MPIABI_Win win);
! int MPIABI_Get_accumulate(const void *origin_addr, int origin_count,
!                           MPIABI_Datatype origin_datatype, void *result_addr,
!                           int result_count, MPIABI_Datatype result_datatype,
!                           int target_rank, MPIABI_Aint target_disp,
!                           int target_count, MPIABI_Datatype target_datatype,
!                           MPIABI_Op op, MPIABI_Win win);
! int MPIABI_Get_accumulate_c(const void *origin_addr, MPIABI_Count origin_count,
!                             MPIABI_Datatype origin_datatype, void *result_addr,
!                             MPIABI_Count result_count,
!                             MPIABI_Datatype result_datatype, int target_rank,
!                             MPIABI_Aint target_disp, MPIABI_Count target_count,
!                             MPIABI_Datatype target_datatype, MPIABI_Op op,
!                             MPIABI_Win win);
! int MPIABI_Get_c(void *origin_addr, MPIABI_Count origin_count,
!                  MPIABI_Datatype origin_datatype, int target_rank,
!                  MPIABI_Aint target_disp, MPIABI_Count target_count,
!                  MPIABI_Datatype target_datatype, MPIABI_Win win);
! int MPIABI_Put(const void *origin_addr, int origin_count,
!                MPIABI_Datatype origin_datatype, int target_rank,
!                MPIABI_Aint target_disp, int target_count,
!                MPIABI_Datatype target_datatype, MPIABI_Win win);
! int MPIABI_Put_c(const void *origin_addr, MPIABI_Count origin_count,
!                  MPIABI_Datatype origin_datatype, int target_rank,
!                  MPIABI_Aint target_disp, MPIABI_Count target_count,
!                  MPIABI_Datatype target_datatype, MPIABI_Win win);
! int MPIABI_Raccumulate(const void *origin_addr, int origin_count,
!                        MPIABI_Datatype origin_datatype, int target_rank,
!                        MPIABI_Aint target_disp, int target_count,
!                        MPIABI_Datatype target_datatype, MPIABI_Op op,
!                        MPIABI_Win win, MPIABI_Request *request);
! int MPIABI_Raccumulate_c(const void *origin_addr, MPIABI_Count origin_count,
!                          MPIABI_Datatype origin_datatype, int target_rank,
!                          MPIABI_Aint target_disp, MPIABI_Count target_count,
!                          MPIABI_Datatype target_datatype, MPIABI_Op op,
!                          MPIABI_Win win, MPIABI_Request *request);
! int MPIABI_Rget(void *origin_addr, int origin_count,
!                 MPIABI_Datatype origin_datatype, int target_rank,
!                 MPIABI_Aint target_disp, int target_count,
!                 MPIABI_Datatype target_datatype, MPIABI_Win win,
!                 MPIABI_Request *request);
! int MPIABI_Rget_accumulate(const void *origin_addr, int origin_count,
!                            MPIABI_Datatype origin_datatype, void *result_addr,
!                            int result_count, MPIABI_Datatype result_datatype,
!                            int target_rank, MPIABI_Aint target_disp,
!                            int target_count, MPIABI_Datatype target_datatype,
!                            MPIABI_Op op, MPIABI_Win win,
!                            MPIABI_Request *request);
! int MPIABI_Rget_accumulate_c(const void *origin_addr, MPIABI_Count origin_count,
!                              MPIABI_Datatype origin_datatype, void *result_addr,
!                              MPIABI_Count result_count,
!                              MPIABI_Datatype result_datatype, int target_rank,
!                              MPIABI_Aint target_disp, MPIABI_Count target_count,
!                              MPIABI_Datatype target_datatype, MPIABI_Op op,
!                              MPIABI_Win win, MPIABI_Request *request);
! int MPIABI_Rget_c(void *origin_addr, MPIABI_Count origin_count,
!                   MPIABI_Datatype origin_datatype, int target_rank,
!                   MPIABI_Aint target_disp, MPIABI_Count target_count,
!                   MPIABI_Datatype target_datatype, MPIABI_Win win,
!                   MPIABI_Request *request);
! int MPIABI_Rput(const void *origin_addr, int origin_count,
!                 MPIABI_Datatype origin_datatype, int target_rank,
!                 MPIABI_Aint target_disp, int target_count,
!                 MPIABI_Datatype target_datatype, MPIABI_Win win,
!                 MPIABI_Request *request);
! int MPIABI_Rput_c(const void *origin_addr, MPIABI_Count origin_count,
!                   MPIABI_Datatype origin_datatype, int target_rank,
!                   MPIABI_Aint target_disp, MPIABI_Count target_count,
!                   MPIABI_Datatype target_datatype, MPIABI_Win win,
!                   MPIABI_Request *request);
! int MPIABI_Win_allocate(MPIABI_Aint size, int disp_unit, MPIABI_Info info,
!                         MPIABI_Comm comm, void *baseptr, MPIABI_Win *win);
! int MPIABI_Win_allocate_c(MPIABI_Aint size, MPIABI_Aint disp_unit,
!                           MPIABI_Info info, MPIABI_Comm comm, void *baseptr,
!                           MPIABI_Win *win);
! int MPIABI_Win_allocate_shared(MPIABI_Aint size, int disp_unit,
!                                MPIABI_Info info, MPIABI_Comm comm,
!                                void *baseptr, MPIABI_Win *win);
! int MPIABI_Win_allocate_shared_c(MPIABI_Aint size, MPIABI_Aint disp_unit,
!                                  MPIABI_Info info, MPIABI_Comm comm,
!                                  void *baseptr, MPIABI_Win *win);
! int MPIABI_Win_attach(MPIABI_Win win, void *base, MPIABI_Aint size);
! int MPIABI_Win_complete(MPIABI_Win win);
! int MPIABI_Win_create(void *base, MPIABI_Aint size, int disp_unit,
!                       MPIABI_Info info, MPIABI_Comm comm, MPIABI_Win *win);
! int MPIABI_Win_create_c(void *base, MPIABI_Aint size, MPIABI_Aint disp_unit,
!                         MPIABI_Info info, MPIABI_Comm comm, MPIABI_Win *win);
! int MPIABI_Win_create_dynamic(MPIABI_Info info, MPIABI_Comm comm,
!                               MPIABI_Win *win);
! int MPIABI_Win_detach(MPIABI_Win win, const void *base);
! int MPIABI_Win_fence(int assert, MPIABI_Win win);
! int MPIABI_Win_flush(int rank, MPIABI_Win win);
! int MPIABI_Win_flush_all(MPIABI_Win win);
! int MPIABI_Win_flush_local(int rank, MPIABI_Win win);
! int MPIABI_Win_flush_local_all(MPIABI_Win win);
! int MPIABI_Win_free(MPIABI_Win *win);
! int MPIABI_Win_get_group(MPIABI_Win win, MPIABI_Group *group);
! int MPIABI_Win_get_info(MPIABI_Win win, MPIABI_Info *info_used);
! int MPIABI_Win_lock(int lock_type, int rank, int assert, MPIABI_Win win);
! int MPIABI_Win_lock_all(int assert, MPIABI_Win win);
! int MPIABI_Win_post(MPIABI_Group group, int assert, MPIABI_Win win);
! int MPIABI_Win_set_info(MPIABI_Win win, MPIABI_Info info);
! int MPIABI_Win_shared_query(MPIABI_Win win, int rank, MPIABI_Aint *size,
!                             int *disp_unit, void *baseptr);
! int MPIABI_Win_shared_query_c(MPIABI_Win win, int rank, MPIABI_Aint *size,
!                               MPIABI_Aint *disp_unit, void *baseptr);
! int MPIABI_Win_start(MPIABI_Group group, int assert, MPIABI_Win win);
! int MPIABI_Win_sync(MPIABI_Win win);
! int MPIABI_Win_test(MPIABI_Win win, int *flag);
! int MPIABI_Win_unlock(int rank, MPIABI_Win win);
! int MPIABI_Win_unlock_all(MPIABI_Win win);
! int MPIABI_Win_wait(MPIABI_Win win);
! 
! // A.3.11 External Interfaces C Bindings
! 
! int MPIABI_Grequest_complete(MPIABI_Request request);
! int MPIABI_Grequest_start(MPIABI_Grequest_query_function *query_fn,
!                           MPIABI_Grequest_free_function *free_fn,
!                           MPIABI_Grequest_cancel_function *cancel_fn,
!                           void *extra_state, MPIABI_Request *request);
! int MPIABI_Status_set_cancelled(MPIABI_Status *status, int flag);
! int MPIABI_Status_set_elements(MPIABI_Status *status, MPIABI_Datatype datatype,
!                                int count);
! int MPIABI_Status_set_elements_c(MPIABI_Status *status,
!                                  MPIABI_Datatype datatype, MPIABI_Count count);
! int MPIABI_Status_set_error(MPIABI_Status *status, int err);
! int MPIABI_Status_set_source(MPIABI_Status *status, int source);
! int MPIABI_Status_set_tag(MPIABI_Status *status, int tag);
! 
! // A.3.12 I/O C Bindings
! 
! int MPIABI_File_close(MPIABI_File *fh);
! int MPIABI_File_delete(const char *filename, MPIABI_Info info);
! int MPIABI_File_get_amode(MPIABI_File fh, int *amode);
! int MPIABI_File_get_atomicity(MPIABI_File fh, int *flag);
! int MPIABI_File_get_byte_offset(MPIABI_File fh, MPIABI_Offset offset,
!                                 MPIABI_Offset *disp);
! int MPIABI_File_get_group(MPIABI_File fh, MPIABI_Group *group);
! int MPIABI_File_get_info(MPIABI_File fh, MPIABI_Info *info_used);
! int MPIABI_File_get_position(MPIABI_File fh, MPIABI_Offset *offset);
! int MPIABI_File_get_position_shared(MPIABI_File fh, MPIABI_Offset *offset);
! int MPIABI_File_get_size(MPIABI_File fh, MPIABI_Offset *size);
! int MPIABI_File_get_type_extent(MPIABI_File fh, MPIABI_Datatype datatype,
!                                 MPIABI_Aint *extent);
! int MPIABI_File_get_type_extent_c(MPIABI_File fh, MPIABI_Datatype datatype,
!                                   MPIABI_Count *extent);
! int MPIABI_File_get_view(MPIABI_File fh, MPIABI_Offset *disp,
!                          MPIABI_Datatype *etype, MPIABI_Datatype *filetype,
!                          char *datarep);
! int MPIABI_File_iread(MPIABI_File fh, void *buf, int count,
!                       MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iread_all(MPIABI_File fh, void *buf, int count,
!                           MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iread_all_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                             MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iread_at(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                          int count, MPIABI_Datatype datatype,
!                          MPIABI_Request *request);
! int MPIABI_File_iread_at_all(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                              int count, MPIABI_Datatype datatype,
!                              MPIABI_Request *request);
! int MPIABI_File_iread_at_all_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                                MPIABI_Count count, MPIABI_Datatype datatype,
!                                MPIABI_Request *request);
! int MPIABI_File_iread_at_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                            MPIABI_Count count, MPIABI_Datatype datatype,
!                            MPIABI_Request *request);
! int MPIABI_File_iread_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                         MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iread_shared(MPIABI_File fh, void *buf, int count,
!                              MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iread_shared_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                                MPIABI_Datatype datatype,
!                                MPIABI_Request *request);
! int MPIABI_File_iwrite(MPIABI_File fh, const void *buf, int count,
!                        MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iwrite_all(MPIABI_File fh, const void *buf, int count,
!                            MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iwrite_all_c(MPIABI_File fh, const void *buf,
!                              MPIABI_Count count, MPIABI_Datatype datatype,
!                              MPIABI_Request *request);
! int MPIABI_File_iwrite_at(MPIABI_File fh, MPIABI_Offset offset, const void *buf,
!                           int count, MPIABI_Datatype datatype,
!                           MPIABI_Request *request);
! int MPIABI_File_iwrite_at_all(MPIABI_File fh, MPIABI_Offset offset,
!                               const void *buf, int count,
!                               MPIABI_Datatype datatype,
!                               MPIABI_Request *request);
! int MPIABI_File_iwrite_at_all_c(MPIABI_File fh, MPIABI_Offset offset,
!                                 const void *buf, MPIABI_Count count,
!                                 MPIABI_Datatype datatype,
!                                 MPIABI_Request *request);
! int MPIABI_File_iwrite_at_c(MPIABI_File fh, MPIABI_Offset offset,
!                             const void *buf, MPIABI_Count count,
!                             MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iwrite_c(MPIABI_File fh, const void *buf, MPIABI_Count count,
!                          MPIABI_Datatype datatype, MPIABI_Request *request);
! int MPIABI_File_iwrite_shared(MPIABI_File fh, const void *buf, int count,
!                               MPIABI_Datatype datatype,
!                               MPIABI_Request *request);
! int MPIABI_File_iwrite_shared_c(MPIABI_File fh, const void *buf,
!                                 MPIABI_Count count, MPIABI_Datatype datatype,
!                                 MPIABI_Request *request);
! int MPIABI_File_open(MPIABI_Comm comm, const char *filename, int amode,
!                      MPIABI_Info info, MPIABI_File *fh);
! int MPIABI_File_preallocate(MPIABI_File fh, MPIABI_Offset size);
! int MPIABI_File_read(MPIABI_File fh, void *buf, int count,
!                      MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_all(MPIABI_File fh, void *buf, int count,
!                          MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_all_begin(MPIABI_File fh, void *buf, int count,
!                                MPIABI_Datatype datatype);
! int MPIABI_File_read_all_begin_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                                  MPIABI_Datatype datatype);
! int MPIABI_File_read_all_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                            MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_all_end(MPIABI_File fh, void *buf, MPIABI_Status *status);
! int MPIABI_File_read_at(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                         int count, MPIABI_Datatype datatype,
!                         MPIABI_Status *status);
! int MPIABI_File_read_at_all(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                             int count, MPIABI_Datatype datatype,
!                             MPIABI_Status *status);
! int MPIABI_File_read_at_all_begin(MPIABI_File fh, MPIABI_Offset offset,
!                                   void *buf, int count,
!                                   MPIABI_Datatype datatype);
! int MPIABI_File_read_at_all_begin_c(MPIABI_File fh, MPIABI_Offset offset,
!                                     void *buf, MPIABI_Count count,
!                                     MPIABI_Datatype datatype);
! int MPIABI_File_read_at_all_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                               MPIABI_Count count, MPIABI_Datatype datatype,
!                               MPIABI_Status *status);
! int MPIABI_File_read_at_all_end(MPIABI_File fh, void *buf,
!                                 MPIABI_Status *status);
! int MPIABI_File_read_at_c(MPIABI_File fh, MPIABI_Offset offset, void *buf,
!                           MPIABI_Count count, MPIABI_Datatype datatype,
!                           MPIABI_Status *status);
! int MPIABI_File_read_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                        MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_ordered(MPIABI_File fh, void *buf, int count,
!                              MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_ordered_begin(MPIABI_File fh, void *buf, int count,
!                                    MPIABI_Datatype datatype);
! int MPIABI_File_read_ordered_begin_c(MPIABI_File fh, void *buf,
!                                      MPIABI_Count count,
!                                      MPIABI_Datatype datatype);
! int MPIABI_File_read_ordered_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                                MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_ordered_end(MPIABI_File fh, void *buf,
!                                  MPIABI_Status *status);
! int MPIABI_File_read_shared(MPIABI_File fh, void *buf, int count,
!                             MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_read_shared_c(MPIABI_File fh, void *buf, MPIABI_Count count,
!                               MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_seek(MPIABI_File fh, MPIABI_Offset offset, int whence);
! int MPIABI_File_seek_shared(MPIABI_File fh, MPIABI_Offset offset, int whence);
! int MPIABI_File_set_atomicity(MPIABI_File fh, int flag);
! int MPIABI_File_set_info(MPIABI_File fh, MPIABI_Info info);
! int MPIABI_File_set_size(MPIABI_File fh, MPIABI_Offset size);
! int MPIABI_File_set_view(MPIABI_File fh, MPIABI_Offset disp,
!                          MPIABI_Datatype etype, MPIABI_Datatype filetype,
!                          const char *datarep, MPIABI_Info info);
! int MPIABI_File_sync(MPIABI_File fh);
! int MPIABI_File_write(MPIABI_File fh, const void *buf, int count,
!                       MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_all(MPIABI_File fh, const void *buf, int count,
!                           MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_all_begin(MPIABI_File fh, const void *buf, int count,
!                                 MPIABI_Datatype datatype);
! int MPIABI_File_write_all_begin_c(MPIABI_File fh, const void *buf,
!                                   MPIABI_Count count, MPIABI_Datatype datatype);
! int MPIABI_File_write_all_c(MPIABI_File fh, const void *buf, MPIABI_Count count,
!                             MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_all_end(MPIABI_File fh, const void *buf,
!                               MPIABI_Status *status);
! int MPIABI_File_write_at(MPIABI_File fh, MPIABI_Offset offset, const void *buf,
!                          int count, MPIABI_Datatype datatype,
!                          MPIABI_Status *status);
! int MPIABI_File_write_at_all(MPIABI_File fh, MPIABI_Offset offset,
!                              const void *buf, int count,
!                              MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_at_all_begin(MPIABI_File fh, MPIABI_Offset offset,
!                                    const void *buf, int count,
!                                    MPIABI_Datatype datatype);
! int MPIABI_File_write_at_all_begin_c(MPIABI_File fh, MPIABI_Offset offset,
!                                      const void *buf, MPIABI_Count count,
!                                      MPIABI_Datatype datatype);
! int MPIABI_File_write_at_all_c(MPIABI_File fh, MPIABI_Offset offset,
!                                const void *buf, MPIABI_Count count,
!                                MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_at_all_end(MPIABI_File fh, const void *buf,
!                                  MPIABI_Status *status);
! int MPIABI_File_write_at_c(MPIABI_File fh, MPIABI_Offset offset,
!                            const void *buf, MPIABI_Count count,
!                            MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_c(MPIABI_File fh, const void *buf, MPIABI_Count count,
!                         MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_ordered(MPIABI_File fh, const void *buf, int count,
!                               MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_ordered_begin(MPIABI_File fh, const void *buf, int count,
!                                     MPIABI_Datatype datatype);
! int MPIABI_File_write_ordered_begin_c(MPIABI_File fh, const void *buf,
!                                       MPIABI_Count count,
!                                       MPIABI_Datatype datatype);
! int MPIABI_File_write_ordered_c(MPIABI_File fh, const void *buf,
!                                 MPIABI_Count count, MPIABI_Datatype datatype,
!                                 MPIABI_Status *status);
! int MPIABI_File_write_ordered_end(MPIABI_File fh, const void *buf,
!                                   MPIABI_Status *status);
! int MPIABI_File_write_shared(MPIABI_File fh, const void *buf, int count,
!                              MPIABI_Datatype datatype, MPIABI_Status *status);
! int MPIABI_File_write_shared_c(MPIABI_File fh, const void *buf,
!                                MPIABI_Count count, MPIABI_Datatype datatype,
!                                MPIABI_Status *status);
! int MPIABI_Register_datarep(
!     const char *datarep, MPIABI_Datarep_conversion_function *read_conversion_fn,
!     MPIABI_Datarep_conversion_function *write_conversion_fn,
!     MPIABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
! int MPIABI_Register_datarep_c(
!     const char *datarep,
!     MPIABI_Datarep_conversion_function_c *read_conversion_fn,
!     MPIABI_Datarep_conversion_function_c *write_conversion_fn,
!     MPIABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
! 
! // A.3.13 Language Bindings C Bindings
! 
! MPIABI_Fint MPIABI_Comm_c2f(MPIABI_Comm comm);
! MPIABI_Comm MPIABI_Comm_f2c(MPIABI_Fint comm);
! MPIABI_Fint MPIABI_Errhandler_c2f(MPIABI_Errhandler errhandler);
! MPIABI_Errhandler MPIABI_Errhandler_f2c(MPIABI_Fint errhandler);
! MPIABI_Fint MPIABI_File_c2f(MPIABI_File file);
! MPIABI_File MPIABI_File_f2c(MPIABI_Fint file);
! MPIABI_Fint MPIABI_Group_c2f(MPIABI_Group group);
! MPIABI_Group MPIABI_Group_f2c(MPIABI_Fint group);
! MPIABI_Fint MPIABI_Info_c2f(MPIABI_Info info);
! MPIABI_Info MPIABI_Info_f2c(MPIABI_Fint info);
! MPIABI_Fint MPIABI_Message_c2f(MPIABI_Message message);
! MPIABI_Message MPIABI_Message_f2c(MPIABI_Fint message);
! MPIABI_Fint MPIABI_Op_c2f(MPIABI_Op op);
! MPIABI_Op MPIABI_Op_f2c(MPIABI_Fint op);
! MPIABI_Fint MPIABI_Request_c2f(MPIABI_Request request);
! MPIABI_Request MPIABI_Request_f2c(MPIABI_Fint request);
! MPIABI_Fint MPIABI_Session_c2f(MPIABI_Session session);
! MPIABI_Session MPIABI_Session_f2c(MPIABI_Fint session);
! int MPIABI_Status_f082f(const MPIABI_F08_status *f08_status,
!                         MPIABI_Fint *f_status);
! int MPIABI_Status_c2f(const MPIABI_Status *c_status, MPIABI_Fint *f_status);
! int MPIABI_Status_c2f08(const MPIABI_Status *c_status,
!                         MPIABI_F08_status *f08_status);
! int MPIABI_Status_f082c(const MPIABI_F08_status *f08_status,
!                         MPIABI_Status *c_status);
! int MPIABI_Status_f2c(const MPIABI_Fint *f_status, MPIABI_Status *c_status);
! int MPIABI_Status_f2f08(const MPIABI_Fint *f_status,
!                         MPIABI_F08_status *f08_status);
! MPIABI_Fint MPIABI_Type_c2f(MPIABI_Datatype datatype);
! int MPIABI_Type_create_f90_complex(int p, int r, MPIABI_Datatype *newtype);
! int MPIABI_Type_create_f90_integer(int r, MPIABI_Datatype *newtype);
! int MPIABI_Type_create_f90_real(int p, int r, MPIABI_Datatype *newtype);
! MPIABI_Datatype MPIABI_Type_f2c(MPIABI_Fint datatype);
! int MPIABI_Type_match_size(int typeclass, int size, MPIABI_Datatype *datatype);
! MPIABI_Fint MPIABI_Win_c2f(MPIABI_Win win);
! MPIABI_Win MPIABI_Win_f2c(MPIABI_Fint win);
! 
! // A.3.14 Tools / Profiling Interface C Bindings
! 
! int MPIABI_Pcontrol(const int level, ...);
! 
! // A.3.15 Tools / MPI Tool Information Interface C Bindings
! 
! int MPIABI_T_category_changed(int *update_number);
! int MPIABI_T_category_get_categories(int cat_index, int len, int indices[]);
! int MPIABI_T_category_get_cvars(int cat_index, int len, int indices[]);
! int MPIABI_T_category_get_events(int cat_index, int len, int indices[]);
! int MPIABI_T_category_get_index(const char *name, int *cat_index);
! int MPIABI_T_category_get_info(int cat_index, char *name, int *name_len,
!                                char *desc, int *desc_len, int *num_cvars,
!                                int *num_pvars, int *num_categories);
! int MPIABI_T_category_get_num(int *num_cat);
! int MPIABI_T_category_get_num_events(int cat_index, int *num_events);
! int MPIABI_T_category_get_pvars(int cat_index, int len, int indices[]);
! int MPIABI_T_cvar_get_index(const char *name, int *cvar_index);
! int MPIABI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
!                            int *verbosity, MPIABI_Datatype *datatype,
!                            MPIABI_T_enum *enumtype, char *desc, int *desc_len,
!                            int *bind, int *scope);
! int MPIABI_T_cvar_get_num(int *num_cvar);
! int MPIABI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
!                                MPIABI_T_cvar_handle *handle, int *count);
! int MPIABI_T_cvar_handle_free(MPIABI_T_cvar_handle *handle);
! int MPIABI_T_cvar_read(MPIABI_T_cvar_handle handle, void *buf);
! int MPIABI_T_cvar_write(MPIABI_T_cvar_handle handle, const void *buf);
! int MPIABI_T_enum_get_info(MPIABI_T_enum enumtype, int *num, char *name,
!                            int *name_len);
! int MPIABI_T_enum_get_item(MPIABI_T_enum enumtype, int index, int *value,
!                            char *name, int *name_len);
! int MPIABI_T_event_callback_get_info(
!     MPIABI_T_event_registration event_registration,
!     MPIABI_T_cb_safety cb_safety, MPIABI_Info *info_used);
! int MPIABI_T_event_callback_set_info(
!     MPIABI_T_event_registration event_registration,
!     MPIABI_T_cb_safety cb_safety, MPIABI_Info info);
! int MPIABI_T_event_copy(MPIABI_T_event_instance event_instance, void *buffer);
! int MPIABI_T_event_get_index(const char *name, int *event_index);
! int MPIABI_T_event_get_info(int event_index, char *name, int *name_len,
!                             int *verbosity,
!                             MPIABI_Datatype array_of_datatypes[],
!                             MPIABI_Aint array_of_displacements[],
!                             int *num_elements, MPIABI_T_enum *enumtype,
!                             MPIABI_Info *info, char *desc, int *desc_len,
!                             int *bind);
! int MPIABI_T_event_get_num(int *num_events);
! int MPIABI_T_event_get_source(MPIABI_T_event_instance event_instance,
!                               int *source_index);
! int MPIABI_T_event_get_timestamp(MPIABI_T_event_instance event_instance,
!                                  MPIABI_Count *event_timestamp);
! int MPIABI_T_event_handle_alloc(
!     int event_index, void *obj_handle, MPIABI_Info info,
!     MPIABI_T_event_registration *event_registration);
! int MPIABI_T_event_handle_free(
!     MPIABI_T_event_registration event_registration, void *user_data,
!     MPIABI_T_event_free_cb_function free_cb_function);
! int MPIABI_T_event_handle_get_info(
!     MPIABI_T_event_registration event_registration, MPIABI_Info *info_used);
! int MPIABI_T_event_handle_set_info(
!     MPIABI_T_event_registration event_registration, MPIABI_Info info);
! int MPIABI_T_event_read(MPIABI_T_event_instance event_instance,
!                         int element_index, void *buffer);
! int MPIABI_T_event_register_callback(
!     MPIABI_T_event_registration event_registration,
!     MPIABI_T_cb_safety cb_safety, MPIABI_Info info, void *user_data,
!     MPIABI_T_event_cb_function event_cb_function);
! int MPIABI_T_event_set_dropped_handler(
!     MPIABI_T_event_registration event_registration,
!     MPIABI_T_event_dropped_cb_function dropped_cb_function);
! int MPIABI_T_finalize(void);
! int MPIABI_T_init_thread(int required, int *provided);
! int MPIABI_T_pvar_get_index(const char *name, int var_class, int *pvar_index);
! int MPIABI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
!                            int *verbosity, int *var_class,
!                            MPIABI_Datatype *datatype, MPIABI_T_enum *enumtype,
!                            char *desc, int *desc_len, int *bind, int *readonly,
!                            int *continuous, int *atomic);
! int MPIABI_T_pvar_get_num(int *num_pvar);
! int MPIABI_T_pvar_handle_alloc(MPIABI_T_pvar_session pe_session, int pvar_index,
!                                void *obj_handle, MPIABI_T_pvar_handle *handle,
!                                int *count);
! int MPIABI_T_pvar_handle_free(MPIABI_T_pvar_session pe_session,
!                               MPIABI_T_pvar_handle *handle);
! int MPIABI_T_pvar_read(MPIABI_T_pvar_session pe_session,
!                        MPIABI_T_pvar_handle handle, void *buf);
! int MPIABI_T_pvar_readreset(MPIABI_T_pvar_session pe_session,
!                             MPIABI_T_pvar_handle handle, void *buf);
! int MPIABI_T_pvar_reset(MPIABI_T_pvar_session pe_session,
!                         MPIABI_T_pvar_handle handle);
! int MPIABI_T_pvar_session_create(MPIABI_T_pvar_session *pe_session);
! int MPIABI_T_pvar_session_free(MPIABI_T_pvar_session *pe_session);
! int MPIABI_T_pvar_start(MPIABI_T_pvar_session pe_session,
!                         MPIABI_T_pvar_handle handle);
! int MPIABI_T_pvar_stop(MPIABI_T_pvar_session pe_session,
!                        MPIABI_T_pvar_handle handle);
! int MPIABI_T_pvar_write(MPIABI_T_pvar_session pe_session,
!                         MPIABI_T_pvar_handle handle, const void *buf);
! int MPIABI_T_source_get_info(int source_index, char *name, int *name_len,
!                              char *desc, int *desc_len,
!                              MPIABI_T_source_order *ordering,
!                              MPIABI_Count *ticks_per_second,
!                              MPIABI_Count *max_ticks, MPIABI_Info *info);
! int MPIABI_T_source_get_num(int *num_sources);
! int MPIABI_T_source_get_timestamp(int source_index, MPIABI_Count *timestamp);
! 
! // A.3.16 Deprecated C Bindings
! 
! int MPIABI_Attr_delete(MPIABI_Comm comm, int keyval);
! int MPIABI_Attr_get(MPIABI_Comm comm, int keyval, void *attribute_val,
!                     int *flag);
! int MPIABI_Attr_put(MPIABI_Comm comm, int keyval, void *attribute_val);
! int MPIABI_Get_elements_x(const MPIABI_Status *status, MPIABI_Datatype datatype,
!                           MPIABI_Count *count);
! int MPIABI_Info_get(MPIABI_Info info, const char *key, int valuelen,
!                     char *value, int *flag);
! int MPIABI_Info_get_valuelen(MPIABI_Info info, const char *key, int *valuelen,
!                              int *flag);
! int MPIABI_Keyval_create(MPIABI_Copy_function *copy_fn,
!                          MPIABI_Delete_function *delete_fn, int *keyval,
!                          void *extra_state);
! int MPIABI_Keyval_free(int *keyval);
! int MPIABI_Status_set_elements_x(MPIABI_Status *status,
!                                  MPIABI_Datatype datatype, MPIABI_Count count);
! int MPIABI_Type_get_extent_x(MPIABI_Datatype datatype, MPIABI_Count *lb,
!                              MPIABI_Count *extent);
! int MPIABI_Type_get_true_extent_x(MPIABI_Datatype datatype,
!                                   MPIABI_Count *true_lb,
!                                   MPIABI_Count *true_extent);
! int MPIABI_Type_size_x(MPIABI_Datatype datatype, MPIABI_Count *size);
! 
! // MPIX
! 
! int MPIXABI_Query_cuda_support(void);
! 
! int MPIXABI_Query_hip_support(void);
! 
! int MPIXABI_Query_rocm_support(void);
! 
! int MPIXABI_Query_ze_support(void);
