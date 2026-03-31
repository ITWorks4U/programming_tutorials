#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
	* Usually, in C/C++ every condition check returns 0 for
	* false, every other value is true! Typically the number
	* range {0, 1} is used only.
	*/
	int valueA = -100;

	if (valueA) {
		puts("This statement is \"true\"");
	}

	return EXIT_SUCCESS;
}