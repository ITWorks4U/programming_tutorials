/*
	Draw your own art on a GTKDrawArea.
	Maybe you have luck and your art will be
	shown in the Louvre? :o)

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>
#include <stdbool.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	RECTANGLE			"rectangle"
#define	PI					3.14159265358979323846

/*	structures	*/
typedef struct GtkObjects {
	GtkDrawingArea *area_to_draw;
	GtkComboBoxText *cbo_style;
	GtkSpinButton *spin_x;
	GtkSpinButton *spin_y;
	GtkColorButton *color_btn;
}AppWidgets;

/*	external	*/
extern cairo_surface_t *surface;
extern bool on_stroke;
extern int size_x;
extern int size_y;
extern bool is_rectangle;
extern GdkRGBA color;

/*	function prototypes	*/
void clear_surface(void);
void draw_brush(GtkWidget *widget, gdouble x, gdouble y);

#endif