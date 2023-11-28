#if MPI_VERSION_NUMBER < 410

#include <assert.h>

// Fake MPI 4.1 support, just enough to make the linker happy

// C functions

void MPI_Buffer_flush() { assert(0); }
void MPI_Buffer_iflush() { assert(0); }
void MPI_Comm_attach_buffer() { assert(0); }
void MPI_Comm_attach_buffer_c() { assert(0); }
void MPI_Comm_detach_buffer() { assert(0); }
void MPI_Comm_detach_buffer_c() { assert(0); }
void MPI_Comm_flush_buffer() { assert(0); }
void MPI_Comm_iflush_buffer() { assert(0); }
void MPI_Request_get_status_all() { assert(0); }
void MPI_Request_get_status_any() { assert(0); }
void MPI_Request_get_status_some() { assert(0); }
void MPI_Session_attach_buffer() { assert(0); }
void MPI_Session_attach_buffer_c() { assert(0); }
void MPI_Session_detach_buffer() { assert(0); }
void MPI_Session_detach_buffer_c() { assert(0); }
void MPI_Session_flush_buffer() { assert(0); }
void MPI_Session_iflush_buffer() { assert(0); }
void MPI_Status_get_error() { assert(0); }
void MPI_Status_get_source() { assert(0); }
void MPI_Status_get_tag() { assert(0); }

#endif
