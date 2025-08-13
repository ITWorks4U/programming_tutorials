/**	system programming in C
 *
 *	How to use semaphores in C.
 *
 *	ITWorks4U
*/

#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#ifndef SEMAPHORE_DEMO_H
#define SEMAPHORE_DEMO_H

#define P_SHARED_OPTION 0
#define INITIAL_VALUE_SEMAPHORE 1

#include <semaphore.h>

//	global mutex
extern sem_t mutex_to_use;

//	function prototype
void *thread_function(void *arg);

#endif // ifndef SEMAPHORE_DEMO_H
#endif // ifdef _WIN32