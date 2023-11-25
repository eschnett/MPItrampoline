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

  integer, parameter :: MAX_RESERVED_HANDLE = int(b'111111111111')

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

  ! Conversions between MPI and MPIABI

  logical function handle_is_reserved(abi_handle)
    integer, intent(in) :: abi_handle
    handle_is_reserved = abi_handle <= MAX_RESERVED_HANDLE
  end function handle_is_reserved
  integer function abi2mpi_unreserved(abi_handle)
    integer, intent(in) :: abi_handle
    integer mpi_handle
    call assert(.not.handle_is_reserved(abi_handle))
    mpi_handle = abi_handle - (MAX_RESERVED_HANDLE + 1)
    abi2mpi_unreserved = mpi_handle
  end function abi2mpi_unreserved
  integer function mpi2abi_unreserved(mpi_handle)
    integer, intent(in) :: mpi_handle
    integer abi_handle
    abi_handle = mpi_handle + (MAX_RESERVED_HANDLE + 1)
    call assert(.not.handle_is_reserved(abi_handle))
    mpi2abi_unreserved = abi_handle
  end function mpi2abi_unreserved

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
       abi2mpi_threadlevel = MPI_THREAD_SINGLE
    case default
       call assert(.false.)
    end select
  end function abi2mpi_threadlevel

  integer function mpi2abi_threadlevel(threadlevel)
    integer, intent(in) ::threadlevel
    select case (threadlevel)
    case (MPI_THREAD_FUNNELED)
       mpi2abi_threadlevel = MPIABI_THREAD_FUNNELED
    case (MPI_THREAD_MULTIPLE)
       mpi2abi_threadlevel = MPIABI_THREAD_MULTIPLE
    case (MPI_THREAD_SERIALIZED)
       mpi2abi_threadlevel = MPIABI_THREAD_SERIALIZED
    case (MPI_THREAD_SINGLE)
       mpi2abi_threadlevel = MPIABI_THREAD_SINGLE
    case default
       call assert(.false.)
    end select
  end function mpi2abi_threadlevel

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

  integer function abi2mpi_comm(comm)
    integer, intent(in) :: comm
    if (.not.handle_is_reserved(comm)) then
       abi2mpi_comm = abi2mpi_unreserved(comm)
       return
    end if
    select case (comm)
    case (MPIABI_COMM_NULL)
       abi2mpi_comm = MPI_COMM_NULL
    case (MPIABI_COMM_SELF)
       abi2mpi_comm = MPI_COMM_SELF
    case (MPIABI_COMM_WORLD)
       abi2mpi_comm = MPI_COMM_WORLD
    case default
       call assert(.false.)
    end select
  end function abi2mpi_comm

  integer function mpi2abi_comm(comm)
    integer, intent(in) :: comm
    select case (comm)
    case (MPI_COMM_NULL)
       mpi2abi_comm = MPIABI_COMM_NULL
    case (MPI_COMM_SELF)
       mpi2abi_comm = MPIABI_COMM_SELF
    case (MPI_COMM_WORLD)
       mpi2abi_comm = MPIABI_COMM_WORLD
    case default
       mpi2abi_comm = mpi2abi_unreserved(comm)
    end select
  end function mpi2abi_comm

  integer function abi2mpi_datatype(datatype)
    integer, intent(in) :: datatype
    if (.not.handle_is_reserved(datatype)) then
       abi2mpi_datatype = abi2mpi_unreserved(datatype)
       return
    end if
    select case (datatype)
    case (MPIABI_DATATYPE_NULL)
       abi2mpi_datatype = MPI_DATATYPE_NULL
       ! [C types]
    case (MPIABI_CHAR)
       abi2mpi_datatype = MPI_CHAR
    case (MPIABI_SHORT)
       abi2mpi_datatype = MPI_SHORT
    case (MPIABI_INT)
       abi2mpi_datatype = MPI_INT
    case (MPIABI_LONG)
       abi2mpi_datatype = MPI_LONG
    case (MPIABI_LONG_LONG_INT)
       abi2mpi_datatype = MPI_LONG_LONG_INT
       ! case (MPIABI_LONG_LONG)
       !   abi2mpi_datatype = MPI_LONG_LONG
    case (MPIABI_SIGNED_CHAR)
       abi2mpi_datatype = MPI_SIGNED_CHAR
    case (MPIABI_UNSIGNED_CHAR)
       abi2mpi_datatype = MPI_UNSIGNED_CHAR
    case (MPIABI_UNSIGNED_SHORT)
       abi2mpi_datatype = MPI_UNSIGNED_SHORT
    case (MPIABI_UNSIGNED)
       abi2mpi_datatype = MPI_UNSIGNED
    case (MPIABI_UNSIGNED_LONG)
       abi2mpi_datatype = MPI_UNSIGNED_LONG
    case (MPIABI_UNSIGNED_LONG_LONG)
       abi2mpi_datatype = MPI_UNSIGNED_LONG_LONG
    case (MPIABI_FLOAT)
       abi2mpi_datatype = MPI_FLOAT
    case (MPIABI_DOUBLE)
       abi2mpi_datatype = MPI_DOUBLE
    case (MPIABI_LONG_DOUBLE)
       abi2mpi_datatype = MPI_LONG_DOUBLE
    case (MPIABI_WCHAR)
       abi2mpi_datatype = MPI_WCHAR
    case (MPIABI_C_BOOL)
       abi2mpi_datatype = MPI_C_BOOL
    case (MPIABI_INT8_T)
       abi2mpi_datatype = MPI_INT8_T
    case (MPIABI_INT16_T)
       abi2mpi_datatype = MPI_INT16_T
    case (MPIABI_INT32_T)
       abi2mpi_datatype = MPI_INT32_T
    case (MPIABI_INT64_T)
       abi2mpi_datatype = MPI_INT64_T
    case (MPIABI_UINT8_T)
       abi2mpi_datatype = MPI_UINT8_T
    case (MPIABI_UINT16_T)
       abi2mpi_datatype = MPI_UINT16_T
    case (MPIABI_UINT32_T)
       abi2mpi_datatype = MPI_UINT32_T
    case (MPIABI_UINT64_T)
       abi2mpi_datatype = MPI_UINT64_T
    case (MPIABI_AINT)
       abi2mpi_datatype = MPI_AINT
    case (MPIABI_COUNT)
       abi2mpi_datatype = MPI_COUNT
    case (MPIABI_OFFSET)
       abi2mpi_datatype = MPI_OFFSET
    case (MPIABI_C_COMPLEX)
       abi2mpi_datatype = MPI_C_COMPLEX
       ! case (MPIABI_C_FLOAT_COMPLEX)
       !   abi2mpi_datatype = MPI_C_FLOAT_COMPLEX
    case (MPIABI_C_DOUBLE_COMPLEX)
       abi2mpi_datatype = MPI_C_DOUBLE_COMPLEX
    case (MPIABI_C_LONG_DOUBLE_COMPLEX)
       abi2mpi_datatype = MPI_C_LONG_DOUBLE_COMPLEX
    case (MPIABI_BYTE)
       abi2mpi_datatype = MPI_BYTE
    case (MPIABI_PACKED)
       abi2mpi_datatype = MPI_PACKED
       ! [Fortran types]
    case (MPIABI_INTEGER)
       abi2mpi_datatype = MPI_INTEGER
    case (MPIABI_REAL)
       abi2mpi_datatype = MPI_REAL
    case (MPIABI_DOUBLE_PRECISION)
       abi2mpi_datatype = MPI_DOUBLE_PRECISION
    case (MPIABI_COMPLEX)
       abi2mpi_datatype = MPI_COMPLEX
    case (MPIABI_LOGICAL)
       abi2mpi_datatype = MPI_LOGICAL
    case (MPIABI_CHARACTER)
       abi2mpi_datatype = MPI_CHARACTER
       ! [C++ types]
    case (MPIABI_CXX_BOOL)
       abi2mpi_datatype = MPI_CXX_BOOL
    case (MPIABI_CXX_FLOAT_COMPLEX)
       abi2mpi_datatype = MPI_CXX_FLOAT_COMPLEX
    case (MPIABI_CXX_DOUBLE_COMPLEX)
       abi2mpi_datatype = MPI_CXX_DOUBLE_COMPLEX
    case (MPIABI_CXX_LONG_DOUBLE_COMPLEX)
       abi2mpi_datatype = MPI_CXX_LONG_DOUBLE_COMPLEX
       ! [Optional datatypes (Fortran)]
    case (MPIABI_DOUBLE_COMPLEX)
       abi2mpi_datatype = MPI_DOUBLE_COMPLEX
