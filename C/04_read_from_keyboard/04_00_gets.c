#include <stdio.h>
#include <stdlib.h>

/*
* With gets() you're able to read any input from keyboard, however, it's strictly
* recommended TO NOT TO USE this function! The gets() function has no buffer overflow
* protection, therefore you can crash your application very easily.
*
* By the way, almost every function, which reads from a file stream has not a clear
* limitation for the input buffer. Use your mind to figure out, when a buffer has
* reached its limit!
*/

int main(void) {
	// holds a single sign only
	char single_sign;

	// holds up to 31 characters including a null termination character \0
	char word[32];

	// fixed word
	char fixed_word[] = "A given string with a fixed length";

	// reading from keyboard
	printf("enter something: ");
	gets(word);

	// see, what happens
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}