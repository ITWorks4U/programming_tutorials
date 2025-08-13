#include <stdio.h>
#include <stdlib.h>
#include "18_math_functions.h"

//	the main has only to implement the header file,
//	where the function calls are handled by the
//	source file for that certain header file

//	NOTE: When you need to compile source file(s), where also a header is
//	/ are multiple headers in use, then the header file(s) should not be a part
//	for the compiler instruction.
//
//	Use: gcc(.exe) math_functions.c main.c
//
//	This is only useful, when in the header file a function is declared to do something.
int main(void) {
	int a = 100;
	int b = 200;

	//	calling external functions for main
	printf("%d + %d = %d\n", a, b, add(a,b));
	printf("%d - %d = %d\n", a, b, subtract(a,b));
	printf("%d * %d = %d\n", a, b, multiply(a,b));
	printf("%d / %d = %d\n", a, b, divide(a,b));

	//	%% for a single %
	printf("%d %% %d = %d\n", a, b, modulo(a,b));

	return EXIT_SUCCESS;
}