!     A.3 C Bindings

!     A.3.1 Point-to-Point Communication C Bindings

      external MPI_Bsend
!     external MPI_Bsend_c
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

      external MPI_Parrived
      external MPI_Pready
      external MPI_Pready_list
      external MPI_Pready_range
      external MPI_Precv_init
      external MPI_Psend_init

!     A.3.3 Datatypes C Bindings

      external MPI_Aint_add
      integer(MPI_ADDRESS_KIND) MPI_Aint_add
      external MPI_Aint_diff
      integer(MPI_ADDRESS_KIND) MPI_Aint_diff
      external MPI_Get_address
      external MPI_Get_elements
!     external MPI_Get_elements_c
      external MPI_Pack
!     external MPI_Pack_c
      external MPI_Pack_external
!     external MPI_Pack_external_c
      external MPI_Pack_external_size
!     external MPI_Pack_external_size_c
      external MPI_Pack_size
!     external MPI_Pack_size_c
      external MPI_Type_commit
      external MPI_Type_contiguous
!     external MPI_Type_contiguous_c
      external MPI_Type_create_darray
!     external MPI_Type_create_darray_c
      external MPI_Type_create_hindexed
      external MPI_Type_create_hindexed_block
!     external MPI_Type_create_hindexed_block_c
!     external MPI_Type_create_hindexed_c
      external MPI_Type_create_hvector
!     external MPI_Type_create_hvector_c
      external MPI_Type_create_indexed_block
!     external MPI_Type_create_indexed_block_c
      external MPI_Type_create_resized
!     external MPI_Type_create_resized_c
      external MPI_Type_create_struct
!     external MPI_Type_create_struct_c
      external MPI_Type_create_subarray
!     external MPI_Type_create_subarray_c
      external MPI_Type_dup
      external MPI_Type_free
      external MPI_Type_get_contents
!     external MPI_Type_get_contents_c
      external MPI_Type_get_envelope
!     external MPI_Type_get_envelope_c
      external MPI_Type_get_extent
!     external MPI_Type_get_extent_c
      external MPI_Type_get_true_extent
!     external MPI_Type_get_true_extent_c
      external MPI_Type_indexed
!     external MPI_Type_indexed_c
      external MPI_Type_size
!     external MPI_Type_size_c
      external MPI_Type_vector
!     external MPI_Type_vector_c
      external MPI_Unpack
!     external MPI_Unpack_c
      external MPI_Unpack_external
!     external MPI_Unpack_external_c

!     A.3.4 Collective Communication C Bindings

      external MPI_Allgather
!     external MPI_Allgather_c
      external MPI_Allgather_init
!     external MPI_Allgather_init_c
      external MPI_Allgatherv
!     external MPI_Allgatherv_c
      external MPI_Allgatherv_init
!     external MPI_Allgatherv_init_c
      external MPI_Allreduce
!     external MPI_Allreduce_c
      external MPI_Allreduce_init
!     external MPI_Allreduce_init_c
      external MPI_Alltoall
!     external MPI_Alltoall_c
      external MPI_Alltoall_init
!     external MPI_Alltoall_init_c
      external MPI_Alltoallv
!     external MPI_Alltoallv_c
      external MPI_Alltoallv_init
!     external MPI_Alltoallv_init_c
      external MPI_Alltoallw
!     external MPI_Alltoallw_c
      external MPI_Alltoallw_init
!     external MPI_Alltoallw_init_c
      external MPI_Barrier
      external MPI_Barrier_init
      external MPI_Bcast
!     external MPI_Bcast_c
      external MPI_Bcast_init
!     external MPI_Bcast_init_c
      external MPI_Exscan
!     external MPI_Exscan_c
      external MPI_Exscan_init
!     external MPI_Exscan_init_c
      external MPI_Gather
!     external MPI_Gather_c
      external MPI_Gather_init
!     external MPI_Gather_init_c
      external MPI_Gatherv
!     external MPI_Gatherv_c
      external MPI_Gatherv_init
!     external MPI_Gatherv_init_c
      external MPI_Iallgather
!     external MPI_Iallgather_c
      external MPI_Iallgatherv
!     external MPI_Iallgatherv_c
      external MPI_Iallreduce
!     external MPI_Iallreduce_c
      external MPI_Ialltoall
