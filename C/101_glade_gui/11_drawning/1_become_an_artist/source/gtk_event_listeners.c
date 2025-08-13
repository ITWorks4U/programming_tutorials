/*
	Draw your own art on a GTKDrawArea.
	Maybe you have luck and your art will be
	shown in the Louvre? :o)

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"
#include <string.h>

void window_destroy(void) {
	gtk_main_quit();
}

/*	on very window resize or when the right mouse button has been pressed	*/
void clear_surface(void) {
	cairo_t *cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
	cairo_paint(cr);
	cairo_destroy(cr);
}

/*	event function for GTKDrawArea	*/
void draw_brush(GtkWidget *widget, gdouble x, gdouble y) {
	/*	the surface object needs to be created here	*/
	cairo_t *cr = cairo_create(surface);

	/*	setting the selected color for the object to draw	*/
	cairo_set_source_rgba(cr, color.red, color.green, color.blue, color.alpha);

	/*	time to paint	*/
	if (is_rectangle) {
		cairo_rectangle(cr, x, y, size_x, size_y);
	} else {
		//	surface, x, y, radius <=> size_x, start angle, end angle
		cairo_arc(cr, x, y, size_x, 0.0, 2 * PI);
	}

	if (on_stroke) {
		cairo_stroke(cr);
	} else {
		cairo_fill(cr);
	}
	
	cairo_destroy(cr);

	gtk_widget_queue_draw_area(widget, x, y, size_x, size_y);
}

gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event, gpointer data) {
	if (surface != NULL) {
		cairo_surface_destroy(surface);
	}

	surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget), CAIRO_CONTENT_COLOR, gtk_widget_get_allocated_width(widget), gtk_widget_get_allocated_height(widget));
	clear_surface();

	return TRUE;
}

gboolean draw_something(GtkWidget *widget, cairo_t *cr, gpointer data) {
	cairo_set_source_surface(cr, surface, 0.0, 0.0);
	cairo_paint(cr);

	return TRUE;
}

gboolean button_press_event_cb(GtkWidget *widget, GdkEventButton *event, gpointer data) {
	if (surface == NULL) {
		return FALSE;
	}

	if (event->button == GDK_BUTTON_PRIMARY) {
		draw_brush(widget, event->x, event->y);
	} else if (event->button == GDK_BUTTON_SECONDARY) {
		clear_surface();
		gtk_widget_queue_draw(widget);
	}

	return TRUE;
}

gboolean motion_notify_event_cb (GtkWidget *widget, GdkEventMotion *event, gpointer data) {
	if (surface == NULL) {
		return FALSE;
	}

	if (event->state & GDK_BUTTON1_MASK) {
		draw_brush(widget, event->x, event->y);
	}

	return TRUE;
}

void changed_style_handling(GtkComboBoxText *cboBox, AppWidgets *app) {
	/*	just differencing between a rectangle and a circle	*/
	if (strncmp(gtk_combo_box_text_get_active_text(app->cbo_style), RECTANGLE, strlen(RECTANGLE)) == 0) {
		is_rectangle = true;
	} else {
		is_rectangle = false;
	}
}

void toggle_object_fill(void) {
	static int ctr = 0;
	ctr++;

	if (ctr % 2 == 1) {
		on_stroke = true;
	} else {
		on_stroke = false;
	}
}

void spin_x_changed(GtkSpinButton *btn, AppWidgets *app) {
	size_x = gtk_spin_button_get_value_as_int(app->spin_x);
}

void spin_y_changed(GtkSpinButton *btn, AppWidgets *app) {
	size_y = gtk_spin_button_get_value_as_int(app->spin_y);
}

void choosen_color(GtkColorButton *btn, AppWidgets *app) {
	gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(app->color_btn), &color);

	/*
		just nice to know which color is in use now
		g_print("red: %.2lf, green: %.2lf, blue: %.2lf, alpha: %.2lf\n", color.red, color.green, color.blue, color.alpha);
	*/
}