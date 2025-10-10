/*
* C++ comes with optimizations to boost code, which takes too much time.
* Example: Calculating the fibonacci series by using recursion.
* By using a high number, this takes too much time to solve the calculation.
*
* By using unsigned long long, for a 64 bit machine,
* the highest possible number is up to 12.2e18. So the upper boundary is
* set to 93 only.
*/

#include <iostream>
#include <vector>
#include "time_calculator.h"

using ULL = unsigned long long;
using namespace std;

const int upper_limit = 93;
static vector<ULL> fibonacci_container;

void init_container() {
	//	initialize the vector with 0,1
	for(int i = 0; i <= 1; i++) {
		fibonacci_container.push_back(i);
	}
}

ULL fibonacci_series_loop(ULL number) {
	if (number < fibonacci_container.size()) {
		return fibonacci_container[number];
	}

	while (fibonacci_container.size() <= number) {
		ULL next = fibonacci_container[fibonacci_container.size() - 1] +
				   fibonacci_container[fibonacci_container.size() - 2];
		fibonacci_container.push_back(next);
	}

	return fibonacci_container[number];
}

ULL fibonacci_series_recursion(ULL number) {
	if (number < fibonacci_container.size()) {
		return fibonacci_container[number];
	}

	ULL result = fibonacci_series_recursion(number - 1) + fibonacci_series_recursion(number - 2);
	fibonacci_container.push_back(result);

	return result;
}

void print_series(bool with_recursion = true) {
	cout << "result by using ";

	if (with_recursion) {
		cout << "recursion" << endl;
	} else {
		cout << "a loop" << endl;
	}

	cout << "{ ";

	for(ULL f : fibonacci_container) {
		cout << f << " ";
	}

	cout << "}" << endl;}

int main() {
	auto start = high_resolution_clock::now();
	init_container();
	for(int i = 0; i <= upper_limit; i++) {
		fibonacci_series_recursion(i);
	}

	print_series();
	fibonacci_container.clear();
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	print_time(duration.count());

	start = high_resolution_clock::now();
	init_container();
	for(int i = 0; i <= upper_limit; i++) {
		fibonacci_series_loop(i);
	}
	print_series(false);
	end = high_resolution_clock::now();
	duration = duration_cast<seconds>(end - start);
	print_time(duration.count());

	return 0;
}