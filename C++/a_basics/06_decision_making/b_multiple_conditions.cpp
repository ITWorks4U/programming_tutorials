#include <iostream>

// in use for expressions, like: and, or
#include <ciso646>
using namespace std;

int main() {
	bool statementTrue = true;
	bool statementFalse = false;
	int number = 100;

	/*
	* logical AND => &&
	* logical OR => ||
	*
	* Don't be confused with a single & or | => These are bitwise operators
	* and does not have any with the logical AND or logical OR!
	* => Take a look to part 11 for bitwise operations.
	*
	* In C++ keywords, like >and<, >or<, ... exists, but those are hardly used.
	*/

	// union of conditions:
	//   every sub condition must be true to become >true< as a result
	//   can never be >true<, because:
	//   if (true AND false AND true) is FALSE
	if (statementTrue && statementFalse && number) {
		cout << "You'll never see this text." << endl;
	}

	// independent check of sub conditions:
	//   at least one sub condition must be true to become >true> as a result
	//   if (true OR false OR true) is TRUE
	if (statementTrue || statementFalse || number) {
		cout << "You'll see that text, of course!" << endl;
	}

	// a block of condition checks
	//   if a sub condition is true, the other possible
	//   true condition checks are ignored
	if (statementTrue && number > 50) {                                // true AND true => true
		cout << "statementTrue && number > 50" << endl;
	} else if (statementTrue && number > 100) {                        // true AND false => false
		cout << "statementTrue && number > 100" << endl;
	} else if (!statementFalse && number < 200) {                      // true AND true => true
		cout << "!statementFalse && number < 200" << endl;
	} else {
		cout << "nothing of the conditions above were true..." << endl;
	}

	// What will happen here?
	// NOTE: depending on the IDE or OS you're using
	//       the keywords >and<, >or< might not be "known"
	//
	// to avoid such error, include this header file:
	//   <ciso646> => was required in older versions of C++ to work
	//   with those expressions
	if (statementTrue and statementFalse) {
		//                                                 Must be placed into brackets!
		cout << "statementTrue and statementFalse: " << (statementTrue and statementFalse) << endl;
	} else if (statementTrue or statementFalse) {
		cout << "statementTrue or statementFalse: " << (statementTrue or statementFalse) << endl;
	} else {
		cout << "What was that...?" << endl;
	}

	return 0;
}