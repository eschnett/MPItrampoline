module mpi_f08_types
  use mpi
  
  implicit none
  private
  save

  public :: MPI_Status_f2f08
  public :: MPI_Status_f082f

  ! Handles

  type, bind(C), public :: MPI_Comm
     integer :: MPI_VAL
  end type MPI_Comm

  type, bind(C), public :: MPI_Datatype
     integer :: MPI_VAL
  end type MPI_Datatype

  type, bind(C), public :: MPI_Errhandler
     integer :: MPI_VAL
  end type MPI_Errhandler

  type, bind(C), public :: MPI_File
     integer :: MPI_VAL
  end type MPI_File

  type, bind(C), public :: MPI_Group
     integer :: MPI_VAL
  end type MPI_Group

  type, bind(C), public :: MPI_Info
     integer :: MPI_VAL
  end type MPI_Info

  type, bind(C), public :: MPI_Message
     integer :: MPI_VAL
  end type MPI_Message

  type, bind(C), public :: MPI_Op
     integer :: MPI_VAL
  end type MPI_Op

  type, bind(C), public :: MPI_Request
     integer :: MPI_VAL
  end type MPI_Request

  type, bind(C), public :: MPI_Session
     integer :: MPI_VAL
  end type MPI_Session

  type, bind(C), public :: MPI_Win
     integer :: MPI_VAL
  end type MPI_Win

  ! Status

  ! We cannot declare this type as `binc(C)` because Flang has a bug
  ! (see <https://github.com/llvm/llvm-project/issues/76529>) that
  ! requires us to use the `sequence` attribute.
  ! type, bind(C), public :: MPI_Status
  type, public :: MPI_Status
     sequence
     integer :: MPI_VAL(MPI_STATUS_SIZE)
  end type MPI_Status
  
contains

  subroutine MPI_Status_f2f08(f_status, f08_status, ierror)
    integer, intent(in) :: f_status(MPI_STATUS_SIZE)
    type(MPI_Status), intent(out) :: f08_status
    integer, optional, intent(out) :: ierror
    f08_status%MPI_VAL = f_status
    if (present(ierror)) ierror = MPI_SUCCESS
  end subroutine MPI_Status_f2f08

  subroutine MPI_Status_f082f(f08_status, f_status, ierror)
    type(MPI_Status), intent(in) :: f08_status
    integer, intent(out) :: f_status(MPI_STATUS_SIZE)
    integer, optional, intent(out) :: ierror
    f_status = f08_status%MPI_VAL
    if (present(ierror)) ierror = MPI_SUCCESS
  end subroutine MPI_Status_f082f

end module mpi_f08_types
