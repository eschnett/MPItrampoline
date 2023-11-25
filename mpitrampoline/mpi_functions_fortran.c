#include "mpi.h"

#include "mpiabi_function_pointers_fortran.h"

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

void mpi_bsend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_bsend_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

// void mpi_bsend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_bsend_c_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

void mpi_bsend_init_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_bsend_init_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_bsend_init_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_bsend_init_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_buffer_attach_(void *buffer, MPI_Fint *size, MPI_Fint *ierror) { (*mpiabi_buffer_attach_ptr)(buffer, size, ierror); }

// void mpi_buffer_attach_c_(void *buffer, MPI_Count *size, MPI_Fint *ierror) { (*mpiabi_buffer_attach_c_ptr)(buffer, size, ierror); }

void mpi_buffer_detach_(void *buffer_addr, MPI_Fint *size, MPI_Fint *ierror) { (*mpiabi_buffer_detach_ptr)(buffer_addr, size, ierror); }

// void mpi_buffer_detach_c_(void *buffer_addr, MPI_Count *size, MPI_Fint *ierror) { (*mpiabi_buffer_detach_c_ptr)(buffer_addr, size, ierror); }

void mpi_buffer_flush_(MPI_Fint *ierror) { (*mpiabi_buffer_flush_ptr)(ierror); }

void mpi_buffer_iflush_(MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_buffer_iflush_ptr)(request, ierror); }

void mpi_cancel_(MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_cancel_ptr)(request, ierror); }

void mpi_comm_attach_buffer_(MPI_Fint *comm, void *buffer, MPI_Fint *size, MPI_Fint *ierror) { (*mpiabi_comm_attach_buffer_ptr)(comm, buffer, size, ierror); }

// void mpi_comm_attach_buffer_c_(MPI_Fint *comm, void *buffer, MPI_Count *size, MPI_Fint *ierror) { (*mpiabi_comm_attach_buffer_c_ptr)(comm, buffer, size, ierror); }

void mpi_comm_detach_buffer_(MPI_Fint *comm, void *buffer_addr, MPI_Fint *size, MPI_Fint *ierror) { (*mpiabi_comm_detach_buffer_ptr)(comm, buffer_addr, size, ierror); }

// void mpi_comm_detach_buffer_c_(MPI_Fint *comm, void *buffer_addr, MPI_Count *size, MPI_Fint *ierror) { (*mpiabi_comm_detach_buffer_c_ptr)(comm, buffer_addr, size, ierror); }

void mpi_comm_flush_buffer_(MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_comm_flush_buffer_ptr)(comm, ierror); }

void mpi_comm_iflush_buffer_(MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_comm_iflush_buffer_ptr)(comm, request, ierror); }

void mpi_get_count_(const MPI_Fint *status, MPI_Fint *datatype, MPI_Fint *count, MPI_Fint *ierror) { (*mpiabi_get_count_ptr)(status, datatype, count, ierror); }

// void mpi_get_count_c_(const MPI_Fint *status, MPI_Fint *datatype, MPI_Count *count, MPI_Fint *ierror) { (*mpiabi_get_count_c_ptr)(status, datatype, count, ierror); }

void mpi_ibsend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_ibsend_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_ibsend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_ibsend_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_improbe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_improbe_ptr)(source, tag, comm, flag, message, status, ierror); }

void mpi_imrecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *message, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_imrecv_ptr)(buf, count, datatype, message, request, ierror); }

// void mpi_imrecv_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *message, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_imrecv_c_ptr)(buf, count, datatype, message, request, ierror); }

void mpi_iprobe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_iprobe_ptr)(source, tag, comm, flag, status, ierror); }

void mpi_irecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_irecv_ptr)(buf, count, datatype, source, tag, comm, request, ierror); }

// void mpi_irecv_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_irecv_c_ptr)(buf, count, datatype, source, tag, comm, request, ierror); }

void mpi_irsend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_irsend_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_irsend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_irsend_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_isend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_isend_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_isend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_isend_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_isendrecv_(const void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_isendrecv_ptr)(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, request, ierror); }

// void mpi_isendrecv_c_(const void *sendbuf, MPI_Count *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf, MPI_Count *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_isendrecv_c_ptr)(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, request, ierror); }

void mpi_isendrecv_replace_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_isendrecv_replace_ptr)(buf, count, datatype, dest, sendtag, source, recvtag, comm, request, ierror); }

// void mpi_isendrecv_replace_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_isendrecv_replace_c_ptr)(buf, count, datatype, dest, sendtag, source, recvtag, comm, request, ierror); }

void mpi_issend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_issend_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_issend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_issend_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_mprobe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_mprobe_ptr)(source, tag, comm, message, status, ierror); }

void mpi_mrecv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_mrecv_ptr)(buf, count, datatype, message, status, ierror); }

// void mpi_mrecv_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *message, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_mrecv_c_ptr)(buf, count, datatype, message, status, ierror); }

void mpi_probe_(MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_probe_ptr)(source, tag, comm, status, ierror); }

void mpi_recv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_recv_ptr)(buf, count, datatype, source, tag, comm, status, ierror); }

// void mpi_recv_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_recv_c_ptr)(buf, count, datatype, source, tag, comm, status, ierror); }

void mpi_recv_init_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_recv_init_ptr)(buf, count, datatype, source, tag, comm, request, ierror); }

// void mpi_recv_init_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *source, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_recv_init_c_ptr)(buf, count, datatype, source, tag, comm, request, ierror); }

void mpi_request_free_(MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_request_free_ptr)(request, ierror); }

void mpi_request_get_status_(MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_request_get_status_ptr)(request, flag, status, ierror); }

void mpi_request_get_status_all_(MPI_Fint *count, const MPI_Fint *array_of_requests[], MPI_Fint *flag, MPI_Fint *array_of_statuses[], MPI_Fint *ierror) { (*mpiabi_request_get_status_all_ptr)(count, array_of_requests, flag, array_of_statuses, ierror); }

void mpi_request_get_status_any_(MPI_Fint *count, const MPI_Fint *array_of_requests[], MPI_Fint *index, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_request_get_status_any_ptr)(count, array_of_requests, index, flag, status, ierror); }

void mpi_request_get_status_some_(MPI_Fint *incount, const MPI_Fint *array_of_requests[], MPI_Fint *outcount, MPI_Fint *array_of_indices[], MPI_Fint *array_of_statuses[], MPI_Fint *ierror) { (*mpiabi_request_get_status_some_ptr)(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierror); }

void mpi_rsend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_rsend_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

// void mpi_rsend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_rsend_c_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

void mpi_rsend_init_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_rsend_init_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_rsend_init_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_rsend_init_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_send_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_send_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

// void mpi_send_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_send_c_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

void mpi_send_init_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_send_init_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_send_init_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_send_init_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_sendrecv_(const void *sendbuf, MPI_Fint *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf, MPI_Fint *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_sendrecv_ptr)(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierror); }

// void mpi_sendrecv_c_(const void *sendbuf, MPI_Count *sendcount, MPI_Fint *sendtype, MPI_Fint *dest, MPI_Fint *sendtag, void *recvbuf, MPI_Count *recvcount, MPI_Fint *recvtype, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_sendrecv_c_ptr)(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, status, ierror); }

void mpi_sendrecv_replace_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_sendrecv_replace_ptr)(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierror); }

// void mpi_sendrecv_replace_c_(void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *sendtag, MPI_Fint *source, MPI_Fint *recvtag, MPI_Fint *comm, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_sendrecv_replace_c_ptr)(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierror); }

void mpi_session_attach_buffer_(MPI_Fint *session, void *buffer, MPI_Fint *size, MPI_Fint *ierror) { (*mpiabi_session_attach_buffer_ptr)(session, buffer, size, ierror); }

// void mpi_session_attach_buffer_c_(MPI_Fint *session, void *buffer, MPI_Count *size, MPI_Fint *ierror) { (*mpiabi_session_attach_buffer_c_ptr)(session, buffer, size, ierror); }

void mpi_session_detach_buffer_(MPI_Fint *session, void *buffer_addr, MPI_Fint *size, MPI_Fint *ierror) { (*mpiabi_session_detach_buffer_ptr)(session, buffer_addr, size, ierror); }

// void mpi_session_detach_buffer_c_(MPI_Fint *session, void *buffer_addr, MPI_Count *size, MPI_Fint *ierror) { (*mpiabi_session_detach_buffer_c_ptr)(session, buffer_addr, size, ierror); }

void mpi_session_flush_buffer_(MPI_Fint *session, MPI_Fint *ierror) { (*mpiabi_session_flush_buffer_ptr)(session, ierror); }

void mpi_session_iflush_buffer_(MPI_Fint *session, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_session_iflush_buffer_ptr)(session, request, ierror); }

void mpi_ssend_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_ssend_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

// void mpi_ssend_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) { (*mpiabi_ssend_c_ptr)(buf, count, datatype, dest, tag, comm, ierror); }

void mpi_ssend_init_(const void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_ssend_init_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

// void mpi_ssend_init_c_(const void *buf, MPI_Count *count, MPI_Fint *datatype, MPI_Fint *dest, MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_ssend_init_c_ptr)(buf, count, datatype, dest, tag, comm, request, ierror); }

void mpi_start_(MPI_Fint *request, MPI_Fint *ierror) { (*mpiabi_start_ptr)(request, ierror); }

void mpi_startall_(MPI_Fint *count, MPI_Fint *array_of_requests[], MPI_Fint *ierror) { (*mpiabi_startall_ptr)(count, array_of_requests, ierror); }

void mpi_status_get_error_(MPI_Fint *status, MPI_Fint *err, MPI_Fint *ierror) { (*mpiabi_status_get_error_ptr)(status, err, ierror); }

void mpi_status_get_source_(MPI_Fint *status, MPI_Fint *source, MPI_Fint *ierror) { (*mpiabi_status_get_source_ptr)(status, source, ierror); }

void mpi_status_get_tag_(MPI_Fint *status, MPI_Fint *tag, MPI_Fint *ierror) { (*mpiabi_status_get_tag_ptr)(status, tag, ierror); }

void mpi_test_(MPI_Fint *request, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_test_ptr)(request, flag, status, ierror); }

void mpi_test_cancelled_(const MPI_Fint *status, MPI_Fint *flag, MPI_Fint *ierror) { (*mpiabi_test_cancelled_ptr)(status, flag, ierror); }

void mpi_testall_(MPI_Fint *count, MPI_Fint *array_of_requests[], MPI_Fint *flag, MPI_Fint *array_of_statuses[], MPI_Fint *ierror) { (*mpiabi_testall_ptr)(count, array_of_requests, flag, array_of_statuses, ierror); }

void mpi_testany_(MPI_Fint *count, MPI_Fint *array_of_requests[], MPI_Fint *index, MPI_Fint *flag, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_testany_ptr)(count, array_of_requests, index, flag, status, ierror); }

void mpi_testsome_(MPI_Fint *incount, MPI_Fint *array_of_requests[], MPI_Fint *outcount, MPI_Fint *array_of_indices[], MPI_Fint *array_of_statuses[], MPI_Fint *ierror) { (*mpiabi_testsome_ptr)(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierror); }

void mpi_wait_(MPI_Fint *request, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_wait_ptr)(request, status, ierror); }

void mpi_waitall_(MPI_Fint *count, MPI_Fint *array_of_requests[], MPI_Fint *array_of_statuses[], MPI_Fint *ierror) { (*mpiabi_waitall_ptr)(count, array_of_requests, array_of_statuses, ierror); }

void mpi_waitany_(MPI_Fint *count, MPI_Fint *array_of_requests[], MPI_Fint *index, MPI_Fint *status, MPI_Fint *ierror) { (*mpiabi_waitany_ptr)(count, array_of_requests, index, status, ierror); }

