module mpiwrapper
  implicit none
  include "mpif.h"
  include "mpiabif_constants.h"
  public
contains

  integer function abi2mpi_comm(comm)
    integer, intent(in) :: comm
    select case (comm)
    case (MPIABI_COMM_NULL)
       abi2mpi_comm = MPI_COMM_NULL
    case (MPIABI_COMM_SELF)
       abi2mpi_comm = MPI_COMM_SELF
    case (MPIABI_COMM_WORLD)
       abi2mpi_comm = MPI_COMM_WORLD
    case default
       abi2mpi_comm = comm
    end select
  end function abi2mpi_comm

  integer function abi2mpi_datatype(datatype)
    integer, intent(in) :: datatype
    select case (datatype)
    case (MPIABI_DATATYPE_NULL)
       abi2mpi_datatype = MPI_DATATYPE_NULL
    case (MPIABI_INTEGER)
       abi2mpi_datatype = MPI_INTEGER
       ! TODO: more types
    case default
       abi2mpi_datatype = datatype
    end select
  end function abi2mpi_datatype

  subroutine mpi2abi_status(mpi_status, abi_status)
    integer, intent(in) :: mpi_status(MPI_STATUS_SIZE)
    integer, intent(out) :: abi_status(MPIABI_STATUS_SIZE)
    integer :: src, dest
    abi_status(MPIABI_SOURCE) = mpi_status(MPI_SOURCE)
    abi_status(MPIABI_TAG) = mpi_status(MPI_TAG)
    abi_status(MPIABI_ERROR) = mpi_status(MPI_ERROR)
    dest = 4
    do src = 1, MPI_STATUS_SIZE
       if (src /= MPI_SOURCE .and. src /= MPI_TAG .and. src /= MPI_ERROR) then
          abi_status(dest) = mpi_status(src)
          dest = dest + 1
       end if
    end do
  end subroutine mpi2abi_status

  integer(MPI_ADDRESS_KIND) function abi2mpi_statusptr_uninitialized(abi_status, mpi_status_storage)
    integer, intent(in) :: abi_status(MPIABI_STATUS_SIZE)
    integer, intent(in) :: mpi_status_storage(MPI_STATUS_SIZE)
    if (loc(abi_status) == loc(MPIABI_STATUS_IGNORE)) then
       abi2mpi_statusptr_uninitialized = loc(MPI_STATUS_IGNORE)
    else
       abi2mpi_statusptr_uninitialized = loc(mpi_status_storage)
    end if
  end function abi2mpi_statusptr_uninitialized

  subroutine mpi2abi_statusptr(mpi_status, abi_status)
    integer, intent(in) :: mpi_status(MPI_STATUS_SIZE)
    integer, intent(out) :: abi_status(MPIABI_STATUS_SIZE)
    if (loc(abi_status) == loc(MPIABI_STATUS_IGNORE)) return
    call mpi2abi_status(mpi_status, abi_status)
  end subroutine mpi2abi_statusptr

  integer function mpi2abi_errorcode(ierror)
    integer, intent(in) :: ierror
    ! Fast path
    if (ierror == MPI_SUCCESS) then
       mpi2abi_errorcode = MPIABI_SUCCESS
       return
    end if
    select case (ierror)
    ! TODO: translate codes
    case default
       mpi2abi_errorcode = ierror
    end select
  end function mpi2abi_errorcode

  integer function abi2mpi_source(source)
    integer, intent(in) :: source
    select case (source)
    case (MPIABI_ANY_SOURCE)
       abi2mpi_source = MPI_ANY_SOURCE
    case default
       abi2mpi_source = source
    end select
  end function abi2mpi_source

  integer function abi2mpi_tag(tag)
    integer, intent(in) ::tag
    select case (tag)
    case (MPIABI_ANY_TAG)
       abi2mpi_tag = MPI_ANY_TAG
    case default
       abi2mpi_tag = tag
    end select
  end function abi2mpi_tag

end module mpiwrapper
