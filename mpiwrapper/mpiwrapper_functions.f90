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
