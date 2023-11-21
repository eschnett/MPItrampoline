#ifndef MPIABI_TYPES_H
#define MPIABI_TYPES_H

#include <stddef.h>

// Define MPIABI types

// A.1.2 Types

// C opaque types

typedef ptrdiff_t MPIABI_Aint;
typedef ptrdiff_t MPIABI_Count;
typedef int MPIABI_Fint;
typedef ptrdiff_t MPIABI_Offset;

typedef struct {
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
  int mpi_reserved[5];
} MPIABI_Status;

typedef MPIABI_Status MPIABI_F08_status;

// C handles to assorted structures

typedef struct MPIABI_ABI_Comm *MPIABI_Comm;
typedef struct MPIABI_ABI_Datatype *MPIABI_Datatype;
typedef struct MPIABI_ABI_Errhandler *MPIABI_Errhandler;
typedef struct MPIABI_ABI_File *MPIABI_File;
typedef struct MPIABI_ABI_Group *MPIABI_Group;
typedef struct MPIABI_ABI_Info *MPIABI_Info;
typedef struct MPIABI_ABI_Message *MPIABI_Message;
typedef struct MPIABI_ABI_Op *MPIABI_Op;
typedef struct MPIABI_ABI_Request *MPIABI_Request;
typedef struct MPIABI_ABI_Session *MPIABI_Session;
typedef struct MPIABI_ABI_Win *MPIABI_Win;

// Types for the MPI_T interface

typedef struct MPIABI_ABI_T_enum *MPIABI_T_enum;
typedef struct MPIABI_ABI_T_cvar_handle *MPIABI_T_cvar_handle;
typedef struct MPIABI_ABI_T_pvar_handle *MPIABI_T_pvar_handle;
typedef struct MPIABI_ABI_T_pvar_session *MPIABI_T_pvar_session;
typedef struct MPIABI_ABI_T_event_instance *MPIABI_T_event_instance;
typedef struct MPIABI_ABI_T_event_registration *MPIABI_T_event_registration;
typedef struct MPIABI_ABI_T_source_order *MPIABI_T_source_order;
typedef struct MPIABI_ABI_T_cb_safety *MPIABI_T_cb_safety;

// Callback function types

// A.1.3 Prototype Definitions

typedef void MPIABI_User_function(void *invec, void *inoutvec, int *len,
                                  MPIABI_Datatype *datatype);
typedef void MPIABI_User_function_c(void *invec, void *inoutvec,
                                    MPIABI_Count *len,
                                    MPIABI_Datatype *datatype);
typedef int MPIABI_Comm_copy_attr_function(MPIABI_Comm oldcomm, int comm_keyval,
                                           void *extra_state,
                                           void *attribute_val_in,
                                           void *attribute_val_out, int *flag);
typedef int MPIABI_Comm_delete_attr_function(MPIABI_Comm comm, int comm_keyval,
                                             void *attribute_val,
                                             void *extra_state);
typedef int MPIABI_Win_copy_attr_function(MPIABI_Win oldwin, int win_keyval,
                                          void *extra_state,
                                          void *attribute_val_in,
                                          void *attribute_val_out, int *flag);
typedef int MPIABI_Win_delete_attr_function(MPIABI_Win win, int win_keyval,
                                            void *attribute_val,
                                            void *extra_state);
typedef int MPIABI_Type_copy_attr_function(MPIABI_Datatype oldtype,
                                           int type_keyval, void *extra_state,
                                           void *attribute_val_in,
                                           void *attribute_val_out, int *flag);
typedef int MPIABI_Type_delete_attr_function(MPIABI_Datatype datatype,
                                             int type_keyval,
                                             void *attribute_val,
                                             void *extra_state);
typedef void MPIABI_Comm_errhandler_function(MPIABI_Comm *comm, int *error_code,
                                             ...);
typedef void MPIABI_Win_errhandler_function(MPIABI_Win *win, int *error_code,
                                            ...);
typedef void MPIABI_File_errhandler_function(MPIABI_File *file, int *error_code,
                                             ...);
typedef void MPIABI_Session_errhandler_function(MPIABI_Session *session,
                                                int *error_code, ...);
typedef int MPIABI_Grequest_query_function(void *extra_state,
                                           MPIABI_Status *status);
typedef int MPIABI_Grequest_free_function(void *extra_state);
typedef int MPIABI_Grequest_cancel_function(void *extra_state, int complete);
typedef int MPIABI_Datarep_extent_function(MPIABI_Datatype datatype,
                                           MPIABI_Aint *extent,
                                           void *extra_state);
typedef int MPIABI_Datarep_conversion_function(void *userbuf,
                                               MPIABI_Datatype datatype,
                                               int count, void *filebuf,
                                               MPIABI_Offset position,
                                               void *extra_state);
typedef int
MPIABI_Datarep_conversion_function_c(void *userbuf, MPIABI_Datatype datatype,
                                     MPIABI_Count count, void *filebuf,
                                     MPIABI_Offset position, void *extra_state);
typedef void
MPIABI_T_event_cb_function(MPIABI_T_event_instance event_instance,
                           MPIABI_T_event_registration event_registration,
                           MPIABI_T_cb_safety cb_safety, void *user_data);
typedef void
MPIABI_T_event_free_cb_function(MPIABI_T_event_registration event_registration,
                                MPIABI_T_cb_safety cb_safety, void *user_data);
typedef void MPIABI_T_event_dropped_cb_function(
    MPIABI_Count count, MPIABI_T_event_registration event_registration,
    int source_index, MPIABI_T_cb_safety cb_safety, void *user_data);

// A.1.4 Deprecated Prototype Definitions

typedef int MPIABI_Copy_function(MPIABI_Comm oldcomm, int keyval,
                                 void *extra_state, void *attribute_val_in,
                                 void *attribute_val_out, int *flag);
typedef int MPIABI_Delete_function(MPIABI_Comm comm, int keyval,
                                   void *attribute_val, void *extra_state);

#endif // #ifndef MPIABI_TYPES_H
