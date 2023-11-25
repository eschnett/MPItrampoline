!     A.3 C Bindings

!     A.3.1 Point-to-Point Communication C Bindings

      external MPI_bsend
!     external MPI_bsend_c
      external MPI_Bsend_init
!     external MPI_Bsend_init_c
      external MPI_Buffer_attach
!     external MPI_Buffer_attach_c
      external MPI_Buffer_detach
!     external MPI_Buffer_detach_c
      external MPI_Buffer_flush
      external MPI_Buffer_iflush
      external MPI_Cancel
      external MPI_Comm_attach_buffer
!     external MPI_Comm_attach_buffer_c
      external MPI_Comm_detach_buffer
!     external MPI_Comm_detach_buffer_c
      external MPI_Comm_flush_buffer
      external MPI_Comm_iflush_buffer
      external MPI_Get_count
!     external MPI_Get_count_c
      external MPI_Ibsend
!     external MPI_Ibsend_c
      external MPI_Improbe
      external MPI_Imrecv
!     external MPI_Imrecv_c
      external MPI_Iprobe
      external MPI_Irecv
!     external MPI_Irecv_c
      external MPI_Irsend
!     external MPI_Irsend_c
      external MPI_Isend
!     external MPI_Isend_c
      external MPI_Isendrecv
!     external MPI_Isendrecv_c
      external MPI_Isendrecv_replace
!     external MPI_Isendrecv_replace_c
      external MPI_Issend
!     external MPI_Issend_c
      external MPI_Mprobe
      external MPI_Mrecv
!     external MPI_Mrecv_c
      external MPI_Probe
      external MPI_Recv
!     external MPI_Recv_c
      external MPI_Recv_init
!     external MPI_Recv_init_c
      external MPI_Request_free
      external MPI_Request_get_status
      external MPI_Request_get_status_all
      external MPI_Request_get_status_any
      external MPI_Request_get_status_some
      external MPI_Rsend
!     external MPI_Rsend_c
      external MPI_Rsend_init
!     external MPI_Rsend_init_c
      external MPI_Send
!     external MPI_Send_c
      external MPI_Send_init
!     external MPI_Send_init_c
      external MPI_Sendrecv
!     external MPI_Sendrecv_c
      external MPI_Sendrecv_replace
!     external MPI_Sendrecv_replace_c
      external MPI_Session_attach_buffer
!     external MPI_Session_attach_buffer_c
      external MPI_Session_detach_buffer
!     external MPI_Session_detach_buffer_c
      external MPI_Session_flush_buffer
      external MPI_Session_iflush_buffer
      external MPI_Ssend
!     external MPI_Ssend_c
      external MPI_Ssend_init
!     external MPI_Ssend_init_c
      external MPI_Start
      external MPI_Startall
      external MPI_Status_get_error
      external MPI_Status_get_source
      external MPI_Status_get_tag
      external MPI_Test
      external MPI_Test_cancelled
      external MPI_Testall
      external MPI_Testany
      external MPI_Testsome
      external MPI_Wait
      external MPI_Waitall
      external MPI_Waitany
      external MPI_Waitsome

!     A.3.2 Partitioned Communication C Bindings

      external MPIABI_Parrived
      external MPIABI_Pready
      external MPIABI_Pready_list
      external MPIABI_Pready_range
      external MPIABI_Precv_init
      external MPIABI_Psend_init

!     A.3.3 Datatypes C Bindings

      external MPIABI_Aint_add
      integer(MPI_ADDRESS_KIND) MPIABI_Aint_add
      external MPIABI_Aint_diff
      integer(MPI_ADDRESS_KIND) MPIABI_Aint_diff
      external MPIABI_Get_address
      external MPIABI_Get_elements
!     external MPIABI_Get_elements_c
      external MPIABI_Pack
!     external MPIABI_Pack_c
      external MPIABI_Pack_external
