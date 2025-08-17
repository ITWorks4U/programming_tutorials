/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <iostream>
using namespace std;

int main() {
	//	Bit shifting allows you to move the bits by n positions to the left or right.
	//	Shift to the left makes the number bigger, where right shift makes the number smaller.

	int a = 42;

	//	42 becomes 336
	cout << "a << 3 = " << (a << 3) << endl;

	// 42 becomes 5
	cout << "a >> 3 = " << (a >> 3) << endl;

	return 0;
}