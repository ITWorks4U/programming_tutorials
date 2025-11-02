#include <iostream>
using namespace std;

int main() {
	// -----------
	// while loop (runs, while a certain condition is given)
	// in contrast to a for loop make sure, that the condition in the head
	// will false at any time to leave the loop
	// -----------
	int ctr = 0;
	while(ctr < 10) {
		// required, otherwise the loop never ends
		ctr++;
		cout << "ctr: " << ctr << endl;
	}

	while (ctr != 0) {
		ctr--;

		if (ctr % 2 == 0) {
			continue;
		}

		cout << "ctr: " << ctr << endl;
	}

	/* infinite loop in C-style */
	while(1) {
		break;
	}

	/* infinite loop with a boolean expression */
	while(true) {
		break;
	}

	/* Also an infinite loop, however, THIS can't be left in a usual way! */
	// while(1) {}
	// while(true);

	return 0;
}