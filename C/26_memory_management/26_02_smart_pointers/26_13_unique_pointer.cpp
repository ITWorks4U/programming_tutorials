/*
* Since the behavior of an application may differ by using a C++ compiler,
* especially, when pointers are in use, C++ comes with smart pointers to
* avoid a bunch of undefined behavior. Some of those smart pointers, however,
* are now deprecated and in the future there might come new ways of smart pointers.
*/

#ifndef __cplusplus
#error "This sample is only in use for C++."
#else
#include <iostream>
#include <memory>

using namespace std;

struct Person {
	void do_something() {
		cout << "Hello there!" << endl;
	}

	Person() {
		cout << "creating new instance of person..." << endl;
	}

	~Person() {
		cout << "destroying instance of person..." << endl;
	}
};

/*
* The type unique_ptr is in use to gain access to a resource by one instance only.
* It works like auto_ptr, however, it comes with more options for us.
*/

int main() {
	unique_ptr<Person> p0(new Person());
	p0->do_something();
	cout << "address of p0: " << p0.get() << "H" << endl;
	cout << "using a second instance here" << endl;

	//	unlike to auto_ptr, if available, you need to use move(*ptr)
	unique_ptr<Person> p1 = move(p0);
	cout << "address of p1: " << p1.get() << "H" << endl;
	cout << "address of p0: " << p0.get() << "H" << endl;

	cout << "p1 is now being deleted..." << endl;
	p1.reset();

	//	don't think, that p0 now gets access back to the memory address
	//	p0 is still 0, but you can still use the function(s)
	cout << "address of p0: " << p0.get() << "H" << endl;
	p0->do_something();
	p0.reset();

	return 0;
}

#endif