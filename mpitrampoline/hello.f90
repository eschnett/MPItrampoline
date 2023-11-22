program hello
  implicit none
  include "mpif.h"

  call mpi_init()
  call mpi_finalize()
end program hello
