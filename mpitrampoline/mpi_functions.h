#ifndef MPI_FUNCTIONS_H
#define MPI_FUNCTIONS_H

#include "mpi_constants.h"
#include "mpi_types.h"
#include "mpiabi_function_pointers.h"

// Declare (and inline-define) MPI functions

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

inline int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Bsend_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Bsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Bsend_c_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) {
  return (*MPIABI_Bsend_init_ptr)(buf, count, datatype, dest, tag, comm,
                                  request);
}

inline int MPI_Bsend_init_c(const void *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Bsend_init_c_ptr)(buf, count, datatype, dest, tag, comm,
                                    request);
}

inline int MPI_Buffer_attach(void *buffer, int size) {
  return (*MPIABI_Buffer_attach_ptr)(buffer, size);
}

inline int MPI_Buffer_attach_c(void *buffer, MPI_Count size) {
  return (*MPIABI_Buffer_attach_c_ptr)(buffer, size);
}

inline int MPI_Buffer_detach(void *buffer_addr, int *size) {
  return (*MPIABI_Buffer_detach_ptr)(buffer_addr, size);
}

inline int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size) {
  return (*MPIABI_Buffer_detach_c_ptr)(buffer_addr, size);
}

inline int MPI_Buffer_flush(void) { return (*MPIABI_Buffer_flush_ptr)(); }

inline int MPI_Buffer_iflush(MPI_Request *request) {
  return (*MPIABI_Buffer_iflush_ptr)(request);
}

inline int MPI_Cancel(MPI_Request *request) {
  return (*MPIABI_Cancel_ptr)(request);
}

inline int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size) {
  return (*MPIABI_Comm_attach_buffer_ptr)(comm, buffer, size);
}

inline int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer,
                                    MPI_Count size) {
  return (*MPIABI_Comm_attach_buffer_c_ptr)(comm, buffer, size);
}

inline int MPI_Comm_detach_buffer(MPI_Comm comm, void *buffer_addr, int *size) {
  return (*MPIABI_Comm_detach_buffer_ptr)(comm, buffer_addr, size);
}

inline int MPI_Comm_detach_buffer_c(MPI_Comm comm, void *buffer_addr,
                                    MPI_Count *size) {
  return (*MPIABI_Comm_detach_buffer_c_ptr)(comm, buffer_addr, size);
}

inline int MPI_Comm_flush_buffer(MPI_Comm comm) {
  return (*MPIABI_Comm_flush_buffer_ptr)(comm);
}

inline int MPI_Comm_iflush_buffer(MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Comm_iflush_buffer_ptr)(comm, request);
}

inline int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype,
                         int *count) {
  return (*MPIABI_Get_count_ptr)(status, datatype, count);
}

inline int MPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype,
                           MPI_Count *count) {
  return (*MPIABI_Get_count_c_ptr)(status, datatype, count);
}

inline int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ibsend_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Ibsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  return (*MPIABI_Ibsend_c_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                       MPI_Message *message, MPI_Status *status) {
  return (*MPIABI_Improbe_ptr)(source, tag, comm, flag, message, status);
}

inline int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                      MPI_Message *message, MPI_Request *request) {
  return (*MPIABI_Imrecv_ptr)(buf, count, datatype, message, request);
}

inline int MPI_Imrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                        MPI_Message *message, MPI_Request *request) {
  return (*MPIABI_Imrecv_c_ptr)(buf, count, datatype, message, request);
}

inline int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                      MPI_Status *status) {
  return (*MPIABI_Iprobe_ptr)(source, tag, comm, flag, status);
}

inline int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source,
                     int tag, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Irecv_ptr)(buf, count, datatype, source, tag, comm, request);
}

inline int MPI_Irecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                       int source, int tag, MPI_Comm comm,
                       MPI_Request *request) {
  return (*MPIABI_Irecv_c_ptr)(buf, count, datatype, source, tag, comm,
                               request);
}

inline int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Irsend_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Irsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  return (*MPIABI_Irsend_c_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Isend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Isend_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Isend_c_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Isendrecv(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, int dest, int sendtag,
                         void *recvbuf, int recvcount, MPI_Datatype recvtype,
                         int source, int recvtag, MPI_Comm comm,
                         MPI_Request *request) {
  return (*MPIABI_Isendrecv_ptr)(sendbuf, sendcount, sendtype, dest, sendtag,
                                 recvbuf, recvcount, recvtype, source, recvtag,
                                 comm, request);
}

inline int MPI_Isendrecv_c(const void *sendbuf, MPI_Count sendcount,
                           MPI_Datatype sendtype, int dest, int sendtag,
                           void *recvbuf, MPI_Count recvcount,
                           MPI_Datatype recvtype, int source, int recvtag,
                           MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Isendrecv_c_ptr)(sendbuf, sendcount, sendtype, dest, sendtag,
                                   recvbuf, recvcount, recvtype, source,
                                   recvtag, comm, request);
}

inline int MPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int sendtag, int source, int recvtag,
                                 MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Isendrecv_replace_ptr)(buf, count, datatype, dest, sendtag,
                                         source, recvtag, comm, request);
}

inline int MPI_Isendrecv_replace_c(void *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int sendtag,
                                   int source, int recvtag, MPI_Comm comm,
                                   MPI_Request *request) {
  return (*MPIABI_Isendrecv_replace_c_ptr)(buf, count, datatype, dest, sendtag,
                                           source, recvtag, comm, request);
}

inline int MPI_Issend(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Issend_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Issend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  return (*MPIABI_Issend_c_ptr)(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message,
                      MPI_Status *status) {
  return (*MPIABI_Mprobe_ptr)(source, tag, comm, message, status);
}

inline int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                     MPI_Message *message, MPI_Status *status) {
  return (*MPIABI_Mrecv_ptr)(buf, count, datatype, message, status);
}

inline int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                       MPI_Message *message, MPI_Status *status) {
  return (*MPIABI_Mrecv_c_ptr)(buf, count, datatype, message, status);
}

inline int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
  return (*MPIABI_Probe_ptr)(source, tag, comm, status);
}

inline int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source,
                    int tag, MPI_Comm comm, MPI_Status *status) {
  return (*MPIABI_Recv_ptr)(buf, count, datatype, source, tag, comm, status);
}

inline int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                      int source, int tag, MPI_Comm comm, MPI_Status *status) {
  return (*MPIABI_Recv_c_ptr)(buf, count, datatype, source, tag, comm, status);
}

inline int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                         int source, int tag, MPI_Comm comm,
                         MPI_Request *request) {
  return (*MPIABI_Recv_init_ptr)(buf, count, datatype, source, tag, comm,
                                 request);
}

inline int MPI_Recv_init_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Request *request) {
  return (*MPIABI_Recv_init_c_ptr)(buf, count, datatype, source, tag, comm,
                                   request);
}

inline int MPI_Request_free(MPI_Request *request) {
  return (*MPIABI_Request_free_ptr)(request);
}

inline int MPI_Request_get_status(MPI_Request request, int *flag,
                                  MPI_Status *status) {
  return (*MPIABI_Request_get_status_ptr)(request, flag, status);
}

inline int MPI_Request_get_status_all(int count,
                                      const MPI_Request array_of_requests[],
                                      int *flag,
                                      MPI_Status array_of_statuses[]) {
  return (*MPIABI_Request_get_status_all_ptr)(count, array_of_requests, flag,
                                              array_of_statuses);
}

inline int MPI_Request_get_status_any(int count,
                                      const MPI_Request array_of_requests[],
                                      int *index, int *flag,
                                      MPI_Status *status) {
  return (*MPIABI_Request_get_status_any_ptr)(count, array_of_requests, index,
                                              flag, status);
}

inline int MPI_Request_get_status_some(int incount,
                                       const MPI_Request array_of_requests[],
                                       int *outcount, int array_of_indices[],
                                       MPI_Status array_of_statuses[]) {
  return (*MPIABI_Request_get_status_some_ptr)(incount, array_of_requests,
                                               outcount, array_of_indices,
                                               array_of_statuses);
}

inline int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Rsend_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Rsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Rsend_c_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) {
  return (*MPIABI_Rsend_init_ptr)(buf, count, datatype, dest, tag, comm,
                                  request);
}

inline int MPI_Rsend_init_c(const void *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Rsend_init_c_ptr)(buf, count, datatype, dest, tag, comm,
                                    request);
}

inline int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
                    int tag, MPI_Comm comm) {
  return (*MPIABI_Send_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Send_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Send_c_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype,
                         int dest, int tag, MPI_Comm comm,
                         MPI_Request *request) {
  return (*MPIABI_Send_init_ptr)(buf, count, datatype, dest, tag, comm,
                                 request);
}

inline int MPI_Send_init_c(const void *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Send_init_c_ptr)(buf, count, datatype, dest, tag, comm,
                                   request);
}

inline int MPI_Sendrecv(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, int dest, int sendtag,
                        void *recvbuf, int recvcount, MPI_Datatype recvtype,
                        int source, int recvtag, MPI_Comm comm,
                        MPI_Status *status) {
  return (*MPIABI_Sendrecv_ptr)(sendbuf, sendcount, sendtype, dest, sendtag,
                                recvbuf, recvcount, recvtype, source, recvtag,
                                comm, status);
}

inline int MPI_Sendrecv_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, int dest, int sendtag,
                          void *recvbuf, MPI_Count recvcount,
                          MPI_Datatype recvtype, int source, int recvtag,
                          MPI_Comm comm, MPI_Status *status) {
  return (*MPIABI_Sendrecv_c_ptr)(sendbuf, sendcount, sendtype, dest, sendtag,
                                  recvbuf, recvcount, recvtype, source, recvtag,
                                  comm, status);
}

inline int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                                int dest, int sendtag, int source, int recvtag,
                                MPI_Comm comm, MPI_Status *status) {
  return (*MPIABI_Sendrecv_replace_ptr)(buf, count, datatype, dest, sendtag,
                                        source, recvtag, comm, status);
}

inline int MPI_Sendrecv_replace_c(void *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int sendtag,
                                  int source, int recvtag, MPI_Comm comm,
                                  MPI_Status *status) {
  return (*MPIABI_Sendrecv_replace_c_ptr)(buf, count, datatype, dest, sendtag,
                                          source, recvtag, comm, status);
}

inline int MPI_Session_attach_buffer(MPI_Session session, void *buffer,
                                     int size) {
  return (*MPIABI_Session_attach_buffer_ptr)(session, buffer, size);
}

inline int MPI_Session_attach_buffer_c(MPI_Session session, void *buffer,
                                       MPI_Count size) {
  return (*MPIABI_Session_attach_buffer_c_ptr)(session, buffer, size);
}

inline int MPI_Session_detach_buffer(MPI_Session session, void *buffer_addr,
                                     int *size) {
  return (*MPIABI_Session_detach_buffer_ptr)(session, buffer_addr, size);
}

inline int MPI_Session_detach_buffer_c(MPI_Session session, void *buffer_addr,
                                       MPI_Count *size) {
  return (*MPIABI_Session_detach_buffer_c_ptr)(session, buffer_addr, size);
}

inline int MPI_Session_flush_buffer(MPI_Session session) {
  return (*MPIABI_Session_flush_buffer_ptr)(session);
}

inline int MPI_Session_iflush_buffer(MPI_Session session,
                                     MPI_Request *request) {
  return (*MPIABI_Session_iflush_buffer_ptr)(session, request);
}

inline int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Ssend_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  return (*MPIABI_Ssend_c_ptr)(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) {
  return (*MPIABI_Ssend_init_ptr)(buf, count, datatype, dest, tag, comm,
                                  request);
}

inline int MPI_Ssend_init_c(const void *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ssend_init_c_ptr)(buf, count, datatype, dest, tag, comm,
                                    request);
}

inline int MPI_Start(MPI_Request *request) {
  return (*MPIABI_Start_ptr)(request);
}

inline int MPI_Startall(int count, MPI_Request array_of_requests[]) {
  return (*MPIABI_Startall_ptr)(count, array_of_requests);
}

inline int MPI_Status_get_error(MPI_Status *status, int *err) {
  return (*MPIABI_Status_get_error_ptr)(status, err);
}

inline int MPI_Status_get_source(MPI_Status *status, int *source) {
  return (*MPIABI_Status_get_source_ptr)(status, source);
}

inline int MPI_Status_get_tag(MPI_Status *status, int *tag) {
  return (*MPIABI_Status_get_tag_ptr)(status, tag);
}

inline int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status) {
  return (*MPIABI_Test_ptr)(request, flag, status);
}

inline int MPI_Test_cancelled(const MPI_Status *status, int *flag) {
  return (*MPIABI_Test_cancelled_ptr)(status, flag);
}

inline int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                       MPI_Status array_of_statuses[]) {
  return (*MPIABI_Testall_ptr)(count, array_of_requests, flag,
                               array_of_statuses);
}

inline int MPI_Testany(int count, MPI_Request array_of_requests[], int *index,
                       int *flag, MPI_Status *status) {
  return (*MPIABI_Testany_ptr)(count, array_of_requests, index, flag, status);
}

inline int MPI_Testsome(int incount, MPI_Request array_of_requests[],
                        int *outcount, int array_of_indices[],
                        MPI_Status array_of_statuses[]) {
  return (*MPIABI_Testsome_ptr)(incount, array_of_requests, outcount,
                                array_of_indices, array_of_statuses);
}

inline int MPI_Wait(MPI_Request *request, MPI_Status *status) {
  return (*MPIABI_Wait_ptr)(request, status);
}

inline int MPI_Waitall(int count, MPI_Request array_of_requests[],
                       MPI_Status array_of_statuses[]) {
  return (*MPIABI_Waitall_ptr)(count, array_of_requests, array_of_statuses);
}

inline int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index,
                       MPI_Status *status) {
  return (*MPIABI_Waitany_ptr)(count, array_of_requests, index, status);
}

inline int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                        int *outcount, int array_of_indices[],
                        MPI_Status array_of_statuses[]) {
  return (*MPIABI_Waitsome_ptr)(incount, array_of_requests, outcount,
                                array_of_indices, array_of_statuses);
}

// A.3.2 Partitioned Communication C Bindings

inline int MPI_Parrived(MPI_Request request, int partition, int *flag) {
  return (*MPIABI_Parrived_ptr)(request, partition, flag);
}

inline int MPI_Pready(int partition, MPI_Request request) {
  return (*MPIABI_Pready_ptr)(partition, request);
}

inline int MPI_Pready_list(int length, const int array_of_partitions[],
                           MPI_Request request) {
  return (*MPIABI_Pready_list_ptr)(length, array_of_partitions, request);
}

inline int MPI_Pready_range(int partition_low, int partition_high,
                            MPI_Request request) {
  return (*MPIABI_Pready_range_ptr)(partition_low, partition_high, request);
}

inline int MPI_Precv_init(void *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int source, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Precv_init_ptr)(buf, partitions, count, datatype, source, tag,
                                  comm, info, request);
}

