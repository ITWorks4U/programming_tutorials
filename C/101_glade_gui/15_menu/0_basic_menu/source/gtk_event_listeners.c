/*
	Creating a simple menu with certain items.
	In GTK 3.10+ the GTKImageMenuItem has been marked as deprecated and you
	should replace that with GtkBox with GtkImage and GtkLabel instead.
	=> https://docs.gtk.org/gtk3/class.ImageMenuItem.html

	However, you can still use that deprecated item.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void clicked_test(void) {
	g_print("this item has been clicked...\n");
}

void deselected_item(void) {
	g_print("this item has been deselected...\n");
}

void selected_item(void) {
	g_print("this item has been selected...\n");
}

void quit_that_application(void) {
	gtk_main_quit();
}