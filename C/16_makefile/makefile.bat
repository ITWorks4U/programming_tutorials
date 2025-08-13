::	for Windows only
::	use this batch file to build or clean up your application
::
::	It may happen, that on your machine this batch file won't create an
::	executable file. This may happen, if the system settings blocks a batch
::	file or else. Try to use the powershell file instead.
::
::	If this also fails, then you have to build your application by using the command line.
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
gcc.exe -g3 -Wall 16_use_a_makefile.c -o app.exe
echo application has been built
goto :eof

:clean_up
del app.exe 2>nul
echo application has been removed, if this was existing
goto :eof