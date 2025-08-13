/*
* This circle "inherits" from the base shape.
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CIRCLE_H
#define CIRCLE_H

#include "geometric_object.h"

typedef struct {
	Shape base;
	double radius;
} Circle;

Circle *circle_create(double radius);
void circle_destroy(Circle *c);
#endif

#ifdef __cplusplus
}
#endif