/*
* Arrays are a fixed list of values, depending on its data type. Don't think, that an array and
* a pointer are the same! They don't, even they have a set of shared functionalities.
*
* If you want to know how to use pointers, then take a look to chapter 26.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funny_function(int array[], size_t elements) {
	for(size_t i = 0; i < elements; i++) {
		printf("element: %d\n", array[i]);
	}	
}

int main(void) {
	// -----------
	// integer array
	// -----------

	// 9 elements
	int array[] = {1, 2, 3, -100. -687, 753, 42, 1337, 9001};

	// unable to print array elements
	// printf("array has %ls elements\n", array);

	// 9 elements? No! There're 36 "elements".
	// printf("array has %lu elements\n", sizeof(array));

	// this is the correct way to receive the number of elements in an array:
	// 9 elements :o)
	size_t number_of_elements = sizeof(array) / sizeof(array[0]);

	// by the way: On Windows %lu might be an unsigned int, so it may happen,
	// that you're getting a warning on compile time
	printf("array has %lu elements\n", number_of_elements);

	for(size_t i = 0; i < number_of_elements; i++) {
		printf("array element: %d\n", array[i]);
	}

	// -----------
	// C-strings (are more an array of characters)
	// -----------
	char word[] = "Howdy! How're you?";

	// Surprised of sizeof and strlen?
	printf("word has %lu elements\n", sizeof(word));
	printf("word has %lu elements\n", strlen(word));
	printf("word has %lu elements\n", sizeof(word) / sizeof(word[0]));

	for(size_t i = 0; i < sizeof(word) / sizeof(word[0]); i++) {
		printf("word element: %c\n", word[i]);
	}

	// -----------
	// outsourcing to function
	// for a static array this works fine, however, if you're
	// using a pointer instead, you'll get a (some) nasty surprise(s)
	// -----------
	funny_function(array, sizeof(array) / sizeof(array[0]));

	return EXIT_SUCCESS;
}