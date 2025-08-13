/*
* Working with strings in C.
* It's difficult in contrast to other
* programming languages, because in C
* a string will be handled in a different way.
*
* It's not recommended to run this code under C++,
* because it may cause to crash the application!
*/

#include <stdio.h>
#include <stdlib.h>

//	contains functions to work with for C-strings
#include <string.h>

// usually, on Windows the library <strings.h> is might not be available
// => this can be handled by macro condition checks => described in chapter 17
// or it can be commented out
#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
// for strcasecmp() function
#include <strings.h>
#endif

int main(void) {
	//	C-string with up to 49 characters (last char: \0)!
	char word[50];

	//	fixed C-string with 36 characters (with \0)
	char fixed_expression[] = "A fixed expression for our purpose.";

	/*	May work for C, but that's not recommended!	*/
	if (word != fixed_expression) {
		puts("These C-Strings are different.");
	} else {
		puts("These C-Strings are equal.");
	}

	/*
		comparing two C-strings to each other
		int strcmp(char *s1, char *s2);

		returns:
		< 0		:=		s1 is smaller than s2
		0		:=		s1 is equal to s2
		> 0		:=		s1 is greater than s2

		int strncmp(char *s1, char *s2, size_t __n);
		compares two C-strings up to n characters

		in Visual Studio (Windows) these functions are (horrible) deprecated and shall not used anymore

		function     |    "new" function
		-------------|--------------------
		strcmp       |    strcmp_s
		strncmp      |    strncmp_s
		...          |    ...
	*/

	//	don't expect a useful result => since >>word<< looks like an "empty" string, this is wrong, because an uninitalized
	//	variable, C-string, ... holds garbage on runtime, thus you don't really know what that variable
	//	contains on runtime until assignment
	printf("%d\n", strcmp(word, fixed_expression));

	// this function below comes from strings.h (not Windows)
	// in Windows: this function is defined in string.h instead

	//	ignoring case formatting; result differs to above
	printf("%d\n", strcasecmp(word, fixed_expression));

	return EXIT_SUCCESS;
}