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

// NOTE:  In case of an error, this resource could
//        still remain and this may also cause a
//        deadlock!

#include <stdio.h>
#include <stdlib.h>
#include "semaphore_demo.h"

#ifdef _WIN32
HANDLE semaphore = NULL;

DWORD WINAPI worker_thread(LPVOID arg) {
	int thread_number = (int)(intptr_t)arg;
	printf("thread %d: waiting for semaphore...\n", thread_number);

	// waiting for the free semaphore
	// an internal loop checks, if the current thread
	// is now able to enter that critical area
	WaitForSingleObject(semaphore, INFINITE);
	printf("thread %d: entered the critical section.\n", thread_number);

	// simulate a long process
	puts("long process....");
	Sleep(5000);

	printf("thread %d: left the critical section.\n", thread_number);

	// releasing the semaphore
	ReleaseSemaphore(semaphore, 1, NULL);

	return 0;
}
#else
sem_t semaphore;

void *thread_function(void *arg) {
	/*
	* int sem_wait(sem_t *sem);
	* Locks/Decrements a semaphore pointed to by sem.
	*
	* on success: 0 returns, -1 otherwise and errno is set
	*/
	if (sem_wait(&semaphore) < 0) {
		perror("sem_wait()");
		return NULL;
	}

	puts("entering function...");
	printf("long process for thread %lu\n...", pthread_self());
	sleep(5);

	/*
	* int sem_post(sem_t *sem);
	* Unlocks/Increments the semaphore pointed by sem.
	*
	* on success: 0 returns, -1 otherwise and errno is set
	*/
	if (sem_post(&semaphore) < 0) {
		perror("sem_post()");
		return NULL;
	}

	return NULL;
}
#endif