/*
	Wanna make a password generator?
	Here you can use this!

	The forth version comes with a menu to control the application.
	The real menu allows you to use an about dialogue, whereas a
	tab view gives you control control about the application itself.

	Unlike to version 3.0 every 5 seconds a new password is going to create,
	whereas an overview tells you how long this password is available for you.
	
	By using the option to exclude similar looking characters, these are not
	part of the random generated password.

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>
#include <stdbool.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	WORD_POOL			"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789#'_-:.;,<>!\"$%&/()={}[]+*?"
#define	BUTTON_START		"START"
#define	BUTTON_STOP			"STOP"
#define	CONTENT_LENGTH		30
#define	NBR_LENGTH			2
#define	TIMER_START_STR		"next password in "
#define	TIMER_END_STR		" seconds"
#define	TIMER_END_STR_2		" second"			/*	only, if 1 *second* is left	*/

extern bool with_capital_letters;
extern bool with_lower_letters;
extern bool with_numbers;
extern bool with_bonus_characters;
extern bool toggle_button_state;
extern bool with_excluding_characters;

/*	structures	*/
typedef struct GtkObjects {
	/*	input / output fields	*/
	GtkSpinButton *spin_button;
	GtkEntry *password_output;

	/*	check boxes	*/
	GtkCheckButton *chk_capital;
	GtkCheckButton *chk_lower;
	GtkCheckButton *chk_numbers;
	GtkCheckButton *chk_bonus;
	GtkCheckButton *chk_excluding;

	/*	misc	*/
	GtkMessageDialog *message;
	GtkButton *toggle_button;
	GtkLevelBar *password_strength;
	GtkAboutDialog *about_window;
	GtkLabel *lbl_countdown;
}AppWidgets;

/*	function prototypes	*/
gboolean refresh_password(const AppWidgets *app);
void toggle_object_availability(const AppWidgets *app, bool isActive);
void cleanUpTheMess();
bool onMatchForExludingCharacter(const char sign);

#endif