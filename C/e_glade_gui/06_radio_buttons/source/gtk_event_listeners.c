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

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void on_rb_choice_1_toggled(GtkRadioButton *btn, AppWidgets *app) {
	gtk_label_set_text(app->chosen_output, "rb 1 selected");
}

void on_rb_choice_2_toggled(GtkRadioButton *btn, AppWidgets *app) {
	gtk_label_set_text(app->chosen_output, "rb 2 selected");
}

void on_rb_choice_3_toggled(GtkRadioButton *btn, AppWidgets *app) {
	gtk_label_set_text(app->chosen_output, "rb 3 selected");
}