/*
* Knapsack problem:
* "How many objects can be collected with the highest value without exceeding the limitation?"
*
* contains:
* - a defined set of items with their weights
* - a defined set of values for each item
* - a maximum capacity
* - a backtracking algorithm in case of the capacity has been exceeded or a possible better way may exist
*
* author:	ITWorks4U
* created:	July 14th, 2025
* updated:	July 22nd, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main(void) {
	init_knapsack();
	if (on_continue) {
		printf("maximum value in the knapsack: %d\n", solve_knapsack_problem());
		display_all_items();

		clean_up();
	}

	return EXIT_SUCCESS;
}