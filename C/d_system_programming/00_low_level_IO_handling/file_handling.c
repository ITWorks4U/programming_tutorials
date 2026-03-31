/*
* system programming in C
*
* Handle with files by using the low level functions.
* This has been upgraded to work on a Windows system, too.
*
* author:   ITWorks4U
* created:  January 1st, 2022
* updated:  November 3rd, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>

// for errno
#include <errno.h>

// for strerror()
#include <string.h>

#ifdef _WIN32
// only for Windows
#include <io.h>
#define F_OK    0
#define open   _open
#define close  _close
#else
#include <unistd.h>
#include <sys/types.h>
#endif

#include <sys/stat.h>
#include <fcntl.h>

#define FILE_NAME_TO_USE   "testfile.txt"
#define FILE_CONTENT       "This is a simple text."

static int _nbr_written_characters = -1;

void user_layer_file_handling(void) {
	FILE *handler = NULL;

	if ((handler = fopen(FILE_NAME_TO_USE, "w")) == NULL) {
		// prints the given text including a detailed error message
		perror("fopen()");

		// prints an error message depending on errno
		fprintf(stderr, "%s\n", strerror(errno));
		return;
	}

	_nbr_written_characters = fprintf(handler, "%s\n", FILE_CONTENT);
	printf("number of written characters to %s: %d\n", FILE_NAME_TO_USE, _nbr_written_characters);

	if (fclose(handler) < 0) {
		perror("fclose()");
		return;
	}
}

void system_layer_file_handling(void) {
	int file_descriptor = -1;

	// opens a file, where write operations only are planned
	if ((file_descriptor = open(FILE_NAME_TO_USE, O_WRONLY)) < 0) {
		perror("open()");
		return;
	}
	
	// write content of buffer to the file
	_nbr_written_characters = write(file_descriptor, FILE_CONTENT, sizeof(FILE_CONTENT));
	switch(_nbr_written_characters) {
		case -1:
			perror("write()");
			return;
		case 0:
			fprintf(stderr, "No content has been written!\n");
			return;
		default:
			printf("number of written characters to %s: %d\n", FILE_NAME_TO_USE, _nbr_written_characters);
			break;
	}
	
	// closes a file descritor
	if (close(file_descriptor) < 0) {
		perror("close()");
		return;
	}
}

int main(void) {
	/**** USER LAYER ****/
	user_layer_file_handling();

	/**** SYSTEM LAYER ****/
	system_layer_file_handling();

	return EXIT_SUCCESS;
}