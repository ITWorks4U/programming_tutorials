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

//	--------------------------
//	define a new macro
//
//	ATTENTION: Make sure, that this macro does not exist anywhere in
//	your application, which means, in your included header file this
//	expression may already be defined there!
#define LENGTH 200
//	"200" above will be interpreted as an integer by default
//	you can also use literals (see chapter 20) to clearly determine
//	a type for a value / expression

//	--------------------------
//	undefinition of a macro
//	if this macro does not exist, no warning appears on compile time
//
//	ATTENTION: Make sure, that this macro does not exist anywhere in
//	your application, especially in included header files, which may
//	be defined there to do anything, otherwise on compile time or
//	runtime an undefined behavior may appear!
#undef NOTHING123
//	--------------------------

void fun_with_macro_usage();

int main(void) {
	//	use length (expected as an integer) to count something...
	for(int i = 0; i < LENGTH; i++) {
		printf("%d\n", i);
	}

	fun_with_macro_usage();

	//	that's a macro, too :o)
	return EXIT_SUCCESS;
}

void fun_with_macro_usage() {
	//	What happens here?
	#undef LENGTH

	//	at this point LENGTH is no longer known and the compiler throws an error
	// printf("LENGTH = %d\n", LENGTH);

	// now LENGTH can be redefined with any other data
	// if LENGTH hasn't been undefined before a warning appears
	// on compile time
	#define LENGTH "ABC"
	printf("%s\n", LENGTH);
}