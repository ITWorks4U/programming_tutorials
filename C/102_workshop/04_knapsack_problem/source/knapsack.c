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
#include <string.h>
#include <errno.h>
#include "knapsack.h"

// -----------
// Static / Global Declarations
// -----------

static Knapsack *_knapsack = NULL;
static int **dp_table = NULL;

static int knapsack_values[] = VALUES;
static int knapsack_weights[] = WEIGHTS;

bool on_continue = true;

// -----------
// Function Definitions
// -----------

void init_knapsack(void) {
	_knapsack = (Knapsack *)calloc(1, sizeof(Knapsack));
	if (!_knapsack) {
		perror("calloc(Knapsack)");
		on_continue = false;
		return;
	}

	_knapsack->weights = knapsack_weights;
	_knapsack->values = knapsack_values;
}

void clean_up(void) {
	if (dp_table) {
		for (int i = 0; i <= NBR_OF_ELEMENTS; i++) {
			free(dp_table[i]);
		}
		free(dp_table);
		dp_table = NULL;
	}

	free(_knapsack);
	_knapsack = NULL;
}

int solve_knapsack_problem(void) {
	dp_table = (int **)calloc(NBR_OF_ELEMENTS + 1, sizeof(int *));
	if (dp_table == NULL) {
		perror("calloc(dp_table)");
		return 0;
	}

	for (int i = 0; i <= NBR_OF_ELEMENTS; i++) {
		dp_table[i] = (int *)calloc(MAX_CAPACITY + 1, sizeof(int));
		if (dp_table[i] == NULL) {
			fprintf(stderr, "calloc(dp_table[%d]): %s\n", i, strerror(errno));

			for (int j = 0; j < i; j++) {
				free(dp_table[j]);
			}

			free(dp_table);
			return 0;
		}
	}

	for (int i = 1; i <= NBR_OF_ELEMENTS; i++) {
		for (int w = 1; w <= MAX_CAPACITY; w++) {
			int item_idx = i - 1;
			if (_knapsack->weights[item_idx] <= w) {
				int include = _knapsack->values[item_idx] + dp_table[i - 1][w - _knapsack->weights[item_idx]];
				int exclude = dp_table[i - 1][w];
				dp_table[i][w] = (include > exclude) ? include : exclude;
			} else {
				dp_table[i][w] = dp_table[i - 1][w];
			}
		}
	}

	return dp_table[NBR_OF_ELEMENTS][MAX_CAPACITY];
}

void display_all_items(void) {
	int w = MAX_CAPACITY;
	for (int i = NBR_OF_ELEMENTS; i > 0 && w > 0; i--) {
		if (dp_table[i][w] != dp_table[i - 1][w]) {
			int item_idx = i - 1;

			printf(
				"item %d (value: %d, weight: %d)\n",
				item_idx, _knapsack->values[item_idx], _knapsack->weights[item_idx]
			);

			w -= _knapsack->weights[item_idx];
		}
	}
}