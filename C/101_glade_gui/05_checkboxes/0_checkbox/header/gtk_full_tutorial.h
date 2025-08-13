/*
	Checkbox buttons allows a multiple choice of options, actions, ...
	To handle a checkbox button, a counter is in use here.
	When the value of this counter is odd, then this check box has been
	checked. Otherwise it's unchecked.
	
	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	IS_TOGGLED			"The check box button is pressed."
#define	IS_NOT_TOGGLED		"The check box button is unpressed."

/*	structures	*/
typedef struct GtkObjects {
	GtkLabel *lbl_status;
	GtkCheckButton *chk_toggle;
}AppWidgets;

#endif