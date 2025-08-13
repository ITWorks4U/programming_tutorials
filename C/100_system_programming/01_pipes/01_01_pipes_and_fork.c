/**	system programming in C
 *
 *	How to use pipes with fork in C.
 *
 *	ITWorks4U
*/

#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define	BUFFER_LENGTH		100

int main(void) {
	int pipe_file_descriptor[2] = {0};
	int nbr_read = -1;
	int pid_nbr = -1;

	memset(buffer, '\0', BUFFER_LENGTH);
	char text_to_use[] = "Hello from parent!";

	if (pipe(pipe_file_descriptor) < 0) {
		perror("pipe()");
		return EXIT_FAILURE;
	}

	//	for more details: see C programming chapter 29
	switch(pid_nbr = fork()) {
		case -1: {
			perror("fork()");
			return EXIT_FAILURE;
		} case 0: {

			//	closing write pipe
			if (close(pipe_file_descriptor[1]) < 0) {
				perror("close()");
				return EXIT_FAILURE;
			}

			//	reading from pipe
			nbr_read = read(pipe_file_descriptor[0], buffer, sizeof(buffer));
			switch(nbr_read) {
				case -1:
					perror("read()");
					return EXIT_FAILURE;
				case 0:
					fprintf(stderr, "EOF / empty pipe\n");
					return EXIT_FAILURE;
				default:
					printf("read %d bytes from \"%s\"\n", nbr_read, buffer);
			}

			break;

		} default: {

			//	closing read pipe
			if (close(pipe_file_descriptor[0]) < 0) {
				perror("close()");
				return EXIT_FAILURE;
			}

			//	writing content to the pipe
			if (write(pipe_file_descriptor[1], text_to_use, strlen(text_to_use)) < 0) {
				perror("write()");
				return EXIT_FAILURE;
			}


			//	waiting for child
			if (waitpid(pid_nbr, NULL, WUNTRACED) < 0) {
				perror("waitpid()");
				return EXIT_FAILURE;
			}
		}
	}

	return EXIT_SUCCESS;
}

#endif