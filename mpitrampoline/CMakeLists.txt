cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPItrampoline VERSION 6.0.0
  DESCRIPTION "MPI trampoline"
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
set(SOVERSION 6)

include(CheckLanguage)
check_language(C)
if(NOT(CMAKE_C_COMPILER))
  message(FATAL_ERROR "No C support")
endif()
set(CMAKE_C_STANDARD 99)
enable_language(C)

configure_file(mpitrampoline.h.in mpitrampoline.h @ONLY)

add_library(mpitrampoline
  mpi.h
  mpitrampoline.h
  mpi_constants.h
  mpi_functions.c
  mpi_functions.h
  mpi_types.h
  mpiabi_function_pointers.h
  mpiabi_function_pointers.c
)
target_include_directories(
  mpitrampoline
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ../mpiabi
)
set_target_properties(mpitrampoline PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${SOVERSION}
  PUBLIC_HEADER "mpi.h;${CMAKE_CURRENT_BINARY_DIR}/mpitrampoline.h;mpi_constants.h;mpi_functions.h;mpi_types.h;../mpiabi/mpiabi.h;../mpiabi/mpiabi_constants.h;../mpiabi/mpiabi_functions.h;../mpiabi/mpiabi_types.h"
)

install(TARGETS mpitrampoline EXPORT MPItrampolineTargets)
