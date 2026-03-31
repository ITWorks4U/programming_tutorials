/*
	The different buttons and their purpose...

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
	widgets->lbl_normal_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_normal_ button"));
	widgets->lbl_spin_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_spin_button"));
	widgets->lbl_toggle_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_toggled_button"));
	widgets->lbl_menu_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_menu_button"));
	widgets->lbl_lock_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_lock_button"));
	widgets->lbl_switch_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_switch_button"));
	widgets->lbl_model_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_model_button"));
	widgets->lbl_file_chooser_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_file_chooser"));
	widgets->lbl_color_chooser_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_color_chooser"));
	widgets->lbl_font_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_font_button"));
	widgets->lbl_link_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_link_button"));
	widgets->lbl_scale_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_scale_button"));
	widgets->lbl_volume_button = GTK_LABEL(gtk_builder_get_object(builder, "lvl_volume_button"));
	widgets->lbl_app_chooser_button = GTK_LABEL(gtk_builder_get_object(builder, "lbl_app_chooser_button"));

	widgets->spin_btn = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spin"));
	widgets->file_chooser_button = GTK_FILE_CHOOSER_BUTTON(gtk_builder_get_object(builder, "file"));
	widgets->btn_switch = GTK_SWITCH(gtk_builder_get_object(builder, "switch"));
	widgets->color_btn = GTK_COLOR_BUTTON(gtk_builder_get_object(builder, "color_btn"));
	widgets->font_button = GTK_FONT_BUTTON(gtk_builder_get_object(builder, "font_btn"));
	widgets->link_btn = GTK_LINK_BUTTON(gtk_builder_get_object(builder, "link_btn"));
	widgets->scale_btn = GTK_SCALE_BUTTON(gtk_builder_get_object(builder, "scale_btn"));
	widgets->volume_btn = GTK_VOLUME_BUTTON(gtk_builder_get_object(builder, "volume_btn"));
	widgets->app_btn = GTK_APP_CHOOSER_BUTTON(gtk_builder_get_object(builder, "app_btn"));
	
	gtk_builder_connect_signals(builder, widgets);
	g_object_unref(builder);

	gtk_widget_show(GTK_WIDGET(window));
	gtk_main();

	g_slice_free(AppWidgets, widgets);
	return EXIT_SUCCESS;
}