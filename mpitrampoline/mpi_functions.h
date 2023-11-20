#ifndef MPI_FUNCTIONS_H
#define MPI_FUNCTIONS_H

#include "mpi_constants.h"
#include "mpi_types.h"

#include <mpiabi.h>

// Declare (and inline-define) MPI functions

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

inline int MPI_Bsend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) {
  return MPIABI_Bsend(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Bsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  return MPIABI_Bsend_c(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Bsend_init(const void *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) {
  return MPIABI_Bsend_init(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Bsend_init_c(const void *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Bsend_init_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Buffer_attach(void *buffer, int size) {
  return MPIABI_Buffer_attach(buffer, size);
}

inline int MPI_Buffer_attach_c(void *buffer, MPI_Count size) {
  return MPIABI_Buffer_attach_c(buffer, size);
}

inline int MPI_Buffer_detach(void *buffer_addr, int *size) {
  return MPIABI_Buffer_detach(buffer_addr, size);
}

inline int MPI_Buffer_detach_c(void *buffer_addr, MPI_Count *size) {
  return MPIABI_Buffer_detach_c(buffer_addr, size);
}

inline int MPI_Buffer_flush(void) { return MPIABI_Buffer_flush(); }

inline int MPI_Buffer_iflush(MPI_Request *request) {
  return MPIABI_Buffer_iflush(request);
}

inline int MPI_Cancel(MPI_Request *request) { return MPIABI_Cancel(request); }

inline int MPI_Comm_attach_buffer(MPI_Comm comm, void *buffer, int size) {
  return MPIABI_Comm_attach_buffer(comm, buffer, size);
}

inline int MPI_Comm_attach_buffer_c(MPI_Comm comm, void *buffer,
                                    MPI_Count size) {
  return MPIABI_Comm_attach_buffer_c(comm, buffer, size);
}

inline int MPI_Comm_detach_buffer(MPI_Comm comm, void *buffer_addr, int *size) {
  return MPIABI_Comm_detach_buffer(comm, buffer_addr, size);
}

inline int MPI_Comm_detach_buffer_c(MPI_Comm comm, void *buffer_addr,
                                    MPI_Count *size) {
  return MPIABI_Comm_detach_buffer_c(comm, buffer_addr, size);
}

inline int MPI_Comm_flush_buffer(MPI_Comm comm) {
  return MPIABI_Comm_flush_buffer(comm);
}

inline int MPI_Comm_iflush_buffer(MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Comm_iflush_buffer(comm, request);
}

inline int MPI_Get_count(const MPI_Status *status, MPI_Datatype datatype,
                         int *count) {
  return MPIABI_Get_count(status, datatype, count);
}

inline int MPI_Get_count_c(const MPI_Status *status, MPI_Datatype datatype,
                           MPI_Count *count) {
  return MPIABI_Get_count_c(status, datatype, count);
}

inline int MPI_Ibsend(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ibsend(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Ibsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  return MPIABI_Ibsend_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Improbe(int source, int tag, MPI_Comm comm, int *flag,
                       MPI_Message *message, MPI_Status *status) {
  return MPIABI_Improbe(source, tag, comm, flag, message, status);
}

inline int MPI_Imrecv(void *buf, int count, MPI_Datatype datatype,
                      MPI_Message *message, MPI_Request *request) {
  return MPIABI_Imrecv(buf, count, datatype, message, request);
}

inline int MPI_Imrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                        MPI_Message *message, MPI_Request *request) {
  return MPIABI_Imrecv_c(buf, count, datatype, message, request);
}

inline int MPI_Iprobe(int source, int tag, MPI_Comm comm, int *flag,
                      MPI_Status *status) {
  return MPIABI_Iprobe(source, tag, comm, flag, status);
}

inline int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int source,
                     int tag, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Irecv(buf, count, datatype, source, tag, comm, request);
}

inline int MPI_Irecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                       int source, int tag, MPI_Comm comm,
                       MPI_Request *request) {
  return MPIABI_Irecv_c(buf, count, datatype, source, tag, comm, request);
}

inline int MPI_Irsend(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Irsend(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Irsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  return MPIABI_Irsend_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Isend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Isend(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Isend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Isend_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Isendrecv(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, int dest, int sendtag,
                         void *recvbuf, int recvcount, MPI_Datatype recvtype,
                         int source, int recvtag, MPI_Comm comm,
                         MPI_Request *request) {
  return MPIABI_Isendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf,
                          recvcount, recvtype, source, recvtag, comm, request);
}

inline int MPI_Isendrecv_c(const void *sendbuf, MPI_Count sendcount,
                           MPI_Datatype sendtype, int dest, int sendtag,
                           void *recvbuf, MPI_Count recvcount,
                           MPI_Datatype recvtype, int source, int recvtag,
                           MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Isendrecv_c(sendbuf, sendcount, sendtype, dest, sendtag,
                            recvbuf, recvcount, recvtype, source, recvtag, comm,
                            request);
}

inline int MPI_Isendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                                 int dest, int sendtag, int source, int recvtag,
                                 MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Isendrecv_replace(buf, count, datatype, dest, sendtag, source,
                                  recvtag, comm, request);
}

inline int MPI_Isendrecv_replace_c(void *buf, MPI_Count count,
                                   MPI_Datatype datatype, int dest, int sendtag,
                                   int source, int recvtag, MPI_Comm comm,
                                   MPI_Request *request) {
  return MPIABI_Isendrecv_replace_c(buf, count, datatype, dest, sendtag, source,
                                    recvtag, comm, request);
}

inline int MPI_Issend(const void *buf, int count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Issend(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Issend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                        int dest, int tag, MPI_Comm comm,
                        MPI_Request *request) {
  return MPIABI_Issend_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Mprobe(int source, int tag, MPI_Comm comm, MPI_Message *message,
                      MPI_Status *status) {
  return MPIABI_Mprobe(source, tag, comm, message, status);
}

inline int MPI_Mrecv(void *buf, int count, MPI_Datatype datatype,
                     MPI_Message *message, MPI_Status *status) {
  return MPIABI_Mrecv(buf, count, datatype, message, status);
}

inline int MPI_Mrecv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                       MPI_Message *message, MPI_Status *status) {
  return MPIABI_Mrecv_c(buf, count, datatype, message, status);
}

inline int MPI_Probe(int source, int tag, MPI_Comm comm, MPI_Status *status) {
  return MPIABI_Probe(source, tag, comm, status);
}

inline int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source,
                    int tag, MPI_Comm comm, MPI_Status *status) {
  return MPIABI_Recv(buf, count, datatype, source, tag, comm, status);
}

inline int MPI_Recv_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                      int source, int tag, MPI_Comm comm, MPI_Status *status) {
  return MPIABI_Recv_c(buf, count, datatype, source, tag, comm, status);
}

inline int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
                         int source, int tag, MPI_Comm comm,
                         MPI_Request *request) {
  return MPIABI_Recv_init(buf, count, datatype, source, tag, comm, request);
}

inline int MPI_Recv_init_c(void *buf, MPI_Count count, MPI_Datatype datatype,
                           int source, int tag, MPI_Comm comm,
                           MPI_Request *request) {
  return MPIABI_Recv_init_c(buf, count, datatype, source, tag, comm, request);
}

inline int MPI_Request_free(MPI_Request *request) {
  return MPIABI_Request_free(request);
}

inline int MPI_Request_get_status(MPI_Request request, int *flag,
                                  MPI_Status *status) {
  return MPIABI_Request_get_status(request, flag, status);
}

inline int MPI_Request_get_status_all(int count,
                                      const MPI_Request array_of_requests[],
                                      int *flag,
                                      MPI_Status array_of_statuses[]) {
  return MPIABI_Request_get_status_all(count, array_of_requests, flag,
                                       array_of_statuses);
}

inline int MPI_Request_get_status_any(int count,
                                      const MPI_Request array_of_requests[],
                                      int *index, int *flag,
                                      MPI_Status *status) {
  return MPIABI_Request_get_status_any(count, array_of_requests, index, flag,
                                       status);
}

inline int MPI_Request_get_status_some(int incount,
                                       const MPI_Request array_of_requests[],
                                       int *outcount, int array_of_indices[],
                                       MPI_Status array_of_statuses[]) {
  return MPIABI_Request_get_status_some(incount, array_of_requests, outcount,
                                        array_of_indices, array_of_statuses);
}

inline int MPI_Rsend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) {
  return MPIABI_Rsend(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Rsend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  return MPIABI_Rsend_c(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Rsend_init(const void *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) {
  return MPIABI_Rsend_init(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Rsend_init_c(const void *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Rsend_init_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
                    int tag, MPI_Comm comm) {
  return MPIABI_Send(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Send_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                      int dest, int tag, MPI_Comm comm) {
  return MPIABI_Send_c(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Send_init(const void *buf, int count, MPI_Datatype datatype,
                         int dest, int tag, MPI_Comm comm,
                         MPI_Request *request) {
  return MPIABI_Send_init(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Send_init_c(const void *buf, MPI_Count count,
                           MPI_Datatype datatype, int dest, int tag,
                           MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Send_init_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Sendrecv(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, int dest, int sendtag,
                        void *recvbuf, int recvcount, MPI_Datatype recvtype,
                        int source, int recvtag, MPI_Comm comm,
                        MPI_Status *status) {
  return MPIABI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf,
                         recvcount, recvtype, source, recvtag, comm, status);
}

inline int MPI_Sendrecv_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, int dest, int sendtag,
                          void *recvbuf, MPI_Count recvcount,
                          MPI_Datatype recvtype, int source, int recvtag,
                          MPI_Comm comm, MPI_Status *status) {
  return MPIABI_Sendrecv_c(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf,
                           recvcount, recvtype, source, recvtag, comm, status);
}

inline int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                                int dest, int sendtag, int source, int recvtag,
                                MPI_Comm comm, MPI_Status *status) {
  return MPIABI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source,
                                 recvtag, comm, status);
}

inline int MPI_Sendrecv_replace_c(void *buf, MPI_Count count,
                                  MPI_Datatype datatype, int dest, int sendtag,
                                  int source, int recvtag, MPI_Comm comm,
                                  MPI_Status *status) {
  return MPIABI_Sendrecv_replace_c(buf, count, datatype, dest, sendtag, source,
                                   recvtag, comm, status);
}

inline int MPI_Session_attach_buffer(MPI_Session session, void *buffer,
                                     int size) {
  return MPIABI_Session_attach_buffer(session, buffer, size);
}

inline int MPI_Session_attach_buffer_c(MPI_Session session, void *buffer,
                                       MPI_Count size) {
  return MPIABI_Session_attach_buffer_c(session, buffer, size);
}

inline int MPI_Session_detach_buffer(MPI_Session session, void *buffer_addr,
                                     int *size) {
  return MPIABI_Session_detach_buffer(session, buffer_addr, size);
}

inline int MPI_Session_detach_buffer_c(MPI_Session session, void *buffer_addr,
                                       MPI_Count *size) {
  return MPIABI_Session_detach_buffer_c(session, buffer_addr, size);
}

inline int MPI_Session_flush_buffer(MPI_Session session) {
  return MPIABI_Session_flush_buffer(session);
}

inline int MPI_Session_iflush_buffer(MPI_Session session,
                                     MPI_Request *request) {
  return MPIABI_Session_iflush_buffer(session, request);
}

inline int MPI_Ssend(const void *buf, int count, MPI_Datatype datatype,
                     int dest, int tag, MPI_Comm comm) {
  return MPIABI_Ssend(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Ssend_c(const void *buf, MPI_Count count, MPI_Datatype datatype,
                       int dest, int tag, MPI_Comm comm) {
  return MPIABI_Ssend_c(buf, count, datatype, dest, tag, comm);
}

inline int MPI_Ssend_init(const void *buf, int count, MPI_Datatype datatype,
                          int dest, int tag, MPI_Comm comm,
                          MPI_Request *request) {
  return MPIABI_Ssend_init(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Ssend_init_c(const void *buf, MPI_Count count,
                            MPI_Datatype datatype, int dest, int tag,
                            MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ssend_init_c(buf, count, datatype, dest, tag, comm, request);
}

inline int MPI_Start(MPI_Request *request) { return MPIABI_Start(request); }

inline int MPI_Startall(int count, MPI_Request array_of_requests[]) {
  return MPIABI_Startall(count, array_of_requests);
}

inline int MPI_Status_get_error(MPI_Status *status, int *err) {
  return MPIABI_Status_get_error(status, err);
}

inline int MPI_Status_get_source(MPI_Status *status, int *source) {
  return MPIABI_Status_get_source(status, source);
}

inline int MPI_Status_get_tag(MPI_Status *status, int *tag) {
  return MPIABI_Status_get_tag(status, tag);
}

inline int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status) {
  return MPIABI_Test(request, flag, status);
}

inline int MPI_Test_cancelled(const MPI_Status *status, int *flag) {
  return MPIABI_Test_cancelled(status, flag);
}

inline int MPI_Testall(int count, MPI_Request array_of_requests[], int *flag,
                       MPI_Status array_of_statuses[]) {
  return MPIABI_Testall(count, array_of_requests, flag, array_of_statuses);
}

inline int MPI_Testany(int count, MPI_Request array_of_requests[], int *index,
                       int *flag, MPI_Status *status) {
  return MPIABI_Testany(count, array_of_requests, index, flag, status);
}

inline int MPI_Testsome(int incount, MPI_Request array_of_requests[],
                        int *outcount, int array_of_indices[],
                        MPI_Status array_of_statuses[]) {
  return MPIABI_Testsome(incount, array_of_requests, outcount, array_of_indices,
                         array_of_statuses);
}

inline int MPI_Wait(MPI_Request *request, MPI_Status *status) {
  return MPIABI_Wait(request, status);
}

inline int MPI_Waitall(int count, MPI_Request array_of_requests[],
                       MPI_Status array_of_statuses[]) {
  return MPIABI_Waitall(count, array_of_requests, array_of_statuses);
}

inline int MPI_Waitany(int count, MPI_Request array_of_requests[], int *index,
                       MPI_Status *status) {
  return MPIABI_Waitany(count, array_of_requests, index, status);
}

inline int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
                        int *outcount, int array_of_indices[],
                        MPI_Status array_of_statuses[]) {
  return MPIABI_Waitsome(incount, array_of_requests, outcount, array_of_indices,
                         array_of_statuses);
}

// A.3.2 Partitioned Communication C Bindings

inline int MPI_Parrived(MPI_Request request, int partition, int *flag) {
  return MPIABI_Parrived(request, partition, flag);
}

inline int MPI_Pready(int partition, MPI_Request request) {
  return MPIABI_Pready(partition, request);
}

inline int MPI_Pready_list(int length, const int array_of_partitions[],
                           MPI_Request request) {
  return MPIABI_Pready_list(length, array_of_partitions, request);
}

inline int MPI_Pready_range(int partition_low, int partition_high,
                            MPI_Request request) {
  return MPIABI_Pready_range(partition_low, partition_high, request);
}

inline int MPI_Precv_init(void *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int source, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return MPIABI_Precv_init(buf, partitions, count, datatype, source, tag, comm,
                           info, request);
}

inline int MPI_Psend_init(const void *buf, int partitions, MPI_Count count,
                          MPI_Datatype datatype, int dest, int tag,
                          MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return MPIABI_Psend_init(buf, partitions, count, datatype, dest, tag, comm,
                           info, request);
}

// A.3.3 Datatypes C Bindings

inline MPI_Aint MPI_Aint_add(MPI_Aint base, MPI_Aint disp) {
  return MPIABI_Aint_add(base, disp);
}

inline MPI_Aint MPI_Aint_diff(MPI_Aint addr1, MPI_Aint addr2) {
  return MPIABI_Aint_diff(addr1, addr2);
}

inline int MPI_Get_address(const void *location, MPI_Aint *address) {
  return MPIABI_Get_address(location, address);
}

inline int MPI_Get_elements(const MPI_Status *status, MPI_Datatype datatype,
                            int *count) {
  return MPIABI_Get_elements(status, datatype, count);
}

inline int MPI_Get_elements_c(const MPI_Status *status, MPI_Datatype datatype,
                              MPI_Count *count) {
  return MPIABI_Get_elements_c(status, datatype, count);
}

inline int MPI_Pack(const void *inbuf, int incount, MPI_Datatype datatype,
                    void *outbuf, int outsize, int *position, MPI_Comm comm) {
  return MPIABI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm);
}

inline int MPI_Pack_c(const void *inbuf, MPI_Count incount,
                      MPI_Datatype datatype, void *outbuf, MPI_Count outsize,
                      MPI_Count *position, MPI_Comm comm) {
  return MPIABI_Pack_c(inbuf, incount, datatype, outbuf, outsize, position,
                       comm);
}

inline int MPI_Pack_external(const char datarep[], const void *inbuf,
                             int incount, MPI_Datatype datatype, void *outbuf,
                             MPI_Aint outsize, MPI_Aint *position) {
  return MPIABI_Pack_external(datarep, inbuf, incount, datatype, outbuf,
                              outsize, position);
}

inline int MPI_Pack_external_c(const char datarep[], const void *inbuf,
                               MPI_Count incount, MPI_Datatype datatype,
                               void *outbuf, MPI_Count outsize,
                               MPI_Count *position) {
  return MPIABI_Pack_external_c(datarep, inbuf, incount, datatype, outbuf,
                                outsize, position);
}

inline int MPI_Pack_external_size(const char datarep[], MPI_Count incount,
                                  MPI_Datatype datatype, MPI_Count *size) {
  return MPIABI_Pack_external_size(datarep, incount, datatype, size);
}

inline int MPI_Pack_external_size_c(const char datarep[], MPI_Count incount,
                                    MPI_Datatype datatype, MPI_Count *size) {
  return MPIABI_Pack_external_size_c(datarep, incount, datatype, size);
}

inline int MPI_Pack_size_c(MPI_Count incount, MPI_Datatype datatype,
                           MPI_Comm comm, MPI_Count *size) {
  return MPIABI_Pack_size_c(incount, datatype, comm, size);
}

inline int MPI_Type_commit(MPI_Datatype *datatype) {
  return MPIABI_Type_commit(datatype);
}

inline int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
                               MPI_Datatype *newtype) {
  return MPIABI_Type_contiguous(count, oldtype, newtype);
}

inline int MPI_Type_contiguous_c(MPI_Count count, MPI_Datatype oldtype,
                                 MPI_Datatype *newtype) {
  return MPIABI_Type_contiguous_c(count, oldtype, newtype);
}

inline int MPI_Type_create_darray(int size, int rank, int ndims,
                                  const int array_of_gsizes[],
                                  const int array_of_distribs[],
                                  const int array_of_dargs[],
                                  const int array_of_psizes[], int order,
                                  MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_create_darray(size, rank, ndims, array_of_gsizes,
                                   array_of_distribs, array_of_dargs,
                                   array_of_psizes, order, oldtype, newtype);
}

inline int MPI_Type_create_darray_c(int size, int rank, int ndims,
                                    const MPI_Count array_of_gsizes[],
                                    const int array_of_distribs[],
                                    const int array_of_dargs[],
                                    const int array_of_psizes[], int order,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return MPIABI_Type_create_darray_c(size, rank, ndims, array_of_gsizes,
                                     array_of_distribs, array_of_dargs,
                                     array_of_psizes, order, oldtype, newtype);
}

inline int MPI_Type_create_hindexed(int count,
                                    const int array_of_blocklengths[],
                                    const MPI_Aint array_of_displacements[],
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return MPIABI_Type_create_hindexed(count, array_of_blocklengths,
                                     array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_hindexed_block(int count, int blocklength,
                                          const int array_of_displacements[],
                                          MPI_Datatype oldtype,
                                          MPI_Datatype *newtype) {
  return MPIABI_Type_create_hindexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int
MPI_Type_create_hindexed_block_c(MPI_Count count, MPI_Count blocklength,
                                 const MPI_Count array_of_displacements[],
                                 MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_create_hindexed_block_c(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_hindexed_c(MPI_Count count,
                                      const MPI_Count array_of_blocklengths[],
                                      const MPI_Count array_of_displacements[],
                                      MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  return MPIABI_Type_create_hindexed_c(
      count, array_of_blocklengths, array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_hvector(int count, int blocklength, MPI_Aint stride,
                                   MPI_Datatype oldtype,
                                   MPI_Datatype *newtype) {
  return MPIABI_Type_create_hvector(count, blocklength, stride, oldtype,
                                    newtype);
}

inline int MPI_Type_create_hvector_c(MPI_Count count, MPI_Count blocklength,
                                     MPI_Count stride, MPI_Datatype oldtype,
                                     MPI_Datatype *newtype) {
  return MPIABI_Type_create_hvector_c(count, blocklength, stride, oldtype,
                                      newtype);
}

inline int MPI_Type_create_indexed_block(int count, int blocklength,
                                         const int array_of_displacements[],
                                         MPI_Datatype oldtype,
                                         MPI_Datatype *newtype) {
  return MPIABI_Type_create_indexed_block(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int
MPI_Type_create_indexed_block_c(MPI_Count count, MPI_Count blocklength,
                                const MPI_Count array_of_displacements[],
                                MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_create_indexed_block_c(
      count, blocklength, array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
                                   MPI_Aint extent, MPI_Datatype *newtype) {
  return MPIABI_Type_create_resized(oldtype, lb, extent, newtype);
}

inline int MPI_Type_create_resized_c(MPI_Datatype oldtype, MPI_Count lb,
                                     MPI_Count extent, MPI_Datatype *newtype) {
  return MPIABI_Type_create_resized_c(oldtype, lb, extent, newtype);
}

inline int MPI_Type_create_struct(int count, const int array_of_blocklengths[],
                                  const MPI_Aint array_of_displacements[],
                                  const MPI_Datatype array_of_types[],
                                  MPI_Datatype *newtype) {
  return MPIABI_Type_create_struct(count, array_of_blocklengths,
                                   array_of_displacements, array_of_types,
                                   newtype);
}

inline int MPI_Type_create_struct_c(MPI_Count count,
                                    const MPI_Count array_of_blocklengths[],
                                    const MPI_Count array_of_displacements[],
                                    const MPI_Datatype array_of_types[],
                                    MPI_Datatype *newtype) {
  return MPIABI_Type_create_struct_c(count, array_of_blocklengths,
                                     array_of_displacements, array_of_types,
                                     newtype);
}

inline int MPI_Type_create_subarray(int ndims, const int array_of_sizes[],
                                    const int array_of_subsizes[],
                                    const int array_of_starts[], int order,
                                    MPI_Datatype oldtype,
                                    MPI_Datatype *newtype) {
  return MPIABI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes,
                                     array_of_starts, order, oldtype, newtype);
}

inline int MPI_Type_create_subarray_c(int ndims,
                                      const MPI_Count array_of_sizes[],
                                      const MPI_Count array_of_subsizes[],
                                      const MPI_Count array_of_starts[],
                                      int order, MPI_Datatype oldtype,
                                      MPI_Datatype *newtype) {
  return MPIABI_Type_create_subarray_c(ndims, array_of_sizes, array_of_subsizes,
                                       array_of_starts, order, oldtype,
                                       newtype);
}

inline int MPI_Type_dup(MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_dup(oldtype, newtype);
}

inline int MPI_Type_free(MPI_Datatype *datatype) {
  return MPIABI_Type_free(datatype);
}

inline int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
                                 int max_addresses, int max_datatypes,
                                 int array_of_integers[],
                                 MPI_Aint array_of_addresses[],
                                 MPI_Datatype array_of_datatypes[]) {
  return MPIABI_Type_get_contents(datatype, max_integers, max_addresses,
                                  max_datatypes, array_of_integers,
                                  array_of_addresses, array_of_datatypes);
}

inline int MPI_Type_get_contents_c(
    MPI_Datatype datatype, MPI_Count max_integers, MPI_Count max_addresses,
    MPI_Count max_large_counts, MPI_Count max_datatypes,
    int array_of_integers[], MPI_Aint array_of_addresses[],
    MPI_Count array_of_large_counts[], MPI_Datatype array_of_datatypes[]) {
  return MPIABI_Type_get_contents_c(datatype, max_integers, max_addresses,
                                    max_large_counts, max_datatypes,
                                    array_of_integers, array_of_addresses,
                                    array_of_large_counts, array_of_datatypes);
}

inline int MPI_Type_get_envelope(MPI_Datatype datatype, int *num_integers,
                                 int *num_addresses, int *num_datatypes,
                                 int *combiner) {
  return MPIABI_Type_get_envelope(datatype, num_integers, num_addresses,
                                  num_datatypes, combiner);
}

inline int MPI_Type_get_envelope_c(MPI_Datatype datatype,
                                   MPI_Count *num_integers,
                                   MPI_Count *num_addresses,
                                   MPI_Count *num_large_counts,
                                   MPI_Count *num_datatypes, int *combiner) {
  return MPIABI_Type_get_envelope_c(datatype, num_integers, num_addresses,
                                    num_large_counts, num_datatypes, combiner);
}

inline int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
                               MPI_Aint *extent) {
  return MPIABI_Type_get_extent(datatype, lb, extent);
}

inline int MPI_Type_get_extent_c(MPI_Datatype datatype, MPI_Count *lb,
                                 MPI_Count *extent) {
  return MPIABI_Type_get_extent_c(datatype, lb, extent);
}

inline int MPI_Type_get_true_extent(MPI_Datatype datatype, MPI_Aint *true_lb,
                                    MPI_Aint *true_extent) {
  return MPIABI_Type_get_true_extent(datatype, true_lb, true_extent);
}

inline int MPI_Type_get_true_extent_c(MPI_Datatype datatype, MPI_Count *true_lb,
                                      MPI_Count *true_extent) {
  return MPIABI_Type_get_true_extent_c(datatype, true_lb, true_extent);
}

inline int MPI_Type_indexed(int count, const int array_of_blocklengths[],
                            const int array_of_displacements[],
                            MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_indexed(count, array_of_blocklengths,
                             array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_indexed_c(MPI_Count count,
                              const MPI_Count array_of_blocklengths[],
                              const MPI_Count array_of_displacements[],
                              MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_indexed_c(count, array_of_blocklengths,
                               array_of_displacements, oldtype, newtype);
}

inline int MPI_Type_size(MPI_Datatype datatype, int *size) {
  return MPIABI_Type_size(datatype, size);
}

inline int MPI_Type_size_c(MPI_Datatype datatype, MPI_Count *size) {
  return MPIABI_Type_size_c(datatype, size);
}

inline int MPI_Type_vector(int count, int blocklength, int stride,
                           MPI_Datatype oldtype, MPI_Datatype *newtype) {
  return MPIABI_Type_vector(count, blocklength, stride, oldtype, newtype);
}

inline int MPI_Type_vector_c(MPI_Count count, MPI_Count blocklength,
                             MPI_Count stride, MPI_Datatype oldtype,
                             MPI_Datatype *newtype) {
  return MPIABI_Type_vector_c(count, blocklength, stride, oldtype, newtype);
}

inline int MPI_Unpack(const void *inbuf, int insize, int *position,
                      void *outbuf, int outcount, MPI_Datatype datatype,
                      MPI_Comm comm) {
  return MPIABI_Unpack(inbuf, insize, position, outbuf, outcount, datatype,
                       comm);
}

inline int MPI_Unpack_c(const void *inbuf, MPI_Count insize,
                        MPI_Count *position, void *outbuf, MPI_Count outcount,
                        MPI_Datatype datatype, MPI_Comm comm) {
  return MPIABI_Unpack_c(inbuf, insize, position, outbuf, outcount, datatype,
                         comm);
}

inline int MPI_Unpack_external(const char datarep[], const void *inbuf,
                               MPI_Aint insize, MPI_Aint *position,
                               void *outbuf, int outcount,
                               MPI_Datatype datatype) {
  return MPIABI_Unpack_external(datarep, inbuf, insize, position, outbuf,
                                outcount, datatype);
}

inline int MPI_Unpack_external_c(const char datarep[], const void *inbuf,
                                 MPI_Count insize, MPI_Count *position,
                                 void *outbuf, MPI_Count outcount,
                                 MPI_Datatype datatype) {
  return MPIABI_Unpack_external_c(datarep, inbuf, insize, position, outbuf,
                                  outcount, datatype);
}

// A.3.4 Collective Communication C Bindings

inline int MPI_Allgather(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                          recvtype, comm);
}

inline int MPI_Allgather_c(const void *sendbuf, MPI_Count sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Count recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm) {
  return MPIABI_Allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                            recvtype, comm);
}

inline int MPI_Allgather_init(const void *sendbuf, int sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              int recvcount, MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return MPIABI_Allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, comm, info, request);
}

inline int MPI_Allgather_init_c(const void *sendbuf, MPI_Count sendcount,
                                MPI_Datatype sendtype, void *recvbuf,
                                MPI_Count recvcount, MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Info info,
                                MPI_Request *request) {
  return MPIABI_Allgather_init_c(sendbuf, sendcount, sendtype, recvbuf,
                                 recvcount, recvtype, comm, info, request);
}

inline int MPI_Allgatherv(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const int recvcounts[], const int displs[],
                          MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                           displs, recvtype, comm);
}

inline int MPI_Allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const MPI_Count recvcounts[],
                            const MPI_Aint displs[], MPI_Datatype recvtype,
                            MPI_Comm comm) {
  return MPIABI_Allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                             displs, recvtype, comm);
}

inline int MPI_Allgatherv_init(const void *sendbuf, int sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               const int recvcounts[], const int displs[],
                               MPI_Datatype recvtype, MPI_Comm comm,
                               MPI_Info info, MPI_Request *request) {
  return MPIABI_Allgatherv_init(sendbuf, sendcount, sendtype, recvbuf,
                                recvcounts, displs, recvtype, comm, info,
                                request);
}

inline int MPI_Allgatherv_init_c(const void *sendbuf, MPI_Count sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 const MPI_Count recvcounts[],
                                 const MPI_Aint displs[], MPI_Datatype recvtype,
                                 MPI_Comm comm, MPI_Info info,
                                 MPI_Request *request) {
  return MPIABI_Allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcounts, displs, recvtype, comm, info,
                                  request);
}

inline int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return MPIABI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Allreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return MPIABI_Allreduce_c(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Allreduce_init(const void *sendbuf, void *recvbuf, int count,
                              MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                              MPI_Info info, MPI_Request *request) {
  return MPIABI_Allreduce_init(sendbuf, recvbuf, count, datatype, op, comm,
                               info, request);
}

inline int MPI_Allreduce_init_c(const void *sendbuf, void *recvbuf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Op op, MPI_Comm comm, MPI_Info info,
                                MPI_Request *request) {
  return MPIABI_Allreduce_init_c(sendbuf, recvbuf, count, datatype, op, comm,
                                 info, request);
}

inline int MPI_Alltoall(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                         recvtype, comm);
}

inline int MPI_Alltoall_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          MPI_Count recvcount, MPI_Datatype recvtype,
                          MPI_Comm comm) {
  return MPIABI_Alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                           recvtype, comm);
}

inline int MPI_Alltoall_init(const void *sendbuf, int sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             int recvcount, MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return MPIABI_Alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                              recvtype, comm, info, request);
}

inline int MPI_Alltoall_init_c(const void *sendbuf, MPI_Count sendcount,
                               MPI_Datatype sendtype, void *recvbuf,
                               MPI_Count recvcount, MPI_Datatype recvtype,
                               MPI_Comm comm, MPI_Info info,
                               MPI_Request *request) {
  return MPIABI_Alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf,
                                recvcount, recvtype, comm, info, request);
}

inline int MPI_Alltoallv(const void *sendbuf, const int sendcounts[],
                         const int sdispls[], MPI_Datatype sendtype,
                         void *recvbuf, const int recvcounts[],
                         const int rdispls[], MPI_Datatype recvtype,
                         MPI_Comm comm) {
  return MPIABI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                          recvcounts, rdispls, recvtype, comm);
}

inline int MPI_Alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                           const MPI_Aint sdispls[], MPI_Datatype sendtype,
                           void *recvbuf, const MPI_Count recvcounts[],
                           const MPI_Aint rdispls[], MPI_Datatype recvtype,
                           MPI_Comm comm) {
  return MPIABI_Alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                            recvcounts, rdispls, recvtype, comm);
}

inline int MPI_Alltoallv_init(const void *sendbuf, const int sendcounts[],
                              const int sdispls[], MPI_Datatype sendtype,
                              void *recvbuf, const int recvcounts[],
                              const int rdispls[], MPI_Datatype recvtype,
                              MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return MPIABI_Alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                               recvcounts, rdispls, recvtype, comm, info,
                               request);
}

inline int MPI_Alltoallv_init_c(const void *sendbuf,
                                const MPI_Count sendcounts[],
                                const MPI_Aint sdispls[], MPI_Datatype sendtype,
                                void *recvbuf, const MPI_Count recvcounts[],
                                const MPI_Aint rdispls[], MPI_Datatype recvtype,
                                MPI_Comm comm, MPI_Info info,
                                MPI_Request *request) {
  return MPIABI_Alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype,
                                 recvbuf, recvcounts, rdispls, recvtype, comm,
                                 info, request);
}

inline int MPI_Alltoallw(const void *sendbuf, const int sendcounts[],
                         const int sdispls[], const MPI_Datatype sendtypes[],
                         void *recvbuf, const int recvcounts[],
                         const int rdispls[], const MPI_Datatype recvtypes[],
                         MPI_Comm comm) {
  return MPIABI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                          recvcounts, rdispls, recvtypes, comm);
}

inline int MPI_Alltoallw_c(const void *sendbuf, const MPI_Count sendcounts[],
                           const MPI_Aint sdispls[],
                           const MPI_Datatype sendtypes[], void *recvbuf,
                           const MPI_Count recvcounts[],
                           const MPI_Aint rdispls[],
                           const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return MPIABI_Alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                            recvcounts, rdispls, recvtypes, comm);
}

inline int MPI_Alltoallw_init(const void *sendbuf, const int sendcounts[],
                              const int sdispls[],
                              const MPI_Datatype sendtypes[], void *recvbuf,
                              const int recvcounts[], const int rdispls[],
                              const MPI_Datatype recvtypes[], MPI_Comm comm,
                              MPI_Info info, MPI_Request *request) {
  return MPIABI_Alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                               recvcounts, rdispls, recvtypes, comm, info,
                               request);
}

