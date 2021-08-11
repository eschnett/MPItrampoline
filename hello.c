#include "mpi.h"

#include <stdio.h>

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  printf("size: %d, rank: %d\n", size, rank);

  int isend = 42;
  int irecv = -1;
  MPI_Send(&isend, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
  MPI_Status status;
  MPI_Recv(&irecv, 1, MPI_INT, (rank + size - 1) % size, 0, MPI_COMM_WORLD,
           &status);
  int count;
  MPI_Get_count(&status, MPI_INT, &count);
  if (rank == 0) {
    printf("sent: %d, received: %d\n", isend, irecv);
    printf("source: %d, tag: %d, error: %d, count: %d\n", status.MPI_SOURCE,
           status.MPI_TAG, status.MPI_ERROR, count);
  }

  MPI_Finalize();

  return 0;
}
