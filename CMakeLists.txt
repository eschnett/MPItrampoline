#[[
rm -rf build $HOME/src/c/MPIstuff/mpitrampoline
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=gcc-mp-11 -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline
cmake --build build && cmake --install build

env MPITRAMPOLINE_LIB=/Users/eschnett/src/c/MPIstuff/lib/libmpiwrapper.dylib /Users/eschnett/src/c/MPIstuff/bin/mpi-test
/Users/eschnett/src/c/MPIstuff/bin/mpiexec -n 4 /Users/eschnett/src/c/MPIstuff/bin/mpi-test



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
  LANGUAGES C
  )

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# TODO: We don't know how to properly propagate the ${CMAKE_DL_LIBS}
# dependency to other packages when building a static library. We thus
# always build a shared library.
add_library(mpi SHARED mpi.h mpio.h mpif.h mpi-constants.inc mpi-functions.inc mpi-constants-f.inc mpi-functions-f.inc mpi.c)
target_link_libraries(mpi PUBLIC ${CMAKE_DL_LIBS})
set_target_properties(mpi PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION 1
  PUBLIC_HEADER "mpi.h;mpio.h;mpif.h;mpi-constants.inc;mpi-functions.inc"
  )
install(TARGETS mpi EXPORT MPItrampoline)
export(EXPORT MPItrampoline FILE MPItrampolineConfig.cmake)

# write_basic_package_version_file(
#   ${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfigVersion.cmake
#   VERSION ${VERSION}
#   COMPATIBILITY SameMajorVersion
#   )
# install(
#   FILES
#   ${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfig.cmake
#   ${CMAKE_CURRENT_BINARY_DIR}/MPItrampolineConfigVersion.cmake
#   DESTINATION share/MPItrampoline/cmake
#   )

configure_file(MPItrampoline.pc.in MPItrampoline.pc @ONLY)
install(
  FILES ${CMAKE_BINARY_DIR}/MPItrampoline.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
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
