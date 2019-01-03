@echo off

echo Compiling...

g++ -o uva_prob.exe uva_prob.cpp
if %ERRORLEVEL% EQU 0 (
	echo Complete.
)