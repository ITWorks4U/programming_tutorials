#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* In C the boolean data type doesn't exist, however, you can
* either simulate a boolean determination by using integer values,
* where 0 means false, every other value means true, no matter is positive or negative
*
* In stdbool.h true is defined as 1, whereas false is defined as 0.
*
* regular way:   int expression = 0   => leads to "false"
* custom way:    #define TRUE 1       => every "TRUE" statement leads to 1
* stdbool.h:     true / false         => leads to 1 / 0
*/

// way 2:
#define TRUE    1
#define FALSE   0

int main() {
	// way 1:
	int condition = 1;

	// NOTE: condition checks (decision making) will be more handled in chapter a:06

	if (condition) {                     // this is always true, as long as, the raw condition value leads to "true"
		// ...
	}

	if (condition == 1) {                // this is true only, if the compared value is 1, otherwise "false"
		// ...
	}

	if (TRUE) {                          // same as the first condition check
		// ...
	}

	if (FALSE) {                         // this will never run the code(s) in this block
		// ...
	}

	// way 3:
	int a = 10;
	int b = 20;

	// definition of boolean expression
	// alternative: int, where 0 <=> false and 1 <=> true
	bool a_is_greater_than_b = a > b;

	// some condidtion check versions:
	if (a_is_greater_than_b) {
		printf("%d is greater than %d\n", a, b);
	} else {
		printf("%d is greater than %d\n", b, a);
	}

	// also mostly used condition check in a short form
	// at this moment a bit hard to understand
	// => this will be described later
	printf("Is %d greater than %d?: %d\n", a, b, a > b ? a : b);

	return EXIT_SUCCESS;
}