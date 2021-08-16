module mpi_f08
  implicit none

  type :: mpi_comm
     integer :: comm
  end type mpi_comm

  type :: mpi_datatype
     integer :: datatype
  end type mpi_datatype

  type :: mpi_status
     integer :: status(6)
     integer :: mpi_source
     integer :: mpi_tag
     integer :: mpi_error
     integer :: padding
  end type mpi_status

  interface mpi_send
     subroutine mpi_send_impl(buf, count, datatype, dest, tag, comm, ierror)
       import mpi_comm, mpi_datatype
       implicit none
       type(*), dimension(..), intent(in) :: buf
       integer, intent(in) :: count
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       type(mpi_comm), intent(in) :: comm
       integer, optional, intent(out) :: ierror
     end subroutine mpi_send_impl
  end interface mpi_send

  interface mpi_recv
     subroutine mpi_recv_impl(buf, count, datatype, dest, tag, comm, status, ierror)
       import mpi_comm, mpi_datatype, mpi_status
       implicit none
       type(*), dimension(..) :: buf
       integer, intent(in) :: count
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       type(mpi_comm), intent(in) :: comm
       type(mpi_status), intent(out) :: status
       integer, optional, intent(out) :: ierror
     end subroutine mpi_recv_impl
  end interface mpi_recv

  interface  mpi_init
     subroutine mpi_init_impl(ierror)
       implicit none
       integer, optional, intent(out) :: ierror
     end subroutine mpi_init_impl
  end interface mpi_init

  interface mpi_finalize
     subroutine mpi_finalize_impl(ierror)
       implicit none
       integer, optional, intent(out) :: ierror
     end subroutine mpi_finalize_impl
  end interface mpi_finalize

  interface mpi_wtime
     double precision function mpi_wtime()
       implicit none
     end function mpi_wtime
  end interface mpi_wtime

  interface mpi_wtick
     double precision function mpi_wtick()
       implicit none
     end function mpi_wtick
  end interface mpi_wtick

end module mpi_f08
