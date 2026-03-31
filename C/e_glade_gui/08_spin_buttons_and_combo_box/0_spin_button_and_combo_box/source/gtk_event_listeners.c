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

#include "../header/gtk_full_tutorial.h"
#include <string.h>
#include <stdlib.h>

void window_destroy(void) {
	gtk_main_quit();
}

/*	event function for spin button	*/
void spin_value_changed(GtkSpinButton *spinBtn, AppWidgets *app) {

	/*	the spin button can also be used with the mouse wheel	*/
	gint spinNumber = gtk_spin_button_get_value_as_int(app->spin_button);

	gchar spinNumberAsWord[MAX_LENGTH_SPIN];
	memset(spinNumberAsWord, '\0', MAX_LENGTH_SPIN);
	sprintf(spinNumberAsWord, "%d", spinNumber);

	gtk_label_set_text(app->chosen_output, spinNumberAsWord);
}

/*	event function for chosen element from combo box	*/
void on_changed_option(GtkComboBoxText *cboBox, AppWidgets *app) {
	gchar *itemText = gtk_combo_box_text_get_active_text(app->cbo_selection);
	gtk_label_set_text(app->chosen_output, itemText);
	g_free(itemText);
}

/*	event function to add a new element to the combo box	*/
void add_new_element(GtkButton *btn, AppWidgets *app) {
	/*	at least two elements already exists in our combo box, therefore the next value is 3	*/
	static gint itemNumber = 2;
	itemNumber++;

	gtk_combo_box_text_insert_text(app->cbo_selection, itemNumber, gtk_entry_get_text(app->entry_for_new_element));
	gtk_entry_set_text(app->entry_for_new_element, "");
}