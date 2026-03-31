/*
* Singleton classes can be useful to declare only
* a single instance of a class.
*
* But not every time a singleton class is useful.
* In combination with threads, clusters, inheritance there's
* no guarantee to work well with it.
*
* ============================
* Usually, it makes no sense to use a singleton class for inheritance, but it's also possible.
*
* example taken from: https://sourcemaking.com/design_patterns/singleton/cpp/2 and refreshed
* There's no guarantee, that this works well in your case.
*
* Attention: Don't use raw pointers like in the link above. Otherwise you may get an undefined behavior,
* because the destructor of your octal class might not being called.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#define OCTAL_SIZE	10

class Number {
	static string type;

	protected:
		int value;

		Number() {
			cout << "number object has been created..." << endl;
		}

	public:
		static Number *getInstance();

		/*	always remember: a virtual destructor must exist for inheritance in C++	*/
		virtual ~Number() {
			cout << "number object has been destroyed..." << endl;
		}

		static void setType(string t) {
			type = t;
		}

		virtual void setValue(int in) {
			value = in;
		}

		virtual int getValue() const {
			return value;
		}
};

class Octal: public Number {
	public:
		/*	the number class needs to be a "friend" to be able to use	*/
		friend Number;
		void setValue(int in) {

			/*	usually, this shall not be in use in C++ => undefined behavior may occour	*/

			char buf[OCTAL_SIZE];
			memset(buf, '\0', OCTAL_SIZE);
			sprintf(buf, "%o", in);
			sscanf(buf, "%d", &value);
		}
		
	protected:
		Octal() {
			cout << "octal object has been created..." << endl;
		}

		virtual ~Octal() {
			cout << "octal object has been destroyed..." << endl;
		}
};

/*
	The getInstance function of Number class needs to be outsourced,
	otherwise you can't create an instance of the Octal class.
*/
Number *Number::getInstance() {
	if (type == "octal") {
		static Octal inst;
		return &inst;
	}

	static Number inst;
	return &inst;
}

/*	"global start value"	*/
string Number::type = "decimal";

int main() {
	/*	meme:	Why is a programmer confused between christmas and halloween...?	*/
	const int memeNumber = 25;

	Number::getInstance()->setValue(memeNumber);
	cout << "decimal value is " << Number::getInstance()->getValue() << endl;

	/*	switching...	*/
	Number::setType("octal");
	Number::getInstance()->setValue(memeNumber);
	cout << "octal value is " << Number::getInstance()->getValue() << endl;
}