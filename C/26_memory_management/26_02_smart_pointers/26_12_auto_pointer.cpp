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
* auto_ptr is in use to gain access to a resource by one instance only.
* In C++ 11 and higher this pointer handling has been marked as deprecated.
* It's recommended to use unique_ptr.
*
* The idea of an auto_ptr:
* Only one pointer has access to a certain resource. When a second pointer wants
* to use this resource, pointer1 moves this resource to pointer2 and pointer1
* is automatically released.
*
* On a Windows machine auto_ptr does not exist. Try to run this sample on an another OS instead.
*/

int main() {
	#ifdef _WIN32
	#warning "The type auto_ptr is unknown under Windows. Try to run this sample on an another OS."
	#else
	cout << "using auto_ptr" << endl;
	auto_ptr<Person> p0(new Person());
	p0->do_something();

	cout << "address of p0: " << p0.get() << "H" << endl;

	cout << "using a second instance here" << endl;
	auto_ptr<Person> p1(p0);

	//	since p1 is now using the memory, p0 still exist, but this is no longer in use
	//	unless p1 has been removed
	cout << "address of p1: " << p1.get() << "H" << endl;
	cout << "address of p0: " << p0.get() << "H" << endl;

	cout << "p1 is now being deleted..." << endl;
	p1.reset();

	//	now p0 is still in use here
	p0.reset();

	//	unlike to free() / delete the smart_pointers does not need
	//	to release manually; that means, even in an exception case
	//	this allocated memory is automatically removed from the
	//	system, too
	#endif

	return 0;
}

#endif