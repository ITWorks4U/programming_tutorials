/*
* Reading from the keyboard and try to check, if the input
* is a numeric expression. This does not contain any regular
* expression.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	/*
	* really stupid and a primitive way, too
	*
	* It may work for positive integers well, however, what happens,
	* if you're using a floating point expression, hexadecimal expression, ...?
	*
	* Of course, it won't work (well). You also might cause an undefined behavior on runtime.
	*/

	//	let's use this
	int number_to_use = -1;

	printf("enter a number: ");

	//	"ret" contains the return value of scanf
	//	scanf() returns 0 for an invalid number, otherwise >0 for "valid"
	//
	//	this can be used, but this is also a dumb way to do, furthermore
	//	if you combine the input with at least a real leading number
	//	and any kind of non numerical characters, then this input
	//	is also "valid", which shouldn't
	int ret = scanf("%d", &number_to_use);

	printf("given input: %d\n", number_to_use);

	if (ret == 0) {
		puts("Your input was not a number. :(");
	} else {
		puts("Your input was a number. :)");
	}

	return EXIT_SUCCESS;
}