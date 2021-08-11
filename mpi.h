#ifndef MPI_H
#define MPI_H

#include <stddef.h>
#include <stdint.h>

typedef uintptr_t MPI_Aint;
typedef int MPI_Fint;
typedef ptrdiff_t MPI_Count;
typedef ptrdiff_t MPI_Offset;

typedef uintptr_t MPI_Comm;
typedef uintptr_t MPI_Datatype;
typedef uintptr_t MPI_Group;
typedef uintptr_t MPI_Info;
typedef uintptr_t MPI_Op;
typedef uintptr_t MPI_Request;

typedef struct {
  union {
    struct {
      int f0;
      int f1;
      int f2;
      int f3;
      size_t f4;
    } OpenMPI;
    struct {
      int f0;
      int f1;
      int f2;
      int f3;
      int f4;
    } MPICH;
  } wrapped;
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
} MPI_Status;

// TODO: Don't define these
typedef MPI_Status *MPI_StatusPtr;
typedef const MPI_Status *MPI_const_StatusPtr;

#define CONSTANT(TYPE, NAME) extern MPI_##TYPE MPI_##NAME;
#include "mpi-constants.inc"
#undef CONSTANT

#define MT(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES) extern RTYPE(*MPI_##NAME) PTYPES;
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT

#endif // #ifndef MPI_H
