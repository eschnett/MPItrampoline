#include "mpi.h"

// Constants

struct {
  MPI_Fint mpi_comm_null_;
  MPI_Fint mpi_comm_self_;
  MPI_Fint mpi_comm_world_;
} mpitrampoline_constants_;

void init_fortran() {
  mpitrampoline_constants_.mpi_comm_null_ = MPI_Comm_c2f(MPI_COMM_NULL);
  mpitrampoline_constants_.mpi_comm_self_ = MPI_Comm_c2f(MPI_COMM_SELF);
  mpitrampoline_constants_.mpi_comm_world_ = MPI_Comm_c2f(MPI_COMM_WORLD);
}

// Functions

void mpi_send_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *dest,
               MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *ierror) {
  *ierror = MPI_Send(buf, *count, MPI_Type_f2c(*datatype), *dest, *tag,
                     MPI_Comm_f2c(*comm));
}

void mpi_recv_(void *buf, MPI_Fint *count, MPI_Fint *datatype, MPI_Fint *source,
               MPI_Fint *tag, MPI_Fint *comm, MPI_Fint *status,
               MPI_Fint *ierror) {
  MPI_Status c_status;
  MPI_Status_f2c(status, &c_status);
  *ierror = MPI_Recv(buf, *count, MPI_Type_f2c(*datatype), *source, *tag,
                     MPI_Comm_f2c(*comm), &c_status);
  MPI_Status_c2f(&c_status, status);
}

void mpi_init_(MPI_Fint *ierror) { *ierror = MPI_Init(NULL, NULL); }

void mpi_finalize_(MPI_Fint *ierror) { *ierror = MPI_Finalize(); }
