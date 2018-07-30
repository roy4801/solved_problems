#!/bin/bash

clear
g++ uva/${1}.cpp -o uva/a.out
if [ "$?" == "0" ]; then
	pushd uva/ > /dev/null
	echo Running
	./a.out
	echo End
	popd > /dev/null
	./edit.sh ${1}
fi