inline int MPI_Psend_init(const void *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Psend_init_ptr)(buf, partitions, count, datatype, dest, tag,
                                  comm, info, request);
}

// A.3.3 Datatypes C Bindings

inline MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp) {
  return (*MPIABI_Aint_add_ptr)(base, disp);
}

inline MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2) {
  return (*MPIABI_Aint_diff_ptr)(addr1, addr2);
}

inline int MPI_Get_address(const void *location, MPI_Aint *address) {
  return (*MPIABI_Get_address_ptr)(location, address);
}

inline int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype,
                            int *count) {
  return (*MPIABI_Get_elements_ptr)(status, datatype, count);
}

inline int MPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype,
                              MPI_Count *count) {
  return (*MPIABI_Get_elements_c_ptr)(status, datatype, count);
}

inline int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype,
                    void *outbuf, int outsize, int *position, MPI_Comm comm) {
  return (*MPIABI_Pack_ptr)(inbuf, incount, datatype, outbuf, outsize, position,
                            comm);
}

inline int MPI_Pack_c(const void *inbuf, MPI_Count incount,
                      MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                      MPI_Count *position, MPI_Comm comm) {
  return (*MPIABI_Pack_c_ptr)(inbuf, incount, datatype, outbuf, outsize,
                              position, comm);
}

inline int MPI_Pack_external(const char datarep[], const void *inbuf,
                             int incount, MPI_Datatype datatype, void *outbuf,
                             MPI_Aint outsize, MPI_Aint *position) {
  return (*MPIABI_Pack_external_ptr)(datarep, inbuf, incount, datatype, outbuf,
                                     outsize, position);
}

inline int MPI_Pack_external_c(const char datarep[], const void *inbuf,
                               MPI_Count incount, MPI_Datatype datatype,
                               void *outbuf, MPI_Count outsize,
                               MPI_Count *position) {
  return (*MPIABI_Pack_external_c_ptr)(datarep, inbuf, incount, datatype,
                                       outbuf, outsize, position);
}

inline int MPI_Pack_external_size(const char datarep[], MPI_Count incount,
                                  MPI_Datatype datatype, MPI_Count *size) {
  return (*MPIABI_Pack_external_size_ptr)(datarep, incount, datatype, size);
}

inline int MPI_Pack_external_size_c(const char datarep[], MPI_Count incount,
                                    MPI_Datatype datatype, MPI_Aint *size) {
  return (*MPIABI_Pack_external_size_c_ptr)(datarep, incount, datatype, size);
}

inline int MPI_Pack_size_c(MPI_Count incount, MPI_Datatype datatype,
                           MPI_Comm comm, MPI_Count *size) {
  return (*MPIABI_Pack_size_c_ptr)(incount, datatype, comm, size);
}

inline int MPI_Type_commit(MPI_Datatype *datatype) {
  return (*MPIABI_Type_commit_ptr)(datatype);
}

inline int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                               MPI_Datatype *newtype) {
  return (*MPIABI_Type_contiguous_ptr)(count, oldtype, newtype);
}

inline int MPI_Type_contiguous_c(MPI_Count count, MPI_Datatype oldtype,
                                 MPI_Datatype *newtype) {
  return (*MPIABI_Type_contiguous_c_ptr)(count, oldtype, newtype);
}

inline int MPI_Type_create_darray(int size, int rank, int ndims,
                                  const int array_of_gsizes[],
                                  const int array_of_distribs[],
                                  const int array_of_dargs[],
                                  const int array_of_psizes[], int order,
                                  MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_darray_ptr)(
      size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
      array_of_psizes, order, oldtype, newtype);
}

inline int MPI_Type_create_darray_c(int size, int rank, int ndims,
                                    const MPI_Count array_of_gsizes[],
                                    const int array_of_distribs[],
                                    const int array_of_dargs[],
                                    const int array_of_psizes[], int order,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_darray_c_ptr)(
      size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs,
      array_of_psizes, order, oldtype, newtype);
}

inline int MPI_Type_create_hindexed(int count,
                                    const int array_of_blocklengths[],
                                    const MPI_Aint array_of_displacements[],
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_hindexed_ptr)(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

inline int
MPI_Type_create_hindexed_block(int count, int blocklength,
                               const MPI_Aint array_of_displacements[],
                               MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_hindexed_block_ptr)(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int
MPI_Type_create_hindexed_block_c(MPI_Count count, MPI_Count blocklength,
                                 const MPI_Count array_of_displacements[],
                                 MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_hindexed_block_c_ptr)(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_hindexed_c(MPI_Count count,
                                      const MPI_Count array_of_blocklengths[],
                                      const MPI_Count array_of_displacements[],
                                      MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_hindexed_c_ptr)(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride,
                                   MPI_Datatype oldtype,
                                   MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_hvector_ptr)(count, blocklength, stride, oldtype,
                                           newtype);
}

inline int MPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength,
                                     MPI_Count stride, MPI_Datatype oldtype,
                                     MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_hvector_c_ptr)(count, blocklength, stride,
                                             oldtype, newtype);
}

inline int MPI_Type_create_indexed_block(int count, int blocklength,
                                         const int array_of_displacements[],
                                         MPI_Datatype oldtype,
                                         MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_indexed_block_ptr)(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int
MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                const MPI_Count array_of_displacements[],
                                MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_indexed_block_c_ptr)(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                   MPI_Aint extent, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_resized_ptr)(oldtype, lb, extent, newtype);
}

inline int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb,
                                     MPI_Count extent, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_resized_c_ptr)(oldtype, lb, extent, newtype);
}

inline int MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                                  const MPI_Aint array_of_displacements[],
                                  const MPI_Datatype array_of_types[],
                                  MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_struct_ptr)(count, array_of_blocklengths,
                                          array_of_displacements,
                                          array_of_types, newtype);
}

inline int MPI_Type_create_struct_c(MPI_Count count,
                                    const MPI_Count array_of_blocklengths[],
                                    const MPI_Count array_of_displacements[],
                                    const MPI_Datatype array_of_types[],
                                    MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_struct_c_ptr)(count, array_of_blocklengths,
                                            array_of_displacements,
                                            array_of_types, newtype);
}

inline int MPI_Type_create_subarray(int ndims, const int array_of_sizes[],
                                    const int array_of_subsizes[],
                                    const int array_of_starts[], int order,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_subarray_ptr)(ndims, array_of_sizes,
                                            array_of_subsizes, array_of_starts,
                                            order, oldtype, newtype);
}

inline int MPI_Type_create_subarray_c(int ndims,
                                      const MPI_Count array_of_sizes[],
                                      const MPI_Count array_of_subsizes[],
                                      const MPI_Count array_of_starts[],
                                      int order, MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_subarray_c_ptr)(
      ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype,
      newtype);
}

inline int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_dup_ptr)(oldtype, newtype);
}

inline int MPI_Type_free(MPI_Datatype *datatype) {
  return (*MPIABI_Type_free_ptr)(datatype);
}

inline int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                 int max_addresses, int max_datatypes,
                                 int array_of_integers[],
                                 MPI_Aint array_of_addresses[],
                                 MPI_Datatype array_of_datatypes[]) {
  return (*MPIABI_Type_get_contents_ptr)(
      datatype, max_integers, max_addresses, max_datatypes, array_of_integers,
      array_of_addresses, array_of_datatypes);
}

inline int MPI_Type_get_contents_c(
    MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses,
    MPI_Count max_large_counts, MPI_Count max_datatypes,
    int array_of_integers[], MPI_Aint array_of_addresses[],
    MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[]) {
  return (*MPIABI_Type_get_contents_c_ptr)(
      datatype, max_integers, max_addresses, max_large_counts, max_datatypes,
      array_of_integers, array_of_addresses, array_of_large_counts,
      array_of_datatypes);
}

inline int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                                 int *num_addresses, int *num_datatypes,
                                 int *combiner) {
  return (*MPIABI_Type_get_envelope_ptr)(datatype, num_integers, num_addresses,
                                         num_datatypes, combiner);
}

inline int MPI_Type_get_envelope_c(MPI_Datatype datatype,
                                   MPI_Count *num_integers,
                                   MPI_Count *num_addresses,
                                   MPI_Count *num_large_counts,
                                   MPI_Count *num_datatypes, int *combiner) {
  return (*MPIABI_Type_get_envelope_c_ptr)(datatype, num_integers,
                                           num_addresses, num_large_counts,
                                           num_datatypes, combiner);
}

inline int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                               MPI_Aint *extent) {
  return (*MPIABI_Type_get_extent_ptr)(datatype, lb, extent);
}

inline int MPI_Type_get_extent_c(MPI_Datatype datatype, MPI_Count *lb,
                                 MPI_Count *extent) {
  return (*MPIABI_Type_get_extent_c_ptr)(datatype, lb, extent);
}

inline int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                                    MPI_Aint *true_extent) {
  return (*MPIABI_Type_get_true_extent_ptr)(datatype, true_lb, true_extent);
}

inline int MPI_Type_get_true_extent_c(MPI_Datatype datatype, MPI_Count *true_lb,
                                      MPI_Count *true_extent) {
  return (*MPIABI_Type_get_true_extent_c_ptr)(datatype, true_lb, true_extent);
}

inline int MPI_Type_indexed(int count, const int array_of_blocklengths[],
                            const int array_of_displacements[],
                            MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_indexed_ptr)(count, array_of_blocklengths,
                                    array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_indexed_c(MPI_Count count,
                              const MPI_Count array_of_blocklengths[],
                              const MPI_Count array_of_displacements[],
                              MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_indexed_c_ptr)(count, array_of_blocklengths,
                                      array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_size(MPI_Datatype datatype, int *size) {
  return (*MPIABI_Type_size_ptr)(datatype, size);
}

inline int MPI_Type_size_c(MPI_Datatype datatype, MPI_Count *size) {
  return (*MPIABI_Type_size_c_ptr)(datatype, size);
}

inline int MPI_Type_vector(int count, int blocklength, int stride,
                           MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return (*MPIABI_Type_vector_ptr)(count, blocklength, stride, oldtype,
                                   newtype);
}

inline int MPI_Type_vector_c(MPI_Count count, MPI_Count blocklength,
                             MPI_Count stride, MPI_Datatype oldtype,
                             MPI_Datatype *newtype) {
  return (*MPIABI_Type_vector_c_ptr)(count, blocklength, stride, oldtype,
                                     newtype);
}

inline int MPI_Unpack(const void *inbuf, int insize, int *position,
                      void *outbuf, int outcount, MPI_Datatype datatype,
                      MPI_Comm comm) {
  return (*MPIABI_Unpack_ptr)(inbuf, insize, position, outbuf, outcount,
                              datatype, comm);
}

inline int MPI_Unpack_c(const void *inbuf, MPI_Count insize,
                        MPI_Count *position, void *outbuf, MPI_Count outcount,
                        MPI_Datatype datatype, MPI_Comm comm) {
  return (*MPIABI_Unpack_c_ptr)(inbuf, insize, position, outbuf, outcount,
                                datatype, comm);
}

inline int MPI_Unpack_external(const char datarep[], const void *inbuf,
                               MPI_Aint insize, MPI_Aint *position,
                               void *outbuf, int outcount,
                               MPI_Datatype datatype) {
  return (*MPIABI_Unpack_external_ptr)(datarep, inbuf, insize, position, outbuf,
                                       outcount, datatype);
}

inline int MPI_Unpack_external_c(const char datarep[], const void *inbuf,
                                 MPI_Count insize, MPI_Count *position,
                                 void *outbuf, MPI_Count outcount,
                                 MPI_Datatype datatype) {
  return (*MPIABI_Unpack_external_c_ptr)(datarep, inbuf, insize, position,
                                         outbuf, outcount, datatype);
}

// A.3.4 Collective Communication C Bindings

inline int MPI_Allgather(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, MPI_Comm comm) {
  return (*MPIABI_Allgather_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, comm);
}

inline int MPI_Allgather_c(const void *sendbuf, MPI_Count sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Count recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm) {
  return (*MPIABI_Allgather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcount, recvtype, comm);
}

inline int MPI_Allgather_init(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return (*MPIABI_Allgather_init_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcount, recvtype, comm, info, request);
}

inline int MPI_Allgather_init_c(const void *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Count recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Info info,
                                MPI_Request *request) {
  return (*MPIABI_Allgather_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, comm, info,
                                        request);
}

inline int MPI_Allgatherv(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPI_Datatype recvtype, MPI_Comm comm) {
  return (*MPIABI_Allgatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcounts, displs, recvtype, comm);
}

inline int MPI_Allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const MPI_Count recvcounts[],
                            const MPI_Aint displs[], MPI_Datatype recvtype,
                            MPI_Comm comm) {
  return (*MPIABI_Allgatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcounts, displs, recvtype, comm);
}

inline int MPI_Allgatherv_init(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPI_Datatype recvtype, MPI_Comm comm,
                               MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Allgatherv_init_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcounts, displs, recvtype, comm, info,
                                       request);
}

inline int MPI_Allgatherv_init_c(const void *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Count recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request) {
  return (*MPIABI_Allgatherv_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcounts, displs, recvtype, comm,
                                         info, request);
}

inline int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Allreduce_ptr)(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Allreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Allreduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Allreduce_init(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Allreduce_init_ptr)(sendbuf, recvbuf, count, datatype, op,
                                      comm, info, request);
}

inline int MPI_Allreduce_init_c(const void *sendbuf, void *recvbuf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm, MPI_Info info,
                                MPI_Request *request) {
  return (*MPIABI_Allreduce_init_c_ptr)(sendbuf, recvbuf, count, datatype, op,
                                        comm, info, request);
}

inline int MPI_Alltoall(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPI_Datatype recvtype, MPI_Comm comm) {
  return (*MPIABI_Alltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm);
}

inline int MPI_Alltoall_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          MPI_Count recvcount, MPI_Datatype recvtype,
                          MPI_Comm comm) {
  return (*MPIABI_Alltoall_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcount, recvtype, comm);
}

inline int MPI_Alltoall_init(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return (*MPIABI_Alltoall_init_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, comm, info, request);
}

inline int MPI_Alltoall_init_c(const void *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm, MPI_Info info,
                               MPI_Request *request) {
  return (*MPIABI_Alltoall_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcount, recvtype, comm, info,
                                       request);
}

inline int MPI_Alltoallv(const void *sendbuf, const int sendcounts[],
                         const int sdispls[], MPI_Datatype sendtype,
                         void *recvbuf, const int recvcounts[],
                         const int rdispls[], MPI_Datatype recvtype,
                         MPI_Comm comm) {
  return (*MPIABI_Alltoallv_ptr)(sendbuf, sendcounts, sdispls, sendtype,
                                 recvbuf, recvcounts, rdispls, recvtype, comm);
}

