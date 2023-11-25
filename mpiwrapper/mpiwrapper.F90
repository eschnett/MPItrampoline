#include "mpiwrapper.h"
  
! Work around a bug in MPICH 4.1.4 <https://github.com/pmodels/mpich/issues/6807>
#ifndef HAVE_FORTRAN_MPI_SESSION_NULL
! This is only valid for MPICH
#define MPI_SESSION_NULL 939524096
#endif

module mpiwrapper
  ! use mpi
  implicit none
  include "mpif.h"
  include "mpiabif_constants.h"
  public
contains

  ! Error handling

  subroutine assert(cond)
    logical, intent(in) :: cond
    integer ierror
    if (cond) return
    write(0, '("Assertion failure")')
    call MPI_Abort(MPI_COMM_SELF, 1, ierror)
    stop
  end subroutine assert

  ! Translate (non-handle) integers

  elemental integer function mpi2abi_errorcode(ierror)
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

  integer function abi2mpi_proc(proc)
    integer, intent(in) :: proc
    select case (proc)
    case (MPIABI_ANY_SOURCE)
       abi2mpi_proc = MPI_ANY_SOURCE
    case (MPIABI_PROC_NULL)
       abi2mpi_proc = MPI_PROC_NULL
    case default
       call assert(proc >= 0)
       abi2mpi_proc = proc
    end select
  end function abi2mpi_proc

  integer function mpi2abi_proc(proc)
    integer, intent(in) :: proc
    select case (proc)
    case (MPI_ANY_SOURCE)
       mpi2abi_proc = MPIABI_ANY_SOURCE
    case (MPI_PROC_NULL)
       mpi2abi_proc = MPIABI_PROC_NULL
    case default
       call assert(proc >= 0)
       mpi2abi_proc = proc
    end select
  end function mpi2abi_proc

  elemental integer function abi2mpi_root(root)
    integer, intent(in) :: root
    select case (root)
    case (MPIABI_ROOT)
       abi2mpi_root = MPI_ROOT
    case default
       abi2mpi_root = root
    end select
  end function abi2mpi_root

  elemental integer function abi2mpi_source(source)
    integer, intent(in) :: source
    select case (source)
    case (MPIABI_ANY_SOURCE)
       abi2mpi_source = MPI_ANY_SOURCE
    case default
       abi2mpi_source = source
    end select
  end function abi2mpi_source

  elemental integer function abi2mpi_tag(tag)
    integer, intent(in) ::tag
    select case (tag)
    case (MPIABI_ANY_TAG)
       abi2mpi_tag = MPI_ANY_TAG
    case default
       abi2mpi_tag = tag
    end select
  end function abi2mpi_tag

  elemental integer function mpi2abi_tag(tag)
    integer, intent(in) ::tag
    select case (tag)
    case (MPI_ANY_TAG)
       mpi2abi_tag = MPIABI_ANY_TAG
    case default
       mpi2abi_tag = tag
    end select
  end function mpi2abi_tag

  integer function abi2mpi_threadlevel(threadlevel)
    integer, intent(in) ::threadlevel
    select case (threadlevel)
    case (MPIABI_THREAD_FUNNELED)
       abi2mpi_threadlevel = MPI_THREAD_FUNNELED
    case (MPIABI_THREAD_MULTIPLE)
       abi2mpi_threadlevel = MPI_THREAD_MULTIPLE
    case (MPIABI_THREAD_SERIALIZED)
       abi2mpi_threadlevel = MPI_THREAD_SERIALIZED
    case (MPIABI_THREAD_SINGLE)
       abi2mpi_threadlevel = MPI_THREAD_SINGLE;
    case default
       call assert(.false.)
    end select
  end function abi2mpi_threadlevel

  ! Translate addresses

  integer(MPI_ADDRESS_KIND) function abi2mpi_buffer_ptr(buffer_ptr)
    integer(MPIABI_ADDRESS_KIND), intent(in) :: buffer_ptr
    if (buffer_ptr == loc(MPIABI_IN_PLACE)) then
       abi2mpi_buffer_ptr = loc(MPI_IN_PLACE)
       return
    end if
    abi2mpi_buffer_ptr = buffer_ptr
  end function abi2mpi_buffer_ptr

  integer(MPIABI_ADDRESS_KIND) function mpi2abi_buffer_ptr(buffer_ptr)
    integer(MPI_ADDRESS_KIND), intent(in) :: buffer_ptr
    if (buffer_ptr == loc(MPI_IN_PLACE)) then
       mpi2abi_buffer_ptr = loc(MPIABI_IN_PLACE)
       return
    end if
    mpi2abi_buffer_ptr = buffer_ptr
  end function mpi2abi_buffer_ptr

  ! Translate handles

  elemental integer function abi2mpi_comm(comm)
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

  elemental integer function abi2mpi_datatype(datatype)
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

  elemental integer function abi2mpi_info(info)
    integer, intent(in) :: info
    select case (info)
    case (MPIABI_INFO_ENV)
       abi2mpi_info = MPI_INFO_ENV
    case (MPIABI_INFO_NULL)
       abi2mpi_info = MPI_INFO_NULL
    case default
       abi2mpi_info = info
    end select
  end function abi2mpi_info

  elemental integer function abi2mpi_message(message)
    integer, intent(in) :: message
    select case (message)
    case (MPIABI_MESSAGE_NO_PROC)
       abi2mpi_message = MPI_MESSAGE_NO_PROC
    case (MPIABI_MESSAGE_NULL)
       abi2mpi_message = MPI_MESSAGE_NULL
    case default
       abi2mpi_message = message
    end select
  end function abi2mpi_message

  elemental integer function abi2mpi_request(request)
    integer, intent(in) :: request
    if (request == MPI_REQUEST_NULL) then
       abi2mpi_request = MPIABI_REQUEST_NULL
       return
    end if
    abi2mpi_request = request
  end function abi2mpi_request

  elemental integer function mpi2abi_request(request)
    integer, intent(in) :: request
    if (request == MPIABI_REQUEST_NULL) then
       mpi2abi_request = MPI_REQUEST_NULL
       return
    end if
    mpi2abi_request = request
  end function mpi2abi_request

  elemental integer function abi2mpi_session(session)
    integer, intent(in) :: session
    select case (session)
    case (MPIABI_SESSION_NULL)
       abi2mpi_session = MPI_SESSION_NULL
    case default
       abi2mpi_session = session
    end select
  end function abi2mpi_session

  ! Translate statuses

  subroutine abi2mpi_status(abi_status, mpi_status)
    integer, intent(in) :: abi_status(MPIABI_STATUS_SIZE)
    integer, intent(out) :: mpi_status(MPI_STATUS_SIZE)
    integer :: src, dest
    mpi_status(MPI_SOURCE) = abi_status(MPIABI_SOURCE)
    mpi_status(MPI_TAG) = abi_status(MPIABI_TAG)
    mpi_status(MPI_ERROR) = abi_status(MPIABI_ERROR)
    src = 4
    do dest = 1, MPI_STATUS_SIZE
       if (src /= MPI_SOURCE .and. src /= MPI_TAG .and. src /= MPI_ERROR) then
          mpi_status(dest) = abi_status(src)
          src = src + 1
       end if
    end do
  end subroutine abi2mpi_status

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

  integer(MPI_ADDRESS_KIND) function abi2mpi_status_ptr_uninitialized(abi_status, mpi_status_storage)
    integer, intent(in) :: abi_status(MPIABI_STATUS_SIZE)
    integer, intent(in) :: mpi_status_storage(MPI_STATUS_SIZE)
    if (loc(abi_status) == loc(MPIABI_STATUS_IGNORE)) then
       abi2mpi_status_ptr_uninitialized = loc(MPI_STATUS_IGNORE)
    else
       abi2mpi_status_ptr_uninitialized = loc(mpi_status_storage)
    end if
  end function abi2mpi_status_ptr_uninitialized

  subroutine mpi2abi_status_ptr(mpi_status, abi_status)
    integer, intent(in) :: mpi_status(MPI_STATUS_SIZE)
    integer, intent(out) :: abi_status(MPIABI_STATUS_SIZE)
    if (loc(abi_status) == loc(MPIABI_STATUS_IGNORE)) return
    call mpi2abi_status(mpi_status, abi_status)
  end subroutine mpi2abi_status_ptr

end module mpiwrapper
