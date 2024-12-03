#!/bin/bash

chec_err() {
    if ! [[ $1 -eq 0 ]]; then
        exit $1
    fi
}

g++ -std=c++20 day$1.cpp -o day$1
chec_err $?

SUFFIX=${1//[^0-9]/}
./day$1 < day${SUFFIX}.in > day${SUFFIX}.out
chec_err $?

less day${SUFFIX}.out

