#include <stdio.h>
#include <stdlib.h>

/*
* When you want to call a function, typically this function has been
* defined and declared earlier or you're using a function prototype.
*
* Since C and C++ have a different behavior, the compiler returns
* a different behavior on runtime.
*
* For C: This function is interpreted as an integer function, which may
* also return any integer value. You'll also see a warning message by default.
*
* For C++: The compiler refuses to build your application, because
* the certain function is unknown yet.
*/

int main(void) {
	weired_function();

	return EXIT_SUCCESS;
}

void weired_function() {
	puts("Hi there!");
}

// -------------------------------------------------

/*
* To avoid that weired behavior, move the function over main
* or declare weired_function as a function prototype over main.
*/
void weired_function();

int main(void) {
	weired_function();
	return EXIT_SUCCESS;
}

void weired_function() {
	puts("Hi there!");
}