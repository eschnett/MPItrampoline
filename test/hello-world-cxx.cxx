#include <mpi.h>

#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Hello, World!\n";

  std::cout << "Compiled with MPItrampoline " << MPITRAMPOLINE_VERSION_MAJOR
            << "." << MPITRAMPOLINE_VERSION_MINOR << "."
            << MPITRAMPOLINE_VERSION_PATCH << "\n";
  std::cout << "Running with MPItrampoline " << mpitrampoline_version_major
            << "." << mpitrampoline_version_minor << "."
            << mpitrampoline_version_patch << "\n";

  int version, subversion;
  MPI_Get_version(&version, &subversion);
  std::cout << "Running on MPI standard version " << version << "."
            << subversion << "\n";
  char library_version[MPI_MAX_LIBRARY_VERSION_STRING];
  int resultlen;
  MPI_Get_library_version(library_version, &resultlen);
  std::cout << "Running on " << library_version << "\n";

  MPI_Init(&argc, &argv);

  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (argc >= 2) {
    const int expected_size = std::atoi(argv[1]);
    if (size != expected_size) {
      std::cerr << "rank " << rank << ", size " << size << ", expected size "
                << expected_size << "\n";
      std::exit(1);
    }
  }

  if (rank == 0)
    std::cout << "Hello, World!\n";

  int token;
  if (rank > 0)
    MPI_Recv(&token, 0, MPI_INT, rank - 1, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
  std::cout << "  process " << rank << "/" << size << "\n";
  if (rank < size - 1)
    MPI_Send(&token, 0, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
  MPI_Barrier(MPI_COMM_WORLD);

  if (rank == 0)
    std::cout << "Done.\n";
  MPI_Finalize();

  return 0;
}