void mpi_waitsome_(MPI_Fint *incount, MPI_Fint *array_of_requests[], MPI_Fint *outcount, MPI_Fint *array_of_indices[], MPI_Fint *array_of_statuses[], MPI_Fint *ierror) { (*mpiabi_waitsome_ptr)(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierror); }

// A.3.2 Partitioned Communication C Bindings

void mpi_parrived_(MPIABI_Fint *request, MPIABI_Fint *partition, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_parrived_ptr)(request, partition, flag, ierror); }

void mpi_pready_(MPIABI_Fint *partition, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_pready_ptr)(partition, request, ierror); }

void mpi_pready_list_(MPIABI_Fint *length, const MPIABI_Fint *array_of_partitions[], MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_pready_list_ptr)(length, array_of_partitions, request, ierror); }

void mpi_pready_range_(MPIABI_Fint *partition_low, MPIABI_Fint *partition_high, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_pready_range_ptr)(partition_low, partition_high, request, ierror); }

void mpi_precv_init_(void *buf, MPIABI_Fint *partitions, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *source, MPIABI_Fint *tag, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_precv_init_ptr)(buf, partitions, count, datatype, source, tag, comm, info, request, ierror); }

void mpi_psend_init_(const void *buf, MPIABI_Fint *partitions, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *dest, MPIABI_Fint *tag, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_psend_init_ptr)(buf, partitions, count, datatype, dest, tag, comm, info, request, ierror); }

// A.3.3 Datatypes C Bindings

MPIABI_Aint mpi_aint_add_(MPIABI_Aint *base, MPIABI_Aint *disp) { return (*mpiabi_aint_add_ptr)(base, disp); }

MPIABI_Aint mpi_aint_diff_(MPIABI_Aint *addr1, MPIABI_Aint *addr2) { return (*mpiabi_aint_diff_ptr)(addr1, addr2); }

void mpi_get_address_(const void *location, MPIABI_Aint *address, MPIABI_Fint *ierror) { (*mpiabi_get_address_ptr)(location, address, ierror); }

void mpi_get_elements_(const MPIABI_Fint *status, MPIABI_Fint *datatype, MPIABI_Fint *count, MPIABI_Fint *ierror) { (*mpiabi_get_elements_ptr)(status, datatype, count, ierror); }

// void mpi_get_elements_c_(const MPIABI_Fint *status, MPIABI_Fint *datatype, MPIABI_Count *count, MPIABI_Fint *ierror) { (*mpiabi_get_elements_c_ptr)(status, datatype, count, ierror); }

void mpi_pack_(const void *inbuf, MPIABI_Fint *incount, MPIABI_Fint *datatype, void *outbuf, MPIABI_Fint *outsize, MPIABI_Fint *position, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_pack_ptr)(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror); }

// void mpi_pack_c_(const void *inbuf, MPIABI_Count *incount, MPIABI_Fint *datatype, void *outbuf, MPIABI_Count *outsize, MPIABI_Count *position, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_pack_c_ptr)(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror); }

void mpi_pack_external_(const char datarep[], const void *inbuf, MPIABI_Fint *incount, MPIABI_Fint *datatype, void *outbuf, MPIABI_Aint *outsize, MPIABI_Aint *position, MPIABI_Fint *ierror) { (*mpiabi_pack_external_ptr)(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierror); }

// void mpi_pack_external_c_(const char datarep[], const void *inbuf, MPIABI_Count *incount, MPIABI_Fint *datatype, void *outbuf, MPIABI_Count *outsize, MPIABI_Count *position, MPIABI_Fint *ierror) { (*mpiabi_pack_external_c_ptr)(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierror); }

void mpi_pack_external_size_(const char datarep[], MPIABI_Count *incount, MPIABI_Fint *datatype, MPIABI_Aint *size, MPIABI_Fint *ierror) { (*mpiabi_pack_external_size_ptr)(datarep, incount, datatype, size, ierror); }

// void mpi_pack_external_size_c_(const char datarep[], MPIABI_Count *incount, MPIABI_Fint *datatype, MPIABI_Count *size, MPIABI_Fint *ierror) { (*mpiabi_pack_external_size_c_ptr)(datarep, incount, datatype, size, ierror); }

void mpi_pack_size_(MPIABI_Fint *incount, MPIABI_Fint *datatype, MPIABI_Fint *comm, MPIABI_Fint *size, MPIABI_Fint *ierror) { (*mpiabi_pack_size_ptr)(incount, datatype, comm, size, ierror); }

// void mpi_pack_size_c_(MPIABI_Count *incount, MPIABI_Fint *datatype, MPIABI_Fint *comm, MPIABI_Count *size, MPIABI_Fint *ierror) { (*mpiabi_pack_size_c_ptr)(incount, datatype, comm, size, ierror); }

void mpi_type_commit_(MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_type_commit_ptr)(datatype, ierror); }

void mpi_type_contiguous_(MPIABI_Fint *count, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_contiguous_ptr)(count, oldtype, newtype, ierror); }

// void mpi_type_contiguous_c_(MPIABI_Count *count, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_contiguous_c_ptr)(count, oldtype, newtype, ierror); }

void mpi_type_create_darray_(MPIABI_Fint *size, MPIABI_Fint *rank, MPIABI_Fint *ndims, const MPIABI_Fint *array_of_gsizes[], const MPIABI_Fint *array_of_distribs[], const MPIABI_Fint *array_of_dargs[], const MPIABI_Fint *array_of_psizes[], MPIABI_Fint *order, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_darray_ptr)( size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype, ierror); }

// void mpi_type_create_darray_c_(MPIABI_Fint *size, MPIABI_Fint *rank, MPIABI_Fint *ndims, const MPIABI_Count *array_of_gsizes[], const MPIABI_Fint *array_of_distribs[], const MPIABI_Fint *array_of_dargs[], const MPIABI_Fint *array_of_psizes[], MPIABI_Fint *order, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_darray_c_ptr)( size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, order, oldtype, newtype, ierror); }

void mpi_type_create_hindexed_(MPIABI_Fint *count, const MPIABI_Fint *array_of_blocklengths[], const MPIABI_Aint *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_hindexed_ptr)(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror); }

void mpi_type_create_hindexed_block_( MPIABI_Fint *count, MPIABI_Fint *blocklength, const MPIABI_Aint *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_hindexed_block_ptr)( count, blocklength, array_of_displacements, oldtype, newtype, ierror); }

// void mpi_type_create_hindexed_block_c_( MPIABI_Count *count, MPIABI_Count *blocklength, const MPIABI_Count *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_hindexed_block_c_ptr)( count, blocklength, array_of_displacements, oldtype, newtype, ierror); }

// void mpi_type_create_hindexed_c_(MPIABI_Count *count, const MPIABI_Count *array_of_blocklengths[], const MPIABI_Count *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_hindexed_c_ptr)(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror); }

void mpi_type_create_hvector_(MPIABI_Fint *count, MPIABI_Fint *blocklength, MPIABI_Aint *stride, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_hvector_ptr)(count, blocklength, stride, oldtype, newtype, ierror); }

// void mpi_type_create_hvector_c_(MPIABI_Count *count, MPIABI_Count *blocklength, MPIABI_Count *stride, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_hvector_c_ptr)(count, blocklength, stride, oldtype, newtype, ierror); }

void mpi_type_create_indexed_block_(MPIABI_Fint *count, MPIABI_Fint *blocklength, const MPIABI_Fint *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_indexed_block_ptr)( count, blocklength, array_of_displacements, oldtype, newtype, ierror); }

// void mpi_type_create_indexed_block_c_( MPIABI_Count *count, MPIABI_Count *blocklength, const MPIABI_Count *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_indexed_block_c_ptr)( count, blocklength, array_of_displacements, oldtype, newtype, ierror); }

void mpi_type_create_resized_(MPIABI_Fint *oldtype, MPIABI_Aint *lb, MPIABI_Aint *extent, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_resized_ptr)(oldtype, lb, extent, newtype, ierror); }

// void mpi_type_create_resized_c_(MPIABI_Fint *oldtype, MPIABI_Count *lb, MPIABI_Count *extent, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_resized_c_ptr)(oldtype, lb, extent, newtype, ierror); }

void mpi_type_create_struct_(MPIABI_Fint *count, const MPIABI_Fint *array_of_blocklengths[], const MPIABI_Aint *array_of_displacements[], const MPIABI_Fint *array_of_types[], MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_struct_ptr)(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierror); }

// void mpi_type_create_struct_c_(MPIABI_Count *count, const MPIABI_Count *array_of_blocklengths[], const MPIABI_Count *array_of_displacements[], const MPIABI_Fint *array_of_types[], MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_struct_c_ptr)(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierror); }

void mpi_type_create_subarray_(MPIABI_Fint *ndims, const MPIABI_Fint *array_of_sizes[], const MPIABI_Fint *array_of_subsizes[], const MPIABI_Fint *array_of_starts[], MPIABI_Fint *order, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_subarray_ptr)(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierror); }

// void mpi_type_create_subarray_c_(MPIABI_Fint *ndims, const MPIABI_Count *array_of_sizes[], const MPIABI_Count *array_of_subsizes[], const MPIABI_Count *array_of_starts[], MPIABI_Fint *order, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_create_subarray_c_ptr)(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierror); }

void mpi_type_dup_(MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_dup_ptr)(oldtype, newtype, ierror); }

void mpi_type_free_(MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_type_free_ptr)(datatype, ierror); }

void mpi_type_get_contents_(MPIABI_Fint *datatype, MPIABI_Fint *max_integers, MPIABI_Fint *max_addresses, MPIABI_Fint *max_datatypes, MPIABI_Fint *array_of_integers[], MPIABI_Aint *array_of_addresses[], MPIABI_Fint *array_of_datatypes[], MPIABI_Fint *ierror) { (*mpiabi_type_get_contents_ptr)( datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, array_of_datatypes, ierror); }

// void mpi_type_get_contents_c_( MPIABI_Fint *datatype, MPIABI_Count *max_integers, MPIABI_Count *max_addresses, MPIABI_Count *max_large_counts, MPIABI_Count *max_datatypes, MPIABI_Fint *array_of_integers[], MPIABI_Aint *array_of_addresses[], MPIABI_Count *array_of_large_counts[], MPIABI_Fint *array_of_datatypes[], MPIABI_Fint *ierror) { (*mpiabi_type_get_contents_c_ptr)( datatype, max_integers, max_addresses, max_large_counts, max_datatypes, array_of_integers, array_of_addresses, array_of_large_counts, array_of_datatypes, ierror); }

void mpi_type_get_envelope_(MPIABI_Fint *datatype, MPIABI_Fint *num_integers, MPIABI_Fint *num_addresses, MPIABI_Fint *num_datatypes, MPIABI_Fint *combiner, MPIABI_Fint *ierror) { (*mpiabi_type_get_envelope_ptr)(datatype, num_integers, num_addresses, num_datatypes, combiner, ierror); }

// void mpi_type_get_envelope_c_(MPIABI_Fint *datatype, MPIABI_Count *num_integers, MPIABI_Count *num_addresses, MPIABI_Count *num_large_counts, MPIABI_Count *num_datatypes, MPIABI_Fint *combiner, MPIABI_Fint *ierror) { (*mpiabi_type_get_envelope_c_ptr)(datatype, num_integers, num_addresses, num_large_counts, num_datatypes, combiner, ierror); }

void mpi_type_get_extent_(MPIABI_Fint *datatype, MPIABI_Aint *lb, MPIABI_Aint *extent, MPIABI_Fint *ierror) { (*mpiabi_type_get_extent_ptr)(datatype, lb, extent, ierror); }

// void mpi_type_get_extent_c_(MPIABI_Fint *datatype, MPIABI_Count *lb, MPIABI_Count *extent, MPIABI_Fint *ierror) { (*mpiabi_type_get_extent_c_ptr)(datatype, lb, extent, ierror); }

