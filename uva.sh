#!/bin/bash

echo Compiling
g++ -std=c++17 uva/$1.cpp -o uva/a.out
if [[ $? -eq 0 ]]; then
    echo Running
    ./uva/a.out < uva/testdata/$1.in | tee uva/testdata/$1.out
fi
echo Complete