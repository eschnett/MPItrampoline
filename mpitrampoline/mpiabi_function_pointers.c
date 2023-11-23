#include "mpiabi_function_pointers.h"

// Declare pointers to MPIABI functions

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

int (*MPIABI_Bsend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                        int dest, int tag, MPIABI_Comm comm);
int (*MPIABI_Bsend_c_ptr)(const void *buf, MPIABI_Count count,
                          MPIABI_Datatype datatype, int dest, int tag,
                          MPIABI_Comm comm);
int (*MPIABI_Bsend_init_ptr)(const void *buf, int count,
                             MPIABI_Datatype datatype, int dest, int tag,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Bsend_init_c_ptr)(const void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype, int dest, int tag,
                               MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Buffer_attach_ptr)(void *buffer, int size);
int (*MPIABI_Buffer_attach_c_ptr)(void *buffer, MPIABI_Count size);
int (*MPIABI_Buffer_detach_ptr)(void *buffer_addr, int *size);
int (*MPIABI_Buffer_detach_c_ptr)(void *buffer_addr, MPIABI_Count *size);
int (*MPIABI_Buffer_flush_ptr)(void);
int (*MPIABI_Buffer_iflush_ptr)(MPIABI_Request *request);
int (*MPIABI_Cancel_ptr)(MPIABI_Request *request);
int (*MPIABI_Comm_attach_buffer_ptr)(MPIABI_Comm comm, void *buffer, int size);
int (*MPIABI_Comm_attach_buffer_c_ptr)(MPIABI_Comm comm, void *buffer,
                                       MPIABI_Count size);
int (*MPIABI_Comm_detach_buffer_ptr)(MPIABI_Comm comm, void *buffer_addr,
                                     int *size);
int (*MPIABI_Comm_detach_buffer_c_ptr)(MPIABI_Comm comm, void *buffer_addr,
                                       MPIABI_Count *size);
int (*MPIABI_Comm_flush_buffer_ptr)(MPIABI_Comm comm);
int (*MPIABI_Comm_iflush_buffer_ptr)(MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Get_count_ptr)(const MPIABI_Status *status,
                            MPIABI_Datatype datatype, int *count);
int (*MPIABI_Get_count_c_ptr)(const MPIABI_Status *status,
                              MPIABI_Datatype datatype, MPIABI_Count *count);
int (*MPIABI_Ibsend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                         int dest, int tag, MPIABI_Comm comm,
                         MPIABI_Request *request);
int (*MPIABI_Ibsend_c_ptr)(const void *buf, MPIABI_Count count,
                           MPIABI_Datatype datatype, int dest, int tag,
                           MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Improbe_ptr)(int source, int tag, MPIABI_Comm comm, int *flag,
                          MPIABI_Message *message, MPIABI_Status *status);
int (*MPIABI_Imrecv_ptr)(void *buf, int count, MPIABI_Datatype datatype,
                         MPIABI_Message *message, MPIABI_Request *request);
int (*MPIABI_Imrecv_c_ptr)(void *buf, MPIABI_Count count,
                           MPIABI_Datatype datatype, MPIABI_Message *message,
                           MPIABI_Request *request);
int (*MPIABI_Iprobe_ptr)(int source, int tag, MPIABI_Comm comm, int *flag,
                         MPIABI_Status *status);
int (*MPIABI_Irecv_ptr)(void *buf, int count, MPIABI_Datatype datatype,
                        int source, int tag, MPIABI_Comm comm,
                        MPIABI_Request *request);
int (*MPIABI_Irecv_c_ptr)(void *buf, MPIABI_Count count,
                          MPIABI_Datatype datatype, int source, int tag,
                          MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Irsend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                         int dest, int tag, MPIABI_Comm comm,
                         MPIABI_Request *request);
int (*MPIABI_Irsend_c_ptr)(const void *buf, MPIABI_Count count,
                           MPIABI_Datatype datatype, int dest, int tag,
                           MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Isend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                        int dest, int tag, MPIABI_Comm comm,
                        MPIABI_Request *request);
int (*MPIABI_Isend_c_ptr)(const void *buf, MPIABI_Count count,
                          MPIABI_Datatype datatype, int dest, int tag,
                          MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Isendrecv_ptr)(const void *sendbuf, int sendcount,
                            MPIABI_Datatype sendtype, int dest, int sendtag,
                            void *recvbuf, int recvcount,
                            MPIABI_Datatype recvtype, int source, int recvtag,
                            MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Isendrecv_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                              MPIABI_Datatype sendtype, int dest, int sendtag,
                              void *recvbuf, MPIABI_Count recvcount,
                              MPIABI_Datatype recvtype, int source, int recvtag,
                              MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Isendrecv_replace_ptr)(void *buf, int count,
                                    MPIABI_Datatype datatype, int dest,
                                    int sendtag, int source, int recvtag,
                                    MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Isendrecv_replace_c_ptr)(void *buf, MPIABI_Count count,
                                      MPIABI_Datatype datatype, int dest,
                                      int sendtag, int source, int recvtag,
                                      MPIABI_Comm comm,
                                      MPIABI_Request *request);
int (*MPIABI_Issend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                         int dest, int tag, MPIABI_Comm comm,
                         MPIABI_Request *request);
int (*MPIABI_Issend_c_ptr)(const void *buf, MPIABI_Count count,
                           MPIABI_Datatype datatype, int dest, int tag,
                           MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Mprobe_ptr)(int source, int tag, MPIABI_Comm comm,
                         MPIABI_Message *message, MPIABI_Status *status);
int (*MPIABI_Mrecv_ptr)(void *buf, int count, MPIABI_Datatype datatype,
                        MPIABI_Message *message, MPIABI_Status *status);
int (*MPIABI_Mrecv_c_ptr)(void *buf, MPIABI_Count count,
                          MPIABI_Datatype datatype, MPIABI_Message *message,
                          MPIABI_Status *status);
int (*MPIABI_Probe_ptr)(int source, int tag, MPIABI_Comm comm,
                        MPIABI_Status *status);
int (*MPIABI_Recv_ptr)(void *buf, int count, MPIABI_Datatype datatype,
                       int source, int tag, MPIABI_Comm comm,
                       MPIABI_Status *status);
int (*MPIABI_Recv_c_ptr)(void *buf, MPIABI_Count count,
                         MPIABI_Datatype datatype, int source, int tag,
                         MPIABI_Comm comm, MPIABI_Status *status);
int (*MPIABI_Recv_init_ptr)(void *buf, int count, MPIABI_Datatype datatype,
                            int source, int tag, MPIABI_Comm comm,
                            MPIABI_Request *request);
int (*MPIABI_Recv_init_c_ptr)(void *buf, MPIABI_Count count,
                              MPIABI_Datatype datatype, int source, int tag,
                              MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Request_free_ptr)(MPIABI_Request *request);
int (*MPIABI_Request_get_status_ptr)(MPIABI_Request request, int *flag,
                                     MPIABI_Status *status);
int (*MPIABI_Request_get_status_all_ptr)(
    int count, const MPIABI_Request array_of_requests[], int *flag,
    MPIABI_Status array_of_statuses[]);
int (*MPIABI_Request_get_status_any_ptr)(
    int count, const MPIABI_Request array_of_requests[], int *index, int *flag,
    MPIABI_Status *status);
int (*MPIABI_Request_get_status_some_ptr)(
    int incount, const MPIABI_Request array_of_requests[], int *outcount,
    int array_of_indices[], MPIABI_Status array_of_statuses[]);
int (*MPIABI_Rsend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                        int dest, int tag, MPIABI_Comm comm);
int (*MPIABI_Rsend_c_ptr)(const void *buf, MPIABI_Count count,
                          MPIABI_Datatype datatype, int dest, int tag,
                          MPIABI_Comm comm);
int (*MPIABI_Rsend_init_ptr)(const void *buf, int count,
                             MPIABI_Datatype datatype, int dest, int tag,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Rsend_init_c_ptr)(const void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype, int dest, int tag,
                               MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Send_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                       int dest, int tag, MPIABI_Comm comm);
int (*MPIABI_Send_c_ptr)(const void *buf, MPIABI_Count count,
                         MPIABI_Datatype datatype, int dest, int tag,
                         MPIABI_Comm comm);
int (*MPIABI_Send_init_ptr)(const void *buf, int count,
                            MPIABI_Datatype datatype, int dest, int tag,
                            MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Send_init_c_ptr)(const void *buf, MPIABI_Count count,
                              MPIABI_Datatype datatype, int dest, int tag,
                              MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Sendrecv_ptr)(const void *sendbuf, int sendcount,
                           MPIABI_Datatype sendtype, int dest, int sendtag,
                           void *recvbuf, int recvcount,
                           MPIABI_Datatype recvtype, int source, int recvtag,
                           MPIABI_Comm comm, MPIABI_Status *status);
int (*MPIABI_Sendrecv_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                             MPIABI_Datatype sendtype, int dest, int sendtag,
                             void *recvbuf, MPIABI_Count recvcount,
                             MPIABI_Datatype recvtype, int source, int recvtag,
                             MPIABI_Comm comm, MPIABI_Status *status);
int (*MPIABI_Sendrecv_replace_ptr)(void *buf, int count,
                                   MPIABI_Datatype datatype, int dest,
                                   int sendtag, int source, int recvtag,
                                   MPIABI_Comm comm, MPIABI_Status *status);
int (*MPIABI_Sendrecv_replace_c_ptr)(void *buf, MPIABI_Count count,
                                     MPIABI_Datatype datatype, int dest,
                                     int sendtag, int source, int recvtag,
                                     MPIABI_Comm comm, MPIABI_Status *status);
int (*MPIABI_Session_attach_buffer_ptr)(MPIABI_Session session, void *buffer,
                                        int size);
int (*MPIABI_Session_attach_buffer_c_ptr)(MPIABI_Session session, void *buffer,
                                          MPIABI_Count size);
int (*MPIABI_Session_detach_buffer_ptr)(MPIABI_Session session,
                                        void *buffer_addr, int *size);
int (*MPIABI_Session_detach_buffer_c_ptr)(MPIABI_Session session,
                                          void *buffer_addr,
                                          MPIABI_Count *size);
int (*MPIABI_Session_flush_buffer_ptr)(MPIABI_Session session);
int (*MPIABI_Session_iflush_buffer_ptr)(MPIABI_Session session,
                                        MPIABI_Request *request);
int (*MPIABI_Ssend_ptr)(const void *buf, int count, MPIABI_Datatype datatype,
                        int dest, int tag, MPIABI_Comm comm);
int (*MPIABI_Ssend_c_ptr)(const void *buf, MPIABI_Count count,
                          MPIABI_Datatype datatype, int dest, int tag,
                          MPIABI_Comm comm);
int (*MPIABI_Ssend_init_ptr)(const void *buf, int count,
                             MPIABI_Datatype datatype, int dest, int tag,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ssend_init_c_ptr)(const void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype, int dest, int tag,
                               MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Start_ptr)(MPIABI_Request *request);
int (*MPIABI_Startall_ptr)(int count, MPIABI_Request array_of_requests[]);
int (*MPIABI_Status_get_error_ptr)(MPIABI_Status *status, int *err);
int (*MPIABI_Status_get_source_ptr)(MPIABI_Status *status, int *source);
int (*MPIABI_Status_get_tag_ptr)(MPIABI_Status *status, int *tag);
int (*MPIABI_Test_ptr)(MPIABI_Request *request, int *flag,
                       MPIABI_Status *status);
int (*MPIABI_Test_cancelled_ptr)(const MPIABI_Status *status, int *flag);
int (*MPIABI_Testall_ptr)(int count, MPIABI_Request array_of_requests[],
                          int *flag, MPIABI_Status array_of_statuses[]);
int (*MPIABI_Testany_ptr)(int count, MPIABI_Request array_of_requests[],
                          int *index, int *flag, MPIABI_Status *status);
int (*MPIABI_Testsome_ptr)(int incount, MPIABI_Request array_of_requests[],
                           int *outcount, int array_of_indices[],
                           MPIABI_Status array_of_statuses[]);
int (*MPIABI_Wait_ptr)(MPIABI_Request *request, MPIABI_Status *status);
int (*MPIABI_Waitall_ptr)(int count, MPIABI_Request array_of_requests[],
                          MPIABI_Status array_of_statuses[]);
int (*MPIABI_Waitany_ptr)(int count, MPIABI_Request array_of_requests[],
                          int *index, MPIABI_Status *status);
int (*MPIABI_Waitsome_ptr)(int incount, MPIABI_Request array_of_requests[],
                           int *outcount, int array_of_indices[],
                           MPIABI_Status array_of_statuses[]);

// A.3.2 Partitioned Communication C Bindings

int (*MPIABI_Parrived_ptr)(MPIABI_Request request, int partition, int *flag);
int (*MPIABI_Pready_ptr)(int partition, MPIABI_Request request);
int (*MPIABI_Pready_list_ptr)(int length, const int array_of_partitions[],
                              MPIABI_Request request);
int (*MPIABI_Pready_range_ptr)(int partition_low, int partition_high,
                               MPIABI_Request request);
int (*MPIABI_Precv_init_ptr)(void *buf, int partitions, MPIABI_Count count,
                             MPIABI_Datatype datatype, int source, int tag,
                             MPIABI_Comm comm, MPIABI_Info info,
                             MPIABI_Request *request);
int (*MPIABI_Psend_init_ptr)(const void *buf, int partitions,
                             MPIABI_Count count, MPIABI_Datatype datatype,
                             int dest, int tag, MPIABI_Comm comm,
                             MPIABI_Info info, MPIABI_Request *request);

// A.3.3 Datatypes C Bindings

