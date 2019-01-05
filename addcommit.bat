@echo off

if -%1-==-- (
	goto :ex
)

echo Update README.md
pushd utils
start /b cp.bat
timeout /t 3
uva_prob.exe
popd utils

echo Git commands
git add uva/%1.cpp uva/testdata/%1.in uva/testdata/%1.out
git commit -m "%1"
git status


:ex