/*
* Even functions are not an exception for a wrong usage.
*
* There't a slightly difference between function_0 and function_1:
* Call by value and call by reference.
*
* call by value:
* you just want to transfer the content of a variable, ...
*
* call by reference:
* you want to use the >>address<< of any object / variable / field
*/

#ifndef __cplusplus
	#include <stdio.h>
	#include <stdlib.h>
#else
	#define CPP_IN_USE
	#include <iostream>
	using namespace std;
#endif

#define BUFFER_LENGTH   100

void function_0(int data) {
	#ifndef CPP_IN_USE
	// only for C
	printf("(function_0) ");

	printf("data = %d\n", data);
	#else
	// only for C++
	cout << "(function_0) ";
	cout << "data = " << data << endl;
	#endif
}

void function_1(int *data) {
	#ifndef CPP_IN_USE
	printf("(function_1) ");
	#else
	cout << "(function_1) ";
	#endif

	// assuming, that the field data of type int*
	// may have 10 elements
	const int nbr_of_elements = 10;

	for(int i = 0; i < nbr_of_elements; i++) {
		#ifndef CPP_IN_USE
		printf("data[%d] = %d\n", i, data[i]);
		#else
		cout << "data[" << i << "] = " << data[i] << endl;
		#endif
	}
}

int main(void) {
	puts("Warning: This sample causes an undefined behavior during runtime!");

	int number = 100;
	int array[] = {0,1,2,3,4,5,6,7,8,9};
	int *field = NULL;

	#ifndef CPP_IN_USE
		// works only for C
		function_0(number);
		function_0(NULL);

		// Surprised?
		function_0(&array);
		function_0(field);

		field = calloc(10, sizeof(int));
		function_0(field);

		// Still confused and also surprised?
		function_1(number);
		function_1(NULL);
		function_1(array);
		function_1(field);

		free(field);
	#else
		function_0(number);
		function_1(array);

		// may crash your application
		// function_0(NULL);
		// function_1(&number);
		// function_1(NULL);
		// function_1(nullptr);
		// function_1(field);

		field = new int[10];
		function_1(field);
		delete field;

		// won't work => syntax error:
		// function_0(nullptr);
		// function_0(array);
		// function_0(field);
		// function_1(number);
	#endif


	#ifndef CPP_IN_USE
	return EXIT_SUCCESS;
	#else
	return 0;
	#endif
}