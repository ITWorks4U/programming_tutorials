/*
* system programming C
*
* Working with message queues. A message queue is a temporary
* file to put messages, which can be used for an another process,
* thread, ...
*
* This script has been updated to work with on a Windows machine,
* as well as, on an UNIX system.
*
* author:   ITWorks4U
* created:  January 1st, 2022
* updated:  November 4th, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message_queue.h"

#ifdef _WIN32
HANDLE message_queue_reader = NULL;
#else
mqd_t mq;
#endif

void clean_up(void) {
	#ifdef _WIN32
	if (message_queue_reader != NULL) {
		CloseHandle(message_queue_reader);
	}
	#else
	if (mq != (mqd_t)-1) {
		mq_close(mq);
	}

	mq_unlink(QUEUE_NAME);
	#endif
}

int main(void) {
	atexit(clean_up);

	#ifdef _WIN32
	// only for Windows
	DWORD bytesWritten;
	char buffer[BUFFER_LENGTH];

	memset(buffer, '\0', sizeof(buffer));

	// wait for the pipe to become available
	if (!WaitNamedPipe(PIPE_PATH_WINDOWS, NMPWAIT_WAIT_FOREVER)) {
		printf("Pipe not available. Error: %lu\n", GetLastError());
		return EXIT_FAILURE;
	}

	// connect to the named pipe
	message_queue_reader = CreateFile(
		PIPE_PATH_WINDOWS,
		GENERIC_WRITE,
		0,                  // without sharing
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);

	if (message_queue_reader == INVALID_HANDLE_VALUE) {
		printf("Failed to connect to pipe: %lu\n", GetLastError());
		return EXIT_FAILURE;
	}

	// send a few messages
	char *messages[] = {"Hello", "from", "the", "client", NULL};
	for (int i = 0; messages[i]; i++) {
		WriteFile(message_queue_reader, messages[i], (DWORD)strlen(messages[i]), &bytesWritten, NULL);
		printf("sent: %s\n", messages[i]);

		// wait 0.5 s
		Sleep(500);
	}
	#else
	// only for UNIX
	// open the existing message queue (write-only)
	mq = mq_open(QUEUE_NAME, O_WRONLY);
	if (mq == (mqd_t)-1) {
		perror("[client] mq_open");
		exit(1);
	}

	char *messages[] = {"Hello", "from", "the", "client", "exit"};

	for (int i = 0; messages[i]; i++) {
		if (mq_send(mq, messages[i], strlen(messages[i]), 0) == -1) {
			perror("[client] mq_send()");
			continue;
		}

		printf("[client] sent: %s\n", messages[i]);

		// let's wait for a while
		sleep(1);
	}
	#endif

	return EXIT_SUCCESS;
}