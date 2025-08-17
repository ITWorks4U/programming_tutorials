#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
	* switch(expression) offers a better handling of events by given expression.
	* Make sure to use a break; statement in each case, otherwise the next
	* case instruction is also in use!
	*/

	int number_level;
	printf("enter a number: ");
	scanf("%d", &number_level);

	switch(number_level) {
		case 0:
			//	This code is in use only, if number_level contains 0 only.
			break;
		case 1:
			//	only for 1
			break;
		case -123:
			//	only for -123...
			break;
		case 100:
		case 200:
		case 300:
			//	you can also handle multuple, fixed cases
			break;
		default:
			//	any other unmanaged case lands here
			break;
	}

	/*	weired behavior of scanf():	*/

	//	What happens here? => if number_level stores 0, which is a valid number,
	//	this will be wronly used. If you want to check, if 0 is a valid number,
	//	use a regular expression instead. => This will be handled later.
	if (number_level) {
		puts("This statement is \"true\"");
	} else {
		puts("This statement is \"false\"");
	}

	return EXIT_SUCCESS;
}