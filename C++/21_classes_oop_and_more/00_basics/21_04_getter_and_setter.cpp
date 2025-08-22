#include <iostream>
#include <string>
using namespace std;

/*
* Since the members are private, like always, those can't
* be accessed or modified from outside. Unless the getter
* and setter methods exists.
*/

class Person {
	int person_id;
	string f_name;
	string l_name;
	string birth_date;

	public:
		~Person();
		Person(string f_name, string l_name, string birth_date);
		void print_person_data();

		string get_first_name();
		void set_first_name(string f_name);

		string get_last_name();
		void update_last_name(string l_name);

		//	...
};

//	outsourced...
Person::~Person() {}

Person::Person(string f_name, string l_name, string birth_date) {
	this->person_id++;
	this->f_name = f_name;
	this->l_name = l_name;
	this->birth_date = birth_date;
}

void Person::print_person_data() {
	cout <<
		"Person-ID: " << person_id << endl <<
		"first name: " << f_name << endl <<
		"last name: " << l_name << endl <<
		"birth date: " << birth_date << endl
	<< endl;
}

string Person::get_first_name() {
	return f_name;
}

void Person::set_first_name(string f_name) {
	this->f_name = f_name;
}

string Person::get_last_name() {
	return l_name;
}

void Person::update_last_name(string l_name) {
	this->l_name = l_name;
}

int main() {
	Person p("Bob", "Royal", "2025-01-01");
	p.print_person_data();

	//	get and update data...
	cout << "f_name... " << p.get_first_name() << endl;
	cout << "l_name... " << p.get_last_name() << endl << endl;

	p.set_first_name("Alice");
	p.update_last_name("Cooper");
	p.print_person_data();
	return 0;
};