!     external MPI_Ialltoall_c
      external MPI_Ialltoallv
!     external MPI_Ialltoallv_c
      external MPI_Ialltoallw
!     external MPI_Ialltoallw_c
      external MPI_Ibarrier
      external MPI_Ibcast
!     external MPI_Ibcast_c
      external MPI_Iexscan
!     external MPI_Iexscan_c
      external MPI_Igather
!     external MPI_Igather_c
      external MPI_Igatherv
!     external MPI_Igatherv_c
      external MPI_Ireduce
!     external MPI_Ireduce_c
      external MPI_Ireduce_scatter
      external MPI_Ireduce_scatter_block
!     external MPI_Ireduce_scatter_block_c
!     external MPI_Ireduce_scatter_c
      external MPI_Iscan
!     external MPI_Iscan_c
      external MPI_Iscatter
!     external MPI_Iscatter_c
      external MPI_Iscatterv
!     external MPI_Iscatterv_c
      external MPI_Op_commutative
      external MPI_Op_create
!     external MPI_Op_create_c
      external MPI_Op_free
      external MPI_Reduce
!     external MPI_Reduce_c
      external MPI_Reduce_init
!     external MPI_Reduce_init_c
      external MPI_Reduce_local
!     external MPI_Reduce_local_c
      external MPI_Reduce_scatter
      external MPI_Reduce_scatter_block
!     external MPI_Reduce_scatter_block_c
      external MPI_Reduce_scatter_block_init
!     external MPI_Reduce_scatter_block_init_c
!     external MPI_Reduce_scatter_c
      external MPI_Reduce_scatter_init
!     external MPI_Reduce_scatter_init_c
      external MPI_Scan
!     external MPI_Scan_c
      external MPI_Scan_init
!     external MPI_Scan_init_c
      external MPI_Scatter
!     external MPI_Scatter_c
      external MPI_Scatter_init
!     external MPI_Scatter_init_c
      external MPI_Scatterv
!     external MPI_Scatterv_c
      external MPI_Scatterv_init
!     external MPI_Scatterv_init_c
      external MPI_Type_get_value_index

!     A.3.5 Groups, Contexts, Communicators, and Caching C Bindings

      external MPI_Comm_compare
      external MPI_Comm_create
      external MPI_Comm_create_from_group
      external MPI_Comm_create_group
      external MPI_Comm_create_keyval
      external MPI_Comm_delete_attr
      external MPI_Comm_dup
      external MPI_Comm_dup_with_info
      external MPI_Comm_free
      external MPI_Comm_get_name
      external MPI_Comm_free_keyval
      external MPI_Comm_get_attr
      external MPI_Comm_get_info
      external MPI_Comm_group
      external MPI_Comm_idup
      external MPI_Comm_idup_with_info
      external MPI_Comm_rank
      external MPI_Comm_remote_group
      external MPI_Comm_remote_size
      external MPI_Comm_set_attr
      external MPI_Comm_set_info
      external MPI_Comm_set_name
      external MPI_Comm_size
      external MPI_Comm_split
      external MPI_Group_free
      external MPI_Comm_split_type
      external MPI_Comm_test_inter
      external MPI_Group_compare
      external MPI_Group_difference
      external MPI_Group_excl
      external MPI_Group_from_session_pset
      external MPI_Group_incl
      external MPI_Group_intersection
      external MPI_Group_range_excl
      external MPI_Group_range_incl
      external MPI_Group_rank
      external MPI_Group_size
      external MPI_Group_translate_ranks
      external MPI_Group_union
      external MPI_Intercomm_create
      external MPI_Intercomm_create_from_groups
      external MPI_Intercomm_merge
      external MPI_Type_create_keyval
      external MPI_Type_delete_attr
      external MPI_Type_free_keyval
      external MPI_Type_get_attr
      external MPI_Type_get_name
      external MPI_Type_set_attr
      external MPI_Type_set_name
      external MPI_Win_create_keyval
      external MPI_Win_delete_attr
      external MPI_Win_free_keyval
      external MPI_Win_get_attr
      external MPI_Win_get_name
      external MPI_Win_set_attr
      external MPI_Win_set_name

