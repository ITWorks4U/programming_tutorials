/*
* Determine the prime numbers for a very large number range.
* This could be realized with the sieve of eratosthenes.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include "time_calculator.h"
using namespace std;
static const int upper_boundary = 1500500500;

// -----
// primitive way
// -----

bool on_prime(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	int limit = std::sqrt(n);
	for (int i = 3; i <= limit; i += 2) {
		if (n % i == 0) return false;
	}

	return true;
}

void primitive_way_for_prime_numbers() {
	vector<int> prime_numbers;

	for (int i = 2; i <= upper_boundary; ++i) {
		if (on_prime(i)) {
			prime_numbers.push_back(i);
		}
	}

	cout << "found " << prime_numbers.size() << " prime numbers" << endl;
}

// -----
// using a sieve instead
// -----

void sieve_of_eratosthenes() {
	vector<bool> on_prime_number(upper_boundary + 1, true);
	on_prime_number[0] = on_prime_number[1] = false;

	for(int i = 2; i * i <= upper_boundary; ++i) {
		if (on_prime_number[i]) {
			for(int j = i * i; j <= upper_boundary; j += i) {
				on_prime_number[j] = false;
			}
		}
	}

	int nbr_of_primes = 0;

	for(int i = 2; i <= upper_boundary; i++) {
		if(on_prime_number[i]) {
			nbr_of_primes++;
		}
	}

	cout << "found " << nbr_of_primes << " prime numbers" << endl;
}

void determine_prime_numbers(bool use_sieve = true) {
	auto start = high_resolution_clock::now();

	if (!use_sieve) {
		cout << "using the primive way (pray to god...)" << endl;
		primitive_way_for_prime_numbers();
	} else {
		cout << "using a sieve, like sieve of eratosthenes, instead..." << endl;
		sieve_of_eratosthenes();
	}

	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	print_time(duration.count());
}

int main() {
	cout << "determine all prime numbers between [2," << upper_boundary << "]..." << endl;
	//NOTE: NOT recommended to use the primitive way, unless you can spent a huge time amount ;-)
	determine_prime_numbers(true);

	return 0;
}