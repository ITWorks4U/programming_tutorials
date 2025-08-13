/*
	Dialogues allows you to deal with more professional skill.
	A dialogue could be a simple message dialogue, file chooser,
	about window, wizard, ...

	Here you have a small text editor, written in C with GTK!

	(C) 2024 ITWorks4U
*/

#include <string.h>
#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void open_file(GtkButton *btn, AppWidgets *app) {
	gchar *fileName = NULL;
	gchar *fileContents = NULL;
	gboolean fileSuccess = FALSE;

	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(app->file_chooser_open), SOURCE_DESTINATION_PATH);

	/*	using *.c, *.h, *.txt files only	*/
	GtkFileFilter *fileFilter = updateFileFilter(TEXT_FILES | C_SOURCE_FILES);
	gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(app->file_chooser_open), fileFilter);

	gtk_widget_show(GTK_WIDGET(app->file_chooser_open));

	if (gtk_dialog_run(GTK_DIALOG(app->file_chooser_open)) == GTK_RESPONSE_OK) {
		fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app->file_chooser_open));

		if (fileName != NULL) {
			/*	copy the contents of the file to dynamically allocated memory	*/
			fileSuccess = g_file_get_contents(fileName, &fileContents, NULL, NULL);
			
			if (fileSuccess) {
				gtk_text_buffer_set_text(app->buffer_text, fileContents, -1);
			}

			g_free(fileContents);
		}

		g_free(fileName);
	}

	gtk_widget_hide(GTK_WIDGET(app->file_chooser_open));
}

void save_file(GtkButton *btn, AppWidgets *app) {
	gchar *fileName = NULL;
	gchar *textContent = NULL;

	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(app->file_chooser_save), SOURCE_DESTINATION_PATH);

	/*	saving the content as text files only	*/
	GtkFileFilter *filterForSaving = updateFileFilter(ALL_TEXT_FILES);
	gtk_file_chooser_set_filter(GTK_FILE_CHOOSER(app->file_chooser_save), filterForSaving);

	gtk_widget_show(GTK_WIDGET(app->file_chooser_save));

	if (gtk_dialog_run(GTK_DIALOG(app->file_chooser_save)) == GTK_RESPONSE_OK) {
		fileName = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app->file_chooser_save));

		/*	required objects to determine from where to where a text is going to save	*/
		GtkTextIter *start = (GtkTextIter *) calloc(1, sizeof(GtkTextIter));
		GtkTextIter *end = (GtkTextIter *) calloc(1, sizeof(GtkTextIter));

		gtk_text_buffer_get_start_iter(app->buffer_text, start);
		gtk_text_buffer_get_end_iter(app->buffer_text, end);

		if (fileName != NULL) {
			textContent = gtk_text_buffer_get_text(app->buffer_text, start, end, -1);
			g_file_set_contents(fileName, textContent, strlen(textContent), NULL);
			g_free(textContent);
		}

		g_free(end);
		g_free(start);
		g_free(fileName);
	}

	gtk_widget_hide(GTK_WIDGET(app->file_chooser_save));
}

void show_about_window(GtkButton *btn, AppWidgets *app) {
	gtk_widget_show(GTK_WIDGET(app->about_window));
	gtk_dialog_run(GTK_DIALOG(app->about_window));
	gtk_widget_hide(GTK_WIDGET(app->about_window));
}

GtkFileFilter *updateFileFilter(int filters) {
	GtkFileFilter *filterToUse = gtk_file_filter_new();

	if (filters == ALL_TEXT_FILES) {
		gtk_file_filter_add_pattern(filterToUse, "*.txt");
		gtk_file_filter_add_pattern(filterToUse, "*.c");
		gtk_file_filter_add_pattern(filterToUse, "*.h");
		gtk_file_filter_add_pattern(filterToUse, "*.cpp");
		gtk_file_filter_add_pattern(filterToUse, "*.hpp");
		gtk_file_filter_add_pattern(filterToUse, "*.java");
		gtk_file_filter_add_pattern(filterToUse, "*.py");
		gtk_file_filter_add_pattern(filterToUse, "*.log");
		gtk_file_filter_add_pattern(filterToUse, "*.dat");
	} else {
		if ((filters & TEXT_FILES) == TEXT_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.txt");
		}

		if ((filters & C_SOURCE_FILES) == C_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.c");
			gtk_file_filter_add_pattern(filterToUse, "*.h");
		}

		if ((filters & CPP_SOURCE_FILES) == CPP_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.cpp");
			gtk_file_filter_add_pattern(filterToUse, "*.hpp");
			gtk_file_filter_add_pattern(filterToUse, "*.h");
		}

		if ((filters & JAVA_SOURCE_FILES) == JAVA_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.java");
		}

		if ((filters & PYTHON_SOURCE_FILES) == PYTHON_SOURCE_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.py");
		}

		if ((filters & LOGGING_FILES) == LOGGING_FILES) {
			gtk_file_filter_add_pattern(filterToUse, "*.txt");
			gtk_file_filter_add_pattern(filterToUse, "*.log");
			gtk_file_filter_add_pattern(filterToUse, "*.dat");
		}
	}

	return filterToUse;
}