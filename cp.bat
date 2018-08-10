@echo off

cls
g++ -std=c++11 -Wall uva/%1.cpp -o uva/a.exe

if %ERRORLEVEL% EQU 0 (
	echo Running
	@pushd uva
	a.exe
	@popd
	echo End
)
