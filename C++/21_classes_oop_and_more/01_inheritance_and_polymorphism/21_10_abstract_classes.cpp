#include <iostream>
using namespace std;

/*
* Abstract classes, also known as interfaces (C++ only),
* allows you to define a common class, where the child
* class(es) only are implementing the functionality
* of code.
*
* Every child class, which inherits from the abstract class/
* interface, MUST implement all methods. It's like
* a contract.
*
* Since an abstract class / interface class has been defined,
* it can't be instanziated.
*
* An interface is often defined as I<ClassName>, where "I"
* represents an interface.
*
* When is a class defined as an abstract class / interface?
* - define a method with >virtual< keyword, followed by = 0;
*/

const double pi = 3.141;

class IGeometricObject {
	public:
		virtual double calculate_area() = 0;
		virtual double calculate_perimeter() = 0;
		virtual ~IGeometricObject() {}
};

class Circle : public IGeometricObject {
	double radius = 0.0;

	public:
		Circle(double radius) {
			this->radius = radius;
		}

		double calculate_area() {
			return pi * this->radius * this->radius;
		}

		double calculate_perimeter() {
			return 2 * pi * this->radius;
		}
};

int main() {
	//	unable to create an object of the base class
	// IGeometricObject go;

	Circle c(3.5);
	cout << "{" << c.calculate_area() << ", " << c.calculate_perimeter() << "}" << endl;

	//	However, a polymorphism is still possible here.
	IGeometricObject *go = new Circle(7.53);
	cout << "{" << go->calculate_area() << ", " << go->calculate_perimeter() << "}" << endl;
	delete go;

	return 0;
}