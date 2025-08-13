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
#error "This source code can't be build with a C++ compiler. Use a C compiler instead."
#else
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_exception(int exception_number) {
	puts("division by 0 is not allowed");

	//	What will happen, if the exit command does not
	//	exist? It may happen, that you're trapped into
	//	an infinite loop or the application is waiting
	//	for any "input" => Ctrl + C to lift off the curse.
	exit(0);
}

int main(void) {
	signal(SIGFPE, handle_exception);

	int a = 100;

	//	usually, a division by 0 is not allowed and this will
	//	trigger a SIGFPE signal for "floating point exception"
	for(int i = 10; i >= -10; i -= 2) {
		printf("%d / %d = %d\n", a, i, a/i);
	}

	return EXIT_SUCCESS;
}
#endif