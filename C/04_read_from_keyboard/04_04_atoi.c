#include <stdio.h>
#include <stdlib.h>

/*
	With atoi() (argument to integer), atol(), atof(), ... you can try to convert the given
	word to an integer, long, float, ... , however, these functions have no buffer overflow
	detection and mostly no error on compile time appears when a wrong format is in use.
*/

int main(void) {
	//	may be used, because 100 is a valid integer value, however, ...
	int number = atoi("100");
	printf("number = %d\n", number);

	//	What may happen here?
	//	Do you see a warning on compile time?
	//	Do you see 123 in number?
	//	=> At this point it's not clear what may happen here!
	number = atoi("123 I don't care about a wrong input!");
	printf("number = %d\n", number);

	return EXIT_SUCCESS;
}