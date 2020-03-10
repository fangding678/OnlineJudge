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

function func1()
{
    for elem in `ls t_archive`
    do
        echo "$elem"
    #    sed 's/main/func/g' t_archive/$elem > t_archive/_$elem
    done
}

