# docker build --build-arg cpuarch=amd64 --build-arg githash=$(git rev-parse HEAD) --build-arg mpivendor=mpich --tag mpitrampoline6 --progress plain .
# docker run --interactive --rm --tty mpitrampoline6

# amd64, arm32v5, arm32v7, arm64v8, i386, mips64le, ppc64le, riscv64
ARG cpuarch=amd64

FROM ${cpuarch}/debian:12.2

# mpich, openmpi
ARG mpivendor=mpich

# 1. Install dependencies

ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && \
    apt --yes --no-install-recommends install \
        build-essential \
        ca-certificates \
        cmake \
        gfortran \
        git \
        less \
        ninja-build

# Install system MPI
RUN case ${mpivendor} in \
        mpich) pkgs=libmpich-dev;; \
        openmpi) pkgs=libopenmpi-dev;; \
        *) exit 1;; \
    esac && \
    apt-get --yes --no-install-recommends install ${pkgs}

# 2. Download MPItrampoline

ARG githash
RUN git clone -b eschnett/MPItrampoline6 https://github.com/eschnett/MPItrampoline && \
    cd MPItrampoline && \
    git checkout ${githash}

# 3. Build MPIwrapper

WORKDIR /MPItrampoline/mpiwrapper
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_C_COMPILER=mpicc \
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
RUN ./hello-world 1
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./hello-world 4

RUN /usr/local/bin/mpifc -c hello-world-fortran.f90
RUN /usr/local/bin/mpifc -o hello-world-fortran hello-world-fortran.o
RUN ./hello-world-fortran
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./hello-world-fortran