!     A.3.6 Virtual Topologies for MPI Processes C Bindings

      external MPI_Cart_coords
      external MPI_Cart_create
      external MPI_Cart_get
      external MPI_Cart_map
      external MPI_Cart_rank
      external MPI_Cart_shift
      external MPI_Cart_sub
      external MPI_Cartdim_get
      external MPI_Dims_create
      external MPI_Dist_graph_create
      external MPI_Dist_graph_create_adjacent
      external MPI_Dist_graph_neighbors
      external MPI_Dist_graph_neighbors_count
      external MPI_Graph_create
      external MPI_Graph_get
      external MPI_Graph_map
      external MPI_Graph_neighbors
      external MPI_Graph_neighbors_count
      external MPI_Graphdims_get
      external MPI_Ineighbor_allgather
!     external MPI_Ineighbor_allgather_c
      external MPI_Ineighbor_allgatherv
!     external MPI_Ineighbor_allgatherv_c
      external MPI_Ineighbor_alltoall
!     external MPI_Ineighbor_alltoall_c
      external MPI_Ineighbor_alltoallv
!     external MPI_Ineighbor_alltoallv_c
      external MPI_Ineighbor_alltoallw
!     external MPI_Ineighbor_alltoallw_c
      external MPI_Neighbor_allgather
!     external MPI_Neighbor_allgather_c
      external MPI_Neighbor_allgather_init
!     external MPI_Neighbor_allgather_init_c
      external MPI_Neighbor_allgatherv
!     external MPI_Neighbor_allgatherv_c
      external MPI_Neighbor_allgatherv_init
!     external MPI_Neighbor_allgatherv_init_c
      external MPI_Neighbor_alltoall
!     external MPI_Neighbor_alltoall_c
      external MPI_Neighbor_alltoall_init
!     external MPI_Neighbor_alltoall_init_c
      external MPI_Neighbor_alltoallv
!     external MPI_Neighbor_alltoallv_c
      external MPI_Neighbor_alltoallv_init
!     external MPI_Neighbor_alltoallv_init_c
      external MPI_Neighbor_alltoallw
!     external MPI_Neighbor_alltoallw_c
      external MPI_Neighbor_alltoallw_init
!     external MPI_Neighbor_alltoallw_init_c
      external MPI_Topo_test

!     A.3.7 MPI Environmental Management C Bindings

      external MPI_Add_error_class
      external MPI_Add_error_code
      external MPI_Add_error_string
      external MPI_Alloc_mem
      external MPI_Comm_call_errhandler
      external MPI_Comm_create_errhandler
      external MPI_Comm_get_errhandler
      external MPI_Comm_set_errhandler
      external MPI_Errhandler_free
      external MPI_Error_class
      external MPI_Error_string
      external MPI_File_call_errhandler
      external MPI_File_create_errhandler
      external MPI_File_get_errhandler
      external MPI_File_set_errhandler
      external MPI_Free_mem
      external MPI_Get_hw_resource_info
      external MPI_Get_library_version
      external MPI_Get_processor_name
      external MPI_Get_version
      external MPI_Remove_error_class
      external MPI_Remove_error_code
      external MPI_Remove_error_string
      external MPI_Session_call_errhandler
      external MPI_Session_create_errhandler
      external MPI_Session_get_errhandler
      external MPI_Session_set_errhandler
      external MPI_Win_call_errhandler
      external MPI_Win_create_errhandler
      external MPI_Win_get_errhandler
      external MPI_Win_set_errhandler
      external MPI_Wtick
      double precision MPI_Wtick
      external MPI_Wtime
      double precision MPI_Wtime

!     A.3.8 The Info Object C Bindings

      external MPI_Info_create
      external MPI_Info_create_env
      external MPI_Info_delete
      external MPI_Info_dup
      external MPI_Info_free
      external MPI_Info_get_nkeys
      external MPI_Info_get_nthkey
      external MPI_Info_get_string
      external MPI_Info_set

!     A.3.9 Process Creation and Management C Bindings

      external MPI_Abort
      external MPI_Close_port
      external MPI_Comm_accept
      external MPI_Comm_connect
      external MPI_Comm_disconnect
      external MPI_Comm_get_parent
      external MPI_Comm_join
      external MPI_Comm_spawn
      external MPI_Comm_spawn_multiple

      external MPI_Finalize
      external MPI_Finalized
      external MPI_Init
      external MPI_Init_thread
      external MPI_Initialized
      external MPI_Is_thread_main
      external MPI_Lookup_name
      external MPI_Open_port
      external MPI_Publish_name
      external MPI_Query_thread
      external MPI_Session_finalize
      external MPI_Session_get_info
      external MPI_Session_get_nth_pset
      external MPI_Session_get_num_psets
      external MPI_Session_get_pset_info
      external MPI_Session_init
      external MPI_Unpublish_name

