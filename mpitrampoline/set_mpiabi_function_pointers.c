// Declare pointers to MPIABI functions

// A.3 C Bindings

// A.3.1 Point-to-Point Communication C Bindings

MPIABI_Bsend_ptr = get_symbol(handle, "MPIABI_Bsend");
MPIABI_Bsend_c_ptr = get_symbol(handle, "MPIABI_Bsend_c");
MPIABI_Bsend_init_ptr = get_symbol(handle, "MPIABI_Bsend_init");
MPIABI_Bsend_init_c_ptr = get_symbol(handle, "MPIABI_Bsend_init_c");
MPIABI_Buffer_attach_ptr = get_symbol(handle, "MPIABI_Buffer_attach");
MPIABI_Buffer_attach_c_ptr = get_symbol(handle, "MPIABI_Buffer_attach_c");
MPIABI_Buffer_detach_ptr = get_symbol(handle, "MPIABI_Buffer_detach");
MPIABI_Buffer_detach_c_ptr = get_symbol(handle, "MPIABI_Buffer_detach_c");
MPIABI_Buffer_flush_ptr = get_symbol(handle, "MPIABI_Buffer_flush");
MPIABI_Buffer_iflush_ptr = get_symbol(handle, "MPIABI_Buffer_iflush");
MPIABI_Cancel_ptr = get_symbol(handle, "MPIABI_Cancel");
MPIABI_Comm_attach_buffer_ptr = get_symbol(handle, "MPIABI_Comm_attach_buffer");
MPIABI_Comm_attach_buffer_c_ptr =
    get_symbol(handle, "MPIABI_Comm_attach_buffer_c");
MPIABI_Comm_detach_buffer_ptr = get_symbol(handle, "MPIABI_Comm_detach_buffer");
MPIABI_Comm_detach_buffer_c_ptr =
    get_symbol(handle, "MPIABI_Comm_detach_buffer_c");
MPIABI_Comm_flush_buffer_ptr = get_symbol(handle, "MPIABI_Comm_flush_buffer");
MPIABI_Comm_iflush_buffer_ptr = get_symbol(handle, "MPIABI_Comm_iflush_buffer");
MPIABI_Get_count_ptr = get_symbol(handle, "MPIABI_Get_count");
MPIABI_Get_count_c_ptr = get_symbol(handle, "MPIABI_Get_count_c");
MPIABI_Ibsend_ptr = get_symbol(handle, "MPIABI_Ibsend");
MPIABI_Ibsend_c_ptr = get_symbol(handle, "MPIABI_Ibsend_c");
MPIABI_Improbe_ptr = get_symbol(handle, "MPIABI_Improbe");
MPIABI_Imrecv_ptr = get_symbol(handle, "MPIABI_Imrecv");
MPIABI_Imrecv_c_ptr = get_symbol(handle, "MPIABI_Imrecv_c");
MPIABI_Iprobe_ptr = get_symbol(handle, "MPIABI_Iprobe");
MPIABI_Irecv_ptr = get_symbol(handle, "MPIABI_Irecv");
MPIABI_Irecv_c_ptr = get_symbol(handle, "MPIABI_Irecv_c");
MPIABI_Irsend_ptr = get_symbol(handle, "MPIABI_Irsend");
MPIABI_Irsend_c_ptr = get_symbol(handle, "MPIABI_Irsend_c");
MPIABI_Isend_ptr = get_symbol(handle, "MPIABI_Isend");
MPIABI_Isend_c_ptr = get_symbol(handle, "MPIABI_Isend_c");
MPIABI_Isendrecv_ptr = get_symbol(handle, "MPIABI_Isendrecv");
MPIABI_Isendrecv_c_ptr = get_symbol(handle, "MPIABI_Isendrecv_c");
MPIABI_Isendrecv_replace_ptr = get_symbol(handle, "MPIABI_Isendrecv_replace");
MPIABI_Isendrecv_replace_c_ptr =
    get_symbol(handle, "MPIABI_Isendrecv_replace_c");
MPIABI_Issend_ptr = get_symbol(handle, "MPIABI_Issend");
MPIABI_Issend_c_ptr = get_symbol(handle, "MPIABI_Issend_c");
MPIABI_Mprobe_ptr = get_symbol(handle, "MPIABI_Mprobe");
MPIABI_Mrecv_ptr = get_symbol(handle, "MPIABI_Mrecv");
MPIABI_Mrecv_c_ptr = get_symbol(handle, "MPIABI_Mrecv_c");
MPIABI_Probe_ptr = get_symbol(handle, "MPIABI_Probe");
MPIABI_Recv_ptr = get_symbol(handle, "MPIABI_Recv");
MPIABI_Recv_c_ptr = get_symbol(handle, "MPIABI_Recv_c");
MPIABI_Recv_init_ptr = get_symbol(handle, "MPIABI_Recv_init");
MPIABI_Recv_init_c_ptr = get_symbol(handle, "MPIABI_Recv_init_c");
MPIABI_Request_free_ptr = get_symbol(handle, "MPIABI_Request_free");
MPIABI_Request_get_status_ptr = get_symbol(handle, "MPIABI_Request_get_status");
MPIABI_Request_get_status_all_ptr =
    get_symbol(handle, "MPIABI_Request_get_status_all");
MPIABI_Request_get_status_any_ptr =
    get_symbol(handle, "MPIABI_Request_get_status_any");
MPIABI_Request_get_status_some_ptr =
    get_symbol(handle, "MPIABI_Request_get_status_some");
MPIABI_Rsend_ptr = get_symbol(handle, "MPIABI_Rsend");
MPIABI_Rsend_c_ptr = get_symbol(handle, "MPIABI_Rsend_c");
MPIABI_Rsend_init_ptr = get_symbol(handle, "MPIABI_Rsend_init");
MPIABI_Rsend_init_c_ptr = get_symbol(handle, "MPIABI_Rsend_init_c");
MPIABI_Send_ptr = get_symbol(handle, "MPIABI_Send");
MPIABI_Send_c_ptr = get_symbol(handle, "MPIABI_Send_c");
MPIABI_Send_init_ptr = get_symbol(handle, "MPIABI_Send_init");
MPIABI_Send_init_c_ptr = get_symbol(handle, "MPIABI_Send_init_c");
MPIABI_Sendrecv_ptr = get_symbol(handle, "MPIABI_Sendrecv");
MPIABI_Sendrecv_c_ptr = get_symbol(handle, "MPIABI_Sendrecv_c");
MPIABI_Sendrecv_replace_ptr = get_symbol(handle, "MPIABI_Sendrecv_replace");
MPIABI_Sendrecv_replace_c_ptr = get_symbol(handle, "MPIABI_Sendrecv_replace_c");
MPIABI_Session_attach_buffer_ptr =
    get_symbol(handle, "MPIABI_Session_attach_buffer");
MPIABI_Session_attach_buffer_c_ptr =
    get_symbol(handle, "MPIABI_Session_attach_buffer_c");
MPIABI_Session_detach_buffer_ptr =
    get_symbol(handle, "MPIABI_Session_detach_buffer");
MPIABI_Session_detach_buffer_c_ptr =
    get_symbol(handle, "MPIABI_Session_detach_buffer_c");
MPIABI_Session_flush_buffer_ptr =
    get_symbol(handle, "MPIABI_Session_flush_buffer");
MPIABI_Session_iflush_buffer_ptr =
    get_symbol(handle, "MPIABI_Session_iflush_buffer");
MPIABI_Ssend_ptr = get_symbol(handle, "MPIABI_Ssend");
MPIABI_Ssend_c_ptr = get_symbol(handle, "MPIABI_Ssend_c");
MPIABI_Ssend_init_ptr = get_symbol(handle, "MPIABI_Ssend_init");
MPIABI_Ssend_init_c_ptr = get_symbol(handle, "MPIABI_Ssend_init_c");
MPIABI_Start_ptr = get_symbol(handle, "MPIABI_Start");
MPIABI_Startall_ptr = get_symbol(handle, "MPIABI_Startall");
MPIABI_Status_get_error_ptr = get_symbol(handle, "MPIABI_Status_get_error");
MPIABI_Status_get_source_ptr = get_symbol(handle, "MPIABI_Status_get_source");
MPIABI_Status_get_tag_ptr = get_symbol(handle, "MPIABI_Status_get_tag");
MPIABI_Test_ptr = get_symbol(handle, "MPIABI_Test");
MPIABI_Test_cancelled_ptr = get_symbol(handle, "MPIABI_Test_cancelled");
MPIABI_Testall_ptr = get_symbol(handle, "MPIABI_Testall");
MPIABI_Testany_ptr = get_symbol(handle, "MPIABI_Testany");
MPIABI_Testsome_ptr = get_symbol(handle, "MPIABI_Testsome");
MPIABI_Wait_ptr = get_symbol(handle, "MPIABI_Wait");
MPIABI_Waitall_ptr = get_symbol(handle, "MPIABI_Waitall");
MPIABI_Waitany_ptr = get_symbol(handle, "MPIABI_Waitany");
MPIABI_Waitsome_ptr = get_symbol(handle, "MPIABI_Waitsome");

