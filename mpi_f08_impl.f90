subroutine mpitrampoline_mpi_f08_init()

  use mpi_f08

  use mpi, only: &
       mpi_comm_null1 => mpi_comm_null, &
       mpi_comm_self1 => mpi_comm_self, &
       mpi_comm_world1 => mpi_comm_world, &

       mpi_int1 => mpi_int, &
       mpi_integer1 => mpi_integer

  implicit none

  mpi_int%datatype = mpi_int1
  mpi_integer%datatype = mpi_integer1
  
  mpi_comm_null%comm = mpi_comm_null1
  mpi_comm_self%comm = mpi_comm_self1
  mpi_comm_world%comm = mpi_comm_world1

end subroutine mpitrampoline_mpi_f08_init

subroutine mpi_get_count_impl(status, datatype, count, ierror)
  use mpi_f08, only: mpi_status, mpi_datatype
  use mpi, only: mpi_status_size, mpi_source, mpi_tag, mpi_error, mpi_get_count
  implicit none
  type(mpi_status), intent(in) :: status
  type(mpi_datatype), intent(in) :: datatype
  integer, intent(out) :: count
  integer, optional, intent(out) :: ierror

  integer status1(mpi_status_size)
  integer ierror1
  
  status1(1:mpi_status_size) = status%status
  status1(mpi_source) = status%mpi_source
  status1(mpi_tag) = status%mpi_tag
  status1(mpi_error) = status%mpi_error

  call mpi_get_count(status1, datatype%datatype, count, ierror1)

  if (present(ierror)) ierror = ierror1
end subroutine mpi_get_count_impl

subroutine mpi_comm_size_impl(comm, size, ierror)
  use mpi_f08, only: mpi_comm
  use mpi, only: mpi_comm_size
  implicit none
  type(mpi_comm), intent(in) :: comm
  integer, intent(out) :: size
  integer, optional, intent(out) :: ierror

  integer ierror1

  call mpi_comm_size(comm%comm, size, ierror1)

  if (present(ierror)) ierror = ierror1
end subroutine mpi_comm_size_impl

subroutine mpi_comm_rank_impl(comm, rank, ierror)
  use mpi_f08, only: mpi_comm
  use mpi, only: mpi_comm_rank
  implicit none
  type(mpi_comm), intent(in) :: comm
  integer, intent(out) :: rank
  integer, optional, intent(out) :: ierror

  integer ierror1

  call mpi_comm_rank(comm%comm, rank, ierror1)

  if (present(ierror)) ierror = ierror1
end subroutine mpi_comm_rank_impl

subroutine mpi_init_impl(ierror)
  use mpi, only: mpi_init
  implicit none
  integer, optional, intent(out) :: ierror
    
  integer ierror1
  
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
  use mpi_f08, only: mpi_comm
  use mpi, only: mpi_abort
  implicit none
  type(mpi_comm), intent(in) :: comm
  integer, intent(in) :: errorcode
  integer, optional, intent(out) :: ierror

  integer ierror1

  call mpi_abort(comm%comm, errorcode, ierror1)

  if (present(ierror)) ierror = ierror1
end subroutine mpi_abort_impl