!     A.3.10 One-Sided Communications C Bindings

      external MPI_Accumulate
!     external MPI_Accumulate_c
      external MPI_Compare_and_swap
      external MPI_Fetch_and_op
      external MPI_Get
      external MPI_Get_accumulate
!     external MPI_Get_accumulate_c
!     external MPI_Get_c
      external MPI_Put
!     external MPI_Put_c
      external MPI_Raccumulate
!     external MPI_Raccumulate_c
      external MPI_Rget
      external MPI_Rget_accumulate
!     external MPI_Rget_accumulate_c
!     external MPI_Rget_c
      external MPI_Rput
!     external MPI_Rput_c
      external MPI_Win_allocate
!     external MPI_Win_allocate_c
      external MPI_Win_allocate_shared
!     external MPI_Win_allocate_shared_c
      external MPI_Win_attach
      external MPI_Win_complete
      external MPI_Win_create
!     external MPI_Win_create_c
      external MPI_Win_create_dynamic
      external MPI_Win_detach
      external MPI_Win_fence
      external MPI_Win_flush
      external MPI_Win_flush_all
      external MPI_Win_flush_local
      external MPI_Win_flush_local_all
      external MPI_Win_free
      external MPI_Win_get_group
      external MPI_Win_get_info
      external MPI_Win_lock
      external MPI_Win_lock_all
      external MPI_Win_post
      external MPI_Win_set_info
      external MPI_Win_shared_query
!     external MPI_Win_shared_query_c
      external MPI_Win_start
      external MPI_Win_sync
      external MPI_Win_test
      external MPI_Win_unlock
      external MPI_Win_unlock_all
      external MPI_Win_wait

!     A.3.11      External Interfaces C Bindings

      external MPI_Grequest_complete
      external MPI_Grequest_start
      external MPI_Status_set_cancelled
      external MPI_Status_set_elements
!     external MPI_Status_set_elements_c
      external MPI_Status_set_error
      external MPI_Status_set_source
      external MPI_Status_set_tag

!     A.3.12 I/O C Bindings

      external MPI_File_close
      external MPI_File_delete
      external MPI_File_get_amode
      external MPI_File_get_atomicity
      external MPI_File_get_byte_offset
      external MPI_File_get_group
      external MPI_File_get_info
      external MPI_File_get_position
      external MPI_File_get_position_shared
      external MPI_File_get_size
      external MPI_File_get_type_extent
!     external MPI_File_get_type_extent_c
      external MPI_File_get_view
      external MPI_File_iread
      external MPI_File_iread_all
!     external MPI_File_iread_all_c
      external MPI_File_iread_at
      external MPI_File_iread_at_all
!     external MPI_File_iread_at_all_c
!     external MPI_File_iread_at_c
!     external MPI_File_iread_c
      external MPI_File_iread_shared
!     external MPI_File_iread_shared_c
      external MPI_File_iwrite
      external MPI_File_iwrite_all
!     external MPI_File_iwrite_all_c
      external MPI_File_iwrite_at
      external MPI_File_iwrite_at_all
!     external MPI_File_iwrite_at_all_c
!     external MPI_File_iwrite_at_c
!     external MPI_File_iwrite_c
      external MPI_File_iwrite_shared
!     external MPI_File_iwrite_shared_c
      external MPI_File_open
      external MPI_File_preallocate
      external MPI_File_read
      external MPI_File_read_all
      external MPI_File_read_all_begin
!     external MPI_File_read_all_begin_c
!     external MPI_File_read_all_c
      external MPI_File_read_all_end
      external MPI_File_read_at
      external MPI_File_read_at_all
      external MPI_File_read_at_all_begin
!     external MPI_File_read_at_all_begin_c
!     external MPI_File_read_at_all_c
      external MPI_File_read_at_all_end
