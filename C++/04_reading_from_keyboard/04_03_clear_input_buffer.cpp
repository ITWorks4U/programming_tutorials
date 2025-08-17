#include <iostream>
#include <string>

//	for numeric_limits
//	don't mix this with limits.h
#include <limits>

using namespace std;

int main() {
	string content;
	cout << "enter something: ";

	//	reading until the enter key ('\n') has been detected
	//	allows to read multiple words
	getline(cin, content);
	cout << "content contains: " << content << endl;

	/*
	* huge mistake:
	* - cin.clear() does NOT clear the input buffer
	*   => cleans error flags only, if any
	*
	* use cin.ignore() instead
	*
	* -------------------
	* What about the cleanup instruction in C?
	* int c;
	* while ((c = getchar()) != '\n' && c != EOF);
	*
	* This can be used, as long as, no C++ instructions, like cin, getline, ...
	* is in use, otherwise it may lead to synchronization issues. This is also
	* not a good choice for performance critical section(s).
	*/

	//	cleans the whole buffer
	//	a second "enter key press" is required here
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return 0;
}