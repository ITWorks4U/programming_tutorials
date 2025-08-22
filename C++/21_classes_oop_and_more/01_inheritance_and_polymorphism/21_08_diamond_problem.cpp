#include <iostream>
#include <string>
using namespace std;

/*
* A diamond problem occurs, when a child class
* inhertis from two or more base classes, where
* these classes inhertits fro an another base class.
*
* By accessing by polymorphism we have a problem, because
* we don't know, which base class is now in use here?
* On compile time you'll receive an error about "ambigius usage"
* or similar.
*
* With the keyword "virtual" for each inheritance
* we can deal with that.
*
* Other OOP languages, like Java (more for interfaces),
* C#, etc. handles the diamond problem automatically.
*/

class Base {
	public:
		virtual ~Base() {}
		virtual string identify_class() = 0;
};

//	virtual keyword is required
class Child1 : virtual public Base {
	protected:
		virtual ~Child1() {}
		virtual string identify_class() {
			return "From child 1!";
		}
};

//	public virtual can also be used
class Child2 : public virtual Base {
	protected:
		virtual ~Child2() {}
		virtual string identify_class() {
			return "From child 2!";
		}
};

class DiamondProblem : public Child1, Child2 {
	public:
		virtual ~DiamondProblem() {}
		string identify_class() {
			return "Diamond!";
		}
};

int main() {
	//	accessing by polymorphism
	Base *dp = new DiamondProblem();
	cout << dp->identify_class() << endl;
	delete dp;

	//	won't affected, because it's a direct access
	DiamondProblem dp_0;
	cout << dp_0.identify_class() << endl;

	return 0;
}