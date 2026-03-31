/*
	still the same example like 02/03/04

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	constants	*/
#define	STRING_LENGTH		100
#define	NBR_LENGTH			5
#define	STRING_CLICKED		"You've clicked this button "
#define	STRING_TAIL			" times."
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"

/*	header(s)	*/
#include <gtk/gtk.h>

/*	data structure(s)	*/
typedef struct GtkObjects {
	GtkLabel *lbl_output;
	GtkEntry *text_input;
}AppWidgets;

#endif