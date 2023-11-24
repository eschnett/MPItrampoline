subroutine MPI_COMM_NULL_COPY_FN(oldcomm, comm_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldcomm, comm_keyval, ierror
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_COMM_NULL_COPY_FN

subroutine MPI_COMM_DUP_FN(oldcomm, comm_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldcomm, comm_keyval, ierror
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_COMM_DUP_FN

subroutine MPI_COMM_NULL_DELETE_FN(comm, comm_keyval, attribute_val, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer comm, comm_keyval, ierror
  integer(MPI_ADDRESS_KIND) attribute_val, extra_state
  ierror = MPI_SUCCESS
end subroutine MPI_COMM_NULL_DELETE_FN