void mpi_type_get_true_extent_(MPIABI_Fint *datatype, MPIABI_Aint *true_lb, MPIABI_Aint *true_extent, MPIABI_Fint *ierror) { (*mpiabi_type_get_true_extent_ptr)(datatype, true_lb, true_extent, ierror); }

// void mpi_type_get_true_extent_c_(MPIABI_Fint *datatype, MPIABI_Count *true_lb, MPIABI_Count *true_extent, MPIABI_Fint *ierror) { (*mpiabi_type_get_true_extent_c_ptr)(datatype, true_lb, true_extent, ierror); }

void mpi_type_indexed_(MPIABI_Fint *count, const MPIABI_Fint *array_of_blocklengths[], const MPIABI_Fint *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_indexed_ptr)(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror); }

// void mpi_type_indexed_c_(MPIABI_Count *count, const MPIABI_Count *array_of_blocklengths[], const MPIABI_Count *array_of_displacements[], MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_indexed_c_ptr)(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror); }

void mpi_type_size_(MPIABI_Fint *datatype, MPIABI_Fint *size, MPIABI_Fint *ierror) { (*mpiabi_type_size_ptr)(datatype, size, ierror); }

// void mpi_type_size_c_(MPIABI_Fint *datatype, MPIABI_Count *size, MPIABI_Fint *ierror) { (*mpiabi_type_size_c_ptr)(datatype, size, ierror); }

void mpi_type_vector_(MPIABI_Fint *count, MPIABI_Fint *blocklength, MPIABI_Fint *stride, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_vector_ptr)(count, blocklength, stride, oldtype, newtype, ierror); }

// void mpi_type_vector_c_(MPIABI_Count *count, MPIABI_Count *blocklength, MPIABI_Count *stride, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_vector_c_ptr)(count, blocklength, stride, oldtype, newtype, ierror); }

void mpi_unpack_(const void *inbuf, MPIABI_Fint *insize, MPIABI_Fint *position, void *outbuf, MPIABI_Fint *outcount, MPIABI_Fint *datatype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_unpack_ptr)(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror); }

// void mpi_unpack_c_(const void *inbuf, MPIABI_Count *insize, MPIABI_Count *position, void *outbuf, MPIABI_Count *outcount, MPIABI_Fint *datatype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_unpack_c_ptr)(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror); }

void mpi_unpack_external_(const char datarep[], const void *inbuf, MPIABI_Aint *insize, MPIABI_Aint *position, void *outbuf, MPIABI_Fint *outcount, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_unpack_external_ptr)(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierror); }

// void mpi_unpack_external_c_(const char datarep[], const void *inbuf, MPIABI_Count *insize, MPIABI_Count *position, void *outbuf, MPIABI_Count *outcount, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_unpack_external_c_ptr)(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierror); }

// A.3.4 Collective Communication C Bindings

void mpi_allgather_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_allgather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

// void mpi_allgather_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_allgather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

void mpi_allgather_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_allgather_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

// void mpi_allgather_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_allgather_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

void mpi_allgatherv_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_allgatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror); }

// void mpi_allgatherv_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_allgatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror); }

void mpi_allgatherv_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_allgatherv_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror); }

// void mpi_allgatherv_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_allgatherv_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror); }

void mpi_allreduce_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_allreduce_ptr)(sendbuf, recvbuf, count, datatype, op, comm, ierror); }

// void mpi_allreduce_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_allreduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, ierror); }

void mpi_allreduce_init_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_allreduce_init_ptr)(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror); }

// void mpi_allreduce_init_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_allreduce_init_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror); }

void mpi_alltoall_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_alltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

// void mpi_alltoall_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_alltoall_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

void mpi_alltoall_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_alltoall_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

// void mpi_alltoall_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_alltoall_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

void mpi_alltoallv_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_alltoallv_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror); }

// void mpi_alltoallv_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_alltoallv_c_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror); }

void mpi_alltoallv_init_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_alltoallv_init_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror); }

// void mpi_alltoallv_init_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_alltoallv_init_c_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror); }

void mpi_alltoallw_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_alltoallw_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror); }

// void mpi_alltoallw_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_alltoallw_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror); }

void mpi_alltoallw_init_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_alltoallw_init_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror); }

// void mpi_alltoallw_init_c_( const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_alltoallw_init_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror); }

void mpi_barrier_(MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_barrier_ptr)(comm, ierror); }

void mpi_barrier_init_(MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_barrier_init_ptr)(comm, info, request, ierror); }

void mpi_bcast_(void *buffer, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_bcast_ptr)(buffer, count, datatype, root, comm, ierror); }

// void mpi_bcast_c_(void *buffer, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_bcast_c_ptr)(buffer, count, datatype, root, comm, ierror); }

void mpi_bcast_init_(void *buffer, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_bcast_init_ptr)(buffer, count, datatype, root, comm, info, request, ierror); }

// void mpi_bcast_init_c_(void *buffer, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_bcast_init_c_ptr)(buffer, count, datatype, root, comm, info, request, ierror); }

void mpi_exscan_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_exscan_ptr)(sendbuf, recvbuf, count, datatype, op, comm, ierror); }

// void mpi_exscan_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_exscan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, ierror); }

void mpi_exscan_init_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_exscan_init_ptr)(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror); }

// void mpi_exscan_init_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_exscan_init_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror); }

void mpi_gather_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_gather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror); }

// void mpi_gather_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_gather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror); }

void mpi_gather_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_gather_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror); }

// void mpi_gather_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_gather_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror); }

void mpi_gatherv_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_gatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierror); }

// void mpi_gatherv_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_gatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierror); }

void mpi_gatherv_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_gatherv_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request, ierror); }

// void mpi_gatherv_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_gatherv_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request, ierror); }

void mpi_iallgather_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iallgather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

// void mpi_iallgather_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iallgather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

void mpi_iallgatherv_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iallgatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror); }

// void mpi_iallgatherv_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iallgatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror); }

void mpi_iallreduce_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iallreduce_ptr)(sendbuf, recvbuf, count, datatype, op, comm, request, ierror); }

// void mpi_iallreduce_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iallreduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, request, ierror); }

void mpi_ialltoall_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ialltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

// void mpi_ialltoall_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ialltoall_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

void mpi_ialltoallv_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ialltoallv_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror); }

// void mpi_ialltoallv_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ialltoallv_c_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror); }

void mpi_ialltoallw_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ialltoallw_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror); }

// void mpi_ialltoallw_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ialltoallw_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror); }

void mpi_ibarrier_(MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ibarrier_ptr)(comm, request, ierror); }

void mpi_ibcast_(void *buffer, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ibcast_ptr)(buffer, count, datatype, root, comm, request, ierror); }

// void mpi_ibcast_c_(void *buffer, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ibcast_c_ptr)(buffer, count, datatype, root, comm, request, ierror); }

void mpi_iexscan_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iexscan_ptr)(sendbuf, recvbuf, count, datatype, op, comm, request, ierror); }

// void mpi_iexscan_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iexscan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, request, ierror); }

void mpi_igather_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_igather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror); }

// void mpi_igather_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_igather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror); }

void mpi_igatherv_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_igatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierror); }

// void mpi_igatherv_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_igatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierror); }

void mpi_ireduce_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ireduce_ptr)(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror); }

// void mpi_ireduce_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ireduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror); }

void mpi_ireduce_scatter_(const void *sendbuf, void *recvbuf, const MPIABI_Fint *recvcounts[], MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ireduce_scatter_ptr)(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierror); }

void mpi_ireduce_scatter_block_(const void *sendbuf, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ireduce_scatter_block_ptr)(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierror); }

// void mpi_ireduce_scatter_block_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ireduce_scatter_block_c_ptr)(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierror); }

// void mpi_ireduce_scatter_c_(const void *sendbuf, void *recvbuf, const MPIABI_Count *recvcounts[], MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ireduce_scatter_c_ptr)(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierror); }

void mpi_iscan_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iscan_ptr)(sendbuf, recvbuf, count, datatype, op, comm, request, ierror); }

// void mpi_iscan_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iscan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, request, ierror); }

void mpi_iscatter_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iscatter_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror); }

// void mpi_iscatter_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iscatter_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror); }

void mpi_iscatterv_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iscatterv_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror); }

// void mpi_iscatterv_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_iscatterv_c_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror); }

void mpi_op_commutative_(MPIABI_Fint *op, MPIABI_Fint *commute, MPIABI_Fint *ierror) { (*mpiabi_op_commutative_ptr)(op, commute, ierror); }

void mpi_op_create_(void (*user_fn)(void), MPIABI_Fint *commute, MPIABI_Fint *op, MPIABI_Fint *ierror) { (*mpiabi_op_create_ptr)(user_fn, commute, op, ierror); }

// void mpi_op_create_c_(void (*user_fn)(void), MPIABI_Fint *commute, MPIABI_Fint *op, MPIABI_Fint *ierror) { (*mpiabi_op_create_c_ptr)(user_fn, commute, op, ierror); }

void mpi_op_free_(MPIABI_Fint *op, MPIABI_Fint *ierror) { (*mpiabi_op_free_ptr)(op, ierror); }

void mpi_reduce_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_reduce_ptr)(sendbuf, recvbuf, count, datatype, op, root, comm, ierror); }

// void mpi_reduce_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_reduce_c_ptr)(sendbuf, recvbuf, count, datatype, op, root, comm, ierror); }

void mpi_reduce_init_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_reduce_init_ptr)(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, ierror); }

// void mpi_reduce_init_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_reduce_init_c_ptr)(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, ierror); }

void mpi_reduce_local_(const void *inbuf, void *inoutbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *ierror) { (*mpiabi_reduce_local_ptr)(inbuf, inoutbuf, count, datatype, op, ierror); }

// void mpi_reduce_local_c_(const void *inbuf, void *inoutbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *ierror) { (*mpiabi_reduce_local_c_ptr)(inbuf, inoutbuf, count, datatype, op, ierror); }

void mpi_reduce_scatter_(const void *sendbuf, void *recvbuf, const MPIABI_Fint *recvcounts[], MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_ptr)(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror); }

void mpi_reduce_scatter_block_(const void *sendbuf, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_block_ptr)(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror); }

// void mpi_reduce_scatter_block_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_block_c_ptr)(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror); }

void mpi_reduce_scatter_block_init_(const void *sendbuf, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_block_init_ptr)(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request, ierror); }

// void mpi_reduce_scatter_block_init_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_block_init_c_ptr)( sendbuf, recvbuf, recvcount, datatype, op, comm, info, request, ierror); }

// void mpi_reduce_scatter_c_(const void *sendbuf, void *recvbuf, const MPIABI_Count *recvcounts[], MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_c_ptr)(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror); }

void mpi_reduce_scatter_init_(const void *sendbuf, void *recvbuf, const MPIABI_Fint *recvcounts[], MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_init_ptr)(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request, ierror); }

// void mpi_reduce_scatter_init_c_(const void *sendbuf, void *recvbuf, const MPIABI_Count *recvcounts[], MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_reduce_scatter_init_c_ptr)(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request, ierror); }

void mpi_scan_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_scan_ptr)(sendbuf, recvbuf, count, datatype, op, comm, ierror); }

// void mpi_scan_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_scan_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, ierror); }

void mpi_scan_init_(const void *sendbuf, void *recvbuf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_scan_init_ptr)(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror); }

// void mpi_scan_init_c_(const void *sendbuf, void *recvbuf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *op, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_scan_init_c_ptr)(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror); }

void mpi_scatter_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_scatter_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror); }

