#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("Hello, World!\n");

  printf("Compiled with MPItrampoline %d.%d.%d\n", MPITRAMPOLINE_VERSION_MAJOR,
         MPITRAMPOLINE_VERSION_MINOR, MPITRAMPOLINE_VERSION_PATCH);
  printf("Running with MPItrampoline %d.%d.%d\n", mpitrampoline_version_major,
         mpitrampoline_version_minor, mpitrampoline_version_patch);

  MPI_Init(&argc, &argv);

  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (argc >= 2) {
    const int expected_size = atoi(argv[1]);
    if (size != expected_size) {
      fprintf(stderr, "rank %d, size %d, expected size %d\n", rank, size,
              expected_size);
      exit(1);
    }
  }

  if (rank == 0)
    printf("Hello, World!\n");

  int token;
  if (rank > 0)
    MPI_Recv(&token, 0, MPI_INT, rank - 1, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
  printf("  process %d/%d\n", rank, size);
  if (rank < size - 1)
    MPI_Send(&token, 0, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);

  if (rank == 0)
    printf("Done.\n");
  MPI_Finalize();

  return 0;
}