inline int MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                           const MPI_Aint sdispls[], MPI_Datatype sendtype,
                           void *recvbuf, const MPI_Count recvcounts[],
                           const MPI_Aint rdispls[], MPI_Datatype recvtype,
                           MPI_Comm comm) {
  return (*MPIABI_Alltoallv_c_ptr)(sendbuf, sendcounts, sdispls, sendtype,
                                   recvbuf, recvcounts, rdispls, recvtype,
                                   comm);
}

inline int MPI_Alltoallv_init(const void *sendbuf, const int sendcounts[],
                              const int sdispls[], MPI_Datatype sendtype,
                              void *recvbuf, const int recvcounts[],
                              const int rdispls[], MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return (*MPIABI_Alltoallv_init_ptr)(sendbuf, sendcounts, sdispls, sendtype,
                                      recvbuf, recvcounts, rdispls, recvtype,
                                      comm, info, request);
}

inline int MPI_Alltoallv_init_c(const void *sendbuf,
                                const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                void *recvbuf, const MPI_Count recvcounts[],
                                const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Info info,
                                MPI_Request *request) {
  return (*MPIABI_Alltoallv_init_c_ptr)(sendbuf, sendcounts, sdispls, sendtype,
                                        recvbuf, recvcounts, rdispls, recvtype,
                                        comm, info, request);
}

inline int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                         const int sdispls[], const MPI_Datatype sendtypes[],
                         void *recvbuf, const int recvcounts[],
                         const int rdispls[], const MPI_Datatype recvtypes[],
                         MPI_Comm comm) {
  return (*MPIABI_Alltoallw_ptr)(sendbuf, sendcounts, sdispls, sendtypes,
                                 recvbuf, recvcounts, rdispls, recvtypes, comm);
}

inline int MPI_Alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[],
                           const MPI_Aint sdispls[],
                           const MPI_Datatype sendtypes[], void *recvbuf,
                           const MPI_Count recvcounts[],
                           const MPI_Aint rdispls[],
                           const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return (*MPIABI_Alltoallw_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes,
                                   recvbuf, recvcounts, rdispls, recvtypes,
                                   comm);
}

inline int MPI_Alltoallw_init(const void *sendbuf, const int sendcounts[],
                              const int sdispls[],
                              const MPI_Datatype sendtypes[], void *recvbuf,
                              const int recvcounts[], const int rdispls[],
                              const MPI_Datatype recvtypes[], MPI_Comm comm,
                              MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Alltoallw_init_ptr)(sendbuf, sendcounts, sdispls, sendtypes,
                                      recvbuf, recvcounts, rdispls, recvtypes,
                                      comm, info, request);
}

inline int
MPI_Alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                     const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                     void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                     MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Alltoallw_init_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes,
                                        recvbuf, recvcounts, rdispls, recvtypes,
                                        comm, info, request);
}

inline int MPI_Barrier(MPI_Comm comm) { return (*MPIABI_Barrier_ptr)(comm); }

inline int MPI_Barrier_init(MPI_Comm comm, MPI_Info info,
                            MPI_Request *request) {
  return (*MPIABI_Barrier_init_ptr)(comm, info, request);
}

inline int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
                     MPI_Comm comm) {
  return (*MPIABI_Bcast_ptr)(buffer, count, datatype, root, comm);
}

inline int MPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype,
                       int root, MPI_Comm comm) {
  return (*MPIABI_Bcast_c_ptr)(buffer, count, datatype, root, comm);
}

inline int MPI_Bcast_init(void *buffer, int count, MPI_Datatype datatype,
                          int root, MPI_Comm comm, MPI_Info info,
                          MPI_Request *request) {
  return (*MPIABI_Bcast_init_ptr)(buffer, count, datatype, root, comm, info,
                                  request);
}

inline int MPI_Bcast_init_c(void *buffer, MPI_Count count,
                            MPI_Datatype datatype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Bcast_init_c_ptr)(buffer, count, datatype, root, comm, info,
                                    request);
}

inline int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Exscan_ptr)(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Exscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Exscan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Exscan_init(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                           MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Exscan_init_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                                   info, request);
}

inline int MPI_Exscan_init_c(const void *sendbuf, void *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return (*MPIABI_Exscan_init_c_ptr)(sendbuf, recvbuf, count, datatype, op,
                                     comm, info, request);
}

inline int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                      void *recvbuf, int recvcount, MPI_Datatype recvtype,
                      int root, MPI_Comm comm) {
  return (*MPIABI_Gather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                              recvtype, root, comm);
}

inline int MPI_Gather_c(const void *sendbuf, MPI_Count sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        MPI_Count recvcount, MPI_Datatype recvtype, int root,
                        MPI_Comm comm) {
  return (*MPIABI_Gather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, root, comm);
}

inline int MPI_Gather_init(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, int root, MPI_Comm comm,
                           MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Gather_init_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcount, recvtype, root, comm, info,
                                   request);
}

inline int MPI_Gather_init_c(const void *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Count recvcount, MPI_Datatype recvtype,
                             int root, MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return (*MPIABI_Gather_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, root, comm, info,
                                     request);
}

inline int MPI_Gatherv(const void *sendbuf, int sendcount,
                       MPI_Datatype sendtype, void *recvbuf,
                       const int recvcounts[], const int displs[],
                       MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return (*MPIABI_Gatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                               recvcounts, displs, recvtype, root, comm);
}

inline int MPI_Gatherv_c(const void *sendbuf, MPI_Count sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         const MPI_Count recvcounts[], const MPI_Aint displs[],
                         MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return (*MPIABI_Gatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcounts, displs, recvtype, root, comm);
}

inline int MPI_Gatherv_init(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Gatherv_init_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcounts, displs, recvtype, root, comm,
                                    info, request);
}

inline int MPI_Gatherv_init_c(const void *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Count recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return (*MPIABI_Gatherv_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcounts, displs, recvtype, root, comm,
                                      info, request);
}

inline int MPI_Iallgather(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm,
                          MPI_Request *request) {
  return (*MPIABI_Iallgather_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcount, recvtype, comm, request);
}

inline int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Count recvcount, MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Iallgather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm, request);
}

inline int MPI_Iallgatherv(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           const int recvcounts[], const int displs[],
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request) {
  return (*MPIABI_Iallgatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcounts, displs, recvtype, comm, request);
}

inline int MPI_Iallgatherv_c(const void *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const MPI_Count recvcounts[],
                             const MPI_Aint displs[], MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Iallgatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcounts, displs, recvtype, comm,
                                     request);
}

inline int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                          MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                          MPI_Request *request) {
  return (*MPIABI_Iallreduce_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                                  request);
}

inline int MPI_Iallreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request) {
  return (*MPIABI_Iallreduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                                    request);
}

inline int MPI_Ialltoall(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, MPI_Comm comm,
                         MPI_Request *request) {
  return (*MPIABI_Ialltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, comm, request);
}

inline int MPI_Ialltoall_c(const void *sendbuf, MPI_Count sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Count recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ialltoall_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcount, recvtype, comm, request);
}

inline int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                          const int sdispls[], MPI_Datatype sendtype,
                          void *recvbuf, const int recvcounts[],
                          const int rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ialltoallv_ptr)(sendbuf, sendcounts, sdispls, sendtype,
                                  recvbuf, recvcounts, rdispls, recvtype, comm,
                                  request);
}

inline int MPI_Ialltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                            const MPI_Aint sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const MPI_Count recvcounts[],
                            const MPI_Aint rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ialltoallv_c_ptr)(sendbuf, sendcounts, sdispls, sendtype,
                                    recvbuf, recvcounts, rdispls, recvtype,
                                    comm, request);
}

inline int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                          const int sdispls[], const MPI_Datatype sendtypes[],
                          void *recvbuf, const int recvcounts[],
                          const int rdispls[], const MPI_Datatype recvtypes[],
                          MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ialltoallw_ptr)(sendbuf, sendcounts, sdispls, sendtypes,
                                  recvbuf, recvcounts, rdispls, recvtypes, comm,
                                  request);
}

inline int MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[],
                            const MPI_Aint sdispls[],
                            const MPI_Datatype sendtypes[], void *recvbuf,
                            const MPI_Count recvcounts[],
                            const MPI_Aint rdispls[],
                            const MPI_Datatype recvtypes[], MPI_Comm comm,
                            MPI_Request *request) {
  return (*MPIABI_Ialltoallw_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes,
                                    recvbuf, recvcounts, rdispls, recvtypes,
                                    comm, request);
}

inline int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ibarrier_ptr)(comm, request);
}

inline int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root,
                      MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ibcast_ptr)(buffer, count, datatype, root, comm, request);
}

inline int MPI_Ibcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype,
                        int root, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ibcast_c_ptr)(buffer, count, datatype, root, comm, request);
}

inline int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request) {
  return (*MPIABI_Iexscan_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                               request);
}

inline int MPI_Iexscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Request *request) {
  return (*MPIABI_Iexscan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                                 request);
}

inline int MPI_Igather(const void *sendbuf, int sendcount,
                       MPI_Datatype sendtype, void *recvbuf, int recvcount,
                       MPI_Datatype recvtype, int root, MPI_Comm comm,
                       MPI_Request *request) {
  return (*MPIABI_Igather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, root, comm, request);
}

inline int MPI_Igather_c(const void *sendbuf, MPI_Count sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         MPI_Count recvcount, MPI_Datatype recvtype, int root,
                         MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Igather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, root, comm, request);
}

inline int MPI_Igatherv(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        const int recvcounts[], const int displs[],
                        MPI_Datatype recvtype, int root, MPI_Comm comm,
                        MPI_Request *request) {
  return (*MPIABI_Igatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                recvcounts, displs, recvtype, root, comm,
                                request);
}

inline int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const MPI_Count recvcounts[], const MPI_Aint displs[],
                          MPI_Datatype recvtype, int root, MPI_Comm comm,
                          MPI_Request *request) {
  return (*MPIABI_Igatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcounts, displs, recvtype, root, comm,
                                  request);
}

inline int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, int root,
                       MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ireduce_ptr)(sendbuf, recvbuf, count, datatype, op, root,
                               comm, request);
}

inline int MPI_Ireduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Op op, int root,
                         MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ireduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, root,
                                 comm, request);
}

inline int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                               const int recvcounts[], MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ireduce_scatter_ptr)(sendbuf, recvbuf, recvcounts, datatype,
                                       op, comm, request);
}

inline int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                     int recvcount, MPI_Datatype datatype,
                                     MPI_Op op, MPI_Comm comm,
                                     MPI_Request *request) {
  return (*MPIABI_Ireduce_scatter_block_ptr)(sendbuf, recvbuf, recvcount,
                                             datatype, op, comm, request);
}

inline int MPI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                       MPI_Count recvcount,
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ireduce_scatter_block_c_ptr)(sendbuf, recvbuf, recvcount,
                                               datatype, op, comm, request);
}

inline int MPI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf,
                                 const MPI_Count recvcounts[],
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ireduce_scatter_c_ptr)(sendbuf, recvbuf, recvcounts, datatype,
                                         op, comm, request);
}

inline int MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
                     MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                     MPI_Request *request) {
  return (*MPIABI_Iscan_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                             request);
}

inline int MPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request) {
  return (*MPIABI_Iscan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                               request);
}

inline int MPI_Iscatter(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int root, MPI_Comm comm,
                        MPI_Request *request) {
  return (*MPIABI_Iscatter_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, root, comm, request);
}

inline int MPI_Iscatter_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          MPI_Count recvcount, MPI_Datatype recvtype, int root,
                          MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Iscatter_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcount, recvtype, root, comm, request);
}

inline int MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                         const int displs[], MPI_Datatype sendtype,
                         void *recvbuf, int recvcount, MPI_Datatype recvtype,
                         int root, MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Iscatterv_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                 recvcount, recvtype, root, comm, request);
}

inline int MPI_Iscatterv_c(const void *sendbuf, const MPI_Count sendcounts[],
                           const MPI_Aint displs[], MPI_Datatype sendtype,
                           void *recvbuf, MPI_Count recvcount,
                           MPI_Datatype recvtype, int root, MPI_Comm comm,
                           MPI_Request *request) {
  return (*MPIABI_Iscatterv_c_ptr)(sendbuf, sendcounts, displs, sendtype,
                                   recvbuf, recvcount, recvtype, root, comm,
                                   request);
}

inline int MPI_Op_commutative(MPI_Op op, int *commute) {
  return (*MPIABI_Op_commutative_ptr)(op, commute);
}

inline int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) {
  return (*MPIABI_Op_create_ptr)(user_fn, commute, op);
}

inline int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute,
                           MPI_Op *op) {
  return (*MPIABI_Op_create_c_ptr)(user_fn, commute, op);
}

inline int MPI_Op_free(MPI_Op *op) { return (*MPIABI_Op_free_ptr)(op); }

inline int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, int root,
                      MPI_Comm comm) {
  return (*MPIABI_Reduce_ptr)(sendbuf, recvbuf, count, datatype, op, root,
                              comm);
}

inline int MPI_Reduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Op op, int root,
                        MPI_Comm comm) {
  return (*MPIABI_Reduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, root,
                                comm);
}

inline int MPI_Reduce_init(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, int root,
                           MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Reduce_init_ptr)(sendbuf, recvbuf, count, datatype, op, root,
                                   comm, info, request);
}

inline int MPI_Reduce_init_c(const void *sendbuf, void *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             int root, MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return (*MPIABI_Reduce_init_c_ptr)(sendbuf, recvbuf, count, datatype, op,
                                     root, comm, info, request);
}

inline int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                            MPI_Datatype datatype, MPI_Op op) {
  return (*MPIABI_Reduce_local_ptr)(inbuf, inoutbuf, count, datatype, op);
}

inline int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf,
                              MPI_Count count, MPI_Datatype datatype,
                              MPI_Op op) {
  return (*MPIABI_Reduce_local_c_ptr)(inbuf, inoutbuf, count, datatype, op);
}

inline int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                              const int recvcounts[], MPI_Datatype datatype,
                              MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Reduce_scatter_ptr)(sendbuf, recvbuf, recvcounts, datatype,
                                      op, comm);
}

inline int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                    int recvcount, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Reduce_scatter_block_ptr)(sendbuf, recvbuf, recvcount,
                                            datatype, op, comm);
}

inline int MPI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                      MPI_Count recvcount,
                                      MPI_Datatype datatype, MPI_Op op,
                                      MPI_Comm comm) {
  return (*MPIABI_Reduce_scatter_block_c_ptr)(sendbuf, recvbuf, recvcount,
                                              datatype, op, comm);
}

inline int MPI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf,
                                         int recvcount, MPI_Datatype datatype,
                                         MPI_Op op, MPI_Comm comm,
                                         MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Reduce_scatter_block_init_ptr)(
      sendbuf, recvbuf, recvcount, datatype, op, comm, info, request);
}

