#include <iostream>
using namespace std;

//	-----------
//	Allows to run the function again and again and again... and... again.
//	Runs mostly faster than an iteration and has less content in contrast
//	to an iteration, however, you may have trouble when an error occurrs,
//	because it's hard to find a logical error.
//
//	By the way by using a recursion your RAM and CPU usage are also affected!
//	-----------
int recursion_function(int counter) {
	if (counter >= 100) {
		return counter;
	}

	cout << "counter = " << counter << endl;
	counter++;
	return recursion_function(counter);
}

/*
* looks quite simple, however, by using numbers >30 this will take a very, very, VERY long time
* unless, you're using a buffer for already calculated numbers instead => comes in a later session
*/
int fibonacci(int n) {
	switch(n) {
		case 0:
			return 0;
		case 1:
			return 1;
	}

	return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
	cout <<
		recursion_function(0) << endl <<
		"--------------" << endl << "using fibonacci sequence" << endl << "--------------"
	<< endl;

	for(int i = 0; i <= 30; i++) {
		cout << "fib(" << i << ") = " << fibonacci(i) << endl;
	}

	return 0;
}