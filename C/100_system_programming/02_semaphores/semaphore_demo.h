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

#ifndef SEMAPHORE_DEMO_H
#define SEMAPHORE_DEMO_H

// let create 5 threads
#define THREAD_COUNT    5

#ifdef _WIN32
#include <Windows.h>

// global mutex / semaphore
extern HANDLE semaphore;

DWORD WINAPI worker_thread(LPVOID arg);

#else
// for an UNIX system only
#define P_SHARED_OPTION         0
#define INITIAL_VALUE_SEMAPHORE 1

// NOTE:  It may happen, that you'll receive
//        a bunch of undefined references.
//        In that case compile the application
//        with -lpthread and -lrt.

#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// global mutex / semaphore
extern sem_t semaphore;

// function prototype
void *thread_function(void *arg);
#endif

#endif