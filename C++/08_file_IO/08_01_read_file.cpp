/*
* In contrast to C programming you usually don't use:
* - FILE* fopen(const char *__FILE_NAME__, const char *__MODE__);
* - int fclose(FILE *__PTR__);
*
* Of course, you can also do this in C++, however, your application
* might result to an undefined behavior.
*
* There's a smarter version to use file streams instead.
*/

#include <iostream>
#include <string>

//	for file I/O operations
#include <fstream>

using namespace std;

int main() {
	//	fstream: file stream for read and write operations
	//	alternative: istream for "in stream" only
	fstream fs;

	fs.open("test.txt", ios_base::in);

	//	opening file stream to open a file
	//	- this file MUST exist
	//	- it must NOT be a directory and
	//	- you should have access permissions to that file,
	//
	//	otherwise the operation fails
	//	-> no exception occurrs, however,
	//	you would be disappointed about the "reason"

	if (!fs.is_open()) {
		/*
		* NOTE:
		* The "error handling" is pathetic,
		* becuase in C++ this won't work
		* as well as in C programming.
		*
		* In that case, we deal with that either way.
		*/

		//	for any reason, why this file stream fails...
		cerr << "file can't be read... ¯\\_(ツ)_/¯" << endl;

		//	alternative way: using perror() function as used in C 
		// perror("File can't be read!");
		return 1;
	}

	//	how to read the file
	string tmp;

	while (!fs.eof()) {
		//	way one: read every singe word -> ineffective,
		//	because you're unable to read the file as expected
		//fs >> tmp;

		//	way two: read the full line, no matter, how much
		//	text is there
		getline(fs, tmp);

		//	output:
		cout << tmp << endl;
	}

	//	closing the file stream
	fs.close();

	/*
	* NOTE:
	* At any time any exception may occur here,
	* therfore this code is a kind of mess, however,
	* this shows you the basic usage of writing a file
	* in C++.
	*/

	return 0;
}