// A.3.2 Partitioned Communication C Bindings

MPIABI_Parrived_ptr = get_symbol(handle, "MPIABI_Parrived");
MPIABI_Pready_ptr = get_symbol(handle, "MPIABI_Pready");
MPIABI_Pready_list_ptr = get_symbol(handle, "MPIABI_Pready_list");
MPIABI_Pready_range_ptr = get_symbol(handle, "MPIABI_Pready_range");
MPIABI_Precv_init_ptr = get_symbol(handle, "MPIABI_Precv_init");
MPIABI_Psend_init_ptr = get_symbol(handle, "MPIABI_Psend_init");

// A.3.3 Datatypes C Bindings

MPIABI_Aint_add_ptr = get_symbol(handle, "MPIABI_Aint_add");
MPIABI_Aint_diff_ptr = get_symbol(handle, "MPIABI_Aint_diff");
MPIABI_Get_address_ptr = get_symbol(handle, "MPIABI_Get_address");
MPIABI_Get_elements_ptr = get_symbol(handle, "MPIABI_Get_elements");
MPIABI_Get_elements_c_ptr = get_symbol(handle, "MPIABI_Get_elements_c");
MPIABI_Pack_ptr = get_symbol(handle, "MPIABI_Pack");
MPIABI_Pack_c_ptr = get_symbol(handle, "MPIABI_Pack_c");
MPIABI_Pack_external_ptr = get_symbol(handle, "MPIABI_Pack_external");
MPIABI_Pack_external_c_ptr = get_symbol(handle, "MPIABI_Pack_external_c");
MPIABI_Pack_external_size_ptr = get_symbol(handle, "MPIABI_Pack_external_size");
MPIABI_Pack_external_size_c_ptr =
    get_symbol(handle, "MPIABI_Pack_external_size_c");
MPIABI_Pack_size_c_ptr = get_symbol(handle, "MPIABI_Pack_size_c");
MPIABI_Type_commit_ptr = get_symbol(handle, "MPIABI_Type_commit");
MPIABI_Type_contiguous_ptr = get_symbol(handle, "MPIABI_Type_contiguous");
MPIABI_Type_contiguous_c_ptr = get_symbol(handle, "MPIABI_Type_contiguous_c");
MPIABI_Type_create_darray_ptr = get_symbol(handle, "MPIABI_Type_create_darray");
MPIABI_Type_create_darray_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_darray_c");
MPIABI_Type_create_hindexed_ptr =
    get_symbol(handle, "MPIABI_Type_create_hindexed");
MPIABI_Type_create_hindexed_block_ptr =
    get_symbol(handle, "MPIABI_Type_create_hindexed_block");
MPIABI_Type_create_hindexed_block_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_hindexed_block_c");
MPIABI_Type_create_hindexed_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_hindexed_c");
MPIABI_Type_create_hvector_ptr =
    get_symbol(handle, "MPIABI_Type_create_hvector");
MPIABI_Type_create_hvector_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_hvector_c");
MPIABI_Type_create_indexed_block_ptr =
    get_symbol(handle, "MPIABI_Type_create_indexed_block");
MPIABI_Type_create_indexed_block_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_indexed_block_c");
MPIABI_Type_create_resized_ptr =
    get_symbol(handle, "MPIABI_Type_create_resized");
MPIABI_Type_create_resized_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_resized_c");
MPIABI_Type_create_struct_ptr = get_symbol(handle, "MPIABI_Type_create_struct");
MPIABI_Type_create_struct_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_struct_c");
MPIABI_Type_create_subarray_ptr =
    get_symbol(handle, "MPIABI_Type_create_subarray");
MPIABI_Type_create_subarray_c_ptr =
    get_symbol(handle, "MPIABI_Type_create_subarray_c");
MPIABI_Type_dup_ptr = get_symbol(handle, "MPIABI_Type_dup");
MPIABI_Type_free_ptr = get_symbol(handle, "MPIABI_Type_free");
MPIABI_Type_get_contents_ptr = get_symbol(handle, "MPIABI_Type_get_contents");
MPIABI_Type_get_contents_c_ptr =
    get_symbol(handle, "MPIABI_Type_get_contents_c");
MPIABI_Type_get_envelope_ptr = get_symbol(handle, "MPIABI_Type_get_envelope");
MPIABI_Type_get_envelope_c_ptr =
    get_symbol(handle, "MPIABI_Type_get_envelope_c");
MPIABI_Type_get_extent_ptr = get_symbol(handle, "MPIABI_Type_get_extent");
MPIABI_Type_get_extent_c_ptr = get_symbol(handle, "MPIABI_Type_get_extent_c");
MPIABI_Type_get_true_extent_ptr =
    get_symbol(handle, "MPIABI_Type_get_true_extent");
MPIABI_Type_get_true_extent_c_ptr =
    get_symbol(handle, "MPIABI_Type_get_true_extent_c");
MPIABI_Type_indexed_ptr = get_symbol(handle, "MPIABI_Type_indexed");
MPIABI_Type_indexed_c_ptr = get_symbol(handle, "MPIABI_Type_indexed_c");
MPIABI_Type_size_ptr = get_symbol(handle, "MPIABI_Type_size");
MPIABI_Type_size_c_ptr = get_symbol(handle, "MPIABI_Type_size_c");
MPIABI_Type_vector_ptr = get_symbol(handle, "MPIABI_Type_vector");
MPIABI_Type_vector_c_ptr = get_symbol(handle, "MPIABI_Type_vector_c");
MPIABI_Unpack_ptr = get_symbol(handle, "MPIABI_Unpack");
MPIABI_Unpack_c_ptr = get_symbol(handle, "MPIABI_Unpack_c");
MPIABI_Unpack_external_ptr = get_symbol(handle, "MPIABI_Unpack_external");
MPIABI_Unpack_external_c_ptr = get_symbol(handle, "MPIABI_Unpack_external_c");

// A.3.4 Collective Communication C Bindings

