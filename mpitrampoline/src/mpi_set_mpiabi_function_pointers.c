// Declare pointers to MPIABI functions

#include <mpi_mpiabi_function_pointers.h>

void *mpitrampoline_get_symbol(void *handle, const char *name);

void mpi_set_mpiabi_function_pointers(void *handle) {

  // A.3 C Bindings

  // A.3.1 Point-to-Point Communication C Bindings

  MPIABI_Bsend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Bsend");
  MPIABI_Bsend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Bsend_c");
  MPIABI_Bsend_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Bsend_init");
  MPIABI_Bsend_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Bsend_init_c");
  MPIABI_Buffer_attach_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Buffer_attach");
  MPIABI_Buffer_attach_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Buffer_attach_c");
  MPIABI_Buffer_detach_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Buffer_detach");
  MPIABI_Buffer_detach_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Buffer_detach_c");
  MPIABI_Buffer_flush_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Buffer_flush");
  MPIABI_Buffer_iflush_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Buffer_iflush");
  MPIABI_Cancel_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Cancel");
  MPIABI_Comm_attach_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_attach_buffer");
  MPIABI_Comm_attach_buffer_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_attach_buffer_c");
  MPIABI_Comm_detach_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_detach_buffer");
  MPIABI_Comm_detach_buffer_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_detach_buffer_c");
  MPIABI_Comm_flush_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_flush_buffer");
  MPIABI_Comm_iflush_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_iflush_buffer");
  MPIABI_Get_count_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Get_count");
  MPIABI_Get_count_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_count_c");
  MPIABI_Ibsend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ibsend");
  MPIABI_Ibsend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ibsend_c");
  MPIABI_Improbe_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Improbe");
  MPIABI_Imrecv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Imrecv");
  MPIABI_Imrecv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Imrecv_c");
  MPIABI_Iprobe_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iprobe");
  MPIABI_Irecv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Irecv");
  MPIABI_Irecv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Irecv_c");
  MPIABI_Irsend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Irsend");
  MPIABI_Irsend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Irsend_c");
  MPIABI_Isend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Isend");
  MPIABI_Isend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Isend_c");
  MPIABI_Isendrecv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Isendrecv");
  MPIABI_Isendrecv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Isendrecv_c");
  MPIABI_Isendrecv_replace_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Isendrecv_replace");
  MPIABI_Isendrecv_replace_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Isendrecv_replace_c");
  MPIABI_Issend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Issend");
  MPIABI_Issend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Issend_c");
  MPIABI_Mprobe_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Mprobe");
  MPIABI_Mrecv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Mrecv");
  MPIABI_Mrecv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Mrecv_c");
  MPIABI_Probe_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Probe");
  MPIABI_Recv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Recv");
  MPIABI_Recv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Recv_c");
  MPIABI_Recv_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Recv_init");
  MPIABI_Recv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Recv_init_c");
  MPIABI_Request_free_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Request_free");
  MPIABI_Request_get_status_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Request_get_status");
  MPIABI_Request_get_status_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Request_get_status_all");
  MPIABI_Request_get_status_any_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Request_get_status_any");
  MPIABI_Request_get_status_some_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Request_get_status_some");
  MPIABI_Rsend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rsend");
  MPIABI_Rsend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rsend_c");
  MPIABI_Rsend_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rsend_init");
  MPIABI_Rsend_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Rsend_init_c");
  MPIABI_Send_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Send");
  MPIABI_Send_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Send_c");
  MPIABI_Send_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Send_init");
  MPIABI_Send_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Send_init_c");
  MPIABI_Sendrecv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Sendrecv");
  MPIABI_Sendrecv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Sendrecv_c");
  MPIABI_Sendrecv_replace_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Sendrecv_replace");
  MPIABI_Sendrecv_replace_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Sendrecv_replace_c");
  MPIABI_Session_attach_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_attach_buffer");
  MPIABI_Session_attach_buffer_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_attach_buffer_c");
  MPIABI_Session_detach_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_detach_buffer");
  MPIABI_Session_detach_buffer_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_detach_buffer_c");
  MPIABI_Session_flush_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_flush_buffer");
  MPIABI_Session_iflush_buffer_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_iflush_buffer");
  MPIABI_Ssend_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ssend");
  MPIABI_Ssend_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ssend_c");
  MPIABI_Ssend_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ssend_init");
  MPIABI_Ssend_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ssend_init_c");
  MPIABI_Start_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Start");
  MPIABI_Startall_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Startall");
  MPIABI_Status_get_error_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_get_error");
  MPIABI_Status_get_source_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_get_source");
  MPIABI_Status_get_tag_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_get_tag");
  MPIABI_Test_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Test");
  MPIABI_Test_cancelled_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Test_cancelled");
  MPIABI_Testall_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Testall");
  MPIABI_Testany_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Testany");
  MPIABI_Testsome_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Testsome");
  MPIABI_Wait_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Wait");
  MPIABI_Waitall_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Waitall");
  MPIABI_Waitany_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Waitany");
  MPIABI_Waitsome_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Waitsome");

  // A.3.2 Partitioned Communication C Bindings

  MPIABI_Parrived_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Parrived");
  MPIABI_Pready_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Pready");
  MPIABI_Pready_list_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pready_list");
  MPIABI_Pready_range_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pready_range");
  MPIABI_Precv_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Precv_init");
  MPIABI_Psend_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Psend_init");

  // A.3.3 Datatypes C Bindings

  MPIABI_Aint_add_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Aint_add");
  MPIABI_Aint_diff_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Aint_diff");
  MPIABI_Get_address_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_address");
  MPIABI_Get_elements_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_elements");
  MPIABI_Get_elements_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_elements_c");
  MPIABI_Pack_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Pack");
  MPIABI_Pack_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Pack_c");
  MPIABI_Pack_external_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pack_external");
  MPIABI_Pack_external_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pack_external_c");
  MPIABI_Pack_external_size_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pack_external_size");
  MPIABI_Pack_external_size_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pack_external_size_c");
  MPIABI_Pack_size_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Pack_size");
  MPIABI_Pack_size_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Pack_size_c");
  MPIABI_Type_commit_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_commit");
  MPIABI_Type_contiguous_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_contiguous");
  MPIABI_Type_contiguous_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_contiguous_c");
  MPIABI_Type_create_darray_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_darray");
  MPIABI_Type_create_darray_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_darray_c");
  MPIABI_Type_create_hindexed_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_hindexed");
  MPIABI_Type_create_hindexed_block_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_hindexed_block");
  MPIABI_Type_create_hindexed_block_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_hindexed_block_c");
  MPIABI_Type_create_hindexed_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_hindexed_c");
  MPIABI_Type_create_hvector_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_hvector");
  MPIABI_Type_create_hvector_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_hvector_c");
  MPIABI_Type_create_indexed_block_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_indexed_block");
  MPIABI_Type_create_indexed_block_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_indexed_block_c");
  MPIABI_Type_create_resized_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_resized");
  MPIABI_Type_create_resized_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_resized_c");
  MPIABI_Type_create_struct_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_struct");
  MPIABI_Type_create_struct_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_struct_c");
  MPIABI_Type_create_subarray_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_subarray");
  MPIABI_Type_create_subarray_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_subarray_c");
  MPIABI_Type_dup_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Type_dup");
  MPIABI_Type_free_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Type_free");
  MPIABI_Type_get_contents_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_contents");
  MPIABI_Type_get_contents_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_contents_c");
  MPIABI_Type_get_envelope_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_envelope");
  MPIABI_Type_get_envelope_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_envelope_c");
  MPIABI_Type_get_extent_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_extent");
  MPIABI_Type_get_extent_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_extent_c");
  MPIABI_Type_get_true_extent_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_true_extent");
  MPIABI_Type_get_true_extent_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_true_extent_c");
  MPIABI_Type_indexed_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_indexed");
  MPIABI_Type_indexed_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_indexed_c");
  MPIABI_Type_size_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Type_size");
  MPIABI_Type_size_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_size_c");
  MPIABI_Type_vector_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_vector");
  MPIABI_Type_vector_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_vector_c");
  MPIABI_Unpack_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Unpack");
  MPIABI_Unpack_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Unpack_c");
  MPIABI_Unpack_external_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Unpack_external");
  MPIABI_Unpack_external_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Unpack_external_c");

  // A.3.4 Collective Communication C Bindings

  MPIABI_Allgather_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Allgather");
  MPIABI_Allgather_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allgather_c");
  MPIABI_Allgather_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allgather_init");
  MPIABI_Allgather_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allgather_init_c");
  MPIABI_Allgatherv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Allgatherv");
  MPIABI_Allgatherv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allgatherv_c");
  MPIABI_Allgatherv_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allgatherv_init");
  MPIABI_Allgatherv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allgatherv_init_c");
  MPIABI_Allreduce_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Allreduce");
  MPIABI_Allreduce_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allreduce_c");
  MPIABI_Allreduce_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allreduce_init");
  MPIABI_Allreduce_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Allreduce_init_c");
  MPIABI_Alltoall_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Alltoall");
  MPIABI_Alltoall_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Alltoall_c");
  MPIABI_Alltoall_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoall_init");
  MPIABI_Alltoall_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoall_init_c");
  MPIABI_Alltoallv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Alltoallv");
  MPIABI_Alltoallv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoallv_c");
  MPIABI_Alltoallv_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoallv_init");
  MPIABI_Alltoallv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoallv_init_c");
  MPIABI_Alltoallw_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Alltoallw");
  MPIABI_Alltoallw_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoallw_c");
  MPIABI_Alltoallw_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoallw_init");
  MPIABI_Alltoallw_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Alltoallw_init_c");
  MPIABI_Barrier_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Barrier");
  MPIABI_Barrier_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Barrier_init");
  MPIABI_Bcast_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Bcast");
  MPIABI_Bcast_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Bcast_c");
  MPIABI_Bcast_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Bcast_init");
  MPIABI_Bcast_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Bcast_init_c");
  MPIABI_Exscan_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Exscan");
  MPIABI_Exscan_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Exscan_c");
  MPIABI_Exscan_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Exscan_init");
  MPIABI_Exscan_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Exscan_init_c");
  MPIABI_Gather_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Gather");
  MPIABI_Gather_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Gather_c");
  MPIABI_Gather_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Gather_init");
  MPIABI_Gather_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Gather_init_c");
  MPIABI_Gatherv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Gatherv");
  MPIABI_Gatherv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Gatherv_c");
  MPIABI_Gatherv_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Gatherv_init");
  MPIABI_Gatherv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Gatherv_init_c");
  MPIABI_Iallgather_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iallgather");
  MPIABI_Iallgather_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Iallgather_c");
  MPIABI_Iallgatherv_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Iallgatherv");
  MPIABI_Iallgatherv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Iallgatherv_c");
  MPIABI_Iallreduce_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iallreduce");
  MPIABI_Iallreduce_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Iallreduce_c");
  MPIABI_Ialltoall_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ialltoall");
  MPIABI_Ialltoall_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ialltoall_c");
  MPIABI_Ialltoallv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ialltoallv");
  MPIABI_Ialltoallv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ialltoallv_c");
  MPIABI_Ialltoallw_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ialltoallw");
  MPIABI_Ialltoallw_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ialltoallw_c");
  MPIABI_Ibarrier_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ibarrier");
  MPIABI_Ibcast_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ibcast");
  MPIABI_Ibcast_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ibcast_c");
  MPIABI_Iexscan_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iexscan");
  MPIABI_Iexscan_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iexscan_c");
  MPIABI_Igather_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Igather");
  MPIABI_Igather_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Igather_c");
  MPIABI_Igatherv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Igatherv");
  MPIABI_Igatherv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Igatherv_c");
  MPIABI_Ireduce_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ireduce");
  MPIABI_Ireduce_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Ireduce_c");
  MPIABI_Ireduce_scatter_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ireduce_scatter");
  MPIABI_Ireduce_scatter_block_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ireduce_scatter_block");
  MPIABI_Ireduce_scatter_block_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ireduce_scatter_block_c");
  MPIABI_Ireduce_scatter_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ireduce_scatter_c");
  MPIABI_Iscan_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iscan");
  MPIABI_Iscan_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iscan_c");
  MPIABI_Iscatter_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iscatter");
  MPIABI_Iscatter_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iscatter_c");
  MPIABI_Iscatterv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Iscatterv");
  MPIABI_Iscatterv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Iscatterv_c");
  MPIABI_Op_commutative_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Op_commutative");
  MPIABI_Op_create_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Op_create");
  MPIABI_Op_create_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Op_create_c");
  MPIABI_Op_free_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Op_free");
  MPIABI_Reduce_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Reduce");
  MPIABI_Reduce_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Reduce_c");
  MPIABI_Reduce_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_init");
  MPIABI_Reduce_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_init_c");
  MPIABI_Reduce_local_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_local");
  MPIABI_Reduce_local_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_local_c");
  MPIABI_Reduce_scatter_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter");
  MPIABI_Reduce_scatter_block_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_block");
  MPIABI_Reduce_scatter_block_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_block_c");
  MPIABI_Reduce_scatter_block_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_block_init");
  MPIABI_Reduce_scatter_block_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_block_init_c");
  MPIABI_Reduce_scatter_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_c");
  MPIABI_Reduce_scatter_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_init");
  MPIABI_Reduce_scatter_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Reduce_scatter_init_c");
  MPIABI_Scan_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scan");
  MPIABI_Scan_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scan_c");
  MPIABI_Scan_init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scan_init");
  MPIABI_Scan_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Scan_init_c");
  MPIABI_Scatter_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scatter");
  MPIABI_Scatter_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scatter_c");
  MPIABI_Scatter_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Scatter_init");
  MPIABI_Scatter_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Scatter_init_c");
  MPIABI_Scatterv_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scatterv");
  MPIABI_Scatterv_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Scatterv_c");
  MPIABI_Scatterv_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Scatterv_init");
  MPIABI_Scatterv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Scatterv_init_c");
  MPIABI_Type_get_value_index_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_value_index");

  // A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

  MPIABI_Comm_compare_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_compare");
  MPIABI_Comm_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_create");
  MPIABI_Comm_create_from_group_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_create_from_group");
  MPIABI_Comm_create_group_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_create_group");
  MPIABI_Comm_create_keyval_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_create_keyval");
  MPIABI_Comm_delete_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_delete_attr");
  MPIABI_Comm_dup_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_dup");
  MPIABI_Comm_dup_with_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_dup_with_info");
  MPIABI_Comm_free_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_free");
  MPIABI_Comm_get_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_get_name");
  MPIABI_Comm_free_keyval_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_free_keyval");
  MPIABI_Comm_get_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_get_attr");
  MPIABI_Comm_get_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_get_info");
  MPIABI_Comm_group_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_group");
  MPIABI_Comm_idup_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_idup");
  MPIABI_Comm_idup_with_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_idup_with_info");
  MPIABI_Comm_rank_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_rank");
  MPIABI_Comm_remote_group_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_remote_group");
  MPIABI_Comm_remote_size_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_remote_size");
  MPIABI_Comm_set_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_set_attr");
  MPIABI_Comm_set_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_set_info");
  MPIABI_Comm_set_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_set_name");
  MPIABI_Comm_size_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_size");
  MPIABI_Comm_split_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_split");
  MPIABI_Group_free_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Group_free");
  MPIABI_Comm_split_type_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_split_type");
  MPIABI_Comm_test_inter_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_test_inter");
  MPIABI_Group_compare_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_compare");
  MPIABI_Group_difference_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_difference");
  MPIABI_Group_excl_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Group_excl");
  MPIABI_Group_from_session_pset_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_from_session_pset");
  MPIABI_Group_incl_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Group_incl");
  MPIABI_Group_intersection_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_intersection");
  MPIABI_Group_range_excl_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_range_excl");
  MPIABI_Group_range_incl_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_range_incl");
  MPIABI_Group_rank_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Group_rank");
  MPIABI_Group_size_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Group_size");
  MPIABI_Group_translate_ranks_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_translate_ranks");
  MPIABI_Group_union_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Group_union");
  MPIABI_Intercomm_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Intercomm_create");
  MPIABI_Intercomm_create_from_groups_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Intercomm_create_from_groups");
  MPIABI_Intercomm_merge_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Intercomm_merge");
  MPIABI_Type_create_keyval_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_create_keyval");
  MPIABI_Type_delete_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_delete_attr");
  MPIABI_Type_free_keyval_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_free_keyval");
  MPIABI_Type_get_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_attr");
  MPIABI_Type_get_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_name");
  MPIABI_Type_set_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_set_attr");
  MPIABI_Type_set_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_set_name");
  MPIABI_Win_create_keyval_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_create_keyval");
  MPIABI_Win_delete_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_delete_attr");
  MPIABI_Win_free_keyval_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_free_keyval");
  MPIABI_Win_get_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_get_attr");
  MPIABI_Win_get_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_get_name");
  MPIABI_Win_set_attr_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_set_attr");
  MPIABI_Win_set_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_set_name");

  // A.3.6 Virtual Topologies for MPI Processes C Bindings

  MPIABI_Cart_coords_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Cart_coords");
  MPIABI_Cart_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Cart_create");
  MPIABI_Cart_get_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Cart_get");
  MPIABI_Cart_map_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Cart_map");
  MPIABI_Cart_rank_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Cart_rank");
  MPIABI_Cart_shift_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Cart_shift");
  MPIABI_Cart_sub_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Cart_sub");
  MPIABI_Cartdim_get_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Cartdim_get");
  MPIABI_Dims_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Dims_create");
  MPIABI_Dist_graph_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Dist_graph_create");
  MPIABI_Dist_graph_create_adjacent_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Dist_graph_create_adjacent");
  MPIABI_Dist_graph_neighbors_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Dist_graph_neighbors");
  MPIABI_Dist_graph_neighbors_count_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Dist_graph_neighbors_count");
  MPIABI_Graph_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Graph_create");
  MPIABI_Graph_get_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Graph_get");
  MPIABI_Graph_map_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Graph_map");
  MPIABI_Graph_neighbors_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Graph_neighbors");
  MPIABI_Graph_neighbors_count_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Graph_neighbors_count");
  MPIABI_Graphdims_get_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Graphdims_get");
  MPIABI_Ineighbor_allgather_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_allgather");
  MPIABI_Ineighbor_allgather_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_allgather_c");
  MPIABI_Ineighbor_allgatherv_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_allgatherv");
  MPIABI_Ineighbor_allgatherv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_allgatherv_c");
  MPIABI_Ineighbor_alltoall_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_alltoall");
  MPIABI_Ineighbor_alltoall_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_alltoall_c");
  MPIABI_Ineighbor_alltoallv_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_alltoallv");
  MPIABI_Ineighbor_alltoallv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_alltoallv_c");
  MPIABI_Ineighbor_alltoallw_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_alltoallw");
  MPIABI_Ineighbor_alltoallw_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Ineighbor_alltoallw_c");
  MPIABI_Neighbor_allgather_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgather");
  MPIABI_Neighbor_allgather_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgather_c");
  MPIABI_Neighbor_allgather_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgather_init");
  MPIABI_Neighbor_allgather_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgather_init_c");
  MPIABI_Neighbor_allgatherv_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgatherv");
  MPIABI_Neighbor_allgatherv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgatherv_c");
  MPIABI_Neighbor_allgatherv_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgatherv_init");
  MPIABI_Neighbor_allgatherv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_allgatherv_init_c");
  MPIABI_Neighbor_alltoall_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoall");
  MPIABI_Neighbor_alltoall_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoall_c");
  MPIABI_Neighbor_alltoall_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoall_init");
  MPIABI_Neighbor_alltoall_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoall_init_c");
  MPIABI_Neighbor_alltoallv_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallv");
  MPIABI_Neighbor_alltoallv_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallv_c");
  MPIABI_Neighbor_alltoallv_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallv_init");
  MPIABI_Neighbor_alltoallv_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallv_init_c");
  MPIABI_Neighbor_alltoallw_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallw");
  MPIABI_Neighbor_alltoallw_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallw_c");
  MPIABI_Neighbor_alltoallw_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallw_init");
  MPIABI_Neighbor_alltoallw_init_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Neighbor_alltoallw_init_c");
  MPIABI_Topo_test_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Topo_test");

  // A.3.7 MPI Environmental Management C Bindings

  MPIABI_Add_error_class_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Add_error_class");
  MPIABI_Add_error_code_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Add_error_code");
  MPIABI_Add_error_string_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Add_error_string");
  MPIABI_Alloc_mem_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Alloc_mem");
  MPIABI_Comm_call_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_call_errhandler");
  MPIABI_Comm_create_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_create_errhandler");
  MPIABI_Comm_get_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_get_errhandler");
  MPIABI_Comm_set_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_set_errhandler");
  MPIABI_Errhandler_free_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Errhandler_free");
  MPIABI_Error_class_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Error_class");
  MPIABI_Error_string_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Error_string");
  MPIABI_File_call_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_call_errhandler");
  MPIABI_File_create_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_create_errhandler");
  MPIABI_File_get_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_errhandler");
  MPIABI_File_set_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_set_errhandler");
  MPIABI_Free_mem_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Free_mem");
  MPIABI_Get_hw_resource_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_hw_resource_info");
  MPIABI_Get_library_version_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_library_version");
  MPIABI_Get_processor_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_processor_name");
  MPIABI_Get_version_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_version");
  MPIABI_Remove_error_class_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Remove_error_class");
  MPIABI_Remove_error_code_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Remove_error_code");
  MPIABI_Remove_error_string_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Remove_error_string");
  MPIABI_Session_call_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_call_errhandler");
  MPIABI_Session_create_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_create_errhandler");
  MPIABI_Session_get_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_get_errhandler");
  MPIABI_Session_set_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_set_errhandler");
  MPIABI_Win_call_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_call_errhandler");
  MPIABI_Win_create_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_create_errhandler");
  MPIABI_Win_get_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_get_errhandler");
  MPIABI_Win_set_errhandler_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_set_errhandler");
  MPIABI_Wtick_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Wtick");
  MPIABI_Wtime_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Wtime");

  // A.3.8 The Info Object C Bindings

  MPIABI_Info_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_create");
  MPIABI_Info_create_env_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_create_env");
  MPIABI_Info_delete_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_delete");
  MPIABI_Info_dup_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Info_dup");
  MPIABI_Info_free_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Info_free");
  MPIABI_Info_get_nkeys_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_get_nkeys");
  MPIABI_Info_get_nthkey_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_get_nthkey");
  MPIABI_Info_get_string_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_get_string");
  MPIABI_Info_set_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Info_set");

  // A.3.9 Process Creation and Management C Bindings

  MPIABI_Abort_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Abort");
  MPIABI_Close_port_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Close_port");
  MPIABI_Comm_accept_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_accept");
  MPIABI_Comm_connect_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_connect");
  MPIABI_Comm_disconnect_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_disconnect");
  MPIABI_Comm_get_parent_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_get_parent");
  MPIABI_Comm_join_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_join");
  MPIABI_Comm_spawn_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Comm_spawn");
  MPIABI_Comm_spawn_multiple_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Comm_spawn_multiple");
  MPIABI_Finalize_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Finalize");
  MPIABI_Finalized_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Finalized");
  MPIABI_Init_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Init");
  MPIABI_Init_thread_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Init_thread");
  MPIABI_Initialized_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Initialized");
  MPIABI_Is_thread_main_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Is_thread_main");
  MPIABI_Lookup_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Lookup_name");
  MPIABI_Open_port_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Open_port");
  MPIABI_Publish_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Publish_name");
  MPIABI_Query_thread_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Query_thread");
  MPIABI_Session_finalize_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_finalize");
  MPIABI_Session_get_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_get_info");
  MPIABI_Session_get_nth_pset_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_get_nth_pset");
  MPIABI_Session_get_num_psets_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_get_num_psets");
  MPIABI_Session_get_pset_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_get_pset_info");
  MPIABI_Session_init_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Session_init");
  MPIABI_Unpublish_name_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Unpublish_name");

  // A.3.10 One-Sided Communications C Bindings

  MPIABI_Accumulate_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Accumulate");
  MPIABI_Accumulate_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Accumulate_c");
  MPIABI_Compare_and_swap_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Compare_and_swap");
  MPIABI_Fetch_and_op_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Fetch_and_op");
  MPIABI_Get_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Get");
  MPIABI_Get_accumulate_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_accumulate");
  MPIABI_Get_accumulate_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_accumulate_c");
  MPIABI_Get_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Get_c");
  MPIABI_Put_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Put");
  MPIABI_Put_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Put_c");
  MPIABI_Raccumulate_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Raccumulate");
  MPIABI_Raccumulate_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Raccumulate_c");
  MPIABI_Rget_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rget");
  MPIABI_Rget_accumulate_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Rget_accumulate");
  MPIABI_Rget_accumulate_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Rget_accumulate_c");
  MPIABI_Rget_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rget_c");
  MPIABI_Rput_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rput");
  MPIABI_Rput_c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Rput_c");
  MPIABI_Win_allocate_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_allocate");
  MPIABI_Win_allocate_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_allocate_c");
  MPIABI_Win_allocate_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_allocate_shared");
  MPIABI_Win_allocate_shared_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_allocate_shared_c");
  MPIABI_Win_attach_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_attach");
  MPIABI_Win_complete_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_complete");
  MPIABI_Win_create_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_create");
  MPIABI_Win_create_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_create_c");
  MPIABI_Win_create_dynamic_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_create_dynamic");
  MPIABI_Win_detach_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_detach");
  MPIABI_Win_fence_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_fence");
  MPIABI_Win_flush_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_flush");
  MPIABI_Win_flush_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_flush_all");
  MPIABI_Win_flush_local_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_flush_local");
  MPIABI_Win_flush_local_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_flush_local_all");
  MPIABI_Win_free_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_free");
  MPIABI_Win_get_group_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_get_group");
  MPIABI_Win_get_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_get_info");
  MPIABI_Win_lock_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_lock");
  MPIABI_Win_lock_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_lock_all");
  MPIABI_Win_post_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_post");
  MPIABI_Win_set_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_set_info");
  MPIABI_Win_shared_query_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_shared_query");
  MPIABI_Win_shared_query_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_shared_query_c");
  MPIABI_Win_start_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_start");
  MPIABI_Win_sync_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_sync");
  MPIABI_Win_test_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_test");
  MPIABI_Win_unlock_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_unlock");
  MPIABI_Win_unlock_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Win_unlock_all");
  MPIABI_Win_wait_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Win_wait");

  // A.3.11 External Interfaces C Bindings

  MPIABI_Grequest_complete_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Grequest_complete");
  MPIABI_Grequest_start_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Grequest_start");
  MPIABI_Status_set_cancelled_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_cancelled");
  MPIABI_Status_set_elements_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_elements");
  MPIABI_Status_set_elements_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_elements_c");
  MPIABI_Status_set_error_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_error");
  MPIABI_Status_set_source_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_source");
  MPIABI_Status_set_tag_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_tag");

  // A.3.12 I/O C Bindings

  MPIABI_File_close_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_close");
  MPIABI_File_delete_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_delete");
  MPIABI_File_get_amode_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_amode");
  MPIABI_File_get_atomicity_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_atomicity");
  MPIABI_File_get_byte_offset_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_byte_offset");
  MPIABI_File_get_group_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_group");
  MPIABI_File_get_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_info");
  MPIABI_File_get_position_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_position");
  MPIABI_File_get_position_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_position_shared");
  MPIABI_File_get_size_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_size");
  MPIABI_File_get_type_extent_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_type_extent");
  MPIABI_File_get_type_extent_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_type_extent_c");
  MPIABI_File_get_view_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_get_view");
  MPIABI_File_iread_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_iread");
  MPIABI_File_iread_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_all");
  MPIABI_File_iread_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_all_c");
  MPIABI_File_iread_at_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_at");
  MPIABI_File_iread_at_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_at_all");
  MPIABI_File_iread_at_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_at_all_c");
  MPIABI_File_iread_at_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_at_c");
  MPIABI_File_iread_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_c");
  MPIABI_File_iread_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_shared");
  MPIABI_File_iread_shared_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iread_shared_c");
  MPIABI_File_iwrite_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite");
  MPIABI_File_iwrite_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_all");
  MPIABI_File_iwrite_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_all_c");
  MPIABI_File_iwrite_at_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_at");
  MPIABI_File_iwrite_at_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_at_all");
  MPIABI_File_iwrite_at_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_at_all_c");
  MPIABI_File_iwrite_at_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_at_c");
  MPIABI_File_iwrite_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_c");
  MPIABI_File_iwrite_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_shared");
  MPIABI_File_iwrite_shared_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_iwrite_shared_c");
  MPIABI_File_open_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_open");
  MPIABI_File_preallocate_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_preallocate");
  MPIABI_File_read_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_read");
  MPIABI_File_read_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_all");
  MPIABI_File_read_all_begin_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_all_begin");
  MPIABI_File_read_all_begin_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_all_begin_c");
  MPIABI_File_read_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_all_c");
  MPIABI_File_read_all_end_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_all_end");
  MPIABI_File_read_at_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at");
  MPIABI_File_read_at_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at_all");
  MPIABI_File_read_at_all_begin_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at_all_begin");
  MPIABI_File_read_at_all_begin_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at_all_begin_c");
  MPIABI_File_read_at_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at_all_c");
  MPIABI_File_read_at_all_end_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at_all_end");
  MPIABI_File_read_at_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_at_c");
  MPIABI_File_read_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_c");
  MPIABI_File_read_ordered_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_ordered");
  MPIABI_File_read_ordered_begin_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_ordered_begin");
  MPIABI_File_read_ordered_begin_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_ordered_begin_c");
  MPIABI_File_read_ordered_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_ordered_c");
  MPIABI_File_read_ordered_end_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_ordered_end");
  MPIABI_File_read_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_shared");
  MPIABI_File_read_shared_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_read_shared_c");
  MPIABI_File_seek_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_seek");
  MPIABI_File_seek_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_seek_shared");
  MPIABI_File_set_atomicity_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_set_atomicity");
  MPIABI_File_set_info_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_set_info");
  MPIABI_File_set_size_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_set_size");
  MPIABI_File_set_view_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_set_view");
  MPIABI_File_sync_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_sync");
  MPIABI_File_write_ptr = mpitrampoline_get_symbol(handle, "MPIABI_File_write");
  MPIABI_File_write_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_all");
  MPIABI_File_write_all_begin_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_all_begin");
  MPIABI_File_write_all_begin_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_all_begin_c");
  MPIABI_File_write_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_all_c");
  MPIABI_File_write_all_end_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_all_end");
  MPIABI_File_write_at_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at");
  MPIABI_File_write_at_all_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at_all");
  MPIABI_File_write_at_all_begin_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at_all_begin");
  MPIABI_File_write_at_all_begin_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at_all_begin_c");
  MPIABI_File_write_at_all_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at_all_c");
  MPIABI_File_write_at_all_end_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at_all_end");
  MPIABI_File_write_at_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_at_c");
  MPIABI_File_write_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_c");
  MPIABI_File_write_ordered_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_ordered");
  MPIABI_File_write_ordered_begin_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_ordered_begin");
  MPIABI_File_write_ordered_begin_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_ordered_begin_c");
  MPIABI_File_write_ordered_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_ordered_c");
  MPIABI_File_write_ordered_end_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_ordered_end");
  MPIABI_File_write_shared_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_shared");
  MPIABI_File_write_shared_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_File_write_shared_c");
  MPIABI_Register_datarep_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Register_datarep");
  MPIABI_Register_datarep_c_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Register_datarep_c");

  // TODO // A.3.13 Language Bindings C Bindings
  // TODO
  // TODO MPIABI_Comm_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Comm_c2f");
  // TODO MPIABI_Comm_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Comm_f2c");
  // TODO MPIABI_Errhandler_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Errhandler_c2f");
  // TODO MPIABI_Errhandler_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Errhandler_f2c");
  // TODO MPIABI_File_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_File_c2f");
  // TODO MPIABI_File_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_File_f2c");
  // TODO MPIABI_Group_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Group_c2f");
  // TODO MPIABI_Group_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Group_f2c");
  // TODO MPIABI_Info_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Info_c2f");
  // TODO MPIABI_Info_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Info_f2c");
  // TODO MPIABI_Message_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Message_c2f");
  // TODO MPIABI_Message_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Message_f2c");
  // TODO MPIABI_Op_c2f_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Op_c2f");
  // TODO MPIABI_Op_f2c_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Op_f2c");
  // TODO MPIABI_Request_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Request_c2f");
  // TODO MPIABI_Request_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Request_f2c");
  // TODO MPIABI_Session_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Session_c2f");
  // TODO MPIABI_Session_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Session_f2c");
  // TODO MPIABI_Status_f082f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Status_f082f");
  // TODO MPIABI_Status_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Status_c2f");
  // TODO MPIABI_Status_c2f08_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Status_c2f08");
  // TODO MPIABI_Status_f082c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Status_f082c");
  // TODO MPIABI_Status_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Status_f2c");
  // TODO MPIABI_Status_f2f08_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Status_f2f08");
  // TODO MPIABI_Type_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Type_c2f");
  // TODO MPIABI_Type_create_f90_complex_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_Type_create_f90_complex");
  // TODO MPIABI_Type_create_f90_integer_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_Type_create_f90_integer");
  // TODO MPIABI_Type_create_f90_real_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_Type_create_f90_real");
  // TODO MPIABI_Type_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Type_f2c");
  // TODO MPIABI_Type_match_size_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Type_match_size");
  // TODO MPIABI_Win_c2f_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Win_c2f");
  // TODO MPIABI_Win_f2c_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_Win_f2c");

  // A.3.14 Tools / Profiling Interface C Bindings

  MPIABI_Pcontrol_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Pcontrol");

  // TODO // A.3.15 Tools / MPI Tool Information Interface C Bindings
  // TODO
  // TODO MPIABI_T_category_changed_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_category_changed");
  // TODO MPIABI_T_category_get_categories_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_category_get_categories");
  // TODO MPIABI_T_category_get_cvars_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_category_get_cvars");
  // TODO MPIABI_T_category_get_events_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_category_get_events");
  // TODO MPIABI_T_category_get_index_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_category_get_index");
  // TODO MPIABI_T_category_get_info_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_category_get_info");
  // TODO MPIABI_T_category_get_num_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_category_get_num");
  // TODO MPIABI_T_category_get_num_events_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_category_get_num_events");
  // TODO MPIABI_T_category_get_pvars_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_category_get_pvars");
  // TODO MPIABI_T_cvar_get_index_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_cvar_get_index");
  // TODO MPIABI_T_cvar_get_info_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_cvar_get_info");
  // TODO MPIABI_T_cvar_get_num_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_cvar_get_num");
  // TODO MPIABI_T_cvar_handle_alloc_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_cvar_handle_alloc");
  // TODO MPIABI_T_cvar_handle_free_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_cvar_handle_free");
  // TODO MPIABI_T_cvar_read_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_cvar_read");
  // TODO MPIABI_T_cvar_write_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_cvar_write");
  // TODO MPIABI_T_enum_get_info_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_enum_get_info");
  // TODO MPIABI_T_enum_get_item_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_enum_get_item");
  // TODO MPIABI_T_event_callback_get_info_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_callback_get_info");
  // TODO MPIABI_T_event_callback_set_info_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_callback_set_info");
  // TODO MPIABI_T_event_copy_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_copy");
  // TODO MPIABI_T_event_get_index_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_get_index");
  // TODO MPIABI_T_event_get_info_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_get_info");
  // TODO MPIABI_T_event_get_num_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_get_num");
  // TODO MPIABI_T_event_get_source_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_get_source");
  // TODO MPIABI_T_event_get_timestamp_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_event_get_timestamp");
  // TODO MPIABI_T_event_handle_alloc_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_event_handle_alloc");
  // TODO MPIABI_T_event_handle_free_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_event_handle_free");
  // TODO MPIABI_T_event_handle_get_info_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_handle_get_info");
  // TODO MPIABI_T_event_handle_set_info_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_handle_set_info");
  // TODO MPIABI_T_event_read_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_read");
  // TODO MPIABI_T_event_register_callback_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_register_callback");
  // TODO MPIABI_T_event_set_dropped_handler_ptr =
  // TODO     mpitrampoline_get_symbol(handle,
  // "MPIABI_T_event_set_dropped_handler");
  // TODO MPIABI_T_finalize_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_finalize");
  // TODO MPIABI_T_init_thread_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_init_thread");
  // TODO MPIABI_T_pvar_get_index_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_get_index");
  // TODO MPIABI_T_pvar_get_info_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_get_info");
  // TODO MPIABI_T_pvar_get_num_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_get_num");
  // TODO MPIABI_T_pvar_handle_alloc_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_pvar_handle_alloc");
  // TODO MPIABI_T_pvar_handle_free_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_handle_free");
  // TODO MPIABI_T_pvar_read_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_read");
  // TODO MPIABI_T_pvar_readreset_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_readreset");
  // TODO MPIABI_T_pvar_reset_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_reset");
  // TODO MPIABI_T_pvar_session_create_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_pvar_session_create");
  // TODO MPIABI_T_pvar_session_free_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_pvar_session_free");
  // TODO MPIABI_T_pvar_start_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_start");
  // TODO MPIABI_T_pvar_stop_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_stop");
  // TODO MPIABI_T_pvar_write_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_pvar_write");
  // TODO MPIABI_T_source_get_info_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_source_get_info");
  // TODO MPIABI_T_source_get_num_ptr = mpitrampoline_get_symbol(handle,
  // "MPIABI_T_source_get_num");
  // TODO MPIABI_T_source_get_timestamp_ptr =
  // TODO     mpitrampoline_get_symbol(handle, "MPIABI_T_source_get_timestamp");

  // A.3.16 Deprecated C Bindings

  MPIABI_Attr_delete_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Attr_delete");
  MPIABI_Attr_get_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Attr_get");
  MPIABI_Attr_put_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Attr_put");
  MPIABI_Get_elements_x_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Get_elements_x");
  MPIABI_Info_get_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Info_get");
  MPIABI_Info_get_valuelen_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Info_get_valuelen");
  MPIABI_Keyval_create_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Keyval_create");
  MPIABI_Keyval_free_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Keyval_free");
  MPIABI_Status_set_elements_x_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Status_set_elements_x");
  MPIABI_Type_get_extent_x_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_extent_x");
  MPIABI_Type_get_true_extent_x_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_get_true_extent_x");
  MPIABI_Type_size_x_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_size_x");

  // Removed C Bindings

  MPIABI_Address_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Address");
  MPIABI_Type_hindexed_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_hindexed");
  MPIABI_Type_hvector_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_hvector");
  MPIABI_Type_struct_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_struct");
  MPIABI_Type_extent_ptr =
      mpitrampoline_get_symbol(handle, "MPIABI_Type_extent");
  MPIABI_Type_lb_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Type_lb");
  MPIABI_Type_ub_ptr = mpitrampoline_get_symbol(handle, "MPIABI_Type_ub");

  // MPIX

  MPIXABI_Query_cuda_support_ptr =
      mpitrampoline_get_symbol(handle, "MPIXABI_Query_cuda_support");
  MPIXABI_Query_hip_support_ptr =
      mpitrampoline_get_symbol(handle, "MPIXABI_Query_hip_support");
  MPIXABI_Query_rocm_support_ptr =
      mpitrampoline_get_symbol(handle, "MPIXABI_Query_rocm_support");
  MPIXABI_Query_ze_support_ptr =
      mpitrampoline_get_symbol(handle, "MPIXABI_Query_ze_support");
}
