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

//	some more fun with predefined macro preprocessing values
int main(void) {
	//	print the current file name and line number
	printf("Using file: \"%s\" on line: %d\n", __FILE__, __LINE__);

	//	check, on which OS this application currently runs
	printf("You're running this application under a ");

	//	hint: there're different ways to check, if this application is going to run on
	//	a Windows machine, depending on which version for compiler, or Windows you're using
	//	these can also be possible definitions for Windows:
	//	- __WIN32__, __WIN64__
	//	- __WIN32, __WIN64
	//	- __MSDOS__ (really, for MSDOS)
	#ifdef _WIN32
	//	_WIN64 doesn't need to be checked in a separate block, because
	//	_WIN32 already covers 32 and 64 bit
	puts("Windows 32 or Windows 64 machine.");
	#elif defined(__unix__) || defined(__linux__)
	//	you can also combine multiple preprocessing values,
	//	but sometimes this works only with defined(X) expression
	puts("Linux machine.");
	#elif defined(__APPLE__) || defined(_MAC)
	puts("macOS machine");
	#elif __MSDOS__
	puts("MS DOS machine.")
	#else
	puts("n unknown OS...");
	#endif

	return EXIT_SUCCESS;
}