MPIABI_Allgather_ptr = get_symbol(handle, "MPIABI_Allgather");
MPIABI_Allgather_c_ptr = get_symbol(handle, "MPIABI_Allgather_c");
MPIABI_Allgather_init_ptr = get_symbol(handle, "MPIABI_Allgather_init");
MPIABI_Allgather_init_c_ptr = get_symbol(handle, "MPIABI_Allgather_init_c");
MPIABI_Allgatherv_ptr = get_symbol(handle, "MPIABI_Allgatherv");
MPIABI_Allgatherv_c_ptr = get_symbol(handle, "MPIABI_Allgatherv_c");
MPIABI_Allgatherv_init_ptr = get_symbol(handle, "MPIABI_Allgatherv_init");
MPIABI_Allgatherv_init_c_ptr = get_symbol(handle, "MPIABI_Allgatherv_init_c");
MPIABI_Allreduce_ptr = get_symbol(handle, "MPIABI_Allreduce");
MPIABI_Allreduce_c_ptr = get_symbol(handle, "MPIABI_Allreduce_c");
MPIABI_Allreduce_init_ptr = get_symbol(handle, "MPIABI_Allreduce_init");
MPIABI_Allreduce_init_c_ptr = get_symbol(handle, "MPIABI_Allreduce_init_c");
MPIABI_Alltoall_ptr = get_symbol(handle, "MPIABI_Alltoall");
MPIABI_Alltoall_c_ptr = get_symbol(handle, "MPIABI_Alltoall_c");
MPIABI_Alltoall_init_ptr = get_symbol(handle, "MPIABI_Alltoall_init");
MPIABI_Alltoall_init_c_ptr = get_symbol(handle, "MPIABI_Alltoall_init_c");
MPIABI_Alltoallv_ptr = get_symbol(handle, "MPIABI_Alltoallv");
MPIABI_Alltoallv_c_ptr = get_symbol(handle, "MPIABI_Alltoallv_c");
MPIABI_Alltoallv_init_ptr = get_symbol(handle, "MPIABI_Alltoallv_init");
MPIABI_Alltoallv_init_c_ptr = get_symbol(handle, "MPIABI_Alltoallv_init_c");
MPIABI_Alltoallw_ptr = get_symbol(handle, "MPIABI_Alltoallw");
MPIABI_Alltoallw_c_ptr = get_symbol(handle, "MPIABI_Alltoallw_c");
MPIABI_Alltoallw_init_ptr = get_symbol(handle, "MPIABI_Alltoallw_init");
MPIABI_Alltoallw_init_c_ptr = get_symbol(handle, "MPIABI_Alltoallw_init_c");
MPIABI_Barrier_ptr = get_symbol(handle, "MPIABI_Barrier");
MPIABI_Barrier_init_ptr = get_symbol(handle, "MPIABI_Barrier_init");
MPIABI_Bcast_ptr = get_symbol(handle, "MPIABI_Bcast");
MPIABI_Bcast_c_ptr = get_symbol(handle, "MPIABI_Bcast_c");
MPIABI_Bcast_init_ptr = get_symbol(handle, "MPIABI_Bcast_init");
MPIABI_Bcast_init_c_ptr = get_symbol(handle, "MPIABI_Bcast_init_c");
MPIABI_Exscan_ptr = get_symbol(handle, "MPIABI_Exscan");
MPIABI_Exscan_c_ptr = get_symbol(handle, "MPIABI_Exscan_c");
MPIABI_Exscan_init_ptr = get_symbol(handle, "MPIABI_Exscan_init");
MPIABI_Exscan_init_c_ptr = get_symbol(handle, "MPIABI_Exscan_init_c");
MPIABI_Gather_ptr = get_symbol(handle, "MPIABI_Gather");
MPIABI_Gather_c_ptr = get_symbol(handle, "MPIABI_Gather_c");
MPIABI_Gather_init_ptr = get_symbol(handle, "MPIABI_Gather_init");
MPIABI_Gather_init_c_ptr = get_symbol(handle, "MPIABI_Gather_init_c");
MPIABI_Gatherv_ptr = get_symbol(handle, "MPIABI_Gatherv");
MPIABI_Gatherv_c_ptr = get_symbol(handle, "MPIABI_Gatherv_c");
MPIABI_Gatherv_init_ptr = get_symbol(handle, "MPIABI_Gatherv_init");
MPIABI_Gatherv_init_c_ptr = get_symbol(handle, "MPIABI_Gatherv_init_c");
MPIABI_Iallgather_ptr = get_symbol(handle, "MPIABI_Iallgather");
MPIABI_Iallgather_c_ptr = get_symbol(handle, "MPIABI_Iallgather_c");
MPIABI_Iallgatherv_ptr = get_symbol(handle, "MPIABI_Iallgatherv");
MPIABI_Iallgatherv_c_ptr = get_symbol(handle, "MPIABI_Iallgatherv_c");
MPIABI_Iallreduce_ptr = get_symbol(handle, "MPIABI_Iallreduce");
MPIABI_Iallreduce_c_ptr = get_symbol(handle, "MPIABI_Iallreduce_c");
MPIABI_Ialltoall_ptr = get_symbol(handle, "MPIABI_Ialltoall");
MPIABI_Ialltoall_c_ptr = get_symbol(handle, "MPIABI_Ialltoall_c");
MPIABI_Ialltoallv_ptr = get_symbol(handle, "MPIABI_Ialltoallv");
MPIABI_Ialltoallv_c_ptr = get_symbol(handle, "MPIABI_Ialltoallv_c");
MPIABI_Ialltoallw_ptr = get_symbol(handle, "MPIABI_Ialltoallw");
MPIABI_Ialltoallw_c_ptr = get_symbol(handle, "MPIABI_Ialltoallw_c");
MPIABI_Ibarrier_ptr = get_symbol(handle, "MPIABI_Ibarrier");
MPIABI_Ibcast_ptr = get_symbol(handle, "MPIABI_Ibcast");
MPIABI_Ibcast_c_ptr = get_symbol(handle, "MPIABI_Ibcast_c");
MPIABI_Iexscan_ptr = get_symbol(handle, "MPIABI_Iexscan");
MPIABI_Iexscan_c_ptr = get_symbol(handle, "MPIABI_Iexscan_c");
MPIABI_Igather_ptr = get_symbol(handle, "MPIABI_Igather");
MPIABI_Igather_c_ptr = get_symbol(handle, "MPIABI_Igather_c");
MPIABI_Igatherv_ptr = get_symbol(handle, "MPIABI_Igatherv");
MPIABI_Igatherv_c_ptr = get_symbol(handle, "MPIABI_Igatherv_c");
MPIABI_Ireduce_ptr = get_symbol(handle, "MPIABI_Ireduce");
MPIABI_Ireduce_c_ptr = get_symbol(handle, "MPIABI_Ireduce_c");
MPIABI_Ireduce_scatter_ptr = get_symbol(handle, "MPIABI_Ireduce_scatter");
MPIABI_Ireduce_scatter_block_ptr =
    get_symbol(handle, "MPIABI_Ireduce_scatter_block");
MPIABI_Ireduce_scatter_block_c_ptr =
    get_symbol(handle, "MPIABI_Ireduce_scatter_block_c");
MPIABI_Ireduce_scatter_c_ptr = get_symbol(handle, "MPIABI_Ireduce_scatter_c");
MPIABI_Iscan_ptr = get_symbol(handle, "MPIABI_Iscan");
MPIABI_Iscan_c_ptr = get_symbol(handle, "MPIABI_Iscan_c");
MPIABI_Iscatter_ptr = get_symbol(handle, "MPIABI_Iscatter");
MPIABI_Iscatter_c_ptr = get_symbol(handle, "MPIABI_Iscatter_c");
MPIABI_Iscatterv_ptr = get_symbol(handle, "MPIABI_Iscatterv");
MPIABI_Iscatterv_c_ptr = get_symbol(handle, "MPIABI_Iscatterv_c");
MPIABI_Op_commutative_ptr = get_symbol(handle, "MPIABI_Op_commutative");
MPIABI_Op_create_ptr = get_symbol(handle, "MPIABI_Op_create");
MPIABI_Op_create_c_ptr = get_symbol(handle, "MPIABI_Op_create_c");
MPIABI_Op_free_ptr = get_symbol(handle, "MPIABI_Op_free");
MPIABI_Reduce_ptr = get_symbol(handle, "MPIABI_Reduce");
MPIABI_Reduce_c_ptr = get_symbol(handle, "MPIABI_Reduce_c");
MPIABI_Reduce_init_ptr = get_symbol(handle, "MPIABI_Reduce_init");
MPIABI_Reduce_init_c_ptr = get_symbol(handle, "MPIABI_Reduce_init_c");
MPIABI_Reduce_local_ptr = get_symbol(handle, "MPIABI_Reduce_local");
MPIABI_Reduce_local_c_ptr = get_symbol(handle, "MPIABI_Reduce_local_c");
MPIABI_Reduce_scatter_ptr = get_symbol(handle, "MPIABI_Reduce_scatter");
MPIABI_Reduce_scatter_block_ptr =
    get_symbol(handle, "MPIABI_Reduce_scatter_block");
MPIABI_Reduce_scatter_block_c_ptr =
    get_symbol(handle, "MPIABI_Reduce_scatter_block_c");
MPIABI_Reduce_scatter_block_init_ptr =
    get_symbol(handle, "MPIABI_Reduce_scatter_block_init");
MPIABI_Reduce_scatter_block_init_c_ptr =
    get_symbol(handle, "MPIABI_Reduce_scatter_block_init_c");
MPIABI_Reduce_scatter_c_ptr = get_symbol(handle, "MPIABI_Reduce_scatter_c");
MPIABI_Reduce_scatter_init_ptr =
    get_symbol(handle, "MPIABI_Reduce_scatter_init");
MPIABI_Reduce_scatter_init_c_ptr =
    get_symbol(handle, "MPIABI_Reduce_scatter_init_c");
MPIABI_Scan_ptr = get_symbol(handle, "MPIABI_Scan");
MPIABI_Scan_c_ptr = get_symbol(handle, "MPIABI_Scan_c");
MPIABI_Scan_init_ptr = get_symbol(handle, "MPIABI_Scan_init");
MPIABI_Scan_init_c_ptr = get_symbol(handle, "MPIABI_Scan_init_c");
MPIABI_Scatter_ptr = get_symbol(handle, "MPIABI_Scatter");
MPIABI_Scatter_c_ptr = get_symbol(handle, "MPIABI_Scatter_c");
MPIABI_Scatter_init_ptr = get_symbol(handle, "MPIABI_Scatter_init");
MPIABI_Scatter_init_c_ptr = get_symbol(handle, "MPIABI_Scatter_init_c");
MPIABI_Scatterv_ptr = get_symbol(handle, "MPIABI_Scatterv");
MPIABI_Scatterv_c_ptr = get_symbol(handle, "MPIABI_Scatterv_c");
MPIABI_Scatterv_init_ptr = get_symbol(handle, "MPIABI_Scatterv_init");
MPIABI_Scatterv_init_c_ptr = get_symbol(handle, "MPIABI_Scatterv_init_c");
MPIABI_Type_get_value_index_ptr =
    get_symbol(handle, "MPIABI_Type_get_value_index");

// A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

MPIABI_Comm_compare_ptr = get_symbol(handle, "MPIABI_Comm_compare");
MPIABI_Comm_create_ptr = get_symbol(handle, "MPIABI_Comm_create");
MPIABI_Comm_create_from_group_ptr =
    get_symbol(handle, "MPIABI_Comm_create_from_group");
