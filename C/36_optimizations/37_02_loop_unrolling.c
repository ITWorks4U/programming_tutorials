/*
* Reducing the amount of loop states,
* by using multiple statements at once.
*/

#ifdef __cplusplus
#error "Don't use C++. This may result to an undefined behavior or your application might be interpreted as a threat."
#else

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 1,000,000,000 times
#define UPPER_LIMIT 1000000000

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

int main(void) {
	clock_t begin = clock();
	for(int i = 0; i < UPPER_LIMIT; i++) {}
	clock_t end = clock();
	time_amount(((double)(end - begin) / CLOCKS_PER_SEC));

	puts("-----");
	begin = clock();
	for(int i = 0; i < UPPER_LIMIT; i += 5) {}
	end = clock();
	time_amount(((double)(end - begin) / CLOCKS_PER_SEC));

	return EXIT_SUCCESS;
}

#endif