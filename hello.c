#include "mpi.h"

#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int initialized, finalized;
  MPI_Initialized(&initialized);
  assert(!initialized);
  MPI_Finalized(&finalized);
  assert(!finalized);

  MPI_Init(&argc, &argv);

  MPI_Initialized(&initialized);
  assert(initialized);
  MPI_Finalized(&finalized);
  assert(!finalized);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  printf("size: %d, rank: %d\n", size, rank);

  {
    int isend = 42;
    int irecv = -1;
    MPI_Send(&isend, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
    MPI_Status status;
    MPI_Recv(&irecv, 1, MPI_INT, (rank + size - 1) % size, 0, MPI_COMM_WORLD,
             &status);
    assert(isend == 42);
    assert(irecv == 42);
    assert(status.MPI_SOURCE == (rank + size - 1) % size);
    assert(status.MPI_TAG == 0);
    int count;
    MPI_Get_count(&status, MPI_INT, &count);
    assert(count == 1);
    if (rank == 0) {
      printf("sent: %d, received: %d\n", isend, irecv);
      printf("source: %d, tag: %d, error: %d, count: %d\n", status.MPI_SOURCE,
             status.MPI_TAG, status.MPI_ERROR, count);
    }
  }

  {
    int isend = 42;
    int irecv = -1;
    MPI_Request sreq;
    MPI_Isend(&isend, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD, &sreq);
    MPI_Request rreq;
    MPI_Irecv(&irecv, 1, MPI_INT, (rank + size - 1) % size, 0, MPI_COMM_WORLD,
              &rreq);
    MPI_Wait(&sreq, MPI_STATUS_IGNORE);
    MPI_Status status;
    MPI_Wait(&rreq, &status);
    assert(isend == 42);
    assert(irecv == 42);
    assert(status.MPI_SOURCE == (rank + size - 1) % size);
    assert(status.MPI_TAG == 0);
    int count;
    MPI_Get_count(&status, MPI_INT, &count);
    assert(count == 1);
  }

  MPI_Barrier(MPI_COMM_WORLD);

  MPI_Finalize();

  MPI_Initialized(&initialized);
  assert(initialized);
  MPI_Finalized(&finalized);
  assert(finalized);

  return 0;
}
