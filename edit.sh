#!/bin/bash

platform=$(uname)

if [[ "${platform}"=="Linux" ]]; then
	subl uva/${1}.cpp uva/testdata/${1}.in uva/testdata/${1}.out
elif [[ "${platform}"=="Darwin" ]]; then
	open -a 'Sublime Text' uva/${1}.cpp uva/testdata/${1}.in uva/testdata/${1}.out
fi

