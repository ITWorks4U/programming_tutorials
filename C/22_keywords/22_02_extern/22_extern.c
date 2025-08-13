#include "22_extern.h"

/*
* since data and also test_1 have been defined with
* extern in the header file, this can be declared
* with any value
*/

//	since data now contains 100, this can be used elsewhere
int data = 100;

//	let's declare test_1 with...
struct test_1 {
	float f0;
	char sign;
};