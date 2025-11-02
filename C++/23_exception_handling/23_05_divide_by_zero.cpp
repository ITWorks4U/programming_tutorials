/*
* Do you think, that a division by zero would throw
* an exception by default? Think again. ;-)
*
* A division by 0 causes an undefined behavior in C++.
* Perhaps an exception can really be thrown and catched,
* perhaps this error has been "handled" internal or the
* application silency terminates without any useful information,
* or the application may crash elsewhere.
*/

#include <iostream>
using namespace std;

int divide(int a, int b) {
	return a / b;
}

int main() {
	int nominator = 10;

	// without catching a division by 0 error
	// for (int denominator = 10; denominator >= -10; denominator--) {
	// 	cout << nominator << "/" << denominator << " = " << divide(nominator, denominator) << endl;
	// }

	// By the way, what kind of arithmetic error could be thrown?
	// Maybe runtime_error, logic_error, exception, ...?
	//
	// In summary, you don't know, unless you're throwing a certain
	// exception, when the denominator is 0.
	for (int denominator = 10; denominator >= -10; denominator--) {
		try {
			cout << nominator << "/" << denominator << " = " << divide(nominator, denominator) << endl;
		} catch (exception &e) {
			cerr << e.what() << endl;
		}
	}

	return 0;
}