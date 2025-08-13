/*
* In C the keyword 'register' sugggests to the
* compiler that the current variable should be
* stored into a CPU register, rather than into
* the memory.
*
* Each variable, which is successfully stored
* on a CPU register can be much faster accessed
* than on the memory, however, it depends on
* the compiler, if this variable CAN be stored
* on a CPU register or not, moreover, this
* variable can't be requested by using an
* address operator format. It will cause an error
* on compile time.
*
* On modern compilers the register keyword became obsolete.
* When does it makes sense to use register keyword?
* - a particular variable will be heavily used on runtime,
*   which may slow down the performance, when the variable
*   is stored to the RAM instead of to a CPU register
* - when you're working on an embedded system (any micro controller)
*   or a (very) old system
*
* Finally, the register is a storage class specifier.
* We can't use more than one storage class
* for a register variable, like:
* - register static int number;
* - register auto int number;
* - register extern int number;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_time(double seconds) {
	double hours = floor(seconds / 3600);
	double minutes = floor(fmod(seconds, 3600) / 60);
	double secs = floor(fmod(seconds, 60));

	// fractional part of the second
	double fractional = seconds - floor(seconds);
	double milliseconds = floor(fractional * 1000);
	double microseconds = floor(fmod(fractional * 1e6, 1000));
	double nanoseconds  = floor(fmod(fractional * 1e9, 1000));

	//	it may happen, that the µ symbol can't be displayed correctly
	printf(
		"duration: %.0lf h, %.0lf min, %.0lf s, %.0lf ms, %.0lf (micro)s, %.0lf ns\n",
		hours, minutes, secs, milliseconds, microseconds, nanoseconds
	);
}

int main(void) {
	//	without using register
	long summary = 0;
	clock_t start = clock();

	for(int i = 0; i < 100000000; i++) {
		summary += i;
	}

	clock_t end = clock();
	print_time(((double)(end - start) / CLOCKS_PER_SEC));

	//	with register
	summary = 0;
	start = clock();

	for(register int i = 0; i < 100000000; i++) {
		summary += i;
	}

	end = clock();
	print_time(((double)(end - start) / CLOCKS_PER_SEC));

	int a = 100;
	printf("a = %d, location: %p\n", a, &a);

	register int b = 42;
	//	causes an error on compile time
	//printf("b = %d, location: %p\n", b, &b);

	return EXIT_SUCCESS;
}