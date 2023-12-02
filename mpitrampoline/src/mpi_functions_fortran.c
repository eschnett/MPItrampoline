// MPI Fortran function wrappers

// This file has been generated automatically
// by `mpitrampoline/generate_trampoline.jl`.
// Do not modify this file, changes will be overwritten.

#include <mpi.h>
#include <mpiabi_function_pointers_fortran.h>

void mpi_bsend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_bsend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    ierror
  );
}

void mpi_bsend_init_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_bsend_init_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_buffer_attach_(
  void *buffer,
  const MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_buffer_attach_ptr)(
    buffer,
    size,
    ierror
  );
}

void mpi_buffer_detach_(
  MPI_Aint *buffer_addr,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_buffer_detach_ptr)(
    buffer_addr,
    size,
    ierror
  );
}

void mpi_buffer_flush_(
  MPI_Fint *ierror
) {
  return (*mpiabi_buffer_flush_ptr)(
    ierror
  );
}

void mpi_buffer_iflush_(
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_buffer_iflush_ptr)(
    request,
    ierror
  );
}

void mpi_cancel_(
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_cancel_ptr)(
    request,
    ierror
  );
}

void mpi_comm_attach_buffer_(
  const MPI_Fint *comm,
  const void *buffer,
  const MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_attach_buffer_ptr)(
    comm,
    buffer,
    size,
    ierror
  );
}

void mpi_comm_detach_buffer_(
  const MPI_Fint *comm,
  MPI_Aint *buffer_addr,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_detach_buffer_ptr)(
    comm,
    buffer_addr,
    size,
    ierror
  );
}

void mpi_comm_flush_buffer_(
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_flush_buffer_ptr)(
    comm,
    ierror
  );
}

void mpi_comm_iflush_buffer_(
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_iflush_buffer_ptr)(
    comm,
    request,
    ierror
  );
}

void mpi_get_count_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *datatype,
  MPI_Fint *count,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_count_ptr)(
    status,
    datatype,
    count,
    ierror
  );
}

void mpi_ibsend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ibsend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_improbe_(
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *flag,
  MPI_Fint *message,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_improbe_ptr)(
    source,
    tag,
    comm,
    flag,
    message,
    status,
    ierror
  );
}

void mpi_imrecv_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *message,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_imrecv_ptr)(
    buf,
    count,
    datatype,
    message,
    request,
    ierror
  );
}

void mpi_iprobe_(
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *flag,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_iprobe_ptr)(
    source,
    tag,
    comm,
    flag,
    status,
    ierror
  );
}

void mpi_irecv_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_irecv_ptr)(
    buf,
    count,
    datatype,
    source,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_irsend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_irsend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_isend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_isend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_isendrecv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  const MPI_Fint *dest,
  const MPI_Fint *sendtag,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *source,
  const MPI_Fint *recvtag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_isendrecv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    dest,
    sendtag,
    recvbuf,
    recvcount,
    recvtype,
    source,
    recvtag,
    comm,
    request,
    ierror
  );
}

void mpi_isendrecv_replace_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *sendtag,
  const MPI_Fint *source,
  const MPI_Fint *recvtag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_isendrecv_replace_ptr)(
    buf,
    count,
    datatype,
    dest,
    sendtag,
    source,
    recvtag,
    comm,
    request,
    ierror
  );
}

void mpi_issend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_issend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_mprobe_(
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *message,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_mprobe_ptr)(
    source,
    tag,
    comm,
    message,
    status,
    ierror
  );
}

void mpi_mrecv_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *message,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_mrecv_ptr)(
    buf,
    count,
    datatype,
    message,
    status,
    ierror
  );
}

void mpi_probe_(
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_probe_ptr)(
    source,
    tag,
    comm,
    status,
    ierror
  );
}

void mpi_recv_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_recv_ptr)(
    buf,
    count,
    datatype,
    source,
    tag,
    comm,
    status,
    ierror
  );
}

void mpi_recv_init_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_recv_init_ptr)(
    buf,
    count,
    datatype,
    source,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_request_free_(
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_request_free_ptr)(
    request,
    ierror
  );
}

void mpi_request_get_status_(
  const MPI_Fint *request,
  MPI_Fint *flag,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_request_get_status_ptr)(
    request,
    flag,
    status,
    ierror
  );
}

void mpi_request_get_status_all_(
  const MPI_Fint *count,
  const MPI_Fint *array_of_requests,
  MPI_Fint *flag,
  MPI_Fint *array_of_statuses[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_request_get_status_all_ptr)(
    count,
    array_of_requests,
    flag,
    array_of_statuses,
    ierror
  );
}

void mpi_request_get_status_any_(
  const MPI_Fint *count,
  const MPI_Fint *array_of_requests,
  MPI_Fint *index,
  MPI_Fint *flag,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_request_get_status_any_ptr)(
    count,
    array_of_requests,
    index,
    flag,
    status,
    ierror
  );
}

void mpi_request_get_status_some_(
  const MPI_Fint *incount,
  const MPI_Fint *array_of_requests,
  MPI_Fint *outcount,
  MPI_Fint *array_of_indices,
  MPI_Fint *array_of_statuses[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_request_get_status_some_ptr)(
    incount,
    array_of_requests,
    outcount,
    array_of_indices,
    array_of_statuses,
    ierror
  );
}

void mpi_rsend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_rsend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    ierror
  );
}

void mpi_rsend_init_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_rsend_init_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_send_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_send_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    ierror
  );
}

void mpi_send_init_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_send_init_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_sendrecv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  const MPI_Fint *dest,
  const MPI_Fint *sendtag,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *source,
  const MPI_Fint *recvtag,
  const MPI_Fint *comm,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_sendrecv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    dest,
    sendtag,
    recvbuf,
    recvcount,
    recvtype,
    source,
    recvtag,
    comm,
    status,
    ierror
  );
}

void mpi_sendrecv_replace_(
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *sendtag,
  const MPI_Fint *source,
  const MPI_Fint *recvtag,
  const MPI_Fint *comm,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_sendrecv_replace_ptr)(
    buf,
    count,
    datatype,
    dest,
    sendtag,
    source,
    recvtag,
    comm,
    status,
    ierror
  );
}

void mpi_session_attach_buffer_(
  const MPI_Fint *session,
  const void *buffer,
  const MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_attach_buffer_ptr)(
    session,
    buffer,
    size,
    ierror
  );
}

void mpi_session_detach_buffer_(
  const MPI_Fint *session,
  MPI_Aint *buffer_addr,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_detach_buffer_ptr)(
    session,
    buffer_addr,
    size,
    ierror
  );
}

void mpi_session_flush_buffer_(
  const MPI_Fint *session,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_flush_buffer_ptr)(
    session,
    ierror
  );
}

void mpi_session_iflush_buffer_(
  const MPI_Fint *session,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_iflush_buffer_ptr)(
    session,
    request,
    ierror
  );
}

void mpi_ssend_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_ssend_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    ierror
  );
}

void mpi_ssend_init_(
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *dest,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ssend_init_ptr)(
    buf,
    count,
    datatype,
    dest,
    tag,
    comm,
    request,
    ierror
  );
}

void mpi_start_(
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_start_ptr)(
    request,
    ierror
  );
}

void mpi_startall_(
  const MPI_Fint *count,
  MPI_Fint *array_of_requests,
  MPI_Fint *ierror
) {
  return (*mpiabi_startall_ptr)(
    count,
    array_of_requests,
    ierror
  );
}

void mpi_status_get_error_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *err,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_get_error_ptr)(
    status,
    err,
    ierror
  );
}

void mpi_status_get_source_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *source,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_get_source_ptr)(
    status,
    source,
    ierror
  );
}

void mpi_status_get_tag_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *tag,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_get_tag_ptr)(
    status,
    tag,
    ierror
  );
}

void mpi_test_(
  MPI_Fint *request,
  MPI_Fint *flag,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_test_ptr)(
    request,
    flag,
    status,
    ierror
  );
}

void mpi_test_cancelled_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_test_cancelled_ptr)(
    status,
    flag,
    ierror
  );
}

void mpi_testall_(
  const MPI_Fint *count,
  MPI_Fint *array_of_requests,
  MPI_Fint *flag,
  MPI_Fint *array_of_statuses[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_testall_ptr)(
    count,
    array_of_requests,
    flag,
    array_of_statuses,
    ierror
  );
}

void mpi_testany_(
  const MPI_Fint *count,
  MPI_Fint *array_of_requests,
  MPI_Fint *index,
  MPI_Fint *flag,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_testany_ptr)(
    count,
    array_of_requests,
    index,
    flag,
    status,
    ierror
  );
}

void mpi_testsome_(
  const MPI_Fint *incount,
  MPI_Fint *array_of_requests,
  MPI_Fint *outcount,
  MPI_Fint *array_of_indices,
  MPI_Fint *array_of_statuses[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_testsome_ptr)(
    incount,
    array_of_requests,
    outcount,
    array_of_indices,
    array_of_statuses,
    ierror
  );
}

void mpi_wait_(
  MPI_Fint *request,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_wait_ptr)(
    request,
    status,
    ierror
  );
}

void mpi_waitall_(
  const MPI_Fint *count,
  MPI_Fint *array_of_requests,
  MPI_Fint *array_of_statuses[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_waitall_ptr)(
    count,
    array_of_requests,
    array_of_statuses,
    ierror
  );
}

void mpi_waitany_(
  const MPI_Fint *count,
  MPI_Fint *array_of_requests,
  MPI_Fint *index,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_waitany_ptr)(
    count,
    array_of_requests,
    index,
    status,
    ierror
  );
}

void mpi_waitsome_(
  const MPI_Fint *incount,
  MPI_Fint *array_of_requests,
  MPI_Fint *outcount,
  MPI_Fint *array_of_indices,
  MPI_Fint *array_of_statuses[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_waitsome_ptr)(
    incount,
    array_of_requests,
    outcount,
    array_of_indices,
    array_of_statuses,
    ierror
  );
}

void mpi_parrived_(
  const MPI_Fint *request,
  const MPI_Fint *partition,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_parrived_ptr)(
    request,
    partition,
    flag,
    ierror
  );
}

