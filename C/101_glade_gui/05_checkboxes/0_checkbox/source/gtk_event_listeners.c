/*
	Checkbox buttons allows a multiple choice of options, actions, ...
	To handle a checkbox button, a counter is in use here.
	When the value of this counter is odd, then this check box has been
	checked. Otherwise it's unchecked.
	
	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void toggle_state(GtkCheckButton *btn, AppWidgets *app) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		/*	for each odd number => this check box is active	*/
		gtk_label_set_text(app->lbl_status, IS_TOGGLED);
	} else {
		gtk_label_set_text(app->lbl_status, IS_NOT_TOGGLED);
	}
}