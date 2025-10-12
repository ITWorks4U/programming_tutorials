:: Building the applications on a Windows machine only.
@echo off
setlocal

:: --------------
:: flags to set
:: --------------
set COMPILER=gcc.exe
set C_FLAGS=-I../header -I../config -Wall -Wparentheses
set CONFIG=../config/config_reader.c
set SOCK_IMPL=../socket_impl/socket_implementations.c
set C_FLAG_LWS=-lws2_32
set SERVER_WIN=server_win.exe
set CLIENT_WIN=client_win.exe

:: --------------
:: check, if no argument or more
:: than one argument is/are given
:: --------------
if "%1" == "" goto how_to_use
if not "%2" == "" goto how_to_use

:: --------------
:: check, if the first argument is "build" or "clean" only
:: every other argument calls the help function instead
:: --------------
if "%1" == "build_server" goto build_server
if "%1" == "build_client" goto build_client
if "%1" == "clean" goto clean_up

:: --------------
:: for any other single argument
:: --------------
goto how_to_use

:: --------------
:: targets
:: --------------
:how_to_use
echo "usage: build.bat [build_server | build_client | clean]"
echo build_server = build the server application
echo build_client = build the client application
echo clean = removes the application(s)
goto :eof

:build_server
:: building server
%COMPILER% %C_FLAGS% server.c %CONFIG% %SOCK_IMPL% -o %SERVER_WIN% %C_FLAG_LWS%
goto :eof

:build_client
:: building client
%COMPILER% %C_FLAGS% client.c %CONFIG% %SOCK_IMPL% -o %CLIENT_WIN% %C_FLAG_LWS%
goto :eof

:clean_up
del %SERVER_WIN% 2>nul
del %CLIENT_WIN% 2>nul
goto :eof

endlocal