@echo off

cls
g++ -std=c++11 -Wall -DDBG %1/%2.cpp -o %1/a.exe

if %ERRORLEVEL% EQU 0 (
	echo Running
	@pushd %1
	a.exe
	@popd
	echo End
)
