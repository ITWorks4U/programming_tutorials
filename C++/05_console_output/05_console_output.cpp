#include <iostream>
using namespace std;

int main() {
	//	prints a message to stdout
	//	that, what you already have done multiple times
	cout << "A normal text to stdout by using cout." << endl;

	//	prints a message to stderr
	//	usually, stdout and stderr (on console) are "identical",
	//	because you can't see the difference, but you can
	//	manage the result outside of the application
	cerr << "This is an error message by using cerr." << endl;

	return 0;
}