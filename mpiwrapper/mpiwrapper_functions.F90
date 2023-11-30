#include "mpiwrapper.h"
  
#define MPI_VERSION_NUMBER (100 * MPI_Fortran_VERSION_MAJOR + MPI_Fortran_VERSION_MINOR)

! Fake MPI 4 support, just enough to make the compiler happy
#ifndef HAVE_MPI_BUFFER_AUTOMATIC
#define MPI_BUFFER_AUTOMATIC MPIABI_BUFFER_AUTOMATIC
#endif

! A.3 C Bindings

! A.3.1 Point-to-Point Communication C Bindings

subroutine MPIABI_Bsend(buf, count, datatype, dest, tag, comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: buf(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call MPI_Bsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm))
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bsend
 
subroutine MPIABI_Bsend_init(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Bsend_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), &
       wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bsend_init
 
subroutine MPIABI_Buffer_attach(buffer, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: buffer(*)
  integer, intent(in) :: size
  integer, intent(out) :: ierror
  integer(MPIABI_ADDRESS_KIND) buffer_addr
  integer(MPI_ADDRESS_KIND) wrap_buffer_addr
  integer wrap_buffer(*)
  pointer (wrap_buffer_addr, wrap_buffer)
  buffer_addr = loc(buffer)
  if (buffer_addr == loc(MPIABI_BUFFER_AUTOMATIC)) then
     wrap_buffer_addr = loc(MPI_BUFFER_AUTOMATIC)
  else
     wrap_buffer_addr = buffer_addr
  end if
  call MPI_Buffer_attach(wrap_buffer, size, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Buffer_attach

subroutine MPIABI_Buffer_detach(buffer_addr, size, ierror)
  use mpiwrapper
  implicit none
  integer(MPIABI_ADDRESS_KIND), intent(out) :: buffer_addr
  integer, intent(out) :: size
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_buffer_addr
  call MPI_Buffer_detach(wrap_buffer_addr, size, ierror)
  if (wrap_buffer_addr == loc(MPI_BUFFER_AUTOMATIC)) then
     buffer_addr = loc(MPIABI_BUFFER_AUTOMATIC)
  else
     buffer_addr = wrap_buffer_addr
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Buffer_detach

subroutine MPIABI_Buffer_flush(ierror)
  use mpiwrapper
  implicit none
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  call MPI_Buffer_flush(ierror)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Buffer_flush

subroutine MPIABI_Buffer_iflush(request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: request
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_request
  call MPI_Buffer_iflush(wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Buffer_iflush

subroutine MPIABI_Cancel(request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: request
  integer, intent(out) :: ierror
  integer wrap_request
  wrap_request = abi2mpi_request(request)
  call MPI_Cancel(wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Cancel

subroutine MPIABI_Comm_attach_buffer(comm, buffer, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(in) :: buffer(*)
  integer, intent(in) :: size
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer(MPIABI_ADDRESS_KIND) buffer_addr
  integer(MPI_ADDRESS_KIND) wrap_buffer_addr
  integer wrap_buffer(*)
  pointer (wrap_buffer_addr, wrap_buffer)
  buffer_addr = loc(buffer)
  if (buffer_addr == loc(MPIABI_BUFFER_AUTOMATIC)) then
     wrap_buffer_addr = loc(MPI_BUFFER_AUTOMATIC)
  else
     wrap_buffer_addr = buffer_addr
  end if
  call MPI_Comm_attach_buffer(abi2mpi_comm(comm), wrap_buffer, size, ierror)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Comm_attach_buffer

subroutine MPIABI_Comm_detach_buffer(comm, buffer_addr, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer(MPIABI_ADDRESS_KIND), intent(out) :: buffer_addr
  integer, intent(out) :: size
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer(MPI_ADDRESS_KIND) wrap_buffer_addr
  call MPI_Comm_detach_buffer(abi2mpi_comm(comm), wrap_buffer_addr, size, ierror)
  if (wrap_buffer_addr == loc(MPI_BUFFER_AUTOMATIC)) then
     buffer_addr = loc(MPIABI_BUFFER_AUTOMATIC)
  else
     buffer_addr = wrap_buffer_addr
  end if
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Comm_detach_buffer

subroutine MPIABI_Comm_flush_buffer(comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  call MPI_Comm_flush_buffer(abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Comm_flush_buffer

subroutine MPIABI_Comm_iflush_buffer(comm, request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(out) :: request
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_request
  call MPI_Comm_iflush_buffer(abi2mpi_comm(comm), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Comm_iflush_buffer

subroutine MPIABI_Get_count(status, datatype, count, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: status(MPIABI_STATUS_SIZE)
  integer, intent(in) :: datatype
  integer, intent(out) :: count
  integer, intent(out) :: ierror
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Get_count(wrap_status, abi2mpi_datatype(datatype), count, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_count

subroutine MPIABI_Ibsend(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Ibsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_request, &
       ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ibsend

subroutine MPIABI_Improbe(source, tag, comm, flag, message, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: source
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  logical, intent(in) :: flag
  integer, intent(in) :: message
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Improbe(abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), flag, abi2mpi_message(message), wrap_status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Improbe

subroutine MPIABI_Imrecv(buf, count, datatype, message, request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(out) :: buf
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: message
  integer, intent(out) :: request
  integer, intent(out) :: ierror
  integer wrap_request
  call MPI_Imrecv(buf, count, abi2mpi_datatype(datatype), abi2mpi_message(message), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Imrecv

subroutine MPIABI_Iprobe(source, tag, comm, flag, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: source
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  logical, intent(out) :: flag
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Iprobe(abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), flag, wrap_status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Iprobe

subroutine MPIABI_Irecv(buf, count, datatype, source, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Irecv(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_request, &
       ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Irecv

subroutine MPIABI_Irsend(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Irsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_request, &
       ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Irsend

subroutine MPIABI_Isend(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Isend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_request, &
       ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Isend

subroutine MPIABI_Isendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, &
     request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: sendbuf(*)
  integer, intent(in) :: sendcount
  integer, intent(in) :: sendtype
  integer, intent(in) :: dest
  integer, intent(in) :: sendtag
  integer, intent(out) :: recvbuf
  integer, intent(in) :: recvcount
  integer, intent(in) :: recvtype
  integer, intent(in) :: source
  integer, intent(in) :: recvtag
  integer, intent(in) :: comm
  integer, intent(out) :: request
  integer, intent(out) :: ierror
  integer wrap_request
  call MPI_Isendrecv(sendbuf, sendcount, abi2mpi_datatype(sendtype), abi2mpi_proc(dest), abi2mpi_tag(sendtag), recvbuf, recvcount, &
       abi2mpi_datatype(recvtype), abi2mpi_proc(source), abi2mpi_tag(recvtag), abi2mpi_comm(comm), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Isendrecv

subroutine MPIABI_Isendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Isendrecv_replace(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(sendtag), &
       abi2mpi_proc(source), abi2mpi_tag(recvtag), abi2mpi_comm(comm), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Isendrecv_replace

subroutine MPIABI_Issend(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Issend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_request, &
       ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Issend

subroutine MPIABI_Mprobe(source, tag, comm, message, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: source
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(in) :: message
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Mprobe(abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), abi2mpi_message(message), status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Mprobe

subroutine MPIABI_Mrecv(buf, count, datatype, message, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(out) :: buf(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: message
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Mrecv(buf, count, abi2mpi_datatype(datatype), abi2mpi_message(message), status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Mrecv

subroutine MPIABI_Probe(source, tag, comm, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: source
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Probe(abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Probe

subroutine MPIABI_Recv(buf, count, datatype, source, tag, comm, status, ierror)
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
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Recv(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), wrap_status, &
       ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Recv

subroutine MPIABI_Recv_init(buf, count, datatype, source, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Recv_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(source), abi2mpi_tag(tag), abi2mpi_comm(comm), &
       wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Recv_init

subroutine MPIABI_Request_free(request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: request
  integer, intent(out) :: ierror
  integer wrap_request
  wrap_request = abi2mpi_request(request)
  call MPI_Request_free(wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Request_free

subroutine MPIABI_Request_get_status(request, flag, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: request
  logical, intent(out) :: flag
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Request_get_status(abi2mpi_request(request), flag, wrap_status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Request_get_status

subroutine MPIABI_Request_get_status_all(count, array_of_requests, flag, array_of_statuses, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: array_of_requests(count)
  logical, intent(out) :: flag
  integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, count)
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_array_of_requests(count)
  integer wrap_array_of_statuses(MPI_STATUS_SIZE, count)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  if (loc(array_of_statuses) == loc(MPIABI_STATUSES_IGNORE)) then
     call MPI_Request_get_status_all(count, wrap_array_of_requests, flag, MPI_STATUSES_IGNORE, ierror)
  else
     call MPI_Request_get_status_all(count, wrap_array_of_requests, flag, wrap_array_of_statuses, ierror)
     do n = 1, count
        call mpi2abi_status(wrap_array_of_statuses(:, n), array_of_statuses(:, n))
     end do
  end if
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Request_get_status_all

subroutine MPIABI_Request_get_status_any(count, array_of_requests, index, flag, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: array_of_requests(count)
  integer, intent(out) :: index
  logical, intent(out) :: flag
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_array_of_requests(count)
  integer wrap_status(MPI_STATUS_SIZE)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  call MPI_Request_get_status_any(count, wrap_array_of_requests, index, flag, wrap_status, ierror)
  call mpi2abi_status(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Request_get_status_any

subroutine MPIABI_Request_get_status_some(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: incount
  integer, intent(in) :: array_of_requests(incount)
  integer, intent(out) :: outcount
  integer, intent(out) :: array_of_indices(incount)
  integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, incount)
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_array_of_requests(incount)
  integer wrap_array_of_statuses(MPI_STATUS_SIZE, incount)
  integer n
  do n = 1, incount
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  call MPI_Request_get_status_some(incount, wrap_array_of_requests, outcount, array_of_indices, wrap_array_of_statuses, ierror)
  do n = 1, outcount
     call mpi2abi_status(wrap_array_of_statuses(:, n), array_of_statuses(:, n))
  end do
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Request_get_status_some

subroutine MPIABI_Rsend(buf, count, datatype, dest, tag, comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: buf(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call MPI_Rsend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rsend

subroutine MPIABI_Rsend_init(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Rsend_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), &
       wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Rsend_init

subroutine MPIABI_Send(buf, count, datatype, dest, tag, comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: buf(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call MPI_Send(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Send

subroutine MPIABI_Send_init(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Send_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), &
       wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Send_init

subroutine MPIABI_Sendrecv(sendbuf, sendcount, sendtype, dest, sendtag, recvbuf, recvcount, recvtype, source, recvtag, comm, &
     status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: sendbuf(*)
  integer, intent(in) :: sendcount
  integer, intent(in) :: sendtype
  integer, intent(in) :: dest
  integer, intent(in) :: sendtag
  integer, intent(out) :: recvbuf
  integer, intent(in) :: recvcount
  integer, intent(in) :: recvtype
  integer, intent(in) :: source
  integer, intent(in) :: recvtag
  integer, intent(in) :: comm
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Sendrecv(sendbuf, sendcount, abi2mpi_datatype(sendtype), abi2mpi_proc(dest), abi2mpi_tag(sendtag), recvbuf, recvcount, &
       abi2mpi_datatype(recvtype), abi2mpi_proc(source), abi2mpi_tag(recvtag), abi2mpi_comm(comm), wrap_status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Sendrecv

subroutine MPIABI_Sendrecv_replace(buf, count, datatype, dest, sendtag, source, recvtag, comm, status, ierror)
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
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Sendrecv_replace(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(sendtag), &
       abi2mpi_proc(source), abi2mpi_tag(recvtag), abi2mpi_comm(comm), wrap_status, ierror)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Sendrecv_replace

subroutine MPIABI_Session_attach_buffer(session, buffer, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: session
  integer, intent(in) :: buffer(*)
  integer, intent(in) :: size
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer(MPIABI_ADDRESS_KIND) buffer_addr
  integer(MPI_ADDRESS_KIND) wrap_buffer_addr
  integer wrap_buffer(*)
  pointer (wrap_buffer_addr, wrap_buffer)
  buffer_addr = loc(buffer)
  if (buffer_addr == loc(MPIABI_BUFFER_AUTOMATIC)) then
     wrap_buffer_addr = loc(MPI_BUFFER_AUTOMATIC)
  else
     wrap_buffer_addr = buffer_addr
  end if
  call MPI_Session_attach_buffer(abi2mpi_session(session), wrap_buffer, size, ierror)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Session_attach_buffer

subroutine MPIABI_Session_detach_buffer(session, buffer_addr, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: session
  integer(MPIABI_ADDRESS_KIND), intent(out) :: buffer_addr
  integer, intent(out) :: size
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer(MPI_ADDRESS_KIND) wrap_buffer_addr
  call MPI_Session_detach_buffer(abi2mpi_session(session), wrap_buffer_addr, size, ierror)
  if (wrap_buffer_addr == loc(MPI_BUFFER_AUTOMATIC)) then
     buffer_addr = loc(MPIABI_BUFFER_AUTOMATIC)
  else
     buffer_addr = wrap_buffer_addr
  end if
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Session_detach_buffer

subroutine MPIABI_Session_flush_buffer(session, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: session
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  call MPI_Session_flush_buffer(abi2mpi_session(session), ierror)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Session_flush_buffer

subroutine MPIABI_Session_iflush_buffer(session, request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: session
  integer, intent(out) :: request
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_request
  call MPI_Session_iflush_buffer(abi2mpi_session(session), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Session_iflush_buffer

subroutine MPIABI_Ssend(buf, count, datatype, dest, tag, comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: buf(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: dest
  integer, intent(in) :: tag
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call MPI_Ssend(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ssend

subroutine MPIABI_Ssend_init(buf, count, datatype, dest, tag, comm, request, ierror)
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
  integer wrap_request
  call MPI_Ssend_init(buf, count, abi2mpi_datatype(datatype), abi2mpi_proc(dest), abi2mpi_tag(tag), abi2mpi_comm(comm), &
       wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Ssend_init

subroutine MPIABI_Start(request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: request
  integer, intent(out) :: ierror
  call MPI_Start(abi2mpi_request(request), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Start

subroutine MPIABI_Startall(count, array_of_requests, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: array_of_requests(count)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(count)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  call MPI_Startall(count, wrap_array_of_requests, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Startall

subroutine MPIABI_Status_get_error(status, err, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: err
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_get_error(wrap_status, err, ierror)
  err = mpi2abi_errorcode(err)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Status_get_error

subroutine MPIABI_Status_get_source(status, source, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: source
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_get_source(wrap_status, source, ierror)
  source = mpi2abi_proc(source)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Status_get_source

subroutine MPIABI_Status_get_tag(status, tag, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: tag
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_get_tag(wrap_status, tag, ierror)
  tag = mpi2abi_proc(tag)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Status_get_tag

subroutine MPIABI_Test(request, flag, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: request
  logical, intent(out) :: flag
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_request
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_request = abi2mpi_request(request)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Test(wrap_request, flag, wrap_status, ierror)
  if (flag) then
     request = mpi2abi_request(wrap_request)
     call mpi2abi_status_ptr(wrap_status, status)
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Test

subroutine MPIABI_Test_cancelled(status, flag, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: status(MPIABI_STATUS_SIZE)
  logical, intent(out) :: flag
  integer, intent(out) :: ierror
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Test_cancelled(wrap_status, flag, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Test_cancelled

subroutine MPIABI_Testall(count, array_of_requests, flag, array_of_statuses, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(inout) :: array_of_requests(count)
  logical, intent(out) :: flag
  integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, count)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(count)
  integer wrap_array_of_statuses(MPI_STATUS_SIZE, count)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  if (loc(array_of_statuses) == loc(MPIABI_STATUSES_IGNORE)) then
     call MPI_Testall(count, wrap_array_of_requests, flag, MPI_STATUSES_IGNORE, ierror)
     if (flag) then
        array_of_requests = mpi2abi_request(wrap_array_of_requests)
     end if
  else
     call MPI_Testall(count, wrap_array_of_requests, flag, wrap_array_of_statuses, ierror)
     if (flag) then
        array_of_requests = mpi2abi_request(wrap_array_of_requests)
        do n = 1, count
           call mpi2abi_status(wrap_array_of_statuses(:, n), array_of_statuses(:, n))
        end do
     end if
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Testall

subroutine MPIABI_Testany(count, array_of_requests, index, flag, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(inout) :: array_of_requests(count)
  integer, intent(out) :: index
  logical, intent(out) :: flag
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(count)
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Testany(count, wrap_array_of_requests, index, flag, wrap_status, ierror)
  if (flag) then
     array_of_requests(index) = mpi2abi_request(wrap_array_of_requests(index))
     call mpi2abi_status_ptr(wrap_status, status)
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Testany

subroutine MPIABI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: incount
  integer, intent(inout) :: array_of_requests(incount)
  integer, intent(out) :: outcount
  integer, intent(out) :: array_of_indices(incount)
  integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, incount)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(incount)
  integer wrap_array_of_statuses(MPI_STATUS_SIZE, incount)
  integer n
  do n = 1, incount
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  if (loc(array_of_statuses) == loc(MPIABI_STATUSES_IGNORE)) then
     call MPI_Testsome(incount, wrap_array_of_requests, outcount, array_of_indices, MPI_STATUSES_IGNORE, ierror)
  else
     call MPI_Testsome(incount, wrap_array_of_requests, outcount, array_of_indices, wrap_array_of_statuses, ierror)
     do n = 1, outcount
        array_of_requests(array_of_indices(n)) = mpi2abi_request(wrap_array_of_requests(array_of_indices(n)))
        call mpi2abi_status(wrap_array_of_statuses(:, n), array_of_statuses(:, n))
     end do
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Testsome

subroutine MPIABI_Wait(request, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: request
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_request
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  wrap_request = abi2mpi_request(request)
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Wait(wrap_request, wrap_status, ierror)
  request = mpi2abi_request(wrap_request)
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Wait

subroutine MPIABI_Waitall(count, array_of_requests, array_of_statuses, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(inout) :: array_of_requests(count)
  integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, count)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(count)
  integer wrap_array_of_statuses(MPI_STATUS_SIZE, count)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  if (loc(array_of_statuses) == loc(MPIABI_STATUSES_IGNORE)) then
     call MPI_Waitall(count, wrap_array_of_requests, MPI_STATUSES_IGNORE, ierror)
     array_of_requests = mpi2abi_request(wrap_array_of_requests)
  else
     call MPI_Waitall(count, wrap_array_of_requests, wrap_array_of_statuses, ierror)
     array_of_requests = mpi2abi_request(wrap_array_of_requests)
     do n = 1, count
        call mpi2abi_status(wrap_array_of_statuses(:, n), array_of_statuses(:, n))
     end do
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Waitall

subroutine MPIABI_Waitany(count, array_of_requests, index, status, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(inout) :: array_of_requests(count)
  integer, intent(out) :: index
  integer, intent(out) :: status(MPIABI_STATUS_SIZE)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(count)
  integer wrap_status_storage(MPI_STATUS_SIZE)
  integer(MPIABI_ADDRESS_KIND) wrap_status_ptr
  integer wrap_status(MPI_STATUS_SIZE)
  pointer (wrap_status_ptr, wrap_status)
  integer n
  do n = 1, count
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  wrap_status_ptr = abi2mpi_status_ptr_uninitialized(status, wrap_status_storage)
  call MPI_Waitany(count, wrap_array_of_requests, index, wrap_status, ierror)
  array_of_requests(index) = mpi2abi_request(wrap_array_of_requests(index))
  call mpi2abi_status_ptr(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Waitany

subroutine MPIABI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: incount
  integer, intent(inout) :: array_of_requests(incount)
  integer, intent(out) :: outcount
  integer, intent(out) :: array_of_indices(incount)
  integer, intent(out) :: array_of_statuses(MPIABI_STATUS_SIZE, incount)
  integer, intent(out) :: ierror
  integer wrap_array_of_requests(incount)
  integer wrap_array_of_statuses(MPI_STATUS_SIZE, incount)
  integer n
  do n = 1, incount
     wrap_array_of_requests(n) = abi2mpi_request(array_of_requests(n))
  end do
  if (loc(array_of_statuses) == loc(MPIABI_STATUSES_IGNORE)) then
     call MPI_Waitsome(incount, wrap_array_of_requests, outcount, array_of_indices, MPI_STATUSES_IGNORE, ierror)
  else
     call MPI_Waitsome(incount, wrap_array_of_requests, outcount, array_of_indices, wrap_array_of_statuses, ierror)
     do n = 1, outcount
        array_of_requests(array_of_indices(n)) = mpi2abi_request(wrap_array_of_requests(array_of_indices(n)))
        call mpi2abi_status(wrap_array_of_statuses(:, n), array_of_statuses(:, n))
     end do
  end if
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Waitsome

! A.3.2 Partitioned Communication C Bindings
 
! subroutine MPIABI_Parrived(request, partition, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Parrived(request, partition, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Parrived
! 
! subroutine MPIABI_Pready(partition, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Pready(partition, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Pready
! 
! subroutine MPIABI_Pready_list(length, array_of_partitions, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Pready_list(length, array_of_partitions, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Pready_list
! 
! subroutine MPIABI_Pready_range(partition_low, partition_high, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Pready_range(partition_low, partition_high, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Pready_range
! 
! subroutine MPIABI_Precv_init(buf, partitions, count, datatype, source, tag, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Precv_init(buf, partitions, count, datatype, source, tag, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Precv_init
! 
! subroutine MPIABI_Psend_init(buf, partitions, count, datatype, dest, tag, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Psend_init(buf, partitions, count, datatype, dest, tag, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Psend_init

! A.3.3 Datatypes C Bindings

integer(MPIABI_ADDRESS_KIND) function MPIABI_Aint_add(base, disp)
  use mpiwrapper
  implicit none
  integer(MPIABI_ADDRESS_KIND), intent(in) :: base
  integer(MPIABI_ADDRESS_KIND), intent(in) :: disp
  ! This function is not defined by MPICH so we implement it ourselves
  MPIABI_Aint_add = base + disp
end function MPIABI_Aint_add

integer(MPIABI_ADDRESS_KIND) function MPIABI_Aint_diff(addr1, addr2)
  use mpiwrapper
  implicit none
  integer(MPIABI_ADDRESS_KIND), intent(in) :: addr1
  integer(MPIABI_ADDRESS_KIND), intent(in) :: addr2
  ! This function is not defined by MPICH so we implement it ourselves
  MPIABI_Aint_diff = addr1 - addr2
end function MPIABI_Aint_diff

subroutine MPIABI_Get_address(location, address, ierror)
  use mpiwrapper
  implicit none
  integer :: location(*)
  integer(MPIABI_ADDRESS_KIND), intent(out) :: address
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_address
  call MPI_Get_address(location, wrap_address, ierror)
  address = wrap_address
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_address

subroutine MPIABI_Get_elements(status, datatype, count, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: status(MPIABI_STATUS_SIZE)
  integer, intent(in) :: datatype
  integer, intent(out) :: count
  integer, intent(out) :: ierror
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Get_elements(wrap_status, abi2mpi_datatype(datatype), count, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Get_elements

subroutine MPIABI_Pack(inbuf, incount, datatype, outbuf, outsize, position, comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: inbuf(*)
  integer, intent(in) :: incount
  integer, intent(in) :: datatype
  integer outbuf(*)
  integer(MPIABI_ADDRESS_KIND), intent(in) :: outsize
  integer(MPIABI_ADDRESS_KIND), intent(inout) :: position
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_outsize
  integer(MPI_ADDRESS_KIND) wrap_position
  wrap_outsize = outsize
  wrap_position = position
  call MPI_Pack(inbuf, incount, abi2mpi_datatype(datatype), outbuf, wrap_outsize, wrap_position, abi2mpi_comm(comm), ierror)
  position = wrap_position
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack

subroutine MPIABI_Pack_external(datarep, inbuf, incount, datatype, outbuf, outsize, position, ierror)
  use mpiwrapper
  implicit none
  character(*), intent(in) :: datarep
  integer, intent(in) :: inbuf(*)
  integer, intent(in) :: incount
  integer, intent(in) :: datatype
  integer outbuf(*)
  integer(MPIABI_ADDRESS_KIND), intent(in) :: outsize
  integer(MPIABI_ADDRESS_KIND), intent(inout) :: position
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_outsize
  integer(MPI_ADDRESS_KIND) wrap_position
  wrap_outsize = outsize
  wrap_position = position
  call MPI_Pack_external(datarep, inbuf, incount, abi2mpi_datatype(datatype), outbuf, wrap_outsize, wrap_position, ierror)
  position = wrap_position
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack_external

subroutine MPIABI_Pack_external_size(datarep, incount, datatype, size, ierror)
  use mpiwrapper
  implicit none
  character(*), intent(in) :: datarep
  integer, intent(in) :: incount
  integer, intent(in) :: datatype
  integer(MPIABI_ADDRESS_KIND), intent(out) :: size
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_size
  call MPI_Pack_external_size(datarep, incount, abi2mpi_datatype(datatype), wrap_size, ierror)
  size = wrap_size
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack_external_size

subroutine MPIABI_Pack_size(incount, datatype, comm, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: incount
  integer, intent(in) :: datatype
  integer, intent(in) :: comm
  integer, intent(out) :: size
  integer, intent(out) :: ierror
  call MPI_Pack_size(incount, abi2mpi_datatype(datatype), abi2mpi_comm(comm), size, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Pack_size

subroutine MPIABI_Type_commit(datatype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: datatype
  integer, intent(out) :: ierror
  integer wrap_datatype
  wrap_datatype = abi2mpi_datatype(datatype)
  call MPI_Type_commit(wrap_datatype, ierror)
  datatype = mpi2abi_datatype(wrap_datatype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_commit

subroutine MPIABI_Type_contiguous(count, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_contiguous(count, abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_contiguous

subroutine MPIABI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, &
     order, oldtype, newtype, ierror)
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
  integer wrap_array_of_distribs(ndims)
  integer wrap_newtype
  integer n
  do n = 1, ndims
     wrap_array_of_distribs(n) = abi2mpi_distrib(array_of_distribs(n))
  end do
  call MPI_Type_create_darray(size, rank, ndims, array_of_gsizes, array_of_distribs, array_of_dargs, array_of_psizes, &
       abi2mpi_order(order), abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_darray

subroutine MPIABI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: array_of_blocklengths(count)
  integer, intent(in) :: array_of_displacements(count)
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_create_hindexed(count, array_of_blocklengths, array_of_displacements, abi2mpi_datatype(oldtype), wrap_newtype, &
       ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_hindexed

subroutine MPIABI_Type_create_hindexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) ::count
  integer, intent(in) ::blocklength
  integer, intent(in) ::array_of_displacements
  integer, intent(in) ::oldtype
  integer, intent(out) ::newtype
  integer, intent(out) ::ierror
  integer wrap_newtype
  call MPI_Type_create_hindexed_block(count, blocklength, array_of_displacements, abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_hindexed_block

subroutine MPIABI_Type_create_hvector(count, blocklength, stride, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: blocklength
  integer, intent(in) :: stride
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_create_hvector(count, blocklength, stride, abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_hvector

subroutine MPIABI_Type_create_indexed_block(count, blocklength, array_of_displacements, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: blocklength
  integer, intent(in) :: array_of_displacements
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_create_indexed_block(count, blocklength, array_of_displacements, abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_indexed_block

subroutine MPIABI_Type_create_resized(oldtype, lb, extent, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: oldtype
  integer(MPIABI_ADDRESS_KIND), intent(in) :: lb
  integer(MPIABI_ADDRESS_KIND), intent(in) :: extent
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_lb
  integer(MPI_ADDRESS_KIND) wrap_extent
  integer wrap_newtype
  wrap_lb = lb
  wrap_extent = extent
  call MPI_Type_create_resized(abi2mpi_datatype(oldtype), wrap_lb, wrap_extent, wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_resized

subroutine MPIABI_Type_create_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: array_of_blocklengths(count)
  integer(MPIABI_ADDRESS_KIND), intent(in) :: array_of_displacements(count)
  integer, intent(in) :: array_of_types(count)
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_array_of_displacements(count)
  integer wrap_array_of_types(count)
  integer wrap_newtype
  integer n
  do n = 1, count
     wrap_array_of_displacements(n) = array_of_displacements(n)
     wrap_array_of_types(n) = abi2mpi_datatype(array_of_types(n))
  end do
  call MPI_Type_create_struct(count, array_of_blocklengths, wrap_array_of_displacements, wrap_array_of_types, wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_struct

subroutine MPIABI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, order, oldtype, newtype, ierror)
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
  integer wrap_newtype
  call MPI_Type_create_subarray(ndims, array_of_sizes, array_of_subsizes, array_of_starts, abi2mpi_order(order), &
       abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_create_subarray

subroutine MPIABI_Type_dup(oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_dup(abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_dup

subroutine MPIABI_Type_free(datatype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: datatype
  integer, intent(out) :: ierror
  integer wrap_datatype
  wrap_datatype = abi2mpi_datatype(datatype)
  call MPI_Type_free(wrap_datatype, ierror)
  datatype = mpi2abi_datatype(wrap_datatype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_free

subroutine MPIABI_Type_get_contents(datatype, max_integers, max_addresses, max_datatypes, array_of_integers, array_of_addresses, &
     array_of_datatypes, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: datatype
  integer, intent(in) :: max_integers
  integer, intent(in) :: max_addresses
  integer, intent(in) :: max_datatypes
  integer, intent(out) :: array_of_integers(max_integers)
  integer(MPIABI_ADDRESS_KIND), intent(out) :: array_of_addresses(max_addresses)
  integer, intent(out) :: array_of_datatypes(max_datatypes)
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_array_of_addresses(max_addresses)
  integer wrap_array_of_datatypes(max_datatypes)
  integer n
  call MPI_Type_get_contents(abi2mpi_datatype(datatype), max_integers, max_addresses, max_datatypes, array_of_integers, &
       wrap_array_of_addresses, wrap_array_of_datatypes, ierror)
  do n = 1, max_addresses
     array_of_addresses(n) = wrap_array_of_addresses(n)
  end do
  do n = 1, max_datatypes
     array_of_datatypes(n) = abi2mpi_datatype(wrap_array_of_datatypes(n))
  end do
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_contents

subroutine MPIABI_Type_get_envelope(datatype, num_integers, num_addresses, num_datatypes, combiner, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: datatype
  integer, intent(out) :: num_integers
  integer, intent(out) :: num_addresses
  integer, intent(out) :: num_datatypes
  integer, intent(out) :: combiner
  integer, intent(out) :: ierror
  integer wrap_combiner
  call MPI_Type_get_envelope(abi2mpi_datatype(datatype), num_integers, num_addresses, num_datatypes, wrap_combiner, ierror)
  combiner = mpi2abi_combiner(wrap_combiner)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_envelope

subroutine MPIABI_Type_get_extent(datatype, lb, extent, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: datatype
  integer(MPIABI_ADDRESS_KIND), intent(out) :: lb
  integer(MPIABI_ADDRESS_KIND), intent(out) :: extent
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_lb
  integer(MPI_ADDRESS_KIND) wrap_extent
  call MPI_Type_get_extent(abi2mpi_datatype(datatype), wrap_lb, wrap_extent, ierror)
  lb = wrap_lb
  extent = wrap_extent
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_extent

subroutine MPIABI_Type_get_true_extent(datatype, true_lb, true_extent, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: datatype
  integer(MPIABI_ADDRESS_KIND), intent(out) :: true_lb
  integer(MPIABI_ADDRESS_KIND), intent(out) :: true_extent
  integer, intent(out) :: ierror
  integer(MPI_ADDRESS_KIND) wrap_true_lb
  integer(MPI_ADDRESS_KIND) wrap_true_extent
  call MPI_Type_get_true_extent(datatype, true_lb, true_extent, ierror)
  true_lb = wrap_true_lb
  true_extent = wrap_true_extent
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_get_true_extent

subroutine MPIABI_Type_indexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: array_of_blocklengths(count)
  integer, intent(in) :: array_of_displacements(count)
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_indexed(count, array_of_blocklengths, array_of_displacements, abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_indexed

subroutine MPIABI_Type_size(datatype, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: datatype
  integer, intent(out) :: size
  integer, intent(out) :: ierror
  call MPI_Type_size(abi2mpi_datatype(datatype), size, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_size

subroutine MPIABI_Type_vector(count, blocklength, stride, oldtype, newtype, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: count
  integer, intent(in) :: blocklength
  integer, intent(in) :: stride
  integer, intent(in) :: oldtype
  integer, intent(out) :: newtype
  integer, intent(out) :: ierror
  integer wrap_newtype
  call MPI_Type_vector(count, blocklength, stride, abi2mpi_datatype(oldtype), wrap_newtype, ierror)
  newtype = mpi2abi_datatype(wrap_newtype)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Type_vector

subroutine MPIABI_Unpack(inbuf, insize, position, outbuf, outcount, datatype, comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: inbuf(*)
  integer, intent(in) :: insize
  integer, intent(inout) :: position
  integer, intent(out) :: outbuf(*)
  integer, intent(in) :: outcount
  integer, intent(in) :: datatype
  integer, intent(in) :: comm
  integer, intent(out) :: ierror  
  call MPI_Unpack(inbuf, insize, position, outbuf, outcount, abi2mpi_datatype(datatype), abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Unpack

subroutine MPIABI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, datatype, ierror)
  use mpiwrapper
  implicit none
  character(*), intent(in) :: datarep
  integer, intent(in) :: inbuf
  integer, intent(in) :: insize
  integer, intent(inout) :: position
  integer, intent(out) :: outbuf
  integer, intent(in) :: outcount
  integer, intent(in) :: datatype
  integer, intent(out) :: ierror
  call MPI_Unpack_external(datarep, inbuf, insize, position, outbuf, outcount, abi2mpi_datatype(datatype), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Unpack_external
 
! A.3.4 Collective Communication C Bindings

subroutine MPIABI_Allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
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
  integer wrap_sendbuf(1)
  integer(MPI_ADDRESS_KIND) wrap_sendbuf_ptr
  wrap_sendbuf_ptr = abi2mpi_buffer_ptr(loc(sendbuf))
  call MPI_Allgather(wrap_sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount, abi2mpi_datatype(recvtype), &
       abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allgather

subroutine MPIABI_Allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
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
  integer wrap_sendbuf(1)
  integer(MPI_ADDRESS_KIND) wrap_sendbuf_ptr
  integer wrap_request
  wrap_sendbuf_ptr = abi2mpi_buffer_ptr(loc(sendbuf))
  call MPI_Allgather_init(wrap_sendbuf, sendcount, abi2mpi_datatype(sendtype), recvbuf, recvcount, abi2mpi_datatype(recvtype), &
       abi2mpi_comm(comm), abi2mpi_info(info), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Allgather_init

! subroutine MPIABI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allgatherv
! 
! subroutine MPIABI_Allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allgatherv_c
! 
! subroutine MPIABI_Allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allgatherv_init
! 
! subroutine MPIABI_Allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allgatherv_init_c
! 
! subroutine MPIABI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allreduce(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allreduce
! 
! subroutine MPIABI_Allreduce_c(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allreduce_c(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allreduce_c
! 
! subroutine MPIABI_Allreduce_init(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allreduce_init(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allreduce_init
! 
! subroutine MPIABI_Allreduce_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Allreduce_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Allreduce_init_c
! 
! subroutine MPIABI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoall
! 
! subroutine MPIABI_Alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoall_c
! 
! subroutine MPIABI_Alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoall_init
! 
! subroutine MPIABI_Alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoall_init_c
! 
! subroutine MPIABI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallv
! 
! subroutine MPIABI_Alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallv_c
! 
! subroutine MPIABI_Alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallv_init
! 
! subroutine MPIABI_Alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallv_init_c
! 
! subroutine MPIABI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallw
! 
! subroutine MPIABI_Alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallw_c
! 
! subroutine MPIABI_Alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallw_init
! 
! subroutine MPIABI_Alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alltoallw_init_c

subroutine MPIABI_Barrier(comm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call MPI_Barrier(abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Barrier

subroutine MPIABI_Barrier_init(comm, info, request, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(in) :: info
  integer, intent(out) :: request
  integer, intent(out) :: ierror
  integer wrap_request
  call MPI_Barrier_init(abi2mpi_comm(comm), abi2mpi_info(info), wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Barrier_init

subroutine MPIABI_Bcast(buffer, count, datatype, root, comm, ierror)
  use mpiwrapper
  implicit none
  integer buffer(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: root
  integer, intent(in) :: comm
  integer, intent(out) :: ierror
  call MPI_Bcast(buffer, count, abi2mpi_datatype(datatype), abi2mpi_root(root), abi2mpi_comm(comm), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bcast

subroutine MPIABI_Bcast_init(buffer, count, datatype, root, comm, info, request, ierror)
  use mpiwrapper
  implicit none
  integer buffer(*)
  integer, intent(in) :: count
  integer, intent(in) :: datatype
  integer, intent(in) :: root
  integer, intent(in) :: comm
  integer, intent(in) :: info
  integer, intent(out) :: request
  integer, intent(out) :: ierror
  integer wrap_request
  call MPI_Bcast_init(buffer, count, abi2mpi_datatype(datatype), abi2mpi_root(root), abi2mpi_comm(comm), abi2mpi_info(info), &
       wrap_request, ierror)
  request = mpi2abi_request(wrap_request)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Bcast_init

! subroutine MPIABI_Exscan(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Exscan(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Exscan
! 
! subroutine MPIABI_Exscan_c(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Exscan_c(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Exscan_c
! 
! subroutine MPIABI_Exscan_init(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Exscan_init(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Exscan_init
! 
! subroutine MPIABI_Exscan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Exscan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Exscan_init_c
! 
! subroutine MPIABI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gather
! 
! subroutine MPIABI_Gather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gather_c
! 
! subroutine MPIABI_Gather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gather_init
! 
! subroutine MPIABI_Gather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gather_init_c
! 
! subroutine MPIABI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gatherv
! 
! subroutine MPIABI_Gatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gatherv_c
! 
! subroutine MPIABI_Gatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gatherv_init
! 
! subroutine MPIABI_Gatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Gatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Gatherv_init_c
! 
! subroutine MPIABI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iallgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iallgather
! 
! subroutine MPIABI_Iallgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iallgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iallgather_c
! 
! subroutine MPIABI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iallgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iallgatherv
! 
! subroutine MPIABI_Iallgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iallgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iallgatherv_c
! 
! subroutine MPIABI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iallreduce(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iallreduce
! 
! subroutine MPIABI_Iallreduce_c(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iallreduce_c(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iallreduce_c
! 
! subroutine MPIABI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ialltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ialltoall
! 
! subroutine MPIABI_Ialltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ialltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ialltoall_c
! 
! subroutine MPIABI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ialltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ialltoallv
! 
! subroutine MPIABI_Ialltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ialltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ialltoallv_c
! 
! subroutine MPIABI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ialltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ialltoallw
! 
! subroutine MPIABI_Ialltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ialltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ialltoallw_c
! 
! subroutine MPIABI_Ibarrier(comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ibarrier(comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ibarrier
! 
! subroutine MPIABI_Ibcast(buffer, count, datatype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ibcast(buffer, count, datatype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ibcast
! 
! subroutine MPIABI_Ibcast_c(buffer, count, datatype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ibcast_c(buffer, count, datatype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ibcast_c
! 
! subroutine MPIABI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iexscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iexscan
! 
! subroutine MPIABI_Iexscan_c(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iexscan_c(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iexscan_c
! 
! subroutine MPIABI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Igather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Igather
! 
! subroutine MPIABI_Igather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Igather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Igather_c
! 
! subroutine MPIABI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Igatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Igatherv
! 
! subroutine MPIABI_Igatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Igatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Igatherv_c
! 
! subroutine MPIABI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ireduce(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ireduce
! 
! subroutine MPIABI_Ireduce_c(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ireduce_c(sendbuf, recvbuf, count, datatype, op, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ireduce_c
! 
! subroutine MPIABI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ireduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ireduce_scatter
! 
! subroutine MPIABI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ireduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ireduce_scatter_block
! 
! subroutine MPIABI_Ireduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ireduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ireduce_scatter_block_c
! 
! subroutine MPIABI_Ireduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ireduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ireduce_scatter_c
! 
! subroutine MPIABI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iscan(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iscan
! 
! subroutine MPIABI_Iscan_c(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iscan_c(sendbuf, recvbuf, count, datatype, op, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iscan_c
! 
! subroutine MPIABI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iscatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iscatter
! 
! subroutine MPIABI_Iscatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iscatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iscatter_c
! 
! subroutine MPIABI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iscatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iscatterv
! 
! subroutine MPIABI_Iscatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Iscatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Iscatterv_c
! 
! subroutine MPIABI_Op_commutative(op, commute, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Op_commutative(op, commute, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Op_commutative
! 
! subroutine MPIABI_Op_create(user_fn, commute, op, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Op_create(user_fn, commute, op, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Op_create
! 
! subroutine MPIABI_Op_create_c(user_fn, commute, op, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Op_create_c(user_fn, commute, op, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Op_create_c
! 
! subroutine MPIABI_Op_free(op, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Op_free(op, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Op_free
! 
! subroutine MPIABI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce
! 
! subroutine MPIABI_Reduce_c(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_c(sendbuf, recvbuf, count, datatype, op, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_c
! 
! subroutine MPIABI_Reduce_init(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_init(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_init
! 
! subroutine MPIABI_Reduce_init_c(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_init_c(sendbuf, recvbuf, count, datatype, op, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_init_c
! 
! subroutine MPIABI_Reduce_local(inbuf, inoutbuf, count, datatype, op, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_local(inbuf, inoutbuf, count, datatype, op, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_local
! 
! subroutine MPIABI_Reduce_local_c(inbuf, inoutbuf, count, datatype, op, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_local_c(inbuf, inoutbuf, count, datatype, op, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_local_c
! 
! subroutine MPIABI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter
! 
! subroutine MPIABI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_block(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_block
! 
! subroutine MPIABI_Reduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_block_c(sendbuf, recvbuf, recvcount, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_block_c
! 
! subroutine MPIABI_Reduce_scatter_block_init(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_block_init(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_block_init
! 
! subroutine MPIABI_Reduce_scatter_block_init_c(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_block_init_c(sendbuf, recvbuf, recvcount, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_block_init_c
! 
! subroutine MPIABI_Reduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_c
! 
! subroutine MPIABI_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_init(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_init
! 
! subroutine MPIABI_Reduce_scatter_init_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Reduce_scatter_init_c(sendbuf, recvbuf, recvcounts, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Reduce_scatter_init_c
! 
! subroutine MPIABI_Scan(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scan(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scan
! 
! subroutine MPIABI_Scan_c(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scan_c(sendbuf, recvbuf, count, datatype, op, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scan_c
! 
! subroutine MPIABI_Scan_init(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scan_init(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scan_init
! 
! subroutine MPIABI_Scan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scan_init_c(sendbuf, recvbuf, count, datatype, op, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scan_init_c
! 
! subroutine MPIABI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatter
! 
! subroutine MPIABI_Scatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatter_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatter_c
! 
! subroutine MPIABI_Scatter_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatter_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatter_init
! 
! subroutine MPIABI_Scatter_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatter_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatter_init_c
! 
! subroutine MPIABI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatterv(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatterv
! 
! subroutine MPIABI_Scatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatterv_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatterv_c
! 
! subroutine MPIABI_Scatterv_init(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatterv_init(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatterv_init
! 
! subroutine MPIABI_Scatterv_init_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Scatterv_init_c(sendbuf, sendcounts, displs, sendtype, recvbuf, recvcount, recvtype, root, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Scatterv_init_c
! 
! subroutine MPIABI_Type_get_value_index(value_type, index_type, pair_type, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_get_value_index(value_type, index_type, pair_type, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_get_value_index
! 
! ! A.3.5 Groups,  Contexts,  Communicators,  and Caching C Bindings
! 
! subroutine MPIABI_Comm_compare(comm1, comm2, result, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_compare(comm1, comm2, result, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_compare
! 
! subroutine MPIABI_Comm_create(comm, group, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_create(comm, group, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_create
! 
! subroutine MPIABI_Comm_create_from_group(group, stringtag, info, errhandler, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_create_from_group(group, stringtag, info, errhandler, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_create_from_group
! 
! subroutine MPIABI_Comm_create_group(comm, group, tag, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_create_group(comm, group, tag, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_create_group
! 
! subroutine MPIABI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_create_keyval(comm_copy_attr_fn, comm_delete_attr_fn, comm_keyval, extra_state, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_create_keyval
! 
! subroutine MPIABI_Comm_delete_attr(comm, comm_keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_delete_attr(comm, comm_keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_delete_attr
! 
! subroutine MPIABI_Comm_dup(comm, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_dup(comm, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_dup
! 
! subroutine MPIABI_Comm_dup_with_info(comm, info, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_dup_with_info(comm, info, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_dup_with_info
! 
! subroutine MPIABI_Comm_free(comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_free(comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_free
! 
! subroutine MPIABI_Comm_get_name(comm, comm_name, resultlen, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_get_name(comm, comm_name, resultlen, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_get_name
! 
! subroutine MPIABI_Comm_free_keyval(comm_keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_free_keyval(comm_keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_free_keyval
! 
! subroutine MPIABI_Comm_get_attr(comm, comm_keyval, attribute_val, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_get_attr(comm, comm_keyval, attribute_val, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_get_attr
! 
! subroutine MPIABI_Comm_get_info(comm, info_used, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_get_info(comm, info_used, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_get_info
! 
! subroutine MPIABI_Comm_group(comm, group, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_group(comm, group, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_group
! 
! subroutine MPIABI_Comm_idup(comm, newcomm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_idup(comm, newcomm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_idup
! 
! subroutine MPIABI_Comm_idup_with_info(comm, info, newcomm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_idup_with_info(comm, info, newcomm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_idup_with_info

subroutine MPIABI_Comm_rank(comm, rank, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(out) :: rank
  integer, intent(out) :: ierror
  integer wrap_comm
  wrap_comm = abi2mpi_comm(comm)
  call MPI_Comm_rank(wrap_comm, rank, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_rank

! subroutine MPIABI_Comm_remote_group(comm, group, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_remote_group(comm, group, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_remote_group
! 
! subroutine MPIABI_Comm_remote_size(comm, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_remote_size(comm, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_remote_size
! 
! subroutine MPIABI_Comm_set_attr(comm, comm_keyval, attribute_val, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_set_attr(comm, comm_keyval, attribute_val, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_set_attr
! 
! subroutine MPIABI_Comm_set_info(comm, info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_set_info(comm, info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_set_info
! 
! subroutine MPIABI_Comm_set_name(comm, comm_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_set_name(comm, comm_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_set_name

subroutine MPIABI_Comm_size(comm, size, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(out) :: size
  integer, intent(out) :: ierror
  integer wrap_comm
  wrap_comm = abi2mpi_comm(comm)
  call MPI_Comm_size(wrap_comm, size, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_size

subroutine MPIABI_Comm_split(comm, color, key, newcomm, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(in) :: color
  integer, intent(in) :: key
  integer, intent(out) :: newcomm
  integer, intent(out) :: ierror
  integer wrap_newcomm
  call MPI_Comm_split(abi2mpi_comm(comm), color, key, wrap_newcomm, ierror)
  newcomm = mpi2abi_comm(wrap_newcomm)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Comm_split

! subroutine MPIABI_Group_free(group, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_free(group, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_free
! 
! subroutine MPIABI_Comm_split_type(comm, split_type, key, info, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_split_type(comm, split_type, key, info, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_split_type
! 
! subroutine MPIABI_Comm_test_inter(comm, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_test_inter(comm, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_test_inter
! 
! subroutine MPIABI_Group_compare(group1, group2, result, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_compare(group1, group2, result, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_compare
! 
! subroutine MPIABI_Group_difference(group1, group2, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_difference(group1, group2, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_difference
! 
! subroutine MPIABI_Group_excl(group, n, ranks, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_excl(group, n, ranks, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_excl
! 
! subroutine MPIABI_Group_from_session_pset(session, pset_name, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_from_session_pset(session, pset_name, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_from_session_pset
! 
! subroutine MPIABI_Group_incl(group, n, ranks, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_incl(group, n, ranks, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_incl
! 
! subroutine MPIABI_Group_intersection(group1, group2, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_intersection(group1, group2, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_intersection
! 
! subroutine MPIABI_Group_range_excl(group, n, ranges, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_range_excl(group, n, ranges, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_range_excl
! 
! subroutine MPIABI_Group_range_incl(group, n, ranges, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_range_incl(group, n, ranges, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_range_incl
! 
! subroutine MPIABI_Group_rank(group, rank, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_rank(group, rank, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_rank
! 
! subroutine MPIABI_Group_size(group, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_size(group, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_size
! 
! subroutine MPIABI_Group_translate_ranks(group1, n, ranks1, group2, ranks2, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_translate_ranks(group1, n, ranks1, group2, ranks2, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_translate_ranks
! 
! subroutine MPIABI_Group_union(group1, group2, newgroup, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Group_union(group1, group2, newgroup, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Group_union
! 
! subroutine MPIABI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Intercomm_create
! 
! subroutine MPIABI_Intercomm_create_from_groups(local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler, newintercomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Intercomm_create_from_groups(local_group, local_leader, remote_group, remote_leader, stringtag, info, errhandler, newintercomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Intercomm_create_from_groups
! 
! subroutine MPIABI_Intercomm_merge(intercomm, high, newintracomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Intercomm_merge(intercomm, high, newintracomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Intercomm_merge
! 
! subroutine MPIABI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_create_keyval(type_copy_attr_fn, type_delete_attr_fn, type_keyval, extra_state, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_create_keyval
! 
! subroutine MPIABI_Type_delete_attr(datatype, type_keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_delete_attr(datatype, type_keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_delete_attr
! 
! subroutine MPIABI_Type_free_keyval(type_keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_free_keyval(type_keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_free_keyval
! 
! subroutine MPIABI_Type_get_attr(datatype, type_keyval, attribute_val, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_get_attr(datatype, type_keyval, attribute_val, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_get_attr
! 
! subroutine MPIABI_Type_get_name(datatype, type_name, resultlen, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_get_name(datatype, type_name, resultlen, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_get_name
! 
! subroutine MPIABI_Type_set_attr(datatype, type_keyval, attribute_val, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_set_attr(datatype, type_keyval, attribute_val, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_set_attr
! 
! subroutine MPIABI_Type_set_name(datatype, type_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_set_name(datatype, type_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_set_name
! 
! subroutine MPIABI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_create_keyval(win_copy_attr_fn, win_delete_attr_fn, win_keyval, extra_state, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_create_keyval
! 
! subroutine MPIABI_Win_delete_attr(win, win_keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_delete_attr(win, win_keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_delete_attr
! 
! subroutine MPIABI_Win_free_keyval(win_keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_free_keyval(win_keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_free_keyval
! 
! subroutine MPIABI_Win_get_attr(win, win_keyval, attribute_val, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_get_attr(win, win_keyval, attribute_val, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_get_attr
! 
! subroutine MPIABI_Win_get_name(win, win_name, resultlen, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_get_name(win, win_name, resultlen, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_get_name
! 
! subroutine MPIABI_Win_set_attr(win, win_keyval, attribute_val, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_set_attr(win, win_keyval, attribute_val, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_set_attr
! 
! subroutine MPIABI_Win_set_name(win, win_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_set_name(win, win_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_set_name
! 
! ! A.3.6 Virtual Topologies for MPI Processes C Bindings
! 
! subroutine MPIABI_Cart_coords(comm, rank, maxdims, coords, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_coords(comm, rank, maxdims, coords, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_coords
! 
! subroutine MPIABI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_create
! 
! subroutine MPIABI_Cart_get(comm, maxdims, dims, periods, coords, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_get(comm, maxdims, dims, periods, coords, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_get
! 
! subroutine MPIABI_Cart_map(comm, ndims, dims, periods, newrank, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_map(comm, ndims, dims, periods, newrank, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_map
! 
! subroutine MPIABI_Cart_rank(comm, coords, rank, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_rank(comm, coords, rank, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_rank
! 
! subroutine MPIABI_Cart_shift(comm, direction, disp, rank_source, rank_dest, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_shift(comm, direction, disp, rank_source, rank_dest, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_shift
! 
! subroutine MPIABI_Cart_sub(comm, remain_dims, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cart_sub(comm, remain_dims, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cart_Sub
! 
! subroutine MPIABI_Cartdim_get(comm, ndims, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Cartdim_get(comm, ndims, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Cartdim_get
! 
! subroutine MPIABI_Dims_create(nnodes, ndims, dims, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Dims_create(nnodes, ndims, dims, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Dims_create
! 
! subroutine MPIABI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Dist_graph_create(comm_old, n, sources, degrees, destinations, weights, info, reorder, comm_dist_graph, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Dist_graph_create
! 
! subroutine MPIABI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Dist_graph_create_adjacent(comm_old, indegree, sources, sourceweights, outdegree, destinations, destweights, info, reorder, comm_dist_graph, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Dist_graph_create_adjacent
! 
! subroutine MPIABI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Dist_graph_neighbors(comm, maxindegree, sources, sourceweights, maxoutdegree, destinations, destweights, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Dist_graph_neighbors
! 
! subroutine MPIABI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Dist_graph_neighbors_count(comm, indegree, outdegree, weighted, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Dist_graph_neighbors_count
! 
! subroutine MPIABI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Graph_create(comm_old, nnodes, index, edges, reorder, comm_graph, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Graph_create
! 
! subroutine MPIABI_Graph_get(comm, maxindex, maxedges, index, edges, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Graph_get(comm, maxindex, maxedges, index, edges, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Graph_get
! 
! subroutine MPIABI_Graph_map(comm, nnodes, index, edges, newrank, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Graph_map(comm, nnodes, index, edges, newrank, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Graph_map
! 
! subroutine MPIABI_Graph_neighbors(comm, rank, maxneighbors, neighbors, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Graph_neighbors(comm, rank, maxneighbors, neighbors, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Graph_neighbors
! 
! subroutine MPIABI_Graph_neighbors_count(comm, rank, nneighbors, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Graph_neighbors_count(comm, rank, nneighbors, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Graph_neighbors_count
! 
! subroutine MPIABI_Graphdims_get(comm, nnodes, nedges, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Graphdims_get(comm, nnodes, nedges, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Graphdims_get
! 
! subroutine MPIABI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_allgather
! 
! subroutine MPIABI_Ineighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_allgather_c
! 
! subroutine MPIABI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_allgatherv
! 
! subroutine MPIABI_Ineighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_allgatherv_c
! 
! subroutine MPIABI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_alltoall
! 
! subroutine MPIABI_Ineighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_alltoall_c
! 
! subroutine MPIABI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_alltoallv
! 
! subroutine MPIABI_Ineighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_alltoallv_c
! 
! subroutine MPIABI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_alltoallw
! 
! subroutine MPIABI_Ineighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Ineighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Ineighbor_alltoallw_c
! 
! subroutine MPIABI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgather
! 
! subroutine MPIABI_Neighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgather_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgather_c
! 
! subroutine MPIABI_Neighbor_allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgather_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgather_init
! 
! subroutine MPIABI_Neighbor_allgather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgather_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgather_init_c
! 
! subroutine MPIABI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgatherv(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgatherv
! 
! subroutine MPIABI_Neighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgatherv_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgatherv_c
! 
! subroutine MPIABI_Neighbor_allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgatherv_init(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgatherv_init
! 
! subroutine MPIABI_Neighbor_allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_allgatherv_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcounts, displs, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_allgatherv_init_c
! 
! subroutine MPIABI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoall(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoall
! 
! subroutine MPIABI_Neighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoall_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoall_c
! 
! subroutine MPIABI_Neighbor_alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoall_init(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoall_init
! 
! subroutine MPIABI_Neighbor_alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoall_init_c(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoall_init_c
! 
! subroutine MPIABI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallv
! 
! subroutine MPIABI_Neighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallv_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallv_c
! 
! subroutine MPIABI_Neighbor_alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallv_init(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallv_init
! 
! subroutine MPIABI_Neighbor_alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallv_init_c(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls, recvtype, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallv_init_c
! 
! subroutine MPIABI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallw(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallw
! 
! subroutine MPIABI_Neighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallw_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallw_c
! 
! subroutine MPIABI_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallw_init(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallw_init
! 
! subroutine MPIABI_Neighbor_alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Neighbor_alltoallw_init_c(sendbuf, sendcounts, sdispls, sendtypes, recvbuf, recvcounts, rdispls, recvtypes, comm, info, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Neighbor_alltoallw_init_c
! 
! subroutine MPIABI_Topo_test(comm, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Topo_test(comm, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Topo_test
! 
! ! A.3.7 MPI Environmental Management C Bindings
! 
! subroutine MPIABI_Add_error_class(errorclass, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Add_error_class(errorclass, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Add_error_class
! 
! subroutine MPIABI_Add_error_code(errorclass, errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Add_error_code(errorclass, errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Add_error_code
! 
! subroutine MPIABI_Add_error_string(errorcode, string, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Add_error_string(errorcode, string, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Add_error_string
! 
! subroutine MPIABI_Alloc_mem(size, info, baseptr, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Alloc_mem(size, info, baseptr, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Alloc_mem
! 
! subroutine MPIABI_Comm_call_errhandler(comm, errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_call_errhandler(comm, errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_call_errhandler
! 
! subroutine MPIABI_Comm_create_errhandler(comm_errhandler_fn, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_create_errhandler(comm_errhandler_fn, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_create_errhandler
! 
! subroutine MPIABI_Comm_get_errhandler(comm, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_get_errhandler(comm, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_get_errhandler
! 
! subroutine MPIABI_Comm_set_errhandler(comm, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_set_errhandler(comm, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_set_errhandler
! 
! subroutine MPIABI_Errhandler_free(errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Errhandler_free(errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Errhandler_free
! 
! subroutine MPIABI_Error_class(errorcode, errorclass, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Error_class(errorcode, errorclass, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Error_class
! 
! subroutine MPIABI_Error_string(errorcode, string, resultlen, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Error_string(errorcode, string, resultlen, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Error_string
! 
! subroutine MPIABI_File_call_errhandler(fh, errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_call_errhandler(fh, errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_call_errhandler
! 
! subroutine MPIABI_File_create_errhandler(file_errhandler_fn, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_create_errhandler(file_errhandler_fn, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_create_errhandler
! 
! subroutine MPIABI_File_get_errhandler(file, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_errhandler(file, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_errhandler
! 
! subroutine MPIABI_File_set_errhandler(file, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_set_errhandler(file, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_set_errhandler
! 
! subroutine MPIABI_Free_mem(base, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Free_mem(base, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Free_mem
! 
! subroutine MPIABI_Get_hw_resource_info(hw_info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_hw_resource_info(hw_info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_hw_resource_info
! 
! subroutine MPIABI_Get_library_version(version, resultlen, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_library_version(version, resultlen, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_library_version
! 
! subroutine MPIABI_Get_processor_name(name, resultlen, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_processor_name(name, resultlen, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_processor_name
! 
! subroutine MPIABI_Get_version(version, subversion, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_version(version, subversion, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_version
! 
! subroutine MPIABI_Remove_error_class(errorclass, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Remove_error_class(errorclass, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Remove_error_class
! 
! subroutine MPIABI_Remove_error_code(errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Remove_error_code(errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Remove_error_code
! 
! subroutine MPIABI_Remove_error_string(errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Remove_error_string(errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Remove_error_string
! 
! subroutine MPIABI_Session_call_errhandler(session, errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_call_errhandler(session, errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_call_errhandler
! 
! subroutine MPIABI_Session_create_errhandler(session_errhandler_fn, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_create_errhandler(session_errhandler_fn, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_create_errhandler
! 
! subroutine MPIABI_Session_get_errhandler(session, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_get_errhandler(session, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_get_errhandler
! 
! subroutine MPIABI_Session_set_errhandler(session, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_set_errhandler(session, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_set_errhandler
! 
! subroutine MPIABI_Win_call_errhandler(win, errorcode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_call_errhandler(win, errorcode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_call_errhandler
! 
! subroutine MPIABI_Win_create_errhandler(win_errhandler_fn, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_create_errhandler(win_errhandler_fn, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_create_errhandler
! 
! subroutine MPIABI_Win_get_errhandler(win, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_get_errhandler(win, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_get_errhandler
! 
! subroutine MPIABI_Win_set_errhandler(win, errhandler, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_set_errhandler(win, errhandler, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_set_errhandler

double precision function MPIABI_Wtick()
  use mpiwrapper
  implicit none
  MPIABI_Wtick = MPI_Wtick()
end function MPIABI_Wtick

double precision function MPIABI_Wtime()
  use mpiwrapper
  implicit none
  MPIABI_Wtime = MPI_Wtime()
end function MPIABI_Wtime

! A.3.8 The Info Object C Bindings

! subroutine MPIABI_Info_create(info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_create(info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_create
! 
! subroutine MPIABI_Info_create_env(argc, argv, info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_create_env(argc, argv, info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_create_env
! 
! subroutine MPIABI_Info_delete(info, key, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_delete(info, key, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_delete
! 
! subroutine MPIABI_Info_dup(info, newinfo, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_dup(info, newinfo, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_dup
! 
! subroutine MPIABI_Info_free(info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_free(info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_free
! 
! subroutine MPIABI_Info_get_nkeys(info, nkeys, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_get_nkeys(info, nkeys, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_get_nkeys
! 
! subroutine MPIABI_Info_get_nthkey(info, n, key, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_get_nthkey(info, n, key, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_get_nthkey
! 
! subroutine MPIABI_Info_get_string(info, key, buflen, value, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_get_string(info, key, buflen, value, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_get_string
! 
! subroutine MPIABI_Info_set(info, key, value, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_set(info, key, value, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_set

! A.3.9 Process Creation and Management C Bindings

subroutine MPIABI_Abort(comm, errorcode, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: comm
  integer, intent(in) :: errorcode
  integer, intent(out) :: ierror
  call MPI_Abort(abi2mpi_comm(comm), errorcode, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Abort

! subroutine MPIABI_Close_port(port_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Close_port(port_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Close_port
! 
! subroutine MPIABI_Comm_accept(port_name, info, root, comm, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_accept(port_name, info, root, comm, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_accept
! 
! subroutine MPIABI_Comm_connect(port_name, info, root, comm, newcomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_connect(port_name, info, root, comm, newcomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_connect
! 
! subroutine MPIABI_Comm_disconnect(comm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_disconnect(comm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_disconnect
! 
! subroutine MPIABI_Comm_get_parent(parent, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_get_parent(parent, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_get_parent
! 
! subroutine MPIABI_Comm_join(fd, intercomm, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_join(fd, intercomm, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_join
! 
! subroutine MPIABI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_spawn
! 
! subroutine MPIABI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Comm_spawn_multiple

subroutine MPIABI_Finalize(ierror)
  use mpiwrapper
  implicit none
  integer, intent(out) :: ierror
  call MPI_Finalize(ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Finalize

subroutine MPIABI_Finalized(flag, ierror)
  use mpiwrapper
  implicit none
  logical, intent(out) :: flag
  integer, intent(out) :: ierror
  call MPI_Finalized(flag, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Finalized

subroutine MPIABI_Init(ierror)
  use mpiwrapper
  implicit none
  integer, intent(out) :: ierror
  call MPI_Init(ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Init

subroutine MPIABI_Init_thread(required, provided, ierror)
  use mpiwrapper
  implicit none
  integer, intent(in) :: required
  integer, intent(out) :: provided
  integer, intent(out) :: ierror
  call MPI_Init_thread(abi2mpi_threadlevel(required), abi2mpi_threadlevel(provided), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Init_thread

subroutine MPIABI_Initialized(flag, ierror)
  use mpiwrapper
  implicit none
  logical, intent(out) :: flag
  integer, intent(out) :: ierror
  call MPI_Initialized(flag, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Initialized

subroutine MPIABI_Is_thread_main(flag, ierror)
  use mpiwrapper
  implicit none
  logical, intent(out) :: flag
  integer, intent(out) :: ierror
  call MPI_Is_thread_main(flag, ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Is_thread_main

! subroutine MPIABI_Lookup_name(service_name, info, port_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Lookup_name(service_name, info, port_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Lookup_name
! 
! subroutine MPIABI_Open_port(info, port_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Open_port(info, port_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Open_port
! 
! subroutine MPIABI_Publish_name(service_name, info, port_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Publish_name(service_name, info, port_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Publish_name

subroutine MPIABI_Query_thread(provided, ierror)
  use mpiwrapper
  implicit none
  integer, intent(out) :: provided
  integer, intent(out) :: ierror
  integer wrap_provided
  call MPI_Query_thread(wrap_provided, ierror)
  provided = mpi2abi_threadlevel(wrap_provided)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Query_thread

! subroutine MPIABI_Session_finalize(session, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_finalize(session, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_finalize
! 
! subroutine MPIABI_Session_get_info(session, info_used, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_get_info(session, info_used, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_get_info
! 
! subroutine MPIABI_Session_get_nth_pset(session, info, n, pset_len, pset_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_get_nth_pset(session, info, n, pset_len, pset_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_get_nth_pset
! 
! subroutine MPIABI_Session_get_num_psets(session, info, npset_names, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_get_num_psets(session, info, npset_names, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_get_num_psets
! 
! subroutine MPIABI_Session_get_pset_info(session, pset_name, info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_get_pset_info(session, pset_name, info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_get_pset_info
! 
! subroutine MPIABI_Session_init(info, errhandler, session, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Session_init(info, errhandler, session, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Session_init
! 
! subroutine MPIABI_Unpublish_name(service_name, info, port_name, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Unpublish_name(service_name, info, port_name, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Unpublish_name
! 
! ! A.3.10 One-Sided Communications C Bindings
! 
! subroutine MPIABI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Accumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Accumulate
! 
! subroutine MPIABI_Accumulate_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Accumulate_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Accumulate_c
! 
! subroutine MPIABI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Compare_and_swap(origin_addr, compare_addr, result_addr, datatype, target_rank, target_disp, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Compare_and_swap
! 
! subroutine MPIABI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Fetch_and_op(origin_addr, result_addr, datatype, target_rank, target_disp, op, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Fetch_and_op
! 
! subroutine MPIABI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Get(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get
! 
! subroutine MPIABI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_accumulate
! 
! subroutine MPIABI_Get_accumulate_c(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_accumulate_c(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_accumulate_c
! 
! subroutine MPIABI_Get_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_c
! 
! subroutine MPIABI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Put(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Put
! 
! subroutine MPIABI_Put_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Put_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Put_c
! 
! subroutine MPIABI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Raccumulate(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Raccumulate
! 
! subroutine MPIABI_Raccumulate_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Raccumulate_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Raccumulate_c
! 
! subroutine MPIABI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Rget(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Rget
! 
! subroutine MPIABI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Rget_accumulate(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Rget_accumulate
! 
! subroutine MPIABI_Rget_accumulate_c(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Rget_accumulate_c(origin_addr, origin_count, origin_datatype, result_addr, result_count, result_datatype, target_rank, target_disp, target_count, target_datatype, op, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Rget_accumulate_c
! 
! subroutine MPIABI_Rget_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Rget_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Rget_c
! 
! subroutine MPIABI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Rput(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Rput
! 
! subroutine MPIABI_Rput_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Rput_c(origin_addr, origin_count, origin_datatype, target_rank, target_disp, target_count, target_datatype, win, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Rput_c
! 
! subroutine MPIABI_Win_allocate(size, disp_unit, info, comm, baseptr, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_allocate(size, disp_unit, info, comm, baseptr, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_allocate
! 
! subroutine MPIABI_Win_allocate_c(size, disp_unit, info, comm, baseptr, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_allocate_c(size, disp_unit, info, comm, baseptr, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_allocate_c
! 
! subroutine MPIABI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_allocate_shared(size, disp_unit, info, comm, baseptr, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_allocate_shared
! 
! subroutine MPIABI_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_allocate_shared_c(size, disp_unit, info, comm, baseptr, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_allocate_shared_c
! 
! subroutine MPIABI_Win_attach(win, base, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_attach(win, base, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_attach
! 
! subroutine MPIABI_Win_complete(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_complete(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_complete
! 
! subroutine MPIABI_Win_create(base, size, disp_unit, info, comm, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_create(base, size, disp_unit, info, comm, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_create
! 
! subroutine MPIABI_Win_create_c(base, size, disp_unit, info, comm, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_create_c(base, size, disp_unit, info, comm, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_create_c
! 
! subroutine MPIABI_Win_create_dynamic(info, comm, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_create_dynamic(info, comm, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_create_dynamic
! 
! subroutine MPIABI_Win_detach(win, base, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_detach(win, base, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_detach
! 
! subroutine MPIABI_Win_fence(assert, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_fence(assert, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_fence
! 
! subroutine MPIABI_Win_flush(rank, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_flush(rank, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_flush
! 
! subroutine MPIABI_Win_flush_all(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_flush_all(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_flush_all
! 
! subroutine MPIABI_Win_flush_local(rank, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_flush_local(rank, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_flush_local
! 
! subroutine MPIABI_Win_flush_local_all(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_flush_local_all(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_flush_local_all
! 
! subroutine MPIABI_Win_free(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_free(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_free
! 
! subroutine MPIABI_Win_get_group(win, group, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_get_group(win, group, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_get_group
! 
! subroutine MPIABI_Win_get_info(win, info_used, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_get_info(win, info_used, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_get_info
! 
! subroutine MPIABI_Win_lock(lock_type, rank, assert, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_lock(lock_type, rank, assert, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_lock
! 
! subroutine MPIABI_Win_lock_all(assert, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_lock_all(assert, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_lock_all
! 
! subroutine MPIABI_Win_post(group, assert, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_post(group, assert, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_post
! 
! subroutine MPIABI_Win_set_info(win, info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_set_info(win, info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_set_info
! 
! subroutine MPIABI_Win_shared_query(win, rank, size, disp_unit, baseptr, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_shared_query(win, rank, size, disp_unit, baseptr, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_shared_query
! 
! subroutine MPIABI_Win_shared_query_c(win, rank, size, disp_unit, baseptr, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_shared_query_c(win, rank, size, disp_unit, baseptr, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_shared_query_c
! 
! subroutine MPIABI_Win_start(group, assert, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_start(group, assert, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_start
! 
! subroutine MPIABI_Win_sync(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_sync(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_sync
! 
! subroutine MPIABI_Win_test(win, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_test(win, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_test
! 
! subroutine MPIABI_Win_unlock(rank, win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_unlock(rank, win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_unlock
! 
! subroutine MPIABI_Win_unlock_all(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_unlock_all(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_unlock_all
! 
! subroutine MPIABI_Win_wait(win)
!   use mpiwrapper
!   implicit none
!   call MPI_Win_wait(win)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Win_wait
! 
! ! A.3.11 External Interfaces C Bindings
! 
! subroutine MPIABI_Grequest_complete(request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Grequest_complete(request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Grequest_complete
! 
! subroutine MPIABI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Grequest_start(query_fn, free_fn, cancel_fn, extra_state, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Grequest_start

subroutine MPIABI_Status_set_cancelled(status, flag, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: status(MPIABI_STATUS_SIZE)
  logical, intent(in) :: flag
  integer, intent(out) :: ierror
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_set_cancelled(wrap_status, flag, ierror)
  call mpi2abi_status(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Status_set_cancelled

subroutine MPIABI_Status_set_elements(status, datatype, count, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: status(MPIABI_STATUS_SIZE)
  integer, intent(in) :: datatype
  integer, intent(in) :: count
  integer, intent(out) :: ierror
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_set_elements(wrap_status, abi2mpi_datatype(datatype), count, ierror)
  call mpi2abi_status(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_Status_set_elements

subroutine MPIABI_Status_set_error(status, err, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: status(MPIABI_STATUS_SIZE)
  integer, intent(in) :: err
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_set_error(wrap_status, abi2mpi_errorcode(err), ierror)
  call mpi2abi_status(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Status_set_error

subroutine MPIABI_Status_set_source(status, source, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: status(MPIABI_STATUS_SIZE)
  integer, intent(in) :: source
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_set_source(wrap_status, abi2mpi_proc(source), ierror)
  call mpi2abi_status(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Status_set_source

subroutine MPIABI_Status_set_tag(status, tag, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: status(MPIABI_STATUS_SIZE)
  integer, intent(in) :: tag
  integer, intent(out) :: ierror
#if MPI_VERSION_NUMBER >= 410
  integer wrap_status(MPI_STATUS_SIZE)
  call abi2mpi_status(status, wrap_status)
  call MPI_Status_set_tag(wrap_status, abi2mpi_tag(tag), ierror)
  call mpi2abi_status(wrap_status, status)
  ierror = mpi2abi_errorcode(ierror)
#else
  call assert(.false.)
#endif
end subroutine MPIABI_Status_set_tag

! A.3.12 I/O C Bindings

subroutine MPIABI_File_close(fh, ierror)
  use mpiwrapper
  implicit none
  integer, intent(inout) :: fh
  integer, intent(out) :: ierror
  integer wrap_fh
  wrap_fh = abi2mpi_file(fh)
  call MPI_File_close(wrap_fh, ierror)
  fh = mpi2abi_file(wrap_fh)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_close

subroutine MPIABI_File_delete(filename, info, ierror)
  use mpiwrapper
  implicit none
  character(*), intent(in) :: filename
  integer, intent(in) :: info
  integer, intent(out) :: ierror
  call MPI_File_delete(filename, abi2mpi_info(info), ierror)
  ierror = mpi2abi_errorcode(ierror)
end subroutine MPIABI_File_delete

! subroutine MPIABI_File_get_amode(fh, amode, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_amode(fh, amode, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_amode
! 
! subroutine MPIABI_File_get_atomicity(fh, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_atomicity(fh, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_atomicity
! 
! subroutine MPIABI_File_get_byte_offset(fh, offset, disp, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_byte_offset(fh, offset, disp, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_byte_offset
! 
! subroutine MPIABI_File_get_group(fh, group, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_group(fh, group, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_group
! 
! subroutine MPIABI_File_get_info(fh, info_used, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_info(fh, info_used, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_info
! 
! subroutine MPIABI_File_get_position(fh, offset, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_position(fh, offset, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_position
! 
! subroutine MPIABI_File_get_position_shared(fh, offset, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_position_shared(fh, offset, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_position_shared
! 
! subroutine MPIABI_File_get_size(fh, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_size(fh, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_size
! 
! subroutine MPIABI_File_get_type_extent(fh, datatype, extent, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_type_extent(fh, datatype, extent, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_type_extent
! 
! subroutine MPIABI_File_get_type_extent_c(fh, datatype, extent, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_type_extent_c(fh, datatype, extent, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_type_extent_c
! 
! subroutine MPIABI_File_get_view(fh, disp, etype, filetype, datarep, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_get_view(fh, disp, etype, filetype, datarep, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_get_view
! 
! subroutine MPIABI_File_iread(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread
! 
! subroutine MPIABI_File_iread_all(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_all(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_all
! 
! subroutine MPIABI_File_iread_all_c(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_all_c(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_all_c
! 
! subroutine MPIABI_File_iread_at(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_at(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_at
! 
! subroutine MPIABI_File_iread_at_all(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_at_all(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_at_all
! 
! subroutine MPIABI_File_iread_at_all_c(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_at_all_c(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_at_all_c
! 
! subroutine MPIABI_File_iread_at_c(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_at_c(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_at_c
! 
! subroutine MPIABI_File_iread_c(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_c(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_c
! 
! subroutine MPIABI_File_iread_shared(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_shared(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_shared
! 
! subroutine MPIABI_File_iread_shared_c(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iread_shared_c(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iread_shared_c
! 
! subroutine MPIABI_File_iwrite(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite
! 
! subroutine MPIABI_File_iwrite_all(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_all(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_all
! 
! subroutine MPIABI_File_iwrite_all_c(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_all_c(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_all_c
! 
! subroutine MPIABI_File_iwrite_at(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_at(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_at
! 
! subroutine MPIABI_File_iwrite_at_all(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_at_all(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_at_all
! 
! subroutine MPIABI_File_iwrite_at_all_c(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_at_all_c(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_at_all_c
! 
! subroutine MPIABI_File_iwrite_at_c(fh, offset, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_at_c(fh, offset, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_at_c
! 
! subroutine MPIABI_File_iwrite_c(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_c(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_c
! 
! subroutine MPIABI_File_iwrite_shared(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_shared(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_shared
! 
! subroutine MPIABI_File_iwrite_shared_c(fh, buf, count, datatype, request, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_iwrite_shared_c(fh, buf, count, datatype, request, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_iwrite_shared_c
! 
! subroutine MPIABI_File_open(comm, filename, amode, info, fh, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_open(comm, filename, amode, info, fh, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_open
! 
! subroutine MPIABI_File_preallocate(fh, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_preallocate(fh, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_preallocate
! 
! subroutine MPIABI_File_read(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read
! 
! subroutine MPIABI_File_read_all(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_all(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_all
! 
! subroutine MPIABI_File_read_all_begin(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_all_begin(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_all_begin
! 
! subroutine MPIABI_File_read_all_begin_c(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_all_begin_c(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_all_begin_c
! 
! subroutine MPIABI_File_read_all_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_all_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_all_c
! 
! subroutine MPIABI_File_read_all_end(fh, buf, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_all_end(fh, buf, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_all_end
! 
! subroutine MPIABI_File_read_at(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at
! 
! subroutine MPIABI_File_read_at_all(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at_all(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at_all
! 
! subroutine MPIABI_File_read_at_all_begin(fh, offset, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at_all_begin(fh, offset, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at_all_begin
! 
! subroutine MPIABI_File_read_at_all_begin_c(fh, offset, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at_all_begin_c(fh, offset, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at_all_begin_c
! 
! subroutine MPIABI_File_read_at_all_c(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at_all_c(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at_all_c
! 
! subroutine MPIABI_File_read_at_all_end(fh, buf, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at_all_end(fh, buf, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at_all_end
! 
! subroutine MPIABI_File_read_at_c(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_at_c(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_at_c
! 
! subroutine MPIABI_File_read_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_c
! 
! subroutine MPIABI_File_read_ordered(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_ordered(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_ordered
! 
! subroutine MPIABI_File_read_ordered_begin(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_ordered_begin(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_ordered_begin
! 
! subroutine MPIABI_File_read_ordered_begin_c(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_ordered_begin_c(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_ordered_begin_c
! 
! subroutine MPIABI_File_read_ordered_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_ordered_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_ordered_c
! 
! subroutine MPIABI_File_read_ordered_end(fh, buf, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_ordered_end(fh, buf, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_ordered_end
! 
! subroutine MPIABI_File_read_shared(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_shared(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_shared
! 
! subroutine MPIABI_File_read_shared_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_read_shared_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_read_shared_c
! 
! subroutine MPIABI_File_seek(fh, offset, whence, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_seek(fh, offset, whence, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_seek
! 
! subroutine MPIABI_File_seek_shared(fh, offset, whence, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_seek_shared(fh, offset, whence, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_seek_shared
! 
! subroutine MPIABI_File_set_atomicity(fh, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_set_atomicity(fh, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_set_atomicity
! 
! subroutine MPIABI_File_set_info(fh, info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_set_info(fh, info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_set_info
! 
! subroutine MPIABI_File_set_size(fh, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_set_size(fh, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_set_size
! 
! subroutine MPIABI_File_set_view(fh, disp, etype, filetype, datarep, info, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_set_view(fh, disp, etype, filetype, datarep, info, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_set_view
! 
! subroutine MPIABI_File_sync(fh, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_sync(fh, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_sync
! 
! subroutine MPIABI_File_write(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write
! 
! subroutine MPIABI_File_write_all(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_all(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_all
! 
! subroutine MPIABI_File_write_all_begin(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_all_begin(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_all_begin
! 
! subroutine MPIABI_File_write_all_begin_c(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_all_begin_c(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_all_begin_c
! 
! subroutine MPIABI_File_write_all_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_all_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_all_c
! 
! subroutine MPIABI_File_write_all_end(fh, buf, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_all_end(fh, buf, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_all_end
! 
! subroutine MPIABI_File_write_at(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at
! 
! subroutine MPIABI_File_write_at_all(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at_all(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at_all
! 
! subroutine MPIABI_File_write_at_all_begin(fh, offset, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at_all_begin(fh, offset, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at_all_begin
! 
! subroutine MPIABI_File_write_at_all_begin_c(fh, offset, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at_all_begin_c(fh, offset, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at_all_begin_c
! 
! subroutine MPIABI_File_write_at_all_c(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at_all_c(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at_all_c
! 
! subroutine MPIABI_File_write_at_all_end(fh, buf, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at_all_end(fh, buf, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at_all_end
! 
! subroutine MPIABI_File_write_at_c(fh, offset, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_at_c(fh, offset, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_at_c
! 
! subroutine MPIABI_File_write_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_c
! 
! subroutine MPIABI_File_write_ordered(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_ordered(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_ordered
! 
! subroutine MPIABI_File_write_ordered_begin(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_ordered_begin(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_ordered_begin
! 
! subroutine MPIABI_File_write_ordered_begin_c(fh, buf, count, datatype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_ordered_begin_c(fh, buf, count, datatype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_ordered_begin_c
! 
! subroutine MPIABI_File_write_ordered_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_ordered_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_ordered_c
! 
! subroutine MPIABI_File_write_ordered_end(fh, buf, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_ordered_end(fh, buf, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_ordered_end
! 
! subroutine MPIABI_File_write_shared(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_shared(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_shared
! 
! subroutine MPIABI_File_write_shared_c(fh, buf, count, datatype, status, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_File_write_shared_c(fh, buf, count, datatype, status, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_File_write_shared_c
! 
! subroutine MPIABI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Register_datarep(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Register_datarep
! 
! subroutine MPIABI_Register_datarep_c(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Register_datarep_c(datarep, read_conversion_fn, write_conversion_fn, dtype_file_extent_fn, extra_state, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Register_datarep_c
! 
! ! A.3.13 Language Bindings C Bindings
! 
! ! A.3.14 Tools / Profiling Interface C Bindings
! 
! subroutine MPIABI_Pcontrol(level, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Pcontrol(level, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Pcontrol
! 
! ! A.3.16 Deprecated C Bindings
! 
! subroutine MPIABI_Attr_delete(comm, keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Attr_delete(comm, keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Attr_delete
! 
! subroutine MPIABI_Attr_get(comm, keyval, attribute_val, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Attr_get(comm, keyval, attribute_val, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Attr_get
! 
! subroutine MPIABI_Attr_put(comm, keyval, attribute_val, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Attr_put(comm, keyval, attribute_val, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Attr_put
! 
! subroutine MPIABI_Get_elements_x(status, datatype, count, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Get_elements_x(status, datatype, count, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Get_elements_x
! 
! subroutine MPIABI_Info_get(info, key, valuelen, value, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_get(info, key, valuelen, value, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_get
! 
! subroutine MPIABI_Info_get_valuelen(info, key, valuelen, flag, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Info_get_valuelen(info, key, valuelen, flag, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Info_get_valuelen
! 
! subroutine MPIABI_Keyval_create(copy_fn, delete_fn, keyval, extra_state, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Keyval_create(copy_fn, delete_fn, keyval, extra_state, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Keyval_create
! 
! subroutine MPIABI_Keyval_free(keyval, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Keyval_free(keyval, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Keyval_free
! 
! subroutine MPIABI_Status_set_elements_x(status, datatype, count, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Status_set_elements_x(status, datatype, count, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Status_set_elements_x
! 
! subroutine MPIABI_Type_get_extent_x(datatype, lb, extent, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_get_extent_x(datatype, lb, extent, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_get_extent_x
! 
! subroutine MPIABI_Type_get_true_extent_x(datatype, true_lb, true_extent, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_get_true_extent_x(datatype, true_lb, true_extent, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_get_true_extent_x
! 
! subroutine MPIABI_Type_size_x(datatype, size, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_size_x(datatype, size, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_size_x
! 
! ! Removed C Bindings
! 
! subroutine MPIABI_Address(location, address, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Address(location, address, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Address
! 
! subroutine MPIABI_Type_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_hindexed(count, array_of_blocklengths, array_of_displacements, oldtype, newtype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_hindexed
! 
! subroutine MPIABI_Type_hvector(count, blocklength, stride, oldtype, newtype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_hvector(count, blocklength, stride, oldtype, newtype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_hvector
! 
! subroutine MPIABI_Type_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_struct(count, array_of_blocklengths, array_of_displacements, array_of_types, newtype, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_struct
! 
! subroutine MPIABI_Type_extent(datatype, extent, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_extent(datatype, extent, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_extent
! 
! subroutine MPIABI_Type_lb(datatype, displacement, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_lb(datatype, displacement, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_lb
! 
! subroutine MPIABI_Type_ub(datatype, displacement, ierror)
!   use mpiwrapper
!   implicit none
!   call MPI_Type_ub(datatype, displacement, ierror)
!   ierror = mpi2abi_errorcode(ierror)
! end subroutine MPIABI_Type_ub
