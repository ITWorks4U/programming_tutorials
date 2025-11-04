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

	/* Won't work in C, unless pointers are in use. => See: chapter 26. */
	// word = fixed_expression;

	// In C, and also C++, this can be used, but it's also NOT recommended
	// *word = *fixed_expression;

	// this can be used, however, since >>word<< contains any garbage you don't
	// know, what word may also contain data after fully copying each character
	// from fixed_expression to word
	// for(size_t i = 0; i < strlen(fixed_expression); i++) {
	// 	word[i] = fixed_expression[i];
	// }

	/*
	* copy a text to an another C-string; doesn't handle buffer overflow
	* char *strcpy(char *dest, const char *source);
	*
	* returns the memory address pointer for dest (rarely used)
	*
	* char *strncpy(char *dest, const char *source, size_t __n);
	* copies n characters from source to destination; doesn't handle buffer overflow
	*
	* for Visual Studio:
	* use strcpy_s(), strncpy_s(), ... instead
	*/
	strncpy(word, fixed_expression, strlen(fixed_expression));
	printf("word contains: %s\n", word);

	return EXIT_SUCCESS;
}