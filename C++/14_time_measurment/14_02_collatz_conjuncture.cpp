#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

//	static tells the compiler, that this step_ctr is available
//	only in this file
static int step_ctr = 0;

void print_time(long long seconds) {
	long long hours = seconds / 3600;
	long long minutes = seconds / 60;
	long long remaining_seconds = seconds % 60;
	long long milli_seconds = seconds * 1000;
	long long micro_seconds = seconds * 1000000;
	long long nano_seconds = seconds * 1000000000;

	cout << "duration: " <<
		hours << "h, " << minutes << "min, " << remaining_seconds << "s, " <<
		milli_seconds << "ms, " << micro_seconds << "(micro)s, " << nano_seconds << "ns"
	<< endl;
}

int collatz_conjecture(int number) {
	cout << "current number: " << number << endl;
	step_ctr++;

	if (number == 1) {
		//	return 1 for 1 only
		return 1;
	}

	if (number % 2 == 0) {
		//	number is even
		return collatz_conjecture(number / 2);
	}
	
	//	number is odd (except for 1)
	return collatz_conjecture(3 * number + 1);
}

int main(void) {
	const int upper_boundary = 123456789;
	auto start = high_resolution_clock::now();
	cout << "start time measurment..." << endl;

	collatz_conjecture(upper_boundary);

	cout << "Took " << step_ctr << " steps..." << endl;

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	print_time(duration.count());

	return 0;
}