#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
	//	-----------
	//	while loop (runs, while a certain condition is given)
	//	in contrast to a for loop make sure, that the condition in the head
	//	will false at any time to leave the loop
	//	-----------
	int ctr = 0;
	while(ctr < 10) {
		ctr++;																				//	required, otherwise the loop never ends
		printf("%d\n", ctr);
	}

	while (ctr != 0) {
		ctr--;

		if (ctr % 2 == 0) {
			continue;
		}

		printf("%d\n", ctr);
	}

	/*	infinite loop in C-style until stdbool was available	*/
	while(1) {
		break;
	}

	/*	infinite loop with a boolean expression	*/
	while(true) {
		break;
	}

	/*	Also an infinite loop, however, THIS can't be left in a usual way!	*/
	// while(true);

	return EXIT_SUCCESS;
}