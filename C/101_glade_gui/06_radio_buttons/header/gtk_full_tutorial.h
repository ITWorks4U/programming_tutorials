/*
	Radio buttons are similar to check box buttons, however,
	by default a radio button must be a member of an another
	radio button to make sure, that only one radio button
	can be pressed for a certain choice.

	This will be handled in the glade file:
	Every other radio button, which shall be interact with
	an another radio button, has this property set: "Group",
	where there the name of the master radio button is given.

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
	GtkLabel *chosen_output;
}AppWidgets;

#endif