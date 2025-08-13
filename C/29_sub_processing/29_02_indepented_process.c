#ifdef _WIN32
#error "This sample can't be run under Windows.
#else

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
*/

/*
* using arguments for the main application, which
* are planned to use for the child process only, like:
*
* ls -Alh | grep *.txt
* ps -elf | prep app.run | grep -v grep
* ...
*/
int main(int argc, char **argv) {
	pid_t pid = fork();

	switch(pid) {
		case -1: {
			perror("fork() returned -1");
			break;
		} case 0: {
			puts("child process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			puts("I'm going to be independent! :)");

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

			puts("Are you still able to see this text here?");

			break;
		} default: {
			puts("parent process here...");
			printf("PID: %3d, PPID: %3d\n", getpid(), getppid());
			sleep(3);
			puts("parent process ends now");
			puts("Wait...? Where's my child?");

			/*
			* However, your main application might still be able to wait for
			* your child process. In that case a waitpid() is no longer required.
			*/

			switch (waitpid(pid, NULL, 0)) {
				case -1: {
					perror("unable to wait for child...");
					break;
				} default: {
					puts("Ah, there you're! :)");
					break;
				}
			}

			break;
		}
	}

	return EXIT_SUCCESS;
}
#endif