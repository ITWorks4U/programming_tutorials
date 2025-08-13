/**	system programming in C
 *
 *	How to use pipes in C.
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

//also in use, when you want to use pipe2() function
//include <fcntl.h>

#define	BUFFER_LENGTH		10

int main(void) {
	/*	int pipe(int pipefd[2]);
	*	Creates a pipe, an undirectional data channel, that can be used for interprocess communication.
	*	The array pipefd[2] is in use to return two file descriptors referring to the ends of the pipe.
	*
	*	On success, 0 returns; on fail, -1 returns and errno is set.
	*
	*	int pipe2(int pipefd[2], int flags); => from fcntl.h
	*	Like pipe() function it will do the same. The second parameter flags can be:
	*		O_CLOEXEC	-	close on exec
	*		O_DIRECT	-	create a pipe that performs I/O in "packet" mode
	*		O_NONBLOCK	-	set file status flag on the two new open file descriptors
	*/

	//	used to store two ends for the pipe
	int pipe_file_descriptor[2] = {0};
	int nbr_read = -1;
	char buffer[BUFFER_LENGTH] = {0};
	const char text[] = "hello";

	//	creating pipe
	if (pipe(pipe_file_descriptor) < 0) {
		perror("pipe()");
		return EXIT_FAILURE;
	}

	//	write to pipe; pipe_file_descriptor must be on 1
	if (write(pipe_file_descriptor[1], text, strlen(text)) < 0) {
		perror("write()");
		return EXIT_FAILURE;
	}

	//	read from a pipe; pipe_file_descriptor must be on 0
	nbr_read = read(pipe_file_descriptor[0], buffer, sizeof(buffer));
	switch(nbr_read) {
		case -1:
			perror("read()");
			return EXIT_FAILURE;
		case 0:
			fprintf(stderr, "reading EOF or an empty pipe\n");
			return EXIT_FAILURE;
		default:
			printf("read %d bytes from pipe: %s\n", nbr_read, buffer);
	}

	return EXIT_SUCCESS;
}

#endif