inline int
MPI_Alltoallw_init_c(const void *sendbuf, const MPI_Count sendcounts[],
                     const MPI_Aint sdispls[], const MPI_Datatype sendtypes[],
                     void *recvbuf, const MPI_Count recvcounts[],
                     const MPI_Aint rdispls[], const MPI_Datatype recvtypes[],
                     MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return MPIABI_Alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes,
                                 recvbuf, recvcounts, rdispls, recvtypes, comm,
                                 info, request);
}

inline int MPI_Barrier(MPI_Comm comm) { return MPIABI_Barrier(comm); }

inline int MPI_Barrier_init(MPI_Comm comm, MPI_Info info,
                            MPI_Request *request) {
  return MPIABI_Barrier_init(comm, info, request);
}

inline int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype, int root,
                     MPI_Comm comm) {
  return MPIABI_Bcast(buffer, count, datatype, root, comm);
}

inline int MPI_Bcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype,
                       int root, MPI_Comm comm) {
  return MPIABI_Bcast_c(buffer, count, datatype, root, comm);
}

inline int MPI_Bcast_init(void *buffer, int count, MPI_Datatype datatype,
                          int root, MPI_Comm comm, MPI_Info info,
                          MPI_Request *request) {
  return MPIABI_Bcast_init(buffer, count, datatype, root, comm, info, request);
}

