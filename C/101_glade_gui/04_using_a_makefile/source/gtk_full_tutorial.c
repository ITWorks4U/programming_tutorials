/*
	still the same example like 02/03/04

	(C) 2024 ITWorks4U
*/

#include <gtk/gtk.h>
#include <stdlib.h>
#include "../header/gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file(GLADE_SOURCE_PATH);

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	widgets->lbl_output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_output"));
	widgets->text_input = GTK_ENTRY(gtk_builder_get_object(builder, "txt_input"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}