# MPItrampoline

* [![GitHub
  CI](https://github.com/eschnett/MPIwrapper/actions/workflows/CI.yml/badge.svg)](https://github.com/eschnett/MPIwrapper/actions)
* [![GitHub
  CI](https://github.com/eschnett/MPItrampoline/actions/workflows/CI.yml/badge.svg)](https://github.com/eschnett/MPItrampoline/actions)
* [![GitHub
  CI](https://github.com/eschnett/MPItest/actions/workflows/CI.yml/badge.svg)](https://github.com/eschnett/MPItest/actions)
* [![GitHub
  CI-integration](https://github.com/eschnett/MPItest/actions/workflows/CI-integration.yml/badge.svg)](https://github.com/eschnett/MPItest/actions)

[MPI](https://www.mpi-forum.org) is the de-facto standard for
inter-node communication on HPC systems, and has been for the past 25
years. While highly successful, MPI is a standard for source code (it
defines an [API](https://en.wikipedia.org/wiki/API)), and is not a
standard defining binary compatibility (it does not define an
[ABI](https://en.wikipedia.org/wiki/Application_binary_interface)).
This means that applications running on HPC systems need to be
compiled anew on every system. This is tedious, since the software
that is available on every HPC system is slightly different.

This project attempts to remedy this. It defines an ABI for MPI, and
provides an MPI implementation based on this ABI. That is,
MPItrampoline does not implement any MPI functions itself, it only
forwards them to a "real" implementation via this ABI. The advantage
is that one can produce "portable" applications that can use any given
MPI implementation. For example, this will make it possible to build
external packages for [Julia](https://julialang.org) via
[Yggdrasil](https://github.com/JuliaPackaging/Yggdrasil) that run
efficiently on almost any HPC system.

A small and simple
[MPIwrapper](https://github.com/eschnett/MPIwrapper) library is used
to provide this ABI for any given MPI installation. MPIwrapper needs
to be compiled for each MPI installation that is to be used with
MPItrampoline, but this is quick and easy.

## Workflow

### Preparing an HPC system

Install MPIwrapper, wrapping the MPI installation you want to use
there. You can install MPIwrapper multiple times if you want to wrap
more than one MPI implementation.

This is usually as simple as
```sh
cmake -S . -B build -DCMAKE_CXX_COMPILER=mpicxx -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX=$HOME/mpiwrapper
cmake --build build
cmake --install build
```
The MPIwrapper libraries remain on the HPC system, they are installed
independently of any application.

### Building an application

Build your application as usual, using MPItrampline as MPI library.

### Running an application

At startup time, MPItrampoline needs to be told which MPIwrapper
library to use. This is done via the environment variable
`MPITRAMPOLINE_LIB`. You also need to use the `mpiexec` (or `mpirun`,
or `srun`, ...) method for the MPI installation that was wrapped via
MPIwrapper.

For example:
```sh
env MPITRAMPOLINE_LIB=$HOME/mpiwrapper/lib/libmpiwrapper.so mpiexec -n 4 ./your-application
```

## Current state

MPItrampoline uses the C preprocessor to create wrapper functions for
each MPI function. This is how `MPI_Send` is wrapped:
```C
FUNCTION(int, Send,
         (const void *buf, int count, MT(Datatype) datatype, int dest, int tag,
          MT(Comm) comm),
         (buf, count, (MP(Datatype))datatype, dest, tag, (MP(Comm))comm))
```

Unfortunately, MPItrampoline does not yet wrap all MPI functions. It
also currently only supports C and not yet Fortran. Your help is
welcome.

Wrapping Cray MPI, Intel MPI, MPICH, Microsoft-MPI, OpenMPI, and
Spectrum MPI should be working with MPItrampoline. (Not all have been
tested.) Certain MPI types, constants, and functions are difficult to
wrap. Theoretically, there could be MPI libraries where it is not
possible to implement the MPI ABI. If you encounter this, please let
me know -- maybe there is a work-around.
