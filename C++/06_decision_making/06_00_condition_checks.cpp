#include <iostream>
using namespace std;

/*
* condition checks are almost identical to C programming, however,
* in contrast to C programming you're using bool
* by default
*
* false: 0
* true:  1
*/

int main() {
	bool checker = true;

	//	often used: if (checker) {...}
	if (checker == true) {
		cout << "condition is true" << endl;
	} else {
		//	only in use, if the condition above is false
		cout << "condition is false" << endl;
	}

	//	opposite

	//	often used: if (!checker) {...}
	if (checker != true) {
		cout << ">this< condition is true" << endl;
	} else {
		cout << ">this< condition is false" << endl;
	}

	//	What happens here?
	bool expression = -3000;
	cout << "expression is marked as: " << expression << endl;

	return 0;
}