#include <iostream>
#include <string>
using namespace std;

/*
* In C++ a class is amost similar to a struct or union,
* which comes with additional security settings.
*
* While union and struct members are public by default,
* everything in a class is private. To set / chance
* this access modifications, you can write
* public, private or protected.
*
* private:
* - accessing to members / methods can only be done
*   inside of the class
*   => even derived classes has no access
* - no access from outside
*
* protected:
* - accessing to members / methods can be done inside
*   of the class, as well as, for derived classes
* - no access from outside
*
* public:
* - accessing to members / methods from everywhere
*
* A struct or union allows you to initialize up to one
* member, whereas a class has not this limit.
*
* Like in C:
* using any member of a structure / union / class, on runtime
* you'll see garbage
*/

class Person {
	//	private access by default
	int person_id;
	string f_name;
	string l_name;
	string birth_date;
};

int main() {
	//	object instane, like always
	//	by the way, if no constructor of a class has been defined,
	//	a default constructor and destructor will be used instead
	Person p;

	//	You can't do this.
	//cout << p.person_id << ", " << p.f_name << endl;

	return 0;
};