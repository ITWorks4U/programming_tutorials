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

//	contains functions for C-strings
#include <string.h>

int main(void) {
	char word[50];
	char fixed_expression[] = "A fixed expression for our purpose.";

	/*
	* There're two ways to determine the length of a string, whereas it's not
	* a good choice to use them those at every time:
	*
	* 1) strlen()
	* 2) sizeof()
	*/

	//	determine the length of a string: size_t strlen(const char *s);
	//	The strlen() function calculates the length of the string pointed to by s,
	//	excluding null terminating null byte ('\0').
	printf("word contains %lu characters\n", strlen(word));

	//	however, if you use sizeof(word), the result is different rather than strlen()
	//	sizeof() returns the maximum amount of possible storage for given C-string
	printf("word contains %lu characters\n", sizeof(word));

	//	What about fixed_expression? Surprised?
	printf("fixed_expression contains %lu characters\n", strlen(fixed_expression));
	printf("fixed_expression contains %lu characters\n", sizeof(fixed_expression));

	//	in summary:
	//	strlen(): counts all characters until the first null termination character \0 has been detected
	//	sizeof(): counts the maximum number of possible storage characters with null termination character
	//
	//	in summary, part 2:
	//	since >>word<< contains up to 50 characters and this is not initialized, it contains garbage and
	//	your >>word<< may result any content

	return EXIT_SUCCESS;
}