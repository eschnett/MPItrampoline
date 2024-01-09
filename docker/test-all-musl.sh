#!/bin/bash

cpuarchs="amd64 arm32v5 arm32v7 arm64v8 i386 ppc64le riscv64 s390x"
# mpich does not build with musl?
# mpivendors="mpich openmpi"
mpivendors="openmpi"

githash=$(git rev-parse HEAD)
for cpuarch in ${cpuarchs}; do
    for mpivendor in ${mpivendors}; do
        tag="mpi-test-suite-alpine.libc-musl.cpuarch-${cpuarch}.mpivendor-${mpivendor}"
        rm -f "${tag}".*
        {
	    docker build --build-arg cpuarch="${cpuarch}" --build-arg githash="${githash}" --build-arg mpivendor="${mpivendor}" --file Dockerfile.musl --progress plain --tag "mpitrampoline6-musl-${cpuarch}-${mpivendor}" . &&
                : >"${tag}.succeeded" ||
                    : >"${tag}.failed";
        } 2>&1 |
            tee "${tag}.log"
    done
done
