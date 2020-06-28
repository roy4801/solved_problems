#!/bin/bash

function usage_msg()
{
    echo "$0 <cp|gen>"
    echo "    cp    compile and run"
    echo "   gen    generate"
}

[[ -n "$1" ]] && usage_msg

function compile_and_run()
{
    echo Compiling
    g++ -std=c++17 uva/$1.cpp -o uva/a.out
    if [[ $? -eq 0 ]]; then
        echo Running
        ./uva/a.out < uva/testdata/$1.in | tee uva/testdata/$1.out
    fi
    echo Complete
}

compile_and_run $1 $2
