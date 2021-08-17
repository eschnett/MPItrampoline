#ifndef MPI_H
#define MPI_H

#include <stddef.h>
#include <stdint.h>

// Identify ourselves
// TODO: Use cmake to fill this in automatically
#define MPITRAMPOLINE_VERSION_MAJOR 1
#define MPITRAMPOLINE_VERSION_MINOR 0
#define MPITRAMPOLINE_VERSION_PATCH 0

// Compile-time constants

// TODO: Check whether these limits are compatible with the wrapped MPI
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

typedef intptr_t MPI_Aint;
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

// TODO: Don't define these publicly
typedef MPI_Comm *MPI_CommPtr;
typedef MPI_Datatype *MPI_DatatypePtr;
typedef MPI_Errhandler *MPI_ErrhandlerPtr;
typedef MPI_File *MPI_FilePtr;
typedef MPI_Group *MPI_GroupPtr;
typedef MPI_Info *MPI_InfoPtr;
typedef MPI_Message *MPI_MessagePtr;
typedef MPI_Op *MPI_OpPtr;
typedef MPI_Request *MPI_RequestPtr;
typedef MPI_Win *MPI_WinPtr;

// MPI_Status

// TODO: Don't define this publicly
#ifdef __LP64__
#define MPI_STATUS_SIZE 10
#else
#define MPI_STATUS_SIZE 8
#endif

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

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L
_Static_assert(MPI_STATUS_SIZE * sizeof(MPI_Fint) == sizeof(MPI_Status), "");
#elif defined __cplusplus && __cplusplus >= 201103L
static_assert(MPI_STATUS_SIZE * sizeof(MPI_Fint) == sizeof(MPI_Status), "");
#endif

// TODO: Don't define these publicly
typedef MPI_Status *MPI_StatusPtr;
typedef const MPI_Status *MPI_const_StatusPtr;

// Callback function types

typedef int MPI_Comm_copy_attr_function(MPI_Comm oldcomm, int comm_keyval,
                                        void *extra_state,
                                        void *attribute_val_in,
                                        void *attribute_val, int *flag);
typedef int MPI_Comm_delete_attr_function(MPI_Comm comm, int comm_keyval,
                                          void *attribute_val,
                                          void *extra_state);
typedef void MPI_Comm_errhandler_function(MPI_Comm *, int *, ...);
typedef MPI_Comm_copy_attr_function MPI_Copy_function;
#if 0
// TODO: Handle conversions
typedef int MPI_Datarep_conversion_function(void *userbuf,
                                            MPI_Datatype datatype, int count,
                                            void *filebuf, MPI_Offset position,
                                            void *extra_state);
typedef int MPI_Datarep_extent_function(MPI_Datatype datatype,
                                        MPI_Aint *file_extent,
                                        void *extra_state);
#endif
typedef MPI_Comm_delete_attr_function MPI_Delete_function;
typedef void MPI_File_errhandler_function(MPI_File *, int *, ...);
typedef int MPI_Grequest_cancel_function(void *extra_state, int complete);
typedef int MPI_Grequest_free_function(void *extra_state);
#if 0
// TODO: Handle status correctly
typedef int MPI_Grequest_query_function(void *extra_state, MPI_Status *status);
#endif
typedef int MPI_Type_copy_attr_function(MPI_Datatype oldtype, int type_keyval,
                                        void *extra_state,
                                        void *attribute_val_in,
                                        void *attribute_val_out, int *flag);
typedef int MPI_Type_delete_attr_function(MPI_Datatype datatype,
                                          int type_keyval, void *attribute_val,
                                          void *extra_state);
typedef void MPI_User_function(void *invec, void *inoutvec, int *len,
                               MPI_Datatype *datatype);
typedef int MPI_Win_copy_attr_function(MPI_Win oldwin, int win_keyval,
                                       void *extra_state,
                                       void *attribute_val_in,
                                       void *attribute_val_out, int *flag);
typedef int MPI_Win_delete_attr_function(MPI_Win win, int win_keyval,
                                         void *attribute_val,
                                         void *extra_state);
typedef void MPI_Win_errhandler_function(MPI_Win *, int *, ...);

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

// TODO: Use inline function wrappers
#define MT(TYPE) MPI_##TYPE
#define MP(TYPE) MPI_##TYPE
#define FUNCTION(RTYPE, NAME, PTYPES, PNAMES)                                  \
  extern RTYPE(*MPItrampoline_##NAME) PTYPES;                                  \
  inline RTYPE MPI_##NAME PTYPES { return MPItrampoline_##NAME PNAMES; }
#include "mpi-functions.inc"
#undef FUNCTION
#undef MT
#undef MP

#ifdef __cplusplus
}
#endif

#endif // #ifndef MPI_H