!     external MPIABI_Pack_external_c
      external MPIABI_Pack_external_size
!     external MPIABI_Pack_external_size_c
      external MPIABI_Pack_size
!     external MPIABI_Pack_size_c
      external MPIABI_Type_commit
      external MPIABI_Type_contiguous
!     external MPIABI_Type_contiguous_c
      external MPIABI_Type_create_darray
!     external MPIABI_Type_create_darray_c
      external MPIABI_Type_create_hindexed
      external MPIABI_Type_create_hindexed_block
!     external MPIABI_Type_create_hindexed_block_c
!     external MPIABI_Type_create_hindexed_c
      external MPIABI_Type_create_hvector
!     external MPIABI_Type_create_hvector_c
      external MPIABI_Type_create_indexed_block
!     external MPIABI_Type_create_indexed_block_c
      external MPIABI_Type_create_resized
!     external MPIABI_Type_create_resized_c
      external MPIABI_Type_create_struct
!     external MPIABI_Type_create_struct_c
      external MPIABI_Type_create_subarray
!     external MPIABI_Type_create_subarray_c
      external MPIABI_Type_dup
      external MPIABI_Type_free
      external MPIABI_Type_get_contents
!     external MPIABI_Type_get_contents_c
      external MPIABI_Type_get_envelope
!     external MPIABI_Type_get_envelope_c
      external MPIABI_Type_get_extent
!     external MPIABI_Type_get_extent_c
      external MPIABI_Type_get_true_extent
!     external MPIABI_Type_get_true_extent_c
      external MPIABI_Type_indexed
!     external MPIABI_Type_indexed_c
      external MPIABI_Type_size
!     external MPIABI_Type_size_c
      external MPIABI_Type_vector
!     external MPIABI_Type_vector_c
      external MPIABI_Unpack
!     external MPIABI_Unpack_c
      external MPIABI_Unpack_external
!     external MPIABI_Unpack_external_c

!     A.3.4 Collective Communication C Bindings

      external MPIABI_Allgather
!     external MPIABI_Allgather_c
      external MPIABI_Allgather_init
!     external MPIABI_Allgather_init_c
      external MPIABI_Allgatherv
!     external MPIABI_Allgatherv_c
      external MPIABI_Allgatherv_init
!     external MPIABI_Allgatherv_init_c
      external MPIABI_Allreduce
!     external MPIABI_Allreduce_c
      external MPIABI_Allreduce_init
!     external MPIABI_Allreduce_init_c
      external MPIABI_Alltoall
!     external MPIABI_Alltoall_c
      external MPIABI_Alltoall_init
!     external MPIABI_Alltoall_init_c
      external MPIABI_Alltoallv
!     external MPIABI_Alltoallv_c
      external MPIABI_Alltoallv_init
!     external MPIABI_Alltoallv_init_c
      external MPIABI_Alltoallw
!     external MPIABI_Alltoallw_c
      external MPIABI_Alltoallw_init
!     external MPIABI_Alltoallw_init_c
      external MPIABI_Barrier
      external MPIABI_Barrier_init
      external MPIABI_Bcast
!     external MPIABI_Bcast_c
      external MPIABI_Bcast_init
!     external MPIABI_Bcast_init_c
      external MPIABI_Exscan
!     external MPIABI_Exscan_c
      external MPIABI_Exscan_init
!     external MPIABI_Exscan_init_c
      external MPIABI_Gather
!     external MPIABI_Gather_c
      external MPIABI_Gather_init
!     external MPIABI_Gather_init_c
      external MPIABI_Gatherv
!     external MPIABI_Gatherv_c
      external MPIABI_Gatherv_init
!     external MPIABI_Gatherv_init_c
      external MPIABI_Iallgather
!     external MPIABI_Iallgather_c
      external MPIABI_Iallgatherv
!     external MPIABI_Iallgatherv_c
      external MPIABI_Iallreduce
