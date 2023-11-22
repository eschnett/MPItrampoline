module mpiwrapper
  implicit none
  include "mpif.h"
  include "mpiabif_constants.h"
  public
contains
  
  integer function abi2mpi_comm(comm)
    integer comm
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

  integer function mpi2abi_errorcode(ierror)
    integer ierror
    mpi2abi_errorcode = ierror
  end function mpi2abi_errorcode

end module mpiwrapper
