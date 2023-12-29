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

check_language(CXX)
if(NOT(CMAKE_CXX_COMPILER))
  message(FATAL_ERROR "No C++ support")
endif()
# set(CMAKE_CXX_STANDARD 11)
enable_language(CXX)

check_language(Fortran)
if(NOT(CMAKE_Fortran_COMPILER))
  message(FATAL_ERROR "No C support")
endif()
enable_language(Fortran)

set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
include(GNUInstallDirs)

# Check for Fortran features

include(CheckFortranCompilerFlag)
check_fortran_compiler_flag(-fallow-argument-mismatch Fortran_flag_allow_argument_mismatch)
if(Fortran_flag_allow_argument_mismatch)
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fallow-argument-mismatch")
endif()
check_fortran_compiler_flag(-fcray-pointer Fortran_flag_cray_pointer)
if(Fortran_flag_cray_pointer)
  set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fcray-pointer")
endif()
check_fortran_source_compiles(
  "
  end
  subroutine sub(buf)
    implicit none
    integer buf(*)
  end
  subroutine caller1(buf)
    implicit none
    integer buf(1)
    interface
       subroutine sub(buf)
         implicit none
         integer buf(*)
         !dir$ ignore_tkr(tkr) buf
       end subroutine sub
    end interface
    call sub(buf)
  end subroutine caller1
  subroutine caller2(buf)
    implicit none
    real buf(1)
    interface
       subroutine sub(buf)
         implicit none
         integer buf(*)
         !dir$ ignore_tkr(tkr) buf
       end subroutine sub
    end interface
    call sub(buf)
  end subroutine caller2
  subroutine caller3(buf)
    implicit none
    real buf
    interface
       subroutine sub(buf)
         implicit none
         integer buf(*)
         !dir$ ignore_tkr(tkr) buf
       end subroutine sub
    end interface
    call sub(buf)
  end subroutine caller3
  "
  HAVE_Fortran_attribute_dir_ignore_tkr
  SRC_EXT f90
)
if(HAVE_Fortran_attribute_dir_ignore_tkr)
  set(DIR_IGNORE_TKR "")
else()
  set(DIR_IGNORE_TKR "!disabled ")
endif()
check_fortran_source_compiles(
  "
  end
  subroutine sub(buf)
    implicit none
    !gcc$ attributes no_arg_check :: buf
    integer buf(*)
  end
  subroutine caller1(buf)
    implicit none
    integer buf(1)
    interface
       subroutine sub(buf)
         implicit none
         integer buf(*)
         !gcc$ attributes no_arg_check :: buf
       end subroutine sub
    end interface
    call sub(buf)
  end subroutine caller1
  subroutine caller2(buf)
    implicit none
    real buf(1)
    interface
       subroutine sub(buf)
         implicit none
         integer buf(*)
         !gcc$ attributes no_arg_check :: buf
       end subroutine sub
    end interface
    call sub(buf)
  end subroutine caller2
  subroutine caller3(buf)
    implicit none
    real buf
    interface
       subroutine sub(buf)
         implicit none
         integer buf(*)
         !gcc$ attributes no_arg_check :: buf
       end subroutine sub
    end interface
    call sub(buf)
  end subroutine caller3
  "
  HAVE_Fortran_attribute_gcc_attributes_no_arg_check
  SRC_EXT f90
)
if(HAVE_Fortran_attribute_gcc_attributes_no_arg_check)
  set(GCC_ATTRIBUTES_NO_ARG_CHECK "")
else()
  set(GCC_ATTRIBUTES_NO_ARG_CHECK "!disabled ")
endif()
add_compile_definitions(ENABLE_FORTRAN)

configure_file(include/mpitrampoline.h.in include/mpitrampoline.h @ONLY)
configure_file(include/mpitrampolinef.h.in include/mpitrampolinef.h @ONLY)
configure_file(include/mpif_functions.h.in include/mpif_functions.h @ONLY)
configure_file(src/mpi_f08_functions.F90.in src/mpi_f08_functions.F90 @ONLY)

add_library(mpitrampoline
  # MPI C header files
  include/mpitrampoline.h
  include/mpi.h
  include/mpi_mpitrampoline.h
  include/mpi_types.h
  include/mpi_constants.h
  include/mpi_functions.h
  include/mpi_mpiabi_function_pointers.h
  # MPI Fortran header files
  include/mpitrampolinef.h
  include/mpif.h
  include/mpif_types.h
  include/mpif_constants.h
  include/mpif_functions.h
  # MPI Fortran modules
  src/mpi.F90
  src/mpi_f08.F90
  src/mpi_f08_types.F90
  src/mpi_f08_constants.F90
  src/mpi_f08_functions.F90
  # Implementation
  src/mpitrampoline.c
  src/mpi_functions.c
  src/mpi_functions_fortran.c
  src/mpi_mpiabi_function_pointers.c
  src/mpi_mpiabi_function_pointers_fortran.c
  src/mpi_set_mpiabi_function_pointers.c
  src/mpi_set_mpiabi_function_pointers_fortran.c
  src/mpif_special_functions.F90
)
# target_compile_options(mpitrampoline PRIVATE -Wall -Wextra -Wno-unused-dummy-argument -Wno-unused-parameter)
target_include_directories(
  mpitrampoline
  PRIVATE include ${CMAKE_CURRENT_BINARY_DIR}/include
  PRIVATE ../mpiabi
)
target_link_libraries(mpitrampoline PRIVATE ${CMAKE_DL_LIBS})
list(APPEND public_headers
  ${CMAKE_CURRENT_BINARY_DIR}/include/mpitrampoline.h
  include/mpi.h
  include/mpi_mpitrampoline.h
  include/mpi_types.h
  include/mpi_constants.h
  include/mpi_functions.h
  include/mpi_mpiabi_function_pointers.h
  ../mpiabi/mpiabi_types.h
  ../mpiabi/mpiabi_constants.h
  ../mpiabi/mpiabi_version.h
  ${CMAKE_CURRENT_BINARY_DIR}/include/mpitrampolinef.h
  include/mpif.h
  include/mpif_types.h
  include/mpif_constants.h
  ${CMAKE_CURRENT_BINARY_DIR}/include/mpif_functions.h
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

install(FILES ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi.mod DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi_f08_types.mod DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi_f08_constants.mod DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi_f08_functions.mod DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi_f08_functions_internal.mod DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi_f08.mod DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Install pkgconfig files

configure_file(pkgconfig/MPItrampoline.pc.in pkgconfig/MPItrampoline.pc @ONLY)
configure_file(pkgconfig/mpi-c.pc.in pkgconfig/mpi-c.pc @ONLY)
configure_file(pkgconfig/mpi-cxx.pc.in pkgconfig/mpi-cxx.pc @ONLY)
configure_file(pkgconfig/mpi-fort.pc.in pkgconfig/mpi-fort.pc @ONLY)
install(
  FILES
  ${CMAKE_BINARY_DIR}/pkgconfig/MPItrampoline.pc
  ${CMAKE_BINARY_DIR}/pkgconfig/mpi-c.pc
  ${CMAKE_BINARY_DIR}/pkgconfig/mpi-cxx.pc
  ${CMAKE_BINARY_DIR}/pkgconfig/mpi-fort.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

# Install compiler wrappers

configure_file(bin/mpicc.in bin/mpicc @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpicc
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
configure_file(bin/mpicxx.in bin/mpicxx @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpicxx
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
configure_file(bin/mpifc.in bin/mpifc @ONLY)
configure_file(bin/mpifort.in bin/mpifort @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpifc ${CMAKE_CURRENT_BINARY_DIR}/bin/mpifort
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
