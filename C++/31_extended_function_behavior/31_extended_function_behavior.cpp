/*
* Extend / use a function like in C. Since there's no valid
* reason to do this, this shall not be used in C++.
*
* It may also leads into an undefined behavior.
*
* This sample shows how to use a function as an argument
* for an another function. If you want to see more, then
* check this out: https://github.com/ITWorks4U/programming_tutorials/tree/main/C/25_function_behavior
*/
#include <iostream>
using namespace std;

int add_numbers(int a, int b) {
	return a + b;
}

int subtract_numbers(int a, int b) {
	return a - b;
}

//                    the argument acceps
//                    only a function, which
//                    has two arguments of
//                    type int
void dynamic_function(int (*f)(int, int)) {
	cout << "{ ";
	for(int i = 0, j = 10; i < 20; i++, j--) {
		cout << (*f)(i,j) << " ";
	}
	cout << "}" << endl;
}

int main() {
	cout << endl << "using add_numbers...." << endl << endl;
	dynamic_function(add_numbers);

	cout << endl << "using subtract_numbers...." << endl << endl;
	dynamic_function(subtract_numbers);

	return 0;
}