void mpi_pready_(
  const MPI_Fint *partition,
  const MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_pready_ptr)(
    partition,
    request,
    ierror
  );
}

void mpi_pready_list_(
  const MPI_Fint *length,
  const MPI_Fint *array_of_partitions,
  const MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_pready_list_ptr)(
    length,
    array_of_partitions,
    request,
    ierror
  );
}

void mpi_pready_range_(
  const MPI_Fint *partition_low,
  const MPI_Fint *partition_high,
  const MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_pready_range_ptr)(
    partition_low,
    partition_high,
    request,
    ierror
  );
}

void mpi_precv_init_(
  void *buf,
  const MPI_Fint *partitions,
  const MPI_Count *count,
  const MPI_Fint *datatype,
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_precv_init_ptr)(
    buf,
    partitions,
    count,
    datatype,
    source,
    tag,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_psend_init_(
  void *buf,
  const MPI_Fint *partitions,
  const MPI_Count *count,
  const MPI_Fint *datatype,
  const MPI_Fint *source,
  const MPI_Fint *tag,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_psend_init_ptr)(
    buf,
    partitions,
    count,
    datatype,
    source,
    tag,
    comm,
    info,
    request,
    ierror
  );
}

MPI_Aint mpi_aint_add_(
  const MPI_Aint *base,
  const MPI_Aint *disp
) {
  return (*mpiabi_aint_add_ptr)(
    base,
    disp
  );
}

MPI_Aint mpi_aint_diff_(
  const MPI_Aint *addr1,
  const MPI_Aint *addr2
) {
  return (*mpiabi_aint_diff_ptr)(
    addr1,
    addr2
  );
}

void mpi_get_address_(
  const void *location,
  MPI_Aint *address,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_address_ptr)(
    location,
    address,
    ierror
  );
}

void mpi_get_elements_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *datatype,
  MPI_Fint *count,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_elements_ptr)(
    status,
    datatype,
    count,
    ierror
  );
}

void mpi_pack_(
  const void *inbuf,
  const MPI_Fint *incount,
  const MPI_Fint *datatype,
  void *outbuf,
  const MPI_Fint *outsize,
  MPI_Fint *position,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_pack_ptr)(
    inbuf,
    incount,
    datatype,
    outbuf,
    outsize,
    position,
    comm,
    ierror
  );
}

void mpi_pack_external_(
  const char **datarep,
  const void *inbuf,
  const MPI_Fint *incount,
  const MPI_Fint *datatype,
  void *outbuf,
  const MPI_Aint *outsize,
  MPI_Aint *position,
  MPI_Fint *ierror
) {
  return (*mpiabi_pack_external_ptr)(
    datarep,
    inbuf,
    incount,
    datatype,
    outbuf,
    outsize,
    position,
    ierror
  );
}

void mpi_pack_external_size_(
  const char **datarep,
  const MPI_Count *incount,
  const MPI_Fint *datatype,
  MPI_Aint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_pack_external_size_ptr)(
    datarep,
    incount,
    datatype,
    size,
    ierror
  );
}

void mpi_pack_size_(
  const MPI_Fint *incount,
  const MPI_Fint *datatype,
  const MPI_Fint *comm,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_pack_size_ptr)(
    incount,
    datatype,
    comm,
    size,
    ierror
  );
}

void mpi_type_commit_(
  MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_commit_ptr)(
    datatype,
    ierror
  );
}

void mpi_type_contiguous_(
  const MPI_Fint *count,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_contiguous_ptr)(
    count,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_create_darray_(
  const MPI_Fint *size,
  const MPI_Fint *rank,
  const MPI_Fint *ndims,
  const MPI_Fint *array_of_gsizes,
  const MPI_Fint *array_of_distribs,
  const MPI_Fint *array_of_dargs,
  const MPI_Fint *array_of_psizes,
  const MPI_Fint *order,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_darray_ptr)(
    size,
    rank,
    ndims,
    array_of_gsizes,
    array_of_distribs,
    array_of_dargs,
    array_of_psizes,
    order,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_create_hindexed_(
  const MPI_Fint *count,
  const MPI_Fint *array_of_blocklengths,
  const MPI_Aint *array_of_displacements,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_hindexed_ptr)(
    count,
    array_of_blocklengths,
    array_of_displacements,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_create_hindexed_block_(
  const MPI_Fint *count,
  const MPI_Fint *blocklength,
  const MPI_Aint *array_of_displacements,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_hindexed_block_ptr)(
    count,
    blocklength,
    array_of_displacements,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_create_hvector_(
  const MPI_Fint *count,
  const MPI_Fint *blocklength,
  const MPI_Aint *stride,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_hvector_ptr)(
    count,
    blocklength,
    stride,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_create_indexed_block_(
  const MPI_Fint *count,
  const MPI_Fint *blocklength,
  const MPI_Fint *array_of_displacements,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_indexed_block_ptr)(
    count,
    blocklength,
    array_of_displacements,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_create_resized_(
  const MPI_Fint *oldtype,
  const MPI_Aint *lb,
  const MPI_Aint *extent,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_resized_ptr)(
    oldtype,
    lb,
    extent,
    newtype,
    ierror
  );
}

void mpi_type_create_struct_(
  const MPI_Fint *count,
  const MPI_Fint *array_of_blocklengths,
  const MPI_Aint *array_of_displacements,
  const MPI_Fint *array_of_types,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_struct_ptr)(
    count,
    array_of_blocklengths,
    array_of_displacements,
    array_of_types,
    newtype,
    ierror
  );
}

void mpi_type_create_subarray_(
  const MPI_Fint *ndims,
  const MPI_Fint *array_of_sizes,
  const MPI_Fint *array_of_subsizes,
  const MPI_Fint *array_of_starts,
  const MPI_Fint *order,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_subarray_ptr)(
    ndims,
    array_of_sizes,
    array_of_subsizes,
    array_of_starts,
    order,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_dup_(
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_dup_ptr)(
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_free_(
  MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_free_ptr)(
    datatype,
    ierror
  );
}

void mpi_type_get_contents_(
  const MPI_Fint *datatype,
  const MPI_Fint *max_integers,
  const MPI_Fint *max_addresses,
  const MPI_Fint *max_datatypes,
  MPI_Fint *array_of_integers,
  MPI_Aint *array_of_addresses,
  MPI_Fint *array_of_datatypes,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_contents_ptr)(
    datatype,
    max_integers,
    max_addresses,
    max_datatypes,
    array_of_integers,
    array_of_addresses,
    array_of_datatypes,
    ierror
  );
}

void mpi_type_get_envelope_(
  const MPI_Fint *datatype,
  MPI_Fint *num_integers,
  MPI_Fint *num_addresses,
  MPI_Fint *num_datatypes,
  MPI_Fint *combiner,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_envelope_ptr)(
    datatype,
    num_integers,
    num_addresses,
    num_datatypes,
    combiner,
    ierror
  );
}

void mpi_type_get_extent_(
  const MPI_Fint *datatype,
  MPI_Aint *lb,
  MPI_Aint *extent,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_extent_ptr)(
    datatype,
    lb,
    extent,
    ierror
  );
}

void mpi_type_get_true_extent_(
  const MPI_Fint *datatype,
  MPI_Aint *true_lb,
  MPI_Aint *true_extent,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_true_extent_ptr)(
    datatype,
    true_lb,
    true_extent,
    ierror
  );
}

void mpi_type_indexed_(
  const MPI_Fint *count,
  const MPI_Fint *array_of_blocklengths,
  const MPI_Fint *array_of_displacements,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_indexed_ptr)(
    count,
    array_of_blocklengths,
    array_of_displacements,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_size_(
  const MPI_Fint *datatype,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_size_ptr)(
    datatype,
    size,
    ierror
  );
}

void mpi_type_vector_(
  const MPI_Fint *count,
  const MPI_Fint *blocklength,
  const MPI_Fint *stride,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_vector_ptr)(
    count,
    blocklength,
    stride,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_unpack_(
  const void *inbuf,
  const MPI_Fint *insize,
  MPI_Fint *position,
  void *outbuf,
  const MPI_Fint *outcount,
  const MPI_Fint *datatype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_unpack_ptr)(
    inbuf,
    insize,
    position,
    outbuf,
    outcount,
    datatype,
    comm,
    ierror
  );
}

void mpi_unpack_external_(
  const char **datarep,
  const void *inbuf,
  const MPI_Aint *insize,
  MPI_Aint *position,
  void *outbuf,
  const MPI_Fint *outcount,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_unpack_external_ptr)(
    datarep,
    inbuf,
    insize,
    position,
    outbuf,
    outcount,
    datatype,
    ierror
  );
}

void mpi_allgather_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_allgather_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    ierror
  );
}

void mpi_allgather_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_allgather_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_allgatherv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_allgatherv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    comm,
    ierror
  );
}

void mpi_allgatherv_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_allgatherv_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_allreduce_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_allreduce_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    ierror
  );
}

void mpi_allreduce_init_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_allreduce_init_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_alltoall_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_alltoall_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    ierror
  );
}

void mpi_alltoall_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_alltoall_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_alltoallv_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_alltoallv_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcounts,
    rdispls,
    recvtype,
    comm,
    ierror
  );
}

void mpi_alltoallv_init_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_alltoallv_init_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcounts,
    rdispls,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_alltoallw_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtypes,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtypes,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_alltoallw_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtypes,
    recvbuf,
    recvcounts,
    rdispls,
    recvtypes,
    comm,
    ierror
  );
}

void mpi_alltoallw_init_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtypes,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtypes,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_alltoallw_init_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtypes,
    recvbuf,
    recvcounts,
    rdispls,
    recvtypes,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_barrier_(
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_barrier_ptr)(
    comm,
    ierror
  );
}

void mpi_barrier_init_(
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_barrier_init_ptr)(
    comm,
    info,
    request,
    ierror
  );
}

void mpi_bcast_(
  void *buffer,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_bcast_ptr)(
    buffer,
    count,
    datatype,
    root,
    comm,
    ierror
  );
}

void mpi_bcast_init_(
  void *buffer,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_bcast_init_ptr)(
    buffer,
    count,
    datatype,
    root,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_exscan_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_exscan_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    ierror
  );
}

