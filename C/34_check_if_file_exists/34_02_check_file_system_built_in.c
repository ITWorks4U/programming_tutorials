/* use a common way system built in function */

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/stat.h>
#endif

int main(void) {
	#if _WIN32
	/*	taken from: https://stackoverflow.com/questions/3828835/how-can-we-check-if-a-file-exists-or-not-using-win32-program	*/
	
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(FILE_TO_CHECK, &FindFileData) ;

	int found = handle != INVALID_HANDLE_VALUE;
	if(found) {
		FindClose(handle);
		puts(EXISTING);
	} else {
		puts(MISSING);
	}
	#else
	struct stat buffer;

	/*
	* int stat(const char *__restrict__ __file, struct stat* __restrict__ __buf);
	* returns 0 on success,
	* -1 on error => errno is set
	*
	* If you omit __buf and replaces it with a NULL argument in case you won't use struct stat,
	* a warning of "non-null expectation failed" appears. So make sure to use a struct stat,
	* even you don't need that in any case.
	*/

	if (stat(FILE_TO_CHECK, &buffer) < 0) {
		puts(MISSING);
	} else {
		puts(EXISTING);
	}
	#endif

	return EXIT_SUCCESS;
}