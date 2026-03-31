/*
* Would you like to play lottery? Receive 6 random and unique numbers
* from 49 possible numbers. Perhaps this might be your next tip. ;-)
*
* NOTE:
* You can also use a raw C-style implementation, but it MAY happen,
* that your application is unable to build or run on a Windows
* machine! Use the C++ - style implementation instead.
*/

#include <iostream>
#include <vector>
#include <random>

// for shuffle and sort
#include <algorithm>

// fallback to a time-based seeding
#include <chrono>

using namespace std;

int main() {
	vector<int> pool;
	for (int i = 1; i <= 49; ++i) {
		pool.push_back(i);
	}

	// NOTE:  It may happen, that you receive the same "random numbers"
	//        over and over again. If true, then use the time-based
	//        seeding instruction from <chrono> header file instead.

	// random_device rd;
	// mt19937 gen(rd());

	// NOTE:  only in use, if the two instructions above gives you the
	//        same random numbers over and over again
	mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

	// shuffle the pool randomly
	shuffle(pool.begin(), pool.end(), gen);

	// pick the first 6 numbers
	vector<int> lottery_numbers(pool.begin(), pool.begin() + 6);

	cout << "Your lottery numbers are: ";
	for (int num : lottery_numbers) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
