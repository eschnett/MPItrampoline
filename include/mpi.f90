module mpi
  implicit none
  save

  include "mpiabif.h"

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
  parameter (MPI_MAX_LIBRARY_VERSION_STRING = MPIABI_MAX_LIBRARY_VERSION_STRING)
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
  integer MPI_OFFSET_KIND
  parameter (MPI_OFFSET_KIND = 8)

  integer MPI_STATUS_SIZE
  parameter (MPI_STATUS_SIZE = MPIABI_STATUS_SIZE)

  character(1) MPI_ARGV_NULL(1)
  common /MPI_ARGV_NULL/ MPI_ARGV_NULL
  character(1) MPI_ARGVS_NULL(1, 1)
  common /MPI_ARGVS_NULL/ MPI_ARGVS_NULL

  integer MPI_BOTTOM
  common /MPI_BOTTOM/ MPI_BOTTOM

  integer MPI_IN_PLACE
  common /MPI_IN_PLACE/ MPI_IN_PLACE

  integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
  common /MPI_STATUS_IGNORE/ MPI_STATUS_IGNORE
  integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
  common /MPI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE

  integer MPI_UNWEIGHTED(1)
  common /MPI_UNWEIGHTED/ MPI_UNWEIGHTED

  include "mpi_decl_constants_fortran.h"

  ! TOOD: Define types for handles, as in `mpi_f08`

  interface
     subroutine mpi_send(buf, count, datatype, dest, tag, comm, ierror)
       implicit none
       !gcc$ attributes no_arg_check :: buf
       type(*), intent(in) :: buf(*)
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       integer, intent(in) :: comm
       integer, intent(out) :: ierror
     end subroutine mpi_send

     subroutine mpi_recv(buf, count, datatype, dest, tag, comm, status, ierror)
       import mpi_status_size
       implicit none
       !gcc$ attributes no_arg_check :: buf
       integer :: buf(*)
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       integer, intent(in) :: comm
       integer, intent(out) :: status(mpi_status_size)
       integer, intent(out) :: ierror
     end subroutine mpi_recv

     subroutine mpi_get_count(status, datatype, count, ierror)
       import mpi_status_size
       implicit none
       integer, intent(in) :: status(mpi_status_size)
       integer, intent(in) :: datatype
       integer, intent(out) :: count
       integer, intent(out) :: ierror
     end subroutine mpi_get_count

     subroutine mpi_comm_size(comm, size, ierror)
       implicit none
       integer, intent(in) :: comm
       integer, intent(out) :: size
       integer, intent(out) :: ierror
     end subroutine mpi_comm_size

     subroutine mpi_comm_rank(comm, rank, ierror)
       implicit none
       integer, intent(in) :: comm
       integer, intent(out) :: rank
       integer, intent(out) :: ierror
     end subroutine mpi_comm_rank

     subroutine mpi_init(ierror)
       implicit none
       integer, intent(out) :: ierror
     end subroutine mpi_init

     subroutine mpi_finalize(ierror)
       implicit none
       integer, intent(out) :: ierror
     end subroutine mpi_finalize

     subroutine mpi_abort(comm, errorcode, ierror)
       implicit none
       integer, intent(in) :: comm
       integer, intent(in) :: errorcode
       integer, intent(out) :: ierror
     end subroutine mpi_abort

     double precision function mpi_wtime()
       implicit none
     end function mpi_wtime

     double precision function mpi_wtick()
       implicit none
     end function mpi_wtick
  end interface

end module mpi
