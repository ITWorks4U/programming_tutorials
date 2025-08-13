#include <stdio.h>
#include <stdlib.h>

/*
	It doesn't matter, which input function you're using, when you don't clear
	the input buffer with any characters left. This input buffer causes a
	wrong behavior if you're using a next input function. The buffer with n characters
	left has a higher priority instead of your keyboard, a file, ...

	Perhaps you have heared to use a function, like:
	fflush(stdin);

	This, however, does NOT clear your input buffer. This is only in use
	for output buffer.

	To clear the input buffer, use this syntax:
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
*/

int main(void) {
	char single_sign;
	char word[32];
	char fixed_word[] = "A given string with a fixed length";
	int number;

	// assuming, you may input more than 31 characters
	printf("enter something for word: ");
	fgets(word, 31, stdin);

	//	this will clear the input buffer left
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	/*
	* Try to run your application without that clean up
	* instruction above. Are you able to enter anything
	* for word_2? Obviously, you can't.
	*/
	printf("enter again a new input for word_2: ");
	char word_2[32];
	fgets(word_2, 31, stdin);

	/*	see, what happens:	*/
	printf("your input was: %s\n", word);
	printf("word_2 contains: %s\n", word_2);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}