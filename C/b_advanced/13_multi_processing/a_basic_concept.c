/*
* Sub processing, threads allows you to do operations at almost the same time.
* There's a slightly difference between sub processing and threads as well as
* on which OS you're working.
*
* on Windows, you use functions, like:
* - CreateProcess()
* - CreateThread()
* - ...
*
* on UNIX/Linux/(possible macOS), use functions, like:
* - fork();
* - pthread_create();
* - ...
*
* Even you've launched any application before, this contains a single
* process with a single thread. When a sub process is going to start
* the main process can wait for the child process, if given, otherwise
* the main process ends erlier than the child process.
* => this child process becomes to an orphan process and it will be
*    collected by the init process with process it 1
*
* A child process, however, can also be terminated erlier than the
* main process.
* => this child process becomes to a zombie process; this won't be
*    collected by the init process
*
* examples to use sub process(es):
* - launch an additional application
* - do a "parallel" operation
*   - by using critical resources there's no guarantee for success, e. g:
*     - I/O handling
*     - communication by UART
*     - network comminication
*     - pipe
*     - ...
*
* A process and also the sub process are sharing the same
* file handler objects, streams, ...
*
* Since a sub process has been successfully created, the main process
* do its stuff and don't usually care about the sub process(es).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32
// for Windows only
#define SUB_PROCESS_WINDOWS
#include <Windows.h>
#define APP_TO_LAUNCH "C:\\Windows\\System32\\notepad.exe"
#else
#define SUB_PROCESS_UNIX
// for UNIX only
#include <unistd.h>
#include <sys/types.h>
#endif

#ifdef SUB_PROCESS_WINDOWS
void create_new_process(void) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// create the child process
	if (!CreateProcess(
		APP_TO_LAUNCH,      // Application name
		NULL,               // Command line
		NULL,               // Process handle not inheritable
		NULL,               // Thread handle not inheritable
		FALSE,              // Set handle inheritance to FALSE
		0,                  // No creation flags
		NULL,               // Use parent's environment block
		NULL,               // Use parent's starting directory 
		&si,                // Pointer to STARTUPINFO structure
		&pi)                // Pointer to PROCESS_INFORMATION structure
	) {
		fprintf(stderr, "CreateProcess failed (%lu).\n", GetLastError());
		return;
	}

	// wait until child process exits
	WaitForSingleObject(pi.hProcess, INFINITE);
	puts("back to business...");

	// close process and thread handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
#endif

#ifdef SUB_PROCESS_UNIX
void create_new_process(void) {
	/*
	* pid_t fork(void);
	*
	* Attempting to create a new process.
	*
	* returns:
	* -1:	any error (errno is set)
	* 0:	child process has been successfully created
	* >0:	parent process as caller
	*/
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			puts("child process here...");

			/*
			* pid_t getpid(void);
			* Returns the process-ID of the caller.
			*
			* pid_t getppid(void);
			* Returns the parent process-ID of the caller.
			*/
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			break;
		} default: {
			puts("parent process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());

			/*
			* At this point we didn't care about our child process,
			* thus your child process might be terminated earlier than
			* the main process or vice versa. This affects the state of
			* your child process.
			*/

			break;
		}
	}
}
#endif

int main(void) {
	printf("Scanning running system: ");
	bool on_unknown_system = false;

	#ifdef _WIN32
	puts("Windows");
	#elif defined(__unix__) || defined(__linux__)
	puts("Linux");
	#elif defined(__APPLE__) || defined(_MAC)
	puts("macOS");
	#else
	puts("unknown");
	on_unknown_system = true;
	#endif

	if (on_unknown_system) {
		fprintf(stderr, "ERROR: Unable to detect the OS. A sub process can't be created.\n");
		return EXIT_FAILURE;
	}

	#ifdef SUB_PROCESS_WINDOWS
	create_new_process();
	#endif

	#ifdef SUB_PROCESS_UNIX
	create_new_process();
	#endif

	return EXIT_SUCCESS;
}
