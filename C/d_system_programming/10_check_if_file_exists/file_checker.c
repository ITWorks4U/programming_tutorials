/*
* System programming in C.
*
* Check, if a file may exist on a certain system.
* In C there're many different ways to do this, however,
* not on every system the implementation may work.
*
* Here are three different ways to try to figure out,
* if a file may exist or not.
*
* example 1: using signals
* NOTE:      signals are hardly in use to check,
*            if a file may exist or not
*
* example 2: using access
* NOTE:      On Windows _access() only exists.
*            To make sure to use a common way for
*            all available systems, a macro function
*            will be used there.
*
* example 3: using built in methods
* NOTE:      It's a bit more complex, but may give
*            you a more clean or more faster output.
*
* author:    itworks4U
* created:   October 13th, 2025
* updated:   November 3rd, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "file_checker.h"

static void _signal_handling_event(int signum) {
	fprintf(stderr, "gotten signal: %d \n", signum);
	puts(FILE_IS_MISSING);
	exit(EXIT_FAILURE);
}

void test_with_signals(void) {
	/*
	* Not recommended, because usually no signal can be used
	* to catch a file I/O error. MAYBE some signals,
	* like SIGUSR1 / SIGUSR2 (UNIX/Linux) can be used,
	* but this is not a 100% guarantee.
	*
	* In summary, drop the idea to try to hande an I/O
	* error by using signals.
	*/

	signal(SIGUSR1, _signal_handling_event);

	// on some systems a SIGSEGV is going to raise,
	// when fopen() fails, so this >might< be a "valid"
	// way to handle such kind of errors
	signal(SIGSEGV, _signal_handling_event);

	/*
	* On Windows SIGUSR1 is not knwon, so SIGUSR1 has to be defined
	* by hand, but the behavior may be different.
	*
	* It MAY happen, that this signal has been triggered.
	* Similar to SIGSEGV, but this is not guaranteed.
	*/

	// On some systems, fopen() may raise SIGSEGV,
	// which can be handled. SIGUSR1, either Windows or UNIX,
	// MAY be triggered, but this is not a valid case.
	FILE *f = fopen(FILE_TO_CHECK, "r");
	if (f == NULL) {
		// Manually trigger a certain signal number.
		// NOTE:    Even SIGUSR1 has been defined (Windows) or
		//          still exists (UNIX), it's hardly possible
		//          to handle that signal. On Windows, this
		//          not existing file "still exists".
		//
		//          On an UNIX system SIGUSR1 can be handled.
		raise(SIGUSR1);

		// By using raise(SIGSEGV), this can also be handled
		// on a Windows machine.
		// raise(SIGSEGV);
	}

	/*	do something here	*/
	fclose(f);
	puts(FILE_EXISTS);
}

void test_with_access(void) {
	// access() helps you to figure out,
	// if a file surely exists
	//
	// NOTE: On Windows access() does not exist.
	//       A redefinition of _access() must be
	//       do before.
	//       int __cdecl _access(const char *_FileName, int _AccessMode);
	//
	//       On an UNIX system access() exists.
	//       int access(const char *__name, int __type);
	//
	// Both functions returns 0 on success, <0 on failure and errno is set.

	if (access(FILE_TO_CHECK, F_OK) < 0) {
		perror("access()");
		puts(FILE_IS_MISSING);
	} else {
		puts(FILE_EXISTS);
	}
}

void test_with_system_built_in(void) {
	#if _WIN32
	/* taken from: https://stackoverflow.com/questions/3828835/how-can-we-check-if-a-file-exists-or-not-using-win32-program */
	
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(FILE_TO_CHECK, &FindFileData) ;

	if (handle != INVALID_HANDLE_VALUE) {
		puts(FILE_EXISTS);
	} else {
		// unlike to _access() errno is not set and
		// perror() won't print you a reason for failure
		puts(FILE_IS_MISSING);
	}

	FindClose(handle);
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
		perror("stat()");
		puts(FILE_IS_MISSING);
	} else {
		puts(FILE_EXISTS);
	}
	#endif
}

int main(void) {
	// test_with_signals();
	// test_with_access();
	// test_with_system_built_in();

	return EXIT_SUCCESS;
}