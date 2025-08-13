/*
	By using a menu bar in combination with a text editor,
	you can create an application with more style.

	(C) 2024 ITWorks4U
*/

#include <gtk/gtk.h>
#include "../header/gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file(GLADE_SOURCE_PATH);

	widgets->window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	widgets->file_chooser_open = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder, "file_chooser_open"));
	widgets->file_chooser_save = GTK_FILE_CHOOSER_DIALOG(gtk_builder_get_object(builder, "file_chooser_save"));
	widgets->about_window = GTK_ABOUT_DIALOG(gtk_builder_get_object(builder, "about_window"));
	widgets->buffer_text = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "buffer_for_text_area"));
	widgets->text_view_area = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "text_area"));

	/*
		optional:	When no title in the glade application has been given, this can be done here, too.
		attention:	In that case your window is not defined here in main only, it comes from
					the known structure "AppWidgets"! That's required, because in the source file
					"gtk_event_listeners.c" the window must also be available there.
	*/
	gtk_window_set_title(widgets->window, TITLE_WINDOW);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(widgets->window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}