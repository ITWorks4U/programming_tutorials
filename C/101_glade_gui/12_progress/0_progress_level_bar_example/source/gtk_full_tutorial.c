/*
	Using a progress bar and a level bar.

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
	widgets->progress_bar = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "progress_bar"));
	widgets->level_bar = GTK_LEVEL_BAR(gtk_builder_get_object(builder, "level_bar"));

	/*	refreshing each 100ms	*/
	g_timeout_add(100, (GSourceFunc) timer_handler, widgets);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}