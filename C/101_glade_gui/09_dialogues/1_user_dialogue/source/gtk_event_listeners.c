/*
	Dialogues allows you to deal with more professional skill.
	A dialogue could be a simple message dialogue, file chooser,
	about window, wizard, ...

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void open_about_dialogue(GtkButton *btn, AppWidgets *app) {
	gtk_widget_show(GTK_WIDGET(app->about_dialogue));
	gtk_dialog_run(GTK_DIALOG(app->about_dialogue));
	gtk_widget_hide(GTK_WIDGET(app->about_dialogue));
}

void open_normal_dialogue(GtkButton *btn, AppWidgets *app) {
	/*
		Usually, gtk_dialog_run can be a standalone function,
		but sometimes this can also be in use, when a certain
		button response ID returns. More in use by file dialogues.
	*/

	gtk_widget_show(GTK_WIDGET(app->info_dialogue));
	if (gtk_dialog_run(GTK_DIALOG(app->info_dialogue)) == GTK_RESPONSE_OK) {}
	gtk_widget_hide(GTK_WIDGET(app->info_dialogue));
}