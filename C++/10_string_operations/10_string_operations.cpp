/*
* In contrast to C strings, C++ strings can be used
* more easily and offers you to interact with methods
* from the string class, too.
*/

#include <iostream>

//	don't mix up with <string.h> or <strings.h>
#include <string>
using namespace std;

int main() {
	//	---------
	//	determine size of string
	//	---------
	string str = "Howdy! How're you?";
	cout << "amount of characters (str.length()): " << str.length() << endl;

	//	What's going to print here?
	cout << "amount of characters (sizeof(str)): " << sizeof(str) << endl;

	//	---------
	//	concatenation
	//	---------
	string word = " I'm fine. Thanks!";
	str += word;
	cout << str;

	//	alternative way:
	string s;
	s.append(word);
	cout << s << endl;

	//	---------
	//	inserting
	//	---------
	//	inserting on position 5 "aaaa"
	s.insert(5, "aaaa");
	cout << "after s.insert(5, \"aaaa\");: " << s << endl;

	//	---------
	//	erasing
	//	---------
	//	erasing on position 3 the next 10 characters
	word.erase(3, 10);
	cout << "after word.erase(3, 10); " << word << endl;

	return 0;
}