/*
	Radio buttons are similar to check box buttons, however,
	by default a radio button must be a member of an another
	radio button to make sure, that only one radio button
	can be pressed for a certain choice.

	This will be handled in the glade file:
	Every other radio button, which shall be interact with
	an another radio button, has this property set: "Group",
	where there the name of the master radio button is given.

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
	widgets->chosen_output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_choosen"));

	gtk_label_set_text(widgets->chosen_output, "no option selected yet");

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}