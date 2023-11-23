# MPItrampoline

* [![CI](https://github.com/eschnett/MPItrampoline/actions/workflows/CI.yml/badge.svg?branch=eschnett/MPItrampoline6)](https://github.com/eschnett/MPItrampoline/actions/workflows/CI.yml)

This is a complete rewrite using the upcoming standard MPI ABI: [Why
and How](http://export.arxiv.org/abs/2308.11214), [proposed
standard](https://github.com/mpiwg-abi/specification-text-draft).

## Current state

Supported MPI standard:
- MPI 4.1, except:
  - MPI tool interface (planned)
  - MPI profiling interface (planned)
  - `MPI_Comm_create_errhandler` (API does not allow forwarding)
  - `MPI_File_create_errhandler` (API does not allow forwarding)
  - `MPI_Pcontrol` (vararg functions cannot be forwarded)
  - `MPI_Session_create_errhandler` (API does not allow forwarding)
  - `MPI_Win_create_errhandler` (API does not allow forwarding)

Tested MPI implementations:
- MPICH
- OpenMPI

Supported languages:
- C
- C++ (using the MPI C standard)
- fixed-form Fortran (aka "Fortran 77"): nascent, via `mpif.h`
- free-form Fortran (aka "Fortran 90"): nascent, via `mpif.h`

Tested CPU architectures:
- amd64
- arm32v5
- arm32v7
- arm64v8
- i386
- mips64le
- ppc64le
- s390x

Tested HPC systems:
- none yet
