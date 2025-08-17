#include <iostream>
using namespace std;

/*
* definition of a function:
* [modifier] <datatype> <function name>([parameters: <datatype> <expression> [= predefined value]])
*/

//	void :=	"nothing" => void doesn't comes with a return value
void function1() {
	cout << "This is a void-function!" << endl;
}

//	other functions requires a return value depending on the data type
//	hint:
//	in C as well as in C++, you'll get a warning about a missing return instruction
//	in C++ you'll get "nan" as the return state
double function2() {
	//	not all numbers behind the comma returns here
	return 12345.6789;
}

int main() {
	cout << "The main function!" << endl;
	function1();
	cout << function2() << endl;

	return 0;
}