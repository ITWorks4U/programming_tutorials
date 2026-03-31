#include <stdio.h>
#include <stdlib.h>

int main() {
	/* trying to print an integer by using a different format */
	// 1,517,538,462
	int a = 1517538462;

	printf("a as decimal value = %d\n", a);              // regular formatted output for an integer
	printf("a as octal value = %o\n", a);                // octal expression | %O won't work
	printf("a as hexadecimal value = %X\n", a);          // hexadecimal expression | %x prints 0x instead of OX
	printf("a as exponential value = %e\n", a);          // format into an exponentional value | won't correctly work for an integer
	printf("a as short value = %d\n", (short)a);         // transfer the integer data type into a short data type => short as a smaller range than an integer

	// %c can only display a visible character between 33 and 127!
	// 0 - 31: system command, like \0, \n, \b, ... 32: space
	printf("a as char value = %c\n", a);                 // try to transfer the integer value into its character on ASCII table, IF possible

	// printf("a as string value = %s\n", a);            // causes a segmentation fault => application crashes
	printf("a as long value = %ld\n", (long) a);         // transfer the integer data type into a long data type | you may get a warning on compile time
	printf("a as unsigned int value = %u\n", a);         // works correctly for an integer, since it's not declared as 'unsigned'
	printf("a as float value = %f\n", a);                // transfer the integer data type into a single floating point number | won't work correctly
	printf("a as double value = %lf\n", a);              // maybe the same result for a double floating point number
	printf("a as pointer value = %p\n", &a);             // return the address, where this integer has been placed during runtime
	                                                     // strictly recommended: use & in front of the variable, otherwise a wrong address returns
                                                         // followed by an undefined behavior

	return EXIT_SUCCESS;
}