#include <stdlib.h>
#include "36_coordinates.h"

//	-----------
//	"C-style-methods"
//	moreover function implementations, which will be linked
//	to the "methods" of the structure itself
//
//	these implementation functions must comes first,
//	otherwise the compiler does not know those functions
//	-----------

static int get_x_impl(const Coordinate *self) {
	return self != NULL ? self->x : INVALID_VALUE;
}

static int get_y_impl(const Coordinate *self) {
	return self != NULL ? self->y : INVALID_VALUE;
}

static Coordinate *add_impl(const Coordinate *self, const Coordinate *other) {
	if (!self || !other) {
		return NULL;
	}

	return coord_create(self->x + other->x, self->y + other->y);
}

static Coordinate *subtract_impl(const Coordinate *self, const Coordinate *other) {
	if (!self || !other) {
		return NULL;
	}

	return coord_create(self->x - other->x, self->y - other->y);
}

static int dot_product_impl(const Coordinate *self, const Coordinate *other) {
	return (!(self == NULL || other == NULL)) ? (self->x * other->x + self->y * other->y) : 0;
}

static int cross_product_impl(const Coordinate *self, const Coordinate *other) {
	return (!(self == NULL || other == NULL)) ? (self->x * other->y - self->y * other->x) : 0;
}

//	-----------
//	regular functions left
//	-----------

struct Coordinate *coord_create(const int x, const int y) {
	struct Coordinate *__new = (struct Coordinate *) calloc(1, sizeof(struct Coordinate));
	if (__new == NULL) {
		return NULL;
	}

	__new->x = x;
	__new->y = y;

	//	assigning the "methods" to this new created instance
	__new->get_x = get_x_impl;
	__new->get_y = get_y_impl;
	__new->add = add_impl;
	__new->subtract = subtract_impl;
	__new->dot_product = dot_product_impl;
	__new->cross_product = cross_product_impl;

	return __new;
}

void coord_destroy(struct Coordinate *self) {
	free(self);
}