/**	system programming in C
 *
 *	How to use shared memory in C.
 *
 *	ITWorks4U
*/

#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include "shared_memory.h"

int main(void) {
	key_t key;
	int shm_id = -1;
	char *content = NULL;

	if ((key = ftok(FILE_TO_USE, SIZE_TO_USE)) < 0) {
		perror("ftok()");
		return EXIT_FAILURE;
	}

	//	define an IPC shared memory
	if ((shm_id = shmget(key, BUFFER_SIZE, PERMISSION | IPC_CREAT)) < 0) {
		perror("shmget()");
		return EXIT_FAILURE;
	}

	//	attaching shared memory seqment
	if ((content = (char *) shmat(shm_id, NULL, 0)) == NULL) {
		perror("shmat()");
		return EXIT_FAILURE;
	}

	printf("entering data: ");
	fgets(content, BUFFER_SIZE, stdin);
	int str_length = strlen(content);
	content[str_length - 1] = '\0';

	//	detaching the shared memory
	if (shmdt(content) < 0) {
		perror("shmdt()");
		return EXIT_FAILURE;
	}

	content = NULL;
	return EXIT_SUCCESS;
}

#endif