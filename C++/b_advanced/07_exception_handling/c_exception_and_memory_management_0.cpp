/*
* It may happen, that a memory management is required to do
* something. However, what happens, if an exception appears?
*
* Can you ensure to release allocated memory in every case?
* This sample does not use smart_pointers.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream fs;
	fs.exceptions(ios::failbit | ios::badbit);
	char *buffer = nullptr;
	const int buffer_size = 1024;

	try {
		// What will happen with buffer, when
		// an exception has been thrown...?
		buffer = new char[buffer_size];

		fs.open("__any__file__", ios_base::in);
		fs.read(buffer, buffer_size);
		fs.close();

		// remove allocated buffer, if and only if, no error
		// has been detected on runtime
		// delete[] buffer;
	} catch (const ifstream::failure &io_e) {
		cerr << "ifstream::failure &io_e has been thrown: " << io_e.what() << endl;
	} catch (const exception &e) {
		cerr << "exception &e has been thrown: " << e.what() << endl;
	}

	// Since buffer has been allocated as a buffer for
	// file I/O and suddenly any error appeared, the buffer
	// won't be released from memory and this causes a
	// memory leak. Doesn't sounds good, right?

	// in general, this instruction below could be used,
	// where the delete[] command in the try block must not
	// be placed there:
	delete[] buffer;

	return 0;
}
