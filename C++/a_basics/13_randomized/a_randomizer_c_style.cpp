/*
* Create pseudo randomized numbers in C-Style.
* This can be used, however, this has also some
* flaws, e. g. not thread safe, causing undefined
* behavior, ...
*
* NOTE:
* On a Windows machine it MAY happen, that your application
* would be a computer virus or your software MAY contain
* suspicious content. Reason: The time() function may
* result this uncommonly error.
*/

#include <iostream>
#include <ctime>
using namespace std;

int main() {
	// start with time_t variable
	// if this has a fixed value, then you will always get
	// the same "random" numbers
	//
	// A C++ compiler might gives you a warning.
	time_t t;

	// create a random seed
	//
	// NOTE:   If your application (tested on some Windows machines) may not
	//         launch, because it might be a "computer virus" or else,
	//         then this instruction below might be the reason:
	//         srand(time(&t));

	// may be used, but also allows backdoors to use
	srand(t);

	// srand(<any fixed number>) results to a fixed "random" number over and
	// and over again

	// since a random seed has been created, rand() can now be used
	// basicly a random number between 0 and RAND_MAX
	for(int i = 0; i < 10; i++) {
		cout << "random number: " << rand() << endl;
	}

	cout << endl << endl;

	// a random number within a range
	// rand() % <number> returns a range between 0..n-1 (for <number>)
	// if you want a range between 1..n, just add +1
	for(int i = 0; i < 10; i++) {
		cout << "random number between 10 and 100: " << (rand() % (100-10) + 1) << endl;
	}

	return 0;
}