/*
* Handling an exception in C++ allows you to react
* and interact with special cases, where any exception
* can appear for sure, like:
*
* - using file stream
* - using network stream
* - converting a string into an integer (without regular expression check before)
* - ...
*/

#include <iostream>
#include <fstream>
#include <string>

// exception handling with additional options
// those libraries are not required to use here:
// #include <exception>
// #include <stdexcept>

using namespace std;

int main() {
	/*
	* same simple example again: try to read from a file stream, where:
	* - the file does not exist
	* - the file stream is corrupted
	* - it's a directory
	* - insufficient permissions
	* - ...
	*/

	fstream fs;

	// to enable to throw exceptions, this must be done first,
	// because fs.open() does not throw an exception by default,
	// which will be able to handle here
	fs.exceptions(ios::failbit | ios::badbit);
	
	try {
		// this can be failed, but this is an expected possible failure
		fs.open("not_existing", ios_base::in);
		string current_line;

		while(getline(fs, current_line)) {
			cout << current_line << endl;
		}

		fs.close();
	} catch (const ifstream::failure &io_e) {
		// catching every file error here
		cerr << "ifstream::failure &io_e has been thrown: " << io_e.what() << endl;
	} catch (const exception &e) {
		// in case of any error, here: a general error
		// this gives us an information, why the attempt(s)
		// above failed

		// this is the last possible way to handle any exception,
		// which was unable to handle before
		//
		// fun fact: unlike to use [const] exception &e, you can
		// also use: catch(...) to catch any exception
		cerr << "exception &e has been thrown: " << e.what() << endl;
	}

	/*
	* Looks much easier, however, this is not given everytime.
	* When you're using memory management by >new< or raw pointers (C),
	* then you must ensure to release those memory in any error case,
	* otherwise you'll receive memory leaks, followed by undefined behavior.
	*/

	return 0;
}