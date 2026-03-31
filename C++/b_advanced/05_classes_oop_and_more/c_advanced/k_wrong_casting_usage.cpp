/*
* Using a C++ casting in combination for a polymorphism
* >>can<< be used, however, make sure you know what you
* do, otherwise this logic error causes a runtime error or worse.
*/

#include <iostream>
using namespace std;

const double pi = 3.141;

class GeometricObject {
	public:
		virtual double calculate_area() = 0;
		virtual double calculate_perimeter() = 0;
		virtual ~GeometricObject() { cout << "Destructor" << endl; }
};

class Circle : public GeometricObject {
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
	Circle c(1.03);
	cout << "{" << c.calculate_area() << ", " << c.calculate_perimeter() << "}" << endl;

	//	Typically, a polymorphism can be used by this way:
	GeometricObject *go = new Circle(1.56789);
	cout << "{" << go->calculate_area() << ", " << go->calculate_perimeter() << "}" << endl;
	delete go;

	//------------------------------
	//	You can also use this in that way:
	//------------------------------
	// GeometricObject *go2 = dynamic_cast<Circle *>(&c);
	/*
	* ...however, this is a huge mistake, because you're forced to mix
	* an object instance from the stack with an instance from the heap,
	* thus, two object refernces points to one object on the same time.
	*
	* Since this object does no longer exist, the other pointer reference
	* is also vanished.
	*/

	// try to figure out, what may happen here:
	// delete go2;

	/*
	* WITHOUT deleting go2 we >>might<< fix that problem, however,
	* a memory leak will occur...
	*/

	//------------------------------
	//	this also works, however, you might also cause a runtime error:
	//------------------------------
	// Circle *c2 = dynamic_cast<Circle *>(go);
	// cout << "{" << c2->calculate_area() << ", " << c2->calculate_perimeter() << "}" << endl;
	
	//------------------------------
	//	So, what happens, when both objects are no longer in use and are removed by delete?
	// delete c2;
	// delete go;

	return 0;
}