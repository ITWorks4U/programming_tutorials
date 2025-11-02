// import required libraries
// NOTE: In C++ it's uncommon to import C-libraries.
#include <iostream>

// this namespace allows you to use special instructions quite easy,
// however, in advanced C++ programming this shall not be used in that way
using namespace std;

// an application must start with main
int main() {
	// Every output is a "word".

	cout << "This is the first output!" << endl;

	/*
	* cout, endl, ... are defined in a namespace of "std" => std::cout, ...
	* without "using namespace std" std::cout << "text" << std::endl is required
	*
	* cout  :=  console output
	* <<    :=  direction stream => "write something to console output"
	* endl  :=  adding an end line => for C (printf()): \n
	*
	* Power of endl:
	* - flushes the output stream (not everytime a good choice)
	* - depending on which system you're programming, it's required to know
	*   how to create a new line
	*
	*   (mostly on old systems):
	*   - UNIX/Linux: \n
	*   - Windows:    \r\n
	*   - MacOS:      \r
	*
	* endl automatically determines which correct
	* format shall be used here
	*/

	// print numbers on console
	//      number             "word"
	cout << 123456 << endl << "123456" << endl;

	// in contrast to C you don't need to use
	// EXIT_SUCCESS / EXIT_FAILURE
	// furthermore those expressions are a clean
	// expression for: 0 / 1
	return 0;
}