#include "mpi.h"

#include <stdio.h>

int main(int argc, char **argv) {
  fprintf(stderr, "main.0\n");

  int initialized;
  fprintf(stderr, "&MPI_Initialized=%p\n", &MPI_Initialized);
  fprintf(stderr, "MPI_Initialized=%p\n", MPI_Initialized);
  MPI_Initialized(&initialized);
  printf("initialized: %d\n", initialized);

  MPI_Init(&argc, &argv);
  fprintf(stderr, "main.1\n");

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  fprintf(stderr, "main.2\n");
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  fprintf(stderr, "main.3\n");
  printf("size: %d, rank: %d\n", size, rank);

  int isend = 42;
  int irecv = -1;
  MPI_Send(&isend, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
  fprintf(stderr, "main.4\n");
  MPI_Status status;
  MPI_Recv(&irecv, 1, MPI_INT, (rank + size - 1) % size, 0, MPI_COMM_WORLD,
           &status);
  fprintf(stderr, "main.5\n");
  int count;
  MPI_Get_count(&status, MPI_INT, &count);
  fprintf(stderr, "main.6\n");
  if (rank == 0) {
    printf("sent: %d, received: %d\n", isend, irecv);
    printf("source: %d, tag: %d, error: %d, count: %d\n", status.MPI_SOURCE,
           status.MPI_TAG, status.MPI_ERROR, count);
  }

  MPI_Finalize();
  fprintf(stderr, "main.9\n");

  return 0;
}
