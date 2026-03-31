#include <iostream>
#include <string>
using namespace std;

class MathError : public exception {
	string error_message;

	public:
	MathError(string error_message) {
		this->error_message = error_message;
	}

	virtual ~MathError() {}

	string get_message() const {
		return this->error_message;
	}
};

/* using a whole template class */
template <class T>
class Calculator {
	public:
		Calculator() {}
		virtual ~Calculator() {}

		/*
		* Mostly the certain template methods are already implemented
		* in the class. These can also be outsourced into a certain
		* source file, however, there're some limitations.
		*
		* For more informations, take a look into the advanced/ folder.
		*/
		T add(T a, T b) const {
			return a + b;
		}

		T sub(T a, T b) const {
			return a - b;
		}

		T mul(T a, T b) const {
			return a * b;
		}

		T div(T a, T b) const {
			if (b == 0) {
				throw MathError("b must not be 0");
			}

			return a / b;
		}
};

int main() {
	int a = 10;
	int b = 0;

	double c = 1.52;
	double d = 4e-2;

	// to use a template class you must write the data type behind the class

	cout << "-------------" << endl;

	Calculator<int> calc_integer;
	cout << "a + b = " << calc_integer.add(a, b) << endl;
	cout << "a - b = " << calc_integer.sub(a, b) << endl;
	cout << "a * b = " << calc_integer.mul(a, b) << endl;

	try {
		cout << "a / b = " << calc_integer.div(a, b) << endl;
	} catch (MathError &me) {
		cerr << me.get_message() << endl;
	}

	cout << "-------------" << endl;

	Calculator<double> calc_double;
	cout << "c + d = " << calc_double.add(c, d) << endl;
	cout << "c - d = " << calc_double.sub(c, d) << endl;
	cout << "c * d = " << calc_double.mul(c, d) << endl;
	
	try {
		cout << "c / d = " << calc_double.div(c, d) << endl;
	} catch (MathError &me) {
		cerr << me.get_message() << endl;
	}

	return 0;
}