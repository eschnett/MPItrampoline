!     These constants must be compatible with the respective C
!     declarations. The string size constants need to be one less than
!     in C since Fortran does not store a trailing NUL character.

      include "mpif_version.h"

      integer MPIABI_VERSION_MAJOR
      parameter (MPIABI_VERSION_MAJOR = 2)
      integer MPIABI_VERSION_MINOR
      parameter (MPIABI_VERSION_MINOR = 6)
      integer MPIABI_VERSION_PATCH
      parameter (MPIABI_VERSION_PATCH = 0)

      integer MPI_VERSION
      parameter (MPI_VERSION = 3)
      integer MPI_SUBVERSION
      parameter (MPI_SUBVERSION = 1)

      integer MPI_MAX_DATAREP_STRING
      parameter (MPI_MAX_DATAREP_STRING = 127)
      integer MPI_MAX_ERROR_STRING
      parameter (MPI_MAX_ERROR_STRING = 1023)
      integer MPI_MAX_INFO_KEY
      parameter (MPI_MAX_INFO_KEY = 255)
      integer MPI_MAX_INFO_VAL
      parameter (MPI_MAX_INFO_VAL = 1023)
      integer MPI_MAX_LIBRARY_VERSION_STRING
      parameter (MPI_MAX_LIBRARY_VERSION_STRING = 8191)
      integer MPI_MAX_OBJECT_NAME
      parameter (MPI_MAX_OBJECT_NAME = 127)
      integer MPI_MAX_PORT_NAME
      parameter (MPI_MAX_PORT_NAME = 1023)
      integer MPI_MAX_PROCESSOR_NAME
      parameter (MPI_MAX_PROCESSOR_NAME = 255)

      logical MPI_ASYNC_PROTECTS_NONBLOCKING
      parameter (MPI_ASYNC_PROTECTS_NONBLOCKING = .false.)
      logical MPI_SUBARRAYS_SUPPORTED
      parameter (MPI_SUBARRAYS_SUPPORTED = .false.)

      integer MPI_ADDRESS_KIND
      parameter (MPI_ADDRESS_KIND = MPITRAMPOLINE_SIZEOF_CPTRDIFF_T)
      integer MPI_COUNT_KIND
      parameter (MPI_COUNT_KIND = 8)
      integer MPI_OFFSET_KIND
      parameter (MPI_OFFSET_KIND = 8)

      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = 6)
