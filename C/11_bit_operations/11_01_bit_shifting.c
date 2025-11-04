/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// Bit shifting allows you to move the bits by n positions to the left or right.
	// Shift to the left makes the number bigger, where right shift makes the number smaller.

	int a = 42;

	// 42 becomes 336
	printf("%d\n", a << 3);

	// 42 becomes 5
	printf("%d\n", a >> 3);

	return EXIT_SUCCESS;
}