/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <iostream>
using namespace std;

int main() {
	// bit operators can also be used for arithmetic operations to speed up the calculation
	// hardly used, but still worth

	int a = 42;
	int b = 9001;

	// arithmetic way
	cout << a << " is odd or even? => " << (a % 2 == 0 ? "even" : "odd") << endl;
	cout << b << " is odd or even? => " << (b % 2 == 0 ? "even" : "odd") << endl;

	// bitwise way
	// only the last bit is checked with 1
	// if true, then this number is odd, otherwise even
	cout << a << " is odd or even? => " << ((a & 1) == 0 ? "even" : "odd") << endl;
	cout << b << " is odd or even? => " << ((b & 1) == 0 ? "even" : "odd") << endl;

	return 0;
}