MPIABI_Comm_create_group_ptr = get_symbol(handle, "MPIABI_Comm_create_group");
MPIABI_Comm_create_keyval_ptr = get_symbol(handle, "MPIABI_Comm_create_keyval");
MPIABI_Comm_delete_attr_ptr = get_symbol(handle, "MPIABI_Comm_delete_attr");
MPIABI_Comm_dup_ptr = get_symbol(handle, "MPIABI_Comm_dup");
MPIABI_Comm_dup_with_info_ptr = get_symbol(handle, "MPIABI_Comm_dup_with_info");
MPIABI_Comm_free_ptr = get_symbol(handle, "MPIABI_Comm_free");
MPIABI_Comm_get_name_ptr = get_symbol(handle, "MPIABI_Comm_get_name");
MPIABI_Comm_free_keyval_ptr = get_symbol(handle, "MPIABI_Comm_free_keyval");
MPIABI_Comm_get_attr_ptr = get_symbol(handle, "MPIABI_Comm_get_attr");
MPIABI_Comm_get_info_ptr = get_symbol(handle, "MPIABI_Comm_get_info");
MPIABI_Comm_group_ptr = get_symbol(handle, "MPIABI_Comm_group");
MPIABI_Comm_idup_ptr = get_symbol(handle, "MPIABI_Comm_idup");
MPIABI_Comm_idup_with_info_ptr =
    get_symbol(handle, "MPIABI_Comm_idup_with_info");
MPIABI_Comm_rank_ptr = get_symbol(handle, "MPIABI_Comm_rank");
MPIABI_Comm_remote_group_ptr = get_symbol(handle, "MPIABI_Comm_remote_group");
MPIABI_Comm_remote_size_ptr = get_symbol(handle, "MPIABI_Comm_remote_size");
MPIABI_Comm_set_attr_ptr = get_symbol(handle, "MPIABI_Comm_set_attr");
MPIABI_Comm_set_info_ptr = get_symbol(handle, "MPIABI_Comm_set_info");
MPIABI_Comm_set_name_ptr = get_symbol(handle, "MPIABI_Comm_set_name");
MPIABI_Comm_size_ptr = get_symbol(handle, "MPIABI_Comm_size");
MPIABI_Comm_split_ptr = get_symbol(handle, "MPIABI_Comm_split");
MPIABI_Group_free_ptr = get_symbol(handle, "MPIABI_Group_free");
MPIABI_Comm_split_type_ptr = get_symbol(handle, "MPIABI_Comm_split_type");
MPIABI_Comm_test_inter_ptr = get_symbol(handle, "MPIABI_Comm_test_inter");
MPIABI_Group_compare_ptr = get_symbol(handle, "MPIABI_Group_compare");
MPIABI_Group_difference_ptr = get_symbol(handle, "MPIABI_Group_difference");
MPIABI_Group_excl_ptr = get_symbol(handle, "MPIABI_Group_excl");
MPIABI_Group_from_session_pset_ptr =
    get_symbol(handle, "MPIABI_Group_from_session_pset");
MPIABI_Group_incl_ptr = get_symbol(handle, "MPIABI_Group_incl");
MPIABI_Group_intersection_ptr = get_symbol(handle, "MPIABI_Group_intersection");
MPIABI_Group_range_excl_ptr = get_symbol(handle, "MPIABI_Group_range_excl");
MPIABI_Group_range_incl_ptr = get_symbol(handle, "MPIABI_Group_range_incl");
MPIABI_Group_rank_ptr = get_symbol(handle, "MPIABI_Group_rank");
MPIABI_Group_size_ptr = get_symbol(handle, "MPIABI_Group_size");
MPIABI_Group_translate_ranks_ptr =
    get_symbol(handle, "MPIABI_Group_translate_ranks");
MPIABI_Group_union_ptr = get_symbol(handle, "MPIABI_Group_union");
MPIABI_Intercomm_create_ptr = get_symbol(handle, "MPIABI_Intercomm_create");
MPIABI_Intercomm_create_from_groups_ptr =
    get_symbol(handle, "MPIABI_Intercomm_create_from_groups");
MPIABI_Intercomm_merge_ptr = get_symbol(handle, "MPIABI_Intercomm_merge");
MPIABI_Type_create_keyval_ptr = get_symbol(handle, "MPIABI_Type_create_keyval");
MPIABI_Type_delete_attr_ptr = get_symbol(handle, "MPIABI_Type_delete_attr");
MPIABI_Type_free_keyval_ptr = get_symbol(handle, "MPIABI_Type_free_keyval");
MPIABI_Type_get_attr_ptr = get_symbol(handle, "MPIABI_Type_get_attr");
MPIABI_Type_get_name_ptr = get_symbol(handle, "MPIABI_Type_get_name");
MPIABI_Type_set_attr_ptr = get_symbol(handle, "MPIABI_Type_set_attr");
MPIABI_Type_set_name_ptr = get_symbol(handle, "MPIABI_Type_set_name");
MPIABI_Win_create_keyval_ptr = get_symbol(handle, "MPIABI_Win_create_keyval");
MPIABI_Win_delete_attr_ptr = get_symbol(handle, "MPIABI_Win_delete_attr");
MPIABI_Win_free_keyval_ptr = get_symbol(handle, "MPIABI_Win_free_keyval");
MPIABI_Win_get_attr_ptr = get_symbol(handle, "MPIABI_Win_get_attr");
MPIABI_Win_get_name_ptr = get_symbol(handle, "MPIABI_Win_get_name");
MPIABI_Win_set_attr_ptr = get_symbol(handle, "MPIABI_Win_set_attr");
MPIABI_Win_set_name_ptr = get_symbol(handle, "MPIABI_Win_set_name");

// A.3.6 Virtual Topologies for MPI Processes C Bindings

MPIABI_Cart_coords_ptr = get_symbol(handle, "MPIABI_Cart_coords");
MPIABI_Cart_create_ptr = get_symbol(handle, "MPIABI_Cart_create");
MPIABI_Cart_get_ptr = get_symbol(handle, "MPIABI_Cart_get");
MPIABI_Cart_map_ptr = get_symbol(handle, "MPIABI_Cart_map");
MPIABI_Cart_rank_ptr = get_symbol(handle, "MPIABI_Cart_rank");
MPIABI_Cart_shift_ptr = get_symbol(handle, "MPIABI_Cart_shift");
MPIABI_Cart_sub_ptr = get_symbol(handle, "MPIABI_Cart_sub");
MPIABI_Cartdim_get_ptr = get_symbol(handle, "MPIABI_Cartdim_get");
MPIABI_Dims_create_ptr = get_symbol(handle, "MPIABI_Dims_create");
MPIABI_Dist_graph_create_ptr = get_symbol(handle, "MPIABI_Dist_graph_create");
MPIABI_Dist_graph_create_adjacent_ptr =
    get_symbol(handle, "MPIABI_Dist_graph_create_adjacent");
MPIABI_Dist_graph_neighbors_ptr =
    get_symbol(handle, "MPIABI_Dist_graph_neighbors");
MPIABI_Dist_graph_neighbors_count_ptr =
    get_symbol(handle, "MPIABI_Dist_graph_neighbors_count");
MPIABI_Graph_create_ptr = get_symbol(handle, "MPIABI_Graph_create");
MPIABI_Graph_get_ptr = get_symbol(handle, "MPIABI_Graph_get");
MPIABI_Graph_map_ptr = get_symbol(handle, "MPIABI_Graph_map");
MPIABI_Graph_neighbors_ptr = get_symbol(handle, "MPIABI_Graph_neighbors");
MPIABI_Graph_neighbors_count_ptr =
    get_symbol(handle, "MPIABI_Graph_neighbors_count");
MPIABI_Graphdims_get_ptr = get_symbol(handle, "MPIABI_Graphdims_get");
MPIABI_Ineighbor_allgather_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_allgather");
MPIABI_Ineighbor_allgather_c_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_allgather_c");
MPIABI_Ineighbor_allgatherv_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_allgatherv");
MPIABI_Ineighbor_allgatherv_c_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_allgatherv_c");
MPIABI_Ineighbor_alltoall_ptr = get_symbol(handle, "MPIABI_Ineighbor_alltoall");
MPIABI_Ineighbor_alltoall_c_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_alltoall_c");
MPIABI_Ineighbor_alltoallv_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_alltoallv");
MPIABI_Ineighbor_alltoallv_c_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_alltoallv_c");
MPIABI_Ineighbor_alltoallw_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_alltoallw");
MPIABI_Ineighbor_alltoallw_c_ptr =
    get_symbol(handle, "MPIABI_Ineighbor_alltoallw_c");
