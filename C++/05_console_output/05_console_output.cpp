#include <iostream>

// I/O manipulation
#include <iomanip>

using namespace std;

int main() {
	// prints a message to stdout
	// that, what you already have done multiple times
	cout << "A normal text to stdout by using cout." << endl;

	// prints a message to stderr
	// usually, stdout and stderr (on console) are "identical",
	// because you can't see the difference, but you can
	// manage the result outside of the application
	cerr << "This is an error message by using cerr." << endl;

	// -------------
	// print a message with a formatted output style
	// -------------
	int width_for_output = 17;
	int number = 10;

	cout << setw(width_for_output) << number << endl;

	// alignment: left, right (default), middle
	cout << left  << setw(width_for_output) << number << endl;
	cout << right << setw(width_for_output) << number << endl;
	cout << internal << setw(width_for_output) << -number << endl;

	// replace whitespace(s) with a certain character
	char placeholder = '.';
	cout << setfill(placeholder) << setw(width_for_output) << number << endl;

	// formatting with floating point data
	double x = 123.456789;
	cout << fixed << setprecision(2) << x << endl;            // fix the numbers after the comma to two numbers
	cout << scientific << setprecision(4) << x << endl;       // convert the floating point number into an exponential format


	return 0;
}