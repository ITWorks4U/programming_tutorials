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
#include <string.h>

int main(void) {
	char word[50];
	char fixed_expression[] = "A fixed expression for our purpose.";

	/* Won't work in C! */
	// word += fixed_expression;

	// will be interpreted as an addition of two numbers, if this might
	// not throw an error during compile time
	// word = word + fixed_expression

	/*
	* concatenation: add a string to an another string; doesn't handle buffer overflow
	* char *strcat(char *destination, const char *source);
	*
	* char *strncat(char *destination, const char *source, size_t __n);
	* add n characters from source to destination; doesn't handle buffer overflow
	*
	* for Visual Studio:
	* use strcat_s() / strncat_s() instead
	*/
	memset(word, '\0', 50);
	strncat(word, fixed_expression, strlen(fixed_expression));
	printf("word contains: %s\n", word);

	return EXIT_SUCCESS;
}