MPIABI_Neighbor_allgather_ptr = get_symbol(handle, "MPIABI_Neighbor_allgather");
MPIABI_Neighbor_allgather_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgather_c");
MPIABI_Neighbor_allgather_init_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgather_init");
MPIABI_Neighbor_allgather_init_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgather_init_c");
MPIABI_Neighbor_allgatherv_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgatherv");
MPIABI_Neighbor_allgatherv_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgatherv_c");
MPIABI_Neighbor_allgatherv_init_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgatherv_init");
MPIABI_Neighbor_allgatherv_init_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_allgatherv_init_c");
MPIABI_Neighbor_alltoall_ptr = get_symbol(handle, "MPIABI_Neighbor_alltoall");
MPIABI_Neighbor_alltoall_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoall_c");
MPIABI_Neighbor_alltoall_init_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoall_init");
MPIABI_Neighbor_alltoall_init_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoall_init_c");
MPIABI_Neighbor_alltoallv_ptr = get_symbol(handle, "MPIABI_Neighbor_alltoallv");
MPIABI_Neighbor_alltoallv_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoallv_c");
MPIABI_Neighbor_alltoallv_init_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoallv_init");
MPIABI_Neighbor_alltoallv_init_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoallv_init_c");
MPIABI_Neighbor_alltoallw_ptr = get_symbol(handle, "MPIABI_Neighbor_alltoallw");
MPIABI_Neighbor_alltoallw_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoallw_c");
MPIABI_Neighbor_alltoallw_init_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoallw_init");
MPIABI_Neighbor_alltoallw_init_c_ptr =
    get_symbol(handle, "MPIABI_Neighbor_alltoallw_init_c");
MPIABI_Topo_test_ptr = get_symbol(handle, "MPIABI_Topo_test");

