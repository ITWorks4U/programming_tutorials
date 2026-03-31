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

		//	declaration to be a "friend" for another classes
		//	this allows all given classes to gain access to EVERYTHING
		friend class ForeignClass;
};

/*	somewhere in your project...	*/

/*
* This class has the granted access to everything for BaseClass,
* because it's a friend of BaseClass.
*/
class ForeignClass {
	public:
		void access() {
			BaseClass bc;

			/*	you're also able to modify the members, which shouldn't be able...	*/
			bc.private_member = (0x100 >> 8) & 0x1;
			bc.protected_member = 123.456;

			cout <<
				"access #1:" << endl <<
				"let's see the private member: " << bc.private_member << endl <<
				"What about the protected member? " << bc.protected_member
			<< endl;
		}

		void access(BaseClass &bc) {
			/*
			* with the argument you're also able to do the same thing;
			* by using const this allows you only to read the members
			*/

			cout <<
				"access #2:" << endl <<
				"let's see the private member: " << bc.private_member << endl <<
				"What about the protected member? " << bc.protected_member
			<< endl;

			bc.unable_to_display();
		}

		void access(const BaseClass &bc) {
			/*
			* with the argument you're also able to do the same thing;
			* by using const this allows you only to read the members
			*/

			cout <<
				"access #3:" << endl <<
				"let's see the private member: " << bc.private_member << endl <<
				"What about the protected member? " << bc.protected_member
			<< endl;

			// bc.unable_to_display();
		}
};

int main() {
	BaseClass bc;
	ForeignClass fc;
	fc.access();

	//	if the last access() method shall be used,
	//	then comment access() #2 out or add const
	//	to the parameter
	fc.access(bc);

	return 0;
}