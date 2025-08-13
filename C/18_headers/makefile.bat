@echo off
setlocal

::	check, if no argument or more than one argument is/are given
if "%1" == "" goto help_function
if not "%2" == "" goto help_function

::	check, if the first argument is "build" or "clean" only
::	every other argument calls the help function instead
if "%1" == "build" goto build_app
if "%1" == "clean" goto clean_up

::	for any other single argument
goto help_function

::	--------------
::	functions
::	--------------
:help_function
echo "usage: makefile.bat [build | clean]"
echo build = build the application
echo clean = removes the application
goto :eof

:build_app
gcc.exe -g3 -Wall -o app.exe 18_math_functions.c 18_main.c
if %errorlevel% == 0 (
	echo application has been built
)
goto :eof

:clean_up
del app.exe 2>nul
echo application has been removed, if this was existing
goto :eof