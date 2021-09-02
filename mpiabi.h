#ifndef MPIABI_H
#define MPIABI_H

#include <stddef.h>
#include <stdint.h>

#if defined __cplusplus && __cplusplus >= 201103L
#include <type_traits>
#endif

// MPI ABI version (we use SemVer)

#define MPIABI_VERSION_MAJOR 2
#define MPIABI_VERSION_MINOR 0
#define MPIABI_VERSION_PATCH 0

// Compile-time constants

#define MPIABI_MPI_VERSION 3
#define MPIABI_MPI_SUBVERSION 1

#define MPIABI_MAX_DATAREP_STRING 128          // from MPICH
#define MPIABI_MAX_ERROR_STRING 1024           // MPICH's default
#define MPIABI_MAX_INFO_KEY 256                // from MPICH
#define MPIABI_MAX_INFO_VAL 1024               // from MPICH
#define MPIABI_MAX_LIBRARY_VERSION_STRING 8192 // MPICH's default
#define MPIABI_MAX_OBJECT_NAME 128             // from MPICH
#define MPIABI_MAX_PORT_NAME 256               // from MPICH
#define MPIABI_MAX_PROCESSOR_NAME 128          // MPICH's default

// Simple types

typedef intptr_t MPIABI_Aint;
typedef int64_t MPIABI_Count;
typedef int MPIABI_Fint;
typedef int64_t MPIABI_Offset;

// Handles

typedef uintptr_t MPIABI_Comm;
typedef uintptr_t MPIABI_Datatype;
typedef uintptr_t MPIABI_Errhandler;
typedef uintptr_t MPIABI_File;
typedef uintptr_t MPIABI_Group;
typedef uintptr_t MPIABI_Info;
typedef uintptr_t MPIABI_Message;
typedef uintptr_t MPIABI_Op;
typedef uintptr_t MPIABI_Request;
typedef uintptr_t MPIABI_Win;

// TODO: Don't define these publicly
typedef MPIABI_Comm *MPIABI_CommPtr;
typedef MPIABI_Datatype *MPIABI_DatatypePtr;
typedef MPIABI_Errhandler *MPIABI_ErrhandlerPtr;
typedef MPIABI_File *MPIABI_FilePtr;
typedef MPIABI_Group *MPIABI_GroupPtr;
typedef MPIABI_Info *MPIABI_InfoPtr;
typedef MPIABI_Message *MPIABI_MessagePtr;
typedef MPIABI_Op *MPIABI_OpPtr;
typedef MPIABI_Request *MPIABI_RequestPtr;
typedef MPIABI_Win *MPIABI_WinPtr;

// MPI_Status
// This is a difficult type for an ABI since it has user-accessible fields.

#ifdef __LP64__
#define MPIABI_STATUS_SIZE 10
#else
#define MPIABI_STATUS_SIZE 8
#endif

// We put the MPI_Status struct in the beginning. This way, we can
// cast from MPI_Status* to MPIABI_Status* when the status is
// undefined, or when it is `MPI_STATUS_IGNORE`.
typedef struct {
  union {
    struct {
      int f0;
      int f1;
      int f2;
      int f3;
      size_t f4;
    } status_OpenMPI; // also IBM Spectrum MPI
    struct {
      int f0;
      int f1;
      int f2;
      int f3;
      int f4;
    } status_MPICH; // also Intel MPI
  } mpi_status;
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
} MPIABI_Status;

// TODO: Don't define these publicly
typedef MPIABI_Status *MPIABI_StatusPtr;
typedef const MPIABI_Status *MPIABI_const_StatusPtr;

#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L
_Static_assert(MPIABI_STATUS_SIZE * sizeof(MPIABI_Fint) ==
                   sizeof(MPIABI_Status),
               "");
#elif defined __cplusplus && __cplusplus >= 201103L
static_assert(MPIABI_STATUS_SIZE * sizeof(MPIABI_Fint) == sizeof(MPIABI_Status),
              "");
static_assert(std::is_pod<MPIABI_Status>::value, "");
#endif

// Helper types
// TODO: Don't define these publicly
typedef int MPIABI_array_int_3[3];

// Callback function types

typedef void MPIABI_Comm_copy_attr_function();
typedef void MPIABI_Comm_delete_attr_function();
typedef void MPIABI_Comm_errhandler_function();
typedef MPIABI_Comm_errhandler_function MPIABI_Comm_errhandler_fn;
typedef MPIABI_Comm_copy_attr_function MPIABI_Copy_function;
typedef void MPIABI_Datarep_conversion_function();
typedef void MPIABI_Datarep_extent_function();
typedef void MPIABI_Delete_function();
typedef void MPIABI_File_errhandler_function();
typedef void MPIABI_File_errhandler_fn();
typedef void MPIABI_Grequest_cancel_function();
typedef void MPIABI_Grequest_free_function();
typedef void MPIABI_Grequest_query_function();
typedef void MPIABI_Type_copy_attr_function();
typedef void MPIABI_Type_delete_attr_function();
typedef void MPIABI_User_function();
typedef void MPIABI_Win_copy_attr_function();
typedef void MPIABI_Win_delete_attr_function();
typedef void MPIABI_Win_errhandler_function();
typedef MPIABI_Win_errhandler_function MPIABI_Win_errhandler_fn;

// Constants

#ifdef __cplusplus
extern "C" {
#endif

extern const int mpiabi_version_major;
extern const int mpiabi_version_minor;
extern const int mpiabi_version_patch;

#ifdef __cplusplus
}
#endif

#endif // #ifndef MPIABI_H
