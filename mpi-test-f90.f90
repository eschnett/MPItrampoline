program mpi_test_f90
  implicit none
  include "mpif.h"
  integer ierror
  call MPI_Init(ierror)
  call MPI_Finalize(ierror)
end program mpi_test_f90
