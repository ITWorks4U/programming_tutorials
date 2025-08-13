#include <stdio.h>
#include <stdlib.h>

/*
* You're also able to read a single sign from keyboard by using one of
* these functions: getc(), fgetc(), getchar(), getch(). The single sign
* will be converted as an integer and can't be referenced to a C-string!
*
* By the way, almost every function, which reads from a file stream has not a clear
* limitation for the input buffer. Use your mind to figure out, when a buffer has
* reached its limit!
*/

int main(void) {
	char single_sign;
	char word[32];
	char fixed_word[] = "A given string with a fixed length";
	int number;

	/*	reading from keyboard	*/
	printf("enter a single character: ");

	//	reading from a string (stdin: keyboard)
	getc(stdin);

	printf("again... ");
	//	better handling in contrast to getc(), but does the same action
	fgetc(stdin);

	printf("and again... ");
	//	reading a single character from keyboard (stdin is fixed)
	getchar();

	//	often used on Windows and turbo C
	// getch();

	/*	see, what happens:	*/
	printf("your input was: %s\n", word);
	printf("signle_sign contains...? \"%c\"\n", single_sign);
	printf("fixed word: %s\n", fixed_word);

	return EXIT_SUCCESS;
}