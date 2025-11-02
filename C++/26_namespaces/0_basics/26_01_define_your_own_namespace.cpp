/*
* To define your own namespace start with:
* namespace [name] {
*  // whatever you want here
* }
*
* then you can use using namespace [name];
*/

#include <iostream>
#include <string>

namespace custom_namespace {
	// allows you to use String instead of std::string,
	// as well as, the class Person
	using String = std::string;

	struct Person {
		int person_id;
		String f_name;
		String l_name;
		String birth_date;
	};
}

int main() {
	// This won't work, because Person is in an own
	// namespace, which hasn't been used before.
	// Person p;

	/*
	* different ways to use Person:
	*
	* (1) custom_namespace::Person p;
	* (2) using Person = custom_namespace::Person;
	*     Person p;
	* (3) using namespace custom_namespace;
	*/

	using Person = custom_namespace::Person;
	Person p;
	p.person_id = 1;
	p.f_name = "Bob";
	p.l_name = "Royal";
	p.birth_date = "2025-01-01";

	std::cout << p.person_id << ", " << p.f_name << ", " << p.l_name << ", " << p.birth_date << std::endl;

	custom_namespace::String s = "Hello from the custom namespace!";
	std::cout << s << std::endl;

	return 0;
}