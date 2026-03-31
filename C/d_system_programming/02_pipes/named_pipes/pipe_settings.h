/*
* system programming in C
*
* Using pipes for certain operations. A pipe can be used to
* communicate between two processes. One process is able to write,
* whereas an another process has a read side.
*
* common example (UNIX): ls -Alh | grep *.txt
* - list everything in the current folder
* - instead of displaying to the console, move the result to the
*   grep command to filter them with all text files.
*
* example for Windows: dir | find "c"
* - lists the current directory
* - redirect the result into the find command to filter
*   all files, which contains "c"
*
* ---
* Named pipes are in use for communicate data by using
* unrelated processes, like a "server / client".
* Named pipes provide a persistent communication channel between processes,
* surviving beyond the life of the process that created them. As long as the
* certain pipe file exist, the communication over that pipe
* is possible.
* ---
*
* This source code has been updated to work on
* a Windows machine, too.
*
* NOTE:     The server must run first, before the client starts,
*           otherwise the pipe was unable to open.
*
* author:   ITWorks4U
* created:  January 1st, 2022
* updated:  November 3rd, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#ifndef PIPE_SETTINGS_H
#define PIPE_SETTINGS_H

#define BUFFER_LENGTH      128
#define TIMEOUT_MS         20000
#define CLIENT_MESSAGE     "Hello from client!"
#define SERVER_MESSAGE     "Hello from server!"

#define PIPE_PATH_WINDOWS  "\\\\.\\pipe\\fifo_pipe"
#define PIPE_PATH_UNIX     "/tmp/fifo_pipe"
#define MODE_PIPE_UNIX     0666

#endif