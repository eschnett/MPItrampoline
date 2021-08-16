#[[
rm -rf build $HOME/src/c/MPIstuff/mpitrampoline
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=gcc-mp-11 -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline
cmake --build build && cmake --install build



export PATH=$HOME/src/spack/opt/spack/linux-ubuntu18.04-skylake_avx512/gcc-11.2.0/cmake-3.21.1-ztbpwc6mr65mqagnikcuuiifn3ox6btv/bin:$PATH
rm -rf build ../MPIstuff
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff
cmake --build build && cmake --install build

env MPITRAMPOLINE_LIB=$HOME/src/c/MPIstuff-openmpi/lib/libmpiwrapper.so /cm/shared/apps/openmpi/gcc-9/64/4.1.0/bin/mpiexec -n 4 -mca oob_tcp_if_include lo --mca btl self,vader $HOME/src/c/MPIstuff/bin/mpi-test

env MPITRAMPOLINE_LIB=$HOME/src/c/MPIstuff-intel/lib/libmpiwrapper.so /cm/shared/apps/intel/mpi/2021.1.1/bin/mpiexec -n 4 $HOME/src/c/MPIstuff/bin/mpi-test
]]



cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPItrampoline VERSION 1.0.0
  DESCRIPTION "MPI trampoline"
  LANGUAGES C Fortran
  )

set(CMAKE_Fortran_MODULE_DIRECTORY ${CMAKE_BINARY_DIR}/mod_files)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_custom_command(
  OUTPUT mpif.h
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/fortran-cpp.sh ${CMAKE_CURRENT_SOURCE_DIR}/mpif.h.in mpif.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/mpif.h.in ${CMAKE_CURRENT_SOURCE_DIR}/mpi-constants-f.inc ${CMAKE_CURRENT_SOURCE_DIR}/mpi-functions-f.inc
  VERBATIM)
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/mpif.h"
  DESTINATION include
  )

# We always use static linking to avoid confusion between
# MPItrampoline MPI and the wrapped MPI: Both define e.g. `MPI_Init`,
# and our (MPItrampoline's) `MPI_Init` must not interpose the
# `MPI_Init` defined by the wrapped MPI.
add_library(
  mpitrampoline STATIC
  mpi.h mpio.h mpif.h
  mpi-constants.inc mpi-functions.inc mpi-constants-f.inc mpi-functions-f.inc
  mpi.c
  mpi.f90 mpi_impl.f90 mpi_impl_integer_0.f90 mpi_impl_integer_1.f90
  mpi_f08.f90 mpi_f08_impl.f90 mpi_f08_impl_integer_0.f90 mpi_f08_impl_integer_1.f90
  )
target_include_directories(mpitrampoline PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(mpitrampoline PUBLIC ${CMAKE_DL_LIBS})
set_target_properties(mpitrampoline PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  # TODO: Add mpif.h as public header instead of installing it manually
  PUBLIC_HEADER "mpi.h;mpio.h;mpi-constants.inc;mpi-functions.inc"
  )
install(TARGETS mpitrampoline EXPORT MPItrampolineTargets)
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
