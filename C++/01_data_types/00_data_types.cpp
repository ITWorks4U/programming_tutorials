/*
* determine, how much bytes a datatype requires;
* contains the primitive datatypes only
*
* similar to C the data types are mostly identical
*/

#include <iostream>

//	required for string data type
#include <string>

using namespace std;

int main() {
	//	sizeof(<data type>) is a keyword from C

	//	alternative: int8_t
	cout << "char has a size of " << sizeof(char) << " bytes" << endl;

	//	alternative: int16_t
	cout << "short has a size of " << sizeof(short) << " bytes" << endl;

	//	identical to short
	cout << "short int has a size of " << sizeof(short int) << " bytes" << endl;

	//	alternative: int32_t
	cout << "int has a size of " << sizeof(int) << " bytes" << endl;

	//	alternative: int64_t
	cout << "long has a size of " << sizeof(long) << " bytes" << endl;

	//	identical to long
	cout << "long int has a size of " << sizeof(long int) << " bytes" << endl;
	cout << "long long has a size of " << sizeof(long long) << " bytes" << endl;

	//	identical to long long
	cout << "long long int has a size of " << sizeof(long long int) << " bytes" << endl;

	//	in contrast to C you can use bool by default
	//	in C: usually use <stdbool.h>
	cout << "bool has a size of " << sizeof(bool) << " bytes" << endl;

	//	a C++ string is different to a C-string
	cout << "string has a size of " << sizeof(string) << " bytes" << endl;

	//	alternatives: u_char, u_int8_t
	cout << "unsigned char has a size of " << sizeof(unsigned char) << " bytes" << endl;

	//	alternatives: u_short, u_int16_t
	cout << "unsigned short has a size of " << sizeof(unsigned short) << " bytes" << endl;
	cout << "unsigned short int has a size of " << sizeof(unsigned short int) << " bytes" << endl;
	cout << "unsigned int has a size of " << sizeof(unsigned int) << " bytes" << endl;
	cout << "unsigned long has a size of " << sizeof(unsigned long) << " bytes" << endl;
	cout << "unsigned long int has a size of " << sizeof(unsigned long int) << " bytes" << endl;
	cout << "unsigned long long has a size of " << sizeof(unsigned long long) << " bytes" << endl;
	cout << "unsigned long long int has a size of " << sizeof(unsigned long long int) << " bytes" << endl;

	//	bool and string doesn't comes with an 'unsigned' 
	// cout << "bool has a size of " << sizeof(bool) << " bytes" << endl;
	// cout << "string has a size of " << sizeof(string) << " bytes" << endl;

	return 0;
}