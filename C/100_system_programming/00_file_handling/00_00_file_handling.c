/**	system programming in C
 *
 *	handle with files
 *
 *	ITWorks4U
*/

#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#include <stdio.h>
#include <stdlib.h>

//	for errno
#include <errno.h>

//	for strerror()
#include <string.h>

#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//	file to use
#define	FILE_NAME_TO_USE	"testfile.txt"

void user_layer_file_handling(void) {
	FILE *handler = NULL;

	if ((handler = fopen(FILE_NAME_TO_USE, "r")) == NULL) {
		//	prints the given text including a detailed error message
		perror("fopen()");

		//	prints an error message depending on errno
		fprintf(stderr, "%s\n", strerror(errno));
		return;
	}

	if (access(FILE_NAME_TO_USE, F_OK | R_OK) < 0) {
		perror("access()");
		return;
	}

	/*	do other stuff	*/

	if (fclose(handler) < 0) {
		perror("fclose()");
		return;
	}

	/*	FILE* fopen(const char *pathname, const char *mode);
	*	Opens a file to handle with it.
	*
	*	int access(const char *pathname, int mode);
	*	Check user's permissions for a file.
	*
	*	int fclose(FILE *stream);
	*	Closes a stream.
	*/
}

void system_layer_file_handling(void) {
	int file_descriptor = -1;

	//	opens a file, where write operations only are planned
	if ((file_descriptor = open(FILE_NAME_TO_USE, O_WRONLY)) < 0) {
		perror("open()");
		return;
	}

	char buffer[] = "This is a simple text.";
	int nbr_written;

	//	write content of buffer to the file
	nbr_written = write(file_descriptor, buffer, sizeof(buffer));
	switch(nbr_written) {
		case -1:
			perror("write()");
			return;
		case 0:
			fprintf(stderr, "No content has been written!\n");
			return;
		default:
			printf("%d bytes has been written\n", nbr_written);
	}

	//	closes a file descritor
	if (close(file_descriptor) < 0) {
		perror("close()");
		return;
	}
}

int main(void) {
	/****	USER LAYER	****/
	user_layer_file_handling();

	/****	SYSTEM LAYER	****/
	system_layer_file_handling();

	return EXIT_SUCCESS;
}

#endif