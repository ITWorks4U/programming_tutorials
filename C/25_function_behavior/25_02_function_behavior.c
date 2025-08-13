/*
* In C, and also in C++ a function can be used as an argument for an another function as well.
*/

#include <stdio.h>
#include <stdlib.h>

//	both functions below are planned to use
//	as an argument for an another function
int add_numbers(int a, int b) {
	return a + b;
}

int multiply_numbers(int a, int b) {
	return a * b;
}

//	this function uses any integer function with two
//	integer arguments; best practice with one of both
//	functions above
//
//	the argument MUST NOT have an argument name, otherwise
//	the source code can't be compiled
void dynamic_function(int (*f)(int, int)) {
	printf("( ");
	for(int i = 0; i < 50; i++) {
		//	calling the anonymous argument function
		//	and determine "a" and "b"
		printf("%d ", (*f)(i, i-1));
	}
	printf(")\n");
}

int main(void) {
	//	How to call that function?
	//	call your function and add the function name
	//	only to the argument => this must not have their
	//	argument(s)

	puts(".:add_numbers:.");
	dynamic_function(add_numbers);

	puts(".:multiply_numbers:.");
	dynamic_function(multiply_numbers);

	return EXIT_SUCCESS;
}