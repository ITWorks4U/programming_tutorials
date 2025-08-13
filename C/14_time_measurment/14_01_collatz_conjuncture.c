#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//	static tells the compiler, that this step_ctr is available
//	only in this file
static int step_ctr = 0;

void print_time(double seconds) {
	printf(
		"duration: %.lf h, %.lf min, %.lf s\n",
		floor(seconds / 3600), floor(seconds / 60), fmod(seconds, 60)
	);
}

int collatz_conjecture(int number) {
	printf("current number: %d\n", number);
	step_ctr++;

	if (number == 1) {
		//	return 1 for 1 only
		return 1;
	}

	if (number % 2 == 0) {
		//	number is even
		return collatz_conjecture(number / 2);
	}
	
	//	number is odd (except for 1)
	return collatz_conjecture(3 * number + 1);
}

int main(void) {
	const int upper_boundary = 123456789;
	clock_t start_timer = clock();
	puts("starting time measurement...");

	collatz_conjecture(upper_boundary);
	printf("For %d it tooks %d steps.\n", upper_boundary, step_ctr);
	puts("Finished!");
	clock_t end_timer = clock();
	print_time(((double)(end_timer - start_timer) / CLOCKS_PER_SEC));
	return EXIT_SUCCESS;
}