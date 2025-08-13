/*
* This triangle "inherits" from the base shape.
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "geometric_object.h"

typedef struct {
	Shape base;
	double a, b, c;
} Triangle;

Triangle *triangle_create(double a, double b, double c);
void triangle_destroy(Triangle *t);

#endif

#ifdef __cplusplus
}
#endif