#ifdef HAVE_MPI_INTEGER1
    case (MPIABI_INTEGER1)
       abi2mpi_datatype = MPI_INTEGER1
#endif
#ifdef HAVE_MPI_INTEGER2
    case (MPIABI_INTEGER2)
       abi2mpi_datatype = MPI_INTEGER2
#endif
#ifdef HAVE_MPI_INTEGER4
    case (MPIABI_INTEGER4)
       abi2mpi_datatype = MPI_INTEGER4
#endif
#ifdef HAVE_MPI_INTEGER8
    case (MPIABI_INTEGER8)
       abi2mpi_datatype = MPI_INTEGER8
#endif
#ifdef HAVE_MPI_INTEGER16
    case (MPIABI_INTEGER16)
       abi2mpi_datatype = MPI_INTEGER16
#endif
#ifdef HAVE_MPI_REAL2
    case (MPIABI_REAL2)
       abi2mpi_datatype = MPI_REAL2
#endif
#ifdef HAVE_MPI_REAL4
    case (MPIABI_REAL4)
       abi2mpi_datatype = MPI_REAL4
#endif
#ifdef HAVE_MPI_REAL8
    case (MPIABI_REAL8)
       abi2mpi_datatype = MPI_REAL8
#endif
#ifdef HAVE_MPI_REAL16
    case (MPIABI_REAL16)
       abi2mpi_datatype = MPI_REAL16
