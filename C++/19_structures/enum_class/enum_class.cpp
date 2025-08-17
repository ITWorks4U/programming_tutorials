/*
* In contrast to a default enum, an enum class may hold
* a state, which has been defined in an another enum class.
*
* However, an enumeration class can't be used in the direct way
* like a default enumeration block.
*/

#include <iostream>
using namespace std;

enum class StatusA {
	READY, WORK, STOPPED 
};

enum class StatusB {
	READY, RUNNING, HALTED, FAILED
};

enum Status {
	A, B, C
};

int main() {
	//	Basic access to a default enum? No!
	//	This won't work.
	// StatusA status = READY;

	//	you have to use 
	StatusA status = StatusA::READY;

	//	can't be used directly
	//	=> "How may lines of error do you want to read on console?" C++: "Yes."
	// std::cout << "status has value of: " << status << std::endl;
	// std::cout << "StatusA::READY = " << StatusA::READY << std::endl;

	//	you can just compare the status with the set of states
	switch(status) {
		case StatusA::READY:
			std::cout << "This status is ready to use." << std::endl;
			break;
		case StatusA::WORK:
			std::cout << "The status is buisy for now." << std::endl;
			break;
		case StatusA::STOPPED:
			std::cout << "The status is not running." << std::endl;
			break;
	}

	//	to iterate trough a simple enumeration, use this:
	std::initializer_list<Status> all_states = {A, B, C};
	for(Status s1 : all_states) {
		std::cout << s1 << std::endl;
	}

	return 0;
}