!     external MPIABI_Iallreduce_c
      external MPIABI_Ialltoall
!     external MPIABI_Ialltoall_c
      external MPIABI_Ialltoallv
!     external MPIABI_Ialltoallv_c
      external MPIABI_Ialltoallw
!     external MPIABI_Ialltoallw_c
      external MPIABI_Ibarrier
      external MPIABI_Ibcast
!     external MPIABI_Ibcast_c
      external MPIABI_Iexscan
!     external MPIABI_Iexscan_c
      external MPIABI_Igather
!     external MPIABI_Igather_c
      external MPIABI_Igatherv
!     external MPIABI_Igatherv_c
      external MPIABI_Ireduce
!     external MPIABI_Ireduce_c
      external MPIABI_Ireduce_scatter
      external MPIABI_Ireduce_scatter_block
!     external MPIABI_Ireduce_scatter_block_c
!     external MPIABI_Ireduce_scatter_c
      external MPIABI_Iscan
!     external MPIABI_Iscan_c
      external MPIABI_Iscatter
!     external MPIABI_Iscatter_c
      external MPIABI_Iscatterv
!     external MPIABI_Iscatterv_c
      external MPIABI_Op_commutative
      external MPIABI_Op_create
!     external MPIABI_Op_create_c
      external MPIABI_Op_free
      external MPIABI_Reduce
!     external MPIABI_Reduce_c
      external MPIABI_Reduce_init
!     external MPIABI_Reduce_init_c
      external MPIABI_Reduce_local
!     external MPIABI_Reduce_local_c
      external MPIABI_Reduce_scatter
      external MPIABI_Reduce_scatter_block
!     external MPIABI_Reduce_scatter_block_c
      external MPIABI_Reduce_scatter_block_init
!     external MPIABI_Reduce_scatter_block_init_c
!     external MPIABI_Reduce_scatter_c
      external MPIABI_Reduce_scatter_init
!     external MPIABI_Reduce_scatter_init_c
      external MPIABI_Scan
!     external MPIABI_Scan_c
      external MPIABI_Scan_init
!     external MPIABI_Scan_init_c
      external MPIABI_Scatter
!     external MPIABI_Scatter_c
      external MPIABI_Scatter_init
!     external MPIABI_Scatter_init_c
      external MPIABI_Scatterv
!     external MPIABI_Scatterv_c
      external MPIABI_Scatterv_init
!     external MPIABI_Scatterv_init_c
      external MPIABI_Type_get_value_index

!     A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

      external MPIABI_Comm_compare
      external MPIABI_Comm_create
      external MPIABI_Comm_create_from_group
      external MPIABI_Comm_create_group
      external MPIABI_Comm_create_keyval
      external MPIABI_Comm_delete_attr
      external MPIABI_Comm_dup
      external MPIABI_Comm_dup_with_info
      external MPIABI_Comm_free
      external MPIABI_Comm_get_name
      external MPIABI_Comm_free_keyval
      external MPIABI_Comm_get_attr
      external MPIABI_Comm_get_info
      external MPIABI_Comm_group
      external MPIABI_Comm_idup
      external MPIABI_Comm_idup_with_info
      external MPIABI_Comm_rank
      external MPIABI_Comm_remote_group
      external MPIABI_Comm_remote_size
      external MPIABI_Comm_set_attr
      external MPIABI_Comm_set_info
      external MPIABI_Comm_set_name
      external MPIABI_Comm_size
      external MPIABI_Comm_split
      external MPIABI_Group_free
      external MPIABI_Comm_split_type
      external MPIABI_Comm_test_inter
      external MPIABI_Group_compare
      external MPIABI_Group_difference
      external MPIABI_Group_excl
      external MPIABI_Group_from_session_pset
      external MPIABI_Group_incl
      external MPIABI_Group_intersection
      external MPIABI_Group_range_excl
      external MPIABI_Group_range_incl
      external MPIABI_Group_rank
      external MPIABI_Group_size
      external MPIABI_Group_translate_ranks
      external MPIABI_Group_union
      external MPIABI_Intercomm_create
      external MPIABI_Intercomm_create_from_groups
      external MPIABI_Intercomm_merge
      external MPIABI_Type_create_keyval
      external MPIABI_Type_delete_attr
      external MPIABI_Type_free_keyval
      external MPIABI_Type_get_attr
      external MPIABI_Type_get_name
      external MPIABI_Type_set_attr
      external MPIABI_Type_set_name
      external MPIABI_Win_create_keyval
      external MPIABI_Win_delete_attr
      external MPIABI_Win_free_keyval
      external MPIABI_Win_get_attr
      external MPIABI_Win_get_name
      external MPIABI_Win_set_attr
      external MPIABI_Win_set_name