void mpi_exscan_init_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_exscan_init_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_gather_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_gather_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    ierror
  );
}

void mpi_gather_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_gather_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_gatherv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_gatherv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    root,
    comm,
    ierror
  );
}

void mpi_gatherv_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_gatherv_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    root,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_iallgather_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iallgather_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_iallgatherv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iallgatherv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_iallreduce_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iallreduce_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    request,
    ierror
  );
}

void mpi_ialltoall_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ialltoall_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_ialltoallv_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ialltoallv_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcounts,
    rdispls,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_ialltoallw_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtypes,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtypes,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ialltoallw_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtypes,
    recvbuf,
    recvcounts,
    rdispls,
    recvtypes,
    comm,
    request,
    ierror
  );
}

void mpi_ibarrier_(
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ibarrier_ptr)(
    comm,
    request,
    ierror
  );
}

void mpi_ibcast_(
  void *buffer,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ibcast_ptr)(
    buffer,
    count,
    datatype,
    root,
    comm,
    request,
    ierror
  );
}

void mpi_iexscan_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iexscan_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    request,
    ierror
  );
}

void mpi_igather_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_igather_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    request,
    ierror
  );
}

void mpi_igatherv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_igatherv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    root,
    comm,
    request,
    ierror
  );
}

void mpi_ireduce_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ireduce_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    root,
    comm,
    request,
    ierror
  );
}

void mpi_ireduce_scatter_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ireduce_scatter_ptr)(
    sendbuf,
    recvbuf,
    recvcounts,
    datatype,
    op,
    comm,
    request,
    ierror
  );
}

void mpi_ireduce_scatter_block_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ireduce_scatter_block_ptr)(
    sendbuf,
    recvbuf,
    recvcount,
    datatype,
    op,
    comm,
    request,
    ierror
  );
}

void mpi_iscan_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iscan_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    request,
    ierror
  );
}

void mpi_iscatter_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iscatter_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    request,
    ierror
  );
}

void mpi_iscatterv_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_iscatterv_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    request,
    ierror
  );
}

void mpi_op_commutative_(
  const MPI_Fint *op,
  MPI_Fint *commute,
  MPI_Fint *ierror
) {
  return (*mpiabi_op_commutative_ptr)(
    op,
    commute,
    ierror
  );
}

void mpi_op_create_(
  const void (**user_fn)(void),
  const MPI_Fint *commute,
  MPI_Fint *op,
  MPI_Fint *ierror
) {
  return (*mpiabi_op_create_ptr)(
    user_fn,
    commute,
    op,
    ierror
  );
}

void mpi_op_free_(
  MPI_Fint *op,
  MPI_Fint *ierror
) {
  return (*mpiabi_op_free_ptr)(
    op,
    ierror
  );
}

void mpi_reduce_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    root,
    comm,
    ierror
  );
}

void mpi_reduce_init_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_init_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    root,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_reduce_local_(
  const void *inbuf,
  void *inoutbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_local_ptr)(
    inbuf,
    inoutbuf,
    count,
    datatype,
    op,
    ierror
  );
}

void mpi_reduce_scatter_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_scatter_ptr)(
    sendbuf,
    recvbuf,
    recvcounts,
    datatype,
    op,
    comm,
    ierror
  );
}

void mpi_reduce_scatter_block_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_scatter_block_ptr)(
    sendbuf,
    recvbuf,
    recvcount,
    datatype,
    op,
    comm,
    ierror
  );
}

void mpi_reduce_scatter_block_init_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_scatter_block_init_ptr)(
    sendbuf,
    recvbuf,
    recvcount,
    datatype,
    op,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_reduce_scatter_init_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_reduce_scatter_init_ptr)(
    sendbuf,
    recvbuf,
    recvcounts,
    datatype,
    op,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_scan_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_scan_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    ierror
  );
}

void mpi_scan_init_(
  const void *sendbuf,
  void *recvbuf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  const MPI_Fint *op,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_scan_init_ptr)(
    sendbuf,
    recvbuf,
    count,
    datatype,
    op,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_scatter_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_scatter_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    ierror
  );
}

void mpi_scatter_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_scatter_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_scatterv_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *displs,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_scatterv_ptr)(
    sendbuf,
    sendcounts,
    displs,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    ierror
  );
}

void mpi_scatterv_init_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *displs,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_scatterv_init_ptr)(
    sendbuf,
    sendcounts,
    displs,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    root,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_type_get_value_index_(
  const MPI_Fint *value_type,
  const MPI_Fint *index_type,
  MPI_Fint *pair_type,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_value_index_ptr)(
    value_type,
    index_type,
    pair_type,
    ierror
  );
}

void mpi_comm_compare_(
  const MPI_Fint *comm1,
  const MPI_Fint *comm2,
  MPI_Fint *result,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_compare_ptr)(
    comm1,
    comm2,
    result,
    ierror
  );
}

void mpi_comm_create_(
  const MPI_Fint *comm,
  const MPI_Fint *group,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_create_ptr)(
    comm,
    group,
    newcomm,
    ierror
  );
}

void mpi_comm_create_from_group_(
  const MPI_Fint *group,
  const char **stringtag,
  const MPI_Fint *info,
  const MPI_Fint *errhandler,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_create_from_group_ptr)(
    group,
    stringtag,
    info,
    errhandler,
    newcomm,
    ierror
  );
}

void mpi_comm_create_group_(
  const MPI_Fint *comm,
  const MPI_Fint *group,
  const MPI_Fint *tag,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_create_group_ptr)(
    comm,
    group,
    tag,
    newcomm,
    ierror
  );
}

void mpi_comm_create_keyval_(
  const void (**comm_copy_attr_fn)(void),
  const void (**comm_delete_attr_fn)(void),
  MPI_Fint *comm_keyval,
  void *extra_state,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_create_keyval_ptr)(
    comm_copy_attr_fn,
    comm_delete_attr_fn,
    comm_keyval,
    extra_state,
    ierror
  );
}

void mpi_comm_delete_attr_(
  const MPI_Fint *comm,
  const MPI_Fint *comm_keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_delete_attr_ptr)(
    comm,
    comm_keyval,
    ierror
  );
}

void mpi_comm_dup_(
  const MPI_Fint *comm,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_dup_ptr)(
    comm,
    newcomm,
    ierror
  );
}

void mpi_comm_dup_with_info_(
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_dup_with_info_ptr)(
    comm,
    info,
    newcomm,
    ierror
  );
}

void mpi_comm_free_(
  MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_free_ptr)(
    comm,
    ierror
  );
}

void mpi_comm_get_name_(
  const MPI_Fint *comm,
  char **comm_name,
  MPI_Fint *resultlen,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_get_name_ptr)(
    comm,
    comm_name,
    resultlen,
    ierror
  );
}

void mpi_comm_free_keyval_(
  MPI_Fint *comm_keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_free_keyval_ptr)(
    comm_keyval,
    ierror
  );
}

void mpi_comm_get_attr_(
  const MPI_Fint *comm,
  const MPI_Fint *comm_keyval,
  void *attribute_val,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_get_attr_ptr)(
    comm,
    comm_keyval,
    attribute_val,
    flag,
    ierror
  );
}

void mpi_comm_get_info_(
  const MPI_Fint *comm,
  MPI_Fint *info_used,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_get_info_ptr)(
    comm,
    info_used,
    ierror
  );
}

void mpi_comm_group_(
  const MPI_Fint *comm,
  MPI_Fint *group,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_group_ptr)(
    comm,
    group,
    ierror
  );
}

void mpi_comm_idup_(
  const MPI_Fint *comm,
  MPI_Fint *newcomm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_idup_ptr)(
    comm,
    newcomm,
    request,
    ierror
  );
}

void mpi_comm_idup_with_info_(
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *newcomm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_idup_with_info_ptr)(
    comm,
    info,
    newcomm,
    request,
    ierror
  );
}

void mpi_comm_rank_(
  const MPI_Fint *comm,
  MPI_Fint *rank,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_rank_ptr)(
    comm,
    rank,
    ierror
  );
}

void mpi_comm_remote_group_(
  const MPI_Fint *comm,
  MPI_Fint *group,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_remote_group_ptr)(
    comm,
    group,
    ierror
  );
}

void mpi_comm_remote_size_(
  const MPI_Fint *comm,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_remote_size_ptr)(
    comm,
    size,
    ierror
  );
}

void mpi_comm_set_attr_(
  const MPI_Fint *comm,
  const MPI_Fint *comm_keyval,
  void *attribute_val,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_set_attr_ptr)(
    comm,
    comm_keyval,
    attribute_val,
    ierror
  );
}

void mpi_comm_set_info_(
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_set_info_ptr)(
    comm,
    info,
    ierror
  );
}

void mpi_comm_set_name_(
  const MPI_Fint *comm,
  const char **comm_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_set_name_ptr)(
    comm,
    comm_name,
    ierror
  );
}

void mpi_comm_size_(
  const MPI_Fint *comm,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_size_ptr)(
    comm,
    size,
    ierror
  );
}

void mpi_comm_split_(
  const MPI_Fint *comm,
  const MPI_Fint *color,
  const MPI_Fint *key,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_split_ptr)(
    comm,
    color,
    key,
    newcomm,
    ierror
  );
}

void mpi_group_free_(
  MPI_Fint *group,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_free_ptr)(
    group,
    ierror
  );
}

void mpi_comm_split_type_(
  const MPI_Fint *comm,
  const MPI_Fint *split_type,
  const MPI_Fint *key,
  const MPI_Fint *info,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_split_type_ptr)(
    comm,
    split_type,
    key,
    info,
    newcomm,
    ierror
  );
}

void mpi_comm_test_inter_(
  const MPI_Fint *comm,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_test_inter_ptr)(
    comm,
    flag,
    ierror
  );
}

void mpi_group_compare_(
  const MPI_Fint *group1,
  const MPI_Fint *group2,
  MPI_Fint *result,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_compare_ptr)(
    group1,
    group2,
    result,
    ierror
  );
}

void mpi_group_difference_(
  const MPI_Fint *group1,
  const MPI_Fint *group2,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_difference_ptr)(
    group1,
    group2,
    newgroup,
    ierror
  );
}

