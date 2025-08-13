/*
* Macros are (very) powerful and
* often used for C and mostly for C++, however,
* these offers you a bunch of problems, if you don't mind them.
*
* There're different ways to use macros:
* - constant expression
* - functions (Use that with care!)
* - preprocessing expression
*
* Attention:
* Macros does not have a type specification! So you can also get
* an undefined behavior or a logical error in your application!
*/

#include <stdio.h>
#include <stdlib.h>

//	macros can also be used for function operations,
//	however, missing brackets causes a wrong result
//
//	attention: a macro function can "operate" with any datatype,
//	but this also causes an undefined behavior
//	macro functions were made to run a function over and over again
//	without forcing to use a limitation of datatype(s)
#define		QUBIC_WRONG(X) (X * X * X)
#define		QUBIC_CORRECT(X) ((X) * (X) * (X))

//	a normal function as an alternative
int qubic_function(int number) {
	return number * number * number;
}

int main(void) {
	int a = 123;
	int b = 61;

	printf("wrong: (%d - %d)^3 = %d\n", a, b, QUBIC_WRONG(a-b));
	printf("correct: (%d - %d)^3 = %d\n", a, b, QUBIC_CORRECT(a-b));
	printf("by function: (%d - %d)^3 = %d\n", a, b, qubic_function(a-b));

	/*
	* Why is QUBIC_WRONG wrong? Since the brackets between X are missing,
	* any amount of multiple numbers, like a-b causes:
	* 123 - 61 * 123 - 61 * 123 - 61 => a wrong calculation due mathematical rules
	*
	* QUBIC_CORRECT: (X) forces to calculate a sub operation first, before the
	* defined operation(s) in the macro function itself triggers:
	* (123 - 61) * (123 - 61) * (123 - 61)
	*
	* qubic_function: does the same thing
	*/

	return EXIT_SUCCESS;
}