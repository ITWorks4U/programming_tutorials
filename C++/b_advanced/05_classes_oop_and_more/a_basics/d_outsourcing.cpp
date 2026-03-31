#include <iostream>
#include <string>
using namespace std;

/*
* Outsourcing methods from a class helps you to gain
* a clean overview of your class(es) and other data
* structure(s).
*
* Similar to a C-Header file the outsourced objects
* can be handled in an own source file as well.
*/

class Person {
	int person_id;
	string f_name;
	string l_name;
	string birth_date;

	public:
		//	since the constructor(s), destructor, method(s) is(are) defined
		//	as a "function prototype", the(ir) declaration(s) is(are) outside
		//	of the class
		Person();
		~Person();
		Person(string f_name, string l_name, string birth_date);
		Person(const Person &p);
		Person(Person &&p);

		void print_person_data();
};

//	outsourced overview, where the syntax might confuse you...
//	syntax: <data_type> [namespace_name::]<class_name>::<method>

//	usually, this shall be moved into an own source file instead...
Person::Person() {
	cout << "Constructing a new instance for class Person..." << endl;
}

Person::~Person() {
	cout << "Removing the instance for class Person..." << endl;
}

Person::Person(string f_name, string l_name, string birth_date) {
	cout << "parameterized constructor called..." << endl;
	this->f_name = f_name;
	this->l_name = l_name;
	this->birth_date = birth_date;
}

Person::Person(const Person &p) {
	cout << "copy constructor called..." << endl;

	this->person_id = p.person_id;
	this->f_name = p.f_name;
	this->l_name = p.l_name;
	this->birth_date = p.birth_date;
}

Person::Person(Person &&p) {
	cout << "move constructor called..." << endl;
}

void Person::print_person_data() {
	cout <<
		"Person-ID: " << person_id << endl <<
		"first name: " << f_name << endl <<
		"last name: " << l_name << endl <<
		"birth date: " << birth_date << endl
	<< endl;
}

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