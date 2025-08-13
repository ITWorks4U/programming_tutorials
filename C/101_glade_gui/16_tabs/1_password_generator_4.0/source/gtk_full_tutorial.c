/*
	Wanna make a password generator?
	Here you can use this!

	The forth version comes with a menu to control the application.
	The real menu allows you to use an about dialogue, whereas a
	tab view gives you control control about the application itself.

	Unlike to version 3.0 every 5 seconds a new password is going to create,
	whereas an overview tells you how long this password is available for you.
	
	By using the option to exclude similar looking characters, these are not
	part of the random generated password.

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
	widgets->chk_excluding = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "chk_exclude_chars"));
	widgets->message = GTK_MESSAGE_DIALOG(gtk_builder_get_object(builder, "message_dialogue"));
	widgets->password_strength = GTK_LEVEL_BAR(gtk_builder_get_object(builder, "level_password_strength"));
	widgets->about_window = GTK_ABOUT_DIALOG(gtk_builder_get_object(builder, "about_window"));
	widgets->lbl_countdown = GTK_LABEL(gtk_builder_get_object(builder, "lbl_countdown"));
	
	/*	registering refresh events	*/
	g_timeout_add(250, (GSourceFunc)refresh_password, widgets);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}