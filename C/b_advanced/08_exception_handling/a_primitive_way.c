/*
* The C programming does not come with an exception handling procedure.
* Those exceptions can sometimes being handled with signal handling instructions,
* however, this does not work for every case of exception and remeber:
*
* An exception handling is NOT equal to a signal handling!
*
* C++ MIGHT be able to handle C-style-exceptions, however, there's no guarantee.
* In that case this source file can't be build with a C++ compiler.
*/

#ifdef __cplusplus
#error "By using a C++ compiler this application may be handled like a threat or it leads to an undefined behavior. Use a C compiler instead."
#else
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int nominator = 100;

	// Usually, a division by 0 is not allowed and this MAY
	// trigger a SIGFPE signal for "floating point exception"
	// or an undefined behavior.
	for(int denominator = 10; denominator >= -10; denominator -= 2) {
		if (denominator == 0) {                       // "handle" this error by skipping that process
			continue;
		}

		printf("%d / %d = %d\n", nominator, denominator, nominator/denominator);
	}

	return EXIT_SUCCESS;
}
#endif