inline int MPI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf,
                                           MPI_Count recvcount,
                                           MPI_Datatype datatype, MPI_Op op,
                                           MPI_Comm comm, MPI_Info info,
                                           MPI_Request *request) {
  return (*MPIABI_Reduce_scatter_block_init_c_ptr)(
      sendbuf, recvbuf, recvcount, datatype, op, comm, info, request);
}

inline int MPI_Reduce_scatter_c(const void *sendbuf, void *recvbuf,
                                const MPI_Count recvcounts[],
                                MPI_Datatype datatype, MPI_Op op,
                                MPI_Comm comm) {
  return (*MPIABI_Reduce_scatter_c_ptr)(sendbuf, recvbuf, recvcounts, datatype,
                                        op, comm);
}

inline int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf,
                                   const int recvcounts[],
                                   MPI_Datatype datatype, MPI_Op op,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request) {
  return (*MPIABI_Reduce_scatter_init_ptr)(sendbuf, recvbuf, recvcounts,
                                           datatype, op, comm, info, request);
}

inline int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf,
                                     const MPI_Count recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request) {
  return (*MPIABI_Reduce_scatter_init_c_ptr)(sendbuf, recvbuf, recvcounts,
                                             datatype, op, comm, info, request);
}

inline int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Scan_ptr)(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Scan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return (*MPIABI_Scan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Scan_init(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Scan_init_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                                 info, request);
}

inline int MPI_Scan_init_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                           MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Scan_init_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm,
                                   info, request);
}

inline int MPI_Scatter(const void *sendbuf, int sendcount,
                       MPI_Datatype sendtype, void *recvbuf, int recvcount,
                       MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return (*MPIABI_Scatter_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, root, comm);
}

inline int MPI_Scatter_c(const void *sendbuf, MPI_Count sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         MPI_Count recvcount, MPI_Datatype recvtype, int root,
                         MPI_Comm comm) {
  return (*MPIABI_Scatter_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, root, comm);
}

inline int MPI_Scatter_init(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Scatter_init_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, root, comm, info,
                                    request);
}

inline int MPI_Scatter_init_c(const void *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Count recvcount, MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return (*MPIABI_Scatter_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcount, recvtype, root, comm, info,
                                      request);
}

inline int MPI_Scatterv(const void *sendbuf, const int sendcounts[],
                        const int displs[], MPI_Datatype sendtype,
                        void *recvbuf, int recvcount, MPI_Datatype recvtype,
                        int root, MPI_Comm comm) {
  return (*MPIABI_Scatterv_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                recvcount, recvtype, root, comm);
}

inline int MPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[],
                          const MPI_Aint displs[], MPI_Datatype sendtype,
                          void *recvbuf, MPI_Count recvcount,
                          MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return (*MPIABI_Scatterv_c_ptr)(sendbuf, sendcounts, displs, sendtype,
                                  recvbuf, recvcount, recvtype, root, comm);
}

inline int MPI_Scatterv_init(const void *sendbuf, const int sendcounts[],
                             const int displs[], MPI_Datatype sendtype,
                             void *recvbuf, int recvcount,
                             MPI_Datatype recvtype, int root, MPI_Comm comm,
                             MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Scatterv_init_ptr)(sendbuf, sendcounts, displs, sendtype,
                                     recvbuf, recvcount, recvtype, root, comm,
                                     info, request);
}

inline int MPI_Scatterv_init_c(const void *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype,
                               void *recvbuf, MPI_Count recvcount,
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Scatterv_init_c_ptr)(sendbuf, sendcounts, displs, sendtype,
                                       recvbuf, recvcount, recvtype, root, comm,
                                       info, request);
}

inline int MPI_Type_get_value_index(MPI_Datatype value_type,
                                    MPI_Datatype index_type,
                                    MPI_Datatype *pair_type) {
  return (*MPIABI_Type_get_value_index_ptr)(value_type, index_type, pair_type);
}

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

inline int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) {
  return (*MPIABI_Comm_compare_ptr)(comm1, comm2, result);
}

inline int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) {
  return (*MPIABI_Comm_create_ptr)(comm, group, newcomm);
}

inline int MPI_Comm_create_from_group(MPI_Group group, const char *stringtag,
                                      MPI_Info info, MPI_Errhandler errhandler,
                                      MPI_Comm *newcomm) {
  return (*MPIABI_Comm_create_from_group_ptr)(group, stringtag, info,
                                              errhandler, newcomm);
}

inline int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                 MPI_Comm *newcomm) {
  return (*MPIABI_Comm_create_group_ptr)(comm, group, tag, newcomm);
}

inline int
MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                       MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                       int *comm_keyval, void *extra_state) {
  return (*MPIABI_Comm_create_keyval_ptr)(
      comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state);
}

inline int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) {
  return (*MPIABI_Comm_delete_attr_ptr)(comm, comm_keyval);
}

inline int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
  return (*MPIABI_Comm_dup_ptr)(comm, newcomm);
}

inline int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                  MPI_Comm *newcomm) {
  return (*MPIABI_Comm_dup_with_info_ptr)(comm, info, newcomm);
}

inline int MPI_Comm_free(MPI_Comm *comm) {
  return (*MPIABI_Comm_free_ptr)(comm);
}

inline int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) {
  return (*MPIABI_Comm_get_name_ptr)(comm, comm_name, resultlen);
}

inline int MPI_Comm_free_keyval(int *comm_keyval) {
  return (*MPIABI_Comm_free_keyval_ptr)(comm_keyval);
}

inline int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                             void *attribute_val, int *flag) {
  return (*MPIABI_Comm_get_attr_ptr)(comm, comm_keyval, attribute_val, flag);
}

inline int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) {
  return (*MPIABI_Comm_get_info_ptr)(comm, info_used);
}

inline int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) {
  return (*MPIABI_Comm_group_ptr)(comm, group);
}

inline int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                         MPI_Request *request) {
  return (*MPIABI_Comm_idup_ptr)(comm, newcomm, request);
}

inline int MPI_Comm_idup_with_info(MPI_Comm comm, MPI_Info info,
                                   MPI_Comm *newcomm, MPI_Request *request) {
  return (*MPIABI_Comm_idup_with_info_ptr)(comm, info, newcomm, request);
}

inline int MPI_Comm_rank(MPI_Comm comm, int *rank) {
  return (*MPIABI_Comm_rank_ptr)(comm, rank);
}

inline int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) {
  return (*MPIABI_Comm_remote_group_ptr)(comm, group);
}

inline int MPI_Comm_remote_size(MPI_Comm comm, int *size) {
  return (*MPIABI_Comm_remote_size_ptr)(comm, size);
}

inline int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                             void *attribute_val) {
  return (*MPIABI_Comm_set_attr_ptr)(comm, comm_keyval, attribute_val);
}

inline int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) {
  return (*MPIABI_Comm_set_info_ptr)(comm, info);
}

inline int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) {
  return (*MPIABI_Comm_set_name_ptr)(comm, comm_name);
}

inline int MPI_Comm_size(MPI_Comm comm, int *size) {
  return (*MPIABI_Comm_size_ptr)(comm, size);
}

inline int MPI_Comm_split(MPI_Comm comm, int color, int key,
                          MPI_Comm *newcomm) {
  return (*MPIABI_Comm_split_ptr)(comm, color, key, newcomm);
}

inline int MPI_Group_free(MPI_Group *group) {
  return (*MPIABI_Group_free_ptr)(group);
}

inline int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                               MPI_Info info, MPI_Comm *newcomm) {
  return (*MPIABI_Comm_split_type_ptr)(comm, split_type, key, info, newcomm);
}

inline int MPI_Comm_test_inter(MPI_Comm comm, int *flag) {
  return (*MPIABI_Comm_test_inter_ptr)(comm, flag);
}

inline int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) {
  return (*MPIABI_Group_compare_ptr)(group1, group2, result);
}

inline int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                MPI_Group *newgroup) {
  return (*MPIABI_Group_difference_ptr)(group1, group2, newgroup);
}

inline int MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                          MPI_Group *newgroup) {
  return (*MPIABI_Group_excl_ptr)(group, n, ranks, newgroup);
}

inline int MPI_Group_from_session_pset(MPI_Session session,
                                       const char *pset_name,
                                       MPI_Group *newgroup) {
  return (*MPIABI_Group_from_session_pset_ptr)(session, pset_name, newgroup);
}

inline int MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                          MPI_Group *newgroup) {
  return (*MPIABI_Group_incl_ptr)(group, n, ranks, newgroup);
}

inline int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup) {
  return (*MPIABI_Group_intersection_ptr)(group1, group2, newgroup);
}

inline int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                MPI_Group *newgroup) {
  return (*MPIABI_Group_range_excl_ptr)(group, n, ranges, newgroup);
}

inline int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                MPI_Group *newgroup) {
  return (*MPIABI_Group_range_incl_ptr)(group, n, ranges, newgroup);
}

inline int MPI_Group_rank(MPI_Group group, int *rank) {
  return (*MPIABI_Group_rank_ptr)(group, rank);
}

inline int MPI_Group_size(MPI_Group group, int *size) {
  return (*MPIABI_Group_size_ptr)(group, size);
}

inline int MPI_Group_translate_ranks(MPI_Group group1, int n,
                                     const int ranks1[], MPI_Group group2,
                                     int ranks2[]) {
  return (*MPIABI_Group_translate_ranks_ptr)(group1, n, ranks1, group2, ranks2);
}

inline int MPI_Group_union(MPI_Group group1, MPI_Group group2,
                           MPI_Group *newgroup) {
  return (*MPIABI_Group_union_ptr)(group1, group2, newgroup);
}

inline int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                MPI_Comm peer_comm, int remote_leader, int tag,
                                MPI_Comm *newintercomm) {
  return (*MPIABI_Intercomm_create_ptr)(local_comm, local_leader, peer_comm,
                                        remote_leader, tag, newintercomm);
}

inline int MPI_Intercomm_create_from_groups(
    MPI_Group local_group, int local_leader, MPI_Group remote_group,
    int remote_leader, const char *stringtag, MPI_Info info,
    MPI_Errhandler errhandler, MPI_Comm *newintercomm) {
  return (*MPIABI_Intercomm_create_from_groups_ptr)(
      local_group, local_leader, remote_group, remote_leader, stringtag, info,
      errhandler, newintercomm);
}

inline int MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                               MPI_Comm *newintracomm) {
  return (*MPIABI_Intercomm_merge_ptr)(intercomm, high, newintracomm);
}

inline int
MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                       MPI_Type_delete_attr_function *type_delete_attr_fn,
                       int *type_keyval, void *extra_state) {
  return (*MPIABI_Type_create_keyval_ptr)(
      type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state);
}

inline int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) {
  return (*MPIABI_Type_delete_attr_ptr)(datatype, type_keyval);
}

inline int MPI_Type_free_keyval(int *type_keyval) {
  return (*MPIABI_Type_free_keyval_ptr)(type_keyval);
}

inline int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                             void *attribute_val, int *flag) {
  return (*MPIABI_Type_get_attr_ptr)(datatype, type_keyval, attribute_val,
                                     flag);
}

inline int MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                             int *resultlen) {
  return (*MPIABI_Type_get_name_ptr)(datatype, type_name, resultlen);
}

inline int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                             void *attribute_val) {
  return (*MPIABI_Type_set_attr_ptr)(datatype, type_keyval, attribute_val);
}

inline int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name) {
  return (*MPIABI_Type_set_name_ptr)(datatype, type_name);
}

inline int
MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                      MPI_Win_delete_attr_function *win_delete_attr_fn,
                      int *win_keyval, void *extra_state) {
  return (*MPIABI_Win_create_keyval_ptr)(win_copy_attr_fn, win_delete_attr_fn,
                                         win_keyval, extra_state);
}

inline int MPI_Win_delete_attr(MPI_Win win, int win_keyval) {
  return (*MPIABI_Win_delete_attr_ptr)(win, win_keyval);
}

inline int MPI_Win_free_keyval(int *win_keyval) {
  return (*MPIABI_Win_free_keyval_ptr)(win_keyval);
}

inline int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                            int *flag) {
  return (*MPIABI_Win_get_attr_ptr)(win, win_keyval, attribute_val, flag);
}

inline int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) {
  return (*MPIABI_Win_get_name_ptr)(win, win_name, resultlen);
}

inline int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) {
  return (*MPIABI_Win_set_attr_ptr)(win, win_keyval, attribute_val);
}

inline int MPI_Win_set_name(MPI_Win win, const char *win_name) {
  return (*MPIABI_Win_set_name_ptr)(win, win_name);
}

// A.3.6 Virtual Topologies for MPI Processes C Bindings

inline int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) {
  return (*MPIABI_Cart_coords_ptr)(comm, rank, maxdims, coords);
}

inline int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[],
                           const int periods[], int reorder,
                           MPI_Comm *comm_cart) {
  return (*MPIABI_Cart_create_ptr)(comm_old, ndims, dims, periods, reorder,
                                   comm_cart);
}

inline int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                        int coords[]) {
  return (*MPIABI_Cart_get_ptr)(comm, maxdims, dims, periods, coords);
}

inline int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                        const int periods[], int *newrank) {
  return (*MPIABI_Cart_map_ptr)(comm, ndims, dims, periods, newrank);
}

inline int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) {
  return (*MPIABI_Cart_rank_ptr)(comm, coords, rank);
}

inline int MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                          int *rank_source, int *rank_dest) {
  return (*MPIABI_Cart_shift_ptr)(comm, direction, disp, rank_source,
                                  rank_dest);
}

inline int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[],
                        MPI_Comm *newcomm) {
  return (*MPIABI_Cart_sub_ptr)(comm, remain_dims, newcomm);
}

inline int MPI_Cartdim_get(MPI_Comm comm, int *ndims) {
  return (*MPIABI_Cartdim_get_ptr)(comm, ndims);
}

inline int MPI_Dims_create(int nnodes, int ndims, int dims[]) {
  return (*MPIABI_Dims_create_ptr)(nnodes, ndims, dims);
}

inline int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[],
                                 const int degrees[], const int destinations[],
                                 const int weights[], MPI_Info info,
                                 int reorder, MPI_Comm *comm_dist_graph) {
  return (*MPIABI_Dist_graph_create_ptr)(comm_old, n, sources, degrees,
                                         destinations, weights, info, reorder,
                                         comm_dist_graph);
}

inline int
MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                               const int sources[], const int sourceweights[],
                               int outdegree, const int destinations[],
                               const int destweights[], MPI_Info info,
                               int reorder, MPI_Comm *comm_dist_graph) {
  return (*MPIABI_Dist_graph_create_adjacent_ptr)(
      comm_old, indegree, sources, sourceweights, outdegree, destinations,
      destweights, info, reorder, comm_dist_graph);
}

inline int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                    int sources[], int sourceweights[],
                                    int maxoutdegree, int destinations[],
                                    int destweights[]) {
  return (*MPIABI_Dist_graph_neighbors_ptr)(comm, maxindegree, sources,
                                            sourceweights, maxoutdegree,
                                            destinations, destweights);
}

