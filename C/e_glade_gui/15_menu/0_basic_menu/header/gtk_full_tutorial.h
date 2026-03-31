/*
	Creating a simple menu with certain items.
	In GTK 3.10+ the GTKImageMenuItem has been marked as deprecated and you
	should replace that with GtkBox with GtkImage and GtkLabel instead.
	=> https://docs.gtk.org/gtk3/class.ImageMenuItem.html

	However, you can still use that deprecated item.

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
	/*	no items in use here	*/
}AppWidgets;

#endif