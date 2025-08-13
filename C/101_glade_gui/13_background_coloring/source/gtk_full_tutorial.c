/*
	Coloring the background of objects are possible,
	however, the known functions are often deprecated,
	whereas the advise for given alternate function or
	data structure is deprecrated as well.

	Thus, there're few options as an alternative.
	While a label has the option to modify the background color,
	any other object needs to be use a deprecated function at this moment.

	There's also a way to suppress the deprecation waring for certain
	function.

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
	widgets->lbl_background = GTK_LABEL(gtk_builder_get_object(builder, "lbl_background"));
	widgets->btn_background = GTK_BUTTON(gtk_builder_get_object(builder, "btn_to_modify"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}