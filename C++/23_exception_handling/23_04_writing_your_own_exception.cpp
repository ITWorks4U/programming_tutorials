/*
* Write your own exception and throw that class in case of a specific error.
*
* On a Windows machine, it may happen, that this application can't be run,
* because any antivirus program may detect this as a "computer virus".
*/

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class CustomException : exception {
	string err_msg;

	public:
		CustomException(string message) {
			err_msg = message;
		}

		// A promise to the compiler, that this destructor
		// does NOT throw an exception.
		// => e. g. by using / releasing data from
		// memory
		//
		// On old C++ versions (C++98 and earlier)
		// throw() has been used here, which is
		// identical to noexcept; on newer versions
		// C++11 and newer, throw() is deprecated.
		//
		// If an exception may be raised here, then
		// you lied to the compiler and the application
		// termiantes immediately.
		virtual ~CustomException() noexcept {}

		const char *what() const noexcept override {
			return err_msg.c_str();
		}
};

void check_value(int value) {
	if (value < 0) {
		CustomException ce("value is < 0...");
		throw ce;
	}

	// ...
}

int main() {
	try {
		// runs fine
		check_value(100);

		// runs fine, too
		check_value(0);

		// raises the error
		check_value(-1);
	} catch (CustomException &ce) {
		cerr << "custom exception has been thrown with: " << ce.what() << endl;
	} catch (exception &e) {
		cerr << "general exception: " << e.what() << endl;
	}

	return 0;
}