/*
	Similar to a normal dialogue, you can also load a picture to your application.

	(C) 2024 ITWorks4U
*/
#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void load_image(GtkButton *btn, AppWidgets *app) {
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(app->file_chooser), "/home/");
	gtk_widget_show(GTK_WIDGET(app->file_chooser));

	if (gtk_dialog_run(GTK_DIALOG(app->file_chooser)) == GTK_RESPONSE_OK) {
		gtk_image_set_from_file(GTK_IMAGE(app->image), gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app->file_chooser)));
	}
	
	gtk_widget_hide(GTK_WIDGET(app->file_chooser));
}