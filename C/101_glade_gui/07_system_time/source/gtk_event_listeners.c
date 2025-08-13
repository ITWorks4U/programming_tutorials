/*
	Handling with background events.
	Every UI has a big problem: Overloading of objects, which does something.

	An UI is "just" a visual reflection for the user. Every other
	system resource needs to be handled in the background.

	for example: displaying the current system time
	
	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	/*
		Attention:

		Even the dateTime object is a pointer, this must not be
		freed, because this is not a pointer, which is going to
		store to the heap. This one is going to store to the stack!
	*/

	/*g_free(dateTime);*/
	gtk_main_quit();
}

gboolean system_time_event(AppWidgets *app) {
	gchar *dateTimeFormatter = NULL;

	dateTime = g_date_time_new_now_local();
	dateTimeFormatter = g_date_time_format(dateTime, "%H:%M:%S");
	
	gtk_entry_set_text(app->time_output, dateTimeFormatter);
	g_free(dateTimeFormatter);

	return TRUE;
}