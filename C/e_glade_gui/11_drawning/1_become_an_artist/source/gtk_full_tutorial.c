/*
	Draw your own art on a GTKDrawArea.
	Maybe you have luck and your art will be
	shown in the Louvre? :o)

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
	widgets->cbo_style = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "cbo_style_selecter"));
	widgets->spin_x = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin_for_x"));
	widgets->spin_y = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin_for_y"));
	widgets->color_btn = GTK_COLOR_BUTTON(gtk_builder_get_object(builder, "color_button"));

	/*
		register events for draw area

		widget: the widget to register the events
		events:	what kind of events are required, where:
			gtk_widget_get_events := receive all known events from the certain widget
			GDK_BUTTON_PRESS_MASK := when the mouse button (not specified which mouse button at this moment) has been pressed
			GDK_POINTER_MOTION_MASK := when the mouse has been moved while the mouse button has been pressed, too
	*/
	gtk_widget_set_events(GTK_WIDGET(widgets->area_to_draw), gtk_widget_get_events(GTK_WIDGET(widgets->area_to_draw)) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK);

	/*	activate the first element for combo box text */
	gtk_combo_box_set_active(GTK_COMBO_BOX(widgets->cbo_style), 0);

	/*	start color	*/
	color.red = 0.5;
	color.green = 0.5;
	color.blue = 0.5;
	color.alpha = 1.0;
	gtk_color_chooser_set_rgba(GTK_COLOR_CHOOSER(widgets->color_btn), &color);

	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}