inline int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                          int *outdegree, int *weighted) {
  return (*MPIABI_Dist_graph_neighbors_count_ptr)(comm, indegree, outdegree,
                                                  weighted);
}

inline int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[],
                            const int edges[], int reorder,
                            MPI_Comm *comm_graph) {
  return (*MPIABI_Graph_create_ptr)(comm_old, nnodes, index, edges, reorder,
                                    comm_graph);
}

inline int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[],
                         int edges[]) {
  return (*MPIABI_Graph_get_ptr)(comm, maxindex, maxedges, index, edges);
}

inline int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[],
                         const int edges[], int *newrank) {
  return (*MPIABI_Graph_map_ptr)(comm, nnodes, index, edges, newrank);
}

inline int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                               int neighbors[]) {
  return (*MPIABI_Graph_neighbors_ptr)(comm, rank, maxneighbors, neighbors);
}

inline int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) {
  return (*MPIABI_Graph_neighbors_count_ptr)(comm, rank, nneighbors);
}

inline int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) {
  return (*MPIABI_Graphdims_get_ptr)(comm, nnodes, nedges);
}

inline int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_allgather_ptr)(sendbuf, sendcount, sendtype,
                                           recvbuf, recvcount, recvtype, comm,
                                           request);
}

inline int MPI_Ineighbor_allgather_c(const void *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Count recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_allgather_c_ptr)(sendbuf, sendcount, sendtype,
                                             recvbuf, recvcount, recvtype, comm,
                                             request);
}

inline int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    const int recvcounts[], const int displs[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Request *request) {
  return (*MPIABI_Ineighbor_allgatherv_ptr)(sendbuf, sendcount, sendtype,
                                            recvbuf, recvcounts, displs,
                                            recvtype, comm, request);
}

inline int MPI_Ineighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const MPI_Count recvcounts[],
                                      const MPI_Aint displs[],
                                      MPI_Datatype recvtype, MPI_Comm comm,
                                      MPI_Request *request) {
  return (*MPIABI_Ineighbor_allgatherv_c_ptr)(sendbuf, sendcount, sendtype,
                                              recvbuf, recvcounts, displs,
                                              recvtype, comm, request);
}

inline int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_alltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcount, recvtype, comm, request);
}

inline int MPI_Ineighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_alltoall_c_ptr)(sendbuf, sendcount, sendtype,
                                            recvbuf, recvcount, recvtype, comm,
                                            request);
}

inline int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                   const int sdispls[], MPI_Datatype sendtype,
                                   void *recvbuf, const int recvcounts[],
                                   const int rdispls[], MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_alltoallv_ptr)(sendbuf, sendcounts, sdispls,
                                           sendtype, recvbuf, recvcounts,
                                           rdispls, recvtype, comm, request);
}

inline int
MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                          const MPI_Aint sdispls[], MPI_Datatype sendtype,
                          void *recvbuf, const MPI_Count recvcounts[],
                          const MPI_Aint rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_alltoallv_c_ptr)(sendbuf, sendcounts, sdispls,
                                             sendtype, recvbuf, recvcounts,
                                             rdispls, recvtype, comm, request);
}

inline int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                                   const MPI_Aint sdispls[],
                                   const MPI_Datatype sendtypes[],
                                   void *recvbuf, const int recvcounts[],
                                   const MPI_Aint rdispls[],
                                   const MPI_Datatype recvtypes[],
                                   MPI_Comm comm, MPI_Request *request) {
  return (*MPIABI_Ineighbor_alltoallw_ptr)(sendbuf, sendcounts, sdispls,
                                           sendtypes, recvbuf, recvcounts,
                                           rdispls, recvtypes, comm, request);
}

inline int MPI_Ineighbor_alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request) {
  return (*MPIABI_Ineighbor_alltoallw_c_ptr)(sendbuf, sendcounts, sdispls,
                                             sendtypes, recvbuf, recvcounts,
                                             rdispls, recvtypes, comm, request);
}

inline int MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm) {
  return (*MPIABI_Neighbor_allgather_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcount, recvtype, comm);
}

inline int MPI_Neighbor_allgather_c(const void *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm) {
  return (*MPIABI_Neighbor_allgather_c_ptr)(sendbuf, sendcount, sendtype,
                                            recvbuf, recvcount, recvtype, comm);
}

inline int MPI_Neighbor_allgather_init(const void *sendbuf, int sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       int recvcount, MPI_Datatype recvtype,
                                       MPI_Comm comm, MPI_Info info,
                                       MPI_Request *request) {
  return (*MPIABI_Neighbor_allgather_init_ptr)(sendbuf, sendcount, sendtype,
                                               recvbuf, recvcount, recvtype,
                                               comm, info, request);
}

inline int MPI_Neighbor_allgather_init_c(const void *sendbuf,
                                         MPI_Count sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         MPI_Count recvcount,
                                         MPI_Datatype recvtype, MPI_Comm comm,
                                         MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_allgather_init_c_ptr)(sendbuf, sendcount, sendtype,
                                                 recvbuf, recvcount, recvtype,
                                                 comm, info, request);
}

inline int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const int recvcounts[], const int displs[],
                                   MPI_Datatype recvtype, MPI_Comm comm) {
  return (*MPIABI_Neighbor_allgatherv_ptr)(sendbuf, sendcount, sendtype,
                                           recvbuf, recvcounts, displs,
                                           recvtype, comm);
}

inline int MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const MPI_Count recvcounts[],
                                     const MPI_Aint displs[],
                                     MPI_Datatype recvtype, MPI_Comm comm) {
  return (*MPIABI_Neighbor_allgatherv_c_ptr)(sendbuf, sendcount, sendtype,
                                             recvbuf, recvcounts, displs,
                                             recvtype, comm);
}

inline int MPI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const int recvcounts[],
                                        const int displs[],
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_allgatherv_init_ptr)(sendbuf, sendcount, sendtype,
                                                recvbuf, recvcounts, displs,
                                                recvtype, comm, info, request);
}

inline int MPI_Neighbor_allgatherv_init_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_allgatherv_init_c_ptr)(
      sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm,
      info, request);
}

inline int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm) {
  return (*MPIABI_Neighbor_alltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcount, recvtype, comm);
}

inline int MPI_Neighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm) {
  return (*MPIABI_Neighbor_alltoall_c_ptr)(sendbuf, sendcount, sendtype,
                                           recvbuf, recvcount, recvtype, comm);
}

inline int MPI_Neighbor_alltoall_init(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      int recvcount, MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Info info,
                                      MPI_Request *request) {
  return (*MPIABI_Neighbor_alltoall_init_ptr)(sendbuf, sendcount, sendtype,
                                              recvbuf, recvcount, recvtype,
                                              comm, info, request);
}

inline int MPI_Neighbor_alltoall_init_c(const void *sendbuf,
                                        MPI_Count sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Count recvcount,
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_alltoall_init_c_ptr)(sendbuf, sendcount, sendtype,
                                                recvbuf, recvcount, recvtype,
                                                comm, info, request);
}

inline int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                  const int sdispls[], MPI_Datatype sendtype,
                                  void *recvbuf, const int recvcounts[],
                                  const int rdispls[], MPI_Datatype recvtype,
                                  MPI_Comm comm) {
  return (*MPIABI_Neighbor_alltoallv_ptr)(sendbuf, sendcounts, sdispls,
                                          sendtype, recvbuf, recvcounts,
                                          rdispls, recvtype, comm);
}

inline int MPI_Neighbor_alltoallv_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm) {
  return (*MPIABI_Neighbor_alltoallv_c_ptr)(sendbuf, sendcounts, sdispls,
                                            sendtype, recvbuf, recvcounts,
                                            rdispls, recvtype, comm);
}

inline int MPI_Neighbor_alltoallv_init(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
    MPI_Request *request) {
  return (*MPIABI_Neighbor_alltoallv_init_ptr)(
      sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
      recvtype, comm, info, request);
}

inline int MPI_Neighbor_alltoallv_init_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
    MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_alltoallv_init_c_ptr)(
      sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
      recvtype, comm, info, request);
}

inline int MPI_Neighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return (*MPIABI_Neighbor_alltoallw_ptr)(sendbuf, sendcounts, sdispls,
                                          sendtypes, recvbuf, recvcounts,
                                          rdispls, recvtypes, comm);
}

inline int MPI_Neighbor_alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return (*MPIABI_Neighbor_alltoallw_c_ptr)(sendbuf, sendcounts, sdispls,
                                            sendtypes, recvbuf, recvcounts,
                                            rdispls, recvtypes, comm);
}

inline int MPI_Neighbor_alltoallw_init(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_alltoallw_init_ptr)(
      sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
      recvtypes, comm, info, request);
}

inline int MPI_Neighbor_alltoallw_init_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Info info, MPI_Request *request) {
  return (*MPIABI_Neighbor_alltoallw_init_c_ptr)(
      sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
      recvtypes, comm, info, request);
}

inline int MPI_Topo_test(MPI_Comm comm, int *status) {
  return (*MPIABI_Topo_test_ptr)(comm, status);
}

// A.3.7 MPI Environmental Management C Bindings

inline int MPI_Add_error_class(int *errorclass) {
  return (*MPIABI_Add_error_class_ptr)(errorclass);
}

inline int MPI_Add_error_code(int errorclass, int *errorcode) {
  return (*MPIABI_Add_error_code_ptr)(errorclass, errorcode);
}

inline int MPI_Add_error_string(int errorcode, const char *string) {
  return (*MPIABI_Add_error_string_ptr)(errorcode, string);
}

inline int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) {
  return (*MPIABI_Alloc_mem_ptr)(size, info, baseptr);
}

inline int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) {
  return (*MPIABI_Comm_call_errhandler_ptr)(comm, errorcode);
}

inline int
MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn,
                           MPI_Errhandler *errhandler) {
  return (*MPIABI_Comm_create_errhandler_ptr)(comm_errhandler_fn, errhandler);
}

inline int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler) {
  return (*MPIABI_Comm_get_errhandler_ptr)(comm, errhandler);
}

inline int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) {
  return (*MPIABI_Comm_set_errhandler_ptr)(comm, errhandler);
}

inline int MPI_Errhandler_free(MPI_Errhandler *errhandler) {
  return (*MPIABI_Errhandler_free_ptr)(errhandler);
}

inline int MPI_Error_class(int errorcode, int *errorclass) {
  return (*MPIABI_Error_class_ptr)(errorcode, errorclass);
}

inline int MPI_Error_string(int errorcode, char *string, int *resultlen) {
  return (*MPIABI_Error_string_ptr)(errorcode, string, resultlen);
}

inline int MPI_File_call_errhandler(MPI_File fh, int errorcode) {
  return (*MPIABI_File_call_errhandler_ptr)(fh, errorcode);
}

inline int
MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn,
                           MPI_Errhandler *errhandler) {
  return (*MPIABI_File_create_errhandler_ptr)(file_errhandler_fn, errhandler);
}

inline int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) {
  return (*MPIABI_File_get_errhandler_ptr)(file, errhandler);
}

inline int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) {
  return (*MPIABI_File_set_errhandler_ptr)(file, errhandler);
}

inline int MPI_Free_mem(void *base) { return (*MPIABI_Free_mem_ptr)(base); }

inline int MPI_Get_hw_resource_info(MPI_Info *hw_info) {
  return (*MPIABI_Get_hw_resource_info_ptr)(hw_info);
}

inline int MPI_Get_library_version(char *version, int *resultlen) {
  return (*MPIABI_Get_library_version_ptr)(version, resultlen);
}

inline int MPI_Get_processor_name(char *name, int *resultlen) {
  return (*MPIABI_Get_processor_name_ptr)(name, resultlen);
}

inline int MPI_Get_version(int *version, int *subversion) {
  return (*MPIABI_Get_version_ptr)(version, subversion);
}

inline int MPI_Remove_error_class(int errorclass) {
  return (*MPIABI_Remove_error_class_ptr)(errorclass);
}

inline int MPI_Remove_error_code(int errorcode) {
  return (*MPIABI_Remove_error_code_ptr)(errorcode);
}

inline int MPI_Remove_error_string(int errorcode) {
  return (*MPIABI_Remove_error_string_ptr)(errorcode);
}

inline int MPI_Session_call_errhandler(MPI_Session session, int errorcode) {
  return (*MPIABI_Session_call_errhandler_ptr)(session, errorcode);
}

inline int MPI_Session_create_errhandler(
    MPI_Session_errhandler_function *session_errhandler_fn,
    MPI_Errhandler *errhandler) {
  return (*MPIABI_Session_create_errhandler_ptr)(session_errhandler_fn,
                                                 errhandler);
}

inline int MPI_Session_get_errhandler(MPI_Session session,
                                      MPI_Errhandler *errhandler) {
  return (*MPIABI_Session_get_errhandler_ptr)(session, errhandler);
}

inline int MPI_Session_set_errhandler(MPI_Session session,
                                      MPI_Errhandler errhandler) {
  return (*MPIABI_Session_set_errhandler_ptr)(session, errhandler);
}

inline int MPI_Win_call_errhandler(MPI_Win win, int errorcode) {
  return (*MPIABI_Win_call_errhandler_ptr)(win, errorcode);
}

inline int
MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn,
                          MPI_Errhandler *errhandler) {
  return (*MPIABI_Win_create_errhandler_ptr)(win_errhandler_fn, errhandler);
}

inline int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) {
  return (*MPIABI_Win_get_errhandler_ptr)(win, errhandler);
}

inline int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) {
  return (*MPIABI_Win_set_errhandler_ptr)(win, errhandler);
}

inline double MPI_Wtick(void) { return (*MPIABI_Wtick_ptr)(); }

inline double MPI_Wtime(void) { return (*MPIABI_Wtime_ptr)(); }

// A.3.8 The Info Object C Bindings

inline int MPI_Info_create(MPI_Info *info) {
  return (*MPIABI_Info_create_ptr)(info);
}

inline int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info) {
  return (*MPIABI_Info_create_env_ptr)(argc, argv, info);
}

inline int MPI_Info_delete(MPI_Info info, const char *key) {
  return (*MPIABI_Info_delete_ptr)(info, key);
}

inline int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) {
  return (*MPIABI_Info_dup_ptr)(info, newinfo);
}

inline int MPI_Info_free(MPI_Info *info) {
  return (*MPIABI_Info_free_ptr)(info);
}

inline int MPI_Info_get_nkeys(MPI_Info info, int *nkeys) {
  return (*MPIABI_Info_get_nkeys_ptr)(info, nkeys);
}

inline int MPI_Info_get_nthkey(MPI_Info info, int n, char *key) {
  return (*MPIABI_Info_get_nthkey_ptr)(info, n, key);
}

