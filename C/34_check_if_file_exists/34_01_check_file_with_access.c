/*
* Check a file by using access.
*
* On Windows _access() is in use, whereas access()
* on other systems is in use instead.
*/

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

#ifdef _WIN32
	#include <io.h>

	//	define file attribute states
	//	F => file itself
	//	X => executable flag
	//	W => write flag
	//	R => read flag
	#define	F_OK	0
	#define X_OK	1
	#define W_OK	2
	#define R_OK	4
#else
	#include <unistd.h>
#endif

int main(void) {
	#ifdef _WIN32

	//	similar to access() in Linux the flags can be combined with a BIT-OR
	//	in that case it checks, if a file is "OK" and read flag is set
	//
	//	returns 0 for success, otherwise -1
	if (_access(FILE_TO_CHECK, F_OK | R_OK) != 0) {
		puts(MISSING);
	} else {
		puts(EXISTING);
	}
	#else

	/*
	* int access(const char *__name, int __type);
	* returns 0 on success,
	* -1 on error => errno is set
	*/
	if (access(FILE_TO_CHECK, F_OK | R_OK) < 0) {
		perror("access()");
		puts(MISSING);
	} else {
		puts(EXISTING);
	}
	#endif

	return EXIT_SUCCESS;
}