#include <iostream>
using namespace std;

/*
* Not everytime a public inheritance can be done here.
* C++ also offers you to use a protected as well as a
* private inheritance, whereas the usages are different
* to a "default" public inheritance.
*/

class Coordinates {
	public:
		int x = 1;
	protected:
		int y = 2;
	private:
		int z = 3;

	public:
		Coordinates() {}
		virtual ~Coordinates() {}

		int get_y() {
			return this->y;
		}

		int get_z() {
			return this->z;
		}
};

class Point0 : public Coordinates {
	public:
		int get_y() {
			return this->y;
		}

		int get_x() {
			return this->x;
		}
};

class Point1 : protected Coordinates {
	public:
		int get_y() {
			return this->y;
		}

		int get_x() {
			return this->x;
		}
};

class Point2 : private Coordinates {
	public:
		int get_y() {
			return this->y;
		}

		int get_x() {
			return this->x;
		}
};

int main() {
	Point0 p0;

	//	works
	cout << "{" << p0.x << ", " << p0.get_y() << ", " << p0.get_z() << "}" << endl;
	//	works, too
	cout << "{" << p0.get_x() << ", " << p0.get_y() << ", " << p0.get_z() << "}" << endl;


	//	get_z() can't be accessed here, even get_z() is public in Coordinates class
	Point1 p1;
	cout << "{" << p1.get_x() << ", " << p1.get_y() << ", " << /*p1.get_z()*/ "???" << "}" << endl;

	Point2 p2;
	cout << "{" << p2.get_x() << ", " << p2.get_y() << ", " << /*p2.get_z()*/ "???" << "}" << endl;

	/*
	* What about polymorphism?
	*
	* private:     no polymorphism
	* protected:   no polymorphism
	* public:      default polymorphism
	*
	* get_y() only, if Coordinates offers get_y() as public
	*/

	Coordinates *c = new Point0();
	cout << "{" << c->x << ", " << c->get_y() << ", " << c->get_z() << "}" << endl;
	delete c;

	return 0;
}