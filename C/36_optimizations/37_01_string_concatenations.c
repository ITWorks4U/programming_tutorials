/*
* Concatenating C strings can be done with strcat, but this
* takes too much time. It might be better to to use memcpy,
* because this uses pointer arithmetic.
*
* in summary:
* - strcat: O(n²)
* - memcpy: O(n)
*/

#ifdef __cplusplus
#error "Don't use C++. This may result to an undefined behavior or your application might be interpreted as a threat."
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define BUFFER_LENGTH     10000001
#define WORD_TO_USE       "HELLO"
#define UPPER_LIMIT       2000000
// "HELLO" shall be stored into a C-string 2,000,000 times.

static char buffer[BUFFER_LENGTH];

void time_amount(double seconds) {
	double hours = floor(seconds / 3600);
	double minutes = floor(fmod(seconds, 3600) / 60);
	double secs = floor(fmod(seconds, 60));

	double fractional = seconds - floor(seconds);
	double milliseconds = floor(fractional * 1000);
	double microseconds = floor(fmod(fractional * 1e6, 1000));
	double nanoseconds  = floor(fmod(fractional * 1e9, 1000));

	fprintf(
		stdout,
		"time amount: %.0lf h, %.0lf min, %.0lf s, %.0lf ms, %.0lf (micro)s, %.0lf ns\n",
		hours, minutes, secs, milliseconds, microseconds, nanoseconds
	);
}

void clear_buffer(void) {
	memset(buffer, '\0', BUFFER_LENGTH);
}

void use_strcat(void) {
	clear_buffer();

	for(int i = 0; i < UPPER_LIMIT; i++) {
		strcat(buffer, WORD_TO_USE);
	}
}

void use_memcpy(void) {
	clear_buffer();

	char *ptr = buffer;
	for(int i = 0; i < UPPER_LIMIT; i++) {
		memcpy(ptr, WORD_TO_USE, strlen(WORD_TO_USE));
		ptr += strlen(WORD_TO_USE);
	}

	*ptr = '\0';
}

int main(void) {
	/*
	* Depending on the machine, you're working on,
	* the consumed time may differ. On a test PC (
	* - Intel Core i7 12-th Gen; 2.1 GHz
	*)
	* the time amouts were:
	*
	* use_strcat: 13 min, 35s, 735ms
	* use_memcpy: 15ms
	*/

	clock_t begin = clock();
	use_strcat();
	clock_t end = clock();
	time_amount(((double)(end - begin) / CLOCKS_PER_SEC));

	puts("----------------");

	begin = clock();
	use_memcpy();
	end = clock();
	time_amount(((double)(end - begin) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}

#endif