/*
* Every programming comes with an option for bit operations.
* Bit operations allows you to handle operations faster.
*/

#include <iostream>

// required to use "and", "bitand", ... correctly
#include <ciso646>
using namespace std;

int main() {
	/*
	* size of an integer value: 4 bytes
	* maximum number of an integer value (in C):      2,147,483,647
	* binary representation:	11111111 11111111 11111111 11111111
	*
	* What operators are in use?
	* & => bitwise and
	* | => bitwise or
	* ~ => bitwise not
	* ^ => bitwise xor
	*
	* You can also use expressions, like bitand, bitor, xor, compl, but
	* those are hardly used and those does not often result the identical
	* result, because you must combine those with additional brackets.
	* Furthermore your brackets must be placed correctly, otherwise the
	* result(s) is(are) difficult to the expected result!
	*
	* Don't mix bitwise and or bitwise or with && or ||, because these are logical operators.
	* Don't also mix expressions, like "and", "or", "not" => Those are also logical operators!
	*/

	// 00000000 00101010
	int a = 42;
	// 00100011 00101001
	int b = 9001;

	// a AND b => 40;
	//            must be placed in brackets
	cout << "a & b: " << (a & b) << endl;
	cout << "a bitand b: " << (a bitand b) << endl;

	// a OR b => 9003
	cout << "a | b: " << (a | b) << endl;
	cout << "a bitor b: " << (a bitor b) << endl;

	// a XOR b => 8963
	cout << "a ^ b: " << (a ^ b) << endl;
	cout << "a xor b: " << (a xor b) << endl;

	// NOT a => -43
	cout << " ~a & b: " << (~a) << endl;
	cout << "compl a: " << (compl a) << endl;

	// NOT a AND b => 8961
	cout << "~a & b: " << (~a & b) << endl;
	cout << "((compl a) bitand b): " << ((compl a) bitand b) << endl;

	// NOT (a AND b) => NAND(a, b) => -41
	cout << "~(a & b): " << ~(a & b) << endl;
	cout << "(compl (a bitand b)): " << (compl (a bitand b)) << endl;

	// NOT (a AND NOT b) => NOT a OR b => -3
	cout << "~a & ~b: " << (~a & ~b) << endl;
	cout << "compl a bitand compl b: " << ((compl a) bitand (compl b)) << endl;

	// NOT a OR b => NOR(a, b) => -9004
	cout << "~(a | b): " << ~(a | b) << endl;
	cout << "(compl (a bitor b)): " << (compl (a bitor b)) << endl;

	// NOT a XOR b => NXOR(a, b) => -8964
	cout << "~(a ^ b): " << ~(a ^ b) << endl;
	cout << "((compl a) xor b): " << ((compl a) xor b) << endl;

	return 0;
}