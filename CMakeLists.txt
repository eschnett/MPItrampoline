cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPItrampoline VERSION 5.5.0
  DESCRIPTION "MPI trampoline"
  HOMEPAGE_URL "https://github.com/eschnett/MPItrampoline"
  LANGUAGES NONE
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
set(SOVERSION 5)

option(ENABLE_FORTRAN "Build Fortran MPI bindings" ON)

include(CheckLanguage)
check_language(C)
if(NOT(CMAKE_C_COMPILER))
  message(FATAL_ERROR "No C support")
endif()
set(CMAKE_C_STANDARD 99)
enable_language(C)

check_language(CXX)
if(NOT(CMAKE_CXX_COMPILER))
  message(WARNING "No C++ support")
endif()
enable_language(CXX)

if(ENABLE_FORTRAN)
  check_language(Fortran)
  if(NOT(CMAKE_Fortran_COMPILER))
    message(FATAL_ERROR "No Fortran support")
  endif()
  message(STATUS "Enabling Fortran support")
  enable_language(Fortran)
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
    subroutine attr(buf)
      integer buf
      !dir$ ignore_tkr(tkr) buf
    end
    "
    Fortran_attribute_dir_ignore_tkr
    SRC_EXT f90)
  if(Fortran_attribute_dir_ignore_tkr)
    add_compile_definitions(DIR_IGNORE_TKR=) # enabled
  else()
    add_compile_definitions(DIR_IGNORE_TKR=!) # disabled
  endif()
  check_fortran_source_compiles(
    "
    end
    subroutine attr(buf)
      integer buf
      !gcc$ attributes no_arg_check :: buf
    end
    "
    Fortran_attribute_gcc_attributes_no_arg_check
    SRC_EXT f90)
  if(Fortran_attribute_gcc_attributes_no_arg_check)
    add_compile_definitions(GCC_ATTRIBUTES_NO_ARG_CHECK=) # enabled
  else()
    add_compile_definitions(GCC_ATTRIBUTES_NO_ARG_CHECK=!) # disabled
  endif()
  add_compile_definitions(ENABLE_FORTRAN)
else()
  message(STATUS "Disabling Fortran support")
endif()

if(ENABLE_FORTRAN)
  # Use CMAKE_CURRENT_BINARY_DIR (not CMAKE_BINARY_DIR) so that the path
  # resolves correctly when MPItrampoline is included as a subproject via
  # FetchContent.  CMAKE_BINARY_DIR always points to the top-level build
  # tree, whereas CMAKE_CURRENT_BINARY_DIR follows the currently processed
  # CMakeLists.txt.
  set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)



configure_file(include/mpi_version.h.in include/mpi_version.h @ONLY)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/include/mpi_version.h"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

if(ENABLE_FORTRAN)
  include(CheckTypeSize)
  check_type_size(ptrdiff_t MPITRAMPOLINE_SIZEOF_CPTRDIFF_T LANGUAGE C)
  if(${MPITRAMPOLINE_SIZEOF_CPTRDIFF_T} STREQUAL "" OR
      ${MPITRAMPOLINE_SIZEOF_CPTRDIFF_T} STREQUAL "0")
    message(FATAL_ERROR "Cannot determine sizeof(ptrdiff_t).")
  endif()

  configure_file(mpiabi/mpiabif.h.in include/mpiabif.h @ONLY)
  install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/include/mpiabif.h"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

  configure_file(include/mpif_version.h.in include/mpif_version.h @ONLY)
  install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/include/mpif_version.h"
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

  # configure_file(include/mpi.f90.in include/mpi.f90 @ONLY)
  # install(
  #   FILES "${CMAKE_CURRENT_BINARY_DIR}/include/mpi.f90"
  #   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  #   )
  # 
  # configure_file(include/mpi_f08.f90.in include/mpi_f08.f90 @ONLY)
  # install(
  #   FILES "${CMAKE_CURRENT_BINARY_DIR}/include/mpi_f08.f90"
  #   DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  #   )
endif()

configure_file(src/mpi_defaults.h.in src/mpi_defaults.h @ONLY)

add_custom_command(
  OUTPUT
  include/mpi_decl_constants_c.h
  include/mpi_decl_functions_c.h
  include/mpi_decl_constants_fortran.h
  include/mpi_decl_functions_fortran.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen/gen_decl.py
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/gen/gen_decl.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_constants.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_functions.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_constants_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_functions_fortran.py
  )
install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/include/mpi_decl_constants_c.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/mpi_decl_functions_c.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/mpi_decl_constants_fortran.h"
  "${CMAKE_CURRENT_BINARY_DIR}/include/mpi_decl_functions_fortran.h"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

add_custom_command(
  OUTPUT
  src/mpi_defn_constants_c.h
  src/mpi_defn_functions_c.h
  src/mpi_defn_constants_fortran.h
  src/mpi_defn_functions_fortran.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen/gen_defn.py
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/gen/gen_defn.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_constants.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_functions.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_constants_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_functions_fortran.py
  )

add_custom_command(
  OUTPUT
  src/mpi_init_constants_c.h
  src/mpi_init_functions_c.h
  src/mpi_init_constants_fortran.h
  src/mpi_init_functions_fortran.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/gen/gen_init.py
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/gen/gen_init.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_constants.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_functions.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_constants_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpiabi/mpi_functions_fortran.py
  )

