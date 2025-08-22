/*
* Singleton classes can be useful to declare only
* a single instance of a class.
*
* But not every time a singleton class is useful.
* In combination with threads, clusters, inheritance there's
* no guarantee to work well with it.
*/
#include <iostream>
#include <string>
using namespace std;

class Singleton {
	// a singleton class shall have only a basic private constructor
	Singleton() {
		cout << "creating the singleton class..." << endl;
	}

	string tmp;

	public:
		/*
		* To get an instance of the class a linked reference attempt is required.
		* Since a function / method is marked with '*' it's0 NOT a pointer!
		* The keyword 'static' helps us to create a single instance of the class during runtime.
		*
		* It doesn't matter how often "getInstance()" has been called.
		* The first call only creates the instance once.
		*/
		static Singleton *getInstance() {
			cout << "getting instance of the class..." << endl;

			static Singleton itself;
			return &itself;
		}

		/*
		* It makes no sense to create other constructors, like this...
		* Of course you CAN do this, however, your concept of a singleton class does no longer exist.
		*/
		Singleton(string s0) {
			//	...
		}

		// a destructor is optional, but it helps you often out
		virtual ~Singleton() {
			cout << "destroying singleton instance..." << endl;
		}

		/*	functions for the singleton class...	*/
		void meme() {
			cout << "This function goes brrrrrrrr." << endl;
		}

		void update_temp(string tmp) {
			this->tmp = tmp;
		}

		string get_temp() const {
			return this->tmp;
		}
};

int main() {
	/*
	* Since a singleton class is going to use, you can't create
	* a single instance by the normal known way, because the basic
	* constructor is private.
	*/
	// Singleton s0;

	// creating only 1 instance of the singleton class; no matter how often you'll do this
	Singleton *s0 = Singleton::getInstance();
	Singleton *s1 = Singleton::getInstance();
	
	// since s0 and s1 are pointers, we can take a look where on
	// runtime the instance has been stored on the memory
	cout << "location of s0... " << s0 << "H" << endl;
	cout << "location of s1... " << s1 << "H" << endl;

	s0->meme();
	s0->update_temp("This is a singleton example.");
	cout << s0->get_temp() << endl;

	s1->meme();
	s1->update_temp("This is a singleton example #2.");
	cout << s1->get_temp() << endl;

	/*
	* However, s0 and s1 are NOT dynamic pointers, thus the delete attempt causes crashes on runtime.
	* When the scope of s0, s1, ... ends, the destructor of the singleton is going to call automatically.
	*/
	// delete s1;
	// delete s0;

	/*
	* It's also possible to create, if given, an another instance of the singleton class, however,
	* at this time your singleton class doesn't exist in that context anymore.
	*/
	Singleton s3("aaaa");

	/*
	* Unlike to s0 and s1, s3 must be marked with '&' to get the address of this object.
	* In contrast to s0 and s1, 's3' also has an another address on runtime.
	*/
	cout << "Where s3 has been located on runtime... " << &s3 << "H" << endl;
	cout << "still the address of the singleton reference... " << s3.getInstance() << "H" << endl;

	s3.update_temp("fffffff");
	cout << s3.get_temp() << endl;

	return 0;
}