/*
	When you are not a novice in programming or you want to
	create a professional design for coding,
	then create a header file, which contains your objects to use.

	Attention: Here you're allowed to use a single structure only,
	which can be managed with GTK. Not sure, if this is now available
	for more than one structure.

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

#include <gtk/gtk.h>

#define	STRING_LENGTH	100
#define	NBR_LENGTH		5
#define	STRING_CLICKED	"You've clicked this button "
#define	STRING_TAIL		" times."

typedef struct GtkObjects {
	GtkLabel *lbl_output;
	GtkEntry *text_input;
}AppWidgets;

#endif