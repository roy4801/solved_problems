@echo off

if -%1-==-- (
    call :usage
    goto :end
)

echo.>%1\%2.cpp
echo.>%1\testdata\%2.in
echo.>%1\testdata\%2.out
echo Created
goto :end


:usage
setlocal
echo %0.bat [name.cpp]
echo  generate .cpp and testing files(*.in) of specific name
endlocal

:end