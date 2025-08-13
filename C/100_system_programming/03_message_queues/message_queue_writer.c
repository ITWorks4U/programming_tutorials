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
#include <string.h>
#include <unistd.h>

//	these libraries are required for message queue
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include "message_queue.h"

int main(void) {
	struct MessageQueue mq;
	int msg_id, str_length;
	key_t key_to_use;

	//	uses the identity of the given pathname and the least significant 8 bits of proj_id
	if ((key_to_use = ftok(FILE_TO_USE, SIZE_TO_USE)) < 0) {
		perror("ftok()");
		return EXIT_FAILURE;
	}

	//	get a System V message queue identifier
	if ((msg_id = msgget(key_to_use, PERMISSION_OPTION | IPC_CREAT)) < 0) {
		perror("msgget()");
		return EXIT_FAILURE;
	}

	printf("enter a text: ");
	fgets(mq.m_text, sizeof(mq.m_text), stdin);
	str_length = strlen(mq.m_text);

	//	replacing \n to \0
	mq.m_text[str_length - 1] = '\0';

	//	send a message trough the queue
	if (msgsnd(msg_id, &mq, str_length, 0) < 0) {
		perror("msgsnd()");
		return EXIT_FAILURE;
	}

	if (msgctl(msg_id, IPC_RMID, NULL) < 0) {
		perror("msgctl()");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

#endif