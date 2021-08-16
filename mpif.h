      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = 10)
      integer MPI_any_source 
      common /MPI_any_source/                                           &
     &MPI_any_source
      integer MPI_any_tag 
      common /MPI_any_tag/                                              &
     &MPI_any_tag
      integer MPI_proc_null 
      common /MPI_proc_null/                                            &
     &MPI_proc_null
      integer MPI_root 
      common /MPI_root/                                                 &
     &MPI_root
      integer MPI_congruent 
      common /MPI_congruent/                                            &
     &MPI_congruent
      integer MPI_ident 
      common /MPI_ident/                                                &
     &MPI_ident
      integer MPI_similar 
      common /MPI_similar/                                              &
     &MPI_similar
      integer MPI_unequal 
      common /MPI_unequal/                                              &
     &MPI_unequal
      integer MPI_keyval_invalid 
      common /MPI_keyval_invalid/                                       &
     &MPI_keyval_invalid
      integer MPI_undefined 
      common /MPI_undefined/                                            &
     &MPI_undefined
      integer MPI_comm_null 
      common /MPI_comm_null/                                            &
     &MPI_comm_null
      integer MPI_comm_self 
      common /MPI_comm_self/                                            &
     &MPI_comm_self
      integer MPI_comm_world 
      common /MPI_comm_world/                                           &
     &MPI_comm_world
      integer MPI_combiner_contiguous 
      common /MPI_combiner_contiguous/                                  &
     &MPI_combiner_contiguous
      integer MPI_combiner_darray 
      common /MPI_combiner_darray/                                      &
     &MPI_combiner_darray
      integer MPI_combiner_dup 
      common /MPI_combiner_dup/                                         &
     &MPI_combiner_dup
      integer MPI_combiner_f90_complex 
      common /MPI_combiner_f90_complex/                                 &
     &MPI_combiner_f90_complex
      integer MPI_combiner_f90_integer 
      common /MPI_combiner_f90_integer/                                 &
     &MPI_combiner_f90_integer
      integer MPI_combiner_f90_real 
      common /MPI_combiner_f90_real/                                    &
     &MPI_combiner_f90_real
      integer MPI_combiner_hindexed 
      common /MPI_combiner_hindexed/                                    &
     &MPI_combiner_hindexed
      integer MPI_combiner_hindexed_block 
      common /MPI_combiner_hindexed_block/                              &
     &MPI_combiner_hindexed_block
      integer MPI_combiner_hvector 
      common /MPI_combiner_hvector/                                     &
     &MPI_combiner_hvector
      integer MPI_combiner_indexed 
      common /MPI_combiner_indexed/                                     &
     &MPI_combiner_indexed
      integer MPI_combiner_indexed_block 
      common /MPI_combiner_indexed_block/                               &
     &MPI_combiner_indexed_block
      integer MPI_combiner_named 
      common /MPI_combiner_named/                                       &
     &MPI_combiner_named
      integer MPI_combiner_resized 
      common /MPI_combiner_resized/                                     &
     &MPI_combiner_resized
      integer MPI_combiner_struct 
      common /MPI_combiner_struct/                                      &
     &MPI_combiner_struct
      integer MPI_combiner_subarray 
      common /MPI_combiner_subarray/                                    &
     &MPI_combiner_subarray
      integer MPI_combiner_vector 
      common /MPI_combiner_vector/                                      &
     &MPI_combiner_vector
      integer MPI_distribute_block 
      common /MPI_distribute_block/                                     &
     &MPI_distribute_block
      integer MPI_distribute_cyclic 
      common /MPI_distribute_cyclic/                                    &
     &MPI_distribute_cyclic
      integer MPI_distribute_none 
      common /MPI_distribute_none/                                      &
     &MPI_distribute_none
      integer MPI_err_access 
      common /MPI_err_access/                                           &
     &MPI_err_access
      integer MPI_err_amode 
      common /MPI_err_amode/                                            &
     &MPI_err_amode
      integer MPI_err_arg 
      common /MPI_err_arg/                                              &
     &MPI_err_arg
      integer MPI_err_assert 
      common /MPI_err_assert/                                           &
     &MPI_err_assert
      integer MPI_err_bad_file 
      common /MPI_err_bad_file/                                         &
     &MPI_err_bad_file
      integer MPI_err_base 
      common /MPI_err_base/                                             &
     &MPI_err_base
      integer MPI_err_buffer 
      common /MPI_err_buffer/                                           &
     &MPI_err_buffer
      integer MPI_err_comm 
      common /MPI_err_comm/                                             &
     &MPI_err_comm
      integer MPI_err_conversion 
      common /MPI_err_conversion/                                       &
     &MPI_err_conversion
      integer MPI_err_count 
      common /MPI_err_count/                                            &
     &MPI_err_count
      integer MPI_err_dims 
      common /MPI_err_dims/                                             &
     &MPI_err_dims
      integer MPI_err_disp 
      common /MPI_err_disp/                                             &
     &MPI_err_disp
      integer MPI_err_dup_datarep 
      common /MPI_err_dup_datarep/                                      &
     &MPI_err_dup_datarep
      integer MPI_err_file 
      common /MPI_err_file/                                             &
     &MPI_err_file
      integer MPI_err_file_exists 
      common /MPI_err_file_exists/                                      &
     &MPI_err_file_exists
      integer MPI_err_file_in_use 
      common /MPI_err_file_in_use/                                      &
     &MPI_err_file_in_use
      integer MPI_err_group 
      common /MPI_err_group/                                            &
     &MPI_err_group
      integer MPI_err_info 
      common /MPI_err_info/                                             &
     &MPI_err_info
      integer MPI_err_info_key 
      common /MPI_err_info_key/                                         &
     &MPI_err_info_key
      integer MPI_err_info_nokey 
      common /MPI_err_info_nokey/                                       &
     &MPI_err_info_nokey
      integer MPI_err_info_value 
      common /MPI_err_info_value/                                       &
     &MPI_err_info_value
      integer MPI_err_intern 
      common /MPI_err_intern/                                           &
     &MPI_err_intern
      integer MPI_err_in_status 
      common /MPI_err_in_status/                                        &
     &MPI_err_in_status
      integer MPI_err_io 
      common /MPI_err_io/                                               &
     &MPI_err_io
      integer MPI_err_keyval 
      common /MPI_err_keyval/                                           &
     &MPI_err_keyval
      integer MPI_err_locktype 
      common /MPI_err_locktype/                                         &
     &MPI_err_locktype
      integer MPI_err_name 
      common /MPI_err_name/                                             &
     &MPI_err_name
      integer MPI_err_not_same 
      common /MPI_err_not_same/                                         &
     &MPI_err_not_same
      integer MPI_err_no_mem 
      common /MPI_err_no_mem/                                           &
     &MPI_err_no_mem
      integer MPI_err_no_space 
      common /MPI_err_no_space/                                         &
     &MPI_err_no_space
      integer MPI_err_no_such_file 
      common /MPI_err_no_such_file/                                     &
     &MPI_err_no_such_file
      integer MPI_err_op 
      common /MPI_err_op/                                               &
     &MPI_err_op
      integer MPI_err_other 
      common /MPI_err_other/                                            &
     &MPI_err_other
      integer MPI_err_pending 
      common /MPI_err_pending/                                          &
     &MPI_err_pending
      integer MPI_err_port 
      common /MPI_err_port/                                             &
     &MPI_err_port
      integer MPI_err_quota 
      common /MPI_err_quota/                                            &
     &MPI_err_quota
      integer MPI_err_rank 
      common /MPI_err_rank/                                             &
     &MPI_err_rank
      integer MPI_err_read_only 
      common /MPI_err_read_only/                                        &
     &MPI_err_read_only
      integer MPI_err_request 
      common /MPI_err_request/                                          &
     &MPI_err_request
      integer MPI_err_rma_attach 
      common /MPI_err_rma_attach/                                       &
     &MPI_err_rma_attach
      integer MPI_err_rma_conflict 
      common /MPI_err_rma_conflict/                                     &
     &MPI_err_rma_conflict
      integer MPI_err_rma_flavor 
      common /MPI_err_rma_flavor/                                       &
     &MPI_err_rma_flavor
      integer MPI_err_rma_range 
      common /MPI_err_rma_range/                                        &
     &MPI_err_rma_range
      integer MPI_err_rma_shared 
      common /MPI_err_rma_shared/                                       &
     &MPI_err_rma_shared
      integer MPI_err_rma_sync 
      common /MPI_err_rma_sync/                                         &
     &MPI_err_rma_sync
      integer MPI_err_root 
      common /MPI_err_root/                                             &
     &MPI_err_root
      integer MPI_err_service 
      common /MPI_err_service/                                          &
     &MPI_err_service
      integer MPI_err_size 
      common /MPI_err_size/                                             &
     &MPI_err_size
      integer MPI_err_spawn 
      common /MPI_err_spawn/                                            &
     &MPI_err_spawn
      integer MPI_err_tag 
      common /MPI_err_tag/                                              &
     &MPI_err_tag
      integer MPI_err_topology 
      common /MPI_err_topology/                                         &
     &MPI_err_topology
      integer MPI_err_truncate 
      common /MPI_err_truncate/                                         &
     &MPI_err_truncate
      integer MPI_err_type 
      common /MPI_err_type/                                             &
     &MPI_err_type
      integer MPI_err_unknown 
      common /MPI_err_unknown/                                          &
     &MPI_err_unknown
      integer MPI_err_unsupported_datarep 
      common /MPI_err_unsupported_datarep/                              &
     &MPI_err_unsupported_datarep
      integer MPI_err_unsupported_operation 
      common /MPI_err_unsupported_operation/                            &
     &MPI_err_unsupported_operation
      integer MPI_err_win 
      common /MPI_err_win/                                              &
     &MPI_err_win
      integer MPI_success 
      common /MPI_success/                                              &
     &MPI_success
      integer MPI_mode_append 
      common /MPI_mode_append/                                          &
     &MPI_mode_append
      integer MPI_mode_create 
      common /MPI_mode_create/                                          &
     &MPI_mode_create
      integer MPI_mode_delete_on_close 
      common /MPI_mode_delete_on_close/                                 &
     &MPI_mode_delete_on_close
      integer MPI_mode_excl 
      common /MPI_mode_excl/                                            &
     &MPI_mode_excl
      integer MPI_mode_rdonly 
      common /MPI_mode_rdonly/                                          &
     &MPI_mode_rdonly
      integer MPI_mode_rdwr 
      common /MPI_mode_rdwr/                                            &
     &MPI_mode_rdwr
      integer MPI_mode_sequential 
      common /MPI_mode_sequential/                                      &
     &MPI_mode_sequential
      integer MPI_mode_unique_open 
      common /MPI_mode_unique_open/                                     &
     &MPI_mode_unique_open
      integer MPI_mode_wronly 
      common /MPI_mode_wronly/                                          &
     &MPI_mode_wronly
      integer MPI_order_c 
      common /MPI_order_c/                                              &
     &MPI_order_c
      integer MPI_order_fortran 
      common /MPI_order_fortran/                                        &
     &MPI_order_fortran
      integer MPI_thread_single 
      common /MPI_thread_single/                                        &
     &MPI_thread_single
      integer MPI_thread_funneled 
      common /MPI_thread_funneled/                                      &
     &MPI_thread_funneled
      integer MPI_thread_serialized 
      common /MPI_thread_serialized/                                    &
     &MPI_thread_serialized
      integer MPI_thread_multiple 
      common /MPI_thread_multiple/                                      &
     &MPI_thread_multiple
      integer MPI_bottom 
      common /MPI_bottom/                                               &
     &MPI_bottom
      integer MPI_in_place 
      common /MPI_in_place/                                             &
     &MPI_in_place
      external MPI_send
      external MPI_recv
      external MPI_get_count
      external MPI_wtime
      external MPI_wtick
      external MPI_init
      external MPI_finalize
      external MPI_initialized
      external MPI_abort
      external MPI_finalized
      double precision MPI_Wtime
      double precision MPI_Wtick
