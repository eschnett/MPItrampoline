// The section names follow the MPI 3.1 standard.

// 3.2 Blocking Send and Receive Operations
FUNCTION(void, send,
         (const void *buf, MT(Fint) * count, MT(Fint) * datatype,
          MT(Fint) * dest, MT(Fint) * tag, MT(Fint) * comm, MT(Fint) * ierror),
         (buf, count, datatype, dest, tag, comm, ierror))
FUNCTION(void, recv,
         (const void *buf, MT(Fint) * count, MT(Fint) * datatype,
          MT(Fint) * source, MT(Fint) * tag, MT(Fint) * comm, MT(Fint *) status,
          MT(Fint) * ierror),
         (buf, count, datatype, source, tag, comm, status, ierror))
FUNCTION(void, get_count,
         (MT(Fint) * status, MT(Fint) * datatype, MT(Fint) * count,
          MT(Fint) * ierror),
         (status, datatype, count, ierror))

// 8.6 Times and Synchronization
FUNCTION(double, wtime, (), ())
FUNCTION(double, wtick, (), ())

// 8.7 Startup
FUNCTION(void, init, (MT(Fint) * ierror), (ierror))
FUNCTION(void, finalize, (MT(Fint) * ierror), (ierror))
FUNCTION(void, initialized, (MT(Fint) * flag, MT(Fint) * ierror),
         (flag, ierror))
FUNCTION(void, abort,
         (MT(Fint) * comm, MT(Fint) * errorcode, MT(Fint) * ierror),
         (comm, errorcode, ierror))
FUNCTION(void, finalized, (MT(Fint) * flag, MT(Fint) * ierror), (flag, ierror))
