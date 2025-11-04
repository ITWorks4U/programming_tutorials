/*
* Header files are similar to interfaces, where those are not interfaces for OOP.
* These offers data types, definitions, functions, etc.
*/

// mostly used on Windows: #pragma once
// => short form of #ifndef .... #define .... #endif

// basic usage, where the expression must contain the name
// of the header file itself

// those command is also known as multiple include protection,
// so if that macro is not already known, this will be defined here;
// if this header file, for example, has been included anywhere in your
// project, then it's no need to define that block of code instructions
// over and over again
#ifndef	MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H
	// a header file may contain:
	// - (any) included libraries
	// - (any) macro definitions (see chapter 17)
	// - (any) structures (see chapter 19)
	// - (any) function prototypes
	// - (any) external handling variables (see chapter 22)

	int add(int a, int b);
	int subtract(int a, int b);
	int multiply(int a, int b);
	int divide(int a, int b);
	int modulo(int a, int b);

#endif