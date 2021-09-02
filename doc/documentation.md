# MPItrampoline

[MPItrampoline](https://github.com/eschnett/MPItrampoline) is an MPI
implementation that works by forwarding all MPI calls to another MPI
library, which can be chosen at run time. This make it much easier to
build software on HPC systems, where one often cannot build and
install one's own MPI library.

## Background

[MPI](https://www.mpi-forum.org) is the de-facto standard for
inter-node communication on HPC systems, and has been for the past 25
years. While highly successful, MPI is a standard for source code (it
defines an [API](https://en.wikipedia.org/wiki/API)), and is not a
standard defining binary compatibility (it does not define an
[ABI](https://en.wikipedia.org/wiki/Application_binary_interface)).
This means that applications running on HPC systems need to be
compiled anew on every system. This is tedious, since the software
that is available on every HPC system is slightly different. Modern
approaches based on Docker or on statically linked binaries do not
work.

MPI libraries are different from most other libraries (such as FFTW,
HDF5, PETSc): to run efficiently, MPI needs to access the high-speed
networking hardware. Therefore, MPI is usually either distributed with
the operating system (Cray) or is installed by system administrators.
CUDA faces a similar issue, as it needs to access the GPU hardware.
CUDA solves this by being distributed in two pieces: The CUDA driver,
which needs to be installed by a system administrator, and the CUDA
toolkit, which can be installed by anybody. As long as a CUDA driver
is installed on the system, one can bring one's own CUDA toolkit. MPI
libraries are, unfortunately, not split into two pieces like this, and
one can therefore not use one's own MPI library. On each HPC system,
one needs to compile applications from scratch, using the MPI
libraries that are installed there, and (by transitivity) using the
C++ and Fortran compilers that where used to build these MPI
libraries. This leads to much headache and suffering.

## How it works

MPItrampoline aims to address this. It comes in two pieces,
*MPIwrapper* and *MPItrampoline* itself. MPItrampoline is highly
portable, and one can build applications against it. It is possible to
create statically linked, portable binaries (within the usual
limitations), and download and run them on HPC systems.

At run time, MPItrampoline needs access a real MPI implementation. For
each MPI implementation that is to be used with MPItrampoline, one
needs to build the MPIwrapper library, which links against the real
MPI implementation. MPItrampoline and MPIwrapper communicate via an
*MPI ABI* that effectively isolates applications from system-dependent
MPI implementations. MPItrampoline and MPIwrapper can be built by
different compilers.

## Example

We use the following scenario as example: We have an application that
uses FFTW, HDF5, and MPI. The application is written mostly in C++
with some kernels in Fortran and some glue code in C. Both FFTW and
HDF5 also use MPI. For consistency, it will be necessary to build all
software (FFTW, HDF5, MPI, and the application) with the same C, C++,
and Fortran compilers, and both FFTW and HDF5 need to be built using
the same MPI library as Cactus.

### Current state

Usually, one has to go through the following steps for each HPC system
where the application should be installed:

- Choose an MPI implementation from among those available on the
  system. This determines which C, C++, and Fortran compilers need to
  be used.
- Check whether there is a matching FFTW library available on the
  system. It must be build by the same compilers, and must be using
  the same MPI library. If none is there (or if it is too old), one
  has to build and install FFTW oneself (or ask the system
  administrators for help).
- Ditto for HDF5. HDF5 has many more configuration options that FFTW,
  and it is less likely that a matching version is available.
- Finally, one configures one's application (here: Cactus) to uses
  these compilers and these FFTW, HDF5, and MPI libraries.

When the application needs to be installed on a different system (a
student's laptop, a workstation, a different HPC system, ...), then
all these steps need to be repeated. When researchers want to make
changes to the application, then each member of the research group
needs to install the application by themselves, and needs to acquire
the respective system administration skills.

This is a very frustrating experience. The complexity in these steps
is, in my opinion, one of the largest stumbling blocks for new HPC
users, and is one of the main reasons why HPC remains a niche field.
It takes a lot of experience to successfully install software on HPC
systems.

### MPItrampoline

With MPItrampoline, this is much simplified:

- Start out by choosing a C, C++, and Fortran compiler. You are free
  to choose a modern C++ compiler if needed, or stay away from
  vendor-provided compilers that are difficult to use.
- Build MPItrampoline
- Build FFTW
- Build HDF5
- Build the application

One is free to

THIS DOESN'T LOOK MUCH SIMPLER
