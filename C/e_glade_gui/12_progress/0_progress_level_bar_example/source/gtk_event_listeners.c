/*
	Using a progress bar and a level bar.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

static gdouble progress_value = 0.0;

void trigger_progress_bar(GtkButton *btn, AppWidgets *app) {
	progress_value = 1.0;
	gtk_progress_bar_set_fraction(app->progress_bar, progress_value);
	gtk_level_bar_set_value(app->level_bar, progress_value);
}

gboolean timer_handler(AppWidgets *app) {
	if (progress_value > 0.0) {
		progress_value -= 0.05;
		gtk_progress_bar_set_fraction(app->progress_bar, progress_value);
		gtk_level_bar_set_value(app->level_bar, progress_value);
	}

	return TRUE;
}