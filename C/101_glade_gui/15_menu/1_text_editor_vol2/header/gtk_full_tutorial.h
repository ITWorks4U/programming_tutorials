/*
	By using a menu bar in combination with a text editor,
	you can create an application with more style.

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	SOURCE_DESTINATION_PATH	"/home/"
#define	TITLE_WINDOW		"A simple text editor 2.0"

/*
	attention:	When your path to the file or file name is too long,
	then an undefined behavior will occour!
*/
#define	BUFFER_TITLE		127
#define	TINY_BUFFER			31

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

	/*	the window itself -> required to update the title	*/
	GtkWindow *window;
}AppWidgets;

/*	function prototype	*/
GtkFileFilter *updateFileFilter(int filters);
void cleanUp(void);
void saveFileTo(AppWidgets *app);
void updateWindowTitle(GtkWindow *window, char *fileName);

#endif