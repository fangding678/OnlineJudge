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

function batch_copy()
{
    cd ..
    for i in {235..242}
    do
        echo $i
        cmd="cp exercise/_c0xxx.h exercise/_c0${i}.h"
        echo ${cmd}
        eval ${cmd}
    done
}

