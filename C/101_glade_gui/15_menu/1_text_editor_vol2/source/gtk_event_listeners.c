/*
	By using a menu bar in combination with a text editor,
	you can create an application with more style.

	(C) 2024 ITWorks4U
*/

#include <string.h>
#include <stdbool.h>
#include "../header/gtk_full_tutorial.h"

//	-------------------
//	static references to use
//	-------------------

/*	in use for saving a file	*/
static gchar *fileName = NULL;

/*	in use for cut, copy, paste, delete	*/
static GtkClipboard *board = NULL;

/*	updating the window title with the certain loaded file	*/
void updateWindowTitle(GtkWindow *window, char *fileName) {
	char buffer[BUFFER_TITLE];
	memset(buffer, '\0', BUFFER_TITLE);
	memcpy(buffer, TITLE_WINDOW, strlen(TITLE_WINDOW));

	/*	only in case the fileName is not empty (when any file has been loaded)	*/
	if (strlen(fileName) > 0) {
		/*
			strncat could also be in use, however, your compiler might give you
			a warning, that the length of " - " is equal to the source length:
			"warning: ‘strncat’ specified bound 3 equals source length [-Wstringop-overflow=]"

			or in other words: since the third argument has a fixed and known length,
			your compiler gives you that warning, whereas fileName has a dynamic length,
			and there your compiler won't give you that warning

			thus, only strcat is in use here
		*/
		strcat(buffer, " - ");

		/*
			before fileName is going to append to the title, which holds the absolute path,
			we only need the appendix after the last '/'

			attention: this works only for C-Strings; strings in C++ might have a nasty unknown
			side affect
		*/
		char tmp[TINY_BUFFER];
		memset(tmp, '\0', TINY_BUFFER);

		char *token = strtok(fileName, "/");
		while (token != NULL) {

			/*	always reset the temporary buffer and copy the next token	*/
			memset(tmp, '\0', TINY_BUFFER);
			memmove(tmp, token, strlen(token));
			token = strtok(NULL, "/");
		}

		/*	since tmp has a dynamic length, strncat is in use here	*/
		strncat(buffer, tmp, strlen(tmp));
	}
	
	gtk_window_set_title(window, buffer);
}

/*	clean up the mess before terminating the application	*/
void cleanUp(void) {
	g_free(fileName);
	fileName = NULL;
	board = NULL;
	gtk_main_quit();
}

/*	'X' has been pressed	*/
void window_destroy(void) {
	cleanUp();
}

/*	create a new editor view and remove every text; regardless of what you have seen before	*/
void create_new_document(GtkImageMenuItem *imi, AppWidgets *app) {
	if (fileName != NULL) {
		/*	to avoid to overwrite the previous opened file pointer, which still exists	*/
		g_free(fileName);
		fileName = NULL;
	}

	gtk_text_buffer_set_text(app->buffer_text, "", 0);
	updateWindowTitle(app->window, "");
}

void open_file(GtkImageMenuItem *imi, AppWidgets *app) {
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
			updateWindowTitle(app->window, fileName);
		}
	}

	gtk_widget_hide(GTK_WIDGET(app->file_chooser_open));
}

void save_current_file(GtkImageMenuItem *imi, AppWidgets *app) {
	gchar *textContent = NULL;

	if (fileName != NULL) {
		/*
			only in use, when a file has been loaded and the content has been modified,
			then the current file is going to overwrite
		*/

		GtkTextIter *start = (GtkTextIter *) calloc(1, sizeof(GtkTextIter));
		GtkTextIter *end = (GtkTextIter *) calloc(1, sizeof(GtkTextIter));

		/*	get start and end position of the whole text to save	*/
		gtk_text_buffer_get_start_iter(app->buffer_text, start);
		gtk_text_buffer_get_end_iter(app->buffer_text, end);

		textContent = gtk_text_buffer_get_text(app->buffer_text, start, end, -1);

		/*	overwrite and save the file	*/
		g_file_set_contents(fileName, textContent, strlen(textContent), NULL);
		g_free(textContent);

		g_free(end);
		g_free(start);
	} else {

		/*	otherwise that's a new file, which is going to save first time	*/
		saveFileTo(app);
	}
}