!     external MPI_File_read_at_c
!     external MPI_File_read_c
      external MPI_File_read_ordered
      external MPI_File_read_ordered_begin
!     external MPI_File_read_ordered_begin_c
!     external MPI_File_read_ordered_c
      external MPI_File_read_ordered_end
      external MPI_File_read_shared
!     external MPI_File_read_shared_c
      external MPI_File_seek
      external MPI_File_seek_shared
      external MPI_File_set_atomicity
      external MPI_File_set_info
      external MPI_File_set_size
      external MPI_File_set_view
      external MPI_File_sync
      external MPI_File_write
      external MPI_File_write_all
      external MPI_File_write_all_begin
!     external MPI_File_write_all_begin_c
!     external MPI_File_write_all_c
      external MPI_File_write_all_end
      external MPI_File_write_at
      external MPI_File_write_at_all
      external MPI_File_write_at_all_begin
!     external MPI_File_write_at_all_begin_c
!     external MPI_File_write_at_all_c
      external MPI_File_write_at_all_end
!     external MPI_File_write_at_c
!     external MPI_File_write_c
      external MPI_File_write_ordered
      external MPI_File_write_ordered_begin
!     external MPI_File_write_ordered_begin_c
!     external MPI_File_write_ordered_c
      external MPI_File_write_ordered_end
      external MPI_File_write_shared
!     external MPI_File_write_shared_c
      external MPI_Register_datarep
!     external MPI_Register_datarep_c

!     A.3.13 Language Bindings C Bindings

!     A.3.14 Tools / Profiling Interface C Bindings

      external MPI_Pcontrol

!     A.3.15 Tools / MPI Tool Information Interface C Bindings

      external MPI_T_category_changed
      external MPI_T_category_get_categories
      external MPI_T_category_get_cvars
      external MPI_T_category_get_events
      external MPI_T_category_get_index
      external MPI_T_category_get_info
      external MPI_T_category_get_num
      external MPI_T_category_get_num_events
      external MPI_T_category_get_pvars
      external MPI_T_cvar_get_index
      external MPI_T_cvar_get_info
      external MPI_T_cvar_get_num
      external MPI_T_cvar_handle_alloc
      external MPI_T_cvar_handle_free
      external MPI_T_cvar_read
      external MPI_T_cvar_write
      external MPI_T_enum_get_info
      external MPI_T_enum_get_item
      external MPI_T_event_callback_get_info
      external MPI_T_event_callback_set_info
      external MPI_T_event_copy
      external MPI_T_event_get_index
      external MPI_T_event_get_info
      external MPI_T_event_get_num
      external MPI_T_event_get_source
      external MPI_T_event_get_timestamp
      external MPI_T_event_handle_alloc
      external MPI_T_event_handle_free
      external MPI_T_event_handle_get_info
      external MPI_T_event_handle_set_info
      external MPI_T_event_read
      external MPI_T_event_register_callback
      external MPI_T_event_set_dropped_handler
      external MPI_T_finalize
      external MPI_T_init_thread
      external MPI_T_pvar_get_index
      external MPI_T_pvar_get_info
      external MPI_T_pvar_get_num
      external MPI_T_pvar_handle_alloc
      external MPI_T_pvar_handle_free
      external MPI_T_pvar_read
      external MPI_T_pvar_readreset
      external MPI_T_pvar_reset
      external MPI_T_pvar_session_create
      external MPI_T_pvar_session_free
      external MPI_T_pvar_start
      external MPI_T_pvar_stop
      external MPI_T_pvar_write
      external MPI_T_source_get_info
      external MPI_T_source_get_num
      external MPI_T_source_get_timestamp

!     A.3.16 Deprecated C Bindings

      external MPI_Attr_delete
      external MPI_Attr_get
      external MPI_Attr_put
      external MPI_Get_elements_x
      external MPI_Info_get
      external MPI_Info_get_valuelen
      external MPI_Keyval_create
      external MPI_Keyval_free
      external MPI_Status_set_elements_x
      external MPI_Type_get_extent_x
      external MPI_Type_get_true_extent_x
      external MPI_Type_size_x

!     Removed C Bindings

      external MPI_Address
      external MPI_Type_hindexed
      external MPI_Type_hvector
      external MPI_Type_struct
      external MPI_Type_extent
      external MPI_Type_lb
      external MPI_Type_ub
