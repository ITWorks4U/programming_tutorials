#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* In C the boolean data type doesn't exist, however, you can
* either simulate a boolean determination by using integer values,
* where 0 means false, every other value means true, by defining
* your own boolean determination or by using stdbool.h.
*
* In stdbool.h true is defined as 1, whereas false is defined as 0.
*/

int main() {
	int a = 10;
	int b = 20;

	//	definition of boolean expression
	//	alternative: int, where 0 <=> false and 1 <=> true
	bool a_is_greater_than_b = a > b;

	//	some condidtion check versions:
	if (a_is_greater_than_b) {
		printf("%d is greater than %d\n", a, b);
	} else {
		printf("%d is greater than %d\n", b, a);
	}

	//	also mostly used condition check in a short form
	//	at this moment a bit hard to understand
	//	=> this will be described later
	printf("Is %d greater than %d?: %d\n", a, b, a > b ? a : b);

	return EXIT_SUCCESS;
}