inline int MPI_Bcast_init_c(void *buffer, MPI_Count count,
                            MPI_Datatype datatype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) {
  return MPIABI_Bcast_init_c(buffer, count, datatype, root, comm, info,
                             request);
}

inline int MPI_Exscan(const void *sendbuf, void *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return MPIABI_Exscan(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Exscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return MPIABI_Exscan_c(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Exscan_init(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                           MPI_Info info, MPI_Request *request) {
  return MPIABI_Exscan_init(sendbuf, recvbuf, count, datatype, op, comm, info,
                            request);
}

inline int MPI_Exscan_init_c(const void *sendbuf, void *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return MPIABI_Exscan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info,
                              request);
}

inline int MPI_Gather(const void *sendbuf, int sendcount, MPI_Datatype sendtype,
                      void *recvbuf, int recvcount, MPI_Datatype recvtype,
                      int root, MPI_Comm comm) {
  return MPIABI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                       recvtype, root, comm);
}

inline int MPI_Gather_c(const void *sendbuf, MPI_Count sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        MPI_Count recvcount, MPI_Datatype recvtype, int root,
                        MPI_Comm comm) {
  return MPIABI_Gather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                         recvtype, root, comm);
}

inline int MPI_Gather_init(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf, int recvcount,
                           MPI_Datatype recvtype, int root, MPI_Comm comm,
                           MPI_Info info, MPI_Request *request) {
  return MPIABI_Gather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                            recvtype, root, comm, info, request);
}

inline int MPI_Gather_init_c(const void *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             MPI_Count recvcount, MPI_Datatype recvtype,
                             int root, MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return MPIABI_Gather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                              recvtype, root, comm, info, request);
}

inline int MPI_Gatherv(const void *sendbuf, int sendcount,
                       MPI_Datatype sendtype, void *recvbuf,
                       const int recvcounts[], const int displs[],
                       MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return MPIABI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                        displs, recvtype, root, comm);
}

inline int MPI_Gatherv_c(const void *sendbuf, MPI_Count sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         const MPI_Count recvcounts[], const MPI_Aint displs[],
                         MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return MPIABI_Gatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                          displs, recvtype, root, comm);
}

inline int MPI_Gatherv_init(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            const int recvcounts[], const int displs[],
                            MPI_Datatype recvtype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) {
  return MPIABI_Gatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                             displs, recvtype, root, comm, info, request);
}

inline int MPI_Gatherv_init_c(const void *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              const MPI_Count recvcounts[],
                              const MPI_Aint displs[], MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return MPIABI_Gatherv_init_c(sendbuf, sendcount, sendtype, recvbuf,
                               recvcounts, displs, recvtype, root, comm, info,
                               request);
}

inline int MPI_Iallgather(const void *sendbuf, int sendcount,
                          MPI_Datatype sendtype, void *recvbuf, int recvcount,
                          MPI_Datatype recvtype, MPI_Comm comm,
                          MPI_Request *request) {
  return MPIABI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                           recvtype, comm, request);
}

inline int MPI_Iallgather_c(const void *sendbuf, MPI_Count sendcount,
                            MPI_Datatype sendtype, void *recvbuf,
                            MPI_Count recvcount, MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Iallgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                             recvtype, comm, request);
}

inline int MPI_Iallgatherv(const void *sendbuf, int sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           const int recvcounts[], const int displs[],
                           MPI_Datatype recvtype, MPI_Comm comm,
                           MPI_Request *request) {
  return MPIABI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                            displs, recvtype, comm, request);
}

inline int MPI_Iallgatherv_c(const void *sendbuf, MPI_Count sendcount,
                             MPI_Datatype sendtype, void *recvbuf,
                             const MPI_Count recvcounts[],
                             const MPI_Aint displs[], MPI_Datatype recvtype,
                             MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Iallgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                              displs, recvtype, comm, request);
}

inline int MPI_Iallreduce(const void *sendbuf, void *recvbuf, int count,
                          MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                          MPI_Request *request) {
  return MPIABI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm,
                           request);
}

inline int MPI_Iallreduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                            MPI_Request *request) {
  return MPIABI_Iallreduce_c(sendbuf, recvbuf, count, datatype, op, comm,
                             request);
}

inline int MPI_Ialltoall(const void *sendbuf, int sendcount,
                         MPI_Datatype sendtype, void *recvbuf, int recvcount,
                         MPI_Datatype recvtype, MPI_Comm comm,
                         MPI_Request *request) {
  return MPIABI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                          recvtype, comm, request);
}

inline int MPI_Ialltoall_c(const void *sendbuf, MPI_Count sendcount,
                           MPI_Datatype sendtype, void *recvbuf,
                           MPI_Count recvcount, MPI_Datatype recvtype,
                           MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ialltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                            recvtype, comm, request);
}

inline int MPI_Ialltoallv(const void *sendbuf, const int sendcounts[],
                          const int sdispls[], MPI_Datatype sendtype,
                          void *recvbuf, const int recvcounts[],
                          const int rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                           recvcounts, rdispls, recvtype, comm, request);
}

inline int MPI_Ialltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                            const MPI_Aint sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const MPI_Count recvcounts[],
                            const MPI_Aint rdispls[], MPI_Datatype recvtype,
                            MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ialltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                             recvcounts, rdispls, recvtype, comm, request);
}

inline int MPI_Ialltoallw(const void *sendbuf, const int sendcounts[],
                          const int sdispls[], const MPI_Datatype sendtypes[],
                          void *recvbuf, const int recvcounts[],
                          const int rdispls[], const MPI_Datatype recvtypes[],
                          MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                           recvcounts, rdispls, recvtypes, comm, request);
}

inline int MPI_Ialltoallw_c(const void *sendbuf, const MPI_Count sendcounts[],
                            const MPI_Aint sdispls[],
                            const MPI_Datatype sendtypes[], void *recvbuf,
                            const MPI_Count recvcounts[],
                            const MPI_Aint rdispls[],
                            const MPI_Datatype recvtypes[], MPI_Comm comm,
                            MPI_Request *request) {
  return MPIABI_Ialltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf,
                             recvcounts, rdispls, recvtypes, comm, request);
}

inline int MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ibarrier(comm, request);
}

inline int MPI_Ibcast(void *buffer, int count, MPI_Datatype datatype, int root,
                      MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ibcast(buffer, count, datatype, root, comm, request);
}

inline int MPI_Ibcast_c(void *buffer, MPI_Count count, MPI_Datatype datatype,
                        int root, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ibcast_c(buffer, count, datatype, root, comm, request);
}

inline int MPI_Iexscan(const void *sendbuf, void *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request) {
  return MPIABI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request);
}

inline int MPI_Iexscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Request *request) {
  return MPIABI_Iexscan_c(sendbuf, recvbuf, count, datatype, op, comm, request);
}

inline int MPI_Igather(const void *sendbuf, int sendcount,
                       MPI_Datatype sendtype, void *recvbuf, int recvcount,
                       MPI_Datatype recvtype, int root, MPI_Comm comm,
                       MPI_Request *request) {
  return MPIABI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                        recvtype, root, comm, request);
}

inline int MPI_Igather_c(const void *sendbuf, MPI_Count sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         MPI_Count recvcount, MPI_Datatype recvtype, int root,
                         MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Igather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                          recvtype, root, comm, request);
}

inline int MPI_Igatherv(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf,
                        const int recvcounts[], const int displs[],
                        MPI_Datatype recvtype, int root, MPI_Comm comm,
                        MPI_Request *request) {
  return MPIABI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                         displs, recvtype, root, comm, request);
}

inline int MPI_Igatherv_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          const MPI_Count recvcounts[], const MPI_Aint displs[],
                          MPI_Datatype recvtype, int root, MPI_Comm comm,
                          MPI_Request *request) {
  return MPIABI_Igatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts,
                           displs, recvtype, root, comm, request);
}

inline int MPI_Ireduce(const void *sendbuf, void *recvbuf, int count,
                       MPI_Datatype datatype, MPI_Op op, int root,
                       MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm,
                        request);
}

inline int MPI_Ireduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                         MPI_Datatype datatype, MPI_Op op, int root,
                         MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ireduce_c(sendbuf, recvbuf, count, datatype, op, root, comm,
                          request);
}

inline int MPI_Ireduce_scatter(const void *sendbuf, void *recvbuf,
                               const int recvcounts[], MPI_Datatype datatype,
                               MPI_Op op, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op,
                                comm, request);
}

inline int MPI_Ireduce_scatter_block(const void *sendbuf, void *recvbuf,
                                     int recvcount, MPI_Datatype datatype,
                                     MPI_Op op, MPI_Comm comm,
                                     MPI_Request *request) {
  return MPIABI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op,
                                      comm, request);
}

inline int MPI_Ireduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                       MPI_Count recvcount,
                                       MPI_Datatype datatype, MPI_Op op,
                                       MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ireduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype,
                                        op, comm, request);
}

inline int MPI_Ireduce_scatter_c(const void *sendbuf, void *recvbuf,
                                 const MPI_Count recvcounts[],
                                 MPI_Datatype datatype, MPI_Op op,
                                 MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ireduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op,
                                  comm, request);
}

inline int MPI_Iscan(const void *sendbuf, void *recvbuf, int count,
                     MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                     MPI_Request *request) {
  return MPIABI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request);
}

inline int MPI_Iscan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                       MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                       MPI_Request *request) {
  return MPIABI_Iscan_c(sendbuf, recvbuf, count, datatype, op, comm, request);
}

inline int MPI_Iscatter(const void *sendbuf, int sendcount,
                        MPI_Datatype sendtype, void *recvbuf, int recvcount,
                        MPI_Datatype recvtype, int root, MPI_Comm comm,
                        MPI_Request *request) {
  return MPIABI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                         recvtype, root, comm, request);
}

inline int MPI_Iscatter_c(const void *sendbuf, MPI_Count sendcount,
                          MPI_Datatype sendtype, void *recvbuf,
                          MPI_Count recvcount, MPI_Datatype recvtype, int root,
                          MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Iscatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                           recvtype, root, comm, request);
}

inline int MPI_Iscatterv(const void *sendbuf, const int sendcounts[],
                         const int displs[], MPI_Datatype sendtype,
                         void *recvbuf, int recvcount, MPI_Datatype recvtype,
                         int root, MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf,
                          recvcount, recvtype, root, comm, request);
}

inline int MPI_Iscatterv_c(const void *sendbuf, const MPI_Count sendcounts[],
                           const MPI_Aint displs[], MPI_Datatype sendtype,
                           void *recvbuf, MPI_Count recvcount,
                           MPI_Datatype recvtype, int root, MPI_Comm comm,
                           MPI_Request *request) {
  return MPIABI_Iscatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf,
                            recvcount, recvtype, root, comm, request);
}

inline int MPI_Op_commutative(MPI_Op op, int *commute) {
  return MPIABI_Op_commutative(op, commute);
}

inline int MPI_Op_create(MPI_User_function *user_fn, int commute, MPI_Op *op) {
  return MPIABI_Op_create(user_fn, commute, op);
}

inline int MPI_Op_create_c(MPI_User_function_c *user_fn, int commute,
                           MPI_Op *op) {
  return MPIABI_Op_create_c(user_fn, commute, op);
}

inline int MPI_Op_free(MPI_Op *op) { return MPIABI_Op_free(op); }

inline int MPI_Reduce(const void *sendbuf, void *recvbuf, int count,
                      MPI_Datatype datatype, MPI_Op op, int root,
                      MPI_Comm comm) {
  return MPIABI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm);
}

inline int MPI_Reduce_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                        MPI_Datatype datatype, MPI_Op op, int root,
                        MPI_Comm comm) {
  return MPIABI_Reduce_c(sendbuf, recvbuf, count, datatype, op, root, comm);
}

inline int MPI_Reduce_init(const void *sendbuf, void *recvbuf, int count,
                           MPI_Datatype datatype, MPI_Op op, int root,
                           MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return MPIABI_Reduce_init(sendbuf, recvbuf, count, datatype, op, root, comm,
                            info, request);
}

inline int MPI_Reduce_init_c(const void *sendbuf, void *recvbuf,
                             MPI_Count count, MPI_Datatype datatype, MPI_Op op,
                             int root, MPI_Comm comm, MPI_Info info,
                             MPI_Request *request) {
  return MPIABI_Reduce_init_c(sendbuf, recvbuf, count, datatype, op, root, comm,
                              info, request);
}

inline int MPI_Reduce_local(const void *inbuf, void *inoutbuf, int count,
                            MPI_Datatype datatype, MPI_Op op) {
  return MPIABI_Reduce_local(inbuf, inoutbuf, count, datatype, op);
}

inline int MPI_Reduce_local_c(const void *inbuf, void *inoutbuf,
                              MPI_Count count, MPI_Datatype datatype,
                              MPI_Op op) {
  return MPIABI_Reduce_local_c(inbuf, inoutbuf, count, datatype, op);
}

inline int MPI_Reduce_scatter(const void *sendbuf, void *recvbuf,
                              const int recvcounts[], MPI_Datatype datatype,
                              MPI_Op op, MPI_Comm comm) {
  return MPIABI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op,
                               comm);
}

inline int MPI_Reduce_scatter_block(const void *sendbuf, void *recvbuf,
                                    int recvcount, MPI_Datatype datatype,
                                    MPI_Op op, MPI_Comm comm) {
  return MPIABI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op,
                                     comm);
}

inline int MPI_Reduce_scatter_block_c(const void *sendbuf, void *recvbuf,
                                      MPI_Count recvcount,
                                      MPI_Datatype datatype, MPI_Op op,
                                      MPI_Comm comm) {
  return MPIABI_Reduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype,
                                       op, comm);
}

