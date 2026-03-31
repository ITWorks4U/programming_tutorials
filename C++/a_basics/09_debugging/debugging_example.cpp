/*
* Debugging is the most spent time for a programmer, because you
* have to figure out what's going wrong, which was not supposed to get.
*
* It doesn't matter, if YOU have caused a logical error or if
* any other person did this. It's YOUR job to fix this.
*
* Outside of a CLI (console line interface) you can use gdb(.exe).
* Take a look to the readme file for more informations.
*/

#include <iostream>
using namespace std;

int recursion_function(int counter) {
	if (counter < 0) {
		return counter;
	}

	// oops, the given counter never reaches
	// the condition above and this causes
	// an application crash
	cout << "counter = " << counter << endl;
	counter++;
	return recursion_function(counter);
}

int main(void) {
	cout << recursion_function(0) << endl;
	return 0;
}