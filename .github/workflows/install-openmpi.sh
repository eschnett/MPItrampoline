#!/bin/sh

set -euxo pipefail

wget https://download.open-mpi.org/release/open-mpi/v5.0/openmpi-5.0.0.tar.bz2
tar xzf openmpi-5.0.0.tar.bz2
cd openmpi-5.0.0
./configure
make -j$(nproc)
make install
