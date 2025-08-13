/*
* Similar to sub processes threads allows you to work with many parallel tasks,
* because each CPU core can do a single action to speed up your application,
* however, using threads are tricky and may also cause an undefined behavior or,
* worse, a deadlock.
*
* On Windows you can't use POSIX threads by default. In that case you have to do
* an alternative way.
*
* Remember: by using UNIX/Linux/... you should use -lm to tell the compiler to
* work with math functions and math objects. On Windows this is not required.
*
* attention:
* To be able to build the application, the certain thread library is required to
* link with the compiler. Furthermore this application shall be compiled with a
* C compiler only. By using a C++ compiler this may cause undefined behavior(s).
*
* fun fact:
* - it may happen, that a threading application might take more time rather than
*   the non-thread application :)
*
* |---------|----------|
* |   OS    |   flag   |
* |---------|----------|
* | Windows | -lws2_32 |
* |---------|----------|
* | Linux   | -pthread |
* |---------|----------|
* | macOS   | -pthread |
* |---------|----------|
*/

#include <stdio.h>
#include <stdlib.h>
#include "30_library/30_threading.h"

int main(void) {
	puts("launching the application with threads...");

	#ifdef THREADING_ON_WINDOWS
	/*
	* Create a new thread for a Windows process.
	*
	* HANDLE CreateThread(
	*	LPSECURITY_ATTRIBUTES   lpThreadAttributes,  // security settings (usually NULL)
	*	SIZE_T                  dwStackSize,         // stack size (0 = default)
	*	LPTHREAD_START_ROUTINE  lpStartAddress,      // function pointer to thread function
	*	LPVOID                  lpParameter,         // argument to the thread function
	*	DWORD                   dwCreationFlags,     // flags (0 = start immediately)
	*	LPDWORD                 lpThreadId           // output thread ID (NULL = ignore)
	* );
	*/
	HANDLE thread_0 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)bubble_thread, NULL, 0, NULL);
	if (thread_0 == NULL) {
		print_error_message("CreateThread (1st thread)");
		return EXIT_FAILURE;
	}

	HANDLE thread_1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)bubble_thread, NULL, 0, NULL);
	if (thread_1 == NULL) {
		print_error_message("CreateThread (2nd thread)");
		return EXIT_FAILURE;
	}

	/*
	* Let the main application thread wait until the sub threads has been completed.
	*
	* DWORD WaitForSingleObject(
	*	HANDLE hHandle,         // handle to the object (thread in this case)
	*	DWORD  dwMilliseconds   // how long to wait (INFINITE => wait forever until the thread finishes)
	* );
	*/
	DWORD result = WaitForSingleObject(thread_0, INFINITE);
	if (result == WAIT_FAILED) {
		print_error_message("WaitForSingleObject (1st thread)");
		return EXIT_FAILURE;
	}

	result = WaitForSingleObject(thread_1, INFINITE);
	if (result == WAIT_FAILED) {
		print_error_message("WaitForSingleObject (2nd thread)");
		return EXIT_FAILURE;
	}

	/*
	* Closes the handler of the process. This does NOT terminate the thread!
	*
	* BOOL CloseHandle(
	*	HANDLE hObject   // handle to close
	* );
	*/
	if (!CloseHandle(thread_0)) {
		print_error_message("CloseHandle (1st thread)");
		return EXIT_FAILURE;
	}

	if (!CloseHandle(thread_1)) {
		print_error_message("CloseHandle (2nd thread)");
		return EXIT_FAILURE;
	}

	#endif

	#ifdef THREADING_ON_LINUX
	pthread_t thread1, thread2;

	/*
	* Create a new POSIX thread.
	*
	* int pthread_create(
	*	pthrad_t *__restrict__ __newthread,
	*	const pthread_attr_t *__restrict__ __attr,
	*	void *(*__start_routine)(void*),
	*	void *__restrict__ __arg
	* );
	*
	* __newthread: POSIX-thread to use
	* __attr: if required, run this thread with certain attributes
	* __start_routine: thread function to use => it must be a void* function with void* as an argument
	* __arg: if required, your __start_routine uses any single argument (like Object in Java / C#)
	*
	* returns:
	* -1: on any error => errno is set
	* 0: successfully created thread, which runs NOW
	*/
	if (pthread_create(&thread1, NULL, &bubble_thread, NULL) < 0) {
		perror("pthread_create #1");
		return EXIT_FAILURE;
	}
	
	if (pthread_create(&thread2, NULL, &bubble_thread, NULL) < 0) {
		perror("pthread_create #2");
		return EXIT_FAILURE;
	}

	/*
	* The main application is forced to wait for sub threads.
	*
	* int pthread_join(pthread_t __th, void **__thread_return);
	*
	* __th: thread to wait
	* __thread_return: if required, the certain return value can be used for further operations
	*
	* returns:
	* -1: on any error => errno is set
	* 0: successfully joined thread
	*
	* => In contrast to higher leveled languages, like C++, Java, C#, Python, ...,
	* there's no timeout option to wait n seconds for the thread.
	*/
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	#endif

	//	on the test machine, (Windows) the time amount took up to 40 seconds
	//	How long did this work on your machine? (:

	return EXIT_SUCCESS;
}