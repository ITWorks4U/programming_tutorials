#include <stdio.h>
#include <stdlib.h>

/*
* The static keyword in C is a storage-class specifier.
* It has different meanings, depending on the context.
*
* Inside a function it makes a variable to retain it's value
* between multiple function calls.
*
* Outside of a function it retains the visibility of the
* function or variable to the current file only.
*
* By the way, a function is usually available from outside,
* unless you declare that function as static, too.
*/

// often used for global declarations to make sure, that this variable
// if available in this file only
// => this is not a mark for a constant expression
static int value = 100;

/*
* usually, in a function every variable will be
* automatically removed from the stack, when the
* function has been left; unless those variable(s)
* is(are) defined with static.
*
* if a variable inside of a function is declared with
* static, then this variable still exists in the RAM
* an can be used more often
*/
int without_static(void) {
	int value_a = 0;
	return ++value_a;
}

int with_static(void) {
	static int value_a = 0;
	return ++value_a;
}

// even a function can be declared as static
// => this prevents to call that function from outside
//
// => it makes no sense to declare a function with static
// in a header file, because that affects, that this function
// is available in the header file only, as well as, declaring
// a function in the certain source file with static, where in the
// header file this isn't, a compiler error results
static void internal_function(void) {
	puts("This function is only available in this source file.");
}

int main(void) {
	printf("static variable: %d\n", value++);
	printf("static value (modified): %d <=> %o <=> %x\n", value, value, value);

	internal_function();

	for(int i = 0; i < 10; i++) {
		printf("value_a (non static): %d <=> value_a (static): %d\n", without_static(), with_static());
	}

	return EXIT_SUCCESS;
}