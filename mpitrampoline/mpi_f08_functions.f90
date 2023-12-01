! MPI Fortran 2008 function bindings

! This file has been generated automatically
! by `mpitrampoline/generate_trampoline.jl`.
! Do not modify this file, changes will be overwritten.

module mpi_f08_functions_internal
   use mpi_f08_types
   use mpi_f08_constants

   implicit none
   public
   save

   interface

      subroutine MPI_Bsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Bsend

      subroutine MPI_Bsend_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Bsend_init

      subroutine MPI_Buffer_attach( &
         buffer, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buffer
         !gcc$ attributes no_arg_check :: buffer
         integer :: buffer(*)
         integer, intent(in) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Buffer_attach

      subroutine MPI_Buffer_detach( &
         buffer_addr, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer(MPI_ADDRESS_KIND), intent(out) :: buffer_addr
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Buffer_detach

      subroutine MPI_Buffer_flush( &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: ierror
      end subroutine MPI_Buffer_flush

      subroutine MPI_Buffer_iflush( &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Buffer_iflush

      subroutine MPI_Cancel( &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Cancel

      subroutine MPI_Comm_attach_buffer( &
         comm, &
         buffer, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         !dir$ ignore_tkr(tkr) buffer
         !gcc$ attributes no_arg_check :: buffer
         integer, intent(in) :: buffer(*)
         integer, intent(in) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_attach_buffer

      subroutine MPI_Comm_detach_buffer( &
         comm, &
         buffer_addr, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer(MPI_ADDRESS_KIND), intent(out) :: buffer_addr
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_detach_buffer

      subroutine MPI_Comm_flush_buffer( &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_flush_buffer

      subroutine MPI_Comm_iflush_buffer( &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_iflush_buffer

      subroutine MPI_Get_count( &
         status, &
         datatype, &
         count, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: count
         integer, intent(out) :: ierror
      end subroutine MPI_Get_count

      subroutine MPI_Ibsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ibsend

      subroutine MPI_Improbe( &
         source, &
         tag, &
         comm, &
         flag, &
         message, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         logical, intent(out) :: flag
         type(MPI_Message), intent(out) :: message
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Improbe

      subroutine MPI_Imrecv( &
         buf, &
         count, &
         datatype, &
         message, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Message), intent(out) :: message
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Imrecv

      subroutine MPI_Iprobe( &
         source, &
         tag, &
         comm, &
         flag, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Iprobe

      subroutine MPI_Irecv( &
         buf, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Irecv

      subroutine MPI_Irsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Irsend

      subroutine MPI_Isend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Isend

      subroutine MPI_Isendrecv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         dest, &
         sendtag, &
         recvbuf, &
         recvcount, &
         recvtype, &
         source, &
         recvtag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         integer, intent(in) :: dest
         integer, intent(in) :: sendtag
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: source
         integer, intent(in) :: recvtag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Isendrecv

      subroutine MPI_Isendrecv_replace( &
         buf, &
         count, &
         datatype, &
         dest, &
         sendtag, &
         source, &
         recvtag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(inout) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: sendtag
         integer, intent(in) :: source
         integer, intent(in) :: recvtag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Isendrecv_replace

      subroutine MPI_Issend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Issend

      subroutine MPI_Mprobe( &
         source, &
         tag, &
         comm, &
         message, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Message), intent(out) :: message
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Mprobe

      subroutine MPI_Mrecv( &
         buf, &
         count, &
         datatype, &
         message, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Message), intent(out) :: message
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Mrecv

      subroutine MPI_Probe( &
         source, &
         tag, &
         comm, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Probe

      subroutine MPI_Recv( &
         buf, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Recv

      subroutine MPI_Recv_init( &
         buf, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Recv_init

      subroutine MPI_Request_free( &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(inout) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Request_free

      subroutine MPI_Request_get_status( &
         request, &
         flag, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(in) :: request
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Request_get_status

      subroutine MPI_Request_get_status_all( &
         count, &
         array_of_requests, &
         flag, &
         array_of_statuses, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(in) :: array_of_requests(count)
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: array_of_statuses(count)
         integer, intent(out) :: ierror
      end subroutine MPI_Request_get_status_all

      subroutine MPI_Request_get_status_any( &
         count, &
         array_of_requests, &
         index, &
         flag, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(in) :: array_of_requests(count)
         integer, intent(out) :: index
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Request_get_status_any

      subroutine MPI_Request_get_status_some( &
         incount, &
         array_of_requests, &
         outcount, &
         array_of_indices, &
         array_of_statuses, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: incount
         type(MPI_Request), intent(in) :: array_of_requests(incount)
         integer, intent(out) :: outcount
         integer, intent(out) :: array_of_indices(incount)
         type(MPI_Status), intent(out) :: array_of_statuses(incount)
         integer, intent(out) :: ierror
      end subroutine MPI_Request_get_status_some

      subroutine MPI_Rsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Rsend

      subroutine MPI_Rsend_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Rsend_init

      subroutine MPI_Send( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Send

      subroutine MPI_Send_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Send_init

      subroutine MPI_Sendrecv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         dest, &
         sendtag, &
         recvbuf, &
         recvcount, &
         recvtype, &
         source, &
         recvtag, &
         comm, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         integer, intent(in) :: dest
         integer, intent(in) :: sendtag
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: source
         integer, intent(in) :: recvtag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Sendrecv

      subroutine MPI_Sendrecv_replace( &
         buf, &
         count, &
         datatype, &
         dest, &
         sendtag, &
         source, &
         recvtag, &
         comm, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(inout) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: sendtag
         integer, intent(in) :: source
         integer, intent(in) :: recvtag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Sendrecv_replace

      subroutine MPI_Session_attach_buffer( &
         session, &
         buffer, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         !dir$ ignore_tkr(tkr) buffer
         !gcc$ attributes no_arg_check :: buffer
         integer, intent(in) :: buffer(*)
         integer, intent(in) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Session_attach_buffer

      subroutine MPI_Session_detach_buffer( &
         session, &
         buffer_addr, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         integer(MPI_ADDRESS_KIND), intent(out) :: buffer_addr
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Session_detach_buffer

      subroutine MPI_Session_flush_buffer( &
         session, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         integer, intent(out) :: ierror
      end subroutine MPI_Session_flush_buffer

      subroutine MPI_Session_iflush_buffer( &
         session, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Session_iflush_buffer

      subroutine MPI_Ssend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Ssend

      subroutine MPI_Ssend_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: dest
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ssend_init

      subroutine MPI_Start( &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(inout) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Start

      subroutine MPI_Startall( &
         count, &
         array_of_requests, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(inout) :: array_of_requests(count)
         integer, intent(out) :: ierror
      end subroutine MPI_Startall

      subroutine MPI_Status_get_error( &
         status, &
         err, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         integer, intent(out) :: err
         integer, intent(out) :: ierror
      end subroutine MPI_Status_get_error

      subroutine MPI_Status_get_source( &
         status, &
         source, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         integer, intent(out) :: source
         integer, intent(out) :: ierror
      end subroutine MPI_Status_get_source

      subroutine MPI_Status_get_tag( &
         status, &
         tag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         integer, intent(out) :: tag
         integer, intent(out) :: ierror
      end subroutine MPI_Status_get_tag

      subroutine MPI_Test( &
         request, &
         flag, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(inout) :: request
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Test

      subroutine MPI_Test_cancelled( &
         status, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Test_cancelled

      subroutine MPI_Testall( &
         count, &
         array_of_requests, &
         flag, &
         array_of_statuses, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(inout) :: array_of_requests(count)
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: array_of_statuses(count)
         integer, intent(out) :: ierror
      end subroutine MPI_Testall

      subroutine MPI_Testany( &
         count, &
         array_of_requests, &
         index, &
         flag, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(inout) :: array_of_requests(count)
         integer, intent(out) :: index
         logical, intent(out) :: flag
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Testany

      subroutine MPI_Testsome( &
         incount, &
         array_of_requests, &
         outcount, &
         array_of_indices, &
         array_of_statuses, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: incount
         type(MPI_Request), intent(inout) :: array_of_requests(incount)
         integer, intent(out) :: outcount
         integer, intent(out) :: array_of_indices(incount)
         type(MPI_Status), intent(out) :: array_of_statuses(incount)
         integer, intent(out) :: ierror
      end subroutine MPI_Testsome

      subroutine MPI_Wait( &
         request, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(inout) :: request
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Wait

      subroutine MPI_Waitall( &
         count, &
         array_of_requests, &
         array_of_statuses, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(inout) :: array_of_requests(count)
         type(MPI_Status), intent(out) :: array_of_statuses(count)
         integer, intent(out) :: ierror
      end subroutine MPI_Waitall

      subroutine MPI_Waitany( &
         count, &
         array_of_requests, &
         index, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Request), intent(inout) :: array_of_requests(count)
         integer, intent(out) :: index
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Waitany

      subroutine MPI_Waitsome( &
         incount, &
         array_of_requests, &
         outcount, &
         array_of_indices, &
         array_of_statuses, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: incount
         type(MPI_Request), intent(inout) :: array_of_requests(incount)
         integer, intent(out) :: outcount
         integer, intent(out) :: array_of_indices(incount)
         type(MPI_Status), intent(out) :: array_of_statuses(incount)
         integer, intent(out) :: ierror
      end subroutine MPI_Waitsome

      subroutine MPI_Parrived( &
         request, &
         partition, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(in) :: request
         integer, intent(in) :: partition
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Parrived

      subroutine MPI_Pready( &
         partition, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: partition
         type(MPI_Request), intent(in) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Pready

      subroutine MPI_Pready_list( &
         length, &
         array_of_partitions, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: length
         integer, intent(in) :: array_of_partitions(length)
         type(MPI_Request), intent(in) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Pready_list

      subroutine MPI_Pready_range( &
         partition_low, &
         partition_high, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: partition_low
         integer, intent(in) :: partition_high
         type(MPI_Request), intent(in) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Pready_range

      subroutine MPI_Precv_init( &
         buf, &
         partitions, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: partitions
         integer(MPI_COUNT_KIND), intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Precv_init

      subroutine MPI_Psend_init( &
         buf, &
         partitions, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: partitions
         integer(MPI_COUNT_KIND), intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: source
         integer, intent(in) :: tag
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Psend_init

      function MPI_Aint_add( &
         base, &
         disp &
      ) result(result)
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer(MPI_ADDRESS_KIND), intent(in) :: base
         integer(MPI_ADDRESS_KIND), intent(in) :: disp
         integer(MPI_ADDRESS_KIND) :: result
      end function MPI_Aint_add

      function MPI_Aint_diff( &
         addr1, &
         addr2 &
      ) result(result)
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer(MPI_ADDRESS_KIND), intent(in) :: addr1
         integer(MPI_ADDRESS_KIND), intent(in) :: addr2
         integer(MPI_ADDRESS_KIND) :: result
      end function MPI_Aint_diff

      subroutine MPI_Get_address( &
         location, &
         address, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) location
         !gcc$ attributes no_arg_check :: location
         integer, intent(in) :: location(*)
         integer(MPI_ADDRESS_KIND), intent(out) :: address
         integer, intent(out) :: ierror
      end subroutine MPI_Get_address

      subroutine MPI_Get_elements( &
         status, &
         datatype, &
         count, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: count
         integer, intent(out) :: ierror
      end subroutine MPI_Get_elements

      subroutine MPI_Pack( &
         inbuf, &
         incount, &
         datatype, &
         outbuf, &
         outsize, &
         position, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) inbuf
         !gcc$ attributes no_arg_check :: inbuf
         integer, intent(in) :: inbuf(*)
         integer, intent(in) :: incount
         type(MPI_Datatype), intent(in) :: datatype
         !dir$ ignore_tkr(tkr) outbuf
         !gcc$ attributes no_arg_check :: outbuf
         integer :: outbuf(*)
         integer, intent(in) :: outsize
         integer, intent(out) :: position
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Pack

      subroutine MPI_Pack_external( &
         datarep, &
         inbuf, &
         incount, &
         datatype, &
         outbuf, &
         outsize, &
         position, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: datarep
         !dir$ ignore_tkr(tkr) inbuf
         !gcc$ attributes no_arg_check :: inbuf
         integer, intent(in) :: inbuf(*)
         integer, intent(in) :: incount
         type(MPI_Datatype), intent(in) :: datatype
         !dir$ ignore_tkr(tkr) outbuf
         !gcc$ attributes no_arg_check :: outbuf
         integer :: outbuf(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: outsize
         integer(MPI_ADDRESS_KIND), intent(out) :: position
         integer, intent(out) :: ierror
      end subroutine MPI_Pack_external

      subroutine MPI_Pack_external_size( &
         datarep, &
         incount, &
         datatype, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: datarep
         integer(MPI_COUNT_KIND), intent(in) :: incount
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Pack_external_size

      subroutine MPI_Pack_size( &
         incount, &
         datatype, &
         comm, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: incount
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Pack_size

      subroutine MPI_Type_commit( &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(out) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_commit

      subroutine MPI_Type_contiguous( &
         count, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_contiguous

      subroutine MPI_Type_create_darray( &
         size, &
         rank, &
         ndims, &
         array_of_gsizes, &
         array_of_distribs, &
         array_of_dargs, &
         array_of_psizes, &
         order, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: size
         integer, intent(in) :: rank
         integer, intent(in) :: ndims
         integer, intent(in) :: array_of_gsizes(ndims)
         integer, intent(in) :: array_of_distribs(ndims)
         integer, intent(in) :: array_of_dargs(ndims)
         integer, intent(in) :: array_of_psizes(ndims)
         integer, intent(in) :: order
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_darray

      subroutine MPI_Type_create_hindexed( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: array_of_blocklengths(count)
         integer(MPI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_hindexed

      subroutine MPI_Type_create_hindexed_block( &
         count, &
         blocklength, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: blocklength
         integer(MPI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_hindexed_block

      subroutine MPI_Type_create_hvector( &
         count, &
         blocklength, &
         stride, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: blocklength
         integer(MPI_ADDRESS_KIND), intent(in) :: stride
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_hvector

      subroutine MPI_Type_create_indexed_block( &
         count, &
         blocklength, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: blocklength
         integer, intent(in) :: array_of_displacements(count)
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_indexed_block

      subroutine MPI_Type_create_resized( &
         oldtype, &
         lb, &
         extent, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: oldtype
         integer(MPI_ADDRESS_KIND), intent(in) :: lb
         integer(MPI_ADDRESS_KIND), intent(in) :: extent
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_resized

      subroutine MPI_Type_create_struct( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         array_of_types, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: array_of_blocklengths(count)
         integer(MPI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
         type(MPI_Datatype), intent(in) :: array_of_types(count)
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_struct

      subroutine MPI_Type_create_subarray( &
         ndims, &
         array_of_sizes, &
         array_of_subsizes, &
         array_of_starts, &
         order, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: ndims
         integer, intent(in) :: array_of_sizes(ndims)
         integer, intent(in) :: array_of_subsizes(ndims)
         integer, intent(in) :: array_of_starts(ndims)
         integer, intent(in) :: order
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_subarray

      subroutine MPI_Type_dup( &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_dup

      subroutine MPI_Type_free( &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(out) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_free

      subroutine MPI_Type_get_contents( &
         datatype, &
         max_integers, &
         max_addresses, &
         max_datatypes, &
         array_of_integers, &
         array_of_addresses, &
         array_of_datatypes, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: max_integers
         integer, intent(in) :: max_addresses
         integer, intent(in) :: max_datatypes
         integer, intent(out) :: array_of_integers
         integer(MPI_ADDRESS_KIND), intent(out) :: array_of_addresses
         type(MPI_Datatype), intent(out) :: array_of_datatypes
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_contents

      subroutine MPI_Type_get_envelope( &
         datatype, &
         num_integers, &
         num_addresses, &
         num_datatypes, &
         combiner, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: num_integers
         integer, intent(out) :: num_addresses
         integer, intent(out) :: num_datatypes
         integer, intent(out) :: combiner
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_envelope

      subroutine MPI_Type_get_extent( &
         datatype, &
         lb, &
         extent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: lb
         integer(MPI_ADDRESS_KIND), intent(out) :: extent
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_extent

      subroutine MPI_Type_get_true_extent( &
         datatype, &
         true_lb, &
         true_extent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: true_lb
         integer(MPI_ADDRESS_KIND), intent(out) :: true_extent
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_true_extent

      subroutine MPI_Type_indexed( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: array_of_blocklengths(count)
         integer, intent(in) :: array_of_displacements(count)
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_indexed

      subroutine MPI_Type_size( &
         datatype, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Type_size

      subroutine MPI_Type_vector( &
         count, &
         blocklength, &
         stride, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: blocklength
         integer, intent(in) :: stride
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_vector

      subroutine MPI_Unpack( &
         inbuf, &
         insize, &
         position, &
         outbuf, &
         outcount, &
         datatype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) inbuf
         !gcc$ attributes no_arg_check :: inbuf
         integer, intent(in) :: inbuf(*)
         integer, intent(in) :: insize
         integer, intent(out) :: position
         !dir$ ignore_tkr(tkr) outbuf
         !gcc$ attributes no_arg_check :: outbuf
         integer :: outbuf(*)
         integer, intent(in) :: outcount
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Unpack

      subroutine MPI_Unpack_external( &
         datarep, &
         inbuf, &
         insize, &
         position, &
         outbuf, &
         outcount, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: datarep
         !dir$ ignore_tkr(tkr) inbuf
         !gcc$ attributes no_arg_check :: inbuf
         integer, intent(in) :: inbuf(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: insize
         integer(MPI_ADDRESS_KIND), intent(out) :: position
         !dir$ ignore_tkr(tkr) outbuf
         !gcc$ attributes no_arg_check :: outbuf
         integer :: outbuf(*)
         integer, intent(in) :: outcount
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_Unpack_external

      subroutine MPI_Allgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Allgather

      subroutine MPI_Allgather_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Allgather_init

      subroutine MPI_Allgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Allgatherv

      subroutine MPI_Allgatherv_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Allgatherv_init

      subroutine MPI_Allreduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Allreduce

      subroutine MPI_Allreduce_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Allreduce_init

      subroutine MPI_Alltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Alltoall

      subroutine MPI_Alltoall_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Alltoall_init

      subroutine MPI_Alltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Alltoallv

      subroutine MPI_Alltoallv_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Alltoallv_init

      subroutine MPI_Alltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtypes(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtypes(*)
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Alltoallw

      subroutine MPI_Alltoallw_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtypes(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtypes(*)
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Alltoallw_init

      subroutine MPI_Barrier( &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Barrier

      subroutine MPI_Barrier_init( &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Barrier_init

      subroutine MPI_Bcast( &
         buffer, &
         count, &
         datatype, &
         root, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buffer
         !gcc$ attributes no_arg_check :: buffer
         integer :: buffer(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Bcast

      subroutine MPI_Bcast_init( &
         buffer, &
         count, &
         datatype, &
         root, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buffer
         !gcc$ attributes no_arg_check :: buffer
         integer :: buffer(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Bcast_init

      subroutine MPI_Exscan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Exscan

      subroutine MPI_Exscan_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Exscan_init

      subroutine MPI_Gather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Gather

      subroutine MPI_Gather_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Gather_init

      subroutine MPI_Gatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         root, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Gatherv

      subroutine MPI_Gatherv_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Gatherv_init

      subroutine MPI_Iallgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iallgather

      subroutine MPI_Iallgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iallgatherv

      subroutine MPI_Iallreduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iallreduce

      subroutine MPI_Ialltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ialltoall

      subroutine MPI_Ialltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ialltoallv

      subroutine MPI_Ialltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtypes(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtypes(*)
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ialltoallw

      subroutine MPI_Ibarrier( &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ibarrier

      subroutine MPI_Ibcast( &
         buffer, &
         count, &
         datatype, &
         root, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buffer
         !gcc$ attributes no_arg_check :: buffer
         integer :: buffer(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ibcast

      subroutine MPI_Iexscan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iexscan

      subroutine MPI_Igather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Igather

      subroutine MPI_Igatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         root, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Igatherv

      subroutine MPI_Ireduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         root, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ireduce

      subroutine MPI_Ireduce_scatter( &
         sendbuf, &
         recvbuf, &
         recvcounts, &
         datatype, &
         op, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ireduce_scatter

      subroutine MPI_Ireduce_scatter_block( &
         sendbuf, &
         recvbuf, &
         recvcount, &
         datatype, &
         op, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ireduce_scatter_block

      subroutine MPI_Iscan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iscan

      subroutine MPI_Iscatter( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iscatter

      subroutine MPI_Iscatterv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Iscatterv

      subroutine MPI_Op_commutative( &
         op, &
         commute, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Op), intent(in) :: op
         logical, intent(out) :: commute
         integer, intent(out) :: ierror
      end subroutine MPI_Op_commutative

      subroutine MPI_Op_create( &
         user_fn, &
         commute, &
         op, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: user_fn
         logical, intent(in) :: commute
         type(MPI_Op), intent(out) :: op
         integer, intent(out) :: ierror
      end subroutine MPI_Op_create

      subroutine MPI_Op_free( &
         op, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Op), intent(out) :: op
         integer, intent(out) :: ierror
      end subroutine MPI_Op_free

      subroutine MPI_Reduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         root, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce

      subroutine MPI_Reduce_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         root, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce_init

      subroutine MPI_Reduce_local( &
         inbuf, &
         inoutbuf, &
         count, &
         datatype, &
         op, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) inbuf
         !gcc$ attributes no_arg_check :: inbuf
         integer, intent(in) :: inbuf(*)
         !dir$ ignore_tkr(tkr) inoutbuf
         !gcc$ attributes no_arg_check :: inoutbuf
         integer :: inoutbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce_local

      subroutine MPI_Reduce_scatter( &
         sendbuf, &
         recvbuf, &
         recvcounts, &
         datatype, &
         op, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce_scatter

      subroutine MPI_Reduce_scatter_block( &
         sendbuf, &
         recvbuf, &
         recvcount, &
         datatype, &
         op, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce_scatter_block

      subroutine MPI_Reduce_scatter_block_init( &
         sendbuf, &
         recvbuf, &
         recvcount, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce_scatter_block_init

      subroutine MPI_Reduce_scatter_init( &
         sendbuf, &
         recvbuf, &
         recvcounts, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Reduce_scatter_init

      subroutine MPI_Scan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Scan

      subroutine MPI_Scan_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Scan_init

      subroutine MPI_Scatter( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Scatter

      subroutine MPI_Scatter_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Scatter_init

      subroutine MPI_Scatterv( &
         sendbuf, &
         sendcounts, &
         displs, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Scatterv

      subroutine MPI_Scatterv_init( &
         sendbuf, &
         sendcounts, &
         displs, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Scatterv_init

      subroutine MPI_Type_get_value_index( &
         value_type, &
         index_type, &
         pair_type, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: value_type
         type(MPI_Datatype), intent(in) :: index_type
         type(MPI_Datatype), intent(out) :: pair_type
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_value_index

      subroutine MPI_Comm_compare( &
         comm1, &
         comm2, &
         result, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm1
         type(MPI_Comm), intent(in) :: comm2
         integer, intent(out) :: result
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_compare

      subroutine MPI_Comm_create( &
         comm, &
         group, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Group), intent(in) :: group
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_create

      subroutine MPI_Comm_create_from_group( &
         group, &
         stringtag, &
         info, &
         errhandler, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         character(*), intent(in) :: stringtag
         type(MPI_Info), intent(in) :: info
         type(MPI_Errhandler), intent(in) :: errhandler
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_create_from_group

      subroutine MPI_Comm_create_group( &
         comm, &
         group, &
         tag, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: tag
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_create_group

      subroutine MPI_Comm_create_keyval( &
         comm_copy_attr_fn, &
         comm_delete_attr_fn, &
         comm_keyval, &
         extra_state, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: comm_copy_attr_fn
         external :: comm_delete_attr_fn
         integer, intent(out) :: comm_keyval
         !dir$ ignore_tkr(tkr) extra_state
         !gcc$ attributes no_arg_check :: extra_state
         integer :: extra_state(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_create_keyval

      subroutine MPI_Comm_delete_attr( &
         comm, &
         comm_keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: comm_keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_delete_attr

      subroutine MPI_Comm_dup( &
         comm, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_dup

      subroutine MPI_Comm_dup_with_info( &
         comm, &
         info, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_dup_with_info

      subroutine MPI_Comm_free( &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(out) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_free

      subroutine MPI_Comm_get_name( &
         comm, &
         comm_name, &
         resultlen, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         character(*), intent(out) :: comm_name
         integer, intent(out) :: resultlen
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_get_name

      subroutine MPI_Comm_free_keyval( &
         comm_keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: comm_keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_free_keyval

      subroutine MPI_Comm_get_attr( &
         comm, &
         comm_keyval, &
         attribute_val, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: comm_keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_get_attr

      subroutine MPI_Comm_get_info( &
         comm, &
         info_used, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(out) :: info_used
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_get_info

      subroutine MPI_Comm_group( &
         comm, &
         group, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Group), intent(out) :: group
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_group

      subroutine MPI_Comm_idup( &
         comm, &
         newcomm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Comm), intent(out) :: newcomm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_idup

      subroutine MPI_Comm_idup_with_info( &
         comm, &
         info, &
         newcomm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(out) :: newcomm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_idup_with_info

      subroutine MPI_Comm_rank( &
         comm, &
         rank, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: rank
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_rank

      subroutine MPI_Comm_remote_group( &
         comm, &
         group, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Group), intent(out) :: group
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_remote_group

      subroutine MPI_Comm_remote_size( &
         comm, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_remote_size

      subroutine MPI_Comm_set_attr( &
         comm, &
         comm_keyval, &
         attribute_val, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: comm_keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_set_attr

      subroutine MPI_Comm_set_info( &
         comm, &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_set_info

      subroutine MPI_Comm_set_name( &
         comm, &
         comm_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         character(*), intent(in) :: comm_name
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_set_name

      subroutine MPI_Comm_size( &
         comm, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_size

      subroutine MPI_Comm_split( &
         comm, &
         color, &
         key, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: color
         integer, intent(in) :: key
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_split

      subroutine MPI_Group_free( &
         group, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(out) :: group
         integer, intent(out) :: ierror
      end subroutine MPI_Group_free

      subroutine MPI_Comm_split_type( &
         comm, &
         split_type, &
         key, &
         info, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: split_type
         integer, intent(in) :: key
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_split_type

      subroutine MPI_Comm_test_inter( &
         comm, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_test_inter

      subroutine MPI_Group_compare( &
         group1, &
         group2, &
         result, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group1
         type(MPI_Group), intent(in) :: group2
         integer, intent(out) :: result
         integer, intent(out) :: ierror
      end subroutine MPI_Group_compare

      subroutine MPI_Group_difference( &
         group1, &
         group2, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group1
         type(MPI_Group), intent(in) :: group2
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_difference

      subroutine MPI_Group_excl( &
         group, &
         n, &
         ranks, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: n
         integer, intent(in) :: ranks(n)
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_excl

      subroutine MPI_Group_from_session_pset( &
         session, &
         pset_name, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         character(*), intent(in) :: pset_name
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_from_session_pset

      subroutine MPI_Group_incl( &
         group, &
         n, &
         ranks, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: n
         integer, intent(in) :: ranks(n)
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_incl

      subroutine MPI_Group_intersection( &
         group1, &
         group2, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group1
         type(MPI_Group), intent(in) :: group2
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_intersection

      subroutine MPI_Group_range_excl( &
         group, &
         n, &
         ranges, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: n
         integer, intent(in) :: ranges(n)
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_range_excl

      subroutine MPI_Group_range_incl( &
         group, &
         n, &
         ranges, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: n
         integer, intent(in) :: ranges(n)
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_range_incl

      subroutine MPI_Group_rank( &
         group, &
         rank, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(out) :: rank
         integer, intent(out) :: ierror
      end subroutine MPI_Group_rank

      subroutine MPI_Group_size( &
         group, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Group_size

      subroutine MPI_Group_translate_ranks( &
         group1, &
         n, &
         ranks1, &
         group2, &
         ranks2, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group1
         integer, intent(in) :: n
         integer, intent(in) :: ranks1(n)
         type(MPI_Group), intent(in) :: group2
         integer, intent(in) :: ranks2(n)
         integer, intent(out) :: ierror
      end subroutine MPI_Group_translate_ranks

      subroutine MPI_Group_union( &
         group1, &
         group2, &
         newgroup, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group1
         type(MPI_Group), intent(in) :: group2
         type(MPI_Group), intent(out) :: newgroup
         integer, intent(out) :: ierror
      end subroutine MPI_Group_union

      subroutine MPI_Intercomm_create( &
         local_comm, &
         local_leader, &
         peer_comm, &
         remote_leader, &
         tag, &
         newintercomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: local_comm
         integer, intent(in) :: local_leader
         type(MPI_Comm), intent(in) :: peer_comm
         integer, intent(in) :: remote_leader
         integer, intent(in) :: tag
         type(MPI_Comm), intent(out) :: newintercomm
         integer, intent(out) :: ierror
      end subroutine MPI_Intercomm_create

      subroutine MPI_Intercomm_create_from_groups( &
         local_group, &
         local_leader, &
         remote_group, &
         remote_leader, &
         stringtag, &
         info, &
         errhandler, &
         newintercomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: local_group
         integer, intent(in) :: local_leader
         type(MPI_Group), intent(in) :: remote_group
         integer, intent(in) :: remote_leader
         character(*), intent(in) :: stringtag
         type(MPI_Info), intent(in) :: info
         type(MPI_Errhandler), intent(in) :: errhandler
         type(MPI_Comm), intent(out) :: newintercomm
         integer, intent(out) :: ierror
      end subroutine MPI_Intercomm_create_from_groups

      subroutine MPI_Intercomm_merge( &
         intercomm, &
         high, &
         newintracomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: intercomm
         integer, intent(in) :: high
         type(MPI_Comm), intent(out) :: newintracomm
         integer, intent(out) :: ierror
      end subroutine MPI_Intercomm_merge

      subroutine MPI_Type_create_keyval( &
         type_copy_attr_fn, &
         type_delete_attr_fn, &
         type_keyval, &
         extra_state, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: type_copy_attr_fn
         external :: type_delete_attr_fn
         integer, intent(out) :: type_keyval
         !dir$ ignore_tkr(tkr) extra_state
         !gcc$ attributes no_arg_check :: extra_state
         integer :: extra_state(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_keyval

      subroutine MPI_Type_delete_attr( &
         datatype, &
         type_keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: type_keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Type_delete_attr

      subroutine MPI_Type_free_keyval( &
         type_keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: type_keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Type_free_keyval

      subroutine MPI_Type_get_attr( &
         datatype, &
         type_keyval, &
         attribute_val, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: type_keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_attr

      subroutine MPI_Type_get_name( &
         datatype, &
         type_name, &
         resultlen, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         character(*), intent(out) :: type_name
         integer, intent(out) :: resultlen
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_name

      subroutine MPI_Type_set_attr( &
         datatype, &
         type_keyval, &
         attribute_val, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: type_keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Type_set_attr

      subroutine MPI_Type_set_name( &
         datatype, &
         type_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         character(*), intent(in) :: type_name
         integer, intent(out) :: ierror
      end subroutine MPI_Type_set_name

      subroutine MPI_Win_create_keyval( &
         win_copy_attr_fn, &
         win_delete_attr_fn, &
         win_keyval, &
         extra_state, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: win_copy_attr_fn
         external :: win_delete_attr_fn
         integer, intent(out) :: win_keyval
         !dir$ ignore_tkr(tkr) extra_state
         !gcc$ attributes no_arg_check :: extra_state
         integer :: extra_state(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Win_create_keyval

      subroutine MPI_Win_delete_attr( &
         win, &
         win_keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(in) :: win_keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Win_delete_attr

      subroutine MPI_Win_free_keyval( &
         win_keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: win_keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Win_free_keyval

      subroutine MPI_Win_get_attr( &
         win, &
         win_keyval, &
         attribute_val, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(in) :: win_keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Win_get_attr

      subroutine MPI_Win_get_name( &
         win, &
         win_name, &
         resultlen, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         character(*), intent(out) :: win_name
         integer, intent(out) :: resultlen
         integer, intent(out) :: ierror
      end subroutine MPI_Win_get_name

      subroutine MPI_Win_set_attr( &
         win, &
         win_keyval, &
         attribute_val, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(in) :: win_keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Win_set_attr

      subroutine MPI_Win_set_name( &
         win, &
         win_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         character(*), intent(in) :: win_name
         integer, intent(out) :: ierror
      end subroutine MPI_Win_set_name

      subroutine MPI_Cart_coords( &
         comm, &
         rank, &
         maxdims, &
         coords, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: rank
         integer, intent(in) :: maxdims
         integer, intent(out) :: coords(maxdims)
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_coords

      subroutine MPI_Cart_create( &
         comm_old, &
         ndims, &
         dims, &
         periods, &
         reorder, &
         comm_cart, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm_old
         integer, intent(in) :: ndims
         integer, intent(in) :: dims(ndims)
         logical, intent(in) :: periods(ndims)
         logical, intent(in) :: reorder
         type(MPI_Comm), intent(out) :: comm_cart
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_create

      subroutine MPI_Cart_get( &
         comm, &
         maxdims, &
         dims, &
         periods, &
         coords, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: maxdims
         integer, intent(out) :: dims(maxdims)
         integer, intent(out) :: periods(maxdims)
         integer, intent(out) :: coords(maxdims)
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_get

      subroutine MPI_Cart_map( &
         comm, &
         ndims, &
         dims, &
         periods, &
         newrank, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: ndims
         integer, intent(in) :: dims(ndims)
         integer, intent(in) :: periods(ndims)
         integer, intent(out) :: newrank
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_map

      subroutine MPI_Cart_rank( &
         comm, &
         coords, &
         rank, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: coords(*)
         integer, intent(out) :: rank
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_rank

      subroutine MPI_Cart_shift( &
         comm, &
         direction, &
         disp, &
         rank_source, &
         rank_dest, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: direction
         integer, intent(in) :: disp
         integer, intent(out) :: rank_source
         integer, intent(out) :: rank_dest
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_shift

      subroutine MPI_Cart_sub( &
         comm, &
         remain_dims, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         logical, intent(in) :: remain_dims(*)
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Cart_sub

      subroutine MPI_Cartdim_get( &
         comm, &
         ndims, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ndims
         integer, intent(out) :: ierror
      end subroutine MPI_Cartdim_get

      subroutine MPI_Dims_create( &
         nnodes, &
         ndims, &
         dims, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: nnodes
         integer, intent(in) :: ndims
         integer, intent(in) :: dims(ndims)
         integer, intent(out) :: ierror
      end subroutine MPI_Dims_create

      subroutine MPI_Dist_graph_create( &
         comm_old, &
         n, &
         sources, &
         degrees, &
         destinations, &
         weights, &
         info, &
         reorder, &
         comm_dist_graph, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm_old
         integer, intent(in) :: n
         integer, intent(in) :: sources(n)
         integer, intent(in) :: degrees(n)
         integer, intent(in) :: destinations(*)
         integer, intent(in) :: weights(*)
         type(MPI_Info), intent(in) :: info
         logical, intent(in) :: reorder
         type(MPI_Comm), intent(out) :: comm_dist_graph
         integer, intent(out) :: ierror
      end subroutine MPI_Dist_graph_create

      subroutine MPI_Dist_graph_create_adjacent( &
         comm_old, &
         indegree, &
         sources, &
         sourceweights, &
         outdegree, &
         destinations, &
         destweights, &
         info, &
         reorder, &
         comm_dist_graph, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm_old
         integer, intent(in) :: indegree
         integer, intent(in) :: sources(indegree)
         integer, intent(in) :: sourceweights(*)
         integer, intent(in) :: outdegree
         integer, intent(in) :: destinations(outdegree)
         integer, intent(in) :: destweights(*)
         type(MPI_Info), intent(in) :: info
         integer, intent(in) :: reorder
         type(MPI_Comm), intent(out) :: comm_dist_graph
         integer, intent(out) :: ierror
      end subroutine MPI_Dist_graph_create_adjacent

      subroutine MPI_Dist_graph_neighbors( &
         comm, &
         maxindegree, &
         sources, &
         sourceweights, &
         maxoutdegree, &
         destinations, &
         destweights, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: maxindegree
         integer, intent(out) :: sources(maxindegree)
         integer, intent(out) :: sourceweights(*)
         integer, intent(in) :: maxoutdegree
         integer, intent(out) :: destinations(maxoutdegree)
         integer, intent(out) :: destweights(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Dist_graph_neighbors

      subroutine MPI_Dist_graph_neighbors_count( &
         comm, &
         indegree, &
         outdegree, &
         weighted, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: indegree
         integer, intent(out) :: outdegree
         integer, intent(out) :: weighted
         integer, intent(out) :: ierror
      end subroutine MPI_Dist_graph_neighbors_count

      subroutine MPI_Graph_create( &
         comm_old, &
         nnodes, &
         index, &
         edges, &
         reorder, &
         comm_graph, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm_old
         integer, intent(in) :: nnodes
         integer, intent(in) :: index(nnodes)
         integer, intent(in) :: edges(nnodes)
         integer, intent(in) :: reorder
         type(MPI_Comm), intent(out) :: comm_graph
         integer, intent(out) :: ierror
      end subroutine MPI_Graph_create

      subroutine MPI_Graph_get( &
         comm, &
         maxindex, &
         maxedges, &
         index, &
         edges, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: maxindex
         integer, intent(in) :: maxedges
         integer, intent(out) :: index(maxindex)
         integer, intent(out) :: edges(maxedges)
         integer, intent(out) :: ierror
      end subroutine MPI_Graph_get

      subroutine MPI_Graph_map( &
         comm, &
         nnodes, &
         index, &
         edges, &
         newrank, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: nnodes
         integer, intent(in) :: index(nnodes)
         integer, intent(in) :: edges(nnodes)
         integer, intent(out) :: newrank
         integer, intent(out) :: ierror
      end subroutine MPI_Graph_map

      subroutine MPI_Graph_neighbors( &
         comm, &
         rank, &
         maxneighbors, &
         neighbors, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: rank
         integer, intent(in) :: maxneighbors
         integer, intent(out) :: neighbors(maxneighbors)
         integer, intent(out) :: ierror
      end subroutine MPI_Graph_neighbors

      subroutine MPI_Graph_neighbors_count( &
         comm, &
         rank, &
         nneighbors, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: rank
         integer, intent(out) :: nneighbors
         integer, intent(out) :: ierror
      end subroutine MPI_Graph_neighbors_count

      subroutine MPI_Graphdims_get( &
         comm, &
         nnodes, &
         nedges, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: nnodes
         integer, intent(out) :: nedges
         integer, intent(out) :: ierror
      end subroutine MPI_Graphdims_get

      subroutine MPI_Ineighbor_allgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ineighbor_allgather

      subroutine MPI_Ineighbor_allgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ineighbor_allgatherv

      subroutine MPI_Ineighbor_alltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ineighbor_alltoall

      subroutine MPI_Ineighbor_alltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ineighbor_alltoallv

      subroutine MPI_Ineighbor_alltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtypes(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtypes(*)
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Ineighbor_alltoallw

      subroutine MPI_Neighbor_allgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_allgather

      subroutine MPI_Neighbor_allgather_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_allgather_init

      subroutine MPI_Neighbor_allgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_allgatherv

      subroutine MPI_Neighbor_allgatherv_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: displs(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_allgatherv_init

      subroutine MPI_Neighbor_alltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_alltoall

      subroutine MPI_Neighbor_alltoall_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcount
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcount
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_alltoall_init

      subroutine MPI_Neighbor_alltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_alltoallv

      subroutine MPI_Neighbor_alltoallv_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer, intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtype
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer, intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtype
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_alltoallv_init

      subroutine MPI_Neighbor_alltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtypes(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtypes(*)
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_alltoallw

      subroutine MPI_Neighbor_alltoallw_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         info, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) sendbuf
         !gcc$ attributes no_arg_check :: sendbuf
         integer, intent(in) :: sendbuf(*)
         integer, intent(in) :: sendcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: sdispls(*)
         type(MPI_Datatype), intent(in) :: sendtypes(*)
         !dir$ ignore_tkr(tkr) recvbuf
         !gcc$ attributes no_arg_check :: recvbuf
         integer :: recvbuf(*)
         integer, intent(in) :: recvcounts(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: rdispls(*)
         type(MPI_Datatype), intent(in) :: recvtypes(*)
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Info), intent(in) :: info
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Neighbor_alltoallw_init

      subroutine MPI_Topo_test( &
         comm, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_Topo_test

      subroutine MPI_Add_error_class( &
         errorclass, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: errorclass
         integer, intent(out) :: ierror
      end subroutine MPI_Add_error_class

      subroutine MPI_Add_error_code( &
         errorclass, &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorclass
         integer, intent(out) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Add_error_code

      subroutine MPI_Add_error_string( &
         errorcode, &
         string, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorcode
         character(*), intent(in) :: string
         integer, intent(out) :: ierror
      end subroutine MPI_Add_error_string

      subroutine MPI_Alloc_mem( &
         size, &
         info, &
         baseptr, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer(MPI_ADDRESS_KIND), intent(in) :: size
         type(MPI_Info), intent(in) :: info
         !dir$ ignore_tkr(tkr) baseptr
         !gcc$ attributes no_arg_check :: baseptr
         integer :: baseptr(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Alloc_mem

      subroutine MPI_Comm_call_errhandler( &
         comm, &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_call_errhandler

      subroutine MPI_Comm_create_errhandler( &
         comm_errhandler_fn, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: comm_errhandler_fn
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_create_errhandler

      subroutine MPI_Comm_get_errhandler( &
         comm, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_get_errhandler

      subroutine MPI_Comm_set_errhandler( &
         comm, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Errhandler), intent(in) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_set_errhandler

      subroutine MPI_Errhandler_free( &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Errhandler_free

      subroutine MPI_Error_class( &
         errorcode, &
         errorclass, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorcode
         integer, intent(out) :: errorclass
         integer, intent(out) :: ierror
      end subroutine MPI_Error_class

      subroutine MPI_Error_string( &
         errorcode, &
         string, &
         resultlen, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorcode
         character(*), intent(out) :: string
         integer, intent(out) :: resultlen
         integer, intent(out) :: ierror
      end subroutine MPI_Error_string

      subroutine MPI_File_call_errhandler( &
         fh, &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_File_call_errhandler

      subroutine MPI_File_create_errhandler( &
         file_errhandler_fn, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: file_errhandler_fn
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_File_create_errhandler

      subroutine MPI_File_get_errhandler( &
         file, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: file
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_errhandler

      subroutine MPI_File_set_errhandler( &
         file, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: file
         type(MPI_Errhandler), intent(in) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_File_set_errhandler

      subroutine MPI_Free_mem( &
         base, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) base
         !gcc$ attributes no_arg_check :: base
         integer :: base(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Free_mem

      subroutine MPI_Get_hw_resource_info( &
         hw_info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(out) :: hw_info
         integer, intent(out) :: ierror
      end subroutine MPI_Get_hw_resource_info

      subroutine MPI_Get_library_version( &
         version, &
         resultlen, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(out) :: version
         integer, intent(out) :: resultlen
         integer, intent(out) :: ierror
      end subroutine MPI_Get_library_version

      subroutine MPI_Get_processor_name( &
         name, &
         resultlen, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(out) :: name
         integer, intent(out) :: resultlen
         integer, intent(out) :: ierror
      end subroutine MPI_Get_processor_name

      subroutine MPI_Get_version( &
         version, &
         subversion, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: version
         integer, intent(out) :: subversion
         integer, intent(out) :: ierror
      end subroutine MPI_Get_version

      subroutine MPI_Remove_error_class( &
         errorclass, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorclass
         integer, intent(out) :: ierror
      end subroutine MPI_Remove_error_class

      subroutine MPI_Remove_error_code( &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Remove_error_code

      subroutine MPI_Remove_error_string( &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Remove_error_string

      subroutine MPI_Session_call_errhandler( &
         session, &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Session_call_errhandler

      subroutine MPI_Session_create_errhandler( &
         session_errhandler_fn, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: session_errhandler_fn
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Session_create_errhandler

      subroutine MPI_Session_get_errhandler( &
         session, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Session_get_errhandler

      subroutine MPI_Session_set_errhandler( &
         session, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         type(MPI_Errhandler), intent(in) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Session_set_errhandler

      subroutine MPI_Win_call_errhandler( &
         win, &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Win_call_errhandler

      subroutine MPI_Win_create_errhandler( &
         win_errhandler_fn, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: win_errhandler_fn
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Win_create_errhandler

      subroutine MPI_Win_get_errhandler( &
         win, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         type(MPI_Errhandler), intent(out) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Win_get_errhandler

      subroutine MPI_Win_set_errhandler( &
         win, &
         errhandler, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         type(MPI_Errhandler), intent(in) :: errhandler
         integer, intent(out) :: ierror
      end subroutine MPI_Win_set_errhandler

      function MPI_Wtick( &
      ) result(result)
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         double precision :: result
      end function MPI_Wtick

      function MPI_Wtime( &
      ) result(result)
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         double precision :: result
      end function MPI_Wtime

      subroutine MPI_Info_create( &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(out) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_Info_create

      subroutine MPI_Info_create_env( &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(out) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_Info_create_env

      subroutine MPI_Info_delete( &
         info, &
         key, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: key
         integer, intent(out) :: ierror
      end subroutine MPI_Info_delete

      subroutine MPI_Info_dup( &
         info, &
         newinfo, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         type(MPI_Info), intent(out) :: newinfo
         integer, intent(out) :: ierror
      end subroutine MPI_Info_dup

      subroutine MPI_Info_free( &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(out) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_Info_free

      subroutine MPI_Info_get_nkeys( &
         info, &
         nkeys, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: nkeys
         integer, intent(out) :: ierror
      end subroutine MPI_Info_get_nkeys

      subroutine MPI_Info_get_nthkey( &
         info, &
         n, &
         key, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         integer, intent(in) :: n
         character(*), intent(out) :: key
         integer, intent(out) :: ierror
      end subroutine MPI_Info_get_nthkey

      subroutine MPI_Info_get_string( &
         info, &
         key, &
         buflen, &
         value, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: key
         integer, intent(out) :: buflen
         character(*), intent(out) :: value
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Info_get_string

      subroutine MPI_Info_set( &
         info, &
         key, &
         value, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: key
         character(*), intent(in) :: value
         integer, intent(out) :: ierror
      end subroutine MPI_Info_set

      subroutine MPI_Abort( &
         comm, &
         errorcode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: errorcode
         integer, intent(out) :: ierror
      end subroutine MPI_Abort

      subroutine MPI_Close_port( &
         port_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: port_name
         integer, intent(out) :: ierror
      end subroutine MPI_Close_port

      subroutine MPI_Comm_accept( &
         port_name, &
         info, &
         root, &
         comm, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: port_name
         type(MPI_Info), intent(in) :: info
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_accept

      subroutine MPI_Comm_connect( &
         port_name, &
         info, &
         root, &
         comm, &
         newcomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: port_name
         type(MPI_Info), intent(in) :: info
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Comm), intent(out) :: newcomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_connect

      subroutine MPI_Comm_disconnect( &
         comm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(out) :: comm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_disconnect

      subroutine MPI_Comm_get_parent( &
         parent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(out) :: parent
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_get_parent

      subroutine MPI_Comm_join( &
         fd, &
         intercomm, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: fd
         type(MPI_Comm), intent(out) :: intercomm
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_join

      subroutine MPI_Comm_spawn( &
         command, &
         argv, &
         maxprocs, &
         info, &
         root, &
         comm, &
         intercomm, &
         array_of_errcodes, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: command
         character(*), intent(in) :: argv(*)
         integer, intent(in) :: maxprocs
         type(MPI_Info), intent(in) :: info
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Comm), intent(out) :: intercomm
         integer, intent(out) :: array_of_errcodes(maxprocs)
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_spawn

      subroutine MPI_Comm_spawn_multiple( &
         count, &
         array_of_commands, &
         array_of_argv, &
         array_of_maxprocs, &
         array_of_info, &
         root, &
         comm, &
         intercomm, &
         array_of_errcodes, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         character(*), intent(in) :: array_of_commands(count)
         character(*), intent(in) :: array_of_argv(count, *)
         integer, intent(in) :: array_of_maxprocs(count)
         type(MPI_Info), intent(in) :: array_of_info(count)
         integer, intent(in) :: root
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Comm), intent(out) :: intercomm
         integer, intent(out) :: array_of_errcodes(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Comm_spawn_multiple

      subroutine MPI_Finalize( &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: ierror
      end subroutine MPI_Finalize

      subroutine MPI_Finalized( &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Finalized

      subroutine MPI_Init( &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: ierror
      end subroutine MPI_Init

      subroutine MPI_Init_thread( &
         required, &
         provided, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: required
         integer, intent(out) :: provided
         integer, intent(out) :: ierror
      end subroutine MPI_Init_thread

      subroutine MPI_Initialized( &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Initialized

      subroutine MPI_Is_thread_main( &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Is_thread_main

      subroutine MPI_Lookup_name( &
         service_name, &
         info, &
         port_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: service_name
         type(MPI_Info), intent(in) :: info
         character(*), intent(out) :: port_name
         integer, intent(out) :: ierror
      end subroutine MPI_Lookup_name

      subroutine MPI_Open_port( &
         info, &
         port_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         character(*), intent(out) :: port_name
         integer, intent(out) :: ierror
      end subroutine MPI_Open_port

      subroutine MPI_Publish_name( &
         service_name, &
         info, &
         port_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: service_name
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: port_name
         integer, intent(out) :: ierror
      end subroutine MPI_Publish_name

      subroutine MPI_Query_thread( &
         provided, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: provided
         integer, intent(out) :: ierror
      end subroutine MPI_Query_thread

      subroutine MPI_Session_finalize( &
         session, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(out) :: session
         integer, intent(out) :: ierror
      end subroutine MPI_Session_finalize

      subroutine MPI_Session_get_info( &
         session, &
         info_used, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         type(MPI_Info), intent(out) :: info_used
         integer, intent(out) :: ierror
      end subroutine MPI_Session_get_info

      subroutine MPI_Session_get_nth_pset( &
         session, &
         info, &
         n, &
         pset_len, &
         pset_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         type(MPI_Info), intent(in) :: info
         integer, intent(in) :: n
         integer, intent(out) :: pset_len
         character(*), intent(out) :: pset_name
         integer, intent(out) :: ierror
      end subroutine MPI_Session_get_nth_pset

      subroutine MPI_Session_get_num_psets( &
         session, &
         info, &
         npset_names, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: npset_names
         integer, intent(out) :: ierror
      end subroutine MPI_Session_get_num_psets

      subroutine MPI_Session_get_pset_info( &
         session, &
         pset_name, &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Session), intent(in) :: session
         character(*), intent(in) :: pset_name
         type(MPI_Info), intent(out) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_Session_get_pset_info

      subroutine MPI_Session_init( &
         info, &
         errhandler, &
         session, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         type(MPI_Errhandler), intent(in) :: errhandler
         type(MPI_Session), intent(out) :: session
         integer, intent(out) :: ierror
      end subroutine MPI_Session_init

      subroutine MPI_Unpublish_name( &
         service_name, &
         info, &
         port_name, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: service_name
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: port_name
         integer, intent(out) :: ierror
      end subroutine MPI_Unpublish_name

      subroutine MPI_Accumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Accumulate

      subroutine MPI_Compare_and_swap( &
         origin_addr, &
         compare_addr, &
         result_addr, &
         datatype, &
         target_rank, &
         target_disp, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         !dir$ ignore_tkr(tkr) compare_addr
         !gcc$ attributes no_arg_check :: compare_addr
         integer, intent(in) :: compare_addr(*)
         !dir$ ignore_tkr(tkr) result_addr
         !gcc$ attributes no_arg_check :: result_addr
         integer :: result_addr(*)
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Compare_and_swap

      subroutine MPI_Fetch_and_op( &
         origin_addr, &
         result_addr, &
         datatype, &
         target_rank, &
         target_disp, &
         op, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         !dir$ ignore_tkr(tkr) result_addr
         !gcc$ attributes no_arg_check :: result_addr
         integer :: result_addr(*)
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         type(MPI_Op), intent(in) :: op
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Fetch_and_op

      subroutine MPI_Get( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Get

      subroutine MPI_Get_accumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         result_addr, &
         result_count, &
         result_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         !dir$ ignore_tkr(tkr) result_addr
         !gcc$ attributes no_arg_check :: result_addr
         integer :: result_addr(*)
         integer, intent(in) :: result_count
         type(MPI_Datatype), intent(in) :: result_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Get_accumulate

      subroutine MPI_Put( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Put

      subroutine MPI_Raccumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Win), intent(in) :: win
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Raccumulate

      subroutine MPI_Rget( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Win), intent(in) :: win
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Rget

      subroutine MPI_Rget_accumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         result_addr, &
         result_count, &
         result_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         !dir$ ignore_tkr(tkr) result_addr
         !gcc$ attributes no_arg_check :: result_addr
         integer :: result_addr(*)
         integer, intent(in) :: result_count
         type(MPI_Datatype), intent(in) :: result_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Op), intent(in) :: op
         type(MPI_Win), intent(in) :: win
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Rget_accumulate

      subroutine MPI_Rput( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) origin_addr
         !gcc$ attributes no_arg_check :: origin_addr
         integer, intent(in) :: origin_addr(*)
         integer, intent(in) :: origin_count
         type(MPI_Datatype), intent(in) :: origin_datatype
         integer, intent(in) :: target_rank
         integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
         integer, intent(in) :: target_count
         type(MPI_Datatype), intent(in) :: target_datatype
         type(MPI_Win), intent(in) :: win
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Rput

      subroutine MPI_Win_allocate( &
         size, &
         disp_unit, &
         info, &
         comm, &
         baseptr, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer(MPI_ADDRESS_KIND), intent(in) :: size
         integer, intent(in) :: disp_unit
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(in) :: comm
         !dir$ ignore_tkr(tkr) baseptr
         !gcc$ attributes no_arg_check :: baseptr
         integer :: baseptr(*)
         type(MPI_Win), intent(out) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_allocate

      subroutine MPI_Win_allocate_shared( &
         size, &
         disp_unit, &
         info, &
         comm, &
         baseptr, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer(MPI_ADDRESS_KIND), intent(in) :: size
         integer, intent(in) :: disp_unit
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(in) :: comm
         !dir$ ignore_tkr(tkr) baseptr
         !gcc$ attributes no_arg_check :: baseptr
         integer :: baseptr(*)
         type(MPI_Win), intent(out) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_allocate_shared

      subroutine MPI_Win_attach( &
         win, &
         base, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         !dir$ ignore_tkr(tkr) base
         !gcc$ attributes no_arg_check :: base
         integer :: base(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Win_attach

      subroutine MPI_Win_complete( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_complete

      subroutine MPI_Win_create( &
         base, &
         size, &
         disp_unit, &
         info, &
         comm, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) base
         !gcc$ attributes no_arg_check :: base
         integer :: base(*)
         integer(MPI_ADDRESS_KIND), intent(in) :: size
         integer, intent(in) :: disp_unit
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Win), intent(out) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_create

      subroutine MPI_Win_create_dynamic( &
         info, &
         comm, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         type(MPI_Comm), intent(in) :: comm
         type(MPI_Win), intent(out) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_create_dynamic

      subroutine MPI_Win_detach( &
         win, &
         base, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         !dir$ ignore_tkr(tkr) base
         !gcc$ attributes no_arg_check :: base
         integer, intent(in) :: base(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Win_detach

      subroutine MPI_Win_fence( &
         assert, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: assert
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_fence

      subroutine MPI_Win_flush( &
         rank, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: rank
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_flush

      subroutine MPI_Win_flush_all( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_flush_all

      subroutine MPI_Win_flush_local( &
         rank, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: rank
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_flush_local

      subroutine MPI_Win_flush_local_all( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_flush_local_all

      subroutine MPI_Win_free( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(out) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_free

      subroutine MPI_Win_get_group( &
         win, &
         group, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         type(MPI_Group), intent(out) :: group
         integer, intent(out) :: ierror
      end subroutine MPI_Win_get_group

      subroutine MPI_Win_get_info( &
         win, &
         info_used, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         type(MPI_Info), intent(out) :: info_used
         integer, intent(out) :: ierror
      end subroutine MPI_Win_get_info

      subroutine MPI_Win_lock( &
         lock_type, &
         rank, &
         assert, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: lock_type
         integer, intent(in) :: rank
         integer, intent(in) :: assert
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_lock

      subroutine MPI_Win_lock_all( &
         assert, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: assert
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_lock_all

      subroutine MPI_Win_post( &
         group, &
         assert, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: assert
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_post

      subroutine MPI_Win_set_info( &
         win, &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_Win_set_info

      subroutine MPI_Win_shared_query( &
         win, &
         rank, &
         size, &
         disp_unit, &
         baseptr, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(in) :: rank
         integer(MPI_ADDRESS_KIND), intent(out) :: size
         integer, intent(out) :: disp_unit
         !dir$ ignore_tkr(tkr) baseptr
         !gcc$ attributes no_arg_check :: baseptr
         integer :: baseptr(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Win_shared_query

      subroutine MPI_Win_start( &
         group, &
         assert, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Group), intent(in) :: group
         integer, intent(in) :: assert
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_start

      subroutine MPI_Win_sync( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_sync

      subroutine MPI_Win_test( &
         win, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Win_test

      subroutine MPI_Win_unlock( &
         rank, &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: rank
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_unlock

      subroutine MPI_Win_unlock_all( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_unlock_all

      subroutine MPI_Win_wait( &
         win, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Win), intent(in) :: win
         integer, intent(out) :: ierror
      end subroutine MPI_Win_wait

      subroutine MPI_Grequest_complete( &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Request), intent(in) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Grequest_complete

      subroutine MPI_Grequest_start( &
         query_fn, &
         free_fn, &
         cancel_fn, &
         extra_state, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: query_fn
         external :: free_fn
         external :: cancel_fn
         !dir$ ignore_tkr(tkr) extra_state
         !gcc$ attributes no_arg_check :: extra_state
         integer :: extra_state(*)
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_Grequest_start

      subroutine MPI_Status_set_cancelled( &
         status, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(out) :: status
         logical, intent(in) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Status_set_cancelled

      subroutine MPI_Status_set_elements( &
         status, &
         datatype, &
         count, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(out) :: status
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(in) :: count
         integer, intent(out) :: ierror
      end subroutine MPI_Status_set_elements

      subroutine MPI_Status_set_error( &
         status, &
         err, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(out) :: status
         integer, intent(in) :: err
         integer, intent(out) :: ierror
      end subroutine MPI_Status_set_error

      subroutine MPI_Status_set_source( &
         status, &
         source, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(out) :: status
         integer, intent(in) :: source
         integer, intent(out) :: ierror
      end subroutine MPI_Status_set_source

      subroutine MPI_Status_set_tag( &
         status, &
         tag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(out) :: status
         integer, intent(in) :: tag
         integer, intent(out) :: ierror
      end subroutine MPI_Status_set_tag

      subroutine MPI_File_close( &
         fh, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(out) :: fh
         integer, intent(out) :: ierror
      end subroutine MPI_File_close

      subroutine MPI_File_delete( &
         filename, &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: filename
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_File_delete

      subroutine MPI_File_get_amode( &
         fh, &
         amode, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer, intent(out) :: amode
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_amode

      subroutine MPI_File_get_atomicity( &
         fh, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_atomicity

      subroutine MPI_File_get_byte_offset( &
         fh, &
         offset, &
         disp, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         integer(MPI_OFFSET_KIND), intent(out) :: disp
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_byte_offset

      subroutine MPI_File_get_group( &
         fh, &
         group, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         type(MPI_Group), intent(out) :: group
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_group

      subroutine MPI_File_get_info( &
         fh, &
         info_used, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         type(MPI_Info), intent(out) :: info_used
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_info

      subroutine MPI_File_get_position( &
         fh, &
         offset, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(out) :: offset
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_position

      subroutine MPI_File_get_position_shared( &
         fh, &
         offset, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(out) :: offset
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_position_shared

      subroutine MPI_File_get_size( &
         fh, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_size

      subroutine MPI_File_get_type_extent( &
         fh, &
         datatype, &
         extent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: extent
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_type_extent

      subroutine MPI_File_get_view( &
         fh, &
         disp, &
         etype, &
         filetype, &
         datarep, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(out) :: disp
         type(MPI_Datatype), intent(out) :: etype
         type(MPI_Datatype), intent(out) :: filetype
         character(*), intent(out) :: datarep
         integer, intent(out) :: ierror
      end subroutine MPI_File_get_view

      subroutine MPI_File_iread( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iread

      subroutine MPI_File_iread_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iread_all

      subroutine MPI_File_iread_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iread_at

      subroutine MPI_File_iread_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iread_at_all

      subroutine MPI_File_iread_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iread_shared

      subroutine MPI_File_iwrite( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iwrite

      subroutine MPI_File_iwrite_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iwrite_all

      subroutine MPI_File_iwrite_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iwrite_at

      subroutine MPI_File_iwrite_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iwrite_at_all

      subroutine MPI_File_iwrite_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Request), intent(out) :: request
         integer, intent(out) :: ierror
      end subroutine MPI_File_iwrite_shared

      subroutine MPI_File_open( &
         comm, &
         filename, &
         amode, &
         info, &
         fh, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         character(*), intent(in) :: filename
         integer, intent(in) :: amode
         type(MPI_Info), intent(in) :: info
         type(MPI_File), intent(out) :: fh
         integer, intent(out) :: ierror
      end subroutine MPI_File_open

      subroutine MPI_File_preallocate( &
         fh, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_File_preallocate

      subroutine MPI_File_read( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read

      subroutine MPI_File_read_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_all

      subroutine MPI_File_read_all_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_all_begin

      subroutine MPI_File_read_all_end( &
         fh, &
         buf, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_all_end

      subroutine MPI_File_read_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_at

      subroutine MPI_File_read_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_at_all

      subroutine MPI_File_read_at_all_begin( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_at_all_begin

      subroutine MPI_File_read_at_all_end( &
         fh, &
         buf, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_at_all_end

      subroutine MPI_File_read_ordered( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_ordered

      subroutine MPI_File_read_ordered_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_ordered_begin

      subroutine MPI_File_read_ordered_end( &
         fh, &
         buf, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_ordered_end

      subroutine MPI_File_read_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_read_shared

      subroutine MPI_File_seek( &
         fh, &
         offset, &
         whence, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         integer, intent(in) :: whence
         integer, intent(out) :: ierror
      end subroutine MPI_File_seek

      subroutine MPI_File_seek_shared( &
         fh, &
         offset, &
         whence, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         integer, intent(in) :: whence
         integer, intent(out) :: ierror
      end subroutine MPI_File_seek_shared

      subroutine MPI_File_set_atomicity( &
         fh, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         logical, intent(in) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_File_set_atomicity

      subroutine MPI_File_set_info( &
         fh, &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_File_set_info

      subroutine MPI_File_set_size( &
         fh, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_File_set_size

      subroutine MPI_File_set_view( &
         fh, &
         disp, &
         etype, &
         filetype, &
         datarep, &
         info, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: disp
         type(MPI_Datatype), intent(in) :: etype
         type(MPI_Datatype), intent(in) :: filetype
         character(*), intent(in) :: datarep
         type(MPI_Info), intent(in) :: info
         integer, intent(out) :: ierror
      end subroutine MPI_File_set_view

      subroutine MPI_File_sync( &
         fh, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer, intent(out) :: ierror
      end subroutine MPI_File_sync

      subroutine MPI_File_write( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write

      subroutine MPI_File_write_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_all

      subroutine MPI_File_write_all_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_all_begin

      subroutine MPI_File_write_all_end( &
         fh, &
         buf, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_all_end

      subroutine MPI_File_write_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_at

      subroutine MPI_File_write_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_at_all

      subroutine MPI_File_write_at_all_begin( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         integer(MPI_OFFSET_KIND), intent(in) :: offset
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_at_all_begin

      subroutine MPI_File_write_at_all_end( &
         fh, &
         buf, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_at_all_end

      subroutine MPI_File_write_ordered( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_ordered

      subroutine MPI_File_write_ordered_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_ordered_begin

      subroutine MPI_File_write_ordered_end( &
         fh, &
         buf, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_ordered_end

      subroutine MPI_File_write_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_File), intent(in) :: fh
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer, intent(in) :: buf(*)
         integer, intent(in) :: count
         type(MPI_Datatype), intent(in) :: datatype
         type(MPI_Status), intent(out) :: status
         integer, intent(out) :: ierror
      end subroutine MPI_File_write_shared

      subroutine MPI_Register_datarep( &
         datarep, &
         read_conversion_fn, &
         write_conversion_fn, &
         dtype_file_extent_fn, &
         extra_state, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         character(*), intent(in) :: datarep
         external :: read_conversion_fn
         external :: write_conversion_fn
         external :: dtype_file_extent_fn
         !dir$ ignore_tkr(tkr) extra_state
         !gcc$ attributes no_arg_check :: extra_state
         integer :: extra_state(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Register_datarep

      subroutine MPI_F_sync_reg( &
         buf &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) buf
         !gcc$ attributes no_arg_check :: buf
         integer :: buf(*)
      end subroutine MPI_F_sync_reg

      subroutine MPI_Type_create_f90_complex( &
         p, &
         r, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: p
         integer, intent(in) :: r
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_f90_complex

      subroutine MPI_Type_create_f90_integer( &
         r, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: r
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_f90_integer

      subroutine MPI_Type_create_f90_real( &
         p, &
         r, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: p
         integer, intent(in) :: r
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_create_f90_real

      subroutine MPI_Type_match_size( &
         typeclass, &
         size, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: typeclass
         integer, intent(in) :: size
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_match_size

      subroutine MPI_Pcontrol( &
         level &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: level
      end subroutine MPI_Pcontrol

      subroutine MPI_Attr_delete( &
         comm, &
         keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Attr_delete

      subroutine MPI_Attr_get( &
         comm, &
         keyval, &
         attribute_val, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Attr_get

      subroutine MPI_Attr_put( &
         comm, &
         keyval, &
         attribute_val, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Comm), intent(in) :: comm
         integer, intent(in) :: keyval
         !dir$ ignore_tkr(tkr) attribute_val
         !gcc$ attributes no_arg_check :: attribute_val
         integer :: attribute_val(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Attr_put

      subroutine MPI_Get_elements_x( &
         status, &
         datatype, &
         count, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(in) :: status
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_COUNT_KIND), intent(out) :: count
         integer, intent(out) :: ierror
      end subroutine MPI_Get_elements_x

      subroutine MPI_Info_get( &
         info, &
         key, &
         valuelen, &
         value, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: key
         integer, intent(in) :: valuelen
         character(*), intent(out) :: value
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Info_get

      subroutine MPI_Info_get_valuelen( &
         info, &
         key, &
         valuelen, &
         flag, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Info), intent(in) :: info
         character(*), intent(in) :: key
         integer, intent(out) :: valuelen
         logical, intent(out) :: flag
         integer, intent(out) :: ierror
      end subroutine MPI_Info_get_valuelen

      subroutine MPI_Keyval_create( &
         copy_fn, &
         delete_fn, &
         keyval, &
         extra_state, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         external :: copy_fn
         external :: delete_fn
         integer, intent(out) :: keyval
         !dir$ ignore_tkr(tkr) extra_state
         !gcc$ attributes no_arg_check :: extra_state
         integer :: extra_state(*)
         integer, intent(out) :: ierror
      end subroutine MPI_Keyval_create

      subroutine MPI_Keyval_free( &
         keyval, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(out) :: keyval
         integer, intent(out) :: ierror
      end subroutine MPI_Keyval_free

      subroutine MPI_Status_set_elements_x( &
         status, &
         datatype, &
         count, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Status), intent(out) :: status
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_COUNT_KIND), intent(in) :: count
         integer, intent(out) :: ierror
      end subroutine MPI_Status_set_elements_x

      subroutine MPI_Type_get_extent_x( &
         datatype, &
         lb, &
         extent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_COUNT_KIND), intent(out) :: lb
         integer(MPI_COUNT_KIND), intent(out) :: extent
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_extent_x

      subroutine MPI_Type_get_true_extent_x( &
         datatype, &
         true_lb, &
         true_extent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_COUNT_KIND), intent(out) :: true_lb
         integer(MPI_COUNT_KIND), intent(out) :: true_extent
         integer, intent(out) :: ierror
      end subroutine MPI_Type_get_true_extent_x

      subroutine MPI_Type_size_x( &
         datatype, &
         size, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_COUNT_KIND), intent(out) :: size
         integer, intent(out) :: ierror
      end subroutine MPI_Type_size_x

      subroutine MPI_Address( &
         location, &
         address, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         !dir$ ignore_tkr(tkr) location
         !gcc$ attributes no_arg_check :: location
         integer :: location(*)
         integer(MPI_ADDRESS_KIND), intent(out) :: address
         integer, intent(out) :: ierror
      end subroutine MPI_Address

      subroutine MPI_Type_hindexed( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(out) :: array_of_blocklengths
         integer(MPI_ADDRESS_KIND), intent(out) :: array_of_displacements
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_hindexed

      subroutine MPI_Type_hvector( &
         count, &
         blocklength, &
         stride, &
         oldtype, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(in) :: blocklength
         integer(MPI_ADDRESS_KIND), intent(in) :: stride
         type(MPI_Datatype), intent(in) :: oldtype
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_hvector

      subroutine MPI_Type_struct( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         array_of_types, &
         newtype, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         integer, intent(in) :: count
         integer, intent(out) :: array_of_blocklengths
         integer(MPI_ADDRESS_KIND), intent(out) :: array_of_displacements
         type(MPI_Datatype), intent(out) :: array_of_types
         type(MPI_Datatype), intent(out) :: newtype
         integer, intent(out) :: ierror
      end subroutine MPI_Type_struct

      subroutine MPI_Type_extent( &
         datatype, &
         extent, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: extent
         integer, intent(out) :: ierror
      end subroutine MPI_Type_extent

      subroutine MPI_Type_lb( &
         datatype, &
         displacement, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: displacement
         integer, intent(out) :: ierror
      end subroutine MPI_Type_lb

      subroutine MPI_Type_ub( &
         datatype, &
         displacement, &
         ierror &
      )
         use mpi_f08_types
         use mpi_f08_constants
         implicit none
         type(MPI_Datatype), intent(in) :: datatype
         integer(MPI_ADDRESS_KIND), intent(out) :: displacement
         integer, intent(out) :: ierror
      end subroutine MPI_Type_ub

   end interface

end module mpi_f08_functions_internal

module mpi_f08_functions
   use mpi_f08_types
   use mpi_f08_constants

   use mpi_f08_functions_internal, &
      wrapped_MPI_Bsend => MPI_Bsend, &
      wrapped_MPI_Bsend_init => MPI_Bsend_init, &
      wrapped_MPI_Buffer_attach => MPI_Buffer_attach, &
      wrapped_MPI_Buffer_detach => MPI_Buffer_detach, &
      wrapped_MPI_Buffer_flush => MPI_Buffer_flush, &
      wrapped_MPI_Buffer_iflush => MPI_Buffer_iflush, &
      wrapped_MPI_Cancel => MPI_Cancel, &
      wrapped_MPI_Comm_attach_buffer => MPI_Comm_attach_buffer, &
      wrapped_MPI_Comm_detach_buffer => MPI_Comm_detach_buffer, &
      wrapped_MPI_Comm_flush_buffer => MPI_Comm_flush_buffer, &
      wrapped_MPI_Comm_iflush_buffer => MPI_Comm_iflush_buffer, &
      wrapped_MPI_Get_count => MPI_Get_count, &
      wrapped_MPI_Ibsend => MPI_Ibsend, &
      wrapped_MPI_Improbe => MPI_Improbe, &
      wrapped_MPI_Imrecv => MPI_Imrecv, &
      wrapped_MPI_Iprobe => MPI_Iprobe, &
      wrapped_MPI_Irecv => MPI_Irecv, &
      wrapped_MPI_Irsend => MPI_Irsend, &
      wrapped_MPI_Isend => MPI_Isend, &
      wrapped_MPI_Isendrecv => MPI_Isendrecv, &
      wrapped_MPI_Isendrecv_replace => MPI_Isendrecv_replace, &
      wrapped_MPI_Issend => MPI_Issend, &
      wrapped_MPI_Mprobe => MPI_Mprobe, &
      wrapped_MPI_Mrecv => MPI_Mrecv, &
      wrapped_MPI_Probe => MPI_Probe, &
      wrapped_MPI_Recv => MPI_Recv, &
      wrapped_MPI_Recv_init => MPI_Recv_init, &
      wrapped_MPI_Request_free => MPI_Request_free, &
      wrapped_MPI_Request_get_status => MPI_Request_get_status, &
      wrapped_MPI_Request_get_status_all => MPI_Request_get_status_all, &
      wrapped_MPI_Request_get_status_any => MPI_Request_get_status_any, &
      wrapped_MPI_Request_get_status_some => MPI_Request_get_status_some, &
      wrapped_MPI_Rsend => MPI_Rsend, &
      wrapped_MPI_Rsend_init => MPI_Rsend_init, &
      wrapped_MPI_Send => MPI_Send, &
      wrapped_MPI_Send_init => MPI_Send_init, &
      wrapped_MPI_Sendrecv => MPI_Sendrecv, &
      wrapped_MPI_Sendrecv_replace => MPI_Sendrecv_replace, &
      wrapped_MPI_Session_attach_buffer => MPI_Session_attach_buffer, &
      wrapped_MPI_Session_detach_buffer => MPI_Session_detach_buffer, &
      wrapped_MPI_Session_flush_buffer => MPI_Session_flush_buffer, &
      wrapped_MPI_Session_iflush_buffer => MPI_Session_iflush_buffer, &
      wrapped_MPI_Ssend => MPI_Ssend, &
      wrapped_MPI_Ssend_init => MPI_Ssend_init, &
      wrapped_MPI_Start => MPI_Start, &
      wrapped_MPI_Startall => MPI_Startall, &
      wrapped_MPI_Status_get_error => MPI_Status_get_error, &
      wrapped_MPI_Status_get_source => MPI_Status_get_source, &
      wrapped_MPI_Status_get_tag => MPI_Status_get_tag, &
      wrapped_MPI_Test => MPI_Test, &
      wrapped_MPI_Test_cancelled => MPI_Test_cancelled, &
      wrapped_MPI_Testall => MPI_Testall, &
      wrapped_MPI_Testany => MPI_Testany, &
      wrapped_MPI_Testsome => MPI_Testsome, &
      wrapped_MPI_Wait => MPI_Wait, &
      wrapped_MPI_Waitall => MPI_Waitall, &
      wrapped_MPI_Waitany => MPI_Waitany, &
      wrapped_MPI_Waitsome => MPI_Waitsome, &
      wrapped_MPI_Parrived => MPI_Parrived, &
      wrapped_MPI_Pready => MPI_Pready, &
      wrapped_MPI_Pready_list => MPI_Pready_list, &
      wrapped_MPI_Pready_range => MPI_Pready_range, &
      wrapped_MPI_Precv_init => MPI_Precv_init, &
      wrapped_MPI_Psend_init => MPI_Psend_init, &
      wrapped_MPI_Aint_add => MPI_Aint_add, &
      wrapped_MPI_Aint_diff => MPI_Aint_diff, &
      wrapped_MPI_Get_address => MPI_Get_address, &
      wrapped_MPI_Get_elements => MPI_Get_elements, &
      wrapped_MPI_Pack => MPI_Pack, &
      wrapped_MPI_Pack_external => MPI_Pack_external, &
      wrapped_MPI_Pack_external_size => MPI_Pack_external_size, &
      wrapped_MPI_Pack_size => MPI_Pack_size, &
      wrapped_MPI_Type_commit => MPI_Type_commit, &
      wrapped_MPI_Type_contiguous => MPI_Type_contiguous, &
      wrapped_MPI_Type_create_darray => MPI_Type_create_darray, &
      wrapped_MPI_Type_create_hindexed => MPI_Type_create_hindexed, &
      wrapped_MPI_Type_create_hindexed_block => MPI_Type_create_hindexed_block, &
      wrapped_MPI_Type_create_hvector => MPI_Type_create_hvector, &
      wrapped_MPI_Type_create_indexed_block => MPI_Type_create_indexed_block, &
      wrapped_MPI_Type_create_resized => MPI_Type_create_resized, &
      wrapped_MPI_Type_create_struct => MPI_Type_create_struct, &
      wrapped_MPI_Type_create_subarray => MPI_Type_create_subarray, &
      wrapped_MPI_Type_dup => MPI_Type_dup, &
      wrapped_MPI_Type_free => MPI_Type_free, &
      wrapped_MPI_Type_get_contents => MPI_Type_get_contents, &
      wrapped_MPI_Type_get_envelope => MPI_Type_get_envelope, &
      wrapped_MPI_Type_get_extent => MPI_Type_get_extent, &
      wrapped_MPI_Type_get_true_extent => MPI_Type_get_true_extent, &
      wrapped_MPI_Type_indexed => MPI_Type_indexed, &
      wrapped_MPI_Type_size => MPI_Type_size, &
      wrapped_MPI_Type_vector => MPI_Type_vector, &
      wrapped_MPI_Unpack => MPI_Unpack, &
      wrapped_MPI_Unpack_external => MPI_Unpack_external, &
      wrapped_MPI_Allgather => MPI_Allgather, &
      wrapped_MPI_Allgather_init => MPI_Allgather_init, &
      wrapped_MPI_Allgatherv => MPI_Allgatherv, &
      wrapped_MPI_Allgatherv_init => MPI_Allgatherv_init, &
      wrapped_MPI_Allreduce => MPI_Allreduce, &
      wrapped_MPI_Allreduce_init => MPI_Allreduce_init, &
      wrapped_MPI_Alltoall => MPI_Alltoall, &
      wrapped_MPI_Alltoall_init => MPI_Alltoall_init, &
      wrapped_MPI_Alltoallv => MPI_Alltoallv, &
      wrapped_MPI_Alltoallv_init => MPI_Alltoallv_init, &
      wrapped_MPI_Alltoallw => MPI_Alltoallw, &
      wrapped_MPI_Alltoallw_init => MPI_Alltoallw_init, &
      wrapped_MPI_Barrier => MPI_Barrier, &
      wrapped_MPI_Barrier_init => MPI_Barrier_init, &
      wrapped_MPI_Bcast => MPI_Bcast, &
      wrapped_MPI_Bcast_init => MPI_Bcast_init, &
      wrapped_MPI_Exscan => MPI_Exscan, &
      wrapped_MPI_Exscan_init => MPI_Exscan_init, &
      wrapped_MPI_Gather => MPI_Gather, &
      wrapped_MPI_Gather_init => MPI_Gather_init, &
      wrapped_MPI_Gatherv => MPI_Gatherv, &
      wrapped_MPI_Gatherv_init => MPI_Gatherv_init, &
      wrapped_MPI_Iallgather => MPI_Iallgather, &
      wrapped_MPI_Iallgatherv => MPI_Iallgatherv, &
      wrapped_MPI_Iallreduce => MPI_Iallreduce, &
      wrapped_MPI_Ialltoall => MPI_Ialltoall, &
      wrapped_MPI_Ialltoallv => MPI_Ialltoallv, &
      wrapped_MPI_Ialltoallw => MPI_Ialltoallw, &
      wrapped_MPI_Ibarrier => MPI_Ibarrier, &
      wrapped_MPI_Ibcast => MPI_Ibcast, &
      wrapped_MPI_Iexscan => MPI_Iexscan, &
      wrapped_MPI_Igather => MPI_Igather, &
      wrapped_MPI_Igatherv => MPI_Igatherv, &
      wrapped_MPI_Ireduce => MPI_Ireduce, &
      wrapped_MPI_Ireduce_scatter => MPI_Ireduce_scatter, &
      wrapped_MPI_Ireduce_scatter_block => MPI_Ireduce_scatter_block, &
      wrapped_MPI_Iscan => MPI_Iscan, &
      wrapped_MPI_Iscatter => MPI_Iscatter, &
      wrapped_MPI_Iscatterv => MPI_Iscatterv, &
      wrapped_MPI_Op_commutative => MPI_Op_commutative, &
      wrapped_MPI_Op_create => MPI_Op_create, &
      wrapped_MPI_Op_free => MPI_Op_free, &
      wrapped_MPI_Reduce => MPI_Reduce, &
      wrapped_MPI_Reduce_init => MPI_Reduce_init, &
      wrapped_MPI_Reduce_local => MPI_Reduce_local, &
      wrapped_MPI_Reduce_scatter => MPI_Reduce_scatter, &
      wrapped_MPI_Reduce_scatter_block => MPI_Reduce_scatter_block, &
      wrapped_MPI_Reduce_scatter_block_init => MPI_Reduce_scatter_block_init, &
      wrapped_MPI_Reduce_scatter_init => MPI_Reduce_scatter_init, &
      wrapped_MPI_Scan => MPI_Scan, &
      wrapped_MPI_Scan_init => MPI_Scan_init, &
      wrapped_MPI_Scatter => MPI_Scatter, &
      wrapped_MPI_Scatter_init => MPI_Scatter_init, &
      wrapped_MPI_Scatterv => MPI_Scatterv, &
      wrapped_MPI_Scatterv_init => MPI_Scatterv_init, &
      wrapped_MPI_Type_get_value_index => MPI_Type_get_value_index, &
      wrapped_MPI_Comm_compare => MPI_Comm_compare, &
      wrapped_MPI_Comm_create => MPI_Comm_create, &
      wrapped_MPI_Comm_create_from_group => MPI_Comm_create_from_group, &
      wrapped_MPI_Comm_create_group => MPI_Comm_create_group, &
      wrapped_MPI_Comm_create_keyval => MPI_Comm_create_keyval, &
      wrapped_MPI_Comm_delete_attr => MPI_Comm_delete_attr, &
      wrapped_MPI_Comm_dup => MPI_Comm_dup, &
      wrapped_MPI_Comm_dup_with_info => MPI_Comm_dup_with_info, &
      wrapped_MPI_Comm_free => MPI_Comm_free, &
      wrapped_MPI_Comm_get_name => MPI_Comm_get_name, &
      wrapped_MPI_Comm_free_keyval => MPI_Comm_free_keyval, &
      wrapped_MPI_Comm_get_attr => MPI_Comm_get_attr, &
      wrapped_MPI_Comm_get_info => MPI_Comm_get_info, &
      wrapped_MPI_Comm_group => MPI_Comm_group, &
      wrapped_MPI_Comm_idup => MPI_Comm_idup, &
      wrapped_MPI_Comm_idup_with_info => MPI_Comm_idup_with_info, &
      wrapped_MPI_Comm_rank => MPI_Comm_rank, &
      wrapped_MPI_Comm_remote_group => MPI_Comm_remote_group, &
      wrapped_MPI_Comm_remote_size => MPI_Comm_remote_size, &
      wrapped_MPI_Comm_set_attr => MPI_Comm_set_attr, &
      wrapped_MPI_Comm_set_info => MPI_Comm_set_info, &
      wrapped_MPI_Comm_set_name => MPI_Comm_set_name, &
      wrapped_MPI_Comm_size => MPI_Comm_size, &
      wrapped_MPI_Comm_split => MPI_Comm_split, &
      wrapped_MPI_Group_free => MPI_Group_free, &
      wrapped_MPI_Comm_split_type => MPI_Comm_split_type, &
      wrapped_MPI_Comm_test_inter => MPI_Comm_test_inter, &
      wrapped_MPI_Group_compare => MPI_Group_compare, &
      wrapped_MPI_Group_difference => MPI_Group_difference, &
      wrapped_MPI_Group_excl => MPI_Group_excl, &
      wrapped_MPI_Group_from_session_pset => MPI_Group_from_session_pset, &
      wrapped_MPI_Group_incl => MPI_Group_incl, &
      wrapped_MPI_Group_intersection => MPI_Group_intersection, &
      wrapped_MPI_Group_range_excl => MPI_Group_range_excl, &
      wrapped_MPI_Group_range_incl => MPI_Group_range_incl, &
      wrapped_MPI_Group_rank => MPI_Group_rank, &
      wrapped_MPI_Group_size => MPI_Group_size, &
      wrapped_MPI_Group_translate_ranks => MPI_Group_translate_ranks, &
      wrapped_MPI_Group_union => MPI_Group_union, &
      wrapped_MPI_Intercomm_create => MPI_Intercomm_create, &
      wrapped_MPI_Intercomm_create_from_groups => MPI_Intercomm_create_from_groups, &
      wrapped_MPI_Intercomm_merge => MPI_Intercomm_merge, &
      wrapped_MPI_Type_create_keyval => MPI_Type_create_keyval, &
      wrapped_MPI_Type_delete_attr => MPI_Type_delete_attr, &
      wrapped_MPI_Type_free_keyval => MPI_Type_free_keyval, &
      wrapped_MPI_Type_get_attr => MPI_Type_get_attr, &
      wrapped_MPI_Type_get_name => MPI_Type_get_name, &
      wrapped_MPI_Type_set_attr => MPI_Type_set_attr, &
      wrapped_MPI_Type_set_name => MPI_Type_set_name, &
      wrapped_MPI_Win_create_keyval => MPI_Win_create_keyval, &
      wrapped_MPI_Win_delete_attr => MPI_Win_delete_attr, &
      wrapped_MPI_Win_free_keyval => MPI_Win_free_keyval, &
      wrapped_MPI_Win_get_attr => MPI_Win_get_attr, &
      wrapped_MPI_Win_get_name => MPI_Win_get_name, &
      wrapped_MPI_Win_set_attr => MPI_Win_set_attr, &
      wrapped_MPI_Win_set_name => MPI_Win_set_name, &
      wrapped_MPI_Cart_coords => MPI_Cart_coords, &
      wrapped_MPI_Cart_create => MPI_Cart_create, &
      wrapped_MPI_Cart_get => MPI_Cart_get, &
      wrapped_MPI_Cart_map => MPI_Cart_map, &
      wrapped_MPI_Cart_rank => MPI_Cart_rank, &
      wrapped_MPI_Cart_shift => MPI_Cart_shift, &
      wrapped_MPI_Cart_sub => MPI_Cart_sub, &
      wrapped_MPI_Cartdim_get => MPI_Cartdim_get, &
      wrapped_MPI_Dims_create => MPI_Dims_create, &
      wrapped_MPI_Dist_graph_create => MPI_Dist_graph_create, &
      wrapped_MPI_Dist_graph_create_adjacent => MPI_Dist_graph_create_adjacent, &
      wrapped_MPI_Dist_graph_neighbors => MPI_Dist_graph_neighbors, &
      wrapped_MPI_Dist_graph_neighbors_count => MPI_Dist_graph_neighbors_count, &
      wrapped_MPI_Graph_create => MPI_Graph_create, &
      wrapped_MPI_Graph_get => MPI_Graph_get, &
      wrapped_MPI_Graph_map => MPI_Graph_map, &
      wrapped_MPI_Graph_neighbors => MPI_Graph_neighbors, &
      wrapped_MPI_Graph_neighbors_count => MPI_Graph_neighbors_count, &
      wrapped_MPI_Graphdims_get => MPI_Graphdims_get, &
      wrapped_MPI_Ineighbor_allgather => MPI_Ineighbor_allgather, &
      wrapped_MPI_Ineighbor_allgatherv => MPI_Ineighbor_allgatherv, &
      wrapped_MPI_Ineighbor_alltoall => MPI_Ineighbor_alltoall, &
      wrapped_MPI_Ineighbor_alltoallv => MPI_Ineighbor_alltoallv, &
      wrapped_MPI_Ineighbor_alltoallw => MPI_Ineighbor_alltoallw, &
      wrapped_MPI_Neighbor_allgather => MPI_Neighbor_allgather, &
      wrapped_MPI_Neighbor_allgather_init => MPI_Neighbor_allgather_init, &
      wrapped_MPI_Neighbor_allgatherv => MPI_Neighbor_allgatherv, &
      wrapped_MPI_Neighbor_allgatherv_init => MPI_Neighbor_allgatherv_init, &
      wrapped_MPI_Neighbor_alltoall => MPI_Neighbor_alltoall, &
      wrapped_MPI_Neighbor_alltoall_init => MPI_Neighbor_alltoall_init, &
      wrapped_MPI_Neighbor_alltoallv => MPI_Neighbor_alltoallv, &
      wrapped_MPI_Neighbor_alltoallv_init => MPI_Neighbor_alltoallv_init, &
      wrapped_MPI_Neighbor_alltoallw => MPI_Neighbor_alltoallw, &
      wrapped_MPI_Neighbor_alltoallw_init => MPI_Neighbor_alltoallw_init, &
      wrapped_MPI_Topo_test => MPI_Topo_test, &
      wrapped_MPI_Add_error_class => MPI_Add_error_class, &
      wrapped_MPI_Add_error_code => MPI_Add_error_code, &
      wrapped_MPI_Add_error_string => MPI_Add_error_string, &
      wrapped_MPI_Alloc_mem => MPI_Alloc_mem, &
      wrapped_MPI_Comm_call_errhandler => MPI_Comm_call_errhandler, &
      wrapped_MPI_Comm_create_errhandler => MPI_Comm_create_errhandler, &
      wrapped_MPI_Comm_get_errhandler => MPI_Comm_get_errhandler, &
      wrapped_MPI_Comm_set_errhandler => MPI_Comm_set_errhandler, &
      wrapped_MPI_Errhandler_free => MPI_Errhandler_free, &
      wrapped_MPI_Error_class => MPI_Error_class, &
      wrapped_MPI_Error_string => MPI_Error_string, &
      wrapped_MPI_File_call_errhandler => MPI_File_call_errhandler, &
      wrapped_MPI_File_create_errhandler => MPI_File_create_errhandler, &
      wrapped_MPI_File_get_errhandler => MPI_File_get_errhandler, &
      wrapped_MPI_File_set_errhandler => MPI_File_set_errhandler, &
      wrapped_MPI_Free_mem => MPI_Free_mem, &
      wrapped_MPI_Get_hw_resource_info => MPI_Get_hw_resource_info, &
      wrapped_MPI_Get_library_version => MPI_Get_library_version, &
      wrapped_MPI_Get_processor_name => MPI_Get_processor_name, &
      wrapped_MPI_Get_version => MPI_Get_version, &
      wrapped_MPI_Remove_error_class => MPI_Remove_error_class, &
      wrapped_MPI_Remove_error_code => MPI_Remove_error_code, &
      wrapped_MPI_Remove_error_string => MPI_Remove_error_string, &
      wrapped_MPI_Session_call_errhandler => MPI_Session_call_errhandler, &
      wrapped_MPI_Session_create_errhandler => MPI_Session_create_errhandler, &
      wrapped_MPI_Session_get_errhandler => MPI_Session_get_errhandler, &
      wrapped_MPI_Session_set_errhandler => MPI_Session_set_errhandler, &
      wrapped_MPI_Win_call_errhandler => MPI_Win_call_errhandler, &
      wrapped_MPI_Win_create_errhandler => MPI_Win_create_errhandler, &
      wrapped_MPI_Win_get_errhandler => MPI_Win_get_errhandler, &
      wrapped_MPI_Win_set_errhandler => MPI_Win_set_errhandler, &
      wrapped_MPI_Wtick => MPI_Wtick, &
      wrapped_MPI_Wtime => MPI_Wtime, &
      wrapped_MPI_Info_create => MPI_Info_create, &
      wrapped_MPI_Info_create_env => MPI_Info_create_env, &
      wrapped_MPI_Info_delete => MPI_Info_delete, &
      wrapped_MPI_Info_dup => MPI_Info_dup, &
      wrapped_MPI_Info_free => MPI_Info_free, &
      wrapped_MPI_Info_get_nkeys => MPI_Info_get_nkeys, &
      wrapped_MPI_Info_get_nthkey => MPI_Info_get_nthkey, &
      wrapped_MPI_Info_get_string => MPI_Info_get_string, &
      wrapped_MPI_Info_set => MPI_Info_set, &
      wrapped_MPI_Abort => MPI_Abort, &
      wrapped_MPI_Close_port => MPI_Close_port, &
      wrapped_MPI_Comm_accept => MPI_Comm_accept, &
      wrapped_MPI_Comm_connect => MPI_Comm_connect, &
      wrapped_MPI_Comm_disconnect => MPI_Comm_disconnect, &
      wrapped_MPI_Comm_get_parent => MPI_Comm_get_parent, &
      wrapped_MPI_Comm_join => MPI_Comm_join, &
      wrapped_MPI_Comm_spawn => MPI_Comm_spawn, &
      wrapped_MPI_Comm_spawn_multiple => MPI_Comm_spawn_multiple, &
      wrapped_MPI_Finalize => MPI_Finalize, &
      wrapped_MPI_Finalized => MPI_Finalized, &
      wrapped_MPI_Init => MPI_Init, &
      wrapped_MPI_Init_thread => MPI_Init_thread, &
      wrapped_MPI_Initialized => MPI_Initialized, &
      wrapped_MPI_Is_thread_main => MPI_Is_thread_main, &
      wrapped_MPI_Lookup_name => MPI_Lookup_name, &
      wrapped_MPI_Open_port => MPI_Open_port, &
      wrapped_MPI_Publish_name => MPI_Publish_name, &
      wrapped_MPI_Query_thread => MPI_Query_thread, &
      wrapped_MPI_Session_finalize => MPI_Session_finalize, &
      wrapped_MPI_Session_get_info => MPI_Session_get_info, &
      wrapped_MPI_Session_get_nth_pset => MPI_Session_get_nth_pset, &
      wrapped_MPI_Session_get_num_psets => MPI_Session_get_num_psets, &
      wrapped_MPI_Session_get_pset_info => MPI_Session_get_pset_info, &
      wrapped_MPI_Session_init => MPI_Session_init, &
      wrapped_MPI_Unpublish_name => MPI_Unpublish_name, &
      wrapped_MPI_Accumulate => MPI_Accumulate, &
      wrapped_MPI_Compare_and_swap => MPI_Compare_and_swap, &
      wrapped_MPI_Fetch_and_op => MPI_Fetch_and_op, &
      wrapped_MPI_Get => MPI_Get, &
      wrapped_MPI_Get_accumulate => MPI_Get_accumulate, &
      wrapped_MPI_Put => MPI_Put, &
      wrapped_MPI_Raccumulate => MPI_Raccumulate, &
      wrapped_MPI_Rget => MPI_Rget, &
      wrapped_MPI_Rget_accumulate => MPI_Rget_accumulate, &
      wrapped_MPI_Rput => MPI_Rput, &
      wrapped_MPI_Win_allocate => MPI_Win_allocate, &
      wrapped_MPI_Win_allocate_shared => MPI_Win_allocate_shared, &
      wrapped_MPI_Win_attach => MPI_Win_attach, &
      wrapped_MPI_Win_complete => MPI_Win_complete, &
      wrapped_MPI_Win_create => MPI_Win_create, &
      wrapped_MPI_Win_create_dynamic => MPI_Win_create_dynamic, &
      wrapped_MPI_Win_detach => MPI_Win_detach, &
      wrapped_MPI_Win_fence => MPI_Win_fence, &
      wrapped_MPI_Win_flush => MPI_Win_flush, &
      wrapped_MPI_Win_flush_all => MPI_Win_flush_all, &
      wrapped_MPI_Win_flush_local => MPI_Win_flush_local, &
      wrapped_MPI_Win_flush_local_all => MPI_Win_flush_local_all, &
      wrapped_MPI_Win_free => MPI_Win_free, &
      wrapped_MPI_Win_get_group => MPI_Win_get_group, &
      wrapped_MPI_Win_get_info => MPI_Win_get_info, &
      wrapped_MPI_Win_lock => MPI_Win_lock, &
      wrapped_MPI_Win_lock_all => MPI_Win_lock_all, &
      wrapped_MPI_Win_post => MPI_Win_post, &
      wrapped_MPI_Win_set_info => MPI_Win_set_info, &
      wrapped_MPI_Win_shared_query => MPI_Win_shared_query, &
      wrapped_MPI_Win_start => MPI_Win_start, &
      wrapped_MPI_Win_sync => MPI_Win_sync, &
      wrapped_MPI_Win_test => MPI_Win_test, &
      wrapped_MPI_Win_unlock => MPI_Win_unlock, &
      wrapped_MPI_Win_unlock_all => MPI_Win_unlock_all, &
      wrapped_MPI_Win_wait => MPI_Win_wait, &
      wrapped_MPI_Grequest_complete => MPI_Grequest_complete, &
      wrapped_MPI_Grequest_start => MPI_Grequest_start, &
      wrapped_MPI_Status_set_cancelled => MPI_Status_set_cancelled, &
      wrapped_MPI_Status_set_elements => MPI_Status_set_elements, &
      wrapped_MPI_Status_set_error => MPI_Status_set_error, &
      wrapped_MPI_Status_set_source => MPI_Status_set_source, &
      wrapped_MPI_Status_set_tag => MPI_Status_set_tag, &
      wrapped_MPI_File_close => MPI_File_close, &
      wrapped_MPI_File_delete => MPI_File_delete, &
      wrapped_MPI_File_get_amode => MPI_File_get_amode, &
      wrapped_MPI_File_get_atomicity => MPI_File_get_atomicity, &
      wrapped_MPI_File_get_byte_offset => MPI_File_get_byte_offset, &
      wrapped_MPI_File_get_group => MPI_File_get_group, &
      wrapped_MPI_File_get_info => MPI_File_get_info, &
      wrapped_MPI_File_get_position => MPI_File_get_position, &
      wrapped_MPI_File_get_position_shared => MPI_File_get_position_shared, &
      wrapped_MPI_File_get_size => MPI_File_get_size, &
      wrapped_MPI_File_get_type_extent => MPI_File_get_type_extent, &
      wrapped_MPI_File_get_view => MPI_File_get_view, &
      wrapped_MPI_File_iread => MPI_File_iread, &
      wrapped_MPI_File_iread_all => MPI_File_iread_all, &
      wrapped_MPI_File_iread_at => MPI_File_iread_at, &
      wrapped_MPI_File_iread_at_all => MPI_File_iread_at_all, &
      wrapped_MPI_File_iread_shared => MPI_File_iread_shared, &
      wrapped_MPI_File_iwrite => MPI_File_iwrite, &
      wrapped_MPI_File_iwrite_all => MPI_File_iwrite_all, &
      wrapped_MPI_File_iwrite_at => MPI_File_iwrite_at, &
      wrapped_MPI_File_iwrite_at_all => MPI_File_iwrite_at_all, &
      wrapped_MPI_File_iwrite_shared => MPI_File_iwrite_shared, &
      wrapped_MPI_File_open => MPI_File_open, &
      wrapped_MPI_File_preallocate => MPI_File_preallocate, &
      wrapped_MPI_File_read => MPI_File_read, &
      wrapped_MPI_File_read_all => MPI_File_read_all, &
      wrapped_MPI_File_read_all_begin => MPI_File_read_all_begin, &
      wrapped_MPI_File_read_all_end => MPI_File_read_all_end, &
      wrapped_MPI_File_read_at => MPI_File_read_at, &
      wrapped_MPI_File_read_at_all => MPI_File_read_at_all, &
      wrapped_MPI_File_read_at_all_begin => MPI_File_read_at_all_begin, &
      wrapped_MPI_File_read_at_all_end => MPI_File_read_at_all_end, &
      wrapped_MPI_File_read_ordered => MPI_File_read_ordered, &
      wrapped_MPI_File_read_ordered_begin => MPI_File_read_ordered_begin, &
      wrapped_MPI_File_read_ordered_end => MPI_File_read_ordered_end, &
      wrapped_MPI_File_read_shared => MPI_File_read_shared, &
      wrapped_MPI_File_seek => MPI_File_seek, &
      wrapped_MPI_File_seek_shared => MPI_File_seek_shared, &
      wrapped_MPI_File_set_atomicity => MPI_File_set_atomicity, &
      wrapped_MPI_File_set_info => MPI_File_set_info, &
      wrapped_MPI_File_set_size => MPI_File_set_size, &
      wrapped_MPI_File_set_view => MPI_File_set_view, &
      wrapped_MPI_File_sync => MPI_File_sync, &
      wrapped_MPI_File_write => MPI_File_write, &
      wrapped_MPI_File_write_all => MPI_File_write_all, &
      wrapped_MPI_File_write_all_begin => MPI_File_write_all_begin, &
      wrapped_MPI_File_write_all_end => MPI_File_write_all_end, &
      wrapped_MPI_File_write_at => MPI_File_write_at, &
      wrapped_MPI_File_write_at_all => MPI_File_write_at_all, &
      wrapped_MPI_File_write_at_all_begin => MPI_File_write_at_all_begin, &
      wrapped_MPI_File_write_at_all_end => MPI_File_write_at_all_end, &
      wrapped_MPI_File_write_ordered => MPI_File_write_ordered, &
      wrapped_MPI_File_write_ordered_begin => MPI_File_write_ordered_begin, &
      wrapped_MPI_File_write_ordered_end => MPI_File_write_ordered_end, &
      wrapped_MPI_File_write_shared => MPI_File_write_shared, &
      wrapped_MPI_Register_datarep => MPI_Register_datarep, &
      wrapped_MPI_F_sync_reg => MPI_F_sync_reg, &
      wrapped_MPI_Type_create_f90_complex => MPI_Type_create_f90_complex, &
      wrapped_MPI_Type_create_f90_integer => MPI_Type_create_f90_integer, &
      wrapped_MPI_Type_create_f90_real => MPI_Type_create_f90_real, &
      wrapped_MPI_Type_match_size => MPI_Type_match_size, &
      wrapped_MPI_Pcontrol => MPI_Pcontrol, &
      wrapped_MPI_Attr_delete => MPI_Attr_delete, &
      wrapped_MPI_Attr_get => MPI_Attr_get, &
      wrapped_MPI_Attr_put => MPI_Attr_put, &
      wrapped_MPI_Get_elements_x => MPI_Get_elements_x, &
      wrapped_MPI_Info_get => MPI_Info_get, &
      wrapped_MPI_Info_get_valuelen => MPI_Info_get_valuelen, &
      wrapped_MPI_Keyval_create => MPI_Keyval_create, &
      wrapped_MPI_Keyval_free => MPI_Keyval_free, &
      wrapped_MPI_Status_set_elements_x => MPI_Status_set_elements_x, &
      wrapped_MPI_Type_get_extent_x => MPI_Type_get_extent_x, &
      wrapped_MPI_Type_get_true_extent_x => MPI_Type_get_true_extent_x, &
      wrapped_MPI_Type_size_x => MPI_Type_size_x, &
      wrapped_MPI_Address => MPI_Address, &
      wrapped_MPI_Type_hindexed => MPI_Type_hindexed, &
      wrapped_MPI_Type_hvector => MPI_Type_hvector, &
      wrapped_MPI_Type_struct => MPI_Type_struct, &
      wrapped_MPI_Type_extent => MPI_Type_extent, &
      wrapped_MPI_Type_lb => MPI_Type_lb, &
      wrapped_MPI_Type_ub => MPI_Type_ub

   implicit none
   private
   save

   public :: MPI_Bsend
   public :: MPI_Bsend_init
   public :: MPI_Buffer_attach
   public :: MPI_Buffer_detach
   public :: MPI_Buffer_flush
   public :: MPI_Buffer_iflush
   public :: MPI_Cancel
   public :: MPI_Comm_attach_buffer
   public :: MPI_Comm_detach_buffer
   public :: MPI_Comm_flush_buffer
   public :: MPI_Comm_iflush_buffer
   public :: MPI_Get_count
   public :: MPI_Ibsend
   public :: MPI_Improbe
   public :: MPI_Imrecv
   public :: MPI_Iprobe
   public :: MPI_Irecv
   public :: MPI_Irsend
   public :: MPI_Isend
   public :: MPI_Isendrecv
   public :: MPI_Isendrecv_replace
   public :: MPI_Issend
   public :: MPI_Mprobe
   public :: MPI_Mrecv
   public :: MPI_Probe
   public :: MPI_Recv
   public :: MPI_Recv_init
   public :: MPI_Request_free
   public :: MPI_Request_get_status
   public :: MPI_Request_get_status_all
   public :: MPI_Request_get_status_any
   public :: MPI_Request_get_status_some
   public :: MPI_Rsend
   public :: MPI_Rsend_init
   public :: MPI_Send
   public :: MPI_Send_init
   public :: MPI_Sendrecv
   public :: MPI_Sendrecv_replace
   public :: MPI_Session_attach_buffer
   public :: MPI_Session_detach_buffer
   public :: MPI_Session_flush_buffer
   public :: MPI_Session_iflush_buffer
   public :: MPI_Ssend
   public :: MPI_Ssend_init
   public :: MPI_Start
   public :: MPI_Startall
   public :: MPI_Status_get_error
   public :: MPI_Status_get_source
   public :: MPI_Status_get_tag
   public :: MPI_Test
   public :: MPI_Test_cancelled
   public :: MPI_Testall
   public :: MPI_Testany
   public :: MPI_Testsome
   public :: MPI_Wait
   public :: MPI_Waitall
   public :: MPI_Waitany
   public :: MPI_Waitsome
   public :: MPI_Parrived
   public :: MPI_Pready
   public :: MPI_Pready_list
   public :: MPI_Pready_range
   public :: MPI_Precv_init
   public :: MPI_Psend_init
   public :: MPI_Aint_add
   public :: MPI_Aint_diff
   public :: MPI_Get_address
   public :: MPI_Get_elements
   public :: MPI_Pack
   public :: MPI_Pack_external
   public :: MPI_Pack_external_size
   public :: MPI_Pack_size
   public :: MPI_Type_commit
   public :: MPI_Type_contiguous
   public :: MPI_Type_create_darray
   public :: MPI_Type_create_hindexed
   public :: MPI_Type_create_hindexed_block
   public :: MPI_Type_create_hvector
   public :: MPI_Type_create_indexed_block
   public :: MPI_Type_create_resized
   public :: MPI_Type_create_struct
   public :: MPI_Type_create_subarray
   public :: MPI_Type_dup
   public :: MPI_Type_free
   public :: MPI_Type_get_contents
   public :: MPI_Type_get_envelope
   public :: MPI_Type_get_extent
   public :: MPI_Type_get_true_extent
   public :: MPI_Type_indexed
   public :: MPI_Type_size
   public :: MPI_Type_vector
   public :: MPI_Unpack
   public :: MPI_Unpack_external
   public :: MPI_Allgather
   public :: MPI_Allgather_init
   public :: MPI_Allgatherv
   public :: MPI_Allgatherv_init
   public :: MPI_Allreduce
   public :: MPI_Allreduce_init
   public :: MPI_Alltoall
   public :: MPI_Alltoall_init
   public :: MPI_Alltoallv
   public :: MPI_Alltoallv_init
   public :: MPI_Alltoallw
   public :: MPI_Alltoallw_init
   public :: MPI_Barrier
   public :: MPI_Barrier_init
   public :: MPI_Bcast
   public :: MPI_Bcast_init
   public :: MPI_Exscan
   public :: MPI_Exscan_init
   public :: MPI_Gather
   public :: MPI_Gather_init
   public :: MPI_Gatherv
   public :: MPI_Gatherv_init
   public :: MPI_Iallgather
   public :: MPI_Iallgatherv
   public :: MPI_Iallreduce
   public :: MPI_Ialltoall
   public :: MPI_Ialltoallv
   public :: MPI_Ialltoallw
   public :: MPI_Ibarrier
   public :: MPI_Ibcast
   public :: MPI_Iexscan
   public :: MPI_Igather
   public :: MPI_Igatherv
   public :: MPI_Ireduce
   public :: MPI_Ireduce_scatter
   public :: MPI_Ireduce_scatter_block
   public :: MPI_Iscan
   public :: MPI_Iscatter
   public :: MPI_Iscatterv
   public :: MPI_Op_commutative
   public :: MPI_Op_create
   public :: MPI_Op_free
   public :: MPI_Reduce
   public :: MPI_Reduce_init
   public :: MPI_Reduce_local
   public :: MPI_Reduce_scatter
   public :: MPI_Reduce_scatter_block
   public :: MPI_Reduce_scatter_block_init
   public :: MPI_Reduce_scatter_init
   public :: MPI_Scan
   public :: MPI_Scan_init
   public :: MPI_Scatter
   public :: MPI_Scatter_init
   public :: MPI_Scatterv
   public :: MPI_Scatterv_init
   public :: MPI_Type_get_value_index
   public :: MPI_Comm_compare
   public :: MPI_Comm_create
   public :: MPI_Comm_create_from_group
   public :: MPI_Comm_create_group
   public :: MPI_Comm_create_keyval
   public :: MPI_Comm_delete_attr
   public :: MPI_Comm_dup
   public :: MPI_Comm_dup_with_info
   public :: MPI_Comm_free
   public :: MPI_Comm_get_name
   public :: MPI_Comm_free_keyval
   public :: MPI_Comm_get_attr
   public :: MPI_Comm_get_info
   public :: MPI_Comm_group
   public :: MPI_Comm_idup
   public :: MPI_Comm_idup_with_info
   public :: MPI_Comm_rank
   public :: MPI_Comm_remote_group
   public :: MPI_Comm_remote_size
   public :: MPI_Comm_set_attr
   public :: MPI_Comm_set_info
   public :: MPI_Comm_set_name
   public :: MPI_Comm_size
   public :: MPI_Comm_split
   public :: MPI_Group_free
   public :: MPI_Comm_split_type
   public :: MPI_Comm_test_inter
   public :: MPI_Group_compare
   public :: MPI_Group_difference
   public :: MPI_Group_excl
   public :: MPI_Group_from_session_pset
   public :: MPI_Group_incl
   public :: MPI_Group_intersection
   public :: MPI_Group_range_excl
   public :: MPI_Group_range_incl
   public :: MPI_Group_rank
   public :: MPI_Group_size
   public :: MPI_Group_translate_ranks
   public :: MPI_Group_union
   public :: MPI_Intercomm_create
   public :: MPI_Intercomm_create_from_groups
   public :: MPI_Intercomm_merge
   public :: MPI_Type_create_keyval
   public :: MPI_Type_delete_attr
   public :: MPI_Type_free_keyval
   public :: MPI_Type_get_attr
   public :: MPI_Type_get_name
   public :: MPI_Type_set_attr
   public :: MPI_Type_set_name
   public :: MPI_Win_create_keyval
   public :: MPI_Win_delete_attr
   public :: MPI_Win_free_keyval
   public :: MPI_Win_get_attr
   public :: MPI_Win_get_name
   public :: MPI_Win_set_attr
   public :: MPI_Win_set_name
   public :: MPI_Cart_coords
   public :: MPI_Cart_create
   public :: MPI_Cart_get
   public :: MPI_Cart_map
   public :: MPI_Cart_rank
   public :: MPI_Cart_shift
   public :: MPI_Cart_sub
   public :: MPI_Cartdim_get
   public :: MPI_Dims_create
   public :: MPI_Dist_graph_create
   public :: MPI_Dist_graph_create_adjacent
   public :: MPI_Dist_graph_neighbors
   public :: MPI_Dist_graph_neighbors_count
   public :: MPI_Graph_create
   public :: MPI_Graph_get
   public :: MPI_Graph_map
   public :: MPI_Graph_neighbors
   public :: MPI_Graph_neighbors_count
   public :: MPI_Graphdims_get
   public :: MPI_Ineighbor_allgather
   public :: MPI_Ineighbor_allgatherv
   public :: MPI_Ineighbor_alltoall
   public :: MPI_Ineighbor_alltoallv
   public :: MPI_Ineighbor_alltoallw
   public :: MPI_Neighbor_allgather
   public :: MPI_Neighbor_allgather_init
   public :: MPI_Neighbor_allgatherv
   public :: MPI_Neighbor_allgatherv_init
   public :: MPI_Neighbor_alltoall
   public :: MPI_Neighbor_alltoall_init
   public :: MPI_Neighbor_alltoallv
   public :: MPI_Neighbor_alltoallv_init
   public :: MPI_Neighbor_alltoallw
   public :: MPI_Neighbor_alltoallw_init
   public :: MPI_Topo_test
   public :: MPI_Add_error_class
   public :: MPI_Add_error_code
   public :: MPI_Add_error_string
   public :: MPI_Alloc_mem
   public :: MPI_Comm_call_errhandler
   public :: MPI_Comm_create_errhandler
   public :: MPI_Comm_get_errhandler
   public :: MPI_Comm_set_errhandler
   public :: MPI_Errhandler_free
   public :: MPI_Error_class
   public :: MPI_Error_string
   public :: MPI_File_call_errhandler
   public :: MPI_File_create_errhandler
   public :: MPI_File_get_errhandler
   public :: MPI_File_set_errhandler
   public :: MPI_Free_mem
   public :: MPI_Get_hw_resource_info
   public :: MPI_Get_library_version
   public :: MPI_Get_processor_name
   public :: MPI_Get_version
   public :: MPI_Remove_error_class
   public :: MPI_Remove_error_code
   public :: MPI_Remove_error_string
   public :: MPI_Session_call_errhandler
   public :: MPI_Session_create_errhandler
   public :: MPI_Session_get_errhandler
   public :: MPI_Session_set_errhandler
   public :: MPI_Win_call_errhandler
   public :: MPI_Win_create_errhandler
   public :: MPI_Win_get_errhandler
   public :: MPI_Win_set_errhandler
   public :: MPI_Wtick
   public :: MPI_Wtime
   public :: MPI_Info_create
   public :: MPI_Info_create_env
   public :: MPI_Info_delete
   public :: MPI_Info_dup
   public :: MPI_Info_free
   public :: MPI_Info_get_nkeys
   public :: MPI_Info_get_nthkey
   public :: MPI_Info_get_string
   public :: MPI_Info_set
   public :: MPI_Abort
   public :: MPI_Close_port
   public :: MPI_Comm_accept
   public :: MPI_Comm_connect
   public :: MPI_Comm_disconnect
   public :: MPI_Comm_get_parent
   public :: MPI_Comm_join
   public :: MPI_Comm_spawn
   public :: MPI_Comm_spawn_multiple
   public :: MPI_Finalize
   public :: MPI_Finalized
   public :: MPI_Init
   public :: MPI_Init_thread
   public :: MPI_Initialized
   public :: MPI_Is_thread_main
   public :: MPI_Lookup_name
   public :: MPI_Open_port
   public :: MPI_Publish_name
   public :: MPI_Query_thread
   public :: MPI_Session_finalize
   public :: MPI_Session_get_info
   public :: MPI_Session_get_nth_pset
   public :: MPI_Session_get_num_psets
   public :: MPI_Session_get_pset_info
   public :: MPI_Session_init
   public :: MPI_Unpublish_name
   public :: MPI_Accumulate
   public :: MPI_Compare_and_swap
   public :: MPI_Fetch_and_op
   public :: MPI_Get
   public :: MPI_Get_accumulate
   public :: MPI_Put
   public :: MPI_Raccumulate
   public :: MPI_Rget
   public :: MPI_Rget_accumulate
   public :: MPI_Rput
   public :: MPI_Win_allocate
   public :: MPI_Win_allocate_shared
   public :: MPI_Win_attach
   public :: MPI_Win_complete
   public :: MPI_Win_create
   public :: MPI_Win_create_dynamic
   public :: MPI_Win_detach
   public :: MPI_Win_fence
   public :: MPI_Win_flush
   public :: MPI_Win_flush_all
   public :: MPI_Win_flush_local
   public :: MPI_Win_flush_local_all
   public :: MPI_Win_free
   public :: MPI_Win_get_group
   public :: MPI_Win_get_info
   public :: MPI_Win_lock
   public :: MPI_Win_lock_all
   public :: MPI_Win_post
   public :: MPI_Win_set_info
   public :: MPI_Win_shared_query
   public :: MPI_Win_start
   public :: MPI_Win_sync
   public :: MPI_Win_test
   public :: MPI_Win_unlock
   public :: MPI_Win_unlock_all
   public :: MPI_Win_wait
   public :: MPI_Grequest_complete
   public :: MPI_Grequest_start
   public :: MPI_Status_set_cancelled
   public :: MPI_Status_set_elements
   public :: MPI_Status_set_error
   public :: MPI_Status_set_source
   public :: MPI_Status_set_tag
   public :: MPI_File_close
   public :: MPI_File_delete
   public :: MPI_File_get_amode
   public :: MPI_File_get_atomicity
   public :: MPI_File_get_byte_offset
   public :: MPI_File_get_group
   public :: MPI_File_get_info
   public :: MPI_File_get_position
   public :: MPI_File_get_position_shared
   public :: MPI_File_get_size
   public :: MPI_File_get_type_extent
   public :: MPI_File_get_view
   public :: MPI_File_iread
   public :: MPI_File_iread_all
   public :: MPI_File_iread_at
   public :: MPI_File_iread_at_all
   public :: MPI_File_iread_shared
   public :: MPI_File_iwrite
   public :: MPI_File_iwrite_all
   public :: MPI_File_iwrite_at
   public :: MPI_File_iwrite_at_all
   public :: MPI_File_iwrite_shared
   public :: MPI_File_open
   public :: MPI_File_preallocate
   public :: MPI_File_read
   public :: MPI_File_read_all
   public :: MPI_File_read_all_begin
   public :: MPI_File_read_all_end
   public :: MPI_File_read_at
   public :: MPI_File_read_at_all
   public :: MPI_File_read_at_all_begin
   public :: MPI_File_read_at_all_end
   public :: MPI_File_read_ordered
   public :: MPI_File_read_ordered_begin
   public :: MPI_File_read_ordered_end
   public :: MPI_File_read_shared
   public :: MPI_File_seek
   public :: MPI_File_seek_shared
   public :: MPI_File_set_atomicity
   public :: MPI_File_set_info
   public :: MPI_File_set_size
   public :: MPI_File_set_view
   public :: MPI_File_sync
   public :: MPI_File_write
   public :: MPI_File_write_all
   public :: MPI_File_write_all_begin
   public :: MPI_File_write_all_end
   public :: MPI_File_write_at
   public :: MPI_File_write_at_all
   public :: MPI_File_write_at_all_begin
   public :: MPI_File_write_at_all_end
   public :: MPI_File_write_ordered
   public :: MPI_File_write_ordered_begin
   public :: MPI_File_write_ordered_end
   public :: MPI_File_write_shared
   public :: MPI_Register_datarep
   public :: MPI_F_sync_reg
   public :: MPI_Type_create_f90_complex
   public :: MPI_Type_create_f90_integer
   public :: MPI_Type_create_f90_real
   public :: MPI_Type_match_size
   public :: MPI_Pcontrol
   public :: MPI_Attr_delete
   public :: MPI_Attr_get
   public :: MPI_Attr_put
   public :: MPI_Get_elements_x
   public :: MPI_Info_get
   public :: MPI_Info_get_valuelen
   public :: MPI_Keyval_create
   public :: MPI_Keyval_free
   public :: MPI_Status_set_elements_x
   public :: MPI_Type_get_extent_x
   public :: MPI_Type_get_true_extent_x
   public :: MPI_Type_size_x
   public :: MPI_Address
   public :: MPI_Type_hindexed
   public :: MPI_Type_hvector
   public :: MPI_Type_struct
   public :: MPI_Type_extent
   public :: MPI_Type_lb
   public :: MPI_Type_ub

contains

   subroutine MPI_Bsend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Bsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Bsend

   subroutine MPI_Bsend_init( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Bsend_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Bsend_init

   subroutine MPI_Buffer_attach( &
      buffer, &
      size, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buffer
      !gcc$ attributes no_arg_check :: buffer
      integer :: buffer(*)
      integer, intent(in) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Buffer_attach( &
         buffer, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Buffer_attach

   subroutine MPI_Buffer_detach( &
      buffer_addr, &
      size, &
      ierror &
   )
      integer(MPI_ADDRESS_KIND), intent(out) :: buffer_addr
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Buffer_detach( &
         buffer_addr, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Buffer_detach

   subroutine MPI_Buffer_flush( &
      ierror &
   )
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Buffer_flush( &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Buffer_flush

   subroutine MPI_Buffer_iflush( &
      request, &
      ierror &
   )
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Buffer_iflush( &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Buffer_iflush

   subroutine MPI_Cancel( &
      request, &
      ierror &
   )
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cancel( &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cancel

   subroutine MPI_Comm_attach_buffer( &
      comm, &
      buffer, &
      size, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      !dir$ ignore_tkr(tkr) buffer
      !gcc$ attributes no_arg_check :: buffer
      integer, intent(in) :: buffer(*)
      integer, intent(in) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_attach_buffer( &
         comm, &
         buffer, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_attach_buffer

   subroutine MPI_Comm_detach_buffer( &
      comm, &
      buffer_addr, &
      size, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer(MPI_ADDRESS_KIND), intent(out) :: buffer_addr
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_detach_buffer( &
         comm, &
         buffer_addr, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_detach_buffer

   subroutine MPI_Comm_flush_buffer( &
      comm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_flush_buffer( &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_flush_buffer

   subroutine MPI_Comm_iflush_buffer( &
      comm, &
      request, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_iflush_buffer( &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_iflush_buffer

   subroutine MPI_Get_count( &
      status, &
      datatype, &
      count, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out) :: count
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_count( &
         status, &
         datatype, &
         count, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_count

   subroutine MPI_Ibsend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ibsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ibsend

   subroutine MPI_Improbe( &
      source, &
      tag, &
      comm, &
      flag, &
      message, &
      status, &
      ierror &
   )
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      logical, intent(out) :: flag
      type(MPI_Message), intent(out) :: message
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Improbe( &
         source, &
         tag, &
         comm, &
         flag, &
         message, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Improbe

   subroutine MPI_Imrecv( &
      buf, &
      count, &
      datatype, &
      message, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Message), intent(out) :: message
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Imrecv( &
         buf, &
         count, &
         datatype, &
         message, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Imrecv

   subroutine MPI_Iprobe( &
      source, &
      tag, &
      comm, &
      flag, &
      status, &
      ierror &
   )
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iprobe( &
         source, &
         tag, &
         comm, &
         flag, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iprobe

   subroutine MPI_Irecv( &
      buf, &
      count, &
      datatype, &
      source, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Irecv( &
         buf, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Irecv

   subroutine MPI_Irsend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Irsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Irsend

   subroutine MPI_Isend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Isend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Isend

   subroutine MPI_Isendrecv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      dest, &
      sendtag, &
      recvbuf, &
      recvcount, &
      recvtype, &
      source, &
      recvtag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      integer, intent(in) :: dest
      integer, intent(in) :: sendtag
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: source
      integer, intent(in) :: recvtag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Isendrecv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         dest, &
         sendtag, &
         recvbuf, &
         recvcount, &
         recvtype, &
         source, &
         recvtag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Isendrecv

   subroutine MPI_Isendrecv_replace( &
      buf, &
      count, &
      datatype, &
      dest, &
      sendtag, &
      source, &
      recvtag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(inout) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: sendtag
      integer, intent(in) :: source
      integer, intent(in) :: recvtag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Isendrecv_replace( &
         buf, &
         count, &
         datatype, &
         dest, &
         sendtag, &
         source, &
         recvtag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Isendrecv_replace

   subroutine MPI_Issend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Issend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Issend

   subroutine MPI_Mprobe( &
      source, &
      tag, &
      comm, &
      message, &
      status, &
      ierror &
   )
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Message), intent(out) :: message
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Mprobe( &
         source, &
         tag, &
         comm, &
         message, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Mprobe

   subroutine MPI_Mrecv( &
      buf, &
      count, &
      datatype, &
      message, &
      status, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Message), intent(out) :: message
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Mrecv( &
         buf, &
         count, &
         datatype, &
         message, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Mrecv

   subroutine MPI_Probe( &
      source, &
      tag, &
      comm, &
      status, &
      ierror &
   )
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Probe( &
         source, &
         tag, &
         comm, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Probe

   subroutine MPI_Recv( &
      buf, &
      count, &
      datatype, &
      source, &
      tag, &
      comm, &
      status, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Recv( &
         buf, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Recv

   subroutine MPI_Recv_init( &
      buf, &
      count, &
      datatype, &
      source, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Recv_init( &
         buf, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Recv_init

   subroutine MPI_Request_free( &
      request, &
      ierror &
   )
      type(MPI_Request), intent(inout) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Request_free( &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Request_free

   subroutine MPI_Request_get_status( &
      request, &
      flag, &
      status, &
      ierror &
   )
      type(MPI_Request), intent(in) :: request
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Request_get_status( &
         request, &
         flag, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Request_get_status

   subroutine MPI_Request_get_status_all( &
      count, &
      array_of_requests, &
      flag, &
      array_of_statuses, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(in) :: array_of_requests(count)
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: array_of_statuses(count)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Request_get_status_all( &
         count, &
         array_of_requests, &
         flag, &
         array_of_statuses, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Request_get_status_all

   subroutine MPI_Request_get_status_any( &
      count, &
      array_of_requests, &
      index, &
      flag, &
      status, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(in) :: array_of_requests(count)
      integer, intent(out) :: index
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Request_get_status_any( &
         count, &
         array_of_requests, &
         index, &
         flag, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Request_get_status_any

   subroutine MPI_Request_get_status_some( &
      incount, &
      array_of_requests, &
      outcount, &
      array_of_indices, &
      array_of_statuses, &
      ierror &
   )
      integer, intent(in) :: incount
      type(MPI_Request), intent(in) :: array_of_requests(incount)
      integer, intent(out) :: outcount
      integer, intent(out) :: array_of_indices(incount)
      type(MPI_Status), intent(out) :: array_of_statuses(incount)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Request_get_status_some( &
         incount, &
         array_of_requests, &
         outcount, &
         array_of_indices, &
         array_of_statuses, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Request_get_status_some

   subroutine MPI_Rsend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Rsend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Rsend

   subroutine MPI_Rsend_init( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Rsend_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Rsend_init

   subroutine MPI_Send( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Send( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Send

   subroutine MPI_Send_init( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Send_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Send_init

   subroutine MPI_Sendrecv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      dest, &
      sendtag, &
      recvbuf, &
      recvcount, &
      recvtype, &
      source, &
      recvtag, &
      comm, &
      status, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      integer, intent(in) :: dest
      integer, intent(in) :: sendtag
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: source
      integer, intent(in) :: recvtag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Sendrecv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         dest, &
         sendtag, &
         recvbuf, &
         recvcount, &
         recvtype, &
         source, &
         recvtag, &
         comm, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Sendrecv

   subroutine MPI_Sendrecv_replace( &
      buf, &
      count, &
      datatype, &
      dest, &
      sendtag, &
      source, &
      recvtag, &
      comm, &
      status, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(inout) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: sendtag
      integer, intent(in) :: source
      integer, intent(in) :: recvtag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Sendrecv_replace( &
         buf, &
         count, &
         datatype, &
         dest, &
         sendtag, &
         source, &
         recvtag, &
         comm, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Sendrecv_replace

   subroutine MPI_Session_attach_buffer( &
      session, &
      buffer, &
      size, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      !dir$ ignore_tkr(tkr) buffer
      !gcc$ attributes no_arg_check :: buffer
      integer, intent(in) :: buffer(*)
      integer, intent(in) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_attach_buffer( &
         session, &
         buffer, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_attach_buffer

   subroutine MPI_Session_detach_buffer( &
      session, &
      buffer_addr, &
      size, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      integer(MPI_ADDRESS_KIND), intent(out) :: buffer_addr
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_detach_buffer( &
         session, &
         buffer_addr, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_detach_buffer

   subroutine MPI_Session_flush_buffer( &
      session, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_flush_buffer( &
         session, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_flush_buffer

   subroutine MPI_Session_iflush_buffer( &
      session, &
      request, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_iflush_buffer( &
         session, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_iflush_buffer

   subroutine MPI_Ssend( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ssend( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ssend

   subroutine MPI_Ssend_init( &
      buf, &
      count, &
      datatype, &
      dest, &
      tag, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: dest
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ssend_init( &
         buf, &
         count, &
         datatype, &
         dest, &
         tag, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ssend_init

   subroutine MPI_Start( &
      request, &
      ierror &
   )
      type(MPI_Request), intent(inout) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Start( &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Start

   subroutine MPI_Startall( &
      count, &
      array_of_requests, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(inout) :: array_of_requests(count)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Startall( &
         count, &
         array_of_requests, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Startall

   subroutine MPI_Status_get_error( &
      status, &
      err, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      integer, intent(out) :: err
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_get_error( &
         status, &
         err, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_get_error

   subroutine MPI_Status_get_source( &
      status, &
      source, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      integer, intent(out) :: source
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_get_source( &
         status, &
         source, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_get_source

   subroutine MPI_Status_get_tag( &
      status, &
      tag, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      integer, intent(out) :: tag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_get_tag( &
         status, &
         tag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_get_tag

   subroutine MPI_Test( &
      request, &
      flag, &
      status, &
      ierror &
   )
      type(MPI_Request), intent(inout) :: request
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Test( &
         request, &
         flag, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Test

   subroutine MPI_Test_cancelled( &
      status, &
      flag, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Test_cancelled( &
         status, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Test_cancelled

   subroutine MPI_Testall( &
      count, &
      array_of_requests, &
      flag, &
      array_of_statuses, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(inout) :: array_of_requests(count)
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: array_of_statuses(count)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Testall( &
         count, &
         array_of_requests, &
         flag, &
         array_of_statuses, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Testall

   subroutine MPI_Testany( &
      count, &
      array_of_requests, &
      index, &
      flag, &
      status, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(inout) :: array_of_requests(count)
      integer, intent(out) :: index
      logical, intent(out) :: flag
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Testany( &
         count, &
         array_of_requests, &
         index, &
         flag, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Testany

   subroutine MPI_Testsome( &
      incount, &
      array_of_requests, &
      outcount, &
      array_of_indices, &
      array_of_statuses, &
      ierror &
   )
      integer, intent(in) :: incount
      type(MPI_Request), intent(inout) :: array_of_requests(incount)
      integer, intent(out) :: outcount
      integer, intent(out) :: array_of_indices(incount)
      type(MPI_Status), intent(out) :: array_of_statuses(incount)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Testsome( &
         incount, &
         array_of_requests, &
         outcount, &
         array_of_indices, &
         array_of_statuses, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Testsome

   subroutine MPI_Wait( &
      request, &
      status, &
      ierror &
   )
      type(MPI_Request), intent(inout) :: request
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Wait( &
         request, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Wait

   subroutine MPI_Waitall( &
      count, &
      array_of_requests, &
      array_of_statuses, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(inout) :: array_of_requests(count)
      type(MPI_Status), intent(out) :: array_of_statuses(count)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Waitall( &
         count, &
         array_of_requests, &
         array_of_statuses, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Waitall

   subroutine MPI_Waitany( &
      count, &
      array_of_requests, &
      index, &
      status, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Request), intent(inout) :: array_of_requests(count)
      integer, intent(out) :: index
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Waitany( &
         count, &
         array_of_requests, &
         index, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Waitany

   subroutine MPI_Waitsome( &
      incount, &
      array_of_requests, &
      outcount, &
      array_of_indices, &
      array_of_statuses, &
      ierror &
   )
      integer, intent(in) :: incount
      type(MPI_Request), intent(inout) :: array_of_requests(incount)
      integer, intent(out) :: outcount
      integer, intent(out) :: array_of_indices(incount)
      type(MPI_Status), intent(out) :: array_of_statuses(incount)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Waitsome( &
         incount, &
         array_of_requests, &
         outcount, &
         array_of_indices, &
         array_of_statuses, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Waitsome

   subroutine MPI_Parrived( &
      request, &
      partition, &
      flag, &
      ierror &
   )
      type(MPI_Request), intent(in) :: request
      integer, intent(in) :: partition
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Parrived( &
         request, &
         partition, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Parrived

   subroutine MPI_Pready( &
      partition, &
      request, &
      ierror &
   )
      integer, intent(in) :: partition
      type(MPI_Request), intent(in) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pready( &
         partition, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pready

   subroutine MPI_Pready_list( &
      length, &
      array_of_partitions, &
      request, &
      ierror &
   )
      integer, intent(in) :: length
      integer, intent(in) :: array_of_partitions(length)
      type(MPI_Request), intent(in) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pready_list( &
         length, &
         array_of_partitions, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pready_list

   subroutine MPI_Pready_range( &
      partition_low, &
      partition_high, &
      request, &
      ierror &
   )
      integer, intent(in) :: partition_low
      integer, intent(in) :: partition_high
      type(MPI_Request), intent(in) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pready_range( &
         partition_low, &
         partition_high, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pready_range

   subroutine MPI_Precv_init( &
      buf, &
      partitions, &
      count, &
      datatype, &
      source, &
      tag, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: partitions
      integer(MPI_COUNT_KIND), intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Precv_init( &
         buf, &
         partitions, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Precv_init

   subroutine MPI_Psend_init( &
      buf, &
      partitions, &
      count, &
      datatype, &
      source, &
      tag, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: partitions
      integer(MPI_COUNT_KIND), intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: source
      integer, intent(in) :: tag
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Psend_init( &
         buf, &
         partitions, &
         count, &
         datatype, &
         source, &
         tag, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Psend_init

   function MPI_Aint_add( &
      base, &
      disp &
   ) result(result)
      integer(MPI_ADDRESS_KIND), intent(in) :: base
      integer(MPI_ADDRESS_KIND), intent(in) :: disp
      integer(MPI_ADDRESS_KIND) :: result
      result = wrapped_MPI_Aint_add( &
         base, &
         disp &
      )
   end function MPI_Aint_add

   function MPI_Aint_diff( &
      addr1, &
      addr2 &
   ) result(result)
      integer(MPI_ADDRESS_KIND), intent(in) :: addr1
      integer(MPI_ADDRESS_KIND), intent(in) :: addr2
      integer(MPI_ADDRESS_KIND) :: result
      result = wrapped_MPI_Aint_diff( &
         addr1, &
         addr2 &
      )
   end function MPI_Aint_diff

   subroutine MPI_Get_address( &
      location, &
      address, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) location
      !gcc$ attributes no_arg_check :: location
      integer, intent(in) :: location(*)
      integer(MPI_ADDRESS_KIND), intent(out) :: address
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_address( &
         location, &
         address, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_address

   subroutine MPI_Get_elements( &
      status, &
      datatype, &
      count, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out) :: count
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_elements( &
         status, &
         datatype, &
         count, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_elements

   subroutine MPI_Pack( &
      inbuf, &
      incount, &
      datatype, &
      outbuf, &
      outsize, &
      position, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) inbuf
      !gcc$ attributes no_arg_check :: inbuf
      integer, intent(in) :: inbuf(*)
      integer, intent(in) :: incount
      type(MPI_Datatype), intent(in) :: datatype
      !dir$ ignore_tkr(tkr) outbuf
      !gcc$ attributes no_arg_check :: outbuf
      integer :: outbuf(*)
      integer, intent(in) :: outsize
      integer, intent(out) :: position
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pack( &
         inbuf, &
         incount, &
         datatype, &
         outbuf, &
         outsize, &
         position, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pack

   subroutine MPI_Pack_external( &
      datarep, &
      inbuf, &
      incount, &
      datatype, &
      outbuf, &
      outsize, &
      position, &
      ierror &
   )
      character(*), intent(in) :: datarep
      !dir$ ignore_tkr(tkr) inbuf
      !gcc$ attributes no_arg_check :: inbuf
      integer, intent(in) :: inbuf(*)
      integer, intent(in) :: incount
      type(MPI_Datatype), intent(in) :: datatype
      !dir$ ignore_tkr(tkr) outbuf
      !gcc$ attributes no_arg_check :: outbuf
      integer :: outbuf(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: outsize
      integer(MPI_ADDRESS_KIND), intent(out) :: position
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pack_external( &
         datarep, &
         inbuf, &
         incount, &
         datatype, &
         outbuf, &
         outsize, &
         position, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pack_external

   subroutine MPI_Pack_external_size( &
      datarep, &
      incount, &
      datatype, &
      size, &
      ierror &
   )
      character(*), intent(in) :: datarep
      integer(MPI_COUNT_KIND), intent(in) :: incount
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pack_external_size( &
         datarep, &
         incount, &
         datatype, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pack_external_size

   subroutine MPI_Pack_size( &
      incount, &
      datatype, &
      comm, &
      size, &
      ierror &
   )
      integer, intent(in) :: incount
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Pack_size( &
         incount, &
         datatype, &
         comm, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Pack_size

   subroutine MPI_Type_commit( &
      datatype, &
      ierror &
   )
      type(MPI_Datatype), intent(out) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_commit( &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_commit

   subroutine MPI_Type_contiguous( &
      count, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_contiguous( &
         count, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_contiguous

   subroutine MPI_Type_create_darray( &
      size, &
      rank, &
      ndims, &
      array_of_gsizes, &
      array_of_distribs, &
      array_of_dargs, &
      array_of_psizes, &
      order, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: size
      integer, intent(in) :: rank
      integer, intent(in) :: ndims
      integer, intent(in) :: array_of_gsizes(ndims)
      integer, intent(in) :: array_of_distribs(ndims)
      integer, intent(in) :: array_of_dargs(ndims)
      integer, intent(in) :: array_of_psizes(ndims)
      integer, intent(in) :: order
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_darray( &
         size, &
         rank, &
         ndims, &
         array_of_gsizes, &
         array_of_distribs, &
         array_of_dargs, &
         array_of_psizes, &
         order, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_darray

   subroutine MPI_Type_create_hindexed( &
      count, &
      array_of_blocklengths, &
      array_of_displacements, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: array_of_blocklengths(count)
      integer(MPI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_hindexed( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_hindexed

   subroutine MPI_Type_create_hindexed_block( &
      count, &
      blocklength, &
      array_of_displacements, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: blocklength
      integer(MPI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_hindexed_block( &
         count, &
         blocklength, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_hindexed_block

   subroutine MPI_Type_create_hvector( &
      count, &
      blocklength, &
      stride, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: blocklength
      integer(MPI_ADDRESS_KIND), intent(in) :: stride
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_hvector( &
         count, &
         blocklength, &
         stride, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_hvector

   subroutine MPI_Type_create_indexed_block( &
      count, &
      blocklength, &
      array_of_displacements, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: blocklength
      integer, intent(in) :: array_of_displacements(count)
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_indexed_block( &
         count, &
         blocklength, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_indexed_block

   subroutine MPI_Type_create_resized( &
      oldtype, &
      lb, &
      extent, &
      newtype, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: oldtype
      integer(MPI_ADDRESS_KIND), intent(in) :: lb
      integer(MPI_ADDRESS_KIND), intent(in) :: extent
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_resized( &
         oldtype, &
         lb, &
         extent, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_resized

   subroutine MPI_Type_create_struct( &
      count, &
      array_of_blocklengths, &
      array_of_displacements, &
      array_of_types, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: array_of_blocklengths(count)
      integer(MPI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
      type(MPI_Datatype), intent(in) :: array_of_types(count)
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_struct( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         array_of_types, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_struct

   subroutine MPI_Type_create_subarray( &
      ndims, &
      array_of_sizes, &
      array_of_subsizes, &
      array_of_starts, &
      order, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: ndims
      integer, intent(in) :: array_of_sizes(ndims)
      integer, intent(in) :: array_of_subsizes(ndims)
      integer, intent(in) :: array_of_starts(ndims)
      integer, intent(in) :: order
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_subarray( &
         ndims, &
         array_of_sizes, &
         array_of_subsizes, &
         array_of_starts, &
         order, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_subarray

   subroutine MPI_Type_dup( &
      oldtype, &
      newtype, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_dup( &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_dup

   subroutine MPI_Type_free( &
      datatype, &
      ierror &
   )
      type(MPI_Datatype), intent(out) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_free( &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_free

   subroutine MPI_Type_get_contents( &
      datatype, &
      max_integers, &
      max_addresses, &
      max_datatypes, &
      array_of_integers, &
      array_of_addresses, &
      array_of_datatypes, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: max_integers
      integer, intent(in) :: max_addresses
      integer, intent(in) :: max_datatypes
      integer, intent(out) :: array_of_integers
      integer(MPI_ADDRESS_KIND), intent(out) :: array_of_addresses
      type(MPI_Datatype), intent(out) :: array_of_datatypes
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_contents( &
         datatype, &
         max_integers, &
         max_addresses, &
         max_datatypes, &
         array_of_integers, &
         array_of_addresses, &
         array_of_datatypes, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_contents

   subroutine MPI_Type_get_envelope( &
      datatype, &
      num_integers, &
      num_addresses, &
      num_datatypes, &
      combiner, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out) :: num_integers
      integer, intent(out) :: num_addresses
      integer, intent(out) :: num_datatypes
      integer, intent(out) :: combiner
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_envelope( &
         datatype, &
         num_integers, &
         num_addresses, &
         num_datatypes, &
         combiner, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_envelope

   subroutine MPI_Type_get_extent( &
      datatype, &
      lb, &
      extent, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: lb
      integer(MPI_ADDRESS_KIND), intent(out) :: extent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_extent( &
         datatype, &
         lb, &
         extent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_extent

   subroutine MPI_Type_get_true_extent( &
      datatype, &
      true_lb, &
      true_extent, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: true_lb
      integer(MPI_ADDRESS_KIND), intent(out) :: true_extent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_true_extent( &
         datatype, &
         true_lb, &
         true_extent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_true_extent

   subroutine MPI_Type_indexed( &
      count, &
      array_of_blocklengths, &
      array_of_displacements, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: array_of_blocklengths(count)
      integer, intent(in) :: array_of_displacements(count)
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_indexed( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_indexed

   subroutine MPI_Type_size( &
      datatype, &
      size, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_size( &
         datatype, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_size

   subroutine MPI_Type_vector( &
      count, &
      blocklength, &
      stride, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: blocklength
      integer, intent(in) :: stride
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_vector( &
         count, &
         blocklength, &
         stride, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_vector

   subroutine MPI_Unpack( &
      inbuf, &
      insize, &
      position, &
      outbuf, &
      outcount, &
      datatype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) inbuf
      !gcc$ attributes no_arg_check :: inbuf
      integer, intent(in) :: inbuf(*)
      integer, intent(in) :: insize
      integer, intent(out) :: position
      !dir$ ignore_tkr(tkr) outbuf
      !gcc$ attributes no_arg_check :: outbuf
      integer :: outbuf(*)
      integer, intent(in) :: outcount
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Unpack( &
         inbuf, &
         insize, &
         position, &
         outbuf, &
         outcount, &
         datatype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Unpack

   subroutine MPI_Unpack_external( &
      datarep, &
      inbuf, &
      insize, &
      position, &
      outbuf, &
      outcount, &
      datatype, &
      ierror &
   )
      character(*), intent(in) :: datarep
      !dir$ ignore_tkr(tkr) inbuf
      !gcc$ attributes no_arg_check :: inbuf
      integer, intent(in) :: inbuf(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: insize
      integer(MPI_ADDRESS_KIND), intent(out) :: position
      !dir$ ignore_tkr(tkr) outbuf
      !gcc$ attributes no_arg_check :: outbuf
      integer :: outbuf(*)
      integer, intent(in) :: outcount
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Unpack_external( &
         datarep, &
         inbuf, &
         insize, &
         position, &
         outbuf, &
         outcount, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Unpack_external

   subroutine MPI_Allgather( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Allgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Allgather

   subroutine MPI_Allgather_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Allgather_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Allgather_init

   subroutine MPI_Allgatherv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Allgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Allgatherv

   subroutine MPI_Allgatherv_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Allgatherv_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Allgatherv_init

   subroutine MPI_Allreduce( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Allreduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Allreduce

   subroutine MPI_Allreduce_init( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Allreduce_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Allreduce_init

   subroutine MPI_Alltoall( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alltoall

   subroutine MPI_Alltoall_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alltoall_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alltoall_init

   subroutine MPI_Alltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alltoallv

   subroutine MPI_Alltoallv_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alltoallv_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alltoallv_init

   subroutine MPI_Alltoallw( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtypes, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtypes(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtypes(*)
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alltoallw

   subroutine MPI_Alltoallw_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtypes, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtypes(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtypes(*)
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alltoallw_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alltoallw_init

   subroutine MPI_Barrier( &
      comm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Barrier( &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Barrier

   subroutine MPI_Barrier_init( &
      comm, &
      info, &
      request, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Barrier_init( &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Barrier_init

   subroutine MPI_Bcast( &
      buffer, &
      count, &
      datatype, &
      root, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buffer
      !gcc$ attributes no_arg_check :: buffer
      integer :: buffer(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Bcast( &
         buffer, &
         count, &
         datatype, &
         root, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Bcast

   subroutine MPI_Bcast_init( &
      buffer, &
      count, &
      datatype, &
      root, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buffer
      !gcc$ attributes no_arg_check :: buffer
      integer :: buffer(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Bcast_init( &
         buffer, &
         count, &
         datatype, &
         root, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Bcast_init

   subroutine MPI_Exscan( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Exscan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Exscan

   subroutine MPI_Exscan_init( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Exscan_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Exscan_init

   subroutine MPI_Gather( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Gather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Gather

   subroutine MPI_Gather_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Gather_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Gather_init

   subroutine MPI_Gatherv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      root, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Gatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         root, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Gatherv

   subroutine MPI_Gatherv_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      root, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Gatherv_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Gatherv_init

   subroutine MPI_Iallgather( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iallgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iallgather

   subroutine MPI_Iallgatherv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iallgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iallgatherv

   subroutine MPI_Iallreduce( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iallreduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iallreduce

   subroutine MPI_Ialltoall( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ialltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ialltoall

   subroutine MPI_Ialltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ialltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ialltoallv

   subroutine MPI_Ialltoallw( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtypes, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtypes(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtypes(*)
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ialltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ialltoallw

   subroutine MPI_Ibarrier( &
      comm, &
      request, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ibarrier( &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ibarrier

   subroutine MPI_Ibcast( &
      buffer, &
      count, &
      datatype, &
      root, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) buffer
      !gcc$ attributes no_arg_check :: buffer
      integer :: buffer(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ibcast( &
         buffer, &
         count, &
         datatype, &
         root, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ibcast

   subroutine MPI_Iexscan( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iexscan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iexscan

   subroutine MPI_Igather( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Igather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Igather

   subroutine MPI_Igatherv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      root, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Igatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         root, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Igatherv

   subroutine MPI_Ireduce( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      root, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ireduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         root, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ireduce

   subroutine MPI_Ireduce_scatter( &
      sendbuf, &
      recvbuf, &
      recvcounts, &
      datatype, &
      op, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ireduce_scatter( &
         sendbuf, &
         recvbuf, &
         recvcounts, &
         datatype, &
         op, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ireduce_scatter

   subroutine MPI_Ireduce_scatter_block( &
      sendbuf, &
      recvbuf, &
      recvcount, &
      datatype, &
      op, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ireduce_scatter_block( &
         sendbuf, &
         recvbuf, &
         recvcount, &
         datatype, &
         op, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ireduce_scatter_block

   subroutine MPI_Iscan( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iscan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iscan

   subroutine MPI_Iscatter( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iscatter( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iscatter

   subroutine MPI_Iscatterv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Iscatterv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Iscatterv

   subroutine MPI_Op_commutative( &
      op, &
      commute, &
      ierror &
   )
      type(MPI_Op), intent(in) :: op
      logical, intent(out) :: commute
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Op_commutative( &
         op, &
         commute, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Op_commutative

   subroutine MPI_Op_create( &
      user_fn, &
      commute, &
      op, &
      ierror &
   )
      external :: user_fn
      logical, intent(in) :: commute
      type(MPI_Op), intent(out) :: op
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Op_create( &
         user_fn, &
         commute, &
         op, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Op_create

   subroutine MPI_Op_free( &
      op, &
      ierror &
   )
      type(MPI_Op), intent(out) :: op
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Op_free( &
         op, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Op_free

   subroutine MPI_Reduce( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      root, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         root, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce

   subroutine MPI_Reduce_init( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      root, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         root, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce_init

   subroutine MPI_Reduce_local( &
      inbuf, &
      inoutbuf, &
      count, &
      datatype, &
      op, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) inbuf
      !gcc$ attributes no_arg_check :: inbuf
      integer, intent(in) :: inbuf(*)
      !dir$ ignore_tkr(tkr) inoutbuf
      !gcc$ attributes no_arg_check :: inoutbuf
      integer :: inoutbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce_local( &
         inbuf, &
         inoutbuf, &
         count, &
         datatype, &
         op, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce_local

   subroutine MPI_Reduce_scatter( &
      sendbuf, &
      recvbuf, &
      recvcounts, &
      datatype, &
      op, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce_scatter( &
         sendbuf, &
         recvbuf, &
         recvcounts, &
         datatype, &
         op, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce_scatter

   subroutine MPI_Reduce_scatter_block( &
      sendbuf, &
      recvbuf, &
      recvcount, &
      datatype, &
      op, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce_scatter_block( &
         sendbuf, &
         recvbuf, &
         recvcount, &
         datatype, &
         op, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce_scatter_block

   subroutine MPI_Reduce_scatter_block_init( &
      sendbuf, &
      recvbuf, &
      recvcount, &
      datatype, &
      op, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce_scatter_block_init( &
         sendbuf, &
         recvbuf, &
         recvcount, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce_scatter_block_init

   subroutine MPI_Reduce_scatter_init( &
      sendbuf, &
      recvbuf, &
      recvcounts, &
      datatype, &
      op, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Reduce_scatter_init( &
         sendbuf, &
         recvbuf, &
         recvcounts, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Reduce_scatter_init

   subroutine MPI_Scan( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Scan( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Scan

   subroutine MPI_Scan_init( &
      sendbuf, &
      recvbuf, &
      count, &
      datatype, &
      op, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Scan_init( &
         sendbuf, &
         recvbuf, &
         count, &
         datatype, &
         op, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Scan_init

   subroutine MPI_Scatter( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Scatter( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Scatter

   subroutine MPI_Scatter_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Scatter_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Scatter_init

   subroutine MPI_Scatterv( &
      sendbuf, &
      sendcounts, &
      displs, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Scatterv( &
         sendbuf, &
         sendcounts, &
         displs, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Scatterv

   subroutine MPI_Scatterv_init( &
      sendbuf, &
      sendcounts, &
      displs, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      root, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Scatterv_init( &
         sendbuf, &
         sendcounts, &
         displs, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         root, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Scatterv_init

   subroutine MPI_Type_get_value_index( &
      value_type, &
      index_type, &
      pair_type, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: value_type
      type(MPI_Datatype), intent(in) :: index_type
      type(MPI_Datatype), intent(out) :: pair_type
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_value_index( &
         value_type, &
         index_type, &
         pair_type, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_value_index

   subroutine MPI_Comm_compare( &
      comm1, &
      comm2, &
      result, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm1
      type(MPI_Comm), intent(in) :: comm2
      integer, intent(out) :: result
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_compare( &
         comm1, &
         comm2, &
         result, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_compare

   subroutine MPI_Comm_create( &
      comm, &
      group, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Group), intent(in) :: group
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_create( &
         comm, &
         group, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_create

   subroutine MPI_Comm_create_from_group( &
      group, &
      stringtag, &
      info, &
      errhandler, &
      newcomm, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      character(*), intent(in) :: stringtag
      type(MPI_Info), intent(in) :: info
      type(MPI_Errhandler), intent(in) :: errhandler
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_create_from_group( &
         group, &
         stringtag, &
         info, &
         errhandler, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_create_from_group

   subroutine MPI_Comm_create_group( &
      comm, &
      group, &
      tag, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: tag
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_create_group( &
         comm, &
         group, &
         tag, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_create_group

   subroutine MPI_Comm_create_keyval( &
      comm_copy_attr_fn, &
      comm_delete_attr_fn, &
      comm_keyval, &
      extra_state, &
      ierror &
   )
      external :: comm_copy_attr_fn
      external :: comm_delete_attr_fn
      integer, intent(out) :: comm_keyval
      !dir$ ignore_tkr(tkr) extra_state
      !gcc$ attributes no_arg_check :: extra_state
      integer :: extra_state(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_create_keyval( &
         comm_copy_attr_fn, &
         comm_delete_attr_fn, &
         comm_keyval, &
         extra_state, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_create_keyval

   subroutine MPI_Comm_delete_attr( &
      comm, &
      comm_keyval, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: comm_keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_delete_attr( &
         comm, &
         comm_keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_delete_attr

   subroutine MPI_Comm_dup( &
      comm, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_dup( &
         comm, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_dup

   subroutine MPI_Comm_dup_with_info( &
      comm, &
      info, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_dup_with_info( &
         comm, &
         info, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_dup_with_info

   subroutine MPI_Comm_free( &
      comm, &
      ierror &
   )
      type(MPI_Comm), intent(out) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_free( &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_free

   subroutine MPI_Comm_get_name( &
      comm, &
      comm_name, &
      resultlen, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      character(*), intent(out) :: comm_name
      integer, intent(out) :: resultlen
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_get_name( &
         comm, &
         comm_name, &
         resultlen, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_get_name

   subroutine MPI_Comm_free_keyval( &
      comm_keyval, &
      ierror &
   )
      integer, intent(out) :: comm_keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_free_keyval( &
         comm_keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_free_keyval

   subroutine MPI_Comm_get_attr( &
      comm, &
      comm_keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: comm_keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_get_attr( &
         comm, &
         comm_keyval, &
         attribute_val, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_get_attr

   subroutine MPI_Comm_get_info( &
      comm, &
      info_used, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(out) :: info_used
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_get_info( &
         comm, &
         info_used, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_get_info

   subroutine MPI_Comm_group( &
      comm, &
      group, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Group), intent(out) :: group
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_group( &
         comm, &
         group, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_group

   subroutine MPI_Comm_idup( &
      comm, &
      newcomm, &
      request, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Comm), intent(out) :: newcomm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_idup( &
         comm, &
         newcomm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_idup

   subroutine MPI_Comm_idup_with_info( &
      comm, &
      info, &
      newcomm, &
      request, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(out) :: newcomm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_idup_with_info( &
         comm, &
         info, &
         newcomm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_idup_with_info

   subroutine MPI_Comm_rank( &
      comm, &
      rank, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: rank
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_rank( &
         comm, &
         rank, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_rank

   subroutine MPI_Comm_remote_group( &
      comm, &
      group, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Group), intent(out) :: group
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_remote_group( &
         comm, &
         group, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_remote_group

   subroutine MPI_Comm_remote_size( &
      comm, &
      size, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_remote_size( &
         comm, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_remote_size

   subroutine MPI_Comm_set_attr( &
      comm, &
      comm_keyval, &
      attribute_val, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: comm_keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_set_attr( &
         comm, &
         comm_keyval, &
         attribute_val, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_set_attr

   subroutine MPI_Comm_set_info( &
      comm, &
      info, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_set_info( &
         comm, &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_set_info

   subroutine MPI_Comm_set_name( &
      comm, &
      comm_name, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      character(*), intent(in) :: comm_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_set_name( &
         comm, &
         comm_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_set_name

   subroutine MPI_Comm_size( &
      comm, &
      size, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_size( &
         comm, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_size

   subroutine MPI_Comm_split( &
      comm, &
      color, &
      key, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: color
      integer, intent(in) :: key
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_split( &
         comm, &
         color, &
         key, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_split

   subroutine MPI_Group_free( &
      group, &
      ierror &
   )
      type(MPI_Group), intent(out) :: group
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_free( &
         group, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_free

   subroutine MPI_Comm_split_type( &
      comm, &
      split_type, &
      key, &
      info, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: split_type
      integer, intent(in) :: key
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_split_type( &
         comm, &
         split_type, &
         key, &
         info, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_split_type

   subroutine MPI_Comm_test_inter( &
      comm, &
      flag, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_test_inter( &
         comm, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_test_inter

   subroutine MPI_Group_compare( &
      group1, &
      group2, &
      result, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group1
      type(MPI_Group), intent(in) :: group2
      integer, intent(out) :: result
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_compare( &
         group1, &
         group2, &
         result, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_compare

   subroutine MPI_Group_difference( &
      group1, &
      group2, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group1
      type(MPI_Group), intent(in) :: group2
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_difference( &
         group1, &
         group2, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_difference

   subroutine MPI_Group_excl( &
      group, &
      n, &
      ranks, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: n
      integer, intent(in) :: ranks(n)
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_excl( &
         group, &
         n, &
         ranks, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_excl

   subroutine MPI_Group_from_session_pset( &
      session, &
      pset_name, &
      newgroup, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      character(*), intent(in) :: pset_name
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_from_session_pset( &
         session, &
         pset_name, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_from_session_pset

   subroutine MPI_Group_incl( &
      group, &
      n, &
      ranks, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: n
      integer, intent(in) :: ranks(n)
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_incl( &
         group, &
         n, &
         ranks, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_incl

   subroutine MPI_Group_intersection( &
      group1, &
      group2, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group1
      type(MPI_Group), intent(in) :: group2
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_intersection( &
         group1, &
         group2, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_intersection

   subroutine MPI_Group_range_excl( &
      group, &
      n, &
      ranges, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: n
      integer, intent(in) :: ranges(n)
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_range_excl( &
         group, &
         n, &
         ranges, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_range_excl

   subroutine MPI_Group_range_incl( &
      group, &
      n, &
      ranges, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: n
      integer, intent(in) :: ranges(n)
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_range_incl( &
         group, &
         n, &
         ranges, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_range_incl

   subroutine MPI_Group_rank( &
      group, &
      rank, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(out) :: rank
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_rank( &
         group, &
         rank, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_rank

   subroutine MPI_Group_size( &
      group, &
      size, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_size( &
         group, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_size

   subroutine MPI_Group_translate_ranks( &
      group1, &
      n, &
      ranks1, &
      group2, &
      ranks2, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group1
      integer, intent(in) :: n
      integer, intent(in) :: ranks1(n)
      type(MPI_Group), intent(in) :: group2
      integer, intent(in) :: ranks2(n)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_translate_ranks( &
         group1, &
         n, &
         ranks1, &
         group2, &
         ranks2, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_translate_ranks

   subroutine MPI_Group_union( &
      group1, &
      group2, &
      newgroup, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group1
      type(MPI_Group), intent(in) :: group2
      type(MPI_Group), intent(out) :: newgroup
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Group_union( &
         group1, &
         group2, &
         newgroup, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Group_union

   subroutine MPI_Intercomm_create( &
      local_comm, &
      local_leader, &
      peer_comm, &
      remote_leader, &
      tag, &
      newintercomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: local_comm
      integer, intent(in) :: local_leader
      type(MPI_Comm), intent(in) :: peer_comm
      integer, intent(in) :: remote_leader
      integer, intent(in) :: tag
      type(MPI_Comm), intent(out) :: newintercomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Intercomm_create( &
         local_comm, &
         local_leader, &
         peer_comm, &
         remote_leader, &
         tag, &
         newintercomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Intercomm_create

   subroutine MPI_Intercomm_create_from_groups( &
      local_group, &
      local_leader, &
      remote_group, &
      remote_leader, &
      stringtag, &
      info, &
      errhandler, &
      newintercomm, &
      ierror &
   )
      type(MPI_Group), intent(in) :: local_group
      integer, intent(in) :: local_leader
      type(MPI_Group), intent(in) :: remote_group
      integer, intent(in) :: remote_leader
      character(*), intent(in) :: stringtag
      type(MPI_Info), intent(in) :: info
      type(MPI_Errhandler), intent(in) :: errhandler
      type(MPI_Comm), intent(out) :: newintercomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Intercomm_create_from_groups( &
         local_group, &
         local_leader, &
         remote_group, &
         remote_leader, &
         stringtag, &
         info, &
         errhandler, &
         newintercomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Intercomm_create_from_groups

   subroutine MPI_Intercomm_merge( &
      intercomm, &
      high, &
      newintracomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: intercomm
      integer, intent(in) :: high
      type(MPI_Comm), intent(out) :: newintracomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Intercomm_merge( &
         intercomm, &
         high, &
         newintracomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Intercomm_merge

   subroutine MPI_Type_create_keyval( &
      type_copy_attr_fn, &
      type_delete_attr_fn, &
      type_keyval, &
      extra_state, &
      ierror &
   )
      external :: type_copy_attr_fn
      external :: type_delete_attr_fn
      integer, intent(out) :: type_keyval
      !dir$ ignore_tkr(tkr) extra_state
      !gcc$ attributes no_arg_check :: extra_state
      integer :: extra_state(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_keyval( &
         type_copy_attr_fn, &
         type_delete_attr_fn, &
         type_keyval, &
         extra_state, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_keyval

   subroutine MPI_Type_delete_attr( &
      datatype, &
      type_keyval, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: type_keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_delete_attr( &
         datatype, &
         type_keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_delete_attr

   subroutine MPI_Type_free_keyval( &
      type_keyval, &
      ierror &
   )
      integer, intent(out) :: type_keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_free_keyval( &
         type_keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_free_keyval

   subroutine MPI_Type_get_attr( &
      datatype, &
      type_keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: type_keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_attr( &
         datatype, &
         type_keyval, &
         attribute_val, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_attr

   subroutine MPI_Type_get_name( &
      datatype, &
      type_name, &
      resultlen, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      character(*), intent(out) :: type_name
      integer, intent(out) :: resultlen
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_name( &
         datatype, &
         type_name, &
         resultlen, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_name

   subroutine MPI_Type_set_attr( &
      datatype, &
      type_keyval, &
      attribute_val, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: type_keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_set_attr( &
         datatype, &
         type_keyval, &
         attribute_val, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_set_attr

   subroutine MPI_Type_set_name( &
      datatype, &
      type_name, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      character(*), intent(in) :: type_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_set_name( &
         datatype, &
         type_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_set_name

   subroutine MPI_Win_create_keyval( &
      win_copy_attr_fn, &
      win_delete_attr_fn, &
      win_keyval, &
      extra_state, &
      ierror &
   )
      external :: win_copy_attr_fn
      external :: win_delete_attr_fn
      integer, intent(out) :: win_keyval
      !dir$ ignore_tkr(tkr) extra_state
      !gcc$ attributes no_arg_check :: extra_state
      integer :: extra_state(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_create_keyval( &
         win_copy_attr_fn, &
         win_delete_attr_fn, &
         win_keyval, &
         extra_state, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_create_keyval

   subroutine MPI_Win_delete_attr( &
      win, &
      win_keyval, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(in) :: win_keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_delete_attr( &
         win, &
         win_keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_delete_attr

   subroutine MPI_Win_free_keyval( &
      win_keyval, &
      ierror &
   )
      integer, intent(out) :: win_keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_free_keyval( &
         win_keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_free_keyval

   subroutine MPI_Win_get_attr( &
      win, &
      win_keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(in) :: win_keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_get_attr( &
         win, &
         win_keyval, &
         attribute_val, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_get_attr

   subroutine MPI_Win_get_name( &
      win, &
      win_name, &
      resultlen, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      character(*), intent(out) :: win_name
      integer, intent(out) :: resultlen
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_get_name( &
         win, &
         win_name, &
         resultlen, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_get_name

   subroutine MPI_Win_set_attr( &
      win, &
      win_keyval, &
      attribute_val, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(in) :: win_keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_set_attr( &
         win, &
         win_keyval, &
         attribute_val, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_set_attr

   subroutine MPI_Win_set_name( &
      win, &
      win_name, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      character(*), intent(in) :: win_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_set_name( &
         win, &
         win_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_set_name

   subroutine MPI_Cart_coords( &
      comm, &
      rank, &
      maxdims, &
      coords, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: rank
      integer, intent(in) :: maxdims
      integer, intent(out) :: coords(maxdims)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_coords( &
         comm, &
         rank, &
         maxdims, &
         coords, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_coords

   subroutine MPI_Cart_create( &
      comm_old, &
      ndims, &
      dims, &
      periods, &
      reorder, &
      comm_cart, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm_old
      integer, intent(in) :: ndims
      integer, intent(in) :: dims(ndims)
      logical, intent(in) :: periods(ndims)
      logical, intent(in) :: reorder
      type(MPI_Comm), intent(out) :: comm_cart
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_create( &
         comm_old, &
         ndims, &
         dims, &
         periods, &
         reorder, &
         comm_cart, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_create

   subroutine MPI_Cart_get( &
      comm, &
      maxdims, &
      dims, &
      periods, &
      coords, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: maxdims
      integer, intent(out) :: dims(maxdims)
      integer, intent(out) :: periods(maxdims)
      integer, intent(out) :: coords(maxdims)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_get( &
         comm, &
         maxdims, &
         dims, &
         periods, &
         coords, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_get

   subroutine MPI_Cart_map( &
      comm, &
      ndims, &
      dims, &
      periods, &
      newrank, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: ndims
      integer, intent(in) :: dims(ndims)
      integer, intent(in) :: periods(ndims)
      integer, intent(out) :: newrank
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_map( &
         comm, &
         ndims, &
         dims, &
         periods, &
         newrank, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_map

   subroutine MPI_Cart_rank( &
      comm, &
      coords, &
      rank, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: coords(*)
      integer, intent(out) :: rank
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_rank( &
         comm, &
         coords, &
         rank, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_rank

   subroutine MPI_Cart_shift( &
      comm, &
      direction, &
      disp, &
      rank_source, &
      rank_dest, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: direction
      integer, intent(in) :: disp
      integer, intent(out) :: rank_source
      integer, intent(out) :: rank_dest
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_shift( &
         comm, &
         direction, &
         disp, &
         rank_source, &
         rank_dest, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_shift

   subroutine MPI_Cart_sub( &
      comm, &
      remain_dims, &
      newcomm, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      logical, intent(in) :: remain_dims(*)
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cart_sub( &
         comm, &
         remain_dims, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cart_sub

   subroutine MPI_Cartdim_get( &
      comm, &
      ndims, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: ndims
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Cartdim_get( &
         comm, &
         ndims, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Cartdim_get

   subroutine MPI_Dims_create( &
      nnodes, &
      ndims, &
      dims, &
      ierror &
   )
      integer, intent(in) :: nnodes
      integer, intent(in) :: ndims
      integer, intent(in) :: dims(ndims)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Dims_create( &
         nnodes, &
         ndims, &
         dims, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Dims_create

   subroutine MPI_Dist_graph_create( &
      comm_old, &
      n, &
      sources, &
      degrees, &
      destinations, &
      weights, &
      info, &
      reorder, &
      comm_dist_graph, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm_old
      integer, intent(in) :: n
      integer, intent(in) :: sources(n)
      integer, intent(in) :: degrees(n)
      integer, intent(in) :: destinations(*)
      integer, intent(in) :: weights(*)
      type(MPI_Info), intent(in) :: info
      logical, intent(in) :: reorder
      type(MPI_Comm), intent(out) :: comm_dist_graph
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Dist_graph_create( &
         comm_old, &
         n, &
         sources, &
         degrees, &
         destinations, &
         weights, &
         info, &
         reorder, &
         comm_dist_graph, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Dist_graph_create

   subroutine MPI_Dist_graph_create_adjacent( &
      comm_old, &
      indegree, &
      sources, &
      sourceweights, &
      outdegree, &
      destinations, &
      destweights, &
      info, &
      reorder, &
      comm_dist_graph, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm_old
      integer, intent(in) :: indegree
      integer, intent(in) :: sources(indegree)
      integer, intent(in) :: sourceweights(*)
      integer, intent(in) :: outdegree
      integer, intent(in) :: destinations(outdegree)
      integer, intent(in) :: destweights(*)
      type(MPI_Info), intent(in) :: info
      integer, intent(in) :: reorder
      type(MPI_Comm), intent(out) :: comm_dist_graph
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Dist_graph_create_adjacent( &
         comm_old, &
         indegree, &
         sources, &
         sourceweights, &
         outdegree, &
         destinations, &
         destweights, &
         info, &
         reorder, &
         comm_dist_graph, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Dist_graph_create_adjacent

   subroutine MPI_Dist_graph_neighbors( &
      comm, &
      maxindegree, &
      sources, &
      sourceweights, &
      maxoutdegree, &
      destinations, &
      destweights, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: maxindegree
      integer, intent(out) :: sources(maxindegree)
      integer, intent(out) :: sourceweights(*)
      integer, intent(in) :: maxoutdegree
      integer, intent(out) :: destinations(maxoutdegree)
      integer, intent(out) :: destweights(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Dist_graph_neighbors( &
         comm, &
         maxindegree, &
         sources, &
         sourceweights, &
         maxoutdegree, &
         destinations, &
         destweights, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Dist_graph_neighbors

   subroutine MPI_Dist_graph_neighbors_count( &
      comm, &
      indegree, &
      outdegree, &
      weighted, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: indegree
      integer, intent(out) :: outdegree
      integer, intent(out) :: weighted
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Dist_graph_neighbors_count( &
         comm, &
         indegree, &
         outdegree, &
         weighted, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Dist_graph_neighbors_count

   subroutine MPI_Graph_create( &
      comm_old, &
      nnodes, &
      index, &
      edges, &
      reorder, &
      comm_graph, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm_old
      integer, intent(in) :: nnodes
      integer, intent(in) :: index(nnodes)
      integer, intent(in) :: edges(nnodes)
      integer, intent(in) :: reorder
      type(MPI_Comm), intent(out) :: comm_graph
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Graph_create( &
         comm_old, &
         nnodes, &
         index, &
         edges, &
         reorder, &
         comm_graph, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Graph_create

   subroutine MPI_Graph_get( &
      comm, &
      maxindex, &
      maxedges, &
      index, &
      edges, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: maxindex
      integer, intent(in) :: maxedges
      integer, intent(out) :: index(maxindex)
      integer, intent(out) :: edges(maxedges)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Graph_get( &
         comm, &
         maxindex, &
         maxedges, &
         index, &
         edges, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Graph_get

   subroutine MPI_Graph_map( &
      comm, &
      nnodes, &
      index, &
      edges, &
      newrank, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: nnodes
      integer, intent(in) :: index(nnodes)
      integer, intent(in) :: edges(nnodes)
      integer, intent(out) :: newrank
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Graph_map( &
         comm, &
         nnodes, &
         index, &
         edges, &
         newrank, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Graph_map

   subroutine MPI_Graph_neighbors( &
      comm, &
      rank, &
      maxneighbors, &
      neighbors, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: rank
      integer, intent(in) :: maxneighbors
      integer, intent(out) :: neighbors(maxneighbors)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Graph_neighbors( &
         comm, &
         rank, &
         maxneighbors, &
         neighbors, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Graph_neighbors

   subroutine MPI_Graph_neighbors_count( &
      comm, &
      rank, &
      nneighbors, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: rank
      integer, intent(out) :: nneighbors
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Graph_neighbors_count( &
         comm, &
         rank, &
         nneighbors, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Graph_neighbors_count

   subroutine MPI_Graphdims_get( &
      comm, &
      nnodes, &
      nedges, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: nnodes
      integer, intent(out) :: nedges
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Graphdims_get( &
         comm, &
         nnodes, &
         nedges, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Graphdims_get

   subroutine MPI_Ineighbor_allgather( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ineighbor_allgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ineighbor_allgather

   subroutine MPI_Ineighbor_allgatherv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ineighbor_allgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ineighbor_allgatherv

   subroutine MPI_Ineighbor_alltoall( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ineighbor_alltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ineighbor_alltoall

   subroutine MPI_Ineighbor_alltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtype, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ineighbor_alltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ineighbor_alltoallv

   subroutine MPI_Ineighbor_alltoallw( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtypes, &
      comm, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtypes(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtypes(*)
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Ineighbor_alltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Ineighbor_alltoallw

   subroutine MPI_Neighbor_allgather( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_allgather( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_allgather

   subroutine MPI_Neighbor_allgather_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_allgather_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_allgather_init

   subroutine MPI_Neighbor_allgatherv( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_allgatherv( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_allgatherv

   subroutine MPI_Neighbor_allgatherv_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      displs, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: displs(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_allgatherv_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         displs, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_allgatherv_init

   subroutine MPI_Neighbor_alltoall( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_alltoall( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_alltoall

   subroutine MPI_Neighbor_alltoall_init( &
      sendbuf, &
      sendcount, &
      sendtype, &
      recvbuf, &
      recvcount, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcount
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcount
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_alltoall_init( &
         sendbuf, &
         sendcount, &
         sendtype, &
         recvbuf, &
         recvcount, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_alltoall_init

   subroutine MPI_Neighbor_alltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtype, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_alltoallv( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_alltoallv

   subroutine MPI_Neighbor_alltoallv_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtype, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtype, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer, intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtype
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer, intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtype
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_alltoallv_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtype, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtype, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_alltoallv_init

   subroutine MPI_Neighbor_alltoallw( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtypes, &
      comm, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtypes(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtypes(*)
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_alltoallw( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_alltoallw

   subroutine MPI_Neighbor_alltoallw_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      recvtypes, &
      comm, &
      info, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) sendbuf
      !gcc$ attributes no_arg_check :: sendbuf
      integer, intent(in) :: sendbuf(*)
      integer, intent(in) :: sendcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: sdispls(*)
      type(MPI_Datatype), intent(in) :: sendtypes(*)
      !dir$ ignore_tkr(tkr) recvbuf
      !gcc$ attributes no_arg_check :: recvbuf
      integer :: recvbuf(*)
      integer, intent(in) :: recvcounts(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: rdispls(*)
      type(MPI_Datatype), intent(in) :: recvtypes(*)
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Info), intent(in) :: info
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Neighbor_alltoallw_init( &
         sendbuf, &
         sendcounts, &
         sdispls, &
         sendtypes, &
         recvbuf, &
         recvcounts, &
         rdispls, &
         recvtypes, &
         comm, &
         info, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Neighbor_alltoallw_init

   subroutine MPI_Topo_test( &
      comm, &
      status, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Topo_test( &
         comm, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Topo_test

   subroutine MPI_Add_error_class( &
      errorclass, &
      ierror &
   )
      integer, intent(out) :: errorclass
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Add_error_class( &
         errorclass, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Add_error_class

   subroutine MPI_Add_error_code( &
      errorclass, &
      errorcode, &
      ierror &
   )
      integer, intent(in) :: errorclass
      integer, intent(out) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Add_error_code( &
         errorclass, &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Add_error_code

   subroutine MPI_Add_error_string( &
      errorcode, &
      string, &
      ierror &
   )
      integer, intent(in) :: errorcode
      character(*), intent(in) :: string
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Add_error_string( &
         errorcode, &
         string, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Add_error_string

   subroutine MPI_Alloc_mem( &
      size, &
      info, &
      baseptr, &
      ierror &
   )
      integer(MPI_ADDRESS_KIND), intent(in) :: size
      type(MPI_Info), intent(in) :: info
      !dir$ ignore_tkr(tkr) baseptr
      !gcc$ attributes no_arg_check :: baseptr
      integer :: baseptr(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Alloc_mem( &
         size, &
         info, &
         baseptr, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Alloc_mem

   subroutine MPI_Comm_call_errhandler( &
      comm, &
      errorcode, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_call_errhandler( &
         comm, &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_call_errhandler

   subroutine MPI_Comm_create_errhandler( &
      comm_errhandler_fn, &
      errhandler, &
      ierror &
   )
      external :: comm_errhandler_fn
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_create_errhandler( &
         comm_errhandler_fn, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_create_errhandler

   subroutine MPI_Comm_get_errhandler( &
      comm, &
      errhandler, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_get_errhandler( &
         comm, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_get_errhandler

   subroutine MPI_Comm_set_errhandler( &
      comm, &
      errhandler, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Errhandler), intent(in) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_set_errhandler( &
         comm, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_set_errhandler

   subroutine MPI_Errhandler_free( &
      errhandler, &
      ierror &
   )
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Errhandler_free( &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Errhandler_free

   subroutine MPI_Error_class( &
      errorcode, &
      errorclass, &
      ierror &
   )
      integer, intent(in) :: errorcode
      integer, intent(out) :: errorclass
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Error_class( &
         errorcode, &
         errorclass, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Error_class

   subroutine MPI_Error_string( &
      errorcode, &
      string, &
      resultlen, &
      ierror &
   )
      integer, intent(in) :: errorcode
      character(*), intent(out) :: string
      integer, intent(out) :: resultlen
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Error_string( &
         errorcode, &
         string, &
         resultlen, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Error_string

   subroutine MPI_File_call_errhandler( &
      fh, &
      errorcode, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_call_errhandler( &
         fh, &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_call_errhandler

   subroutine MPI_File_create_errhandler( &
      file_errhandler_fn, &
      errhandler, &
      ierror &
   )
      external :: file_errhandler_fn
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_create_errhandler( &
         file_errhandler_fn, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_create_errhandler

   subroutine MPI_File_get_errhandler( &
      file, &
      errhandler, &
      ierror &
   )
      type(MPI_File), intent(in) :: file
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_errhandler( &
         file, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_errhandler

   subroutine MPI_File_set_errhandler( &
      file, &
      errhandler, &
      ierror &
   )
      type(MPI_File), intent(in) :: file
      type(MPI_Errhandler), intent(in) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_set_errhandler( &
         file, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_set_errhandler

   subroutine MPI_Free_mem( &
      base, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) base
      !gcc$ attributes no_arg_check :: base
      integer :: base(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Free_mem( &
         base, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Free_mem

   subroutine MPI_Get_hw_resource_info( &
      hw_info, &
      ierror &
   )
      type(MPI_Info), intent(out) :: hw_info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_hw_resource_info( &
         hw_info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_hw_resource_info

   subroutine MPI_Get_library_version( &
      version, &
      resultlen, &
      ierror &
   )
      character(*), intent(out) :: version
      integer, intent(out) :: resultlen
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_library_version( &
         version, &
         resultlen, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_library_version

   subroutine MPI_Get_processor_name( &
      name, &
      resultlen, &
      ierror &
   )
      character(*), intent(out) :: name
      integer, intent(out) :: resultlen
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_processor_name( &
         name, &
         resultlen, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_processor_name

   subroutine MPI_Get_version( &
      version, &
      subversion, &
      ierror &
   )
      integer, intent(out) :: version
      integer, intent(out) :: subversion
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_version( &
         version, &
         subversion, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_version

   subroutine MPI_Remove_error_class( &
      errorclass, &
      ierror &
   )
      integer, intent(in) :: errorclass
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Remove_error_class( &
         errorclass, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Remove_error_class

   subroutine MPI_Remove_error_code( &
      errorcode, &
      ierror &
   )
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Remove_error_code( &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Remove_error_code

   subroutine MPI_Remove_error_string( &
      errorcode, &
      ierror &
   )
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Remove_error_string( &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Remove_error_string

   subroutine MPI_Session_call_errhandler( &
      session, &
      errorcode, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_call_errhandler( &
         session, &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_call_errhandler

   subroutine MPI_Session_create_errhandler( &
      session_errhandler_fn, &
      errhandler, &
      ierror &
   )
      external :: session_errhandler_fn
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_create_errhandler( &
         session_errhandler_fn, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_create_errhandler

   subroutine MPI_Session_get_errhandler( &
      session, &
      errhandler, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_get_errhandler( &
         session, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_get_errhandler

   subroutine MPI_Session_set_errhandler( &
      session, &
      errhandler, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      type(MPI_Errhandler), intent(in) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_set_errhandler( &
         session, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_set_errhandler

   subroutine MPI_Win_call_errhandler( &
      win, &
      errorcode, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_call_errhandler( &
         win, &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_call_errhandler

   subroutine MPI_Win_create_errhandler( &
      win_errhandler_fn, &
      errhandler, &
      ierror &
   )
      external :: win_errhandler_fn
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_create_errhandler( &
         win_errhandler_fn, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_create_errhandler

   subroutine MPI_Win_get_errhandler( &
      win, &
      errhandler, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      type(MPI_Errhandler), intent(out) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_get_errhandler( &
         win, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_get_errhandler

   subroutine MPI_Win_set_errhandler( &
      win, &
      errhandler, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      type(MPI_Errhandler), intent(in) :: errhandler
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_set_errhandler( &
         win, &
         errhandler, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_set_errhandler

   function MPI_Wtick( &
   ) result(result)
      double precision :: result
      result = wrapped_MPI_Wtick( &
      )
   end function MPI_Wtick

   function MPI_Wtime( &
   ) result(result)
      double precision :: result
      result = wrapped_MPI_Wtime( &
      )
   end function MPI_Wtime

   subroutine MPI_Info_create( &
      info, &
      ierror &
   )
      type(MPI_Info), intent(out) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_create( &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_create

   subroutine MPI_Info_create_env( &
      info, &
      ierror &
   )
      type(MPI_Info), intent(out) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_create_env( &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_create_env

   subroutine MPI_Info_delete( &
      info, &
      key, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: key
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_delete( &
         info, &
         key, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_delete

   subroutine MPI_Info_dup( &
      info, &
      newinfo, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      type(MPI_Info), intent(out) :: newinfo
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_dup( &
         info, &
         newinfo, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_dup

   subroutine MPI_Info_free( &
      info, &
      ierror &
   )
      type(MPI_Info), intent(out) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_free( &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_free

   subroutine MPI_Info_get_nkeys( &
      info, &
      nkeys, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      integer, intent(out) :: nkeys
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_get_nkeys( &
         info, &
         nkeys, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_get_nkeys

   subroutine MPI_Info_get_nthkey( &
      info, &
      n, &
      key, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      integer, intent(in) :: n
      character(*), intent(out) :: key
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_get_nthkey( &
         info, &
         n, &
         key, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_get_nthkey

   subroutine MPI_Info_get_string( &
      info, &
      key, &
      buflen, &
      value, &
      flag, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: key
      integer, intent(out) :: buflen
      character(*), intent(out) :: value
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_get_string( &
         info, &
         key, &
         buflen, &
         value, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_get_string

   subroutine MPI_Info_set( &
      info, &
      key, &
      value, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: key
      character(*), intent(in) :: value
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_set( &
         info, &
         key, &
         value, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_set

   subroutine MPI_Abort( &
      comm, &
      errorcode, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: errorcode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Abort( &
         comm, &
         errorcode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Abort

   subroutine MPI_Close_port( &
      port_name, &
      ierror &
   )
      character(*), intent(in) :: port_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Close_port( &
         port_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Close_port

   subroutine MPI_Comm_accept( &
      port_name, &
      info, &
      root, &
      comm, &
      newcomm, &
      ierror &
   )
      character(*), intent(in) :: port_name
      type(MPI_Info), intent(in) :: info
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_accept( &
         port_name, &
         info, &
         root, &
         comm, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_accept

   subroutine MPI_Comm_connect( &
      port_name, &
      info, &
      root, &
      comm, &
      newcomm, &
      ierror &
   )
      character(*), intent(in) :: port_name
      type(MPI_Info), intent(in) :: info
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Comm), intent(out) :: newcomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_connect( &
         port_name, &
         info, &
         root, &
         comm, &
         newcomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_connect

   subroutine MPI_Comm_disconnect( &
      comm, &
      ierror &
   )
      type(MPI_Comm), intent(out) :: comm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_disconnect( &
         comm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_disconnect

   subroutine MPI_Comm_get_parent( &
      parent, &
      ierror &
   )
      type(MPI_Comm), intent(out) :: parent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_get_parent( &
         parent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_get_parent

   subroutine MPI_Comm_join( &
      fd, &
      intercomm, &
      ierror &
   )
      integer, intent(in) :: fd
      type(MPI_Comm), intent(out) :: intercomm
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_join( &
         fd, &
         intercomm, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_join

   subroutine MPI_Comm_spawn( &
      command, &
      argv, &
      maxprocs, &
      info, &
      root, &
      comm, &
      intercomm, &
      array_of_errcodes, &
      ierror &
   )
      character(*), intent(in) :: command
      character(*), intent(in) :: argv(*)
      integer, intent(in) :: maxprocs
      type(MPI_Info), intent(in) :: info
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Comm), intent(out) :: intercomm
      integer, intent(out) :: array_of_errcodes(maxprocs)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_spawn( &
         command, &
         argv, &
         maxprocs, &
         info, &
         root, &
         comm, &
         intercomm, &
         array_of_errcodes, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_spawn

   subroutine MPI_Comm_spawn_multiple( &
      count, &
      array_of_commands, &
      array_of_argv, &
      array_of_maxprocs, &
      array_of_info, &
      root, &
      comm, &
      intercomm, &
      array_of_errcodes, &
      ierror &
   )
      integer, intent(in) :: count
      character(*), intent(in) :: array_of_commands(count)
      character(*), intent(in) :: array_of_argv(count, *)
      integer, intent(in) :: array_of_maxprocs(count)
      type(MPI_Info), intent(in) :: array_of_info(count)
      integer, intent(in) :: root
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Comm), intent(out) :: intercomm
      integer, intent(out) :: array_of_errcodes(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Comm_spawn_multiple( &
         count, &
         array_of_commands, &
         array_of_argv, &
         array_of_maxprocs, &
         array_of_info, &
         root, &
         comm, &
         intercomm, &
         array_of_errcodes, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Comm_spawn_multiple

   subroutine MPI_Finalize( &
      ierror &
   )
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Finalize( &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Finalize

   subroutine MPI_Finalized( &
      flag, &
      ierror &
   )
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Finalized( &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Finalized

   subroutine MPI_Init( &
      ierror &
   )
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Init( &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Init

   subroutine MPI_Init_thread( &
      required, &
      provided, &
      ierror &
   )
      integer, intent(in) :: required
      integer, intent(out) :: provided
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Init_thread( &
         required, &
         provided, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Init_thread

   subroutine MPI_Initialized( &
      flag, &
      ierror &
   )
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Initialized( &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Initialized

   subroutine MPI_Is_thread_main( &
      flag, &
      ierror &
   )
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Is_thread_main( &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Is_thread_main

   subroutine MPI_Lookup_name( &
      service_name, &
      info, &
      port_name, &
      ierror &
   )
      character(*), intent(in) :: service_name
      type(MPI_Info), intent(in) :: info
      character(*), intent(out) :: port_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Lookup_name( &
         service_name, &
         info, &
         port_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Lookup_name

   subroutine MPI_Open_port( &
      info, &
      port_name, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      character(*), intent(out) :: port_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Open_port( &
         info, &
         port_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Open_port

   subroutine MPI_Publish_name( &
      service_name, &
      info, &
      port_name, &
      ierror &
   )
      character(*), intent(in) :: service_name
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: port_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Publish_name( &
         service_name, &
         info, &
         port_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Publish_name

   subroutine MPI_Query_thread( &
      provided, &
      ierror &
   )
      integer, intent(out) :: provided
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Query_thread( &
         provided, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Query_thread

   subroutine MPI_Session_finalize( &
      session, &
      ierror &
   )
      type(MPI_Session), intent(out) :: session
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_finalize( &
         session, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_finalize

   subroutine MPI_Session_get_info( &
      session, &
      info_used, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      type(MPI_Info), intent(out) :: info_used
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_get_info( &
         session, &
         info_used, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_get_info

   subroutine MPI_Session_get_nth_pset( &
      session, &
      info, &
      n, &
      pset_len, &
      pset_name, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      type(MPI_Info), intent(in) :: info
      integer, intent(in) :: n
      integer, intent(out) :: pset_len
      character(*), intent(out) :: pset_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_get_nth_pset( &
         session, &
         info, &
         n, &
         pset_len, &
         pset_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_get_nth_pset

   subroutine MPI_Session_get_num_psets( &
      session, &
      info, &
      npset_names, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      type(MPI_Info), intent(in) :: info
      integer, intent(out) :: npset_names
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_get_num_psets( &
         session, &
         info, &
         npset_names, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_get_num_psets

   subroutine MPI_Session_get_pset_info( &
      session, &
      pset_name, &
      info, &
      ierror &
   )
      type(MPI_Session), intent(in) :: session
      character(*), intent(in) :: pset_name
      type(MPI_Info), intent(out) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_get_pset_info( &
         session, &
         pset_name, &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_get_pset_info

   subroutine MPI_Session_init( &
      info, &
      errhandler, &
      session, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      type(MPI_Errhandler), intent(in) :: errhandler
      type(MPI_Session), intent(out) :: session
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Session_init( &
         info, &
         errhandler, &
         session, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Session_init

   subroutine MPI_Unpublish_name( &
      service_name, &
      info, &
      port_name, &
      ierror &
   )
      character(*), intent(in) :: service_name
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: port_name
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Unpublish_name( &
         service_name, &
         info, &
         port_name, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Unpublish_name

   subroutine MPI_Accumulate( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      op, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Accumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Accumulate

   subroutine MPI_Compare_and_swap( &
      origin_addr, &
      compare_addr, &
      result_addr, &
      datatype, &
      target_rank, &
      target_disp, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      !dir$ ignore_tkr(tkr) compare_addr
      !gcc$ attributes no_arg_check :: compare_addr
      integer, intent(in) :: compare_addr(*)
      !dir$ ignore_tkr(tkr) result_addr
      !gcc$ attributes no_arg_check :: result_addr
      integer :: result_addr(*)
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Compare_and_swap( &
         origin_addr, &
         compare_addr, &
         result_addr, &
         datatype, &
         target_rank, &
         target_disp, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Compare_and_swap

   subroutine MPI_Fetch_and_op( &
      origin_addr, &
      result_addr, &
      datatype, &
      target_rank, &
      target_disp, &
      op, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      !dir$ ignore_tkr(tkr) result_addr
      !gcc$ attributes no_arg_check :: result_addr
      integer :: result_addr(*)
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      type(MPI_Op), intent(in) :: op
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Fetch_and_op( &
         origin_addr, &
         result_addr, &
         datatype, &
         target_rank, &
         target_disp, &
         op, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Fetch_and_op

   subroutine MPI_Get( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get

   subroutine MPI_Get_accumulate( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      result_addr, &
      result_count, &
      result_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      op, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      !dir$ ignore_tkr(tkr) result_addr
      !gcc$ attributes no_arg_check :: result_addr
      integer :: result_addr(*)
      integer, intent(in) :: result_count
      type(MPI_Datatype), intent(in) :: result_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_accumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         result_addr, &
         result_count, &
         result_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_accumulate

   subroutine MPI_Put( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Put( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Put

   subroutine MPI_Raccumulate( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      op, &
      win, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Win), intent(in) :: win
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Raccumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Raccumulate

   subroutine MPI_Rget( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      win, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Win), intent(in) :: win
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Rget( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Rget

   subroutine MPI_Rget_accumulate( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      result_addr, &
      result_count, &
      result_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      op, &
      win, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      !dir$ ignore_tkr(tkr) result_addr
      !gcc$ attributes no_arg_check :: result_addr
      integer :: result_addr(*)
      integer, intent(in) :: result_count
      type(MPI_Datatype), intent(in) :: result_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Op), intent(in) :: op
      type(MPI_Win), intent(in) :: win
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Rget_accumulate( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         result_addr, &
         result_count, &
         result_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         op, &
         win, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Rget_accumulate

   subroutine MPI_Rput( &
      origin_addr, &
      origin_count, &
      origin_datatype, &
      target_rank, &
      target_disp, &
      target_count, &
      target_datatype, &
      win, &
      request, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) origin_addr
      !gcc$ attributes no_arg_check :: origin_addr
      integer, intent(in) :: origin_addr(*)
      integer, intent(in) :: origin_count
      type(MPI_Datatype), intent(in) :: origin_datatype
      integer, intent(in) :: target_rank
      integer(MPI_ADDRESS_KIND), intent(in) :: target_disp
      integer, intent(in) :: target_count
      type(MPI_Datatype), intent(in) :: target_datatype
      type(MPI_Win), intent(in) :: win
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Rput( &
         origin_addr, &
         origin_count, &
         origin_datatype, &
         target_rank, &
         target_disp, &
         target_count, &
         target_datatype, &
         win, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Rput

   subroutine MPI_Win_allocate( &
      size, &
      disp_unit, &
      info, &
      comm, &
      baseptr, &
      win, &
      ierror &
   )
      integer(MPI_ADDRESS_KIND), intent(in) :: size
      integer, intent(in) :: disp_unit
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(in) :: comm
      !dir$ ignore_tkr(tkr) baseptr
      !gcc$ attributes no_arg_check :: baseptr
      integer :: baseptr(*)
      type(MPI_Win), intent(out) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_allocate( &
         size, &
         disp_unit, &
         info, &
         comm, &
         baseptr, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_allocate

   subroutine MPI_Win_allocate_shared( &
      size, &
      disp_unit, &
      info, &
      comm, &
      baseptr, &
      win, &
      ierror &
   )
      integer(MPI_ADDRESS_KIND), intent(in) :: size
      integer, intent(in) :: disp_unit
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(in) :: comm
      !dir$ ignore_tkr(tkr) baseptr
      !gcc$ attributes no_arg_check :: baseptr
      integer :: baseptr(*)
      type(MPI_Win), intent(out) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_allocate_shared( &
         size, &
         disp_unit, &
         info, &
         comm, &
         baseptr, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_allocate_shared

   subroutine MPI_Win_attach( &
      win, &
      base, &
      size, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      !dir$ ignore_tkr(tkr) base
      !gcc$ attributes no_arg_check :: base
      integer :: base(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_attach( &
         win, &
         base, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_attach

   subroutine MPI_Win_complete( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_complete( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_complete

   subroutine MPI_Win_create( &
      base, &
      size, &
      disp_unit, &
      info, &
      comm, &
      win, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) base
      !gcc$ attributes no_arg_check :: base
      integer :: base(*)
      integer(MPI_ADDRESS_KIND), intent(in) :: size
      integer, intent(in) :: disp_unit
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Win), intent(out) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_create( &
         base, &
         size, &
         disp_unit, &
         info, &
         comm, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_create

   subroutine MPI_Win_create_dynamic( &
      info, &
      comm, &
      win, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      type(MPI_Comm), intent(in) :: comm
      type(MPI_Win), intent(out) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_create_dynamic( &
         info, &
         comm, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_create_dynamic

   subroutine MPI_Win_detach( &
      win, &
      base, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      !dir$ ignore_tkr(tkr) base
      !gcc$ attributes no_arg_check :: base
      integer, intent(in) :: base(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_detach( &
         win, &
         base, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_detach

   subroutine MPI_Win_fence( &
      assert, &
      win, &
      ierror &
   )
      integer, intent(in) :: assert
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_fence( &
         assert, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_fence

   subroutine MPI_Win_flush( &
      rank, &
      win, &
      ierror &
   )
      integer, intent(in) :: rank
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_flush( &
         rank, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_flush

   subroutine MPI_Win_flush_all( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_flush_all( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_flush_all

   subroutine MPI_Win_flush_local( &
      rank, &
      win, &
      ierror &
   )
      integer, intent(in) :: rank
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_flush_local( &
         rank, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_flush_local

   subroutine MPI_Win_flush_local_all( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_flush_local_all( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_flush_local_all

   subroutine MPI_Win_free( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(out) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_free( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_free

   subroutine MPI_Win_get_group( &
      win, &
      group, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      type(MPI_Group), intent(out) :: group
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_get_group( &
         win, &
         group, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_get_group

   subroutine MPI_Win_get_info( &
      win, &
      info_used, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      type(MPI_Info), intent(out) :: info_used
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_get_info( &
         win, &
         info_used, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_get_info

   subroutine MPI_Win_lock( &
      lock_type, &
      rank, &
      assert, &
      win, &
      ierror &
   )
      integer, intent(in) :: lock_type
      integer, intent(in) :: rank
      integer, intent(in) :: assert
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_lock( &
         lock_type, &
         rank, &
         assert, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_lock

   subroutine MPI_Win_lock_all( &
      assert, &
      win, &
      ierror &
   )
      integer, intent(in) :: assert
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_lock_all( &
         assert, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_lock_all

   subroutine MPI_Win_post( &
      group, &
      assert, &
      win, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: assert
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_post( &
         group, &
         assert, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_post

   subroutine MPI_Win_set_info( &
      win, &
      info, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      type(MPI_Info), intent(in) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_set_info( &
         win, &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_set_info

   subroutine MPI_Win_shared_query( &
      win, &
      rank, &
      size, &
      disp_unit, &
      baseptr, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(in) :: rank
      integer(MPI_ADDRESS_KIND), intent(out) :: size
      integer, intent(out) :: disp_unit
      !dir$ ignore_tkr(tkr) baseptr
      !gcc$ attributes no_arg_check :: baseptr
      integer :: baseptr(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_shared_query( &
         win, &
         rank, &
         size, &
         disp_unit, &
         baseptr, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_shared_query

   subroutine MPI_Win_start( &
      group, &
      assert, &
      win, &
      ierror &
   )
      type(MPI_Group), intent(in) :: group
      integer, intent(in) :: assert
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_start( &
         group, &
         assert, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_start

   subroutine MPI_Win_sync( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_sync( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_sync

   subroutine MPI_Win_test( &
      win, &
      flag, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_test( &
         win, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_test

   subroutine MPI_Win_unlock( &
      rank, &
      win, &
      ierror &
   )
      integer, intent(in) :: rank
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_unlock( &
         rank, &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_unlock

   subroutine MPI_Win_unlock_all( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_unlock_all( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_unlock_all

   subroutine MPI_Win_wait( &
      win, &
      ierror &
   )
      type(MPI_Win), intent(in) :: win
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Win_wait( &
         win, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Win_wait

   subroutine MPI_Grequest_complete( &
      request, &
      ierror &
   )
      type(MPI_Request), intent(in) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Grequest_complete( &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Grequest_complete

   subroutine MPI_Grequest_start( &
      query_fn, &
      free_fn, &
      cancel_fn, &
      extra_state, &
      request, &
      ierror &
   )
      external :: query_fn
      external :: free_fn
      external :: cancel_fn
      !dir$ ignore_tkr(tkr) extra_state
      !gcc$ attributes no_arg_check :: extra_state
      integer :: extra_state(*)
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Grequest_start( &
         query_fn, &
         free_fn, &
         cancel_fn, &
         extra_state, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Grequest_start

   subroutine MPI_Status_set_cancelled( &
      status, &
      flag, &
      ierror &
   )
      type(MPI_Status), intent(out) :: status
      logical, intent(in) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_set_cancelled( &
         status, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_set_cancelled

   subroutine MPI_Status_set_elements( &
      status, &
      datatype, &
      count, &
      ierror &
   )
      type(MPI_Status), intent(out) :: status
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(in) :: count
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_set_elements( &
         status, &
         datatype, &
         count, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_set_elements

   subroutine MPI_Status_set_error( &
      status, &
      err, &
      ierror &
   )
      type(MPI_Status), intent(out) :: status
      integer, intent(in) :: err
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_set_error( &
         status, &
         err, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_set_error

   subroutine MPI_Status_set_source( &
      status, &
      source, &
      ierror &
   )
      type(MPI_Status), intent(out) :: status
      integer, intent(in) :: source
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_set_source( &
         status, &
         source, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_set_source

   subroutine MPI_Status_set_tag( &
      status, &
      tag, &
      ierror &
   )
      type(MPI_Status), intent(out) :: status
      integer, intent(in) :: tag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_set_tag( &
         status, &
         tag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_set_tag

   subroutine MPI_File_close( &
      fh, &
      ierror &
   )
      type(MPI_File), intent(out) :: fh
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_close( &
         fh, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_close

   subroutine MPI_File_delete( &
      filename, &
      info, &
      ierror &
   )
      character(*), intent(in) :: filename
      type(MPI_Info), intent(in) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_delete( &
         filename, &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_delete

   subroutine MPI_File_get_amode( &
      fh, &
      amode, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer, intent(out) :: amode
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_amode( &
         fh, &
         amode, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_amode

   subroutine MPI_File_get_atomicity( &
      fh, &
      flag, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_atomicity( &
         fh, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_atomicity

   subroutine MPI_File_get_byte_offset( &
      fh, &
      offset, &
      disp, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      integer(MPI_OFFSET_KIND), intent(out) :: disp
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_byte_offset( &
         fh, &
         offset, &
         disp, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_byte_offset

   subroutine MPI_File_get_group( &
      fh, &
      group, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      type(MPI_Group), intent(out) :: group
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_group( &
         fh, &
         group, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_group

   subroutine MPI_File_get_info( &
      fh, &
      info_used, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      type(MPI_Info), intent(out) :: info_used
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_info( &
         fh, &
         info_used, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_info

   subroutine MPI_File_get_position( &
      fh, &
      offset, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(out) :: offset
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_position( &
         fh, &
         offset, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_position

   subroutine MPI_File_get_position_shared( &
      fh, &
      offset, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(out) :: offset
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_position_shared( &
         fh, &
         offset, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_position_shared

   subroutine MPI_File_get_size( &
      fh, &
      size, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_size( &
         fh, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_size

   subroutine MPI_File_get_type_extent( &
      fh, &
      datatype, &
      extent, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: extent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_type_extent( &
         fh, &
         datatype, &
         extent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_type_extent

   subroutine MPI_File_get_view( &
      fh, &
      disp, &
      etype, &
      filetype, &
      datarep, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(out) :: disp
      type(MPI_Datatype), intent(out) :: etype
      type(MPI_Datatype), intent(out) :: filetype
      character(*), intent(out) :: datarep
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_get_view( &
         fh, &
         disp, &
         etype, &
         filetype, &
         datarep, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_get_view

   subroutine MPI_File_iread( &
      fh, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iread( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iread

   subroutine MPI_File_iread_all( &
      fh, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iread_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iread_all

   subroutine MPI_File_iread_at( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iread_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iread_at

   subroutine MPI_File_iread_at_all( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iread_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iread_at_all

   subroutine MPI_File_iread_shared( &
      fh, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iread_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iread_shared

   subroutine MPI_File_iwrite( &
      fh, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iwrite( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iwrite

   subroutine MPI_File_iwrite_all( &
      fh, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iwrite_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iwrite_all

   subroutine MPI_File_iwrite_at( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iwrite_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iwrite_at

   subroutine MPI_File_iwrite_at_all( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iwrite_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iwrite_at_all

   subroutine MPI_File_iwrite_shared( &
      fh, &
      buf, &
      count, &
      datatype, &
      request, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Request), intent(out) :: request
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_iwrite_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         request, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_iwrite_shared

   subroutine MPI_File_open( &
      comm, &
      filename, &
      amode, &
      info, &
      fh, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      character(*), intent(in) :: filename
      integer, intent(in) :: amode
      type(MPI_Info), intent(in) :: info
      type(MPI_File), intent(out) :: fh
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_open( &
         comm, &
         filename, &
         amode, &
         info, &
         fh, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_open

   subroutine MPI_File_preallocate( &
      fh, &
      size, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_preallocate( &
         fh, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_preallocate

   subroutine MPI_File_read( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read

   subroutine MPI_File_read_all( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_all

   subroutine MPI_File_read_all_begin( &
      fh, &
      buf, &
      count, &
      datatype, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_all_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_all_begin

   subroutine MPI_File_read_all_end( &
      fh, &
      buf, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_all_end( &
         fh, &
         buf, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_all_end

   subroutine MPI_File_read_at( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_at

   subroutine MPI_File_read_at_all( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_at_all

   subroutine MPI_File_read_at_all_begin( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_at_all_begin( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_at_all_begin

   subroutine MPI_File_read_at_all_end( &
      fh, &
      buf, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_at_all_end( &
         fh, &
         buf, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_at_all_end

   subroutine MPI_File_read_ordered( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_ordered( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_ordered

   subroutine MPI_File_read_ordered_begin( &
      fh, &
      buf, &
      count, &
      datatype, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_ordered_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_ordered_begin

   subroutine MPI_File_read_ordered_end( &
      fh, &
      buf, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_ordered_end( &
         fh, &
         buf, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_ordered_end

   subroutine MPI_File_read_shared( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_read_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_read_shared

   subroutine MPI_File_seek( &
      fh, &
      offset, &
      whence, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      integer, intent(in) :: whence
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_seek( &
         fh, &
         offset, &
         whence, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_seek

   subroutine MPI_File_seek_shared( &
      fh, &
      offset, &
      whence, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      integer, intent(in) :: whence
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_seek_shared( &
         fh, &
         offset, &
         whence, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_seek_shared

   subroutine MPI_File_set_atomicity( &
      fh, &
      flag, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      logical, intent(in) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_set_atomicity( &
         fh, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_set_atomicity

   subroutine MPI_File_set_info( &
      fh, &
      info, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      type(MPI_Info), intent(in) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_set_info( &
         fh, &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_set_info

   subroutine MPI_File_set_size( &
      fh, &
      size, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_set_size( &
         fh, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_set_size

   subroutine MPI_File_set_view( &
      fh, &
      disp, &
      etype, &
      filetype, &
      datarep, &
      info, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: disp
      type(MPI_Datatype), intent(in) :: etype
      type(MPI_Datatype), intent(in) :: filetype
      character(*), intent(in) :: datarep
      type(MPI_Info), intent(in) :: info
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_set_view( &
         fh, &
         disp, &
         etype, &
         filetype, &
         datarep, &
         info, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_set_view

   subroutine MPI_File_sync( &
      fh, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_sync( &
         fh, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_sync

   subroutine MPI_File_write( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write

   subroutine MPI_File_write_all( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_all( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_all

   subroutine MPI_File_write_all_begin( &
      fh, &
      buf, &
      count, &
      datatype, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_all_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_all_begin

   subroutine MPI_File_write_all_end( &
      fh, &
      buf, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_all_end( &
         fh, &
         buf, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_all_end

   subroutine MPI_File_write_at( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_at( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_at

   subroutine MPI_File_write_at_all( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_at_all( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_at_all

   subroutine MPI_File_write_at_all_begin( &
      fh, &
      offset, &
      buf, &
      count, &
      datatype, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      integer(MPI_OFFSET_KIND), intent(in) :: offset
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_at_all_begin( &
         fh, &
         offset, &
         buf, &
         count, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_at_all_begin

   subroutine MPI_File_write_at_all_end( &
      fh, &
      buf, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_at_all_end( &
         fh, &
         buf, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_at_all_end

   subroutine MPI_File_write_ordered( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_ordered( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_ordered

   subroutine MPI_File_write_ordered_begin( &
      fh, &
      buf, &
      count, &
      datatype, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_ordered_begin( &
         fh, &
         buf, &
         count, &
         datatype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_ordered_begin

   subroutine MPI_File_write_ordered_end( &
      fh, &
      buf, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_ordered_end( &
         fh, &
         buf, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_ordered_end

   subroutine MPI_File_write_shared( &
      fh, &
      buf, &
      count, &
      datatype, &
      status, &
      ierror &
   )
      type(MPI_File), intent(in) :: fh
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer, intent(in) :: buf(*)
      integer, intent(in) :: count
      type(MPI_Datatype), intent(in) :: datatype
      type(MPI_Status), intent(out) :: status
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_File_write_shared( &
         fh, &
         buf, &
         count, &
         datatype, &
         status, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_File_write_shared

   subroutine MPI_Register_datarep( &
      datarep, &
      read_conversion_fn, &
      write_conversion_fn, &
      dtype_file_extent_fn, &
      extra_state, &
      ierror &
   )
      character(*), intent(in) :: datarep
      external :: read_conversion_fn
      external :: write_conversion_fn
      external :: dtype_file_extent_fn
      !dir$ ignore_tkr(tkr) extra_state
      !gcc$ attributes no_arg_check :: extra_state
      integer :: extra_state(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Register_datarep( &
         datarep, &
         read_conversion_fn, &
         write_conversion_fn, &
         dtype_file_extent_fn, &
         extra_state, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Register_datarep

   subroutine MPI_F_sync_reg( &
      buf &
   )
      !dir$ ignore_tkr(tkr) buf
      !gcc$ attributes no_arg_check :: buf
      integer :: buf(*)
      call wrapped_MPI_F_sync_reg( &
         buf &
      )
   end subroutine MPI_F_sync_reg

   subroutine MPI_Type_create_f90_complex( &
      p, &
      r, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: p
      integer, intent(in) :: r
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_f90_complex( &
         p, &
         r, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_f90_complex

   subroutine MPI_Type_create_f90_integer( &
      r, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: r
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_f90_integer( &
         r, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_f90_integer

   subroutine MPI_Type_create_f90_real( &
      p, &
      r, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: p
      integer, intent(in) :: r
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_create_f90_real( &
         p, &
         r, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_create_f90_real

   subroutine MPI_Type_match_size( &
      typeclass, &
      size, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: typeclass
      integer, intent(in) :: size
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_match_size( &
         typeclass, &
         size, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_match_size

   subroutine MPI_Pcontrol( &
      level &
   )
      integer, intent(in) :: level
      call wrapped_MPI_Pcontrol( &
         level &
      )
   end subroutine MPI_Pcontrol

   subroutine MPI_Attr_delete( &
      comm, &
      keyval, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Attr_delete( &
         comm, &
         keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Attr_delete

   subroutine MPI_Attr_get( &
      comm, &
      keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Attr_get( &
         comm, &
         keyval, &
         attribute_val, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Attr_get

   subroutine MPI_Attr_put( &
      comm, &
      keyval, &
      attribute_val, &
      ierror &
   )
      type(MPI_Comm), intent(in) :: comm
      integer, intent(in) :: keyval
      !dir$ ignore_tkr(tkr) attribute_val
      !gcc$ attributes no_arg_check :: attribute_val
      integer :: attribute_val(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Attr_put( &
         comm, &
         keyval, &
         attribute_val, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Attr_put

   subroutine MPI_Get_elements_x( &
      status, &
      datatype, &
      count, &
      ierror &
   )
      type(MPI_Status), intent(in) :: status
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_COUNT_KIND), intent(out) :: count
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Get_elements_x( &
         status, &
         datatype, &
         count, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Get_elements_x

   subroutine MPI_Info_get( &
      info, &
      key, &
      valuelen, &
      value, &
      flag, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: key
      integer, intent(in) :: valuelen
      character(*), intent(out) :: value
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_get( &
         info, &
         key, &
         valuelen, &
         value, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_get

   subroutine MPI_Info_get_valuelen( &
      info, &
      key, &
      valuelen, &
      flag, &
      ierror &
   )
      type(MPI_Info), intent(in) :: info
      character(*), intent(in) :: key
      integer, intent(out) :: valuelen
      logical, intent(out) :: flag
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Info_get_valuelen( &
         info, &
         key, &
         valuelen, &
         flag, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Info_get_valuelen

   subroutine MPI_Keyval_create( &
      copy_fn, &
      delete_fn, &
      keyval, &
      extra_state, &
      ierror &
   )
      external :: copy_fn
      external :: delete_fn
      integer, intent(out) :: keyval
      !dir$ ignore_tkr(tkr) extra_state
      !gcc$ attributes no_arg_check :: extra_state
      integer :: extra_state(*)
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Keyval_create( &
         copy_fn, &
         delete_fn, &
         keyval, &
         extra_state, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Keyval_create

   subroutine MPI_Keyval_free( &
      keyval, &
      ierror &
   )
      integer, intent(out) :: keyval
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Keyval_free( &
         keyval, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Keyval_free

   subroutine MPI_Status_set_elements_x( &
      status, &
      datatype, &
      count, &
      ierror &
   )
      type(MPI_Status), intent(out) :: status
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_COUNT_KIND), intent(in) :: count
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Status_set_elements_x( &
         status, &
         datatype, &
         count, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Status_set_elements_x

   subroutine MPI_Type_get_extent_x( &
      datatype, &
      lb, &
      extent, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_COUNT_KIND), intent(out) :: lb
      integer(MPI_COUNT_KIND), intent(out) :: extent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_extent_x( &
         datatype, &
         lb, &
         extent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_extent_x

   subroutine MPI_Type_get_true_extent_x( &
      datatype, &
      true_lb, &
      true_extent, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_COUNT_KIND), intent(out) :: true_lb
      integer(MPI_COUNT_KIND), intent(out) :: true_extent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_get_true_extent_x( &
         datatype, &
         true_lb, &
         true_extent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_get_true_extent_x

   subroutine MPI_Type_size_x( &
      datatype, &
      size, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_COUNT_KIND), intent(out) :: size
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_size_x( &
         datatype, &
         size, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_size_x

   subroutine MPI_Address( &
      location, &
      address, &
      ierror &
   )
      !dir$ ignore_tkr(tkr) location
      !gcc$ attributes no_arg_check :: location
      integer :: location(*)
      integer(MPI_ADDRESS_KIND), intent(out) :: address
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Address( &
         location, &
         address, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Address

   subroutine MPI_Type_hindexed( &
      count, &
      array_of_blocklengths, &
      array_of_displacements, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(out) :: array_of_blocklengths
      integer(MPI_ADDRESS_KIND), intent(out) :: array_of_displacements
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_hindexed( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_hindexed

   subroutine MPI_Type_hvector( &
      count, &
      blocklength, &
      stride, &
      oldtype, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(in) :: blocklength
      integer(MPI_ADDRESS_KIND), intent(in) :: stride
      type(MPI_Datatype), intent(in) :: oldtype
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_hvector( &
         count, &
         blocklength, &
         stride, &
         oldtype, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_hvector

   subroutine MPI_Type_struct( &
      count, &
      array_of_blocklengths, &
      array_of_displacements, &
      array_of_types, &
      newtype, &
      ierror &
   )
      integer, intent(in) :: count
      integer, intent(out) :: array_of_blocklengths
      integer(MPI_ADDRESS_KIND), intent(out) :: array_of_displacements
      type(MPI_Datatype), intent(out) :: array_of_types
      type(MPI_Datatype), intent(out) :: newtype
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_struct( &
         count, &
         array_of_blocklengths, &
         array_of_displacements, &
         array_of_types, &
         newtype, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_struct

   subroutine MPI_Type_extent( &
      datatype, &
      extent, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: extent
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_extent( &
         datatype, &
         extent, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_extent

   subroutine MPI_Type_lb( &
      datatype, &
      displacement, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: displacement
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_lb( &
         datatype, &
         displacement, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_lb

   subroutine MPI_Type_ub( &
      datatype, &
      displacement, &
      ierror &
   )
      type(MPI_Datatype), intent(in) :: datatype
      integer(MPI_ADDRESS_KIND), intent(out) :: displacement
      integer, intent(out), optional :: ierror
      integer :: wrap_ierror
      call wrapped_MPI_Type_ub( &
         datatype, &
         displacement, &
         wrap_ierror &
      )
      if (present(ierror)) ierror = wrap_ierror
   end subroutine MPI_Type_ub

end module mpi_f08_functions
