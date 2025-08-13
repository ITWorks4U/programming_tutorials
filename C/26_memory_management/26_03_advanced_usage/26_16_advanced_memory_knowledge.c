/*
* Usually, by using pointers it allows you to handle
* with dynamically allocated structures, however,
* you can do much more, also much more wrongly memory management.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* This function is using the addresses of two
* arguments of type int. => Call by reference.
* You can refer to the addresses of a and b, however,
* you can't do this vice versa!
*/
int function1(const int *a, const int *b) {
	printf("*****************\n");
	printf("a = %d, b = %d <=> %pH, %pH\n", a, b, &a, &b);
	printf("*****************\n");

	return 1;
}

bool function2(int a, int b) {
	printf("-----------------\n");
	printf("a = %d, b = %d <=> %pH, %pH\n", a, b, &a, &b);
	printf("-----------------\n");

	return false;
}

void function3(int a, int b) {
	printf("#################\n");
	printf("a = %d, b = %d <=> %pH, %pH\n", a, b, &a, &b);
	printf("#################\n");
}

int main(void) {
	int a = 10, b = 20;

	/*
	* By using sizeof for a function you won't call the function
	* directly, you're "just" requesting the size of the function
	* including where this function is going to store on runtime.
	*/
	//	4 bytes (int)
	#ifndef __cplusplus
	//	C++ refuses to build this source code
	size_t size_of_function1 = sizeof(function1(a, b));
	#endif

	//	C: 4 bytes, because bool is an integer; C++: 1 byte
	size_t size_of_function2 = sizeof(function2(a, b));

	//	1 byte (void)
	//	in C this works, but C++ refuses to build your application
	#ifndef __cplusplus
	size_t size_of_function3 = sizeof(function3(a, b));
	#endif

	char fixed_word[] = "This is a simple text!";
	//	with %p we're requesting, >>where<< a variable, function, pointer, ... is located on runtime
	//	to get the address, write an apersand (&) in front of your object

	//	NOTE: Windows uses %u, whereas %lu is in use elsewhere
	#ifndef __cplusplus
	printf("size of function1 = %lu bytes, located on: %pH\n", size_of_function1, &function1);
	#endif

	printf("size of function2 = %lu bytes, located on: %pH\n", size_of_function2, &function2);

	#ifndef __cplusplus
	printf("size of function3 = %lu bytes, located on: %pH\n", size_of_function3, &function3);
	#endif

	/*	for a c-string (also any other pointer) it's not required to use &	*/
	printf("%s <=> memory: %pH\n", fixed_word, fixed_word);
	printf("%s <=> memory: %pH\n", fixed_word, &fixed_word);

	/*	try to figure out, what happens here:	*/
	// printf("a = %d, b = %d <=> %pH, %pH\n", a, b, a, b);
	printf("a = %d, b = %d <=> %pH, %pH\n", a, b, &a, &b);

	function1(&a, &b);																						//	call by reference
	printf("location of function1: %pH\n", &function1);
	function2(a, b);																						//	call by value
	function3(a, b);																						//	same here

	return EXIT_SUCCESS;
}