/*	for function prototypes */

#ifndef LIB_H
#define LIB_H

/// @brief	Prints "Hello from a C library!", which will be in use for python.
void say_hello_from_C(void);

/// @brief Square multiplication for an array of numbers.
/// @param n number of elements to use
/// @param array_in input array with n elements
/// @param array_out result array of n elements
void square_multiplication(int n, double *array_in, double *array_out);

/// @brief Do a bubble sort in C, which is going to use in Python instead
/// @param nbr_of_elements number of elements to use
/// @param array_in array with random numbers
/// @param array_out array with sorted elements
void bubble_sort(size_t nbr_of_elements, double *array_in, double *array_out);

#endif