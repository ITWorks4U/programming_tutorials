/*
	Basic usage of "How to create a GUI" written in C with the tool glade and GTK 3.
	This code sample allows you to display a basic, empty window with the callback
	function to close this window and also close this application process.

	(C) 2024 ITWorks4U
*/

/*	in some editors this library might not be found => since you have installed GTK correctly, ignore that false warning	*/
#include <gtk/gtk.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	/*	Since raw pointers are in use (for C only), we have to initialize these with NULL!	*/
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;

	/*	in case of by using command line arguments => are hardly used and not shown in any example	*/
	gtk_init(&argc, &argv);

	/*
		combine the glade file with your application

		attention:	Make sure your glade file can be found!
	*/

	/*	1st way to initialize	*/
	// builder = gtk_builder_new();
	// gtk_builder_add_from_file(builder, "gtk_window.glade", NULL);

	/*
		gboolean gtk_builder_add_from_file (GtkBuilder* builder, const char* filename, GError** error);

		builder:
		-	builder object to use
		
		filename:
		-	the name of the glade file

		error:
		-	return location for a recoverable error, if required
		-	NULL: "We don't care about any error."

		returns:
		-	TRUE on success
		-	FALSE if an error occurred
	*/

	/*	2nd way to initalize	*/
	builder = gtk_builder_new_from_file("gtk_window.glade");

	/*
		GtkBuilder* gtk_builder_new_from_file (const char* filename);

		filename:
		-	the name of the glade file

		returns:
		-	a GtkBuilder interface; the caller of the function takes ownership of the data, and is responsible for freeing it
	*/

	/*	initializing the created window	*/
	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));

	/*	connecting event signals, like closing this window and terminating the application	*/
	gtk_builder_connect_signals(builder, NULL);

	/*	the builder is no longer in use here	*/
	g_object_unref(builder);

	/*	mark the window to display	*/
	gtk_widget_show(GTK_WIDGET(window));

	/*	display the window	*/
	gtk_main();

	/*	In C you're also welcome to write: return 0	*/
	return EXIT_SUCCESS;
}

/*	event handler function, when the 'X' of your window has been pressed	*/
void window_destroy(void) {
	gtk_main_quit();
}