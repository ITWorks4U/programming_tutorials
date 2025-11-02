/*
* In contrast to C programming, which does not comes with lambda expressions,
* but those can be simulated with macros, does C++ offer to use them.
*
* Lambda expressions are similar to functions, which aren't functions.
* It allows you to handle an expression like a function without defining a function.
* In summary, lambda expressions are anonymous functions.
*
* Often used by mathematicians.
*/

#include <iostream>
#include <exception>
using namespace std;

void aNormalFunction() {
	cout << "a normal function here..." << endl;
}

int main() {
	aNormalFunction();

	// an empty lambda, which does and returns nothing; can't handle with variables
	auto empty_lambda = [](){};

	int argument = 5;
	auto lambda_with_fixed_argument = [argument](){
		return argument * argument;
	};

	auto lambda_with_dynamic_arguments = [](float a, float b) -> float {
		return a * b;
	};

	/*
	* "promise", that this lambda expression won't throw an exception
	* if an exception will be thrown here, then you lied to the compiler
	* and the application will be terminated immediately.
	*/
	auto lambda_no_exception = []() noexcept {
		return "Everything is fine.";
	};

	// when called, the application terminates immediately
	auto lambda_no_exception_liar = []() noexcept {
		throw runtime_error("Pinoccio would be jealous...");
	};


	/*
	* Old C++98 implementation. This is now marked as deprecated and has
	* the identical effect to noexcept. Even an exception is going to
	* throw here, which is handled inside the lambda expression, your
	* application, however, is still able to continue with the next
	* instruction.
	*/
	auto lambda_with_exception = []() throw() {
		try {
			logic_error e("logic_error exception has been thrown");
			throw e;
		} catch (logic_error &e) {
			cerr << e.what() << endl;
		}
	};

	// this does also not throw an exception, even when throw()
	// is given here
	auto confusing_lambda_expression = []() throw() {
		return "Everything works fine.";
	};



	// when called, the application terminates immediately
	auto lambda_05_failure_0 = []() throw() {
		try {
			throw logic_error("throw here...");
		} catch (logic_error &e) {
			cerr << e.what() << endl;

			//	hint: never add >>throw;<< here,
			//	otherwise the application will termiante immediately
			//	with a failure, even this "new thrown exception" shall
			//	be handled in an own try-catch-block
			throw;
		}
	};

	// when called, the application terminates immediately
	auto lambda_05_failure_1 = []() throw() {
		logic_error e("logic_error is going to throw here");
		throw e;
	};

	// -------------------
	// -------------------
	// -------------------

	cout <<
		"-------------" << endl <<
		"outputs" << endl <<
		"-------------" <<
	endl;

	// can't be used, because an empty lambda expression
	// is just like a void function
	// cout << empty_lambda << endl;
	// cout << empty_lambda() << endl;

	cout << "empty_lambda: <nothing, because empty_lambda does not contain anything>";
	empty_lambda();

	cout << endl << "lambda_with_fixed_argument: " << lambda_with_fixed_argument() << endl;

	cout << "lambda_with_dynamic_arguments: " << lambda_with_dynamic_arguments(0.01F, 3.0F) << endl;

	cout << "lambda_no_exception: ";
	try {
		cout << lambda_no_exception() << endl;
	} catch (exception &e) {
		cerr << e.what() << endl;
	}

	cout << "lambda_no_exception again: " << lambda_no_exception() << endl;
	// -----------------

	cout << "lambda_with_exception (with try-except)" << endl;
	try {
		lambda_with_exception();
	} catch (exception &e) {
		cerr << e.what() << endl;
	}
	// -----------------

	cout << "lambda_with_exception (without try-except) " << endl;
	lambda_with_exception();

	cout << "that causes confusion... " << confusing_lambda_expression() << endl;

	return 0;
}