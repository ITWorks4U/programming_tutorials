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
	DWORD bytes_read = 0;
	char buffer[BUFFER_LENGTH];
	memset(buffer, '\0', sizeof(buffer));

	// create a named pipe
	message_queue_reader = CreateNamedPipe(
		PIPE_PATH_WINDOWS,        // pipe name
		PIPE_ACCESS_INBOUND,      // read-only server end
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		1,                        // max instances
		0,                        // out buffer size
		0,                        // in buffer size
		TIMEOUT_MS,               // timeout in milliseconds (here: 20s)
		NULL                      // default security
	);

	if (message_queue_reader == INVALID_HANDLE_VALUE) {
		printf("CreateNamedPipe failed: %lu\n", GetLastError());
		return EXIT_FAILURE;
	}

	puts("Waiting for client to connect...");
	BOOL connected = ConnectNamedPipe(message_queue_reader, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);

	if (!connected) {
		printf("Client connection failed: %lu\n", GetLastError());
		return EXIT_FAILURE;
	}

	puts("Client connected! Waiting for messages...");

	// read messages until the client closes the pipe
	while (ReadFile(message_queue_reader, buffer, sizeof(buffer) - 1, &bytes_read, NULL)) {
		buffer[bytes_read] = '\0';
		printf("Received: %s\n", buffer);
	}

	puts("Client disconnected...");
	#else
	// UNIX only
	char buffer[BUFFER_LENGTH + 1];
	memset(buffer, '\0', sizeof(buffer));

	struct mq_attr attr = {
		.mq_flags = 0,                // blocking read/write
		.mq_maxmsg = 10,              // max number of messages
		.mq_msgsize = BUFFER_LENGTH,  // max message size (here: 128 bytes)
		.mq_curmsgs = 0
	};

	// create the message queue (read-only for this process)
	mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, QUEUE_MODE_OPTION, &attr);
	if (mq == (mqd_t)-1) {
		perror("mq_open()");
		return EXIT_FAILURE;
	}

	puts("[server] waiting for messages...");

	while (true) {
		ssize_t bytes_read = mq_receive(mq, buffer, BUFFER_LENGTH, NULL);
		if (bytes_read >= 0) {
			buffer[bytes_read] = '\0';
			printf("[server] received: %s\n", buffer);

			// leave the loop, when client sends "exit"
			if (strcmp(buffer, "exit") == 0) {
				break;
			}
		} else {
			perror("[server] mq_receive()");
		}
	}
	#endif

	return EXIT_SUCCESS;
}