#endif
#ifdef HAVE_MPI_COMPLEX2
    case (MPIABI_COMPLEX2)
       abi2mpi_datatype = MPI_COMPLEX2
#endif
#ifdef HAVE_MPI_COMPLEX4
    case (MPIABI_COMPLEX4)
       abi2mpi_datatype = MPI_COMPLEX4
#endif
#ifdef HAVE_MPI_COMPLEX8
    case (MPIABI_COMPLEX8)
       abi2mpi_datatype = MPI_COMPLEX8
#endif
#ifdef HAVE_MPI_COMPLEX16
    case (MPIABI_COMPLEX16)
       abi2mpi_datatype = MPI_COMPLEX16
#endif
#ifdef HAVE_MPI_COMPLEX32
    case (MPIABI_COMPLEX32)
       abi2mpi_datatype = MPI_COMPLEX32
#endif
       ! [Extensions]
#ifdef HAVE_MPI_REAL1
    case (MPIABI_REAL1)
       abi2mpi_datatype = MPI_REAL1
#endif
#ifdef HAVE_MPI_LOGICAL1
    case (MPIABI_LOGICAL1)
       abi2mpi_datatype = MPI_LOGICAL1
#endif
#ifdef HAVE_MPI_LOGICAL2
    case (MPIABI_LOGICAL2)
       abi2mpi_datatype = MPI_LOGICAL2
#endif
#ifdef HAVE_MPI_LOGICAL4
    case (MPIABI_LOGICAL4)
       abi2mpi_datatype = MPI_LOGICAL4
#endif
#ifdef HAVE_MPI_LOGICAL8
    case (MPIABI_LOGICAL8)
       abi2mpi_datatype = MPI_LOGICAL8
#endif
       ! [Datatypes for reduction functions (C)]
    case (MPIABI_FLOAT_INT)
       abi2mpi_datatype = MPI_FLOAT_INT
    case (MPIABI_DOUBLE_INT)
       abi2mpi_datatype = MPI_DOUBLE_INT
    case (MPIABI_LONG_INT)
       abi2mpi_datatype = MPI_LONG_INT
    case (MPIABI_2INT)
       abi2mpi_datatype = MPI_2INT
    case (MPIABI_SHORT_INT)
       abi2mpi_datatype = MPI_SHORT_INT
    case (MPIABI_LONG_DOUBLE_INT)
       abi2mpi_datatype = MPI_LONG_DOUBLE_INT
       ! [Datatypes for reduction functions (Fortran)]
    case (MPIABI_2REAL)
       abi2mpi_datatype = MPI_2REAL
    case (MPIABI_2DOUBLE_PRECISION)
       abi2mpi_datatype = MPI_2DOUBLE_PRECISION
    case (MPIABI_2INTEGER)
       abi2mpi_datatype = MPI_2INTEGER
       ! [Removed constructs]
#ifdef HAVE_MPI_LB
    case (MPIABI_LB)
       abi2mpi_datatype = MPI_LB
#endif
#ifdef HAVE_MPI_UB
    case (MPIABI_UB)
       abi2mpi_datatype = MPI_UB
