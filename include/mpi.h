#ifndef MPI_H
#define MPI_H

#include "mpi_version.h"

#include "mpiabi.h"

#include <stddef.h>
#include <stdint.h>

#ifndef MPITRAMPOLINE_CONST
#define MPITRAMPOLINE_CONST const
#endif

// Compile-time constants

#define MPI_VERSION MPIABI_MPI_VERSION
#define MPI_SUBVERSION MPIABI_MPI_SUBVERSION

#define MPI_MAX_DATAREP_STRING MPIABI_MAX_DATAREP_STRING
#define MPI_MAX_ERROR_STRING MPIABI_MAX_ERROR_STRING
#define MPI_MAX_INFO_KEY MPIABI_MAX_INFO_KEY
#define MPI_MAX_INFO_VAL MPIABI_MAX_INFO_VAL
#define MPI_MAX_LIBRARY_VERSION_STRING MPIABI_MAX_LIBRARY_VERSION_STRING
#define MPI_MAX_OBJECT_NAME MPIABI_MAX_OBJECT_NAME
#define MPI_MAX_PORT_NAME MPIABI_MAX_PORT_NAME
#define MPI_MAX_PROCESSOR_NAME MPIABI_MAX_PROCESSOR_NAME

// Simple types

typedef MPIABI_Aint MPI_Aint;
typedef MPIABI_Count MPI_Count;
typedef MPIABI_Fint MPI_Fint;
typedef MPIABI_Offset MPI_Offset;

// Handles

// Use pointers for MPI handles. This is safer since we can use
// different pointer types for different handle types. We cannot use
// structs directly because MPI requires that handles can be compared
// for equality.
typedef struct MPItrampoline_Comm *MPI_Comm;
typedef struct MPItrampoline_Datatype *MPI_Datatype;
typedef struct MPItrampoline_Errhandler *MPI_Errhandler;
typedef struct MPItrampoline_File *MPI_File;
typedef struct MPItrampoline_Group *MPI_Group;
typedef struct MPItrampoline_Info *MPI_Info;
typedef struct MPItrampoline_Message *MPI_Message;
typedef struct MPItrampoline_Op *MPI_Op;
typedef struct MPItrampoline_Request *MPI_Request;
typedef struct MPItrampoline_Win *MPI_Win;

// MPI_Status

#define MPI_STATUS_SIZE MPIABI_STATUS_SIZE
typedef MPIABI_Status MPI_Status;

// Callback function types

typedef int MPI_Comm_copy_attr_function(MPI_Comm oldcomm, int comm_keyval,
                                        void *extra_state,
                                        void *attribute_val_in,
                                        void *attribute_val, int *flag);
typedef int MPI_Comm_delete_attr_function(MPI_Comm comm, int comm_keyval,
                                          void *attribute_val,
                                          void *extra_state);
typedef void MPI_Comm_errhandler_function(MPI_Comm *, int *, ...);
typedef MPI_Comm_errhandler_function MPI_Comm_errhandler_fn;
typedef MPI_Comm_copy_attr_function MPI_Copy_function;
typedef int MPI_Datarep_conversion_function(void *userbuf,
                                            MPI_Datatype datatype, int count,
                                            void *filebuf, MPI_Offset position,
                                            void *extra_state);
typedef int MPI_Datarep_extent_function(MPI_Datatype datatype,
                                        MPI_Aint *file_extent,
                                        void *extra_state);
typedef MPI_Comm_delete_attr_function MPI_Delete_function;
typedef void MPI_File_errhandler_function(MPI_File *, int *, ...);
typedef MPI_File_errhandler_function MPI_File_errhandler_fn;
typedef int MPI_Grequest_cancel_function(void *extra_state, int complete);
typedef int MPI_Grequest_free_function(void *extra_state);
typedef int MPI_Grequest_query_function(void *extra_state, MPI_Status *status);
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
typedef MPI_Win_errhandler_function MPI_Win_errhandler_fn;

// Constants and Functions

#ifdef __cplusplus
extern "C" {
#endif

extern int MPITRAMPOLINE_CONST mpiwrapper_version_major;
extern int MPITRAMPOLINE_CONST mpiwrapper_version_minor;
extern int MPITRAMPOLINE_CONST mpiwrapper_version_patch;

extern int MPITRAMPOLINE_CONST mpiabi_loaded_version_major;
extern int MPITRAMPOLINE_CONST mpiabi_loaded_version_minor;
extern int MPITRAMPOLINE_CONST mpiabi_loaded_version_patch;

#include "mpi_decl_constants_c.h"
#include "mpi_decl_functions_c.h"

inline int PMPI_Pcontrol(int level, ...) { return MPI_SUCCESS; }
int MPI_Pcontrol(int level, ...);

#ifdef __cplusplus
}
#endif

#endif // #ifndef MPI_H
