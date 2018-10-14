#!/bin/bash

# usage: ./addcommit.sh <type> <problem>

git add ${1}/${2}.cpp ${1}/testdata/${2}.in ${1}/testdata/${2}.out
git commit -m "${1}/${2}"
git push origin master