void mpi_group_excl_(
  const MPI_Fint *group,
  const MPI_Fint *n,
  const MPI_Fint *ranks,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_excl_ptr)(
    group,
    n,
    ranks,
    newgroup,
    ierror
  );
}

void mpi_group_from_session_pset_(
  const MPI_Fint *session,
  const char **pset_name,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_from_session_pset_ptr)(
    session,
    pset_name,
    newgroup,
    ierror
  );
}

void mpi_group_incl_(
  const MPI_Fint *group,
  const MPI_Fint *n,
  const MPI_Fint *ranks,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_incl_ptr)(
    group,
    n,
    ranks,
    newgroup,
    ierror
  );
}

void mpi_group_intersection_(
  const MPI_Fint *group1,
  const MPI_Fint *group2,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_intersection_ptr)(
    group1,
    group2,
    newgroup,
    ierror
  );
}

void mpi_group_range_excl_(
  const MPI_Fint *group,
  const MPI_Fint *n,
  const MPI_Fint *ranges,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_range_excl_ptr)(
    group,
    n,
    ranges,
    newgroup,
    ierror
  );
}

void mpi_group_range_incl_(
  const MPI_Fint *group,
  const MPI_Fint *n,
  const MPI_Fint *ranges,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_range_incl_ptr)(
    group,
    n,
    ranges,
    newgroup,
    ierror
  );
}

void mpi_group_rank_(
  const MPI_Fint *group,
  MPI_Fint *rank,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_rank_ptr)(
    group,
    rank,
    ierror
  );
}

void mpi_group_size_(
  const MPI_Fint *group,
  MPI_Fint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_size_ptr)(
    group,
    size,
    ierror
  );
}

void mpi_group_translate_ranks_(
  const MPI_Fint *group1,
  const MPI_Fint *n,
  const MPI_Fint *ranks1,
  const MPI_Fint *group2,
  const MPI_Fint *ranks2,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_translate_ranks_ptr)(
    group1,
    n,
    ranks1,
    group2,
    ranks2,
    ierror
  );
}

void mpi_group_union_(
  const MPI_Fint *group1,
  const MPI_Fint *group2,
  MPI_Fint *newgroup,
  MPI_Fint *ierror
) {
  return (*mpiabi_group_union_ptr)(
    group1,
    group2,
    newgroup,
    ierror
  );
}

void mpi_intercomm_create_(
  const MPI_Fint *local_comm,
  const MPI_Fint *local_leader,
  const MPI_Fint *peer_comm,
  const MPI_Fint *remote_leader,
  const MPI_Fint *tag,
  MPI_Fint *newintercomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_intercomm_create_ptr)(
    local_comm,
    local_leader,
    peer_comm,
    remote_leader,
    tag,
    newintercomm,
    ierror
  );
}

void mpi_intercomm_create_from_groups_(
  const MPI_Fint *local_group,
  const MPI_Fint *local_leader,
  const MPI_Fint *remote_group,
  const MPI_Fint *remote_leader,
  const char **stringtag,
  const MPI_Fint *info,
  const MPI_Fint *errhandler,
  MPI_Fint *newintercomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_intercomm_create_from_groups_ptr)(
    local_group,
    local_leader,
    remote_group,
    remote_leader,
    stringtag,
    info,
    errhandler,
    newintercomm,
    ierror
  );
}

void mpi_intercomm_merge_(
  const MPI_Fint *intercomm,
  const MPI_Fint *high,
  MPI_Fint *newintracomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_intercomm_merge_ptr)(
    intercomm,
    high,
    newintracomm,
    ierror
  );
}

void mpi_type_create_keyval_(
  const void (**type_copy_attr_fn)(void),
  const void (**type_delete_attr_fn)(void),
  MPI_Fint *type_keyval,
  void *extra_state,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_keyval_ptr)(
    type_copy_attr_fn,
    type_delete_attr_fn,
    type_keyval,
    extra_state,
    ierror
  );
}

void mpi_type_delete_attr_(
  const MPI_Fint *datatype,
  const MPI_Fint *type_keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_delete_attr_ptr)(
    datatype,
    type_keyval,
    ierror
  );
}

void mpi_type_free_keyval_(
  MPI_Fint *type_keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_free_keyval_ptr)(
    type_keyval,
    ierror
  );
}

void mpi_type_get_attr_(
  const MPI_Fint *datatype,
  const MPI_Fint *type_keyval,
  void *attribute_val,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_attr_ptr)(
    datatype,
    type_keyval,
    attribute_val,
    flag,
    ierror
  );
}

void mpi_type_get_name_(
  const MPI_Fint *datatype,
  char **type_name,
  MPI_Fint *resultlen,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_name_ptr)(
    datatype,
    type_name,
    resultlen,
    ierror
  );
}

void mpi_type_set_attr_(
  const MPI_Fint *datatype,
  const MPI_Fint *type_keyval,
  void *attribute_val,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_set_attr_ptr)(
    datatype,
    type_keyval,
    attribute_val,
    ierror
  );
}

void mpi_type_set_name_(
  const MPI_Fint *datatype,
  const char **type_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_set_name_ptr)(
    datatype,
    type_name,
    ierror
  );
}

void mpi_win_create_keyval_(
  const void (**win_copy_attr_fn)(void),
  const void (**win_delete_attr_fn)(void),
  MPI_Fint *win_keyval,
  void *extra_state,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_create_keyval_ptr)(
    win_copy_attr_fn,
    win_delete_attr_fn,
    win_keyval,
    extra_state,
    ierror
  );
}

void mpi_win_delete_attr_(
  const MPI_Fint *win,
  const MPI_Fint *win_keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_delete_attr_ptr)(
    win,
    win_keyval,
    ierror
  );
}

void mpi_win_free_keyval_(
  MPI_Fint *win_keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_free_keyval_ptr)(
    win_keyval,
    ierror
  );
}

void mpi_win_get_attr_(
  const MPI_Fint *win,
  const MPI_Fint *win_keyval,
  void *attribute_val,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_get_attr_ptr)(
    win,
    win_keyval,
    attribute_val,
    flag,
    ierror
  );
}

void mpi_win_get_name_(
  const MPI_Fint *win,
  char **win_name,
  MPI_Fint *resultlen,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_get_name_ptr)(
    win,
    win_name,
    resultlen,
    ierror
  );
}

void mpi_win_set_attr_(
  const MPI_Fint *win,
  const MPI_Fint *win_keyval,
  void *attribute_val,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_set_attr_ptr)(
    win,
    win_keyval,
    attribute_val,
    ierror
  );
}

void mpi_win_set_name_(
  const MPI_Fint *win,
  const char **win_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_set_name_ptr)(
    win,
    win_name,
    ierror
  );
}

void mpi_cart_coords_(
  const MPI_Fint *comm,
  const MPI_Fint *rank,
  const MPI_Fint *maxdims,
  MPI_Fint *coords,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_coords_ptr)(
    comm,
    rank,
    maxdims,
    coords,
    ierror
  );
}

void mpi_cart_create_(
  const MPI_Fint *comm_old,
  const MPI_Fint *ndims,
  const MPI_Fint *dims,
  const MPI_Fint *periods,
  const MPI_Fint *reorder,
  MPI_Fint *comm_cart,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_create_ptr)(
    comm_old,
    ndims,
    dims,
    periods,
    reorder,
    comm_cart,
    ierror
  );
}

void mpi_cart_get_(
  const MPI_Fint *comm,
  const MPI_Fint *maxdims,
  MPI_Fint *dims,
  MPI_Fint *periods,
  MPI_Fint *coords,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_get_ptr)(
    comm,
    maxdims,
    dims,
    periods,
    coords,
    ierror
  );
}

void mpi_cart_map_(
  const MPI_Fint *comm,
  const MPI_Fint *ndims,
  const MPI_Fint *dims,
  const MPI_Fint *periods,
  MPI_Fint *newrank,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_map_ptr)(
    comm,
    ndims,
    dims,
    periods,
    newrank,
    ierror
  );
}

void mpi_cart_rank_(
  const MPI_Fint *comm,
  const MPI_Fint *coords,
  MPI_Fint *rank,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_rank_ptr)(
    comm,
    coords,
    rank,
    ierror
  );
}

void mpi_cart_shift_(
  const MPI_Fint *comm,
  const MPI_Fint *direction,
  const MPI_Fint *disp,
  MPI_Fint *rank_source,
  MPI_Fint *rank_dest,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_shift_ptr)(
    comm,
    direction,
    disp,
    rank_source,
    rank_dest,
    ierror
  );
}

void mpi_cart_sub_(
  const MPI_Fint *comm,
  const MPI_Fint *remain_dims,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_cart_sub_ptr)(
    comm,
    remain_dims,
    newcomm,
    ierror
  );
}

void mpi_cartdim_get_(
  const MPI_Fint *comm,
  MPI_Fint *ndims,
  MPI_Fint *ierror
) {
  return (*mpiabi_cartdim_get_ptr)(
    comm,
    ndims,
    ierror
  );
}

void mpi_dims_create_(
  const MPI_Fint *nnodes,
  const MPI_Fint *ndims,
  const MPI_Fint *dims,
  MPI_Fint *ierror
) {
  return (*mpiabi_dims_create_ptr)(
    nnodes,
    ndims,
    dims,
    ierror
  );
}

void mpi_dist_graph_create_(
  const MPI_Fint *comm_old,
  const MPI_Fint *n,
  const MPI_Fint *sources,
  const MPI_Fint *degrees,
  const MPI_Fint *destinations,
  const MPI_Fint *weights,
  const MPI_Fint *info,
  const MPI_Fint *reorder,
  MPI_Fint *comm_dist_graph,
  MPI_Fint *ierror
) {
  return (*mpiabi_dist_graph_create_ptr)(
    comm_old,
    n,
    sources,
    degrees,
    destinations,
    weights,
    info,
    reorder,
    comm_dist_graph,
    ierror
  );
}

