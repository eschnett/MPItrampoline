      integer MPI_STATUS_SIZE
      parameter (MPI_STATUS_SIZE = 10)

      integer MPI_ANY_SOURCE
      common /MPI_ANY_SOURCE/ MPI_ANY_SOURCE
      integer MPI_ANY_TAG
      common /MPI_ANY_TAG/ MPI_ANY_TAG
      integer MPI_PROC_NULL
      common /MPI_PROC_NULL/ MPI_PROC_NULL
      integer MPI_ROOT
      common /MPI_ROOT/ MPI_ROOT

      integer MPI_COMM_NULL
      common /MPI_COMM_NULL/ MPI_COMM_NULL
      integer MPI_COMM_SELF
      common /MPI_COMM_SELF/ MPI_COMM_SELF
      integer MPI_COMM_WORLD
      common /MPI_COMM_WORLD/ MPI_COMM_WORLD

      external MPI_Send
      external MPI_Recv
      external MPI_Init
      external MPI_Finalize
