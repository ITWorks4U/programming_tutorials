// C++ also comes with a for-each-loop
// prefered in combination with collections, like a simple array,
// or any other container collection

#include <iostream>
using namespace std;

int main() {
	int simple_array[] = {0,1,2,3,4,5,6,7,8,9};

	// you don't need to access to the certain position and allows
	// you to speed up the code
	//
	// syntax: for(<datatype> <variable> : <container collection>) {}
	for(int number : simple_array) {
		cout << number << endl;
	}

	return 0;
}