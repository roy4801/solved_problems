@echo off

if -%1-==-- (
    call :usage
    goto :end
)

echo.>uva\%1.cpp
echo.>uva\testdata\%1.in
echo.>uva\testdata\%1.out
echo Created
goto :end


:usage
setlocal
echo %0.bat [name.cpp]
echo  generate .cpp and testing files(*.in) of specific name
endlocal

:end