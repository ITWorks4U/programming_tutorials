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

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <stdbool.h>

//	definitions
#define MAX_CAPACITY     50
#define NBR_OF_ELEMENTS  7
#define VALUES           {10, 31, 29, 16, 13, 24, 8}
#define WEIGHTS          {6, 18, 19, 7, 15, 16, 12}

//	extern

/// @brief Flag, if the procedure is possible.
extern bool on_continue;

//	structure

/// @brief A knapsack, which may contain any amount of values.
typedef struct {
	//	a set of weights
	int *weights;

	//	a set of values
	int *values;
} Knapsack;

//	function prototypes

/// @brief Create a new knapsack.
void init_knapsack(void);

/// @brief Clean up the mess.
void clean_up(void);

/// @brief Try to solve the knapsack problem including backtracking.
/// @return the optimized number of items with their weights
int solve_knapsack_problem(void);

/// @brief Show, what the knapsack contains...
void display_all_items(void);

#endif