!     A.3.6 Virtual Topologies for MPI Processes C Bindings

      external MPIABI_Cart_coords
      external MPIABI_Cart_create
      external MPIABI_Cart_get
      external MPIABI_Cart_map
      external MPIABI_Cart_rank
      external MPIABI_Cart_shift
      external MPIABI_Cart_sub
      external MPIABI_Cartdim_get
      external MPIABI_Dims_create
      external MPIABI_Dist_graph_create
      external MPIABI_Dist_graph_create_adjacent
      external MPIABI_Dist_graph_neighbors
      external MPIABI_Dist_graph_neighbors_count
      external MPIABI_Graph_create
      external MPIABI_Graph_get
      external MPIABI_Graph_map
      external MPIABI_Graph_neighbors
      external MPIABI_Graph_neighbors_count
      external MPIABI_Graphdims_get
      external MPIABI_Ineighbor_allgather
!     external MPIABI_Ineighbor_allgather_c
      external MPIABI_Ineighbor_allgatherv
!     external MPIABI_Ineighbor_allgatherv_c
      external MPIABI_Ineighbor_alltoall
!     external MPIABI_Ineighbor_alltoall_c
      external MPIABI_Ineighbor_alltoallv
!     external MPIABI_Ineighbor_alltoallv_c
      external MPIABI_Ineighbor_alltoallw
!     external MPIABI_Ineighbor_alltoallw_c
      external MPIABI_Neighbor_allgather
!     external MPIABI_Neighbor_allgather_c
      external MPIABI_Neighbor_allgather_init
!     external MPIABI_Neighbor_allgather_init_c
      external MPIABI_Neighbor_allgatherv
!     external MPIABI_Neighbor_allgatherv_c
      external MPIABI_Neighbor_allgatherv_init
!     external MPIABI_Neighbor_allgatherv_init_c
      external MPIABI_Neighbor_alltoall
!     external MPIABI_Neighbor_alltoall_c
      external MPIABI_Neighbor_alltoall_init
!     external MPIABI_Neighbor_alltoall_init_c
      external MPIABI_Neighbor_alltoallv
!     external MPIABI_Neighbor_alltoallv_c
      external MPIABI_Neighbor_alltoallv_init
!     external MPIABI_Neighbor_alltoallv_init_c
      external MPIABI_Neighbor_alltoallw
!     external MPIABI_Neighbor_alltoallw_c
      external MPIABI_Neighbor_alltoallw_init
!     external MPIABI_Neighbor_alltoallw_init_c
      external MPIABI_Topo_test

