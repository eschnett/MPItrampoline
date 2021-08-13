      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = 10)

      integer MPI_COMM_NULL
      integer MPI_COMM_SELF
      integer MPI_COMM_WORLD
      common /mpitrampoline_constants/                                  &
     &     MPI_COMM_NULL,                                               &
     &     MPI_COMM_SELF,                                               &
     &     MPI_COMM_WORLD

      external MPI_Send
      external MPI_Recv
      external MPI_Init
      external MPI_Finalize
