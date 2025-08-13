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

/*
	A huge pitfall waits for you, if you don't mind:

	Every sub window also comes with the destroy event, which means,
	when the 'X' of this button has been pressed, it should be closed.
	However, this has a nasty surprise for you!

	By using the event function, like "close_window", you'll see your
	sub window once only. Unless you're restarting your application.

	To avoid this, you have to handle the steps in another way:
	1)	show the certain widget
	2)	run the widget => this manages the close event automatically and correct
	3)	hide the certain widget
	4)	repeat :o)

	Hint: you may also have seen this in the password generator vol. 2
*/

void open_about_dialogue(GtkButton *btn, AppWidgets *app) {
	gtk_widget_show(GTK_WIDGET(app->about_dialogue));
	gtk_dialog_run(GTK_DIALOG(app->about_dialogue));
	gtk_widget_hide(GTK_WIDGET(app->about_dialogue));
}

// void close_window(GtkAboutDialog *dlg, AppWidgets *app) {
// 	gtk_widget_hide(GTK_WIDGET(app->about_dialogue));
// }