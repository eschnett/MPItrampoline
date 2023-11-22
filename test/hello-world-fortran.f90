program hello
  implicit none
  include "mpif.h"

  integer size, rank
  integer token
  integer status(MPI_STATUS_SIZE)
  integer ierror

  print '("Hello, World!")'

  print '("Running with MPItrampoline ",i0,".",i0,".",i0)', &
       MPITRAMPOLINE_VERSION_MAJOR, MPITRAMPOLINE_VERSION_MINOR, MPITRAMPOLINE_VERSION_PATCH

  call MPI_Init(ierror)
  
  call MPI_Comm_size(MPI_COMM_WORLD, size, ierror)
  call MPI_Comm_rank(MPI_COMM_WORLD, rank, ierror)

  if (rank == 0) then
     print '("Hello, World!")'
  end if

  if (rank > 0) then
     print '("A.0")'
     call MPI_Recv(token, 0, MPI_INTEGER, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE, ierror)
     print '("A.1")'
  end if
  print '("  process ",i0,"/",i0)', rank, size
  if (rank < size - 1) then
     print '("A.2")'
     call MPI_Send(token, 0, MPI_INTEGER, rank + 1, 0, MPI_COMM_WORLD, ierror)
     print '("A.3")'
  end if
  call MPI_Barrier(MPI_COMM_WORLD, ierror)
  print '("A.4")'

  if (rank == 0) then
     print '("Done.")'
  end if
  call MPI_Finalize(ierror)
end program hello
