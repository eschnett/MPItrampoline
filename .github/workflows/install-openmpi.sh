#!/bin/bash

set -euxo pipefail

wget https://download.open-mpi.org/release/open-mpi/v5.0/openmpi-5.0.0.tar.bz2
tar xjf openmpi-5.0.0.tar.bz2
cd openmpi-5.0.0
# We don't want to deal with the `rpath` for the shared libraries
./configure --enable-shared=no --enable-static=yes
make -j$(nproc)
sudo make install
