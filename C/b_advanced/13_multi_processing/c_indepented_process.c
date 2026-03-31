/*
* A sub process may also become an indepented process, so the parent
* process has no more control after a successfully creation. Depending
* on which OS you're using, some additional settings can be made.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 10s for sleeping
// NOTE: for Windows this milliseconds must be multiplied
//       by factor 1000
#define TIME_TO_SLEEP   10

#ifdef _WIN32
// for Windows only
#define SUB_PROCESS_WINDOWS
#include <Windows.h>
#else
// only for UNIX
#define SUB_PROCESS_UNIX
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif

#ifdef SUB_PROCESS_WINDOWS
void create_indepented_process(char **argv) {
	char *command_line = argv[1];

	STARTUPINFOA si;

	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// --- independent and hidden sub process ---
	BOOL success = CreateProcessA(
		NULL,                // application name
		command_line,        // command line from argv[1]
		NULL,                // process handle not inheritable
		NULL,                // thread handle not inheritable
		FALSE,               // handle inheritance
		DETACHED_PROCESS,    // detached (independent of parent)
		NULL,                // use parent's environment block
		NULL,                // use parent's current directory
		&si,                 // STARTUPINFO
		&pi                  // PROCESS_INFORMATION
	);

	if (!success) {
		printf("CreateProcess failed (%lu)\n", GetLastError());
		return;
	}

	printf("Process '%s' started successfully (PID: %lu)\n", argv[1], pi.dwProcessId);

	// close handles so the child runs independently
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	printf("Parent exiting now...\n");
}
#endif

#ifdef SUB_PROCESS_UNIX
/*
* Running a sub process as an own process, thus the main process can't handle
* or wait for that child process, even by any try attempt.
*
* To make the child process to an indepented process, use: int exec*(...).
* There are many kind of different functions.
*
* from "man exec", there're different exec*(...) functions:
* 
* l - execl(), execlp(), execle()
* v - execv(), execvp(), execvpe()
* e - execle(), execvpe()
* p - execlp(), execvp(), execvpe()
*
* returns:
* -1, on any error (errno is set)
* 0 on success
* => You're unable to see this result, because at this point your sub process is no longer a part of your current application.
*
* using arguments for the main application, which
* are planned to use for the child process only, like:
*
* ls -Alh | grep *.txt
* ps -elf | prep app.run | grep -v grep
* ...
*/
void create_indepented_process(int argc, char **argv) {
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			// starts a new session to detach from the parent terminal
			setsid();

			puts("child process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			puts("[child]: I'm going to be independent! :)");

			int ctr = 0;
			char **args = calloc(argc, argc * sizeof(char *));

			while(ctr < (argc - 1)) {
				args[ctr] = argv[ctr + 1];
				ctr++;
			}

			execvp(argv[1], args);

			/*
			* Attention:
			* - You're creating dynamic allocated memory on the heap,
			* which are no longer accessable and can't be freed()!
			*
			* You could also use a static string, located on the stack,
			* however, your exec*() function might not work.
			* Even, if 0 has returned.
			*/

			// NOTE: By default this text and any other processes after
			// successfully exec*() function is unable to run unless the
			// function itself returned a value < 0 for any error.
			puts("[child]: Are you still able to see this text here? ;-)");

			break;
		} default: {
			puts("parent process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			printf("[parent]: time to sleep for %d seconds...\n", TIME_TO_SLEEP);
			sleep(TIME_TO_SLEEP);
			puts("[parent]: process now ends");
			puts("[parent]: Wait...? Where's my child?");

			// -----
			// However, your main application might still be able to wait for
			// your child process. In that case a waitpid() is no longer required.
			// -----

			// switch (waitpid(pid, NULL, 0)) {
			// 	case -1: {
			// 		perror("unable to wait for child...");
			// 		break;
			// 	} default: {
			// 		puts("Ah, there you're! :)");
			// 		break;
			// 	}
			// }

			break;
		}
	}
}
#endif

// The application can be used with one argument only.
int main(int argc, char **argv) {
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

	if (argc != 2) {
		fprintf(stderr, "ERROR: The application needs one argument as a process to run.\n");
		return EXIT_FAILURE;
	}

	#ifdef SUB_PROCESS_WINDOWS
	create_indepented_process(argv);
	#endif

	#ifdef SUB_PROCESS_UNIX
	create_indepented_process(argc, argv);
	#endif

	return EXIT_SUCCESS;
}