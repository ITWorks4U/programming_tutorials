/*
	similar to the previous example:

	When a button has been pressed,
	a label show up how often this button has been pressed.

	additional event: when a text in the text field has been typed in
	and the certain button has been pressed, the text moves to the label.

	(C) 2024 ITWorks4U
*/
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

#define	STRING_LENGTH	100
#define	NBR_LENGTH		5
#define	STRING_CLICKED	"You've clicked this button "
#define	STRING_TAIL		" times."

static GtkLabel *lbl_output = NULL;
static GtkEntry *text_input = NULL;

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("gtk_window.glade");

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	lbl_output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_output"));
	text_input = GTK_ENTRY(gtk_builder_get_object(builder, "txt_input"));

	gtk_builder_connect_signals(builder, NULL);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	return EXIT_SUCCESS;
}

void window_destroy(void) {
	gtk_main_quit();
}

void on_btn_clicked(void) {
	static unsigned int count = 0;
	char strCounter[STRING_LENGTH];
	memset(strCounter, '\0', STRING_LENGTH);

	char strClicked[NBR_LENGTH];
	memset(strClicked, '\0', NBR_LENGTH);
	memcpy(strCounter, STRING_CLICKED, strlen(STRING_CLICKED));

	count++;
	sprintf(strClicked, "%d", count);
	strcat(strCounter, strClicked);
	strcat(strCounter, STRING_TAIL);

	gtk_label_set_text(lbl_output, strCounter);
}

void on_btn_from_textfield_clicked(GtkButton *button, GtkLabel *lbl) {
	gtk_label_set_text(lbl, gtk_entry_get_text(text_input));
}