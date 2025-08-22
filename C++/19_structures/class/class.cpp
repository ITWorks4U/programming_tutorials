/*
* C++ comes with a class structure. This is similar to
* a basic struct, but it offers more powerful features
* and settings.
*/

#include <iostream>
#include <string>
using namespace std;

enum class Status {
	READY, RUNNING, HALTED, FAILED
};

/*
* In contrast to a basic structure every member:
* - data types
* - functions => class methods
* - constant expressions
* - ...
* are set to a PRIVATE block. Those can't be accessed
* from outside. To gain access from outside, either move
* them to a PUBLIC block or create methods to read only
* the value.
*/

class Service {
	int service_id;
	string service_name;
	string service_description;
	Status service_status;

	public:
		// every instruction here is now public
		// until the next block (protected / private) appears
		// it's also no need to move all instructions into an
		// own block, but this allows you to handle that block
		// much better

		// by default no constructor or destructor is strictly
		// required => more details: take a look to chapter 21
		Service() {}
		~Service() {}

		int get_service_id() {
			return service_id;
		}

		string get_service_name() {
			return service_name;
		}

		string get_service_description() {
			return service_description;
		}

		string get_status() {
			switch(service_status) {
				case Status::READY:
					return "status is ready";
				case Status::RUNNING:
					return "status is running";
				case Status::HALTED:
					return "status is paused";
				case Status::FAILED:
					return "status failure";
				default:
					return "unknown status detected";
			}
		}
};

int main() {
	Service s;

	//	since no access to the private members is available
	//	we can only read from that members by using the public
	//	methods
	//
	//	like in C: any uninitialized member contains garbage by
	//	default and you'll see that result here
	cout <<
		s.get_service_id() << ", " << s.get_service_name() << ", " <<
		s.get_service_description() << ", " << s.get_status()
	<< endl;

	return 0;
}