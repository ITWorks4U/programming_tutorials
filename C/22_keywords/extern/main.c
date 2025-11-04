#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

int main(void) {
	/*
	* Since data is defined as extern in the header file
	* and declared with a value in the source file, this
	* variable can now be used here. This variable is also
	* able to modify.
	*/
	printf("data = %d\n", data);
	data++;
	printf("data = %d\n", data);

	struct test_0 t_0 = {
		.a = 9,
		.b = 10
	};
	printf("(%d, %d)\n", t_0.a, t_0.b);

	// test_1, however, can't be used to access
	// to test_1 from external source file
	//
	// this can be declared again, which is
	// available in this main only
	#define BUFFER_LENGTH 100

	struct test_1 {
		char word[BUFFER_LENGTH];
	};

	struct test_1 t_1;
	memset(t_1.word, '\0', BUFFER_LENGTH);
	strcpy(t_1.word, "Take a look to this output...");
	printf("%s\n", t_1.word);

	return EXIT_SUCCESS;
}