#include <stdio.h>
#include <stdlib.h>

/*
* It makes no sense to define more than one main function. The main function represents the
* entry point of your application. You may also give the main function arguments to handle
* these input values.
*/

/*
* mostly used => attention: any function in C, which has "no arguments" has a different
* behavior in contrast to C++
*/
int main() {
	return EXIT_SUCCESS;
}

/* almost identical to function above without accepting any argument */
int main(void) {
	return EXIT_SUCCESS;
}

/* used to handle n arguments for your application;
*  unlike to use char *argv[], **argv is also often in use
*
*  NOTE: Each argument, no matter what, is always a C-string.
*/
int main(int argc, char *argv[]) {
	for(int i = argc; i < argc; i++) {
		printf("argument on postion %d = %s\n", i, argv[i]);
	}

	return EXIT_SUCCESS;
}

/* hardly used, however, you'll get a warning on compile time, because a main must be of type int */
void main() {
}

void main(void) {
}

void main(int argc, char *argv[]) {
}