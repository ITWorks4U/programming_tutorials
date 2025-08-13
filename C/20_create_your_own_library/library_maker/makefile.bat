::	building the libary by using a batch script
::	if this batch script does not work on your machine, then try to use
::	the powershell script instead
::
::	if this also fails, then you must enter the compile commands into the command line instead
@echo off
setlocal

set LIB_NAME=library_maker.dll

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
gcc.exe -g3 -Wall -DLIBARY_MAKER_EXPORTS -shared -o %LIB_NAME% library_maker.c -Wl,--out-implib,library_maker.a

::	don't print a message for those two commands on stdout or stderr
del library_maker.a 2>&1>nul
move library_maker.dll ..\run_example 2>&1>nul

echo the libary has been built
goto :eof

:clean_up
del ..\run_example\library_maker.dll 2>&1>nul
echo the libary has been removed, if this was existing
goto :eof