/*
* Pointers allows you to do arithmetic operations, however, don't think,
* that this is identical to an unsual arithmetic operations. You've limited
* operations and their results are also different.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 0;
	int *b = &a;

	//	since *b has not been created with malloc(), calloc(), new, ...
	//	the pointer reference is going to remove automatically
	//	from the stack, when the application ends (in any way)
	//	=> there's no need to use free(), delete

	//	[(         a        ) <=> (         b        )]
	//	[(variable, location) <=> (variable, location)]

	//	Why b[0]? => this shows the value of a, whereas
	//	b[n+1] refers to the next unknown address and this
	//	may contain anything, which is trying to convert to
	//	an integer => this might be able to display for you,
	//	but this may also abort your application
	printf("[(%d, %pH) <=> (%d, %pH)]\n", a, &a, b[0], b);
	a++;
	b++;

	puts("Now what?");
	printf("[(%d, %pH) <=> (%d, %pH)]\n", a, &a, b[0], b);
	a++;
	b++;

	puts("And again...?");
	printf("[(%d, %pH) <=> (%d, %pH)]\n", a, &a, b[0], b);

	//	Since both a and b can use ++ and also --, this does
	//	not mean, that a and b are identical after the operation.
	//	a's value is incrementing by 1, whereas the address is still the same
	//	b's value is not incrementing; b's previous address is no longer pointed
	//	and b now points to the next block of address of the size of int => 4 bytes;
	//	that means, that b now refers to another block of memory, which is a foreign
	//	block, and tries to convert the random garbage value into an integer

	return EXIT_SUCCESS;
}