inline int MPI_Reduce_scatter_block_init(const void *sendbuf, void *recvbuf,
                                         int recvcount, MPI_Datatype datatype,
                                         MPI_Op op, MPI_Comm comm,
                                         MPI_Info info, MPI_Request *request) {
  return MPIABI_Reduce_scatter_block_init(sendbuf, recvbuf, recvcount, datatype,
                                          op, comm, info, request);
}

inline int MPI_Reduce_scatter_block_init_c(const void *sendbuf, void *recvbuf,
                                           MPI_Count recvcount,
                                           MPI_Datatype datatype, MPI_Op op,
                                           MPI_Comm comm, MPI_Info info,
                                           MPI_Request *request) {
  return MPIABI_Reduce_scatter_block_init_c(sendbuf, recvbuf, recvcount,
                                            datatype, op, comm, info, request);
}

inline int MPI_Reduce_scatter_c(const void *sendbuf, void *recvbuf,
                                const MPI_Count recvcounts[],
                                MPI_Datatype datatype, MPI_Op op,
                                MPI_Comm comm) {
  return MPIABI_Reduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op,
                                 comm);
}

inline int MPI_Reduce_scatter_init(const void *sendbuf, void *recvbuf,
                                   const int recvcounts[],
                                   MPI_Datatype datatype, MPI_Op op,
                                   MPI_Comm comm, MPI_Info info,
                                   MPI_Request *request) {
  return MPIABI_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op,
                                    comm, info, request);
}

inline int MPI_Reduce_scatter_init_c(const void *sendbuf, void *recvbuf,
                                     const MPI_Count recvcounts[],
                                     MPI_Datatype datatype, MPI_Op op,
                                     MPI_Comm comm, MPI_Info info,
                                     MPI_Request *request) {
  return MPIABI_Reduce_scatter_init_c(sendbuf, recvbuf, recvcounts, datatype,
                                      op, comm, info, request);
}

inline int MPI_Scan(const void *sendbuf, void *recvbuf, int count,
                    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return MPIABI_Scan(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Scan_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                      MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {
  return MPIABI_Scan_c(sendbuf, recvbuf, count, datatype, op, comm);
}

inline int MPI_Scan_init(const void *sendbuf, void *recvbuf, int count,
                         MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                         MPI_Info info, MPI_Request *request) {
  return MPIABI_Scan_init(sendbuf, recvbuf, count, datatype, op, comm, info,
                          request);
}

inline int MPI_Scan_init_c(const void *sendbuf, void *recvbuf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Op op, MPI_Comm comm,
                           MPI_Info info, MPI_Request *request) {
  return MPIABI_Scan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info,
                            request);
}

inline int MPI_Scatter(const void *sendbuf, int sendcount,
                       MPI_Datatype sendtype, void *recvbuf, int recvcount,
                       MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return MPIABI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                        recvtype, root, comm);
}

inline int MPI_Scatter_c(const void *sendbuf, MPI_Count sendcount,
                         MPI_Datatype sendtype, void *recvbuf,
                         MPI_Count recvcount, MPI_Datatype recvtype, int root,
                         MPI_Comm comm) {
  return MPIABI_Scatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                          recvtype, root, comm);
}

inline int MPI_Scatter_init(const void *sendbuf, int sendcount,
                            MPI_Datatype sendtype, void *recvbuf, int recvcount,
                            MPI_Datatype recvtype, int root, MPI_Comm comm,
                            MPI_Info info, MPI_Request *request) {
  return MPIABI_Scatter_init(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                             recvtype, root, comm, info, request);
}

inline int MPI_Scatter_init_c(const void *sendbuf, MPI_Count sendcount,
                              MPI_Datatype sendtype, void *recvbuf,
                              MPI_Count recvcount, MPI_Datatype recvtype,
                              int root, MPI_Comm comm, MPI_Info info,
                              MPI_Request *request) {
  return MPIABI_Scatter_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount,
                               recvtype, root, comm, info, request);
}

inline int MPI_Scatterv(const void *sendbuf, const int sendcounts[],
                        const int displs[], MPI_Datatype sendtype,
                        void *recvbuf, int recvcount, MPI_Datatype recvtype,
                        int root, MPI_Comm comm) {
  return MPIABI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf,
                         recvcount, recvtype, root, comm);
}

inline int MPI_Scatterv_c(const void *sendbuf, const MPI_Count sendcounts[],
                          const MPI_Aint displs[], MPI_Datatype sendtype,
                          void *recvbuf, MPI_Count recvcount,
                          MPI_Datatype recvtype, int root, MPI_Comm comm) {
  return MPIABI_Scatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf,
                           recvcount, recvtype, root, comm);
}

inline int MPI_Scatterv_init(const void *sendbuf, const int sendcounts[],
                             const int displs[], MPI_Datatype sendtype,
                             void *recvbuf, int recvcount,
                             MPI_Datatype recvtype, int root, MPI_Comm comm,
                             MPI_Info info, MPI_Request *request) {
  return MPIABI_Scatterv_init(sendbuf, sendcounts, displs, sendtype, recvbuf,
                              recvcount, recvtype, root, comm, info, request);
}

inline int MPI_Scatterv_init_c(const void *sendbuf,
                               const MPI_Count sendcounts[],
                               const MPI_Aint displs[], MPI_Datatype sendtype,
                               void *recvbuf, MPI_Count recvcount,
                               MPI_Datatype recvtype, int root, MPI_Comm comm,
                               MPI_Info info, MPI_Request *request) {
  return MPIABI_Scatterv_init_c(sendbuf, sendcounts, displs, sendtype, recvbuf,
                                recvcount, recvtype, root, comm, info, request);
}

inline int MPI_Type_get_value_index(MPI_Datatype value_type,
                                    MPI_Datatype index_type,
                                    MPI_Datatype *pair_type) {
  return MPIABI_Type_get_value_index(value_type, index_type, pair_type);
}

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

inline int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *result) {
  return MPIABI_Comm_compare(comm1, comm2, result);
}

inline int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) {
  return MPIABI_Comm_create(comm, group, newcomm);
}

inline int MPI_Comm_create_from_group(MPI_Group group, const char *stringtag,
                                      MPI_Info info, MPI_Errhandler errhandler,
                                      MPI_Comm *newcomm) {
  return MPIABI_Comm_create_from_group(group, stringtag, info, errhandler,
                                       newcomm);
}

inline int MPI_Comm_create_group(MPI_Comm comm, MPI_Group group, int tag,
                                 MPI_Comm *newcomm) {
  return MPIABI_Comm_create_group(comm, group, tag, newcomm);
}

inline int
MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
                       MPI_Comm_delete_attr_function *comm_delete_attr_fn,
                       int *comm_keyval, void *extra_state) {
  return MPIABI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn,
                                   comm_keyval, extra_state);
}

inline int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval) {
  return MPIABI_Comm_delete_attr(comm, comm_keyval);
}

inline int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm) {
  return MPIABI_Comm_dup(comm, newcomm);
}

inline int MPI_Comm_dup_with_info(MPI_Comm comm, MPI_Info info,
                                  MPI_Comm *newcomm) {
  return MPIABI_Comm_dup_with_info(comm, info, newcomm);
}

inline int MPI_Comm_free(MPI_Comm *comm) { return MPIABI_Comm_free(comm); }

inline int MPI_Comm_get_name(MPI_Comm comm, char *comm_name, int *resultlen) {
  return MPIABI_Comm_get_name(comm, comm_name, resultlen);
}

inline int MPI_Comm_free_keyval(int *comm_keyval) {
  return MPIABI_Comm_free_keyval(comm_keyval);
}

inline int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
                             void *attribute_val, int *flag) {
  return MPIABI_Comm_get_attr(comm, comm_keyval, attribute_val, flag);
}

inline int MPI_Comm_get_info(MPI_Comm comm, MPI_Info *info_used) {
  return MPIABI_Comm_get_info(comm, info_used);
}

inline int MPI_Comm_group(MPI_Comm comm, MPI_Group *group) {
  return MPIABI_Comm_group(comm, group);
}

inline int MPI_Comm_idup(MPI_Comm comm, MPI_Comm *newcomm,
                         MPI_Request *request) {
  return MPIABI_Comm_idup(comm, newcomm, request);
}

inline int MPI_Comm_idup_with_info(MPI_Comm comm, MPI_Info info,
                                   MPI_Comm *newcomm, MPI_Request *request) {
  return MPIABI_Comm_idup_with_info(comm, info, newcomm, request);
}

inline int MPI_Comm_rank(MPI_Comm comm, int *rank) {
  return MPIABI_Comm_rank(comm, rank);
}

inline int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group) {
  return MPIABI_Comm_remote_group(comm, group);
}

inline int MPI_Comm_remote_size(MPI_Comm comm, int *size) {
  return MPIABI_Comm_remote_size(comm, size);
}

inline int MPI_Comm_set_attr(MPI_Comm comm, int comm_keyval,
                             void *attribute_val) {
  return MPIABI_Comm_set_attr(comm, comm_keyval, attribute_val);
}

inline int MPI_Comm_set_info(MPI_Comm comm, MPI_Info info) {
  return MPIABI_Comm_set_info(comm, info);
}

inline int MPI_Comm_set_name(MPI_Comm comm, const char *comm_name) {
  return MPIABI_Comm_set_name(comm, comm_name);
}

inline int MPI_Comm_split(MPI_Comm comm, int color, int key,
                          MPI_Comm *newcomm) {
  return MPIABI_Comm_split(comm, color, key, newcomm);
}

inline int MPI_Group_free(MPI_Group *group) { return MPIABI_Group_free(group); }

inline int MPI_Comm_split_type(MPI_Comm comm, int split_type, int key,
                               MPI_Info info, MPI_Comm *newcomm) {
  return MPIABI_Comm_split_type(comm, split_type, key, info, newcomm);
}

inline int MPI_Comm_test_inter(MPI_Comm comm, int *flag) {
  return MPIABI_Comm_test_inter(comm, flag);
}

inline int MPI_Group_compare(MPI_Group group1, MPI_Group group2, int *result) {
  return MPIABI_Group_compare(group1, group2, result);
}

inline int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
                                MPI_Group *newgroup) {
  return MPIABI_Group_difference(group1, group2, newgroup);
}

inline int MPI_Group_excl(MPI_Group group, int n, const int ranks[],
                          MPI_Group *newgroup) {
  return MPIABI_Group_excl(group, n, ranks, newgroup);
}

inline int MPI_Group_from_session_pset(MPI_Session session,
                                       const char *pset_name,
                                       MPI_Group *newgroup) {
  return MPIABI_Group_from_session_pset(session, pset_name, newgroup);
}

inline int MPI_Group_incl(MPI_Group group, int n, const int ranks[],
                          MPI_Group *newgroup) {
  return MPIABI_Group_incl(group, n, ranks, newgroup);
}

inline int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
                                  MPI_Group *newgroup) {
  return MPIABI_Group_intersection(group1, group2, newgroup);
}

inline int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
                                MPI_Group *newgroup) {
  return MPIABI_Group_range_excl(group, n, ranges, newgroup);
}

inline int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
                                MPI_Group *newgroup) {
  return MPIABI_Group_range_incl(group, n, ranges, newgroup);
}

inline int MPI_Group_rank(MPI_Group group, int *rank) {
  return MPIABI_Group_rank(group, rank);
}

inline int MPI_Group_size(MPI_Group group, int *size) {
  return MPIABI_Group_size(group, size);
}

inline int MPI_Group_translate_ranks(MPI_Group group1, int n,
                                     const int ranks1[], MPI_Group group2,
                                     int ranks2[]) {
  return MPIABI_Group_translate_ranks(group1, n, ranks1, group2, ranks2);
}

inline int MPI_Group_union(MPI_Group group1, MPI_Group group2,
                           MPI_Group *newgroup) {
  return MPIABI_Group_union(group1, group2, newgroup);
}

inline int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                                MPI_Comm peer_comm, int remote_leader, int tag,
                                MPI_Comm *newintercomm) {
  return MPIABI_Intercomm_create(local_comm, local_leader, peer_comm,
                                 remote_leader, tag, newintercomm);
}

inline int MPI_Intercomm_create_from_groups(
    MPI_Group local_group, int local_leader, MPI_Group remote_group,
    int remote_leader, const char *stringtag, MPI_Info info,
    MPI_Errhandler errhandler, MPI_Comm *newintercomm) {
  return MPIABI_Intercomm_create_from_groups(
      local_group, local_leader, remote_group, remote_leader, stringtag, info,
      errhandler, newintercomm);
}

inline int MPI_Intercomm_merge(MPI_Comm intercomm, int high,
                               MPI_Comm *newintracomm) {
  return MPIABI_Intercomm_merge(intercomm, high, newintracomm);
}

inline int
MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
                       MPI_Type_delete_attr_function *type_delete_attr_fn,
                       int *type_keyval, void *extra_state) {
  return MPIABI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn,
                                   type_keyval, extra_state);
}

inline int MPI_Type_delete_attr(MPI_Datatype datatype, int type_keyval) {
  return MPIABI_Type_delete_attr(datatype, type_keyval);
}

inline int MPI_Type_free_keyval(int *type_keyval) {
  return MPIABI_Type_free_keyval(type_keyval);
}

inline int MPI_Type_get_attr(MPI_Datatype datatype, int type_keyval,
                             void *attribute_val, int *flag) {
  return MPIABI_Type_get_attr(datatype, type_keyval, attribute_val, flag);
}

inline int MPI_Type_get_name(MPI_Datatype datatype, char *type_name,
                             int *resultlen) {
  return MPIABI_Type_get_name(datatype, type_name, resultlen);
}

inline int MPI_Type_set_attr(MPI_Datatype datatype, int type_keyval,
                             void *attribute_val) {
  return MPIABI_Type_set_attr(datatype, type_keyval, attribute_val);
}

inline int MPI_Type_set_name(MPI_Datatype datatype, const char *type_name) {
  return MPIABI_Type_set_name(datatype, type_name);
}

inline int
MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
                      MPI_Win_delete_attr_function *win_delete_attr_fn,
                      int *win_keyval, void *extra_state) {
  return MPIABI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn,
                                  win_keyval, extra_state);
}

inline int MPI_Win_delete_attr(MPI_Win win, int win_keyval) {
  return MPIABI_Win_delete_attr(win, win_keyval);
}

inline int MPI_Win_free_keyval(int *win_keyval) {
  return MPIABI_Win_free_keyval(win_keyval);
}

inline int MPI_Win_get_attr(MPI_Win win, int win_keyval, void *attribute_val,
                            int *flag) {
  return MPIABI_Win_get_attr(win, win_keyval, attribute_val, flag);
}

inline int MPI_Win_get_name(MPI_Win win, char *win_name, int *resultlen) {
  return MPIABI_Win_get_name(win, win_name, resultlen);
}

inline int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val) {
  return MPIABI_Win_set_attr(win, win_keyval, attribute_val);
}

inline int MPI_Win_set_name(MPI_Win win, const char *win_name) {
  return MPIABI_Win_set_name(win, win_name);
}

// A.3.6 Virtual Topologies for MPI Processes C Bindings

inline int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[]) {
  return MPIABI_Cart_coords(comm, rank, maxdims, coords);
}

inline int MPI_Cart_create(MPI_Comm comm_old, int ndims, const int dims[],
                           const int periods[], int reorder,
                           MPI_Comm *comm_cart) {
  return MPIABI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart);
}

inline int MPI_Cart_get(MPI_Comm comm, int maxdims, int dims[], int periods[],
                        int coords[]) {
  return MPIABI_Cart_get(comm, maxdims, dims, periods, coords);
}

inline int MPI_Cart_map(MPI_Comm comm, int ndims, const int dims[],
                        const int periods[], int *newrank) {
  return MPIABI_Cart_map(comm, ndims, dims, periods, newrank);
}

inline int MPI_Cart_rank(MPI_Comm comm, const int coords[], int *rank) {
  return MPIABI_Cart_rank(comm, coords, rank);
}

inline int MPI_Cart_shift(MPI_Comm comm, int direction, int disp,
                          int *rank_source, int *rank_dest) {
  return MPIABI_Cart_shift(comm, direction, disp, rank_source, rank_dest);
}

inline int MPI_Cart_sub(MPI_Comm comm, const int remain_dims[],
                        MPI_Comm *newcomm) {
  return MPIABI_Cart_sub(comm, remain_dims, newcomm);
}

inline int MPI_Cartdim_get(MPI_Comm comm, int *ndims) {
  return MPIABI_Cartdim_get(comm, ndims);
}

inline int MPI_Dims_create(int nnodes, int ndims, int dims[]) {
  return MPIABI_Dims_create(nnodes, ndims, dims);
}

