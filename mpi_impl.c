#include "mpi.h"

#include <ISO_Fortran_binding.h>

void mpiwrapper_send_impl_(CFI_cdesc_t *bufdesc, MPI_Fint count,
                           MPI_Fint datatype, MPI_Fint dest, MPI_Fint tag,
                           MPI_Fint comm, MPI_Fint *ierror) {
  mpi_send_(bufdesc->base_addr...
}