// void mpi_scatter_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_scatter_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror); }

void mpi_scatter_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_scatter_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror); }

// void mpi_scatter_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_scatter_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror); }

void mpi_scatterv_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_scatterv_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror); }

// void mpi_scatterv_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_scatterv_c_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror); }

void mpi_scatterv_init_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_scatterv_init_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror); }

// void mpi_scatterv_init_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_scatterv_init_c_ptr)(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror); }

void mpi_type_get_value_index_(MPIABI_Fint *value_type, MPIABI_Fint *index_type, MPIABI_Fint *pair_type, MPIABI_Fint *ierror) { (*mpiabi_type_get_value_index_ptr)(value_type, index_type, pair_type, ierror); }

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

void mpi_comm_compare_(MPIABI_Fint *comm1, MPIABI_Fint *comm2, MPIABI_Fint *result, MPIABI_Fint *ierror) { (*mpiabi_comm_compare_ptr)(comm1, comm2, result, ierror); }

void mpi_comm_create_(MPIABI_Fint *comm, MPIABI_Fint *group, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_create_ptr)(comm, group, newcomm, ierror); }

void mpi_comm_create_from_group_(MPIABI_Fint *group, const char *stringtag, MPIABI_Fint *info, MPI_Fint *errhandler, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_create_from_group_ptr)(group, stringtag, info, errhandler, newcomm, ierror); }

void mpi_comm_create_group_(MPIABI_Fint *comm, MPIABI_Fint *group, MPIABI_Fint *tag, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_create_group_ptr)(comm, group, tag, newcomm, ierror); }

void mpi_comm_create_keyval_(void (*comm_copy_attr_fn)(void), void (*comm_delete_attr_fn)(void), MPIABI_Fint *comm_keyval, void *extra_state, MPIABI_Fint *ierror) { (*mpiabi_comm_create_keyval_ptr)(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierror); }

void mpi_comm_delete_attr_(MPIABI_Fint *comm, MPIABI_Fint *comm_keyval, MPIABI_Fint *ierror) { (*mpiabi_comm_delete_attr_ptr)(comm, comm_keyval, ierror); }

void mpi_comm_dup_(MPIABI_Fint *comm, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_dup_ptr)(comm, newcomm, ierror); }

void mpi_comm_dup_with_info_(MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_dup_with_info_ptr)(comm, info, newcomm, ierror); }

void mpi_comm_free_(MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_comm_free_ptr)(comm, ierror); }

void mpi_comm_get_name_(MPIABI_Fint *comm, char *comm_name, MPIABI_Fint *resultlen, MPIABI_Fint *ierror) { (*mpiabi_comm_get_name_ptr)(comm, comm_name, resultlen, ierror); }

void mpi_comm_free_keyval_(MPIABI_Fint *comm_keyval, MPIABI_Fint *ierror) { (*mpiabi_comm_free_keyval_ptr)(comm_keyval, ierror); }

void mpi_comm_get_attr_(MPIABI_Fint *comm, MPIABI_Fint *comm_keyval, void *attribute_val, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_comm_get_attr_ptr)(comm, comm_keyval, attribute_val, flag, ierror); }

void mpi_comm_get_info_(MPIABI_Fint *comm, MPIABI_Fint *info_used, MPIABI_Fint *ierror) { (*mpiabi_comm_get_info_ptr)(comm, info_used, ierror); }

void mpi_comm_group_(MPIABI_Fint *comm, MPIABI_Fint *group, MPIABI_Fint *ierror) { (*mpiabi_comm_group_ptr)(comm, group, ierror); }

void mpi_comm_idup_(MPIABI_Fint *comm, MPIABI_Fint *newcomm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_comm_idup_ptr)(comm, newcomm, request, ierror); }

void mpi_comm_idup_with_info_(MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *newcomm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_comm_idup_with_info_ptr)(comm, info, newcomm, request, ierror); }

void mpi_comm_rank_(MPIABI_Fint *comm, MPIABI_Fint *rank, MPIABI_Fint *ierror) { (*mpiabi_comm_rank_ptr)(comm, rank, ierror); }

void mpi_comm_remote_group_(MPIABI_Fint *comm, MPIABI_Fint *group, MPIABI_Fint *ierror) { (*mpiabi_comm_remote_group_ptr)(comm, group, ierror); }

void mpi_comm_remote_size_(MPIABI_Fint *comm, MPIABI_Fint *size, MPIABI_Fint *ierror) { (*mpiabi_comm_remote_size_ptr)(comm, size, ierror); }

void mpi_comm_set_attr_(MPIABI_Fint *comm, MPIABI_Fint *comm_keyval, void *attribute_val, MPIABI_Fint *ierror) { (*mpiabi_comm_set_attr_ptr)(comm, comm_keyval, attribute_val, ierror); }

void mpi_comm_set_info_(MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_comm_set_info_ptr)(comm, info, ierror); }

void mpi_comm_set_name_(MPIABI_Fint *comm, const char *comm_name, MPIABI_Fint *ierror) { (*mpiabi_comm_set_name_ptr)(comm, comm_name, ierror); }

void mpi_comm_size_(MPIABI_Fint *comm, MPIABI_Fint *size, MPIABI_Fint *ierror) { (*mpiabi_comm_size_ptr)(comm, size, ierror); }

void mpi_comm_split_(MPIABI_Fint *comm, MPIABI_Fint *color, MPIABI_Fint *key, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_split_ptr)(comm, color, key, newcomm, ierror); }

void mpi_group_free_(MPIABI_Fint *group, MPIABI_Fint *ierror) { (*mpiabi_group_free_ptr)(group, ierror); }

void mpi_comm_split_type_(MPIABI_Fint *comm, MPIABI_Fint *split_type, MPIABI_Fint *key, MPIABI_Fint *info, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_split_type_ptr)(comm, split_type, key, info, newcomm, ierror); }

void mpi_comm_test_inter_(MPIABI_Fint *comm, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_comm_test_inter_ptr)(comm, flag, ierror); }

void mpi_group_compare_(MPIABI_Fint *group1, MPIABI_Fint *group2, MPIABI_Fint *result, MPIABI_Fint *ierror) { (*mpiabi_group_compare_ptr)(group1, group2, result, ierror); }

void mpi_group_difference_(MPIABI_Fint *group1, MPIABI_Fint *group2, MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_difference_ptr)(group1, group2, newgroup, ierror); }

void mpi_group_excl_(MPIABI_Fint *group, MPIABI_Fint *n, const MPIABI_Fint *ranks[], MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_excl_ptr)(group, n, ranks, newgroup, ierror); }

void mpi_group_from_session_pset_(MPIABI_Fint *session, const char *pset_name, MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_from_session_pset_ptr)(session, pset_name, newgroup, ierror); }

void mpi_group_incl_(MPIABI_Fint *group, MPIABI_Fint *n, const MPIABI_Fint *ranks[], MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_incl_ptr)(group, n, ranks, newgroup, ierror); }

void mpi_group_intersection_(MPIABI_Fint *group1, MPIABI_Fint *group2, MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_intersection_ptr)(group1, group2, newgroup, ierror); }

void mpi_group_range_excl_(MPIABI_Fint *group, MPIABI_Fint *n, MPIABI_Fint *ranges[][3], MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_range_excl_ptr)(group, n, ranges, newgroup, ierror); }

void mpi_group_range_incl_(MPIABI_Fint *group, MPIABI_Fint *n, MPIABI_Fint *ranges[][3], MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_range_incl_ptr)(group, n, ranges, newgroup, ierror); }

void mpi_group_rank_(MPIABI_Fint *group, MPIABI_Fint *rank, MPIABI_Fint *ierror) { (*mpiabi_group_rank_ptr)(group, rank, ierror); }

void mpi_group_size_(MPIABI_Fint *group, MPIABI_Fint *size, MPIABI_Fint *ierror) { (*mpiabi_group_size_ptr)(group, size, ierror); }

void mpi_group_translate_ranks_(MPIABI_Fint *group1, MPIABI_Fint *n, const MPIABI_Fint *ranks1[], MPIABI_Fint *group2, MPIABI_Fint *ranks2[], MPIABI_Fint *ierror) { (*mpiabi_group_translate_ranks_ptr)(group1, n, ranks1, group2, ranks2, ierror); }

void mpi_group_union_(MPIABI_Fint *group1, MPIABI_Fint *group2, MPIABI_Fint *newgroup, MPIABI_Fint *ierror) { (*mpiabi_group_union_ptr)(group1, group2, newgroup, ierror); }

void mpi_intercomm_create_(MPIABI_Fint *local_comm, MPIABI_Fint *local_leader, MPIABI_Fint *peer_comm, MPIABI_Fint *remote_leader, MPIABI_Fint *tag, MPIABI_Fint *newintercomm, MPIABI_Fint *ierror) { (*mpiabi_intercomm_create_ptr)(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierror); }

void mpi_intercomm_create_from_groups_( MPIABI_Fint *local_group, MPIABI_Fint *local_leader, MPIABI_Fint *remote_group, MPIABI_Fint *remote_leader, const char *stringtag, MPIABI_Fint *info, MPI_Fint *errhandler, MPIABI_Fint *newintercomm, MPIABI_Fint *ierror) { (*mpiabi_intercomm_create_from_groups_ptr)( local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler, newintercomm, ierror); }

void mpi_intercomm_merge_(MPIABI_Fint *intercomm, MPIABI_Fint *high, MPIABI_Fint *newintracomm, MPIABI_Fint *ierror) { (*mpiabi_intercomm_merge_ptr)(intercomm, high, newintracomm, ierror); }

void mpi_type_create_keyval_(void (*type_copy_attr_fn)(void), void (*type_delete_attr_fn)(void), MPIABI_Fint *type_keyval, void *extra_state, MPIABI_Fint *ierror) { (*mpiabi_type_create_keyval_ptr)(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierror); }

void mpi_type_delete_attr_(MPIABI_Fint *datatype, MPIABI_Fint *type_keyval, MPIABI_Fint *ierror) { (*mpiabi_type_delete_attr_ptr)(datatype, type_keyval, ierror); }

void mpi_type_free_keyval_(MPIABI_Fint *type_keyval, MPIABI_Fint *ierror) { (*mpiabi_type_free_keyval_ptr)(type_keyval, ierror); }

void mpi_type_get_attr_(MPIABI_Fint *datatype, MPIABI_Fint *type_keyval, void *attribute_val, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_type_get_attr_ptr)(datatype, type_keyval, attribute_val, flag, ierror); }

void mpi_type_get_name_(MPIABI_Fint *datatype, char *type_name, MPIABI_Fint *resultlen, MPIABI_Fint *ierror) { (*mpiabi_type_get_name_ptr)(datatype, type_name, resultlen, ierror); }

void mpi_type_set_attr_(MPIABI_Fint *datatype, MPIABI_Fint *type_keyval, void *attribute_val, MPIABI_Fint *ierror) { (*mpiabi_type_set_attr_ptr)(datatype, type_keyval, attribute_val, ierror); }

void mpi_type_set_name_(MPIABI_Fint *datatype, const char *type_name, MPIABI_Fint *ierror) { (*mpiabi_type_set_name_ptr)(datatype, type_name, ierror); }

void mpi_win_create_keyval_(void (*win_copy_attr_fn)(void), void (*win_delete_attr_fn)(void), MPIABI_Fint *win_keyval, void *extra_state, MPIABI_Fint *ierror) { (*mpiabi_win_create_keyval_ptr)(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierror); }

void mpi_win_delete_attr_(MPIABI_Fint *win, MPIABI_Fint *win_keyval, MPIABI_Fint *ierror) { (*mpiabi_win_delete_attr_ptr)(win, win_keyval, ierror); }