inline int MPI_Dist_graph_create(MPI_Comm comm_old, int n, const int sources[],
                                 const int degrees[], const int destinations[],
                                 const int weights[], MPI_Info info,
                                 int reorder, MPI_Comm *comm_dist_graph) {
  return MPIABI_Dist_graph_create(comm_old, n, sources, degrees, destinations,
                                  weights, info, reorder, comm_dist_graph);
}

inline int
MPI_Dist_graph_create_adjacent(MPI_Comm comm_old, int indegree,
                               const int sources[], const int sourceweights[],
                               int outdegree, const int destinations[],
                               const int destweights[], MPI_Info info,
                               int reorder, MPI_Comm *comm_dist_graph) {
  return MPIABI_Dist_graph_create_adjacent(
      comm_old, indegree, sources, sourceweights, outdegree, destinations,
      destweights, info, reorder, comm_dist_graph);
}

inline int MPI_Dist_graph_neighbors(MPI_Comm comm, int maxindegree,
                                    int sources[], int sourceweights[],
                                    int maxoutdegree, int destinations[],
                                    int destweights[]) {
  return MPIABI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights,
                                     maxoutdegree, destinations, destweights);
}

inline int MPI_Dist_graph_neighbors_count(MPI_Comm comm, int *indegree,
                                          int *outdegree, int *weighted) {
  return MPIABI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted);
}

inline int MPI_Graph_create(MPI_Comm comm_old, int nnodes, const int index[],
                            const int edges[], int reorder,
                            MPI_Comm *comm_graph) {
  return MPIABI_Graph_create(comm_old, nnodes, index, edges, reorder,
                             comm_graph);
}

inline int MPI_Graph_get(MPI_Comm comm, int maxindex, int maxedges, int index[],
                         int edges[]) {
  return MPIABI_Graph_get(comm, maxindex, maxedges, index, edges);
}

inline int MPI_Graph_map(MPI_Comm comm, int nnodes, const int index[],
                         const int edges[], int *newrank) {
  return MPIABI_Graph_map(comm, nnodes, index, edges, newrank);
}

inline int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors,
                               int neighbors[]) {
  return MPIABI_Graph_neighbors(comm, rank, maxneighbors, neighbors);
}

inline int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors) {
  return MPIABI_Graph_neighbors_count(comm, rank, nneighbors);
}

inline int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges) {
  return MPIABI_Graphdims_get(comm, nnodes, nedges);
}

inline int MPI_Ineighbor_allgather(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   int recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm, request);
}

inline int MPI_Ineighbor_allgather_c(const void *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     MPI_Count recvcount, MPI_Datatype recvtype,
                                     MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcount, recvtype, comm, request);
}

inline int MPI_Ineighbor_allgatherv(const void *sendbuf, int sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    const int recvcounts[], const int displs[],
                                    MPI_Datatype recvtype, MPI_Comm comm,
                                    MPI_Request *request) {
  return MPIABI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcounts, displs, recvtype, comm,
                                     request);
}

inline int MPI_Ineighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      const MPI_Count recvcounts[],
                                      const MPI_Aint displs[],
                                      MPI_Datatype recvtype, MPI_Comm comm,
                                      MPI_Request *request) {
  return MPIABI_Ineighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcounts, displs, recvtype, comm,
                                       request);
}

inline int MPI_Ineighbor_alltoall(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  int recvcount, MPI_Datatype recvtype,
                                  MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                   recvcount, recvtype, comm, request);
}

inline int MPI_Ineighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, comm, request);
}

inline int MPI_Ineighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                   const int sdispls[], MPI_Datatype sendtype,
                                   void *recvbuf, const int recvcounts[],
                                   const int rdispls[], MPI_Datatype recvtype,
                                   MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                    recvbuf, recvcounts, rdispls, recvtype,
                                    comm, request);
}

inline int
MPI_Ineighbor_alltoallv_c(const void *sendbuf, const MPI_Count sendcounts[],
                          const MPI_Aint sdispls[], MPI_Datatype sendtype,
                          void *recvbuf, const MPI_Count recvcounts[],
                          const MPI_Aint rdispls[], MPI_Datatype recvtype,
                          MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype,
                                      recvbuf, recvcounts, rdispls, recvtype,
                                      comm, request);
}

inline int MPI_Ineighbor_alltoallw(const void *sendbuf, const int sendcounts[],
                                   const MPI_Aint sdispls[],
                                   const MPI_Datatype sendtypes[],
                                   void *recvbuf, const int recvcounts[],
                                   const MPI_Aint rdispls[],
                                   const MPI_Datatype recvtypes[],
                                   MPI_Comm comm, MPI_Request *request) {
  return MPIABI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                    recvbuf, recvcounts, rdispls, recvtypes,
                                    comm, request);
}

inline int MPI_Ineighbor_alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Request *request) {
  return MPIABI_Ineighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes,
                                      recvbuf, recvcounts, rdispls, recvtypes,
                                      comm, request);
}

inline int MPI_Neighbor_allgather(const void *sendbuf, int sendcount,
                                  MPI_Datatype sendtype, void *recvbuf,
                                  MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf,
                                   recvtype, comm);
}

inline int MPI_Neighbor_allgather_c(const void *sendbuf, MPI_Count sendcount,
                                    MPI_Datatype sendtype, void *recvbuf,
                                    MPI_Count recvcount, MPI_Datatype recvtype,
                                    MPI_Comm comm) {
  return MPIABI_Neighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf,
                                     recvcount, recvtype, comm);
}

inline int MPI_Neighbor_allgather_init(const void *sendbuf, int sendcount,
                                       MPI_Datatype sendtype, void *recvbuf,
                                       int recvcount, MPI_Datatype recvtype,
                                       MPI_Comm comm, MPI_Info info,
                                       MPI_Request *request) {
  return MPIABI_Neighbor_allgather_init(sendbuf, sendcount, sendtype, recvbuf,
                                        recvcount, recvtype, comm, info,
                                        request);
}

inline int MPI_Neighbor_allgather_init_c(const void *sendbuf,
                                         MPI_Count sendcount,
                                         MPI_Datatype sendtype, void *recvbuf,
                                         MPI_Count recvcount,
                                         MPI_Datatype recvtype, MPI_Comm comm,
                                         MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_allgather_init_c(sendbuf, sendcount, sendtype, recvbuf,
                                          recvcount, recvtype, comm, info,
                                          request);
}

inline int MPI_Neighbor_allgatherv(const void *sendbuf, int sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   const int recvcounts[], const int displs[],
                                   MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcounts, displs, recvtype, comm);
}

inline int MPI_Neighbor_allgatherv_c(const void *sendbuf, MPI_Count sendcount,
                                     MPI_Datatype sendtype, void *recvbuf,
                                     const MPI_Count recvcounts[],
                                     const MPI_Aint displs[],
                                     MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Neighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf,
                                      recvcounts, displs, recvtype, comm);
}

inline int MPI_Neighbor_allgatherv_init(const void *sendbuf, int sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        const int recvcounts[],
                                        const int displs[],
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_allgatherv_init(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcounts, displs, recvtype, comm,
                                         info, request);
}

inline int MPI_Neighbor_allgatherv_init_c(
    const void *sendbuf, MPI_Count sendcount, MPI_Datatype sendtype,
    void *recvbuf, const MPI_Count recvcounts[], const MPI_Aint displs[],
    MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_allgatherv_init_c(sendbuf, sendcount, sendtype,
                                           recvbuf, recvcounts, displs,
                                           recvtype, comm, info, request);
}

inline int MPI_Neighbor_alltoall(const void *sendbuf, int sendcount,
                                 MPI_Datatype sendtype, void *recvbuf,
                                 int recvcount, MPI_Datatype recvtype,
                                 MPI_Comm comm) {
  return MPIABI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf,
                                  recvcount, recvtype, comm);
}

inline int MPI_Neighbor_alltoall_c(const void *sendbuf, MPI_Count sendcount,
                                   MPI_Datatype sendtype, void *recvbuf,
                                   MPI_Count recvcount, MPI_Datatype recvtype,
                                   MPI_Comm comm) {
  return MPIABI_Neighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf,
                                    recvcount, recvtype, comm);
}

inline int MPI_Neighbor_alltoall_init(const void *sendbuf, int sendcount,
                                      MPI_Datatype sendtype, void *recvbuf,
                                      int recvcount, MPI_Datatype recvtype,
                                      MPI_Comm comm, MPI_Info info,
                                      MPI_Request *request) {
  return MPIABI_Neighbor_alltoall_init(sendbuf, sendcount, sendtype, recvbuf,
                                       recvcount, recvtype, comm, info,
                                       request);
}

inline int MPI_Neighbor_alltoall_init_c(const void *sendbuf,
                                        MPI_Count sendcount,
                                        MPI_Datatype sendtype, void *recvbuf,
                                        MPI_Count recvcount,
                                        MPI_Datatype recvtype, MPI_Comm comm,
                                        MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf,
                                         recvcount, recvtype, comm, info,
                                         request);
}

inline int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                                  const int sdispls[], MPI_Datatype sendtype,
                                  void *recvbuf, const int recvcounts[],
                                  const int rdispls[], MPI_Datatype recvtype,
                                  MPI_Comm comm) {
  return MPIABI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                   recvbuf, recvcounts, rdispls, recvtype,
                                   comm);
}

inline int MPI_Neighbor_alltoallv_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm) {
  return MPIABI_Neighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype,
                                     recvbuf, recvcounts, rdispls, recvtype,
                                     comm);
}

inline int MPI_Neighbor_alltoallv_init(
    const void *sendbuf, const int sendcounts[], const int sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
    const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm, MPI_Info info,
    MPI_Request *request) {
  return MPIABI_Neighbor_alltoallv_init(sendbuf, sendcounts, sdispls, sendtype,
                                        recvbuf, recvcounts, rdispls, recvtype,
                                        comm, info, request);
}

inline int MPI_Neighbor_alltoallv_init_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    MPI_Datatype sendtype, void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], MPI_Datatype recvtype, MPI_Comm comm,
    MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_alltoallv_init_c(
      sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
      recvtype, comm, info, request);
}

inline int MPI_Neighbor_alltoallw(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return MPIABI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes,
                                   recvbuf, recvcounts, rdispls, recvtypes,
                                   comm);
}

inline int MPI_Neighbor_alltoallw_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm) {
  return MPIABI_Neighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes,
                                     recvbuf, recvcounts, rdispls, recvtypes,
                                     comm);
}

inline int MPI_Neighbor_alltoallw_init(
    const void *sendbuf, const int sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const int recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes,
                                        recvbuf, recvcounts, rdispls, recvtypes,
                                        comm, info, request);
}

inline int MPI_Neighbor_alltoallw_init_c(
    const void *sendbuf, const MPI_Count sendcounts[], const MPI_Aint sdispls[],
    const MPI_Datatype sendtypes[], void *recvbuf, const MPI_Count recvcounts[],
    const MPI_Aint rdispls[], const MPI_Datatype recvtypes[], MPI_Comm comm,
    MPI_Info info, MPI_Request *request) {
  return MPIABI_Neighbor_alltoallw_init_c(
      sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls,
      recvtypes, comm, info, request);
}

inline int MPI_Topo_test(MPI_Comm comm, int *status) {
  return MPIABI_Topo_test(comm, status);
}

// A.3.7 MPI Environmental Management C Bindings

inline int MPI_Add_error_class(int *errorclass) {
  return MPIABI_Add_error_class(errorclass);
}

inline int MPI_Add_error_code(int errorclass, int *errorcode) {
  return MPIABI_Add_error_code(errorclass, errorcode);
}

inline int MPI_Add_error_string(int errorcode, const char *string) {
  return MPIABI_Add_error_string(errorcode, string);
}

inline int MPI_Alloc_mem(MPI_Aint size, MPI_Info info, void *baseptr) {
  return MPIABI_Alloc_mem(size, info, baseptr);
}

inline int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode) {
  return MPIABI_Comm_call_errhandler(comm, errorcode);
}

inline int
MPI_Comm_create_errhandler(MPI_Comm_errhandler_function *comm_errhandler_fn,
                           MPI_Errhandler *errhandler) {
  return MPIABI_Comm_create_errhandler(comm_errhandler_fn, errhandler);
}

inline int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler) {
  return MPIABI_Comm_get_errhandler(comm, errhandler);
}

inline int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler) {
  return MPIABI_Comm_set_errhandler(comm, errhandler);
}

inline int MPI_Errhandler_free(MPI_Errhandler *errhandler) {
  return MPIABI_Errhandler_free(errhandler);
}

inline int MPI_Error_class(int errorcode, int *errorclass) {
  return MPIABI_Error_class(errorcode, errorclass);
}

inline int MPI_Error_string(int errorcode, char *string, int *resultlen) {
  return MPIABI_Error_string(errorcode, string, resultlen);
}

inline int MPI_File_call_errhandler(MPI_File fh, int errorcode) {
  return MPIABI_File_call_errhandler(fh, errorcode);
}

inline int
MPI_File_create_errhandler(MPI_File_errhandler_function *file_errhandler_fn,
                           MPI_Errhandler *errhandler) {
  return MPIABI_File_create_errhandler(file_errhandler_fn, errhandler);
}

inline int MPI_File_get_errhandler(MPI_File file, MPI_Errhandler *errhandler) {
  return MPIABI_File_get_errhandler(file, errhandler);
}

inline int MPI_File_set_errhandler(MPI_File file, MPI_Errhandler errhandler) {
  return MPIABI_File_set_errhandler(file, errhandler);
}

inline int MPI_Free_mem(void *base) { return MPIABI_Free_mem(base); }

inline int MPI_Get_hw_resource_info(MPI_Info *hw_info) {
  return MPIABI_Get_hw_resource_info(hw_info);
}

inline int MPI_Get_library_version(char *version, int *resultlen) {
  return MPIABI_Get_library_version(version, resultlen);
}

inline int MPI_Get_processor_name(char *name, int *resultlen) {
  return MPIABI_Get_processor_name(name, resultlen);
}

inline int MPI_Get_version(int *version, int *subversion) {
  return MPIABI_Get_version(version, subversion);
}

inline int MPI_Remove_error_class(int errorclass) {
  return MPIABI_Remove_error_class(errorclass);
}

inline int MPI_Remove_error_code(int errorcode) {
  return MPIABI_Remove_error_code(errorcode);
}

inline int MPI_Remove_error_string(int errorcode) {
  return MPIABI_Remove_error_string(errorcode);
}

inline int MPI_Session_call_errhandler(MPI_Session session, int errorcode) {
  return MPIABI_Session_call_errhandler(session, errorcode);
}

inline int MPI_Session_create_errhandler(
    MPI_Session_errhandler_function *session_errhandler_fn,
    MPI_Errhandler *errhandler) {
  return MPIABI_Session_create_errhandler(session_errhandler_fn, errhandler);
}

inline int MPI_Session_get_errhandler(MPI_Session session,
                                      MPI_Errhandler *errhandler) {
  return MPIABI_Session_get_errhandler(session, errhandler);
}

inline int MPI_Session_set_errhandler(MPI_Session session,
                                      MPI_Errhandler errhandler) {
  return MPIABI_Session_set_errhandler(session, errhandler);
}

inline int MPI_Win_call_errhandler(MPI_Win win, int errorcode) {
  return MPIABI_Win_call_errhandler(win, errorcode);
}

inline int
MPI_Win_create_errhandler(MPI_Win_errhandler_function *win_errhandler_fn,
                          MPI_Errhandler *errhandler) {
  return MPIABI_Win_create_errhandler(win_errhandler_fn, errhandler);
}

inline int MPI_Win_get_errhandler(MPI_Win win, MPI_Errhandler *errhandler) {
  return MPIABI_Win_get_errhandler(win, errhandler);
}

inline int MPI_Win_set_errhandler(MPI_Win win, MPI_Errhandler errhandler) {
  return MPIABI_Win_set_errhandler(win, errhandler);
}

inline double MPI_Wtick(void) { return MPIABI_Wtick(); }

inline double MPI_Wtime(void) { return MPIABI_Wtime(); }

// A.3.8 The Info Object C Bindings

inline int MPI_Info_create(MPI_Info *info) { return MPIABI_Info_create(info); }

inline int MPI_Info_create_env(int argc, char *argv[], MPI_Info *info) {
  return MPIABI_Info_create_env(argc, argv, info);
}

inline int MPI_Info_delete(MPI_Info info, const char *key) {
  return MPIABI_Info_delete(info, key);
}

inline int MPI_Info_dup(MPI_Info info, MPI_Info *newinfo) {
  return MPIABI_Info_dup(info, newinfo);
}

