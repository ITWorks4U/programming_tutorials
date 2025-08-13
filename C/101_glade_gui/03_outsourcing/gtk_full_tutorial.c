/*
	When you are not a novice in programming or you want to
	create a professional design for coding,
	then create a header file, which contains your objects to use.

	Attention: Here you're allowed to use a single structure only,
	which can be managed with GTK. Not sure, if this is now available
	for more than one structure.

	(C) 2024 ITWorks4U
*/

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;

	/*	to be able to use your widgets from the structure, this must be "registered"	*/
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("gtk_window.glade");

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	widgets->lbl_output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_output"));
	widgets->text_input = GTK_ENTRY(gtk_builder_get_object(builder, "txt_input"));

	/*
		important:	now we're using our objects from the structure, the second argument must
		refer to your structure
	*/
	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	/*	normal usage of memory management: when a resource is in use, it must be freed by hand	*/
	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}

void window_destroy(void) {
	gtk_main_quit();
}

void on_btn_clicked(GtkButton *btn, AppWidgets *app) {
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

	gtk_label_set_text(app->lbl_output, strCounter);
}

void on_btn_from_textfield_clicked(GtkButton *button, AppWidgets *app) {
	gtk_label_set_text(app->lbl_output, gtk_entry_get_text(app->text_input));
}