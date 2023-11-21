# docker build --build-arg GITHASH=$(git rev-parse HEAD) --tag mpitrampoline6 --progress plain .
# docker run --interactive --rm --tty mpitrampoline6

FROM ubuntu:23.10

ENV DEBIAN_FRONTEND=noninteractive

# 1. Install dependencies

RUN apt update && \
    apt --yes --no-install-recommends install \
        build-essential \
        ca-certificates \
        cmake \
        git \
        less \
        libmpich-dev \
        ninja-build

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
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build

# 4. Build MPItrampoline

WORKDIR /MPItrampoline/mpitrampoline
RUN cmake -B build -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCMAKE_INSTALL_PREFIX=/usr/local
RUN cmake --build build
RUN cmake --install build

# 5. Run test

WORKDIR /MPItrampoline/test
RUN cc -Wall -g -c hello-world.c
RUN cc -Wall -g -o hello-world hello-world.o -lmpitrampoline
RUN ./hello-world
RUN mpiexec -4 ./hello-world
