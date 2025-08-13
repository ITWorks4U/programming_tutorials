/*
* Dont't think, that a const expression is a real constant. That's just
* a readonly expression and does not allows you to modify its value.
*
* Unless you know how to use raw pointers. >:-)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	const int shall_not_be_modified = 100;

	//	this is impossible, as expected
	// shall_not_be_modified++;

	//	may give you a warning, that the const might no longer be available here
	int *address_ptr = &shall_not_be_modified;

	printf(
		"[%d, %pH] <=> [%d, %pH]\n",
		shall_not_be_modified, &shall_not_be_modified, address_ptr[0], address_ptr
	);

	//	"Arvada ...!" Oops, wrong spell. °(^.^)
	*address_ptr = 0xBAD;
	puts("Now what...?");

	printf(
		"[%d, %pH] <=> [%d, %pH]\n",
		shall_not_be_modified, &shall_not_be_modified, address_ptr[0], address_ptr
	);

	/*
	* If address_ptr gets a new address reference, this will also affect
	* the origin address, where shall_not_be_modified has usually been located.
	*/

	return EXIT_SUCCESS;
}