#endif
    case default
       call assert(.false.)
    end select
  end function abi2mpi_datatype

  integer function mpi2abi_datatype(datatype)
    integer, intent(in) :: datatype
    ! MPICH defines `MPI_INTEGER16` to be `MPI_DATATYPE_NULL`, and this doesn't work with a `select case` statement
    ! <https://github.com/pmodels/mpich/issues/6809>
    if (datatype == MPI_DATATYPE_NULL) then
       mpi2abi_datatype = MPIABI_DATATYPE_NULL
       return
    end if
    select case (datatype)
    ! case (MPI_DATATYPE_NULL)
    !    mpi2abi_datatype = MPIABI_DATATYPE_NULL
       ! [C types]
    case (MPI_CHAR)
       mpi2abi_datatype = MPIABI_CHAR
    case (MPI_SHORT)
       mpi2abi_datatype = MPIABI_SHORT
    case (MPI_INT)
       mpi2abi_datatype = MPIABI_INT
    case (MPI_LONG)
       mpi2abi_datatype = MPIABI_LONG
    case (MPI_LONG_LONG_INT)
       mpi2abi_datatype = MPIABI_LONG_LONG_INT
       ! case (MPI_LONG_LONG)
       !   mpi2abi_datatype = MPIABI_LONG_LONG
    case (MPI_SIGNED_CHAR)
       mpi2abi_datatype = MPIABI_SIGNED_CHAR
    case (MPI_UNSIGNED_CHAR)
       mpi2abi_datatype = MPIABI_UNSIGNED_CHAR
    case (MPI_UNSIGNED_SHORT)
       mpi2abi_datatype = MPIABI_UNSIGNED_SHORT
    case (MPI_UNSIGNED)
       mpi2abi_datatype = MPIABI_UNSIGNED
    case (MPI_UNSIGNED_LONG)
       mpi2abi_datatype = MPIABI_UNSIGNED_LONG
    case (MPI_UNSIGNED_LONG_LONG)
       mpi2abi_datatype = MPIABI_UNSIGNED_LONG_LONG
    case (MPI_FLOAT)
       mpi2abi_datatype = MPIABI_FLOAT
    case (MPI_DOUBLE)
       mpi2abi_datatype = MPIABI_DOUBLE
    case (MPI_LONG_DOUBLE)
       mpi2abi_datatype = MPIABI_LONG_DOUBLE
    case (MPI_WCHAR)
       mpi2abi_datatype = MPIABI_WCHAR
    case (MPI_C_BOOL)
       mpi2abi_datatype = MPIABI_C_BOOL
    case (MPI_INT8_T)
       mpi2abi_datatype = MPIABI_INT8_T
    case (MPI_INT16_T)
       mpi2abi_datatype = MPIABI_INT16_T
    case (MPI_INT32_T)
       mpi2abi_datatype = MPIABI_INT32_T
    case (MPI_INT64_T)
       mpi2abi_datatype = MPIABI_INT64_T
    case (MPI_UINT8_T)
       mpi2abi_datatype = MPIABI_UINT8_T
    case (MPI_UINT16_T)
       mpi2abi_datatype = MPIABI_UINT16_T
    case (MPI_UINT32_T)
       mpi2abi_datatype = MPIABI_UINT32_T
    case (MPI_UINT64_T)
       mpi2abi_datatype = MPIABI_UINT64_T
    case (MPI_AINT)
       mpi2abi_datatype = MPIABI_AINT
    case (MPI_COUNT)
       mpi2abi_datatype = MPIABI_COUNT
    case (MPI_OFFSET)
       mpi2abi_datatype = MPIABI_OFFSET
    case (MPI_C_COMPLEX)
       mpi2abi_datatype = MPIABI_C_COMPLEX
       ! case (MPI_C_FLOAT_COMPLEX)
       !   mpi2abi_datatype = MPIABI_C_FLOAT_COMPLEX
    case (MPI_C_DOUBLE_COMPLEX)
       mpi2abi_datatype = MPIABI_C_DOUBLE_COMPLEX
    case (MPI_C_LONG_DOUBLE_COMPLEX)
       mpi2abi_datatype = MPIABI_C_LONG_DOUBLE_COMPLEX
    case (MPI_BYTE)
       mpi2abi_datatype = MPIABI_BYTE
    case (MPI_PACKED)
       mpi2abi_datatype = MPIABI_PACKED
       ! [Fortran types]
    case (MPI_INTEGER)
       mpi2abi_datatype = MPIABI_INTEGER
    case (MPI_REAL)
       mpi2abi_datatype = MPIABI_REAL
    case (MPI_DOUBLE_PRECISION)
       mpi2abi_datatype = MPIABI_DOUBLE_PRECISION
    case (MPI_COMPLEX)
       mpi2abi_datatype = MPIABI_COMPLEX
    case (MPI_LOGICAL)
       mpi2abi_datatype = MPIABI_LOGICAL
    case (MPI_CHARACTER)
       mpi2abi_datatype = MPIABI_CHARACTER
       ! [C++ types]
    case (MPI_CXX_BOOL)
       mpi2abi_datatype = MPIABI_CXX_BOOL
    case (MPI_CXX_FLOAT_COMPLEX)
       mpi2abi_datatype = MPIABI_CXX_FLOAT_COMPLEX
    case (MPI_CXX_DOUBLE_COMPLEX)
       mpi2abi_datatype = MPIABI_CXX_DOUBLE_COMPLEX
    case (MPI_CXX_LONG_DOUBLE_COMPLEX)
       mpi2abi_datatype = MPIABI_CXX_LONG_DOUBLE_COMPLEX
       ! [Optional datatypes (Fortran)]
    case (MPI_DOUBLE_COMPLEX)
       mpi2abi_datatype = MPIABI_DOUBLE_COMPLEX