void mpi_win_free_keyval_(MPIABI_Fint *win_keyval, MPIABI_Fint *ierror) { (*mpiabi_win_free_keyval_ptr)(win_keyval, ierror); }

void mpi_win_get_attr_(MPIABI_Fint *win, MPIABI_Fint *win_keyval, void *attribute_val, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_win_get_attr_ptr)(win, win_keyval, attribute_val, flag, ierror); }

void mpi_win_get_name_(MPIABI_Fint *win, char *win_name, MPIABI_Fint *resultlen, MPIABI_Fint *ierror) { (*mpiabi_win_get_name_ptr)(win, win_name, resultlen, ierror); }

void mpi_win_set_attr_(MPIABI_Fint *win, MPIABI_Fint *win_keyval, void *attribute_val, MPIABI_Fint *ierror) { (*mpiabi_win_set_attr_ptr)(win, win_keyval, attribute_val, ierror); }

void mpi_win_set_name_(MPIABI_Fint *win, const char *win_name, MPIABI_Fint *ierror) { (*mpiabi_win_set_name_ptr)(win, win_name, ierror); }

// A.3.6 Virtual Topologies for MPI Processes C Bindings

void mpi_cart_coords_(MPIABI_Fint *comm, MPIABI_Fint *rank, MPIABI_Fint *maxdims, MPIABI_Fint *coords[], MPIABI_Fint *ierror) { (*mpiabi_cart_coords_ptr)(comm, rank, maxdims, coords, ierror); }

void mpi_cart_create_(MPIABI_Fint *comm_old, MPIABI_Fint *ndims, const MPIABI_Fint *dims[], const MPIABI_Fint *periods[], MPIABI_Fint *reorder, MPIABI_Fint *comm_cart, MPIABI_Fint *ierror) { (*mpiabi_cart_create_ptr)(comm_old, ndims, dims, periods, reorder, comm_cart, ierror); }

void mpi_cart_get_(MPIABI_Fint *comm, MPIABI_Fint *maxdims, MPIABI_Fint *dims[], MPIABI_Fint *periods[], MPIABI_Fint *coords[], MPIABI_Fint *ierror) { (*mpiabi_cart_get_ptr)(comm, maxdims, dims, periods, coords, ierror); }

void mpi_cart_map_(MPIABI_Fint *comm, MPIABI_Fint *ndims, const MPIABI_Fint *dims[], const MPIABI_Fint *periods[], MPIABI_Fint *newrank, MPIABI_Fint *ierror) { (*mpiabi_cart_map_ptr)(comm, ndims, dims, periods, newrank, ierror); }

void mpi_cart_rank_(MPIABI_Fint *comm, const MPIABI_Fint *coords[], MPIABI_Fint *rank, MPIABI_Fint *ierror) { (*mpiabi_cart_rank_ptr)(comm, coords, rank, ierror); }

void mpi_cart_shift_(MPIABI_Fint *comm, MPIABI_Fint *direction, MPIABI_Fint *disp, MPIABI_Fint *rank_source, MPIABI_Fint *rank_dest, MPIABI_Fint *ierror) { (*mpiabi_cart_shift_ptr)(comm, direction, disp, rank_source, rank_dest, ierror); }

void mpi_cart_sub_(MPIABI_Fint *comm, const MPIABI_Fint *remain_dims[], MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_cart_sub_ptr)(comm, remain_dims, newcomm, ierror); }

void mpi_cartdim_get_(MPIABI_Fint *comm, MPIABI_Fint *ndims, MPIABI_Fint *ierror) { (*mpiabi_cartdim_get_ptr)(comm, ndims, ierror); }

void mpi_dims_create_(MPIABI_Fint *nnodes, MPIABI_Fint *ndims, MPIABI_Fint *dims[], MPIABI_Fint *ierror) { (*mpiabi_dims_create_ptr)(nnodes, ndims, dims, ierror); }

void mpi_dist_graph_create_(MPIABI_Fint *comm_old, MPIABI_Fint *n, const MPIABI_Fint *sources[], const MPIABI_Fint *degrees[], const MPIABI_Fint *destinations[], const MPIABI_Fint *weights[], MPIABI_Fint *info, MPIABI_Fint *reorder, MPIABI_Fint *comm_dist_graph, MPIABI_Fint *ierror) { (*mpiabi_dist_graph_create_ptr)(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierror); }

void mpi_dist_graph_create_adjacent_( MPIABI_Fint *comm_old, MPIABI_Fint *indegree, const MPIABI_Fint *sources[], const MPIABI_Fint *sourceweights[], MPIABI_Fint *outdegree, const MPIABI_Fint *destinations[], const MPIABI_Fint *destweights[], MPIABI_Fint *info, MPIABI_Fint *reorder, MPIABI_Fint *comm_dist_graph, MPIABI_Fint *ierror) { (*mpiabi_dist_graph_create_adjacent_ptr)( comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierror); }

void mpi_dist_graph_neighbors_(MPIABI_Fint *comm, MPIABI_Fint *maxindegree, MPIABI_Fint *sources[], MPIABI_Fint *sourceweights[], MPIABI_Fint *maxoutdegree, MPIABI_Fint *destinations[], MPIABI_Fint *destweights[], MPIABI_Fint *ierror) { (*mpiabi_dist_graph_neighbors_ptr)(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierror); }

void mpi_dist_graph_neighbors_count_(MPIABI_Fint *comm, MPIABI_Fint *indegree, MPIABI_Fint *outdegree, MPIABI_Fint *weighted, MPIABI_Fint *ierror) { (*mpiabi_dist_graph_neighbors_count_ptr)(comm, indegree, outdegree, weighted, ierror); }

void mpi_graph_create_(MPIABI_Fint *comm_old, MPIABI_Fint *nnodes, const MPIABI_Fint *index[], const MPIABI_Fint *edges[], MPIABI_Fint *reorder, MPIABI_Fint *comm_graph, MPIABI_Fint *ierror) { (*mpiabi_graph_create_ptr)(comm_old, nnodes, index, edges, reorder, comm_graph, ierror); }

void mpi_graph_get_(MPIABI_Fint *comm, MPIABI_Fint *maxindex, MPIABI_Fint *maxedges, MPIABI_Fint *index[], MPIABI_Fint *edges[], MPIABI_Fint *ierror) { (*mpiabi_graph_get_ptr)(comm, maxindex, maxedges, index, edges, ierror); }

void mpi_graph_map_(MPIABI_Fint *comm, MPIABI_Fint *nnodes, const MPIABI_Fint *index[], const MPIABI_Fint *edges[], MPIABI_Fint *newrank, MPIABI_Fint *ierror) { (*mpiabi_graph_map_ptr)(comm, nnodes, index, edges, newrank, ierror); }

void mpi_graph_neighbors_(MPIABI_Fint *comm, MPIABI_Fint *rank, MPIABI_Fint *maxneighbors, MPIABI_Fint *neighbors[], MPIABI_Fint *ierror) { (*mpiabi_graph_neighbors_ptr)(comm, rank, maxneighbors, neighbors, ierror); }

void mpi_graph_neighbors_count_(MPIABI_Fint *comm, MPIABI_Fint *rank, MPIABI_Fint *nneighbors, MPIABI_Fint *ierror) { (*mpiabi_graph_neighbors_count_ptr)(comm, rank, nneighbors, ierror); }

void mpi_graphdims_get_(MPIABI_Fint *comm, MPIABI_Fint *nnodes, MPIABI_Fint *nedges, MPIABI_Fint *ierror) { (*mpiabi_graphdims_get_ptr)(comm, nnodes, nedges, ierror); }

void mpi_ineighbor_allgather_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_allgather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

// void mpi_ineighbor_allgather_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_allgather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

void mpi_ineighbor_allgatherv_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_allgatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror); }

// void mpi_ineighbor_allgatherv_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_allgatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror); }

void mpi_ineighbor_alltoall_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_alltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

// void mpi_ineighbor_alltoall_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_alltoall_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror); }

void mpi_ineighbor_alltoallv_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_alltoallv_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror); }

// void mpi_ineighbor_alltoallv_c_(const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_alltoallv_c_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror); }

void mpi_ineighbor_alltoallw_(const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_alltoallw_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror); }

// void mpi_ineighbor_alltoallw_c_( const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_ineighbor_alltoallw_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror); }

void mpi_neighbor_allgather_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgather_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

// void mpi_neighbor_allgather_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgather_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

void mpi_neighbor_allgather_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgather_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

// void mpi_neighbor_allgather_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgather_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

void mpi_neighbor_allgatherv_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgatherv_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror); }

// void mpi_neighbor_allgatherv_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgatherv_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror); }

void mpi_neighbor_allgatherv_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgatherv_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror); }

// void mpi_neighbor_allgatherv_init_c_( const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *displs[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_allgatherv_init_c_ptr)( sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror); }

void mpi_neighbor_alltoall_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoall_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

// void mpi_neighbor_alltoall_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoall_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror); }

void mpi_neighbor_alltoall_init_(const void *sendbuf, MPIABI_Fint *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Fint *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoall_init_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

// void mpi_neighbor_alltoall_init_c_(const void *sendbuf, MPIABI_Count *sendcount, MPIABI_Fint *sendtype, void *recvbuf, MPIABI_Count *recvcount, MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoall_init_c_ptr)(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror); }

void mpi_neighbor_alltoallv_( const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallv_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror); }

// void mpi_neighbor_alltoallv_c_( const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallv_c_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror); }

void mpi_neighbor_alltoallv_init_( const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Fint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Fint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallv_init_ptr)(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror); }

// void mpi_neighbor_alltoallv_init_c_( const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], MPIABI_Fint *sendtype, void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], MPIABI_Fint *recvtype, MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallv_init_c_ptr)( sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror); }

void mpi_neighbor_alltoallw_( const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallw_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror); }

// void mpi_neighbor_alltoallw_c_( const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallw_c_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror); }

void mpi_neighbor_alltoallw_init_( const void *sendbuf, const MPIABI_Fint *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Fint *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallw_init_ptr)(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror); }

// void mpi_neighbor_alltoallw_init_c_( const void *sendbuf, const MPIABI_Count *sendcounts[], const MPIABI_Aint *sdispls[], const MPIABI_Fint *sendtypes[], void *recvbuf, const MPIABI_Count *recvcounts[], const MPIABI_Aint *rdispls[], const MPIABI_Fint *recvtypes[], MPIABI_Fint *comm, MPIABI_Fint *info, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_neighbor_alltoallw_init_c_ptr)( sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror); }

void mpi_topo_test_(MPIABI_Fint *comm, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_topo_test_ptr)(comm, status, ierror); }

// A.3.7 MPI Environmental Management C Bindings

void mpi_add_error_class_(MPIABI_Fint *errorclass, MPIABI_Fint *ierror) { (*mpiabi_add_error_class_ptr)(errorclass, ierror); }

void mpi_add_error_code_(MPIABI_Fint *errorclass, MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_add_error_code_ptr)(errorclass, errorcode, ierror); }

void mpi_add_error_string_(MPIABI_Fint *errorcode, const char *string, MPIABI_Fint *ierror) { (*mpiabi_add_error_string_ptr)(errorcode, string, ierror); }

void mpi_alloc_mem_(MPIABI_Aint *size, MPIABI_Fint *info, void *baseptr, MPIABI_Fint *ierror) { (*mpiabi_alloc_mem_ptr)(size, info, baseptr, ierror); }

void mpi_comm_call_errhandler_(MPIABI_Fint *comm, MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_comm_call_errhandler_ptr)(comm, errorcode, ierror); }

void mpi_comm_create_errhandler_(void (*comm_errhandler_fn)(void), MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_comm_create_errhandler_ptr)(comm_errhandler_fn, errhandler, ierror); }

void mpi_comm_get_errhandler_(MPIABI_Fint *comm, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_comm_get_errhandler_ptr)(comm, errhandler, ierror); }

