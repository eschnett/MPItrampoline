#[[
rm -rf build
cmake -S . -B build -G Ninja -DCMAKE_C_COMPILER=gcc-mp-11 -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff
cmake --build build
cmake --install build

env MPITRAMPOLINE_LIB=/Users/eschnett/src/c/MPIstuff/lib/libmpiwrapper.dylib /Users/eschnett/src/c/MPIstuff/bin/hello
mpiexec-openmpi-gcc11 -n 4 env MPITRAMPOLINE_LIB=/Users/eschnett/src/c/MPIstuff/lib/libmpiwrapper.dylib /Users/eschnett/src/c/MPIstuff/bin/hello
]]

cmake_minimum_required(VERSION 3.12...3.20)
project(
  MPItrampoline VERSION 1.0
  DESCRIPTION "MPI trampoline"
  LANGUAGES C
  )

add_library(mpi STATIC mpi.h mpi.c)
set_target_properties(mpi PROPERTIES PUBLIC_HEADER "mpi.h")

add_executable(hello hello.c)
target_link_libraries(hello mpi)

install(
  TARGETS mpi hello
  )
