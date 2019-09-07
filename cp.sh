#!/bin/bash

# usage: ./cp.sh <type> <problem>

clear

INCLUDE="-I."

DIR=.
SRC=
PID=

if ! [[ "$1" == "uva" ]]; then
	FLAG=-DDBG
fi

if [[ "$1" == "vjudge" ]]; then
	DIR="${DIR}/vjudge"

	case "$2" in
	# Contest problem
	# cp.sh vjudge cp <Contest> <pid>
	cp)
		DIR="${DIR}/${3}"
		SRC="${DIR}/${4}.cpp"
		PID="${PID}${4}"
	;;
	# Problem
	# cp.sh vjudge p <pid>
	p)
		SRC="${DIR}/${3}.cpp"
		PID="${PID}${3}"
	;;
	esac
fi

# cp.sh hoj <pid>
if [[ "$1" == "hoj" ]]; then
	DIR="${DIR}/hoj"
	SRC="${DIR}/${2}.cpp"
	PID="${PID}${2}"
fi

if [[ "$1" == "zeoj" ]]; then
	DIR="${DIR}/zeoj"
	SRC="${DIR}/${2}.cpp"
	PID="${PID}${2}"
fi

# echo ${DIR}
# echo ${SRC}
# echo ${PID}

g++ -std=c++11 ${INCLUDE} ${FLAG} -Wall "${SRC}" -o "${DIR}/a.out"
if [ "$?" == "0" ]; then
	pushd "${DIR}" > /dev/null
	echo Running
	./a.out
	echo End
	popd > /dev/null
	./edit.sh "${DIR}" "${PID}"
fi
