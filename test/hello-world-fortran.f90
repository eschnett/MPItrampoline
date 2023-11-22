program hello
  implicit none
  include "mpif.h"

  integer size, rank
  integer n
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

  do n = 0, size-1
     if (rank == n) then
        print '("  process ",i0,"/",i0)', rank, size
        call MPI_Barrier(MPI_COMM_WORLD, ierror)
     end if
  end do

  if (rank == 0) then
     print '("Done.")'
  end if
  call MPI_Finalize(ierror)
end program hello
