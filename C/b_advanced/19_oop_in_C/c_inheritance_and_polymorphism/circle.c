#include "circle.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double circle_area(const Shape *self) {
	const Circle *c = (Circle *)self;
	return M_PI * c->radius * c->radius;
}

static double circle_perimeter(const Shape *self) {
	Circle *c = (Circle *)self;

	return 2 * M_PI * c->radius;
}

static void circle_print(const Shape *self) {
	const Circle *c = (Circle *)self;
	printf("Circle(radius=%.2f)\n", c->radius);
}

static const ShapeVTable circle_vtable = {
	.area = circle_area,
	.perimeter = circle_perimeter,
	.print = circle_print
};

Circle *circle_create(double radius) {
	if (radius <= 0.0) {
		return NULL;
	}

	Circle *c = calloc(1, sizeof(Circle));
	if (c == NULL) {
		return NULL;
	}

	c->radius = radius;
	c->base.vtable = &circle_vtable;
	return c;
}

void circle_destroy(Circle *c) {
	free(c);
}
