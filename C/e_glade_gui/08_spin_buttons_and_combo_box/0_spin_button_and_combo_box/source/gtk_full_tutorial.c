/*
	A spin button, also known as numeric button,
	allows you to scroll in a given numerical range.

	In GTK you also need a GTKAdjustment, otherwise
	your spin button won't work correctly.

	A combo box allows you to choose an element to work with.
	This is often a word, but it can also be anything else,
	however, every element in a combo box is... *drumroll* a C-string!

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
	widgets->chosen_output = GTK_LABEL(gtk_builder_get_object(builder, "lbl_output"));
	widgets->entry_for_new_element = GTK_ENTRY(gtk_builder_get_object(builder, "txt_additional_selection"));
	widgets->spin_button = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin_chosen"));
	widgets->cbo_selection = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "combo_text"));

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}