inline int MPI_Info_get_string(MPI_Info info, const char *key, int *buflen,
                               char *value, int *flag) {
  return (*MPIABI_Info_get_string_ptr)(info, key, buflen, value, flag);
}

inline int MPI_Info_set(MPI_Info info, const char *key, const char *value) {
  return (*MPIABI_Info_set_ptr)(info, key, value);
}

// A.3.9 Process Creation and Management C Bindings

inline int MPI_Abort(MPI_Comm comm, int errorcode) {
  return (*MPIABI_Abort_ptr)(comm, errorcode);
}

inline int MPI_Close_port(const char *port_name) {
  return (*MPIABI_Close_port_ptr)(port_name);
}

inline int MPI_Comm_accept(const char *port_name, MPI_Info info, int root,
                           MPI_Comm comm, MPI_Comm *newcomm) {
  return (*MPIABI_Comm_accept_ptr)(port_name, info, root, comm, newcomm);
}

inline int MPI_Comm_connect(const char *port_name, MPI_Info info, int root,
                            MPI_Comm comm, MPI_Comm *newcomm) {
  return (*MPIABI_Comm_connect_ptr)(port_name, info, root, comm, newcomm);
}

inline int MPI_Comm_disconnect(MPI_Comm *comm) {
  return (*MPIABI_Comm_disconnect_ptr)(comm);
}

inline int MPI_Comm_get_parent(MPI_Comm *parent) {
  return (*MPIABI_Comm_get_parent_ptr)(parent);
}

inline int MPI_Comm_join(int fd, MPI_Comm *intercomm) {
  return (*MPIABI_Comm_join_ptr)(fd, intercomm);
}

inline int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs,
                          MPI_Info info, int root, MPI_Comm comm,
                          MPI_Comm *intercomm, int array_of_errcodes[]) {
  return (*MPIABI_Comm_spawn_ptr)(command, argv, maxprocs, info, root, comm,
                                  intercomm, array_of_errcodes);
}

inline int MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                                   char **array_of_argv[],
                                   const int array_of_maxprocs[],
                                   const MPI_Info array_of_info[], int root,
                                   MPI_Comm comm, MPI_Comm *intercomm,
                                   int array_of_errcodes[]) {
  return (*MPIABI_Comm_spawn_multiple_ptr)(
      count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info,
      root, comm, intercomm, array_of_errcodes);
}

inline int MPI_Finalize(void) { return (*MPIABI_Finalize_ptr)(); }

inline int MPI_Finalized(int *flag) { return (*MPIABI_Finalized_ptr)(flag); }

inline int MPI_Init(int *argc, char ***argv) {
  return (*MPIABI_Init_ptr)(argc, argv);
}

inline int MPI_Init_thread(int *argc, char ***argv, int required,
                           int *provided) {
  return (*MPIABI_Init_thread_ptr)(argc, argv, required, provided);
}

inline int MPI_Initialized(int *flag) {
  return (*MPIABI_Initialized_ptr)(flag);
}

inline int MPI_Is_thread_main(int *flag) {
  return (*MPIABI_Is_thread_main_ptr)(flag);
}

inline int MPI_Lookup_name(const char *service_name, MPI_Info info,
                           char *port_name) {
  return (*MPIABI_Lookup_name_ptr)(service_name, info, port_name);
}

inline int MPI_Open_port(MPI_Info info, char *port_name) {
  return (*MPIABI_Open_port_ptr)(info, port_name);
}

inline int MPI_Publish_name(const char *service_name, MPI_Info info,
                            const char *port_name) {
  return (*MPIABI_Publish_name_ptr)(service_name, info, port_name);
}

inline int MPI_Query_thread(int *provided) {
  return (*MPIABI_Query_thread_ptr)(provided);
}

inline int MPI_Session_finalize(MPI_Session *session) {
  return (*MPIABI_Session_finalize_ptr)(session);
}

inline int MPI_Session_get_info(MPI_Session session, MPI_Info *info_used) {
  return (*MPIABI_Session_get_info_ptr)(session, info_used);
}

inline int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n,
                                    int *pset_len, char *pset_name) {
  return (*MPIABI_Session_get_nth_pset_ptr)(session, info, n, pset_len,
                                            pset_name);
}

inline int MPI_Session_get_num_psets(MPI_Session session, MPI_Info info,
                                     int *npset_names) {
  return (*MPIABI_Session_get_num_psets_ptr)(session, info, npset_names);
}

inline int MPI_Session_get_pset_info(MPI_Session session, const char *pset_name,
                                     MPI_Info *info) {
  return (*MPIABI_Session_get_pset_info_ptr)(session, pset_name, info);
}

inline int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler,
                            MPI_Session *session) {
  return (*MPIABI_Session_init_ptr)(info, errhandler, session);
}

inline int MPI_Unpublish_name(const char *service_name, MPI_Info info,
                              const char *port_name) {
  return (*MPIABI_Unpublish_name_ptr)(service_name, info, port_name);
}

// A.3.10 One-Sided Communications C Bindings

inline int MPI_Accumulate(const void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Op op,
                          MPI_Win win) {
  return (*MPIABI_Accumulate_ptr)(origin_addr, origin_count, origin_datatype,
                                  target_rank, target_disp, target_count,
                                  target_datatype, op, win);
}

inline int MPI_Accumulate_c(const void *origin_addr, MPI_Count origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Count target_count,
                            MPI_Datatype target_datatype, MPI_Op op,
                            MPI_Win win) {
  return (*MPIABI_Accumulate_c_ptr)(origin_addr, origin_count, origin_datatype,
                                    target_rank, target_disp, target_count,
                                    target_datatype, op, win);
}

inline int MPI_Compare_and_swap(const void *origin_addr,
                                const void *compare_addr, void *result_addr,
                                MPI_Datatype datatype, int target_rank,
                                MPI_Aint target_disp, MPI_Win win) {
  return (*MPIABI_Compare_and_swap_ptr)(origin_addr, compare_addr, result_addr,
                                        datatype, target_rank, target_disp,
                                        win);
}

inline int MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                            MPI_Datatype datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Op op, MPI_Win win) {
  return (*MPIABI_Fetch_and_op_ptr)(origin_addr, result_addr, datatype,
                                    target_rank, target_disp, op, win);
}

inline int MPI_Get(void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win) {
  return (*MPIABI_Get_ptr)(origin_addr, origin_count, origin_datatype,
                           target_rank, target_disp, target_count,
                           target_datatype, win);
}

inline int MPI_Get_accumulate(const void *origin_addr, int origin_count,
                              MPI_Datatype origin_datatype, void *result_addr,
                              int result_count, MPI_Datatype result_datatype,
                              int target_rank, MPI_Aint target_disp,
                              int target_count, MPI_Datatype target_datatype,
                              MPI_Op op, MPI_Win win) {
  return (*MPIABI_Get_accumulate_ptr)(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win);
}

inline int MPI_Get_accumulate_c(const void *origin_addr, MPI_Count origin_count,
                                MPI_Datatype origin_datatype, void *result_addr,
                                MPI_Count result_count,
                                MPI_Datatype result_datatype, int target_rank,
                                MPI_Aint target_disp, MPI_Count target_count,
                                MPI_Datatype target_datatype, MPI_Op op,
                                MPI_Win win) {
  return (*MPIABI_Get_accumulate_c_ptr)(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win);
}

inline int MPI_Get_c(void *origin_addr, MPI_Count origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Count target_count,
                     MPI_Datatype target_datatype, MPI_Win win) {
  return (*MPIABI_Get_c_ptr)(origin_addr, origin_count, origin_datatype,
                             target_rank, target_disp, target_count,
                             target_datatype, win);
}

inline int MPI_Put(const void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win) {
  return (*MPIABI_Put_ptr)(origin_addr, origin_count, origin_datatype,
                           target_rank, target_disp, target_count,
                           target_datatype, win);
}

inline int MPI_Put_c(const void *origin_addr, MPI_Count origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Count target_count,
                     MPI_Datatype target_datatype, MPI_Win win) {
  return (*MPIABI_Put_c_ptr)(origin_addr, origin_count, origin_datatype,
                             target_rank, target_disp, target_count,
                             target_datatype, win);
}

inline int MPI_Raccumulate(const void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                           MPI_Request *request) {
  return (*MPIABI_Raccumulate_ptr)(origin_addr, origin_count, origin_datatype,
                                   target_rank, target_disp, target_count,
                                   target_datatype, op, win, request);
}

inline int MPI_Raccumulate_c(const void *origin_addr, MPI_Count origin_count,
                             MPI_Datatype origin_datatype, int target_rank,
                             MPI_Aint target_disp, MPI_Count target_count,
                             MPI_Datatype target_datatype, MPI_Op op,
                             MPI_Win win, MPI_Request *request) {
  return (*MPIABI_Raccumulate_c_ptr)(origin_addr, origin_count, origin_datatype,
                                     target_rank, target_disp, target_count,
                                     target_datatype, op, win, request);
}

inline int MPI_Rget(void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request) {
  return (*MPIABI_Rget_ptr)(origin_addr, origin_count, origin_datatype,
                            target_rank, target_disp, target_count,
                            target_datatype, win, request);
}

inline int MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                               MPI_Datatype origin_datatype, void *result_addr,
                               int result_count, MPI_Datatype result_datatype,
                               int target_rank, MPI_Aint target_disp,
                               int target_count, MPI_Datatype target_datatype,
                               MPI_Op op, MPI_Win win, MPI_Request *request) {
  return (*MPIABI_Rget_accumulate_ptr)(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win, request);
}

inline int MPI_Rget_accumulate_c(const void *origin_addr,
                                 MPI_Count origin_count,
                                 MPI_Datatype origin_datatype,
                                 void *result_addr, MPI_Count result_count,
                                 MPI_Datatype result_datatype, int target_rank,
                                 MPI_Aint target_disp, MPI_Count target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win, MPI_Request *request) {
  return (*MPIABI_Rget_accumulate_c_ptr)(
      origin_addr, origin_count, origin_datatype, result_addr, result_count,
      result_datatype, target_rank, target_disp, target_count, target_datatype,
      op, win, request);
}

inline int MPI_Rget_c(void *origin_addr, MPI_Count origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, MPI_Count target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request) {
  return (*MPIABI_Rget_c_ptr)(origin_addr, origin_count, origin_datatype,
                              target_rank, target_disp, target_count,
                              target_datatype, win, request);
}

inline int MPI_Rput(const void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request) {
  return (*MPIABI_Rput_ptr)(origin_addr, origin_count, origin_datatype,
                            target_rank, target_disp, target_count,
                            target_datatype, win, request);
}

inline int MPI_Rput_c(const void *origin_addr, MPI_Count origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, MPI_Count target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request) {
  return (*MPIABI_Rput_c_ptr)(origin_addr, origin_count, origin_datatype,
                              target_rank, target_disp, target_count,
                              target_datatype, win, request);
}

inline int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                            MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return (*MPIABI_Win_allocate_ptr)(size, disp_unit, info, comm, baseptr, win);
}

inline int MPI_Win_allocate_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info,
                              MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return (*MPIABI_Win_allocate_c_ptr)(size, disp_unit, info, comm, baseptr,
                                      win);
}

inline int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info,
                                   MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return (*MPIABI_Win_allocate_shared_ptr)(size, disp_unit, info, comm, baseptr,
                                           win);
}

inline int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit,
                                     MPI_Info info, MPI_Comm comm,
                                     void *baseptr, MPI_Win *win) {
  return (*MPIABI_Win_allocate_shared_c_ptr)(size, disp_unit, info, comm,
                                             baseptr, win);
}

inline int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) {
  return (*MPIABI_Win_attach_ptr)(win, base, size);
}

inline int MPI_Win_complete(MPI_Win win) {
  return (*MPIABI_Win_complete_ptr)(win);
}

inline int MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                          MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return (*MPIABI_Win_create_ptr)(base, size, disp_unit, info, comm, win);
}

inline int MPI_Win_create_c(void *base, MPI_Aint size, MPI_Aint disp_unit,
                            MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return (*MPIABI_Win_create_c_ptr)(base, size, disp_unit, info, comm, win);
}

inline int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return (*MPIABI_Win_create_dynamic_ptr)(info, comm, win);
}

inline int MPI_Win_detach(MPI_Win win, const void *base) {
  return (*MPIABI_Win_detach_ptr)(win, base);
}

inline int MPI_Win_fence(int assert, MPI_Win win) {
  return (*MPIABI_Win_fence_ptr)(assert, win);
}

inline int MPI_Win_flush(int rank, MPI_Win win) {
  return (*MPIABI_Win_flush_ptr)(rank, win);
}

inline int MPI_Win_flush_all(MPI_Win win) {
  return (*MPIABI_Win_flush_all_ptr)(win);
}

inline int MPI_Win_flush_local(int rank, MPI_Win win) {
  return (*MPIABI_Win_flush_local_ptr)(rank, win);
}

inline int MPI_Win_flush_local_all(MPI_Win win) {
  return (*MPIABI_Win_flush_local_all_ptr)(win);
}

inline int MPI_Win_free(MPI_Win *win) { return (*MPIABI_Win_free_ptr)(win); }

inline int MPI_Win_get_group(MPI_Win win, MPI_Group *group) {
  return (*MPIABI_Win_get_group_ptr)(win, group);
}

inline int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) {
  return (*MPIABI_Win_get_info_ptr)(win, info_used);
}

inline int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) {
  return (*MPIABI_Win_lock_ptr)(lock_type, rank, assert, win);
}

inline int MPI_Win_lock_all(int assert, MPI_Win win) {
  return (*MPIABI_Win_lock_all_ptr)(assert, win);
}

inline int MPI_Win_post(MPI_Group group, int assert, MPI_Win win) {
  return (*MPIABI_Win_post_ptr)(group, assert, win);
}

inline int MPI_Win_set_info(MPI_Win win, MPI_Info info) {
  return (*MPIABI_Win_set_info_ptr)(win, info);
}

inline int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                int *disp_unit, void *baseptr) {
  return (*MPIABI_Win_shared_query_ptr)(win, rank, size, disp_unit, baseptr);
}

inline int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size,
                                  MPI_Aint *disp_unit, void *baseptr) {
  return (*MPIABI_Win_shared_query_c_ptr)(win, rank, size, disp_unit, baseptr);
}

inline int MPI_Win_start(MPI_Group group, int assert, MPI_Win win) {
  return (*MPIABI_Win_start_ptr)(group, assert, win);
}

inline int MPI_Win_sync(MPI_Win win) { return (*MPIABI_Win_sync_ptr)(win); }

inline int MPI_Win_test(MPI_Win win, int *flag) {
  return (*MPIABI_Win_test_ptr)(win, flag);
}

inline int MPI_Win_unlock(int rank, MPI_Win win) {
  return (*MPIABI_Win_unlock_ptr)(rank, win);
}

inline int MPI_Win_unlock_all(MPI_Win win) {
  return (*MPIABI_Win_unlock_all_ptr)(win);
}

