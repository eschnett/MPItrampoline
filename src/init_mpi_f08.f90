subroutine mpitrampoline_init_mpi_f08()

  use mpi_f08

  use mpi, only: &
       mpi_comm_null1 => mpi_comm_null, &
       mpi_comm_self1 => mpi_comm_self, &
       mpi_comm_world1 => mpi_comm_world, &

       mpi_int1 => mpi_int, &
       mpi_integer1 => mpi_integer

  implicit none

  mpi_int%mpi_val = mpi_int1
  mpi_integer%mpi_val = mpi_integer1
  
  mpi_comm_null%mpi_val = mpi_comm_null1
  mpi_comm_self%mpi_val = mpi_comm_self1
  mpi_comm_world%mpi_val = mpi_comm_world1

end subroutine mpitrampoline_init_mpi_f08
