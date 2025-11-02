/*
* In contrast to C strings, strings in C++ can be used
* more easily and offers you to interact with methods
* from the string class, too. But even those strings have
* a (lagging) tail.
*/

#include <iostream>

// NOTE:  don't mix up with <string.h> or <strings.h>
// NOTE:  Every string method returns a new string with the modified
//        string content, whereas the original string still remains.
// NOTE:  It may happen, that your application MIGHT be handled as a threat,
//        because some C-string functions comes with some backdoors.

// required for strlen(), and also offers
// to use other C-string functions
#include <cstring>

// required to use strings
#include <string>
using namespace std;

int main() {
	// ---------
	// determine size of string
	// ---------
	string str = "A simple string in C++. Strings are immutable.";

	cout << "\"" << str << "\" has an amount of bytes with... " << endl << endl;

	cout << "(str.length()):       " << str.length() << endl;                 // returns the number of characters
	cout << "(sizeof(str)):        " << sizeof(str) << endl;                  // returns the default size of a string instead
	cout << "strlen(str.c_str()):  " << strlen(str.c_str()) << endl;          // returns the number of characters until the first null termination character: '\0'
	cout << "(sizeof(str.c_str()): " << sizeof(str.c_str()) << endl;          // Are you surprised? ;-)

	// in summary: Sometimes it's strictly required to convert a string into
	// a C-string, but those have a different behavior. Furthermore strlen
	// returns the length of a C-string until the first null termination
	// character has been detected. No matter how many characters are left.

	cout << endl <<
		"-----------" << endl <<
		"other operations here" << endl <<
		"-----------" << endl <<
	endl;

	// ---------
	// concatenation
	// ---------
	string word = "Oh, an another text.";
	str += word;
	cout << str << endl;

	// alternative way:
	string s;
	s.append(word);
	cout << s << endl;

	// ---------
	// insert
	// ---------
	// insert on position 5 "aaaa"
	s.insert(5, "aaaa");
	cout << "after s.insert(5, \"aaaa\");: " << s << endl;

	// ---------
	// erase
	// ---------
	// erasing on position 3 the next 10 characters
	s.erase(3, 10);
	cout << "after s.erase(3, 10); " << s << endl;

	// ---------
	// using C-string functions instead
	// ---------
	//
	// NOTE: It may happen, that your application might
	//       be detected as a threat!
	//
	// NOTE: By the way, when you're using C-strings, then
	//       make sure, that you have ENOUGH free space
	//       for the C-string, otherwise this leads into
	//       an undefined behavior!
	cout << "using some C-string functions instead..." << endl;

	// NOTE: a C-string contains garbage on runtime without
	//       an initialization, so your c_string might shows
	//       you up much more than expected
	char c_string[32];
	cout << "using a c_string with up to 31 variable characters and a null termination character..." << endl << endl;

	strcpy(c_string, word.c_str());
	cout << c_string << ": length of c_string: " << strlen(c_string) << " bytes" << endl;

	strcat(c_string, s.c_str());
	cout << c_string << ": length of c_string: " << strlen(c_string) << " bytes" << endl;

	// Have you noticed, that on some systems a small time amount is in use before the
	// appliction "normally" terminates? If your application hasn't been crashed on the last
	// command (c_string can hold up to 31 characters only, whereas 35 characters with \0 now exists)
	// then a memory access violation has silently been detected or "handled" or just ignored or else.

	return 0;
}