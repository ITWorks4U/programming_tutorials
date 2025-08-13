/*
* OOP and C? Does this work? Well, yes, but actually maybe.
* C is not designed for OOP, however, you can do a tiny step into it.
*
* Fun fact: Objective-C is the result of Smalltalk with C.
*/

#include <stdlib.h>
#include "36_coordinates.h"

/*
* The header file contains the definition, this source
* file contains the declaration. In this file it's required
* to declare your structure to work with.
*/

struct Coordinate {
	int x;
	int y;
};

//	-----------
//	functions
//	-----------

struct Coordinate *coord_create(const int x, const int y) {
	struct Coordinate *__new = (struct Coordinate *) calloc(1, sizeof(struct Coordinate));
	if (__new == NULL) {
		return NULL;
	}

	__new->x = x;
	__new->y = y;

	return __new;
}

void coord_destroy(struct Coordinate *self) {
	free(self);
}

int coord_get_x(const struct Coordinate *self) {
	/*
	* To avoid an undefined reference it's a good advice
	* to check the structure against NULL.
	*/
	return self != NULL ? self->x : INVALID_VALUE;
}

int coord_get_y(const struct Coordinate *self) {
	return self != NULL ? self->y : INVALID_VALUE;
}

struct Coordinate *coord_add(const struct Coordinate *c1, const struct Coordinate *c2) {
	if (c1 == NULL || c2 == NULL) {
		return NULL;
	}

	return coord_create(c1->x + c2->x, c1->y + c2->y);
}

struct Coordinate *coord_subtract(const struct Coordinate *c1, const struct Coordinate *c2) {
	if (c1 == NULL || c2 == NULL) {
		return NULL;
	}

	return coord_create(c1->x - c2->x, c1->y - c2->y);
}

int dot_product(const struct Coordinate *c1, const struct Coordinate *c2) {
	if (c1 == NULL || c2 == NULL) {
		return INVALID_VALUE;
	}

	return c1->x * c2->x + c1->y * c2->y;
}

int cross_product(const struct Coordinate *c1, const struct Coordinate *c2) {
	if (c1 == NULL || c2 == NULL) {
		return INVALID_VALUE;
	}

	return c1->x * c2->y - c1->y * c2->x;
}