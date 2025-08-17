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

#include <iostream>
#include <string>
using namespace std;

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
	string word;
	//...

	//	since string is in use here,
	//	a constructor as well as a
	//	destructor must exist
	MyUnion() {}
	~MyUnion() {}
};

int main(void) {
	union EmptyUnion eu;

	//	in C: 0 bytes, in C++: 1 byte!
	size_t size_of_union = sizeof(eu);
	cout << "Amount of bytes for \"eu\": " << size_of_union << endl;

	//	accessing to members
	/*
	* IMPORTANT:
	* If your union may contain at least one C++ instruction, like string,
	* then you can't initiate that union, because the constructor will be
	* deleted by default. To fix that uncommonly issue, you must remove
	* all raw C++ instructions in that union or you must define a constructor
	* as well as a destructor.
	*
	* Furthermore it may happen, that you won't be able to see that instructions below.
	*/

	MyUnion mu;
	mu.sign = 'A';
	mu.index = 100;
	mu.identification = 123;
	mu.percent = 0.76;
	mu.another_index = 700;
	mu.word = "";

	cout << "Amount of bytes for \"mu\": " << size_of_union << endl;

	//	WYSIWYG? => No! The last assigned member in your union dominates
	//	the values of the other members. In that case mu.word was assigned last,
	//	thus every member has a value of 0 (numeric) or '\0' for char or "\0\0\0..." for other C-string(s).
	cout <<
		mu.sign << ", " << mu.index << ", " << mu.identification << ", " <<
		mu.percent << ", " << mu.another_index << ", " << mu.word
	<< endl;

	//	let's modify that value:
	mu.word = "Hello from union!";

	//	Warning: this may cause an undefined behavior on runtime
	cout <<
		mu.sign << ", " << mu.index << ", " << mu.identification << ", " <<
		mu.percent << ", " << mu.another_index << ", " << mu.word
	<< endl;

	//	or modify an another value instead:
	mu.percent = 0.23e2;

	cout <<
		mu.sign << ", " << mu.index << ", " << mu.identification << ", " <<
		mu.percent << ", " << mu.another_index << ", " << mu.word
	<< endl;

	return 0;
}