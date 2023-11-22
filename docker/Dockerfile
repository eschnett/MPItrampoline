# docker build --build-arg cpuarch=amd64 --build-arg GITHASH=$(git rev-parse HEAD) --build-arg mpivendor=MPICH --tag mpitrampoline6 --progress plain .
# docker run --interactive --rm --tty mpitrampoline6

# amd64, arm32v5, arm32v7, arm64v8, i386, mips64le, ppc64le, riscv64
ARG cpuarch=amd64

FROM ${cpuarch}/debian:12.2

# MPICH, OpenMPI
ARG mpivendor=MPICH

# 1. Install dependencies

ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && \
    apt --yes --no-install-recommends install \
        build-essential \
        ca-certificates \
        cmake \
        git \
        less \
        ninja-build

# Install system MPI
RUN case $mpivendor in \
        MPICH) pkgs=libmpich-dev;; \
        OpenMPI) pkgs=libopenmpi-dev;; \
        *) exit 1;; \
    esac && \
    apt-get --yes --no-install-recommends install ${pkgs}

# 2. Download MPItrampoline

ARG GITHASH
RUN git clone -b eschnett/MPItrampoline6 https://github.com/eschnett/MPItrampoline && \
    cd MPItrampoline && \
    git checkout ${GITHASH}

# 3. Build MPIwrapper

WORKDIR /MPItrampoline/mpiwrapper
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_C_COMPILER=mpicc \
        -DCMAKE_CXX_COMPILER=mpic++ \
        -DCMAKE_Fortran_COMPILER=mpifort \
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build
ENV MPITRAMPOLINE_LIB=/usr/local/lib/libmpiwrapper.so

# 4. Build MPItrampoline

WORKDIR /MPItrampoline/mpitrampoline
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build

# 5. Run test

WORKDIR /MPItrampoline/test

RUN /usr/local/bin/mpicc -c hello-world.c
RUN /usr/local/bin/mpicc -o hello-world hello-world.o
RUN ./hello-world
RUN mpiexec -n 4 ./hello-world

RUN /usr/local/bin/mpifc -c hello-world-fortran.f90
RUN /usr/local/bin/mpifc -o hello-world-fortran hello-world-fortran.o
RUN ./hello-world-fortran
RUN mpiexec -n 4 ./hello-world-fortran