if(ENABLE_FORTRAN)
  add_library(mpitrampoline
    # *** C ***
    # source file
    src/mpi.c
    # header files
    include/mpi.h
    include/mpio.h
    mpiabi/mpiabi.h
    # configured header files
    include/mpi_version.h
    # generated header files
    include/mpi_decl_constants_c.h
    include/mpi_decl_functions_c.h
    # generated source files
    src/mpi_defn_constants_c.h
    src/mpi_defn_functions_c.h
    src/mpi_defn_constants_fortran.h
    src/mpi_defn_functions_fortran.h
    src/mpi_init_constants_c.h
    src/mpi_init_functions_c.h
    src/mpi_init_constants_fortran.h
    src/mpi_init_functions_fortran.h
    # *** Fortran ***
    # source file
    src/init_mpi_f08.f90
    # header files
    include/mpif.h
    include/mpi.F90
    include/mpi_f08.F90
    include/mpiabif.h
    # configured header files
    include/mpif_version.h
    # generated header files
    include/mpi_decl_constants_fortran.h
    include/mpi_decl_functions_fortran.h
    )
  target_include_directories(
    mpitrampoline
    PRIVATE include mpiabi ${CMAKE_CURRENT_BINARY_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/src
    )
  target_link_libraries(mpitrampoline PUBLIC ${CMAKE_DL_LIBS})
  set_target_properties(mpitrampoline PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${SOVERSION}
    # TODO: Add mpi-version.h etc. as public headers instead of installing them manually
    PUBLIC_HEADER "include/mpi.h;include/mpio.h;mpiabi/mpiabi.h;include/mpif.h"
    )
else()
  add_library(mpitrampoline
    # *** C ***
    # source file
    src/mpi.c
    # header files
    include/mpi.h
    include/mpio.h
    mpiabi/mpiabi.h
    # configured header files
    include/mpi_version.h
    # generated header files
    include/mpi_decl_constants_c.h
    include/mpi_decl_functions_c.h
    # generated source files
    src/mpi_defn_constants_c.h
    src/mpi_defn_functions_c.h
    src/mpi_init_constants_c.h
    src/mpi_init_functions_c.h
    )
  target_include_directories(
    mpitrampoline
    PRIVATE include mpiabi ${CMAKE_CURRENT_BINARY_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/src
    )
  target_link_libraries(mpitrampoline PUBLIC ${CMAKE_DL_LIBS})
  set_target_properties(mpitrampoline PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${SOVERSION}
    # TODO: Add mpi-version.h etc. as public headers instead of installing them manually
    PUBLIC_HEADER "include/mpi.h;include/mpio.h;mpiabi/mpiabi.h"
    )
endif()

install(TARGETS mpitrampoline EXPORT MPItrampolineTargets)
if(ENABLE_FORTRAN)
  install(
    FILES
    ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi.mod
    ${CMAKE_Fortran_MODULE_DIRECTORY}/mpi_f08.mod
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
endif()

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfigVersion.cmake
  VERSION ${VERSION}
  COMPATIBILITY SameMajorVersion
  )
install(
  EXPORT MPItrampolineTargets
  FILE MPItrampolineTargets.cmake
  NAMESPACE MPItrampoline::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MPItrampoline
  )
configure_file(MPItrampolineConfig.cmake.in MPItrampolineConfig.cmake @ONLY)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MPItrampoline
  )

configure_file(MPItrampoline.pc.in MPItrampoline.pc @ONLY)
configure_file(mpi-c.pc.in mpi-c.pc @ONLY)
configure_file(mpi-cxx.pc.in mpi-cxx.pc @ONLY)
configure_file(mpi-fort.pc.in mpi-fort.pc @ONLY)
# Use CMAKE_CURRENT_BINARY_DIR (not CMAKE_BINARY_DIR) for the generated .pc
# files so that the paths resolve correctly when MPItrampoline is included as
# a subproject via FetchContent.  CMAKE_BINARY_DIR always points to the
# top-level build tree, whereas CMAKE_CURRENT_BINARY_DIR follows the currently
# processed CMakeLists.txt.
install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/MPItrampoline.pc
  ${CMAKE_CURRENT_BINARY_DIR}/mpi-c.pc
  ${CMAKE_CURRENT_BINARY_DIR}/mpi-cxx.pc
  ${CMAKE_CURRENT_BINARY_DIR}/mpi-fort.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
  )
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/mpi-c.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
  )

configure_file(bin/mpicc.in bin/mpicc @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpicc
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
  )
if(CMAKE_CXX_COMPILER)
  configure_file(bin/mpicxx.in bin/mpicxx @ONLY)
  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpicxx
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    )
endif()
if(ENABLE_FORTRAN)
  configure_file(bin/mpifc.in bin/mpifc @ONLY)
  configure_file(bin/mpifort.in bin/mpifort @ONLY)
  install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpifc ${CMAKE_CURRENT_BINARY_DIR}/bin/mpifort
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    )
endif()

configure_file(bin/mpiexec.in bin/mpiexec @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/bin/mpiexec
  DESTINATION ${CMAKE_INSTALL_BINDIR}
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
  )
