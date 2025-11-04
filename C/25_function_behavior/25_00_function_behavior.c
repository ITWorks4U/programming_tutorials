/*
* A function in C differs slighty to a C++ function, even
* a function might looks identical.
*
* Since the C programming doesn't comes with function overload,
* a function can be used elsewhere.
*/

#ifdef __cplusplus
#error "Don't use a C++ compiler to build this application. Use a C compiler instead."
#else
#include <stdio.h>
#include <stdlib.h>

// as far we know, when a function is defined in that way,
// we assume, that no argument is allowed, however, in C
// you can add any amount of arguments
void simple_function() {
	puts("I was called.");
}

int main(void) {
	// Are you surprised?
	simple_function();
	simple_function(1, 2, 3);
	simple_function(4.0, 5e9, -3e-10);
	simple_function("Hello World!");
	simple_function('E', 'P', 'I', 'C');
	simple_function(NULL);
	// ...

	/*
	* Why is this function with any argument(s) still able to being called?
	* In C programming a function does not accept any arguments, if the void
	* expression is in the brackets. => void simple_function(void);
	*
	* Otherwise an internal definition tells the
	* compiler to allow any arguments with any number of arguments:
	*
	* void simple_function() => void simple_function(...)
	* => If you want to allow in C++ to call a function like C-style, just
	*    use "..." in the brackets.
	*/

	// functions, like printf, fprintf, ... allows to handle any amount of
	// additional arguments
	// int printf(const char *const _Format, ...);

	return EXIT_SUCCESS;
}
#endif