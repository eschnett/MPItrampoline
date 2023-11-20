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

configure_file(mpiwrapper.h.in mpiwrapper.h @ONLY)

add_library(mpiwrapper
  mpiwrapper.c
  mpiwrapper.h
)
target_include_directories(
  mpiwrapper
  PUBLIC include ../mpiabi
)
set_target_properties(mpiwrapper PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${SOVERSION}
  # TODO: Add mpi-version.h etc. as public headers instead of installing them manually
  # PUBLIC_HEADER "include/mpi.h;include/mpio.h;mpiabi/mpiabi.h"
)
