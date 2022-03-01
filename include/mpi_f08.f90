module mpi_f08

  use mpi, only: mpi_status_size

  implicit none
  save

  ! TODO: Make everything private by default

  private mpi_status_size

  logical, parameter :: mpi_async_protects_nonblocking = .false.
  logical, parameter :: mpi_subarrays_supported = .false.

  type, bind(C) :: mpi_comm
     integer :: mpi_val
  end type mpi_comm

  type, bind(C) :: mpi_datatype
     integer :: mpi_val
  end type mpi_datatype

  type, bind(C) :: mpi_status
     integer :: mpi_val(mpi_status_size)
     integer :: mpi_source
     integer :: mpi_tag
     integer :: mpi_error
  end type mpi_status

  logical :: initialized = .false. ! TODO

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
     module procedure mpi_send_impl
  end interface mpi_send

  interface mpi_recv
     module procedure mpi_recv_impl
  end interface mpi_recv

  interface mpi_get_count
     module procedure mpi_get_count_impl
  end interface mpi_get_count

  interface mpi_comm_size
     module procedure mpi_comm_size_impl
  end interface mpi_comm_size

  interface mpi_comm_rank
     module procedure mpi_comm_rank_impl
  end interface mpi_comm_rank

  interface mpi_init
     module procedure mpi_init_impl
  end interface mpi_init

  interface mpi_finalize
     module procedure mpi_finalize_impl
  end interface mpi_finalize

  interface mpi_abort
     module procedure mpi_abort_impl
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
    mpi_comm_eq = comm1%mpi_val .eq. comm2%mpi_val
  end function mpi_comm_eq

  logical function mpi_comm_ne(comm1, comm2)
    type(mpi_comm), intent(in) :: comm1, comm2
    mpi_comm_ne = comm1%mpi_val .ne. comm2%mpi_val
  end function mpi_comm_ne

  logical function mpi_datatype_eq(datatype1, datatype2)
    type(mpi_datatype), intent(in) :: datatype1, datatype2
    mpi_datatype_eq = datatype1%mpi_val .eq. datatype2%mpi_val
  end function mpi_datatype_eq

  logical function mpi_datatype_ne(datatype1, datatype2)
    type(mpi_datatype), intent(in) :: datatype1, datatype2
    mpi_datatype_ne = datatype1%mpi_val .ne. datatype2%mpi_val
  end function mpi_datatype_ne

  subroutine mpi_send_impl(buf, count, datatype, dest, tag, comm, ierror)
    use mpi, only: mpi_send
    !gcc$ attributes no_arg_check :: buf
    type(*), intent(in) :: buf
    integer, intent(in) :: count
    type(mpi_datatype), intent(in) :: datatype
    integer, intent(in) :: dest
    integer, intent(in) :: tag
    type(mpi_comm), intent(in) :: comm
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    call mpi_send(buf, count, datatype%mpi_val, dest, tag, comm%mpi_val, ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_send_impl
  
  subroutine mpi_recv_impl(buf, count, datatype, source, tag, comm, status, ierror)
    use mpi, only: mpi_source, mpi_tag, mpi_error, mpi_recv
    !gcc$ attributes no_arg_check :: buf
    type(*) :: buf
    integer, intent(in) :: count
    type(mpi_datatype), intent(in) :: datatype
    integer, intent(in) :: source
    integer, intent(in) :: tag
    type(mpi_comm), intent(in) :: comm
    type(mpi_status), intent(out) :: status
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    call mpi_recv(buf, count, datatype%mpi_val, source, tag, comm%mpi_val, status%mpi_val, ierror1)
    
    status%mpi_source = status%mpi_val(mpi_source)
    status%mpi_tag = status%mpi_val(mpi_tag)
    status%mpi_error = status%mpi_val(mpi_error)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_recv_impl
  
  subroutine mpi_get_count_impl(status, datatype, count, ierror)
    use mpi, only: mpi_status_size, mpi_source, mpi_tag, mpi_error, mpi_get_count
    implicit none
    type(mpi_status), intent(in) :: status
    type(mpi_datatype), intent(in) :: datatype
    integer, intent(out) :: count
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    type(mpi_status) status1
    
    status1 = status
    status1%mpi_val(mpi_source) = status1%mpi_source
    status1%mpi_val(mpi_tag) = status1%mpi_tag
    status1%mpi_val(mpi_error) = status1%mpi_error
    
    call mpi_get_count(status1%mpi_val, datatype%mpi_val, count, ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_get_count_impl
  
  subroutine mpi_comm_size_impl(comm, size, ierror)
    use mpi, only: mpi_comm_size
    implicit none
    type(mpi_comm), intent(in) :: comm
    integer, intent(out) :: size
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    call mpi_comm_size(comm%mpi_val, size, ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_comm_size_impl
  
  subroutine mpi_comm_rank_impl(comm, rank, ierror)
    use mpi, only: mpi_comm_rank
    implicit none
    type(mpi_comm), intent(in) :: comm
    integer, intent(out) :: rank
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    call mpi_comm_rank(comm%mpi_val, rank, ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_comm_rank_impl
  
  subroutine mpi_init_impl(ierror)
    use mpi, only: mpi_init
    implicit none
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    ! TODO
    if (.not. initialized) then
       ! print '("error")'
       do while (.true.)
       end do
    end if

    call mpi_init(ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_init_impl
  
  subroutine mpi_finalize_impl(ierror)
    use mpi, only: mpi_finalize
    implicit none
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    call mpi_finalize(ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_finalize_impl
  
  subroutine mpi_abort_impl(comm, errorcode, ierror)
    use mpi, only: mpi_abort
    implicit none
    type(mpi_comm), intent(in) :: comm
    integer, intent(in) :: errorcode
    integer, optional, intent(out) :: ierror
    
    integer ierror1
    
    call mpi_abort(comm%mpi_val, errorcode, ierror1)
    
    if (present(ierror)) ierror = ierror1
  end subroutine mpi_abort_impl

end module mpi_f08
