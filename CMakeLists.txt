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
  MPItrampoline VERSION 1.1.1
  DESCRIPTION "MPI trampoline"
  LANGUAGES C Fortran
  )

set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/mod_files)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

configure_file(mpi-version.h.in mpi-version.h @ONLY)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpi-version.h"
  DESTINATION include
  )

add_custom_command(
  OUTPUT mpif.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/fortran-cpp.sh ${CMAKE_CURRENT_SOURCE_DIR}/mpif.h.in mpif.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mpif.h.in ${CMAKE_CURRENT_SOURCE_DIR}/mpi-constants-f.inc ${CMAKE_CURRENT_SOURCE_DIR}/mpi-functions-f.inc
  VERBATIM)
add_custom_command(
  OUTPUT mpi.f90
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/fortran-cpp.sh ${CMAKE_CURRENT_SOURCE_DIR}/mpi.f90.in mpi.f90
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mpi.f90.in ${CMAKE_CURRENT_SOURCE_DIR}/mpi-constants-f.inc ${CMAKE_CURRENT_SOURCE_DIR}/mpi-functions-f.inc
  VERBATIM)
add_custom_command(
  OUTPUT mpi_impl.f90
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/fortran-cpp.sh ${CMAKE_CURRENT_SOURCE_DIR}/mpi_impl.f90.in mpi_impl.f90
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mpi.f90.in ${CMAKE_CURRENT_SOURCE_DIR}/mpi-constants-f.inc ${CMAKE_CURRENT_SOURCE_DIR}/mpi-functions-f.inc
  VERBATIM)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpif.h" "${CMAKE_CURRENT_BINARY_DIR}/mpi.f90"
  DESTINATION include
  )

# We always need to use static linking on macOS to avoid confusion
# between MPItrampoline MPI and the wrapped MPI: Both define e.g.
# `MPI_Init`, and our (MPItrampoline's) `MPI_Init` must not interpose
# the `MPI_Init` defined by the wrapped MPI.
add_library(
  mpi
  mpi.h mpi-version.h mpio.h
  mpi.c
  mpif.h
  mpi.f90 mpi_impl.f90
  mpi_f08.f90 mpi_f08_impl.f90
  mpi-constants.inc mpi-functions.inc mpi-constants-f.inc mpi-functions-f.inc
  )
target_include_directories(mpi PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(mpi PUBLIC ${CMAKE_DL_LIBS})
set_target_properties(mpi PROPERTIES
  VERSION ${PROJECT_VERSION}
  # SOVERSION 1
  # TODO: Add mpi-version.h and mpif.h as public headers instead of installing them manually
  PUBLIC_HEADER "mpi.h;mpio.h;mpi-constants.inc;mpi-functions.inc"
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
