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
if(NOT(CMAKE_C_COMPILER))
  message(FATAL_ERROR "No C support")
endif()
# set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD 11)        # for atomics and mutexes; could use OpenMP instead
enable_language(C)

check_language(Fortran)
if(NOT(CMAKE_Fortran_COMPILER))
  message(FATAL_ERROR "No Fortran support")
endif()
enable_language(Fortran)

include(GNUInstallDirs)

include(FindMPI)
# include(FindOpenMP)
include(FindThreads)

# include(CheckCSourceCompiles)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckSymbolExists)
include(CheckTypeSize)

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

check_symbol_exists(MPI_INTEGER1 mpi.h HAVE_MPI_INTEGER1)
check_symbol_exists(MPI_INTEGER2 mpi.h HAVE_MPI_INTEGER2)
check_symbol_exists(MPI_INTEGER4 mpi.h HAVE_MPI_INTEGER4)
check_symbol_exists(MPI_INTEGER8 mpi.h HAVE_MPI_INTEGER8)
check_symbol_exists(MPI_INTEGER16 mpi.h HAVE_MPI_INTEGER16)

check_symbol_exists(MPI_REAL1 mpi.h HAVE_MPI_REAL1)
check_symbol_exists(MPI_REAL2 mpi.h HAVE_MPI_REAL2)
check_symbol_exists(MPI_REAL4 mpi.h HAVE_MPI_REAL4)
check_symbol_exists(MPI_REAL8 mpi.h HAVE_MPI_REAL8)
check_symbol_exists(MPI_REAL16 mpi.h HAVE_MPI_REAL16)

check_symbol_exists(MPI_COMPLEX2 mpi.h HAVE_MPI_COMPLEX2)
check_symbol_exists(MPI_COMPLEX4 mpi.h HAVE_MPI_COMPLEX4)
check_symbol_exists(MPI_COMPLEX8 mpi.h HAVE_MPI_COMPLEX8)
check_symbol_exists(MPI_COMPLEX16 mpi.h HAVE_MPI_COMPLEX16)
check_symbol_exists(MPI_COMPLEX32 mpi.h HAVE_MPI_COMPLEX32)

check_symbol_exists(MPI_LOGICAL1 mpi.h HAVE_MPI_LOGICAL1)
check_symbol_exists(MPI_LOGICAL2 mpi.h HAVE_MPI_LOGICAL2)
check_symbol_exists(MPI_LOGICAL4 mpi.h HAVE_MPI_LOGICAL4)
check_symbol_exists(MPI_LOGICAL8 mpi.h HAVE_MPI_LOGICAL8)
check_symbol_exists(MPI_LOGICAL16 mpi.h HAVE_MPI_LOGICAL16)

check_symbol_exists(MPI_LB mpi.h HAVE_MPI_LB)
check_symbol_exists(MPI_UB mpi.h HAVE_MPI_UB)

check_function_exists(MPIX_Query_cuda_support HAVE_MPIX_QUERY_CUDA_SUPPORT)
check_function_exists(MPIX_Query_hip_support HAVE_MPIX_QUERY_HIP_SUPPORT)
check_function_exists(MPIX_Query_rocm_support HAVE_MPIX_QUERY_ROCM_SUPPORT)
check_function_exists(MPIX_Query_ze_support HAVE_MPIX_QUERY_ZE_SUPPORT)

configure_file(mpiwrapper.h.in mpiwrapper.h @ONLY)

add_library(mpiwrapper
  MODULE
  mpiwrapper.h
  mpiwrapper.c
  mpiwrapper-mpi3.c
  mpiwrapper.f90
  mpiwrapper_functions.f90
)
target_compile_options(mpiwrapper PRIVATE -Wall -Wextra -fdiagnostics-show-option)
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
