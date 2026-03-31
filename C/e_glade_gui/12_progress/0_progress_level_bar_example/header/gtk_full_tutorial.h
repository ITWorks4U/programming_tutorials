/*
	Using a progress bar and a level bar.

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
	GtkProgressBar *progress_bar;
	GtkLevelBar *level_bar;
}AppWidgets;

gboolean timer_handler(AppWidgets *app);

#endif