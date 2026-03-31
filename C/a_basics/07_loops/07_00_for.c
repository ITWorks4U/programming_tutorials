#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// -----------
	// for loop (stops automatically when end condition is no longer given)
	// -----------

	/* sequential loop */
	for(int i = 0; i < 10; i++) {
		printf("%d\n", i);
	}

	/* sequential loop in reversal order */
	for(int i = 9; i >= 0; i--) {
		printf("%d\n", i);
	}

	/* modifying index	*/
	for(int i = 0; i < 10; i++) {
		printf("%d\n", i++);
	}

	/* skipping a step */
	for(int i = 0; i < 10; i++) {
		if (i == 5) {
			continue;
		}

		printf("%d\n", i);
	}

	/* canceling loop */
	for(int i = 0; i < 10; i++) {
		if (i == 5) {
			break;
		}

		printf("%d\n", i);
	}

	/* infinite loop (use this with care) */
	for(;;) {
		/* at this point this loop ends only, if a break statement has been detected */
		break;
	}

	/* usually, an infinite for loop can also looks like:	*/
	for(int i = 0;;i++) {
		/* since no exit condition is defined, this loop also runs over and over again */
		if (i == 10) {
			break;
		}
	}

	/* also an infinite loop, however, THIS can't be handled in the usual way! */
	// for(;;);

	return EXIT_SUCCESS;
}