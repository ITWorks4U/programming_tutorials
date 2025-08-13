/*
	The different buttons and their purpose...

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	BUFFER				100

/*	structures	*/
typedef struct GtkObjects {
	GtkLabel *lbl_normal_button;
	GtkLabel *lbl_spin_button;
	GtkLabel *lbl_toggle_button;
	GtkLabel *lbl_menu_button;
	GtkLabel *lbl_lock_button;
	GtkLabel *lbl_switch_button;
	GtkLabel *lbl_model_button;
	GtkLabel *lbl_file_chooser_button;
	GtkLabel *lbl_color_chooser_button;
	GtkLabel *lbl_font_button;
	GtkLabel *lbl_link_button;
	GtkLabel *lbl_scale_button;
	GtkLabel *lbl_volume_button;
	GtkLabel *lbl_app_chooser_button;

	GtkSpinButton *spin_btn;
	GtkFileChooserButton *file_chooser_button;
	GtkSwitch *btn_switch;
	GtkColorButton *color_btn;
	GtkFontButton *font_button;
	GtkLinkButton *link_btn;
	GtkScaleButton *scale_btn;
	GtkVolumeButton *volume_btn;
	GtkAppChooserButton *app_btn;
}AppWidgets;

#endif