#ifdef HAVE_MPI_INTEGER1
    case (MPI_INTEGER1)
       mpi2abi_datatype = MPIABI_INTEGER1
#endif
#ifdef HAVE_MPI_INTEGER2
    case (MPI_INTEGER2)
       mpi2abi_datatype = MPIABI_INTEGER2
#endif
#ifdef HAVE_MPI_INTEGER4
    case (MPI_INTEGER4)
       mpi2abi_datatype = MPIABI_INTEGER4
#endif
#ifdef HAVE_MPI_INTEGER8
    case (MPI_INTEGER8)
       mpi2abi_datatype = MPIABI_INTEGER8
#endif
#ifdef HAVE_MPI_INTEGER16
    case (MPI_INTEGER16)
       mpi2abi_datatype = MPIABI_INTEGER16
#endif
#ifdef HAVE_MPI_REAL2
    case (MPI_REAL2)
       mpi2abi_datatype = MPIABI_REAL2
#endif
#ifdef HAVE_MPI_REAL4
    case (MPI_REAL4)
       mpi2abi_datatype = MPIABI_REAL4
#endif
#ifdef HAVE_MPI_REAL8
    case (MPI_REAL8)
       mpi2abi_datatype = MPIABI_REAL8
#endif
#ifdef HAVE_MPI_REAL16
    case (MPI_REAL16)
       mpi2abi_datatype = MPIABI_REAL16
#endif
#ifdef HAVE_MPI_COMPLEX2
    case (MPI_COMPLEX2)
       mpi2abi_datatype = MPIABI_COMPLEX2
#endif
#ifdef HAVE_MPI_COMPLEX4
    case (MPI_COMPLEX4)
       mpi2abi_datatype = MPIABI_COMPLEX4
#endif
#ifdef HAVE_MPI_COMPLEX8
    case (MPI_COMPLEX8)
       mpi2abi_datatype = MPIABI_COMPLEX8
#endif
#ifdef HAVE_MPI_COMPLEX16
    case (MPI_COMPLEX16)
       mpi2abi_datatype = MPIABI_COMPLEX16
#endif
#ifdef HAVE_MPI_COMPLEX32
    case (MPI_COMPLEX32)
       mpi2abi_datatype = MPIABI_COMPLEX32
#endif
       ! [Extensions]
#ifdef HAVE_MPI_REAL1
    case (MPI_REAL1)
       mpi2abi_datatype = MPIABI_REAL1
#endif
#ifdef HAVE_MPI_LOGICAL1
    case (MPI_LOGICAL1)
       mpi2abi_datatype = MPIABI_LOGICAL1
#endif
#ifdef HAVE_MPI_LOGICAL2
    case (MPI_LOGICAL2)
       mpi2abi_datatype = MPIABI_LOGICAL2
#endif
#ifdef HAVE_MPI_LOGICAL4
    case (MPI_LOGICAL4)
       mpi2abi_datatype = MPIABI_LOGICAL4
