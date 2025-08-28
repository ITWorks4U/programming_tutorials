@echo off
setlocal

set LIB_NAME=lib.dll

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
gcc.exe -g3 -Wall -DLIBARY_MAKER_EXPORTS -shared -o %LIB_NAME% lib.c -Wl,--out-implib,lib.a

::	don't print a message for those two commands on stdout or stderr
del lib.a 2>&1>nul
move lib.dll ..\ 2>&1>nul

echo the libary has been built
goto :eof

:clean_up
del ..\lib.dll 2>&1>nul
echo the libary has been removed, if this was existing
goto :eof