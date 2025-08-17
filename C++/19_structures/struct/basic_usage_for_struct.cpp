/*
*
* Structures (struct) are very often used to capsulate
* multiple expressions to one object. Similar to OOP languages,
* however, a struct is not mentioned to use for OOP.
*
* A structure often has a larger amount of bytes, because
* every member requires it's own free space.
*
* --------------------------------
* basic syntax of a struct:
* struct <name> {};
*
* you can also use a synonym for your structure, like:
* struct <name> {}<name_to_use>;
*
* you can also use an anonymous structure, like:
* struct {};
*
* in contrast to C++ when you want to use a structure, you must write:
* struct <name_of_struct> <name_of_instance>;
* => then you can use your structure and an access to its member(s)
*
* if you want to use a syntax like C++, Java, C#, Python, ... just write:
* typedef struct {}<any_expression>;
* => then you can use: <any_expression> <name_of_instance>;
*
* In C++ you don't need to write the expression above. Just write:
* struct <name> {}; and use <name> <instance>;
* --------------------------------
*
* By the way, C handles a structure different rather than C++.
*
* C:
* - a struct contains members only
* - every member is unable to initialize inside of the struct
* - even a function can be wrapped into a struct to "claim", that
*   this function refers to that structure, but this is a bit tricky
*
* C++:
* - may initialize up to one member (any member)
* - may contain functions, constructor, destructor, ...
*  - those functions are called "methods", even there are not in a class
*/

#include <iostream>
#include <string>
using namespace std;

//	structs may contain nothing
//	NOTE: On Windows or any IDE it may happen, that
//	an error is shown up, that a declaration is expected
//	=> this application can be build anyway
struct EmptyStruct {};

struct MyStruct {
	char sign;
	int index;
	long identification;
	float percent;
	int another_index;
	string word;
	//...
};

int main(void) {
	//	usually, it's no need to use <struct> expression,
	//	because C++ handles this correctly
	struct EmptyStruct es;

	//	in C: 0 bytes, in C++: 1 byte!
	size_t size_of_struct = sizeof(es);

	cout << "Amount of bytes for \"es\": " << size_of_struct << endl;

	//	accessing to members
	MyStruct ms;
	ms.sign = 'A';
	ms.index = 100;
	ms.identification = 123;
	ms.percent = 0.76;
	ms.another_index = 700;

	//	in contrast to C you can directly assign a string
	ms.word = "";

	size_of_struct = sizeof(ms);
	cout << "Amount of bytes for \"ms\": " << size_of_struct << endl;

	//	WYSIWYG
	cout <<
		ms.sign << ", " << ms.index << ", " << ms.identification << ", " <<
		ms.percent << ", " << ms.another_index << ", " << ms.word
	<< endl;

	return 0;
}