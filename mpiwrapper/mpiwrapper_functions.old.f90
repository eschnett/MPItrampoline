subroutine MPIABI_Init(ierror)
  use mpiwrapper
  implicit none
  integer ierror
  call MPI_Init(ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Init

subroutine MPIABI_Finalize(ierror)
  use mpiwrapper
  implicit none
  integer ierror
  call MPI_Finalize(ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Finalize

subroutine MPIABI_Barrier(comm, ierror)
  use mpiwrapper
  implicit none
  integer comm
  integer ierror
  integer mpi_comm
  mpi_comm = abi2mpi_comm(comm)
  call MPI_Barrier(mpi_comm, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Barrier

subroutine MPIABI_Recv(buf, count, datatype, source, tag, comm, status, ierror)
  use mpiwrapper
  implicit none
  integer buf, count, datatype, source, tag, comm, status(MPIABI_STATUS_SIZE), ierror
  integer mpi_datatype, mpi_source1, mpi_tag1, mpi_comm, mpi_status(MPI_STATUS_SIZE), mpi_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) mpi_statusptr
  pointer (mpi_statusptr, mpi_status)
  mpi_datatype = abi2mpi_datatype(datatype)
  mpi_source1 = abi2mpi_source(source)
  mpi_tag1 = abi2mpi_tag(tag)
  mpi_comm = abi2mpi_comm(comm)
  mpi_statusptr = abi2mpi_statusptr_uninitialized(status, mpi_status_storage)
  call MPI_Recv(buf, count, mpi_datatype, mpi_source1, mpi_tag1, mpi_comm, mpi_status, ierror)
  call mpi2abi_statusptr(mpi_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Recv

subroutine MPIABI_Send(buf, count, datatype, dest, tag, comm, ierror)
  use mpiwrapper
  implicit none
  integer buf, count, datatype, dest, tag, comm, ierror
  integer mpi_datatype, mpi_comm
  mpi_datatype = abi2mpi_datatype(datatype)
  mpi_comm = abi2mpi_comm(comm)
  call MPI_Send(buf, count, mpi_datatype, dest, tag, mpi_comm, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Send

subroutine MPIABI_Comm_size(comm, size, ierror)
  use mpiwrapper
  implicit none
  integer comm
  integer size
  integer ierror
  integer mpi_comm
  mpi_comm = abi2mpi_comm(comm)
  call MPI_Comm_size(mpi_comm, size, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_Size

subroutine MPIABI_Comm_rank(comm, rank, ierror)
  use mpiwrapper
  implicit none
  integer comm
  integer rank
  integer ierror
  integer mpi_comm
  mpi_comm = abi2mpi_comm(comm)
  call MPI_Comm_rank(mpi_comm, rank, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_Rank
