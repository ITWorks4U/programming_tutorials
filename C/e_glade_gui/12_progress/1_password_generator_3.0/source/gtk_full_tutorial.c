/*
	Wanna make a password generator?
	Here you can use this!

	In the third version the user chooses a password length between 1 and 50 characters
	by using a spin button. Every 500 ms a new random generated password with the certain
	length will be created. It stops, when the user presses the "stop" button or closes
	the application.

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
	widgets->toggle_button = GTK_BUTTON(gtk_builder_get_object(builder, "btn_switch"));
	widgets->spin_button = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin_numbers"));
	widgets->password_output = GTK_ENTRY(gtk_builder_get_object(builder, "entry_password_output"));
	widgets->chk_capital = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_capital_letters"));
	widgets->chk_lower = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_lower_characters"));
	widgets->chk_numbers = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_numbers"));
	widgets->chk_bonus = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_bonus_charaters"));
	widgets->message = GTK_MESSAGE_DIALOG(gtk_builder_get_object(builder, "message_dialogue"));
	widgets->password_strength = GTK_LEVEL_BAR(gtk_builder_get_object(builder, "level_password_strength"));
	widgets->timer_progress = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "visual_timer_prgress"));
	
	/*	generating a new password every 500ms => see into the function for more details	*/
	g_timeout_add(100, (GSourceFunc)refresh_password, widgets);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}