#endif
#ifdef HAVE_MPI_LOGICAL8
    case (MPI_LOGICAL8)
       mpi2abi_datatype = MPIABI_LOGICAL8
#endif
       ! [Datatypes for reduction functions (C)]
    case (MPI_FLOAT_INT)
       mpi2abi_datatype = MPIABI_FLOAT_INT
    case (MPI_DOUBLE_INT)
       mpi2abi_datatype = MPIABI_DOUBLE_INT
    case (MPI_LONG_INT)
       mpi2abi_datatype = MPIABI_LONG_INT
    case (MPI_2INT)
       mpi2abi_datatype = MPIABI_2INT
    case (MPI_SHORT_INT)
       mpi2abi_datatype = MPIABI_SHORT_INT
    case (MPI_LONG_DOUBLE_INT)
       mpi2abi_datatype = MPIABI_LONG_DOUBLE_INT
       ! [Datatypes for reduction functions (Fortran)]
    case (MPI_2REAL)
       mpi2abi_datatype = MPIABI_2REAL
    case (MPI_2DOUBLE_PRECISION)
       mpi2abi_datatype = MPIABI_2DOUBLE_PRECISION
    case (MPI_2INTEGER)
       mpi2abi_datatype = MPIABI_2INTEGER
       ! [Removed constructs]
#ifdef HAVE_MPI_LB
    case (MPI_LB)
       mpi2abi_datatype = MPIABI_LB
#endif
#ifdef HAVE_MPI_UB
    case (MPI_UB)
       mpi2abi_datatype = MPIABI_UB
#endif
    case default
       mpi2abi_datatype = mpi2abi_unreserved(datatype)
    end select
  end function mpi2abi_datatype

  integer function abi2mpi_file(file)
    integer, intent(in) :: file
    if (.not.handle_is_reserved(file)) then
       abi2mpi_file = abi2mpi_unreserved(file)
       return
    end if
    select case (file)
    case (MPIABI_FILE_NULL)
       abi2mpi_file = MPI_FILE_NULL
    case default
       call assert(.false.)
    end select
  end function abi2mpi_file

  integer function mpi2abi_file(file)
    integer, intent(in) :: file
    select case (file)
    case (MPI_FILE_NULL)
       mpi2abi_file = MPIABI_FILE_NULL
    case default
       mpi2abi_file = mpi2abi_unreserved(file)
    end select
  end function mpi2abi_file

  integer function abi2mpi_info(info)
    integer, intent(in) :: info
    if (.not.handle_is_reserved(info)) then
       abi2mpi_info = abi2mpi_unreserved(info)
       return
    end if
    select case (info)
    case (MPIABI_INFO_ENV)
       abi2mpi_info = MPI_INFO_ENV
    case (MPIABI_INFO_NULL)
       abi2mpi_info = MPI_INFO_NULL
    case default
       call assert(.false.)
    end select
  end function abi2mpi_info

  integer function abi2mpi_message(message)
    integer, intent(in) :: message
    select case (message)
    case (MPIABI_MESSAGE_NO_PROC)
       abi2mpi_message = MPI_MESSAGE_NO_PROC
    case (MPIABI_MESSAGE_NULL)
       abi2mpi_message = MPI_MESSAGE_NULL
    case default
       abi2mpi_message = mpi2abi_unreserved(message)
    end select
  end function abi2mpi_message

  integer function abi2mpi_request(request)
    integer, intent(in) :: request
    if (.not.handle_is_reserved(request)) then
       abi2mpi_request = abi2mpi_unreserved(request)
       return
    end if
    select case (request)
    case (MPI_REQUEST_NULL)
       abi2mpi_request = MPIABI_REQUEST_NULL
    case default
       call assert(.false.)
    end select
  end function abi2mpi_request

  elemental integer function mpi2abi_request(request)
    integer, intent(in) :: request
    if (request == MPIABI_REQUEST_NULL) then
       mpi2abi_request = MPI_REQUEST_NULL
       return
    end if
    mpi2abi_request = request
  end function mpi2abi_request

  integer function abi2mpi_session(session)
    integer, intent(in) :: session
    if (.not.handle_is_reserved(session)) then
       abi2mpi_session = abi2mpi_unreserved(session)
       return
    end if
    select case (session)
    case (MPIABI_SESSION_NULL)
       abi2mpi_session = MPI_SESSION_NULL
    case default
       call assert(.false.)
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