void mpi_dist_graph_create_adjacent_(
  const MPI_Fint *comm_old,
  const MPI_Fint *indegree,
  const MPI_Fint *sources,
  const MPI_Fint *sourceweights,
  const MPI_Fint *outdegree,
  const MPI_Fint *destinations,
  const MPI_Fint *destweights,
  const MPI_Fint *info,
  const MPI_Fint *reorder,
  MPI_Fint *comm_dist_graph,
  MPI_Fint *ierror
) {
  return (*mpiabi_dist_graph_create_adjacent_ptr)(
    comm_old,
    indegree,
    sources,
    sourceweights,
    outdegree,
    destinations,
    destweights,
    info,
    reorder,
    comm_dist_graph,
    ierror
  );
}

void mpi_dist_graph_neighbors_(
  const MPI_Fint *comm,
  const MPI_Fint *maxindegree,
  MPI_Fint *sources,
  MPI_Fint *sourceweights,
  const MPI_Fint *maxoutdegree,
  MPI_Fint *destinations,
  MPI_Fint *destweights,
  MPI_Fint *ierror
) {
  return (*mpiabi_dist_graph_neighbors_ptr)(
    comm,
    maxindegree,
    sources,
    sourceweights,
    maxoutdegree,
    destinations,
    destweights,
    ierror
  );
}

void mpi_dist_graph_neighbors_count_(
  const MPI_Fint *comm,
  MPI_Fint *indegree,
  MPI_Fint *outdegree,
  MPI_Fint *weighted,
  MPI_Fint *ierror
) {
  return (*mpiabi_dist_graph_neighbors_count_ptr)(
    comm,
    indegree,
    outdegree,
    weighted,
    ierror
  );
}

void mpi_graph_create_(
  const MPI_Fint *comm_old,
  const MPI_Fint *nnodes,
  const MPI_Fint *index,
  const MPI_Fint *edges,
  const MPI_Fint *reorder,
  MPI_Fint *comm_graph,
  MPI_Fint *ierror
) {
  return (*mpiabi_graph_create_ptr)(
    comm_old,
    nnodes,
    index,
    edges,
    reorder,
    comm_graph,
    ierror
  );
}

void mpi_graph_get_(
  const MPI_Fint *comm,
  const MPI_Fint *maxindex,
  const MPI_Fint *maxedges,
  MPI_Fint *index,
  MPI_Fint *edges,
  MPI_Fint *ierror
) {
  return (*mpiabi_graph_get_ptr)(
    comm,
    maxindex,
    maxedges,
    index,
    edges,
    ierror
  );
}

void mpi_graph_map_(
  const MPI_Fint *comm,
  const MPI_Fint *nnodes,
  const MPI_Fint *index,
  const MPI_Fint *edges,
  MPI_Fint *newrank,
  MPI_Fint *ierror
) {
  return (*mpiabi_graph_map_ptr)(
    comm,
    nnodes,
    index,
    edges,
    newrank,
    ierror
  );
}

void mpi_graph_neighbors_(
  const MPI_Fint *comm,
  const MPI_Fint *rank,
  const MPI_Fint *maxneighbors,
  MPI_Fint *neighbors,
  MPI_Fint *ierror
) {
  return (*mpiabi_graph_neighbors_ptr)(
    comm,
    rank,
    maxneighbors,
    neighbors,
    ierror
  );
}

void mpi_graph_neighbors_count_(
  const MPI_Fint *comm,
  const MPI_Fint *rank,
  MPI_Fint *nneighbors,
  MPI_Fint *ierror
) {
  return (*mpiabi_graph_neighbors_count_ptr)(
    comm,
    rank,
    nneighbors,
    ierror
  );
}

void mpi_graphdims_get_(
  const MPI_Fint *comm,
  MPI_Fint *nnodes,
  MPI_Fint *nedges,
  MPI_Fint *ierror
) {
  return (*mpiabi_graphdims_get_ptr)(
    comm,
    nnodes,
    nedges,
    ierror
  );
}

void mpi_ineighbor_allgather_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ineighbor_allgather_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_ineighbor_allgatherv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ineighbor_allgatherv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_ineighbor_alltoall_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ineighbor_alltoall_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_ineighbor_alltoallv_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ineighbor_alltoallv_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcounts,
    rdispls,
    recvtype,
    comm,
    request,
    ierror
  );
}

void mpi_ineighbor_alltoallw_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Aint *sdispls,
  const MPI_Fint *sendtypes,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Aint *rdispls,
  const MPI_Fint *recvtypes,
  const MPI_Fint *comm,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_ineighbor_alltoallw_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtypes,
    recvbuf,
    recvcounts,
    rdispls,
    recvtypes,
    comm,
    request,
    ierror
  );
}

void mpi_neighbor_allgather_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_allgather_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    ierror
  );
}

void mpi_neighbor_allgather_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_allgather_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_neighbor_allgatherv_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Aint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_allgatherv_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    comm,
    ierror
  );
}

void mpi_neighbor_allgatherv_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Aint *displs,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_allgatherv_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcounts,
    displs,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_neighbor_alltoall_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_alltoall_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    ierror
  );
}

void mpi_neighbor_alltoall_init_(
  const void *sendbuf,
  const MPI_Fint *sendcount,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcount,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_alltoall_init_ptr)(
    sendbuf,
    sendcount,
    sendtype,
    recvbuf,
    recvcount,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_neighbor_alltoallv_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_alltoallv_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcounts,
    rdispls,
    recvtype,
    comm,
    ierror
  );
}

void mpi_neighbor_alltoallv_init_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Fint *sdispls,
  const MPI_Fint *sendtype,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Fint *rdispls,
  const MPI_Fint *recvtype,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_alltoallv_init_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtype,
    recvbuf,
    recvcounts,
    rdispls,
    recvtype,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_neighbor_alltoallw_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Aint *sdispls,
  const MPI_Fint *sendtypes,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Aint *rdispls,
  const MPI_Fint *recvtypes,
  const MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_alltoallw_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtypes,
    recvbuf,
    recvcounts,
    rdispls,
    recvtypes,
    comm,
    ierror
  );
}

void mpi_neighbor_alltoallw_init_(
  const void *sendbuf,
  const MPI_Fint *sendcounts,
  const MPI_Aint *sdispls,
  const MPI_Fint *sendtypes,
  void *recvbuf,
  const MPI_Fint *recvcounts,
  const MPI_Aint *rdispls,
  const MPI_Fint *recvtypes,
  const MPI_Fint *comm,
  const MPI_Fint *info,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_neighbor_alltoallw_init_ptr)(
    sendbuf,
    sendcounts,
    sdispls,
    sendtypes,
    recvbuf,
    recvcounts,
    rdispls,
    recvtypes,
    comm,
    info,
    request,
    ierror
  );
}

void mpi_topo_test_(
  const MPI_Fint *comm,
  MPI_Fint *status,
  MPI_Fint *ierror
) {
  return (*mpiabi_topo_test_ptr)(
    comm,
    status,
    ierror
  );
}

void mpi_add_error_class_(
  MPI_Fint *errorclass,
  MPI_Fint *ierror
) {
  return (*mpiabi_add_error_class_ptr)(
    errorclass,
    ierror
  );
}

void mpi_add_error_code_(
  const MPI_Fint *errorclass,
  MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_add_error_code_ptr)(
    errorclass,
    errorcode,
    ierror
  );
}

void mpi_add_error_string_(
  const MPI_Fint *errorcode,
  const char **string,
  MPI_Fint *ierror
) {
  return (*mpiabi_add_error_string_ptr)(
    errorcode,
    string,
    ierror
  );
}

void mpi_alloc_mem_(
  const MPI_Aint *size,
  const MPI_Fint *info,
  void *baseptr,
  MPI_Fint *ierror
) {
  return (*mpiabi_alloc_mem_ptr)(
    size,
    info,
    baseptr,
    ierror
  );
}

void mpi_comm_call_errhandler_(
  const MPI_Fint *comm,
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_call_errhandler_ptr)(
    comm,
    errorcode,
    ierror
  );
}

void mpi_comm_create_errhandler_(
  const void (**comm_errhandler_fn)(void),
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_create_errhandler_ptr)(
    comm_errhandler_fn,
    errhandler,
    ierror
  );
}

void mpi_comm_get_errhandler_(
  const MPI_Fint *comm,
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_get_errhandler_ptr)(
    comm,
    errhandler,
    ierror
  );
}

void mpi_comm_set_errhandler_(
  const MPI_Fint *comm,
  const MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_set_errhandler_ptr)(
    comm,
    errhandler,
    ierror
  );
}

void mpi_errhandler_free_(
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_errhandler_free_ptr)(
    errhandler,
    ierror
  );
}

void mpi_error_class_(
  const MPI_Fint *errorcode,
  MPI_Fint *errorclass,
  MPI_Fint *ierror
) {
  return (*mpiabi_error_class_ptr)(
    errorcode,
    errorclass,
    ierror
  );
}

void mpi_error_string_(
  const MPI_Fint *errorcode,
  char **string,
  MPI_Fint *resultlen,
  MPI_Fint *ierror
) {
  return (*mpiabi_error_string_ptr)(
    errorcode,
    string,
    resultlen,
    ierror
  );
}

void mpi_file_call_errhandler_(
  const MPI_Fint *fh,
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_call_errhandler_ptr)(
    fh,
    errorcode,
    ierror
  );
}

void mpi_file_create_errhandler_(
  const void (**file_errhandler_fn)(void),
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_create_errhandler_ptr)(
    file_errhandler_fn,
    errhandler,
    ierror
  );
}

void mpi_file_get_errhandler_(
  const MPI_Fint *file,
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_errhandler_ptr)(
    file,
    errhandler,
    ierror
  );
}

void mpi_file_set_errhandler_(
  const MPI_Fint *file,
  const MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_set_errhandler_ptr)(
    file,
    errhandler,
    ierror
  );
}

void mpi_free_mem_(
  void *base,
  MPI_Fint *ierror
) {
  return (*mpiabi_free_mem_ptr)(
    base,
    ierror
  );
}

void mpi_get_hw_resource_info_(
  MPI_Fint *hw_info,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_hw_resource_info_ptr)(
    hw_info,
    ierror
  );
}

void mpi_get_library_version_(
  char **version,
  MPI_Fint *resultlen,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_library_version_ptr)(
    version,
    resultlen,
    ierror
  );
}

