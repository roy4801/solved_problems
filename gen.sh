#!/bin/bash
#                   $1      $2            $3
# usage: ./gen.sh <type> <problem id> [problem name]

JUDGE=$(echo ${1} | tr a-z A-Z)

# uva
if [[ "${1}" == "uva" ]]; then
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifndef ONLINE_JUDGE/g" > uva/${2}.cpp

# vjudge
elif [[ "${1}" == "vjudge" ]]; then
	case "${2}" in
		# Problem
		# gen.sh vjudge p <pid> <pname>
		p)
		cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${3}/g" -e "s/{pname}/${4}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}/${3}.cpp
		;;
		# Contest
		# gen.sh vjudge c <contest> <url>
		c)
		mkdir -p "${1}"/"${3}"/testdata
		echo "# ${3}" >> "${1}"/"${3}"/README.md
		echo "* [Contest link](${4})" >> "${1}"/"${3}"/README.md
		echo "Vjudge contest [${3}] created."
		exit
		;;
		# Problem in Contest
		# gen.sh vjudge cp <contest> <pid> <pname>
		cp)
		cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${4}/g" -e "s/{pname}/${5}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}/"${3}"/"${4}".cpp
		touch ${1}/"${3}"/testdata/"${4}".in
		touch ${1}/"${3}"/testdata/"${4}".out
		echo "Vjudge problem [$4 - $5] in contest [$3]"
		exit
		;;

		*)
		echo "$0 vjudge <type>"
		exit
		;;
	esac

# Atcoder
# gen.sh atcode <contest> <pid> <pname>
elif [[ "${1}" == "atcoder" ]]; then
	CONTEST=${2}
	PID=${3}
	PNAME=${4}
	PATH="${1}/${CONTEST}"

	[[ ! -d "atcoder/${CONTEST}" ]] && mkdir -p "atcoder/${CONTEST}/testdata"
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${PID}/g" -e "s/{pname}/${PNAME}/g" -e "s/{DEFINE}/#ifdef DBG/g" > "${PATH}/${PID}".cpp
	touch "${PATH}/${CONTEST}/testdata/${PID}.in"
	touch "${PATH}/${CONTEST}/testdata/${PID}.out"

	exit
else
	cat template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${2}/g" -e "s/{pname}/${3}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}/${2}.cpp
fi

# echo >> ${1}/README.md
# echo "* [ ] ${2} - ${3}" >> ${1}/README.md
touch ${1}/testdata/${2}.in
touch ${1}/testdata/${2}.out
echo ${1}/${2} created.