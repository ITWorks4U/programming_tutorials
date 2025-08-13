/*
	A spin button, also known as numeric button,
	allows you to scroll in a given numerical range.

	In GTK you also need a GTKAdjustment, otherwise
	your spin button won't work correctly.

	A combo box allows you to choose an element to work with.
	This is often a word, but it can also be anything else,
	however, every element in a combo box is... *drumroll* a C-string!

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	MAX_LENGTH_SPIN		5

/*	structures	*/
typedef struct GtkObjects {
	GtkLabel *chosen_output;

	GtkComboBoxText *cbo_selection;
	GtkSpinButton *spin_button;
	GtkEntry *entry_for_new_element;
}AppWidgets;

#endif