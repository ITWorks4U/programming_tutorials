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
	// Since we know, that >>word<< contains garbage on runtime,
	// it's now time to initialize it with null termination characters
	char word[50];
	char fixed_expression[] = "A fixed expression for our purpose.";

	// could be a way, however, "50" is a "magical number" and may also
	// result into an undefined behavior, when that counter condition
	// is greater than the maximum storage for word itself:
	// for(int i = 0; i < 50; i++) {
	// 	word[i] = '\0';
	// }

	// use one of those functions instead:
	// memset()
	// bzero() => not available for Windows

	// void * memset(void *_Dst, int _Val, size_t _Size);
	// copy to _Dst => _Val => _Size times
	memset(word, '\0', 50);

	strncpy(word, fixed_expression, strlen(fixed_expression));
	printf("word contains: %s\n", word);

	return EXIT_SUCCESS;
}