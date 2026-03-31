/*
* system programming C
*
* Working with shared memory. Shared memory is a way for
* multiple processes to access the same region of memory.
* Useful for fast inter-process communication (IPC).
*
* This script has been updated to work with on a Windows machine,
* as well as, on an UNIX system.
*
* NOTE:     The writer application must runs first to work with
*           the shared memory. As long as the writer application runs
*           the reader application is able to receive the writer's message.
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
#include "shared_memory.h"

#ifdef _WIN32
HANDLE memory_mapped_file = NULL;
LPCTSTR buffered_message = NULL;
#else
int shm_fd = -1;
void *buffered_message = NULL;
#endif

void clean_up(void) {
	#ifdef _WIN32
	if (buffered_message != NULL) {
		UnmapViewOfFile(buffered_message);
	}

	if (memory_mapped_file != NULL) {
		CloseHandle(memory_mapped_file);
	}
	#else
	if (buffered_message != NULL) {
		munmap(buffered_message, SHM_SIZE);
	}

	if (shm_fd != -1) {
		close(shm_fd);
	}
	#endif
}

int main(void) {
	atexit(clean_up);

	#ifdef _WIN32
	// Windows only
	memory_mapped_file = CreateFileMapping(
		INVALID_HANDLE_VALUE,         // use paging file
		NULL,                         // default security
		PAGE_READWRITE,               // read/write access
		0,                            // maximum object size (high-order DWORD)
		SHM_SIZE,                     // maximum object size (low-order DWORD)
		SHM_NAME                      // name of mapping object
	);

	if (memory_mapped_file == NULL) {
		printf("Could not create file mapping object (%lu).\n", GetLastError());
		return EXIT_FAILURE;
	}

	buffered_message = (LPTSTR)MapViewOfFile(memory_mapped_file, FILE_MAP_ALL_ACCESS, 0, 0, SHM_SIZE);
	if (buffered_message == NULL) {
		printf("Could not map view of file (%lu).\n", GetLastError());
		return EXIT_FAILURE;
	}

	strcpy((char*)buffered_message, SHM_MESSAGE_TEXT);
	printf("Wrote message to shared memory.\n");

	printf("Press Enter to exit...");
	getchar();
	#else
	// UNIX only
	shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, SHM_MODE_OPTION);
	if (shm_fd == -1) {
		perror("shm_open()");
		return EXIT_FAILURE;
	}

	ftruncate(shm_fd, SHM_SIZE);

	buffered_message = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (buffered_message == MAP_FAILED) {
		perror("mmap()");
		return EXIT_FAILURE;
	}

	sprintf(buffered_message, SHM_MESSAGE_TEXT);
	printf("Wrote message to shared memory.\n");

	printf("Press Enter to exit...");
	getchar();
	#endif

	return EXIT_SUCCESS;
}