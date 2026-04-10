/*
* C++ comes with an union regex library for all
* systems. In general, this allows you to run a piece of
* code on any system.
*/

#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <vector>
using namespace std;

/*
* allows the following inputs:
*
* any decimal number: optionally starting with a -/+ sign
* this could be an integer or floating point number
* -OR-
* any hexadecimal number: starting with 0x or 0X optionally,
* followed by A-F, a-f, 0-9 and optionally with the letter H or h at the end
* -OR-
* any binary number: starting with 0b or 0B, followed by 0 or 1 1 - n times
* -OR-
* any octal number: starting with o or O, followed by a character between 0-7 1 - n times
*/
bool on_match(string expression) {
	//                                signed decimal or floating point or exponential | hexadecimal number       | binary     | octal
	const string regex_expression = "^(-|\\+)?[0-9]+((,|\\.[0-9]+)|((e|E))(-)?[0-9]+)?|(0x|0X)?[A-Fa-f0-9]+(H|h)?|(0b|0B)[01]+|(o|O)[0-7]+$";

	regex r(regex_expression);
	return regex_match(expression, r);
}

int main() {
	// use a vector of expressions
	cout << endl << endl;

	//                                 fail     | pass   |    fail   |    pass    |   pass  |   fail  |    pass     |   pass
	vector<string> expressions = {"Hello World!", "Affe", "epic fail", "0B1001001", "-123e9", "123abc", "0123456789", "0x123abc"};

	for(string s : expressions) {
		cout << (on_match(s) ? "passed" : "failed") << ": \"" << s << "\": " << endl;
	}

	return 0;
}