#include <iostream>
using namespace std;

int main() {
	//	-----------
	//	for loop (stops automatically when end condition is no longer given)
	//	-----------
	/*	sequential loop	*/
	for(int i = 0; i < 10; i++) {
		cout << "i: " << i << endl;
	}

	/*	sequential loop in reversal order	*/
	for(int i = 9; i >= 0; i--) {
		cout << "i: " << i << endl;
	}

	/*	modifying index	*/
	for(int i = 0; i < 10; i++) {
		cout << "i++: " << i++ << endl;
	}

	/*	skipping a step	*/
	for(int i = 0; i < 10; i++) {
		if (i == 5) {
			continue;
		}

		cout << "i: " << i << endl;
	}

	/*	canceling loop	*/
	for(int i = 0; i < 10; i++) {
		if (i == 5) {
			break;
		}

		cout << "i: " << i << endl;
	}

	/*	infinite loop (use this with care)	*/
	for(;;) {
		/*	at this point this loop ends only, if a break statement has been detected	*/
		break;
	}

	/*	usually, an infinite for loop can also looks like:	*/
	for(int i = 0;;i++) {
		/*	since no exit condition is defined, this loop also runs over and over again	*/
		if (i == 10) {
			break;
		}
	}

	/*	also an infinite loop, however, THIS can't be handled in the usual way!	*/
	// for(;;);

	return 0;
}