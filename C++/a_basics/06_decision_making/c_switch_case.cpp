#include <iostream>
using namespace std;

int main() {
	// simple check for different results

	int number;
	cin >> number;

	// determiantion for given number
	switch(number) {
		case 0:
			// only, if number contains 0

			break;
			// required, otherwise the next case is also in use
		case 1:
			// only, if number contains 1

			break;
		case 823648249:
			break;
		case -9628364:
			break;
		case 10:
		case 20:
		case 30:
			// using this block, if 10, 20 or 30 has been detected
			break;
		default:
			// handles every other case, which
			// hasn't been handled before
			break;
	}

	return 0;
}