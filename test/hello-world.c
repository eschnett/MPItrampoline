#include <mpi.h>
#include <stdio.h>

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

  if (rank == 0)
    printf("Hello, World!\n");

  for (int n = 0; n < size; ++n) {
    if (rank == n)
      printf("  process %d/%d\n", rank, size);
    MPI_Barrier(MPI_COMM_WORLD);
  }

  if (rank == 0)
    printf("Done.\n");
  MPI_Finalize();

  return 0;
}
