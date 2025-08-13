/*
* Enumerations are a set of integers from 0 to n-1, whereas each number
* represents an expression.
*
* --------------------------------
* important mentions:
* --------------------------------
* - an enumeration MUST NOT contain a duplicate expression, 
*   whereas multiple enumerations must also not contain at
*   least one duplicate element
* - an enumeration must contain at least one element
*   => those must not be empty
* - C++ can also handle C-enumerations with the same behavior,
*   however, C++ also introduced enum-classes to be able to
*   define an element(s), which is (are) already defined in
*   an another enum-class
* --------------------------------
*
* Every expression can also be set with a given start value.
*
*/

#include <stdio.h>
#include <stdlib.h>

//	error in C and C++
//	in an IDE this might not be shown as an error
// enum Empty {};

enum Status {
	OK, DEBUG, INFO, WARNING, ERROR, NOTHING 
};

//	WARNING is already defined in Status.
//	'lt' is an acronym expression for 'LogType' 
enum LogType {
	LOG_DEBUG = 100, LOG_INFO, /*WARNING,*/ LOG_WARNING
} lt;

//	defining an own datatype by using 'typedef'
typedef enum {
	ON, OFF
}ToggleSwitch;

int main(void) {
	/*	accessing to enumerations	*/

	//	-----------
	//	Status
	//	-----------
	enum Status status = OK;

	//	Surprised? Since "OK" is the first value, 0 is automatically set
	printf("status = %d\n", status);

	/*
	* Since this source code contains to work with enumerations, which are valid
	* in C, but not in C++, a C++ - compiler may not build this application.
	*
	* "s++" or "lt--" can't be used correctly
	* "error: no 'operator++(int)' declared for postfix '++' [-fpermissive]""
	*
	* In that case by using a C++ compiler this code snippet is skipped.
	*/
	#ifndef __cplusplus
	for(enum Status s = OK; s <= NOTHING; s++) {
		printf("%d\n", s);
	}

	for(lt = LOG_WARNING; lt >= LOG_DEBUG; lt--) {
		printf("%d\n", lt);
	}
	#endif


	//	-----------
	//	custom data type
	//	-----------
	ToggleSwitch ts = ON;
	if (ts == ON) {
		puts("ToggleSwitch is ON!");
	} else {
		puts("ToggleSwitch is OFF!");
	}

	//	-----------
	//	Different amount of bytes? No!
	//	-----------
	size_t size_status = sizeof(enum Status);
	size_t size_log_type = sizeof(lt);
	size_t size_toggle_switch = sizeof(ToggleSwitch);

	printf("amount of bytes for: ");
	#if _WIN32
	printf("[Status = %u; LogType = %u; ToggleSwitch = %u]\n", size_status, size_log_type, size_toggle_switch);
	#else
	printf("[Status = %lu; LogType = %lu; ToggleSwitch = %lu]\n", size_status, size_log_type, size_toggle_switch);
	#endif

	return EXIT_SUCCESS;
}