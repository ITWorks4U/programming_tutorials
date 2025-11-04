/*
* Trying to access to a file, but:
* - does not exist
* - the path is a folder only (Windows: even C:\, D:\, ...) is "a folder"
* - insufficient permissions exists
* - is corrupted
* - ...
*
* Since this C-style exception handling MIGHT also work on C++ without
* a guarantee, this source code can't be build with a C++ compiler.
*/

#ifdef __cplusplus
#error "By using a C++ compiler this application may be handled like a threat or it leads to an undefined behavior. Use a C compiler instead."
#else
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define FILE_TO_TEST "not existing file or insufficient permissions or else"

int main(void) {
	FILE *src = fopen(FILE_TO_TEST, "r");

	if (src == NULL) {
		// for more cases take a look to errno.h
		switch(errno) {
			case ENOENT:
				perror("file error");
				break;
			case EFAULT:
				perror("memory error");
				break;
			case EACCES:
				perror("access error");
				break;
			case EMFILE:
				perror("too much open files");
				break;
			case EPERM:
				perror("permission error");
				break;
			default:
				perror("fopen()");
				break;
		}

		return EXIT_FAILURE;
	}

	// do something with the file
	// ...

	fclose(src);
	return EXIT_SUCCESS;
}
#endif