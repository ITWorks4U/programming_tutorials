/*
* A virtual destructor, especially for inheritance / polymorphism is
* recommended or in some cases strictly required, otherwise you can't
* ensure, that an object instance will be removed from memory, even
* this shall do.
*
* If you don't define and declare a virtual destructor in YOUR base class(es),
* every derived class from that base class can't be removed from memory and
* causes memory leaks.
*
* If you build your application with -Wall flag, then you'll see, what you haven't seen before.
*/

#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.141;

class GeometricObject {
	protected:
		double width;
		double height;

	public:
		//	since GeometricObject is now an abstract class,
		//	an instance is unable
		virtual double calculate_area() = 0;
		virtual double calculate_perimeter() = 0;

		//	make sure, that you have at least
		//	a virtual destructor in your base 
		//	class
		virtual ~GeometricObject() {}
};

class Circle : public GeometricObject {
	double radius;

	public:
		Circle(double radius) {
			cout << "constructing circle..." << endl;
			this->radius = radius;
		}

		~Circle() {
			cout << "circle is going to destroy..." << endl;
		}

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
			cout << "constructing triangle..." << endl;

			this->a = a;
			this->b = b;
			this->c = c;
		}

		~Triangle() {
			cout << "triangle is going to destroy..." << endl;
		}

		double calculate_area() override {
			double s = (a + b + c) / 2.0;
			return sqrt(s * (s - a) * (s - b) * (s - c));
		}

		double calculate_perimeter() override {
			return a + b + c;
		}
};

int main() {
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

	return 0;
}