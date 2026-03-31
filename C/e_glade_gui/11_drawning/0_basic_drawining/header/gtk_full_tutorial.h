/*
	Drawning with cairo on a GTKDrawningArea.
	cairo is a tool for vector graphics, see: https://www.cairographics.org/manual/

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
	GtkDrawingArea *area_to_draw;
}AppWidgets;

#endif
