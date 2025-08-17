#include <iostream>
using namespace std;

int main() {
	//	-----------
	//	in contrast to a while loop the do-while-loop runs at least
	//	once and the condition check, which determines to run the next
	//	iteration is at the end of that loop
	//
	//	unlike to a while loop in the do-while-loop the while statement
	//	must end with a semicolon
	//	-----------
	int ctr = 0;

	do {
		cout << "ctr: " << ctr << endl;
		ctr++;
	} while(ctr < 10);

	do {
		ctr--;

		if (ctr % 2 == 0) {
			continue;
		}

		cout << "ctr: " << ctr << endl;
	} while(ctr != 0);

	/*	infinite loop examples	*/
	//	never leaves a loop in the usual way
	// do {} while(1);
	// do {} while(true);

	do {
		ctr++;
		cout << "ctr: " << ctr << endl;

		if (ctr == 100) {
			break;
		}
	} while(true);

	return 0;
}