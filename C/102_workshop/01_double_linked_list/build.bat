::	Building the application under Windows by
::	using mingw. Make sure you have installed
::	and configured mingw on your system.
::
::	author:		ITWorks4U
::	created:	July 16th, 2025
::	updated:	August 13th, 2025
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
gcc.exe -g3 -Iinclude -Wall source\\double_linked_list.c source\\main.c -o double_linked_list.exe
echo application has been built
goto :eof

:clean_up
del double_linked_list.exe 2>nul
goto :eof