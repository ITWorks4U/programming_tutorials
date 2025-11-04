#ifndef OS_SYSTEM_DEFINITIONS_H
#define OS_SYSTEM_DEFINITIONS_H

// function names for our purpose
#define FUNC_ADD      "addition"
#define FUNC_SUBTRACT "subtraction"
#define FUNC_MULTIPLY "multiply"
#define FUNC_DIVIDE   "divide"

typedef int (*addition_func)(int, int);
typedef int (*subtraction_func)(int, int);
typedef int (*multiply_func)(int, int);
typedef int (*divide_func)(int, int);

#ifdef _WIN32
	#include <Windows.h>
	#define LIBRARY_NAME "math_operations.dll"
#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
	#include <dlfcn.h>
	#include <unistd.h>
	#include <libgen.h>
	#include <string.h>
	#define FULL_PATH_LENGTH 1024

	#if defined(__APPLE__) || defined(_MAC)
		#define LIBRARY_NAME "math_operations.dylib"
	#else
		#define LIBRARY_NAME "math_operations.so"
	#endif
#else
	#define APP_IS_UNABLE_TO_USE
#endif

#endif