void mpi_get_processor_name_(
  char **name,
  MPI_Fint *resultlen,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_processor_name_ptr)(
    name,
    resultlen,
    ierror
  );
}

void mpi_get_version_(
  MPI_Fint *version,
  MPI_Fint *subversion,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_version_ptr)(
    version,
    subversion,
    ierror
  );
}

void mpi_remove_error_class_(
  const MPI_Fint *errorclass,
  MPI_Fint *ierror
) {
  return (*mpiabi_remove_error_class_ptr)(
    errorclass,
    ierror
  );
}

void mpi_remove_error_code_(
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_remove_error_code_ptr)(
    errorcode,
    ierror
  );
}

void mpi_remove_error_string_(
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_remove_error_string_ptr)(
    errorcode,
    ierror
  );
}

void mpi_session_call_errhandler_(
  const MPI_Fint *session,
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_call_errhandler_ptr)(
    session,
    errorcode,
    ierror
  );
}

void mpi_session_create_errhandler_(
  const void (**session_errhandler_fn)(void),
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_create_errhandler_ptr)(
    session_errhandler_fn,
    errhandler,
    ierror
  );
}

void mpi_session_get_errhandler_(
  const MPI_Fint *session,
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_get_errhandler_ptr)(
    session,
    errhandler,
    ierror
  );
}

void mpi_session_set_errhandler_(
  const MPI_Fint *session,
  const MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_set_errhandler_ptr)(
    session,
    errhandler,
    ierror
  );
}

void mpi_win_call_errhandler_(
  const MPI_Fint *win,
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_call_errhandler_ptr)(
    win,
    errorcode,
    ierror
  );
}

void mpi_win_create_errhandler_(
  const void (**win_errhandler_fn)(void),
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_create_errhandler_ptr)(
    win_errhandler_fn,
    errhandler,
    ierror
  );
}

void mpi_win_get_errhandler_(
  const MPI_Fint *win,
  MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_get_errhandler_ptr)(
    win,
    errhandler,
    ierror
  );
}

void mpi_win_set_errhandler_(
  const MPI_Fint *win,
  const MPI_Fint *errhandler,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_set_errhandler_ptr)(
    win,
    errhandler,
    ierror
  );
}

double mpi_wtick_(
) {
  return (*mpiabi_wtick_ptr)(
  );
}

double mpi_wtime_(
) {
  return (*mpiabi_wtime_ptr)(
  );
}

void mpi_info_create_(
  MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_create_ptr)(
    info,
    ierror
  );
}

void mpi_info_create_env_(
  MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_create_env_ptr)(
    info,
    ierror
  );
}

void mpi_info_delete_(
  const MPI_Fint *info,
  const char **key,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_delete_ptr)(
    info,
    key,
    ierror
  );
}

void mpi_info_dup_(
  const MPI_Fint *info,
  MPI_Fint *newinfo,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_dup_ptr)(
    info,
    newinfo,
    ierror
  );
}

void mpi_info_free_(
  MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_free_ptr)(
    info,
    ierror
  );
}

void mpi_info_get_nkeys_(
  const MPI_Fint *info,
  MPI_Fint *nkeys,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_get_nkeys_ptr)(
    info,
    nkeys,
    ierror
  );
}

void mpi_info_get_nthkey_(
  const MPI_Fint *info,
  const MPI_Fint *n,
  char **key,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_get_nthkey_ptr)(
    info,
    n,
    key,
    ierror
  );
}

void mpi_info_get_string_(
  const MPI_Fint *info,
  const char **key,
  MPI_Fint *buflen,
  char **value,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_get_string_ptr)(
    info,
    key,
    buflen,
    value,
    flag,
    ierror
  );
}

void mpi_info_set_(
  const MPI_Fint *info,
  const char **key,
  const char **value,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_set_ptr)(
    info,
    key,
    value,
    ierror
  );
}

void mpi_abort_(
  const MPI_Fint *comm,
  const MPI_Fint *errorcode,
  MPI_Fint *ierror
) {
  return (*mpiabi_abort_ptr)(
    comm,
    errorcode,
    ierror
  );
}

void mpi_close_port_(
  const char **port_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_close_port_ptr)(
    port_name,
    ierror
  );
}

void mpi_comm_accept_(
  const char **port_name,
  const MPI_Fint *info,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_accept_ptr)(
    port_name,
    info,
    root,
    comm,
    newcomm,
    ierror
  );
}

void mpi_comm_connect_(
  const char **port_name,
  const MPI_Fint *info,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *newcomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_connect_ptr)(
    port_name,
    info,
    root,
    comm,
    newcomm,
    ierror
  );
}

void mpi_comm_disconnect_(
  MPI_Fint *comm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_disconnect_ptr)(
    comm,
    ierror
  );
}

void mpi_comm_get_parent_(
  MPI_Fint *parent,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_get_parent_ptr)(
    parent,
    ierror
  );
}

void mpi_comm_join_(
  const MPI_Fint *fd,
  MPI_Fint *intercomm,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_join_ptr)(
    fd,
    intercomm,
    ierror
  );
}

void mpi_comm_spawn_(
  const char **command,
  const char **argv,
  const MPI_Fint *maxprocs,
  const MPI_Fint *info,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *intercomm,
  MPI_Fint *array_of_errcodes,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_spawn_ptr)(
    command,
    argv,
    maxprocs,
    info,
    root,
    comm,
    intercomm,
    array_of_errcodes,
    ierror
  );
}

void mpi_comm_spawn_multiple_(
  const MPI_Fint *count,
  const char **array_of_commands,
  const char **array_of_argv,
  const MPI_Fint *array_of_maxprocs,
  const MPI_Fint *array_of_info,
  const MPI_Fint *root,
  const MPI_Fint *comm,
  MPI_Fint *intercomm,
  MPI_Fint *array_of_errcodes,
  MPI_Fint *ierror
) {
  return (*mpiabi_comm_spawn_multiple_ptr)(
    count,
    array_of_commands,
    array_of_argv,
    array_of_maxprocs,
    array_of_info,
    root,
    comm,
    intercomm,
    array_of_errcodes,
    ierror
  );
}

void mpi_finalize_(
  MPI_Fint *ierror
) {
  return (*mpiabi_finalize_ptr)(
    ierror
  );
}

void mpi_finalized_(
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_finalized_ptr)(
    flag,
    ierror
  );
}

void mpi_init_(
  MPI_Fint *ierror
) {
  return (*mpiabi_init_ptr)(
    ierror
  );
}

void mpi_init_thread_(
  const MPI_Fint *required,
  MPI_Fint *provided,
  MPI_Fint *ierror
) {
  return (*mpiabi_init_thread_ptr)(
    required,
    provided,
    ierror
  );
}

void mpi_initialized_(
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_initialized_ptr)(
    flag,
    ierror
  );
}

void mpi_is_thread_main_(
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_is_thread_main_ptr)(
    flag,
    ierror
  );
}

void mpi_lookup_name_(
  const char **service_name,
  const MPI_Fint *info,
  char **port_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_lookup_name_ptr)(
    service_name,
    info,
    port_name,
    ierror
  );
}

void mpi_open_port_(
  const MPI_Fint *info,
  char **port_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_open_port_ptr)(
    info,
    port_name,
    ierror
  );
}

void mpi_publish_name_(
  const char **service_name,
  const MPI_Fint *info,
  const char **port_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_publish_name_ptr)(
    service_name,
    info,
    port_name,
    ierror
  );
}

void mpi_query_thread_(
  MPI_Fint *provided,
  MPI_Fint *ierror
) {
  return (*mpiabi_query_thread_ptr)(
    provided,
    ierror
  );
}

void mpi_session_finalize_(
  MPI_Fint *session,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_finalize_ptr)(
    session,
    ierror
  );
}

void mpi_session_get_info_(
  const MPI_Fint *session,
  MPI_Fint *info_used,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_get_info_ptr)(
    session,
    info_used,
    ierror
  );
}

void mpi_session_get_nth_pset_(
  const MPI_Fint *session,
  const MPI_Fint *info,
  const MPI_Fint *n,
  MPI_Fint *pset_len,
  char **pset_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_get_nth_pset_ptr)(
    session,
    info,
    n,
    pset_len,
    pset_name,
    ierror
  );
}

void mpi_session_get_num_psets_(
  const MPI_Fint *session,
  const MPI_Fint *info,
  MPI_Fint *npset_names,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_get_num_psets_ptr)(
    session,
    info,
    npset_names,
    ierror
  );
}

void mpi_session_get_pset_info_(
  const MPI_Fint *session,
  const char **pset_name,
  MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_get_pset_info_ptr)(
    session,
    pset_name,
    info,
    ierror
  );
}

void mpi_session_init_(
  const MPI_Fint *info,
  const MPI_Fint *errhandler,
  MPI_Fint *session,
  MPI_Fint *ierror
) {
  return (*mpiabi_session_init_ptr)(
    info,
    errhandler,
    session,
    ierror
  );
}

void mpi_unpublish_name_(
  const char **service_name,
  const MPI_Fint *info,
  const char **port_name,
  MPI_Fint *ierror
) {
  return (*mpiabi_unpublish_name_ptr)(
    service_name,
    info,
    port_name,
    ierror
  );
}

void mpi_accumulate_(
  const void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *op,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_accumulate_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    op,
    win,
    ierror
  );
}

void mpi_compare_and_swap_(
  const void *origin_addr,
  const void *compare_addr,
  void *result_addr,
  const MPI_Fint *datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_compare_and_swap_ptr)(
    origin_addr,
    compare_addr,
    result_addr,
    datatype,
    target_rank,
    target_disp,
    win,
    ierror
  );
}

void mpi_fetch_and_op_(
  const void *origin_addr,
  void *result_addr,
  const MPI_Fint *datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *op,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_fetch_and_op_ptr)(
    origin_addr,
    result_addr,
    datatype,
    target_rank,
    target_disp,
    op,
    win,
    ierror
  );
}

void mpi_get_(
  void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    win,
    ierror
  );
}

void mpi_get_accumulate_(
  const void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  void *result_addr,
  const MPI_Fint *result_count,
  const MPI_Fint *result_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *op,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_accumulate_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    result_addr,
    result_count,
    result_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    op,
    win,
    ierror
  );
}

