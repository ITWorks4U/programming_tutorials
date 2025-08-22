/*
* C++ comes with an union regex library for all
* systems. In general, this allows you to run a piece of
* code on any system.
*/

#include <iostream>
#include <regex>
#include <string>
#include <limits>
using namespace std;

bool on_match(string expression) {
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
	const string regex_expression = "^(-|\\+)?[0-9]+(,|\\.[0-9]+)?|(0x|0X)?[A-Fa-f0-9]+(H|h)?|(0b|0B)[01]+|(o|O)[0-7]+$";

	regex r(regex_expression);
	return regex_match(expression, r);
}

int main() {
	string input = "";
	cout << "Enter any number: ";
	getline(cin, input);

	//	remeber: hit 'enter' again to get cout
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	cout <<
		"Your certain expression: \"" << input << "\" " <<
		(on_match(input) ? "passed" : "failed") <<
		" trough the regular expression filter."
	<< endl;

	return 0;
}