subroutine mpi_send_f08_impl_integer_0(buf, count, datatype, dest, tag, comm, ierror)
  use mpi_f08, only: mpi_comm, mpi_datatype
  use mpi, only: mpi_send
  implicit none

  integer, intent(in) :: buf
  integer, intent(in) :: count
  type(mpi_datatype), intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  type(mpi_comm), intent(in) :: comm
  integer, optional, intent(out) :: ierror
    
  integer ierror1
  
  call mpi_send(buf, count, datatype%datatype, dest, tag, comm%comm, ierror1)
  
  if (present(ierror)) ierror = ierror1
end subroutine mpi_send_f08_impl_integer_0

subroutine mpi_recv_f08_impl_integer_0(buf, count, datatype, dest, tag, comm, status, ierror)
  use mpi_f08, only: mpi_comm, mpi_datatype, mpi_status
  use mpi, only: mpi_status_size, mpi_source, mpi_tag, mpi_error, mpi_recv
  implicit none

  integer, intent(out) :: buf
  integer, intent(in) :: count
  type(mpi_datatype), intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  type(mpi_comm), intent(in) :: comm
  type(mpi_status), intent(out) :: status
  integer, optional, intent(out) :: ierror
    
  integer status1(mpi_status_size)
  integer ierror1
  
  call mpi_recv(buf, count, datatype%datatype, dest, tag, comm%comm, status1, ierror1)
  
  status%status = status1(1:mpi_status_size)
  status%mpi_source = status1(mpi_source)
  status%mpi_tag = status1(mpi_tag)
  status%mpi_error = status1(mpi_error)

  if (present(ierror)) ierror = ierror1
end subroutine mpi_recv_f08_impl_integer_0