void mpi_comm_set_errhandler_(MPIABI_Fint *comm, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_comm_set_errhandler_ptr)(comm, errhandler, ierror); }

void mpi_errhandler_free_(MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_errhandler_free_ptr)(errhandler, ierror); }

void mpi_error_class_(MPIABI_Fint *errorcode, MPIABI_Fint *errorclass, MPIABI_Fint *ierror) { (*mpiabi_error_class_ptr)(errorcode, errorclass, ierror); }

void mpi_error_string_(MPIABI_Fint *errorcode, char *string, MPIABI_Fint *resultlen, MPIABI_Fint *ierror) { (*mpiabi_error_string_ptr)(errorcode, string, resultlen, ierror); }

void mpi_file_call_errhandler_(MPIABI_Fint *fh, MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_file_call_errhandler_ptr)(fh, errorcode, ierror); }

void mpi_file_create_errhandler_(void (*file_errhandler_fn)(void), MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_file_create_errhandler_ptr)(file_errhandler_fn, errhandler, ierror); }

void mpi_file_get_errhandler_(MPIABI_Fint *file, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_file_get_errhandler_ptr)(file, errhandler, ierror); }

void mpi_file_set_errhandler_(MPIABI_Fint *file, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_file_set_errhandler_ptr)(file, errhandler, ierror); }

void mpi_free_mem_(void *base, MPIABI_Fint *ierror) { (*mpiabi_free_mem_ptr)(base, ierror); }

void mpi_get_hw_resource_info_(MPIABI_Fint *hw_info, MPIABI_Fint *ierror) { (*mpiabi_get_hw_resource_info_ptr)(hw_info, ierror); }

void mpi_get_library_version_(char *version, MPIABI_Fint *resultlen, MPIABI_Fint *ierror) { (*mpiabi_get_library_version_ptr)(version, resultlen, ierror); }

void mpi_get_processor_name_(char *name, MPIABI_Fint *resultlen, MPIABI_Fint *ierror) { (*mpiabi_get_processor_name_ptr)(name, resultlen, ierror); }

void mpi_get_version_(MPIABI_Fint *version, MPIABI_Fint *subversion, MPIABI_Fint *ierror) { (*mpiabi_get_version_ptr)(version, subversion, ierror); }

void mpi_remove_error_class_(MPIABI_Fint *errorclass, MPIABI_Fint *ierror) { (*mpiabi_remove_error_class_ptr)(errorclass, ierror); }

void mpi_remove_error_code_(MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_remove_error_code_ptr)(errorcode, ierror); }

void mpi_remove_error_string_(MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_remove_error_string_ptr)(errorcode, ierror); }

void mpi_session_call_errhandler_(MPIABI_Fint *session, MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_session_call_errhandler_ptr)(session, errorcode, ierror); }

void mpi_session_create_errhandler_(void (*session_errhandler_fn)(void), MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_session_create_errhandler_ptr)(session_errhandler_fn, errhandler, ierror); }

void mpi_session_get_errhandler_(MPIABI_Fint *session, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_session_get_errhandler_ptr)(session, errhandler, ierror); }

void mpi_session_set_errhandler_(MPIABI_Fint *session, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_session_set_errhandler_ptr)(session, errhandler, ierror); }

void mpi_win_call_errhandler_(MPIABI_Fint *win, MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_win_call_errhandler_ptr)(win, errorcode, ierror); }

void mpi_win_create_errhandler_(void (*win_errhandler_fn)(void), MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_win_create_errhandler_ptr)(win_errhandler_fn, errhandler, ierror); }

void mpi_win_get_errhandler_(MPIABI_Fint *win, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_win_get_errhandler_ptr)(win, errhandler, ierror); }

void mpi_win_set_errhandler_(MPIABI_Fint *win, MPI_Fint *errhandler, MPIABI_Fint *ierror) { (*mpiabi_win_set_errhandler_ptr)(win, errhandler, ierror); }

double mpi_wtick_(void) { return (*mpiabi_wtick_ptr)(); }

double mpi_wtime_(void) { return (*mpiabi_wtime_ptr)(); }

// A.3.8 The Info Object C Bindings

void mpi_info_create_(MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_info_create_ptr)(info, ierror); }

void mpi_info_create_env_(MPIABI_Fint *argc, char *argv[], MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_info_create_env_ptr)(argc, argv, info, ierror); }

void mpi_info_delete_(MPIABI_Fint *info, const char *key, MPIABI_Fint *ierror) { (*mpiabi_info_delete_ptr)(info, key, ierror); }

void mpi_info_dup_(MPIABI_Fint *info, MPIABI_Fint *newinfo, MPIABI_Fint *ierror) { (*mpiabi_info_dup_ptr)(info, newinfo, ierror); }

void mpi_info_free_(MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_info_free_ptr)(info, ierror); }

void mpi_info_get_nkeys_(MPIABI_Fint *info, MPIABI_Fint *nkeys, MPIABI_Fint *ierror) { (*mpiabi_info_get_nkeys_ptr)(info, nkeys, ierror); }

void mpi_info_get_nthkey_(MPIABI_Fint *info, MPIABI_Fint *n, char *key, MPIABI_Fint *ierror) { (*mpiabi_info_get_nthkey_ptr)(info, n, key, ierror); }

void mpi_info_get_string_(MPIABI_Fint *info, const char *key, MPIABI_Fint *buflen, char *value, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_info_get_string_ptr)(info, key, buflen, value, flag, ierror); }

void mpi_info_set_(MPIABI_Fint *info, const char *key, const char *value, MPIABI_Fint *ierror) { (*mpiabi_info_set_ptr)(info, key, value, ierror); }

// A.3.9 Process Creation and Management C Bindings

void mpi_abort_(MPIABI_Fint *comm, MPIABI_Fint *errorcode, MPIABI_Fint *ierror) { (*mpiabi_abort_ptr)(comm, errorcode, ierror); }

void mpi_close_port_(const char *port_name, MPIABI_Fint *ierror) { (*mpiabi_close_port_ptr)(port_name, ierror); }

void mpi_comm_accept_(const char *port_name, MPIABI_Fint *info, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_accept_ptr)(port_name, info, root, comm, newcomm, ierror); }

void mpi_comm_connect_(const char *port_name, MPIABI_Fint *info, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *newcomm, MPIABI_Fint *ierror) { (*mpiabi_comm_connect_ptr)(port_name, info, root, comm, newcomm, ierror); }

void mpi_comm_disconnect_(MPIABI_Fint *comm, MPIABI_Fint *ierror) { (*mpiabi_comm_disconnect_ptr)(comm, ierror); }

void mpi_comm_get_parent_(MPIABI_Fint *parent, MPIABI_Fint *ierror) { (*mpiabi_comm_get_parent_ptr)(parent, ierror); }

void mpi_comm_join_(MPIABI_Fint *fd, MPIABI_Fint *intercomm, MPIABI_Fint *ierror) { (*mpiabi_comm_join_ptr)(fd, intercomm, ierror); }

void mpi_comm_spawn_(const char *command, char *argv[], MPIABI_Fint *maxprocs, MPIABI_Fint *info, MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *intercomm, MPIABI_Fint *array_of_errcodes[], MPIABI_Fint *ierror) { (*mpiabi_comm_spawn_ptr)(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierror); }

void mpi_comm_spawn_multiple_( MPIABI_Fint *count, char *array_of_commands[], char *array_of_argv[], const MPIABI_Fint *array_of_maxprocs[], const MPIABI_Fint *array_of_info[], MPIABI_Fint *root, MPIABI_Fint *comm, MPIABI_Fint *intercomm, MPIABI_Fint *array_of_errcodes[], MPIABI_Fint *ierror) { (*mpiabi_comm_spawn_multiple_ptr)(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierror); }

void mpi_finalize_(MPIABI_Fint *ierror) { (*mpiabi_finalize_ptr)(ierror); }

void mpi_finalized_(MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_finalized_ptr)(flag, ierror); }

void mpi_init_(MPIABI_Fint *ierror) { (*mpiabi_init_ptr)(ierror); }

void mpi_init_thread_(MPIABI_Fint *required, MPIABI_Fint *provided, MPIABI_Fint *ierror) { (*mpiabi_init_thread_ptr)(required, provided, ierror); }

void mpi_initialized_(MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_initialized_ptr)(flag, ierror); }

void mpi_is_thread_main_(MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_is_thread_main_ptr)(flag, ierror); }

void mpi_lookup_name_(const char *service_name, MPIABI_Fint *info, char *port_name, MPIABI_Fint *ierror) { (*mpiabi_lookup_name_ptr)(service_name, info, port_name, ierror); }

void mpi_open_port_(MPIABI_Fint *info, char *port_name, MPIABI_Fint *ierror) { (*mpiabi_open_port_ptr)(info, port_name, ierror); }

void mpi_publish_name_(const char *service_name, MPIABI_Fint *info, const char *port_name, MPIABI_Fint *ierror) { (*mpiabi_publish_name_ptr)(service_name, info, port_name, ierror); }

void mpi_query_thread_(MPIABI_Fint *provided, MPIABI_Fint *ierror) { (*mpiabi_query_thread_ptr)(provided, ierror); }

void mpi_session_finalize_(MPIABI_Fint *session, MPIABI_Fint *ierror) { (*mpiabi_session_finalize_ptr)(session, ierror); }

void mpi_session_get_info_(MPIABI_Fint *session, MPIABI_Fint *info_used, MPIABI_Fint *ierror) { (*mpiabi_session_get_info_ptr)(session, info_used, ierror); }

void mpi_session_get_nth_pset_(MPIABI_Fint *session, MPIABI_Fint *info, MPIABI_Fint *n, MPIABI_Fint *pset_len, char *pset_name, MPIABI_Fint *ierror) { (*mpiabi_session_get_nth_pset_ptr)(session, info, n, pset_len, pset_name, ierror); }

void mpi_session_get_num_psets_(MPIABI_Fint *session, MPIABI_Fint *info, MPIABI_Fint *npset_names, MPIABI_Fint *ierror) { (*mpiabi_session_get_num_psets_ptr)(session, info, npset_names, ierror); }

void mpi_session_get_pset_info_(MPIABI_Fint *session, const char *pset_name, MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_session_get_pset_info_ptr)(session, pset_name, info, ierror); }

void mpi_session_init_(MPIABI_Fint *info, MPI_Fint *errhandler, MPIABI_Fint *session, MPIABI_Fint *ierror) { (*mpiabi_session_init_ptr)(info, errhandler, session, ierror); }

void mpi_unpublish_name_(const char *service_name, MPIABI_Fint *info, const char *port_name, MPIABI_Fint *ierror) { (*mpiabi_unpublish_name_ptr)(service_name, info, port_name, ierror); }

// A.3.10 One-Sided Communications C Bindings

void mpi_accumulate_(const void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_accumulate_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierror); }

// void mpi_accumulate_c_(const void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_accumulate_c_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierror); }

void mpi_compare_and_swap_(const void *origin_addr, const void *compare_addr, void *result_addr, MPIABI_Fint *datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_compare_and_swap_ptr)(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win, ierror); }

void mpi_fetch_and_op_(const void *origin_addr, void *result_addr, MPIABI_Fint *datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_fetch_and_op_ptr)(origin_addr, result_addr, datatype, target_rank, target_disp, op, win, ierror); }

void mpi_get_(void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_get_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierror); }

void mpi_get_accumulate_(const void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, void *result_addr, MPIABI_Fint *result_count, MPIABI_Fint *result_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_get_accumulate_ptr)(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierror); }

// void mpi_get_accumulate_c_(const void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, void *result_addr, MPIABI_Count *result_count, MPIABI_Fint *result_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_get_accumulate_c_ptr)(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, ierror); }

