#include "triangle.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static double triangle_area(const Shape *self) {
	const Triangle *t = (Triangle *)self;
	double s = (t->a + t->b + t->c) / 2.0;

	// Heron's formula
	return sqrt(s * (s - t->a) * (s - t->b) * (s - t->c));
}

static double triangle_perimeter(const Shape *self) {
	const Triangle *t = (Triangle *)self;
	return t->a + t->b + t->c;
}

static void triangle_print(const Shape *self) {
	const Triangle *t = (Triangle *)self;
	printf("Triangle(a=%.2f, b=%.2f, c=%.2f)\n", t->a, t->b, t->c);
}

static const ShapeVTable triangle_vtable = {
	.area = triangle_area,
	.perimeter = triangle_perimeter,
	.print = triangle_print
};

Triangle *triangle_create(double a, double b, double c) {
	// Simple triangle inequality check
	if (a <= 0 || b <= 0 || c <= 0) {
		return NULL;
	}

	if (a + b <= c || a + c <= b || b + c <= a) {
		return NULL;
	}

	Triangle *t = calloc(1, sizeof(Triangle));
	if (t == NULL) {
		return NULL;
	}

	t->a = a;
	t->b = b;
	t->c = c;
	t->base.vtable = &triangle_vtable;
	return t;
}

void triangle_destroy(Triangle *t) {
	free(t);
}
