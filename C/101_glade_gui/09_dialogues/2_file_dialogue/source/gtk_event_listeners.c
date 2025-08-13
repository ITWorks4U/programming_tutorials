/*
	Dialogues allows you to deal with more professional skill.
	A dialogue could be a simple message dialogue, file chooser,
	about window, wizard, ...

	Attention:
	Since a file chooser dialogue is in use, the terminal prints
	you this message:

	Gtk-CRITICAL **: <time>: gtk_widget_grab_default: assertion 'gtk_widget_get_can_default (widget)' failed

	At this point it's unclear for that reason and also not known how to get rid of this.

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
	gtk_widget_show(GTK_WIDGET(app->info_dialogue));
	gtk_dialog_run(GTK_DIALOG(app->info_dialogue));
	gtk_widget_hide(GTK_WIDGET(app->info_dialogue));
}

void open_file_dialogue(GtkButton *btn, AppWidgets *app) {
	/*
		Remember on, that gtk_dialog_run() can be a standalone function?
		In fact we don't care about the return state, the dialogue closes,
		when it's no longer in use.

		You can also request the response state to do special operations,
		if required.

		By default, your file dialogues always points to the current folder, where
		your application is running now. To set the default path (must be done for
		reading and / or writing), use this function:

		gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(FILE_CHOOSER_TO_USE), <PATH_TO_POINT_TO>);
	*/

	gchar *fileName = NULL;

	/*
		A file chooser may comes with a file filter to choose a certain file.
		This can be done in glade, but you can also do this programmitcally.
	*/
	gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(app->open_dialogue), app->filter_for_opening);
	gtk_widget_show(GTK_WIDGET(app->open_dialogue));
	
	if (gtk_dialog_run(GTK_DIALOG(app->open_dialogue)) == GTK_RESPONSE_OK) {
		fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app->open_dialogue));

		//	do whatever you want here...
		
		g_free(fileName);
	}
	
	gtk_widget_hide(GTK_WIDGET(app->open_dialogue));
}

void open_save_dialogue(GtkButton *btn, AppWidgets *app) {
	gchar *fileName = NULL;

	/*	here the save dialogue doesn't need a file filter	*/
	// gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(app->save_dialogue), <filter for files>);
	
	gtk_widget_show(GTK_WIDGET(app->save_dialogue));
	
	if (gtk_dialog_run(GTK_DIALOG(app->save_dialogue)) == GTK_RESPONSE_OK) {
		fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app->save_dialogue));

		//	do whatever you want here...

		g_free(fileName);
	}

	gtk_widget_hide(GTK_WIDGET(app->save_dialogue));
}