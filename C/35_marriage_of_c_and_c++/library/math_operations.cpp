/*
* a possible way for C++ to declare that functions
* below as pure C functions
*
* if you want to take a look "behind the scenes" of that file,
* run the build script with the target "build_assembly", whereas
* the extern "C" block is not given here
*/
extern "C" {
	#include "math_operations.h"
}

int addition(int a, int b) {
	return a + b;
}

int subtraction(int a, int b) {
	return a - b;
}

int multiply(int a, int b) {
	return a * b;
}

int divide(int a, int b) {
	return a / b;
}