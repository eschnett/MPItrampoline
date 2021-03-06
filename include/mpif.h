      include "mpif_version.h"
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
      parameter (MPI_ADDRESS_KIND = MPIABI_ADDRESS_KIND)
      integer MPI_COUNT_KIND
      parameter (MPI_COUNT_KIND = MPIABI_COUNT_KIND)
      integer MPI_INTEGER_KIND
      parameter (MPI_INTEGER_KIND = MPIABI_INTEGER_KIND)
      integer MPI_OFFSET_KIND
      parameter (MPI_OFFSET_KIND = MPIABI_OFFSET_KIND)

      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = MPIABI_STATUS_SIZE)

!     Sentinel values
      
!     Option 1 to handle sentinel values:
!
!     Define copies here in MPItrampoline, and convert them using
!     explicit comparisons in the C wrapper functions here in
!     MPItrampoline.

!     character(1) MPI_ARGV_NULL(1)
!     common /MPIABI_ARGV_NULL/ MPI_ARGV_NULL
!     character(1) MPI_ARGVS_NULL(1, 1)
!     common /MPIABI_ARGVS_NULL/ MPI_ARGVS_NULL
!
!     integer MPI_BOTTOM
!     common /MPIABI_BOTTOM/ MPI_BOTTOM
!
!     integer MPI_ERRCODES_IGNORE(1)
!     common /MPIABI_ERRCODES_IGNORE/ MPI_ERRCODES_IGNORE
!
!     integer MPI_IN_PLACE
!     common /MPIABI_IN_PLACE/ MPI_IN_PLACE
!
!     integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
!     common /MPIABI_STATUS_IGNORE/ MPI_STATUS_IGNORE
!     integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
!     common /MPIABI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE
!
!     integer MPI_UNWEIGHTED(1)
!     common /MPIABI_UNWEIGHTED/ MPI_UNWEIGHTED
!
!     integer MPI_WEIGHTS_EMPTY(1)
!     common /MPIABI_WEIGHTS_EMPTY/ MPI_WEIGHTS_EMPTY

!     Option 2 to handle sentinel values:

!     Use Cray pointers. Unfortunately, these might not be supported
!     everywhere, and if they are, they require special compiler
!     options.

      character(1) MPI_ARGV_NULL(1)
      integer(MPI_ADDRESS_KIND) MPI_ARGV_NULL_PTR
      pointer (MPI_ARGV_NULL_PTR, MPI_ARGV_NULL)
      common /MPIABI_ARGV_NULL_PTR/ MPI_ARGV_NULL_PTR

      character(1) MPI_ARGVS_NULL(1, 1)
      integer(MPI_ADDRESS_KIND) MPI_ARGVS_NULL_PTR
      pointer (MPI_ARGVS_NULL_PTR, MPI_ARGVS_NULL)
      common /MPIABI_ARGVS_NULL_PTR/ MPI_ARGVS_NULL_PTR
 
      integer MPI_BOTTOM
      integer(MPI_ADDRESS_KIND) MPI_BOTTOM_PTR
      pointer (MPI_BOTTOM_PTR, MPI_BOTTOM)
      common /MPIABI_BOTTOM_PTR/ MPI_BOTTOM_PTR
 
      integer MPI_ERRCODES_IGNORE(1)
      integer(MPI_ADDRESS_KIND) MPI_ERRCODES_IGNORE_PTR
      pointer (MPI_ERRCODES_IGNORE_PTR, MPI_ERRCODES_IGNORE)
      common /MPIABI_ERRCODES_IGNORE_PTR/ MPI_ERRCODES_IGNORE_PTR
 
      integer MPI_IN_PLACE
      integer(MPI_ADDRESS_KIND) MPI_IN_PLACE_PTR
      pointer (MPI_IN_PLACE_PTR, MPI_IN_PLACE)
      common /MPIABI_IN_PLACE_PTR/ MPI_IN_PLACE_PTR

      integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
      integer(MPI_ADDRESS_KIND) MPI_STATUS_IGNORE_PTR
      pointer (MPI_STATUS_IGNORE_PTR, MPI_STATUS_IGNORE)
      common /MPIABI_STATUS_IGNORE_PTR/ MPI_STATUS_IGNORE_PTR
 
      integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
      integer(MPI_ADDRESS_KIND) MPI_STATUSES_IGNORE_PTR
      pointer (MPI_STATUSES_IGNORE_PTR, MPI_STATUSES_IGNORE)
      common /MPIABI_STATUSES_IGNORE_PTR/ MPI_STATUSES_IGNORE_PTR

      integer MPI_UNWEIGHTED(1)
      integer(MPI_ADDRESS_KIND) MPI_UNWEIGHTED_PTR
      pointer (MPI_UNWEIGHTED_PTR, MPI_UNWEIGHTED)
      common /MPIABI_UNWEIGHTED_PTR/ MPI_UNWEIGHTED_PTR
 
      integer MPI_WEIGHTS_EMPTY(1)
      integer(MPI_ADDRESS_KIND) MPI_WEIGHTS_EMPTY_PTR
      pointer (MPI_WEIGHTS_EMPTY_PTR, MPI_WEIGHTS_EMPTY)
      common /MPIABI_WEIGHTS_EMPTY_PTR/ MPI_WEIGHTS_EMPTY_PTR

!     Option 3 to handle sentinel values:
!
!     Use Fortran pointers. Unfortunately, pointers to arrays cannot
!     have a fixed size, and accessing the pointer requires a run-time
!     check whether the array is contiguous. This might make a copy, and
!     thus the sentinel doesn't actually work.

!     TODO: try this with "CONTIGUOUS" attribute

!     integer MPI_STATUS_IGNORE(:)
!     pointer MPI_STATUS_IGNORE
!     common /MPIABI_STATUS_IGNORE/ MPI_STATUS_IGNORE
!
!     integer MPI_STATUSES_IGNORE(:)
!     pointer MPI_STATUSES_IGNORE
!     common /MPIABI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE

!     Most constants and functions

      include "mpi_decl_constants_fortran.h"
      include "mpi_decl_functions_fortran.h"