void mpi_put_(
  const void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_put_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    win,
    ierror
  );
}

void mpi_raccumulate_(
  const void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *op,
  const MPI_Fint *win,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_raccumulate_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    op,
    win,
    request,
    ierror
  );
}

void mpi_rget_(
  void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *win,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_rget_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    win,
    request,
    ierror
  );
}

void mpi_rget_accumulate_(
  const void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  void *result_addr,
  const MPI_Fint *result_count,
  const MPI_Fint *result_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *op,
  const MPI_Fint *win,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_rget_accumulate_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    result_addr,
    result_count,
    result_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    op,
    win,
    request,
    ierror
  );
}

void mpi_rput_(
  const void *origin_addr,
  const MPI_Fint *origin_count,
  const MPI_Fint *origin_datatype,
  const MPI_Fint *target_rank,
  const MPI_Aint *target_disp,
  const MPI_Fint *target_count,
  const MPI_Fint *target_datatype,
  const MPI_Fint *win,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_rput_ptr)(
    origin_addr,
    origin_count,
    origin_datatype,
    target_rank,
    target_disp,
    target_count,
    target_datatype,
    win,
    request,
    ierror
  );
}

void mpi_win_allocate_(
  const MPI_Aint *size,
  const MPI_Fint *disp_unit,
  const MPI_Fint *info,
  const MPI_Fint *comm,
  void *baseptr,
  MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_allocate_ptr)(
    size,
    disp_unit,
    info,
    comm,
    baseptr,
    win,
    ierror
  );
}

void mpi_win_allocate_shared_(
  const MPI_Aint *size,
  const MPI_Fint *disp_unit,
  const MPI_Fint *info,
  const MPI_Fint *comm,
  void *baseptr,
  MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_allocate_shared_ptr)(
    size,
    disp_unit,
    info,
    comm,
    baseptr,
    win,
    ierror
  );
}

void mpi_win_attach_(
  const MPI_Fint *win,
  void *base,
  const MPI_Aint *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_attach_ptr)(
    win,
    base,
    size,
    ierror
  );
}

void mpi_win_complete_(
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_complete_ptr)(
    win,
    ierror
  );
}

void mpi_win_create_(
  void *base,
  const MPI_Aint *size,
  const MPI_Fint *disp_unit,
  const MPI_Fint *info,
  const MPI_Fint *comm,
  MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_create_ptr)(
    base,
    size,
    disp_unit,
    info,
    comm,
    win,
    ierror
  );
}

void mpi_win_create_dynamic_(
  const MPI_Fint *info,
  const MPI_Fint *comm,
  MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_create_dynamic_ptr)(
    info,
    comm,
    win,
    ierror
  );
}

void mpi_win_detach_(
  const MPI_Fint *win,
  const void *base,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_detach_ptr)(
    win,
    base,
    ierror
  );
}

void mpi_win_fence_(
  const MPI_Fint *assert,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_fence_ptr)(
    assert,
    win,
    ierror
  );
}

void mpi_win_flush_(
  const MPI_Fint *rank,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_flush_ptr)(
    rank,
    win,
    ierror
  );
}

void mpi_win_flush_all_(
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_flush_all_ptr)(
    win,
    ierror
  );
}

void mpi_win_flush_local_(
  const MPI_Fint *rank,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_flush_local_ptr)(
    rank,
    win,
    ierror
  );
}

void mpi_win_flush_local_all_(
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_flush_local_all_ptr)(
    win,
    ierror
  );
}

void mpi_win_free_(
  MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_free_ptr)(
    win,
    ierror
  );
}

void mpi_win_get_group_(
  const MPI_Fint *win,
  MPI_Fint *group,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_get_group_ptr)(
    win,
    group,
    ierror
  );
}

void mpi_win_get_info_(
  const MPI_Fint *win,
  MPI_Fint *info_used,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_get_info_ptr)(
    win,
    info_used,
    ierror
  );
}

void mpi_win_lock_(
  const MPI_Fint *lock_type,
  const MPI_Fint *rank,
  const MPI_Fint *assert,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_lock_ptr)(
    lock_type,
    rank,
    assert,
    win,
    ierror
  );
}

void mpi_win_lock_all_(
  const MPI_Fint *assert,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_lock_all_ptr)(
    assert,
    win,
    ierror
  );
}

void mpi_win_post_(
  const MPI_Fint *group,
  const MPI_Fint *assert,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_post_ptr)(
    group,
    assert,
    win,
    ierror
  );
}

void mpi_win_set_info_(
  const MPI_Fint *win,
  const MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_set_info_ptr)(
    win,
    info,
    ierror
  );
}

void mpi_win_shared_query_(
  const MPI_Fint *win,
  const MPI_Fint *rank,
  MPI_Aint *size,
  MPI_Fint *disp_unit,
  void *baseptr,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_shared_query_ptr)(
    win,
    rank,
    size,
    disp_unit,
    baseptr,
    ierror
  );
}

void mpi_win_start_(
  const MPI_Fint *group,
  const MPI_Fint *assert,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_start_ptr)(
    group,
    assert,
    win,
    ierror
  );
}

void mpi_win_sync_(
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_sync_ptr)(
    win,
    ierror
  );
}

void mpi_win_test_(
  const MPI_Fint *win,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_test_ptr)(
    win,
    flag,
    ierror
  );
}

void mpi_win_unlock_(
  const MPI_Fint *rank,
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_unlock_ptr)(
    rank,
    win,
    ierror
  );
}

void mpi_win_unlock_all_(
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_unlock_all_ptr)(
    win,
    ierror
  );
}

void mpi_win_wait_(
  const MPI_Fint *win,
  MPI_Fint *ierror
) {
  return (*mpiabi_win_wait_ptr)(
    win,
    ierror
  );
}

void mpi_grequest_complete_(
  const MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_grequest_complete_ptr)(
    request,
    ierror
  );
}

void mpi_grequest_start_(
  const void (**query_fn)(void),
  const void (**free_fn)(void),
  const void (**cancel_fn)(void),
  void *extra_state,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_grequest_start_ptr)(
    query_fn,
    free_fn,
    cancel_fn,
    extra_state,
    request,
    ierror
  );
}

void mpi_status_set_cancelled_(
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_set_cancelled_ptr)(
    status,
    flag,
    ierror
  );
}

void mpi_status_set_elements_(
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *datatype,
  const MPI_Fint *count,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_set_elements_ptr)(
    status,
    datatype,
    count,
    ierror
  );
}

void mpi_status_set_error_(
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *err,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_set_error_ptr)(
    status,
    err,
    ierror
  );
}

void mpi_status_set_source_(
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *source,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_set_source_ptr)(
    status,
    source,
    ierror
  );
}

void mpi_status_set_tag_(
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *tag,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_set_tag_ptr)(
    status,
    tag,
    ierror
  );
}

void mpi_file_close_(
  MPI_Fint *fh,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_close_ptr)(
    fh,
    ierror
  );
}

void mpi_file_delete_(
  const char **filename,
  const MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_delete_ptr)(
    filename,
    info,
    ierror
  );
}

void mpi_file_get_amode_(
  const MPI_Fint *fh,
  MPI_Fint *amode,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_amode_ptr)(
    fh,
    amode,
    ierror
  );
}

void mpi_file_get_atomicity_(
  const MPI_Fint *fh,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_atomicity_ptr)(
    fh,
    flag,
    ierror
  );
}

void mpi_file_get_byte_offset_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  MPI_Offset *disp,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_byte_offset_ptr)(
    fh,
    offset,
    disp,
    ierror
  );
}

void mpi_file_get_group_(
  const MPI_Fint *fh,
  MPI_Fint *group,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_group_ptr)(
    fh,
    group,
    ierror
  );
}

void mpi_file_get_info_(
  const MPI_Fint *fh,
  MPI_Fint *info_used,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_info_ptr)(
    fh,
    info_used,
    ierror
  );
}

void mpi_file_get_position_(
  const MPI_Fint *fh,
  MPI_Offset *offset,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_position_ptr)(
    fh,
    offset,
    ierror
  );
}

void mpi_file_get_position_shared_(
  const MPI_Fint *fh,
  MPI_Offset *offset,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_position_shared_ptr)(
    fh,
    offset,
    ierror
  );
}

void mpi_file_get_size_(
  const MPI_Fint *fh,
  MPI_Offset *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_size_ptr)(
    fh,
    size,
    ierror
  );
}

void mpi_file_get_type_extent_(
  const MPI_Fint *fh,
  const MPI_Fint *datatype,
  MPI_Aint *extent,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_type_extent_ptr)(
    fh,
    datatype,
    extent,
    ierror
  );
}

void mpi_file_get_view_(
  const MPI_Fint *fh,
  MPI_Offset *disp,
  MPI_Fint *etype,
  MPI_Fint *filetype,
  char **datarep,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_get_view_ptr)(
    fh,
    disp,
    etype,
    filetype,
    datarep,
    ierror
  );
}

void mpi_file_iread_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iread_ptr)(
    fh,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iread_all_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iread_all_ptr)(
    fh,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iread_at_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iread_at_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iread_at_all_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iread_at_all_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iread_shared_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iread_shared_ptr)(
    fh,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iwrite_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iwrite_ptr)(
    fh,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iwrite_all_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iwrite_all_ptr)(
    fh,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iwrite_at_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iwrite_at_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iwrite_at_all_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iwrite_at_all_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_iwrite_shared_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *request,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_iwrite_shared_ptr)(
    fh,
    buf,
    count,
    datatype,
    request,
    ierror
  );
}

void mpi_file_open_(
  const MPI_Fint *comm,
  const char **filename,
  const MPI_Fint *amode,
  const MPI_Fint *info,
  MPI_Fint *fh,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_open_ptr)(
    comm,
    filename,
    amode,
    info,
    fh,
    ierror
  );
}

void mpi_file_preallocate_(
  const MPI_Fint *fh,
  const MPI_Offset *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_preallocate_ptr)(
    fh,
    size,
    ierror
  );
}

void mpi_file_read_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_read_all_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_all_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_read_all_begin_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_all_begin_ptr)(
    fh,
    buf,
    count,
    datatype,
    ierror
  );
}

