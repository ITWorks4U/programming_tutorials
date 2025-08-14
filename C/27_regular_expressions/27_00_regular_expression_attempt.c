/*
* Reading from the keyboard and try to check, if the input
* is a numeric expression. This does not contain any regular
* expression.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_BUFFER 100

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

	//	appendix:
	//	this also a "way" to check out, if a number has been typed in,
	//	however, this is also surrounded with flaws

	//	clean up input buffer => you may hit enter again
	int c;
	while ((c = getchar() != '\n' && c != EOF)) {}

	char input[INPUT_BUFFER];
	memset(input, '\0', INPUT_BUFFER);

	printf("again: print any number: ");
	fgets(input, (INPUT_BUFFER - 1), stdin);

	//	remove trailing \n from fgets
	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n') {
		input[len - 1] = '\0';
	}

	bool on_number = true;
	printf("your input \"%s\" was ", input);

	for (size_t i = 0; i < strlen(input); i++) {
		//	your "number" may also be a negative number
		//	if the first character is not "-" or in the range
		//	between {0;9}, then this is any input rather
		//	than a valid (negative) number
		if (i == 0 && input[i] == '-') {
			continue;
		}

		if ( input[i] < '0' || input[i] > '9') {
			on_number = false;
			break;
		}
	}

	if (on_number) {
		puts("a number");
	} else {
		puts("not a number");
	}

	return EXIT_SUCCESS;
}