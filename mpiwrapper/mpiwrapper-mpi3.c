// Fake MPI 4 support, just enough to make the linker happy

#include <stdlib.h>

// C functions

void MPI_Accumulate_c(void) { abort(); }
void MPI_Allgather_c(void) { abort(); }
void MPI_Allgather_init(void) { abort(); }
void MPI_Allgather_init_c(void) { abort(); }
void MPI_Allgatherv_c(void) { abort(); }
void MPI_Allgatherv_init(void) { abort(); }
void MPI_Allgatherv_init_c(void) { abort(); }
void MPI_Allreduce_c(void) { abort(); }
void MPI_Allreduce_init(void) { abort(); }
void MPI_Allreduce_init_c(void) { abort(); }
void MPI_Alltoall_c(void) { abort(); }
void MPI_Alltoall_init(void) { abort(); }
void MPI_Alltoall_init_c(void) { abort(); }
void MPI_Alltoallv_c(void) { abort(); }
void MPI_Alltoallv_init(void) { abort(); }
void MPI_Alltoallv_init_c(void) { abort(); }
void MPI_Alltoallw_c(void) { abort(); }
void MPI_Alltoallw_init(void) { abort(); }
void MPI_Alltoallw_init_c(void) { abort(); }
void MPI_Barrier_init(void) { abort(); }
void MPI_Bcast_c(void) { abort(); }
void MPI_Bcast_init(void) { abort(); }
void MPI_Bcast_init_c(void) { abort(); }
void MPI_Bsend_c(void) { abort(); }
void MPI_Bsend_init_c(void) { abort(); }
void MPI_Buffer_attach_c(void) { abort(); }
void MPI_Buffer_detach_c(void) { abort(); }
void MPI_Comm_create_from_group(void) { abort(); }
void MPI_Comm_idup_with_info(void) { abort(); }
void MPI_Exscan_c(void) { abort(); }
void MPI_Exscan_init(void) { abort(); }
void MPI_Exscan_init_c(void) { abort(); }
void MPI_File_get_type_extent_c(void) { abort(); }
void MPI_File_iread_all_c(void) { abort(); }
void MPI_File_iread_at_all_c(void) { abort(); }
void MPI_File_iread_at_c(void) { abort(); }
void MPI_File_iread_c(void) { abort(); }
void MPI_File_iread_shared_c(void) { abort(); }
void MPI_File_iwrite_all_c(void) { abort(); }
void MPI_File_iwrite_at_all_c(void) { abort(); }
void MPI_File_iwrite_at_c(void) { abort(); }
void MPI_File_iwrite_c(void) { abort(); }
void MPI_File_iwrite_shared_c(void) { abort(); }
void MPI_File_read_all_begin_c(void) { abort(); }
void MPI_File_read_all_c(void) { abort(); }
void MPI_File_read_at_all_begin_c(void) { abort(); }
void MPI_File_read_at_all_c(void) { abort(); }
void MPI_File_read_ordered_begin_c(void) { abort(); }
void MPI_File_read_ordered_c(void) { abort(); }
void MPI_File_read_shared_c(void) { abort(); }
void MPI_File_write_all_begin_c(void) { abort(); }
void MPI_File_write_all_c(void) { abort(); }
void MPI_File_write_at_all_begin_c(void) { abort(); }
void MPI_File_write_at_all_c(void) { abort(); }
void MPI_File_write_ordered_begin_c(void) { abort(); }
void MPI_File_write_ordered_c(void) { abort(); }
void MPI_File_write_shared_c(void) { abort(); }
void MPI_Gather_c(void) { abort(); }
void MPI_Gather_init(void) { abort(); }
void MPI_Gather_init_c(void) { abort(); }
void MPI_Gatherv_c(void) { abort(); }
void MPI_Gatherv_init(void) { abort(); }
void MPI_Gatherv_init_c(void) { abort(); }
void MPI_Get_accumulate_c(void) { abort(); }
void MPI_Get_c(void) { abort(); }
void MPI_Get_count_c(void) { abort(); }
void MPI_Get_elements_c(void) { abort(); }
void MPI_Group_from_session_pset(void) { abort(); }
void MPI_Iallgather_c(void) { abort(); }
void MPI_Iallgatherv_c(void) { abort(); }
void MPI_Iallreduce_c(void) { abort(); }
void MPI_Ialltoall_c(void) { abort(); }
void MPI_Ialltoallv_c(void) { abort(); }
void MPI_Ialltoallw_c(void) { abort(); }
void MPI_Ibcast_c(void) { abort(); }
void MPI_Ibsend_c(void) { abort(); }
void MPI_Iexscan_c(void) { abort(); }
void MPI_Igather_c(void) { abort(); }
void MPI_Igatherv_c(void) { abort(); }
void MPI_Imrecv_c(void) { abort(); }
void MPI_Ineighbor_allgather_c(void) { abort(); }
void MPI_Ineighbor_allgatherv_c(void) { abort(); }
void MPI_Ineighbor_alltoall_c(void) { abort(); }
void MPI_Ineighbor_alltoallv_c(void) { abort(); }
void MPI_Ineighbor_alltoallw_c(void) { abort(); }
void MPI_Info_create_env(void) { abort(); }
void MPI_Info_get_string(void) { abort(); }
void MPI_Intercomm_create_from_groups(void) { abort(); }
void MPI_Irecv_c(void) { abort(); }
void MPI_Ireduce_c(void) { abort(); }
void MPI_Ireduce_scatter_block_c(void) { abort(); }
void MPI_Ireduce_scatter_c(void) { abort(); }
void MPI_Irsend_c(void) { abort(); }
void MPI_Iscan_c(void) { abort(); }
void MPI_Iscatter_c(void) { abort(); }
void MPI_Iscatterv_c(void) { abort(); }
void MPI_Isend_c(void) { abort(); }
void MPI_Isendrecv(void) { abort(); }
void MPI_Isendrecv_c(void) { abort(); }
void MPI_Isendrecv_replace(void) { abort(); }
void MPI_Isendrecv_replace_c(void) { abort(); }
void MPI_Issend_c(void) { abort(); }
void MPI_Mrecv_c(void) { abort(); }
void MPI_Neighbor_allgather_c(void) { abort(); }
void MPI_Neighbor_allgather_init(void) { abort(); }
void MPI_Neighbor_allgather_init_c(void) { abort(); }
void MPI_Neighbor_allgatherv_c(void) { abort(); }
void MPI_Neighbor_allgatherv_init(void) { abort(); }
void MPI_Neighbor_allgatherv_init_c(void) { abort(); }
void MPI_Neighbor_alltoall_c(void) { abort(); }
void MPI_Neighbor_alltoall_init(void) { abort(); }
void MPI_Neighbor_alltoall_init_c(void) { abort(); }
void MPI_Neighbor_alltoallv_c(void) { abort(); }
void MPI_Neighbor_alltoallv_init(void) { abort(); }
void MPI_Neighbor_alltoallv_init_c(void) { abort(); }
void MPI_Neighbor_alltoallw_c(void) { abort(); }
void MPI_Neighbor_alltoallw_init(void) { abort(); }
void MPI_Neighbor_alltoallw_init_c(void) { abort(); }
void MPI_Op_create_c(void) { abort(); }
void MPI_Pack_c(void) { abort(); }
void MPI_Pack_external_c(void) { abort(); }
void MPI_Pack_external_size_c(void) { abort(); }
void MPI_Pack_size_c(void) { abort(); }
void MPI_Parrived(void) { abort(); }
void MPI_Pready(void) { abort(); }
void MPI_Pready_list(void) { abort(); }
void MPI_Pready_range(void) { abort(); }
void MPI_Precv_init(void) { abort(); }
void MPI_Psend_init(void) { abort(); }
void MPI_Raccumulate_c(void) { abort(); }
void MPI_Recv_c(void) { abort(); }
void MPI_Recv_init_c(void) { abort(); }
void MPI_Reduce_c(void) { abort(); }
void MPI_Reduce_init(void) { abort(); }
void MPI_Reduce_init_c(void) { abort(); }
void MPI_Reduce_local_c(void) { abort(); }
void MPI_Reduce_scatter_block_c(void) { abort(); }
void MPI_Reduce_scatter_block_init(void) { abort(); }
void MPI_Reduce_scatter_block_init_c(void) { abort(); }
void MPI_Reduce_scatter_c(void) { abort(); }
void MPI_Reduce_scatter_init(void) { abort(); }
void MPI_Reduce_scatter_init_c(void) { abort(); }
void MPI_Register_datarep_c(void) { abort(); }
void MPI_Rget_accumulate_c(void) { abort(); }
void MPI_Rget_c(void) { abort(); }
void MPI_Rput_c(void) { abort(); }
void MPI_Rsend_c(void) { abort(); }
void MPI_Rsend_init_c(void) { abort(); }
void MPI_Scan_c(void) { abort(); }
void MPI_Scan_init(void) { abort(); }
void MPI_Scan_init_c(void) { abort(); }
void MPI_Scatter_c(void) { abort(); }
void MPI_Scatter_init(void) { abort(); }
void MPI_Scatter_init_c(void) { abort(); }
void MPI_Scatterv_c(void) { abort(); }
void MPI_Scatterv_init(void) { abort(); }
void MPI_Scatterv_init_c(void) { abort(); }
void MPI_Send_c(void) { abort(); }
void MPI_Send_init_c(void) { abort(); }
void MPI_Sendrecv_c(void) { abort(); }
void MPI_Sendrecv_replace_c(void) { abort(); }
void MPI_Session_call_errhandler(void) { abort(); }
void MPI_Session_finalize(void) { abort(); }
void MPI_Session_get_errhandler(void) { abort(); }
void MPI_Session_get_info(void) { abort(); }
void MPI_Session_get_nth_pset(void) { abort(); }
void MPI_Session_get_num_psets(void) { abort(); }
void MPI_Session_get_pset_info(void) { abort(); }
void MPI_Session_init(void) { abort(); }
void MPI_Session_set_errhandler(void) { abort(); }
void MPI_Ssend_c(void) { abort(); }
void MPI_Ssend_init_c(void) { abort(); }
void MPI_Status_set_elements_c(void) { abort(); }
void MPI_Type_contiguous_c(void) { abort(); }
void MPI_Type_create_darray_c(void) { abort(); }
void MPI_Type_create_hindexed_block_c(void) { abort(); }
void MPI_Type_create_hindexed_c(void) { abort(); }
void MPI_Type_create_hvector_c(void) { abort(); }
void MPI_Type_create_indexed_block_c(void) { abort(); }
void MPI_Type_create_resized_c(void) { abort(); }
void MPI_Type_create_struct_c(void) { abort(); }
void MPI_Type_create_subarray_c(void) { abort(); }
void MPI_Type_get_contents_c(void) { abort(); }
void MPI_Type_get_envelope_c(void) { abort(); }
void MPI_Type_get_extent_c(void) { abort(); }
void MPI_Type_get_true_extent_c(void) { abort(); }
void MPI_Type_indexed_c(void) { abort(); }
void MPI_Type_size_c(void) { abort(); }
void MPI_Type_vector_c(void) { abort(); }
void MPI_Unpack_c(void) { abort(); }
void MPI_Unpack_external_c(void) { abort(); }
void MPI_Win_allocate_shared_c(void) { abort(); }
void MPI_Win_create_c(void) { abort(); }
void MPI_Win_shared_query_c(void) { abort(); }

