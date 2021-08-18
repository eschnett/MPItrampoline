module mpi
  implicit none
  save

  logical, parameter :: mpi_async_protects_nonblocking = .false.
  logical, parameter :: mpi_subarrays_supported = .false.

  integer, parameter :: mpi_status_size = 6

  integer mpi_error
  integer mpi_source
  integer mpi_tag

  integer mpi_comm_null
  integer mpi_comm_self
  integer mpi_comm_world

  integer mpi_double
  integer mpi_double_precision
  integer mpi_float
  integer mpi_int
  integer mpi_integer
  integer mpi_real

  integer mpi_max
  integer mpi_min
  integer mpi_sum

  ! TOOD: Define types for handles, as in `mpi_f08`

  interface
     subroutine mpi_send(buf, count, datatype, dest, tag, comm, ierror)
       implicit none
       !gcc$ attributes no_arg_check :: buf
       type(*), intent(in) :: buf(*)
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       integer, intent(in) :: comm
       integer, intent(out) :: ierror
     end subroutine mpi_send

     subroutine mpi_recv(buf, count, datatype, dest, tag, comm, status, ierror)
       import mpi_status_size
       implicit none
       !gcc$ attributes no_arg_check :: buf
       integer :: buf(*)
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       integer, intent(in) :: comm
       integer, intent(out) :: status(mpi_status_size)
       integer, intent(out) :: ierror
     end subroutine mpi_recv

     subroutine mpi_get_count(status, datatype, count, ierror)
       import mpi_status_size
       implicit none
       integer, intent(in) :: status(mpi_status_size)
       integer, intent(in) :: datatype
       integer, intent(out) :: count
       integer, intent(out) :: ierror
     end subroutine mpi_get_count

     subroutine mpi_comm_size(comm, size, ierror)
       implicit none
       integer, intent(in) :: comm
       integer, intent(out) :: size
       integer, intent(out) :: ierror
     end subroutine mpi_comm_size

     subroutine mpi_comm_rank(comm, rank, ierror)
       implicit none
       integer, intent(in) :: comm
       integer, intent(out) :: rank
       integer, intent(out) :: ierror
     end subroutine mpi_comm_rank

     subroutine mpi_init(ierror)
       implicit none
       integer, intent(out) :: ierror
     end subroutine mpi_init

     subroutine mpi_finalize(ierror)
       implicit none
       integer, intent(out) :: ierror
     end subroutine mpi_finalize

     subroutine mpi_abort(comm, errorcode, ierror)
       implicit none
       integer, intent(in) :: comm
       integer, intent(in) :: errorcode
       integer, intent(out) :: ierror
     end subroutine mpi_abort

     double precision function mpi_wtime()
       implicit none
     end function mpi_wtime

     double precision function mpi_wtick()
       implicit none
     end function mpi_wtick
  end interface

end module mpi
