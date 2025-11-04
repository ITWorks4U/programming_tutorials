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

#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#define BUFFER_LENGTH      128

/// @brief Clean up used resources.
void clean_up(void);

#ifdef _WIN32
// Windows
// NOTE: On a Windows machine the native way with
//       message queues are not easy to implement
//       like on an UNIX system. In that case a
//       named pipe is in use instead.
#include <Windows.h>
#define PIPE_PATH_WINDOWS  "\\\\.\\pipe\\fifo_pipe"
#define TIMEOUT_MS         20000

extern HANDLE message_queue_reader;

#else
// UNIX
#include <unistd.h>
#include <mqueue.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>

#define QUEUE_NAME         "/message_queue_holder"
#define QUEUE_MODE_OPTION  0644    // rw-r--r--

extern mqd_t mq;
#endif
#endif