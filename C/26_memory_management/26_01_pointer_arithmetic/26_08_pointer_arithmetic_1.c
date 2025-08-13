/*
* What about C-Strings? That's right, C-Strings are an array of n characters.
* In that case, this can also be used for a pointer arithmetic.
*/

#include <stdio.h>
#include <stdlib.h>

#define STRING_EXPRESSION	"Hello world!"

void simple_c_string_handling(void) {
	char expression[] = "This is a simple string.";
	char *holy_moly = expression;

	//	a C-String and also any other field does not need to use & character, because
	//	this can automatically be used for output, however, on a function (call by reference)
	//	this might be different to hande, depending on what exactly is planned to do
	printf("[(%s, %pH) <=> (%s, %pH)]\n", expression, expression, holy_moly, holy_moly);

	//	this can't be used, because this is a syntax error
	// expression++;
	holy_moly++;

	puts("What's happening here?");
	printf("[(%s, %pH) <=> (%s, %pH)]\n", expression, expression, holy_moly, holy_moly);

	//	With holy_moly++, the pointer now points to the next character of expression.
	//	What will happen, if holy_moly-- comes twice?
	holy_moly--;
	holy_moly--;

	puts("OK. Now what?");
	printf("[(%s, %p) <=> (%s, %p)]\n", expression, expression, holy_moly, holy_moly);
}

void confusing_c_string_handling(void) {
	char expression[] = "This is a simple string.";

	//	this is not recommended
	long *holy_moly = expression;

	printf("[(%s, %pH) <=> (%ld, %pH)]\n", expression, expression, holy_moly, holy_moly);
	holy_moly++;

	puts("What in the hell did you done?");
	printf("[(%s, %pH) <=> (%ld, %pH)]\n", expression, expression, holy_moly, holy_moly);
}

void surprise_with_macro_string(void) {
	//	Of course, this does not work, since
	//	STRING_EXPRESSION is a C-string.
	//	In that case this is a constant expression
	//	and this can't be modified.
	// STRING_EXPRESSION++;

	char *ptr = STRING_EXPRESSION;

	printf("[(%s, %pH) <=> (%s, %pH)]\n", STRING_EXPRESSION, STRING_EXPRESSION, ptr, ptr);
	ptr++;
	printf("[(%s, %pH) <=> (%s, %pH)]\n", STRING_EXPRESSION, STRING_EXPRESSION, ptr, ptr);
}

int main(void) {
	//	normal way for C-string handling
	simple_c_string_handling();

	puts("-------------");
	//	And what happens, if a C-String or any other field points to a C-String?
	confusing_c_string_handling();

	puts("-------------");
	surprise_with_macro_string();

	return EXIT_SUCCESS;
}