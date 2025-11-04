/*
* Using mathematical functions, like sine(), cosine(), sinh(), ...
*
* for Linux and possibly macOS: The linker needs -lm as additional compiler command,
* otherwise the functions can't be used correctly. This is not required
* everywhere, but you're happier, if you have linked the math libary
* on compile time. ;-)
*/

#ifndef _WIN32
#warning "Make sure to link -lm to the compiler, otherwise your application can't be build."
#endif

#include <stdio.h>
#include <stdlib.h>

// for C only
#include <math.h>

// if you prefer to use C++, use this library instead
// #include <cmath>

#include <float.h>

/*
* Usually, M_PI is not known on a Windows machine, so the application
* is unable to build. Unless, we define M_PI for our own purpose.
*/
#ifndef M_PI
#define M_PI  3.1415926535897932384626433
#endif

/* own written functions to calculate something */
void calculate_area_circle(int radius) {
	printf("area: %e\n", M_PI * radius * radius);
}

void calculate_volume_circle(int radius) {
	printf("volume: %e\n", 4/3 * M_PI * radius * radius * radius);
}

int main(void) {
	for(int i = 0; i < 50; i++) {
		calculate_area_circle(i);
		calculate_volume_circle(i);
	}

	puts("============");

	// using some math functions from [c]math.h:
	for(double i = 0.0; i <= 90.0; i += 0.1) {
		printf("sin(%lf) = %lf\n", i, sin(i));
		printf("cos(%lf) = %lf\n", i, cos(i));
		printf("tan(%lf) = %lf\n", i, tan(i));
		puts("------------");
	}

	puts("============");

	for (int i = 0; i < 10; i++) {
		// casting is recommended, because most of those functions
		// are handling floating point numbers
		printf("power of %d = %e\n", i, pow((double)i, (double)i));
		printf("square root of %d = %e\n", i, sqrt((double) i));
	}

	// many other functions here...
	double d_infinite = DBL_MAX;
	printf("Is %lf infinite? %s\n", d_infinite, isfinite(d_infinite) ? "yes" : "no");

	return EXIT_SUCCESS;
}