// void mpi_get_c_(void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_get_c_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierror); }

void mpi_put_(const void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_put_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierror); }

// void mpi_put_c_(const void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_put_c_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, ierror); }

void mpi_raccumulate_(const void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_raccumulate_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror); }

// void mpi_raccumulate_c_(const void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_raccumulate_c_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror); }

void mpi_rget_(void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_rget_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror); }

void mpi_rget_accumulate_(const void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, void *result_addr, MPIABI_Fint *result_count, MPIABI_Fint *result_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_rget_accumulate_ptr)(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror); }

// void mpi_rget_accumulate_c_(const void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, void *result_addr, MPIABI_Count *result_count, MPIABI_Fint *result_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *op, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_rget_accumulate_c_ptr)(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror); }

// void mpi_rget_c_(void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_rget_c_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror); }

void mpi_rput_(const void *origin_addr, MPIABI_Fint *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Fint *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_rput_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror); }

// void mpi_rput_c_(const void *origin_addr, MPIABI_Count *origin_count, MPIABI_Fint *origin_datatype, MPIABI_Fint *target_rank, MPIABI_Aint *target_disp, MPIABI_Count *target_count, MPIABI_Fint *target_datatype, MPIABI_Fint *win, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_rput_c_ptr)(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror); }

void mpi_win_allocate_(MPIABI_Aint *size, MPIABI_Fint *disp_unit, MPIABI_Fint *info, MPIABI_Fint *comm, void *baseptr, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_allocate_ptr)(size, disp_unit, info, comm, baseptr, win, ierror); }

// void mpi_win_allocate_c_(MPIABI_Aint *size, MPIABI_Aint *disp_unit, MPIABI_Fint *info, MPIABI_Fint *comm, void *baseptr, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_allocate_c_ptr)(size, disp_unit, info, comm, baseptr, win, ierror); }

void mpi_win_allocate_shared_(MPIABI_Aint *size, MPIABI_Fint *disp_unit, MPIABI_Fint *info, MPIABI_Fint *comm, void *baseptr, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_allocate_shared_ptr)(size, disp_unit, info, comm, baseptr, win, ierror); }

// void mpi_win_allocate_shared_c_(MPIABI_Aint *size, MPIABI_Aint *disp_unit, MPIABI_Fint *info, MPIABI_Fint *comm, void *baseptr, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_allocate_shared_c_ptr)(size, disp_unit, info, comm, baseptr, win, ierror); }

void mpi_win_attach_(MPIABI_Fint *win, void *base, MPIABI_Aint *size, MPIABI_Fint *ierror) { (*mpiabi_win_attach_ptr)(win, base, size, ierror); }

void mpi_win_complete_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_complete_ptr)(win, ierror); }

void mpi_win_create_(void *base, MPIABI_Aint *size, MPIABI_Fint *disp_unit, MPIABI_Fint *info, MPIABI_Fint *comm, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_create_ptr)(base, size, disp_unit, info, comm, win, ierror); }

// void mpi_win_create_c_(void *base, MPIABI_Aint *size, MPIABI_Aint *disp_unit, MPIABI_Fint *info, MPIABI_Fint *comm, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_create_c_ptr)(base, size, disp_unit, info, comm, win, ierror); }

void mpi_win_create_dynamic_(MPIABI_Fint *info, MPIABI_Fint *comm, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_create_dynamic_ptr)(info, comm, win, ierror); }

void mpi_win_detach_(MPIABI_Fint *win, const void *base, MPIABI_Fint *ierror) { (*mpiabi_win_detach_ptr)(win, base, ierror); }

void mpi_win_fence_(MPIABI_Fint *assert, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_fence_ptr)(assert, win, ierror); }

void mpi_win_flush_(MPIABI_Fint *rank, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_flush_ptr)(rank, win, ierror); }

void mpi_win_flush_all_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_flush_all_ptr)(win, ierror); }

void mpi_win_flush_local_(MPIABI_Fint *rank, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_flush_local_ptr)(rank, win, ierror); }

void mpi_win_flush_local_all_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_flush_local_all_ptr)(win, ierror); }

void mpi_win_free_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_free_ptr)(win, ierror); }

void mpi_win_get_group_(MPIABI_Fint *win, MPIABI_Fint *group, MPIABI_Fint *ierror) { (*mpiabi_win_get_group_ptr)(win, group, ierror); }

void mpi_win_get_info_(MPIABI_Fint *win, MPIABI_Fint *info_used, MPIABI_Fint *ierror) { (*mpiabi_win_get_info_ptr)(win, info_used, ierror); }

void mpi_win_lock_(MPIABI_Fint *lock_type, MPIABI_Fint *rank, MPIABI_Fint *assert, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_lock_ptr)(lock_type, rank, assert, win, ierror); }

void mpi_win_lock_all_(MPIABI_Fint *assert, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_lock_all_ptr)(assert, win, ierror); }

void mpi_win_post_(MPIABI_Fint *group, MPIABI_Fint *assert, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_post_ptr)(group, assert, win, ierror); }

void mpi_win_set_info_(MPIABI_Fint *win, MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_win_set_info_ptr)(win, info, ierror); }

void mpi_win_shared_query_(MPIABI_Fint *win, MPIABI_Fint *rank, MPIABI_Aint *size, MPIABI_Fint *disp_unit, void *baseptr, MPIABI_Fint *ierror) { (*mpiabi_win_shared_query_ptr)(win, rank, size, disp_unit, baseptr, ierror); }

// void mpi_win_shared_query_c_(MPIABI_Fint *win, MPIABI_Fint *rank, MPIABI_Aint *size, MPIABI_Aint *disp_unit, void *baseptr, MPIABI_Fint *ierror) { (*mpiabi_win_shared_query_c_ptr)(win, rank, size, disp_unit, baseptr, ierror); }

void mpi_win_start_(MPIABI_Fint *group, MPIABI_Fint *assert, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_start_ptr)(group, assert, win, ierror); }

void mpi_win_sync_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_sync_ptr)(win, ierror); }

void mpi_win_test_(MPIABI_Fint *win, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_win_test_ptr)(win, flag, ierror); }

void mpi_win_unlock_(MPIABI_Fint *rank, MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_unlock_ptr)(rank, win, ierror); }

void mpi_win_unlock_all_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_unlock_all_ptr)(win, ierror); }

void mpi_win_wait_(MPIABI_Fint *win, MPIABI_Fint *ierror) { (*mpiabi_win_wait_ptr)(win, ierror); }

// A.3.11 External Interfaces C Bindings

void mpi_grequest_complete_(MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_grequest_complete_ptr)(request, ierror); }

void mpi_grequest_start_(void (*query_fn)(void), void (*free_fn)(void), void (*cancel_fn)(void), void *extra_state, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_grequest_start_ptr)(query_fn, free_fn, cancel_fn, extra_state, request, ierror); }

void mpi_status_set_cancelled_(MPIABI_Fint *status, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_status_set_cancelled_ptr)(status, flag, ierror); }

void mpi_status_set_elements_(MPIABI_Fint *status, MPIABI_Fint *datatype, MPIABI_Fint *count, MPIABI_Fint *ierror) { (*mpiabi_status_set_elements_ptr)(status, datatype, count, ierror); }

// void mpi_status_set_elements_c_(MPIABI_Fint *status, MPIABI_Fint *datatype, MPIABI_Count *count, MPIABI_Fint *ierror) { (*mpiabi_status_set_elements_c_ptr)(status, datatype, count, ierror); }

void mpi_status_set_error_(MPIABI_Fint *status, MPIABI_Fint *err, MPIABI_Fint *ierror) { (*mpiabi_status_set_error_ptr)(status, err, ierror); }

void mpi_status_set_source_(MPIABI_Fint *status, MPIABI_Fint *source, MPIABI_Fint *ierror) { (*mpiabi_status_set_source_ptr)(status, source, ierror); }

void mpi_status_set_tag_(MPIABI_Fint *status, MPIABI_Fint *tag, MPIABI_Fint *ierror) { (*mpiabi_status_set_tag_ptr)(status, tag, ierror); }

// A.3.12 I/O C Bindings

void mpi_file_close_(MPIABI_Fint *fh, MPIABI_Fint *ierror) { (*mpiabi_file_close_ptr)(fh, ierror); }

void mpi_file_delete_(const char *filename, MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_file_delete_ptr)(filename, info, ierror); }

void mpi_file_get_amode_(MPIABI_Fint *fh, MPIABI_Fint *amode, MPIABI_Fint *ierror) { (*mpiabi_file_get_amode_ptr)(fh, amode, ierror); }

void mpi_file_get_atomicity_(MPIABI_Fint *fh, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_file_get_atomicity_ptr)(fh, flag, ierror); }

void mpi_file_get_byte_offset_(MPIABI_Fint *fh, MPIABI_Offset *offset, MPIABI_Offset *disp, MPIABI_Fint *ierror) { (*mpiabi_file_get_byte_offset_ptr)(fh, offset, disp, ierror); }

void mpi_file_get_group_(MPIABI_Fint *fh, MPIABI_Fint *group, MPIABI_Fint *ierror) { (*mpiabi_file_get_group_ptr)(fh, group, ierror); }

void mpi_file_get_info_(MPIABI_Fint *fh, MPIABI_Fint *info_used, MPIABI_Fint *ierror) { (*mpiabi_file_get_info_ptr)(fh, info_used, ierror); }

void mpi_file_get_position_(MPIABI_Fint *fh, MPIABI_Offset *offset, MPIABI_Fint *ierror) { (*mpiabi_file_get_position_ptr)(fh, offset, ierror); }

void mpi_file_get_position_shared_(MPIABI_Fint *fh, MPIABI_Offset *offset, MPIABI_Fint *ierror) { (*mpiabi_file_get_position_shared_ptr)(fh, offset, ierror); }

void mpi_file_get_size_(MPIABI_Fint *fh, MPIABI_Offset *size, MPIABI_Fint *ierror) { (*mpiabi_file_get_size_ptr)(fh, size, ierror); }

void mpi_file_get_type_extent_(MPIABI_Fint *fh, MPIABI_Fint *datatype, MPIABI_Aint *extent, MPIABI_Fint *ierror) { (*mpiabi_file_get_type_extent_ptr)(fh, datatype, extent, ierror); }

// void mpi_file_get_type_extent_c_(MPIABI_Fint *fh, MPIABI_Fint *datatype, MPIABI_Count *extent, MPIABI_Fint *ierror) { (*mpiabi_file_get_type_extent_c_ptr)(fh, datatype, extent, ierror); }

void mpi_file_get_view_(MPIABI_Fint *fh, MPIABI_Offset *disp, MPIABI_Fint *etype, MPIABI_Fint *filetype, char *datarep, MPIABI_Fint *ierror) { (*mpiabi_file_get_view_ptr)(fh, disp, etype, filetype, datarep, ierror); }

void mpi_file_iread_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iread_all_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_all_ptr)(fh, buf, count, datatype, request, ierror); }

// void mpi_file_iread_all_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_all_c_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iread_at_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_at_ptr)(fh, offset, buf, count, datatype, request, ierror); }

void mpi_file_iread_at_all_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_at_all_ptr)(fh, offset, buf, count, datatype, request, ierror); }

// void mpi_file_iread_at_all_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_at_all_c_ptr)(fh, offset, buf, count, datatype, request, ierror); }

// void mpi_file_iread_at_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_at_c_ptr)(fh, offset, buf, count, datatype, request, ierror); }

// void mpi_file_iread_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_c_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iread_shared_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_shared_ptr)(fh, buf, count, datatype, request, ierror); }

// void mpi_file_iread_shared_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iread_shared_c_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iwrite_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iwrite_all_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_all_ptr)(fh, buf, count, datatype, request, ierror); }

