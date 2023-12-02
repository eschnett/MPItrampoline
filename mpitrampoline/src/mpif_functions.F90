subroutine MPI_COMM_NULL_COPY_FN(oldcomm, comm_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldcomm, comm_keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_COMM_NULL_COPY_FN

subroutine MPI_COMM_DUP_FN(oldcomm, comm_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldcomm, comm_keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_COMM_DUP_FN

subroutine MPI_COMM_NULL_DELETE_FN(comm, comm_keyval, attribute_val, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer comm, comm_keyval
  integer(MPI_ADDRESS_KIND) attribute_val, extra_state
  integer ierror
  ierror = MPI_SUCCESS
end subroutine MPI_COMM_NULL_DELETE_FN

subroutine MPI_WIN_NULL_COPY_FN(oldwin, win_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldwin, win_keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_WIN_NULL_COPY_FN

subroutine MPI_WIN_DUP_FN(oldwin, win_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldwin, win_keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_WIN_DUP_FN

subroutine MPI_WIN_NULL_DELETE_FN(win, win_keyval, attribute_val, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer win, win_keyval
  integer(MPI_ADDRESS_KIND) attribute_val, extra_state
  integer ierror
  ierror = MPI_SUCCESS
end subroutine MPI_WIN_NULL_DELETE_FN

subroutine MPI_TYPE_NULL_COPY_FN(oldtype, type_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldtype, type_keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_TYPE_NULL_COPY_FN

subroutine MPI_TYPE_DUP_FN(oldtype, type_keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldtype, type_keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_TYPE_DUP_FN

subroutine MPI_TYPE_NULL_DELETE_FN(type, type_keyval, attribute_val, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer type, type_keyval
  integer(MPI_ADDRESS_KIND) attribute_val, extra_state
  integer ierror
  ierror = MPI_SUCCESS
end subroutine MPI_TYPE_NULL_DELETE_FN

subroutine MPI_CONVERSION_FN_NULL(userbuf, datatype, count, filebuf, position, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer(MPI_ADDRESS_KIND) userbuf
  integer datatype
  integer count
  integer(MPI_ADDRESS_KIND) filebuf
  integer(MPI_OFFSET_KIND) position
  integer(MPI_ADDRESS_KIND) extra_state
  integer ierror
  ierror = MPI_SUCCESS
end subroutine MPI_CONVERSION_FN_NULL

subroutine MPI_CONVERSION_FN_NULL_C(userbuf, datatype, count, filebuf, position, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer(MPI_ADDRESS_KIND) userbuf
  integer datatype
  integer(MPI_COUNT_KIND) count
  integer(MPI_ADDRESS_KIND) filebuf
  integer(MPI_OFFSET_KIND) position
  integer(MPI_ADDRESS_KIND) extra_state
  integer ierror
  ierror = MPI_SUCCESS
end subroutine MPI_CONVERSION_FN_NULL_C

subroutine MPI_NULL_COPY_FN(oldcomm, keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldcomm, keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_NULL_COPY_FN

subroutine MPI_DUP_FN(oldcomm, keyval, extra_state, attribute_val_in, attribute_val_out, flag, ierror)
  implicit none
  include "mpif_constants.h"
  integer oldcomm, keyval
  integer(MPI_ADDRESS_KIND) extra_state, attribute_val_in, attribute_val_out
  logical flag
  integer ierror
  flag = .false.
  ierror = MPI_SUCCESS
end subroutine MPI_DUP_FN

subroutine MPI_NULL_DELETE_FN(comm, keyval, attribute_val, extra_state, ierror)
  implicit none
  include "mpif_constants.h"
  integer comm, keyval
  integer(MPI_ADDRESS_KIND) attribute_val, extra_state
  integer ierror
  ierror = MPI_SUCCESS
end subroutine MPI_NULL_DELETE_FN