MPIABI_Aint (*MPIABI_Aint_add_ptr)(MPIABI_Aint base, MPIABI_Aint disp);
MPIABI_Aint (*MPIABI_Aint_diff_ptr)(MPIABI_Aint addr1, MPIABI_Aint addr2);
int (*MPIABI_Get_address_ptr)(const void *location, MPIABI_Aint *address);
int (*MPIABI_Get_elements_ptr)(const MPIABI_Status *status,
                               MPIABI_Datatype datatype, int *count);
int (*MPIABI_Get_elements_c_ptr)(const MPIABI_Status *status,
                                 MPIABI_Datatype datatype, MPIABI_Count *count);
int (*MPIABI_Pack_ptr)(const void *inbuf, int incount, MPIABI_Datatype datatype,
                       void *outbuf, int outsize, int *position,
                       MPIABI_Comm comm);
int (*MPIABI_Pack_c_ptr)(const void *inbuf, MPIABI_Count incount,
                         MPIABI_Datatype datatype, void *outbuf,
                         MPIABI_Count outsize, MPIABI_Count *position,
                         MPIABI_Comm comm);
int (*MPIABI_Pack_external_ptr)(const char datarep[], const void *inbuf,
                                int incount, MPIABI_Datatype datatype,
                                void *outbuf, MPIABI_Aint outsize,
                                MPIABI_Aint *position);
int (*MPIABI_Pack_external_c_ptr)(const char datarep[], const void *inbuf,
                                  MPIABI_Count incount,
                                  MPIABI_Datatype datatype, void *outbuf,
                                  MPIABI_Count outsize, MPIABI_Count *position);
int (*MPIABI_Pack_external_size_ptr)(const char datarep[], MPIABI_Count incount,
                                     MPIABI_Datatype datatype,
                                     MPIABI_Aint *size);
int (*MPIABI_Pack_external_size_c_ptr)(const char datarep[],
                                       MPIABI_Count incount,
                                       MPIABI_Datatype datatype,
                                       MPIABI_Count *size);
int (*MPIABI_Pack_size_c_ptr)(MPIABI_Count incount, MPIABI_Datatype datatype,
                              MPIABI_Comm comm, MPIABI_Count *size);
int (*MPIABI_Type_commit_ptr)(MPIABI_Datatype *datatype);
int (*MPIABI_Type_contiguous_ptr)(int count, MPIABI_Datatype oldtype,
                                  MPIABI_Datatype *newtype);
int (*MPIABI_Type_contiguous_c_ptr)(MPIABI_Count count, MPIABI_Datatype oldtype,
                                    MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_darray_ptr)(int size, int rank, int ndims,
                                     const int array_of_gsizes[],
                                     const int array_of_distribs[],
                                     const int array_of_dargs[],
                                     const int array_of_psizes[], int order,
                                     MPIABI_Datatype oldtype,
                                     MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_darray_c_ptr)(int size, int rank, int ndims,
                                       const MPIABI_Count array_of_gsizes[],
                                       const int array_of_distribs[],
                                       const int array_of_dargs[],
                                       const int array_of_psizes[], int order,
                                       MPIABI_Datatype oldtype,
                                       MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_hindexed_ptr)(
    int count, const int array_of_blocklengths[],
    const MPIABI_Aint array_of_displacements[], MPIABI_Datatype oldtype,
    MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_hindexed_block_ptr)(
    int count, int blocklength, const MPIABI_Aint array_of_displacements[],
    MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_hindexed_block_c_ptr)(
    MPIABI_Count count, MPIABI_Count blocklength,
    const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
    MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_hindexed_c_ptr)(
    MPIABI_Count count, const MPIABI_Count array_of_blocklengths[],
    const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
    MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_hvector_ptr)(int count, int blocklength,
                                      MPIABI_Aint stride,
                                      MPIABI_Datatype oldtype,
                                      MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_hvector_c_ptr)(MPIABI_Count count,
                                        MPIABI_Count blocklength,
                                        MPIABI_Count stride,
                                        MPIABI_Datatype oldtype,
                                        MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_indexed_block_ptr)(int count, int blocklength,
                                            const int array_of_displacements[],
                                            MPIABI_Datatype oldtype,
                                            MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_indexed_block_c_ptr)(
    MPIABI_Count count, MPIABI_Count blocklength,
    const MPIABI_Count array_of_displacements[], MPIABI_Datatype oldtype,
    MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_resized_ptr)(MPIABI_Datatype oldtype, MPIABI_Aint lb,
                                      MPIABI_Aint extent,
                                      MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_resized_c_ptr)(MPIABI_Datatype oldtype,
                                        MPIABI_Count lb, MPIABI_Count extent,
                                        MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_struct_ptr)(int count,
                                     const int array_of_blocklengths[],
                                     const MPIABI_Aint array_of_displacements[],
                                     const MPIABI_Datatype array_of_types[],
                                     MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_struct_c_ptr)(
    MPIABI_Count count, const MPIABI_Count array_of_blocklengths[],
    const MPIABI_Count array_of_displacements[],
    const MPIABI_Datatype array_of_types[], MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_subarray_ptr)(int ndims, const int array_of_sizes[],
                                       const int array_of_subsizes[],
                                       const int array_of_starts[], int order,
                                       MPIABI_Datatype oldtype,
                                       MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_subarray_c_ptr)(int ndims,
                                         const MPIABI_Count array_of_sizes[],
                                         const MPIABI_Count array_of_subsizes[],
                                         const MPIABI_Count array_of_starts[],
                                         int order, MPIABI_Datatype oldtype,
                                         MPIABI_Datatype *newtype);
int (*MPIABI_Type_dup_ptr)(MPIABI_Datatype oldtype, MPIABI_Datatype *newtype);
int (*MPIABI_Type_free_ptr)(MPIABI_Datatype *datatype);
int (*MPIABI_Type_get_contents_ptr)(MPIABI_Datatype datatype, int max_integers,
                                    int max_addresses, int max_datatypes,
                                    int array_of_integers[],
                                    MPIABI_Aint array_of_addresses[],
                                    MPIABI_Datatype array_of_datatypes[]);
int (*MPIABI_Type_get_contents_c_ptr)(
    MPIABI_Datatype datatype, MPIABI_Count max_integers,
    MPIABI_Count max_addresses, MPIABI_Count max_large_counts,
    MPIABI_Count max_datatypes, int array_of_integers[],
    MPIABI_Aint array_of_addresses[], MPIABI_Count array_of_large_counts[],
    MPIABI_Datatype array_of_datatypes[]);
int (*MPIABI_Type_get_envelope_ptr)(MPIABI_Datatype datatype, int *num_integers,
                                    int *num_addresses, int *num_datatypes,
                                    int *combiner);
int (*MPIABI_Type_get_envelope_c_ptr)(MPIABI_Datatype datatype,
                                      MPIABI_Count *num_integers,
                                      MPIABI_Count *num_addresses,
                                      MPIABI_Count *num_large_counts,
                                      MPIABI_Count *num_datatypes,
                                      int *combiner);
int (*MPIABI_Type_get_extent_ptr)(MPIABI_Datatype datatype, MPIABI_Aint *lb,
                                  MPIABI_Aint *extent);
int (*MPIABI_Type_get_extent_c_ptr)(MPIABI_Datatype datatype, MPIABI_Count *lb,
                                    MPIABI_Count *extent);
int (*MPIABI_Type_get_true_extent_ptr)(MPIABI_Datatype datatype,
                                       MPIABI_Aint *true_lb,
                                       MPIABI_Aint *true_extent);
int (*MPIABI_Type_get_true_extent_c_ptr)(MPIABI_Datatype datatype,
                                         MPIABI_Count *true_lb,
                                         MPIABI_Count *true_extent);
int (*MPIABI_Type_indexed_ptr)(int count, const int array_of_blocklengths[],
                               const int array_of_displacements[],
                               MPIABI_Datatype oldtype,
                               MPIABI_Datatype *newtype);
int (*MPIABI_Type_indexed_c_ptr)(MPIABI_Count count,
                                 const MPIABI_Count array_of_blocklengths[],
                                 const MPIABI_Count array_of_displacements[],
                                 MPIABI_Datatype oldtype,
                                 MPIABI_Datatype *newtype);
int (*MPIABI_Type_size_ptr)(MPIABI_Datatype datatype, int *size);
int (*MPIABI_Type_size_c_ptr)(MPIABI_Datatype datatype, MPIABI_Count *size);
int (*MPIABI_Type_vector_ptr)(int count, int blocklength, int stride,
                              MPIABI_Datatype oldtype,
                              MPIABI_Datatype *newtype);
int (*MPIABI_Type_vector_c_ptr)(MPIABI_Count count, MPIABI_Count blocklength,
                                MPIABI_Count stride, MPIABI_Datatype oldtype,
                                MPIABI_Datatype *newtype);
int (*MPIABI_Unpack_ptr)(const void *inbuf, int insize, int *position,
                         void *outbuf, int outcount, MPIABI_Datatype datatype,
                         MPIABI_Comm comm);
int (*MPIABI_Unpack_c_ptr)(const void *inbuf, MPIABI_Count insize,
                           MPIABI_Count *position, void *outbuf,
                           MPIABI_Count outcount, MPIABI_Datatype datatype,
                           MPIABI_Comm comm);
int (*MPIABI_Unpack_external_ptr)(const char datarep[], const void *inbuf,
                                  MPIABI_Aint insize, MPIABI_Aint *position,
                                  void *outbuf, int outcount,
                                  MPIABI_Datatype datatype);
int (*MPIABI_Unpack_external_c_ptr)(const char datarep[], const void *inbuf,
                                    MPIABI_Count insize, MPIABI_Count *position,
                                    void *outbuf, MPIABI_Count outcount,
                                    MPIABI_Datatype datatype);

// A.3.4 Collective Communication C Bindings

int (*MPIABI_Allgather_ptr)(const void *sendbuf, int sendcount,
                            MPIABI_Datatype sendtype, void *recvbuf,
                            int recvcount, MPIABI_Datatype recvtype,
                            MPIABI_Comm comm);
int (*MPIABI_Allgather_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                              MPIABI_Datatype sendtype, void *recvbuf,
                              MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                              MPIABI_Comm comm);
int (*MPIABI_Allgather_init_ptr)(const void *sendbuf, int sendcount,
                                 MPIABI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPIABI_Datatype recvtype,
                                 MPIABI_Comm comm, MPIABI_Info info,
                                 MPIABI_Request *request);
int (*MPIABI_Allgather_init_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                   MPIABI_Datatype sendtype, void *recvbuf,
                                   MPIABI_Count recvcount,
                                   MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                   MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Allgatherv_ptr)(const void *sendbuf, int sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             const int recvcounts[], const int displs[],
                             MPIABI_Datatype recvtype, MPIABI_Comm comm);
int (*MPIABI_Allgatherv_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               const MPIABI_Count recvcounts[],
                               const MPIABI_Aint displs[],
                               MPIABI_Datatype recvtype, MPIABI_Comm comm);
int (*MPIABI_Allgatherv_init_ptr)(const void *sendbuf, int sendcount,
                                  MPIABI_Datatype sendtype, void *recvbuf,
                                  const int recvcounts[], const int displs[],
                                  MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                  MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Allgatherv_init_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                    MPIABI_Datatype sendtype, void *recvbuf,
                                    const MPIABI_Count recvcounts[],
                                    const MPIABI_Aint displs[],
                                    MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                    MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Allreduce_ptr)(const void *sendbuf, void *recvbuf, int count,
                            MPIABI_Datatype datatype, MPIABI_Op op,
                            MPIABI_Comm comm);
int (*MPIABI_Allreduce_c_ptr)(const void *sendbuf, void *recvbuf,
                              MPIABI_Count count, MPIABI_Datatype datatype,
                              MPIABI_Op op, MPIABI_Comm comm);
int (*MPIABI_Allreduce_init_ptr)(const void *sendbuf, void *recvbuf, int count,
                                 MPIABI_Datatype datatype, MPIABI_Op op,
                                 MPIABI_Comm comm, MPIABI_Info info,
                                 MPIABI_Request *request);
int (*MPIABI_Allreduce_init_c_ptr)(const void *sendbuf, void *recvbuf,
                                   MPIABI_Count count, MPIABI_Datatype datatype,
                                   MPIABI_Op op, MPIABI_Comm comm,
                                   MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Alltoall_ptr)(const void *sendbuf, int sendcount,
                           MPIABI_Datatype sendtype, void *recvbuf,
                           int recvcount, MPIABI_Datatype recvtype,
                           MPIABI_Comm comm);
int (*MPIABI_Alltoall_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                             MPIABI_Comm comm);
int (*MPIABI_Alltoall_init_ptr)(const void *sendbuf, int sendcount,
                                MPIABI_Datatype sendtype, void *recvbuf,
                                int recvcount, MPIABI_Datatype recvtype,
                                MPIABI_Comm comm, MPIABI_Info info,
                                MPIABI_Request *request);
int (*MPIABI_Alltoall_init_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                  MPIABI_Datatype sendtype, void *recvbuf,
                                  MPIABI_Count recvcount,
                                  MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                  MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Alltoallv_ptr)(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], MPIABI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPIABI_Datatype recvtype,
                            MPIABI_Comm comm);
int (*MPIABI_Alltoallv_c_ptr)(const void *sendbuf,
                              const MPIABI_Count sendcounts[],
                              const MPIABI_Aint sdispls[],
                              MPIABI_Datatype sendtype, void *recvbuf,
                              const MPIABI_Count recvcounts[],
                              const MPIABI_Aint rdispls[],
                              MPIABI_Datatype recvtype, MPIABI_Comm comm);
