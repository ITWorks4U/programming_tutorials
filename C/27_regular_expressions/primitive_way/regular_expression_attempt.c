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

void clean_up_input_buffer(void) {
	int c;
	while ((c = getchar() != '\n' && c != EOF)) {}
}

bool check_on_valid_number_0(void) {
	// using scanf()
	int number_to_use = -1;
	printf("enter a number: ");

	// "ret" contains the return value of scanf
	// scanf() returns 0 for an invalid number, otherwise >0 for "valid"
	//
	// this can be used, but this is also a dumb way to do, furthermore
	// if you combine the input with at least a real leading number
	// and any kind of non numerical characters, then this input
	// is also "valid", which shouldn't
	int ret = scanf("%d", &number_to_use);

	// printf("given input: %d\n", number_to_use);

	return ret != 0;
}

bool check_on_valid_number_1(void) {
	// using an own loop to check character by character
	char input[INPUT_BUFFER];
	memset(input, '\0', INPUT_BUFFER);

	printf("enter a number: ");
	fgets(input, (INPUT_BUFFER - 1), stdin);

	// remove trailing \n from fgets
	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n') {
		input[len - 1] = '\0';
	}

	// printf("your input \"%s\" was ", input);

	for (size_t i = 0; i < strlen(input); i++) {
		// your "number" may also be a negative number
		// if the first character is not "-" or in the range
		// between {0;9}, then this is any input rather
		// than a valid (negative) number
		if (i == 0 && input[i] == '-') {
			continue;
		}

		if ( input[i] < '0' || input[i] > '9') {
			return false;
		}
	}

	return true;
}

bool check_on_valid_number_2(void) {
	// check with atoi(), ...
	// NOTE:  atoi(), atof(), ... are deprecated
	//        functions; moreover those functions
	//        does not handle buffer overflow and
	//        this leads into an undefined behavior
	char input[INPUT_BUFFER];
	memset(input, '\0', INPUT_BUFFER);

	printf("enter a number: ");
	fgets(input, (INPUT_BUFFER - 1), stdin);

	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n') {
		input[len - 1] = '\0';
	}

	// printf("your input \"%s\" was ", input);

	// atoi() returns 0 for an "invalid" number
	// What if, "0" was typed in...?
	return atoi(input) != 0;
}

bool check_on_valid_number_3(void) {
	// check with strtol(), ...
	// NOTE:  strtol(), strtod(), ... are much
	//        better than atoi(), ..., however,
	//        only those characters, which are a
	//        real number can be handled. Every other
	//        not numerical character can be moved into
	//        a remaining C-string array. That means, that
	//        all real number characters behind a non
	//        numerical character are also invalid.
	char input[INPUT_BUFFER];
	memset(input, '\0', INPUT_BUFFER);

	printf("enter a number: ");
	fgets(input, (INPUT_BUFFER - 1), stdin);

	size_t len = strlen(input);
	if (len > 0 && input[len - 1] == '\n') {
		input[len - 1] = '\0';
	}

	// printf("your input \"%s\" was ", input);

	// the input is compared character by character;
	// every non numerical character can be lead to **endptr, if given;
	// radix tells, what kind of number format is requested
	//    0 | 10: defaults to decimal
	//         2: binary
	//         8: octal
	//        16: hexadecimal

	// And again, what if, "0" was typed in...?
	return strtol(input, NULL, 10) != 0;
}

int main(void) {
	// NOTE:  All these ways are primitive and are
	//        surrounded with flaws. You shoud NEVER
	//        use them to check for a valid input.

	printf("Your 1st check attempt was %s\n", check_on_valid_number_0() ? "numerical" : "not numerical");
	clean_up_input_buffer();

	// NOTE:  after clean up the input buffer, you
	//        may hit enter again to get to the next
	//        check or result

	printf("Your 2nd check attempt was %s\n", check_on_valid_number_1() ? "numerical" : "not numerical");
	clean_up_input_buffer();

	printf("Your 3rd check attempt was %s\n", check_on_valid_number_2() ? "numerical" : "not numerical");
	clean_up_input_buffer();

	printf("Finally, your 4th check attempt was %s\n", check_on_valid_number_2() ? "numerical" : "not numerical");
	clean_up_input_buffer();

	return EXIT_FAILURE;
}