#!/bin/bash

# usage: ./addcommit.sh <type> <problem>

echo Compiling uva_README_gen
g++ -std=c++11 utils/uva_prob.cpp -I. -o utils/a.out

echo Generating README.md
pushd utils > /dev/null
pwd
./a.out
popd > /dev/null

git add ${1}/${2}.cpp ${1}/testdata/${2}.in ${1}/testdata/${2}.out
git add uva/README.md
git commit -m "[${1}] ${2}"
# git push origin master
