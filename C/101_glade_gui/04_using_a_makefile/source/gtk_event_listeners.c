/*
	still the same example like 02/03/04

	(C) 2024 ITWorks4U
*/

#include <string.h>
#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void on_btn_clicked(GtkButton *btn, AppWidgets *app) {
	static unsigned int count = 0;
	char strCounter[STRING_LENGTH];
	memset(strCounter, '\0', STRING_LENGTH);

	char strClicked[NBR_LENGTH];
	memset(strClicked, '\0', NBR_LENGTH);
	memcpy(strCounter, STRING_CLICKED, strlen(STRING_CLICKED));

	count++;
	sprintf(strClicked, "%d", count);
	strcat(strCounter, strClicked);
	strcat(strCounter, STRING_TAIL);

	gtk_label_set_text(app->lbl_output, strCounter);
}

void on_btn_from_textfield_clicked(GtkButton *button, AppWidgets *app) {
	gtk_label_set_text(app->lbl_output, gtk_entry_get_text(app->text_input));
}