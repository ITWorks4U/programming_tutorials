/*
* Handling an exception by using C-stytle looks dumb and
* also causes undefined behavior. You should not use those
* in C++ programming.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	/*
	* simple example: try to read from a file stream, where:
	* - the file does not exist
	* - the file stream is corrupted
	* - it's a directory
	* - insufficient permissions
	* - ...
	*
	* In general, those possible errors above are (very) hard
	* to handle with C-exception-handling-style.
	*/

	fstream fs;
	fs.open("not_existing", ios_base::in);

	if (!fs.is_open()) {
		//	perror can also be used here to show up
		//	a more clean reason for that failure
		perror("fs.open()");
		return 1;
	}

	//	do something with that opened file

	//	close the file stream
	fs.close();

	return 0;
}