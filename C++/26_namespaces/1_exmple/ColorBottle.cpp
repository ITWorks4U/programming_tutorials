#include <iostream>
#include "ColorBottle.hpp"
using namespace std;

namespace Color {
	void Bottle::drinkFromBottle() {
		cout << "Are you sure?" << endl;
	}

	void Bottle::fillBottle() {
		cout << "fill bottle..." << endl;
	}

	/*
	* Unless the expected result to fill your function
	* with any content your compiler will complain with:
	* "redefinition of 'void Color::doSomething()'".
	*
	* This function must be used in the header file only.
	*/ 
	// void doSomething() {
	// 	cout << "working..." << endl;
	// }

	void bruh() {
		cout << "bruh" << endl;
	}
}