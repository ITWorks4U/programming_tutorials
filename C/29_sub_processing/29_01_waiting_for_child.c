/*
	Creating a mechanism to do a "parallel" work with fork().
	It's not really a way to do parallel work, however, this allows
	you to run your own tasks, which might be independent to this program.
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
	#define SUB_PROCESS_WINDOWS
	#include <Windows.h>
	#define APP_TO_LAUNCH "C:\\Windows\\System32\\notepad.exe"
	#define TIME_TO_SLEEP 10000 //10.000ms => 10s
#else
	#define SUB_PROCESS_UNIX
	#include <unistd.h>
	#include <sys/types.h>

	//	required for waitpid()
#include <sys/wait.h>
#endif

int main(void) {
	#ifdef SUB_PROCESS_WINDOWS
	HANDLE hJob = CreateJobObject(NULL, NULL);
	if (hJob == NULL) {
		printf("CreateJobObject failed (%lu)\n", GetLastError());
		return EXIT_FAILURE;
	}

	JOBOBJECT_EXTENDED_LIMIT_INFORMATION jeli = { 0 };
	jeli.BasicLimitInformation.LimitFlags = JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE;

	if (!SetInformationJobObject(hJob, JobObjectExtendedLimitInformation, &jeli, sizeof(jeli))) {
		printf("SetInformationJobObject failed (%lu)\n", GetLastError());
		return EXIT_FAILURE;
	}

	// Create child process
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	BOOL success = CreateProcess(
		APP_TO_LAUNCH, NULL, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi
	);

	if (!success) {
		printf("CreateProcess failed (%lu)\n", GetLastError());
		return EXIT_FAILURE;
	}

	// Assign child to job
	if (!AssignProcessToJobObject(hJob, pi.hProcess)) {
		printf("AssignProcessToJobObject failed (%lu)\n", GetLastError());
		TerminateProcess(pi.hProcess, 1);
		return EXIT_FAILURE;
	}

	// Resume child
	ResumeThread(pi.hThread);

	// Now, when parent exits, the child will be terminated automatically.
	printf("Child running. Close parent to kill child.\n");
	Sleep(TIME_TO_SLEEP);	// Simulate some parent process work

	//	if the child process is still alive, then the main process
	//	terminates the child process

	// Cleanup
	CloseHandle(hJob);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	#endif

	#ifdef SUB_PROCESS_UNIX
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());

			puts("child: \"I'm going to sleep!\"");
			for(int i = 0; i < 5; i++) {
				puts("child: \"zzz... zzz... zzz...\"");
				sleep(1);
			}

			puts("child: \"I'm back!\"");

			if (getppid() == 1) {
				puts("child: \"Mommy...?\"");
			}

			break;
		} default: {
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			puts("parent: \"Time to go.\"");
			puts("parent: \"Wait...? Did I forgot something?\"");

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
					perror("parent: \"Hm, I think it wasn't important...\"");
					break;
				} default: {
					puts("parent: \"Ah, there you're! :)\"");
					break;
				}
			}

			break;
		}
	}
	#endif

	return EXIT_SUCCESS;
}