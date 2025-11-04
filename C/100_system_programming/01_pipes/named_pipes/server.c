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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include "pipe_settings.h"

#ifndef _WIN32
// only for UNIX systems
static int _file_descriptor_pipe = -1;

static void _clean_up(void) {
	close(_file_descriptor_pipe);
}
#endif

void handle_with_pipes(void) {
	#ifdef _WIN32
	// only for Windows
	HANDLE hPipe;
	char buffer[BUFFER_LENGTH];
	DWORD bytesRead;

	hPipe = CreateNamedPipe(
		TEXT(PIPE_PATH_WINDOWS),
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		1, 1024, 1024, 0, NULL);

	if (hPipe == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "CreateNamedPipe failed. Error: %lu\n", GetLastError());
		return;
	}

	printf("Waiting for client connection...\n");

	if (ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED)) {
		printf("Client connected.\n");

		if (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
			buffer[bytesRead] = '\0';
			printf("Received: %s\n", buffer);
		}
	}

	CloseHandle(hPipe);
	#else
	if (mkfifo(PIPE_PATH_UNIX, MODE_PIPE_UNIX) == -1) {
		perror("mkfifo");
		return;
	}

	printf("Server: waiting for client to read...\n");

	// open FIFO for write side
	_file_descriptor_pipe = open(PIPE_PATH_UNIX, O_WRONLY);
	if (_file_descriptor_pipe == -1) {
		perror("open for write");
		return;
	}

	write(_file_descriptor_pipe, SERVER_MESSAGE, strlen(SERVER_MESSAGE));
	puts("Server: message sent.");

	close(_file_descriptor_pipe);

	// remove FIFO, when done to avoid
	// memory leaks
	unlink(PIPE_PATH_UNIX);
	#endif
}

int main(void) {
	#ifndef _WIN32
	// UNIX side
	atexit(_clean_up);
	#endif

	handle_with_pipes();

	return EXIT_SUCCESS;
}