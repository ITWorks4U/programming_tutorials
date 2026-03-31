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

		/*
		* Luckily, the friend keyword can't be derived,
		* but it still makes your no more secure.
		*/

		friend class ForeignClass;
		friend void access_for_everyone(const BaseClass &bc);

		/*	compiler error: 'DerivedClass' does not name a type	*/
		// friend void access_for_everyone(const DerivedClass &dc);
};

class DerivedClass : public BaseClass {
	public:
		DerivedClass() {}
		DerivedClass(const BaseClass &bc) {}
		virtual ~DerivedClass() {}

		double print_protected_member() const {
			return this->protected_member;
		}

	private:
		string priv_derived;

	protected:
		string prot_derived;

		/*	...	*/
};

class ForeignClass {
	public:
		void access0(const DerivedClass &dc) {
			cout << "access0 called..." << endl;

			cout <<
				"private super class member: " << dc.private_member << endl <<
				"protected super class member: " << dc.protected_member
			<< endl;

			// By using const you don't have access to the function below.
			// dc.unable_to_display();

			/*
			* Since ForeignClass is a fried of BaseClass and
			* DerivedClass has been derived from BaseClass
			* you don't have an access to the private members...
			*/
			// cout << dc.priv_derived << endl;

			/*
			* ...but wait, you're able to access to
			* the protected members of DerivedClass, too!
			* => it doesn't make a difference, if &dc is marked
			*    with const expression in the argument list
			*
			* Luckily, only for read, but it makes not better...
			*/
			// dc.prot_derived = "aaa";
			cout << dc.protected_member << endl;
		}

		void access1(const BaseClass &bc) {
			cout << "access1 called..." << endl;

			cout <<
				"private super class member: " << bc.private_member << endl <<
				"protected super class member: " << bc.protected_member
			<< endl;

			//	without const this is also able to call
			/*bc.unable_to_display();*/

			/* cout << bc.priv_derived << endl;	*/
		}

		void access2(const BaseClass &bc) {
			cout << "access2 called..." << endl;

			DerivedClass dc(bc);
			dc.unable_to_display();
			dc.private_member = 100;

			cout <<
				"private member: " << dc.private_member << endl <<
				"the protected member from dc: " << dc.print_protected_member()
			<< endl;

			dc.protected_member = 500.0;
			cout	<< "again: the protected member from dc: " << dc.print_protected_member() << endl;
		}
};

void access_for_everyone(const BaseClass &bc) {
	cout << "access for everyone (bc)...?" << endl;

	cout << "bc.private: " << bc.private_member << endl
	<< "bc.protected: " << bc.protected_member << endl;
}

void access_for_everyone(const DerivedClass &dc) {
	cout << "access for everyone (dc)...?" << endl;

	cout << "dc.protected only: " << dc.print_protected_member() << endl;
}

int main() {
	BaseClass bc;
	// bc.~BaseClass();
	//	nothing more...

	DerivedClass dc;
	ForeignClass fc;

	cout << "main: protected value from dc: " << dc.print_protected_member() << endl;
	fc.access0(bc);
	fc.access0(dc);

	fc.access1(bc);
	fc.access1(dc);

	fc.access2(bc);
	fc.access2(dc);

	// access_for_everyone(fc);
	access_for_everyone(bc);
	access_for_everyone(dc);

	return 0;
}