inline int MPI_Info_free(MPI_Info *info) { return MPIABI_Info_free(info); }

inline int MPI_Info_get_nkeys(MPI_Info info, int *nkeys) {
  return MPIABI_Info_get_nkeys(info, nkeys);
}

inline int MPI_Info_get_nthkey(MPI_Info info, int n, char *key) {
  return MPIABI_Info_get_nthkey(info, n, key);
}

inline int MPI_Info_get_string(MPI_Info info, const char *key, int *buflen,
                               char *value, int *flag) {
  return MPIABI_Info_get_string(info, key, buflen, value, flag);
}

inline int MPI_Info_set(MPI_Info info, const char *key, const char *value) {
  return MPIABI_Info_set(info, key, value);
}

// A.3.9 Process Creation and Management C Bindings

inline int MPI_Abort(MPI_Comm comm, int errorcode) {
  return MPIABI_Abort(comm, errorcode);
}

inline int MPI_Close_port(const char *port_name) {
  return MPIABI_Close_port(port_name);
}

inline int MPI_Comm_accept(const char *port_name, MPI_Info info, int root,
                           MPI_Comm comm, MPI_Comm *newcomm) {
  return MPIABI_Comm_accept(port_name, info, root, comm, newcomm);
}

inline int MPI_Comm_connect(const char *port_name, MPI_Info info, int root,
                            MPI_Comm comm, MPI_Comm *newcomm) {
  return MPIABI_Comm_connect(port_name, info, root, comm, newcomm);
}

inline int MPI_Comm_disconnect(MPI_Comm *comm) {
  return MPIABI_Comm_disconnect(comm);
}

inline int MPI_Comm_get_parent(MPI_Comm *parent) {
  return MPIABI_Comm_get_parent(parent);
}

inline int MPI_Comm_join(int fd, MPI_Comm *intercomm) {
  return MPIABI_Comm_join(fd, intercomm);
}

inline int MPI_Comm_spawn(const char *command, char *argv[], int maxprocs,
                          MPI_Info info, int root, MPI_Comm comm,
                          MPI_Comm *intercomm, int array_of_errcodes[]) {
  return MPIABI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm,
                           array_of_errcodes);
}

inline int MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
                                   char **array_of_argv[],
                                   const int array_of_maxprocs[],
                                   const MPI_Info array_of_info[], int root,
                                   MPI_Comm comm, MPI_Comm *intercomm,
                                   int array_of_errcodes[]) {
  return MPIABI_Comm_spawn_multiple(count, array_of_commands, array_of_argv,
                                    array_of_maxprocs, array_of_info, root,
                                    comm, intercomm, array_of_errcodes);
}

inline int MPI_Finalize(void) { return MPIABI_Finalize(); }

inline int MPI_Finalized(int *flag) { return MPIABI_Finalized(flag); }

inline int MPI_Init(int *argc, char ***argv) { return MPIABI_Init(argc, argv); }

inline int MPI_Init_thread(int *argc, char ***argv, int required,
                           int *provided) {
  return MPIABI_Init_thread(argc, argv, required, provided);
}

inline int MPI_Initialized(int *flag) { return MPIABI_Initialized(flag); }

inline int MPI_Is_thread_main(int *flag) { return MPIABI_Is_thread_main(flag); }

inline int MPI_Lookup_name(const char *service_name, MPI_Info info,
                           char *port_name) {
  return MPIABI_Lookup_name(service_name, info, port_name);
}

inline int MPI_Open_port(MPI_Info info, char *port_name) {
  return MPIABI_Open_port(info, port_name);
}

inline int MPI_Publish_name(const char *service_name, MPI_Info info,
                            const char *port_name) {
  return MPIABI_Publish_name(service_name, info, port_name);
}

inline int MPI_Query_thread(int *provided) {
  return MPIABI_Query_thread(provided);
}

inline int MPI_Session_finalize(MPI_Session *session) {
  return MPIABI_Session_finalize(session);
}

inline int MPI_Session_get_info(MPI_Session session, MPI_Info *info_used) {
  return MPIABI_Session_get_info(session, info_used);
}

inline int MPI_Session_get_nth_pset(MPI_Session session, MPI_Info info, int n,
                                    int *pset_len, char *pset_name) {
  return MPIABI_Session_get_nth_pset(session, info, n, pset_len, pset_name);
}

inline int MPI_Session_get_num_psets(MPI_Session session, MPI_Info info,
                                     int *npset_names) {
  return MPIABI_Session_get_num_psets(session, info, npset_names);
}

inline int MPI_Session_get_pset_info(MPI_Session session, const char *pset_name,
                                     MPI_Info *info) {
  return MPIABI_Session_get_pset_info(session, pset_name, info);
}

inline int MPI_Session_init(MPI_Info info, MPI_Errhandler errhandler,
                            MPI_Session *session) {
  return MPIABI_Session_init(info, errhandler, session);
}

inline int MPI_Unpublish_name(const char *service_name, MPI_Info info,
                              const char *port_name) {
  return MPIABI_Unpublish_name(service_name, info, port_name);
}

// A.3.10 One-Sided Communications C Bindings

inline int MPI_Accumulate(const void *origin_addr, int origin_count,
                          MPI_Datatype origin_datatype, int target_rank,
                          MPI_Aint target_disp, int target_count,
                          MPI_Datatype target_datatype, MPI_Op op,
                          MPI_Win win) {
  return MPIABI_Accumulate(origin_addr, origin_count, origin_datatype,
                           target_rank, target_disp, target_count,
                           target_datatype, op, win);
}

inline int MPI_Accumulate_c(const void *origin_addr, MPI_Count origin_count,
                            MPI_Datatype origin_datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Count target_count,
                            MPI_Datatype target_datatype, MPI_Op op,
                            MPI_Win win) {
  return MPIABI_Accumulate_c(origin_addr, origin_count, origin_datatype,
                             target_rank, target_disp, target_count,
                             target_datatype, op, win);
}

inline int MPI_Compare_and_swap(const void *origin_addr,
                                const void *compare_addr, void *result_addr,
                                MPI_Datatype datatype, int target_rank,
                                MPI_Aint target_disp, MPI_Win win) {
  return MPIABI_Compare_and_swap(origin_addr, compare_addr, result_addr,
                                 datatype, target_rank, target_disp, win);
}

inline int MPI_Fetch_and_op(const void *origin_addr, void *result_addr,
                            MPI_Datatype datatype, int target_rank,
                            MPI_Aint target_disp, MPI_Op op, MPI_Win win) {
  return MPIABI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank,
                             target_disp, op, win);
}

inline int MPI_Get(void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win) {
  return MPIABI_Get(origin_addr, origin_count, origin_datatype, target_rank,
                    target_disp, target_count, target_datatype, win);
}

inline int MPI_Get_accumulate(const void *origin_addr, int origin_count,
                              MPI_Datatype origin_datatype, void *result_addr,
                              int result_count, MPI_Datatype result_datatype,
                              int target_rank, MPI_Aint target_disp,
                              int target_count, MPI_Datatype target_datatype,
                              MPI_Op op, MPI_Win win) {
  return MPIABI_Get_accumulate(origin_addr, origin_count, origin_datatype,
                               result_addr, result_count, result_datatype,
                               target_rank, target_disp, target_count,
                               target_datatype, op, win);
}

inline int MPI_Get_accumulate_c(const void *origin_addr, MPI_Count origin_count,
                                MPI_Datatype origin_datatype, void *result_addr,
                                MPI_Count result_count,
                                MPI_Datatype result_datatype, int target_rank,
                                MPI_Aint target_disp, MPI_Count target_count,
                                MPI_Datatype target_datatype, MPI_Op op,
                                MPI_Win win) {
  return MPIABI_Get_accumulate_c(origin_addr, origin_count, origin_datatype,
                                 result_addr, result_count, result_datatype,
                                 target_rank, target_disp, target_count,
                                 target_datatype, op, win);
}

inline int MPI_Get_c(void *origin_addr, MPI_Count origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Count target_count,
                     MPI_Datatype target_datatype, MPI_Win win) {
  return MPIABI_Get_c(origin_addr, origin_count, origin_datatype, target_rank,
                      target_disp, target_count, target_datatype, win);
}

inline int MPI_Put(const void *origin_addr, int origin_count,
                   MPI_Datatype origin_datatype, int target_rank,
                   MPI_Aint target_disp, int target_count,
                   MPI_Datatype target_datatype, MPI_Win win) {
  return MPIABI_Put(origin_addr, origin_count, origin_datatype, target_rank,
                    target_disp, target_count, target_datatype, win);
}

inline int MPI_Put_c(const void *origin_addr, MPI_Count origin_count,
                     MPI_Datatype origin_datatype, int target_rank,
                     MPI_Aint target_disp, MPI_Count target_count,
                     MPI_Datatype target_datatype, MPI_Win win) {
  return MPIABI_Put_c(origin_addr, origin_count, origin_datatype, target_rank,
                      target_disp, target_count, target_datatype, win);
}

inline int MPI_Raccumulate(const void *origin_addr, int origin_count,
                           MPI_Datatype origin_datatype, int target_rank,
                           MPI_Aint target_disp, int target_count,
                           MPI_Datatype target_datatype, MPI_Op op, MPI_Win win,
                           MPI_Request *request) {
  return MPIABI_Raccumulate(origin_addr, origin_count, origin_datatype,
                            target_rank, target_disp, target_count,
                            target_datatype, op, win, request);
}

inline int MPI_Raccumulate_c(const void *origin_addr, MPI_Count origin_count,
                             MPI_Datatype origin_datatype, int target_rank,
                             MPI_Aint target_disp, MPI_Count target_count,
                             MPI_Datatype target_datatype, MPI_Op op,
                             MPI_Win win, MPI_Request *request) {
  return MPIABI_Raccumulate_c(origin_addr, origin_count, origin_datatype,
                              target_rank, target_disp, target_count,
                              target_datatype, op, win, request);
}

inline int MPI_Rget(void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request) {
  return MPIABI_Rget(origin_addr, origin_count, origin_datatype, target_rank,
                     target_disp, target_count, target_datatype, win, request);
}

inline int MPI_Rget_accumulate(const void *origin_addr, int origin_count,
                               MPI_Datatype origin_datatype, void *result_addr,
                               int result_count, MPI_Datatype result_datatype,
                               int target_rank, MPI_Aint target_disp,
                               int target_count, MPI_Datatype target_datatype,
                               MPI_Op op, MPI_Win win, MPI_Request *request) {
  return MPIABI_Rget_accumulate(origin_addr, origin_count, origin_datatype,
                                result_addr, result_count, result_datatype,
                                target_rank, target_disp, target_count,
                                target_datatype, op, win, request);
}

inline int MPI_Rget_accumulate_c(const void *origin_addr,
                                 MPI_Count origin_count,
                                 MPI_Datatype origin_datatype,
                                 void *result_addr, MPI_Count result_count,
                                 MPI_Datatype result_datatype, int target_rank,
                                 MPI_Aint target_disp, MPI_Count target_count,
                                 MPI_Datatype target_datatype, MPI_Op op,
                                 MPI_Win win, MPI_Request *request) {
  return MPIABI_Rget_accumulate_c(origin_addr, origin_count, origin_datatype,
                                  result_addr, result_count, result_datatype,
                                  target_rank, target_disp, target_count,
                                  target_datatype, op, win, request);
}

inline int MPI_Rget_c(void *origin_addr, MPI_Count origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, MPI_Count target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request) {
  return MPIABI_Rget_c(origin_addr, origin_count, origin_datatype, target_rank,
                       target_disp, target_count, target_datatype, win,
                       request);
}

inline int MPI_Rput(const void *origin_addr, int origin_count,
                    MPI_Datatype origin_datatype, int target_rank,
                    MPI_Aint target_disp, int target_count,
                    MPI_Datatype target_datatype, MPI_Win win,
                    MPI_Request *request) {
  return MPIABI_Rput(origin_addr, origin_count, origin_datatype, target_rank,
                     target_disp, target_count, target_datatype, win, request);
}

inline int MPI_Rput_c(const void *origin_addr, MPI_Count origin_count,
                      MPI_Datatype origin_datatype, int target_rank,
                      MPI_Aint target_disp, MPI_Count target_count,
                      MPI_Datatype target_datatype, MPI_Win win,
                      MPI_Request *request) {
  return MPIABI_Rput_c(origin_addr, origin_count, origin_datatype, target_rank,
                       target_disp, target_count, target_datatype, win,
                       request);
}

inline int MPI_Win_allocate(MPI_Aint size, int disp_unit, MPI_Info info,
                            MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return MPIABI_Win_allocate(size, disp_unit, info, comm, baseptr, win);
}

inline int MPI_Win_allocate_c(MPI_Aint size, MPI_Aint disp_unit, MPI_Info info,
                              MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return MPIABI_Win_allocate_c(size, disp_unit, info, comm, baseptr, win);
}

inline int MPI_Win_allocate_shared(MPI_Aint size, int disp_unit, MPI_Info info,
                                   MPI_Comm comm, void *baseptr, MPI_Win *win) {
  return MPIABI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win);
}

inline int MPI_Win_allocate_shared_c(MPI_Aint size, MPI_Aint disp_unit,
                                     MPI_Info info, MPI_Comm comm,
                                     void *baseptr, MPI_Win *win) {
  return MPIABI_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr,
                                      win);
}

inline int MPI_Win_attach(MPI_Win win, void *base, MPI_Aint size) {
  return MPIABI_Win_attach(win, base, size);
}

inline int MPI_Win_complete(MPI_Win win) { return MPIABI_Win_complete(win); }

inline int MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
                          MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return MPIABI_Win_create(base, size, disp_unit, info, comm, win);
}

inline int MPI_Win_create_c(void *base, MPI_Aint size, MPI_Aint disp_unit,
                            MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return MPIABI_Win_create_c(base, size, disp_unit, info, comm, win);
}

inline int MPI_Win_create_dynamic(MPI_Info info, MPI_Comm comm, MPI_Win *win) {
  return MPIABI_Win_create_dynamic(info, comm, win);
}

inline int MPI_Win_detach(MPI_Win win, const void *base) {
  return MPIABI_Win_detach(win, base);
}

inline int MPI_Win_fence(int assert, MPI_Win win) {
  return MPIABI_Win_fence(assert, win);
}

inline int MPI_Win_flush(int rank, MPI_Win win) {
  return MPIABI_Win_flush(rank, win);
}

inline int MPI_Win_flush_all(MPI_Win win) { return MPIABI_Win_flush_all(win); }

inline int MPI_Win_flush_local(int rank, MPI_Win win) {
  return MPIABI_Win_flush_local(rank, win);
}

inline int MPI_Win_flush_local_all(MPI_Win win) {
  return MPIABI_Win_flush_local_all(win);
}

inline int MPI_Win_free(MPI_Win *win) { return MPIABI_Win_free(win); }

inline int MPI_Win_get_group(MPI_Win win, MPI_Group *group) {
  return MPIABI_Win_get_group(win, group);
}

inline int MPI_Win_get_info(MPI_Win win, MPI_Info *info_used) {
  return MPIABI_Win_get_info(win, info_used);
}

inline int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win) {
  return MPIABI_Win_lock(lock_type, rank, assert, win);
}

inline int MPI_Win_lock_all(int assert, MPI_Win win) {
  return MPIABI_Win_lock_all(assert, win);
}

inline int MPI_Win_post(MPI_Group group, int assert, MPI_Win win) {
  return MPIABI_Win_post(group, assert, win);
}

inline int MPI_Win_set_info(MPI_Win win, MPI_Info info) {
  return MPIABI_Win_set_info(win, info);
}

inline int MPI_Win_shared_query(MPI_Win win, int rank, MPI_Aint *size,
                                int *disp_unit, void *baseptr) {
  return MPIABI_Win_shared_query(win, rank, size, disp_unit, baseptr);
}

inline int MPI_Win_shared_query_c(MPI_Win win, int rank, MPI_Aint *size,
                                  MPI_Aint *disp_unit, void *baseptr) {
  return MPIABI_Win_shared_query_c(win, rank, size, disp_unit, baseptr);
}

inline int MPI_Win_start(MPI_Group group, int assert, MPI_Win win) {
  return MPIABI_Win_start(group, assert, win);
}

inline int MPI_Win_sync(MPI_Win win) { return MPIABI_Win_sync(win); }

inline int MPI_Win_test(MPI_Win win, int *flag) {
  return MPIABI_Win_test(win, flag);
}

