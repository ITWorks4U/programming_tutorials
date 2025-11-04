#include <stdio.h>
#include <stdlib.h>

// -----------
// Debugging a code runs easy within an IDE.
// Without an IDE (terminal) use gdb
// -----------
// Linux:
// 	gdb shall be installed by default
// 	usage: gdb <application>
// Windows:
// 	use mingw to debug code outside of an IDE
// 	=> gdb.exe <your application.exe>
// -----------
// small breakdown for debugging:
//
//  ---------------|----------------------------|-----------------------------
//  command        | effect                     | additional information
//  ---------------|----------------------------|-----------------------------
//  r | run        | run your application       | shall be the last command
//  ---------------|----------------------------|-----------------------------
//  b | break      | tells the debugger, where  | this can be a function (function name),
//                 | the application shall be   | a line number in the current file,
//                 | halted                     | line number in a foreign file, ...
//                 |                            | example: b(reak) recursion_function
//  ---------------|----------------------------|-----------------------------
// s | step        | do the next step           | can go into a function, which was not marked
//                 |                            | with break => in IDE (typically) F11
//  ---------------|----------------------------|-----------------------------
// n | next        | do the next step           | runs to the next instruction or to the next break statement
//  ---------------|----------------------------|-----------------------------
// p | print       | print the current value    | the value must be named here
//  ---------------|----------------------------|-----------------------------
// q | quit        | stops the debugger         | on runtime you must confirm to leave the debugger
//  ---------------|----------------------------|-----------------------------

int recursion_function(int counter) {
	/*
	* Let's take a look to this recursion function.
	* This leaves the function only, if counter is <0, however,
	* since counter starts with 0 and this will incremented by 1,
	* this recursion will never leave (until the virtual RAM rans out of free space
	* or your PC can't longer be used => best way: restart your system and do not
	* run this this code again ;-))
	*/

	if (counter < 0) {
		return counter;
	}

	printf("counter = %d\n", counter);
	counter++;
	return recursion_function(counter);
}

int main(void) {
	printf("%d\n", recursion_function(0));
	return EXIT_SUCCESS;
}