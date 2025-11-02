/*
* reading from keyboard for C++
*
* it's also possible to use the C-syntax,
* however, that's not recommended for C++
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string content;
	cout << "enter anything: ";

	// cin   := console input => read something from keyboard
	// >>    := "and move the input to a destination"
	cin >> content;

	cout << "content contains: " << content << endl;

	/*
	* disadvantages:
	* -	only the first "word" will be stored to content (similar to gets(), scanf())
	* -	any other input in the input buffer remains until the next input can be read
	* or the application ends
	* => wasting application buffer
	*/

	return 0;
}