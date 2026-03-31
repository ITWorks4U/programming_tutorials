/*
* Waiting for a child process may be helpful, when two or more tasks needs a "parallel" result action.
* The main process can wait for the child process, if set.
* If not, then the child process may become an ophran process and the init process (process ID 1) takes over. (UNIX only).
* The child process itself could also be terminated earlier than the parent process does, so the child
* process may become to a zombie process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 10s for sleeping
// NOTE: for Windows this milliseconds must be multiplied
//       by factor 1000
#define TIME_TO_SLEEP 10

#ifdef _WIN32
// for Windows only
#define SUB_PROCESS_WINDOWS
#include <Windows.h>
#define APP_TO_LAUNCH "C:\\Windows\\System32\\notepad.exe"
#else
// for UNIX only
#define SUB_PROCESS_UNIX
#include <unistd.h>
#include <sys/types.h>

// required for waitpid()
#include <sys/wait.h>
#endif

#ifdef SUB_PROCESS_WINDOWS
void wait_for_child(void) {
	HANDLE hJob = CreateJobObject(NULL, NULL);
	if (hJob == NULL) {
		printf("CreateJobObject failed (%lu)\n", GetLastError());
		return;
	}

	JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = { 0 };
	jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;

	if (!SetInformationJobObject(hJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli))) {
		printf("SetInformationJobObject failed (%lu)\n", GetLastError());
		return;
	}

	// create child process
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	BOOL success = CreateProcess(
		APP_TO_LAUNCH, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi
	);

	if (!success) {
		printf("CreateProcess failed (%lu)\n", GetLastError());
		return;
	}

	// assign child to job
	if (!AssignProcessToJobObject(hJob, pi.hProcess)) {
		printf("AssignProcessToJobObject failed (%lu)\n", GetLastError());
		TerminateProcess(pi.hProcess, 1);
		return;
	}

	// resume child
	ResumeThread(pi.hThread);

	// now, when parent exits, the child will be terminated automatically
	printf("Child running. Close parent process to kill child or wait %d seconds.\n", TIME_TO_SLEEP);

	// simulating some process for the parent process
	Sleep(TIME_TO_SLEEP * 1000);

	// if the child process is still alive, then the main process
	// terminates the child process

	// clean up
	CloseHandle(hJob);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
#endif

#ifdef SUB_PROCESS_UNIX
void wait_for_child(void) {
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());

			printf("[child]: \"I'm going to sleep for %d seconds!\"\n", TIME_TO_SLEEP);
			sleep(TIME_TO_SLEEP);
			puts("[child]: \"I'm back!\"");

			if (getppid() == 1) {
				puts("[child]: \"Mommy...?\"");
			}

			break;
		} default: {
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			puts("[parent]: \"Time to go.\"");
			puts("[parent]: \"Wait...? Did I forgot something?\"");

			/*
			* pid_t waitpid(pid_t __pid, int *__stat_loc, int __options);
			*
			* Attempt to wait for the child.
			*
			* returns:
			* -1:   any error (errno is set)
			* >= 0: waiting attempt was sucessfully
			*
			* Since your main process is forced to wait for the child process,
			* you can handle your child(s) much better. It doesn't now matter if
			* your child process has been terminated earlier or later that the main process did.
			* However, it depends on HOW YOU handle your child(s)!
			*
			* arguments:
			* __pid:
			* - process id, where:
			*   <-1 := waiting for any child process, whose process group ID is equal to the absolute value of pid
			*    -1 := just waiting for any child process
			*     0 := waiting for any child process, whose process group ID is equal to the calling process
			*    >0 := waiting for the child process, which has been successfully created by THIS parent process
			*
			* __stat_loc:
			* - pointer to the location, where the status information for the terminating process wants to be stored,
			*   NULL for: "We don't care about these informations."
			*
			* __options:
			* - specifies optional actions for waitpid; the flags can be combined with bit-OR
			*
			* WNOHANG    := returns immediately if no child exists
			* WUNTRACED  := also return, if a child process has been stopped in any way;
			* status for traced children, which have been stopped, is provided, even if this option is not set
			* WCONTINUED := also return, if a stopped child has been resumed by delivery of SIGCONT
			*/

			/*
			* Attention: Don't use getpid().
			* Otherwise waitpid always returns -1 and your parent process
			* do not longer care about any child process(es)!
			*/
			switch (waitpid(pid, NULL, 0)) {
				case -1: {
					perror("[parent]: \"Hm, I think it wasn't important...\"");
					break;
				} default: {
					puts("[parent]: \"Ah, there you are! :)\"");
					break;
				}
			}

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
	wait_for_child();
	#endif

	#ifdef SUB_PROCESS_UNIX
	wait_for_child();
	#endif

	return EXIT_SUCCESS;
}