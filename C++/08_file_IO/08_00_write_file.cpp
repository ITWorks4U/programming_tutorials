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

//	for file I/O handling
#include <fstream>

using namespace std;

int main() {
	//	fstream: file stream for read and also write operations
	//	alternative: ostream for "out stream" only

	fstream fs;
	fs.open("test.txt", ios_base::out);

	//	opening file stream to open a file;
	//	if this file doesn't exist, it will be created
	//	otherwise the previous content will be replaced
	//	with the new content

	//	operation fails, if a directory instead of a file
	//	is given or you don't have access rights there
	//	-> no exception occurrs, however,
	//	you would be disappointed about the "reason"

	if (!fs.is_open()) {
		//	for any reason, why this file stream fails...
		cerr << "file can't be written... ¯\\_(ツ)_/¯" << endl;

		//	alternative way: using perror() function as used in C 
		// perror("File can't be written!");
		return 1;
	}

	//	how to write something to the file

	//	like to cout:
	//	"write something to given file stream fs"
	fs << "How to write \"I'm sorry!\" 100,000 times:" << endl << endl;

	for(int i = 0; i < 100000; i++) {
		fs << i+1 << ": I'm sorry!" << endl;
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