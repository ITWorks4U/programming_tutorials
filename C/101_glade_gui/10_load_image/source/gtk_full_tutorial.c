/*
	Similar to a normal dialogue, you can also load a picture to your application.

	(C) 2024 ITWorks4U
*/

#include <gtk/gtk.h>
#include "../header/gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file(GLADE_SOURCE_PATH);

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	widgets->image = GTK_IMAGE(gtk_builder_get_object(builder, "image_main"));
	widgets->file_chooser = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder, "file_chooser"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}