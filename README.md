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
  - `MPI_Comm_create_errhandler` (vararg functions cannot be forwarded)
  - `MPI_File_create_errhandler` (vararg functions cannot be forwarded)
  - `MPI_Pcontrol` (vararg functions cannot be forwarded)
  - `MPI_Session_create_errhandler` (vararg functions cannot be forwarded)
  - `MPI_Win_create_errhandler` (vararg functions cannot be forwarded)

Successfully tested MPI implementations:
- MPICH
- OpenMPI

Supported languages:
- C
- C++ (using the MPI C standard)
- fixed-form Fortran (aka "Fortran 77"): nascent, via `mpif.h`
- free-form Fortran (aka "Fortran 90"): nascent, via `mpif.h`

Successfully tested CPU architectures:
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

## Notes

The MPI ABI reserves handles in the range 0...0x3fff (16383). The
underlying MPI implementation might use this range as well. This case
is currently detected but not yet handled.

There is a hardcoded limit on the number of operators that can be
created via `MPI_Op_create` (and `MPI_Op_create_c`). This limit can be
increased if necessary.

`MPI_Comm_idup` (and `MPI_Comm_idup_with_info`) are awkward -- they
require attaching clean-up actions to these requests. Each completed
request then needs to be checked whether it has a cleanup action
attached to it. There is a fast-path; let's see how expensive this is.
