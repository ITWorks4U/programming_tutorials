// usually, it's not required to name the source file identical to the
// header file, but this is often given to determine, where the implementations
// exists

#include <stdio.h>
#include <stdlib.h>

// unlike to the header files above, this header file is marked
// as a "string", because this header file is not in the defined ($)PATH,
// where the compiler tries to find those required libaries instead
#include "18_math_functions.h"

// this file contains the function implementations from the header file
int add(int a, int b) {
	return a + b;
}

int subtract(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	// What happens for b = 0? >:-)
	return a / b;
}

int modulo(int a, int b) {
	return a % b;
}