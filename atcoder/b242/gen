cat ../../template.cpp | sed -e "s/{judge}/${JUDGE}/g" -e "s/{pid}/${1}/g" -e "s/{pname}/${2}/g" -e "s/{DEFINE}/#ifdef DBG/g" > ${1}.cpp
touch testdata/${1}.in
touch testdata/${1}.out
echo ${1} created.