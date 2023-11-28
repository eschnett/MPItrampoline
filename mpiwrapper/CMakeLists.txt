cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPIwrapper VERSION 3.0.0
  DESCRIPTION "MPI wrapper"
  HOMEPAGE_URL "https://github.com/eschnett/MPItrampoline"
  LANGUAGES C Fortran
  )

# SOVERSION is the ABI version of MPItrampoline. (That's different
# from the MPI_ABI version.)
#
# SOVERSION is handled differently under Linux and macOS. We are using
# a single-digit SOVERSION to avoid confusion between VERSION (which
# consists of 3 numbers) and SOVERSION.
#
# Different SOVERSIONs are incompatible; there is no need to have a
# major/minor version number.
set(SOVERSION 3)

include(CheckLanguage)

check_language(C)
if(NOT CMAKE_C_COMPILER)
  message(FATAL_ERROR "No C language compiler")
endif()
# set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD 11)        # for atomics and mutexes; could use OpenMP instead
enable_language(C)

check_language(Fortran)
if(NOT CMAKE_Fortran_COMPILER)
  message(FATAL_ERROR "No Fortran language compiler")
endif()
enable_language(Fortran)

include(GNUInstallDirs)

find_package(MPI REQUIRED COMPONENTS C Fortran)
# include(FindOpenMP)
find_package(Threads REQUIRED)

# include(CheckCSourceCompiles)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckSymbolExists)
include(CheckTypeSize)
include(CheckFortranSourceCompiles)

list(APPEND CMAKE_REQUIRED_INCLUDES "${MPI_C_INCLUDE_DIRS}")
list(APPEND CMAKE_REQUIRED_LIBRARIES "${MPI_C_LIBRARIES}")
check_include_file(mpi.h HAVE_MPI_H)
# OpenMPI 5.0.0 does not allow including `mpi-ext.h` without first
# including `mpi.h` <https://github.com/open-mpi/ompi/issues/12111>
# check_include_file(mpi-ext.h HAVE_MPI_EXT_H)
check_include_files("mpi.h;mpi-ext.h" HAVE_MPI_EXT_H)

list(APPEND CMAKE_EXTRA_INCLUDE_FILES mpi.h)

check_type_size(ptrdiff_t SIZEOF_PTRDIFF_T)

check_type_size(MPI_Aint SIZEOF_MPI_AINT)
check_type_size(MPI_Count SIZEOF_MPI_COUNT)
check_type_size(MPI_Fint SIZEOF_MPI_FINT)
check_type_size(MPI_Offset SIZEOF_MPI_OFFSET)
# check_type_size(MPI_Status SIZEOF_MPI_STATUS)
# check_type_size(MPI_F08_status SIZEOF_MPI_F08_STATUS)

# check_type_size(MPI_Comm SIZEOF_MPI_COMM)
# check_type_size(MPI_Datatype SIZEOF_MPI_DATATYPE)
# check_type_size(MPI_Errhandler SIZEOF_MPI_ERRHANDLER)
# check_type_size(MPI_File SIZEOF_MPI_FILE)
# check_type_size(MPI_Group SIZEOF_MPI_GROUP)
# check_type_size(MPI_Info SIZEOF_MPI_INFO)
# check_type_size(MPI_Message SIZEOF_MPI_MESSAGE)
# check_type_size(MPI_Op SIZEOF_MPI_OP)
# check_type_size(MPI_Request SIZEOF_MPI_REQUEST)
# check_type_size(MPI_Session SIZEOF_MPI_SESSION)
# check_type_size(MPI_Win SIZEOF_MPI_WIN)

