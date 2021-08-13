#ifndef MPI_H
#define MPI_H

#include <stddef.h>
#include <stdint.h>

// Compile-time constants

// #define MPI_MAX_DATAREP_STRING
#define MPI_MAX_ERROR_STRING 1024           // MPICH's default
#define MPI_MAX_INFO_KEY 255                // from MPICH
#define MPI_MAX_INFO_VAL 1024               // from MPICH
#define MPI_MAX_LIBRARY_VERSION_STRING 8192 // MPICH's default
#define MPI_MAX_OBJECT_NAME 128             // from MPICH
#define MPI_MAX_PORT_NAME 256               // from MPICH
#define MPI_MAX_PROCESSOR_NAME 128          // MPICH's default
#define MPI_SUBVERSION 1
#define MPI_VERSION 3 // we pretend to support 3.1

// Simple types

typedef uintptr_t MPI_Aint;
typedef int64_t MPI_Count;
typedef int MPI_Fint;
typedef int64_t MPI_Offset;

// Handles

typedef uintptr_t MPI_Comm;
typedef uintptr_t MPI_Datatype;
typedef uintptr_t MPI_Errhandler;
typedef uintptr_t MPI_File;
typedef uintptr_t MPI_Group;
typedef uintptr_t MPI_Info;
typedef uintptr_t MPI_Message;
typedef uintptr_t MPI_Op;
typedef uintptr_t MPI_Request;
typedef uintptr_t MPI_Win;

// MPI_Status

// TODO: Don't define this publicly
#define MPI_STATUS_SIZE 10

typedef struct {
  union {
    struct {
      int f0;
      int f1;
      int f2;
      int f3;
      size_t f4;
    } padding_OpenMPI; // also Spectrum MPI
    struct {
      int f0;
      int f1;
      int f2;
      int f3;
      int f4;
    } padding_MPICH; // also Intel MPI
  } wrapped;
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
} MPI_Status;

#ifdef __cplusplus
static_assert(MPI_STATUS_SIZE * sizeof(MPI_Fint) == sizeof(MPI_Status));
#else
_Static_assert(MPI_STATUS_SIZE * sizeof(MPI_Fint) == sizeof(MPI_Status));
#endif

// TODO: Don't define these publicly
typedef MPI_Status *MPI_StatusPtr;
typedef const MPI_Status *MPI_const_StatusPtr;

// Callback function types

typedef int(MPI_Comm_copy_attr_function)(MPI_Comm, int, void *, void *, void *,
                                         int *);
typedef int(MPI_Comm_delete_attr_function)(MPI_Comm, int, void *, void *);
typedef void(MPI_Comm_errhandler_function)(MPI_Comm *, int *, ...);
typedef int(MPI_Copy_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int(MPI_Delete_function)(MPI_Comm, int, void *, void *);
typedef void(MPI_File_errhandler_function)(MPI_File *, int *, ...);
typedef int(MPI_Type_copy_attr_function)(MPI_Datatype, int, void *, void *,
                                         void *, int *);
typedef int(MPI_Type_delete_attr_function)(MPI_Datatype, int, void *, void *);
typedef void(MPI_User_function)(void *, void *, int *, MPI_Datatype *);
typedef int(MPI_Win_copy_attr_function)(MPI_Win, int, void *, void *, void *,
                                        int *);
typedef int(MPI_Win_delete_attr_function)(MPI_Win, int, void *, void *);
typedef void(MPI_Win_errhandler_function)(MPI_Win *, int *, ...);

// Constants

#define MT(TYPE) MPI_##TYPE
#define CONSTANT(TYPE, NAME) extern TYPE MPI_##NAME;
#include "mpi-constants.inc"
#undef CONSTANT
#undef MT

// Functions

#ifdef __cplusplus
extern "C" {
#endif

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES) extern RTYPE(*MPI_##NAME) PTYPES;
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT

#ifdef __cplusplus
}
#endif

#endif // #ifndef MPI_H
