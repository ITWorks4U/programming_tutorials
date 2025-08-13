#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	//	-----------
	//	in contrast to a while loop the do-while-loop runs at least
	//	once and the condition check, which determines to run the next
	//	iteration is at the end of that loop
	//
	//	unlike to a while loop in the do-while-loop the while statement
	//	must end with a semicolon
	//	-----------
	int ctr = 0;

	do {
		printf("%d\n", ctr);
		ctr++;
	} while(ctr < 10);

	do {
		ctr--;

		if (ctr % 2 == 0) {
			continue;
		}
		printf("%d\n", ctr);
	} while(ctr != 0);

	/*	infinite loop examples	*/
	//	never leaves a loop in the usual way
	// do {} while(1);
	// do {} while(true);

	do {
		ctr++;
		printf("%d\n", ctr);

		if (ctr == 100) {
			break;
		}
	} while(true);

	return EXIT_SUCCESS;
}