!     A.3.7 MPI Environmental Management C Bindings

      external MPIABI_Add_error_class
      external MPIABI_Add_error_code
      external MPIABI_Add_error_string
      external MPIABI_Alloc_mem
      external MPIABI_Comm_call_errhandler
      external MPIABI_Comm_create_errhandler
      external MPIABI_Comm_get_errhandler
      external MPIABI_Comm_set_errhandler
      external MPIABI_Errhandler_free
      external MPIABI_Error_class
      external MPIABI_Error_string
      external MPIABI_File_call_errhandler
      external MPIABI_File_create_errhandler
      external MPIABI_File_get_errhandler
      external MPIABI_File_set_errhandler
      external MPIABI_Free_mem
      external MPIABI_Get_hw_resource_info
      external MPIABI_Get_library_version
      external MPIABI_Get_processor_name
      external MPIABI_Get_version
      external MPIABI_Remove_error_class
      external MPIABI_Remove_error_code
      external MPIABI_Remove_error_string
      external MPIABI_Session_call_errhandler
      external MPIABI_Session_create_errhandler
      external MPIABI_Session_get_errhandler
      external MPIABI_Session_set_errhandler
      external MPIABI_Win_call_errhandler
      external MPIABI_Win_create_errhandler
      external MPIABI_Win_get_errhandler
      external MPIABI_Win_set_errhandler
      external MPIABI_Wtick
      double precision MPIABI_Wtick
      external MPIABI_Wtime
      double precision MPIABI_Wtime

!     A.3.8 The Info Object C Bindings

      external MPIABI_Info_create
      external MPIABI_Info_create_env
      external MPIABI_Info_delete
      external MPIABI_Info_dup
      external MPIABI_Info_free
      external MPIABI_Info_get_nkeys
      external MPIABI_Info_get_nthkey
      external MPIABI_Info_get_string
      external MPIABI_Info_set

!     A.3.9 Process Creation and Management C Bindings

      external MPIABI_Abort
      external MPIABI_Close_port
      external MPIABI_Comm_accept
      external MPIABI_Comm_connect
      external MPIABI_Comm_disconnect
      external MPIABI_Comm_get_parent
      external MPIABI_Comm_join
      external MPIABI_Comm_spawn
      external MPIABI_Comm_spawn_multiple
      external MPIABI_Finalize
      external MPIABI_Finalized
      external MPIABI_Init
      external MPIABI_Init_thread
      external MPIABI_Initialized
      external MPIABI_Is_thread_main
      external MPIABI_Lookup_name
      external MPIABI_Open_port
      external MPIABI_Publish_name
      external MPIABI_Query_thread
      external MPIABI_Session_finalize
      external MPIABI_Session_get_info
      external MPIABI_Session_get_nth_pset
      external MPIABI_Session_get_num_psets
      external MPIABI_Session_get_pset_info
      external MPIABI_Session_init
      external MPIABI_Unpublish_name

!     A.3.10 One-Sided Communications C Bindings

      external MPIABI_Accumulate
!     external MPIABI_Accumulate_c
      external MPIABI_Compare_and_swap
      external MPIABI_Fetch_and_op
      external MPIABI_Get
      external MPIABI_Get_accumulate
!     external MPIABI_Get_accumulate_c
!     external MPIABI_Get_c
      external MPIABI_Put
!     external MPIABI_Put_c
      external MPIABI_Raccumulate
!     external MPIABI_Raccumulate_c
      external MPIABI_Rget
      external MPIABI_Rget_accumulate
!     external MPIABI_Rget_accumulate_c
!     external MPIABI_Rget_c
      external MPIABI_Rput
!     external MPIABI_Rput_c
      external MPIABI_Win_allocate
!     external MPIABI_Win_allocate_c
      external MPIABI_Win_allocate_shared
!     external MPIABI_Win_allocate_shared_c
      external MPIABI_Win_attach
      external MPIABI_Win_complete
      external MPIABI_Win_create
!     external MPIABI_Win_create_c
      external MPIABI_Win_create_dynamic
      external MPIABI_Win_detach
      external MPIABI_Win_fence
      external MPIABI_Win_flush
      external MPIABI_Win_flush_all
      external MPIABI_Win_flush_local
      external MPIABI_Win_flush_local_all
      external MPIABI_Win_free
      external MPIABI_Win_get_group
      external MPIABI_Win_get_info
      external MPIABI_Win_lock
      external MPIABI_Win_lock_all
      external MPIABI_Win_post
      external MPIABI_Win_set_info
      external MPIABI_Win_shared_query