// Fortran functions

void mpi_allgather_init_(void) { abort(); }
void mpi_allgatherv_init_(void) { abort(); }
void mpi_allreduce_init_(void) { abort(); }
void mpi_alltoall_init_(void) { abort(); }
void mpi_alltoallv_init_(void) { abort(); }
void mpi_alltoallw_init_(void) { abort(); }
void mpi_barrier_init_(void) { abort(); }
void mpi_bcast_init_(void) { abort(); }
void mpi_buffer_flush_(void) { abort(); }
void mpi_buffer_iflush_(void) { abort(); }
void mpi_comm_attach_buffer_(void) { abort(); }
void mpi_comm_create_from_group_(void) { abort(); }
void mpi_comm_detach_buffer_(void) { abort(); }
void mpi_comm_flush_buffer_(void) { abort(); }
void mpi_comm_idup_with_info_(void) { abort(); }
void mpi_comm_iflush_buffer_(void) { abort(); }
void mpi_exscan_init_(void) { abort(); }
void mpi_gather_init_(void) { abort(); }
void mpi_gatherv_init_(void) { abort(); }
void mpi_group_from_session_pset_(void) { abort(); }
void mpi_info_create_env_(void) { abort(); }
void mpi_info_get_string_(void) { abort(); }
void mpi_intercomm_create_from_groups_(void) { abort(); }
void mpi_isendrecv_(void) { abort(); }
void mpi_isendrecv_replace_(void) { abort(); }
void mpi_neighbor_allgather_init_(void) { abort(); }
void mpi_neighbor_allgatherv_init_(void) { abort(); }
void mpi_neighbor_alltoall_init_(void) { abort(); }
void mpi_neighbor_alltoallv_init_(void) { abort(); }
void mpi_neighbor_alltoallw_init_(void) { abort(); }
void mpi_parrived_(void) { abort(); }
void mpi_pready_(void) { abort(); }
void mpi_pready_list_(void) { abort(); }
void mpi_pready_range_(void) { abort(); }
void mpi_precv_init_(void) { abort(); }
void mpi_psend_init_(void) { abort(); }
void mpi_reduce_init_(void) { abort(); }
void mpi_reduce_scatter_block_init_(void) { abort(); }
void mpi_reduce_scatter_init_(void) { abort(); }
void mpi_request_get_status_all_(void) { abort(); }
void mpi_request_get_status_any_(void) { abort(); }
void mpi_request_get_status_some_(void) { abort(); }
void mpi_scan_init_(void) { abort(); }
void mpi_scatter_init_(void) { abort(); }
void mpi_scatterv_init_(void) { abort(); }
void mpi_session_attach_buffer_(void) { abort(); }
void mpi_session_call_errhandler_(void) { abort(); }
void mpi_session_detach_buffer_(void) { abort(); }
void mpi_session_finalize_(void) { abort(); }
void mpi_session_flush_buffer_(void) { abort(); }
void mpi_session_get_errhandler_(void) { abort(); }
void mpi_session_get_info_(void) { abort(); }
void mpi_session_get_nth_pset_(void) { abort(); }
void mpi_session_get_num_psets_(void) { abort(); }
void mpi_session_get_pset_info_(void) { abort(); }
void mpi_session_iflush_buffer_(void) { abort(); }
void mpi_session_init_(void) { abort(); }
void mpi_session_set_errhandler_(void) { abort(); }
void mpi_status_get_error_(void) { abort(); }
void mpi_status_get_source_(void) { abort(); }
void mpi_status_get_tag_(void) { abort(); }
