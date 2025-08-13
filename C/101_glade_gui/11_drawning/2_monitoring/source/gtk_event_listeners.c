/*
	Monitoring your system with a refresh time of 100ms.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"
#include <stdbool.h>

#if defined(__unix__)
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#elif defined(__WIN32__) || defined(__WIN64__)
#include <windows.h>
#endif

void window_destroy(void) {
	gtk_main_quit();
}

void convert_to_timestamp(const unsigned long full_seconds, const AppWidgets *app) {
	int hours = full_seconds / 3600;
	int minutes = (full_seconds - (3600 * hours)) / 60;
	int seconds = full_seconds % 60;

	gchar sys_uplink_time[BUFFER];
	memset(sys_uplink_time, '\0', BUFFER);
	sprintf(sys_uplink_time, "%02d hrs %02d min %02d sec", hours, minutes, seconds);
	gtk_label_set_text(app->lbl_sys_uptime, sys_uplink_time);
}

double convert_to_gigabyte(const unsigned long data) {
	return ((double)data / GIGABYTE);
}

void init_cpu_array(void) {
	for (int i = 0; i < DOUBLE_BUFF; i++) {
		cpu[i] = 0;
	}
}

void cpu_watch_linux(const AppWidgets *app) {
	static long time_start = 0, time_end = 0;
	static bool handle_once = false;
	bool on_continue = true;

	char line[BUFF128];
	char tmp[(BUFF128/4)];

	memset(line, '\0', BUFF128);
	memset(tmp, '\0', (BUFF128/4));

	FILE *fp = NULL;

	if ((fp = fopen("/proc/stat", "r")) == NULL) {
		on_continue = false;
	}

	if (on_continue) {
		fgets(line, BUFF128, fp);
		fclose(fp);

		sscanf(line, "%s %ld", tmp, &time_end);

		if (!handle_once) {
			handle_once = true;
			time_start = time_end;
			on_continue = false;
		}

		if (on_continue) {
			cpu_util = time_end - time_start;
			for(int i = DOUBLE_BUFF-1; i > 0; i--) {
				cpu[i] = cpu[i-1];
			}

			// for(int i = 0; i < DOUBLE_BUFF; i++) {
			// 	g_print("cpu[%d]: %d ", i, cpu[i]);
			// }
			// g_print("\n");

			cpu[0] = cpu_util;

			char cpu_percentage[TINY_BUFFER];
			memset(cpu_percentage, '\0', TINY_BUFFER);
			sprintf(cpu_percentage, "%d%%", cpu_util);

			gtk_label_set_text(app->lbl_cpu_optimization, cpu_percentage);

			time_start = time_end;
			gtk_widget_queue_draw(GTK_WIDGET(app->area_to_draw));
		}
	}
}

void ram_watch_linux(const AppWidgets *app) {
	static struct sysinfo sys;
	bool on_continue = true;

	if (sysinfo(&sys) < 0) {
		on_continue = false;
	}

	if (on_continue) {
		convert_to_timestamp(sys.uptime, app);

		gchar max_ram[TINY_BUFFER];
		memset(max_ram, '\0', TINY_BUFFER);
		sprintf(max_ram, "%.2lf GB", convert_to_gigabyte(sys.totalram));
		gtk_label_set_text(app->lbl_max_ram, max_ram);

		gchar current_ram[TINY_BUFFER];
		memset(current_ram, '\0', TINY_BUFFER);
		sprintf(current_ram, "%.2lf GB", convert_to_gigabyte(sys.totalram - sys.freeram));
		gtk_label_set_text(app->lbl_ram_in_use, current_ram);

		gchar ram_left[TINY_BUFFER];
		memset(ram_left, '\0', TINY_BUFFER);
		sprintf(ram_left, "%.2lf GB", convert_to_gigabyte(sys.freeram));
		gtk_label_set_text(app->lbl_free_ram_left, ram_left);
	}
}

void cpu_watch_windows(const AppWidgets *app) {
	/*TODO:	if the time allows, it will be completed...	*/
}

void ram_watch_windows(const AppWidgets *app) {
	/*TODO:	if the time allows, it will be completed...	*/
}

gboolean timer_handler(const AppWidgets *app) {
	#if defined(__unix__)
		cpu_watch_linux(app);
		ram_watch_linux(app);
	#elif defined (__WIN32__) || (__WIN64__)
		/*	Not tested under Windows! That's now your "homework". :o)	*/
		cpu_watch_windows(app);
		ram_watch_windows(app);
	#endif

	return TRUE;
}

gboolean draw_cpu_line(AppWidgets *app, cairo_t *cr, gpointer data) {
	cairo_set_line_width(cr, 3.0);

	for(int i = 0; i < DOUBLE_BUFF; i++) {
		cairo_set_source_rgba(cr, color.red, color.green, color.blue, color.alpha);

		/*
			double x := start position X
			double y := start position Y
		*/
		cairo_move_to(cr, (double) ((i * 4) + 10), (double) (TINY_BUFFER - cpu[i]) + 50);

		/*
			double x := width of the line graph
			double y := height of the line graph
		*/
		cairo_line_to(cr, (double) (((i+1) * 4) + 10), (double)(TINY_BUFFER - cpu[i + 1]) + 50);

		/*	draw a line from start -> end	*/
		cairo_stroke(cr);
	}

	return TRUE;
}