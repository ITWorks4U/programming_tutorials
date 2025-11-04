/*
* Since we know, that a C function can use any amount of arguments with any kind
* of data types, we could do anything, right? Not really, no.
*
* A function shall handle a single type of arguments only, unless you really
* know what you do.
*/

#ifdef __cplusplus
#error "Don't use a C++ compiler to build this application. Use a C compiler instead."
#else
#include <stdio.h>
#include <stdlib.h>

// required for "function overloading"
#include <stdarg.h>

// allows to "overload" a function to do different operations similar to a
// function / method overload in OOP languages
//
// attention: you are also creating your own pitfall with a function like this,
// when you're using differnt argument types instead of the expected data type
//
// this function below shall handle integer arguments only to let calculate
// the mean value of n integers
double calculate_mean_value(int nbr_of_elements, ...) {
	double mean_value = 0.0;

	// to handle the amount of additional arguments, use:
	va_list vector;

	// initialize the vector with the given number of elements
	va_start(vector, nbr_of_elements);

	printf("( ");
	for(int i = 0; i < nbr_of_elements; i++) {
		// va_arg picks the next element from the vector and this shall be
		// interpreted as an integer
		int element = va_arg(vector, int);

		printf("%d ", element);
		mean_value += element;

		/*
		* Don't make a mistake, like:
		* printf("%d ", va_arg(vector, int));
		* mean_value += va_arg(vector, int);
		*
		* Because va_arg is triggered twice, which means in
		* printf() the argument n is picked, as expected, however,
		* mean_value gets argument n + 1 from va_arg
		*
		* => undefined behavior, when the next argument k after n-1
		* is picked; you MAY get any value of type int, but this
		* also may end in a desaster
		*/
	}
	printf(") => ");

	// remove the vector from memory
	va_end(vector);

	return mean_value / nbr_of_elements;
}

int main(void) {
	// to call those function(s), you must know how many arguments are you expecting
	// to append additionally, otherwise an undefinded behavior may appear
	// 9 := number of arguments
	// 1,2,...,9 := the arguments to use
	printf("average value #1: %lf\n", calculate_mean_value(9, 1,2,3,4,5,6,7,8,9));
	printf("average value #2: %lf\n", calculate_mean_value(3, 123,456,789));

	// What will happen here?
	printf("average value #3: %lf\n", calculate_mean_value(9, 123,456,789));
	printf("average value #4: %lf\n", calculate_mean_value(5, 1,2,3,4,5,6,7,8,9));

	// this, however, works, because a char can easily be interpreted as the integer value from ASCII table
	printf("average value #5: %lf\n", calculate_mean_value(9, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'));

	// Guess what happens, when you try to use other arguments?
	// Perhaps your application works, perhaps your application crashes...?
	printf("average value #6: %lf\n", calculate_mean_value(1, "A simple C-string."));
	printf("average value #7: %lf\n", calculate_mean_value(100));
	printf("average value #8: %lf\n", calculate_mean_value(5, "", "", "", "", ""));
	printf("average value #9: %lf\n", calculate_mean_value(0xA, 0x5555, 0100, 0B1001001));

	return EXIT_SUCCESS;
}
#endif