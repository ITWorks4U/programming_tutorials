/*
	Monitoring your system with a refresh time of 100ms.

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	BUFFER				50
#define	DOUBLE_BUFF			BUFFER*2
#define	BUFF128				128
#define	TINY_BUFFER			10
#define	GIGABYTE			(1024*1024*1024)

/*	structures	*/
typedef struct GtkObjects {
	GtkDrawingArea *area_to_draw;
	GtkLabel *lbl_cpu_optimization;
	GtkLabel *lbl_max_ram;
	GtkLabel *lbl_ram_in_use;
	GtkLabel *lbl_free_ram_left;
	GtkLabel *lbl_sys_uptime;
}AppWidgets;

/*	function prototypes	*/
gboolean timer_handler(const AppWidgets *app);
void init_cpu_array(void);
void cpu_watch_linux(const AppWidgets *app);
void ram_watch_linux(const AppWidgets *app);
void cpu_watch_windows(const AppWidgets *app);
void ram_watch_windows(const AppWidgets *app);
double convert_to_gigabyte(const unsigned long data);
void convert_to_timestamp(const unsigned long full_seconds, const AppWidgets *app);

/*	external definitions	*/
extern int cpu_util;
extern int cpu[DOUBLE_BUFF];
extern GdkRGBA color;

#endif