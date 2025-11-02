/*
* Imagine, you try to calculate something with different data types.
* By overloading functions / class methods, this may work "fine",
* but it looks awful, because you define functions multiple times.
*/

#include <iostream>
using namespace std;

// macro function for any type, but this
// is not recommended for C++
#define GET_MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int get_maximum(int a, int b) {
	return a > b ? a : b;
}

int get_maximum(double a, double b) {
	return a > b ? a : b;
}

int main() {
	cout << "maximum (int only): " << get_maximum(10,11) << endl;
	cout << "maximum (double only): " << get_maximum(1.2e5, 0.2e6) << endl;
	cout << "maximum (by macro): " << GET_MAX(123, 456) << endl;

	// Don't use this command below. This will not crash your application,
	// but you also won't be happy with this.
	// cout << "maximum (by macro again): " << GET_MAX("Hello there!", "How are you?") << endl;

	return 0;
}