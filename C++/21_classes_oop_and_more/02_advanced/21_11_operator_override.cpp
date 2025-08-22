#include <iostream>
using namespace std;

/*
* Overriding operators allows you to define
* your own operators, e. g. arithmetic stuff,
* like addition, substraction etc.
*/

class Point {
	int x, y;

	//	a default constructor is required here
	//	usually, this is in the private block
	Point() {}

	public:
		Point(int x, int y) {
			this->x = x;
			this->y = y;
		}

		virtual ~Point() {}

		int get_x() {
			return this->x;
		}

		int get_y() {
			return this->y;
		}

		/*
		* Overriding operators starts with the keyword
		* >operator< followed by an operator sign, like
		* +, -, *, /, etc. You can also use this to
		* define a custom way for a memory allocation.
		*/
		Point operator +(Point &source) {
			Point p;
			p.x = this->x + source.x;
			p.y = this->y + source.y;

			return p;
		}

		Point operator -(Point &source) {
			Point p;
			p.x = this->x - source.x;
			p.y = this->y - source.y;

			return p;
		}
};

int main() {
	//	normal way as we already know
	Point p1(3,4);
	cout << "p1 = {" << p1.get_x() << ", " << p1.get_y() << "}" << endl;

	Point p2(10,11);
	cout << "p2 = {" << p2.get_x() << ", " << p2.get_y() << "}" << endl;

	//	using overridden operators
	//	since our class offers operator overloading, it's
	//	possible to create objects with a "+" and also a "-"
	Point p3 = p1 + p2;
	cout << "p3 = {" << p3.get_x() << ", " << p3.get_y() << "}" << endl;

	Point p4 = p1 -p2;
	cout << "p4 = {" << p4.get_x() << ", " << p4.get_y() << "}" << endl;

	return 0;
}