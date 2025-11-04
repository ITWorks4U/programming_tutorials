/*
* system programming in C
*
* Using a semaphore in C. Semaphore are in use for multi threading,
* where a critical resource can or is planned to use by more than one
* process at the same time, however, such critical resource can be bound
* to a single thread only, whereas the remaining threads have to wait until
* the current thread releases that resource.
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
#include "semaphore_demo.h"

int main(void) {
	#ifdef _WIN32
	// only for Windows
	HANDLE threads[THREAD_COUNT];
	DWORD threadId;

	// create a semaphore with an initial count
	// of 1 and a maximum count of 1
	semaphore = CreateSemaphore(
		NULL,   // default security attributes
		1,      // initial count
		1,      // maximum count
		NULL    // no name required
	);

	if (semaphore == NULL) {
		printf("CreateSemaphore error: %lu\n", GetLastError());
		return EXIT_FAILURE;
	}

	// create multiple threads
	for (int i = 0; i < THREAD_COUNT; i++) {
		threads[i] = CreateThread(NULL, 0, worker_thread, (LPVOID)(intptr_t)i, 0, &threadId);
		if (threads[i] == NULL) {
			printf("CreateThread error: %lu\n", GetLastError());
			return EXIT_FAILURE;
		}
	}

	// wait for all threads to finish
	puts("[main thread] .:do some stuff:.");
	WaitForMultipleObjects(THREAD_COUNT, threads, TRUE, INFINITE);

	// clean up (the mess)
	for (int i = 0; i < THREAD_COUNT; i++) {
		CloseHandle(threads[i]);
	}

	CloseHandle(semaphore);
	#else
	// only for UNIX sytems
	if (sem_init(&semaphore, P_SHARED_OPTION, INITIAL_VALUE_SEMAPHORE) < 0) {
		perror("sem_init()");
		return EXIT_FAILURE;
	}

	pthread_t threads[THREAD_COUNT];

	for(int i = 0; i < THREAD_COUNT; i++) {
		if (pthread_create(&threads[i], NULL, thread_function, NULL) < 0) {
			perror("pthread_create()");
			return EXIT_FAILURE;
		}
	}
	
	puts("[main thread] .:do some stuff:.");

	// join the threads

	for(int i = 0; i < THREAD_COUNT; i++) {
		if (pthread_join(threads[i], NULL) < 0) {
			perror("pthread_join()");
			return EXIT_FAILURE;
		}
	}
	#endif

	return EXIT_SUCCESS;
}