inline int MPI_Win_wait(MPI_Win win) { return (*MPIABI_Win_wait_ptr)(win); }

// A.3.11 External Interfaces C Bindings

inline int MPI_Grequest_complete(MPI_Request request) {
  return (*MPIABI_Grequest_complete_ptr)(request);
}

inline int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                              MPI_Grequest_free_function *free_fn,
                              MPI_Grequest_cancel_function *cancel_fn,
                              void *extra_state, MPI_Request *request) {
  return (*MPIABI_Grequest_start_ptr)(query_fn, free_fn, cancel_fn, extra_state,
                                      request);
}

inline int MPI_Status_set_cancelled(MPI_Status *status, int flag) {
  return (*MPIABI_Status_set_cancelled_ptr)(status, flag);
}

inline int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                                   int count) {
  return (*MPIABI_Status_set_elements_ptr)(status, datatype, count);
}

inline int MPI_Status_set_elements_c(MPI_Status *status, MPI_Datatype datatype,
                                     MPI_Count count) {
  return (*MPIABI_Status_set_elements_c_ptr)(status, datatype, count);
}

inline int MPI_Status_set_error(MPI_Status *status, int err) {
  return (*MPIABI_Status_set_error_ptr)(status, err);
}

inline int MPI_Status_set_source(MPI_Status *status, int source) {
  return (*MPIABI_Status_set_source_ptr)(status, source);
}

inline int MPI_Status_set_tag(MPI_Status *status, int tag) {
  return (*MPIABI_Status_set_tag_ptr)(status, tag);
}

// A.3.12 I/O C Bindings

inline int MPI_File_close(MPI_File *fh) { return (*MPIABI_File_close_ptr)(fh); }

inline int MPI_File_delete(const char *filename, MPI_Info info) {
  return (*MPIABI_File_delete_ptr)(filename, info);
}

inline int MPI_File_get_amode(MPI_File fh, int *amode) {
  return (*MPIABI_File_get_amode_ptr)(fh, amode);
}

inline int MPI_File_get_atomicity(MPI_File fh, int *flag) {
  return (*MPIABI_File_get_atomicity_ptr)(fh, flag);
}

inline int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                    MPI_Offset *disp) {
  return (*MPIABI_File_get_byte_offset_ptr)(fh, offset, disp);
}

inline int MPI_File_get_group(MPI_File fh, MPI_Group *group) {
  return (*MPIABI_File_get_group_ptr)(fh, group);
}

inline int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) {
  return (*MPIABI_File_get_info_ptr)(fh, info_used);
}

inline int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) {
  return (*MPIABI_File_get_position_ptr)(fh, offset);
}

inline int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) {
  return (*MPIABI_File_get_position_shared_ptr)(fh, offset);
}

inline int MPI_File_get_size(MPI_File fh, MPI_Offset *size) {
  return (*MPIABI_File_get_size_ptr)(fh, size);
}

inline int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                    MPI_Aint *extent) {
  return (*MPIABI_File_get_type_extent_ptr)(fh, datatype, extent);
}

inline int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype,
                                      MPI_Count *extent) {
  return (*MPIABI_File_get_type_extent_c_ptr)(fh, datatype, extent);
}

inline int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype,
                             MPI_Datatype *filetype, char *datarep) {
  return (*MPIABI_File_get_view_ptr)(fh, disp, etype, filetype, datarep);
}

inline int MPI_File_iread(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iread_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_all(MPI_File fh, void *buf, int count,
                              MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iread_all_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iread_all_c_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Request *request) {
  return (*MPIABI_File_iread_at_ptr)(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                 int count, MPI_Datatype datatype,
                                 MPI_Request *request) {
  return (*MPIABI_File_iread_at_all_ptr)(fh, offset, buf, count, datatype,
                                         request);
}

inline int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Request *request) {
  return (*MPIABI_File_iread_at_all_c_ptr)(fh, offset, buf, count, datatype,
                                           request);
}

inline int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Request *request) {
  return (*MPIABI_File_iread_at_c_ptr)(fh, offset, buf, count, datatype,
                                       request);
}

inline int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iread_c_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iread_shared_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count,
                                   MPI_Datatype datatype,
                                   MPI_Request *request) {
  return (*MPIABI_File_iread_shared_c_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite(MPI_File fh, const void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iwrite_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count,
                               MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iwrite_all_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count,
                                 MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iwrite_all_c_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf,
                              int count, MPI_Datatype datatype,
                              MPI_Request *request) {
  return (*MPIABI_File_iwrite_at_ptr)(fh, offset, buf, count, datatype,
                                      request);
}

inline int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset,
                                  const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iwrite_at_all_ptr)(fh, offset, buf, count, datatype,
                                          request);
}

inline int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset,
                                    const void *buf, MPI_Count count,
                                    MPI_Datatype datatype,
                                    MPI_Request *request) {
  return (*MPIABI_File_iwrite_at_all_c_ptr)(fh, offset, buf, count, datatype,
                                            request);
}

inline int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Request *request) {
  return (*MPIABI_File_iwrite_at_c_ptr)(fh, offset, buf, count, datatype,
                                        request);
}

inline int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iwrite_c_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) {
  return (*MPIABI_File_iwrite_shared_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Request *request) {
  return (*MPIABI_File_iwrite_shared_c_ptr)(fh, buf, count, datatype, request);
}

inline int MPI_File_open(MPI_Comm comm, const char *filename, int amode,
                         MPI_Info info, MPI_File *fh) {
  return (*MPIABI_File_open_ptr)(comm, filename, amode, info, fh);
}

inline int MPI_File_preallocate(MPI_File fh, MPI_Offset size) {
  return (*MPIABI_File_preallocate_ptr)(fh, size);
}

inline int MPI_File_read(MPI_File fh, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_all(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_all_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype) {
  return (*MPIABI_File_read_all_begin_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count,
                                     MPI_Datatype datatype) {
  return (*MPIABI_File_read_all_begin_c_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count,
                               MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_all_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  return (*MPIABI_File_read_all_end_ptr)(fh, buf, status);
}

inline int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                            int count, MPI_Datatype datatype,
                            MPI_Status *status) {
  return (*MPIABI_File_read_at_ptr)(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype,
                                MPI_Status *status) {
  return (*MPIABI_File_read_at_all_ptr)(fh, offset, buf, count, datatype,
                                        status);
}

inline int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                                      int count, MPI_Datatype datatype) {
  return (*MPIABI_File_read_at_all_begin_ptr)(fh, offset, buf, count, datatype);
}

inline int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset,
                                        void *buf, MPI_Count count,
                                        MPI_Datatype datatype) {
  return (*MPIABI_File_read_at_all_begin_c_ptr)(fh, offset, buf, count,
                                                datatype);
}

inline int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf,
                                  MPI_Count count, MPI_Datatype datatype,
                                  MPI_Status *status) {
  return (*MPIABI_File_read_at_all_c_ptr)(fh, offset, buf, count, datatype,
                                          status);
}

inline int MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                    MPI_Status *status) {
  return (*MPIABI_File_read_at_all_end_ptr)(fh, buf, status);
}

inline int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf,
                              MPI_Count count, MPI_Datatype datatype,
                              MPI_Status *status) {
  return (*MPIABI_File_read_at_c_ptr)(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_ordered_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype) {
  return (*MPIABI_File_read_ordered_begin_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf,
                                         MPI_Count count,
                                         MPI_Datatype datatype) {
  return (*MPIABI_File_read_ordered_begin_c_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_ordered_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                     MPI_Status *status) {
  return (*MPIABI_File_read_ordered_end_ptr)(fh, buf, status);
}

inline int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_shared_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count,
                                  MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_read_shared_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) {
  return (*MPIABI_File_seek_ptr)(fh, offset, whence);
}

inline int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) {
  return (*MPIABI_File_seek_shared_ptr)(fh, offset, whence);
}

inline int MPI_File_set_atomicity(MPI_File fh, int flag) {
  return (*MPIABI_File_set_atomicity_ptr)(fh, flag);
}

inline int MPI_File_set_info(MPI_File fh, MPI_Info info) {
  return (*MPIABI_File_set_info_ptr)(fh, info);
}

inline int MPI_File_set_size(MPI_File fh, MPI_Offset size) {
  return (*MPIABI_File_set_size_ptr)(fh, size);
}

inline int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                             MPI_Datatype filetype, const char *datarep,
                             MPI_Info info) {
  return (*MPIABI_File_set_view_ptr)(fh, disp, etype, filetype, datarep, info);
}

inline int MPI_File_sync(MPI_File fh) { return (*MPIABI_File_sync_ptr)(fh); }

inline int MPI_File_write(MPI_File fh, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_all(MPI_File fh, const void *buf, int count,
                              MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_all_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count,
                                    MPI_Datatype datatype) {
  return (*MPIABI_File_write_all_begin_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_write_all_begin_c(MPI_File fh, const void *buf,
                                      MPI_Count count, MPI_Datatype datatype) {
  return (*MPIABI_File_write_all_begin_c_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_all_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_all_end(MPI_File fh, const void *buf,
                                  MPI_Status *status) {
  return (*MPIABI_File_write_all_end_ptr)(fh, buf, status);
}

inline int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Status *status) {
  return (*MPIABI_File_write_at_ptr)(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
                                 const void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_at_all_ptr)(fh, offset, buf, count, datatype,
                                         status);
}

inline int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                       const void *buf, int count,
                                       MPI_Datatype datatype) {
  return (*MPIABI_File_write_at_all_begin_ptr)(fh, offset, buf, count,
                                               datatype);
}

inline int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset,
                                         const void *buf, MPI_Count count,
                                         MPI_Datatype datatype) {
  return (*MPIABI_File_write_at_all_begin_c_ptr)(fh, offset, buf, count,
                                                 datatype);
}

inline int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset,
                                   const void *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_at_all_c_ptr)(fh, offset, buf, count, datatype,
                                           status);
}

inline int MPI_File_write_at_all_end(MPI_File fh, const void *buf,
                                     MPI_Status *status) {
  return (*MPIABI_File_write_at_all_end_ptr)(fh, buf, status);
}

inline int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Status *status) {
  return (*MPIABI_File_write_at_c_ptr)(fh, offset, buf, count, datatype,
                                       status);
}

inline int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_ordered(MPI_File fh, const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_ordered_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count,
                                        MPI_Datatype datatype) {
  return (*MPIABI_File_write_ordered_begin_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf,
                                          MPI_Count count,
                                          MPI_Datatype datatype) {
  return (*MPIABI_File_write_ordered_begin_c_ptr)(fh, buf, count, datatype);
}

inline int MPI_File_write_ordered_c(MPI_File fh, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Status *status) {
  return (*MPIABI_File_write_ordered_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_ordered_end(MPI_File fh, const void *buf,
                                      MPI_Status *status) {
  return (*MPIABI_File_write_ordered_end_ptr)(fh, buf, status);
}

inline int MPI_File_write_shared(MPI_File fh, const void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return (*MPIABI_File_write_shared_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_File_write_shared_c(MPI_File fh, const void *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Status *status) {
  return (*MPIABI_File_write_shared_c_ptr)(fh, buf, count, datatype, status);
}

inline int MPI_Register_datarep(
    const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  return (*MPIABI_Register_datarep_ptr)(datarep, read_conversion_fn,
                                        write_conversion_fn,
                                        dtype_file_extent_fn, extra_state);
}

inline int MPI_Register_datarep_c(
    const char *datarep, MPI_Datarep_conversion_function_c *read_conversion_fn,
    MPI_Datarep_conversion_function_c *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  return (*MPIABI_Register_datarep_c_ptr)(datarep, read_conversion_fn,
                                          write_conversion_fn,
                                          dtype_file_extent_fn, extra_state);
}

// A.3.13 Language Bindings C Bindings

inline MPI_Fint MPI_Comm_c2f(MPI_Comm comm) {
  return (*MPIABI_Comm_c2f_ptr)(comm);
}

inline MPI_Comm MPI_Comm_f2c(MPI_Fint comm) {
  return (*MPIABI_Comm_f2c_ptr)(comm);
}

inline MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler errhandler) {
  return (*MPIABI_Errhandler_c2f_ptr)(errhandler);
}

inline MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint errhandler) {
  return (*MPIABI_Errhandler_f2c_ptr)(errhandler);
}

inline MPI_Fint MPI_File_c2f(MPI_File file) {
  return (*MPIABI_File_c2f_ptr)(file);
}

inline MPI_File MPI_File_f2c(MPI_Fint file) {
  return (*MPIABI_File_f2c_ptr)(file);
}

inline MPI_Fint MPI_Group_c2f(MPI_Group group) {
  return (*MPIABI_Group_c2f_ptr)(group);
}

inline MPI_Group MPI_Group_f2c(MPI_Fint group) {
  return (*MPIABI_Group_f2c_ptr)(group);
}

inline MPI_Fint MPI_Info_c2f(MPI_Info info) {
  return (*MPIABI_Info_c2f_ptr)(info);
}

inline MPI_Info MPI_Info_f2c(MPI_Fint info) {
  return (*MPIABI_Info_f2c_ptr)(info);
}

inline MPI_Fint MPI_Message_c2f(MPI_Message message) {
  return (*MPIABI_Message_c2f_ptr)(message);
}

inline MPI_Message MPI_Message_f2c(MPI_Fint message) {
  return (*MPIABI_Message_f2c_ptr)(message);
}

inline MPI_Fint MPI_Op_c2f(MPI_Op op) { return (*MPIABI_Op_c2f_ptr)(op); }

inline MPI_Op MPI_Op_f2c(MPI_Fint op) { return (*MPIABI_Op_f2c_ptr)(op); }

inline MPI_Fint MPI_Request_c2f(MPI_Request request) {
  return (*MPIABI_Request_c2f_ptr)(request);
}

inline MPI_Request MPI_Request_f2c(MPI_Fint request) {
  return (*MPIABI_Request_f2c_ptr)(request);
}

inline MPI_Fint MPI_Session_c2f(MPI_Session session) {
  return (*MPIABI_Session_c2f_ptr)(session);
}

inline MPI_Session MPI_Session_f2c(MPI_Fint session) {
  return (*MPIABI_Session_f2c_ptr)(session);
}

inline int MPI_Status_f082f(const MPI_F08_status *f08_status,
                            MPI_Fint *f_status) {
  return (*MPIABI_Status_f082f_ptr)(f08_status, f_status);
}

inline int MPI_Status_c2f(const MPI_Status *c_status, MPI_Fint *f_status) {
  return (*MPIABI_Status_c2f_ptr)(c_status, f_status);
}

inline int MPI_Status_c2f08(const MPI_Status *c_status,
                            MPI_F08_status *f08_status) {
  return (*MPIABI_Status_c2f08_ptr)(c_status, f08_status);
}

inline int MPI_Status_f082c(const MPI_F08_status *f08_status,
                            MPI_Status *c_status) {
  return (*MPIABI_Status_f082c_ptr)(f08_status, c_status);
}

inline int MPI_Status_f2c(const MPI_Fint *f_status, MPI_Status *c_status) {
  return (*MPIABI_Status_f2c_ptr)(f_status, c_status);
}

inline int MPI_Status_f2f08(const MPI_Fint *f_status,
                            MPI_F08_status *f08_status) {
  return (*MPIABI_Status_f2f08_ptr)(f_status, f08_status);
}

inline MPI_Fint MPI_Type_c2f(MPI_Datatype datatype) {
  return (*MPIABI_Type_c2f_ptr)(datatype);
}

inline int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_f90_complex_ptr)(p, r, newtype);
}

inline int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_f90_integer_ptr)(r, newtype);
}

