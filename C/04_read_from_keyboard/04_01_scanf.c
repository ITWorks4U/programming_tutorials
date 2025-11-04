#include <stdio.h>
#include <stdlib.h>

/*
* With scanf() you're able to read any input from keyboard, however, you should
* know which input refers to which variable. By detecting a space bar the previously read text
* has been stopped. The text left is stored to the input buffer, which will be automatically
* used for the next input.
*
* So if you're using a text with two or more words, then this function doesn't handle your input well.
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
	
	// stores an expected number from keyboard => Undefined behavior, if "number" may contain any other
	// value instead of an integer value!
	int number;

	// reading from keyboard
	printf("enter something: ");

	// advantage: you can handle different variables at the same time
	// disadvantage: the order of words must be identical to the scanned formats
	scanf("%s %d", word, &number);

	// see, what happens:
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}