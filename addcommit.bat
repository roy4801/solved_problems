@echo off

if -%1-==-- (
	goto :ex
)

git add uva/%1.cpp uva/testdata/%1.in uva/testdata/%1.out
git commit -m "%1"
git status


:ex