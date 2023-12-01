module mpi_f08
  use mpi, &
       HIDDEN_MPI_COMM_NULL => MPI_COMM_NULL, &
       HIDDEN_MPI_COMM_SELF => MPI_COMM_SELF, &
       HIDDEN_MPI_COMM_WORLD => MPI_COMM_WORLD

  implicit none
  public
  save

  private :: HIDDEN_MPI_COMM_NULL
  private :: HIDDEN_MPI_COMM_SELF
  private :: HIDDEN_MPI_COMM_WORLD

  ! Handles

  type, bind(C) :: MPI_Comm
     integer :: MPI_VAL
  end type MPI_Comm

  type, bind(C) :: MPI_Datatype
     integer :: MPI_VAL
  end type MPI_Datatype

  type, bind(C) :: MPI_Errhandler
     integer :: MPI_VAL
  end type MPI_Errhandler

  type, bind(C) :: MPI_File
     integer :: MPI_VAL
  end type MPI_File

  type, bind(C) :: MPI_Group
     integer :: MPI_VAL
  end type MPI_Group

  type, bind(C) :: MPI_Info
     integer :: MPI_VAL
  end type MPI_Info

  type, bind(C) :: MPI_Message
     integer :: MPI_VAL
  end type MPI_Message

  type, bind(C) :: MPI_Op
     integer :: MPI_VAL
  end type MPI_Op

  type, bind(C) :: MPI_Request
     integer :: MPI_VAL
  end type MPI_Request

  type, bind(C) :: MPI_Session
     integer :: MPI_VAL
  end type MPI_Session

  type, bind(C) :: MPI_Win
     integer :: MPI_VAL
  end type MPI_Win

  ! Status

  type, bind(C) :: MPI_Status
     integer :: MPI_VAL(MPI_STATUS_SIZE)
  end type MPI_Status

  ! Constants

  type(MPI_Comm), parameter :: MPI_COMM_NULL = MPI_Comm(HIDDEN_MPI_COMM_NULL)
  type(MPI_Comm), parameter :: MPI_COMM_SELF = MPI_Comm(HIDDEN_MPI_COMM_SELF)
  type(MPI_Comm), parameter :: MPI_COMM_WOLRD = MPI_Comm(HIDDEN_MPI_COMM_WORLD)

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

end module mpi_f08
