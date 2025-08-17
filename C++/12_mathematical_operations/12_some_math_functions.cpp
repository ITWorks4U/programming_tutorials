/*
* Using mathematical functions, like sine(), cosine(), sinh(), ...
*
* for Linux and possibly macOS: The linker needs -lm as additional compiler command,
* otherwise the functions can't be used correctly. This is not required
* everywhere, but you're happier, if you have linked the math libary
* on compile time. ;-)
*/

#ifndef _WIN32
#warning "Make sure to link -lm to the compiler, otherwise your application can't be build."
#endif

#include <iostream>

//	for functions, like sin, cos, tan, pow, ...
#include <cmath>

//	for DBL_MAX expression
#include <cfloat>

//	for pi, euler, ...
//	only for C++20 or later
//
//	otherwise the expressions can't be found, so the compilation won't continue;
//	same result, when this header file was not found
// #include <numbers>

//	to be able to print floating point
//	numbers into exponentional notation
#include <iomanip>
using namespace std;

/*
* Usually, M_PI is not known on a Windows machine, so the application
* is unable to build. Unless, we define M_PI for our own purpose.
*/
#ifndef M_PI
#define M_PI  3.1415926535897932384626433
#endif

/*
* C++ also comes with pi and euler expression, by using
* <numbers>
* numbers::e, numbers::pi
*
* this is in use instead of macro expressions => see: chapter 17 in C programming for more details
*/

/*	own written functions to calculate something	*/
void calculate_area_circle(int radius) {
	cout << "area: " << scientific << setprecision(5) << (M_PI * radius * radius) << endl;
}

void calculate_volume_circle(int radius) {
	cout << "volume: " << scientific << setprecision(5) << (4/3 * M_PI * radius * radius * radius) << endl;
}

int main() {
	for(int i = 0; i < 50; i++) {
		calculate_area_circle(i);
		calculate_volume_circle(i);
	}

	cout << "============" << endl << endl;

	//	using some math functions from [c]math.h:
	for(double i = 0.0; i <= 90.0; i += 0.1) {
		cout << "sin(" << i << ") = " << sin(i) << endl;
		cout << "cos(" << i << ") = " << cos(i) << endl;
		cout << "tan(" << i << ") = " << tan(i) << endl;
		cout << "-------------" << endl;
	}

	cout << "============" << endl << endl;

	for (int i = 0; i < 10; i++) {
		//	casting is recommended, because most of those functions
		//	are handling floating point numbers
		cout << "power of " << i << " = " << pow((double)i, (double)i) << endl;
		cout << "square root of " << i << " = " << sqrt((double) i) << endl;
	}

	//	many other functions here...
	double d_infinite = DBL_MAX;
	cout << "Is " << d_infinite << " infinite? " << (isfinite(d_infinite) ? "yes" : "no") << endl;

	return 0;
}