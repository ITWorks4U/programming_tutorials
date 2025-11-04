#ifndef THREADING_H
#define THREADING_H

// This shall not run with a C++ compiler to avoid undefined behavior.
#ifdef __cplusplus
#error "This sample contains C functions only, which might not work correctly with C++. Use a C compiler instead."
#else

#define FILE_TO_USE  "random_numbers.txt"
#define MAX_BUFFER   250000

#include <stdbool.h>

/*
* depending on which OS you're using
*/
#ifdef _WIN32
	#define THREADING_ON_WINDOWS
	#include <Windows.h>
	typedef HANDLE thread_t;

	/// @brief Thread function for Windows.
	/// @param arg any argument, which can be used => must be converted to its desired data type
	/// @return 0 on success, otherwise failure (often -1)
	DWORD WINAPI bubble_thread(LPVOID arg);

	/// @brief Prints a formatted error message to stderr.
	/// @param message the message to print
	void print_error_message(const char *message);
#else
// also valid for other non-Windows systems
	#define THREADING_ON_LINUX
	#include <unistd.h>
	#include <pthread.h>

	/// @brief Thread function for UNIX/Linux/macOS
	/// @param arg any argument, which can be used => must be converted to its desired data type
	/// @return usually NULL, otherwise you want to continue to work with the address of the function itself
	void *bubble_thread(void *arg);
#endif

/// @brief Print the elapsed time to stdout
/// @param seconds elapsed seconds
void time_amount(double seconds);

/// @brief Load the file "random_numbers.txt", which contains 250,000 numbers and
/// fill it to the array. If the file can't be found or any other error
/// may occur, no more action is to do here.
void load_numbers_from_file(void);

/// @brief Sorting all elements to their size by using bubble sort. => O(n*n)
/// The elapsed time will be recorded.
void bubble_sort(void);

// ----------
// external features
// ----------

/// @brief flag to check, if the I/O operation was successful
extern bool coord_on_continue;

/// @brief contains 250,000 random numbers
extern long test_array[MAX_BUFFER];

#endif
#endif