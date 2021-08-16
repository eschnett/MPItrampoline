subroutine mpi_send_impl_integer_1(buf, count, datatype, dest, tag, comm, ierror)
  implicit none
  include "mpif.h"
  integer, intent(in) :: buf(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call mpi_send(buf, count, datatype, dest, tag, comm, ierror)
end subroutine mpi_send_impl_integer_1

subroutine mpi_recv_impl_integer_1(buf, count, datatype, dest, tag, comm, status, ierror)
  implicit none
  include "mpif.h"
  integer, intent(out) :: buf(*)
  integer, intent(out) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: status(mpi_status_size)
  integer, intent(out) :: ierror
  call mpi_recv(buf, count, datatype, dest, tag, comm, status, ierror)
end subroutine mpi_recv_impl_integer_1
