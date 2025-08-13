/*
*
* Unions (union) are rarely used to capsulate
* multiple expressions to one object. In contrast to a struct
* the member with the highest amount of space declares the size
* of this union. => every member shares the space with all members
*
* Why or where are unions used?
* - memory optimization (more in use for embedded systems)
* - interpreting data in multuiple ways, which is also a disadvantage as well
* - hardware registers
* - ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH	20

//	union may also contain nothing
//	NOTE: On Windows or any IDE it may happen, that
//	an error is shown up, that a declaration is expected
//	=> this application can be build anyway
union EmptyUnion {};

union MyUnion {
	char sign;
	int index;
	long identification;
	float percent;
	int another_index;
	char word[BUFFER_LENGTH];
	//...
};

int main(void) {
	union EmptyUnion eu;

	//	in C: 0 bytes, in C++: 1 byte!
	size_t size_of_union = sizeof(eu);
	printf("amount of bytes for \"eu\": ");

	//	NOTE: On Windows sizeof is often declared as an unsigned int
	//	instead of an unsigned long, so a warning (with -Wall flag)
	//	appears on compile time; unless we're using the preprocessor
	//	condition checks
	#if _WIN32
	printf("%u byte(s)\n", size_of_union);
	#else
	printf("%lu byte(s)\n", size_of_union);
	#endif

	//	accessing to members
	union MyUnion mu;
	mu.sign = 'A';
	mu.index = 100;
	mu.identification = 123;
	mu.percent = 0.76;
	mu.another_index = 700;
	memset(mu.word, '\0', BUFFER_LENGTH);

	printf("amount of bytes for \"mu\": ");
	size_of_union = sizeof(mu);

	#if _WIN32
	printf("%u byte(s)\n", size_of_union);
	#else
	printf("%lu byte(s)\n", size_of_union);
	#endif

	//	WYSIWYG? => No! The last assigned member in your union dominates
	//	the values of the other members. In that case mu.word was assigned last,
	//	thus every member has a value of 0 (numeric) or '\0' for char or "\0\0\0..." for other C-string(s).
	printf(
		"%c, %d, %ld, %f, %d, %s\n",
		mu.sign, mu.index, mu.identification, mu.percent, mu.another_index, mu.word
	);

	//	let's modify that value:
	strcpy(mu.word, "Hello from union!");

	//	Warning: this may cause an undefined behavior on runtime
	printf(
		"%c, %d, %ld, %f, %d, %s\n",
		mu.sign, mu.index, mu.identification, mu.percent, mu.another_index, mu.word
	);

	//	or modify an another value instead:
	mu.percent = 0.23e2;

	printf(
		"%c, %d, %ld, %f, %d, %s\n",
		mu.sign, mu.index, mu.identification, mu.percent, mu.another_index, mu.word
	);

	return EXIT_SUCCESS;
}