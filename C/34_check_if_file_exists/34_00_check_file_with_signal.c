/*
* There're different ways to check, if a file may exist or not.
* In contrast to OOP languages, like C++, Java, C#, ... in C
* there's no exception handling available or a smart and save way.
*
* You could either use a condition check, a signal handling or any else,
* however, what happens, when the file exists, but you don't have the
* access right to use it? Or what happens, if the file is corrupted?
* Or what happens, if a path is given? ...
*
* In Windows the expected default behavior may be different to UNIX/Linux / macOS.
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "constants.h"

#ifdef _WIN32
	#define SIGUSR1	10
#endif

//	-------------------
//	use signal handling
//	-------------------
void handler_function(int signum) {
	fprintf(stderr, "gotten signal: %d \n", signum);
	puts(MISSING);
	exit(EXIT_FAILURE);
}

int main(void) {
	/*
	* Not recommended, because usually no signal can be used
	* to catch a file I/O error. MAYBE some signals,
	* like SIGUSR1 / SIGUSR2 (UNIX/Linux) can be used,
	* but this is not a 100% guarantee.
	*
	* In summary, drop the idea to try to hande an I/O
	* error by using signals.
	*/
	
	signal(SIGUSR1, handler_function);

	//	on some systems a SIGSEGV is going to raise,
	//	when fopen() fails, so this >might< be a "valid"
	//	way to handle such kind of errors
	signal(SIGSEGV, handler_function);

	/*
	* On Windows the behavior may be different.
	* The expected result shall be a SIGUSR1, however,
	* no signal has been triggered, thus it assumes that
	* a non existing file may exists anyway.
	*/

	FILE *f = fopen(FILE_TO_CHECK, "r");

	/*	do something here	*/
	fclose(f);
	puts(EXISTING);

	return EXIT_SUCCESS;
}
//	-------------------