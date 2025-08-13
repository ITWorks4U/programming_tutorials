/*
* Basicly you can't do OOP in c0, however, with some tricks this
* can be realized including limitations.
*/

#include <stdio.h>
#include <stdlib.h>
#include "36_coordinates.h"

int main(void) {
	/*
	* This won't work, because it would refer to
	* the definition of the structure in the header
	* file. There the structure is an unknown structure.
	* The compiler won't know what this structure may contain.
	*/
	// struct Coordinate _c;

	/*	you're forced to use pointers	*/
	struct Coordinate *c0 = coord_create(5,5);
	printf("c0: {x;y} = {%d;%d}\n", coord_get_x(c0) , coord_get_y(c0));

	struct Coordinate *c1 = coord_create(16,91);
	printf("c1: {x;y} = {%d;%d}\n", coord_get_x(c1) , coord_get_y(c1));

	/*
	* This causes a memory leak! There's no more pointer to the
	* allocated memory, where c1 has pointed to before.
	*/
	// c1 = NULL;
	// printf("x: %d, y: %d\n", coord_get_x(c1) , coord_get_x(c1));

	//	attention, if you're using coord_add or coord_subtract
	//	these are created pointers and must also be removed from
	//	the memory, otherwise memory leak(s) still exists

	struct Coordinate *c_add = coord_add(c0, c1);
	printf("c_add: {x;y} = {%d;%d}\n", coord_get_x(c_add) , coord_get_y(c_add));

	struct Coordinate *c_sub = coord_subtract(c0, c1);
	printf("c_sub: {x;y} = {%d;%d}\n", coord_get_x(c_sub) , coord_get_y(c_sub));

	printf("c0 (dot) c1: %d\n", dot_product(c0, c1));
	printf("c0 (cross) c1: %d\n", cross_product(c0, c1));

	coord_destroy(c_sub);
	coord_destroy(c_add);
	coord_destroy(c1);
	coord_destroy(c0);

	return EXIT_SUCCESS;
}