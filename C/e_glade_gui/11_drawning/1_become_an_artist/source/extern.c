/*
	Draw your own art on a GTKDrawArea.
	Maybe you have luck and your art will be
	shown in the Louvre? :o)

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

/*	This surface is required for the whole application.	*/
cairo_surface_t *surface = NULL;

/*	other properties to use	*/
bool on_stroke = false;
int size_x = 10;
int size_y = 10;
bool is_rectangle = true;
GdkRGBA color;