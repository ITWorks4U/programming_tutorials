#ifdef __cplusplus
#error "By using a C++ compiler this application may be handled like a threat or it leads to an undefined behavior. Use a C compiler instead."
#else

/*
* Simple time measurement for C programming.
* In C++ there're another ways to handle time measurments.
*
* How does this work? The libary time.h comes with a clock()
* function, which is used to measure processor time consumed by the program.
*
* This can be used for benchmark, time consuming, ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>

void print_time(double seconds) {
	printf(
		"duration: %.lf h, %.lf min, %.lf s\n",
		floor(seconds / 3600), floor(seconds / 60), fmod(seconds, 60)
	);
}

int main(void) {
	char c_string[101];
	memset(c_string, '\0', 101);
	char word_to_copy[] = "This is a simple lext to copy.";
	unsigned int counter = 0;

	clock_t start_timer = clock();
	puts("starting time measurement...");

	// a simple, stupid and "Holy sh*t! Why do you do such bullsh*t?" instruction
	// to emulate a long time amount
	while(counter != UINT_MAX) {
		counter++;
		strncpy(c_string, word_to_copy, strlen(word_to_copy));
	}

	puts("Finished!");
	clock_t end_timer = clock();

	// end-start must be devided by CLOCLS_PER_SEC (number of clock ticks per second)
	// to receive the current elapsed time in seconds
	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}
#endif