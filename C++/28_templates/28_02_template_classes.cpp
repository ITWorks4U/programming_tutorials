#include <iostream>
using namespace std;

/*	using a whole template class	*/
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
			//	make sure, that b != 0
			return a / b;
		}
};

int main() {
	int a = 10;
	int b = 5;

	double c = 1.52;
	double d = 4e-2;

	/*	to use a template class you must write the data type behind the class	*/

	cout << "-------------" << endl;

	Calculator<int> cInt;
	cout << "a + b = " << cInt.add(a, b) << endl;
	cout << "a - b = " << cInt.sub(a, b) << endl;
	cout << "a * b = " << cInt.mul(a, b) << endl;
	cout << "a / b = " << cInt.div(a, b) << endl;

	cout << "-------------" << endl;

	Calculator<double> cDouble;
	cout << "c + d = " << cDouble.add(c, d) << endl;
	cout << "c - d = " << cDouble.sub(c, d) << endl;
	cout << "c * d = " << cDouble.mul(c, d) << endl;
	cout << "c / d = " << cDouble.div(c, d) << endl;

	return 0;
}