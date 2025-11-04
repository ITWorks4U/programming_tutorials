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

#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define SHM_SIZE          1024
#define SHM_MESSAGE_TEXT  "This is a text for the shared memory example."

/// @brief Clean up used resources on application termination.
void clean_up(void);

#ifdef _WIN32
// only for Windows
#include <Windows.h>
#define SHM_NAME          "shared_memory_file"

extern HANDLE memory_mapped_file;
extern LPCTSTR buffered_message;
#else
// only for UNIX
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>             // for mode constants
#include <fcntl.h>                // for O_* constants
#define SHM_NAME          "/shared_memory_file"
#define SHM_MODE_OPTION   0644    // rw-r--r--

extern int shm_fd;
extern void *buffered_message;
#endif

#endif