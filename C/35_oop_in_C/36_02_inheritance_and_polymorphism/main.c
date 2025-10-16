#include <stdio.h>
#include <stdlib.h>

//	including all headers
#include "geometric_object.h"
#include "circle.h"
#include "triangle.h"

int main(void) {
	Shape *shapes[2];

	shapes[0] = (Shape *)circle_create(5.0);
	shapes[1] = (Shape *)triangle_create(3.0, 4.0, 5.0);

	for (int i = 0; i < 2; ++i) {
		shape_print(shapes[i]);
		printf("Area: %.2f\n", shape_area(shapes[i]));
		printf("Perimeter: %.2f\n\n", shape_perimeter(shapes[i]));
	}

	circle_destroy((Circle *)shapes[0]);
	triangle_destroy((Triangle *)shapes[1]);

	return EXIT_SUCCESS;
}
