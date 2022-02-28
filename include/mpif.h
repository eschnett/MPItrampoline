      include "mpiabif.h"

!     Constants

      integer MPI_VERSION
      parameter (MPI_VERSION = MPIABI_MPI_VERSION)
      integer MPI_SUBVERSION
      parameter (MPI_SUBVERSION = MPIABI_MPI_SUBVERSION)

      integer MPI_MAX_DATAREP_STRING
      parameter (MPI_MAX_DATAREP_STRING = MPIABI_MAX_DATAREP_STRING)
      integer MPI_MAX_ERROR_STRING
      parameter (MPI_MAX_ERROR_STRING = MPIABI_MAX_ERROR_STRING)
      integer MPI_MAX_INFO_KEY
      parameter (MPI_MAX_INFO_KEY = MPIABI_MAX_INFO_KEY)
      integer MPI_MAX_INFO_VAL
      parameter (MPI_MAX_INFO_VAL = MPIABI_MAX_INFO_VAL)
      integer MPI_MAX_LIBRARY_VERSION_STRING
      parameter (MPI_MAX_LIBRARY_VERSION_STRING =                       &
     &     MPIABI_MAX_LIBRARY_VERSION_STRING)
      integer MPI_MAX_OBJECT_NAME
      parameter (MPI_MAX_OBJECT_NAME = MPIABI_MAX_OBJECT_NAME)
      integer MPI_MAX_PORT_NAME
      parameter (MPI_MAX_PORT_NAME = MPIABI_MAX_PORT_NAME)
      integer MPI_MAX_PROCESSOR_NAME
      parameter (MPI_MAX_PROCESSOR_NAME = MPIABI_MAX_PROCESSOR_NAME)

      logical MPI_ASYNC_PROTECTS_NONBLOCKING
      parameter (MPI_ASYNC_PROTECTS_NONBLOCKING = .false.)
      logical MPI_SUBARRAYS_SUPPORTED
      parameter (MPI_SUBARRAYS_SUPPORTED = .false.)

      integer MPI_ADDRESS_KIND
      parameter (MPI_ADDRESS_KIND = MPITRAMPOLINE_SIZEOF_CPTRDIFF_T)
      integer MPI_COUNT_KIND
      parameter (MPI_COUNT_KIND = 8)
      integer MPI_INTEGER_KIND
      parameter (MPI_INTEGER_KIND = 4)
      integer MPI_OFFSET_KIND
      parameter (MPI_OFFSET_KIND = 8)

      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = MPIABI_STATUS_SIZE)

!     Sentinel values
      
!     Option 1 to handle sentinel values:
!
!     Define copies here in MPItrampoline, and convert them using
!     explicit comparisons in the C wrapper functions here in
!     MPItrampoline.

      character(1) MPI_ARGV_NULL(1)
      common /MPI_ARGV_NULL/ MPI_ARGV_NULL
      character(1) MPI_ARGVS_NULL(1, 1)
      common /MPI_ARGVS_NULL/ MPI_ARGVS_NULL

      integer MPI_BOTTOM
      common /MPI_BOTTOM/ MPI_BOTTOM

      integer MPI_IN_PLACE
      common /MPI_IN_PLACE/

      integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
      common /MPI_STATUS_IGNORE/ MPI_STATUS_IGNORE
      integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
      common /MPI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE

      integer MPI_UNWEIGHTED(1)
      common /MPI_UNWEIGHTED/ MPI_UNWEIGHTED

!     Option 2 to handle sentinel values:

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

!     Most constants and functions

      include "mpi_decl_constants_fortran.h"
      include "mpi_decl_functions_fortran.h"
