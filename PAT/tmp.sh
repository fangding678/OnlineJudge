#!/usr/bin/env bash

set -o pipefail
set -o errexit

function func1()
{
    for elem in `ls`
    do
        echo "$elem"
        cp $elem/main.c archive/_${elem}.c || true
        cp $elem/main.cpp archive/_${elem}.cc || true
    #    sed 's/main/func/g' t_archive/$elem > t_archive/_$elem
    done
}

echo "----------------------------------------------------------------------------------------------------"
echo "begin..."
func1
echo "end..."
echo "----------------------------------------------------------------------------------------------------"
