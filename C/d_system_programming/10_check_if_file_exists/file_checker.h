/*
* System programming in C.
*
* Check, if a file may exist on a certain system.
* In C there're many different ways to do this, however,
* not on every system the implementation may work.
*
* Here are three different ways to try to figure out,
* if a file may exist or not.
*
* example 1: using signals
* NOTE:      signals are hardly in use to check,
*            if a file may exist or not
*
* example 2: using access
* NOTE:      On Windows _access() only exists.
*            To make sure to use a common way for
*            all available systems, a macro function
*            will be used there.
*
* example 3: using built in methods
* NOTE:      It's a bit more complex, but may give
*            you a more clean or more faster output.
*/

#ifndef FILE_CHECKER_H
#define FILE_CHECKER_H

#define FILE_EXISTS     "File does exist."
#define FILE_IS_MISSING "File does not exist."
#define FILE_TO_CHECK   "test.txt"

#ifdef _WIN32
// only for Windows

// using signals
#define SIGUSR1          10

// using access() function
#include <io.h>
#define access _access
#define F_OK 0

// using system built in functions
#include <Windows.h>
#else
// only for UNIX
#include <unistd.h>
#include <sys/stat.h>
#endif

/// @brief Test on file existing with signals.
void test_with_signals(void);

/// @brief Test on file existing with access function.
void test_with_access(void);

/// @brief Test on file with system built in methods.
void test_with_system_built_in(void);

#endif