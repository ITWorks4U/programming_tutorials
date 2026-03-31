/*
* In C++ you can declare a class to be a "friend" for an another class to allow
* to gain access to protected and private members. Basicly in OOP it makes no sense
* to allow a security flaw, however, you'll learn how to use friend in C++ and to avoid
* this in the future.
*/
#include <iostream>
using namespace std;

class BaseClass {
	int private_member;
	void unable_to_display() {
		cout << "the secret password is: ..." << endl;
	}

	protected:
		double protected_member;
	
	public:
		BaseClass() {}
		virtual ~BaseClass() {}

		/*	...	*/

		//	declaration to be a "friend",
		//	where only THESE functions is able to access from outside
		friend void backdoor(BaseClass &bc);
		friend void backdoor();
};

/*
* Usually, a defined function / method in a class shall be defined with:
* <datatype> [namespace::]<class>::<method>
*
* but in that case it's a normal function outside of this class,
* whereas this function has an opened backdoor to critical areas,
* which shall not be available.
*/
void backdoor(BaseClass &bc) {
	cout <<
		"let's see the private member: " << bc.private_member << endl <<
		"What about the protected member? " << bc.protected_member
	<< endl;

	bc.unable_to_display();
}

/*	There's no need to have the BaseClass instance in the argument list	*/
void backdoor() {
	BaseClass bc;
	bc.private_member = 123456789;
	bc.protected_member = bc.private_member * 2;

	cout <<
		"private member: " << bc.private_member << endl <<
		"protected member: " << bc.protected_member
	<< endl;
}

int main() {
	BaseClass bc;
	backdoor(bc);
	backdoor();

	return 0;
}