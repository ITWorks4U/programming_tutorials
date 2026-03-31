/*
* You always used a namespace, like std.
* This comes with a bunch of classes, other data structures,
* functions, templates, constants, ...
*
* Furthermore a namespace can also be "defined" in other
* libaries, where that namespace is going to extend, e. g.:
* <iostream>
* <string>
* <exception>
* <stdexcept>
* ...
*
* Those libraries above contains the namespace to work with.
* There are different ways to use a specific piece of code
* from std or any other namespace, like:
*
* |-----------------------|-----------------------------|
* |  what you want        |  code behind                |
* |-----------------------|-----------------------------|
* | anything from std     | using namespace std;        |
* |-----------------------|-----------------------------|
* | specific from std     | std::cout, std::string      |
* |-----------------------|-----------------------------|
* | define an alias       | using String = std::string; |
* |-----------------------|-----------------------------|
*/

#include <iostream>
#include <string>

// allow to use anything from std from
// iostream and string only
using namespace std;

// alternative way (doesn't throw an error)
// define String as an alias of std::string
using String = std::string;

// however, this below won't work
// using out = std::cout;

int main() {
	// alias...
	String s = "Hello World!";

	// from std
	cout << s << endl;

	return 0;
}