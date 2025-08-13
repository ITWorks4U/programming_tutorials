/*
	Handling with background events.
	Every UI has a big problem: Overloading of objects, which does something.

	An UI is "just" a visual reflection for the user. Every other
	system resource needs to be handled in the background.

	for example: displaying the current system time
	
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
	widgets->time_output = GTK_ENTRY(gtk_builder_get_object(builder, "txt_current_time"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	/*
		to activate a background timer, use this function:

		Every second the certain function "system_time_event" is going
		to trigger. The third argument is our widgets object, which allows
		us to access to the text field.

		You may also use a function like:
		g_timeout_add(MILLISECONDS, (GSourceFunc) FUNCTION, STRUCTURE_TO_USE);

	*/
	g_timeout_add_seconds(1, (GSourceFunc) system_time_event, widgets);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}