#include <stdio.h>
#include <stdlib.h>
#include "coordinates.h"

int main(void) {
	struct Coordinate *c0 = coord_create(5,5);
	printf("c0: {x;y} = {%d;%d}\n", c0->get_x(c0) , c0->get_y(c0));

	struct Coordinate *c1 = coord_create(16,91);
	printf("c1: {x;y} = {%d;%d}\n", c1->get_x(c1) , c1->get_y(c1));

	struct Coordinate *c_add = c0->add(c0, c1);
	printf("c_add: {x;y} = {%d;%d}\n", c_add->get_x(c_add) , c_add->get_y(c_add));

	struct Coordinate *c_sub = c0->subtract(c0, c1);
	printf("c_sub: {x;y} = {%d;%d}\n", c_sub->get_x(c_sub) , c_sub->get_y(c_sub));

	printf("c0 (dot product) c1: %d\n", c0->dot_product(c0, c1));
	printf("c0 (cross product) c1: %d\n", c0->cross_product(c0, c1));

	coord_destroy(c_sub);
	coord_destroy(c_add);
	coord_destroy(c1);
	coord_destroy(c0);

	return EXIT_SUCCESS;
}