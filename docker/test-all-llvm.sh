#!/bin/bash

cpuarchs="amd64 arm32v5 arm32v7 arm64v8 i386 mips64le ppc64le riscv64 s390x"
mpivendors="mpich openmpi"

githash=$(git rev-parse HEAD)
for cpuarch in ${cpuarchs}; do
    for mpivendor in ${mpivendors}; do
        tag="mpi-test-suite-debian.compiler-llvm.cpuarch-${cpuarch}.mpivendor-${mpivendor}"
        rm -f "${tag}".*
        {
	    docker build --build-arg cpuarch="${cpuarch}" --build-arg githash="${githash}" --build-arg mpivendor="${mpivendor}" --file Dockerfile.llvm --progress plain --tag "mpitrampoline6-llvm-${cpuarch}-${mpivendor}" . &&
                : >"${tag}.succeeded" ||
                    : >"${tag}.failed";
        } 2>&1 |
            tee "${tag}.log"
    done
done
