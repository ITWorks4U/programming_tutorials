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
#include <stdbool.h>

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
	DWORD bytesWritten;

	while (true) {
		hPipe = CreateFile(
			TEXT(PIPE_PATH_WINDOWS),
			GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

		if (hPipe != INVALID_HANDLE_VALUE) {
			break;
		}

		if (GetLastError() != ERROR_PIPE_BUSY) {
			fprintf(stderr, "Could not open pipe. Error: %lu\n", GetLastError());
			return;
		}

		if (!WaitNamedPipe(TEXT(PIPE_PATH_WINDOWS), TIMEOUT_MS)) {
			fprintf(stderr, "Could not open pipe: 20 second wait timed out.\n");
			return;
		}
	}

	WriteFile(hPipe, CLIENT_MESSAGE, (DWORD)strlen(CLIENT_MESSAGE), &bytesWritten, NULL);
	CloseHandle(hPipe);
	#else
	// only for UNIX
	char buffer[BUFFER_LENGTH];
	memset(buffer, '\0', sizeof(buffer));

	printf("Client: waiting for server to write...\n");

	// open FIFO for reading
	_file_descriptor_pipe = open(PIPE_PATH_UNIX, O_RDONLY);
	if (_file_descriptor_pipe == -1) {
		perror("open for read");
		return;
	}

	ssize_t n = read(_file_descriptor_pipe, buffer, sizeof(buffer) - 1);

	switch(n) {
		case -1:
			perror("read()");
			return;
		case 0:
			fprintf(stderr, "No data received from the server. Perhaps the writer pipe has been closed?\n");
			return;
		default:
			printf("Client: received message: %s\n", buffer);
			break;
	}
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