void mpi_file_read_all_end_(
  const MPI_Fint *fh,
  void *buf,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_all_end_ptr)(
    fh,
    buf,
    status,
    ierror
  );
}

void mpi_file_read_at_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_at_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_read_at_all_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_at_all_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_read_at_all_begin_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_at_all_begin_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    ierror
  );
}

void mpi_file_read_at_all_end_(
  const MPI_Fint *fh,
  void *buf,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_at_all_end_ptr)(
    fh,
    buf,
    status,
    ierror
  );
}

void mpi_file_read_ordered_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_ordered_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_read_ordered_begin_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_ordered_begin_ptr)(
    fh,
    buf,
    count,
    datatype,
    ierror
  );
}

void mpi_file_read_ordered_end_(
  const MPI_Fint *fh,
  void *buf,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_ordered_end_ptr)(
    fh,
    buf,
    status,
    ierror
  );
}

void mpi_file_read_shared_(
  const MPI_Fint *fh,
  void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_read_shared_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_seek_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const MPI_Fint *whence,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_seek_ptr)(
    fh,
    offset,
    whence,
    ierror
  );
}

void mpi_file_seek_shared_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const MPI_Fint *whence,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_seek_shared_ptr)(
    fh,
    offset,
    whence,
    ierror
  );
}

void mpi_file_set_atomicity_(
  const MPI_Fint *fh,
  const MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_set_atomicity_ptr)(
    fh,
    flag,
    ierror
  );
}

void mpi_file_set_info_(
  const MPI_Fint *fh,
  const MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_set_info_ptr)(
    fh,
    info,
    ierror
  );
}

void mpi_file_set_size_(
  const MPI_Fint *fh,
  const MPI_Offset *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_set_size_ptr)(
    fh,
    size,
    ierror
  );
}

void mpi_file_set_view_(
  const MPI_Fint *fh,
  const MPI_Offset *disp,
  const MPI_Fint *etype,
  const MPI_Fint *filetype,
  const char **datarep,
  const MPI_Fint *info,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_set_view_ptr)(
    fh,
    disp,
    etype,
    filetype,
    datarep,
    info,
    ierror
  );
}

void mpi_file_sync_(
  const MPI_Fint *fh,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_sync_ptr)(
    fh,
    ierror
  );
}

void mpi_file_write_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_write_all_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_all_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_write_all_begin_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_all_begin_ptr)(
    fh,
    buf,
    count,
    datatype,
    ierror
  );
}

void mpi_file_write_all_end_(
  const MPI_Fint *fh,
  const void *buf,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_all_end_ptr)(
    fh,
    buf,
    status,
    ierror
  );
}

void mpi_file_write_at_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_at_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_write_at_all_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_at_all_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_write_at_all_begin_(
  const MPI_Fint *fh,
  const MPI_Offset *offset,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_at_all_begin_ptr)(
    fh,
    offset,
    buf,
    count,
    datatype,
    ierror
  );
}

void mpi_file_write_at_all_end_(
  const MPI_Fint *fh,
  const void *buf,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_at_all_end_ptr)(
    fh,
    buf,
    status,
    ierror
  );
}

void mpi_file_write_ordered_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_ordered_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_file_write_ordered_begin_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_ordered_begin_ptr)(
    fh,
    buf,
    count,
    datatype,
    ierror
  );
}

void mpi_file_write_ordered_end_(
  const MPI_Fint *fh,
  const void *buf,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_ordered_end_ptr)(
    fh,
    buf,
    status,
    ierror
  );
}

void mpi_file_write_shared_(
  const MPI_Fint *fh,
  const void *buf,
  const MPI_Fint *count,
  const MPI_Fint *datatype,
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  MPI_Fint *ierror
) {
  return (*mpiabi_file_write_shared_ptr)(
    fh,
    buf,
    count,
    datatype,
    status,
    ierror
  );
}

void mpi_register_datarep_(
  const char **datarep,
  const void (**read_conversion_fn)(void),
  const void (**write_conversion_fn)(void),
  const void (**dtype_file_extent_fn)(void),
  void *extra_state,
  MPI_Fint *ierror
) {
  return (*mpiabi_register_datarep_ptr)(
    datarep,
    read_conversion_fn,
    write_conversion_fn,
    dtype_file_extent_fn,
    extra_state,
    ierror
  );
}

void mpi_f_sync_reg_(
  void *buf
) {
  return (*mpiabi_f_sync_reg_ptr)(
    buf
  );
}

void mpi_type_create_f90_complex_(
  const MPI_Fint *p,
  const MPI_Fint *r,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_f90_complex_ptr)(
    p,
    r,
    newtype,
    ierror
  );
}

void mpi_type_create_f90_integer_(
  const MPI_Fint *r,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_f90_integer_ptr)(
    r,
    newtype,
    ierror
  );
}

void mpi_type_create_f90_real_(
  const MPI_Fint *p,
  const MPI_Fint *r,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_create_f90_real_ptr)(
    p,
    r,
    newtype,
    ierror
  );
}

void mpi_type_match_size_(
  const MPI_Fint *typeclass,
  const MPI_Fint *size,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_match_size_ptr)(
    typeclass,
    size,
    newtype,
    ierror
  );
}

void mpi_pcontrol_(
  const MPI_Fint *level
) {
  return (*mpiabi_pcontrol_ptr)(
    level
  );
}

void mpi_attr_delete_(
  const MPI_Fint *comm,
  const MPI_Fint *keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_attr_delete_ptr)(
    comm,
    keyval,
    ierror
  );
}

void mpi_attr_get_(
  const MPI_Fint *comm,
  const MPI_Fint *keyval,
  void *attribute_val,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_attr_get_ptr)(
    comm,
    keyval,
    attribute_val,
    flag,
    ierror
  );
}

void mpi_attr_put_(
  const MPI_Fint *comm,
  const MPI_Fint *keyval,
  void *attribute_val,
  MPI_Fint *ierror
) {
  return (*mpiabi_attr_put_ptr)(
    comm,
    keyval,
    attribute_val,
    ierror
  );
}

void mpi_get_elements_x_(
  const MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *datatype,
  MPI_Count *count,
  MPI_Fint *ierror
) {
  return (*mpiabi_get_elements_x_ptr)(
    status,
    datatype,
    count,
    ierror
  );
}

void mpi_info_get_(
  const MPI_Fint *info,
  const char **key,
  const MPI_Fint *valuelen,
  char **value,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_get_ptr)(
    info,
    key,
    valuelen,
    value,
    flag,
    ierror
  );
}

void mpi_info_get_valuelen_(
  const MPI_Fint *info,
  const char **key,
  MPI_Fint *valuelen,
  MPI_Fint *flag,
  MPI_Fint *ierror
) {
  return (*mpiabi_info_get_valuelen_ptr)(
    info,
    key,
    valuelen,
    flag,
    ierror
  );
}

void mpi_keyval_create_(
  const void (**copy_fn)(void),
  const void (**delete_fn)(void),
  MPI_Fint *keyval,
  void *extra_state,
  MPI_Fint *ierror
) {
  return (*mpiabi_keyval_create_ptr)(
    copy_fn,
    delete_fn,
    keyval,
    extra_state,
    ierror
  );
}

void mpi_keyval_free_(
  MPI_Fint *keyval,
  MPI_Fint *ierror
) {
  return (*mpiabi_keyval_free_ptr)(
    keyval,
    ierror
  );
}

void mpi_status_set_elements_x_(
  MPI_Fint *status[MPI_F_STATUS_SIZE],
  const MPI_Fint *datatype,
  const MPI_Count *count,
  MPI_Fint *ierror
) {
  return (*mpiabi_status_set_elements_x_ptr)(
    status,
    datatype,
    count,
    ierror
  );
}

void mpi_type_get_extent_x_(
  const MPI_Fint *datatype,
  MPI_Count *lb,
  MPI_Count *extent,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_extent_x_ptr)(
    datatype,
    lb,
    extent,
    ierror
  );
}

void mpi_type_get_true_extent_x_(
  const MPI_Fint *datatype,
  MPI_Count *true_lb,
  MPI_Count *true_extent,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_get_true_extent_x_ptr)(
    datatype,
    true_lb,
    true_extent,
    ierror
  );
}

void mpi_type_size_x_(
  const MPI_Fint *datatype,
  MPI_Count *size,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_size_x_ptr)(
    datatype,
    size,
    ierror
  );
}

void mpi_address_(
  void *location,
  MPI_Aint *address,
  MPI_Fint *ierror
) {
  return (*mpiabi_address_ptr)(
    location,
    address,
    ierror
  );
}

void mpi_type_hindexed_(
  const MPI_Fint *count,
  MPI_Fint *array_of_blocklengths,
  MPI_Aint *array_of_displacements,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_hindexed_ptr)(
    count,
    array_of_blocklengths,
    array_of_displacements,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_hvector_(
  const MPI_Fint *count,
  const MPI_Fint *blocklength,
  const MPI_Aint *stride,
  const MPI_Fint *oldtype,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_hvector_ptr)(
    count,
    blocklength,
    stride,
    oldtype,
    newtype,
    ierror
  );
}

void mpi_type_struct_(
  const MPI_Fint *count,
  MPI_Fint *array_of_blocklengths,
  MPI_Aint *array_of_displacements,
  MPI_Fint *array_of_types,
  MPI_Fint *newtype,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_struct_ptr)(
    count,
    array_of_blocklengths,
    array_of_displacements,
    array_of_types,
    newtype,
    ierror
  );
}

void mpi_type_extent_(
  const MPI_Fint *datatype,
  MPI_Aint *extent,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_extent_ptr)(
    datatype,
    extent,
    ierror
  );
}

void mpi_type_lb_(
  const MPI_Fint *datatype,
  MPI_Aint *displacement,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_lb_ptr)(
    datatype,
    displacement,
    ierror
  );
}

void mpi_type_ub_(
  const MPI_Fint *datatype,
  MPI_Aint *displacement,
  MPI_Fint *ierror
) {
  return (*mpiabi_type_ub_ptr)(
    datatype,
    displacement,
    ierror
  );
}

