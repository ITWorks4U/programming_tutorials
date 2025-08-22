#include <iostream>
using namespace std;

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
};

int main() {
	//	since this is an "abstract class", which should not be used from outside,
	//	this can be instanciated, as well...
	GeometricObject go;
	Circle c(5.5);
	Triangle t(3.1,9.7,0.1);

	//	calculate something...
	//	since the methods are defined in GeometricObject
	//	only, the access can be done there

	cout << ".:basic geometric object:." << endl <<
		"area: " << go.calculate_area() << endl <<
		"perimeter: " << go.calculate_perimeter()
	<< endl << endl;

	cout << ".:circle:." << endl <<
		"area: " << go.calculate_area() << endl <<
		"perimeter: " << go.calculate_perimeter()
	<< endl << endl;

	cout << ".:triangle:." << endl <<
		"area: " << go.calculate_area() << endl <<
		"perimeter: " << go.calculate_perimeter()
	<< endl << endl;

	/*
	* Surprised, that circle as well as trigangle has an area of
	* 0.0 and a perimeter of 0.0?
	*
	* Because the methods from geometric are public and those are
	* set with 0.0, every child also uses this only known reference.
	*
	* To avoid this, circle and also triangle must implement their
	* own methods. Often called: overwrite methods
	*/

	return 0;
}