      include "mpiabif_functions.h"

      interface

         subroutine MPI_Init(ierror)
           implicit none
           integer ierror
         end subroutine MPI_Init

         subroutine MPI_Finalize(ierror)
           implicit none
           integer ierror
         end subroutine MPI_Finalize

         subroutine MPI_Barrier(comm, ierror)
           implicit none
           integer comm, ierror
         end subroutine MPI_Barrier

         subroutine MPI_Recv(buf, count, datatype, source, tag, comm,      &
     &     status, ierror)
           implicit none
           integer MPI_STATUS_SIZE
           parameter (MPI_STATUS_SIZE = 8)
           integer buf, count, datatype, source, tag, comm,                &
     &          status(MPI_STATUS_SIZE), ierror
        end subroutine MPI_Recv
        
        subroutine MPI_Send(buf, count, datatype, dest, tag, comm,        &
     &     ierror)
           implicit none
           integer buf, count, datatype, dest, tag, comm, ierror
        end subroutine MPI_Send
        
        subroutine MPI_Comm_size(comm, size, ierror)
           implicit none
           integer comm, size, ierror
        end subroutine MPI_Comm_size
        
        subroutine MPI_Comm_rank(comm, rank, ierror)
           implicit none
           integer comm, rank, ierror
        end subroutine MPI_Comm_rank

      end interface