// void mpi_file_iwrite_all_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_all_c_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iwrite_at_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_at_ptr)(fh, offset, buf, count, datatype, request, ierror); }

void mpi_file_iwrite_at_all_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_at_all_ptr)(fh, offset, buf, count, datatype, request, ierror); }

// void mpi_file_iwrite_at_all_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_at_all_c_ptr)(fh, offset, buf, count, datatype, request, ierror); }

// void mpi_file_iwrite_at_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_at_c_ptr)(fh, offset, buf, count, datatype, request, ierror); }

// void mpi_file_iwrite_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_c_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_iwrite_shared_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_shared_ptr)(fh, buf, count, datatype, request, ierror); }

// void mpi_file_iwrite_shared_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *request, MPIABI_Fint *ierror) { (*mpiabi_file_iwrite_shared_c_ptr)(fh, buf, count, datatype, request, ierror); }

void mpi_file_open_(MPIABI_Fint *comm, const char *filename, MPIABI_Fint *amode, MPIABI_Fint *info, MPIABI_Fint *fh, MPIABI_Fint *ierror) { (*mpiabi_file_open_ptr)(comm, filename, amode, info, fh, ierror); }

void mpi_file_preallocate_(MPIABI_Fint *fh, MPIABI_Offset *size, MPIABI_Fint *ierror) { (*mpiabi_file_preallocate_ptr)(fh, size, ierror); }

void mpi_file_read_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_read_all_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_all_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_read_all_begin_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_read_all_begin_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_read_all_begin_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_read_all_begin_c_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_read_all_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_all_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_read_all_end_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_all_end_ptr)(fh, buf, status, ierror); }

void mpi_file_read_at_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_ptr)(fh, offset, buf, count, datatype, status, ierror); }

void mpi_file_read_at_all_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_all_ptr)(fh, offset, buf, count, datatype, status, ierror); }

void mpi_file_read_at_all_begin_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_all_begin_ptr)(fh, offset, buf, count, datatype, ierror); }

// void mpi_file_read_at_all_begin_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_all_begin_c_ptr)(fh, offset, buf, count, datatype, ierror); }

// void mpi_file_read_at_all_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_all_c_ptr)(fh, offset, buf, count, datatype, status, ierror); }

void mpi_file_read_at_all_end_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_all_end_ptr)(fh, buf, status, ierror); }

// void mpi_file_read_at_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_at_c_ptr)(fh, offset, buf, count, datatype, status, ierror); }

// void mpi_file_read_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_read_ordered_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_ordered_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_read_ordered_begin_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_read_ordered_begin_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_read_ordered_begin_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_read_ordered_begin_c_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_read_ordered_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_ordered_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_read_ordered_end_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_ordered_end_ptr)(fh, buf, status, ierror); }

void mpi_file_read_shared_(MPIABI_Fint *fh, void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_shared_ptr)(fh, buf, count, datatype, status, ierror); }

// void mpi_file_read_shared_c_(MPIABI_Fint *fh, void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_read_shared_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_seek_(MPIABI_Fint *fh, MPIABI_Offset *offset, MPIABI_Fint *whence, MPIABI_Fint *ierror) { (*mpiabi_file_seek_ptr)(fh, offset, whence, ierror); }

void mpi_file_seek_shared_(MPIABI_Fint *fh, MPIABI_Offset *offset, MPIABI_Fint *whence, MPIABI_Fint *ierror) { (*mpiabi_file_seek_shared_ptr)(fh, offset, whence, ierror); }

void mpi_file_set_atomicity_(MPIABI_Fint *fh, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_file_set_atomicity_ptr)(fh, flag, ierror); }

void mpi_file_set_info_(MPIABI_Fint *fh, MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_file_set_info_ptr)(fh, info, ierror); }

void mpi_file_set_size_(MPIABI_Fint *fh, MPIABI_Offset *size, MPIABI_Fint *ierror) { (*mpiabi_file_set_size_ptr)(fh, size, ierror); }

void mpi_file_set_view_(MPIABI_Fint *fh, MPIABI_Offset *disp, MPIABI_Fint *etype, MPIABI_Fint *filetype, const char *datarep, MPIABI_Fint *info, MPIABI_Fint *ierror) { (*mpiabi_file_set_view_ptr)(fh, disp, etype, filetype, datarep, info, ierror); }

void mpi_file_sync_(MPIABI_Fint *fh, MPIABI_Fint *ierror) { (*mpiabi_file_sync_ptr)(fh, ierror); }

void mpi_file_write_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_write_all_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_all_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_write_all_begin_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_write_all_begin_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_write_all_begin_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_write_all_begin_c_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_write_all_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_all_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_write_all_end_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_all_end_ptr)(fh, buf, status, ierror); }

void mpi_file_write_at_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_ptr)(fh, offset, buf, count, datatype, status, ierror); }

void mpi_file_write_at_all_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_all_ptr)(fh, offset, buf, count, datatype, status, ierror); }

void mpi_file_write_at_all_begin_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_all_begin_ptr)(fh, offset, buf, count, datatype, ierror); }

// void mpi_file_write_at_all_begin_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_all_begin_c_ptr)(fh, offset, buf, count, datatype, ierror); }

// void mpi_file_write_at_all_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_all_c_ptr)(fh, offset, buf, count, datatype, status, ierror); }

void mpi_file_write_at_all_end_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_all_end_ptr)(fh, buf, status, ierror); }

// void mpi_file_write_at_c_(MPIABI_Fint *fh, MPIABI_Offset *offset, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_at_c_ptr)(fh, offset, buf, count, datatype, status, ierror); }

// void mpi_file_write_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_write_ordered_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_ordered_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_write_ordered_begin_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_write_ordered_begin_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_write_ordered_begin_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *ierror) { (*mpiabi_file_write_ordered_begin_c_ptr)(fh, buf, count, datatype, ierror); }

// void mpi_file_write_ordered_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_ordered_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_file_write_ordered_end_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_ordered_end_ptr)(fh, buf, status, ierror); }

void mpi_file_write_shared_(MPIABI_Fint *fh, const void *buf, MPIABI_Fint *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_shared_ptr)(fh, buf, count, datatype, status, ierror); }

// void mpi_file_write_shared_c_(MPIABI_Fint *fh, const void *buf, MPIABI_Count *count, MPIABI_Fint *datatype, MPIABI_Fint *status, MPIABI_Fint *ierror) { (*mpiabi_file_write_shared_c_ptr)(fh, buf, count, datatype, status, ierror); }

void mpi_register_datarep_(const char *datarep, void (*read_conversion_fn)(void), void (*write_conversion_fn)(void), void (*dtype_file_extent_fn)(void), void *extra_state, MPIABI_Fint *ierror) { (*mpiabi_register_datarep_ptr)(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierror); }

// void mpi_register_datarep_c_(const char *datarep, void (*read_conversion_fn)(void), void (*write_conversion_fn)(void), void (*dtype_file_extent_fn)(void), void *extra_state, MPIABI_Fint *ierror) { (*mpiabi_register_datarep_c_ptr)(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierror); }

// A.3.13 Language Bindings C Bindings

// A.3.14 Tools / Profiling Interface C Bindings

void mpi_pcontrol_(const MPIABI_Fint *level, MPIABI_Fint *ierror) { (*mpiabi_pcontrol_ptr)(level, ierror); }

// A.3.15 Tools / MPI Tool Information Interface C Bindings

// A.3.16 Deprecated C Bindings

void mpi_attr_delete_(MPIABI_Fint *comm, MPIABI_Fint *keyval, MPIABI_Fint *ierror) { (*mpiabi_attr_delete_ptr)(comm, keyval, ierror); }

void mpi_attr_get_(MPIABI_Fint *comm, MPIABI_Fint *keyval, void *attribute_val, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_attr_get_ptr)(comm, keyval, attribute_val, flag, ierror); }

void mpi_attr_put_(MPIABI_Fint *comm, MPIABI_Fint *keyval, void *attribute_val, MPIABI_Fint *ierror) { (*mpiabi_attr_put_ptr)(comm, keyval, attribute_val, ierror); }

void mpi_get_elements_x_(const MPIABI_Fint *status, MPIABI_Fint *datatype, MPIABI_Count *count, MPIABI_Fint *ierror) { (*mpiabi_get_elements_x_ptr)(status, datatype, count, ierror); }

void mpi_info_get_(MPIABI_Fint *info, const char *key, MPIABI_Fint *valuelen, char *value, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_info_get_ptr)(info, key, valuelen, value, flag, ierror); }

void mpi_info_get_valuelen_(MPIABI_Fint *info, const char *key, MPIABI_Fint *valuelen, MPIABI_Fint *flag, MPIABI_Fint *ierror) { (*mpiabi_info_get_valuelen_ptr)(info, key, valuelen, flag, ierror); }

void mpi_keyval_create_(void (*copy_fn)(void), void (*delete_fn)(void), MPIABI_Fint *keyval, void *extra_state, MPIABI_Fint *ierror) { (*mpiabi_keyval_create_ptr)(copy_fn, delete_fn, keyval, extra_state, ierror); }

void mpi_keyval_free_(MPIABI_Fint *keyval, MPIABI_Fint *ierror) { (*mpiabi_keyval_free_ptr)(keyval, ierror); }

void mpi_status_set_elements_x_(MPIABI_Fint *status, MPIABI_Fint *datatype, MPIABI_Count *count, MPIABI_Fint *ierror) { (*mpiabi_status_set_elements_x_ptr)(status, datatype, count, ierror); }

void mpi_type_get_extent_x_(MPIABI_Fint *datatype, MPIABI_Count *lb, MPIABI_Count *extent, MPIABI_Fint *ierror) { (*mpiabi_type_get_extent_x_ptr)(datatype, lb, extent, ierror); }

void mpi_type_get_true_extent_x_(MPIABI_Fint *datatype, MPIABI_Count *true_lb, MPIABI_Count *true_extent, MPIABI_Fint *ierror) { (*mpiabi_type_get_true_extent_x_ptr)(datatype, true_lb, true_extent, ierror); }

void mpi_type_size_x_(MPIABI_Fint *datatype, MPIABI_Count *size, MPIABI_Fint *ierror) { (*mpiabi_type_size_x_ptr)(datatype, size, ierror); }

// Removed C Bindings

void mpi_address_(void *location, MPIABI_Aint *address, MPIABI_Fint *ierror) { (*mpiabi_address_ptr)(location, address, ierror); }

void mpi_type_hindexed_(MPIABI_Fint *count, MPIABI_Fint *array_of_blocklengths, MPIABI_Aint *array_of_displacements, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_hindexed_ptr)(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror); }

void mpi_type_hvector_(MPIABI_Fint *count, MPIABI_Fint *blocklength, MPIABI_Aint *stride, MPIABI_Fint *oldtype, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_hvector_ptr)(count, blocklength, stride, oldtype, newtype, ierror); }

void mpi_type_struct_(MPIABI_Fint *count, MPIABI_Fint *array_of_blocklengths, MPIABI_Aint *array_of_displacements, MPIABI_Fint *array_of_types, MPIABI_Fint *newtype, MPIABI_Fint *ierror) { (*mpiabi_type_struct_ptr)(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierror); }

void mpi_type_extent_(MPIABI_Fint *datatype, MPIABI_Aint *extent, MPIABI_Fint *ierror) { (*mpiabi_type_extent_ptr)(datatype, extent, ierror); }

void mpi_type_lb_(MPIABI_Fint *datatype, MPIABI_Aint *displacement, MPIABI_Fint *ierror) { (*mpiabi_type_lb_ptr)(datatype, displacement, ierror); }

void mpi_type_ub_(MPIABI_Fint *datatype, MPIABI_Aint *displacement, MPIABI_Fint *ierror) { (*mpiabi_type_ub_ptr)(datatype, displacement, ierror); }
