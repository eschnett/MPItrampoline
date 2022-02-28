      include "mpiabif.h"

      include "mpi_declarations_fortran.h"

!     Option 1 to handle sentinel values:
!
!     Define copies here in MPItrampoline, and convert them using
!     explicit comparisons in the C wrapper functions here in
!     MPItrampoline.

      integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
      common /MPI_STATUS_IGNORE/ MPI_STATUS_IGNORE
      integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
      common /MPI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE

!     Option 2 to handle sentinel values:
!
!     Use Cray pointers. Unfortunately, these might not be supported
!     everywhere, and if they are, they require special compiler
!     options.

!     integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
!     integer(MPI_ADDRESS_KIND) MPI_STATUS_IGNORE_PTR
!     common /MPI_STATUS_IGNORE_PTR/ MPI_STATUS_IGNORE_PTR
!     pointer (MPI_STATUS_IGNORE_PTR, MPI_STATUS_IGNORE)
!
!     integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
!     integer(MPI_ADDRESS_KIND) MPI_STATUSES_IGNORE_PTR
!     common /MPI_STATUSES_IGNORE_PTR/ MPI_STATUSES_IGNORE_PTR
!     pointer (MPI_STATUSES_IGNORE_PTR, MPI_STATUSES_IGNORE)

!     Option 3 to handle sentinel values:
!
!     Use Fortran pointers. Unfortunately, pointers to arrays cannot
!     have a fixed size, and accessing the pointer requires a run-time
!     check whether the array is contiguous. This might make a copy, and
!     thus the sentinel doesn't actually work.

!     integer MPI_STATUS_IGNORE(:)
!     pointer MPI_STATUS_IGNORE
!     common /MPI_STATUS_IGNORE/ MPI_STATUS_IGNORE
!
!     integer MPI_STATUSES_IGNORE(:)
!     pointer MPI_STATUSES_IGNORE
!     common /MPI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE
