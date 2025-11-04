#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int valueA = 100;
	int valueB = 200;

	/*
	* logical AND => &&
	* logical OR => ||
	*
	* Don't be confused with a single & or | => These are bitwise operators
	* and does not have any with the logical AND or logical OR!
	* take a look to part 11 for bitwise operations.
	*/

	if (valueA >= 100 && valueB >= 100) {
		puts("This statement is \"true\"");
	}

	// identical to condition check above
	if (valueA && valueB) {
		puts("This statement is \"true\"");
	}

	if (valueA >= 200 || valueB >= 200) {
		puts("This statement is \"true\"");
	}

	return EXIT_SUCCESS;
}