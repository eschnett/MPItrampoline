cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPIwrapper VERSION 3.0.0
  DESCRIPTION "MPI wrapper"
  HOMEPAGE_URL "https://github.com/eschnett/MPItrampoline"
  LANGUAGES C
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
set(CMAKE_C_STANDARD 99)
enable_language(C)

# include(CheckCSourceCompiles)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckTypeSize)

check_include_file(mpi.h HAVE_MPI_H)
check_include_file(mpi-ext.h HAVE_MPI_EXT_H)

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

check_function_exists(MPIX_Query_cuda_support HAVE_MPIX_QUERY_CUDA_SUPPORT)
check_function_exists(MPIX_Query_hip_support HAVE_MPIX_QUERY_HIP_SUPPORT)
check_function_exists(MPIX_Query_rocm_support HAVE_MPIX_QUERY_ROCM_SUPPORT)
check_function_exists(MPIX_Query_ze_support HAVE_MPIX_QUERY_ZE_SUPPORT)

configure_file(mpiwrapper.h.in mpiwrapper.h @ONLY)

add_library(mpiwrapper
  mpiwrapper.c
  mpiwrapper.h
)
target_include_directories(
  mpiwrapper
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  PUBLIC include ../mpiabi
)
set_target_properties(mpiwrapper PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${SOVERSION}
  # TODO: Add mpi-version.h etc. as public headers instead of installing them manually
  # PUBLIC_HEADER "include/mpi.h;include/mpio.h;mpiabi/mpiabi.h"
)
