/*
* What will happen, if at least two pointers refers to one memory address?
* Correct, undefined behavior is incoming (again).
*
* In C you don't have a chance to fix that issue easily.
* In C++ you might handle this a bit easier by using smart pointers.
* Take a look to section 26_02.
*/

#ifdef __cplusplus
#error	"This sample is not planned to build with a C++ compiler. Use a C compiler instead."
#else
#warning	"This sample contains an undefined behavior!"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *field_0 = calloc(100, sizeof(int));
	int *field_1 = field_0;

	//	now field_0 and also field_1 refers to the same memory
	//	=> this can be used for shared memory, however, this is
	//	also a huge pitfall
	//
	//	NOTE:
	//	On a Windows system you might not see any difference, but this
	//	is a tricky and also a high critical moment, because in that way
	//	you don't see the error in this code.

	//	do something here

	//	Now what happens, if field_1 has been freed, whereas
	//	field_0 has been created with malloc(), calloc(), ...?

	//	yep, field_1 can be freed with free()
	free(field_1);

	//	you should NOT try to use free field_0, because this pointer
	//	has automatically been released, too
	free(field_0);

	return EXIT_SUCCESS;
}
#endif