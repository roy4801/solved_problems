#!/bin/bash

git add uva/${1}.cpp uva/testdata/${1}.in uva/testdata/${1}.out
git commit -m "${1}"
git push origin master
