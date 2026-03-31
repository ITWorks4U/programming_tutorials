/*
	Monitoring your system with a refresh time of 100ms.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

int main(int argc, char **argv) {
	GtkBuilder *builder = NULL;
	GtkWindow *window = NULL;
	AppWidgets *widgets = g_slice_new(AppWidgets);

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file(GLADE_SOURCE_PATH);

	window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));
	widgets->area_to_draw = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "draw_area"));
	widgets->lbl_cpu_optimization = GTK_LABEL(gtk_builder_get_object(builder, "cpu_optimization_level"));
	widgets->lbl_max_ram = GTK_LABEL(gtk_builder_get_object(builder, "lbl_max_ram"));
	widgets->lbl_ram_in_use = GTK_LABEL(gtk_builder_get_object(builder, "lbl_ram_in_use"));
	widgets->lbl_free_ram_left = GTK_LABEL(gtk_builder_get_object(builder, "lbl_ram_left"));
	widgets->lbl_sys_uptime = GTK_LABEL(gtk_builder_get_object(builder, "lbl_sys_uptime"));

	/*	refreshing every 100ms	*/
	g_timeout_add(100, (GSourceFunc)timer_handler, widgets);

	/*	fixed color	*/
	color.red = 0.1;
	color.green = 0.6;
	color.blue = 0.3;
	color.alpha = 1.0;

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}