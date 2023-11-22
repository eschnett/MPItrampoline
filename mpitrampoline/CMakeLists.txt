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
  # MPI C header files
  mpi.h
  mpi_types.h
  mpi_constants.h
  mpi_functions.h
  mpiabi_function_pointers.h
  mpitrampoline.h
  # MPI Fortran header files
  mpif.h
  mpif_types.h
  mpif_constants.h
  mpif_functions.h
  mpitrampolinef.h
  # Implementation
  mpitrampoline.c
  mpi_functions.c
  # mpiabi_function_pointers.c
)
target_compile_options(mpitrampoline PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(
  mpitrampoline
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
  PRIVATE ../mpiabi
)
target_link_libraries(mpitrampoline PRIVATE ${CMAKE_DL_LIBS})
list(APPEND public_headers
  mpi.h
  mpi_types.h
  mpi_constants.h
  mpi_functions.h
  mpiabi_function_pointers.h
  ${CMAKE_CURRENT_BINARY_DIR}/mpitrampoline.h
  ../mpiabi/mpiabi_types.h
  ../mpiabi/mpiabi_constants.h
  ../mpiabi/mpiabi_version.h
  mpif.h
  mpif_types.h
  mpif_constants.h
  mpif_functions.h
  mpitrampolinef.h
  ../mpiabi/mpiabif_types.h
  ../mpiabi/mpiabif_constants.h
  ../mpiabi/mpiabif_functions.h
)
set_target_properties(mpitrampoline PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${SOVERSION}
  PUBLIC_HEADER "${public_headers}"
)

install(TARGETS mpitrampoline EXPORT MPItrampolineTargets)
