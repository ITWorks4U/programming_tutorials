#include <iostream>
#include <string>
using namespace std;

/*
* There're four different types of construtors:
* - default constructor without any argument handling, where:
*   - basic constructor by compiler
*   - basic constructor by your own
* - parameterized constructor
* - copy constructor
* - move constructor
*
* When one of the last three constructors has been declared,
* the default constructor (not your declared constructor)
* does no longer exist and you can't instanciate the class.
* This can only be done by the declared constructors instead.
*/

class Person {
	int person_id;
	string f_name;
	string l_name;
	string birth_date;

	public:
		//	default constructor / destructor
		Person() {
			cout << "Constructing a new instance for class Person..." << endl;
		}

		~Person() {
			cout << "Removing the instance for class Person..." << endl;
		}

		//	parameterized construtor (destructor does not support that)
		Person(string f_name, string l_name, string birth_date) {
			cout << "parameterized constructor called..." << endl;
			//	in that case this-> must be used
			this->f_name = f_name;
			this->l_name = l_name;
			this->birth_date = birth_date;
		}

		//	copy constructor (copy the content from an already created
		//	instance to that new object)
		Person(const Person &p) {
			cout << "copy constructor called..." << endl;

			this->person_id = p.person_id;
			this->f_name = p.f_name;
			this->l_name = p.l_name;
			this->birth_date = p.birth_date;
		}

		/*
		* (taken from: https://www.geeksforgeeks.org/cpp/types-of-constructors-in-cpp/)
		* The move constructor is a recent addition to the family of constructors in C++.
		* It is like a copy constructor that constructs the object from the already existing objects.,
		* but instead of copying the object in the new memory, it makes use of move semantics to transfer
		* the ownership of the already created object to the new object without creating extra copies.
		*
		* It can be seen as stealing the resources from other objects.
		*/
		Person(Person &&p) {
			//	Based on that example from geeksforgeeks this works with
			//	raw pointers, whereas C++ should NOT handle with
			//	raw pointers!

			cout << "move constructor called..." << endl;
		}

		void print_person_data() {
			cout <<
				"Person-ID: " << person_id << endl <<
				"first name: " << f_name << endl <<
				"last name: " << l_name << endl <<
				"birth date: " << birth_date << endl
			<< endl;
		}
};

int main() {
	//	object instane, like always
	Person p0;
	p0.print_person_data();

	//	parameterized constructor
	Person p1("Bob", "Royal", "2025-01-01");
	p1.print_person_data();

	//	copy constructor
	Person p2(p1);
	p2.print_person_data();

	//	move constructor
	//	hint: since no action for the move constructor
	//	has been made, it may happen, that you don't
	//	see a plausible result or the application has
	//	been crashed...
	Person p3(move(p2));
	p3.print_person_data();

	return 0;
};