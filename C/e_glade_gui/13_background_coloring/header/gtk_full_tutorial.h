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

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"

/*	structures	*/
typedef struct GtkObjects {
	GtkLabel *lbl_background;
	GtkButton *btn_background;
}AppWidgets;

#endif