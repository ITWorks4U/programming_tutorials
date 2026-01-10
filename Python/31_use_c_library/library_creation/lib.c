#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void say_hello_from_C(void) {
	puts("Hello from a C library!");
}

void square_multiplication(int n, double *array_in, double *array_out) {
	for(int i = 0; i < n; i++) {
		array_out[i] = array_in[i] * array_in[i];
	}
}

void bubble_sort(size_t nbr_of_elements, double *array_in, double *array_out) {
	for(size_t ctr = 0; ctr < nbr_of_elements; ctr++) {
		array_out[ctr] = array_in[ctr];
	}

	for (size_t i = 0; i < nbr_of_elements - 1; i++) {
		for (size_t j = 0; j < (nbr_of_elements - i) - 1; j++) {
			if (array_out[j] > array_out[j + 1]) {
				double temp = array_out[j];
				array_out[j] = array_out[j + 1];
				array_out[j + 1] = temp;
			}
		}
	}
}