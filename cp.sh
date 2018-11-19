#!/bin/bash

# usage: ./cp.sh <type> <problem>

clear

INCLUDE="-I."

if ! [[ "$1" == "uva" ]]; then
	FLAG=-DDBG
fi

g++ -std=c++11 ${INCLUDE} ${FLAG} -Wall ${1}/${2}.cpp -o ${1}/a.out
if [ "$?" == "0" ]; then
	pushd ${1}/ > /dev/null
	echo Running
	./a.out
	echo End
	popd > /dev/null
	./edit.sh ${1} ${2}
fi
