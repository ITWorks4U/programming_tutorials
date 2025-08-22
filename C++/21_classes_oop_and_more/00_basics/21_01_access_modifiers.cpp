#include <iostream>
#include <string>
using namespace std;

class Person {
	//	private access by default
	int person_id;
	string f_name;
	string l_name;
	string birth_date;

	public:
		//	everything since here is public

		//	constructor => can be used to instanciate
		//	our members
		Person() {
			cout << "Constructing a new instance for class Person..." << endl;
		}

		//	destructor => can be used to release
		//	allocated memory => Use such with care!
		~Person() {
			cout << "Removing the instance for class Person..." << endl;
		}

		//	since the members are private, we need to find a way
		//	to read the members instead
		void print_person_data() {
			cout <<
				"Person-ID: " << person_id << endl <<
				"first name: " << f_name << endl <<
				"last name :" << l_name << endl <<
				"birth date :" << birth_date << endl
			<< endl;

			//	sometime you'll see this instead:
			//	this->person_id, this->f_name, ...
			//	can be used as well
		}
};

int main() {
	//	object instane, like always
	//
	//	By defining an own constructor / destructor, the default
	//	construtor / destructor will be replaced with them.
	Person p;

	//	You still can't do this.
	//cout << p.person_id << ", " << p.f_name << endl;

	p.print_person_data();

	return 0;
};