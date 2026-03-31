/*
* Using an anonymous namespace allows you to store stuff,
* which has often been defined in the current source file instead.
*
* ---------------
* typical C-based:
* ---------------
* <modifier> <datatype> <variable> = <value>
* ---------------
*
* ---------------
* for C++ you can use it in that way:
* ---------------
* namespace {
* <modifier> <datatype> <variable> = <value>
* }
* ---------------
*
* Within the anonymous namespace you can store all global expressions.
* This allows you to have more a clean code.
*/

#include <iostream>
using namespace std;

namespace {
	/* "static" is at this point optional here */
	static long VARIABLE = 10L;
}

void updateVariable(int newValue) {
	VARIABLE += newValue;
}

int main() {
	cout << VARIABLE << endl;
	updateVariable(5);
	cout << VARIABLE << endl;

	return 0;
}
