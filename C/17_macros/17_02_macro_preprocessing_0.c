/*
* Macros are (very) powerful and
* often used for C and mostly for C++, however,
* these offers you a bunch of problems, if you don't mind them.
*
* There're different ways to use macros:
* - constant expression
* - functions (Use that with care!)
* - preprocessing expression
*
* Attention:
* Macros does not have a type specification! So you can also get
* an undefined behavior or a logical error in your application!
*/

#include <stdio.h>
#include <stdlib.h>

//	define a preprocessing command
//	those can be used to determine to compile a block of code
//	only, if the preprocessing command is defined
//
//	However, there're different ways to handle a preprocessing unit!

//	this command is defined without any value
#define COMMAND

int main(void) {
	/*
		check, if COMMAND exists (a number is required, otherwise an error exists)
		for 0: condition check is false
		any number: condition check is true
	*/
	//	now check, if COMMAND is defined
	//	to realize this, #if ... #endif is required

	//	pitfall: if your macro doesn't store any numeric value,
	//	then #if COMMAND causes an error on compile time
	// #if COMMAND
	// puts("Yeah, COMMAND is defined...");
	// #endif

	//	so you have to use an alternative way, like:
	#if COMMAND 1
		puts("COMMAND is defined...");
	#else
		puts("COMMAND is not defined...");
	#endif

	//	usually used to check, if a preprocessing unit is defined
	#ifdef COMMAND
		puts("COMMAND is defined...");
	#else
		puts("COMMAND is not defined...");
	#endif

	//	check, if COMMAND is undefined
	#ifndef COMMAND
		puts("COMMAND is not defined.");
	#else
		puts("COMMAND is defined...");
	#endif

	//	hardly used, but does the same action
	#if defined(COMMAND)
		puts("COMMAND is defined...");
	#else
		puts("COMMAND is not defined.");
	#endif

	//	any other macro definition condition check can also be used,
	//	even "ABC" does not exist anywhere
	#ifdef ABC
		puts("ABC is defined...");
	#endif

	return EXIT_SUCCESS;
}