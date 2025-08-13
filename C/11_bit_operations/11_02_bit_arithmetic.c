/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// bit operators can also be used for arithmetic operations to speed up the calculation
	// hardly used, but still worth

	int a = 42;
	int b = 9001;

	//	arithmetic way
	printf("%d is odd or even? => %s\n", a, a % 2 == 0 ? "even" : "odd");
	printf("%d is odd or even? => %s\n", b, b % 2 == 0 ? "even" : "odd");

	//	bitwise way
	//	only the last bit is checked with 1
	//	if true, then this number is odd, otherwise even
	printf("%d is odd or even? => %s\n", a, (a & 1) == 0 ? "even" : "odd");
	printf("%d is odd or even? => %s\n", b, (b & 1) == 0 ? "even" : "odd");

	return EXIT_SUCCESS;
}