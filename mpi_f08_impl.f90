subroutine mpitrampoline_mpi_f08_init()

  use mpi_f08

  use mpi, only: &
       mpi_comm_null1 => mpi_comm_null, &
       mpi_comm_self1 => mpi_comm_self, &
       mpi_comm_world1 => mpi_comm_world, &

       mpi_int1 => mpi_int, &
       mpi_integer1 => mpi_integer

  implicit none

  mpi_int%datatype = mpi_int1
  mpi_integer%datatype = mpi_integer1
  
  mpi_comm_null%comm = mpi_comm_null1
  mpi_comm_self%comm = mpi_comm_self1
  mpi_comm_world%comm = mpi_comm_world1

end subroutine mpitrampoline_mpi_f08_init
