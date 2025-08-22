#include <iostream>
#include "ColorBottle.hpp"
#include "DrinkBottle.hpp"
using namespace std;

/*
* Be careful:
* You can also implement both namespaces by
* "using namespace <name>;", however,
* when you omit the namespace in front of your class,
* then the compiler won't build your program, because
* the message "Bottle is ambigious." will return.
*
* using namespace Color;
* using namespace Drink;
*
* int main() {
*	// error, because the compiler doesn't know
* 	// which bottle shall be used here
*
* 	Bottle b;
* 	b.fillBottle();
* 	b.drinkFromBottle();
*
* 	return 0;
* }
*/

int main() {
	Color::Bottle b;
	b.fillBottle();
	b.drinkFromBottle();

	Color::doSomething();
	Color::bruh();
	cout << "a = " << Color::a << endl;

	Drink::Bottle d;
	d.fillBottle();
	d.drinkFromBottle();

	return 0;
}