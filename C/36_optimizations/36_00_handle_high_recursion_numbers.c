/*
* Sometimes even C might not be able to handle large numbers
* for a recursion, like the fibonacci series.
*
* Example:
* calculating the fibonacci series with up to 40 this
* takes some seconds or at least some minutes, depending on the
* machine, you're working on. However, the larger the number,
* the more time amount will be consumed.
*
* In contrast to that calculated
* results the sun will be able to die earlier.
*
* Unless, we're using a buffered way to check, if a certain number
* already exists to skip that calculation (again).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#error "Do not use C++. This may result to an error on runtime or the application might be interpreted as a threat."
#else

#define MAX_ELEMENTS    100
#define ULL             unsigned long long

static ULL storage_buffer[MAX_ELEMENTS];

void init_storage_buffer(void) {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		storage_buffer[i] = 0;
	}
}

ULL fibonacci_series(int nbr) {
	if (nbr <= 1) {
		return (ULL) nbr;
	}

	if (storage_buffer[nbr] != 0) {
		return storage_buffer[nbr];
	}

	storage_buffer[nbr] = fibonacci_series(nbr - 1) + fibonacci_series(nbr - 2);
	return storage_buffer[nbr];
}

int main(void) {
	init_storage_buffer();

	for(int i = 0; i < 100; i++) {
		if (i <= 93) {
			fibonacci_series(i);
		}

		// every higher number results to a value overflow
	}

	for(int i = 0; i < MAX_ELEMENTS; i++) {
		printf("fib(%d): %llu\n", i, storage_buffer[i]);
	}

	return EXIT_SUCCESS;
}

#endif