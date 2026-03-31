/*
* shared_ptr is in use to gain access by 2,3,...n more instances, which
* accessing on the same memory address. It's similar to a raw pointer
* usage, however, these pointers are going to release automatically,
* when these are out of scope, e. g. before application termination.
*
* You're also welcome to release an certain pointer by your own by
* using reset(). => this pointer can STILL be used, however, it
* has no longer a reference to an address.
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

int main() {
	cout << "---------------------" << endl;
	cout << "1st instance:" << endl;
	shared_ptr<Person> p0(new Person());
	p0->do_something();
	cout << "address of p0 " << p0.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "2st instance:" << endl;
	shared_ptr<Person> p1(p0);

	// Since shared_ptr also comes with move(p0), the result, however,
	// will be different in contrast to the normal usage.

	cout << "address of p0 " << p0.get() << "H" << endl;
	cout << "address of p1 " << p1.get() << "H" << endl;

	cout << "---------------------" << endl;
	cout << "deleting p1 instance:" << endl;
	p1.reset();

	cout << "---------------------" << endl;
	cout << "deleting p0 instance:" << endl;
	p0.reset();

	// There's no need to delete your Person instance, because
	// this has been released automatically.

	// ----------------------------------
	// in comparison with raw pointers
	// ----------------------------------
	cout << "---------------------" << endl <<
	"in comparison with raw pointers" << endl <<
	"---------------------" << endl;
	Person *p2 = new Person();
	p2->do_something();

	Person *p3 = p2;
	p3->do_something();

	cout << "address of p2 " << p2 << "H" << endl;
	cout << "address of p3 " << p3 << "H" << endl;

	// Since p3 is going to delete, p2 is also affected
	// and these pointers STILL points to the memory address!
	delete p3;

	// not required, but often recommended
	p3 = nullptr;
	p2 = nullptr;
	p1 = nullptr;
	p0 = nullptr;

	return 0;
}
#endif