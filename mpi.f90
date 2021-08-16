module mpi
  implicit none

  integer, parameter :: mpi_status_size = 10

  integer, parameter :: mpi_source = 7
  integer, parameter :: mpi_tag = 8
  integer, parameter :: mpi_error = 9

  interface
     subroutine mpi_send(buf, count, datatype, dest, tag, comm, ierror)
       implicit none
       type(*), dimension(..), intent(in) :: buf
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
       type(*), dimension(..) :: buf
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       integer, intent(in) :: comm
       integer, intent(out) :: status(mpi_status_size)
       integer, intent(out) :: ierror
     end subroutine mpi_recv

     subroutine mpi_init(ierror)
       implicit none
       integer, intent(out) :: ierror
     end subroutine mpi_init

     subroutine mpi_finalize(ierror)
       implicit none
       integer, intent(out) :: ierror
     end subroutine mpi_finalize

     double precision function mpi_wtime()
       implicit none
     end function mpi_wtime

     double precision function mpi_wtick()
       implicit none
     end function mpi_wtick
  end interface
end module mpi
