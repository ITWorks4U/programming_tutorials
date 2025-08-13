/*
	Wanna make a password generator?
	Here you can use this!

	In the first version the user needs to enter a valid password length
	between 1 and 30 characters. To handle each input correctly a regular
	expression is in use.

	This random generated password may contain capital letters, lower letters,
	numbers and or bonus characters. At least one option must be set.
	It doesn't matter which option.

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
	widgets->password_length_input = GTK_ENTRY(gtk_builder_get_object(builder, "entry_pw_length"));
	widgets->password_output = GTK_ENTRY(gtk_builder_get_object(builder, "entry_password_output"));
	widgets->lbl_error = GTK_LABEL(gtk_builder_get_object(builder, "lbl_error_output"));
	widgets->chk_capital = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_capital_letters"));
	widgets->chk_lower = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_lower_characters"));
	widgets->chk_numbers = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_numbers"));
	widgets->chk_bonus = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_bonus_charaters"));
	
	/*	default output for lbl_error:	*/
	gtk_label_set_text(widgets->lbl_error, NO_ERROR);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}