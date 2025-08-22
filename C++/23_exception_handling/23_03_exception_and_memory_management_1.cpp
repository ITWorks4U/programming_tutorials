/*
* It may happen, that a memory management is required to do
* something. However, what happens, if an exception appears?
*
* In contrast to the example before, by using smart_pointers
* the allocated memory will be removed automatically, so it
* doesn't care, if an exception may appear at any time or not.
*
* For more details: take a look to C/26_memory_management
*/

#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

int main() {
	fstream fs;
	fs.exceptions(ios::failbit | ios::badbit);
	const int buffer_size = 1024;

	try {
		// hint: use __FILE__ to use your current file instead

		fs.open("__any__file__", ios_base::in);

		//	using a smart pointer here
		unique_ptr<char []> buffer(new char[buffer_size]);
		fs.read(buffer.get(), buffer_size);

		cout << buffer.get() << endl;
		fs.close();
	} catch (const ifstream::failure &io_e) {
		cerr << "ifstream::failure &io_e has been thrown: " << io_e.what() << endl;
	} catch (const exception &e) {
		cerr << "exception &e has been thrown: " << e.what() << endl;
	}

	//	buffer will be deleted automatically, no matter if an
	//	exception has been thrown or not

	return 0;
}