int (*MPIABI_Alltoallv_init_ptr)(const void *sendbuf, const int sendcounts[],
                                 const int sdispls[], MPIABI_Datatype sendtype,
                                 void *recvbuf, const int recvcounts[],
                                 const int rdispls[], MPIABI_Datatype recvtype,
                                 MPIABI_Comm comm, MPIABI_Info info,
                                 MPIABI_Request *request);
int (*MPIABI_Alltoallv_init_c_ptr)(const void *sendbuf,
                                   const MPIABI_Count sendcounts[],
                                   const MPIABI_Aint sdispls[],
                                   MPIABI_Datatype sendtype, void *recvbuf,
                                   const MPIABI_Count recvcounts[],
                                   const MPIABI_Aint rdispls[],
                                   MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                   MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Alltoallw_ptr)(const void *sendbuf, const int sendcounts[],
                            const int sdispls[],
                            const MPIABI_Datatype sendtypes[], void *recvbuf,
                            const int recvcounts[], const int rdispls[],
                            const MPIABI_Datatype recvtypes[],
                            MPIABI_Comm comm);
int (*MPIABI_Alltoallw_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm);
int (*MPIABI_Alltoallw_init_ptr)(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    const MPIABI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const int rdispls[], const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
    MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Alltoallw_init_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request);
int (*MPIABI_Barrier_ptr)(MPIABI_Comm comm);
int (*MPIABI_Barrier_init_ptr)(MPIABI_Comm comm, MPIABI_Info info,
                               MPIABI_Request *request);
int (*MPIABI_Bcast_ptr)(void *buffer, int count, MPIABI_Datatype datatype,
                        int root, MPIABI_Comm comm);
int (*MPIABI_Bcast_c_ptr)(void *buffer, MPIABI_Count count,
                          MPIABI_Datatype datatype, int root, MPIABI_Comm comm);
int (*MPIABI_Bcast_init_ptr)(void *buffer, int count, MPIABI_Datatype datatype,
                             int root, MPIABI_Comm comm, MPIABI_Info info,
                             MPIABI_Request *request);
int (*MPIABI_Bcast_init_c_ptr)(void *buffer, MPIABI_Count count,
                               MPIABI_Datatype datatype, int root,
                               MPIABI_Comm comm, MPIABI_Info info,
                               MPIABI_Request *request);
int (*MPIABI_Exscan_ptr)(const void *sendbuf, void *recvbuf, int count,
                         MPIABI_Datatype datatype, MPIABI_Op op,
                         MPIABI_Comm comm);
int (*MPIABI_Exscan_c_ptr)(const void *sendbuf, void *recvbuf,
                           MPIABI_Count count, MPIABI_Datatype datatype,
                           MPIABI_Op op, MPIABI_Comm comm);
int (*MPIABI_Exscan_init_ptr)(const void *sendbuf, void *recvbuf, int count,
                              MPIABI_Datatype datatype, MPIABI_Op op,
                              MPIABI_Comm comm, MPIABI_Info info,
                              MPIABI_Request *request);
int (*MPIABI_Exscan_init_c_ptr)(const void *sendbuf, void *recvbuf,
                                MPIABI_Count count, MPIABI_Datatype datatype,
                                MPIABI_Op op, MPIABI_Comm comm,
                                MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Gather_ptr)(const void *sendbuf, int sendcount,
                         MPIABI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPIABI_Datatype recvtype, int root, MPIABI_Comm comm);
int (*MPIABI_Gather_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                           MPIABI_Datatype sendtype, void *recvbuf,
                           MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                           int root, MPIABI_Comm comm);
int (*MPIABI_Gather_init_ptr)(const void *sendbuf, int sendcount,
                              MPIABI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPIABI_Datatype recvtype, int root,
                              MPIABI_Comm comm, MPIABI_Info info,
                              MPIABI_Request *request);
int (*MPIABI_Gather_init_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                MPIABI_Datatype sendtype, void *recvbuf,
                                MPIABI_Count recvcount,
                                MPIABI_Datatype recvtype, int root,
                                MPIABI_Comm comm, MPIABI_Info info,
                                MPIABI_Request *request);
int (*MPIABI_Gatherv_ptr)(const void *sendbuf, int sendcount,
                          MPIABI_Datatype sendtype, void *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPIABI_Datatype recvtype, int root, MPIABI_Comm comm);
int (*MPIABI_Gatherv_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                            MPIABI_Datatype sendtype, void *recvbuf,
                            const MPIABI_Count recvcounts[],
                            const MPIABI_Aint displs[],
                            MPIABI_Datatype recvtype, int root,
                            MPIABI_Comm comm);
int (*MPIABI_Gatherv_init_ptr)(const void *sendbuf, int sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPIABI_Datatype recvtype, int root,
                               MPIABI_Comm comm, MPIABI_Info info,
                               MPIABI_Request *request);
int (*MPIABI_Gatherv_init_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                 MPIABI_Datatype sendtype, void *recvbuf,
                                 const MPIABI_Count recvcounts[],
                                 const MPIABI_Aint displs[],
                                 MPIABI_Datatype recvtype, int root,
                                 MPIABI_Comm comm, MPIABI_Info info,
                                 MPIABI_Request *request);
int (*MPIABI_Iallgather_ptr)(const void *sendbuf, int sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPIABI_Datatype recvtype,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iallgather_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                               MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iallgatherv_ptr)(const void *sendbuf, int sendcount,
                              MPIABI_Datatype sendtype, void *recvbuf,
                              const int recvcounts[], const int displs[],
                              MPIABI_Datatype recvtype, MPIABI_Comm comm,
                              MPIABI_Request *request);
int (*MPIABI_Iallgatherv_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                MPIABI_Datatype sendtype, void *recvbuf,
                                const MPIABI_Count recvcounts[],
                                const MPIABI_Aint displs[],
                                MPIABI_Datatype recvtype, MPIABI_Comm comm,
                                MPIABI_Request *request);
int (*MPIABI_Iallreduce_ptr)(const void *sendbuf, void *recvbuf, int count,
                             MPIABI_Datatype datatype, MPIABI_Op op,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iallreduce_c_ptr)(const void *sendbuf, void *recvbuf,
                               MPIABI_Count count, MPIABI_Datatype datatype,
                               MPIABI_Op op, MPIABI_Comm comm,
                               MPIABI_Request *request);
int (*MPIABI_Ialltoall_ptr)(const void *sendbuf, int sendcount,
                            MPIABI_Datatype sendtype, void *recvbuf,
                            int recvcount, MPIABI_Datatype recvtype,
                            MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ialltoall_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                              MPIABI_Datatype sendtype, void *recvbuf,
                              MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                              MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ialltoallv_ptr)(const void *sendbuf, const int sendcounts[],
                             const int sdispls[], MPIABI_Datatype sendtype,
                             void *recvbuf, const int recvcounts[],
                             const int rdispls[], MPIABI_Datatype recvtype,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ialltoallv_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
    const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ialltoallw_ptr)(const void *sendbuf, const int sendcounts[],
                             const int sdispls[],
                             const MPIABI_Datatype sendtypes[], void *recvbuf,
                             const int recvcounts[], const int rdispls[],
                             const MPIABI_Datatype recvtypes[],
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ialltoallw_c_ptr)(const void *sendbuf,
                               const MPIABI_Count sendcounts[],
                               const MPIABI_Aint sdispls[],
                               const MPIABI_Datatype sendtypes[], void *recvbuf,
                               const MPIABI_Count recvcounts[],
                               const MPIABI_Aint rdispls[],
                               const MPIABI_Datatype recvtypes[],
                               MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ibarrier_ptr)(MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ibcast_ptr)(void *buffer, int count, MPIABI_Datatype datatype,
                         int root, MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ibcast_c_ptr)(void *buffer, MPIABI_Count count,
                           MPIABI_Datatype datatype, int root, MPIABI_Comm comm,
                           MPIABI_Request *request);
int (*MPIABI_Iexscan_ptr)(const void *sendbuf, void *recvbuf, int count,
                          MPIABI_Datatype datatype, MPIABI_Op op,
                          MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iexscan_c_ptr)(const void *sendbuf, void *recvbuf,
                            MPIABI_Count count, MPIABI_Datatype datatype,
                            MPIABI_Op op, MPIABI_Comm comm,
                            MPIABI_Request *request);
int (*MPIABI_Igather_ptr)(const void *sendbuf, int sendcount,
                          MPIABI_Datatype sendtype, void *recvbuf,
                          int recvcount, MPIABI_Datatype recvtype, int root,
                          MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Igather_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                            MPIABI_Datatype sendtype, void *recvbuf,
                            MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                            int root, MPIABI_Comm comm,
                            MPIABI_Request *request);
int (*MPIABI_Igatherv_ptr)(const void *sendbuf, int sendcount,
                           MPIABI_Datatype sendtype, void *recvbuf,
                           const int recvcounts[], const int displs[],
                           MPIABI_Datatype recvtype, int root, MPIABI_Comm comm,
                           MPIABI_Request *request);
int (*MPIABI_Igatherv_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             const MPIABI_Count recvcounts[],
                             const MPIABI_Aint displs[],
                             MPIABI_Datatype recvtype, int root,
                             MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ireduce_ptr)(const void *sendbuf, void *recvbuf, int count,
                          MPIABI_Datatype datatype, MPIABI_Op op, int root,
                          MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ireduce_c_ptr)(const void *sendbuf, void *recvbuf,
                            MPIABI_Count count, MPIABI_Datatype datatype,
                            MPIABI_Op op, int root, MPIABI_Comm comm,
                            MPIABI_Request *request);
int (*MPIABI_Ireduce_scatter_ptr)(const void *sendbuf, void *recvbuf,
                                  const int recvcounts[],
                                  MPIABI_Datatype datatype, MPIABI_Op op,
                                  MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ireduce_scatter_block_ptr)(const void *sendbuf, void *recvbuf,
                                        int recvcount, MPIABI_Datatype datatype,
                                        MPIABI_Op op, MPIABI_Comm comm,
                                        MPIABI_Request *request);
int (*MPIABI_Ireduce_scatter_block_c_ptr)(const void *sendbuf, void *recvbuf,
                                          MPIABI_Count recvcount,
                                          MPIABI_Datatype datatype,
                                          MPIABI_Op op, MPIABI_Comm comm,
                                          MPIABI_Request *request);
int (*MPIABI_Ireduce_scatter_c_ptr)(const void *sendbuf, void *recvbuf,
                                    const MPIABI_Count recvcounts[],
                                    MPIABI_Datatype datatype, MPIABI_Op op,
                                    MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iscan_ptr)(const void *sendbuf, void *recvbuf, int count,
                        MPIABI_Datatype datatype, MPIABI_Op op,
                        MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iscan_c_ptr)(const void *sendbuf, void *recvbuf,
                          MPIABI_Count count, MPIABI_Datatype datatype,
                          MPIABI_Op op, MPIABI_Comm comm,
                          MPIABI_Request *request);
int (*MPIABI_Iscatter_ptr)(const void *sendbuf, int sendcount,
                           MPIABI_Datatype sendtype, void *recvbuf,
                           int recvcount, MPIABI_Datatype recvtype, int root,
                           MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iscatter_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                             MPIABI_Datatype sendtype, void *recvbuf,
                             MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                             int root, MPIABI_Comm comm,
                             MPIABI_Request *request);
int (*MPIABI_Iscatterv_ptr)(const void *sendbuf, const int sendcounts[],
                            const int displs[], MPIABI_Datatype sendtype,
                            void *recvbuf, int recvcount,
                            MPIABI_Datatype recvtype, int root,
                            MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Iscatterv_c_ptr)(const void *sendbuf,
                              const MPIABI_Count sendcounts[],
                              const MPIABI_Aint displs[],
                              MPIABI_Datatype sendtype, void *recvbuf,
                              MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                              int root, MPIABI_Comm comm,
                              MPIABI_Request *request);
int (*MPIABI_Op_commutative_ptr)(MPIABI_Op op, int *commute);
int (*MPIABI_Op_create_ptr)(MPIABI_User_function *user_fn, int commute,
                            MPIABI_Op *op);
int (*MPIABI_Op_create_c_ptr)(MPIABI_User_function_c *user_fn, int commute,
                              MPIABI_Op *op);
int (*MPIABI_Op_free_ptr)(MPIABI_Op *op);
int (*MPIABI_Reduce_ptr)(const void *sendbuf, void *recvbuf, int count,
                         MPIABI_Datatype datatype, MPIABI_Op op, int root,
                         MPIABI_Comm comm);
int (*MPIABI_Reduce_c_ptr)(const void *sendbuf, void *recvbuf,
                           MPIABI_Count count, MPIABI_Datatype datatype,
                           MPIABI_Op op, int root, MPIABI_Comm comm);
int (*MPIABI_Reduce_init_ptr)(const void *sendbuf, void *recvbuf, int count,
                              MPIABI_Datatype datatype, MPIABI_Op op, int root,
                              MPIABI_Comm comm, MPIABI_Info info,
                              MPIABI_Request *request);
int (*MPIABI_Reduce_init_c_ptr)(const void *sendbuf, void *recvbuf,
                                MPIABI_Count count, MPIABI_Datatype datatype,
                                MPIABI_Op op, int root, MPIABI_Comm comm,
                                MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Reduce_local_ptr)(const void *inbuf, void *inoutbuf, int count,
                               MPIABI_Datatype datatype, MPIABI_Op op);
int (*MPIABI_Reduce_local_c_ptr)(const void *inbuf, void *inoutbuf,
                                 MPIABI_Count count, MPIABI_Datatype datatype,
                                 MPIABI_Op op);
int (*MPIABI_Reduce_scatter_ptr)(const void *sendbuf, void *recvbuf,
                                 const int recvcounts[],
                                 MPIABI_Datatype datatype, MPIABI_Op op,
                                 MPIABI_Comm comm);
