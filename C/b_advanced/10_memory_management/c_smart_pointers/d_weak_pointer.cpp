/*
* weak_ptr are in use, when an instance may use the resource by its own.
* It's similar to a thread, which uses this critical resource, whereas
* each other thread must not use it as well at the same time.
* Since it's similar to a thread, it's not the same!
*
* When a weak_ptr is in use, you're unable to call methods from
* Person structure, as well as, getting the address of this object.
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
	weak_ptr<Person> p1(p0);
	cout << "address of p0 " << p0.get() << "H" << endl;

	/*	won't work for a weak_ptr	*/
	//cout << "address of p1 " << p1.get() << "H" << endl;
	// p1->do_something();
	// p1.do_something();

	/*
	* trying to use an instance, which is planned to use
	* the resource by its own => p1 comes with a function lock()
	* => on success, p2 is now able to use this resource
	*
	* What about p0? Since p0 is a shared_ptr, it also has
	* access to the certain memory address.
	*/
	cout << "---------------------" << endl;
	cout << "3rd instance:" << endl;
	if (shared_ptr<Person> p2 = p1.lock()) {
		cout << "locking active..." << endl;
		cout << "p0..." << p0.get() << "H" << endl;
		cout << "p2..." << p2.get() << "H" << endl;
		cout << "# of instances: " << p2.use_count() << endl;
	} else {
		cout << "unable to block the resource for p2 at the moment..." << endl;
	}

	cout << "---------------------" << endl;
	cout << "deleting p1 instance:" << endl;
	p1.reset();

	cout << "---------------------" << endl;
	cout << "try again..." << endl;
	cout << "---------------------" << endl;
	if (shared_ptr<Person> p2 = p1.lock()) {
		cout << "locking active..." << endl;
		cout << "p0..." << p0.get() << "H" << endl;
		cout << "p2..." << p2.get() << "H" << endl;
		cout << "# of instances: " << p2.use_count() << endl;
	} else {
		cout << "unable to block the resource for p2 at the moment..." << endl;
	}

	cout << "---------------------" << endl;
	cout << "deleting p0 instance:" << endl;
	p0.reset();

	// There's no need to delete your Person instance, because
	// this has been released automatically.

	return 0;
}
#endif