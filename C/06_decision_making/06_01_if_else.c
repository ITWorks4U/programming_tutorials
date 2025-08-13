#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int valueA = -100;

	if (valueA) {
		puts("This statement is \"true\"");
	} else {
		puts("This statement is \"false\"");
	}

	return EXIT_SUCCESS;
}