#!/bin/bash
clear
g++ -std=c++11 -I../../ -DDBG -Wall "$1.cpp" -o ./a.out
if [ "$?" == "0" ]; then
	echo Running
	./a.out
	echo End
fi