int (*MPIABI_Reduce_scatter_block_ptr)(const void *sendbuf, void *recvbuf,
                                       int recvcount, MPIABI_Datatype datatype,
                                       MPIABI_Op op, MPIABI_Comm comm);
int (*MPIABI_Reduce_scatter_block_c_ptr)(const void *sendbuf, void *recvbuf,
                                         MPIABI_Count recvcount,
                                         MPIABI_Datatype datatype, MPIABI_Op op,
                                         MPIABI_Comm comm);
int (*MPIABI_Reduce_scatter_block_init_ptr)(
    const void *sendbuf, void *recvbuf, int recvcount, MPIABI_Datatype datatype,
    MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Reduce_scatter_block_init_c_ptr)(
    const void *sendbuf, void *recvbuf, MPIABI_Count recvcount,
    MPIABI_Datatype datatype, MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request);
int (*MPIABI_Reduce_scatter_c_ptr)(const void *sendbuf, void *recvbuf,
                                   const MPIABI_Count recvcounts[],
                                   MPIABI_Datatype datatype, MPIABI_Op op,
                                   MPIABI_Comm comm);
int (*MPIABI_Reduce_scatter_init_ptr)(const void *sendbuf, void *recvbuf,
                                      const int recvcounts[],
                                      MPIABI_Datatype datatype, MPIABI_Op op,
                                      MPIABI_Comm comm, MPIABI_Info info,
                                      MPIABI_Request *request);
int (*MPIABI_Reduce_scatter_init_c_ptr)(const void *sendbuf, void *recvbuf,
                                        const MPIABI_Count recvcounts[],
                                        MPIABI_Datatype datatype, MPIABI_Op op,
                                        MPIABI_Comm comm, MPIABI_Info info,
                                        MPIABI_Request *request);
int (*MPIABI_Scan_ptr)(const void *sendbuf, void *recvbuf, int count,
                       MPIABI_Datatype datatype, MPIABI_Op op,
                       MPIABI_Comm comm);
int (*MPIABI_Scan_c_ptr)(const void *sendbuf, void *recvbuf, MPIABI_Count count,
                         MPIABI_Datatype datatype, MPIABI_Op op,
                         MPIABI_Comm comm);
int (*MPIABI_Scan_init_ptr)(const void *sendbuf, void *recvbuf, int count,
                            MPIABI_Datatype datatype, MPIABI_Op op,
                            MPIABI_Comm comm, MPIABI_Info info,
                            MPIABI_Request *request);
int (*MPIABI_Scan_init_c_ptr)(const void *sendbuf, void *recvbuf,
                              MPIABI_Count count, MPIABI_Datatype datatype,
                              MPIABI_Op op, MPIABI_Comm comm, MPIABI_Info info,
                              MPIABI_Request *request);
int (*MPIABI_Scatter_ptr)(const void *sendbuf, int sendcount,
                          MPIABI_Datatype sendtype, void *recvbuf,
                          int recvcount, MPIABI_Datatype recvtype, int root,
                          MPIABI_Comm comm);
int (*MPIABI_Scatter_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                            MPIABI_Datatype sendtype, void *recvbuf,
                            MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                            int root, MPIABI_Comm comm);
int (*MPIABI_Scatter_init_ptr)(const void *sendbuf, int sendcount,
                               MPIABI_Datatype sendtype, void *recvbuf,
                               int recvcount, MPIABI_Datatype recvtype,
                               int root, MPIABI_Comm comm, MPIABI_Info info,
                               MPIABI_Request *request);
int (*MPIABI_Scatter_init_c_ptr)(const void *sendbuf, MPIABI_Count sendcount,
                                 MPIABI_Datatype sendtype, void *recvbuf,
                                 MPIABI_Count recvcount,
                                 MPIABI_Datatype recvtype, int root,
                                 MPIABI_Comm comm, MPIABI_Info info,
                                 MPIABI_Request *request);
int (*MPIABI_Scatterv_ptr)(const void *sendbuf, const int sendcounts[],
                           const int displs[], MPIABI_Datatype sendtype,
                           void *recvbuf, int recvcount,
                           MPIABI_Datatype recvtype, int root,
                           MPIABI_Comm comm);
int (*MPIABI_Scatterv_c_ptr)(const void *sendbuf,
                             const MPIABI_Count sendcounts[],
                             const MPIABI_Aint displs[],
                             MPIABI_Datatype sendtype, void *recvbuf,
                             MPIABI_Count recvcount, MPIABI_Datatype recvtype,
                             int root, MPIABI_Comm comm);
int (*MPIABI_Scatterv_init_ptr)(const void *sendbuf, const int sendcounts[],
                                const int displs[], MPIABI_Datatype sendtype,
                                void *recvbuf, int recvcount,
                                MPIABI_Datatype recvtype, int root,
                                MPIABI_Comm comm, MPIABI_Info info,
                                MPIABI_Request *request);
int (*MPIABI_Scatterv_init_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint displs[], MPIABI_Datatype sendtype, void *recvbuf,
    MPIABI_Count recvcount, MPIABI_Datatype recvtype, int root,
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Type_get_value_index_ptr)(MPIABI_Datatype value_type,
                                       MPIABI_Datatype index_type,
                                       MPIABI_Datatype *pair_type);

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

int (*MPIABI_Comm_compare_ptr)(MPIABI_Comm comm1, MPIABI_Comm comm2,
                               int *result);
int (*MPIABI_Comm_create_ptr)(MPIABI_Comm comm, MPIABI_Group group,
                              MPIABI_Comm *newcomm);
int (*MPIABI_Comm_create_from_group_ptr)(MPIABI_Group group,
                                         const char *stringtag,
                                         MPIABI_Info info,
                                         MPIABI_Errhandler errhandler,
                                         MPIABI_Comm *newcomm);
int (*MPIABI_Comm_create_group_ptr)(MPIABI_Comm comm, MPIABI_Group group,
                                    int tag, MPIABI_Comm *newcomm);
int (*MPIABI_Comm_create_keyval_ptr)(
    MPIABI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPIABI_Comm_delete_attr_function *comm_delete_attr_fn, int *comm_keyval,
    void *extra_state);
int (*MPIABI_Comm_delete_attr_ptr)(MPIABI_Comm comm, int comm_keyval);
int (*MPIABI_Comm_dup_ptr)(MPIABI_Comm comm, MPIABI_Comm *newcomm);
int (*MPIABI_Comm_dup_with_info_ptr)(MPIABI_Comm comm, MPIABI_Info info,
                                     MPIABI_Comm *newcomm);
int (*MPIABI_Comm_free_ptr)(MPIABI_Comm *comm);
int (*MPIABI_Comm_get_name_ptr)(MPIABI_Comm comm, char *comm_name,
                                int *resultlen);
int (*MPIABI_Comm_free_keyval_ptr)(int *comm_keyval);
int (*MPIABI_Comm_get_attr_ptr)(MPIABI_Comm comm, int comm_keyval,
                                void *attribute_val, int *flag);
int (*MPIABI_Comm_get_info_ptr)(MPIABI_Comm comm, MPIABI_Info *info_used);
int (*MPIABI_Comm_group_ptr)(MPIABI_Comm comm, MPIABI_Group *group);
int (*MPIABI_Comm_idup_ptr)(MPIABI_Comm comm, MPIABI_Comm *newcomm,
                            MPIABI_Request *request);
int (*MPIABI_Comm_idup_with_info_ptr)(MPIABI_Comm comm, MPIABI_Info info,
                                      MPIABI_Comm *newcomm,
                                      MPIABI_Request *request);
int (*MPIABI_Comm_rank_ptr)(MPIABI_Comm comm, int *rank);
int (*MPIABI_Comm_remote_group_ptr)(MPIABI_Comm comm, MPIABI_Group *group);
int (*MPIABI_Comm_remote_size_ptr)(MPIABI_Comm comm, int *size);
int (*MPIABI_Comm_set_attr_ptr)(MPIABI_Comm comm, int comm_keyval,
                                void *attribute_val);
int (*MPIABI_Comm_set_info_ptr)(MPIABI_Comm comm, MPIABI_Info info);
int (*MPIABI_Comm_set_name_ptr)(MPIABI_Comm comm, const char *comm_name);
int (*MPIABI_Comm_size_ptr)(MPIABI_Comm comm, int *size);
int (*MPIABI_Comm_split_ptr)(MPIABI_Comm comm, int color, int key,
                             MPIABI_Comm *newcomm);
int (*MPIABI_Group_free_ptr)(MPIABI_Group *group);
int (*MPIABI_Comm_split_type_ptr)(MPIABI_Comm comm, int split_type, int key,
                                  MPIABI_Info info, MPIABI_Comm *newcomm);
int (*MPIABI_Comm_test_inter_ptr)(MPIABI_Comm comm, int *flag);
int (*MPIABI_Group_compare_ptr)(MPIABI_Group group1, MPIABI_Group group2,
                                int *result);
int (*MPIABI_Group_difference_ptr)(MPIABI_Group group1, MPIABI_Group group2,
                                   MPIABI_Group *newgroup);
int (*MPIABI_Group_excl_ptr)(MPIABI_Group group, int n, const int ranks[],
                             MPIABI_Group *newgroup);
int (*MPIABI_Group_from_session_pset_ptr)(MPIABI_Session session,
                                          const char *pset_name,
                                          MPIABI_Group *newgroup);
int (*MPIABI_Group_incl_ptr)(MPIABI_Group group, int n, const int ranks[],
                             MPIABI_Group *newgroup);
int (*MPIABI_Group_intersection_ptr)(MPIABI_Group group1, MPIABI_Group group2,
                                     MPIABI_Group *newgroup);
int (*MPIABI_Group_range_excl_ptr)(MPIABI_Group group, int n, int ranges[][3],
                                   MPIABI_Group *newgroup);
int (*MPIABI_Group_range_incl_ptr)(MPIABI_Group group, int n, int ranges[][3],
                                   MPIABI_Group *newgroup);
int (*MPIABI_Group_rank_ptr)(MPIABI_Group group, int *rank);
int (*MPIABI_Group_size_ptr)(MPIABI_Group group, int *size);
int (*MPIABI_Group_translate_ranks_ptr)(MPIABI_Group group1, int n,
                                        const int ranks1[], MPIABI_Group group2,
                                        int ranks2[]);
int (*MPIABI_Group_union_ptr)(MPIABI_Group group1, MPIABI_Group group2,
                              MPIABI_Group *newgroup);
int (*MPIABI_Intercomm_create_ptr)(MPIABI_Comm local_comm, int local_leader,
                                   MPIABI_Comm peer_comm, int remote_leader,
                                   int tag, MPIABI_Comm *newintercomm);
int (*MPIABI_Intercomm_create_from_groups_ptr)(
    MPIABI_Group local_group, int local_leader, MPIABI_Group remote_group,
    int remote_leader, const char *stringtag, MPIABI_Info info,
    MPIABI_Errhandler errhandler, MPIABI_Comm *newintercomm);
int (*MPIABI_Intercomm_merge_ptr)(MPIABI_Comm intercomm, int high,
                                  MPIABI_Comm *newintracomm);
int (*MPIABI_Type_create_keyval_ptr)(
    MPIABI_Type_copy_attr_function *type_copy_attr_fn,
    MPIABI_Type_delete_attr_function *type_delete_attr_fn, int *type_keyval,
    void *extra_state);
int (*MPIABI_Type_delete_attr_ptr)(MPIABI_Datatype datatype, int type_keyval);
int (*MPIABI_Type_free_keyval_ptr)(int *type_keyval);
int (*MPIABI_Type_get_attr_ptr)(MPIABI_Datatype datatype, int type_keyval,
                                void *attribute_val, int *flag);
int (*MPIABI_Type_get_name_ptr)(MPIABI_Datatype datatype, char *type_name,
                                int *resultlen);
int (*MPIABI_Type_set_attr_ptr)(MPIABI_Datatype datatype, int type_keyval,
                                void *attribute_val);
int (*MPIABI_Type_set_name_ptr)(MPIABI_Datatype datatype,
                                const char *type_name);
int (*MPIABI_Win_create_keyval_ptr)(
    MPIABI_Win_copy_attr_function *win_copy_attr_fn,
    MPIABI_Win_delete_attr_function *win_delete_attr_fn, int *win_keyval,
    void *extra_state);
int (*MPIABI_Win_delete_attr_ptr)(MPIABI_Win win, int win_keyval);
int (*MPIABI_Win_free_keyval_ptr)(int *win_keyval);
int (*MPIABI_Win_get_attr_ptr)(MPIABI_Win win, int win_keyval,
                               void *attribute_val, int *flag);
int (*MPIABI_Win_get_name_ptr)(MPIABI_Win win, char *win_name, int *resultlen);
int (*MPIABI_Win_set_attr_ptr)(MPIABI_Win win, int win_keyval,
                               void *attribute_val);
int (*MPIABI_Win_set_name_ptr)(MPIABI_Win win, const char *win_name);

// A.3.6 Virtual Topologies for MPI Processes C Bindings

int (*MPIABI_Cart_coords_ptr)(MPIABI_Comm comm, int rank, int maxdims,
                              int coords[]);
int (*MPIABI_Cart_create_ptr)(MPIABI_Comm comm_old, int ndims, const int dims[],
                              const int periods[], int reorder,
                              MPIABI_Comm *comm_cart);
int (*MPIABI_Cart_get_ptr)(MPIABI_Comm comm, int maxdims, int dims[],
                           int periods[], int coords[]);
int (*MPIABI_Cart_map_ptr)(MPIABI_Comm comm, int ndims, const int dims[],
                           const int periods[], int *newrank);
int (*MPIABI_Cart_rank_ptr)(MPIABI_Comm comm, const int coords[], int *rank);
int (*MPIABI_Cart_shift_ptr)(MPIABI_Comm comm, int direction, int disp,
                             int *rank_source, int *rank_dest);
