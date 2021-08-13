#include "mpi.h"

// Constants

MPI_Fint mpi_comm_null_;
MPI_Fint mpi_comm_self_;
MPI_Fint mpi_comm_world_;

void init_fortran() {
  mpi_comm_null_ = MPI_Comm_c2f(MPI_COMM_NULL);
  mpi_comm_self_ = MPI_Comm_c2f(MPI_COMM_SELF);
  mpi_comm_world_ = MPI_Comm_c2f(MPI_COMM_WORLD);
}