void save_file(GtkImageMenuItem *imi, AppWidgets *app) {
	/*	when "save as" has been pressed	*/
	saveFileTo(app);
}

void saveFileTo(AppWidgets *app) {
	/*
		attention:	by default, you won't get an information, when
					the file already exists; this can also be added
	*/

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
	}

	gtk_widget_hide(GTK_WIDGET(app->file_chooser_save));
}

/*	menu "close" has been pressed	*/
void quit_application(void) {
	cleanUp();
}

/*	cut out text	*/
void cut_text(GtkImageMenuItem *imi, AppWidgets *app) {
	/*	honestly, the official documentation was hardly present and not cleary documented	*/

	/*	first check, if any text has been marked	*/
	bool on_selection = gtk_text_buffer_get_has_selection(app->buffer_text);
	if (on_selection) {
		/*	initialize the GTKClipboard with the constant expression	*/
		board = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

		/*
			cut out text and move that to the GTKClipboard

			extern void gtk_text_buffer_cut_clipboard(GtkTextBuffer *buffer, GtkClipboard  *clipboard, gboolean default_editable);
			buffer:
				-	the buffer to use
			clipboard:
				-	the GTKClipboard to move the marked text
			default_editable:
				-	if true, the marked text will disappear
				-	if false, the marked text is still available and won't give you
					the view, that there's a text cut out
		*/
		gtk_text_buffer_cut_clipboard(app->buffer_text, board, true);
	}
}

/*	copy marked text	*/
void copy_text(GtkImageMenuItem *imi, AppWidgets *app) {
	/*	similar to cut text, whereas the marked text is copied	*/
	bool on_selection = gtk_text_buffer_get_has_selection(app->buffer_text);
	if (on_selection) {
		board = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

		/*
			extern void gtk_text_buffer_copy_clipboard(GtkTextBuffer *buffer, GtkClipboard  *clipboard);

			buffer:
				-	the buffer to use
			clipboard:
				-	the GTKClipboard to move the marked text

			fun fact, this function below has the identical behavior:
			extern void gtk_text_buffer_cut_clipboard(GtkTextBuffer *buffer, GtkClipboard  *clipboard, gboolean default_editable);
			
			whereas default_editable is set to false
		*/
		gtk_text_buffer_copy_clipboard(app->buffer_text, board);
	}
}

/*	paste text from the clipboard, if that contains anything	*/
void paste_text(GtkImageMenuItem *imi, AppWidgets *app) {
	if (board != NULL) {
		/*
			required, otherwise that critical warning:
			"gtk_clipboard_request_contents: assertion 'clipboard != NULL' failed"
			will appear
		*/

		gtk_text_buffer_paste_clipboard(app->buffer_text, board, NULL, true);

		/*
			extern void gtk_text_buffer_paste_clipboard(GtkTextBuffer *buffer, GtkClipboard  *clipboard, GtkTextIter *override_location, gboolean default_editable);

			buffer:
				-	the buffer to work with
			clipboard:
				-	the GTKClipboard as "source"
			override_location:
				-	if set, then to a specific GtkTextIter the pasted text is going to paste there
				-	NULL:	use the current cursor position instead
			default_editable:
				-	true, the pasted text is visible
				-	false, the pasted text is invisible
		*/
	}
}

/*	deleting marked text	*/
void delete_text(GtkImageMenuItem *imi, AppWidgets *app) {
	bool on_selection = gtk_text_buffer_get_has_selection(app->buffer_text);
	if (on_selection) {
		board = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
		gtk_text_buffer_delete_selection(app->buffer_text, true, true);

		/*
			extern gboolean gtk_text_buffer_delete_selection(GtkTextBuffer *buffer, gboolean interactive, gboolean default_editable);

			buffer:
				-	the buffer to work with
			interactive:
				-	¯\_(ツ)_/¯ (means, it was not cleary seen, what happens here)
			default_editable:
				-	¯\_(ツ)_/¯ (means, it was not cleary seen, what happens here)
			
			returns:
				-	1, if a text has been marked; no other return value might appear elsewhere

			more informations here: https://docs.gtk.org/gtk3/method.TextBuffer.delete_selection.html
		*/
	}
}

void show_about_window(GtkImageMenuItem *imi, AppWidgets *app) {
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