int (*MPIABI_Cart_sub_ptr)(MPIABI_Comm comm, const int remain_dims[],
                           MPIABI_Comm *newcomm);
int (*MPIABI_Cartdim_get_ptr)(MPIABI_Comm comm, int *ndims);
int (*MPIABI_Dims_create_ptr)(int nnodes, int ndims, int dims[]);
int (*MPIABI_Dist_graph_create_ptr)(MPIABI_Comm comm_old, int n,
                                    const int sources[], const int degrees[],
                                    const int destinations[],
                                    const int weights[], MPIABI_Info info,
                                    int reorder, MPIABI_Comm *comm_dist_graph);
int (*MPIABI_Dist_graph_create_adjacent_ptr)(
    MPIABI_Comm comm_old, int indegree, const int sources[],
    const int sourceweights[], int outdegree, const int destinations[],
    const int destweights[], MPIABI_Info info, int reorder,
    MPIABI_Comm *comm_dist_graph);
int (*MPIABI_Dist_graph_neighbors_ptr)(MPIABI_Comm comm, int maxindegree,
                                       int sources[], int sourceweights[],
                                       int maxoutdegree, int destinations[],
                                       int destweights[]);
int (*MPIABI_Dist_graph_neighbors_count_ptr)(MPIABI_Comm comm, int *indegree,
                                             int *outdegree, int *weighted);
int (*MPIABI_Graph_create_ptr)(MPIABI_Comm comm_old, int nnodes,
                               const int index[], const int edges[],
                               int reorder, MPIABI_Comm *comm_graph);
int (*MPIABI_Graph_get_ptr)(MPIABI_Comm comm, int maxindex, int maxedges,
                            int index[], int edges[]);
int (*MPIABI_Graph_map_ptr)(MPIABI_Comm comm, int nnodes, const int index[],
                            const int edges[], int *newrank);
int (*MPIABI_Graph_neighbors_ptr)(MPIABI_Comm comm, int rank, int maxneighbors,
                                  int neighbors[]);
int (*MPIABI_Graph_neighbors_count_ptr)(MPIABI_Comm comm, int rank,
                                        int *nneighbors);
int (*MPIABI_Graphdims_get_ptr)(MPIABI_Comm comm, int *nnodes, int *nedges);
int (*MPIABI_Ineighbor_allgather_ptr)(const void *sendbuf, int sendcount,
                                      MPIABI_Datatype sendtype, void *recvbuf,
                                      int recvcount, MPIABI_Datatype recvtype,
                                      MPIABI_Comm comm,
                                      MPIABI_Request *request);