!     external MPIABI_Win_shared_query_c
      external MPIABI_Win_start
      external MPIABI_Win_sync
      external MPIABI_Win_test
      external MPIABI_Win_unlock
      external MPIABI_Win_unlock_all
      external MPIABI_Win_wait

!     A.3.11      External Interfaces C Bindings

      external MPIABI_Grequest_complete
      external MPIABI_Grequest_start
      external MPIABI_Status_set_cancelled
      external MPIABI_Status_set_elements
!     external MPIABI_Status_set_elements_c
      external MPIABI_Status_set_error
      external MPIABI_Status_set_source
      external MPIABI_Status_set_tag

!     A.3.12 I/O C Bindings

      external MPIABI_File_close
      external MPIABI_File_delete
      external MPIABI_File_get_amode
      external MPIABI_File_get_atomicity
      external MPIABI_File_get_byte_offset
      external MPIABI_File_get_group
      external MPIABI_File_get_info
      external MPIABI_File_get_position
      external MPIABI_File_get_position_shared
      external MPIABI_File_get_size
      external MPIABI_File_get_type_extent
!     external MPIABI_File_get_type_extent_c
      external MPIABI_File_get_view
      external MPIABI_File_iread
      external MPIABI_File_iread_all
!     external MPIABI_File_iread_all_c
      external MPIABI_File_iread_at
      external MPIABI_File_iread_at_all
!     external MPIABI_File_iread_at_all_c
!     external MPIABI_File_iread_at_c
!     external MPIABI_File_iread_c
      external MPIABI_File_iread_shared
!     external MPIABI_File_iread_shared_c
      external MPIABI_File_iwrite
      external MPIABI_File_iwrite_all
!     external MPIABI_File_iwrite_all_c
      external MPIABI_File_iwrite_at
      external MPIABI_File_iwrite_at_all
!     external MPIABI_File_iwrite_at_all_c
!     external MPIABI_File_iwrite_at_c
!     external MPIABI_File_iwrite_c
      external MPIABI_File_iwrite_shared
!     external MPIABI_File_iwrite_shared_c
      external MPIABI_File_open
      external MPIABI_File_preallocate
      external MPIABI_File_read
      external MPIABI_File_read_all
      external MPIABI_File_read_all_begin
!     external MPIABI_File_read_all_begin_c
!     external MPIABI_File_read_all_c
      external MPIABI_File_read_all_end
      external MPIABI_File_read_at
      external MPIABI_File_read_at_all
      external MPIABI_File_read_at_all_begin
!     external MPIABI_File_read_at_all_begin_c
!     external MPIABI_File_read_at_all_c
      external MPIABI_File_read_at_all_end
!     external MPIABI_File_read_at_c
!     external MPIABI_File_read_c
      external MPIABI_File_read_ordered
      external MPIABI_File_read_ordered_begin
!     external MPIABI_File_read_ordered_begin_c
!     external MPIABI_File_read_ordered_c
      external MPIABI_File_read_ordered_end
      external MPIABI_File_read_shared
!     external MPIABI_File_read_shared_c
      external MPIABI_File_seek
      external MPIABI_File_seek_shared
      external MPIABI_File_set_atomicity
      external MPIABI_File_set_info
      external MPIABI_File_set_size
      external MPIABI_File_set_view
      external MPIABI_File_sync
      external MPIABI_File_write
      external MPIABI_File_write_all
      external MPIABI_File_write_all_begin
!     external MPIABI_File_write_all_begin_c
!     external MPIABI_File_write_all_c
      external MPIABI_File_write_all_end
      external MPIABI_File_write_at
      external MPIABI_File_write_at_all
      external MPIABI_File_write_at_all_begin
