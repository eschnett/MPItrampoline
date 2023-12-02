// MPIABI Fortran function pointers

// This file has been generated automatically
// by `mpitrampoline/generate_trampoline.jl`.
// Do not modify this file, changes will be overwritten.

#include <mpi.h>
#include <mpiabi_version.h>
#include <mpiabi_function_pointers_fortran.h>

void mpitrampoline_init(void);

#ifdef __APPLE__
#define CONSTRUCTOR_PRIORITY
#else
#define CONSTRUCTOR_PRIORITY (1000)
#endif
static void __attribute__((__constructor__ CONSTRUCTOR_PRIORITY))
mpitrampoline_init_auto(void) {
  mpitrampoline_init();
}


void (*mpiabi_bsend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_bsend_init_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_buffer_attach_ptr)(
  void *buffer,
  const MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_buffer_detach_ptr)(
  MPIABI_Aint *buffer_addr,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_buffer_flush_ptr)(
  MPIABI_Fint *ierror
);

void (*mpiabi_buffer_iflush_ptr)(
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_cancel_ptr)(
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_attach_buffer_ptr)(
  const MPIABI_Fint *comm,
  const void *buffer,
  const MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_detach_buffer_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Aint *buffer_addr,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_flush_buffer_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_iflush_buffer_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_count_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *datatype,
  MPIABI_Fint *count,
  MPIABI_Fint *ierror
);

