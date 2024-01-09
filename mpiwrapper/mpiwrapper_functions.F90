! MPI Fortran function wrappers

! This file has been generated automatically
! by `mpiwrapper/generate_wrappers.jl`.
! Do not modify this file, changes will be overwritten.

subroutine MPIABI_Bsend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Bsend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bsend

subroutine MPIABI_Bsend_init( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Bsend_init( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bsend_init

subroutine MPIABI_Buffer_attach( &
   buffer, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer :: buffer(*)
   integer, intent(in) :: size
   integer, intent(out) :: ierror
   call MPI_Buffer_attach( &
      buffer, &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Buffer_attach

subroutine MPIABI_Buffer_detach( &
   buffer_addr, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer(MPIABI_ADDRESS_KIND), intent(out) :: buffer_addr
   integer, intent(out) :: size
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_buffer_addr
   call MPI_Buffer_detach( &
      wrap_buffer_addr, &
      size, &
      ierror &
   )
   buffer_addr = mpi2abi_address(wrap_buffer_addr)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Buffer_detach

subroutine MPIABI_Buffer_flush( &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Buffer_flush is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Buffer_flush( &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Buffer_flush

subroutine MPIABI_Buffer_iflush( &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: request
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Buffer_iflush is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Buffer_iflush( &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Buffer_iflush

subroutine MPIABI_Cancel( &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Cancel( &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cancel

subroutine MPIABI_Comm_attach_buffer( &
   comm, &
   buffer, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: buffer(*)
   integer, intent(in) :: size
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Comm_attach_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Comm_attach_buffer( &
      abi2mpi_comm(comm), &
      buffer, &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_attach_buffer

subroutine MPIABI_Comm_detach_buffer( &
   comm, &
   buffer_addr, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer(MPIABI_ADDRESS_KIND), intent(out) :: buffer_addr
   integer, intent(out) :: size
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Comm_detach_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: wrap_buffer_addr
   call MPI_Comm_detach_buffer( &
      abi2mpi_comm(comm), &
      wrap_buffer_addr, &
      size, &
      ierror &
   )
   buffer_addr = mpi2abi_address(wrap_buffer_addr)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_detach_buffer

subroutine MPIABI_Comm_flush_buffer( &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Comm_flush_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Comm_flush_buffer( &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_flush_buffer

subroutine MPIABI_Comm_iflush_buffer( &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Comm_iflush_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Comm_iflush_buffer( &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_iflush_buffer

subroutine MPIABI_Get_count( &
   status, &
   datatype, &
   count, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: datatype
   integer, intent(out) :: count
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   integer :: wrap_count
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Get_count( &
      wrap_status, &
      abi2mpi_datatype(datatype), &
      wrap_count, &
      ierror &
   )
   count = mpi2abi_maybe_undefined(wrap_count)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_count

subroutine MPIABI_Ibsend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ibsend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ibsend

subroutine MPIABI_Improbe( &
   source, &
   tag, &
   comm, &
   flag, &
   message, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   logical, intent(out) :: flag
   integer, intent(out) :: message
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Improbe( &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      flag, &
      message, &
      wrap_status, &
      ierror &
   )
   if (flag) message = mpi2abi_message(message)
   if (flag) call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Improbe

subroutine MPIABI_Imrecv( &
   buf, &
   count, &
   datatype, &
   message, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: message
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Imrecv( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      message, &
      request, &
      ierror &
   )
   message = mpi2abi_message(message)
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Imrecv

subroutine MPIABI_Iprobe( &
   source, &
   tag, &
   comm, &
   flag, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   logical, intent(out) :: flag
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Iprobe( &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      flag, &
      wrap_status, &
      ierror &
   )
   if (flag) call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iprobe

subroutine MPIABI_Irecv( &
   buf, &
   count, &
   datatype, &
   source, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Irecv( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Irecv

subroutine MPIABI_Irsend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Irsend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Irsend

subroutine MPIABI_Isend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Isend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Isend

subroutine MPIABI_Isendrecv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(in) :: dest
   integer, intent(in) :: sendtag
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: source
   integer, intent(in) :: recvtag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Isendrecv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(sendtag), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(recvtag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Isendrecv

subroutine MPIABI_Isendrecv_replace( &
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
   use mpiwrapper
   implicit none
   integer, intent(inout) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: sendtag
   integer, intent(in) :: source
   integer, intent(in) :: recvtag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Isendrecv_replace( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(sendtag), &
      abi2mpi_proc(source), &
      abi2mpi_tag(recvtag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Isendrecv_replace

subroutine MPIABI_Issend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Issend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Issend

subroutine MPIABI_Mprobe( &
   source, &
   tag, &
   comm, &
   message, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: message
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Mprobe( &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      message, &
      wrap_status, &
      ierror &
   )
   message = mpi2abi_message(message)
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Mprobe

subroutine MPIABI_Mrecv( &
   buf, &
   count, &
   datatype, &
   message, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: message
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Mrecv( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      message, &
      wrap_status, &
      ierror &
   )
   message = mpi2abi_message(message)
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Mrecv

subroutine MPIABI_Probe( &
   source, &
   tag, &
   comm, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Probe( &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Probe

subroutine MPIABI_Recv( &
   buf, &
   count, &
   datatype, &
   source, &
   tag, &
   comm, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Recv( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Recv

subroutine MPIABI_Recv_init( &
   buf, &
   count, &
   datatype, &
   source, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Recv_init( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Recv_init

subroutine MPIABI_Request_free( &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(inout) :: request
   integer, intent(out) :: ierror
   request = abi2mpi_request(request)
   call MPI_Request_free( &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Request_free

subroutine MPIABI_Request_get_status( &
   request, &
   flag, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: request
   logical, intent(out) :: flag
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Request_get_status( &
      abi2mpi_request(request), &
      flag, &
      wrap_status, &
      ierror &
   )
   if (flag) call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Request_get_status

subroutine MPIABI_Request_get_status_all( &
   count, &
   array_of_requests, &
   flag, &
   array_of_statuses, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: array_of_requests(count)
   logical, intent(out) :: flag
   integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, count)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Request_get_status_all is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer :: wrap_array_of_requests(count)
   integer(MPI_ADDRESS_KIND) :: ptr_array_of_statuses
   integer :: wrap_array_of_statuses(MPI_STATUS_SIZE, count)
   pointer(ptr_array_of_statuses, wrap_array_of_statuses)
   integer :: tmp_array_of_statuses(MPI_STATUS_SIZE, count)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_array_of_statuses = abi2mpi_statuses_ptr_uninitialized(array_of_statuses, tmp_array_of_statuses, count)
   call MPI_Request_get_status_all( &
      count, &
      wrap_array_of_requests, &
      flag, &
      wrap_array_of_statuses, &
      ierror &
   )
   if (flag) call mpi2abi_statuses_ptr(wrap_array_of_statuses, array_of_statuses, count)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Request_get_status_all

subroutine MPIABI_Request_get_status_any( &
   count, &
   array_of_requests, &
   index, &
   flag, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: array_of_requests(count)
   integer, intent(out) :: index
   logical, intent(out) :: flag
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Request_get_status_any is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer :: wrap_array_of_requests(count)
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Request_get_status_any( &
      count, &
      wrap_array_of_requests, &
      index, &
      flag, &
      wrap_status, &
      ierror &
   )
   if (flag) call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Request_get_status_any

subroutine MPIABI_Request_get_status_some( &
   incount, &
   array_of_requests, &
   outcount, &
   array_of_indices, &
   array_of_statuses, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: incount
   integer, intent(in) :: array_of_requests(incount)
   integer, intent(out) :: outcount
   integer, intent(out) :: array_of_indices(incount)
   integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, incount)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Request_get_status_some is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer :: wrap_array_of_requests(incount)
   integer(MPI_ADDRESS_KIND) :: ptr_array_of_statuses
   integer :: wrap_array_of_statuses(MPI_STATUS_SIZE, incount)
   pointer(ptr_array_of_statuses, wrap_array_of_statuses)
   integer :: tmp_array_of_statuses(MPI_STATUS_SIZE, incount)
   integer :: i
   do i = 1, incount
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_array_of_statuses = abi2mpi_statuses_ptr_uninitialized(array_of_statuses, tmp_array_of_statuses, incount)
   call MPI_Request_get_status_some( &
      incount, &
      wrap_array_of_requests, &
      outcount, &
      array_of_indices, &
      wrap_array_of_statuses, &
      ierror &
   )
   call mpi2abi_statuses_ptr(wrap_array_of_statuses, array_of_statuses, outcount)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Request_get_status_some

subroutine MPIABI_Rsend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Rsend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rsend

subroutine MPIABI_Rsend_init( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Rsend_init( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rsend_init

subroutine MPIABI_Send( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Send( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Send

subroutine MPIABI_Send_init( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Send_init( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Send_init

subroutine MPIABI_Sendrecv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(in) :: dest
   integer, intent(in) :: sendtag
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: source
   integer, intent(in) :: recvtag
   integer, intent(in) :: comm
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Sendrecv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(sendtag), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(recvtag), &
      abi2mpi_comm(comm), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Sendrecv

subroutine MPIABI_Sendrecv_replace( &
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
   use mpiwrapper
   implicit none
   integer, intent(inout) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: sendtag
   integer, intent(in) :: source
   integer, intent(in) :: recvtag
   integer, intent(in) :: comm
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Sendrecv_replace( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(sendtag), &
      abi2mpi_proc(source), &
      abi2mpi_tag(recvtag), &
      abi2mpi_comm(comm), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Sendrecv_replace

subroutine MPIABI_Session_attach_buffer( &
   session, &
   buffer, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(in) :: buffer(*)
   integer, intent(in) :: size
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Session_attach_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Session_attach_buffer( &
      abi2mpi_session(session), &
      buffer, &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Session_attach_buffer

subroutine MPIABI_Session_detach_buffer( &
   session, &
   buffer_addr, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer(MPIABI_ADDRESS_KIND), intent(out) :: buffer_addr
   integer, intent(out) :: size
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Session_detach_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: wrap_buffer_addr
   call MPI_Session_detach_buffer( &
      abi2mpi_session(session), &
      wrap_buffer_addr, &
      size, &
      ierror &
   )
   buffer_addr = mpi2abi_address(wrap_buffer_addr)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Session_detach_buffer

subroutine MPIABI_Session_flush_buffer( &
   session, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Session_flush_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Session_flush_buffer( &
      abi2mpi_session(session), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Session_flush_buffer

subroutine MPIABI_Session_iflush_buffer( &
   session, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(out) :: request
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Session_iflush_buffer is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Session_iflush_buffer( &
      abi2mpi_session(session), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Session_iflush_buffer

subroutine MPIABI_Ssend( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Ssend( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ssend

subroutine MPIABI_Ssend_init( &
   buf, &
   count, &
   datatype, &
   dest, &
   tag, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: dest
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ssend_init( &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(dest), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ssend_init

subroutine MPIABI_Start( &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(inout) :: request
   integer, intent(out) :: ierror
   request = abi2mpi_request(request)
   call MPI_Start( &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Start

subroutine MPIABI_Startall( &
   count, &
   array_of_requests, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(inout) :: array_of_requests(count)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(count)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   call MPI_Startall( &
      count, &
      wrap_array_of_requests, &
      ierror &
   )
   do i = 1, count
      array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Startall

subroutine MPIABI_Status_get_error( &
   status, &
   err, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: err
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Status_get_error is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Status_get_error( &
      wrap_status, &
      err, &
      ierror &
   )
   err = mpi2abi_errorcode(err)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Status_get_error

subroutine MPIABI_Status_get_source( &
   status, &
   source, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: source
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Status_get_source is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Status_get_source( &
      wrap_status, &
      source, &
      ierror &
   )
   source = mpi2abi_proc(source)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Status_get_source

subroutine MPIABI_Status_get_tag( &
   status, &
   tag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: tag
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Status_get_tag is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Status_get_tag( &
      wrap_status, &
      tag, &
      ierror &
   )
   tag = mpi2abi_tag(tag)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Status_get_tag

subroutine MPIABI_Test( &
   request, &
   flag, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(inout) :: request
   logical, intent(out) :: flag
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   request = abi2mpi_request(request)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Test( &
      request, &
      flag, &
      wrap_status, &
      ierror &
   )
   request = mpi2abi_request(request)
   if (flag) call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Test

subroutine MPIABI_Test_cancelled( &
   status, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Test_cancelled( &
      wrap_status, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Test_cancelled

subroutine MPIABI_Testall( &
   count, &
   array_of_requests, &
   flag, &
   array_of_statuses, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(inout) :: array_of_requests(count)
   logical, intent(out) :: flag
   integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, count)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(count)
   integer(MPI_ADDRESS_KIND) :: ptr_array_of_statuses
   integer :: wrap_array_of_statuses(MPI_STATUS_SIZE, count)
   pointer(ptr_array_of_statuses, wrap_array_of_statuses)
   integer :: tmp_array_of_statuses(MPI_STATUS_SIZE, count)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_array_of_statuses = abi2mpi_statuses_ptr_uninitialized(array_of_statuses, tmp_array_of_statuses, count)
   call MPI_Testall( &
      count, &
      wrap_array_of_requests, &
      flag, &
      wrap_array_of_statuses, &
      ierror &
   )
   do i = 1, count
      if (flag) array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   if (flag) call mpi2abi_statuses_ptr(wrap_array_of_statuses, array_of_statuses, count)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Testall

subroutine MPIABI_Testany( &
   count, &
   array_of_requests, &
   index, &
   flag, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(inout) :: array_of_requests(count)
   integer, intent(out) :: index
   logical, intent(out) :: flag
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(count)
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Testany( &
      count, &
      wrap_array_of_requests, &
      index, &
      flag, &
      wrap_status, &
      ierror &
   )
   do i = 1, count
      if (flag .and. i == index) array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   if (flag) call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Testany

subroutine MPIABI_Testsome( &
   incount, &
   array_of_requests, &
   outcount, &
   array_of_indices, &
   array_of_statuses, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: incount
   integer, intent(inout) :: array_of_requests(incount)
   integer, intent(out) :: outcount
   integer, intent(out) :: array_of_indices(incount)
   integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, incount)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(incount)
   integer(MPI_ADDRESS_KIND) :: ptr_array_of_statuses
   integer :: wrap_array_of_statuses(MPI_STATUS_SIZE, incount)
   pointer(ptr_array_of_statuses, wrap_array_of_statuses)
   integer :: tmp_array_of_statuses(MPI_STATUS_SIZE, incount)
   integer :: i
   do i = 1, incount
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_array_of_statuses = abi2mpi_statuses_ptr_uninitialized(array_of_statuses, tmp_array_of_statuses, incount)
   call MPI_Testsome( &
      incount, &
      wrap_array_of_requests, &
      outcount, &
      array_of_indices, &
      wrap_array_of_statuses, &
      ierror &
   )
   do i = 1, incount
      if (i <= outcount) array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   call mpi2abi_statuses_ptr(wrap_array_of_statuses, array_of_statuses, outcount)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Testsome

subroutine MPIABI_Wait( &
   request, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(inout) :: request
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   request = abi2mpi_request(request)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Wait( &
      request, &
      wrap_status, &
      ierror &
   )
   request = mpi2abi_request(request)
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Wait

subroutine MPIABI_Waitall( &
   count, &
   array_of_requests, &
   array_of_statuses, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(inout) :: array_of_requests(count)
   integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, count)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(count)
   integer(MPI_ADDRESS_KIND) :: ptr_array_of_statuses
   integer :: wrap_array_of_statuses(MPI_STATUS_SIZE, count)
   pointer(ptr_array_of_statuses, wrap_array_of_statuses)
   integer :: tmp_array_of_statuses(MPI_STATUS_SIZE, count)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_array_of_statuses = abi2mpi_statuses_ptr_uninitialized(array_of_statuses, tmp_array_of_statuses, count)
   call MPI_Waitall( &
      count, &
      wrap_array_of_requests, &
      wrap_array_of_statuses, &
      ierror &
   )
   do i = 1, count
      array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   call mpi2abi_statuses_ptr(wrap_array_of_statuses, array_of_statuses, count)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Waitall

subroutine MPIABI_Waitany( &
   count, &
   array_of_requests, &
   index, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(inout) :: array_of_requests(count)
   integer, intent(out) :: index
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(count)
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   integer :: i
   do i = 1, count
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Waitany( &
      count, &
      wrap_array_of_requests, &
      index, &
      wrap_status, &
      ierror &
   )
   do i = 1, count
      if (i == index) array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Waitany

subroutine MPIABI_Waitsome( &
   incount, &
   array_of_requests, &
   outcount, &
   array_of_indices, &
   array_of_statuses, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: incount
   integer, intent(inout) :: array_of_requests(incount)
   integer, intent(out) :: outcount
   integer, intent(out) :: array_of_indices(incount)
   integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, incount)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_requests(incount)
   integer(MPI_ADDRESS_KIND) :: ptr_array_of_statuses
   integer :: wrap_array_of_statuses(MPI_STATUS_SIZE, incount)
   pointer(ptr_array_of_statuses, wrap_array_of_statuses)
   integer :: tmp_array_of_statuses(MPI_STATUS_SIZE, incount)
   integer :: i
   do i = 1, incount
      wrap_array_of_requests(i) = abi2mpi_request(array_of_requests(i))
   end do
   ptr_array_of_statuses = abi2mpi_statuses_ptr_uninitialized(array_of_statuses, tmp_array_of_statuses, incount)
   call MPI_Waitsome( &
      incount, &
      wrap_array_of_requests, &
      outcount, &
      array_of_indices, &
      wrap_array_of_statuses, &
      ierror &
   )
   do i = 1, incount
      if (i <= outcount) array_of_requests(i) = mpi2abi_request(wrap_array_of_requests(i))
   end do
   call mpi2abi_statuses_ptr(wrap_array_of_statuses, array_of_statuses, outcount)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Waitsome

subroutine MPIABI_Parrived( &
   request, &
   partition, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: request
   integer, intent(in) :: partition
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Parrived( &
      abi2mpi_request(request), &
      partition, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Parrived

subroutine MPIABI_Pready( &
   partition, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: partition
   integer, intent(in) :: request
   integer, intent(out) :: ierror
   call MPI_Pready( &
      partition, &
      abi2mpi_request(request), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pready

subroutine MPIABI_Pready_list( &
   length, &
   array_of_partitions, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: length
   integer, intent(in) :: array_of_partitions(length)
   integer, intent(in) :: request
   integer, intent(out) :: ierror
   call MPI_Pready_list( &
      length, &
      array_of_partitions, &
      abi2mpi_request(request), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pready_list

subroutine MPIABI_Pready_range( &
   partition_low, &
   partition_high, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: partition_low
   integer, intent(in) :: partition_high
   integer, intent(in) :: request
   integer, intent(out) :: ierror
   call MPI_Pready_range( &
      partition_low, &
      partition_high, &
      abi2mpi_request(request), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pready_range

subroutine MPIABI_Precv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: partitions
   integer(MPIABI_COUNT_KIND), intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Precv_init( &
      buf, &
      partitions, &
      abi2mpi_count(count), &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Precv_init

subroutine MPIABI_Psend_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   integer, intent(in) :: partitions
   integer(MPIABI_COUNT_KIND), intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: source
   integer, intent(in) :: tag
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Psend_init( &
      buf, &
      partitions, &
      abi2mpi_count(count), &
      abi2mpi_datatype(datatype), &
      abi2mpi_proc(source), &
      abi2mpi_tag(tag), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Psend_init

function MPIABI_Aint_add( &
   base, &
   disp &
) result(result)
   use mpiwrapper
   implicit none
   integer(MPIABI_ADDRESS_KIND), intent(in) :: base
   integer(MPIABI_ADDRESS_KIND), intent(in) :: disp
   integer(MPIABI_ADDRESS_KIND) :: result
   result = MPI_Aint_add( &
      abi2mpi_address(base), &
      abi2mpi_address(disp) &
   )
end function MPIABI_Aint_add

function MPIABI_Aint_diff( &
   addr1, &
   addr2 &
) result(result)
   use mpiwrapper
   implicit none
   integer(MPIABI_ADDRESS_KIND), intent(in) :: addr1
   integer(MPIABI_ADDRESS_KIND), intent(in) :: addr2
   integer(MPIABI_ADDRESS_KIND) :: result
   result = MPI_Aint_diff( &
      abi2mpi_address(addr1), &
      abi2mpi_address(addr2) &
   )
end function MPIABI_Aint_diff

subroutine MPIABI_Get_address( &
   location, &
   address, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: location(*)
   integer(MPIABI_ADDRESS_KIND), intent(out) :: address
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_address
   call MPI_Get_address( &
      location, &
      wrap_address, &
      ierror &
   )
   address = mpi2abi_address(wrap_address)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_address

subroutine MPIABI_Get_elements( &
   status, &
   datatype, &
   count, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: datatype
   integer, intent(out) :: count
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Get_elements( &
      wrap_status, &
      abi2mpi_datatype(datatype), &
      count, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_elements

subroutine MPIABI_Pack( &
   inbuf, &
   incount, &
   datatype, &
   outbuf, &
   outsize, &
   position, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: inbuf(*)
   integer, intent(in) :: incount
   integer, intent(in) :: datatype
   integer, intent(out) :: outbuf(*)
   integer, intent(in) :: outsize
   integer, intent(out) :: position
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Pack( &
      inbuf, &
      incount, &
      abi2mpi_datatype(datatype), &
      outbuf, &
      outsize, &
      position, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack

subroutine MPIABI_Pack_external( &
   datarep, &
   inbuf, &
   incount, &
   datatype, &
   outbuf, &
   outsize, &
   position, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: datarep
   integer, intent(in) :: inbuf(*)
   integer, intent(in) :: incount
   integer, intent(in) :: datatype
   integer, intent(out) :: outbuf(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: outsize
   integer(MPIABI_ADDRESS_KIND), intent(out) :: position
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_position
   call MPI_Pack_external( &
      datarep, &
      inbuf, &
      incount, &
      abi2mpi_datatype(datatype), &
      outbuf, &
      abi2mpi_address(outsize), &
      wrap_position, &
      ierror &
   )
   position = mpi2abi_address(wrap_position)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack_external

subroutine MPIABI_Pack_external_size( &
   datarep, &
   incount, &
   datatype, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: datarep
   integer(MPIABI_COUNT_KIND), intent(in) :: incount
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: size
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_size
   call MPI_Pack_external_size( &
      datarep, &
      abi2mpi_count(incount), &
      abi2mpi_datatype(datatype), &
      wrap_size, &
      ierror &
   )
   size = mpi2abi_address(wrap_size)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack_external_size

subroutine MPIABI_Pack_size( &
   incount, &
   datatype, &
   comm, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: incount
   integer, intent(in) :: datatype
   integer, intent(in) :: comm
   integer, intent(out) :: size
   integer, intent(out) :: ierror
   call MPI_Pack_size( &
      incount, &
      abi2mpi_datatype(datatype), &
      abi2mpi_comm(comm), &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack_size

subroutine MPIABI_Type_commit( &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: datatype
   integer, intent(out) :: ierror
   call MPI_Type_commit( &
      datatype, &
      ierror &
   )
   datatype = mpi2abi_datatype(datatype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_commit

subroutine MPIABI_Type_contiguous( &
   count, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_contiguous( &
      count, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_contiguous

subroutine MPIABI_Type_create_darray( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: size
   integer, intent(in) :: rank
   integer, intent(in) :: ndims
   integer, intent(in) :: array_of_gsizes(ndims)
   integer, intent(in) :: array_of_distribs(ndims)
   integer, intent(in) :: array_of_dargs(ndims)
   integer, intent(in) :: array_of_psizes(ndims)
   integer, intent(in) :: order
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_darray( &
      size, &
      rank, &
      ndims, &
      array_of_gsizes, &
      array_of_distribs, &
      array_of_dargs, &
      array_of_psizes, &
      order, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_darray

subroutine MPIABI_Type_create_hindexed( &
   count, &
   array_of_blocklengths, &
   array_of_displacements, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: array_of_blocklengths(count)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_array_of_displacements(count)
   integer :: i
   do i = 1, count
      wrap_array_of_displacements(i) = abi2mpi_address(array_of_displacements(i))
   end do
   call MPI_Type_create_hindexed( &
      count, &
      array_of_blocklengths, &
      wrap_array_of_displacements, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_hindexed

subroutine MPIABI_Type_create_hindexed_block( &
   count, &
   blocklength, &
   array_of_displacements, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: blocklength
   integer(MPIABI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_array_of_displacements(count)
   integer :: i
   do i = 1, count
      wrap_array_of_displacements(i) = abi2mpi_address(array_of_displacements(i))
   end do
   call MPI_Type_create_hindexed_block( &
      count, &
      blocklength, &
      wrap_array_of_displacements, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_hindexed_block

subroutine MPIABI_Type_create_hvector( &
   count, &
   blocklength, &
   stride, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: blocklength
   integer(MPIABI_ADDRESS_KIND), intent(in) :: stride
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_hvector( &
      count, &
      blocklength, &
      abi2mpi_address(stride), &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_hvector

subroutine MPIABI_Type_create_indexed_block( &
   count, &
   blocklength, &
   array_of_displacements, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: blocklength
   integer, intent(in) :: array_of_displacements(count)
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_indexed_block( &
      count, &
      blocklength, &
      array_of_displacements, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_indexed_block

subroutine MPIABI_Type_create_resized( &
   oldtype, &
   lb, &
   extent, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: oldtype
   integer(MPIABI_ADDRESS_KIND), intent(in) :: lb
   integer(MPIABI_ADDRESS_KIND), intent(in) :: extent
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_resized( &
      abi2mpi_datatype(oldtype), &
      abi2mpi_address(lb), &
      abi2mpi_address(extent), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_resized

subroutine MPIABI_Type_create_struct( &
   count, &
   array_of_blocklengths, &
   array_of_displacements, &
   array_of_types, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: array_of_blocklengths(count)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
   integer, intent(in) :: array_of_types(count)
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_array_of_displacements(count)
   integer :: wrap_array_of_types(count)
   integer :: i
   do i = 1, count
      wrap_array_of_displacements(i) = abi2mpi_address(array_of_displacements(i))
   end do
   do i = 1, count
      wrap_array_of_types(i) = abi2mpi_datatype(array_of_types(i))
   end do
   call MPI_Type_create_struct( &
      count, &
      array_of_blocklengths, &
      wrap_array_of_displacements, &
      wrap_array_of_types, &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_struct

subroutine MPIABI_Type_create_subarray( &
   ndims, &
   array_of_sizes, &
   array_of_subsizes, &
   array_of_starts, &
   order, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: ndims
   integer, intent(in) :: array_of_sizes(ndims)
   integer, intent(in) :: array_of_subsizes(ndims)
   integer, intent(in) :: array_of_starts(ndims)
   integer, intent(in) :: order
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_subarray( &
      ndims, &
      array_of_sizes, &
      array_of_subsizes, &
      array_of_starts, &
      order, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_subarray

subroutine MPIABI_Type_dup( &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_dup( &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_dup

subroutine MPIABI_Type_free( &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: datatype
   integer, intent(out) :: ierror
   call MPI_Type_free( &
      datatype, &
      ierror &
   )
   datatype = mpi2abi_datatype(datatype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_free

subroutine MPIABI_Type_get_contents( &
   datatype, &
   max_integers, &
   max_addresses, &
   max_datatypes, &
   array_of_integers, &
   array_of_addresses, &
   array_of_datatypes, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer, intent(in) :: max_integers
   integer, intent(in) :: max_addresses
   integer, intent(in) :: max_datatypes
   integer, intent(out) :: array_of_integers
   integer(MPIABI_ADDRESS_KIND), intent(out) :: array_of_addresses
   integer, intent(out) :: array_of_datatypes
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_array_of_addresses
   call MPI_Type_get_contents( &
      abi2mpi_datatype(datatype), &
      max_integers, &
      max_addresses, &
      max_datatypes, &
      array_of_integers, &
      wrap_array_of_addresses, &
      array_of_datatypes, &
      ierror &
   )
   array_of_addresses = mpi2abi_address(wrap_array_of_addresses)
   array_of_datatypes = mpi2abi_datatype(array_of_datatypes)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_contents

subroutine MPIABI_Type_get_envelope( &
   datatype, &
   num_integers, &
   num_addresses, &
   num_datatypes, &
   combiner, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer, intent(out) :: num_integers
   integer, intent(out) :: num_addresses
   integer, intent(out) :: num_datatypes
   integer, intent(out) :: combiner
   integer, intent(out) :: ierror
   call MPI_Type_get_envelope( &
      abi2mpi_datatype(datatype), &
      num_integers, &
      num_addresses, &
      num_datatypes, &
      combiner, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_envelope

subroutine MPIABI_Type_get_extent( &
   datatype, &
   lb, &
   extent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: lb
   integer(MPIABI_ADDRESS_KIND), intent(out) :: extent
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_lb
   integer(MPI_ADDRESS_KIND) :: wrap_extent
   call MPI_Type_get_extent( &
      abi2mpi_datatype(datatype), &
      wrap_lb, &
      wrap_extent, &
      ierror &
   )
   lb = mpi2abi_address(wrap_lb)
   extent = mpi2abi_address(wrap_extent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_extent

subroutine MPIABI_Type_get_true_extent( &
   datatype, &
   true_lb, &
   true_extent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: true_lb
   integer(MPIABI_ADDRESS_KIND), intent(out) :: true_extent
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_true_lb
   integer(MPI_ADDRESS_KIND) :: wrap_true_extent
   call MPI_Type_get_true_extent( &
      abi2mpi_datatype(datatype), &
      wrap_true_lb, &
      wrap_true_extent, &
      ierror &
   )
   true_lb = mpi2abi_address(wrap_true_lb)
   true_extent = mpi2abi_address(wrap_true_extent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_true_extent

subroutine MPIABI_Type_indexed( &
   count, &
   array_of_blocklengths, &
   array_of_displacements, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: array_of_blocklengths(count)
   integer, intent(in) :: array_of_displacements(count)
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_indexed( &
      count, &
      array_of_blocklengths, &
      array_of_displacements, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_indexed

subroutine MPIABI_Type_size( &
   datatype, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer, intent(out) :: size
   integer, intent(out) :: ierror
   call MPI_Type_size( &
      abi2mpi_datatype(datatype), &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_size

subroutine MPIABI_Type_vector( &
   count, &
   blocklength, &
   stride, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: blocklength
   integer, intent(in) :: stride
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_vector( &
      count, &
      blocklength, &
      stride, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_vector

subroutine MPIABI_Unpack( &
   inbuf, &
   insize, &
   position, &
   outbuf, &
   outcount, &
   datatype, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: inbuf(*)
   integer, intent(in) :: insize
   integer, intent(out) :: position
   integer, intent(out) :: outbuf(*)
   integer, intent(in) :: outcount
   integer, intent(in) :: datatype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Unpack( &
      inbuf, &
      insize, &
      position, &
      outbuf, &
      outcount, &
      abi2mpi_datatype(datatype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Unpack

subroutine MPIABI_Unpack_external( &
   datarep, &
   inbuf, &
   insize, &
   position, &
   outbuf, &
   outcount, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: datarep
   integer, intent(in) :: inbuf(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: insize
   integer(MPIABI_ADDRESS_KIND), intent(out) :: position
   integer, intent(out) :: outbuf(*)
   integer, intent(in) :: outcount
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_position
   call MPI_Unpack_external( &
      datarep, &
      inbuf, &
      abi2mpi_address(insize), &
      wrap_position, &
      outbuf, &
      outcount, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   position = mpi2abi_address(wrap_position)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Unpack_external

subroutine MPIABI_Allgather( &
   sendbuf, &
   sendcount, &
   sendtype, &
   recvbuf, &
   recvcount, &
   recvtype, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Allgather( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allgather

subroutine MPIABI_Allgather_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Allgather_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allgather_init

subroutine MPIABI_Allgatherv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Allgatherv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allgatherv

subroutine MPIABI_Allgatherv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Allgatherv_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allgatherv_init

subroutine MPIABI_Allreduce( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Allreduce( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allreduce

subroutine MPIABI_Allreduce_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Allreduce_init( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allreduce_init

subroutine MPIABI_Alltoall( &
   sendbuf, &
   sendcount, &
   sendtype, &
   recvbuf, &
   recvcount, &
   recvtype, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Alltoall( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Alltoall

subroutine MPIABI_Alltoall_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Alltoall_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Alltoall_init

subroutine MPIABI_Alltoallv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Alltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      rdispls, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Alltoallv

subroutine MPIABI_Alltoallv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Alltoallv_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      rdispls, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Alltoallv_init

subroutine MPIABI_Alltoallw( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtypes(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtypes(*)
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   integer, allocatable :: wrap_sendtypes(:)
   integer, allocatable :: wrap_recvtypes(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_sendtypes(comm_size))
   allocate(wrap_recvtypes(comm_size))
   do i = 1, comm_size
      wrap_sendtypes(i) = abi2mpi_datatype(sendtypes(i))
   end do
   do i = 1, comm_size
      wrap_recvtypes(i) = abi2mpi_datatype(recvtypes(i))
   end do
   call MPI_Alltoallw( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      wrap_sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      wrap_recvtypes, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_sendtypes)
   deallocate(wrap_recvtypes)
end subroutine MPIABI_Alltoallw

subroutine MPIABI_Alltoallw_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtypes(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtypes(*)
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   integer, allocatable :: wrap_sendtypes(:)
   integer, allocatable :: wrap_recvtypes(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_sendtypes(comm_size))
   allocate(wrap_recvtypes(comm_size))
   do i = 1, comm_size
      wrap_sendtypes(i) = abi2mpi_datatype(sendtypes(i))
   end do
   do i = 1, comm_size
      wrap_recvtypes(i) = abi2mpi_datatype(recvtypes(i))
   end do
   call MPI_Alltoallw_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      wrap_sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      wrap_recvtypes, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_sendtypes)
   deallocate(wrap_recvtypes)
end subroutine MPIABI_Alltoallw_init

subroutine MPIABI_Barrier( &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Barrier( &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Barrier

subroutine MPIABI_Barrier_init( &
   comm, &
   info, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Barrier_init( &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Barrier_init

subroutine MPIABI_Bcast( &
   buffer, &
   count, &
   datatype, &
   root, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buffer(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Bcast( &
      buffer, &
      count, &
      abi2mpi_datatype(datatype), &
      root, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bcast

subroutine MPIABI_Bcast_init( &
   buffer, &
   count, &
   datatype, &
   root, &
   comm, &
   info, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buffer(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Bcast_init( &
      buffer, &
      count, &
      abi2mpi_datatype(datatype), &
      root, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bcast_init

subroutine MPIABI_Exscan( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Exscan( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Exscan

subroutine MPIABI_Exscan_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Exscan_init( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Exscan_init

subroutine MPIABI_Gather( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Gather( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Gather

subroutine MPIABI_Gather_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Gather_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Gather_init

subroutine MPIABI_Gatherv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Gatherv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Gatherv

subroutine MPIABI_Gatherv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Gatherv_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Gatherv_init

subroutine MPIABI_Iallgather( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iallgather( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iallgather

subroutine MPIABI_Iallgatherv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iallgatherv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iallgatherv

subroutine MPIABI_Iallreduce( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iallreduce( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iallreduce

subroutine MPIABI_Ialltoall( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ialltoall( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ialltoall

subroutine MPIABI_Ialltoallv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ialltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      rdispls, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ialltoallv

subroutine MPIABI_Ialltoallw( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtypes(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtypes(*)
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   integer, allocatable :: wrap_sendtypes(:)
   integer, allocatable :: wrap_recvtypes(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_sendtypes(comm_size))
   allocate(wrap_recvtypes(comm_size))
   do i = 1, comm_size
      wrap_sendtypes(i) = abi2mpi_datatype(sendtypes(i))
   end do
   do i = 1, comm_size
      wrap_recvtypes(i) = abi2mpi_datatype(recvtypes(i))
   end do
   call MPI_Ialltoallw( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      wrap_sendtypes, &
      recvbuf, &
      recvcounts, &
      rdispls, &
      wrap_recvtypes, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_sendtypes)
   deallocate(wrap_recvtypes)
end subroutine MPIABI_Ialltoallw

subroutine MPIABI_Ibarrier( &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ibarrier( &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ibarrier

subroutine MPIABI_Ibcast( &
   buffer, &
   count, &
   datatype, &
   root, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buffer(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ibcast( &
      buffer, &
      count, &
      abi2mpi_datatype(datatype), &
      root, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ibcast

subroutine MPIABI_Iexscan( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iexscan( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iexscan

subroutine MPIABI_Igather( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Igather( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Igather

subroutine MPIABI_Igatherv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Igatherv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Igatherv

subroutine MPIABI_Ireduce( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ireduce( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      root, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ireduce

subroutine MPIABI_Ireduce_scatter( &
   sendbuf, &
   recvbuf, &
   recvcounts, &
   datatype, &
   op, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ireduce_scatter( &
      sendbuf, &
      recvbuf, &
      recvcounts, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ireduce_scatter

subroutine MPIABI_Ireduce_scatter_block( &
   sendbuf, &
   recvbuf, &
   recvcount, &
   datatype, &
   op, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ireduce_scatter_block( &
      sendbuf, &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ireduce_scatter_block

subroutine MPIABI_Iscan( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   comm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iscan( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iscan

subroutine MPIABI_Iscatter( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iscatter( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iscatter

subroutine MPIABI_Iscatterv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Iscatterv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iscatterv

subroutine MPIABI_Op_commutative( &
   op, &
   commute, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: op
   logical, intent(out) :: commute
   integer, intent(out) :: ierror
   call MPI_Op_commutative( &
      abi2mpi_op(op), &
      commute, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Op_commutative

subroutine MPIABI_Op_create( &
   user_fn, &
   commute, &
   op, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: user_fn
   logical, intent(in) :: commute
   integer, intent(out) :: op
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Op_create is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_user_fn
   wrap_user_fn = abi2mpi_external(user_fn)
   call MPI_Op_create( &
      wrap_user_fn, &
      commute, &
      op, &
      ierror &
   )
   op = mpi2abi_op(op)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Op_create

subroutine MPIABI_Op_free( &
   op, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: op
   integer, intent(out) :: ierror
   call MPI_Op_free( &
      op, &
      ierror &
   )
   op = mpi2abi_op(op)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Op_free

subroutine MPIABI_Reduce( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   root, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Reduce( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      root, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce

subroutine MPIABI_Reduce_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Reduce_init( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      root, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce_init

subroutine MPIABI_Reduce_local( &
   inbuf, &
   inoutbuf, &
   count, &
   datatype, &
   op, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: inbuf(*)
   integer, intent(out) :: inoutbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(out) :: ierror
   call MPI_Reduce_local( &
      inbuf, &
      inoutbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce_local

subroutine MPIABI_Reduce_scatter( &
   sendbuf, &
   recvbuf, &
   recvcounts, &
   datatype, &
   op, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Reduce_scatter( &
      sendbuf, &
      recvbuf, &
      recvcounts, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce_scatter

subroutine MPIABI_Reduce_scatter_block( &
   sendbuf, &
   recvbuf, &
   recvcount, &
   datatype, &
   op, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Reduce_scatter_block( &
      sendbuf, &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce_scatter_block

subroutine MPIABI_Reduce_scatter_block_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Reduce_scatter_block_init( &
      sendbuf, &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce_scatter_block_init

subroutine MPIABI_Reduce_scatter_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Reduce_scatter_init( &
      sendbuf, &
      recvbuf, &
      recvcounts, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Reduce_scatter_init

subroutine MPIABI_Scan( &
   sendbuf, &
   recvbuf, &
   count, &
   datatype, &
   op, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Scan( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Scan

subroutine MPIABI_Scan_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(in) :: op
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Scan_init( &
      sendbuf, &
      recvbuf, &
      count, &
      abi2mpi_datatype(datatype), &
      abi2mpi_op(op), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Scan_init

subroutine MPIABI_Scatter( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Scatter( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Scatter

subroutine MPIABI_Scatter_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Scatter_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Scatter_init

subroutine MPIABI_Scatterv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Scatterv( &
      sendbuf, &
      sendcounts, &
      displs, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Scatterv

subroutine MPIABI_Scatterv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Scatterv_init( &
      sendbuf, &
      sendcounts, &
      displs, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      root, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Scatterv_init

subroutine MPIABI_Type_get_value_index( &
   value_type, &
   index_type, &
   pair_type, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: value_type
   integer, intent(in) :: index_type
   integer, intent(out) :: pair_type
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Type_get_value_index is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Type_get_value_index( &
      abi2mpi_datatype(value_type), &
      abi2mpi_datatype(index_type), &
      pair_type, &
      ierror &
   )
   pair_type = mpi2abi_datatype(pair_type)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Type_get_value_index

subroutine MPIABI_Comm_compare( &
   comm1, &
   comm2, &
   result, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm1
   integer, intent(in) :: comm2
   integer, intent(out) :: result
   integer, intent(out) :: ierror
   call MPI_Comm_compare( &
      abi2mpi_comm(comm1), &
      abi2mpi_comm(comm2), &
      result, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_compare

subroutine MPIABI_Comm_create( &
   comm, &
   group, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: group
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_create( &
      abi2mpi_comm(comm), &
      abi2mpi_group(group), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_create

subroutine MPIABI_Comm_create_from_group( &
   group, &
   stringtag, &
   info, &
   errhandler, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   character(*), intent(in) :: stringtag
   integer, intent(in) :: info
   integer, intent(in) :: errhandler
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_create_from_group( &
      abi2mpi_group(group), &
      stringtag, &
      abi2mpi_info(info), &
      abi2mpi_errhandler(errhandler), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_create_from_group

subroutine MPIABI_Comm_create_group( &
   comm, &
   group, &
   tag, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: group
   integer, intent(in) :: tag
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_create_group( &
      abi2mpi_comm(comm), &
      abi2mpi_group(group), &
      tag, &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_create_group

subroutine MPIABI_Comm_create_keyval( &
   comm_copy_attr_fn, &
   comm_delete_attr_fn, &
   comm_keyval, &
   extra_state, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: comm_copy_attr_fn
   external :: comm_delete_attr_fn
   integer, intent(out) :: comm_keyval
   integer, intent(out) :: extra_state(*)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Comm_create_keyval is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_comm_copy_attr_fn
   external :: wrap_comm_delete_attr_fn
   wrap_comm_copy_attr_fn = abi2mpi_external(comm_copy_attr_fn)
   wrap_comm_delete_attr_fn = abi2mpi_external(comm_delete_attr_fn)
   call MPI_Comm_create_keyval( &
      wrap_comm_copy_attr_fn, &
      wrap_comm_delete_attr_fn, &
      comm_keyval, &
      extra_state, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_create_keyval

subroutine MPIABI_Comm_delete_attr( &
   comm, &
   comm_keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: comm_keyval
   integer, intent(out) :: ierror
   call MPI_Comm_delete_attr( &
      abi2mpi_comm(comm), &
      comm_keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_delete_attr

subroutine MPIABI_Comm_dup( &
   comm, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_dup( &
      abi2mpi_comm(comm), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_dup

subroutine MPIABI_Comm_dup_with_info( &
   comm, &
   info, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_dup_with_info( &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_dup_with_info

subroutine MPIABI_Comm_free( &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: comm
   integer, intent(out) :: ierror
   call MPI_Comm_free( &
      comm, &
      ierror &
   )
   comm = mpi2abi_comm(comm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_free

subroutine MPIABI_Comm_get_name( &
   comm, &
   comm_name, &
   resultlen, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   character(*), intent(out) :: comm_name
   integer, intent(out) :: resultlen
   integer, intent(out) :: ierror
   call MPI_Comm_get_name( &
      abi2mpi_comm(comm), &
      comm_name, &
      resultlen, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_get_name

subroutine MPIABI_Comm_free_keyval( &
   comm_keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: comm_keyval
   integer, intent(out) :: ierror
   call MPI_Comm_free_keyval( &
      comm_keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_free_keyval

subroutine MPIABI_Comm_get_attr( &
   comm, &
   comm_keyval, &
   attribute_val, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: comm_keyval
   integer, intent(out) :: attribute_val(*)
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Comm_get_attr( &
      abi2mpi_comm(comm), &
      comm_keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_get_attr

subroutine MPIABI_Comm_get_info( &
   comm, &
   info_used, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: info_used
   integer, intent(out) :: ierror
   call MPI_Comm_get_info( &
      abi2mpi_comm(comm), &
      info_used, &
      ierror &
   )
   info_used = mpi2abi_info(info_used)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_get_info

subroutine MPIABI_Comm_group( &
   comm, &
   group, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: group
   integer, intent(out) :: ierror
   call MPI_Comm_group( &
      abi2mpi_comm(comm), &
      group, &
      ierror &
   )
   group = mpi2abi_group(group)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_group

subroutine MPIABI_Comm_idup( &
   comm, &
   newcomm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: newcomm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Comm_idup( &
      abi2mpi_comm(comm), &
      newcomm, &
      request, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_idup

subroutine MPIABI_Comm_idup_with_info( &
   comm, &
   info, &
   newcomm, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: newcomm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Comm_idup_with_info( &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      newcomm, &
      request, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_idup_with_info

subroutine MPIABI_Comm_rank( &
   comm, &
   rank, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: rank
   integer, intent(out) :: ierror
   call MPI_Comm_rank( &
      abi2mpi_comm(comm), &
      rank, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_rank

subroutine MPIABI_Comm_remote_group( &
   comm, &
   group, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: group
   integer, intent(out) :: ierror
   call MPI_Comm_remote_group( &
      abi2mpi_comm(comm), &
      group, &
      ierror &
   )
   group = mpi2abi_group(group)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_remote_group

subroutine MPIABI_Comm_remote_size( &
   comm, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: size
   integer, intent(out) :: ierror
   call MPI_Comm_remote_size( &
      abi2mpi_comm(comm), &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_remote_size

subroutine MPIABI_Comm_set_attr( &
   comm, &
   comm_keyval, &
   attribute_val, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: comm_keyval
   integer, intent(out) :: attribute_val(*)
   integer, intent(out) :: ierror
   call MPI_Comm_set_attr( &
      abi2mpi_comm(comm), &
      comm_keyval, &
      attribute_val, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_set_attr

subroutine MPIABI_Comm_set_info( &
   comm, &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: ierror
   call MPI_Comm_set_info( &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_set_info

subroutine MPIABI_Comm_set_name( &
   comm, &
   comm_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   character(*), intent(in) :: comm_name
   integer, intent(out) :: ierror
   call MPI_Comm_set_name( &
      abi2mpi_comm(comm), &
      comm_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_set_name

subroutine MPIABI_Comm_size( &
   comm, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: size
   integer, intent(out) :: ierror
   call MPI_Comm_size( &
      abi2mpi_comm(comm), &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_size

subroutine MPIABI_Comm_split( &
   comm, &
   color, &
   key, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: color
   integer, intent(in) :: key
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_split( &
      abi2mpi_comm(comm), &
      color, &
      key, &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_split

subroutine MPIABI_Group_free( &
   group, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: group
   integer, intent(out) :: ierror
   call MPI_Group_free( &
      group, &
      ierror &
   )
   group = mpi2abi_group(group)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_free

subroutine MPIABI_Comm_split_type( &
   comm, &
   split_type, &
   key, &
   info, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: split_type
   integer, intent(in) :: key
   integer, intent(in) :: info
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_split_type( &
      abi2mpi_comm(comm), &
      split_type, &
      key, &
      abi2mpi_info(info), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_split_type

subroutine MPIABI_Comm_test_inter( &
   comm, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Comm_test_inter( &
      abi2mpi_comm(comm), &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_test_inter

subroutine MPIABI_Group_compare( &
   group1, &
   group2, &
   result, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group1
   integer, intent(in) :: group2
   integer, intent(out) :: result
   integer, intent(out) :: ierror
   call MPI_Group_compare( &
      abi2mpi_group(group1), &
      abi2mpi_group(group2), &
      result, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_compare

subroutine MPIABI_Group_difference( &
   group1, &
   group2, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group1
   integer, intent(in) :: group2
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_difference( &
      abi2mpi_group(group1), &
      abi2mpi_group(group2), &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_difference

subroutine MPIABI_Group_excl( &
   group, &
   n, &
   ranks, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(in) :: n
   integer, intent(in) :: ranks(n)
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_excl( &
      abi2mpi_group(group), &
      n, &
      ranks, &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_excl

subroutine MPIABI_Group_from_session_pset( &
   session, &
   pset_name, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   character(*), intent(in) :: pset_name
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_from_session_pset( &
      abi2mpi_session(session), &
      pset_name, &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_from_session_pset

subroutine MPIABI_Group_incl( &
   group, &
   n, &
   ranks, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(in) :: n
   integer, intent(in) :: ranks(n)
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_incl( &
      abi2mpi_group(group), &
      n, &
      ranks, &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_incl

subroutine MPIABI_Group_intersection( &
   group1, &
   group2, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group1
   integer, intent(in) :: group2
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_intersection( &
      abi2mpi_group(group1), &
      abi2mpi_group(group2), &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_intersection

subroutine MPIABI_Group_range_excl( &
   group, &
   n, &
   ranges, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(in) :: n
   integer, intent(in) :: ranges(n)
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_range_excl( &
      abi2mpi_group(group), &
      n, &
      ranges, &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_range_excl

subroutine MPIABI_Group_range_incl( &
   group, &
   n, &
   ranges, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(in) :: n
   integer, intent(in) :: ranges(n)
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_range_incl( &
      abi2mpi_group(group), &
      n, &
      ranges, &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_range_incl

subroutine MPIABI_Group_rank( &
   group, &
   rank, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(out) :: rank
   integer, intent(out) :: ierror
   call MPI_Group_rank( &
      abi2mpi_group(group), &
      rank, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_rank

subroutine MPIABI_Group_size( &
   group, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(out) :: size
   integer, intent(out) :: ierror
   call MPI_Group_size( &
      abi2mpi_group(group), &
      size, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_size

subroutine MPIABI_Group_translate_ranks( &
   group1, &
   n, &
   ranks1, &
   group2, &
   ranks2, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group1
   integer, intent(in) :: n
   integer, intent(in) :: ranks1(n)
   integer, intent(in) :: group2
   integer, intent(in) :: ranks2(n)
   integer, intent(out) :: ierror
   call MPI_Group_translate_ranks( &
      abi2mpi_group(group1), &
      n, &
      ranks1, &
      abi2mpi_group(group2), &
      ranks2, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_translate_ranks

subroutine MPIABI_Group_union( &
   group1, &
   group2, &
   newgroup, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group1
   integer, intent(in) :: group2
   integer, intent(out) :: newgroup
   integer, intent(out) :: ierror
   call MPI_Group_union( &
      abi2mpi_group(group1), &
      abi2mpi_group(group2), &
      newgroup, &
      ierror &
   )
   newgroup = mpi2abi_group(newgroup)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Group_union

subroutine MPIABI_Intercomm_create( &
   local_comm, &
   local_leader, &
   peer_comm, &
   remote_leader, &
   tag, &
   newintercomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: local_comm
   integer, intent(in) :: local_leader
   integer, intent(in) :: peer_comm
   integer, intent(in) :: remote_leader
   integer, intent(in) :: tag
   integer, intent(out) :: newintercomm
   integer, intent(out) :: ierror
   call MPI_Intercomm_create( &
      abi2mpi_comm(local_comm), &
      local_leader, &
      abi2mpi_comm(peer_comm), &
      remote_leader, &
      tag, &
      newintercomm, &
      ierror &
   )
   newintercomm = mpi2abi_comm(newintercomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Intercomm_create

subroutine MPIABI_Intercomm_create_from_groups( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: local_group
   integer, intent(in) :: local_leader
   integer, intent(in) :: remote_group
   integer, intent(in) :: remote_leader
   character(*), intent(in) :: stringtag
   integer, intent(in) :: info
   integer, intent(in) :: errhandler
   integer, intent(out) :: newintercomm
   integer, intent(out) :: ierror
   call MPI_Intercomm_create_from_groups( &
      abi2mpi_group(local_group), &
      local_leader, &
      abi2mpi_group(remote_group), &
      remote_leader, &
      stringtag, &
      abi2mpi_info(info), &
      abi2mpi_errhandler(errhandler), &
      newintercomm, &
      ierror &
   )
   newintercomm = mpi2abi_comm(newintercomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Intercomm_create_from_groups

subroutine MPIABI_Intercomm_merge( &
   intercomm, &
   high, &
   newintracomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: intercomm
   integer, intent(in) :: high
   integer, intent(out) :: newintracomm
   integer, intent(out) :: ierror
   call MPI_Intercomm_merge( &
      abi2mpi_comm(intercomm), &
      high, &
      newintracomm, &
      ierror &
   )
   newintracomm = mpi2abi_comm(newintracomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Intercomm_merge

subroutine MPIABI_Type_create_keyval( &
   type_copy_attr_fn, &
   type_delete_attr_fn, &
   type_keyval, &
   extra_state, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: type_copy_attr_fn
   external :: type_delete_attr_fn
   integer, intent(out) :: type_keyval
   integer, intent(out) :: extra_state(*)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Type_create_keyval is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_type_copy_attr_fn
   external :: wrap_type_delete_attr_fn
   wrap_type_copy_attr_fn = abi2mpi_external(type_copy_attr_fn)
   wrap_type_delete_attr_fn = abi2mpi_external(type_delete_attr_fn)
   call MPI_Type_create_keyval( &
      wrap_type_copy_attr_fn, &
      wrap_type_delete_attr_fn, &
      type_keyval, &
      extra_state, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Type_create_keyval

subroutine MPIABI_Type_delete_attr( &
   datatype, &
   type_keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer, intent(in) :: type_keyval
   integer, intent(out) :: ierror
   call MPI_Type_delete_attr( &
      abi2mpi_datatype(datatype), &
      type_keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_delete_attr

subroutine MPIABI_Type_free_keyval( &
   type_keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: type_keyval
   integer, intent(out) :: ierror
   call MPI_Type_free_keyval( &
      type_keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_free_keyval

subroutine MPIABI_Type_get_attr( &
   datatype, &
   type_keyval, &
   attribute_val, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer, intent(in) :: type_keyval
   integer, intent(out) :: attribute_val(*)
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Type_get_attr( &
      abi2mpi_datatype(datatype), &
      type_keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_attr

subroutine MPIABI_Type_get_name( &
   datatype, &
   type_name, &
   resultlen, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   character(*), intent(out) :: type_name
   integer, intent(out) :: resultlen
   integer, intent(out) :: ierror
   call MPI_Type_get_name( &
      abi2mpi_datatype(datatype), &
      type_name, &
      resultlen, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_name

subroutine MPIABI_Type_set_attr( &
   datatype, &
   type_keyval, &
   attribute_val, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer, intent(in) :: type_keyval
   integer, intent(out) :: attribute_val(*)
   integer, intent(out) :: ierror
   call MPI_Type_set_attr( &
      abi2mpi_datatype(datatype), &
      type_keyval, &
      attribute_val, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_set_attr

subroutine MPIABI_Type_set_name( &
   datatype, &
   type_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   character(*), intent(in) :: type_name
   integer, intent(out) :: ierror
   call MPI_Type_set_name( &
      abi2mpi_datatype(datatype), &
      type_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_set_name

subroutine MPIABI_Win_create_keyval( &
   win_copy_attr_fn, &
   win_delete_attr_fn, &
   win_keyval, &
   extra_state, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: win_copy_attr_fn
   external :: win_delete_attr_fn
   integer, intent(out) :: win_keyval
   integer, intent(out) :: extra_state(*)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Win_create_keyval is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_win_copy_attr_fn
   external :: wrap_win_delete_attr_fn
   wrap_win_copy_attr_fn = abi2mpi_external(win_copy_attr_fn)
   wrap_win_delete_attr_fn = abi2mpi_external(win_delete_attr_fn)
   call MPI_Win_create_keyval( &
      wrap_win_copy_attr_fn, &
      wrap_win_delete_attr_fn, &
      win_keyval, &
      extra_state, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Win_create_keyval

subroutine MPIABI_Win_delete_attr( &
   win, &
   win_keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: win_keyval
   integer, intent(out) :: ierror
   call MPI_Win_delete_attr( &
      abi2mpi_win(win), &
      win_keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_delete_attr

subroutine MPIABI_Win_free_keyval( &
   win_keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: win_keyval
   integer, intent(out) :: ierror
   call MPI_Win_free_keyval( &
      win_keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_free_keyval

subroutine MPIABI_Win_get_attr( &
   win, &
   win_keyval, &
   attribute_val, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: win_keyval
   integer, intent(out) :: attribute_val(*)
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Win_get_attr( &
      abi2mpi_win(win), &
      win_keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_get_attr

subroutine MPIABI_Win_get_name( &
   win, &
   win_name, &
   resultlen, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   character(*), intent(out) :: win_name
   integer, intent(out) :: resultlen
   integer, intent(out) :: ierror
   call MPI_Win_get_name( &
      abi2mpi_win(win), &
      win_name, &
      resultlen, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_get_name

subroutine MPIABI_Win_set_attr( &
   win, &
   win_keyval, &
   attribute_val, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: win_keyval
   integer, intent(out) :: attribute_val(*)
   integer, intent(out) :: ierror
   call MPI_Win_set_attr( &
      abi2mpi_win(win), &
      win_keyval, &
      attribute_val, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_set_attr

subroutine MPIABI_Win_set_name( &
   win, &
   win_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   character(*), intent(in) :: win_name
   integer, intent(out) :: ierror
   call MPI_Win_set_name( &
      abi2mpi_win(win), &
      win_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_set_name

subroutine MPIABI_Cart_coords( &
   comm, &
   rank, &
   maxdims, &
   coords, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: rank
   integer, intent(in) :: maxdims
   integer, intent(out) :: coords(maxdims)
   integer, intent(out) :: ierror
   call MPI_Cart_coords( &
      abi2mpi_comm(comm), &
      rank, &
      maxdims, &
      coords, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_coords

subroutine MPIABI_Cart_create( &
   comm_old, &
   ndims, &
   dims, &
   periods, &
   reorder, &
   comm_cart, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm_old
   integer, intent(in) :: ndims
   integer, intent(in) :: dims(ndims)
   logical, intent(in) :: periods(ndims)
   logical, intent(in) :: reorder
   integer, intent(out) :: comm_cart
   integer, intent(out) :: ierror
   call MPI_Cart_create( &
      abi2mpi_comm(comm_old), &
      ndims, &
      dims, &
      periods, &
      reorder, &
      comm_cart, &
      ierror &
   )
   comm_cart = mpi2abi_comm(comm_cart)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_create

subroutine MPIABI_Cart_get( &
   comm, &
   maxdims, &
   dims, &
   periods, &
   coords, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: maxdims
   integer, intent(out) :: dims(maxdims)
   integer, intent(out) :: periods(maxdims)
   integer, intent(out) :: coords(maxdims)
   integer, intent(out) :: ierror
   call MPI_Cart_get( &
      abi2mpi_comm(comm), &
      maxdims, &
      dims, &
      periods, &
      coords, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_get

subroutine MPIABI_Cart_map( &
   comm, &
   ndims, &
   dims, &
   periods, &
   newrank, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: ndims
   integer, intent(in) :: dims(ndims)
   integer, intent(in) :: periods(ndims)
   integer, intent(out) :: newrank
   integer, intent(out) :: ierror
   call MPI_Cart_map( &
      abi2mpi_comm(comm), &
      ndims, &
      dims, &
      periods, &
      newrank, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_map

subroutine MPIABI_Cart_rank( &
   comm, &
   coords, &
   rank, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: coords(*)
   integer, intent(out) :: rank
   integer, intent(out) :: ierror
   call MPI_Cart_rank( &
      abi2mpi_comm(comm), &
      coords, &
      rank, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_rank

subroutine MPIABI_Cart_shift( &
   comm, &
   direction, &
   disp, &
   rank_source, &
   rank_dest, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: direction
   integer, intent(in) :: disp
   integer, intent(out) :: rank_source
   integer, intent(out) :: rank_dest
   integer, intent(out) :: ierror
   call MPI_Cart_shift( &
      abi2mpi_comm(comm), &
      direction, &
      disp, &
      rank_source, &
      rank_dest, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_shift

subroutine MPIABI_Cart_sub( &
   comm, &
   remain_dims, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   logical, intent(in) :: remain_dims(*)
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Cart_sub( &
      abi2mpi_comm(comm), &
      remain_dims, &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cart_sub

subroutine MPIABI_Cartdim_get( &
   comm, &
   ndims, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: ndims
   integer, intent(out) :: ierror
   call MPI_Cartdim_get( &
      abi2mpi_comm(comm), &
      ndims, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cartdim_get

subroutine MPIABI_Dims_create( &
   nnodes, &
   ndims, &
   dims, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: nnodes
   integer, intent(in) :: ndims
   integer, intent(in) :: dims(ndims)
   integer, intent(out) :: ierror
   call MPI_Dims_create( &
      nnodes, &
      ndims, &
      dims, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Dims_create

subroutine MPIABI_Dist_graph_create( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm_old
   integer, intent(in) :: n
   integer, intent(in) :: sources(n)
   integer, intent(in) :: degrees(n)
   integer, intent(in) :: destinations(*)
   integer, intent(in) :: weights(*)
   integer, intent(in) :: info
   logical, intent(in) :: reorder
   integer, intent(out) :: comm_dist_graph
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_weights
   integer :: wrap_weights(*)
   pointer(ptr_weights, wrap_weights)
   ptr_weights = abi2mpi_weight_ptr(loc(weights))
   call MPI_Dist_graph_create( &
      abi2mpi_comm(comm_old), &
      n, &
      sources, &
      degrees, &
      destinations, &
      wrap_weights, &
      abi2mpi_info(info), &
      reorder, &
      comm_dist_graph, &
      ierror &
   )
   comm_dist_graph = mpi2abi_comm(comm_dist_graph)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Dist_graph_create

subroutine MPIABI_Dist_graph_create_adjacent( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm_old
   integer, intent(in) :: indegree
   integer, intent(in) :: sources(indegree)
   integer, intent(in) :: sourceweights(*)
   integer, intent(in) :: outdegree
   integer, intent(in) :: destinations(outdegree)
   integer, intent(in) :: destweights(*)
   integer, intent(in) :: info
   integer, intent(in) :: reorder
   integer, intent(out) :: comm_dist_graph
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_sourceweights
   integer :: wrap_sourceweights(*)
   pointer(ptr_sourceweights, wrap_sourceweights)
   integer(MPI_ADDRESS_KIND) :: ptr_destweights
   integer :: wrap_destweights(*)
   pointer(ptr_destweights, wrap_destweights)
   ptr_sourceweights = abi2mpi_weight_ptr(loc(sourceweights))
   ptr_destweights = abi2mpi_weight_ptr(loc(destweights))
   call MPI_Dist_graph_create_adjacent( &
      abi2mpi_comm(comm_old), &
      indegree, &
      sources, &
      wrap_sourceweights, &
      outdegree, &
      destinations, &
      wrap_destweights, &
      abi2mpi_info(info), &
      reorder, &
      comm_dist_graph, &
      ierror &
   )
   comm_dist_graph = mpi2abi_comm(comm_dist_graph)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Dist_graph_create_adjacent

subroutine MPIABI_Dist_graph_neighbors( &
   comm, &
   maxindegree, &
   sources, &
   sourceweights, &
   maxoutdegree, &
   destinations, &
   destweights, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: maxindegree
   integer, intent(out) :: sources(maxindegree)
   integer, intent(out) :: sourceweights(*)
   integer, intent(in) :: maxoutdegree
   integer, intent(out) :: destinations(maxoutdegree)
   integer, intent(out) :: destweights(*)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_sourceweights
   integer :: wrap_sourceweights(*)
   pointer(ptr_sourceweights, wrap_sourceweights)
   integer(MPI_ADDRESS_KIND) :: ptr_destweights
   integer :: wrap_destweights(*)
   pointer(ptr_destweights, wrap_destweights)
   call MPI_Dist_graph_neighbors( &
      abi2mpi_comm(comm), &
      maxindegree, &
      sources, &
      wrap_sourceweights, &
      maxoutdegree, &
      destinations, &
      wrap_destweights, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Dist_graph_neighbors

subroutine MPIABI_Dist_graph_neighbors_count( &
   comm, &
   indegree, &
   outdegree, &
   weighted, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: indegree
   integer, intent(out) :: outdegree
   integer, intent(out) :: weighted
   integer, intent(out) :: ierror
   call MPI_Dist_graph_neighbors_count( &
      abi2mpi_comm(comm), &
      indegree, &
      outdegree, &
      weighted, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Dist_graph_neighbors_count

subroutine MPIABI_Graph_create( &
   comm_old, &
   nnodes, &
   index, &
   edges, &
   reorder, &
   comm_graph, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm_old
   integer, intent(in) :: nnodes
   integer, intent(in) :: index(nnodes)
   integer, intent(in) :: edges(nnodes)
   integer, intent(in) :: reorder
   integer, intent(out) :: comm_graph
   integer, intent(out) :: ierror
   call MPI_Graph_create( &
      abi2mpi_comm(comm_old), &
      nnodes, &
      index, &
      edges, &
      reorder, &
      comm_graph, &
      ierror &
   )
   comm_graph = mpi2abi_comm(comm_graph)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Graph_create

subroutine MPIABI_Graph_get( &
   comm, &
   maxindex, &
   maxedges, &
   index, &
   edges, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: maxindex
   integer, intent(in) :: maxedges
   integer, intent(out) :: index(maxindex)
   integer, intent(out) :: edges(maxedges)
   integer, intent(out) :: ierror
   call MPI_Graph_get( &
      abi2mpi_comm(comm), &
      maxindex, &
      maxedges, &
      index, &
      edges, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Graph_get

subroutine MPIABI_Graph_map( &
   comm, &
   nnodes, &
   index, &
   edges, &
   newrank, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: nnodes
   integer, intent(in) :: index(nnodes)
   integer, intent(in) :: edges(nnodes)
   integer, intent(out) :: newrank
   integer, intent(out) :: ierror
   call MPI_Graph_map( &
      abi2mpi_comm(comm), &
      nnodes, &
      index, &
      edges, &
      newrank, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Graph_map

subroutine MPIABI_Graph_neighbors( &
   comm, &
   rank, &
   maxneighbors, &
   neighbors, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: rank
   integer, intent(in) :: maxneighbors
   integer, intent(out) :: neighbors(maxneighbors)
   integer, intent(out) :: ierror
   call MPI_Graph_neighbors( &
      abi2mpi_comm(comm), &
      rank, &
      maxneighbors, &
      neighbors, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Graph_neighbors

subroutine MPIABI_Graph_neighbors_count( &
   comm, &
   rank, &
   nneighbors, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: rank
   integer, intent(out) :: nneighbors
   integer, intent(out) :: ierror
   call MPI_Graph_neighbors_count( &
      abi2mpi_comm(comm), &
      rank, &
      nneighbors, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Graph_neighbors_count

subroutine MPIABI_Graphdims_get( &
   comm, &
   nnodes, &
   nedges, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: nnodes
   integer, intent(out) :: nedges
   integer, intent(out) :: ierror
   call MPI_Graphdims_get( &
      abi2mpi_comm(comm), &
      nnodes, &
      nedges, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Graphdims_get

subroutine MPIABI_Ineighbor_allgather( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ineighbor_allgather( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ineighbor_allgather

subroutine MPIABI_Ineighbor_allgatherv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ineighbor_allgatherv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      displs, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ineighbor_allgatherv

subroutine MPIABI_Ineighbor_alltoall( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ineighbor_alltoall( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ineighbor_alltoall

subroutine MPIABI_Ineighbor_alltoallv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Ineighbor_alltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      rdispls, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ineighbor_alltoallv

subroutine MPIABI_Ineighbor_alltoallw( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: sdispls(*)
   integer, intent(in) :: sendtypes(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: rdispls(*)
   integer, intent(in) :: recvtypes(*)
   integer, intent(in) :: comm
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_sdispls(:)
   integer, allocatable :: wrap_sendtypes(:)
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_rdispls(:)
   integer, allocatable :: wrap_recvtypes(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_sdispls(comm_size))
   allocate(wrap_sendtypes(comm_size))
   allocate(wrap_rdispls(comm_size))
   allocate(wrap_recvtypes(comm_size))
   do i = 1, comm_size
      wrap_sdispls(i) = abi2mpi_address(sdispls(i))
   end do
   do i = 1, comm_size
      wrap_sendtypes(i) = abi2mpi_datatype(sendtypes(i))
   end do
   do i = 1, comm_size
      wrap_rdispls(i) = abi2mpi_address(rdispls(i))
   end do
   do i = 1, comm_size
      wrap_recvtypes(i) = abi2mpi_datatype(recvtypes(i))
   end do
   call MPI_Ineighbor_alltoallw( &
      sendbuf, &
      sendcounts, &
      wrap_sdispls, &
      wrap_sendtypes, &
      recvbuf, &
      recvcounts, &
      wrap_rdispls, &
      wrap_recvtypes, &
      abi2mpi_comm(comm), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_sdispls)
   deallocate(wrap_sendtypes)
   deallocate(wrap_rdispls)
   deallocate(wrap_recvtypes)
end subroutine MPIABI_Ineighbor_alltoallw

subroutine MPIABI_Neighbor_allgather( &
   sendbuf, &
   sendcount, &
   sendtype, &
   recvbuf, &
   recvcount, &
   recvtype, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Neighbor_allgather( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Neighbor_allgather

subroutine MPIABI_Neighbor_allgather_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Neighbor_allgather_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Neighbor_allgather_init

subroutine MPIABI_Neighbor_allgatherv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_displs(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_displs(comm_size))
   do i = 1, comm_size
      wrap_displs(i) = abi2mpi_address(displs(i))
   end do
   call MPI_Neighbor_allgatherv( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      wrap_displs, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_displs)
end subroutine MPIABI_Neighbor_allgatherv

subroutine MPIABI_Neighbor_allgatherv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: displs(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_displs(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_displs(comm_size))
   do i = 1, comm_size
      wrap_displs(i) = abi2mpi_address(displs(i))
   end do
   call MPI_Neighbor_allgatherv_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      wrap_displs, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_displs)
end subroutine MPIABI_Neighbor_allgatherv_init

subroutine MPIABI_Neighbor_alltoall( &
   sendbuf, &
   sendcount, &
   sendtype, &
   recvbuf, &
   recvcount, &
   recvtype, &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Neighbor_alltoall( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Neighbor_alltoall

subroutine MPIABI_Neighbor_alltoall_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcount
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcount
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Neighbor_alltoall_init( &
      sendbuf, &
      sendcount, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcount, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Neighbor_alltoall_init

subroutine MPIABI_Neighbor_alltoallv( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   call MPI_Neighbor_alltoallv( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      rdispls, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Neighbor_alltoallv

subroutine MPIABI_Neighbor_alltoallv_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer, intent(in) :: sdispls(*)
   integer, intent(in) :: sendtype
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer, intent(in) :: rdispls(*)
   integer, intent(in) :: recvtype
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Neighbor_alltoallv_init( &
      sendbuf, &
      sendcounts, &
      sdispls, &
      abi2mpi_datatype(sendtype), &
      recvbuf, &
      recvcounts, &
      rdispls, &
      abi2mpi_datatype(recvtype), &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Neighbor_alltoallv_init

subroutine MPIABI_Neighbor_alltoallw( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: sdispls(*)
   integer, intent(in) :: sendtypes(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: rdispls(*)
   integer, intent(in) :: recvtypes(*)
   integer, intent(in) :: comm
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_sdispls(:)
   integer, allocatable :: wrap_sendtypes(:)
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_rdispls(:)
   integer, allocatable :: wrap_recvtypes(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_sdispls(comm_size))
   allocate(wrap_sendtypes(comm_size))
   allocate(wrap_rdispls(comm_size))
   allocate(wrap_recvtypes(comm_size))
   do i = 1, comm_size
      wrap_sdispls(i) = abi2mpi_address(sdispls(i))
   end do
   do i = 1, comm_size
      wrap_sendtypes(i) = abi2mpi_datatype(sendtypes(i))
   end do
   do i = 1, comm_size
      wrap_rdispls(i) = abi2mpi_address(rdispls(i))
   end do
   do i = 1, comm_size
      wrap_recvtypes(i) = abi2mpi_datatype(recvtypes(i))
   end do
   call MPI_Neighbor_alltoallw( &
      sendbuf, &
      sendcounts, &
      wrap_sdispls, &
      wrap_sendtypes, &
      recvbuf, &
      recvcounts, &
      wrap_rdispls, &
      wrap_recvtypes, &
      abi2mpi_comm(comm), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_sdispls)
   deallocate(wrap_sendtypes)
   deallocate(wrap_rdispls)
   deallocate(wrap_recvtypes)
end subroutine MPIABI_Neighbor_alltoallw

subroutine MPIABI_Neighbor_alltoallw_init( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: sendbuf(*)
   integer, intent(in) :: sendcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: sdispls(*)
   integer, intent(in) :: sendtypes(*)
   integer, intent(out) :: recvbuf(*)
   integer, intent(in) :: recvcounts(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: rdispls(*)
   integer, intent(in) :: recvtypes(*)
   integer, intent(in) :: comm
   integer, intent(in) :: info
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_sdispls(:)
   integer, allocatable :: wrap_sendtypes(:)
   integer(MPI_ADDRESS_KIND), allocatable :: wrap_rdispls(:)
   integer, allocatable :: wrap_recvtypes(:)
   integer :: comm_size
   integer :: i
   call MPI_Comm_size(abi2mpi_comm(comm), comm_size, ierror)
   if (ierror /= MPI_SUCCESS) then
      ierror = mpi2abi_errorcode(ierror)
      return
   end if
   allocate(wrap_sdispls(comm_size))
   allocate(wrap_sendtypes(comm_size))
   allocate(wrap_rdispls(comm_size))
   allocate(wrap_recvtypes(comm_size))
   do i = 1, comm_size
      wrap_sdispls(i) = abi2mpi_address(sdispls(i))
   end do
   do i = 1, comm_size
      wrap_sendtypes(i) = abi2mpi_datatype(sendtypes(i))
   end do
   do i = 1, comm_size
      wrap_rdispls(i) = abi2mpi_address(rdispls(i))
   end do
   do i = 1, comm_size
      wrap_recvtypes(i) = abi2mpi_datatype(recvtypes(i))
   end do
   call MPI_Neighbor_alltoallw_init( &
      sendbuf, &
      sendcounts, &
      wrap_sdispls, &
      wrap_sendtypes, &
      recvbuf, &
      recvcounts, &
      wrap_rdispls, &
      wrap_recvtypes, &
      abi2mpi_comm(comm), &
      abi2mpi_info(info), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
   deallocate(wrap_sdispls)
   deallocate(wrap_sendtypes)
   deallocate(wrap_rdispls)
   deallocate(wrap_recvtypes)
end subroutine MPIABI_Neighbor_alltoallw_init

subroutine MPIABI_Topo_test( &
   comm, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: status
   integer, intent(out) :: ierror
   call MPI_Topo_test( &
      abi2mpi_comm(comm), &
      status, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Topo_test

subroutine MPIABI_Add_error_class( &
   errorclass, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: errorclass
   integer, intent(out) :: ierror
   call MPI_Add_error_class( &
      errorclass, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Add_error_class

subroutine MPIABI_Add_error_code( &
   errorclass, &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorclass
   integer, intent(out) :: errorcode
   integer, intent(out) :: ierror
   call MPI_Add_error_code( &
      errorclass, &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Add_error_code

subroutine MPIABI_Add_error_string( &
   errorcode, &
   string, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorcode
   character(*), intent(in) :: string
   integer, intent(out) :: ierror
   call MPI_Add_error_string( &
      errorcode, &
      string, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Add_error_string

subroutine MPIABI_Alloc_mem( &
   size, &
   info, &
   baseptr, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer(MPIABI_ADDRESS_KIND), intent(in) :: size
   integer, intent(in) :: info
   integer, intent(out) :: baseptr(*)
   integer, intent(out) :: ierror
   call MPI_Alloc_mem( &
      abi2mpi_address(size), &
      abi2mpi_info(info), &
      baseptr, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Alloc_mem

subroutine MPIABI_Comm_call_errhandler( &
   comm, &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
   call MPI_Comm_call_errhandler( &
      abi2mpi_comm(comm), &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_call_errhandler

subroutine MPIABI_Comm_create_errhandler( &
   comm_errhandler_fn, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: comm_errhandler_fn
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Comm_create_errhandler is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_comm_errhandler_fn
   wrap_comm_errhandler_fn = abi2mpi_external(comm_errhandler_fn)
   call MPI_Comm_create_errhandler( &
      wrap_comm_errhandler_fn, &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_create_errhandler

subroutine MPIABI_Comm_get_errhandler( &
   comm, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Comm_get_errhandler( &
      abi2mpi_comm(comm), &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_get_errhandler

subroutine MPIABI_Comm_set_errhandler( &
   comm, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Comm_set_errhandler( &
      abi2mpi_comm(comm), &
      abi2mpi_errhandler(errhandler), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_set_errhandler

subroutine MPIABI_Errhandler_free( &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Errhandler_free( &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Errhandler_free

subroutine MPIABI_Error_class( &
   errorcode, &
   errorclass, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorcode
   integer, intent(out) :: errorclass
   integer, intent(out) :: ierror
   call MPI_Error_class( &
      errorcode, &
      errorclass, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Error_class

subroutine MPIABI_Error_string( &
   errorcode, &
   string, &
   resultlen, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorcode
   character(*), intent(out) :: string
   integer, intent(out) :: resultlen
   integer, intent(out) :: ierror
   call MPI_Error_string( &
      errorcode, &
      string, &
      resultlen, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Error_string

subroutine MPIABI_File_call_errhandler( &
   fh, &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
   call MPI_File_call_errhandler( &
      abi2mpi_file(fh), &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_call_errhandler

subroutine MPIABI_File_create_errhandler( &
   file_errhandler_fn, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: file_errhandler_fn
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_File_create_errhandler is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_file_errhandler_fn
   wrap_file_errhandler_fn = abi2mpi_external(file_errhandler_fn)
   call MPI_File_create_errhandler( &
      wrap_file_errhandler_fn, &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_File_create_errhandler

subroutine MPIABI_File_get_errhandler( &
   file, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: file
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
   call MPI_File_get_errhandler( &
      abi2mpi_file(file), &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_errhandler

subroutine MPIABI_File_set_errhandler( &
   file, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: file
   integer, intent(in) :: errhandler
   integer, intent(out) :: ierror
   call MPI_File_set_errhandler( &
      abi2mpi_file(file), &
      abi2mpi_errhandler(errhandler), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_set_errhandler

subroutine MPIABI_Free_mem( &
   base, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: base(*)
   integer, intent(out) :: ierror
   call MPI_Free_mem( &
      base, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Free_mem

subroutine MPIABI_Get_hw_resource_info( &
   hw_info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: hw_info
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Get_hw_resource_info is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Get_hw_resource_info( &
      hw_info, &
      ierror &
   )
   hw_info = mpi2abi_info(hw_info)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Get_hw_resource_info

subroutine MPIABI_Get_library_version( &
   version, &
   resultlen, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(out) :: version
   integer, intent(out) :: resultlen
   integer, intent(out) :: ierror
   call MPI_Get_library_version( &
      version, &
      resultlen, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_library_version

subroutine MPIABI_Get_processor_name( &
   name, &
   resultlen, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(out) :: name
   integer, intent(out) :: resultlen
   integer, intent(out) :: ierror
   call MPI_Get_processor_name( &
      name, &
      resultlen, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_processor_name

subroutine MPIABI_Get_version( &
   version, &
   subversion, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: version
   integer, intent(out) :: subversion
   integer, intent(out) :: ierror
   call MPI_Get_version( &
      version, &
      subversion, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_version

subroutine MPIABI_Remove_error_class( &
   errorclass, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorclass
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Remove_error_class is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Remove_error_class( &
      errorclass, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Remove_error_class

subroutine MPIABI_Remove_error_code( &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Remove_error_code is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Remove_error_code( &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Remove_error_code

subroutine MPIABI_Remove_error_string( &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Remove_error_string is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   call MPI_Remove_error_string( &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Remove_error_string

subroutine MPIABI_Session_call_errhandler( &
   session, &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
   call MPI_Session_call_errhandler( &
      abi2mpi_session(session), &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_call_errhandler

subroutine MPIABI_Session_create_errhandler( &
   session_errhandler_fn, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: session_errhandler_fn
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Session_create_errhandler is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_session_errhandler_fn
   wrap_session_errhandler_fn = abi2mpi_external(session_errhandler_fn)
   call MPI_Session_create_errhandler( &
      wrap_session_errhandler_fn, &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Session_create_errhandler

subroutine MPIABI_Session_get_errhandler( &
   session, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Session_get_errhandler( &
      abi2mpi_session(session), &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_get_errhandler

subroutine MPIABI_Session_set_errhandler( &
   session, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(in) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Session_set_errhandler( &
      abi2mpi_session(session), &
      abi2mpi_errhandler(errhandler), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_set_errhandler

subroutine MPIABI_Win_call_errhandler( &
   win, &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
   call MPI_Win_call_errhandler( &
      abi2mpi_win(win), &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_call_errhandler

subroutine MPIABI_Win_create_errhandler( &
   win_errhandler_fn, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: win_errhandler_fn
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Win_create_errhandler is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_win_errhandler_fn
   wrap_win_errhandler_fn = abi2mpi_external(win_errhandler_fn)
   call MPI_Win_create_errhandler( &
      wrap_win_errhandler_fn, &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Win_create_errhandler

subroutine MPIABI_Win_get_errhandler( &
   win, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Win_get_errhandler( &
      abi2mpi_win(win), &
      errhandler, &
      ierror &
   )
   errhandler = mpi2abi_errhandler(errhandler)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_get_errhandler

subroutine MPIABI_Win_set_errhandler( &
   win, &
   errhandler, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: errhandler
   integer, intent(out) :: ierror
   call MPI_Win_set_errhandler( &
      abi2mpi_win(win), &
      abi2mpi_errhandler(errhandler), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_set_errhandler

function MPIABI_Wtick( &
) result(result)
   use mpiwrapper
   implicit none
   double precision :: result
   result = MPI_Wtick( &
   )
end function MPIABI_Wtick

function MPIABI_Wtime( &
) result(result)
   use mpiwrapper
   implicit none
   double precision :: result
   result = MPI_Wtime( &
   )
end function MPIABI_Wtime

subroutine MPIABI_Info_create( &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: info
   integer, intent(out) :: ierror
   call MPI_Info_create( &
      info, &
      ierror &
   )
   info = mpi2abi_info(info)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_create

subroutine MPIABI_Info_create_env( &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: info
   integer, intent(out) :: ierror
   call MPI_Info_create_env( &
      info, &
      ierror &
   )
   info = mpi2abi_info(info)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_create_env

subroutine MPIABI_Info_delete( &
   info, &
   key, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   character(*), intent(in) :: key
   integer, intent(out) :: ierror
   call MPI_Info_delete( &
      abi2mpi_info(info), &
      key, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_delete

subroutine MPIABI_Info_dup( &
   info, &
   newinfo, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   integer, intent(out) :: newinfo
   integer, intent(out) :: ierror
   call MPI_Info_dup( &
      abi2mpi_info(info), &
      newinfo, &
      ierror &
   )
   newinfo = mpi2abi_info(newinfo)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_dup

subroutine MPIABI_Info_free( &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: info
   integer, intent(out) :: ierror
   call MPI_Info_free( &
      info, &
      ierror &
   )
   info = mpi2abi_info(info)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_free

subroutine MPIABI_Info_get_nkeys( &
   info, &
   nkeys, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   integer, intent(out) :: nkeys
   integer, intent(out) :: ierror
   call MPI_Info_get_nkeys( &
      abi2mpi_info(info), &
      nkeys, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_get_nkeys

subroutine MPIABI_Info_get_nthkey( &
   info, &
   n, &
   key, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   integer, intent(in) :: n
   character(*), intent(out) :: key
   integer, intent(out) :: ierror
   call MPI_Info_get_nthkey( &
      abi2mpi_info(info), &
      n, &
      key, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_get_nthkey

subroutine MPIABI_Info_get_string( &
   info, &
   key, &
   buflen, &
   value, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   character(*), intent(in) :: key
   integer, intent(out) :: buflen
   character(*), intent(out) :: value
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Info_get_string( &
      abi2mpi_info(info), &
      key, &
      buflen, &
      value, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_get_string

subroutine MPIABI_Info_set( &
   info, &
   key, &
   value, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   character(*), intent(in) :: key
   character(*), intent(in) :: value
   integer, intent(out) :: ierror
   call MPI_Info_set( &
      abi2mpi_info(info), &
      key, &
      value, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_set

subroutine MPIABI_Abort( &
   comm, &
   errorcode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: errorcode
   integer, intent(out) :: ierror
   call MPI_Abort( &
      abi2mpi_comm(comm), &
      errorcode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Abort

subroutine MPIABI_Close_port( &
   port_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: port_name
   integer, intent(out) :: ierror
   call MPI_Close_port( &
      port_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Close_port

subroutine MPIABI_Comm_accept( &
   port_name, &
   info, &
   root, &
   comm, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: port_name
   integer, intent(in) :: info
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_accept( &
      port_name, &
      abi2mpi_info(info), &
      root, &
      abi2mpi_comm(comm), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_accept

subroutine MPIABI_Comm_connect( &
   port_name, &
   info, &
   root, &
   comm, &
   newcomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: port_name
   integer, intent(in) :: info
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: newcomm
   integer, intent(out) :: ierror
   call MPI_Comm_connect( &
      port_name, &
      abi2mpi_info(info), &
      root, &
      abi2mpi_comm(comm), &
      newcomm, &
      ierror &
   )
   newcomm = mpi2abi_comm(newcomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_connect

subroutine MPIABI_Comm_disconnect( &
   comm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: comm
   integer, intent(out) :: ierror
   call MPI_Comm_disconnect( &
      comm, &
      ierror &
   )
   comm = mpi2abi_comm(comm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_disconnect

subroutine MPIABI_Comm_get_parent( &
   parent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: parent
   integer, intent(out) :: ierror
   call MPI_Comm_get_parent( &
      parent, &
      ierror &
   )
   parent = mpi2abi_comm(parent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_get_parent

subroutine MPIABI_Comm_join( &
   fd, &
   intercomm, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fd
   integer, intent(out) :: intercomm
   integer, intent(out) :: ierror
   call MPI_Comm_join( &
      fd, &
      intercomm, &
      ierror &
   )
   intercomm = mpi2abi_comm(intercomm)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_join

subroutine MPIABI_Comm_spawn( &
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
   use mpiwrapper
   implicit none
   character(*), intent(in) :: command
   character(*), intent(in) :: argv(*)
   integer, intent(in) :: maxprocs
   integer, intent(in) :: info
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: intercomm
   integer, intent(out) :: array_of_errcodes(maxprocs)
   integer, intent(out) :: ierror
   integer :: wrap_array_of_errcodes(maxprocs)
   integer :: i
   call MPI_Comm_spawn( &
      command, &
      argv, &
      maxprocs, &
      abi2mpi_info(info), &
      root, &
      abi2mpi_comm(comm), &
      intercomm, &
      wrap_array_of_errcodes, &
      ierror &
   )
   intercomm = mpi2abi_comm(intercomm)
   do i = 1, maxprocs
      array_of_errcodes(i) = mpi2abi_errorcode(wrap_array_of_errcodes(i))
   end do
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_spawn

subroutine MPIABI_Comm_spawn_multiple( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   character(*), intent(in) :: array_of_commands(count)
   character(*), intent(in) :: array_of_argv(count, *)
   integer, intent(in) :: array_of_maxprocs(count)
   integer, intent(in) :: array_of_info(count)
   integer, intent(in) :: root
   integer, intent(in) :: comm
   integer, intent(out) :: intercomm
   integer, intent(out) :: array_of_errcodes(*)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Comm_spawn_multiple is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer :: wrap_array_of_info(count)
   integer :: wrap_array_of_errcodes(*)
   integer :: i
   do i = 1, count
      wrap_array_of_info(i) = abi2mpi_info(array_of_info(i))
   end do
   call MPI_Comm_spawn_multiple( &
      count, &
      array_of_commands, &
      array_of_argv, &
      array_of_maxprocs, &
      wrap_array_of_info, &
      root, &
      abi2mpi_comm(comm), &
      intercomm, &
      wrap_array_of_errcodes, &
      ierror &
   )
   intercomm = mpi2abi_comm(intercomm)
   do i = 1, *
      array_of_errcodes(i) = mpi2abi_errorcode(wrap_array_of_errcodes(i))
   end do
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Comm_spawn_multiple

subroutine MPIABI_Finalize( &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: ierror
   call MPI_Finalize( &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Finalize

subroutine MPIABI_Finalized( &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Finalized( &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Finalized

subroutine MPIABI_Init( &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: ierror
   call MPI_Init( &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Init

subroutine MPIABI_Init_thread( &
   required, &
   provided, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: required
   integer, intent(out) :: provided
   integer, intent(out) :: ierror
   integer :: wrap_required
   integer :: wrap_provided
   wrap_required = abi2mpi_threadlevel(required)
   call MPI_Init_thread( &
      wrap_required, &
      wrap_provided, &
      ierror &
   )
   provided = mpi2abi_threadlevel(wrap_provided)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Init_thread

subroutine MPIABI_Initialized( &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Initialized( &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Initialized

subroutine MPIABI_Is_thread_main( &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Is_thread_main( &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Is_thread_main

subroutine MPIABI_Lookup_name( &
   service_name, &
   info, &
   port_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: service_name
   integer, intent(in) :: info
   character(*), intent(out) :: port_name
   integer, intent(out) :: ierror
   call MPI_Lookup_name( &
      service_name, &
      abi2mpi_info(info), &
      port_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Lookup_name

subroutine MPIABI_Open_port( &
   info, &
   port_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   character(*), intent(out) :: port_name
   integer, intent(out) :: ierror
   call MPI_Open_port( &
      abi2mpi_info(info), &
      port_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Open_port

subroutine MPIABI_Publish_name( &
   service_name, &
   info, &
   port_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: service_name
   integer, intent(in) :: info
   character(*), intent(in) :: port_name
   integer, intent(out) :: ierror
   call MPI_Publish_name( &
      service_name, &
      abi2mpi_info(info), &
      port_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Publish_name

subroutine MPIABI_Query_thread( &
   provided, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: provided
   integer, intent(out) :: ierror
   integer :: wrap_provided
   call MPI_Query_thread( &
      wrap_provided, &
      ierror &
   )
   provided = mpi2abi_threadlevel(wrap_provided)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Query_thread

subroutine MPIABI_Session_finalize( &
   session, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: session
   integer, intent(out) :: ierror
   call MPI_Session_finalize( &
      session, &
      ierror &
   )
   session = mpi2abi_session(session)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_finalize

subroutine MPIABI_Session_get_info( &
   session, &
   info_used, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(out) :: info_used
   integer, intent(out) :: ierror
   call MPI_Session_get_info( &
      abi2mpi_session(session), &
      info_used, &
      ierror &
   )
   info_used = mpi2abi_info(info_used)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_get_info

subroutine MPIABI_Session_get_nth_pset( &
   session, &
   info, &
   n, &
   pset_len, &
   pset_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(in) :: info
   integer, intent(in) :: n
   integer, intent(out) :: pset_len
   character(*), intent(out) :: pset_name
   integer, intent(out) :: ierror
   call MPI_Session_get_nth_pset( &
      abi2mpi_session(session), &
      abi2mpi_info(info), &
      n, &
      pset_len, &
      pset_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_get_nth_pset

subroutine MPIABI_Session_get_num_psets( &
   session, &
   info, &
   npset_names, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   integer, intent(in) :: info
   integer, intent(out) :: npset_names
   integer, intent(out) :: ierror
   call MPI_Session_get_num_psets( &
      abi2mpi_session(session), &
      abi2mpi_info(info), &
      npset_names, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_get_num_psets

subroutine MPIABI_Session_get_pset_info( &
   session, &
   pset_name, &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: session
   character(*), intent(in) :: pset_name
   integer, intent(out) :: info
   integer, intent(out) :: ierror
   call MPI_Session_get_pset_info( &
      abi2mpi_session(session), &
      pset_name, &
      info, &
      ierror &
   )
   info = mpi2abi_info(info)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_get_pset_info

subroutine MPIABI_Session_init( &
   info, &
   errhandler, &
   session, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   integer, intent(in) :: errhandler
   integer, intent(out) :: session
   integer, intent(out) :: ierror
   call MPI_Session_init( &
      abi2mpi_info(info), &
      abi2mpi_errhandler(errhandler), &
      session, &
      ierror &
   )
   session = mpi2abi_session(session)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Session_init

subroutine MPIABI_Unpublish_name( &
   service_name, &
   info, &
   port_name, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: service_name
   integer, intent(in) :: info
   character(*), intent(in) :: port_name
   integer, intent(out) :: ierror
   call MPI_Unpublish_name( &
      service_name, &
      abi2mpi_info(info), &
      port_name, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Unpublish_name

subroutine MPIABI_Accumulate( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: op
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Accumulate( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_op(op), &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Accumulate

subroutine MPIABI_Compare_and_swap( &
   origin_addr, &
   compare_addr, &
   result_addr, &
   datatype, &
   target_rank, &
   target_disp, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: compare_addr(*)
   integer, intent(out) :: result_addr(*)
   integer, intent(in) :: datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Compare_and_swap( &
      origin_addr, &
      compare_addr, &
      result_addr, &
      abi2mpi_datatype(datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Compare_and_swap

subroutine MPIABI_Fetch_and_op( &
   origin_addr, &
   result_addr, &
   datatype, &
   target_rank, &
   target_disp, &
   op, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(out) :: result_addr(*)
   integer, intent(in) :: datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: op
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Fetch_and_op( &
      origin_addr, &
      result_addr, &
      abi2mpi_datatype(datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      abi2mpi_op(op), &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Fetch_and_op

subroutine MPIABI_Get( &
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
   use mpiwrapper
   implicit none
   integer, intent(out) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Get( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get

subroutine MPIABI_Get_accumulate( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(out) :: result_addr(*)
   integer, intent(in) :: result_count
   integer, intent(in) :: result_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: op
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Get_accumulate( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      result_addr, &
      result_count, &
      abi2mpi_datatype(result_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_op(op), &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_accumulate

subroutine MPIABI_Put( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Put( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Put

subroutine MPIABI_Raccumulate( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: op
   integer, intent(in) :: win
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Raccumulate( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_op(op), &
      abi2mpi_win(win), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Raccumulate

subroutine MPIABI_Rget( &
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
   use mpiwrapper
   implicit none
   integer, intent(out) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: win
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Rget( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_win(win), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rget

subroutine MPIABI_Rget_accumulate( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(out) :: result_addr(*)
   integer, intent(in) :: result_count
   integer, intent(in) :: result_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: op
   integer, intent(in) :: win
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Rget_accumulate( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      result_addr, &
      result_count, &
      abi2mpi_datatype(result_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_op(op), &
      abi2mpi_win(win), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rget_accumulate

subroutine MPIABI_Rput( &
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
   use mpiwrapper
   implicit none
   integer, intent(in) :: origin_addr(*)
   integer, intent(in) :: origin_count
   integer, intent(in) :: origin_datatype
   integer, intent(in) :: target_rank
   integer(MPIABI_ADDRESS_KIND), intent(in) :: target_disp
   integer, intent(in) :: target_count
   integer, intent(in) :: target_datatype
   integer, intent(in) :: win
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_Rput( &
      origin_addr, &
      origin_count, &
      abi2mpi_datatype(origin_datatype), &
      target_rank, &
      abi2mpi_address(target_disp), &
      target_count, &
      abi2mpi_datatype(target_datatype), &
      abi2mpi_win(win), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rput

subroutine MPIABI_Win_allocate( &
   size, &
   disp_unit, &
   info, &
   comm, &
   baseptr, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer(MPIABI_ADDRESS_KIND), intent(in) :: size
   integer, intent(in) :: disp_unit
   integer, intent(in) :: info
   integer, intent(in) :: comm
   integer, intent(out) :: baseptr(*)
   integer, intent(out) :: win
   integer, intent(out) :: ierror
   call MPI_Win_allocate( &
      abi2mpi_address(size), &
      disp_unit, &
      abi2mpi_info(info), &
      abi2mpi_comm(comm), &
      baseptr, &
      win, &
      ierror &
   )
   win = mpi2abi_win(win)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_allocate

subroutine MPIABI_Win_allocate_shared( &
   size, &
   disp_unit, &
   info, &
   comm, &
   baseptr, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer(MPIABI_ADDRESS_KIND), intent(in) :: size
   integer, intent(in) :: disp_unit
   integer, intent(in) :: info
   integer, intent(in) :: comm
   integer, intent(out) :: baseptr(*)
   integer, intent(out) :: win
   integer, intent(out) :: ierror
   call MPI_Win_allocate_shared( &
      abi2mpi_address(size), &
      disp_unit, &
      abi2mpi_info(info), &
      abi2mpi_comm(comm), &
      baseptr, &
      win, &
      ierror &
   )
   win = mpi2abi_win(win)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_allocate_shared

subroutine MPIABI_Win_attach( &
   win, &
   base, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: base(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: size
   integer, intent(out) :: ierror
   call MPI_Win_attach( &
      abi2mpi_win(win), &
      base, &
      abi2mpi_address(size), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_attach

subroutine MPIABI_Win_complete( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_complete( &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_complete

subroutine MPIABI_Win_create( &
   base, &
   size, &
   disp_unit, &
   info, &
   comm, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: base(*)
   integer(MPIABI_ADDRESS_KIND), intent(in) :: size
   integer, intent(in) :: disp_unit
   integer, intent(in) :: info
   integer, intent(in) :: comm
   integer, intent(out) :: win
   integer, intent(out) :: ierror
   call MPI_Win_create( &
      base, &
      abi2mpi_address(size), &
      disp_unit, &
      abi2mpi_info(info), &
      abi2mpi_comm(comm), &
      win, &
      ierror &
   )
   win = mpi2abi_win(win)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_create

subroutine MPIABI_Win_create_dynamic( &
   info, &
   comm, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   integer, intent(in) :: comm
   integer, intent(out) :: win
   integer, intent(out) :: ierror
   call MPI_Win_create_dynamic( &
      abi2mpi_info(info), &
      abi2mpi_comm(comm), &
      win, &
      ierror &
   )
   win = mpi2abi_win(win)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_create_dynamic

subroutine MPIABI_Win_detach( &
   win, &
   base, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: base(*)
   integer, intent(out) :: ierror
   call MPI_Win_detach( &
      abi2mpi_win(win), &
      base, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_detach

subroutine MPIABI_Win_fence( &
   assert, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: assert
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_fence( &
      assert, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_fence

subroutine MPIABI_Win_flush( &
   rank, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: rank
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_flush( &
      rank, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_flush

subroutine MPIABI_Win_flush_all( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_flush_all( &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_flush_all

subroutine MPIABI_Win_flush_local( &
   rank, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: rank
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_flush_local( &
      rank, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_flush_local

subroutine MPIABI_Win_flush_local_all( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_flush_local_all( &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_flush_local_all

subroutine MPIABI_Win_free( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: win
   integer, intent(out) :: ierror
   call MPI_Win_free( &
      win, &
      ierror &
   )
   win = mpi2abi_win(win)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_free

subroutine MPIABI_Win_get_group( &
   win, &
   group, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: group
   integer, intent(out) :: ierror
   call MPI_Win_get_group( &
      abi2mpi_win(win), &
      group, &
      ierror &
   )
   group = mpi2abi_group(group)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_get_group

subroutine MPIABI_Win_get_info( &
   win, &
   info_used, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: info_used
   integer, intent(out) :: ierror
   call MPI_Win_get_info( &
      abi2mpi_win(win), &
      info_used, &
      ierror &
   )
   info_used = mpi2abi_info(info_used)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_get_info

subroutine MPIABI_Win_lock( &
   lock_type, &
   rank, &
   assert, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: lock_type
   integer, intent(in) :: rank
   integer, intent(in) :: assert
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_lock( &
      lock_type, &
      rank, &
      assert, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_lock

subroutine MPIABI_Win_lock_all( &
   assert, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: assert
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_lock_all( &
      assert, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_lock_all

subroutine MPIABI_Win_post( &
   group, &
   assert, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(in) :: assert
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_post( &
      abi2mpi_group(group), &
      assert, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_post

subroutine MPIABI_Win_set_info( &
   win, &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: info
   integer, intent(out) :: ierror
   call MPI_Win_set_info( &
      abi2mpi_win(win), &
      abi2mpi_info(info), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_set_info

subroutine MPIABI_Win_shared_query( &
   win, &
   rank, &
   size, &
   disp_unit, &
   baseptr, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(in) :: rank
   integer(MPIABI_ADDRESS_KIND), intent(out) :: size
   integer, intent(out) :: disp_unit
   integer, intent(out) :: baseptr(*)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_size
   call MPI_Win_shared_query( &
      abi2mpi_win(win), &
      rank, &
      wrap_size, &
      disp_unit, &
      baseptr, &
      ierror &
   )
   size = mpi2abi_address(wrap_size)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_shared_query

subroutine MPIABI_Win_start( &
   group, &
   assert, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: group
   integer, intent(in) :: assert
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_start( &
      abi2mpi_group(group), &
      assert, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_start

subroutine MPIABI_Win_sync( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_sync( &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_sync

subroutine MPIABI_Win_test( &
   win, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Win_test( &
      abi2mpi_win(win), &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_test

subroutine MPIABI_Win_unlock( &
   rank, &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: rank
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_unlock( &
      rank, &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_unlock

subroutine MPIABI_Win_unlock_all( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_unlock_all( &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_unlock_all

subroutine MPIABI_Win_wait( &
   win, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: win
   integer, intent(out) :: ierror
   call MPI_Win_wait( &
      abi2mpi_win(win), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Win_wait

subroutine MPIABI_Grequest_complete( &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: request
   integer, intent(out) :: ierror
   call MPI_Grequest_complete( &
      abi2mpi_request(request), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Grequest_complete

subroutine MPIABI_Grequest_start( &
   query_fn, &
   free_fn, &
   cancel_fn, &
   extra_state, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: query_fn
   external :: free_fn
   external :: cancel_fn
   integer, intent(out) :: extra_state(*)
   integer, intent(out) :: request
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Grequest_start is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_query_fn
   external :: wrap_free_fn
   external :: wrap_cancel_fn
   wrap_query_fn = abi2mpi_external(query_fn)
   wrap_free_fn = abi2mpi_external(free_fn)
   wrap_cancel_fn = abi2mpi_external(cancel_fn)
   call MPI_Grequest_start( &
      wrap_query_fn, &
      wrap_free_fn, &
      wrap_cancel_fn, &
      extra_state, &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Grequest_start

subroutine MPIABI_Status_set_cancelled( &
   status, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   logical, intent(in) :: flag
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Status_set_cancelled( &
      wrap_status, &
      flag, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Status_set_cancelled

subroutine MPIABI_Status_set_elements( &
   status, &
   datatype, &
   count, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: datatype
   integer, intent(in) :: count
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Status_set_elements( &
      wrap_status, &
      abi2mpi_datatype(datatype), &
      count, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Status_set_elements

subroutine MPIABI_Status_set_error( &
   status, &
   err, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: err
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Status_set_error is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Status_set_error( &
      wrap_status, &
      err, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Status_set_error

subroutine MPIABI_Status_set_source( &
   status, &
   source, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: source
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Status_set_source is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Status_set_source( &
      wrap_status, &
      source, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Status_set_source

subroutine MPIABI_Status_set_tag( &
   status, &
   tag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: tag
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 401
   write(0, '("The Fortran function MPI_Status_set_tag is not available in the wrapped MPI implementation")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Status_set_tag( &
      wrap_status, &
      tag, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Status_set_tag

subroutine MPIABI_File_close( &
   fh, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: fh
   integer, intent(out) :: ierror
   call MPI_File_close( &
      fh, &
      ierror &
   )
   fh = mpi2abi_file(fh)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_close

subroutine MPIABI_File_delete( &
   filename, &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: filename
   integer, intent(in) :: info
   integer, intent(out) :: ierror
   call MPI_File_delete( &
      filename, &
      abi2mpi_info(info), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_delete

subroutine MPIABI_File_get_amode( &
   fh, &
   amode, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: amode
   integer, intent(out) :: ierror
   call MPI_File_get_amode( &
      abi2mpi_file(fh), &
      amode, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_amode

subroutine MPIABI_File_get_atomicity( &
   fh, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_File_get_atomicity( &
      abi2mpi_file(fh), &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_atomicity

subroutine MPIABI_File_get_byte_offset( &
   fh, &
   offset, &
   disp, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer(MPIABI_OFFSET_KIND), intent(out) :: disp
   integer, intent(out) :: ierror
   integer(MPI_OFFSET_KIND) :: wrap_disp
   call MPI_File_get_byte_offset( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      wrap_disp, &
      ierror &
   )
   disp = mpi2abi_offset(wrap_disp)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_byte_offset

subroutine MPIABI_File_get_group( &
   fh, &
   group, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: group
   integer, intent(out) :: ierror
   call MPI_File_get_group( &
      abi2mpi_file(fh), &
      group, &
      ierror &
   )
   group = mpi2abi_group(group)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_group

subroutine MPIABI_File_get_info( &
   fh, &
   info_used, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: info_used
   integer, intent(out) :: ierror
   call MPI_File_get_info( &
      abi2mpi_file(fh), &
      info_used, &
      ierror &
   )
   info_used = mpi2abi_info(info_used)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_info

subroutine MPIABI_File_get_position( &
   fh, &
   offset, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(out) :: offset
   integer, intent(out) :: ierror
   integer(MPI_OFFSET_KIND) :: wrap_offset
   call MPI_File_get_position( &
      abi2mpi_file(fh), &
      wrap_offset, &
      ierror &
   )
   offset = mpi2abi_offset(wrap_offset)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_position

subroutine MPIABI_File_get_position_shared( &
   fh, &
   offset, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(out) :: offset
   integer, intent(out) :: ierror
   integer(MPI_OFFSET_KIND) :: wrap_offset
   call MPI_File_get_position_shared( &
      abi2mpi_file(fh), &
      wrap_offset, &
      ierror &
   )
   offset = mpi2abi_offset(wrap_offset)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_position_shared

subroutine MPIABI_File_get_size( &
   fh, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(out) :: size
   integer, intent(out) :: ierror
   integer(MPI_OFFSET_KIND) :: wrap_size
   call MPI_File_get_size( &
      abi2mpi_file(fh), &
      wrap_size, &
      ierror &
   )
   size = mpi2abi_offset(wrap_size)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_size

subroutine MPIABI_File_get_type_extent( &
   fh, &
   datatype, &
   extent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: extent
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_extent
   call MPI_File_get_type_extent( &
      abi2mpi_file(fh), &
      abi2mpi_datatype(datatype), &
      wrap_extent, &
      ierror &
   )
   extent = mpi2abi_address(wrap_extent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_type_extent

subroutine MPIABI_File_get_view( &
   fh, &
   disp, &
   etype, &
   filetype, &
   datarep, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(out) :: disp
   integer, intent(out) :: etype
   integer, intent(out) :: filetype
   character(*), intent(out) :: datarep
   integer, intent(out) :: ierror
   integer(MPI_OFFSET_KIND) :: wrap_disp
   call MPI_File_get_view( &
      abi2mpi_file(fh), &
      wrap_disp, &
      etype, &
      filetype, &
      datarep, &
      ierror &
   )
   disp = mpi2abi_offset(wrap_disp)
   etype = mpi2abi_datatype(etype)
   filetype = mpi2abi_datatype(filetype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_get_view

subroutine MPIABI_File_iread( &
   fh, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iread( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iread

subroutine MPIABI_File_iread_all( &
   fh, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iread_all( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iread_all

subroutine MPIABI_File_iread_at( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iread_at( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iread_at

subroutine MPIABI_File_iread_at_all( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iread_at_all( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iread_at_all

subroutine MPIABI_File_iread_shared( &
   fh, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iread_shared( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iread_shared

subroutine MPIABI_File_iwrite( &
   fh, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iwrite( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iwrite

subroutine MPIABI_File_iwrite_all( &
   fh, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iwrite_all( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iwrite_all

subroutine MPIABI_File_iwrite_at( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iwrite_at( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iwrite_at

subroutine MPIABI_File_iwrite_at_all( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iwrite_at_all( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iwrite_at_all

subroutine MPIABI_File_iwrite_shared( &
   fh, &
   buf, &
   count, &
   datatype, &
   request, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: request
   integer, intent(out) :: ierror
   call MPI_File_iwrite_shared( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      request, &
      ierror &
   )
   request = mpi2abi_request(request)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_iwrite_shared

subroutine MPIABI_File_open( &
   comm, &
   filename, &
   amode, &
   info, &
   fh, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   character(*), intent(in) :: filename
   integer, intent(in) :: amode
   integer, intent(in) :: info
   integer, intent(out) :: fh
   integer, intent(out) :: ierror
   call MPI_File_open( &
      abi2mpi_comm(comm), &
      filename, &
      amode, &
      abi2mpi_info(info), &
      fh, &
      ierror &
   )
   fh = mpi2abi_file(fh)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_open

subroutine MPIABI_File_preallocate( &
   fh, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: size
   integer, intent(out) :: ierror
   call MPI_File_preallocate( &
      abi2mpi_file(fh), &
      abi2mpi_offset(size), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_preallocate

subroutine MPIABI_File_read( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read

subroutine MPIABI_File_read_all( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_all( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_all

subroutine MPIABI_File_read_all_begin( &
   fh, &
   buf, &
   count, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   call MPI_File_read_all_begin( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_all_begin

subroutine MPIABI_File_read_all_end( &
   fh, &
   buf, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_all_end( &
      abi2mpi_file(fh), &
      buf, &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_all_end

subroutine MPIABI_File_read_at( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_at( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_at

subroutine MPIABI_File_read_at_all( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_at_all( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_at_all

subroutine MPIABI_File_read_at_all_begin( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   call MPI_File_read_at_all_begin( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_at_all_begin

subroutine MPIABI_File_read_at_all_end( &
   fh, &
   buf, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_at_all_end( &
      abi2mpi_file(fh), &
      buf, &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_at_all_end

subroutine MPIABI_File_read_ordered( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_ordered( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_ordered

subroutine MPIABI_File_read_ordered_begin( &
   fh, &
   buf, &
   count, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   call MPI_File_read_ordered_begin( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_ordered_begin

subroutine MPIABI_File_read_ordered_end( &
   fh, &
   buf, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_ordered_end( &
      abi2mpi_file(fh), &
      buf, &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_ordered_end

subroutine MPIABI_File_read_shared( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_read_shared( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_read_shared

subroutine MPIABI_File_seek( &
   fh, &
   offset, &
   whence, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: whence
   integer, intent(out) :: ierror
   call MPI_File_seek( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      whence, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_seek

subroutine MPIABI_File_seek_shared( &
   fh, &
   offset, &
   whence, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: whence
   integer, intent(out) :: ierror
   call MPI_File_seek_shared( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      whence, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_seek_shared

subroutine MPIABI_File_set_atomicity( &
   fh, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   logical, intent(in) :: flag
   integer, intent(out) :: ierror
   call MPI_File_set_atomicity( &
      abi2mpi_file(fh), &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_set_atomicity

subroutine MPIABI_File_set_info( &
   fh, &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: info
   integer, intent(out) :: ierror
   call MPI_File_set_info( &
      abi2mpi_file(fh), &
      abi2mpi_info(info), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_set_info

subroutine MPIABI_File_set_size( &
   fh, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: size
   integer, intent(out) :: ierror
   call MPI_File_set_size( &
      abi2mpi_file(fh), &
      abi2mpi_offset(size), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_set_size

subroutine MPIABI_File_set_view( &
   fh, &
   disp, &
   etype, &
   filetype, &
   datarep, &
   info, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: disp
   integer, intent(in) :: etype
   integer, intent(in) :: filetype
   character(*), intent(in) :: datarep
   integer, intent(in) :: info
   integer, intent(out) :: ierror
   call MPI_File_set_view( &
      abi2mpi_file(fh), &
      abi2mpi_offset(disp), &
      abi2mpi_datatype(etype), &
      abi2mpi_datatype(filetype), &
      datarep, &
      abi2mpi_info(info), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_set_view

subroutine MPIABI_File_sync( &
   fh, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(out) :: ierror
   call MPI_File_sync( &
      abi2mpi_file(fh), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_sync

subroutine MPIABI_File_write( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write

subroutine MPIABI_File_write_all( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_all( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_all

subroutine MPIABI_File_write_all_begin( &
   fh, &
   buf, &
   count, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   call MPI_File_write_all_begin( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_all_begin

subroutine MPIABI_File_write_all_end( &
   fh, &
   buf, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_all_end( &
      abi2mpi_file(fh), &
      buf, &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_all_end

subroutine MPIABI_File_write_at( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_at( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_at

subroutine MPIABI_File_write_at_all( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_at_all( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_at_all

subroutine MPIABI_File_write_at_all_begin( &
   fh, &
   offset, &
   buf, &
   count, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer(MPIABI_OFFSET_KIND), intent(in) :: offset
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   call MPI_File_write_at_all_begin( &
      abi2mpi_file(fh), &
      abi2mpi_offset(offset), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_at_all_begin

subroutine MPIABI_File_write_at_all_end( &
   fh, &
   buf, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_at_all_end( &
      abi2mpi_file(fh), &
      buf, &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_at_all_end

subroutine MPIABI_File_write_ordered( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_ordered( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_ordered

subroutine MPIABI_File_write_ordered_begin( &
   fh, &
   buf, &
   count, &
   datatype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: ierror
   call MPI_File_write_ordered_begin( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_ordered_begin

subroutine MPIABI_File_write_ordered_end( &
   fh, &
   buf, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_ordered_end( &
      abi2mpi_file(fh), &
      buf, &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_ordered_end

subroutine MPIABI_File_write_shared( &
   fh, &
   buf, &
   count, &
   datatype, &
   status, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: fh
   integer, intent(in) :: buf(*)
   integer, intent(in) :: count
   integer, intent(in) :: datatype
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_File_write_shared( &
      abi2mpi_file(fh), &
      buf, &
      count, &
      abi2mpi_datatype(datatype), &
      wrap_status, &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_write_shared

subroutine MPIABI_Register_datarep( &
   datarep, &
   read_conversion_fn, &
   write_conversion_fn, &
   dtype_file_extent_fn, &
   extra_state, &
   ierror &
)
   use mpiwrapper
   implicit none
   character(*), intent(in) :: datarep
   external :: read_conversion_fn
   external :: write_conversion_fn
   external :: dtype_file_extent_fn
   integer, intent(out) :: extra_state(*)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Register_datarep is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_read_conversion_fn
   external :: wrap_write_conversion_fn
   external :: wrap_dtype_file_extent_fn
   wrap_read_conversion_fn = abi2mpi_external(read_conversion_fn)
   wrap_write_conversion_fn = abi2mpi_external(write_conversion_fn)
   wrap_dtype_file_extent_fn = abi2mpi_external(dtype_file_extent_fn)
   call MPI_Register_datarep( &
      datarep, &
      wrap_read_conversion_fn, &
      wrap_write_conversion_fn, &
      wrap_dtype_file_extent_fn, &
      extra_state, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Register_datarep

subroutine MPIABI_F_sync_reg( &
   buf &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: buf(*)
   call MPI_F_sync_reg( &
      buf &
   )
end subroutine MPIABI_F_sync_reg

subroutine MPIABI_Type_create_f90_complex( &
   p, &
   r, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: p
   integer, intent(in) :: r
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_f90_complex( &
      p, &
      r, &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_f90_complex

subroutine MPIABI_Type_create_f90_integer( &
   r, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: r
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_f90_integer( &
      r, &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_f90_integer

subroutine MPIABI_Type_create_f90_real( &
   p, &
   r, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: p
   integer, intent(in) :: r
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_create_f90_real( &
      p, &
      r, &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_f90_real

subroutine MPIABI_Type_match_size( &
   typeclass, &
   size, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: typeclass
   integer, intent(in) :: size
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_match_size( &
      typeclass, &
      size, &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_match_size

subroutine MPIABI_Pcontrol( &
   level &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: level
   call MPI_Pcontrol( &
      level &
   )
end subroutine MPIABI_Pcontrol

subroutine MPIABI_Attr_delete( &
   comm, &
   keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: keyval
   integer, intent(out) :: ierror
   call MPI_Attr_delete( &
      abi2mpi_comm(comm), &
      keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Attr_delete

subroutine MPIABI_Attr_get( &
   comm, &
   keyval, &
   attribute_val, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: keyval
   integer, intent(out) :: attribute_val(*)
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Attr_get( &
      abi2mpi_comm(comm), &
      keyval, &
      attribute_val, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Attr_get

subroutine MPIABI_Attr_put( &
   comm, &
   keyval, &
   attribute_val, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: comm
   integer, intent(in) :: keyval
   integer, intent(out) :: attribute_val(*)
   integer, intent(out) :: ierror
   call MPI_Attr_put( &
      abi2mpi_comm(comm), &
      keyval, &
      attribute_val, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Attr_put

subroutine MPIABI_Get_elements_x( &
   status, &
   datatype, &
   count, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: datatype
   integer(MPIABI_COUNT_KIND), intent(out) :: count
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   integer(MPI_COUNT_KIND) :: wrap_count
   ptr_status = abi2mpi_status_ptr(status, tmp_status)
   call MPI_Get_elements_x( &
      wrap_status, &
      abi2mpi_datatype(datatype), &
      wrap_count, &
      ierror &
   )
   count = mpi2abi_count(wrap_count)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_elements_x

subroutine MPIABI_Info_get( &
   info, &
   key, &
   valuelen, &
   value, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   character(*), intent(in) :: key
   integer, intent(in) :: valuelen
   character(*), intent(out) :: value
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Info_get( &
      abi2mpi_info(info), &
      key, &
      valuelen, &
      value, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_get

subroutine MPIABI_Info_get_valuelen( &
   info, &
   key, &
   valuelen, &
   flag, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: info
   character(*), intent(in) :: key
   integer, intent(out) :: valuelen
   logical, intent(out) :: flag
   integer, intent(out) :: ierror
   call MPI_Info_get_valuelen( &
      abi2mpi_info(info), &
      key, &
      valuelen, &
      flag, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Info_get_valuelen

subroutine MPIABI_Keyval_create( &
   copy_fn, &
   delete_fn, &
   keyval, &
   extra_state, &
   ierror &
)
   use mpiwrapper
   implicit none
   external :: copy_fn
   external :: delete_fn
   integer, intent(out) :: keyval
   integer, intent(out) :: extra_state(*)
   integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER < 9999900
   write(0, '("The Fortran function MPI_Keyval_create is not available in MPItrampoline")')
   call MPI_Abort(MPI_COMM_SELF, 1, ierror)
   stop
#else
   external :: wrap_copy_fn
   external :: wrap_delete_fn
   wrap_copy_fn = abi2mpi_external(copy_fn)
   wrap_delete_fn = abi2mpi_external(delete_fn)
   call MPI_Keyval_create( &
      wrap_copy_fn, &
      wrap_delete_fn, &
      keyval, &
      extra_state, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
#endif
end subroutine MPIABI_Keyval_create

subroutine MPIABI_Keyval_free( &
   keyval, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: keyval
   integer, intent(out) :: ierror
   call MPI_Keyval_free( &
      keyval, &
      ierror &
   )
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Keyval_free

subroutine MPIABI_Status_set_elements_x( &
   status, &
   datatype, &
   count, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: status(MPIABI_STATUS_SIZE)
   integer, intent(in) :: datatype
   integer(MPIABI_COUNT_KIND), intent(in) :: count
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: ptr_status
   integer :: wrap_status(MPI_STATUS_SIZE)
   pointer(ptr_status, wrap_status)
   integer :: tmp_status(MPI_STATUS_SIZE)
   ptr_status = abi2mpi_status_ptr_uninitialized(status, tmp_status)
   call MPI_Status_set_elements_x( &
      wrap_status, &
      abi2mpi_datatype(datatype), &
      abi2mpi_count(count), &
      ierror &
   )
   call mpi2abi_status_ptr(wrap_status, status)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Status_set_elements_x

subroutine MPIABI_Type_get_extent_x( &
   datatype, &
   lb, &
   extent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_COUNT_KIND), intent(out) :: lb
   integer(MPIABI_COUNT_KIND), intent(out) :: extent
   integer, intent(out) :: ierror
   integer(MPI_COUNT_KIND) :: wrap_lb
   integer(MPI_COUNT_KIND) :: wrap_extent
   call MPI_Type_get_extent_x( &
      abi2mpi_datatype(datatype), &
      wrap_lb, &
      wrap_extent, &
      ierror &
   )
   lb = mpi2abi_count(wrap_lb)
   extent = mpi2abi_count(wrap_extent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_extent_x

subroutine MPIABI_Type_get_true_extent_x( &
   datatype, &
   true_lb, &
   true_extent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_COUNT_KIND), intent(out) :: true_lb
   integer(MPIABI_COUNT_KIND), intent(out) :: true_extent
   integer, intent(out) :: ierror
   integer(MPI_COUNT_KIND) :: wrap_true_lb
   integer(MPI_COUNT_KIND) :: wrap_true_extent
   call MPI_Type_get_true_extent_x( &
      abi2mpi_datatype(datatype), &
      wrap_true_lb, &
      wrap_true_extent, &
      ierror &
   )
   true_lb = mpi2abi_count(wrap_true_lb)
   true_extent = mpi2abi_count(wrap_true_extent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_true_extent_x

subroutine MPIABI_Type_size_x( &
   datatype, &
   size, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_COUNT_KIND), intent(out) :: size
   integer, intent(out) :: ierror
   integer(MPI_COUNT_KIND) :: wrap_size
   call MPI_Type_size_x( &
      abi2mpi_datatype(datatype), &
      wrap_size, &
      ierror &
   )
   size = mpi2abi_count(wrap_size)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_size_x

subroutine MPIABI_Address( &
   location, &
   address, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(out) :: location(*)
   integer(MPIABI_ADDRESS_KIND), intent(out) :: address
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_address
   call MPI_Address( &
      location, &
      wrap_address, &
      ierror &
   )
   address = mpi2abi_address(wrap_address)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Address

subroutine MPIABI_Type_hindexed( &
   count, &
   array_of_blocklengths, &
   array_of_displacements, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(out) :: array_of_blocklengths
   integer(MPIABI_ADDRESS_KIND), intent(out) :: array_of_displacements
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_array_of_displacements
   call MPI_Type_hindexed( &
      count, &
      array_of_blocklengths, &
      wrap_array_of_displacements, &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   array_of_displacements = mpi2abi_address(wrap_array_of_displacements)
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_hindexed

subroutine MPIABI_Type_hvector( &
   count, &
   blocklength, &
   stride, &
   oldtype, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(in) :: blocklength
   integer(MPIABI_ADDRESS_KIND), intent(in) :: stride
   integer, intent(in) :: oldtype
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   call MPI_Type_hvector( &
      count, &
      blocklength, &
      abi2mpi_address(stride), &
      abi2mpi_datatype(oldtype), &
      newtype, &
      ierror &
   )
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_hvector

subroutine MPIABI_Type_struct( &
   count, &
   array_of_blocklengths, &
   array_of_displacements, &
   array_of_types, &
   newtype, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: count
   integer, intent(out) :: array_of_blocklengths
   integer(MPIABI_ADDRESS_KIND), intent(out) :: array_of_displacements
   integer, intent(out) :: array_of_types
   integer, intent(out) :: newtype
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_array_of_displacements
   call MPI_Type_struct( &
      count, &
      array_of_blocklengths, &
      wrap_array_of_displacements, &
      array_of_types, &
      newtype, &
      ierror &
   )
   array_of_displacements = mpi2abi_address(wrap_array_of_displacements)
   array_of_types = mpi2abi_datatype(array_of_types)
   newtype = mpi2abi_datatype(newtype)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_struct

subroutine MPIABI_Type_extent( &
   datatype, &
   extent, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: extent
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_extent
   call MPI_Type_extent( &
      abi2mpi_datatype(datatype), &
      wrap_extent, &
      ierror &
   )
   extent = mpi2abi_address(wrap_extent)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_extent

subroutine MPIABI_Type_lb( &
   datatype, &
   displacement, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: displacement
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_displacement
   call MPI_Type_lb( &
      abi2mpi_datatype(datatype), &
      wrap_displacement, &
      ierror &
   )
   displacement = mpi2abi_address(wrap_displacement)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_lb

subroutine MPIABI_Type_ub( &
   datatype, &
   displacement, &
   ierror &
)
   use mpiwrapper
   implicit none
   integer, intent(in) :: datatype
   integer(MPIABI_ADDRESS_KIND), intent(out) :: displacement
   integer, intent(out) :: ierror
   integer(MPI_ADDRESS_KIND) :: wrap_displacement
   call MPI_Type_ub( &
      abi2mpi_datatype(datatype), &
      wrap_displacement, &
      ierror &
   )
   displacement = mpi2abi_address(wrap_displacement)
   ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_ub

