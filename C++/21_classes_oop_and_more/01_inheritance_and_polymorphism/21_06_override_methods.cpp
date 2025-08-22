#include <iostream>
#include <cmath>
using namespace std;

/*
* Since the access to the methods calculate_area() and calculate_perimeter
* was only possible from GeometricObject itself, it was not possible to
* calculate the correct values for each derived class, like a circle,
* triangle, ...
*
* In that case those methods must be overridden by the derived classes.
* Usually, the base methods (GeometricObject) shall be marked with
* >virtual< keyword to mark them as "ah, those shall be able to override..."
* This may be required, if an access to a base attribute shall be used with
* an own value and not by using the base value instead.
*/

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
		double calculate_area() { return 0.0; }
		double calculate_perimeter() { return 0.0; }
};

class Circle : GeometricObject {
	double radius;

	public:
		Circle(double radius) {
			this->radius = radius;
		}

		~Circle() {}

		double calculate_area() {
			return pi * radius * radius;
		}

		double calculate_perimeter() {
			return 2 * pi * radius;
		}
};

class Triangle : GeometricObject {
	double a, b, c;

	public:
		Triangle(double a, double b, double c) {
			this->a = a;
			this->b = b;
			this->c = c;
		}

		~Triangle() {}

		double calculate_area() {
			double s = (a + b + c) / 2.0;

			// Heron's formula => <cmath> is required here
			// remember: outside of Windows the linker needs
			// -lm, otherwise the application can't be build
			return sqrt(s * (s - a) * (s - b) * (s - c));
		}

		double calculate_perimeter() {
			return a + b + c;
		}
};

int main() {
	//	since this is an "abstract class", which should not be used from outside,
	//	this can be instanciated, as well...
	GeometricObject go;
	Circle c(5.5);
	Triangle t(3.1,9.7,0.1);

	//	calculate something...
	cout << ".:basic geometric object:." << endl <<
		"area: " << go.calculate_area() << endl <<
		"perimeter: " << go.calculate_perimeter()
	<< endl << endl;

	cout << ".:circle:." << endl <<
		"area: " << c.calculate_area() << endl <<
		"perimeter: " << c.calculate_perimeter()
	<< endl << endl;

	cout << ".:triangle:." << endl <<
		"area: " << t.calculate_area() << endl <<
		"perimeter: " << t.calculate_perimeter()
	<< endl << endl;

	return 0;
}