int (*MPIABI_Ineighbor_allgather_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, MPIABI_Count recvcount, MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_allgatherv_ptr)(
    const void *sendbuf, int sendcount, MPIABI_Datatype sendtype, void *recvbuf,
    const int recvcounts[], const int displs[], MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_allgatherv_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint displs[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_alltoall_ptr)(const void *sendbuf, int sendcount,
                                     MPIABI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPIABI_Datatype recvtype,
                                     MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_alltoall_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, MPIABI_Count recvcount, MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_alltoallv_ptr)(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPIABI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPIABI_Datatype recvtype, MPIABI_Comm comm,
    MPIABI_Request *request);
int (*MPIABI_Ineighbor_alltoallv_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
    const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_alltoallw_ptr)(
    const void *sendbuf, const int sendcounts[], const MPIABI_Aint sdispls[],
    const MPIABI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPIABI_Aint rdispls[], const MPIABI_Datatype recvtypes[],
    MPIABI_Comm comm, MPIABI_Request *request);
int (*MPIABI_Ineighbor_alltoallw_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm,
    MPIABI_Request *request);
int (*MPIABI_Neighbor_allgather_ptr)(const void *sendbuf, int sendcount,
                                     MPIABI_Datatype sendtype, void *recvbuf,
                                     int recvcount, MPIABI_Datatype recvtype,
                                     MPIABI_Comm comm);
int (*MPIABI_Neighbor_allgather_c_ptr)(const void *sendbuf,
                                       MPIABI_Count sendcount,
                                       MPIABI_Datatype sendtype, void *recvbuf,
                                       MPIABI_Count recvcount,
                                       MPIABI_Datatype recvtype,
                                       MPIABI_Comm comm);
int (*MPIABI_Neighbor_allgather_init_ptr)(const void *sendbuf, int sendcount,
                                          MPIABI_Datatype sendtype,
                                          void *recvbuf, int recvcount,
                                          MPIABI_Datatype recvtype,
                                          MPIABI_Comm comm, MPIABI_Info info,
                                          MPIABI_Request *request);
int (*MPIABI_Neighbor_allgather_init_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, MPIABI_Count recvcount, MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Neighbor_allgatherv_ptr)(const void *sendbuf, int sendcount,
                                      MPIABI_Datatype sendtype, void *recvbuf,
                                      const int recvcounts[],
                                      const int displs[],
                                      MPIABI_Datatype recvtype,
                                      MPIABI_Comm comm);
int (*MPIABI_Neighbor_allgatherv_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint displs[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm);
int (*MPIABI_Neighbor_allgatherv_init_ptr)(
    const void *sendbuf, int sendcount, MPIABI_Datatype sendtype, void *recvbuf,
    const int recvcounts[], const int displs[], MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Neighbor_allgatherv_init_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint displs[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request);
int (*MPIABI_Neighbor_alltoall_ptr)(const void *sendbuf, int sendcount,
                                    MPIABI_Datatype sendtype, void *recvbuf,
                                    int recvcount, MPIABI_Datatype recvtype,
                                    MPIABI_Comm comm);
int (*MPIABI_Neighbor_alltoall_c_ptr)(const void *sendbuf,
                                      MPIABI_Count sendcount,
                                      MPIABI_Datatype sendtype, void *recvbuf,
                                      MPIABI_Count recvcount,
                                      MPIABI_Datatype recvtype,
                                      MPIABI_Comm comm);
int (*MPIABI_Neighbor_alltoall_init_ptr)(const void *sendbuf, int sendcount,
                                         MPIABI_Datatype sendtype,
                                         void *recvbuf, int recvcount,
                                         MPIABI_Datatype recvtype,
                                         MPIABI_Comm comm, MPIABI_Info info,
                                         MPIABI_Request *request);
int (*MPIABI_Neighbor_alltoall_init_c_ptr)(
    const void *sendbuf, MPIABI_Count sendcount, MPIABI_Datatype sendtype,
    void *recvbuf, MPIABI_Count recvcount, MPIABI_Datatype recvtype,
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Neighbor_alltoallv_ptr)(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPIABI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPIABI_Datatype recvtype, MPIABI_Comm comm);
int (*MPIABI_Neighbor_alltoallv_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
    const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm);
int (*MPIABI_Neighbor_alltoallv_init_ptr)(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPIABI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPIABI_Datatype recvtype, MPIABI_Comm comm,
    MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Neighbor_alltoallv_init_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], MPIABI_Datatype sendtype, void *recvbuf,
    const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    MPIABI_Datatype recvtype, MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request);
int (*MPIABI_Neighbor_alltoallw_ptr)(
    const void *sendbuf, const int sendcounts[], const MPIABI_Aint sdispls[],
    const MPIABI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPIABI_Aint rdispls[], const MPIABI_Datatype recvtypes[],
    MPIABI_Comm comm);
int (*MPIABI_Neighbor_alltoallw_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm);
int (*MPIABI_Neighbor_alltoallw_init_ptr)(
    const void *sendbuf, const int sendcounts[], const MPIABI_Aint sdispls[],
    const MPIABI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPIABI_Aint rdispls[], const MPIABI_Datatype recvtypes[],
    MPIABI_Comm comm, MPIABI_Info info, MPIABI_Request *request);
int (*MPIABI_Neighbor_alltoallw_init_c_ptr)(
    const void *sendbuf, const MPIABI_Count sendcounts[],
    const MPIABI_Aint sdispls[], const MPIABI_Datatype sendtypes[],
    void *recvbuf, const MPIABI_Count recvcounts[], const MPIABI_Aint rdispls[],
    const MPIABI_Datatype recvtypes[], MPIABI_Comm comm, MPIABI_Info info,
    MPIABI_Request *request);
int (*MPIABI_Topo_test_ptr)(MPIABI_Comm comm, int *status);

// A.3.7 MPI Environmental Management C Bindings

int (*MPIABI_Add_error_class_ptr)(int *errorclass);
int (*MPIABI_Add_error_code_ptr)(int errorclass, int *errorcode);
int (*MPIABI_Add_error_string_ptr)(int errorcode, const char *string);
int (*MPIABI_Alloc_mem_ptr)(MPIABI_Aint size, MPIABI_Info info, void *baseptr);
int (*MPIABI_Comm_call_errhandler_ptr)(MPIABI_Comm comm, int errorcode);
int (*MPIABI_Comm_create_errhandler_ptr)(
    MPIABI_Comm_errhandler_function *comm_errhandler_fn,
    MPIABI_Errhandler *errhandler);
int (*MPIABI_Comm_get_errhandler_ptr)(MPIABI_Comm comm,
                                      MPIABI_Errhandler *errhandler);
int (*MPIABI_Comm_set_errhandler_ptr)(MPIABI_Comm comm,
                                      MPIABI_Errhandler errhandler);
int (*MPIABI_Errhandler_free_ptr)(MPIABI_Errhandler *errhandler);
int (*MPIABI_Error_class_ptr)(int errorcode, int *errorclass);
int (*MPIABI_Error_string_ptr)(int errorcode, char *string, int *resultlen);
int (*MPIABI_File_call_errhandler_ptr)(MPIABI_File fh, int errorcode);
int (*MPIABI_File_create_errhandler_ptr)(
    MPIABI_File_errhandler_function *file_errhandler_fn,
    MPIABI_Errhandler *errhandler);
int (*MPIABI_File_get_errhandler_ptr)(MPIABI_File file,
                                      MPIABI_Errhandler *errhandler);
int (*MPIABI_File_set_errhandler_ptr)(MPIABI_File file,
                                      MPIABI_Errhandler errhandler);
int (*MPIABI_Free_mem_ptr)(void *base);
int (*MPIABI_Get_hw_resource_info_ptr)(MPIABI_Info *hw_info);
int (*MPIABI_Get_library_version_ptr)(char *version, int *resultlen);
int (*MPIABI_Get_processor_name_ptr)(char *name, int *resultlen);
int (*MPIABI_Get_version_ptr)(int *version, int *subversion);
int (*MPIABI_Remove_error_class_ptr)(int errorclass);
int (*MPIABI_Remove_error_code_ptr)(int errorcode);
int (*MPIABI_Remove_error_string_ptr)(int errorcode);
int (*MPIABI_Session_call_errhandler_ptr)(MPIABI_Session session,
                                          int errorcode);
int (*MPIABI_Session_create_errhandler_ptr)(
    MPIABI_Session_errhandler_function *session_errhandler_fn,
    MPIABI_Errhandler *errhandler);
int (*MPIABI_Session_get_errhandler_ptr)(MPIABI_Session session,
                                         MPIABI_Errhandler *errhandler);
int (*MPIABI_Session_set_errhandler_ptr)(MPIABI_Session session,
                                         MPIABI_Errhandler errhandler);
int (*MPIABI_Win_call_errhandler_ptr)(MPIABI_Win win, int errorcode);
int (*MPIABI_Win_create_errhandler_ptr)(
    MPIABI_Win_errhandler_function *win_errhandler_fn,
    MPIABI_Errhandler *errhandler);
int (*MPIABI_Win_get_errhandler_ptr)(MPIABI_Win win,
                                     MPIABI_Errhandler *errhandler);
int (*MPIABI_Win_set_errhandler_ptr)(MPIABI_Win win,
                                     MPIABI_Errhandler errhandler);
double (*MPIABI_Wtick_ptr)(void);
double (*MPIABI_Wtime_ptr)(void);

// A.3.8 The Info Object C Bindings

int (*MPIABI_Info_create_ptr)(MPIABI_Info *info);
int (*MPIABI_Info_create_env_ptr)(int argc, char *argv[], MPIABI_Info *info);
int (*MPIABI_Info_delete_ptr)(MPIABI_Info info, const char *key);
int (*MPIABI_Info_dup_ptr)(MPIABI_Info info, MPIABI_Info *newinfo);
int (*MPIABI_Info_free_ptr)(MPIABI_Info *info);
int (*MPIABI_Info_get_nkeys_ptr)(MPIABI_Info info, int *nkeys);
int (*MPIABI_Info_get_nthkey_ptr)(MPIABI_Info info, int n, char *key);
int (*MPIABI_Info_get_string_ptr)(MPIABI_Info info, const char *key,
                                  int *buflen, char *value, int *flag);
int (*MPIABI_Info_set_ptr)(MPIABI_Info info, const char *key,
                           const char *value);

// A.3.9 Process Creation and Management C Bindings

int (*MPIABI_Abort_ptr)(MPIABI_Comm comm, int errorcode);
int (*MPIABI_Close_port_ptr)(const char *port_name);
int (*MPIABI_Comm_accept_ptr)(const char *port_name, MPIABI_Info info, int root,
                              MPIABI_Comm comm, MPIABI_Comm *newcomm);
int (*MPIABI_Comm_connect_ptr)(const char *port_name, MPIABI_Info info,
                               int root, MPIABI_Comm comm,
                               MPIABI_Comm *newcomm);
int (*MPIABI_Comm_disconnect_ptr)(MPIABI_Comm *comm);
int (*MPIABI_Comm_get_parent_ptr)(MPIABI_Comm *parent);
int (*MPIABI_Comm_join_ptr)(int fd, MPIABI_Comm *intercomm);
int (*MPIABI_Comm_spawn_ptr)(const char *command, char *argv[], int maxprocs,
                             MPIABI_Info info, int root, MPIABI_Comm comm,
                             MPIABI_Comm *intercomm, int array_of_errcodes[]);
int (*MPIABI_Comm_spawn_multiple_ptr)(
    int count, char *array_of_commands[], char **array_of_argv[],
    const int array_of_maxprocs[], const MPIABI_Info array_of_info[], int root,
    MPIABI_Comm comm, MPIABI_Comm *intercomm, int array_of_errcodes[]);
int (*MPIABI_Finalize_ptr)(void);
int (*MPIABI_Finalized_ptr)(int *flag);
int (*MPIABI_Init_ptr)(int *argc, char ***argv);
int (*MPIABI_Init_thread_ptr)(int *argc, char ***argv, int required,
                              int *provided);
int (*MPIABI_Initialized_ptr)(int *flag);
int (*MPIABI_Is_thread_main_ptr)(int *flag);
int (*MPIABI_Lookup_name_ptr)(const char *service_name, MPIABI_Info info,
                              char *port_name);
int (*MPIABI_Open_port_ptr)(MPIABI_Info info, char *port_name);
int (*MPIABI_Publish_name_ptr)(const char *service_name, MPIABI_Info info,
                               const char *port_name);
int (*MPIABI_Query_thread_ptr)(int *provided);
int (*MPIABI_Session_finalize_ptr)(MPIABI_Session *session);
int (*MPIABI_Session_get_info_ptr)(MPIABI_Session session,
                                   MPIABI_Info *info_used);
int (*MPIABI_Session_get_nth_pset_ptr)(MPIABI_Session session, MPIABI_Info info,
                                       int n, int *pset_len, char *pset_name);
int (*MPIABI_Session_get_num_psets_ptr)(MPIABI_Session session,
                                        MPIABI_Info info, int *npset_names);
int (*MPIABI_Session_get_pset_info_ptr)(MPIABI_Session session,
                                        const char *pset_name,
                                        MPIABI_Info *info);
int (*MPIABI_Session_init_ptr)(MPIABI_Info info, MPIABI_Errhandler errhandler,
                               MPIABI_Session *session);
int (*MPIABI_Unpublish_name_ptr)(const char *service_name, MPIABI_Info info,
                                 const char *port_name);

// A.3.10 One-Sided Communications C Bindings

int (*MPIABI_Accumulate_ptr)(const void *origin_addr, int origin_count,
                             MPIABI_Datatype origin_datatype, int target_rank,
                             MPIABI_Aint target_disp, int target_count,
                             MPIABI_Datatype target_datatype, MPIABI_Op op,
                             MPIABI_Win win);
int (*MPIABI_Accumulate_c_ptr)(const void *origin_addr,
                               MPIABI_Count origin_count,
                               MPIABI_Datatype origin_datatype, int target_rank,
                               MPIABI_Aint target_disp,
                               MPIABI_Count target_count,
                               MPIABI_Datatype target_datatype, MPIABI_Op op,
                               MPIABI_Win win);
int (*MPIABI_Compare_and_swap_ptr)(const void *origin_addr,
                                   const void *compare_addr, void *result_addr,
                                   MPIABI_Datatype datatype, int target_rank,
                                   MPIABI_Aint target_disp, MPIABI_Win win);
int (*MPIABI_Fetch_and_op_ptr)(const void *origin_addr, void *result_addr,
                               MPIABI_Datatype datatype, int target_rank,
                               MPIABI_Aint target_disp, MPIABI_Op op,
                               MPIABI_Win win);
int (*MPIABI_Get_ptr)(void *origin_addr, int origin_count,
                      MPIABI_Datatype origin_datatype, int target_rank,
                      MPIABI_Aint target_disp, int target_count,
                      MPIABI_Datatype target_datatype, MPIABI_Win win);
int (*MPIABI_Get_accumulate_ptr)(
    const void *origin_addr, int origin_count, MPIABI_Datatype origin_datatype,
    void *result_addr, int result_count, MPIABI_Datatype result_datatype,
    int target_rank, MPIABI_Aint target_disp, int target_count,
    MPIABI_Datatype target_datatype, MPIABI_Op op, MPIABI_Win win);
int (*MPIABI_Get_accumulate_c_ptr)(
    const void *origin_addr, MPIABI_Count origin_count,
    MPIABI_Datatype origin_datatype, void *result_addr,
    MPIABI_Count result_count, MPIABI_Datatype result_datatype, int target_rank,
    MPIABI_Aint target_disp, MPIABI_Count target_count,
    MPIABI_Datatype target_datatype, MPIABI_Op op, MPIABI_Win win);
int (*MPIABI_Get_c_ptr)(void *origin_addr, MPIABI_Count origin_count,
                        MPIABI_Datatype origin_datatype, int target_rank,
                        MPIABI_Aint target_disp, MPIABI_Count target_count,
                        MPIABI_Datatype target_datatype, MPIABI_Win win);
int (*MPIABI_Put_ptr)(const void *origin_addr, int origin_count,
                      MPIABI_Datatype origin_datatype, int target_rank,
                      MPIABI_Aint target_disp, int target_count,
                      MPIABI_Datatype target_datatype, MPIABI_Win win);
int (*MPIABI_Put_c_ptr)(const void *origin_addr, MPIABI_Count origin_count,
                        MPIABI_Datatype origin_datatype, int target_rank,
                        MPIABI_Aint target_disp, MPIABI_Count target_count,
                        MPIABI_Datatype target_datatype, MPIABI_Win win);
int (*MPIABI_Raccumulate_ptr)(const void *origin_addr, int origin_count,
                              MPIABI_Datatype origin_datatype, int target_rank,
                              MPIABI_Aint target_disp, int target_count,
                              MPIABI_Datatype target_datatype, MPIABI_Op op,
                              MPIABI_Win win, MPIABI_Request *request);
int (*MPIABI_Raccumulate_c_ptr)(const void *origin_addr,
                                MPIABI_Count origin_count,
                                MPIABI_Datatype origin_datatype,
                                int target_rank, MPIABI_Aint target_disp,
                                MPIABI_Count target_count,
                                MPIABI_Datatype target_datatype, MPIABI_Op op,
                                MPIABI_Win win, MPIABI_Request *request);
int (*MPIABI_Rget_ptr)(void *origin_addr, int origin_count,
                       MPIABI_Datatype origin_datatype, int target_rank,
                       MPIABI_Aint target_disp, int target_count,
                       MPIABI_Datatype target_datatype, MPIABI_Win win,
                       MPIABI_Request *request);
int (*MPIABI_Rget_accumulate_ptr)(const void *origin_addr, int origin_count,
                                  MPIABI_Datatype origin_datatype,
                                  void *result_addr, int result_count,
                                  MPIABI_Datatype result_datatype,
                                  int target_rank, MPIABI_Aint target_disp,
                                  int target_count,
                                  MPIABI_Datatype target_datatype, MPIABI_Op op,
                                  MPIABI_Win win, MPIABI_Request *request);
int (*MPIABI_Rget_accumulate_c_ptr)(
    const void *origin_addr, MPIABI_Count origin_count,
    MPIABI_Datatype origin_datatype, void *result_addr,
    MPIABI_Count result_count, MPIABI_Datatype result_datatype, int target_rank,
    MPIABI_Aint target_disp, MPIABI_Count target_count,
    MPIABI_Datatype target_datatype, MPIABI_Op op, MPIABI_Win win,
    MPIABI_Request *request);
int (*MPIABI_Rget_c_ptr)(void *origin_addr, MPIABI_Count origin_count,
                         MPIABI_Datatype origin_datatype, int target_rank,
                         MPIABI_Aint target_disp, MPIABI_Count target_count,
                         MPIABI_Datatype target_datatype, MPIABI_Win win,
                         MPIABI_Request *request);
int (*MPIABI_Rput_ptr)(const void *origin_addr, int origin_count,
                       MPIABI_Datatype origin_datatype, int target_rank,
                       MPIABI_Aint target_disp, int target_count,
                       MPIABI_Datatype target_datatype, MPIABI_Win win,
                       MPIABI_Request *request);
int (*MPIABI_Rput_c_ptr)(const void *origin_addr, MPIABI_Count origin_count,
                         MPIABI_Datatype origin_datatype, int target_rank,
                         MPIABI_Aint target_disp, MPIABI_Count target_count,
                         MPIABI_Datatype target_datatype, MPIABI_Win win,
                         MPIABI_Request *request);
int (*MPIABI_Win_allocate_ptr)(MPIABI_Aint size, int disp_unit,
                               MPIABI_Info info, MPIABI_Comm comm,
                               void *baseptr, MPIABI_Win *win);
int (*MPIABI_Win_allocate_c_ptr)(MPIABI_Aint size, MPIABI_Aint disp_unit,
                                 MPIABI_Info info, MPIABI_Comm comm,
                                 void *baseptr, MPIABI_Win *win);
int (*MPIABI_Win_allocate_shared_ptr)(MPIABI_Aint size, int disp_unit,
                                      MPIABI_Info info, MPIABI_Comm comm,
                                      void *baseptr, MPIABI_Win *win);
int (*MPIABI_Win_allocate_shared_c_ptr)(MPIABI_Aint size, MPIABI_Aint disp_unit,
                                        MPIABI_Info info, MPIABI_Comm comm,
                                        void *baseptr, MPIABI_Win *win);
int (*MPIABI_Win_attach_ptr)(MPIABI_Win win, void *base, MPIABI_Aint size);
int (*MPIABI_Win_complete_ptr)(MPIABI_Win win);
int (*MPIABI_Win_create_ptr)(void *base, MPIABI_Aint size, int disp_unit,
                             MPIABI_Info info, MPIABI_Comm comm,
                             MPIABI_Win *win);
int (*MPIABI_Win_create_c_ptr)(void *base, MPIABI_Aint size,
                               MPIABI_Aint disp_unit, MPIABI_Info info,
                               MPIABI_Comm comm, MPIABI_Win *win);
int (*MPIABI_Win_create_dynamic_ptr)(MPIABI_Info info, MPIABI_Comm comm,
                                     MPIABI_Win *win);
int (*MPIABI_Win_detach_ptr)(MPIABI_Win win, const void *base);
int (*MPIABI_Win_fence_ptr)(int assert, MPIABI_Win win);
int (*MPIABI_Win_flush_ptr)(int rank, MPIABI_Win win);
int (*MPIABI_Win_flush_all_ptr)(MPIABI_Win win);
int (*MPIABI_Win_flush_local_ptr)(int rank, MPIABI_Win win);
int (*MPIABI_Win_flush_local_all_ptr)(MPIABI_Win win);
int (*MPIABI_Win_free_ptr)(MPIABI_Win *win);
int (*MPIABI_Win_get_group_ptr)(MPIABI_Win win, MPIABI_Group *group);
int (*MPIABI_Win_get_info_ptr)(MPIABI_Win win, MPIABI_Info *info_used);
int (*MPIABI_Win_lock_ptr)(int lock_type, int rank, int assert, MPIABI_Win win);
int (*MPIABI_Win_lock_all_ptr)(int assert, MPIABI_Win win);
int (*MPIABI_Win_post_ptr)(MPIABI_Group group, int assert, MPIABI_Win win);
int (*MPIABI_Win_set_info_ptr)(MPIABI_Win win, MPIABI_Info info);
int (*MPIABI_Win_shared_query_ptr)(MPIABI_Win win, int rank, MPIABI_Aint *size,
                                   int *disp_unit, void *baseptr);
int (*MPIABI_Win_shared_query_c_ptr)(MPIABI_Win win, int rank,
                                     MPIABI_Aint *size, MPIABI_Aint *disp_unit,
                                     void *baseptr);
int (*MPIABI_Win_start_ptr)(MPIABI_Group group, int assert, MPIABI_Win win);
int (*MPIABI_Win_sync_ptr)(MPIABI_Win win);
int (*MPIABI_Win_test_ptr)(MPIABI_Win win, int *flag);
int (*MPIABI_Win_unlock_ptr)(int rank, MPIABI_Win win);
int (*MPIABI_Win_unlock_all_ptr)(MPIABI_Win win);
int (*MPIABI_Win_wait_ptr)(MPIABI_Win win);

// A.3.11 External Interfaces C Bindings

int (*MPIABI_Grequest_complete_ptr)(MPIABI_Request request);
int (*MPIABI_Grequest_start_ptr)(MPIABI_Grequest_query_function *query_fn,
                                 MPIABI_Grequest_free_function *free_fn,
                                 MPIABI_Grequest_cancel_function *cancel_fn,
                                 void *extra_state, MPIABI_Request *request);
int (*MPIABI_Status_set_cancelled_ptr)(MPIABI_Status *status, int flag);
int (*MPIABI_Status_set_elements_ptr)(MPIABI_Status *status,
                                      MPIABI_Datatype datatype, int count);
int (*MPIABI_Status_set_elements_c_ptr)(MPIABI_Status *status,
                                        MPIABI_Datatype datatype,
                                        MPIABI_Count count);
int (*MPIABI_Status_set_error_ptr)(MPIABI_Status *status, int err);
int (*MPIABI_Status_set_source_ptr)(MPIABI_Status *status, int source);
int (*MPIABI_Status_set_tag_ptr)(MPIABI_Status *status, int tag);

// A.3.12 I/O C Bindings

int (*MPIABI_File_close_ptr)(MPIABI_File *fh);
int (*MPIABI_File_delete_ptr)(const char *filename, MPIABI_Info info);
int (*MPIABI_File_get_amode_ptr)(MPIABI_File fh, int *amode);
int (*MPIABI_File_get_atomicity_ptr)(MPIABI_File fh, int *flag);
int (*MPIABI_File_get_byte_offset_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                       MPIABI_Offset *disp);
int (*MPIABI_File_get_group_ptr)(MPIABI_File fh, MPIABI_Group *group);
int (*MPIABI_File_get_info_ptr)(MPIABI_File fh, MPIABI_Info *info_used);
int (*MPIABI_File_get_position_ptr)(MPIABI_File fh, MPIABI_Offset *offset);
int (*MPIABI_File_get_position_shared_ptr)(MPIABI_File fh,
                                           MPIABI_Offset *offset);
int (*MPIABI_File_get_size_ptr)(MPIABI_File fh, MPIABI_Offset *size);
int (*MPIABI_File_get_type_extent_ptr)(MPIABI_File fh, MPIABI_Datatype datatype,
                                       MPIABI_Aint *extent);
int (*MPIABI_File_get_type_extent_c_ptr)(MPIABI_File fh,
                                         MPIABI_Datatype datatype,
                                         MPIABI_Count *extent);
int (*MPIABI_File_get_view_ptr)(MPIABI_File fh, MPIABI_Offset *disp,
                                MPIABI_Datatype *etype,
                                MPIABI_Datatype *filetype, char *datarep);
int (*MPIABI_File_iread_ptr)(MPIABI_File fh, void *buf, int count,
                             MPIABI_Datatype datatype, MPIABI_Request *request);
int (*MPIABI_File_iread_all_ptr)(MPIABI_File fh, void *buf, int count,
                                 MPIABI_Datatype datatype,
                                 MPIABI_Request *request);
int (*MPIABI_File_iread_all_c_ptr)(MPIABI_File fh, void *buf,
                                   MPIABI_Count count, MPIABI_Datatype datatype,
                                   MPIABI_Request *request);
int (*MPIABI_File_iread_at_ptr)(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                                int count, MPIABI_Datatype datatype,
                                MPIABI_Request *request);
int (*MPIABI_File_iread_at_all_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                    void *buf, int count,
                                    MPIABI_Datatype datatype,
                                    MPIABI_Request *request);
int (*MPIABI_File_iread_at_all_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                      void *buf, MPIABI_Count count,
                                      MPIABI_Datatype datatype,
                                      MPIABI_Request *request);
int (*MPIABI_File_iread_at_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                  void *buf, MPIABI_Count count,
                                  MPIABI_Datatype datatype,
                                  MPIABI_Request *request);
int (*MPIABI_File_iread_c_ptr)(MPIABI_File fh, void *buf, MPIABI_Count count,
                               MPIABI_Datatype datatype,
                               MPIABI_Request *request);
int (*MPIABI_File_iread_shared_ptr)(MPIABI_File fh, void *buf, int count,
                                    MPIABI_Datatype datatype,
                                    MPIABI_Request *request);
int (*MPIABI_File_iread_shared_c_ptr)(MPIABI_File fh, void *buf,
                                      MPIABI_Count count,
                                      MPIABI_Datatype datatype,
                                      MPIABI_Request *request);
int (*MPIABI_File_iwrite_ptr)(MPIABI_File fh, const void *buf, int count,
                              MPIABI_Datatype datatype,
                              MPIABI_Request *request);
int (*MPIABI_File_iwrite_all_ptr)(MPIABI_File fh, const void *buf, int count,
                                  MPIABI_Datatype datatype,
                                  MPIABI_Request *request);
int (*MPIABI_File_iwrite_all_c_ptr)(MPIABI_File fh, const void *buf,
                                    MPIABI_Count count,
                                    MPIABI_Datatype datatype,
                                    MPIABI_Request *request);
int (*MPIABI_File_iwrite_at_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                 const void *buf, int count,
                                 MPIABI_Datatype datatype,
                                 MPIABI_Request *request);
int (*MPIABI_File_iwrite_at_all_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                     const void *buf, int count,
                                     MPIABI_Datatype datatype,
                                     MPIABI_Request *request);
int (*MPIABI_File_iwrite_at_all_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                       const void *buf, MPIABI_Count count,
                                       MPIABI_Datatype datatype,
                                       MPIABI_Request *request);
int (*MPIABI_File_iwrite_at_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                   const void *buf, MPIABI_Count count,
                                   MPIABI_Datatype datatype,
                                   MPIABI_Request *request);
int (*MPIABI_File_iwrite_c_ptr)(MPIABI_File fh, const void *buf,
                                MPIABI_Count count, MPIABI_Datatype datatype,
                                MPIABI_Request *request);
int (*MPIABI_File_iwrite_shared_ptr)(MPIABI_File fh, const void *buf, int count,
                                     MPIABI_Datatype datatype,
                                     MPIABI_Request *request);
int (*MPIABI_File_iwrite_shared_c_ptr)(MPIABI_File fh, const void *buf,
                                       MPIABI_Count count,
                                       MPIABI_Datatype datatype,
                                       MPIABI_Request *request);
int (*MPIABI_File_open_ptr)(MPIABI_Comm comm, const char *filename, int amode,
                            MPIABI_Info info, MPIABI_File *fh);
int (*MPIABI_File_preallocate_ptr)(MPIABI_File fh, MPIABI_Offset size);
int (*MPIABI_File_read_ptr)(MPIABI_File fh, void *buf, int count,
                            MPIABI_Datatype datatype, MPIABI_Status *status);
int (*MPIABI_File_read_all_ptr)(MPIABI_File fh, void *buf, int count,
                                MPIABI_Datatype datatype,
                                MPIABI_Status *status);
int (*MPIABI_File_read_all_begin_ptr)(MPIABI_File fh, void *buf, int count,
                                      MPIABI_Datatype datatype);
int (*MPIABI_File_read_all_begin_c_ptr)(MPIABI_File fh, void *buf,
                                        MPIABI_Count count,
                                        MPIABI_Datatype datatype);
int (*MPIABI_File_read_all_c_ptr)(MPIABI_File fh, void *buf, MPIABI_Count count,
                                  MPIABI_Datatype datatype,
                                  MPIABI_Status *status);
int (*MPIABI_File_read_all_end_ptr)(MPIABI_File fh, void *buf,
                                    MPIABI_Status *status);
int (*MPIABI_File_read_at_ptr)(MPIABI_File fh, MPIABI_Offset offset, void *buf,
                               int count, MPIABI_Datatype datatype,
                               MPIABI_Status *status);
int (*MPIABI_File_read_at_all_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                   void *buf, int count,
                                   MPIABI_Datatype datatype,
                                   MPIABI_Status *status);
int (*MPIABI_File_read_at_all_begin_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                         void *buf, int count,
                                         MPIABI_Datatype datatype);
int (*MPIABI_File_read_at_all_begin_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                           void *buf, MPIABI_Count count,
                                           MPIABI_Datatype datatype);
int (*MPIABI_File_read_at_all_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                     void *buf, MPIABI_Count count,
                                     MPIABI_Datatype datatype,
                                     MPIABI_Status *status);
int (*MPIABI_File_read_at_all_end_ptr)(MPIABI_File fh, void *buf,
                                       MPIABI_Status *status);
int (*MPIABI_File_read_at_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                 void *buf, MPIABI_Count count,
                                 MPIABI_Datatype datatype,
                                 MPIABI_Status *status);
int (*MPIABI_File_read_c_ptr)(MPIABI_File fh, void *buf, MPIABI_Count count,
                              MPIABI_Datatype datatype, MPIABI_Status *status);
int (*MPIABI_File_read_ordered_ptr)(MPIABI_File fh, void *buf, int count,
                                    MPIABI_Datatype datatype,
                                    MPIABI_Status *status);
int (*MPIABI_File_read_ordered_begin_ptr)(MPIABI_File fh, void *buf, int count,
                                          MPIABI_Datatype datatype);
int (*MPIABI_File_read_ordered_begin_c_ptr)(MPIABI_File fh, void *buf,
                                            MPIABI_Count count,
                                            MPIABI_Datatype datatype);
int (*MPIABI_File_read_ordered_c_ptr)(MPIABI_File fh, void *buf,
                                      MPIABI_Count count,
                                      MPIABI_Datatype datatype,
                                      MPIABI_Status *status);
int (*MPIABI_File_read_ordered_end_ptr)(MPIABI_File fh, void *buf,
                                        MPIABI_Status *status);
int (*MPIABI_File_read_shared_ptr)(MPIABI_File fh, void *buf, int count,
                                   MPIABI_Datatype datatype,
                                   MPIABI_Status *status);
int (*MPIABI_File_read_shared_c_ptr)(MPIABI_File fh, void *buf,
                                     MPIABI_Count count,
                                     MPIABI_Datatype datatype,
                                     MPIABI_Status *status);
int (*MPIABI_File_seek_ptr)(MPIABI_File fh, MPIABI_Offset offset, int whence);
int (*MPIABI_File_seek_shared_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                   int whence);
int (*MPIABI_File_set_atomicity_ptr)(MPIABI_File fh, int flag);
int (*MPIABI_File_set_info_ptr)(MPIABI_File fh, MPIABI_Info info);
int (*MPIABI_File_set_size_ptr)(MPIABI_File fh, MPIABI_Offset size);
int (*MPIABI_File_set_view_ptr)(MPIABI_File fh, MPIABI_Offset disp,
                                MPIABI_Datatype etype, MPIABI_Datatype filetype,
                                const char *datarep, MPIABI_Info info);
int (*MPIABI_File_sync_ptr)(MPIABI_File fh);
int (*MPIABI_File_write_ptr)(MPIABI_File fh, const void *buf, int count,
                             MPIABI_Datatype datatype, MPIABI_Status *status);
int (*MPIABI_File_write_all_ptr)(MPIABI_File fh, const void *buf, int count,
                                 MPIABI_Datatype datatype,
                                 MPIABI_Status *status);
int (*MPIABI_File_write_all_begin_ptr)(MPIABI_File fh, const void *buf,
                                       int count, MPIABI_Datatype datatype);
int (*MPIABI_File_write_all_begin_c_ptr)(MPIABI_File fh, const void *buf,
                                         MPIABI_Count count,
                                         MPIABI_Datatype datatype);
int (*MPIABI_File_write_all_c_ptr)(MPIABI_File fh, const void *buf,
                                   MPIABI_Count count, MPIABI_Datatype datatype,
                                   MPIABI_Status *status);
int (*MPIABI_File_write_all_end_ptr)(MPIABI_File fh, const void *buf,
                                     MPIABI_Status *status);
int (*MPIABI_File_write_at_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                const void *buf, int count,
                                MPIABI_Datatype datatype,
                                MPIABI_Status *status);
int (*MPIABI_File_write_at_all_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                    const void *buf, int count,
                                    MPIABI_Datatype datatype,
                                    MPIABI_Status *status);
int (*MPIABI_File_write_at_all_begin_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                          const void *buf, int count,
                                          MPIABI_Datatype datatype);
int (*MPIABI_File_write_at_all_begin_c_ptr)(MPIABI_File fh,
                                            MPIABI_Offset offset,
                                            const void *buf, MPIABI_Count count,
                                            MPIABI_Datatype datatype);
int (*MPIABI_File_write_at_all_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                      const void *buf, MPIABI_Count count,
                                      MPIABI_Datatype datatype,
                                      MPIABI_Status *status);
int (*MPIABI_File_write_at_all_end_ptr)(MPIABI_File fh, const void *buf,
                                        MPIABI_Status *status);
int (*MPIABI_File_write_at_c_ptr)(MPIABI_File fh, MPIABI_Offset offset,
                                  const void *buf, MPIABI_Count count,
                                  MPIABI_Datatype datatype,
                                  MPIABI_Status *status);
int (*MPIABI_File_write_c_ptr)(MPIABI_File fh, const void *buf,
                               MPIABI_Count count, MPIABI_Datatype datatype,
                               MPIABI_Status *status);
int (*MPIABI_File_write_ordered_ptr)(MPIABI_File fh, const void *buf, int count,
                                     MPIABI_Datatype datatype,
                                     MPIABI_Status *status);
int (*MPIABI_File_write_ordered_begin_ptr)(MPIABI_File fh, const void *buf,
                                           int count, MPIABI_Datatype datatype);
int (*MPIABI_File_write_ordered_begin_c_ptr)(MPIABI_File fh, const void *buf,
                                             MPIABI_Count count,
                                             MPIABI_Datatype datatype);
int (*MPIABI_File_write_ordered_c_ptr)(MPIABI_File fh, const void *buf,
                                       MPIABI_Count count,
                                       MPIABI_Datatype datatype,
                                       MPIABI_Status *status);
int (*MPIABI_File_write_ordered_end_ptr)(MPIABI_File fh, const void *buf,
                                         MPIABI_Status *status);
int (*MPIABI_File_write_shared_ptr)(MPIABI_File fh, const void *buf, int count,
                                    MPIABI_Datatype datatype,
                                    MPIABI_Status *status);
int (*MPIABI_File_write_shared_c_ptr)(MPIABI_File fh, const void *buf,
                                      MPIABI_Count count,
                                      MPIABI_Datatype datatype,
                                      MPIABI_Status *status);
int (*MPIABI_Register_datarep_ptr)(
    const char *datarep, MPIABI_Datarep_conversion_function *read_conversion_fn,
    MPIABI_Datarep_conversion_function *write_conversion_fn,
    MPIABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);
int (*MPIABI_Register_datarep_c_ptr)(
    const char *datarep,
    MPIABI_Datarep_conversion_function_c *read_conversion_fn,
    MPIABI_Datarep_conversion_function_c *write_conversion_fn,
    MPIABI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state);

// A.3.13 Language Bindings C Bindings

MPIABI_Fint (*MPIABI_Comm_c2f_ptr)(MPIABI_Comm comm);
MPIABI_Comm (*MPIABI_Comm_f2c_ptr)(MPIABI_Fint comm);
MPIABI_Fint (*MPIABI_Errhandler_c2f_ptr)(MPIABI_Errhandler errhandler);
MPIABI_Errhandler (*MPIABI_Errhandler_f2c_ptr)(MPIABI_Fint errhandler);
MPIABI_Fint (*MPIABI_File_c2f_ptr)(MPIABI_File file);
MPIABI_File (*MPIABI_File_f2c_ptr)(MPIABI_Fint file);
MPIABI_Fint (*MPIABI_Group_c2f_ptr)(MPIABI_Group group);
MPIABI_Group (*MPIABI_Group_f2c_ptr)(MPIABI_Fint group);
MPIABI_Fint (*MPIABI_Info_c2f_ptr)(MPIABI_Info info);
MPIABI_Info (*MPIABI_Info_f2c_ptr)(MPIABI_Fint info);
MPIABI_Fint (*MPIABI_Message_c2f_ptr)(MPIABI_Message message);
MPIABI_Message (*MPIABI_Message_f2c_ptr)(MPIABI_Fint message);
MPIABI_Fint (*MPIABI_Op_c2f_ptr)(MPIABI_Op op);
MPIABI_Op (*MPIABI_Op_f2c_ptr)(MPIABI_Fint op);
MPIABI_Fint (*MPIABI_Request_c2f_ptr)(MPIABI_Request request);
MPIABI_Request (*MPIABI_Request_f2c_ptr)(MPIABI_Fint request);
MPIABI_Fint (*MPIABI_Session_c2f_ptr)(MPIABI_Session session);
MPIABI_Session (*MPIABI_Session_f2c_ptr)(MPIABI_Fint session);
int (*MPIABI_Status_f082f_ptr)(const MPIABI_F08_status *f08_status,
                               MPIABI_Fint *f_status);
int (*MPIABI_Status_c2f_ptr)(const MPIABI_Status *c_status,
                             MPIABI_Fint *f_status);
int (*MPIABI_Status_c2f08_ptr)(const MPIABI_Status *c_status,
                               MPIABI_F08_status *f08_status);
int (*MPIABI_Status_f082c_ptr)(const MPIABI_F08_status *f08_status,
                               MPIABI_Status *c_status);
int (*MPIABI_Status_f2c_ptr)(const MPIABI_Fint *f_status,
                             MPIABI_Status *c_status);
int (*MPIABI_Status_f2f08_ptr)(const MPIABI_Fint *f_status,
                               MPIABI_F08_status *f08_status);
MPIABI_Fint (*MPIABI_Type_c2f_ptr)(MPIABI_Datatype datatype);
int (*MPIABI_Type_create_f90_complex_ptr)(int p, int r,
                                          MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_f90_integer_ptr)(int r, MPIABI_Datatype *newtype);
int (*MPIABI_Type_create_f90_real_ptr)(int p, int r, MPIABI_Datatype *newtype);
MPIABI_Datatype (*MPIABI_Type_f2c_ptr)(MPIABI_Fint datatype);
int (*MPIABI_Type_match_size_ptr)(int typeclass, int size,
                                  MPIABI_Datatype *datatype);
MPIABI_Fint (*MPIABI_Win_c2f_ptr)(MPIABI_Win win);
MPIABI_Win (*MPIABI_Win_f2c_ptr)(MPIABI_Fint win);

// A.3.14 Tools / Profiling Interface C Bindings

int (*MPIABI_Pcontrol_ptr)(const int level, ...);

// A.3.15 Tools / MPI Tool Information Interface C Bindings

int (*MPIABI_T_category_changed_ptr)(int *update_number);
int (*MPIABI_T_category_get_categories_ptr)(int cat_index, int len,
                                            int indices[]);
int (*MPIABI_T_category_get_cvars_ptr)(int cat_index, int len, int indices[]);
int (*MPIABI_T_category_get_events_ptr)(int cat_index, int len, int indices[]);
int (*MPIABI_T_category_get_index_ptr)(const char *name, int *cat_index);
int (*MPIABI_T_category_get_info_ptr)(int cat_index, char *name, int *name_len,
                                      char *desc, int *desc_len, int *num_cvars,
                                      int *num_pvars, int *num_categories);
int (*MPIABI_T_category_get_num_ptr)(int *num_cat);
int (*MPIABI_T_category_get_num_events_ptr)(int cat_index, int *num_events);
int (*MPIABI_T_category_get_pvars_ptr)(int cat_index, int len, int indices[]);
int (*MPIABI_T_cvar_get_index_ptr)(const char *name, int *cvar_index);
int (*MPIABI_T_cvar_get_info_ptr)(int cvar_index, char *name, int *name_len,
                                  int *verbosity, MPIABI_Datatype *datatype,
                                  MPIABI_T_enum *enumtype, char *desc,
                                  int *desc_len, int *bind, int *scope);
int (*MPIABI_T_cvar_get_num_ptr)(int *num_cvar);
int (*MPIABI_T_cvar_handle_alloc_ptr)(int cvar_index, void *obj_handle,
                                      MPIABI_T_cvar_handle *handle, int *count);
int (*MPIABI_T_cvar_handle_free_ptr)(MPIABI_T_cvar_handle *handle);
int (*MPIABI_T_cvar_read_ptr)(MPIABI_T_cvar_handle handle, void *buf);
int (*MPIABI_T_cvar_write_ptr)(MPIABI_T_cvar_handle handle, const void *buf);
int (*MPIABI_T_enum_get_info_ptr)(MPIABI_T_enum enumtype, int *num, char *name,
                                  int *name_len);
int (*MPIABI_T_enum_get_item_ptr)(MPIABI_T_enum enumtype, int index, int *value,
                                  char *name, int *name_len);
int (*MPIABI_T_event_callback_get_info_ptr)(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_cb_safety cb_safety, MPIABI_Info *info_used);
int (*MPIABI_T_event_callback_set_info_ptr)(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_cb_safety cb_safety, MPIABI_Info info);
int (*MPIABI_T_event_copy_ptr)(MPIABI_T_event_instance event_instance,
                               void *buffer);
int (*MPIABI_T_event_get_index_ptr)(const char *name, int *event_index);
int (*MPIABI_T_event_get_info_ptr)(int event_index, char *name, int *name_len,
                                   int *verbosity,
                                   MPIABI_Datatype array_of_datatypes[],
                                   MPIABI_Aint array_of_displacements[],
                                   int *num_elements, MPIABI_T_enum *enumtype,
                                   MPIABI_Info *info, char *desc, int *desc_len,
                                   int *bind);
int (*MPIABI_T_event_get_num_ptr)(int *num_events);
int (*MPIABI_T_event_get_source_ptr)(MPIABI_T_event_instance event_instance,
                                     int *source_index);
int (*MPIABI_T_event_get_timestamp_ptr)(MPIABI_T_event_instance event_instance,
                                        MPIABI_Count *event_timestamp);
int (*MPIABI_T_event_handle_alloc_ptr)(
    int event_index, void *obj_handle, MPIABI_Info info,
    MPIABI_T_event_registration *event_registration);
int (*MPIABI_T_event_handle_free_ptr)(
    MPIABI_T_event_registration event_registration, void *user_data,
    MPIABI_T_event_free_cb_function free_cb_function);
int (*MPIABI_T_event_handle_get_info_ptr)(
    MPIABI_T_event_registration event_registration, MPIABI_Info *info_used);
int (*MPIABI_T_event_handle_set_info_ptr)(
    MPIABI_T_event_registration event_registration, MPIABI_Info info);
int (*MPIABI_T_event_read_ptr)(MPIABI_T_event_instance event_instance,
                               int element_index, void *buffer);
int (*MPIABI_T_event_register_callback_ptr)(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_cb_safety cb_safety, MPIABI_Info info, void *user_data,
    MPIABI_T_event_cb_function event_cb_function);
int (*MPIABI_T_event_set_dropped_handler_ptr)(
    MPIABI_T_event_registration event_registration,
    MPIABI_T_event_dropped_cb_function dropped_cb_function);
int (*MPIABI_T_finalize_ptr)(void);
int (*MPIABI_T_init_thread_ptr)(int required, int *provided);
int (*MPIABI_T_pvar_get_index_ptr)(const char *name, int var_class,
                                   int *pvar_index);
int (*MPIABI_T_pvar_get_info_ptr)(int pvar_index, char *name, int *name_len,
                                  int *verbosity, int *var_class,
                                  MPIABI_Datatype *datatype,
                                  MPIABI_T_enum *enumtype, char *desc,
                                  int *desc_len, int *bind, int *readonly,
                                  int *continuous, int *atomic);
int (*MPIABI_T_pvar_get_num_ptr)(int *num_pvar);
int (*MPIABI_T_pvar_handle_alloc_ptr)(MPIABI_T_pvar_session pe_session,
                                      int pvar_index, void *obj_handle,
                                      MPIABI_T_pvar_handle *handle, int *count);
int (*MPIABI_T_pvar_handle_free_ptr)(MPIABI_T_pvar_session pe_session,
                                     MPIABI_T_pvar_handle *handle);
int (*MPIABI_T_pvar_read_ptr)(MPIABI_T_pvar_session pe_session,
                              MPIABI_T_pvar_handle handle, void *buf);
int (*MPIABI_T_pvar_readreset_ptr)(MPIABI_T_pvar_session pe_session,
                                   MPIABI_T_pvar_handle handle, void *buf);
int (*MPIABI_T_pvar_reset_ptr)(MPIABI_T_pvar_session pe_session,
                               MPIABI_T_pvar_handle handle);
int (*MPIABI_T_pvar_session_create_ptr)(MPIABI_T_pvar_session *pe_session);
int (*MPIABI_T_pvar_session_free_ptr)(MPIABI_T_pvar_session *pe_session);
int (*MPIABI_T_pvar_start_ptr)(MPIABI_T_pvar_session pe_session,
                               MPIABI_T_pvar_handle handle);
int (*MPIABI_T_pvar_stop_ptr)(MPIABI_T_pvar_session pe_session,
                              MPIABI_T_pvar_handle handle);
int (*MPIABI_T_pvar_write_ptr)(MPIABI_T_pvar_session pe_session,
                               MPIABI_T_pvar_handle handle, const void *buf);
int (*MPIABI_T_source_get_info_ptr)(int source_index, char *name, int *name_len,
                                    char *desc, int *desc_len,
                                    MPIABI_T_source_order *ordering,
                                    MPIABI_Count *ticks_per_second,
                                    MPIABI_Count *max_ticks, MPIABI_Info *info);
int (*MPIABI_T_source_get_num_ptr)(int *num_sources);
int (*MPIABI_T_source_get_timestamp_ptr)(int source_index,
                                         MPIABI_Count *timestamp);

// A.3.16 Deprecated C Bindings

int (*MPIABI_Attr_delete_ptr)(MPIABI_Comm comm, int keyval);
int (*MPIABI_Attr_get_ptr)(MPIABI_Comm comm, int keyval, void *attribute_val,
                           int *flag);
int (*MPIABI_Attr_put_ptr)(MPIABI_Comm comm, int keyval, void *attribute_val);
int (*MPIABI_Get_elements_x_ptr)(const MPIABI_Status *status,
                                 MPIABI_Datatype datatype, MPIABI_Count *count);
int (*MPIABI_Info_get_ptr)(MPIABI_Info info, const char *key, int valuelen,
                           char *value, int *flag);
int (*MPIABI_Info_get_valuelen_ptr)(MPIABI_Info info, const char *key,
                                    int *valuelen, int *flag);
int (*MPIABI_Keyval_create_ptr)(MPIABI_Copy_function *copy_fn,
                                MPIABI_Delete_function *delete_fn, int *keyval,
                                void *extra_state);
int (*MPIABI_Keyval_free_ptr)(int *keyval);
int (*MPIABI_Status_set_elements_x_ptr)(MPIABI_Status *status,
                                        MPIABI_Datatype datatype,
                                        MPIABI_Count count);
int (*MPIABI_Type_get_extent_x_ptr)(MPIABI_Datatype datatype, MPIABI_Count *lb,
                                    MPIABI_Count *extent);
int (*MPIABI_Type_get_true_extent_x_ptr)(MPIABI_Datatype datatype,
                                         MPIABI_Count *true_lb,
                                         MPIABI_Count *true_extent);
int (*MPIABI_Type_size_x_ptr)(MPIABI_Datatype datatype, MPIABI_Count *size);

// Removed C Bindings

int (*MPIABI_Address_ptr)(void *location, MPIABI_Aint *address);
int (*MPIABI_Type_hindexed_ptr)(int count, int *array_of_blocklengths,
                                MPIABI_Aint *array_of_displacements,
                                MPIABI_Datatype oldtype,
                                MPIABI_Datatype *newtype);
int (*MPIABI_Type_hvector_ptr)(int count, int blocklength, MPIABI_Aint stride,
                               MPIABI_Datatype oldtype,
                               MPIABI_Datatype *newtype);
int (*MPIABI_Type_struct_ptr)(int count, int *array_of_blocklengths,
                              MPIABI_Aint *array_of_displacements,
                              MPIABI_Datatype *array_of_types,
                              MPIABI_Datatype *newtype);
int (*MPIABI_Type_extent_ptr)(MPIABI_Datatype datatype, MPIABI_Aint *extent);
int (*MPIABI_Type_lb_ptr)(MPIABI_Datatype datatype, MPIABI_Aint *displacement);
int (*MPIABI_Type_ub_ptr)(MPIABI_Datatype datatype, MPIABI_Aint *displacement);

// MPIX

int (*MPIXABI_Query_cuda_support_ptr)(void);
int (*MPIXABI_Query_hip_support_ptr)(void);
int (*MPIXABI_Query_rocm_support_ptr)(void);
int (*MPIXABI_Query_ze_support_ptr)(void);
