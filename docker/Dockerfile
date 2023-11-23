# docker build --build-arg cpuarch=amd64 --build-arg githash=$(git rev-parse HEAD) --build-arg mpivendor=mpich --tag mpitrampoline6 --progress plain .
# docker run --interactive --rm --tty mpitrampoline6

# amd64, arm32v5, arm32v7, arm64v8, i386, mips64le, ppc64le, riscv64
ARG cpuarch=amd64

FROM ${cpuarch}/debian:12.2

# 1.1. Install dependencies

ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && \
    apt --yes --no-install-recommends install \
        build-essential \
        autoconf \
        automake \
        autotools-dev \
        ca-certificates \
        cmake \
        gengetopt \
        gfortran \
        git \
        less \
        ninja-build

# 1.2. Download OpenMPI test suite

WORKDIR /home/cactus
ADD https://github.com/open-mpi/mpi-test-suite/archive/refs/tags/v1.1.1.tar.gz /home/cactus/mpi-test-suite-1.1.1.tar.gz
RUN tar xzf mpi-test-suite-1.1.1.tar.gz
WORKDIR /home/cactus/mpi-test-suite-1.1.1
RUN ./autogen.sh

# 1.3 Download MPItrampoline

WORKDIR /home/cactus
ARG githash
RUN git clone -b eschnett/MPItrampoline6 https://github.com/eschnett/MPItrampoline && \
    cd MPItrampoline && \
    git checkout ${githash}

# 2.1 Build MPItrampoline

WORKDIR /home/cactus/MPItrampoline/mpitrampoline
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build

# 2.2. Build simple tests

WORKDIR /home/cactus/MPItrampoline/test

RUN /usr/local/bin/mpicc -c hello-world-c.c
RUN /usr/local/bin/mpicc -o hello-world-c hello-world-c.o

RUN /usr/local/bin/mpicxx -c hello-world-cxx.cxx
RUN /usr/local/bin/mpicxx -o hello-world-cxx hello-world-cxx.o

RUN /usr/local/bin/mpifc -c hello-world-f.f
RUN /usr/local/bin/mpifc -o hello-world-f hello-world-f.o

RUN /usr/local/bin/mpifc -c hello-world-f90.f90
RUN /usr/local/bin/mpifc -o hello-world-f90 hello-world-f90.o

# 2.3. Build OpenMPI test suite

WORKDIR /home/cactus/mpi-test-suite-1.1.1
RUN ./configure CC=/usr/local/bin/mpicc
RUN  make -j$(nproc)

# 3.1 Install system MPI

# mpich, openmpi
ARG mpivendor=mpich

RUN apt update && \
    case ${mpivendor} in \
        mpich) pkgs=libmpich-dev;; \
        openmpi) pkgs=libopenmpi-dev;; \
        *) exit 1;; \
    esac && \
    apt-get --yes --no-install-recommends install ${pkgs}

# 3.2 Build MPIwrapper

WORKDIR /home/cactus/MPItrampoline/mpiwrapper
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_C_COMPILER=mpicc \
        -DCMAKE_Fortran_COMPILER=mpifort \
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build
ENV MPITRAMPOLINE_LIB=/usr/local/lib/libmpiwrapper.so

# 3.3. Run simple tests

WORKDIR /home/cactus/MPItrampoline/test

RUN ./hello-world-c 1
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./hello-world-c 4

RUN ./hello-world-cxx 1
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./hello-world-cxx 4

RUN ./hello-world-f 1
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./hello-world-f 4

RUN ./hello-world-f90 1
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./hello-world-f90 4

# 3.4. Run OpenMPI test suite

WORKDIR /home/cactus/mpi-test-suite-1.1.1
RUN ./mpi_test_suite
RUN case "${mpivendor}" in \
        mpich) mpiexec_options='';; \
        openmpi) mpiexec_options='--allow-run-as-root --oversubscribe';; \
    esac && \
    mpiexec $mpiexec_options -n 4 ./mpi_test_suite
