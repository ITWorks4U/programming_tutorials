/*
* A struct, an union and also an enumeration can have different ways to declare.
* Some of them are prefered in use and some of them hardly.
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
#include <iostream>
#endif

#include "19_adv_structs.h"
#include "19_adv_union.h"
#include "19_adv_enum.h"

// -------------
// only in use for additional functions,
// which are linked to a structure
// -------------
int add_numbers(int a, int b) {
	return a + b;
}

int subtract_numbers(int a, int b) {
	return a - b;
}

int main(void) {
	// -------------
	// structs
	// -------------
	puts(".:structs:.");

	// -------------
	// usual way to use a struct (Coordinates_0)
	struct Coordinates_0 p0;
	p0.x = 10;
	p0.y = 20;
	printf("(%d, %d)\n", p0.x, p0.y);
	// -------------

	// -------------
	// uncommon, but also a way to use an instance
	// name for the struct Coordinates_1
	point_0.x = 5;
	point_0.y = 19;
	printf("(%d, %d)\n", point_0.x, point_0.y);
	// -------------

	// -------------
	// accessing to the members of an anonymous struct
	// won't work => those are possible in enumerations only
	// -------------
	// x = 100;
	// y = 200;
	// -------------

	// -------------
	// accessing to an anonymous struct, where this has an
	// object instance 
	point_1.x = 100;
	point_1.y = 200;
	printf("(%d, %d)\n", point_1.x, point_1.y);
	// -------------

	// -------------
	// using a modern way #1
	// -------------
	Coordinates_2 c;
	c.x = 111;
	c.y = 555;
	printf("(%d, %d)\n", c.x, c.y);
	// -------------

	// -------------
	// using a modern way #2 (it may fail, if not suppored)
	//
	Coordinates_2 c2 = {
		777, 333
	};
	printf("(%d, %d)\n", c2.x, c2.y);
	// -------------

	// -------------
	// using a modern way #3 (direct access to the member for a better workflow)
	// -------------
	Coordinates_2 _c3 = {
		.x = 111,
		.y = 222
	};
	printf("(%d, %d)\n", _c3.x, _c3.y);
	// -------------

	// -------------
	// using functions, which shall be refered to a certain
	// structure instead
	// -------------
	Calculation calc;
	calc.add = add_numbers;
	calc.substact = subtract_numbers;

	printf("%d + %d = %d\n", c.x, c.y, calc.add(c.x, c.y));
	printf("%d - %d = %d\n", c2.x, c2.y, calc.substact(c2.x, c2.y));

	Calculation calc2 = {
		add_numbers, subtract_numbers
	};
	printf("%d + %d = %d\n", c.x, c.y, calc2.add(c.x, c.y));
	printf("%d - %d = %d\n", c2.x, c2.y, calc2.substact(c2.x, c2.y));
	// -------------

	// -------------

	// -------------
	// unions
	// -------------
	puts("\n.:unions:.");
	union Coordinates_3 c3;
	c3.x = 10;
	c3.y = 20;
	printf("(%d, %d)\n", c3.x, c3.y);

	point_2.x = 123;
	point_2.y = 999;
	printf("(%d, %d)\n", point_2.x, point_2.y);

	point_3.x = 753;
	point_3.y = 987;
	printf("(%d, %d)\n", point_3.x, point_3.y);

	Coordinates_5 c4;
	c4.x = 1000;
	c4.y = -10;
	printf("(%d, %d)\n", c4.x, c4.y);

	// In C you may read a warning on compile time like:
	// "excess elements in union initializer", however, C++
	// refuses to build your application here
	// => "too many initializer values"
	#ifndef __cplusplus
	Coordinates_5 c5 = {
		-1, -2
	};
	printf("(%d, %d)\n", c5.x, c5.y);
	#endif

	// -------------
	// enumerations
	// -------------
	puts("\n.:enumerations:.");

	enum Status s0 = A;
	printf("status or s0: %d\n", s0);

	those_status = F;
	printf("those_status (#0): %d\n", those_status);

	// you can also access to any other enumeration,
	// which shall not be intented
	// => works only for C
	#ifndef __cplusplus
	those_status = B;
	printf("those_status (#1): %d\n", those_status);
	#endif

	// accessing to the anonymous enum values
	printf("G = %d, H = %d, I = %d\n", G, H, I);

	// but you can't overwrite their values => "constant expressions"
	// G = 100;

	CustomStatus cs_0 = L;
	printf("cs = %d\n", cs_0);

	// Won't work for C++
	#ifndef __cplusplus
	CustomStatus cs_1 = {
		100
	};
	printf("cs = %d\n", cs_1);
	#endif

	// C++ only
	#ifdef __cplusplus
	std::cout << std::endl << ".:bonus for C++ only:." << std::endl;
	StatusA status = StatusA::READY;

	// can't be used directly
	// => "How may lines of error do you want to read on console?" C++: "Yes."
	// std::cout << "status has value of: " << status << std::endl;
	// std::cout << "StatusA::READY = " << StatusA::READY << std::endl;

	// you can just compare the status with the set of states
	switch(status) {
		case StatusA::READY:
			std::cout << "This status is ready to use." << std::endl;
			break;
		case StatusA::WORK:
			std::cout << "The status is buisy for now." << std::endl;
			break;
		case StatusA::STOPPED:
			std::cout << "The status is not running." << std::endl;
			break;
	}

	std::initializer_list<Status> all_states = {A, B, C};
	for(Status s1 : all_states) {
		std::cout << s1 << std::endl;
	}
	#endif

	return EXIT_SUCCESS;
}