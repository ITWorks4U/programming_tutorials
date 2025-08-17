#include <iostream>
#include <string>

//	for regular expressions
#include <regex>
using namespace std;

/*
* When you try to read from keyboard, a file, ..., the input is ALWAYS a word.
* there're different ways to reveal a number:
* - using a primitive way (can be used, but this is not recommended)
* - using a built-in "method" (does not work for every case)
* - using a regular expression => more in chapter 21
*/

//	primitive C way
bool on_valid_number_0(string s) {
	for(size_t i = 0; i < s.length(); i++) {
		//	for any negative number
		if (i == 0 && s[i] == '-') {
			continue;
		}

		if (s[i] < '0' || s[i] > '9') {
			return false;
		}
	}

	return true;
}

//	can be used, but this does not handle
//	negative numbers
bool on_valid_number_1(string s) {
	for(size_t i = 0; i < s.length(); i++) {
		if (!isdigit(s[i])) {
			return false;
		}
	}

	return true;
}

//	can be used, too, but too complicated
//	and still doesn't handle negative numbers
bool on_valid_number_2(string s) {
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) {
		++it;
	}

	return !s.empty() && it == s.end();
}

//	using regular expression
bool on_valid_number_3(string s) {
	regex checker("^-?[0-9]+$");
	return regex_search(s, checker);
}

int main() {
	/*
	* primitive way to read
	* an integer from keyboard
	*
	* remember: EVERYTHING is a >>word<<
	*/

	int number_to_hold;
	cout << "enter something: ";

	cin >> number_to_hold;
	cout << "your number: " << number_to_hold << endl;

	/*
	* disadvantages:
	* - by mixing numbers with not numerical characters only the numbers
	*   (first detected numbers only) will return
	* -	by enter anything outside of a number range,
	*   0 only will be stored into number_to_hold
	* -	may also crash your application on runtime
	*
	* alternatives:
	* -	using a function, which checks, if the input is an integer
	* - using a regular expression
	*/

	cout << endl << "---------------------" << endl << endl;

	string number1 = "123";
	string number2 = "-99999";
	string number3 = "Hello!";
	string number4 = "123abc456";

	//	check with C style:
	bool nbr1_valid = on_valid_number_0(number1);               //	valid
	bool nbr2_valid = on_valid_number_0(number2);               //	valid
	bool nbr3_valid = on_valid_number_0(number3);               //	invalid
	bool nbr4_valid = on_valid_number_0(number4);               //	invalid

	//	by the way, a boolean expression returns 0 and 1 only
	//	0 : false
	//	1 : true

	cout << ".:using C style:." << endl << endl <<
	"number 1 is valid: " << nbr1_valid << endl <<
	"number 2 is valid: " << nbr2_valid << endl <<
	"number 3 is valid: " << nbr3_valid << endl <<
	"number 4 is valid: " << nbr4_valid << endl;

	cout << endl << "---------------------" << endl << endl;

	//	using built-in C++ check (easy way):
	nbr1_valid = on_valid_number_2(number1);                    //	valid
	nbr2_valid = on_valid_number_2(number2);                    //	invalid... Surprised?
	nbr3_valid = on_valid_number_2(number3);                    //	invalid
	nbr4_valid = on_valid_number_2(number4);                    //	invalid

	cout << ".:using built-in C++ check (easy check):." << endl << endl <<
	"number 1 is valid: " << nbr1_valid << endl <<
	"number 2 is valid: " << nbr2_valid << endl <<
	"number 3 is valid: " << nbr3_valid << endl <<
	"number 4 is valid: " << nbr4_valid << endl;

	cout << endl << "---------------------" << endl << endl;

	//	using built-in C++ check (extended way):
	nbr1_valid = on_valid_number_2(number1);                    //	valid
	nbr2_valid = on_valid_number_2(number2);                    //	invalid... Still surprised?
	nbr3_valid = on_valid_number_2(number3);                    //	invalid
	nbr4_valid = on_valid_number_2(number4);                    //	invalid

	cout << ".:using built-in C++ check (extended way):." << endl << endl <<
	"number 1 is valid: " << nbr1_valid << endl <<
	"number 2 is valid: " << nbr2_valid << endl <<
	"number 3 is valid: " << nbr3_valid << endl <<
	"number 4 is valid: " << nbr4_valid << endl;

	cout << endl << "---------------------" << endl << endl;

	//	using regex (C++ only):
	nbr1_valid = on_valid_number_3(number1);                    //	valid
	nbr2_valid = on_valid_number_3(number2);                    //	valid
	nbr3_valid = on_valid_number_3(number3);                    //	invalid
	nbr4_valid = on_valid_number_3(number4);                    //	invalid

	cout << ".:using C++ regex:." << endl << endl <<
	"number 1 is valid: " << nbr1_valid << endl <<
	"number 2 is valid: " << nbr2_valid << endl <<
	"number 3 is valid: " << nbr3_valid << endl <<
	"number 4 is valid: " << nbr4_valid << endl;

	return 0;
}