#include <mpi.h>

#define MPI_VERSION_NUMBER (100 * MPI_VERSION + MPI_SUBVERSION)

#if MPI_VERSION_NUMBER < 400

#error "don't want to be here"

#include <assert.h>

// Fake MPI 4 support, just enough to make the linker happy

// C functions

void MPI_Accumulate_c() { assert(0); }
void MPI_Allgather_c() { assert(0); }
void MPI_Allgather_init_c() { assert(0); }
void MPI_Allgatherv_c() { assert(0); }
void MPI_Allgatherv_init_c() { assert(0); }
void MPI_Allreduce_c() { assert(0); }
void MPI_Allreduce_init_c() { assert(0); }
void MPI_Alltoall_c() { assert(0); }
void MPI_Alltoall_init_c() { assert(0); }
void MPI_Alltoallv_c() { assert(0); }
void MPI_Alltoallv_init_c() { assert(0); }
void MPI_Alltoallw_c() { assert(0); }
void MPI_Alltoallw_init_c() { assert(0); }
void MPI_Bcast_c() { assert(0); }
void MPI_Bcast_init_c() { assert(0); }
void MPI_Bsend_c() { assert(0); }
void MPI_Bsend_init_c() { assert(0); }
void MPI_Buffer_attach_c() { assert(0); }
void MPI_Buffer_detach_c() { assert(0); }
void MPI_Exscan_c() { assert(0); }
void MPI_Exscan_init_c() { assert(0); }
void MPI_Gather_c() { assert(0); }
void MPI_Gather_init_c() { assert(0); }
void MPI_Gatherv_c() { assert(0); }
void MPI_Gatherv_init_c() { assert(0); }
void MPI_Get_accumulate_c() { assert(0); }
void MPI_Get_c() { assert(0); }
void MPI_Get_count_c() { assert(0); }
void MPI_Get_elements_c() { assert(0); }
void MPI_Iallgather_c() { assert(0); }
void MPI_Iallgatherv_c() { assert(0); }
void MPI_Iallreduce_c() { assert(0); }
void MPI_Ialltoall_c() { assert(0); }
void MPI_Ialltoallv_c() { assert(0); }
void MPI_Ialltoallw_c() { assert(0); }
void MPI_Ibcast_c() { assert(0); }
void MPI_Ibsend_c() { assert(0); }
void MPI_Iexscan_c() { assert(0); }
void MPI_Igather_c() { assert(0); }
void MPI_Igatherv_c() { assert(0); }
void MPI_Imrecv_c() { assert(0); }
void MPI_Ineighbor_allgather_c() { assert(0); }
void MPI_Ineighbor_allgatherv_c() { assert(0); }
void MPI_Ineighbor_alltoall_c() { assert(0); }
void MPI_Ineighbor_alltoallv_c() { assert(0); }
void MPI_Ineighbor_alltoallw_c() { assert(0); }
void MPI_Irecv_c() { assert(0); }
void MPI_Ireduce_c() { assert(0); }
void MPI_Ireduce_scatter_block_c() { assert(0); }
void MPI_Ireduce_scatter_c() { assert(0); }
void MPI_Irsend_c() { assert(0); }
void MPI_Iscan_c() { assert(0); }
void MPI_Iscatter_c() { assert(0); }
void MPI_Iscatterv_c() { assert(0); }
void MPI_Isend_c() { assert(0); }
void MPI_Isendrecv_c() { assert(0); }
void MPI_Isendrecv_replace_c() { assert(0); }
void MPI_Issend_c() { assert(0); }
void MPI_Mrecv_c() { assert(0); }
void MPI_Neighbor_allgather_c() { assert(0); }
void MPI_Neighbor_allgather_init_c() { assert(0); }
void MPI_Neighbor_allgatherv_c() { assert(0); }
void MPI_Neighbor_allgatherv_init_c() { assert(0); }
void MPI_Neighbor_alltoall_c() { assert(0); }
void MPI_Neighbor_alltoall_init_c() { assert(0); }
void MPI_Neighbor_alltoallv_c() { assert(0); }
void MPI_Neighbor_alltoallv_init_c() { assert(0); }
void MPI_Neighbor_alltoallw_c() { assert(0); }
void MPI_Neighbor_alltoallw_init_c() { assert(0); }
void MPI_Op_create_c() { assert(0); }
void MPI_Pack_c() { assert(0); }
void MPI_Pack_external_c() { assert(0); }
void MPI_Pack_external_size_c() { assert(0); }
void MPI_Pack_size_c() { assert(0); }
void MPI_Raccumulate_c() { assert(0); }
void MPI_Recv_c() { assert(0); }
void MPI_Recv_init_c() { assert(0); }
void MPI_Reduce_c() { assert(0); }
void MPI_Reduce_init_c() { assert(0); }
void MPI_Reduce_local_c() { assert(0); }
void MPI_Reduce_scatter_block_c() { assert(0); }
void MPI_Reduce_scatter_block_init_c() { assert(0); }
void MPI_Reduce_scatter_c() { assert(0); }
void MPI_Reduce_scatter_init_c() { assert(0); }
void MPI_Rget_accumulate_c() { assert(0); }
void MPI_Rget_c() { assert(0); }
void MPI_Rput_c() { assert(0); }
void MPI_Rsend_c() { assert(0); }
void MPI_Rsend_init_c() { assert(0); }
void MPI_Scan_c() { assert(0); }
void MPI_Scan_init_c() { assert(0); }
void MPI_Scatter_c() { assert(0); }
void MPI_Scatter_init_c() { assert(0); }
void MPI_Scatterv_c() { assert(0); }
void MPI_Scatterv_init_c() { assert(0); }
void MPI_Send_c() { assert(0); }
void MPI_Send_init_c() { assert(0); }
void MPI_Sendrecv_c() { assert(0); }
void MPI_Sendrecv_replace_c() { assert(0); }
void MPI_Ssend_c() { assert(0); }
void MPI_Ssend_init_c() { assert(0); }
void MPI_Status_set_elements_c() { assert(0); }
void MPI_Type_contiguous_c() { assert(0); }
void MPI_Type_create_darray_c() { assert(0); }
void MPI_Type_create_hindexed_block_c() { assert(0); }
void MPI_Type_create_hindexed_c() { assert(0); }
void MPI_Type_create_hvector_c() { assert(0); }
void MPI_Type_create_indexed_block_c() { assert(0); }
void MPI_Type_create_resized_c() { assert(0); }
void MPI_Type_create_struct_c() { assert(0); }
void MPI_Type_create_subarray_c() { assert(0); }
void MPI_Type_get_contents_c() { assert(0); }
void MPI_Type_get_envelope_c() { assert(0); }
void MPI_Type_get_extent_c() { assert(0); }
void MPI_Type_get_true_extent_c() { assert(0); }
void MPI_Type_indexed_c() { assert(0); }
void MPI_Type_size_c() { assert(0); }
void MPI_Type_vector_c() { assert(0); }
void MPI_Unpack_c() { assert(0); }
void MPI_Unpack_external_c() { assert(0); }
void MPI_Win_allocate_shared_c() { assert(0); }
void MPI_Win_create_c() { assert(0); }
void MPI_Win_shared_query_c() { assert(0); }
void MPI_File_get_type_extent_c() { assert(0); }
void MPI_File_iread_all_c() { assert(0); }
void MPI_File_iread_at_all_c() { assert(0); }
void MPI_File_iread_at_c() { assert(0); }
void MPI_File_iread_c() { assert(0); }
void MPI_File_iread_shared_c() { assert(0); }
void MPI_File_iwrite_all_c() { assert(0); }
void MPI_File_iwrite_at_all_c() { assert(0); }
void MPI_File_iwrite_at_c() { assert(0); }
void MPI_File_iwrite_c() { assert(0); }
void MPI_File_iwrite_shared_c() { assert(0); }
void MPI_File_read_all_begin_c() { assert(0); }
void MPI_File_read_all_c() { assert(0); }
void MPI_File_read_at_all_begin_c() { assert(0); }
void MPI_File_read_at_all_c() { assert(0); }
void MPI_File_read_ordered_begin_c() { assert(0); }
void MPI_File_read_ordered_c() { assert(0); }
void MPI_File_read_shared_c() { assert(0); }
void MPI_File_write_all_begin_c() { assert(0); }
void MPI_File_write_all_c() { assert(0); }
void MPI_File_write_at_all_begin_c() { assert(0); }
void MPI_File_write_at_all_c() { assert(0); }
void MPI_File_write_ordered_begin_c() { assert(0); }
void MPI_File_write_ordered_c() { assert(0); }
void MPI_File_write_shared_c() { assert(0); }
void MPI_Register_datarep_c() { assert(0); }

// Fortran functions

void mpi_buffer_flush_() { assert(0); }
void mpi_buffer_iflush_() { assert(0); }
void mpi_comm_attach_buffer_() { assert(0); }
void mpi_comm_detach_buffer_() { assert(0); }
void mpi_comm_flush_buffer_() { assert(0); }
void mpi_comm_iflush_buffer_() { assert(0); }
void mpi_request_get_status_all_() { assert(0); }
void mpi_request_get_status_any_() { assert(0); }
void mpi_request_get_status_some_() { assert(0); }
void mpi_session_attach_buffer_() { assert(0); }
void mpi_session_detach_buffer_() { assert(0); }
void mpi_session_flush_buffer_() { assert(0); }
void mpi_session_iflush_buffer_() { assert(0); }
void mpi_status_get_error_() { assert(0); }
void mpi_status_get_source_() { assert(0); }
void mpi_status_get_tag_() { assert(0); }

#endif
