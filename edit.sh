#!/bin/bash

platform=$(uname)
editor=

if [[ "${platform}"=="Linux" ]]; then
	editor=subl
elif [[ "${platform}"=="Darwin" ]]; then
	editpr=open -a 'Sublime Text'
fi

$editor ${1}/${2}.cpp ${1}/testdata/${2}.in ${1}/testdata/${2}.out