#ifndef MPI_TYPES_H
#define MPI_TYPES_H

#include <mpiabi_types.h>

// Define MPI types

// A.1.2 Types

// C opaque types

typedef MPIABI_Aint MPI_Aint;
typedef MPIABI_Count MPI_Count;
typedef MPIABI_Fint MPI_Fint;
typedef MPIABI_Offset MPI_Offset;

typedef MPIABI_Status MPI_Status;
typedef MPIABI_Status MPI_F08_status;

// C handles to assorted structures

typedef MPIABI_Comm MPI_Comm;
typedef MPIABI_Datatype MPI_Datatype;
typedef MPIABI_Errhandler MPI_Errhandler;
typedef MPIABI_File MPI_File;
typedef MPIABI_Group MPI_Group;
typedef MPIABI_Info MPI_Info;
typedef MPIABI_Message MPI_Message;
typedef MPIABI_Op MPI_Op;
typedef MPIABI_Request MPI_Request;
typedef MPIABI_Session MPI_Session;
typedef MPIABI_Win MPI_Win;

// Types for the MPI_T interface

typedef MPIABI_T_enum MPI_T_enum;
typedef MPIABI_T_cvar_handle MPI_T_cvar_handle;
typedef MPIABI_T_pvar_handle MPI_T_pvar_handle;
typedef MPIABI_T_pvar_session MPI_T_pvar_session;
typedef MPIABI_T_event_instance MPI_T_event_instance;
typedef MPIABI_T_event_registration MPI_T_event_registration;
typedef MPIABI_T_source_order MPI_T_source_order;
typedef MPIABI_T_cb_safety MPI_T_cb_safety;

// Callback function types

// A.1.3 Prototype Definitions

typedef MPIABI_User_function MPI_User_function;
typedef MPIABI_User_function_c MPI_User_function_c;
typedef MPIABI_Comm_copy_attr_function MPI_Comm_copy_attr_function;
typedef MPIABI_Comm_delete_attr_function MPI_Comm_delete_attr_function;
typedef MPIABI_Win_copy_attr_function MPI_Win_copy_attr_function;
typedef MPIABI_Win_delete_attr_function MPI_Win_delete_attr_function;
typedef MPIABI_Type_copy_attr_function MPI_Type_copy_attr_function;
typedef MPIABI_Type_delete_attr_function MPI_Type_delete_attr_function;
typedef MPIABI_Comm_errhandler_function MPI_Comm_errhandler_function;
typedef MPIABI_Win_errhandler_function MPI_Win_errhandler_function;
typedef MPIABI_File_errhandler_function MPI_File_errhandler_function;
typedef MPIABI_Session_errhandler_function MPI_Session_errhandler_function;
typedef MPIABI_Grequest_query_function MPI_Grequest_query_function;
typedef MPIABI_Grequest_free_function MPI_Grequest_free_function;
typedef MPIABI_Grequest_cancel_function MPI_Grequest_cancel_function;
typedef MPIABI_Datarep_extent_function MPI_Datarep_extent_function;
typedef MPIABI_Datarep_conversion_function MPI_Datarep_conversion_function;
typedef MPIABI_Datarep_conversion_function_c MPI_Datarep_conversion_function_c;
typedef MPIABI_T_event_cb_function MPI_T_event_cb_function;
typedef MPIABI_T_event_free_cb_function MPI_T_event_free_cb_function;
typedef MPIABI_T_event_dropped_cb_function MPI_T_event_dropped_cb_function;

// A.1.4 Deprecated Prototype Definitions

typedef MPIABI_Copy_function MPI_Copy_function;
typedef MPIABI_Delete_function MPI_Delete_function;

#endif // #ifndef MPI_TYPES_H