inline int MPI_Win_unlock(int rank, MPI_Win win) {
  return MPIABI_Win_unlock(rank, win);
}

inline int MPI_Win_unlock_all(MPI_Win win) {
  return MPIABI_Win_unlock_all(win);
}

inline int MPI_Win_wait(MPI_Win win) { return MPIABI_Win_wait(win); }

// A.3.11 External Interfaces C Bindings

inline int MPI_Grequest_complete(MPI_Request request) {
  return MPIABI_Grequest_complete(request);
}

inline int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
                              MPI_Grequest_free_function *free_fn,
                              MPI_Grequest_cancel_function *cancel_fn,
                              void *extra_state, MPI_Request *request) {
  return MPIABI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state,
                               request);
}

inline int MPI_Status_set_cancelled(MPI_Status *status, int flag) {
  return MPIABI_Status_set_cancelled(status, flag);
}

inline int MPI_Status_set_elements(MPI_Status *status, MPI_Datatype datatype,
                                   int count) {
  return MPIABI_Status_set_elements(status, datatype, count);
}

inline int MPI_Status_set_elements_c(MPI_Status *status, MPI_Datatype datatype,
                                     MPI_Count count) {
  return MPIABI_Status_set_elements_c(status, datatype, count);
}

inline int MPI_Status_set_error(MPI_Status *status, int err) {
  return MPIABI_Status_set_error(status, err);
}

inline int MPI_Status_set_source(MPI_Status *status, int source) {
  return MPIABI_Status_set_source(status, source);
}

inline int MPI_Status_set_tag(MPI_Status *status, int tag) {
  return MPIABI_Status_set_tag(status, tag);
}

// A.3.12 I/O C Bindings

inline int MPI_File_close(MPI_File *fh) { return MPIABI_File_close(fh); }

inline int MPI_File_delete(const char *filename, MPI_Info info) {
  return MPIABI_File_delete(filename, info);
}

inline int MPI_File_get_amode(MPI_File fh, int *amode) {
  return MPIABI_File_get_amode(fh, amode);
}

inline int MPI_File_get_atomicity(MPI_File fh, int *flag) {
  return MPIABI_File_get_atomicity(fh, flag);
}

inline int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
                                    MPI_Offset *disp) {
  return MPIABI_File_get_byte_offset(fh, offset, disp);
}

inline int MPI_File_get_group(MPI_File fh, MPI_Group *group) {
  return MPIABI_File_get_group(fh, group);
}

inline int MPI_File_get_info(MPI_File fh, MPI_Info *info_used) {
  return MPIABI_File_get_info(fh, info_used);
}

inline int MPI_File_get_position(MPI_File fh, MPI_Offset *offset) {
  return MPIABI_File_get_position(fh, offset);
}

inline int MPI_File_get_position_shared(MPI_File fh, MPI_Offset *offset) {
  return MPIABI_File_get_position_shared(fh, offset);
}

inline int MPI_File_get_size(MPI_File fh, MPI_Offset *size) {
  return MPIABI_File_get_size(fh, size);
}

inline int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
                                    MPI_Aint *extent) {
  return MPIABI_File_get_type_extent(fh, datatype, extent);
}

inline int MPI_File_get_type_extent_c(MPI_File fh, MPI_Datatype datatype,
                                      MPI_Count *extent) {
  return MPIABI_File_get_type_extent_c(fh, datatype, extent);
}

inline int MPI_File_get_view(MPI_File fh, MPI_Offset *disp, MPI_Datatype *etype,
                             MPI_Datatype *filetype, char *datarep) {
  return MPIABI_File_get_view(fh, disp, etype, filetype, datarep);
}

