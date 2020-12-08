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

function batch_process()
{
    cd ..
    for elem in archive/*
    do
        elem1=${elem:0:9}c${elem:10}
        elem2=${elem1/cpp/h}
        echo "$elem2"
#        mv ${elem} ${elem2}
    #    sed 's/main/func/g' t_archive/$elem > t_archive/_$elem
    done
}

