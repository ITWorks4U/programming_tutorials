#include <iostream>
using namespace std;

/*
* Inside a class a bunch of logic errors may appear, e. g.
* using an argument not as read only, modifying a member, which shaouldn't, etc.
* Therefore you can cause an error on runtime and it's (very) hard to find and solve the problem.
*
* There're two types of calling (a function, constructor, ...):
* calling by value:
* - we don't care where the object has been
*   stored on the memory, because we only want the value itself
* calling by reference:
* - we also need a reference, >>where<< the object
* is stored on the memory to use this object
*
* making arguments as read only: const
* Without const expression in combination with reference objetcs
* the source argument can be used for reading, as well as,
* for writing / modifying and this causes... *drumroll* undefined behavior(s)!
*
*/

class Point {
	int x, y;
	Point() {}

	public:
		// basicly, it's not required to define x and y arguments as read only,
		// because calling by value doesn't need that, unless you really want this
		Point(int x, int y) {
			this->x = x;
			this->y = y;
		}

		// Since a copy constructor is in use, it's
		// recommended to mark the source as read only,
		// otherwise the source is able to modify!
		Point(const Point &copy) {
			this->x = copy.x;
			this->y = copy.y;
		}

		virtual ~Point() {}

		// Members shall also be marked as read only with const expression (behind the method).
		// In that case we "promise" not to modify the members on runtime, otherwise the compiler
		// refuses to build the application.
		int getX() const {

			// try to use this below...
			// return this->++x;

			return this->x;
		}

		int getY() const {
			return this->y;
		}

		Point operator +(const Point &source) {
			Point p;
			p.x = this->x + source.x;
			p.y = this->y + source.y;

			return p;
		}

		Point operator -(const Point &source) {
			Point p;
			p.x = this->x - source.x;
			p.y = this->y - source.y;

			return p;
		}
};

int main() {
	Point p1(3,4);
	cout << "p1 = {" << p1.getX() << ", " << p1.getY() << "}" << endl;

	Point p2(10,11);
	cout << "p2 = {" << p2.getX() << ", " << p2.getY() << "}" << endl;

	Point p3 = p1 + p2;
	cout << "p3 = {" << p3.getX() << ", " << p3.getY() << "}" << endl;

	Point p4 = p1 -p2;
	cout << "p4 = {" << p4.getX() << ", " << p4.getY() << "}" << endl;

	Point p5(p2);
	cout << "p5 = {" << p5.getX() << ", " << p5.getY() << "}" << endl;

	return 0;
}