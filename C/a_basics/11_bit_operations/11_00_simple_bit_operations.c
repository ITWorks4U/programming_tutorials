/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
	* size of an integer value: 4 bytes
	* maximum number of an integer value (in C):     2,147,483,647
	* binary representation:                         11111111 11111111 11111111 11111111
	*
	* What operators are in use?
	* & => bitwise and
	* | => bitwise or
	* ~ => bitwise not
	* ^ => bitwise xor
	*
	* Don't mix bitwise and or bitwise or with && or ||, because these are logical operators.
	*/

	
	int a = 42;                                  // 00000000 00101010
	int b = 9001;                                // 00100011 00101001

	printf("%d\n", a & b);                       // a AND b => 40
	printf("%d\n", a | b);                       // a OR b => 9003
	printf("%d\n", a ^ b);                       // a XOR b => 8963 | NOTE: if a XOR a or b XOR b is in use, 0 always returns
	printf("%d\n", ~a);                          // NOT a => -43
	printf("%d\n", ~a & b);                      // NOT a AND b => 8961
	printf("%d\n", ~(a & b));                    // NOT (a AND b) => NAND(a, b) => -41
	printf("%d\n", ~(a & ~b));                   // NOT (a AND NOT b) => NOT a OR b => -3
	printf("%d\n", ~(a | b));                    // NOT a OR b => NOR(a, b) => -9004
	printf("%d\n", ~(a ^ b));                    // NOT a XOR b => NXOR(a, b) => -8964

	return EXIT_SUCCESS;
}