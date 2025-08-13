/*
	Creating a simple menu with certain items.
	In GTK 3.10+ the GTKImageMenuItem has been marked as deprecated and you
	should replace that with GtkBox with GtkImage and GtkLabel instead.
	=> https://docs.gtk.org/gtk3/class.ImageMenuItem.html

	However, you can still use that deprecated item.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file(GLADE_SOURCE_PATH);

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}