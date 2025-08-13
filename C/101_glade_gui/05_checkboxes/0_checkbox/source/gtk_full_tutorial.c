/*
	Checkbox buttons allows a multiple choice of options, actions, ...
	To handle a checkbox button, a counter is in use here.
	When the value of this counter is odd, then this check box has been
	checked. Otherwise it's unchecked.
	
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
	widgets->chk_toggle = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "toggle_button"));;
	widgets->lbl_status = GTK_LABEL(gtk_builder_get_object(builder, "lbl_for_toggled_state"));

	/*	by default: the checkbox is not pressed	*/
	gtk_label_set_text(widgets->lbl_status, IS_NOT_TOGGLED);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}