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
* Anonymous pipes are in use for multiprocessing units.
* Anonymous pipes are temporary and exist only as long as the process that created them is running.
* ---
*
* This source code has been updated to work on
* a Windows machine, too.
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
#include <windows.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#endif

#define BUFFER_LENGTH      128
#define PIPE_MESSAGE_WRITE "The message from the parent process trough a pipe."

void handle_with_pipes(void) {
	char buffer[BUFFER_LENGTH];
	memset(buffer, '\0', sizeof(buffer));

	#ifdef _WIN32
	// only for Windows

	// create two pipe sides
	HANDLE read_pipe, write_pipe;
	SECURITY_ATTRIBUTES sa = {
		.nLength = sizeof(SECURITY_ATTRIBUTES),
		.lpSecurityDescriptor = NULL,
		.bInheritHandle = TRUE
	};

	if (!CreatePipe(&read_pipe, &write_pipe, &sa, 0)) {
		fprintf(stderr, "CreatePipe failed. Error: %lu\n", GetLastError());
		return;
	}

	// ensure the read handle is not inherited
	if (!SetHandleInformation(read_pipe, HANDLE_FLAG_INHERIT, 0)) {
		fprintf(stderr, "SetHandleInformation failed. Error: %lu\n", GetLastError());
		return;
	}

	// write to the pipe
	DWORD bytesWritten;
	if (!WriteFile(write_pipe, PIPE_MESSAGE_WRITE, (DWORD)strlen(PIPE_MESSAGE_WRITE), &bytesWritten, NULL)) {
		fprintf(stderr, "WriteFile failed. Error: %lu\n", GetLastError());
		return;
	}

	// close write side
	CloseHandle(write_pipe);

	// wait for a while (not really required)
	puts("Waiting 2.5s for receiving the pipe message...");
	Sleep(2500);

	// read from the pipe
	DWORD bytesRead;
	if (ReadFile(read_pipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
		buffer[bytesRead] = '\0';
		printf("Received from pipe: %s\n", buffer);
	} else {
		fprintf(stderr, "ReadFile failed. Error: %lu\n", GetLastError());
	}

	CloseHandle(read_pipe);
	#else
	// only for UNIX
	int pipe_file_descriptor[2] = {0};
	int nbr_read = -1;
	int pid_nbr = -1;

	if (pipe(pipe_file_descriptor) < 0) {
		perror("pipe()");
		return;
	}

	// for more details: see C programming chapter 29
	switch(pid_nbr = fork()) {
		case -1: {
			perror("[parent] fork()");
			return;
		} case 0: {
			// child process

			// closing write pipe
			if (close(pipe_file_descriptor[1]) < 0) {
				perror("[Child] close()");
				return;
			}

			// reading from pipe

			// not really required, but in that case this is fine
			puts("[Child] Waiting 2.5s to receive a message from the parent process...");
			struct timespec request = {
				.tv_sec = 2,
				.tv_nsec = 500000000
			};
			
			struct timespec remaining;
			nanosleep(&request, &remaining);

			nbr_read = read(pipe_file_descriptor[0], buffer, sizeof(buffer));
			switch(nbr_read) {
				case -1:
					perror("[Child] read()");
					return;
				case 0:
					fprintf(stderr, "[Child] EOF / empty pipe\n");
					return;
				default:
					printf("[Child] read %d bytes from \"%s\"\n", nbr_read, buffer);
					break;
			}

			break;

		} default: {
			// parent process

			// closing read pipe
			if (close(pipe_file_descriptor[0]) < 0) {
				perror("[parent] close()");
				return;
			}

			puts("[parent] Writing a message trough a pipe...");

			// writing content to the pipe
			if (write(pipe_file_descriptor[1], PIPE_MESSAGE_WRITE, strlen(PIPE_MESSAGE_WRITE)) < 0) {
				perror("[parent] write()");
				return;
			}

			// waiting for child
			if (waitpid(pid_nbr, NULL, WUNTRACED) < 0) {
				perror("[parent] waitpid()");
				return;
			}
		}
	}
	#endif
}

int main(void) {
	handle_with_pipes();

	return EXIT_SUCCESS;
}