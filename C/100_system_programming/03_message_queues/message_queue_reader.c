/**	system programming in C
 *
 *	How to use message queues in C.
 *
 *	ITWorks4U
*/

#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include "message_queue.h"

int main(void) {
	struct MessageQueue mq;
	int msg_id = -1;
	key_t key;

	if ((key = ftok(FILE_TO_USE, SIZE_TO_USE)) < 0) {
		perror("ftok()");
		return EXIT_FAILURE;
	}

	if ((msg_id = msgget(key, PERMISSION_OPTION)) < 0) {
		perror("msgget()");
		return EXIT_FAILURE;
	}

	//	receiving the content of the message queue
	if (msgrcv(msg_id, &mq, sizeof(mq.m_text), 0, 0) < 0) {
		perror("msgrcv()");
		return EXIT_FAILURE;
	}

	printf("%s\n", mq.m_text);

	return EXIT_SUCCESS;
}

#endif