/*
	Coloring the background of objects are possible,
	however, the known functions are often deprecated,
	whereas the advise for given alternate function or
	data structure is deprecrated as well.

	Thus, there're few options as an alternative.
	While a label has the option to modify the background color,
	any other object needs to be use a deprecated function at this moment.

	There's also a way to suppress the deprecation waring for certain
	function.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void change_background(GtkButton *btn, AppWidgets *app) {
	//	-----------------------

	/*
		for GTK below 3.0

		here red, green, and blue have a range of {0,65535} => {0x0,0xFFFF}
		so, you can use a decimal expression, or bit shift or hexadecimal form
	*/
	// GdkColor c;
	// c.red = 50000;
	// c.green = 1 << 14;
	// c.blue = 0xDEADBEEF;		/*	value overflow here */

	// gtk_widget_modify_bg(GTK_WIDGET(app->lbl_background), GTK_STATE_NORMAL, &c);

	//	-----------------------

	/*
		If you really must use a deprecated function or structure, then use
		these macros.
	*/
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS

	/*
		available for GTK since 3.0; deprecated since 3.16

		red, green and blue have a range of {0.0, 1.0}
		the alpha channel has the same range; the higher the value,
		the more visible is the given color
	*/
	GdkRGBA c;
	c.alpha = 1.0;
	c.blue = 1.0;
	c.red = 0.5;
	c.green = 0.25;

	gtk_widget_override_background_color(GTK_WIDGET(app->btn_background), GTK_STATE_FLAG_NORMAL, &c);
	G_GNUC_END_IGNORE_DEPRECATIONS

	//	-----------------------

	/*
		only available for a label; the other widgets doesn't comes with a function like this;
		attention: a text between <span></span> is required, otherwise you won't see anything
		additional hint: the background color only affects the label text, not the whole
		background, where the label has been placed
	*/
	gchar color[] = "<span background='red'>Test</span>";
	gtk_label_set_markup(app->lbl_background, color);
}