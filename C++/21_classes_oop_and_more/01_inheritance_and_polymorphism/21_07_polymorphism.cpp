#include <iostream>
#include <cmath>
using namespace std;

/*
* Polymorphism allows you to use a base class to refer to an inherited
* class from the base class itself. This can often be used for
* quick access, testing, ..., but that shall not be used everywhere
* and everytime.
*
* todo list for polymorphism:
* - class <derived> : public <base>
* - the base class defines with >virtual< keyword, that this method
*   shall be used for polymorphism instead
* - the child classes must append >override< keyword behind the methods
*   to cooperate with polymorphism
* - the destructor for each base class must be declared with >virtual<
*   keyword to avoid "unexpected events" (not handled here)
*/

#include <iostream>
#include <cmath>
using namespace std;


//	used for Pi
//	usually, use M_PI from cmath or an another
//	C++ library
const double pi = 3.141;

class GeometricObject {
	protected:
		double width;
		double height;

	public:
		//	the base class has "invalid" data here
		virtual double calculate_area() { return 0.0; }
		virtual double calculate_perimeter() { return 0.0; }
};

class Circle : public GeometricObject {
	double radius;

	public:
		Circle(double radius) {
			this->radius = radius;
		}

		~Circle() {}

		double calculate_area() override {
			return pi * radius * radius;
		}

		double calculate_perimeter() override {
			return 2 * pi * radius;
		}
};

class Triangle : public GeometricObject {
	double a, b, c;

	public:
		Triangle(double a, double b, double c) {
			this->a = a;
			this->b = b;
			this->c = c;
		}

		~Triangle() {}

		double calculate_area() override {
			double s = (a + b + c) / 2.0;

			// Heron's formula => <cmath> is required here
			// remember: outside of Windows the linker needs
			// -lm, otherwise the application can't be build
			return sqrt(s * (s - a) * (s - b) * (s - c));
		}

		double calculate_perimeter() override {
			return a + b + c;
		}
};

int main() {
	//	using polymorphism...
	//	you MUST use raw pointers in that case
	//	and you also MUST release those allocated
	//	memory by your hand
	GeometricObject *go_0 = new Circle(5.5);
	cout << ".:circle:." << endl <<
		"area: " << go_0->calculate_area() << endl <<
		"perimeter: " << go_0->calculate_perimeter()
	<< endl << endl;
	delete go_0;

	GeometricObject *go_1 = new Triangle(3.1,9.7,0.1);
	cout << ".:triangle:." << endl <<
		"area: " << go_1->calculate_area() << endl <<
		"perimeter: " << go_1->calculate_perimeter()
	<< endl << endl;
	delete go_1;

	//	these operations are still available
	GeometricObject go;
	cout << ".:basic geometric object:." << endl <<
		"area: " << go.calculate_area() << endl <<
		"perimeter: " << go.calculate_perimeter()
	<< endl << endl;

	return 0;
}