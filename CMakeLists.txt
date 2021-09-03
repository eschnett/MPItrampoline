#[[
rm -rf build $HOME/src/c/MPIstuff/mpitrampoline
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=gcc-mp-11 -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline
cmake --build build && cmake --install build



module load cmake
rm -rf build $HOME/src/c/MPIstuff/mpitrampoline
cmake -S . -B build -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_BUILD_TYPE=Debug=OFF -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline
cmake --build build && cmake --install build
]]



cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPItrampoline VERSION 2.0.0
  DESCRIPTION "MPI trampoline"
  HOMEPAGE_URL "https://github.com/eschnett/MPItrampoline"
  LANGUAGES C Fortran
  )

set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/mod_files)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

configure_file(mpi_version.h.in mpi_version.h @ONLY)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpi_version.h"
  DESTINATION include
  )

add_custom_command(
  OUTPUT mpi_declarations.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_declarations.py >mpi_declarations.h
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_declarations.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions.py
  )
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpi_declarations.h"
  DESTINATION include
  )

add_custom_command(
  OUTPUT mpi_definitions.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_definitions.py >mpi_definitions.h
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_definitions.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions_fortran.py
  )

add_custom_command(
  OUTPUT mpi_initializations.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_initializations.py >mpi_initializations.h
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_initializations.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions_fortran.py
  )

add_custom_command(
  OUTPUT mpi_declarations_fortran.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_declarations_fortran.py >mpi_declarations_fortran.h
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_declarations_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants_fortran.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions_fortran.py
  )
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpi_declarations_fortran.h"
  DESTINATION include
  )

add_custom_command(
  OUTPUT mpi_declarations_fortran90.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_declarations_fortran90.py >mpi_declarations_fortran90.h
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_declarations_fortran90.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants_fortran.py
  # ${CMAKE_CURRENT_SOURCE_DIR}/mpi_functions_fortran.py
  )
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpi_declarations_fortran90.h"
  DESTINATION include
  )

add_custom_command(
  OUTPUT mpi_initializations_fortran90.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_initializations_fortran90.py >mpi_initializations_fortran90.h
  DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/generate_mpi_initializations_fortran90.py
  ${CMAKE_CURRENT_SOURCE_DIR}/mpi_constants_fortran.py
  )

add_library(mpi
  mpiabi.h
  mpi.c mpi.h mpi_version.h mpi_declarations.h mpio.h mpi_definitions.h mpi_initializations.h
  mpif.h mpi_declarations_fortran.h
  mpi.f90 mpi_declarations_fortran90.h mpitrampoline_initialize_fortran90.f90 mpi_initializations_fortran90.h
  mpi_f08.f90 mpitrampoline_initialize_fortran08.f90
  )
target_include_directories(mpi PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(mpi PUBLIC ${CMAKE_DL_LIBS})
set_target_properties(mpi PROPERTIES
  VERSION ${PROJECT_VERSION}
  # SOVERSION 2.0.0
  # TODO: Add mpi-version.h etc. as public headers instead of installing them manually
  PUBLIC_HEADER "mpi.h;mpiabi.h;mpio.h;mpif.h"
  )
install(TARGETS mpi EXPORT MPItrampolineTargets)
install(DIRECTORY ${CMAKE_Fortran_MODULE_DIRECTORY}/ DESTINATION include)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfigVersion.cmake
  VERSION ${VERSION}
  COMPATIBILITY SameMajorVersion
  )
install(
  EXPORT MPItrampolineTargets
  FILE MPItrampolineTargets.cmake
  NAMESPACE MPItrampoline::
  DESTINATION lib/cmake/MPItrampoline
  )
configure_file(MPItrampolineConfig.cmake.in MPItrampolineConfig.cmake @ONLY)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfigVersion.cmake"
  DESTINATION lib/cmake/MPItrampoline
  )

configure_file(MPItrampoline.pc.in MPItrampoline.pc @ONLY)
install(
  FILES ${CMAKE_BINARY_DIR}/MPItrampoline.pc
  DESTINATION lib/pkgconfig
  )

# TODO: Bake in current C/C++/Fortran compilers, not default names
configure_file(mpicc.in mpicc @ONLY)
configure_file(mpicxx.in mpicxx @ONLY)
configure_file(mpifc.in mpifc @ONLY)
configure_file(mpifort.in mpifort @ONLY)
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/mpicc ${CMAKE_CURRENT_BINARY_DIR}/mpicxx ${CMAKE_CURRENT_BINARY_DIR}/mpifc ${CMAKE_CURRENT_BINARY_DIR}/mpifort
  DESTINATION bin
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
  )

install(
  FILES mpiexec
  DESTINATION bin
  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
  )
