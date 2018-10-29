#!/bin/bash

# usage: ./gen.sh <type> <problem id> [problem name]

if [[ "${1}" == "uva" ]]; then
	JUDGE=$(echo ${1} | tr a-z A-Z)
	touch uva/testdata/${2}.in
	touch uva/testdata/${2}.out
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifndef ONLINE_JUDGE/g" > uva/${2}.cpp
	echo uva/${2} created.
elif [[ "${1}" == "poj" ]]; then
	JUDGE=$(echo ${1} | tr a-z A-Z)
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifdef DBG/g" > poj/${2}.cpp
	touch poj/testdata/${2}.in
	touch poj/testdata/${2}.out
	echo poj/${2} created.
elif [[ "${1}" == "cf" ]]; then
	cat template.cpp | sed -e "s/{judge}/${1^^}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifdef DBG/g" > cf/${2}.cpp
	touch cf/testdata/${2}.in
	touch cf/testdata/${2}.out
	echo cf/${2} created.
elif [[ "${1}" == "hoj" ]]; then
	JUDGE=$(echo ${1} | tr a-z A-Z)
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}/${2}.cpp
	touch ${1}/testdata/${2}.in
	touch ${1}/testdata/${2}.out
	echo ${1}/${2} created.
elif [[ "%{1}" == "toj" ]]; then
	JUDGE=$(echo ${1} | tr a-z A-Z)
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}/${2}.cpp
	touch ${1}/testdata/${2}.in
	touch ${1}/testdata/${2}.out
	echo ${1}/${2} created.
fi