inline int MPI_File_iread(MPI_File fh, void *buf, int count,
                          MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iread(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_all(MPI_File fh, void *buf, int count,
                              MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iread_all(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_all_c(MPI_File fh, void *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iread_all_c(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Request *request) {
  return MPIABI_File_iread_at(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iread_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                 int count, MPI_Datatype datatype,
                                 MPI_Request *request) {
  return MPIABI_File_iread_at_all(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iread_at_all_c(MPI_File fh, MPI_Offset offset, void *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Request *request) {
  return MPIABI_File_iread_at_all_c(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iread_at_c(MPI_File fh, MPI_Offset offset, void *buf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Request *request) {
  return MPIABI_File_iread_at_c(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iread_c(MPI_File fh, void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iread_c(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iread_shared(fh, buf, count, datatype, request);
}

inline int MPI_File_iread_shared_c(MPI_File fh, void *buf, MPI_Count count,
                                   MPI_Datatype datatype,
                                   MPI_Request *request) {
  return MPIABI_File_iread_shared_c(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite(MPI_File fh, const void *buf, int count,
                           MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iwrite(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_all(MPI_File fh, const void *buf, int count,
                               MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iwrite_all(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_all_c(MPI_File fh, const void *buf, MPI_Count count,
                                 MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iwrite_all_c(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf,
                              int count, MPI_Datatype datatype,
                              MPI_Request *request) {
  return MPIABI_File_iwrite_at(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iwrite_at_all(MPI_File fh, MPI_Offset offset,
                                  const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iwrite_at_all(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iwrite_at_all_c(MPI_File fh, MPI_Offset offset,
                                    const void *buf, MPI_Count count,
                                    MPI_Datatype datatype,
                                    MPI_Request *request) {
  return MPIABI_File_iwrite_at_all_c(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iwrite_at_c(MPI_File fh, MPI_Offset offset, const void *buf,
                                MPI_Count count, MPI_Datatype datatype,
                                MPI_Request *request) {
  return MPIABI_File_iwrite_at_c(fh, offset, buf, count, datatype, request);
}

inline int MPI_File_iwrite_c(MPI_File fh, const void *buf, MPI_Count count,
                             MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iwrite_c(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_shared(MPI_File fh, const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Request *request) {
  return MPIABI_File_iwrite_shared(fh, buf, count, datatype, request);
}

inline int MPI_File_iwrite_shared_c(MPI_File fh, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Request *request) {
  return MPIABI_File_iwrite_shared_c(fh, buf, count, datatype, request);
}

inline int MPI_File_open(MPI_Comm comm, const char *filename, int amode,
                         MPI_Info info, MPI_File *fh) {
  return MPIABI_File_open(comm, filename, amode, info, fh);
}

inline int MPI_File_preallocate(MPI_File fh, MPI_Offset size) {
  return MPIABI_File_preallocate(fh, size);
}

inline int MPI_File_read(MPI_File fh, void *buf, int count,
                         MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read(fh, buf, count, datatype, status);
}

inline int MPI_File_read_all(MPI_File fh, void *buf, int count,
                             MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_all(fh, buf, count, datatype, status);
}

inline int MPI_File_read_all_begin(MPI_File fh, void *buf, int count,
                                   MPI_Datatype datatype) {
  return MPIABI_File_read_all_begin(fh, buf, count, datatype);
}

inline int MPI_File_read_all_begin_c(MPI_File fh, void *buf, MPI_Count count,
                                     MPI_Datatype datatype) {
  return MPIABI_File_read_all_begin_c(fh, buf, count, datatype);
}

inline int MPI_File_read_all_c(MPI_File fh, void *buf, MPI_Count count,
                               MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_all_c(fh, buf, count, datatype, status);
}

inline int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status) {
  return MPIABI_File_read_all_end(fh, buf, status);
}

inline int MPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf,
                            int count, MPI_Datatype datatype,
                            MPI_Status *status) {
  return MPIABI_File_read_at(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf,
                                int count, MPI_Datatype datatype,
                                MPI_Status *status) {
  return MPIABI_File_read_at_all(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf,
                                      int count, MPI_Datatype datatype) {
  return MPIABI_File_read_at_all_begin(fh, offset, buf, count, datatype);
}

inline int MPI_File_read_at_all_begin_c(MPI_File fh, MPI_Offset offset,
                                        void *buf, MPI_Count count,
                                        MPI_Datatype datatype) {
  return MPIABI_File_read_at_all_begin_c(fh, offset, buf, count, datatype);
}

inline int MPI_File_read_at_all_c(MPI_File fh, MPI_Offset offset, void *buf,
                                  MPI_Count count, MPI_Datatype datatype,
                                  MPI_Status *status) {
  return MPIABI_File_read_at_all_c(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_read_at_all_end(MPI_File fh, void *buf,
                                    MPI_Status *status) {
  return MPIABI_File_read_at_all_end(fh, buf, status);
}

inline int MPI_File_read_at_c(MPI_File fh, MPI_Offset offset, void *buf,
                              MPI_Count count, MPI_Datatype datatype,
                              MPI_Status *status) {
  return MPIABI_File_read_at_c(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_read_c(MPI_File fh, void *buf, MPI_Count count,
                           MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_c(fh, buf, count, datatype, status);
}

inline int MPI_File_read_ordered(MPI_File fh, void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_ordered(fh, buf, count, datatype, status);
}

inline int MPI_File_read_ordered_begin(MPI_File fh, void *buf, int count,
                                       MPI_Datatype datatype) {
  return MPIABI_File_read_ordered_begin(fh, buf, count, datatype);
}

inline int MPI_File_read_ordered_begin_c(MPI_File fh, void *buf,
                                         MPI_Count count,
                                         MPI_Datatype datatype) {
  return MPIABI_File_read_ordered_begin_c(fh, buf, count, datatype);
}

inline int MPI_File_read_ordered_c(MPI_File fh, void *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_ordered_c(fh, buf, count, datatype, status);
}

inline int MPI_File_read_ordered_end(MPI_File fh, void *buf,
                                     MPI_Status *status) {
  return MPIABI_File_read_ordered_end(fh, buf, status);
}

inline int MPI_File_read_shared(MPI_File fh, void *buf, int count,
                                MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_shared(fh, buf, count, datatype, status);
}

inline int MPI_File_read_shared_c(MPI_File fh, void *buf, MPI_Count count,
                                  MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_read_shared_c(fh, buf, count, datatype, status);
}

inline int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence) {
  return MPIABI_File_seek(fh, offset, whence);
}

inline int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence) {
  return MPIABI_File_seek_shared(fh, offset, whence);
}

inline int MPI_File_set_atomicity(MPI_File fh, int flag) {
  return MPIABI_File_set_atomicity(fh, flag);
}

inline int MPI_File_set_info(MPI_File fh, MPI_Info info) {
  return MPIABI_File_set_info(fh, info);
}

inline int MPI_File_set_size(MPI_File fh, MPI_Offset size) {
  return MPIABI_File_set_size(fh, size);
}

inline int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
                             MPI_Datatype filetype, const char *datarep,
                             MPI_Info info) {
  return MPIABI_File_set_view(fh, disp, etype, filetype, datarep, info);
}

inline int MPI_File_sync(MPI_File fh) { return MPIABI_File_sync(fh); }

inline int MPI_File_write(MPI_File fh, const void *buf, int count,
                          MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write(fh, buf, count, datatype, status);
}

inline int MPI_File_write_all(MPI_File fh, const void *buf, int count,
                              MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_all(fh, buf, count, datatype, status);
}

inline int MPI_File_write_all_begin(MPI_File fh, const void *buf, int count,
                                    MPI_Datatype datatype) {
  return MPIABI_File_write_all_begin(fh, buf, count, datatype);
}

inline int MPI_File_write_all_begin_c(MPI_File fh, const void *buf,
                                      MPI_Count count, MPI_Datatype datatype) {
  return MPIABI_File_write_all_begin_c(fh, buf, count, datatype);
}

inline int MPI_File_write_all_c(MPI_File fh, const void *buf, MPI_Count count,
                                MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_all_c(fh, buf, count, datatype, status);
}

inline int MPI_File_write_all_end(MPI_File fh, const void *buf,
                                  MPI_Status *status) {
  return MPIABI_File_write_all_end(fh, buf, status);
}

inline int MPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf,
                             int count, MPI_Datatype datatype,
                             MPI_Status *status) {
  return MPIABI_File_write_at(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
                                 const void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_at_all(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
                                       const void *buf, int count,
                                       MPI_Datatype datatype) {
  return MPIABI_File_write_at_all_begin(fh, offset, buf, count, datatype);
}

inline int MPI_File_write_at_all_begin_c(MPI_File fh, MPI_Offset offset,
                                         const void *buf, MPI_Count count,
                                         MPI_Datatype datatype) {
  return MPIABI_File_write_at_all_begin_c(fh, offset, buf, count, datatype);
}

inline int MPI_File_write_at_all_c(MPI_File fh, MPI_Offset offset,
                                   const void *buf, MPI_Count count,
                                   MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_at_all_c(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_write_at_all_end(MPI_File fh, const void *buf,
                                     MPI_Status *status) {
  return MPIABI_File_write_at_all_end(fh, buf, status);
}

inline int MPI_File_write_at_c(MPI_File fh, MPI_Offset offset, const void *buf,
                               MPI_Count count, MPI_Datatype datatype,
                               MPI_Status *status) {
  return MPIABI_File_write_at_c(fh, offset, buf, count, datatype, status);
}

inline int MPI_File_write_c(MPI_File fh, const void *buf, MPI_Count count,
                            MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_c(fh, buf, count, datatype, status);
}

inline int MPI_File_write_ordered(MPI_File fh, const void *buf, int count,
                                  MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_ordered(fh, buf, count, datatype, status);
}

inline int MPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count,
                                        MPI_Datatype datatype) {
  return MPIABI_File_write_ordered_begin(fh, buf, count, datatype);
}

inline int MPI_File_write_ordered_begin_c(MPI_File fh, const void *buf,
                                          MPI_Count count,
                                          MPI_Datatype datatype) {
  return MPIABI_File_write_ordered_begin_c(fh, buf, count, datatype);
}

inline int MPI_File_write_ordered_c(MPI_File fh, const void *buf,
                                    MPI_Count count, MPI_Datatype datatype,
                                    MPI_Status *status) {
  return MPIABI_File_write_ordered_c(fh, buf, count, datatype, status);
}

inline int MPI_File_write_ordered_end(MPI_File fh, const void *buf,
                                      MPI_Status *status) {
  return MPIABI_File_write_ordered_end(fh, buf, status);
}

inline int MPI_File_write_shared(MPI_File fh, const void *buf, int count,
                                 MPI_Datatype datatype, MPI_Status *status) {
  return MPIABI_File_write_shared(fh, buf, count, datatype, status);
}

inline int MPI_File_write_shared_c(MPI_File fh, const void *buf,
                                   MPI_Count count, MPI_Datatype datatype,
                                   MPI_Status *status) {
  return MPIABI_File_write_shared_c(fh, buf, count, datatype, status);
}

inline int MPI_Register_datarep(
    const char *datarep, MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  return MPIABI_Register_datarep(datarep, read_conversion_fn,
                                 write_conversion_fn, dtype_file_extent_fn,
                                 extra_state);
}

inline int MPI_Register_datarep_c(
    const char *datarep, MPI_Datarep_conversion_function_c *read_conversion_fn,
    MPI_Datarep_conversion_function_c *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn, void *extra_state) {
  return MPIABI_Register_datarep_c(datarep, read_conversion_fn,
                                   write_conversion_fn, dtype_file_extent_fn,
                                   extra_state);
}

// A.3.13 Language Bindings C Bindings

inline MPI_Fint MPI_Comm_c2f(MPI_Comm comm) { return MPIABI_Comm_c2f(comm); }

inline MPI_Comm MPI_Comm_f2c(MPI_Fint comm) { return MPIABI_Comm_f2c(comm); }

inline MPI_Fint MPI_Errhandler_c2f(MPI_Errhandler errhandler) {
  return MPIABI_Errhandler_c2f(errhandler);
}

inline MPI_Errhandler MPI_Errhandler_f2c(MPI_Fint errhandler) {
  return MPIABI_Errhandler_f2c(errhandler);
}

inline MPI_Fint MPI_File_c2f(MPI_File file) { return MPIABI_File_c2f(file); }

inline MPI_File MPI_File_f2c(MPI_Fint file) { return MPIABI_File_f2c(file); }

inline MPI_Fint MPI_Group_c2f(MPI_Group group) {
  return MPIABI_Group_c2f(group);
}

inline MPI_Group MPI_Group_f2c(MPI_Fint group) {
  return MPIABI_Group_f2c(group);
}

inline MPI_Fint MPI_Info_c2f(MPI_Info info) { return MPIABI_Info_c2f(info); }

inline MPI_Info MPI_Info_f2c(MPI_Fint info) { return MPIABI_Info_f2c(info); }

inline MPI_Fint MPI_Message_c2f(MPI_Message message) {
  return MPIABI_Message_c2f(message);
}

inline MPI_Message MPI_Message_f2c(MPI_Fint message) {
  return MPIABI_Message_f2c(message);
}

inline MPI_Fint MPI_Op_c2f(MPI_Op op) { return MPIABI_Op_c2f(op); }

inline MPI_Op MPI_Op_f2c(MPI_Fint op) { return MPIABI_Op_f2c(op); }

inline MPI_Fint MPI_Request_c2f(MPI_Request request) {
  return MPIABI_Request_c2f(request);
}

inline MPI_Request MPI_Request_f2c(MPI_Fint request) {
  return MPIABI_Request_f2c(request);
}

inline MPI_Fint MPI_Session_c2f(MPI_Session session) {
  return MPIABI_Session_c2f(session);
}

inline MPI_Session MPI_Session_f2c(MPI_Fint session) {
  return MPIABI_Session_f2c(session);
}

inline int MPI_Status_f082f(const MPI_F08_status *f08_status,
                            MPI_Fint *f_status) {
  return MPIABI_Status_f082f(f08_status, f_status);
}

inline int MPI_Status_c2f(const MPI_Status *c_status, MPI_Fint *f_status) {
  return MPIABI_Status_c2f(c_status, f_status);
}

inline int MPI_Status_c2f08(const MPI_Status *c_status,
                            MPI_F08_status *f08_status) {
  return MPIABI_Status_c2f08(c_status, f08_status);
}

inline int MPI_Status_f082c(const MPI_F08_status *f08_status,
                            MPI_Status *c_status) {
  return MPIABI_Status_f082c(f08_status, c_status);
}

inline int MPI_Status_f2c(const MPI_Fint *f_status, MPI_Status *c_status) {
  return MPIABI_Status_f2c(f_status, c_status);
}

inline int MPI_Status_f2f08(const MPI_Fint *f_status,
                            MPI_F08_status *f08_status) {
  return MPIABI_Status_f2f08(f_status, f08_status);
}

inline MPI_Fint MPI_Type_c2f(MPI_Datatype datatype) {
  return MPIABI_Type_c2f(datatype);
}

inline int MPI_Type_create_f90_complex(int p, int r, MPI_Datatype *newtype) {
  return MPIABI_Type_create_f90_complex(p, r, newtype);
}

inline int MPI_Type_create_f90_integer(int r, MPI_Datatype *newtype) {
  return MPIABI_Type_create_f90_integer(r, newtype);
}

inline int MPI_Type_create_f90_real(int p, int r, MPI_Datatype *newtype) {
  return MPIABI_Type_create_f90_real(p, r, newtype);
}

inline MPI_Datatype MPI_Type_f2c(MPI_Fint datatype) {
  return MPIABI_Type_f2c(datatype);
}

inline int MPI_Type_match_size(int typeclass, int size,
                               MPI_Datatype *datatype) {
  return MPIABI_Type_match_size(typeclass, size, datatype);
}

inline MPI_Fint MPI_Win_c2f(MPI_Win win) { return MPIABI_Win_c2f(win); }

inline MPI_Win MPI_Win_f2c(MPI_Fint win) { return MPIABI_Win_f2c(win); }

// A.3.14 Tools / Profiling Interface C Bindings

inline int MPI_Pcontrol(const int level, ...) {
  // Variadic arguments cannot be forwarded
  // return MPIABI_Pcontrol(level, ...);
  return MPI_SUCCESS;
}

// A.3.15 Tools / MPI Tool Information Interface C Bindings

inline int MPI_T_category_changed(int *update_number) {
  return MPIABI_T_category_changed(update_number);
}

inline int MPI_T_category_get_categories(int cat_index, int len,
                                         int indices[]) {
  return MPIABI_T_category_get_categories(cat_index, len, indices);
}

inline int MPI_T_category_get_cvars(int cat_index, int len, int indices[]) {
  return MPIABI_T_category_get_cvars(cat_index, len, indices);
}

inline int MPI_T_category_get_events(int cat_index, int len, int indices[]) {
  return MPIABI_T_category_get_events(cat_index, len, indices);
}

inline int MPI_T_category_get_index(const char *name, int *cat_index) {
  return MPIABI_T_category_get_index(name, cat_index);
}

inline int MPI_T_category_get_info(int cat_index, char *name, int *name_len,
                                   char *desc, int *desc_len, int *num_cvars,
                                   int *num_pvars, int *num_categories) {
  return MPIABI_T_category_get_info(cat_index, name, name_len, desc, desc_len,
                                    num_cvars, num_pvars, num_categories);
}

inline int MPI_T_category_get_num(int *num_cat) {
  return MPIABI_T_category_get_num(num_cat);
}

inline int MPI_T_category_get_num_events(int cat_index, int *num_events) {
  return MPIABI_T_category_get_num_events(cat_index, num_events);
}

inline int MPI_T_category_get_pvars(int cat_index, int len, int indices[]) {
  return MPIABI_T_category_get_pvars(cat_index, len, indices);
}

inline int MPI_T_cvar_get_index(const char *name, int *cvar_index) {
  return MPIABI_T_cvar_get_index(name, cvar_index);
}

inline int MPI_T_cvar_get_info(int cvar_index, char *name, int *name_len,
                               int *verbosity, MPI_Datatype *datatype,
                               MPI_T_enum *enumtype, char *desc, int *desc_len,
                               int *bind, int *scope) {
  return MPIABI_T_cvar_get_info(cvar_index, name, name_len, verbosity, datatype,
                                enumtype, desc, desc_len, bind, scope);
}

inline int MPI_T_cvar_get_num(int *num_cvar) {
  return MPIABI_T_cvar_get_num(num_cvar);
}

inline int MPI_T_cvar_handle_alloc(int cvar_index, void *obj_handle,
                                   MPI_T_cvar_handle *handle, int *count) {
  return MPIABI_T_cvar_handle_alloc(cvar_index, obj_handle, handle, count);
}

inline int MPI_T_cvar_handle_free(MPI_T_cvar_handle *handle) {
  return MPIABI_T_cvar_handle_free(handle);
}

inline int MPI_T_cvar_read(MPI_T_cvar_handle handle, void *buf) {
  return MPIABI_T_cvar_read(handle, buf);
}

inline int MPI_T_cvar_write(MPI_T_cvar_handle handle, const void *buf) {
  return MPIABI_T_cvar_write(handle, buf);
}

inline int MPI_T_enum_get_info(MPI_T_enum enumtype, int *num, char *name,
                               int *name_len) {
  return MPIABI_T_enum_get_info(enumtype, num, name, name_len);
}

inline int MPI_T_enum_get_item(MPI_T_enum enumtype, int index, int *value,
                               char *name, int *name_len) {
  return MPIABI_T_enum_get_item(enumtype, index, value, name, name_len);
}

inline int
MPI_T_event_callback_get_info(MPI_T_event_registration event_registration,
                              MPI_T_cb_safety cb_safety, MPI_Info *info_used) {
  return MPIABI_T_event_callback_get_info(event_registration, cb_safety,
                                          info_used);
}

inline int
MPI_T_event_callback_set_info(MPI_T_event_registration event_registration,
                              MPI_T_cb_safety cb_safety, MPI_Info info) {
  return MPIABI_T_event_callback_set_info(event_registration, cb_safety, info);
}

inline int MPI_T_event_copy(MPI_T_event_instance event_instance, void *buffer) {
  return MPIABI_T_event_copy(event_instance, buffer);
}

inline int MPI_T_event_get_index(const char *name, int *event_index) {
  return MPIABI_T_event_get_index(name, event_index);
}

inline int MPI_T_event_get_info(int event_index, char *name, int *name_len,
                                int *verbosity,
                                MPI_Datatype array_of_datatypes[],
                                MPI_Aint array_of_displacements[],
                                int *num_elements, MPI_T_enum *enumtype,
                                MPI_Info *info, char *desc, int *desc_len,
                                int *bind) {
  return MPIABI_T_event_get_info(event_index, name, name_len, verbosity,
                                 array_of_datatypes, array_of_displacements,
                                 num_elements, enumtype, info, desc, desc_len,
                                 bind);
}

inline int MPI_T_event_get_num(int *num_events) {
  return MPIABI_T_event_get_num(num_events);
}

inline int MPI_T_event_get_source(MPI_T_event_instance event_instance,
                                  int *source_index) {
  return MPIABI_T_event_get_source(event_instance, source_index);
}

inline int MPI_T_event_get_timestamp(MPI_T_event_instance event_instance,
                                     MPI_Count *event_timestamp) {
  return MPIABI_T_event_get_timestamp(event_instance, event_timestamp);
}

inline int
MPI_T_event_handle_alloc(int event_index, void *obj_handle, MPI_Info info,
                         MPI_T_event_registration *event_registration) {
  return MPIABI_T_event_handle_alloc(event_index, obj_handle, info,
                                     event_registration);
}

inline int
MPI_T_event_handle_free(MPI_T_event_registration event_registration,
                        void *user_data,
                        MPI_T_event_free_cb_function free_cb_function) {
  return MPIABI_T_event_handle_free(event_registration, user_data,
                                    free_cb_function);
}

inline int
MPI_T_event_handle_get_info(MPI_T_event_registration event_registration,
                            MPI_Info *info_used) {
  return MPIABI_T_event_handle_get_info(event_registration, info_used);
}

inline int
MPI_T_event_handle_set_info(MPI_T_event_registration event_registration,
                            MPI_Info info) {
  return MPIABI_T_event_handle_set_info(event_registration, info);
}

inline int MPI_T_event_read(MPI_T_event_instance event_instance,
                            int element_index, void *buffer) {
  return MPIABI_T_event_read(event_instance, element_index, buffer);
}

inline int MPI_T_event_register_callback(
    MPI_T_event_registration event_registration, MPI_T_cb_safety cb_safety,
    MPI_Info info, void *user_data, MPI_T_event_cb_function event_cb_function) {
  return MPIABI_T_event_register_callback(event_registration, cb_safety, info,
                                          user_data, event_cb_function);
}

inline int MPI_T_event_set_dropped_handler(
    MPI_T_event_registration event_registration,
    MPI_T_event_dropped_cb_function dropped_cb_function) {
  return MPIABI_T_event_set_dropped_handler(event_registration,
                                            dropped_cb_function);
}

inline int MPI_T_finalize(void) { return MPIABI_T_finalize(); }

inline int MPI_T_init_thread(int required, int *provided) {
  return MPIABI_T_init_thread(required, provided);
}

inline int MPI_T_pvar_get_index(const char *name, int var_class,
                                int *pvar_index) {
  return MPIABI_T_pvar_get_index(name, var_class, pvar_index);
}

inline int MPI_T_pvar_get_info(int pvar_index, char *name, int *name_len,
                               int *verbosity, int *var_class,
                               MPI_Datatype *datatype, MPI_T_enum *enumtype,
                               char *desc, int *desc_len, int *bind,
                               int *readonly, int *continuous, int *atomic) {
  return MPIABI_T_pvar_get_info(pvar_index, name, name_len, verbosity,
                                var_class, datatype, enumtype, desc, desc_len,
                                bind, readonly, continuous, atomic);
}

inline int MPI_T_pvar_get_num(int *num_pvar) {
  return MPIABI_T_pvar_get_num(num_pvar);
}

inline int MPI_T_pvar_handle_alloc(MPI_T_pvar_session pe_session,
                                   int pvar_index, void *obj_handle,
                                   MPI_T_pvar_handle *handle, int *count) {
  return MPIABI_T_pvar_handle_alloc(pe_session, pvar_index, obj_handle, handle,
                                    count);
}

inline int MPI_T_pvar_handle_free(MPI_T_pvar_session pe_session,
                                  MPI_T_pvar_handle *handle) {
  return MPIABI_T_pvar_handle_free(pe_session, handle);
}

inline int MPI_T_pvar_read(MPI_T_pvar_session pe_session,
                           MPI_T_pvar_handle handle, void *buf) {
  return MPIABI_T_pvar_read(pe_session, handle, buf);
}

inline int MPI_T_pvar_readreset(MPI_T_pvar_session pe_session,
                                MPI_T_pvar_handle handle, void *buf) {
  return MPIABI_T_pvar_readreset(pe_session, handle, buf);
}

inline int MPI_T_pvar_reset(MPI_T_pvar_session pe_session,
                            MPI_T_pvar_handle handle) {
  return MPIABI_T_pvar_reset(pe_session, handle);
}

inline int MPI_T_pvar_session_create(MPI_T_pvar_session *pe_session) {
  return MPIABI_T_pvar_session_create(pe_session);
}

inline int MPI_T_pvar_session_free(MPI_T_pvar_session *pe_session) {
  return MPIABI_T_pvar_session_free(pe_session);
}

inline int MPI_T_pvar_start(MPI_T_pvar_session pe_session,
                            MPI_T_pvar_handle handle) {
  return MPIABI_T_pvar_start(pe_session, handle);
}

inline int MPI_T_pvar_stop(MPI_T_pvar_session pe_session,
                           MPI_T_pvar_handle handle) {
  return MPIABI_T_pvar_stop(pe_session, handle);
}

inline int MPI_T_pvar_write(MPI_T_pvar_session pe_session,
                            MPI_T_pvar_handle handle, const void *buf) {
  return MPIABI_T_pvar_write(pe_session, handle, buf);
}

inline int MPI_T_source_get_info(int source_index, char *name, int *name_len,
                                 char *desc, int *desc_len,
                                 MPI_T_source_order *ordering,
                                 MPI_Count *ticks_per_second,
                                 MPI_Count *max_ticks, MPI_Info *info) {
  return MPIABI_T_source_get_info(source_index, name, name_len, desc, desc_len,
                                  ordering, ticks_per_second, max_ticks, info);
}

inline int MPI_T_source_get_num(int *num_sources) {
  return MPIABI_T_source_get_num(num_sources);
}

inline int MPI_T_source_get_timestamp(int source_index, MPI_Count *timestamp) {
  return MPIABI_T_source_get_timestamp(source_index, timestamp);
}

// A.3.16 Deprecated C Bindings

inline int MPI_Attr_delete(MPI_Comm comm, int keyval) {
  return MPIABI_Attr_delete(comm, keyval);
}

inline int MPI_Attr_get(MPI_Comm comm, int keyval, void *attribute_val,
                        int *flag) {
  return MPIABI_Attr_get(comm, keyval, attribute_val, flag);
}

inline int MPI_Attr_put(MPI_Comm comm, int keyval, void *attribute_val) {
  return MPIABI_Attr_put(comm, keyval, attribute_val);
}

inline int MPI_Get_elements_x(const MPI_Status *status, MPI_Datatype datatype,
                              MPI_Count *count) {
  return MPIABI_Get_elements_x(status, datatype, count);
}

inline int MPI_Info_get(MPI_Info info, const char *key, int valuelen,
                        char *value, int *flag) {
  return MPIABI_Info_get(info, key, valuelen, value, flag);
}

inline int MPI_Info_get_valuelen(MPI_Info info, const char *key, int *valuelen,
                                 int *flag) {
  return MPIABI_Info_get_valuelen(info, key, valuelen, flag);
}

inline int MPI_Keyval_create(MPI_Copy_function *copy_fn,
                             MPI_Delete_function *delete_fn, int *keyval,
                             void *extra_state) {
  return MPIABI_Keyval_create(copy_fn, delete_fn, keyval, extra_state);
}

inline int MPI_Keyval_free(int *keyval) { return MPIABI_Keyval_free(keyval); }

inline int MPI_Status_set_elements_x(MPI_Status *status, MPI_Datatype datatype,
                                     MPI_Count count) {
  return MPIABI_Status_set_elements_x(status, datatype, count);
}

inline int MPI_Type_get_extent_x(MPI_Datatype datatype, MPI_Count *lb,
                                 MPI_Count *extent) {
  return MPIABI_Type_get_extent_x(datatype, lb, extent);
}

inline int MPI_Type_get_true_extent_x(MPI_Datatype datatype, MPI_Count *true_lb,
                                      MPI_Count *true_extent) {
  return MPIABI_Type_get_true_extent_x(datatype, true_lb, true_extent);
}

inline int MPI_Type_size_x(MPI_Datatype datatype, MPI_Count *size) {
  return MPIABI_Type_size_x(datatype, size);
}

// MPIX

inline int MPIX_Query_cuda_support() { return MPIXABI_Query_cuda_support(); }

inline int MPIX_Query_hip_support() { return MPIXABI_Query_hip_support(); }

inline int MPIX_Query_ze_support() { return MPIXABI_Query_ze_support(); }

#endif // #ifndef MPI_FUNCTIONS_H
