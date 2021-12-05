#!/usr/bin/env bash

set -o pipefail
set -o errexit

echo "build begin..."

mkdir build || true
cd build
cmake ..
make -j2

echo "build end..."

echo "----------------------------------------------------------------------------------------------------"
echo "run main begin..."
./main
echo "run main end..."
echo "----------------------------------------------------------------------------------------------------"