void (*mpiabi_ibsend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_improbe_ptr)(
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *flag,
  MPIABI_Fint *message,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_imrecv_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *message,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iprobe_ptr)(
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *flag,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_irecv_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_irsend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_isend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_isendrecv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *sendtag,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *recvtag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_isendrecv_replace_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *sendtag,
  const MPIABI_Fint *source,
  const MPIABI_Fint *recvtag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_issend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_mprobe_ptr)(
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *message,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_mrecv_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *message,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_probe_ptr)(
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_recv_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_recv_init_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_request_free_ptr)(
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_request_get_status_ptr)(
  const MPIABI_Fint *request,
  MPIABI_Fint *flag,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_request_get_status_all_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *array_of_requests,
  MPIABI_Fint *flag,
  MPIABI_Fint *array_of_statuses[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_request_get_status_any_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *array_of_requests,
  MPIABI_Fint *index,
  MPIABI_Fint *flag,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_request_get_status_some_ptr)(
  const MPIABI_Fint *incount,
  const MPIABI_Fint *array_of_requests,
  MPIABI_Fint *outcount,
  MPIABI_Fint *array_of_indices,
  MPIABI_Fint *array_of_statuses[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_rsend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_rsend_init_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_send_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_send_init_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_sendrecv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *sendtag,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *recvtag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_sendrecv_replace_ptr)(
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *sendtag,
  const MPIABI_Fint *source,
  const MPIABI_Fint *recvtag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_session_attach_buffer_ptr)(
  const MPIABI_Fint *session,
  const void *buffer,
  const MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_detach_buffer_ptr)(
  const MPIABI_Fint *session,
  MPIABI_Aint *buffer_addr,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_flush_buffer_ptr)(
  const MPIABI_Fint *session,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_iflush_buffer_ptr)(
  const MPIABI_Fint *session,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ssend_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_ssend_init_ptr)(
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *dest,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_start_ptr)(
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_startall_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_get_error_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *err,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_get_source_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *source,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_get_tag_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *tag,
  MPIABI_Fint *ierror
);

void (*mpiabi_test_ptr)(
  MPIABI_Fint *request,
  MPIABI_Fint *flag,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_test_cancelled_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_testall_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *flag,
  MPIABI_Fint *array_of_statuses[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_testany_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *index,
  MPIABI_Fint *flag,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_testsome_ptr)(
  const MPIABI_Fint *incount,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *outcount,
  MPIABI_Fint *array_of_indices,
  MPIABI_Fint *array_of_statuses[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_wait_ptr)(
  MPIABI_Fint *request,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_waitall_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *array_of_statuses[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_waitany_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *index,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_waitsome_ptr)(
  const MPIABI_Fint *incount,
  MPIABI_Fint *array_of_requests,
  MPIABI_Fint *outcount,
  MPIABI_Fint *array_of_indices,
  MPIABI_Fint *array_of_statuses[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_parrived_ptr)(
  const MPIABI_Fint *request,
  const MPIABI_Fint *partition,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_pready_ptr)(
  const MPIABI_Fint *partition,
  const MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_pready_list_ptr)(
  const MPIABI_Fint *length,
  const MPIABI_Fint *array_of_partitions,
  const MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_pready_range_ptr)(
  const MPIABI_Fint *partition_low,
  const MPIABI_Fint *partition_high,
  const MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_precv_init_ptr)(
  void *buf,
  const MPIABI_Fint *partitions,
  const MPIABI_Count *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_psend_init_ptr)(
  void *buf,
  const MPIABI_Fint *partitions,
  const MPIABI_Count *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *source,
  const MPIABI_Fint *tag,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

MPIABI_Aint (*mpiabi_aint_add_ptr)(
  const MPIABI_Aint *base,
  const MPIABI_Aint *disp
);

MPIABI_Aint (*mpiabi_aint_diff_ptr)(
  const MPIABI_Aint *addr1,
  const MPIABI_Aint *addr2
);

void (*mpiabi_get_address_ptr)(
  const void *location,
  MPIABI_Aint *address,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_elements_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *datatype,
  MPIABI_Fint *count,
  MPIABI_Fint *ierror
);

void (*mpiabi_pack_ptr)(
  const void *inbuf,
  const MPIABI_Fint *incount,
  const MPIABI_Fint *datatype,
  void *outbuf,
  const MPIABI_Fint *outsize,
  MPIABI_Fint *position,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_pack_external_ptr)(
  const char **datarep,
  const void *inbuf,
  const MPIABI_Fint *incount,
  const MPIABI_Fint *datatype,
  void *outbuf,
  const MPIABI_Aint *outsize,
  MPIABI_Aint *position,
  MPIABI_Fint *ierror
);

void (*mpiabi_pack_external_size_ptr)(
  const char **datarep,
  const MPIABI_Count *incount,
  const MPIABI_Fint *datatype,
  MPIABI_Aint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_pack_size_ptr)(
  const MPIABI_Fint *incount,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_commit_ptr)(
  MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_contiguous_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_darray_ptr)(
  const MPIABI_Fint *size,
  const MPIABI_Fint *rank,
  const MPIABI_Fint *ndims,
  const MPIABI_Fint *array_of_gsizes,
  const MPIABI_Fint *array_of_distribs,
  const MPIABI_Fint *array_of_dargs,
  const MPIABI_Fint *array_of_psizes,
  const MPIABI_Fint *order,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_hindexed_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *array_of_blocklengths,
  const MPIABI_Aint *array_of_displacements,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_hindexed_block_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *blocklength,
  const MPIABI_Aint *array_of_displacements,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_hvector_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *blocklength,
  const MPIABI_Aint *stride,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_indexed_block_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *blocklength,
  const MPIABI_Fint *array_of_displacements,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_resized_ptr)(
  const MPIABI_Fint *oldtype,
  const MPIABI_Aint *lb,
  const MPIABI_Aint *extent,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_struct_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *array_of_blocklengths,
  const MPIABI_Aint *array_of_displacements,
  const MPIABI_Fint *array_of_types,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_subarray_ptr)(
  const MPIABI_Fint *ndims,
  const MPIABI_Fint *array_of_sizes,
  const MPIABI_Fint *array_of_subsizes,
  const MPIABI_Fint *array_of_starts,
  const MPIABI_Fint *order,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_dup_ptr)(
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_free_ptr)(
  MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_contents_ptr)(
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *max_integers,
  const MPIABI_Fint *max_addresses,
  const MPIABI_Fint *max_datatypes,
  MPIABI_Fint *array_of_integers,
  MPIABI_Aint *array_of_addresses,
  MPIABI_Fint *array_of_datatypes,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_envelope_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Fint *num_integers,
  MPIABI_Fint *num_addresses,
  MPIABI_Fint *num_datatypes,
  MPIABI_Fint *combiner,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_extent_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Aint *lb,
  MPIABI_Aint *extent,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_true_extent_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Aint *true_lb,
  MPIABI_Aint *true_extent,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_indexed_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *array_of_blocklengths,
  const MPIABI_Fint *array_of_displacements,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_size_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_vector_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *blocklength,
  const MPIABI_Fint *stride,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_unpack_ptr)(
  const void *inbuf,
  const MPIABI_Fint *insize,
  MPIABI_Fint *position,
  void *outbuf,
  const MPIABI_Fint *outcount,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_unpack_external_ptr)(
  const char **datarep,
  const void *inbuf,
  const MPIABI_Aint *insize,
  MPIABI_Aint *position,
  void *outbuf,
  const MPIABI_Fint *outcount,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_allgather_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_allgather_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_allgatherv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_allgatherv_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_allreduce_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_allreduce_init_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_alltoall_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_alltoall_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_alltoallv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_alltoallv_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_alltoallw_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtypes,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtypes,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_alltoallw_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtypes,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtypes,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_barrier_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_barrier_init_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_bcast_ptr)(
  void *buffer,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_bcast_init_ptr)(
  void *buffer,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_exscan_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_exscan_init_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_gather_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_gather_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_gatherv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_gatherv_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iallgather_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iallgatherv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iallreduce_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ialltoall_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ialltoallv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ialltoallw_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtypes,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtypes,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ibarrier_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ibcast_ptr)(
  void *buffer,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iexscan_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_igather_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_igatherv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ireduce_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ireduce_scatter_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ireduce_scatter_block_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iscan_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iscatter_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_iscatterv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_op_commutative_ptr)(
  const MPIABI_Fint *op,
  MPIABI_Fint *commute,
  MPIABI_Fint *ierror
);

void (*mpiabi_op_create_ptr)(
  const void (**user_fn)(void),
  const MPIABI_Fint *commute,
  MPIABI_Fint *op,
  MPIABI_Fint *ierror
);

void (*mpiabi_op_free_ptr)(
  MPIABI_Fint *op,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_init_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_local_ptr)(
  const void *inbuf,
  void *inoutbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_scatter_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_scatter_block_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_scatter_block_init_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_reduce_scatter_init_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_scan_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_scan_init_ptr)(
  const void *sendbuf,
  void *recvbuf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_scatter_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_scatter_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_scatterv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_scatterv_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_value_index_ptr)(
  const MPIABI_Fint *value_type,
  const MPIABI_Fint *index_type,
  MPIABI_Fint *pair_type,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_compare_ptr)(
  const MPIABI_Fint *comm1,
  const MPIABI_Fint *comm2,
  MPIABI_Fint *result,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_create_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *group,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_create_from_group_ptr)(
  const MPIABI_Fint *group,
  const char **stringtag,
  const MPIABI_Fint *info,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_create_group_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *group,
  const MPIABI_Fint *tag,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_create_keyval_ptr)(
  const void (**comm_copy_attr_fn)(void),
  const void (**comm_delete_attr_fn)(void),
  MPIABI_Fint *comm_keyval,
  void *extra_state,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_delete_attr_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *comm_keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_dup_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_dup_with_info_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_free_ptr)(
  MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_get_name_ptr)(
  const MPIABI_Fint *comm,
  char **comm_name,
  MPIABI_Fint *resultlen,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_free_keyval_ptr)(
  MPIABI_Fint *comm_keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_get_attr_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *comm_keyval,
  void *attribute_val,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_get_info_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *info_used,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_group_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *group,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_idup_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_idup_with_info_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_rank_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *rank,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_remote_group_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *group,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_remote_size_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_set_attr_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *comm_keyval,
  void *attribute_val,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_set_info_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_set_name_ptr)(
  const MPIABI_Fint *comm,
  const char **comm_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_size_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_split_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *color,
  const MPIABI_Fint *key,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_free_ptr)(
  MPIABI_Fint *group,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_split_type_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *split_type,
  const MPIABI_Fint *key,
  const MPIABI_Fint *info,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_test_inter_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_compare_ptr)(
  const MPIABI_Fint *group1,
  const MPIABI_Fint *group2,
  MPIABI_Fint *result,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_difference_ptr)(
  const MPIABI_Fint *group1,
  const MPIABI_Fint *group2,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_excl_ptr)(
  const MPIABI_Fint *group,
  const MPIABI_Fint *n,
  const MPIABI_Fint *ranks,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_from_session_pset_ptr)(
  const MPIABI_Fint *session,
  const char **pset_name,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_incl_ptr)(
  const MPIABI_Fint *group,
  const MPIABI_Fint *n,
  const MPIABI_Fint *ranks,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_intersection_ptr)(
  const MPIABI_Fint *group1,
  const MPIABI_Fint *group2,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_range_excl_ptr)(
  const MPIABI_Fint *group,
  const MPIABI_Fint *n,
  const MPIABI_Fint *ranges,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_range_incl_ptr)(
  const MPIABI_Fint *group,
  const MPIABI_Fint *n,
  const MPIABI_Fint *ranges,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_rank_ptr)(
  const MPIABI_Fint *group,
  MPIABI_Fint *rank,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_size_ptr)(
  const MPIABI_Fint *group,
  MPIABI_Fint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_translate_ranks_ptr)(
  const MPIABI_Fint *group1,
  const MPIABI_Fint *n,
  const MPIABI_Fint *ranks1,
  const MPIABI_Fint *group2,
  const MPIABI_Fint *ranks2,
  MPIABI_Fint *ierror
);

void (*mpiabi_group_union_ptr)(
  const MPIABI_Fint *group1,
  const MPIABI_Fint *group2,
  MPIABI_Fint *newgroup,
  MPIABI_Fint *ierror
);

void (*mpiabi_intercomm_create_ptr)(
  const MPIABI_Fint *local_comm,
  const MPIABI_Fint *local_leader,
  const MPIABI_Fint *peer_comm,
  const MPIABI_Fint *remote_leader,
  const MPIABI_Fint *tag,
  MPIABI_Fint *newintercomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_intercomm_create_from_groups_ptr)(
  const MPIABI_Fint *local_group,
  const MPIABI_Fint *local_leader,
  const MPIABI_Fint *remote_group,
  const MPIABI_Fint *remote_leader,
  const char **stringtag,
  const MPIABI_Fint *info,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *newintercomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_intercomm_merge_ptr)(
  const MPIABI_Fint *intercomm,
  const MPIABI_Fint *high,
  MPIABI_Fint *newintracomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_keyval_ptr)(
  const void (**type_copy_attr_fn)(void),
  const void (**type_delete_attr_fn)(void),
  MPIABI_Fint *type_keyval,
  void *extra_state,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_delete_attr_ptr)(
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *type_keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_free_keyval_ptr)(
  MPIABI_Fint *type_keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_attr_ptr)(
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *type_keyval,
  void *attribute_val,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_name_ptr)(
  const MPIABI_Fint *datatype,
  char **type_name,
  MPIABI_Fint *resultlen,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_set_attr_ptr)(
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *type_keyval,
  void *attribute_val,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_set_name_ptr)(
  const MPIABI_Fint *datatype,
  const char **type_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_create_keyval_ptr)(
  const void (**win_copy_attr_fn)(void),
  const void (**win_delete_attr_fn)(void),
  MPIABI_Fint *win_keyval,
  void *extra_state,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_delete_attr_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *win_keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_free_keyval_ptr)(
  MPIABI_Fint *win_keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_get_attr_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *win_keyval,
  void *attribute_val,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_get_name_ptr)(
  const MPIABI_Fint *win,
  char **win_name,
  MPIABI_Fint *resultlen,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_set_attr_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *win_keyval,
  void *attribute_val,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_set_name_ptr)(
  const MPIABI_Fint *win,
  const char **win_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_coords_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *rank,
  const MPIABI_Fint *maxdims,
  MPIABI_Fint *coords,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_create_ptr)(
  const MPIABI_Fint *comm_old,
  const MPIABI_Fint *ndims,
  const MPIABI_Fint *dims,
  const MPIABI_Fint *periods,
  const MPIABI_Fint *reorder,
  MPIABI_Fint *comm_cart,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_get_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *maxdims,
  MPIABI_Fint *dims,
  MPIABI_Fint *periods,
  MPIABI_Fint *coords,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_map_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *ndims,
  const MPIABI_Fint *dims,
  const MPIABI_Fint *periods,
  MPIABI_Fint *newrank,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_rank_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *coords,
  MPIABI_Fint *rank,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_shift_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *direction,
  const MPIABI_Fint *disp,
  MPIABI_Fint *rank_source,
  MPIABI_Fint *rank_dest,
  MPIABI_Fint *ierror
);

void (*mpiabi_cart_sub_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *remain_dims,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_cartdim_get_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *ndims,
  MPIABI_Fint *ierror
);

void (*mpiabi_dims_create_ptr)(
  const MPIABI_Fint *nnodes,
  const MPIABI_Fint *ndims,
  const MPIABI_Fint *dims,
  MPIABI_Fint *ierror
);

void (*mpiabi_dist_graph_create_ptr)(
  const MPIABI_Fint *comm_old,
  const MPIABI_Fint *n,
  const MPIABI_Fint *sources,
  const MPIABI_Fint *degrees,
  const MPIABI_Fint *destinations,
  const MPIABI_Fint *weights,
  const MPIABI_Fint *info,
  const MPIABI_Fint *reorder,
  MPIABI_Fint *comm_dist_graph,
  MPIABI_Fint *ierror
);

void (*mpiabi_dist_graph_create_adjacent_ptr)(
  const MPIABI_Fint *comm_old,
  const MPIABI_Fint *indegree,
  const MPIABI_Fint *sources,
  const MPIABI_Fint *sourceweights,
  const MPIABI_Fint *outdegree,
  const MPIABI_Fint *destinations,
  const MPIABI_Fint *destweights,
  const MPIABI_Fint *info,
  const MPIABI_Fint *reorder,
  MPIABI_Fint *comm_dist_graph,
  MPIABI_Fint *ierror
);

void (*mpiabi_dist_graph_neighbors_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *maxindegree,
  MPIABI_Fint *sources,
  MPIABI_Fint *sourceweights,
  const MPIABI_Fint *maxoutdegree,
  MPIABI_Fint *destinations,
  MPIABI_Fint *destweights,
  MPIABI_Fint *ierror
);

void (*mpiabi_dist_graph_neighbors_count_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *indegree,
  MPIABI_Fint *outdegree,
  MPIABI_Fint *weighted,
  MPIABI_Fint *ierror
);

void (*mpiabi_graph_create_ptr)(
  const MPIABI_Fint *comm_old,
  const MPIABI_Fint *nnodes,
  const MPIABI_Fint *index,
  const MPIABI_Fint *edges,
  const MPIABI_Fint *reorder,
  MPIABI_Fint *comm_graph,
  MPIABI_Fint *ierror
);

void (*mpiabi_graph_get_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *maxindex,
  const MPIABI_Fint *maxedges,
  MPIABI_Fint *index,
  MPIABI_Fint *edges,
  MPIABI_Fint *ierror
);

void (*mpiabi_graph_map_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *nnodes,
  const MPIABI_Fint *index,
  const MPIABI_Fint *edges,
  MPIABI_Fint *newrank,
  MPIABI_Fint *ierror
);

void (*mpiabi_graph_neighbors_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *rank,
  const MPIABI_Fint *maxneighbors,
  MPIABI_Fint *neighbors,
  MPIABI_Fint *ierror
);

void (*mpiabi_graph_neighbors_count_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *rank,
  MPIABI_Fint *nneighbors,
  MPIABI_Fint *ierror
);

void (*mpiabi_graphdims_get_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *nnodes,
  MPIABI_Fint *nedges,
  MPIABI_Fint *ierror
);

void (*mpiabi_ineighbor_allgather_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ineighbor_allgatherv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ineighbor_alltoall_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ineighbor_alltoallv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_ineighbor_alltoallw_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Aint *sdispls,
  const MPIABI_Fint *sendtypes,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Aint *rdispls,
  const MPIABI_Fint *recvtypes,
  const MPIABI_Fint *comm,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_allgather_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_allgather_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_allgatherv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Aint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_allgatherv_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Aint *displs,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_alltoall_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_alltoall_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcount,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcount,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_alltoallv_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_alltoallv_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Fint *sdispls,
  const MPIABI_Fint *sendtype,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Fint *rdispls,
  const MPIABI_Fint *recvtype,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_alltoallw_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Aint *sdispls,
  const MPIABI_Fint *sendtypes,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Aint *rdispls,
  const MPIABI_Fint *recvtypes,
  const MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_neighbor_alltoallw_init_ptr)(
  const void *sendbuf,
  const MPIABI_Fint *sendcounts,
  const MPIABI_Aint *sdispls,
  const MPIABI_Fint *sendtypes,
  void *recvbuf,
  const MPIABI_Fint *recvcounts,
  const MPIABI_Aint *rdispls,
  const MPIABI_Fint *recvtypes,
  const MPIABI_Fint *comm,
  const MPIABI_Fint *info,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_topo_test_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *status,
  MPIABI_Fint *ierror
);

void (*mpiabi_add_error_class_ptr)(
  MPIABI_Fint *errorclass,
  MPIABI_Fint *ierror
);

void (*mpiabi_add_error_code_ptr)(
  const MPIABI_Fint *errorclass,
  MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_add_error_string_ptr)(
  const MPIABI_Fint *errorcode,
  const char **string,
  MPIABI_Fint *ierror
);

void (*mpiabi_alloc_mem_ptr)(
  const MPIABI_Aint *size,
  const MPIABI_Fint *info,
  void *baseptr,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_call_errhandler_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_create_errhandler_ptr)(
  const void (**comm_errhandler_fn)(void),
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_get_errhandler_ptr)(
  const MPIABI_Fint *comm,
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_set_errhandler_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_errhandler_free_ptr)(
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_error_class_ptr)(
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *errorclass,
  MPIABI_Fint *ierror
);

void (*mpiabi_error_string_ptr)(
  const MPIABI_Fint *errorcode,
  char **string,
  MPIABI_Fint *resultlen,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_call_errhandler_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_create_errhandler_ptr)(
  const void (**file_errhandler_fn)(void),
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_errhandler_ptr)(
  const MPIABI_Fint *file,
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_set_errhandler_ptr)(
  const MPIABI_Fint *file,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_free_mem_ptr)(
  void *base,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_hw_resource_info_ptr)(
  MPIABI_Fint *hw_info,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_library_version_ptr)(
  char **version,
  MPIABI_Fint *resultlen,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_processor_name_ptr)(
  char **name,
  MPIABI_Fint *resultlen,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_version_ptr)(
  MPIABI_Fint *version,
  MPIABI_Fint *subversion,
  MPIABI_Fint *ierror
);

void (*mpiabi_remove_error_class_ptr)(
  const MPIABI_Fint *errorclass,
  MPIABI_Fint *ierror
);

void (*mpiabi_remove_error_code_ptr)(
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_remove_error_string_ptr)(
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_call_errhandler_ptr)(
  const MPIABI_Fint *session,
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_create_errhandler_ptr)(
  const void (**session_errhandler_fn)(void),
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_get_errhandler_ptr)(
  const MPIABI_Fint *session,
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_set_errhandler_ptr)(
  const MPIABI_Fint *session,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_call_errhandler_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_create_errhandler_ptr)(
  const void (**win_errhandler_fn)(void),
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_get_errhandler_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_set_errhandler_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *ierror
);

double (*mpiabi_wtick_ptr)(
);

double (*mpiabi_wtime_ptr)(
);

void (*mpiabi_info_create_ptr)(
  MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_create_env_ptr)(
  MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_delete_ptr)(
  const MPIABI_Fint *info,
  const char **key,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_dup_ptr)(
  const MPIABI_Fint *info,
  MPIABI_Fint *newinfo,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_free_ptr)(
  MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_get_nkeys_ptr)(
  const MPIABI_Fint *info,
  MPIABI_Fint *nkeys,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_get_nthkey_ptr)(
  const MPIABI_Fint *info,
  const MPIABI_Fint *n,
  char **key,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_get_string_ptr)(
  const MPIABI_Fint *info,
  const char **key,
  MPIABI_Fint *buflen,
  char **value,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_set_ptr)(
  const MPIABI_Fint *info,
  const char **key,
  const char **value,
  MPIABI_Fint *ierror
);

void (*mpiabi_abort_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *errorcode,
  MPIABI_Fint *ierror
);

void (*mpiabi_close_port_ptr)(
  const char **port_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_accept_ptr)(
  const char **port_name,
  const MPIABI_Fint *info,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_connect_ptr)(
  const char **port_name,
  const MPIABI_Fint *info,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *newcomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_disconnect_ptr)(
  MPIABI_Fint *comm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_get_parent_ptr)(
  MPIABI_Fint *parent,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_join_ptr)(
  const MPIABI_Fint *fd,
  MPIABI_Fint *intercomm,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_spawn_ptr)(
  const char **command,
  const char **argv,
  const MPIABI_Fint *maxprocs,
  const MPIABI_Fint *info,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *intercomm,
  MPIABI_Fint *array_of_errcodes,
  MPIABI_Fint *ierror
);

void (*mpiabi_comm_spawn_multiple_ptr)(
  const MPIABI_Fint *count,
  const char **array_of_commands,
  const char **array_of_argv,
  const MPIABI_Fint *array_of_maxprocs,
  const MPIABI_Fint *array_of_info,
  const MPIABI_Fint *root,
  const MPIABI_Fint *comm,
  MPIABI_Fint *intercomm,
  MPIABI_Fint *array_of_errcodes,
  MPIABI_Fint *ierror
);

void (*mpiabi_finalize_ptr)(
  MPIABI_Fint *ierror
);

void (*mpiabi_finalized_ptr)(
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_init_ptr)(
  MPIABI_Fint *ierror
);

void (*mpiabi_init_thread_ptr)(
  const MPIABI_Fint *required,
  MPIABI_Fint *provided,
  MPIABI_Fint *ierror
);

void (*mpiabi_initialized_ptr)(
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_is_thread_main_ptr)(
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_lookup_name_ptr)(
  const char **service_name,
  const MPIABI_Fint *info,
  char **port_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_open_port_ptr)(
  const MPIABI_Fint *info,
  char **port_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_publish_name_ptr)(
  const char **service_name,
  const MPIABI_Fint *info,
  const char **port_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_query_thread_ptr)(
  MPIABI_Fint *provided,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_finalize_ptr)(
  MPIABI_Fint *session,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_get_info_ptr)(
  const MPIABI_Fint *session,
  MPIABI_Fint *info_used,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_get_nth_pset_ptr)(
  const MPIABI_Fint *session,
  const MPIABI_Fint *info,
  const MPIABI_Fint *n,
  MPIABI_Fint *pset_len,
  char **pset_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_get_num_psets_ptr)(
  const MPIABI_Fint *session,
  const MPIABI_Fint *info,
  MPIABI_Fint *npset_names,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_get_pset_info_ptr)(
  const MPIABI_Fint *session,
  const char **pset_name,
  MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_session_init_ptr)(
  const MPIABI_Fint *info,
  const MPIABI_Fint *errhandler,
  MPIABI_Fint *session,
  MPIABI_Fint *ierror
);

void (*mpiabi_unpublish_name_ptr)(
  const char **service_name,
  const MPIABI_Fint *info,
  const char **port_name,
  MPIABI_Fint *ierror
);

void (*mpiabi_accumulate_ptr)(
  const void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_compare_and_swap_ptr)(
  const void *origin_addr,
  const void *compare_addr,
  void *result_addr,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_fetch_and_op_ptr)(
  const void *origin_addr,
  void *result_addr,
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *op,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_ptr)(
  void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_accumulate_ptr)(
  const void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  void *result_addr,
  const MPIABI_Fint *result_count,
  const MPIABI_Fint *result_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_put_ptr)(
  const void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_raccumulate_ptr)(
  const void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *win,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_rget_ptr)(
  void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *win,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_rget_accumulate_ptr)(
  const void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  void *result_addr,
  const MPIABI_Fint *result_count,
  const MPIABI_Fint *result_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *op,
  const MPIABI_Fint *win,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_rput_ptr)(
  const void *origin_addr,
  const MPIABI_Fint *origin_count,
  const MPIABI_Fint *origin_datatype,
  const MPIABI_Fint *target_rank,
  const MPIABI_Aint *target_disp,
  const MPIABI_Fint *target_count,
  const MPIABI_Fint *target_datatype,
  const MPIABI_Fint *win,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_allocate_ptr)(
  const MPIABI_Aint *size,
  const MPIABI_Fint *disp_unit,
  const MPIABI_Fint *info,
  const MPIABI_Fint *comm,
  void *baseptr,
  MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_allocate_shared_ptr)(
  const MPIABI_Aint *size,
  const MPIABI_Fint *disp_unit,
  const MPIABI_Fint *info,
  const MPIABI_Fint *comm,
  void *baseptr,
  MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_attach_ptr)(
  const MPIABI_Fint *win,
  void *base,
  const MPIABI_Aint *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_complete_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_create_ptr)(
  void *base,
  const MPIABI_Aint *size,
  const MPIABI_Fint *disp_unit,
  const MPIABI_Fint *info,
  const MPIABI_Fint *comm,
  MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_create_dynamic_ptr)(
  const MPIABI_Fint *info,
  const MPIABI_Fint *comm,
  MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_detach_ptr)(
  const MPIABI_Fint *win,
  const void *base,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_fence_ptr)(
  const MPIABI_Fint *assert,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_flush_ptr)(
  const MPIABI_Fint *rank,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_flush_all_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_flush_local_ptr)(
  const MPIABI_Fint *rank,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_flush_local_all_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_free_ptr)(
  MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_get_group_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *group,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_get_info_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *info_used,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_lock_ptr)(
  const MPIABI_Fint *lock_type,
  const MPIABI_Fint *rank,
  const MPIABI_Fint *assert,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_lock_all_ptr)(
  const MPIABI_Fint *assert,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_post_ptr)(
  const MPIABI_Fint *group,
  const MPIABI_Fint *assert,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_set_info_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_shared_query_ptr)(
  const MPIABI_Fint *win,
  const MPIABI_Fint *rank,
  MPIABI_Aint *size,
  MPIABI_Fint *disp_unit,
  void *baseptr,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_start_ptr)(
  const MPIABI_Fint *group,
  const MPIABI_Fint *assert,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_sync_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_test_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_unlock_ptr)(
  const MPIABI_Fint *rank,
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_unlock_all_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_win_wait_ptr)(
  const MPIABI_Fint *win,
  MPIABI_Fint *ierror
);

void (*mpiabi_grequest_complete_ptr)(
  const MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_grequest_start_ptr)(
  const void (**query_fn)(void),
  const void (**free_fn)(void),
  const void (**cancel_fn)(void),
  void *extra_state,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_set_cancelled_ptr)(
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_set_elements_ptr)(
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *datatype,
  const MPIABI_Fint *count,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_set_error_ptr)(
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *err,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_set_source_ptr)(
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *source,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_set_tag_ptr)(
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *tag,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_close_ptr)(
  MPIABI_Fint *fh,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_delete_ptr)(
  const char **filename,
  const MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_amode_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Fint *amode,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_atomicity_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_byte_offset_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  MPIABI_Offset *disp,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_group_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Fint *group,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_info_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Fint *info_used,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_position_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Offset *offset,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_position_shared_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Offset *offset,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_size_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Offset *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_type_extent_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Fint *datatype,
  MPIABI_Aint *extent,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_get_view_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Offset *disp,
  MPIABI_Fint *etype,
  MPIABI_Fint *filetype,
  char **datarep,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iread_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iread_all_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iread_at_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iread_at_all_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iread_shared_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iwrite_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iwrite_all_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iwrite_at_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iwrite_at_all_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_iwrite_shared_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *request,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_open_ptr)(
  const MPIABI_Fint *comm,
  const char **filename,
  const MPIABI_Fint *amode,
  const MPIABI_Fint *info,
  MPIABI_Fint *fh,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_preallocate_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_all_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_all_begin_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_all_end_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_at_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_at_all_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_at_all_begin_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_at_all_end_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_ordered_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_ordered_begin_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_ordered_end_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_read_shared_ptr)(
  const MPIABI_Fint *fh,
  void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_seek_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const MPIABI_Fint *whence,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_seek_shared_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const MPIABI_Fint *whence,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_set_atomicity_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_set_info_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_set_size_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_set_view_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *disp,
  const MPIABI_Fint *etype,
  const MPIABI_Fint *filetype,
  const char **datarep,
  const MPIABI_Fint *info,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_sync_ptr)(
  const MPIABI_Fint *fh,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_all_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_all_begin_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_all_end_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_at_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_at_all_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_at_all_begin_ptr)(
  const MPIABI_Fint *fh,
  const MPIABI_Offset *offset,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_at_all_end_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_ordered_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_ordered_begin_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_ordered_end_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_file_write_shared_ptr)(
  const MPIABI_Fint *fh,
  const void *buf,
  const MPIABI_Fint *count,
  const MPIABI_Fint *datatype,
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  MPIABI_Fint *ierror
);

void (*mpiabi_register_datarep_ptr)(
  const char **datarep,
  const void (**read_conversion_fn)(void),
  const void (**write_conversion_fn)(void),
  const void (**dtype_file_extent_fn)(void),
  void *extra_state,
  MPIABI_Fint *ierror
);

void (*mpiabi_f_sync_reg_ptr)(
  void *buf
);

void (*mpiabi_type_create_f90_complex_ptr)(
  const MPIABI_Fint *p,
  const MPIABI_Fint *r,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_f90_integer_ptr)(
  const MPIABI_Fint *r,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_create_f90_real_ptr)(
  const MPIABI_Fint *p,
  const MPIABI_Fint *r,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_match_size_ptr)(
  const MPIABI_Fint *typeclass,
  const MPIABI_Fint *size,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_pcontrol_ptr)(
  const MPIABI_Fint *level
);

void (*mpiabi_attr_delete_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_attr_get_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *keyval,
  void *attribute_val,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_attr_put_ptr)(
  const MPIABI_Fint *comm,
  const MPIABI_Fint *keyval,
  void *attribute_val,
  MPIABI_Fint *ierror
);

void (*mpiabi_get_elements_x_ptr)(
  const MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *datatype,
  MPIABI_Count *count,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_get_ptr)(
  const MPIABI_Fint *info,
  const char **key,
  const MPIABI_Fint *valuelen,
  char **value,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_info_get_valuelen_ptr)(
  const MPIABI_Fint *info,
  const char **key,
  MPIABI_Fint *valuelen,
  MPIABI_Fint *flag,
  MPIABI_Fint *ierror
);

void (*mpiabi_keyval_create_ptr)(
  const void (**copy_fn)(void),
  const void (**delete_fn)(void),
  MPIABI_Fint *keyval,
  void *extra_state,
  MPIABI_Fint *ierror
);

void (*mpiabi_keyval_free_ptr)(
  MPIABI_Fint *keyval,
  MPIABI_Fint *ierror
);

void (*mpiabi_status_set_elements_x_ptr)(
  MPIABI_Fint *status[MPIABI_F_STATUS_SIZE],
  const MPIABI_Fint *datatype,
  const MPIABI_Count *count,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_extent_x_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Count *lb,
  MPIABI_Count *extent,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_get_true_extent_x_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Count *true_lb,
  MPIABI_Count *true_extent,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_size_x_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Count *size,
  MPIABI_Fint *ierror
);

void (*mpiabi_address_ptr)(
  void *location,
  MPIABI_Aint *address,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_hindexed_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_blocklengths,
  MPIABI_Aint *array_of_displacements,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_hvector_ptr)(
  const MPIABI_Fint *count,
  const MPIABI_Fint *blocklength,
  const MPIABI_Aint *stride,
  const MPIABI_Fint *oldtype,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_struct_ptr)(
  const MPIABI_Fint *count,
  MPIABI_Fint *array_of_blocklengths,
  MPIABI_Aint *array_of_displacements,
  MPIABI_Fint *array_of_types,
  MPIABI_Fint *newtype,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_extent_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Aint *extent,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_lb_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Aint *displacement,
  MPIABI_Fint *ierror
);

void (*mpiabi_type_ub_ptr)(
  const MPIABI_Fint *datatype,
  MPIABI_Aint *displacement,
  MPIABI_Fint *ierror
);

