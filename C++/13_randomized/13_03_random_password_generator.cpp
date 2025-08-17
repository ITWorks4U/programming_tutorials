/*
* Do you need a new password and you're tired to use an already, perhaps not good application?
* Then create your own application instead. ;-)
*
* In contrast to the C implementation this is more
* robust for raw C++.
*
* - tested with Linux (Mint 21.1), Raspberry OS Lite, Windows
*
* Have fun! :)
*/
#include <iostream>

//	for strtol
#include <cstdlib>

#include <string>
#include <random>

//	fallback seed
#include <chrono>

using namespace std;

//	The application can be used with a single argument only, where it must be an integer only.
int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "usage " << argv[0] << "<length for a random password in a range between 1 and 100>" << endl;
		return 1;
	}

	//	using an uncommonly way to check, if argv[1] is an
	//	integer or not; it may fail, if argv[1] does not
	//	contain a number between ^-?[0-9]$ or if the range
	//	of the integer exceeds
	int pw_length = -1;

	//	exception handling: see chapter 22
	try {
		pw_length = stoi(argv[1]);
	} catch (invalid_argument) {
		cerr << "invalid input" << endl;
		return 1;
	} catch (out_of_range) {
		cerr << "number was out of an integer range" << endl;
		return 1;
	}

	//	finally, check, if the valid number is not in the range of [1;100]
	if (pw_length < 1 || pw_length > 100) {
		cerr << "Input was not in the range between [1,100]" << endl;
		return 1;
	}

	const string word_pool =
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789"
		"!@#$%^&*()-_=+[]{}<>?";

	// random_device rd;
	// mt19937 gen(rd());

	//	fallback to an older system, if the both instructions above
	//	creates the identical random password over and over again
	mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
	uniform_int_distribution<> distr(0, word_pool.size() - 1);

	string password;
	for (int i = 0; i < pw_length; ++i) {
		password += word_pool[distr(gen)];
	}

	cout << "Generated password: " << password << endl;

	return 0;
}