program hello
  use mpi_f08
  implicit none

  integer size, rank
  integer token

  print '("Hello, World!")'

  print '("Running with MPItrampoline ",i0,".",i0,".",i0)', &
       MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR, MPITRAMPOLINE_VERSION_PATCH

  ! call MPI_Init()
  ! 
  ! call MPI_Comm_size(MPI_COMM_WORLD, size)
  ! call MPI_Comm_rank(MPI_COMM_WORLD, rank)
  ! 
  ! if (rank == 0) then
  !    print '("Hello, World!")'
  ! end if
  ! 
  ! if (rank > 0) then
  !    call MPI_Recv(token, 0, MPI_INTEGER, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE)
  ! end if
  ! print '("  process ",i0,"/",i0)', rank, size
  ! if (rank < size - 1) then
  !    call MPI_Send(token, 0, MPI_INTEGER, rank + 1, 0, MPI_COMM_WORLD)
  ! end if
  ! call MPI_Barrier(MPI_COMM_WORLD)
  ! 
  ! if (rank == 0) then
  !    print '("Done.")'
  ! end if
  ! call MPI_Finalize()
end program hello
