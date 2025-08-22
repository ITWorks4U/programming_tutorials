#include "Calculator.hpp"

/*	"solution 3"	*/
#include "Calculator.cpp"

#include <iostream>
using namespace std;

int main() {
int a = 10;
	int b = 5;

	double c = 1.52;
	double d = 4e-2;

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