# check_symbol_exists(MPI_INTEGER mpi.h HAVE_MPI_INTEGER)
# check_symbol_exists(MPI_INTEGER1 mpi.h HAVE_MPI_INTEGER1)
# check_symbol_exists(MPI_INTEGER2 mpi.h HAVE_MPI_INTEGER2)
# check_symbol_exists(MPI_INTEGER4 mpi.h HAVE_MPI_INTEGER4)
# check_symbol_exists(MPI_INTEGER8 mpi.h HAVE_MPI_INTEGER8)
# check_symbol_exists(MPI_INTEGER16 mpi.h HAVE_MPI_INTEGER16)
# 
# check_symbol_exists(MPI_REAL mpi.h HAVE_MPI_REAL)
# check_symbol_exists(MPI_REAL1 mpi.h HAVE_MPI_REAL1)
# check_symbol_exists(MPI_REAL2 mpi.h HAVE_MPI_REAL2)
# check_symbol_exists(MPI_REAL4 mpi.h HAVE_MPI_REAL4)
# check_symbol_exists(MPI_REAL8 mpi.h HAVE_MPI_REAL8)
# check_symbol_exists(MPI_REAL16 mpi.h HAVE_MPI_REAL16)
# 
# check_symbol_exists(MPI_COMPLEX mpi.h HAVE_MPI_COMPLEX)
# check_symbol_exists(MPI_COMPLEX2 mpi.h HAVE_MPI_COMPLEX2)
# check_symbol_exists(MPI_COMPLEX4 mpi.h HAVE_MPI_COMPLEX4)
# check_symbol_exists(MPI_COMPLEX8 mpi.h HAVE_MPI_COMPLEX8)
# check_symbol_exists(MPI_COMPLEX16 mpi.h HAVE_MPI_COMPLEX16)
# check_symbol_exists(MPI_COMPLEX32 mpi.h HAVE_MPI_COMPLEX32)
# 
# check_symbol_exists(MPI_LOGICAL mpi.h HAVE_MPI_LOGICAL)
# check_symbol_exists(MPI_LOGICAL1 mpi.h HAVE_MPI_LOGICAL1)
# check_symbol_exists(MPI_LOGICAL2 mpi.h HAVE_MPI_LOGICAL2)
# check_symbol_exists(MPI_LOGICAL4 mpi.h HAVE_MPI_LOGICAL4)
# check_symbol_exists(MPI_LOGICAL8 mpi.h HAVE_MPI_LOGICAL8)
# check_symbol_exists(MPI_LOGICAL16 mpi.h HAVE_MPI_LOGICAL16)

check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_INTEGER - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_INTEGER
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_INTEGER1 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_INTEGER1
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_INTEGER2 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_INTEGER2
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_INTEGER4 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_INTEGER4
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_INTEGER8 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_INTEGER8
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_INTEGER16 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_INTEGER16
  SRC_EXT .f90
)

check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_REAL - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_REAL
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_REAL1 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_REAL1
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_REAL2 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_REAL2
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_REAL4 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_REAL4
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_REAL8 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_REAL8
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_REAL16 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_REAL16
  SRC_EXT .f90
)

check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_COMPLEX - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_COMPLEX
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_COMPLEX2 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_COMPLEX2
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_COMPLEX4 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_COMPLEX4
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_COMPLEX8 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_COMPLEX8
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_COMPLEX16 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_COMPLEX16
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_COMPLEX32 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_COMPLEX32
  SRC_EXT .f90
)

check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_LOGICAL - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_LOGICAL
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_LOGICAL1 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_LOGICAL1
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_LOGICAL2 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_LOGICAL2
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_LOGICAL4 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_LOGICAL4
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_LOGICAL8 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_LOGICAL8
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer, parameter :: dummy = 1 / (MPI_LOGICAL16 - MPI_DATATYPE_NULL)
  end
  "
  HAVE_USABLE_MPI_LOGICAL16
  SRC_EXT .f90
)

if(NOT(${HAVE_USABLE_MPI_INTEGER}))
  message(FATAL_ERROR "MPI Fortran datatype `MPI_INTEGER` is not usable")
endif()
if(NOT(${HAVE_USABLE_MPI_REAL}))
  message(FATAL_ERROR "MPI Fortran datatype `MPI_REAL` is not usable")
