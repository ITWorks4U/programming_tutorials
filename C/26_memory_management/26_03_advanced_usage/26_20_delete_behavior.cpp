/*
* Do you really think, that 'delete' always works for
* any kind of pointers? This is not true, because depending
* on which pointer you want to release the behavior may
* be different and may also cause memory leak(s), application
* crash, ...
*/

#ifndef __cplusplus
#error	"This sample can be build with a C++ compiler only."
#else
#warning	"This sample causes an undefined behavior!"

#include <iostream>

void use_delete_pointer() {
	//	just a normal way to use a raw pointer in C++
	//	(not recommended; use smart pointers only)
	int *i_ptr = new int;

	/*
	* Do whatever you want to do with this pointer, even it's an integer field.
	* Since it's a pointer with a size of x bytes, depending on the architecture you're working on,
	* it "only" has an allocated size of 4 bytes (integer only) => similar to C: int *i_ptr = malloc(int)
	*
	* By using delete only the allocated memory in bytes are going to release.
	* By using delete[] you're also going to release memory, which hasn't been used
	* for the allocation process => You don't know, what may happen!
	*/

	//	normal way
	delete i_ptr;

	//	don't do this => undefined behavior
	// delete []i_ptr;
}

void use_delete_pointer_pointer() {
	//	create a field of int, which is planned to store up to 100 different values
	//	this is similar to the i_ptr above, but here you want to respect the limitation
	int *i_ptr = new int[100];

	/*
	* Since i_ptr is an integer field with an amount of 20 elements with each size of
	* 4 bytes, this field must be released element for element => delete[] does this job.
	*
	* By using delete you'll only delete the first element, however, the 19 elements left
	* still exists. => Memory leak.
	*/

	//	normal way
	delete []i_ptr;

	//	syntax error
	// delete *i_ptr;

	//	don't do this
	// delete i_ptr;
}

int main() {
	/*
	* Even this application MAY work "without any error", use a memory check application,
	* like "valgrind" (Linux), "Dr.Memory", "PVS Studio", ... to figure out, what kind of mess
	* you are doing here.
	*/
	use_delete_pointer();
	use_delete_pointer_pointer();

	return 0;
}

#endif