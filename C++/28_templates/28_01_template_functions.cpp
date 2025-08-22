/*
* Templates allows you to reduce function / class redundancies and
* also offers you a more clean code. These templates can be interpreted
* as a "shape", which allows to work with any data type in theory.
*
* But you should know, that not every data type can be used for anything.
*/

#include <iostream>
using namespace std;

//	to use templates write:
template <class T>
T getMaximum(T a, T b) {
	return a > b ? a : b;
}

/*
* "T" is often an used expression for template. You're also welcome
* to use any other expression, if possible.
*
* Instead of "class" you can also write typename.
*/
template <typename anything>
void doSomething(anything a) {
	cout << a << endl;
}

//	---------------------
class Test {};

enum class E {
	A, B, C, D, E, F
};
//	---------------------

int main() {
	int a = 10;
	int b = 15;

	double c = 3.141;
	double d = 4e12;

	/*
		for template functions there's no need to write the data type behind the function,
		but you also can do this
	*/
	cout << "a (" << a << ") or b (" << b << "): " << getMaximum<int>(a, b) << endl;
	cout << "c (" << c << ") or d (" << d << "): " << getMaximum(c, d) << endl;
	cout << "c (" << c << ") or d (" << d << "): " << getMaximum<double>(c, d) << endl;

	doSomething(a);
	doSomething(b);
	doSomething(c);
	doSomething(d);
	doSomething("abcdef");

	/*
	* attention:
	* not every type can be used with
	* a template function, like:
	*/
	// Test t;
	// doSomething(t);
	// doSomething(E::A);

	return 0;
}