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

  integer mpi_double1
  common /mpi_double/ mpi_double1
  integer mpi_double_precision1
  common /mpi_double_precision/ mpi_double_precision1
  integer mpi_float1
  common /mpi_float/ mpi_float1
  integer mpi_int1
  common /mpi_int/ mpi_int1
  integer mpi_integer1
  common /mpi_integer/ mpi_integer1
  integer mpi_real1
  common /mpi_real/ mpi_real1

  integer mpi_max1
  common /mpi_max/ mpi_max1
  integer mpi_min1
  common /mpi_min/ mpi_min1
  integer mpi_sum1
  common /mpi_sum/ mpi_sum1

  mpi_error = mpi_error1
  mpi_source = mpi_source1
  mpi_tag = mpi_tag1

  mpi_comm_null = mpi_comm_null1
  mpi_comm_self = mpi_comm_self1
  mpi_comm_world = mpi_comm_world1

  mpi_double = mpi_double1
  mpi_double_precision = mpi_double_precision1
  mpi_float = mpi_float1
  mpi_int = mpi_int1
  mpi_integer = mpi_integer1
  mpi_real = mpi_real1

  mpi_max = mpi_max1
  mpi_min = mpi_min1
  mpi_sum = mpi_sum1

end subroutine mpitrampoline_mpi_init
