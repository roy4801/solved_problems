@echo off

cls
g++ uva/%1.cpp -o uva/a.exe

if %ERRORLEVEL% EQU 0 (
	echo Running
	@pushd uva
	a.exe
	@popd
	echo End
)
