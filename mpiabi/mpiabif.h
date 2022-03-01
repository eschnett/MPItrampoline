!     These constants must be compatible with the respective C
!     declarations. The string size constants need to be one less than
!     in C since Fortran does not store a trailing NUL character.

!     TODO: Move this file to MPIwrapper, changing the prefix to
!     `MPIABI_`.

      include "mpif_version.h"

      integer MPIABI_VERSION_MAJOR
      parameter (MPIABI_VERSION_MAJOR = 2)
      integer MPIABI_VERSION_MINOR
      parameter (MPIABI_VERSION_MINOR = 6)
      integer MPIABI_VERSION_PATCH
      parameter (MPIABI_VERSION_PATCH = 0)

      integer MPIABI_MPI_VERSION
      parameter (MPIABI_MPI_VERSION = 3)
      integer MPIABI_MPI_SUBVERSION
      parameter (MPIABI_MPI_SUBVERSION = 1)

      integer MPIABI_MAX_DATAREP_STRING
      parameter (MPIABI_MAX_DATAREP_STRING = 127)
      integer MPIABI_MAX_ERROR_STRING
      parameter (MPIABI_MAX_ERROR_STRING = 1023)
      integer MPIABI_MAX_INFO_KEY
      parameter (MPIABI_MAX_INFO_KEY = 255)
      integer MPIABI_MAX_INFO_VAL
      parameter (MPIABI_MAX_INFO_VAL = 1023)
      integer MPIABI_MAX_LIBRARY_VERSION_STRING
      parameter (MPIABI_MAX_LIBRARY_VERSION_STRING = 8191)
      integer MPIABI_MAX_OBJECT_NAME
      parameter (MPIABI_MAX_OBJECT_NAME = 127)
      integer MPIABI_MAX_PORT_NAME
      parameter (MPIABI_MAX_PORT_NAME = 1023)
      integer MPIABI_MAX_PROCESSOR_NAME
      parameter (MPIABI_MAX_PROCESSOR_NAME = 255)

      logical MPIABI_ASYNC_PROTECTS_NONBLOCKING
      parameter (MPIABI_ASYNC_PROTECTS_NONBLOCKING = .false.)
      logical MPIABI_SUBARRAYS_SUPPORTED
      parameter (MPIABI_SUBARRAYS_SUPPORTED = .false.)

      integer MPIABI_ADDRESS_KIND
      parameter (MPIABI_ADDRESS_KIND = MPITRAMPOLINE_SIZEOF_CPTRDIFF_T)
      integer MPIABI_COUNT_KIND
      parameter (MPIABI_COUNT_KIND = 8)
      integer MPIABI_OFFSET_KIND
      parameter (MPIABI_OFFSET_KIND = 8)

      integer MPIABI_STATUS_SIZE
      parameter (MPIABI_STATUS_SIZE = 6)
