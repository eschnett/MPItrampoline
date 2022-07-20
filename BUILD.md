# Redshift

## MacPorts

```sh
# -DBUILD_SHARED_LIBS=ON
rm -rf mpitrampoline $HOME/src/c/MPIstuff/mpitrampoline
cmake -S . -B mpitrampoline -G Ninja -DCMAKE_C_COMPILER=gcc-mp-11 -DCMAKE_CXX_COMPILER=g++-mp-11 -DCMAKE_Fortran_COMPILER=gfortran-mp-11 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline
cmake --build mpitrampoline && cmake --install mpitrampoline
```

# Symmetry

## Ubuntu

```sh
module load cmake
rm -rf mpitrampoline-ubuntu $HOME/src/c/MPIstuff/mpitrampoline-ubuntu
cmake -S . -B mpitrampoline-ubuntu -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=ON -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline-ubuntu
cmake --build mpitrampoline-ubuntu
cmake --install mpitrampoline-ubuntu
```

## gcc-9

```sh
module load cmake
rm -rf mpitrampoline-gcc9 $HOME/src/c/MPIstuff/mpitrampoline-gcc9
cmake -S . -B mpitrampoline-gcc9 -DCMAKE_C_COMPILER=gcc-9 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline-gcc9
cmake --build mpitrampoline-gcc9
cmake --install mpitrampoline-gcc9
```

#

rm -rf build $HOME/src/c/MPIstuff/mpitrampoline-nofortran
cmake -S . -B build -G Ninja -DENABLE_FORTRAN=OFF -DCMAKE_C_COMPILER=gcc-mp-11 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$HOME/src/c/MPIstuff/mpitrampoline-nofortran
cmake --build build && cmake --install build
