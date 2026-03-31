/*
	Drawning with cairo on a GTKDrawningArea.
	cairo is a tool for vector graphics, see: https://www.cairographics.org/manual/

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

gboolean draw_something(GtkDrawingArea *area, cairo_t *context, gpointer user_data) {
	/*
		define a RGB color with certain alpha value
		the value is in a range between [0.0 , 1.0]
			0.0 := 0% for this color
			1.0 := 100% for this color

		the alpha value has also a range between [0.0 , 1.0], where:
			0.0 := the whole object is unable to see (transparency by 100%)
			1.0 := the whole object can be seen

		alternative function:	cairo_set_source_rgb(cairo_t *cr, double red, double green, double blue);

		without using rgb(a) function, the certain object (rectangle, circle, ...) will be black only
	*/
	cairo_set_source_rgba(context, 0.5, 1.0, 0.8, 1.0);

	/*	mark to draw a rectangle with:	start position {x,y} and a dimension of {width,height}	*/
	cairo_rectangle(context, 10, 10, 100, 100);

	/*	draw the certain object above	*/
	cairo_fill(context);

	/*	also draw a full 360° circle, which is not filled	*/
	cairo_set_source_rgba(context, 1.0, 0.0, 0.8, 0.5);
	cairo_arc(context, 330, 160, 40, 0, 2 * 3.1415);
	cairo_stroke(context);

	/*	Since we have still fun, what about a circle, which is an arc only?	*/
	float x = 200, y = 100;
	float radius = 40, startAngle = 0.7, endAngle = 2.44;

	cairo_set_source_rgba(context, 1.0, 0.0, 0.0, 1.0);
	cairo_arc(context, x, y, radius, startAngle, endAngle);
	cairo_stroke(context);

	return TRUE;
}