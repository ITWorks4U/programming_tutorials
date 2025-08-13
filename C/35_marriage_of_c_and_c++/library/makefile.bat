@echo off
setlocal

set LIB_NAME=math_operations.dll

::	some checks before...
if "%1" == "" goto help_function
if not "%2" == "" goto help_function
if "%1" == "build" goto build_app
if "%1" == "clean" goto clean_up
if "%1" == "build_assembly" goto build_assembly

::	for any other single argument
goto help_function

::	--------------
::	functions
::	--------------
:help_function
echo "usage: makefile.bat [build | build_assembly | clean]"
echo build = build the libary
echo clean = removes the libary
goto :eof

:build_app
gcc.exe -g3 -Wall -DLIBARY_MAKER_EXPORTS -shared -o %LIB_NAME% math_operations.cpp -Wl,--out-implib,math_operations.a

del math_operations.a 2>&1>nul
move math_operations.dll ..\run_example 2>&1>nul

echo the libary has been built
goto :eof

:clean_up
del ..\run_example\math_operations.dll 2>&1>nul
echo the libary has been removed, if this was existing

del math_assembly_c.asm 2>&1>nul
del math_assembly_cpp.asm 2>&1>nul
goto :eof

:build_assembly
echo creating assembly files instead...
gcc.exe -g3 -Wall -DLIBARY_MAKER_EXPORTS -S math_operations.c -o math_assembly_c.asm
gcc.exe -g3 -Wall -DLIBARY_MAKER_EXPORTS -S math_operations.cpp -o math_assembly_cpp.asm
goto :eof