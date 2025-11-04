/*
* The __restrict__ (restrict in standard C99) keyword is a powerful tool
* for code optimization. This keyword only exists in C. C++ does not comes
* with that keyword and may refuse to build your application.
*
* With __restrict__ we "promise" to the compiler to keep up a clean code
* and "we know, what we do". If we don't mind, an undefined behavior
* also may appear.
*
* It gives the compiler more information about pointer aliasing to generate
* more faster code. Pointer aliasing happens, when two or more pointers
* refer to the same memory. Usually, this is a critical pitfall, because
* once the memory address has been freed, the other pointers may want to
* store to or receive from that memory, which causes an undefined behavior.
*
* Only useful, if you're working with assembly and you need to figure out,
* where an instruction or instructions can be optimized.
*
* To see the difference, compile your source code(s) with -O3 flag.
* To see the assembly file instead, compile your source code(s) with -S flag.
*
* note:
* Not every time __restrict__ has been used the runtime has been speeded up.
*/

#ifdef __cplusplus
#error "This source code is supposed to build with a C compiler only."
#else

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define FIELD_SIZE	5000
#define FILE_NAME	"result.txt"

// adding array values from b and c to a and also "return" a
// even no return statement is given
void add_arrays_without_restrict(int *arr_a, int *arr_b, int *arr_c, int nbr_of_elements) {
	for(int i = 0; i < nbr_of_elements; i++) {
		arr_a[i] = arr_b[i] + arr_c[i];
	}
}

// don't be confused, when you see errors in the IDE
// these might pop up, when a C++ interpretation is in use here
void add_arrays_with_restrict(
	int *__restrict__ arr_a, int *__restrict__ arr_b,
	int *__restrict__ arr_c, int nbr_of_elements) {

		for(int i = 0; i < nbr_of_elements; i++) {
		arr_a[i] = arr_b[i] + arr_c[i];
	}
}

void analyze_process(bool with_restrict) {
	clock_t start = clock();

	// create fields (fiels might be similar arrays, but they aren't)
	int *arr_a = malloc(sizeof(int) * FIELD_SIZE);
	int *arr_b = malloc(sizeof(int) * FIELD_SIZE);
	int *arr_c = malloc(sizeof(int) * FIELD_SIZE);

	// some dummy data
	for(int i = 0; i < FIELD_SIZE; i++) {
		arr_b[i] = (FIELD_SIZE * i) + FIELD_SIZE * 3;
		arr_c[i] = (FIELD_SIZE * i) - FIELD_SIZE * 2;
	}

	// determine which function is in use here
	if (with_restrict) {
		add_arrays_with_restrict(arr_a, arr_b, arr_c, FIELD_SIZE);
	} else {
		add_arrays_without_restrict(arr_a, arr_b, arr_c, FIELD_SIZE);
	}

	// write results to a file
	FILE *destination = fopen(FILE_NAME, "a");
	if (destination == NULL) {
		perror("fopen()");
		return;
	}

	// not a useful method, but in that case this is "good enough"
	fprintf(destination, "\narr_a = [ ");
	for(int i = 0; i < FIELD_SIZE; i++) {
		fprintf(destination, "%d ", arr_a[i]);
	}
	fprintf(destination, "]\n");
	clock_t end = clock();

	// determine the time amount
	double seconds = ((double)(end - start) / CLOCKS_PER_SEC);

	double hours = floor(seconds / 3600);
	double minutes = floor(fmod(seconds, 3600) / 60);
	double secs = floor(fmod(seconds, 60));

	// fractional part of the second
	double fractional = seconds - floor(seconds);
	double milliseconds = floor(fractional * 1000);
	double microseconds = floor(fmod(fractional * 1e6, 1000));
	double nanoseconds  = floor(fmod(fractional * 1e9, 1000));

	// it may happen, that the µ symbol can't be displayed correctly
	fprintf(
		destination,
		"duration: %.0lf h, %.0lf min, %.0lf s, %.0lf ms, %.0lf (micro)s, %.0lf ns\n",
		hours, minutes, secs, milliseconds, microseconds, nanoseconds
	);

	fclose(destination);

	free(arr_c);
	free(arr_b);
	free(arr_a);
}

int main(void) {
	// without __restrict__
	analyze_process(false);

	// with __restrict__
	analyze_process(true);

	return EXIT_SUCCESS;
}
#endif