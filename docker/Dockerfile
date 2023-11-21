# docker build --build-arg GITHASH=$(git rev-parse HEAD) --tag mpitrampoline6 --progress plain .

FROM ubuntu:23.10

ENV DEBIAN_FRONTEND=noninteractive

# 1. Install dependencies

RUN apt update && \
    apt --yes --no-install-recommends install \
        build-essential \
        ca-certificates \
        cmake \
        git \
        ninja-build

# 2. Build MPItrampoline

ARG GITHASH
RUN git clone -b eschnett/MPItrampoline6 https://github.com/eschnett/MPItrampoline && \
    cd MPItrampoline && \
    git checkout ${GITHASH}
WORKDIR MPItrampoline/mpitrampoline
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build

WORKDIR ../test
RUN cc -Wall -g -c hello-world.c
RUN cc -Wall -g -o hello-world hello-world.o -lmpitrampoline

# 3. 



# name: CI
# 
# on:
#   push:
#     branches: [main]
#   pull_request:
#     branches: [main]
# 
# env:
#   BUILD_TYPE: Debug
# 
# jobs:
#   mpiwrapper:
#     strategy:
#       matrix:
#         os: [ubuntu-22.04]
#         # OpenMPI is too far away from MPI 4
#         # mpi: [MPICH, OpenMPI]
#         mpi: [MPICH]
# 
#     runs-on: ${{matrix.os}}
# 
#     steps:
#     - uses: actions/checkout@v4
# 
#     - name: Install ${{matrix.mpi}}
#       run: |
#         case "${{matrix.mpi}}" in
#             MPICH)
#                 sudo apt-get update
#                 sudo apt-get install libmpich-dev
#                 ;;
#             OpenMPI)
#                 ;;
#         esac
# 
#     - name: Restore dependencies
#       id: cache
#       uses: actions/cache/restore@v3
#       with:
#         path: /usr/local
#         key: ${{runner.os}}-${{matrix.mpi}}-dependencies
# 
#     - name: Build ${{matrix.mpi}}
#       if: steps.cache.outputs.cache-hit != 'true'
#       run: |
#         case "${{matrix.mpi}}" in
#             MPICH)
#                 ;;
#             OpenMPI)
#                 ./.github/workflows/install-openmpi.sh
#                 ;;
#         esac
# 
#     - name: Save dependencies
#       uses: actions/cache/save@v3
#       with:
#         path: /usr/local
#         key: ${{steps.cache.cache-primary-key}}
# 
#     - name: Configure
#       working-directory: ${{github.workspace}}/mpiwrapper
#       run: |
#         cmake \
#             -B ${{github.workspace}}/build \
#             -DCMAKE_BUILD_TYPE=Debug \
#             -DCMAKE_C_COMPILER=mpicc \
#             -DCMAKE_INSTALL_PREFIX=$HOME/mpiwrapper-${{matrix.mpi}}
# 
#     - name: Build
#       working-directory: ${{github.workspace}}/mpiwrapper
#       run: cmake --build ${{github.workspace}}/build --verbose
# 
#     # - name: Test
#     #   working-directory: ${{github.workspace}}/build
#     #   run: ctest -C ${{env.BUILD_TYPE}}
# 
#     - name: Install
#       working-directory: ${{github.workspace}}/mpiwrapper
#       run: cmake --install ${{github.workspace}}/build
# 
#     - name: Test
#       run: |
#         cat >hello.c <<EOF
#         %:include <mpi.h>
#         %:include <stdio.h>
#         int main(int argc, char **argv) {
#           MPI_Init(&argc, &argv);
#           int size, rank;
#           MPI_Comm_size(MPI_COMM_WORLD, &size);
#           MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#           for (int n=0; n<size; ++n) {
#             if (rank == n)
#               printf("Hello from process %d/%d\n", rank, size);
#             MPI_Barrier(MPI_COMM_WORLD);
#           }
#           MPI_Finalize();
#           return 0;
#         }
#         EOF
#         cc -I$HOME/mpitrampoline/include -c hello.c
#         cc -L$HOME/mpitrampoline/lib -o hello hello.o -lmpitrampoline
#         mpiexec -n 3 ./hello
# 
#   mpitrampoline:
#     strategy:
#       matrix:
#         os: [ubuntu-22.04]
#         shared: [shared-off, shared-on]
# 
#     runs-on: ${{matrix.os}}
# 
#     steps:
#     - uses: actions/checkout@v4
# 
#     - name: Configure
#       working-directory: ${{github.workspace}}/mpitrampoline
#       run: |
#         shared=$(echo ${{matrix.shared}} | sed -e 's/shared-//')
#         cmake \
#             -B ${{github.workspace}}/build \
#             -DBUILD_SHARED_LIBS=${shared} \
#             -DCMAKE_BUILD_TYPE=Debug \
#             -DCMAKE_INSTALL_PREFIX=$HOME/mpitrampoline
# 
#     - name: Build
#       working-directory: ${{github.workspace}}/mpitrampoline
#       run: cmake --build ${{github.workspace}}/build --verbose
# 
#     # - name: Test
#     #   working-directory: ${{github.workspace}}/build,
#     #   run: ctest -C ${{env.BUILD_TYPE}}
# 
#     - name: Install
#       working-directory: ${{github.workspace}}/mpitrampoline
#       run: cmake --install ${{github.workspace}}/build
# 
#     # - name: Test
#     #   run: |
#     #     cat >hello.c <<EOF
#     #     %:include <mpi.h>
#     #     %:include <stdio.h>
#     #     int main(int argc, char **argv) {
#     #       MPI_Init(&argc, &argv);
#     #       int size, rank;
#     #       MPI_Comm_size(MPI_COMM_WORLD, &size);
#     #       MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#     #       for (int n=0; n<size; ++n) {
#     #         if (rank == n)
#     #           printf("Hello from process %d/%d\n", rank, size);
#     #         MPI_Barrier(MPI_COMM_WORLD);
#     #       }
#     #       MPI_Finalize();
#     #       return 0;
#     #     }
#     #     EOF
#     #     cc -I$HOME/mpitrampoline/include -c hello.c
#     #     cc -L$HOME/mpitrampoline/lib -o hello hello.o -lmpitrampoline
#     #     mpiexec -n 3 ./hello
