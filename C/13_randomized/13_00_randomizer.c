#include <stdio.h>
#include <stdlib.h>

// for C
#include <time.h>

// for C++
// #include <ctime>

int main(void) {
	time_t t;
	srand(t);
	// srand(<any fixed number>) results to a fixed "random" number over and
	// and over again => since "t" is uninitialized a compiler warning may appear,
	// but this allows you to receive random numbers on each application run

	// you can also use a combined function like:
	// srand(time(&t));
	// srand(time(NULL));
	// to create a random seed

	// since a random seed has been created, rand() can now be used
	// basicly a random number between 0 and RAND_MAX
	for(int i = 0; i < 10; i++) {
		printf("random number: %d\n", rand());
	}

	// a random number within a range
	// rand() % <number> returns a range between 0..n-1 (for <number>)
	// if you want a range between 1..n, just add +1
	for(int i = 0; i < 10; i++) {
		printf("random number between 10 and 100: %d\n", rand() % (100-10) + 1);
	}

	return EXIT_SUCCESS;
}