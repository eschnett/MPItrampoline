subroutine mpitrampoline_mpi_init()

  use mpi
  
  implicit none

  integer mpi_error1
  common /mpi_error/ mpi_error1
  integer mpi_source1
  common /mpi_source/ mpi_source1
  integer mpi_tag1
  common /mpi_tag/ mpi_tag1

  integer mpi_comm_null1
  common /mpi_comm_null/ mpi_comm_null1
  integer mpi_comm_self1
  common /mpi_comm_self/ mpi_comm_self1
  integer mpi_comm_world1
  common /mpi_comm_world/ mpi_comm_world1

  integer mpi_int1
  common /mpi_int/ mpi_int1
  integer mpi_integer1
  common /mpi_integer/ mpi_integer1

  mpi_error = mpi_error1
  mpi_source = mpi_source1
  mpi_tag = mpi_tag1

  mpi_comm_null = mpi_comm_null1
  mpi_comm_self = mpi_comm_self1
  mpi_comm_world = mpi_comm_world1

  mpi_int = mpi_int1
  mpi_integer = mpi_integer1

end subroutine mpitrampoline_mpi_init
