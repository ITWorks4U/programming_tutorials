/*
* Still believe, that arrays and pointes are the same? Well, in this sample you'll start to think again.
*
* An array has a fixed size of elements. This can be initialized with values at the beginning or on runtime,
* whereas the limitation shall not be exceeding. Pointers, often called fields, may have the similar behavior,
* but with fields you can do much more. And then, the difference may be huge.
*/

#include <stdio.h>
#include <stdlib.h>

// on compile time (with -Wall) you may get a warning like:
// warning: 'sizeof' on array function parameter 'array' will return size of 'int *' [-Wsizeof-array-argument]

void handle_array(int array[]) {
	// determine the size of an array
	size_t nbr_of_elements = sizeof(array) / sizeof(array[0]);
	printf("This array has ");

	#ifdef _WIN32
	printf("%u ", nbr_of_elements);
	#else
	printf("%lu ", nbr_of_elements);
	#endif

	puts("elements.");
}

void handle_field(int *array) {
	// determine the size of a field
	size_t nbr_of_elements = sizeof(array) / sizeof(array[0]);
	printf("This field has ");

	#ifdef _WIN32
	printf("%u ", nbr_of_elements);
	#else
	printf("%lu ", nbr_of_elements);
	#endif

	puts("elements.");
}

int main(void) {
	// just a normal array, like always
	int array_0[] = {1,2,3,4,5};

	// Often misinterpreted: this "array" is neither a real
	// array nor the initialization is valid.
	// A field can't have more than one value for initialization value.
	// int *array_1 = {1,2,3,4,5};

	// this is the correct definition of a field, even when "array" as name is given
	int *array_1 = (int *) calloc(5, sizeof(int));
	for(int i = 0; i < 5; i++) {
		array_1[i] = i+1;
	}

	// --------------------
	// determine the number of elements for this array and field:
	size_t nbr_of_elements_array = sizeof(array_0) / sizeof(array_0[0]);
	size_t nbr_of_elements_field = sizeof(array_1) / sizeof(array_1[0]);

	printf("number of elements between array and field: ");

	#ifdef _WIN32
	printf("%u <=> %u\n", nbr_of_elements_array, nbr_of_elements_field);
	#else
	printf("%lu <=> %lu\n", nbr_of_elements_array, nbr_of_elements_field);
	#endif

	/*
	* Since the number of elements were easy to determine, why does this
	* not work for a field, which might be the same as an array?
	* sizeof(X) / sizeof(X[0]) can calculate the number of elements, because
	* the size of an integer is well known. No matter on which machine you're working on.
	*
	* If you're using a field, then you'll get in trouble, because a pointer hasn't a
	* known amount of elements. This pointer "just" points to an address, where this field
	* has been placed on any free space in your RAM and this pointer uses the desired amount
	* of size depending on the architecture, you are working on.
	*/

	// --------------------
	puts("--------------------");
	puts("using the functions instead...");
	puts("--------------------");

	// Surprised? In a function even an array and also a field may have
	// only "one" element, because the number of elements can't be
	// figured out there. In a function, it doesn't matter, if you're
	// using an array or a field, in both ways a pointer is in use for this
	// argument and this pointer can only point to the first value of the
	// address, where this array / field has been placed.
	//
	// so, that's the reason, why functions also have a second integer argument
	// to use the "correct" number of elements
	handle_array(array_0);
	handle_array(array_1);
	handle_field(array_0);
	handle_field(array_1);

	free(array_1);

	// --------------------
	// have a bit more fun with fields
	// --------------------
	int *field0 = NULL;
	float **field1 = NULL;
	char *************************field2 = NULL;
	
	// By the way, who's saying, that a field shall always be int*, char*...?
	void ****field3 = NULL;

	// try to figure out the number of elements
	size_t len_field0 = sizeof(field0) / sizeof(field0[0]);
	size_t len_field1 = sizeof(field1) / sizeof(field1[0]);
	size_t len_field2 = sizeof(field2) / sizeof(field2[0]);

	// NOTE: for UNIX/Linux/macOS you should use %lu instead
	// with sizeof(x) the size of the field,
	// depending on the data type can be determined and which
	// architecture you're working on

	printf("[size of bytes] | [number of elements]\n");
	printf("[     %u       ] | [        %u         ]\n", sizeof(field0), len_field0);
	printf("[     %u       ] | [        %u         ]\n", sizeof(field1), len_field1);
	printf("[     %u       ] | [        %u         ]\n", sizeof(field2), len_field2);
	printf("[     %u       ] | [        ?         ]\n", sizeof(field3));

	// a void-pointer can't be used for sizeof(field_x[0])
	// size_t len_field3 = sizeof(field3) / sizeof(field3[0]);

	return EXIT_SUCCESS;
}