inline int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype) {
  return (*MPIABI_Type_create_f90_real_ptr)(p, r, newtype);
}

inline MPI_Datatype MPI_Type_f2c(MPI_Fint datatype) {
  return (*MPIABI_Type_f2c_ptr)(datatype);
}

inline int MPI_Type_match_size(int typeclass, int size,
                               MPI_Datatype *datatype) {
  return (*MPIABI_Type_match_size_ptr)(typeclass, size, datatype);
}

inline MPI_Fint MPI_Win_c2f(MPI_Win win) { return (*MPIABI_Win_c2f_ptr)(win); }

inline MPI_Win MPI_Win_f2c(MPI_Fint win) { return (*MPIABI_Win_f2c_ptr)(win); }

// A.3.14 Tools / Profiling Interface C Bindings

inline int MPI_Pcontrol(const int level, ...) {
  // Variadic arguments cannot be forwarded
  // return (*MPIABI_Pcontrol_ptr)(level, ...);
  return MPI_SUCCESS;
}

// A.3.15 Tools / MPI Tool Information Interface C Bindings

inline int MPI_T_category_changed(int *update_number) {
  return (*MPIABI_T_category_changed_ptr)(update_number);
}

inline int MPI_T_category_get_categories(int cat_index, int len,
                                         int indices[]) {
  return (*MPIABI_T_category_get_categories_ptr)(cat_index, len, indices);
}

inline int MPI_T_category_get_cvars(int cat_index, int len, int indices[]) {
  return (*MPIABI_T_category_get_cvars_ptr)(cat_index, len, indices);
}

inline int MPI_T_category_get_events(int cat_index, int len, int indices[]) {
  return (*MPIABI_T_category_get_events_ptr)(cat_index, len, indices);
}

inline int MPI_T_category_get_index(const char *name, int *cat_index) {
  return (*MPIABI_T_category_get_index_ptr)(name, cat_index);
}

inline int MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                                   char *desc, int *desc_len, int *num_cvars,
                                   int *num_pvars, int *num_categories) {
  return (*MPIABI_T_category_get_info_ptr)(cat_index, name, name_len, desc,
                                           desc_len, num_cvars, num_pvars,
                                           num_categories);
}

inline int MPI_T_category_get_num(int *num_cat) {
  return (*MPIABI_T_category_get_num_ptr)(num_cat);
}

inline int MPI_T_category_get_num_events(int cat_index, int *num_events) {
  return (*MPIABI_T_category_get_num_events_ptr)(cat_index, num_events);
}

inline int MPI_T_category_get_pvars(int cat_index, int len, int indices[]) {
  return (*MPIABI_T_category_get_pvars_ptr)(cat_index, len, indices);
}

inline int MPI_T_cvar_get_index(const char *name, int *cvar_index) {
  return (*MPIABI_T_cvar_get_index_ptr)(name, cvar_index);
}

inline int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                               int *verbosity, MPI_Datatype *datatype,
                               MPI_T_enum *enumtype, char *desc, int *desc_len,
                               int *bind, int *scope) {
  return (*MPIABI_T_cvar_get_info_ptr)(cvar_index, name, name_len, verbosity,
                                       datatype, enumtype, desc, desc_len, bind,
                                       scope);
}

inline int MPI_T_cvar_get_num(int *num_cvar) {
  return (*MPIABI_T_cvar_get_num_ptr)(num_cvar);
}

inline int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                   MPI_T_cvar_handle *handle, int *count) {
  return (*MPIABI_T_cvar_handle_alloc_ptr)(cvar_index, obj_handle, handle,
                                           count);
}

inline int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) {
  return (*MPIABI_T_cvar_handle_free_ptr)(handle);
}

inline int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) {
  return (*MPIABI_T_cvar_read_ptr)(handle, buf);
}

inline int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf) {
  return (*MPIABI_T_cvar_write_ptr)(handle, buf);
}

inline int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                               int *name_len) {
  return (*MPIABI_T_enum_get_info_ptr)(enumtype, num, name, name_len);
}

inline int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value,
                               char *name, int *name_len) {
  return (*MPIABI_T_enum_get_item_ptr)(enumtype, index, value, name, name_len);
}

inline int
MPI_T_event_callback_get_info(MPI_T_event_registration event_registration,
                              MPI_T_cb_safety cb_safety, MPI_Info *info_used) {
  return (*MPIABI_T_event_callback_get_info_ptr)(event_registration, cb_safety,
                                                 info_used);
}

inline int
MPI_T_event_callback_set_info(MPI_T_event_registration event_registration,
                              MPI_T_cb_safety cb_safety, MPI_Info info) {
  return (*MPIABI_T_event_callback_set_info_ptr)(event_registration, cb_safety,
                                                 info);
}

inline int MPI_T_event_copy(MPI_T_event_instance event_instance, void *buffer) {
  return (*MPIABI_T_event_copy_ptr)(event_instance, buffer);
}

inline int MPI_T_event_get_index(const char *name, int *event_index) {
  return (*MPIABI_T_event_get_index_ptr)(name, event_index);
}

inline int MPI_T_event_get_info(int event_index, char *name, int *name_len,
                                int *verbosity,
                                MPI_Datatype array_of_datatypes[],
                                MPI_Aint array_of_displacements[],
                                int *num_elements, MPI_T_enum *enumtype,
                                MPI_Info *info, char *desc, int *desc_len,
                                int *bind) {
  return (*MPIABI_T_event_get_info_ptr)(event_index, name, name_len, verbosity,
                                        array_of_datatypes,
                                        array_of_displacements, num_elements,
                                        enumtype, info, desc, desc_len, bind);
}

inline int MPI_T_event_get_num(int *num_events) {
  return (*MPIABI_T_event_get_num_ptr)(num_events);
}

inline int MPI_T_event_get_source(MPI_T_event_instance event_instance,
                                  int *source_index) {
  return (*MPIABI_T_event_get_source_ptr)(event_instance, source_index);
}

inline int MPI_T_event_get_timestamp(MPI_T_event_instance event_instance,
                                     MPI_Count *event_timestamp) {
  return (*MPIABI_T_event_get_timestamp_ptr)(event_instance, event_timestamp);
}

inline int
MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
                         MPI_T_event_registration *event_registration) {
  return (*MPIABI_T_event_handle_alloc_ptr)(event_index, obj_handle, info,
                                            event_registration);
}

inline int
MPI_T_event_handle_free(MPI_T_event_registration event_registration,
                        void *user_data,
                        MPI_T_event_free_cb_function free_cb_function) {
  return (*MPIABI_T_event_handle_free_ptr)(event_registration, user_data,
                                           free_cb_function);
}

inline int
MPI_T_event_handle_get_info(MPI_T_event_registration event_registration,
                            MPI_Info *info_used) {
  return (*MPIABI_T_event_handle_get_info_ptr)(event_registration, info_used);
}

inline int
MPI_T_event_handle_set_info(MPI_T_event_registration event_registration,
                            MPI_Info info) {
  return (*MPIABI_T_event_handle_set_info_ptr)(event_registration, info);
}

inline int MPI_T_event_read(MPI_T_event_instance event_instance,
                            int element_index, void *buffer) {
  return (*MPIABI_T_event_read_ptr)(event_instance, element_index, buffer);
}

inline int MPI_T_event_register_callback(
    MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety,
    MPI_Info info, void *user_data, MPI_T_event_cb_function event_cb_function) {
  return (*MPIABI_T_event_register_callback_ptr)(
      event_registration, cb_safety, info, user_data, event_cb_function);
}

inline int MPI_T_event_set_dropped_handler(
    MPI_T_event_registration event_registration,
    MPI_T_event_dropped_cb_function dropped_cb_function) {
  return (*MPIABI_T_event_set_dropped_handler_ptr)(event_registration,
                                                   dropped_cb_function);
}

inline int MPI_T_finalize(void) { return (*MPIABI_T_finalize_ptr)(); }

inline int MPI_T_init_thread(int required, int *provided) {
  return (*MPIABI_T_init_thread_ptr)(required, provided);
}

inline int MPI_T_pvar_get_index(const char *name, int var_class,
                                int *pvar_index) {
  return (*MPIABI_T_pvar_get_index_ptr)(name, var_class, pvar_index);
}

inline int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                               int *verbosity, int *var_class,
                               MPI_Datatype *datatype, MPI_T_enum *enumtype,
                               char *desc, int *desc_len, int *bind,
                               int *readonly, int *continuous, int *atomic) {
  return (*MPIABI_T_pvar_get_info_ptr)(
      pvar_index, name, name_len, verbosity, var_class, datatype, enumtype,
      desc, desc_len, bind, readonly, continuous, atomic);
}

inline int MPI_T_pvar_get_num(int *num_pvar) {
  return (*MPIABI_T_pvar_get_num_ptr)(num_pvar);
}

inline int MPI_T_pvar_handle_alloc(MPI_T_pvar_session pe_session,
                                   int pvar_index, void *obj_handle,
                                   MPI_T_pvar_handle *handle, int *count) {
  return (*MPIABI_T_pvar_handle_alloc_ptr)(pe_session, pvar_index, obj_handle,
                                           handle, count);
}

inline int MPI_T_pvar_handle_free(MPI_T_pvar_session pe_session,
                                  MPI_T_pvar_handle *handle) {
  return (*MPIABI_T_pvar_handle_free_ptr)(pe_session, handle);
}

inline int MPI_T_pvar_read(MPI_T_pvar_session pe_session,
                           MPI_T_pvar_handle handle, void *buf) {
  return (*MPIABI_T_pvar_read_ptr)(pe_session, handle, buf);
}

inline int MPI_T_pvar_readreset(MPI_T_pvar_session pe_session,
                                MPI_T_pvar_handle handle, void *buf) {
  return (*MPIABI_T_pvar_readreset_ptr)(pe_session, handle, buf);
}

inline int MPI_T_pvar_reset(MPI_T_pvar_session pe_session,
                            MPI_T_pvar_handle handle) {
  return (*MPIABI_T_pvar_reset_ptr)(pe_session, handle);
}

inline int MPI_T_pvar_session_create(MPI_T_pvar_session *pe_session) {
  return (*MPIABI_T_pvar_session_create_ptr)(pe_session);
}

inline int MPI_T_pvar_session_free(MPI_T_pvar_session *pe_session) {
  return (*MPIABI_T_pvar_session_free_ptr)(pe_session);
}

inline int MPI_T_pvar_start(MPI_T_pvar_session pe_session,
                            MPI_T_pvar_handle handle) {
  return (*MPIABI_T_pvar_start_ptr)(pe_session, handle);
}

inline int MPI_T_pvar_stop(MPI_T_pvar_session pe_session,
                           MPI_T_pvar_handle handle) {
  return (*MPIABI_T_pvar_stop_ptr)(pe_session, handle);
}

inline int MPI_T_pvar_write(MPI_T_pvar_session pe_session,
                            MPI_T_pvar_handle handle, const void *buf) {
  return (*MPIABI_T_pvar_write_ptr)(pe_session, handle, buf);
}

inline int MPI_T_source_get_info(int source_index, char *name, int *name_len,
                                 char *desc, int *desc_len,
                                 MPI_T_source_order *ordering,
                                 MPI_Count *ticks_per_second,
                                 MPI_Count *max_ticks, MPI_Info *info) {
  return (*MPIABI_T_source_get_info_ptr)(source_index, name, name_len, desc,
                                         desc_len, ordering, ticks_per_second,
                                         max_ticks, info);
}

inline int MPI_T_source_get_num(int *num_sources) {
  return (*MPIABI_T_source_get_num_ptr)(num_sources);
}

inline int MPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp) {
  return (*MPIABI_T_source_get_timestamp_ptr)(source_index, timestamp);
}

// A.3.16 Deprecated C Bindings

inline int MPI_Attr_delete(MPI_Comm comm, int keyval) {
  return (*MPIABI_Attr_delete_ptr)(comm, keyval);
}

inline int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                        int *flag) {
  return (*MPIABI_Attr_get_ptr)(comm, keyval, attribute_val, flag);
}

inline int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) {
  return (*MPIABI_Attr_put_ptr)(comm, keyval, attribute_val);
}

inline int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype,
                              MPI_Count *count) {
  return (*MPIABI_Get_elements_x_ptr)(status, datatype, count);
}

inline int MPI_Info_get(MPI_Info info, const char *key, int valuelen,
                        char *value, int *flag) {
  return (*MPIABI_Info_get_ptr)(info, key, valuelen, value, flag);
}

inline int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen,
                                 int *flag) {
  return (*MPIABI_Info_get_valuelen_ptr)(info, key, valuelen, flag);
}

inline int MPI_Keyval_create(MPI_Copy_function *copy_fn,
                             MPI_Delete_function *delete_fn, int *keyval,
                             void *extra_state) {
  return (*MPIABI_Keyval_create_ptr)(copy_fn, delete_fn, keyval, extra_state);
}

inline int MPI_Keyval_free(int *keyval) {
  return (*MPIABI_Keyval_free_ptr)(keyval);
}

inline int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype,
                                     MPI_Count count) {
  return (*MPIABI_Status_set_elements_x_ptr)(status, datatype, count);
}

inline int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                 MPI_Count *extent) {
  return (*MPIABI_Type_get_extent_x_ptr)(datatype, lb, extent);
}

inline int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb,
                                      MPI_Count *true_extent) {
  return (*MPIABI_Type_get_true_extent_x_ptr)(datatype, true_lb, true_extent);
}

inline int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) {
  return (*MPIABI_Type_size_x_ptr)(datatype, size);
}

// MPIX

inline int MPIX_Query_cuda_support(void) {
  return (*MPIXABI_Query_cuda_support_ptr)();
}

inline int MPIX_Query_hip_support(void) {
  return (*MPIXABI_Query_hip_support_ptr)();
}

inline int MPIX_Query_rocm_support(void) {
  return (*MPIXABI_Query_rocm_support_ptr)();
}

inline int MPIX_Query_ze_support(void) {
  return (*MPIXABI_Query_ze_support_ptr)();
}

#endif // #ifndef MPI_FUNCTIONS_H
