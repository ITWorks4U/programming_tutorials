/*
	Wanna make a password generator?
	Here you can use this!

	In the second version the user chooses a password length between 1 and 30 characters
	by using a spin button. So, a regular expression check is no longer required here.

	This random generated password may contain capital letters, lower letters,
	numbers and or bonus characters. At least one option must be set.
	It doesn't matter which option.

	You also gets an advise about your password strength.

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
	widgets->lbl_password_strength = GTK_LABEL(gtk_builder_get_object(builder, "lbl_password_strength"));
	widgets->spin_button = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin_numbers"));
	widgets->password_output = GTK_ENTRY(gtk_builder_get_object(builder, "entry_password_output"));
	widgets->chk_capital = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_capital_letters"));
	widgets->chk_lower = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_lower_characters"));
	widgets->chk_numbers = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_numbers"));
	widgets->chk_bonus = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_bonus_charaters"));
	widgets->message = GTK_MESSAGE_DIALOG(gtk_builder_get_object(builder, "message_dialogue"));
	
	/*	default output for password strength on app start:	*/
	gtk_label_set_text(widgets->lbl_password_strength, TOO_WEAK);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}