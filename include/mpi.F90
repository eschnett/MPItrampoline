module mpi
  implicit none
  public
  save

  include "mpif_version.h"
  include "mpiabif.h"

  integer, parameter :: MPI_VERSION = MPIABI_MPI_VERSION
  integer, parameter :: MPI_SUBVERSION = MPIABI_MPI_SUBVERSION

  integer, parameter :: MPI_MAX_DATAREP_STRING = MPIABI_MAX_DATAREP_STRING
  integer, parameter :: MPI_MAX_ERROR_STRING = MPIABI_MAX_ERROR_STRING
  integer, parameter :: MPI_MAX_INFO_KEY = MPIABI_MAX_INFO_KEY
  integer, parameter :: MPI_MAX_INFO_VAL = MPIABI_MAX_INFO_VAL
  integer, parameter :: MPI_MAX_LIBRARY_VERSION_STRING = MPIABI_MAX_LIBRARY_VERSION_STRING
  integer, parameter :: MPI_MAX_OBJECT_NAME = MPIABI_MAX_OBJECT_NAME
  integer, parameter :: MPI_MAX_PORT_NAME = MPIABI_MAX_PORT_NAME
  integer, parameter :: MPI_MAX_PROCESSOR_NAME = MPIABI_MAX_PROCESSOR_NAME

  logical, parameter :: MPI_ASYNC_PROTECTS_NONBLOCKING = .false.
  logical, parameter :: MPI_SUBARRAYS_SUPPORTED = .false.

  integer, parameter :: MPI_ADDRESS_KIND = MPIABI_ADDRESS_KIND
  integer, parameter :: MPI_COUNT_KIND = MPIABI_COUNT_KIND
  integer, parameter :: MPI_INTEGER_KIND = MPIABI_INTEGER_KIND
  integer, parameter :: MPI_OFFSET_KIND = MPIABI_OFFSET_KIND

  integer, parameter :: MPI_STATUS_SIZE = MPIABI_STATUS_SIZE

  ! character(1) MPI_ARGV_NULL(1)
  ! common /MPIABI_ARGV_NULL/ MPI_ARGV_NULL
  ! character(1) MPI_ARGVS_NULL(1, 1)
  ! common /MPIABI_ARGVS_NULL/ MPI_ARGVS_NULL
  ! 
  ! integer MPI_BOTTOM
  ! common /MPIABI_BOTTOM/ MPI_BOTTOM
  ! 
  ! integer MPI_ERRCODES_IGNORE(1)
  ! common /MPIABI_ERRCODES_IGNORE/ MPI_ERRCODES_IGNORE
  ! 
  ! integer MPI_IN_PLACE
  ! common /MPIABI_IN_PLACE/ MPI_IN_PLACE
  ! 
  ! integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
  ! common /MPIABI_STATUS_IGNORE/ MPI_STATUS_IGNORE
  ! integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
  ! common /MPIABI_STATUSES_IGNORE/ MPI_STATUSES_IGNORE
  ! 
  ! integer MPI_UNWEIGHTED(1)
  ! common /MPIABI_UNWEIGHTED/ MPI_UNWEIGHTED
  ! 
  ! integer MPI_WEIGHTS_EMPTY(1)
  ! common /MPIABI_WEIGHTS_EMPTY/ MPI_WEIGHTS_EMPTY

  character(1) MPI_ARGV_NULL(1)
  integer(MPI_ADDRESS_KIND), private :: MPI_ARGV_NULL_PTR
  pointer (MPI_ARGV_NULL_PTR, MPI_ARGV_NULL)
  common /MPIABI_ARGV_NULL_PTR/ MPI_ARGV_NULL_PTR

  character(1) MPI_ARGVS_NULL(1, 1)
  integer(MPI_ADDRESS_KIND), private :: MPI_ARGVS_NULL_PTR
  pointer (MPI_ARGVS_NULL_PTR, MPI_ARGVS_NULL)
  common /MPIABI_ARGVS_NULL_PTR/ MPI_ARGVS_NULL_PTR
 
  integer MPI_BOTTOM
  integer(MPI_ADDRESS_KIND), private :: MPI_BOTTOM_PTR
  pointer (MPI_BOTTOM_PTR, MPI_BOTTOM)
  common /MPIABI_BOTTOM_PTR/ MPI_BOTTOM_PTR

  integer MPI_ERRCODES_IGNORE(1)
  integer(MPI_ADDRESS_KIND), private :: MPI_ERRCODES_IGNORE_PTR
  pointer (MPI_ERRCODES_IGNORE_PTR, MPI_ERRCODES_IGNORE)
  common /MPIABI_ERRCODES_IGNORE_PTR/ MPI_ERRCODES_IGNORE_PTR
 
  integer MPI_IN_PLACE
  integer(MPI_ADDRESS_KIND) MPI_IN_PLACE_PTR
  pointer (MPI_IN_PLACE_PTR, MPI_IN_PLACE)
  common /MPIABI_IN_PLACE_PTR/ MPI_IN_PLACE_PTR

  integer MPI_STATUS_IGNORE(MPI_STATUS_SIZE)
  integer(MPI_ADDRESS_KIND), private :: MPI_STATUS_IGNORE_PTR
  pointer (MPI_STATUS_IGNORE_PTR, MPI_STATUS_IGNORE)
  common /MPIABI_STATUS_IGNORE_PTR/ MPI_STATUS_IGNORE_PTR
 
  integer MPI_STATUSES_IGNORE(MPI_STATUS_SIZE, 1)
  integer(MPI_ADDRESS_KIND), private :: MPI_STATUSES_IGNORE_PTR
  pointer (MPI_STATUSES_IGNORE_PTR, MPI_STATUSES_IGNORE)
  common /MPIABI_STATUSES_IGNORE_PTR/ MPI_STATUSES_IGNORE_PTR

  integer MPI_UNWEIGHTED(1)
  integer(MPI_ADDRESS_KIND), private :: MPI_UNWEIGHTED_PTR
  pointer (MPI_UNWEIGHTED_PTR, MPI_UNWEIGHTED)
  common /MPIABI_UNWEIGHTED_PTR/ MPI_UNWEIGHTED_PTR
 
  integer MPI_WEIGHTS_EMPTY(1)
  integer(MPI_ADDRESS_KIND), private :: MPI_WEIGHTS_EMPTY_PTR
  pointer (MPI_WEIGHTS_EMPTY_PTR, MPI_WEIGHTS_EMPTY)
  common /MPIABI_WEIGHTS_EMPTY_PTR/ MPI_WEIGHTS_EMPTY_PTR

  include "mpi_decl_constants_fortran.h"

  interface
     subroutine mpi_send(buf, count, datatype, dest, tag, comm, ierror)
       implicit none
       !dir$ ignore_tkr(tkr) buf
       GCC_ATTRIBUTES_NO_ARG_CHECK !gcc$ attributes no_arg_check :: buf
       integer, intent(in) :: buf(*)
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: dest
       integer, intent(in) :: tag
       integer, intent(in) :: comm
       integer, intent(out) :: ierror
     end subroutine mpi_send

     subroutine mpi_recv(buf, count, datatype, source, tag, comm, status, ierror)
       import mpi_status_size
       implicit none
       GCC_ATTRIBUTES_NO_ARG_CHECK !gcc$ attributes no_arg_check :: buf
       integer :: buf(*)
       integer, intent(in) :: count
       integer, intent(in) :: datatype
       integer, intent(in) :: source
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