//TODO // A.3.7 MPI Environmental Management C Bindings
//TODO 
//TODO MPIABI_Add_error_class_ptr = get_symbol(handle, "MPIABI_Add_error_class");
//TODO MPIABI_Add_error_code_ptr = get_symbol(handle, "MPIABI_Add_error_code");
//TODO MPIABI_Add_error_string_ptr = get_symbol(handle, "MPIABI_Add_error_string");
//TODO MPIABI_Alloc_mem_ptr = get_symbol(handle, "MPIABI_Alloc_mem");
//TODO MPIABI_Comm_call_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Comm_call_errhandler");
//TODO MPIABI_Comm_create_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Comm_create_errhandler");
//TODO MPIABI_Comm_get_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Comm_get_errhandler");
//TODO MPIABI_Comm_set_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Comm_set_errhandler");
//TODO MPIABI_Errhandler_free_ptr = get_symbol(handle, "MPIABI_Errhandler_free");
//TODO MPIABI_Error_class_ptr = get_symbol(handle, "MPIABI_Error_class");
//TODO MPIABI_Error_string_ptr = get_symbol(handle, "MPIABI_Error_string");
//TODO MPIABI_File_call_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_File_call_errhandler");
//TODO MPIABI_File_create_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_File_create_errhandler");
//TODO MPIABI_File_get_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_File_get_errhandler");
//TODO MPIABI_File_set_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_File_set_errhandler");
//TODO MPIABI_Free_mem_ptr = get_symbol(handle, "MPIABI_Free_mem");
//TODO MPIABI_Get_hw_resource_info_ptr =
//TODO     get_symbol(handle, "MPIABI_Get_hw_resource_info");
//TODO MPIABI_Get_library_version_ptr =
//TODO     get_symbol(handle, "MPIABI_Get_library_version");
//TODO MPIABI_Get_processor_name_ptr = get_symbol(handle, "MPIABI_Get_processor_name");
//TODO MPIABI_Get_version_ptr = get_symbol(handle, "MPIABI_Get_version");
//TODO MPIABI_Remove_error_class_ptr = get_symbol(handle, "MPIABI_Remove_error_class");
//TODO MPIABI_Remove_error_code_ptr = get_symbol(handle, "MPIABI_Remove_error_code");
//TODO MPIABI_Remove_error_string_ptr =
//TODO     get_symbol(handle, "MPIABI_Remove_error_string");
//TODO MPIABI_Session_call_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_call_errhandler");
//TODO MPIABI_Session_create_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_create_errhandler");
//TODO MPIABI_Session_get_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_get_errhandler");
//TODO MPIABI_Session_set_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_set_errhandler");
//TODO MPIABI_Win_call_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Win_call_errhandler");
//TODO MPIABI_Win_create_errhandler_ptr =
//TODO     get_symbol(handle, "MPIABI_Win_create_errhandler");
//TODO MPIABI_Win_get_errhandler_ptr = get_symbol(handle, "MPIABI_Win_get_errhandler");
//TODO MPIABI_Win_set_errhandler_ptr = get_symbol(handle, "MPIABI_Win_set_errhandler");
//TODO MPIABI_Wtick_ptr = get_symbol(handle, "MPIABI_Wtick");
//TODO MPIABI_Wtime_ptr = get_symbol(handle, "MPIABI_Wtime");
//TODO 
//TODO // A.3.8 The Info Object C Bindings
//TODO 
//TODO MPIABI_Info_create_ptr = get_symbol(handle, "MPIABI_Info_create");
//TODO MPIABI_Info_create_env_ptr = get_symbol(handle, "MPIABI_Info_create_env");
//TODO MPIABI_Info_delete_ptr = get_symbol(handle, "MPIABI_Info_delete");
//TODO MPIABI_Info_dup_ptr = get_symbol(handle, "MPIABI_Info_dup");
//TODO MPIABI_Info_free_ptr = get_symbol(handle, "MPIABI_Info_free");
//TODO MPIABI_Info_get_nkeys_ptr = get_symbol(handle, "MPIABI_Info_get_nkeys");
//TODO MPIABI_Info_get_nthkey_ptr = get_symbol(handle, "MPIABI_Info_get_nthkey");
//TODO MPIABI_Info_get_string_ptr = get_symbol(handle, "MPIABI_Info_get_string");
//TODO MPIABI_Info_set_ptr = get_symbol(handle, "MPIABI_Info_set");
//TODO 
//TODO // A.3.9 Process Creation and Management C Bindings
//TODO 
//TODO MPIABI_Abort_ptr = get_symbol(handle, "MPIABI_Abort");
//TODO MPIABI_Close_port_ptr = get_symbol(handle, "MPIABI_Close_port");
//TODO MPIABI_Comm_accept_ptr = get_symbol(handle, "MPIABI_Comm_accept");
//TODO MPIABI_Comm_connect_ptr = get_symbol(handle, "MPIABI_Comm_connect");
//TODO MPIABI_Comm_disconnect_ptr = get_symbol(handle, "MPIABI_Comm_disconnect");
//TODO MPIABI_Comm_get_parent_ptr = get_symbol(handle, "MPIABI_Comm_get_parent");
//TODO MPIABI_Comm_join_ptr = get_symbol(handle, "MPIABI_Comm_join");
//TODO MPIABI_Comm_spawn_ptr = get_symbol(handle, "MPIABI_Comm_spawn");
//TODO MPIABI_Comm_spawn_multiple_ptr =
//TODO     get_symbol(handle, "MPIABI_Comm_spawn_multiple");
//TODO MPIABI_Finalize_ptr = get_symbol(handle, "MPIABI_Finalize");
//TODO MPIABI_Finalized_ptr = get_symbol(handle, "MPIABI_Finalized");
//TODO MPIABI_Init_ptr = get_symbol(handle, "MPIABI_Init");
//TODO MPIABI_Init_thread_ptr = get_symbol(handle, "MPIABI_Init_thread");
//TODO MPIABI_Initialized_ptr = get_symbol(handle, "MPIABI_Initialized");
//TODO MPIABI_Is_thread_main_ptr = get_symbol(handle, "MPIABI_Is_thread_main");
//TODO MPIABI_Lookup_name_ptr = get_symbol(handle, "MPIABI_Lookup_name");
//TODO MPIABI_Open_port_ptr = get_symbol(handle, "MPIABI_Open_port");
//TODO MPIABI_Publish_name_ptr = get_symbol(handle, "MPIABI_Publish_name");
//TODO MPIABI_Query_thread_ptr = get_symbol(handle, "MPIABI_Query_thread");
//TODO MPIABI_Session_finalize_ptr = get_symbol(handle, "MPIABI_Session_finalize");
//TODO MPIABI_Session_get_info_ptr = get_symbol(handle, "MPIABI_Session_get_info");
//TODO MPIABI_Session_get_nth_pset_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_get_nth_pset");
//TODO MPIABI_Session_get_num_psets_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_get_num_psets");
//TODO MPIABI_Session_get_pset_info_ptr =
//TODO     get_symbol(handle, "MPIABI_Session_get_pset_info");
//TODO MPIABI_Session_init_ptr = get_symbol(handle, "MPIABI_Session_init");
//TODO MPIABI_Unpublish_name_ptr = get_symbol(handle, "MPIABI_Unpublish_name");
//TODO 
//TODO // A.3.10 One-Sided Communications C Bindings
//TODO 
//TODO MPIABI_Accumulate_ptr = get_symbol(handle, "MPIABI_Accumulate");
//TODO MPIABI_Accumulate_c_ptr = get_symbol(handle, "MPIABI_Accumulate_c");
//TODO MPIABI_Compare_and_swap_ptr = get_symbol(handle, "MPIABI_Compare_and_swap");
//TODO MPIABI_Fetch_and_op_ptr = get_symbol(handle, "MPIABI_Fetch_and_op");
//TODO MPIABI_Get_ptr = get_symbol(handle, "MPIABI_Get");
//TODO MPIABI_Get_accumulate_ptr = get_symbol(handle, "MPIABI_Get_accumulate");
//TODO MPIABI_Get_accumulate_c_ptr = get_symbol(handle, "MPIABI_Get_accumulate_c");
//TODO MPIABI_Get_c_ptr = get_symbol(handle, "MPIABI_Get_c");
//TODO MPIABI_Put_ptr = get_symbol(handle, "MPIABI_Put");
//TODO MPIABI_Put_c_ptr = get_symbol(handle, "MPIABI_Put_c");
//TODO MPIABI_Raccumulate_ptr = get_symbol(handle, "MPIABI_Raccumulate");
//TODO MPIABI_Raccumulate_c_ptr = get_symbol(handle, "MPIABI_Raccumulate_c");
//TODO MPIABI_Rget_ptr = get_symbol(handle, "MPIABI_Rget");
//TODO MPIABI_Rget_accumulate_ptr = get_symbol(handle, "MPIABI_Rget_accumulate");
//TODO MPIABI_Rget_accumulate_c_ptr = get_symbol(handle, "MPIABI_Rget_accumulate_c");
//TODO MPIABI_Rget_c_ptr = get_symbol(handle, "MPIABI_Rget_c");
//TODO MPIABI_Rput_ptr = get_symbol(handle, "MPIABI_Rput");
//TODO MPIABI_Rput_c_ptr = get_symbol(handle, "MPIABI_Rput_c");
//TODO MPIABI_Win_allocate_ptr = get_symbol(handle, "MPIABI_Win_allocate");
//TODO MPIABI_Win_allocate_c_ptr = get_symbol(handle, "MPIABI_Win_allocate_c");
//TODO MPIABI_Win_allocate_shared_ptr =
//TODO     get_symbol(handle, "MPIABI_Win_allocate_shared");
//TODO MPIABI_Win_allocate_shared_c_ptr =
//TODO     get_symbol(handle, "MPIABI_Win_allocate_shared_c");
//TODO MPIABI_Win_attach_ptr = get_symbol(handle, "MPIABI_Win_attach");
//TODO MPIABI_Win_complete_ptr = get_symbol(handle, "MPIABI_Win_complete");
//TODO MPIABI_Win_create_ptr = get_symbol(handle, "MPIABI_Win_create");
//TODO MPIABI_Win_create_c_ptr = get_symbol(handle, "MPIABI_Win_create_c");
//TODO MPIABI_Win_create_dynamic_ptr = get_symbol(handle, "MPIABI_Win_create_dynamic");
//TODO MPIABI_Win_detach_ptr = get_symbol(handle, "MPIABI_Win_detach");
//TODO MPIABI_Win_fence_ptr = get_symbol(handle, "MPIABI_Win_fence");
//TODO MPIABI_Win_flush_ptr = get_symbol(handle, "MPIABI_Win_flush");
//TODO MPIABI_Win_flush_all_ptr = get_symbol(handle, "MPIABI_Win_flush_all");
//TODO MPIABI_Win_flush_local_ptr = get_symbol(handle, "MPIABI_Win_flush_local");
//TODO MPIABI_Win_flush_local_all_ptr =
//TODO     get_symbol(handle, "MPIABI_Win_flush_local_all");
//TODO MPIABI_Win_free_ptr = get_symbol(handle, "MPIABI_Win_free");
//TODO MPIABI_Win_get_group_ptr = get_symbol(handle, "MPIABI_Win_get_group");
//TODO MPIABI_Win_get_info_ptr = get_symbol(handle, "MPIABI_Win_get_info");
//TODO MPIABI_Win_lock_ptr = get_symbol(handle, "MPIABI_Win_lock");
//TODO MPIABI_Win_lock_all_ptr = get_symbol(handle, "MPIABI_Win_lock_all");
//TODO MPIABI_Win_post_ptr = get_symbol(handle, "MPIABI_Win_post");
//TODO MPIABI_Win_set_info_ptr = get_symbol(handle, "MPIABI_Win_set_info");
//TODO MPIABI_Win_shared_query_ptr = get_symbol(handle, "MPIABI_Win_shared_query");
//TODO MPIABI_Win_shared_query_c_ptr = get_symbol(handle, "MPIABI_Win_shared_query_c");
//TODO MPIABI_Win_start_ptr = get_symbol(handle, "MPIABI_Win_start");
//TODO MPIABI_Win_sync_ptr = get_symbol(handle, "MPIABI_Win_sync");
//TODO MPIABI_Win_test_ptr = get_symbol(handle, "MPIABI_Win_test");
//TODO MPIABI_Win_unlock_ptr = get_symbol(handle, "MPIABI_Win_unlock");
//TODO MPIABI_Win_unlock_all_ptr = get_symbol(handle, "MPIABI_Win_unlock_all");
//TODO MPIABI_Win_wait_ptr = get_symbol(handle, "MPIABI_Win_wait");
//TODO 
//TODO // A.3.11 External Interfaces C Bindings
//TODO 
//TODO MPIABI_Grequest_complete_ptr = get_symbol(handle, "MPIABI_Grequest_complete");
//TODO MPIABI_Grequest_start_ptr = get_symbol(handle, "MPIABI_Grequest_start");
//TODO MPIABI_Status_set_cancelled_ptr =
//TODO     get_symbol(handle, "MPIABI_Status_set_cancelled");
//TODO MPIABI_Status_set_elements_ptr =
//TODO     get_symbol(handle, "MPIABI_Status_set_elements");
//TODO MPIABI_Status_set_elements_c_ptr =
//TODO     get_symbol(handle, "MPIABI_Status_set_elements_c");
//TODO MPIABI_Status_set_error_ptr = get_symbol(handle, "MPIABI_Status_set_error");
//TODO MPIABI_Status_set_source_ptr = get_symbol(handle, "MPIABI_Status_set_source");
//TODO MPIABI_Status_set_tag_ptr = get_symbol(handle, "MPIABI_Status_set_tag");
//TODO 
//TODO // A.3.12 I/O C Bindings
//TODO 
//TODO MPIABI_File_close_ptr = get_symbol(handle, "MPIABI_File_close");
//TODO MPIABI_File_delete_ptr = get_symbol(handle, "MPIABI_File_delete");
//TODO MPIABI_File_get_amode_ptr = get_symbol(handle, "MPIABI_File_get_amode");
//TODO MPIABI_File_get_atomicity_ptr = get_symbol(handle, "MPIABI_File_get_atomicity");
//TODO MPIABI_File_get_byte_offset_ptr =
//TODO     get_symbol(handle, "MPIABI_File_get_byte_offset");
//TODO MPIABI_File_get_group_ptr = get_symbol(handle, "MPIABI_File_get_group");
//TODO MPIABI_File_get_info_ptr = get_symbol(handle, "MPIABI_File_get_info");
//TODO MPIABI_File_get_position_ptr = get_symbol(handle, "MPIABI_File_get_position");
//TODO MPIABI_File_get_position_shared_ptr =
//TODO     get_symbol(handle, "MPIABI_File_get_position_shared");
//TODO MPIABI_File_get_size_ptr = get_symbol(handle, "MPIABI_File_get_size");
//TODO MPIABI_File_get_type_extent_ptr =
//TODO     get_symbol(handle, "MPIABI_File_get_type_extent");
//TODO MPIABI_File_get_type_extent_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_get_type_extent_c");
//TODO MPIABI_File_get_view_ptr = get_symbol(handle, "MPIABI_File_get_view");
//TODO MPIABI_File_iread_ptr = get_symbol(handle, "MPIABI_File_iread");
//TODO MPIABI_File_iread_all_ptr = get_symbol(handle, "MPIABI_File_iread_all");
//TODO MPIABI_File_iread_all_c_ptr = get_symbol(handle, "MPIABI_File_iread_all_c");
//TODO MPIABI_File_iread_at_ptr = get_symbol(handle, "MPIABI_File_iread_at");
//TODO MPIABI_File_iread_at_all_ptr = get_symbol(handle, "MPIABI_File_iread_at_all");
//TODO MPIABI_File_iread_at_all_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_iread_at_all_c");
//TODO MPIABI_File_iread_at_c_ptr = get_symbol(handle, "MPIABI_File_iread_at_c");
//TODO MPIABI_File_iread_c_ptr = get_symbol(handle, "MPIABI_File_iread_c");
//TODO MPIABI_File_iread_shared_ptr = get_symbol(handle, "MPIABI_File_iread_shared");
//TODO MPIABI_File_iread_shared_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_iread_shared_c");
//TODO MPIABI_File_iwrite_ptr = get_symbol(handle, "MPIABI_File_iwrite");
//TODO MPIABI_File_iwrite_all_ptr = get_symbol(handle, "MPIABI_File_iwrite_all");
//TODO MPIABI_File_iwrite_all_c_ptr = get_symbol(handle, "MPIABI_File_iwrite_all_c");
//TODO MPIABI_File_iwrite_at_ptr = get_symbol(handle, "MPIABI_File_iwrite_at");
//TODO MPIABI_File_iwrite_at_all_ptr = get_symbol(handle, "MPIABI_File_iwrite_at_all");
//TODO MPIABI_File_iwrite_at_all_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_iwrite_at_all_c");
//TODO MPIABI_File_iwrite_at_c_ptr = get_symbol(handle, "MPIABI_File_iwrite_at_c");
//TODO MPIABI_File_iwrite_c_ptr = get_symbol(handle, "MPIABI_File_iwrite_c");
//TODO MPIABI_File_iwrite_shared_ptr = get_symbol(handle, "MPIABI_File_iwrite_shared");
//TODO MPIABI_File_iwrite_shared_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_iwrite_shared_c");
//TODO MPIABI_File_open_ptr = get_symbol(handle, "MPIABI_File_open");
//TODO MPIABI_File_preallocate_ptr = get_symbol(handle, "MPIABI_File_preallocate");
//TODO MPIABI_File_read_ptr = get_symbol(handle, "MPIABI_File_read");
//TODO MPIABI_File_read_all_ptr = get_symbol(handle, "MPIABI_File_read_all");
//TODO MPIABI_File_read_all_begin_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_all_begin");
//TODO MPIABI_File_read_all_begin_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_all_begin_c");
//TODO MPIABI_File_read_all_c_ptr = get_symbol(handle, "MPIABI_File_read_all_c");
//TODO MPIABI_File_read_all_end_ptr = get_symbol(handle, "MPIABI_File_read_all_end");
//TODO MPIABI_File_read_at_ptr = get_symbol(handle, "MPIABI_File_read_at");
//TODO MPIABI_File_read_at_all_ptr = get_symbol(handle, "MPIABI_File_read_at_all");
//TODO MPIABI_File_read_at_all_begin_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_at_all_begin");
//TODO MPIABI_File_read_at_all_begin_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_at_all_begin_c");
//TODO MPIABI_File_read_at_all_c_ptr = get_symbol(handle, "MPIABI_File_read_at_all_c");
//TODO MPIABI_File_read_at_all_end_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_at_all_end");
//TODO MPIABI_File_read_at_c_ptr = get_symbol(handle, "MPIABI_File_read_at_c");
//TODO MPIABI_File_read_c_ptr = get_symbol(handle, "MPIABI_File_read_c");
//TODO MPIABI_File_read_ordered_ptr = get_symbol(handle, "MPIABI_File_read_ordered");
//TODO MPIABI_File_read_ordered_begin_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_ordered_begin");
//TODO MPIABI_File_read_ordered_begin_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_ordered_begin_c");
//TODO MPIABI_File_read_ordered_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_ordered_c");
//TODO MPIABI_File_read_ordered_end_ptr =
//TODO     get_symbol(handle, "MPIABI_File_read_ordered_end");
//TODO MPIABI_File_read_shared_ptr = get_symbol(handle, "MPIABI_File_read_shared");
//TODO MPIABI_File_read_shared_c_ptr = get_symbol(handle, "MPIABI_File_read_shared_c");
//TODO MPIABI_File_seek_ptr = get_symbol(handle, "MPIABI_File_seek");
//TODO MPIABI_File_seek_shared_ptr = get_symbol(handle, "MPIABI_File_seek_shared");
//TODO MPIABI_File_set_atomicity_ptr = get_symbol(handle, "MPIABI_File_set_atomicity");
//TODO MPIABI_File_set_info_ptr = get_symbol(handle, "MPIABI_File_set_info");
//TODO MPIABI_File_set_size_ptr = get_symbol(handle, "MPIABI_File_set_size");
//TODO MPIABI_File_set_view_ptr = get_symbol(handle, "MPIABI_File_set_view");
//TODO MPIABI_File_sync_ptr = get_symbol(handle, "MPIABI_File_sync");
//TODO MPIABI_File_write_ptr = get_symbol(handle, "MPIABI_File_write");
//TODO MPIABI_File_write_all_ptr = get_symbol(handle, "MPIABI_File_write_all");
//TODO MPIABI_File_write_all_begin_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_all_begin");
//TODO MPIABI_File_write_all_begin_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_all_begin_c");
//TODO MPIABI_File_write_all_c_ptr = get_symbol(handle, "MPIABI_File_write_all_c");
//TODO MPIABI_File_write_all_end_ptr = get_symbol(handle, "MPIABI_File_write_all_end");
//TODO MPIABI_File_write_at_ptr = get_symbol(handle, "MPIABI_File_write_at");
//TODO MPIABI_File_write_at_all_ptr = get_symbol(handle, "MPIABI_File_write_at_all");
//TODO MPIABI_File_write_at_all_begin_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_at_all_begin");
//TODO MPIABI_File_write_at_all_begin_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_at_all_begin_c");
//TODO MPIABI_File_write_at_all_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_at_all_c");
//TODO MPIABI_File_write_at_all_end_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_at_all_end");
//TODO MPIABI_File_write_at_c_ptr = get_symbol(handle, "MPIABI_File_write_at_c");
//TODO MPIABI_File_write_c_ptr = get_symbol(handle, "MPIABI_File_write_c");
//TODO MPIABI_File_write_ordered_ptr = get_symbol(handle, "MPIABI_File_write_ordered");
//TODO MPIABI_File_write_ordered_begin_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_ordered_begin");
//TODO MPIABI_File_write_ordered_begin_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_ordered_begin_c");
//TODO MPIABI_File_write_ordered_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_ordered_c");
//TODO MPIABI_File_write_ordered_end_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_ordered_end");
//TODO MPIABI_File_write_shared_ptr = get_symbol(handle, "MPIABI_File_write_shared");
//TODO MPIABI_File_write_shared_c_ptr =
//TODO     get_symbol(handle, "MPIABI_File_write_shared_c");
//TODO MPIABI_Register_datarep_ptr = get_symbol(handle, "MPIABI_Register_datarep");
//TODO MPIABI_Register_datarep_c_ptr = get_symbol(handle, "MPIABI_Register_datarep_c");
//TODO 
//TODO // A.3.13 Language Bindings C Bindings
//TODO 
//TODO MPIABI_Comm_c2f_ptr = get_symbol(handle, "MPIABI_Comm_c2f");
//TODO MPIABI_Comm_f2c_ptr = get_symbol(handle, "MPIABI_Comm_f2c");
//TODO MPIABI_Errhandler_c2f_ptr = get_symbol(handle, "MPIABI_Errhandler_c2f");
//TODO MPIABI_Errhandler_f2c_ptr = get_symbol(handle, "MPIABI_Errhandler_f2c");
//TODO MPIABI_File_c2f_ptr = get_symbol(handle, "MPIABI_File_c2f");
//TODO MPIABI_File_f2c_ptr = get_symbol(handle, "MPIABI_File_f2c");
//TODO MPIABI_Group_c2f_ptr = get_symbol(handle, "MPIABI_Group_c2f");
//TODO MPIABI_Group_f2c_ptr = get_symbol(handle, "MPIABI_Group_f2c");
//TODO MPIABI_Info_c2f_ptr = get_symbol(handle, "MPIABI_Info_c2f");
//TODO MPIABI_Info_f2c_ptr = get_symbol(handle, "MPIABI_Info_f2c");
//TODO MPIABI_Message_c2f_ptr = get_symbol(handle, "MPIABI_Message_c2f");
//TODO MPIABI_Message_f2c_ptr = get_symbol(handle, "MPIABI_Message_f2c");
//TODO MPIABI_Op_c2f_ptr = get_symbol(handle, "MPIABI_Op_c2f");
//TODO MPIABI_Op_f2c_ptr = get_symbol(handle, "MPIABI_Op_f2c");
//TODO MPIABI_Request_c2f_ptr = get_symbol(handle, "MPIABI_Request_c2f");
//TODO MPIABI_Request_f2c_ptr = get_symbol(handle, "MPIABI_Request_f2c");
//TODO MPIABI_Session_c2f_ptr = get_symbol(handle, "MPIABI_Session_c2f");
//TODO MPIABI_Session_f2c_ptr = get_symbol(handle, "MPIABI_Session_f2c");
//TODO MPIABI_Status_f082f_ptr = get_symbol(handle, "MPIABI_Status_f082f");
//TODO MPIABI_Status_c2f_ptr = get_symbol(handle, "MPIABI_Status_c2f");
//TODO MPIABI_Status_c2f08_ptr = get_symbol(handle, "MPIABI_Status_c2f08");
//TODO MPIABI_Status_f082c_ptr = get_symbol(handle, "MPIABI_Status_f082c");
//TODO MPIABI_Status_f2c_ptr = get_symbol(handle, "MPIABI_Status_f2c");
//TODO MPIABI_Status_f2f08_ptr = get_symbol(handle, "MPIABI_Status_f2f08");
//TODO MPIABI_Type_c2f_ptr = get_symbol(handle, "MPIABI_Type_c2f");
//TODO MPIABI_Type_create_f90_complex_ptr =
//TODO     get_symbol(handle, "MPIABI_Type_create_f90_complex");
//TODO MPIABI_Type_create_f90_integer_ptr =
//TODO     get_symbol(handle, "MPIABI_Type_create_f90_integer");
//TODO MPIABI_Type_create_f90_real_ptr =
//TODO     get_symbol(handle, "MPIABI_Type_create_f90_real");
//TODO MPIABI_Type_f2c_ptr = get_symbol(handle, "MPIABI_Type_f2c");
//TODO MPIABI_Type_match_size_ptr = get_symbol(handle, "MPIABI_Type_match_size");
//TODO MPIABI_Win_c2f_ptr = get_symbol(handle, "MPIABI_Win_c2f");
//TODO MPIABI_Win_f2c_ptr = get_symbol(handle, "MPIABI_Win_f2c");
//TODO 
//TODO // A.3.14 Tools / Profiling Interface C Bindings
//TODO 
//TODO MPIABI_Pcontrol_ptr = get_symbol(handle, "MPIABI_Pcontrol");
//TODO 
//TODO // A.3.15 Tools / MPI Tool Information Interface C Bindings
//TODO 
//TODO MPIABI_T_category_changed_ptr = get_symbol(handle, "MPIABI_T_category_changed");
//TODO MPIABI_T_category_get_categories_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_categories");
//TODO MPIABI_T_category_get_cvars_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_cvars");
//TODO MPIABI_T_category_get_events_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_events");
//TODO MPIABI_T_category_get_index_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_index");
//TODO MPIABI_T_category_get_info_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_info");
//TODO MPIABI_T_category_get_num_ptr = get_symbol(handle, "MPIABI_T_category_get_num");
//TODO MPIABI_T_category_get_num_events_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_num_events");
//TODO MPIABI_T_category_get_pvars_ptr =
//TODO     get_symbol(handle, "MPIABI_T_category_get_pvars");
//TODO MPIABI_T_cvar_get_index_ptr = get_symbol(handle, "MPIABI_T_cvar_get_index");
//TODO MPIABI_T_cvar_get_info_ptr = get_symbol(handle, "MPIABI_T_cvar_get_info");
//TODO MPIABI_T_cvar_get_num_ptr = get_symbol(handle, "MPIABI_T_cvar_get_num");
//TODO MPIABI_T_cvar_handle_alloc_ptr =
//TODO     get_symbol(handle, "MPIABI_T_cvar_handle_alloc");
//TODO MPIABI_T_cvar_handle_free_ptr = get_symbol(handle, "MPIABI_T_cvar_handle_free");
//TODO MPIABI_T_cvar_read_ptr = get_symbol(handle, "MPIABI_T_cvar_read");
//TODO MPIABI_T_cvar_write_ptr = get_symbol(handle, "MPIABI_T_cvar_write");
//TODO MPIABI_T_enum_get_info_ptr = get_symbol(handle, "MPIABI_T_enum_get_info");
//TODO MPIABI_T_enum_get_item_ptr = get_symbol(handle, "MPIABI_T_enum_get_item");
//TODO MPIABI_T_event_callback_get_info_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_callback_get_info");
//TODO MPIABI_T_event_callback_set_info_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_callback_set_info");
//TODO MPIABI_T_event_copy_ptr = get_symbol(handle, "MPIABI_T_event_copy");
//TODO MPIABI_T_event_get_index_ptr = get_symbol(handle, "MPIABI_T_event_get_index");
//TODO MPIABI_T_event_get_info_ptr = get_symbol(handle, "MPIABI_T_event_get_info");
//TODO MPIABI_T_event_get_num_ptr = get_symbol(handle, "MPIABI_T_event_get_num");
//TODO MPIABI_T_event_get_source_ptr = get_symbol(handle, "MPIABI_T_event_get_source");
//TODO MPIABI_T_event_get_timestamp_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_get_timestamp");
//TODO MPIABI_T_event_handle_alloc_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_handle_alloc");
//TODO MPIABI_T_event_handle_free_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_handle_free");
//TODO MPIABI_T_event_handle_get_info_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_handle_get_info");
//TODO MPIABI_T_event_handle_set_info_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_handle_set_info");
//TODO MPIABI_T_event_read_ptr = get_symbol(handle, "MPIABI_T_event_read");
//TODO MPIABI_T_event_register_callback_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_register_callback");
//TODO MPIABI_T_event_set_dropped_handler_ptr =
//TODO     get_symbol(handle, "MPIABI_T_event_set_dropped_handler");
//TODO MPIABI_T_finalize_ptr = get_symbol(handle, "MPIABI_T_finalize");
//TODO MPIABI_T_init_thread_ptr = get_symbol(handle, "MPIABI_T_init_thread");
//TODO MPIABI_T_pvar_get_index_ptr = get_symbol(handle, "MPIABI_T_pvar_get_index");
//TODO MPIABI_T_pvar_get_info_ptr = get_symbol(handle, "MPIABI_T_pvar_get_info");
//TODO MPIABI_T_pvar_get_num_ptr = get_symbol(handle, "MPIABI_T_pvar_get_num");
//TODO MPIABI_T_pvar_handle_alloc_ptr =
//TODO     get_symbol(handle, "MPIABI_T_pvar_handle_alloc");
//TODO MPIABI_T_pvar_handle_free_ptr = get_symbol(handle, "MPIABI_T_pvar_handle_free");
//TODO MPIABI_T_pvar_read_ptr = get_symbol(handle, "MPIABI_T_pvar_read");
//TODO MPIABI_T_pvar_readreset_ptr = get_symbol(handle, "MPIABI_T_pvar_readreset");
//TODO MPIABI_T_pvar_reset_ptr = get_symbol(handle, "MPIABI_T_pvar_reset");
//TODO MPIABI_T_pvar_session_create_ptr =
//TODO     get_symbol(handle, "MPIABI_T_pvar_session_create");
//TODO MPIABI_T_pvar_session_free_ptr =
//TODO     get_symbol(handle, "MPIABI_T_pvar_session_free");
//TODO MPIABI_T_pvar_start_ptr = get_symbol(handle, "MPIABI_T_pvar_start");
//TODO MPIABI_T_pvar_stop_ptr = get_symbol(handle, "MPIABI_T_pvar_stop");
//TODO MPIABI_T_pvar_write_ptr = get_symbol(handle, "MPIABI_T_pvar_write");
//TODO MPIABI_T_source_get_info_ptr = get_symbol(handle, "MPIABI_T_source_get_info");
//TODO MPIABI_T_source_get_num_ptr = get_symbol(handle, "MPIABI_T_source_get_num");
//TODO MPIABI_T_source_get_timestamp_ptr =
//TODO     get_symbol(handle, "MPIABI_T_source_get_timestamp");
//TODO 
//TODO // A.3.16 Deprecated C Bindings
//TODO 
//TODO MPIABI_Attr_delete_ptr = get_symbol(handle, "MPIABI_Attr_delete");
//TODO MPIABI_Attr_get_ptr = get_symbol(handle, "MPIABI_Attr_get");
//TODO MPIABI_Attr_put_ptr = get_symbol(handle, "MPIABI_Attr_put");
//TODO MPIABI_Get_elements_x_ptr = get_symbol(handle, "MPIABI_Get_elements_x");
//TODO MPIABI_Info_get_ptr = get_symbol(handle, "MPIABI_Info_get");
//TODO MPIABI_Info_get_valuelen_ptr = get_symbol(handle, "MPIABI_Info_get_valuelen");
//TODO MPIABI_Keyval_create_ptr = get_symbol(handle, "MPIABI_Keyval_create");
//TODO MPIABI_Keyval_free_ptr = get_symbol(handle, "MPIABI_Keyval_free");
//TODO MPIABI_Status_set_elements_x_ptr =
//TODO     get_symbol(handle, "MPIABI_Status_set_elements_x");
//TODO MPIABI_Type_get_extent_x_ptr = get_symbol(handle, "MPIABI_Type_get_extent_x");
//TODO MPIABI_Type_get_true_extent_x_ptr =
//TODO     get_symbol(handle, "MPIABI_Type_get_true_extent_x");
//TODO MPIABI_Type_size_x_ptr = get_symbol(handle, "MPIABI_Type_size_x");

// MPIX

MPIXABI_Query_cuda_support_ptr =
    get_symbol(handle, "MPIXABI_Query_cuda_support");
MPIXABI_Query_hip_support_ptr = get_symbol(handle, "MPIXABI_Query_hip_support");
MPIXABI_Query_rocm_support_ptr =
    get_symbol(handle, "MPIXABI_Query_rocm_support");
MPIXABI_Query_ze_support_ptr = get_symbol(handle, "MPIXABI_Query_ze_support");