endif()
if(NOT(${HAVE_USABLE_MPI_COMPLEX}))
  message(FATAL_ERROR "MPI Fortran datatype `MPI_COMPLEX` is not usable")
endif()
if(NOT(${HAVE_USABLE_MPI_LOGICAL}))
  message(FATAL_ERROR "MPI Fortran datatype `MPI_LOGICAL` is not usable")
endif()


check_symbol_exists(MPI_LB mpi.h HAVE_MPI_LB)
check_symbol_exists(MPI_UB mpi.h HAVE_MPI_UB)

check_function_exists(MPIX_Query_cuda_support HAVE_MPIX_QUERY_CUDA_SUPPORT)
check_function_exists(MPIX_Query_hip_support HAVE_MPIX_QUERY_HIP_SUPPORT)
check_function_exists(MPIX_Query_rocm_support HAVE_MPIX_QUERY_ROCM_SUPPORT)
check_function_exists(MPIX_Query_ze_support HAVE_MPIX_QUERY_ZE_SUPPORT)

list(APPEND CMAKE_REQUIRED_INCLUDES "${MPI_Fortran_INCLUDE_DIRS}")
list(APPEND CMAKE_REQUIRED_LIBRARIES "${MPI_Fortran_LIBRARIES}")
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  end
  "
  HAVE_FORTRAN_MPIF_H
  SRC_EXT .f90
)
check_fortran_source_compiles(
  "
  implicit none
  include 'mpif.h'
  integer session
  session = MPI_SESSION_NULL
  end
  "
  HAVE_FORTRAN_MPI_SESSION_NULL
  SRC_EXT .f90
)

# Check level of MPI 4 support
## Constants
check_symbol_exists(MPI_BUFFER_AUTOMATIC mpi.h HAVE_MPI_BUFFER_AUTOMATIC)
check_symbol_exists(MPI_COMM_TYPE_HW_GUIDED mpi.h HAVE_MPI_COMM_TYPE_HW_GUIDED)
check_symbol_exists(MPI_COMM_TYPE_HW_UNGUIDED mpi.h HAVE_MPI_COMM_TYPE_HW_UNGUIDED)
check_symbol_exists(MPI_COMM_TYPE_RESOURCE_GUIDED mpi.h HAVE_MPI_COMM_TYPE_RESOURCE_GUIDED)
## Types
check_type_size(MPI_Session SIZEOF_MPI_SESSION)
check_type_size(MPI_User_function_c SIZEOF_MPI_USER_FUNCTION_C)

configure_file(mpiwrapper.h.in mpiwrapper.h @ONLY)

add_library(mpiwrapper
  MODULE
  mpiwrapper.h
  mpiwrapper.c
  mpiwrapper-mpi3.c
  mpiwrapper-mpi40.c
  mpiwrapper.F90
  mpiwrapper_functions.F90
)
# target_compile_options(mpiwrapper PRIVATE -Wall -Wextra -fdiagnostics-show-option)
target_compile_options(mpiwrapper PUBLIC -fcray-pointer)
target_include_directories(
  mpiwrapper
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ../mpiabi
)
target_link_libraries(mpiwrapper PRIVATE MPI::MPI_C MPI::MPI_Fortran Threads::Threads)
# This does not work on macOS with GCC
# set_target_properties(mpiwrapper PROPERTIES
#   VERSION ${PROJECT_VERSION}
#   SOVERSION ${SOVERSION}
# )

if(APPLE)
  # On macOS, check that the plugin `libmpiwrapper.so` is built with a
  # two-level namespace. If not, it will use the MPI functions
  # provided by MPItrampoline instead of the "real" MPI, which will
  # recurse infinitely, leading to a stack overflow and segfault.
  add_custom_command(
    TARGET mpiwrapper POST_BUILD
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/check_twolevel.sh ${CMAKE_CURRENT_BINARY_DIR}/libmpiwrapper.so
    COMMENT "Checking whether libmpiwrapper.so plugin uses a two-level namespace..."
    VERBATIM
    )
endif()

install(TARGETS mpiwrapper LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
