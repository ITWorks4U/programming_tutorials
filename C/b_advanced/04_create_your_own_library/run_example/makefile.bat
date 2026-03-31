::	this makefile is required to link the main
::	with the created libary
::
::	to build the libary, take a look in library_maker folder
@echo off


::	some checks before...
if "%1" == "" goto help_function
if not "%2" == "" goto help_function
if "%1" == "build" goto build_app
if "%1" == "clean" goto clean_up

::	for any other single argument
goto help_function

::	--------------
::	functions
::	--------------
:help_function
echo "usage: makefile.bat [build | clean]"
echo build = build the libary
echo clean = removes the libary
goto :eof

:build_app
gcc.exe -g3 -Wall main.c -o library_tester.exe
echo the application has been built
goto :eof

:clean_up
del library_tester.exe 2>&1>nul
echo the application has been removed, if this was existing
goto :eof