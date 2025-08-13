/*
	Handling with background events.
	Every UI has a big problem: Overloading of objects, which does something.

	An UI is "just" a visual reflection for the user. Every other
	system resource needs to be handled in the background.

	for example: displaying the current system time
	
	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>
#include <stdbool.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"

/*	structures	*/
typedef struct GtkObjects {
	GtkEntry *time_output;
}AppWidgets;

/*	this function prototype is required for a system trigger event	*/
gboolean system_time_event(AppWidgets *app);

/*	in use for our purpose	*/
extern GDateTime *dateTime;

#endif