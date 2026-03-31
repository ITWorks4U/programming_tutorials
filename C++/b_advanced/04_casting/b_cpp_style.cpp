/*
* In contrast to the C-style casting, C++ comes with
* specific keywords to allow a casting.
*/

#include <iostream>
#include <limits>
using namespace std;

int main() {
	//	in contrast to macro instructions use
	//	a constant expression instead
	const double light_years = 9.461e15;
	const double euler_expression = 2.1828182845904523536;

	cout <<
		"---------------" << endl <<
		"LY: " << light_years << endl <<
		"---------------"
	<< endl;

	cout <<
		"---------------" << endl <<
		"e: " << euler_expression << endl <<
		"---------------"
	<< endl;

	//	much better than (int), but you'll also get
	//	an integer overflow
	int ly_int = static_cast<int>(light_years);
	cout <<
		"---------------" << endl <<
		"ly_int... " << ly_int << endl <<
		"---------------"
	<< endl;

	/*
	* other casting types, like:
	*
	* reinterpret_cast<type_to_cast>(type);
	* - unsave cast; allows you always to cast a type into another type,
	*   where the compiler might not compile the program
	* - often used for raw pointers
	*
	* dynamic_cast<type_to_cast>(type);
	* - usually used for classes and polymorphism; allows you to cast a
	*   type into another type on runtime, however, use this with care
	* - often used with polymorphic
	*
	* const_cast<type_to_cast>(type);
	* - hardly used casting option; allows you to cast a const*
	*   into another type and vice versa;
	* - use this with care
	*/

	//	--------------
	//	using precision
	//	--------------
	cout << endl << endl <<
		"---------------" << endl <<
		"again..." << endl <<
		"---------------"
	<< endl;

	//	using this template to modify the precision of each double variable
	typedef numeric_limits<double>dbl;

	//	in combination with a fixed precision we have a clear
	//	precision output for each double variable
	cout.precision(dbl::max_exponent10);

	cout << fixed <<
		"---------------" << endl <<
		"LY: " << light_years << endl <<
		"---------------"
	<< endl;

	cout << fixed <<
		"---------------" << endl <<
		"e: " << euler_expression << endl <<
		"---------------"
	<< endl;

	return 0;
}