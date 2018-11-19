#!/bin/bash

# usage: ./gen.sh <type> <problem id> [problem name]

JUDGE=$(echo ${1} | tr a-z A-Z)

if [[ "${1}" == "uva" ]]; then
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifndef ONLINE_JUDGE/g" > uva/${2}.cpp
else
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}/${2}.cpp
fi

# echo >> ${1}/README.md
echo "* [ ] ${2} - ${3}" >> ${1}/README.md
touch ${1}/testdata/${2}.in
touch ${1}/testdata/${2}.out
echo ${1}/${2} created.