!     external MPIABI_File_write_at_all_begin_c
!     external MPIABI_File_write_at_all_c
      external MPIABI_File_write_at_all_end
!     external MPIABI_File_write_at_c
!     external MPIABI_File_write_c
      external MPIABI_File_write_ordered
      external MPIABI_File_write_ordered_begin
!     external MPIABI_File_write_ordered_begin_c
!     external MPIABI_File_write_ordered_c
      external MPIABI_File_write_ordered_end
      external MPIABI_File_write_shared
!     external MPIABI_File_write_shared_c
      external MPIABI_Register_datarep
!     external MPIABI_Register_datarep_c

!     A.3.13 Language Bindings C Bindings

!     A.3.14 Tools / Profiling Interface C Bindings

      external MPIABI_Pcontrol

!     A.3.15 Tools / MPI Tool Information Interface C Bindings

      external MPIABI_T_category_changed
      external MPIABI_T_category_get_categories
      external MPIABI_T_category_get_cvars
      external MPIABI_T_category_get_events
      external MPIABI_T_category_get_index
      external MPIABI_T_category_get_info
      external MPIABI_T_category_get_num
      external MPIABI_T_category_get_num_events
      external MPIABI_T_category_get_pvars
      external MPIABI_T_cvar_get_index
      external MPIABI_T_cvar_get_info
      external MPIABI_T_cvar_get_num
      external MPIABI_T_cvar_handle_alloc
      external MPIABI_T_cvar_handle_free
      external MPIABI_T_cvar_read
      external MPIABI_T_cvar_write
      external MPIABI_T_enum_get_info
      external MPIABI_T_enum_get_item
      external MPIABI_T_event_callback_get_info
      external MPIABI_T_event_callback_set_info
      external MPIABI_T_event_copy
      external MPIABI_T_event_get_index
      external MPIABI_T_event_get_info
      external MPIABI_T_event_get_num
      external MPIABI_T_event_get_source
      external MPIABI_T_event_get_timestamp
      external MPIABI_T_event_handle_alloc
      external MPIABI_T_event_handle_free
      external MPIABI_T_event_handle_get_info
      external MPIABI_T_event_handle_set_info
      external MPIABI_T_event_read
      external MPIABI_T_event_register_callback
      external MPIABI_T_event_set_dropped_handler
      external MPIABI_T_finalize
      external MPIABI_T_init_thread
      external MPIABI_T_pvar_get_index
      external MPIABI_T_pvar_get_info
      external MPIABI_T_pvar_get_num
      external MPIABI_T_pvar_handle_alloc
      external MPIABI_T_pvar_handle_free
      external MPIABI_T_pvar_read
      external MPIABI_T_pvar_readreset
      external MPIABI_T_pvar_reset
      external MPIABI_T_pvar_session_create
      external MPIABI_T_pvar_session_free
      external MPIABI_T_pvar_start
      external MPIABI_T_pvar_stop
      external MPIABI_T_pvar_write
      external MPIABI_T_source_get_info
      external MPIABI_T_source_get_num
      external MPIABI_T_source_get_timestamp

!     A.3.16 Deprecated C Bindings

      external MPIABI_Attr_delete
      external MPIABI_Attr_get
      external MPIABI_Attr_put
      external MPIABI_Get_elements_x
      external MPIABI_Info_get
      external MPIABI_Info_get_valuelen
      external MPIABI_Keyval_create
      external MPIABI_Keyval_free
      external MPIABI_Status_set_elements_x
      external MPIABI_Type_get_extent_x
      external MPIABI_Type_get_true_extent_x
      external MPIABI_Type_size_x

!     Removed C Bindings

      external MPIABI_Address
      external MPIABI_Type_hindexed
      external MPIABI_Type_hvector
      external MPIABI_Type_struct
      external MPIABI_Type_extent
      external MPIABI_Type_lb
      external MPIABI_Type_ub
