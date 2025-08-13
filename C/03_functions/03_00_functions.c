/*
* basic functionality of functions in C
* every function has: [modifier] <data type> <function name> ([arguments: <datatype> <name>, <datatype> <name>, ...]) {}
*
* [] := optional
* <> := required
*/

#include <stdio.h>
#include <stdlib.h>

/*	numeric data types always a value of the type	*/
float function1() {
	return 1234.5678F;
}

/*	data function without a return value; on compiling (C/C++) you'll get a warning only	*/
short function2() {}

/*	void never requires a return type, but you may given them one, if you like...*/
void function3() {}
void function4() {
	puts("Any text!");

	//	A void function hardly needs a return statement,
	//	however, if this function comes with more code, which
	//	is not planned to use, this can speed up your application,
	//	because the code left is never touched and the function
	//	has been left earlier.

	//	If the return statement is on the end of that void function,
	//	then this command is obsolete.
	return;
}

/*	...unless you're using pointers :P	*/
//	will be handled later
void* what_is_this() {
	return NULL;
}

int main(void) {
	//	1234.5678 returns
	printf("%f\n", function1());

	//	What will be printed here?
	printf("%d\n", function2());

	//	for function3() and function4() it won't cooperate with the printf() function
	function3();
	function4();

	//	prints the address of the pointer, if given
	printf("%p\n", what_is_this());

	return EXIT_SUCCESS;
}