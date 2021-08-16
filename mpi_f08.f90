module mpi_f08

  use mpi, only: mpi_status_size

  implicit none
  save

  ! TODO: Make everything private by default

  private mpi_status_size

  type :: mpi_comm
     integer :: comm
  end type mpi_comm

  type :: mpi_datatype
     integer :: datatype
  end type mpi_datatype

  type :: mpi_status
     integer :: status(mpi_status_size)
     integer :: mpi_source
     integer :: mpi_tag
     integer :: mpi_error
     integer :: padding
  end type mpi_status

  type(mpi_comm) :: mpi_comm_null
  type(mpi_comm) :: mpi_comm_self
  type(mpi_comm) :: mpi_comm_world

  type(mpi_datatype) :: mpi_int
  type(mpi_datatype) :: mpi_integer

  interface operator (.eq.)
     module procedure mpi_comm_eq
     module procedure mpi_datatype_eq
  end interface operator (.eq.)

  interface operator (.ne.)
     module procedure mpi_comm_ne
     module procedure mpi_datatype_ne
  end interface operator (.ne.)

  interface mpi_send
     subroutine mpi_send_f08_impl_integer_0(buf, count, datatype, dest, tag, comm, ierror)
       import mpi_comm, mpi_datatype
       implicit none
       integer, intent(in) :: buf
       integer, intent(in) :: count
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       type(mpi_comm), intent(in) :: comm
       integer, optional, intent(out) :: ierror
     end subroutine mpi_send_f08_impl_integer_0
     subroutine mpi_send_f08_impl_integer_1(buf, count, datatype, dest, tag, comm, ierror)
       import mpi_comm, mpi_datatype
       implicit none
       integer, intent(in) :: buf(*)
       integer, intent(in) :: count
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       type(mpi_comm), intent(in) :: comm
       integer, optional, intent(out) :: ierror
     end subroutine mpi_send_f08_impl_integer_1
  end interface mpi_send

  interface mpi_recv
     subroutine mpi_recv_f08_impl_integer_0(buf, count, datatype, dest, tag, comm, status, ierror)
       import mpi_comm, mpi_datatype, mpi_status
       implicit none
       integer, intent(in) :: buf
       integer, intent(in) :: count
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       type(mpi_comm), intent(in) :: comm
       type(mpi_status), intent(out) :: status
       integer, optional, intent(out) :: ierror
     end subroutine mpi_recv_f08_impl_integer_0
     subroutine mpi_recv_f08_impl_integer_1(buf, count, datatype, dest, tag, comm, status, ierror)
       import mpi_comm, mpi_datatype, mpi_status
       implicit none
       integer, intent(in) :: buf(*)
       integer, intent(in) :: count
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       type(mpi_comm), intent(in) :: comm
       type(mpi_status), intent(out) :: status
       integer, optional, intent(out) :: ierror
     end subroutine mpi_recv_f08_impl_integer_1
  end interface mpi_recv

  interface mpi_get_count
     subroutine mpi_get_count_impl(status, datatype, count, ierror)
       import mpi_status, mpi_datatype
       implicit none
       type(mpi_status), intent(in) :: status
       type(mpi_datatype), intent(in) :: datatype
       integer, intent(out) :: count
       integer, optional, intent(out) :: ierror
     end subroutine mpi_get_count_impl
  end interface mpi_get_count

  interface mpi_comm_size
     subroutine mpi_comm_size_impl(comm, size, ierror)
       import mpi_comm
       implicit none
       type(mpi_comm), intent(in) :: comm
       integer, intent(out) :: size
       integer, optional, intent(out) :: ierror
     end subroutine mpi_comm_size_impl
  end interface mpi_comm_size

  interface mpi_comm_rank
     subroutine mpi_comm_rank_impl(comm, rank, ierror)
       import mpi_comm
       implicit none
       type(mpi_comm), intent(in) :: comm
       integer, intent(out) :: rank
       integer, optional, intent(out) :: ierror
     end subroutine mpi_comm_rank_impl
  end interface mpi_comm_rank

  interface mpi_init
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

  interface mpi_abort
     subroutine mpi_abort_impl(comm, errorcode, ierror)
       import mpi_comm
       implicit none
       type(mpi_comm), intent(in) :: comm
       integer, intent(in) :: errorcode
       integer, optional, intent(out) :: ierror
     end subroutine mpi_abort_impl
  end interface mpi_abort

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

contains

  logical function mpi_comm_eq(comm1, comm2)
    type(mpi_comm), intent(in) :: comm1, comm2
    mpi_comm_eq = comm1%comm .eq. comm2%comm
  end function mpi_comm_eq

  logical function mpi_comm_ne(comm1, comm2)
    type(mpi_comm), intent(in) :: comm1, comm2
    mpi_comm_ne = comm1%comm .ne. comm2%comm
  end function mpi_comm_ne

  logical function mpi_datatype_eq(datatype1, datatype2)
    type(mpi_datatype), intent(in) :: datatype1, datatype2
    mpi_datatype_eq = datatype1%datatype .eq. datatype2%datatype
  end function mpi_datatype_eq

  logical function mpi_datatype_ne(datatype1, datatype2)
    type(mpi_datatype), intent(in) :: datatype1, datatype2
    mpi_datatype_ne = datatype1%datatype .ne. datatype2%datatype
  end function mpi_datatype_ne

end module mpi_f08
