#ifndef MATH_OPERATIONS_H
#define	MATH_OPERATIONS_H

/*
* Sometimes it's required to build an application, which
* shall be run in C and C++, however, working with C and C++
* might sometimes not be easy.
*
* Even the code has the typical C-style, your application
* might be able build in C, but not in C++ or in the other direction.
*
* The main reason here is the certain source file: >>math_operations.cpp<<
* Since a C++ - file is in use the compiler (for C++ or C)
* will handle this file in a different way rather than the
* expected output.
*
* If you want to see a clean history about the reason,
* just run the makefile with the certain target(s):
* assembly_c / assembly_cpp.
*
* To fix and handle that issue correctly, you must force
* the compiler to handle the functions (only) as pure C-functions (only).
*
* Other types, like structs, enum (NOT enum-class), union, macros might not be affected.
*
* write:
* #ifdef __cplusplus
* extern "C" {
* #endif
* >>function(s) to use as like pure C functions<<
* #ifdef __cplusplus
* }
* #endif
*
* However, this might look like awful.
*
* There's a smarter way to handle this.
* In your C++ - source file(s) write:
*
* extern "C" {
* #include <your-header.h>
* }
*
* Attention:
* Your header file MUST NOT contain any types, which
* existis in C++, but not in C, e. g.: class, template, namespace, ...
*/

#define	BUFFER	100
#define	STR_CONTENT	"Howdy!"

#ifdef _WIN32
	#ifdef MATH_OPERATIONS_EXPORTS
		#define MATH_OPERATIONS_API __declspec(dllexport)
	#else
		#define MATH_OPERATIONS_API __declspec(dllimport)
	#endif
#else
	#define MATH_OPERATIONS_API
#endif

/*	A typical way to handle with both languages, right?	*/
int addition(int a, int b);
int subtraction(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

struct Data {
	char content[BUFFER];
	struct Data *next;
};

#endif