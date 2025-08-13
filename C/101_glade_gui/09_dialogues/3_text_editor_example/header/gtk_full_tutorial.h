/*
	Dialogues allows you to deal with more professional skill.
	A dialogue could be a simple message dialogue, file chooser,
	about window, wizard, ...

	Here you have a small text editor, written in C with GTK!

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	SOURCE_DESTINATION_PATH	"/home/"

/*	values for file dialogue filter	*/
#define	ALL_TEXT_FILES		0x0
#define	TEXT_FILES			0x1
#define	C_SOURCE_FILES		0x10
#define	CPP_SOURCE_FILES	0x100
#define	JAVA_SOURCE_FILES	0x1000
#define	PYTHON_SOURCE_FILES	0x10000
#define	LOGGING_FILES		0x100000

/*	structures	*/
typedef struct GtkObjects {
	/*	dialogues	*/
	GtkFileChooserDialog *file_chooser_open;
	GtkFileChooserDialog *file_chooser_save;
	GtkAboutDialog *about_window;

	/*	misc	*/
	GtkTextView *text_view_area;
	GtkTextBuffer *buffer_text;
}AppWidgets;

/*	function prototype	*/
GtkFileFilter *updateFileFilter(int filters);

#endif