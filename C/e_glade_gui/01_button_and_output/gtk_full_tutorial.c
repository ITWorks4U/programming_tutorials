/*
	Handle a button event: When a button has been pressed,
	a lable show up how often this button has been pressed.

	(C) 2024 ITWorks4U
*/

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

//	----------
//	constants
//	----------
/*	the maximum amount of charactes for the output	*/
#define	STRING_LENGTH	100

/*
	the number of digits for a number: in that case a range between 0 - 9999!
	But why? Since C is in use and the number must be converted into a C-string,
	make sure to terminate your C-string WITH a nulltermination character: \0
*/
#define	NBR_LENGTH		5

#define	STRING_CLICKED	"You've clicked this button "
#define	STRING_TAIL		" times."

//	----------
//	global object
//	----------
/*	must be global here, because we need that object in main and also in the event function for button click	*/
static GtkLabel *lbl_output = NULL;

//	----------
//	code
//	----------
int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file("gtk_window.glade");

	/*	remember:	each object, which is in use, must be initialized	*/
	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	lbl_output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_output"));

	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	return EXIT_SUCCESS;
}

//	----------
//	event functions
//	----------
void window_destroy(void) {
	gtk_main_quit();
}

void on_btn_clicked(void) {
	static unsigned int count = 0;
	char strCounter[STRING_LENGTH];
	memset(strCounter, '\0', STRING_LENGTH);

	char strClicked[NBR_LENGTH];
	memset(strClicked, '\0', NBR_LENGTH);

	/*	in case of strncpy gives you a warning on compile time	*/
	// strncpy(strCounter, STRING_CLICKED, strlen(STRING_CLICKED));
	memcpy(strCounter, STRING_CLICKED, strlen(STRING_CLICKED));

	count++;
	sprintf(strClicked, "%d", count);

	/*	may also throw a warning	*/
	// strncat(strCounter, strClicked, strlen(strClicked));
	// strncat(strCounter, STRING_TAIL, strlen(STRING_TAIL));

	/*	you may use strcpy or an another function or your own written function instead	*/
	strcat(strCounter, strClicked);
	strcat(strCounter, STRING_TAIL);

	/*	update the content of your label	*/
	gtk_label_set_text(lbl_output, strCounter);
}