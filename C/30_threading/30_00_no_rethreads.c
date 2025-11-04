/*
* Similar to sub processes threads allows you to work with many parallel tasks,
* because each CPU core can do a single action to speed up your application,
* however, using threads are tricky and may also cause an undefined behavior or,
* worse, a deadlock.
*
* On Windows you can't use POSIX threads by default. In that case you have to do
* an alternative way.
*
* This sample, however, doesn't comes with any threading.
*
* Remember: by using UNIX/Linux/... you should use -lm to tell the compiler to
* work with math functions and math objects. On Windows this is not required.
*/

#include <stdio.h>
#include <stdlib.h>
#include "30_library/30_threading.h"

int main(void) {
	puts("launching the application without threads...");
	load_numbers_from_file();

	if (coord_on_continue) {
		// use the bubble sort algorithm twice to sort 250,000 data elements
		bubble_sort();
		bubble_sort();
	}

	// on the test machine, the time amount took up to one minute
	// How long did this work on your machine? (:

	return EXIT_SUCCESS;
}