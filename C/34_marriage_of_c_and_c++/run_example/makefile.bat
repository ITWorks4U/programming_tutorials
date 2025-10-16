@echo off
setlocal

::	some checks before...
if "%1" == "" goto help_function
if not "%2" == "" goto help_function
if "%1" == "build_c" goto build_app_c
if "%1" == "build_cpp" goto build_app_cpp
if "%1" == "clean" goto clean_up

::	for any other single argument
goto help_function

::	--------------
::	functions
::	--------------
:help_function
echo "usage: makefile.bat [build_c | build_cpp | clean]"
echo build = build the libary
echo clean = removes the libary
goto :eof

:build_app_c
gcc.exe -g3 -Wall main.c -o math_operations.exe
echo the application has been built
goto :eof

:build_app_cpp
g++.exe -g3 -Wall main.cpp -o math_operations.exe
echo the application has been built
goto :eof

:clean_up
del math_operations.exe 2>&1>nul
echo the application has been removed, if this was existing
goto :eof