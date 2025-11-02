/*
* Create pseudo randomized numbers in C++-Style.
* This is a modern version of the C-style implementation
* and this is also more robust.
*/

#include <iostream>

// contain random utilities
#include <random>
#include <ctime>

// fallback to a time-based seeding
#include <chrono>
using namespace std;

int main() {
	// NOTE:  It may happen, that you receive the same "random numbers"
	//        over and over again. If true, then use the time-based
	//        seeding instruction from <chrono> header file instead.

	// ----------
	// from <random>
	// ----------
	// seed with a real random value, if available
	random_device rd;

	// initializing a random number engine with seed
	mt19937 gen(rd());

	// NOTE:  only in use, if the two instructions above gives you the
	//        same random numbers over and over again

	// ----------
	// from <chrono>
	// ----------
	// mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

	// define the range [low, high]
	int low = 1;
	int high = 100;

	// create a uniform distribution in that range
	uniform_int_distribution<> distr(low, high);

	for(int i = 0; i < 10; i++) {
		int random_number = distr(gen);
		cout << "random number between " << low << " and " << high << ": " << random_number << std::endl;
	}

	return 0;
}
