#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int counter = 0;

	//	-----------
	//	allows to jump to that mark, if called
	//
	//	it's an "easy" implementation, however,
	//	it causes "spaghetti code", because it's
	//	much harder to debug in case of an error
	//
	//	When or why shall goto statements be used?
	//	If you know, how the assembly version exactly works,
	//	especially, if you know, what YOU do, then you can
	//	optimize your code to reduce steps for the machine code
	//	-----------
	mark:
	printf("counter = %d\n", counter);

	if (counter < 10) {
		//	-----------
		//	command to jump to a certain mark
		//	-----------
		goto mark;
	}

	return EXIT_SUCCESS;
}