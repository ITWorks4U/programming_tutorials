/*
* Usually, you should not use the C-style variant for measuring
* a time amount, because it's not clear, if this works fine and this
* may also cause an undefined behavior. Unlike to use C-Strings a simple
* C++ - string is in use here.
*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>
#include <string>

using namespace std;

void print_time(double seconds) {
	//	unlike to raw C-style cast: (int)
	//	the static_cast instruction is in use here
	//	more details: see chapter X

	int hours = static_cast<int>(floor(seconds / 3600));
	int minutes = static_cast<int>(floor(seconds / 60));
	int remaining_seconds = static_cast<int>(fmod(seconds, 60));

	cout << "duration: " << hours << "h " << minutes << "min " << remaining_seconds << "s " << endl;
}

int main() {
	string s0;
	const string s1 = "This is a simple lext to copy.";
	unsigned int counter = 0;

	//	from <ctime> / <time.h>
	clock_t start_timer = clock();
	cout << "starting time measurement..." << endl << "Please hold the lion." << endl;

	//	a simple, stupid and "Holy sh*t! Why do you do such bullsh*t?" instruction
	//	to emulate a long time amount
	//	UINT_MAX from <climits> / <limits.h>
	while(counter != UINT_MAX) {
		counter++;
		s0 = s1;
	}

	cout << "Finished!" << endl;
	clock_t end_timer = clock();

	//	end-start must be devided by CLOCLS_PER_SEC (number of clock ticks per second)
	//	to receive the current elapsed time in seconds
	double total_time = static_cast<double>((end_timer - start_timer) / CLOCKS_PER_SEC);
	print_time(total_time);

	return 0;
}