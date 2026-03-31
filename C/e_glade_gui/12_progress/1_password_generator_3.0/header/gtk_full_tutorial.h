/*
	Wanna make a password generator?
	Here you can use this!

	In the third version the user chooses a password length between 1 and 50 characters
	by using a spin button. Every 500 ms a new random generated password with the certain
	length will be created. It stops, when the user presses the "stop" button or closes
	the application.

	This random generated password may contain capital letters, lower letters,
	numbers and or bonus characters. At least one option must be set.
	It doesn't matter which option.

	You also gets an advise about your password strength.

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

extern bool with_capital_letters;
extern bool with_lower_letters;
extern bool with_numbers;
extern bool with_bonus_characters;
extern bool toggle_button_state;

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

	/*	misc	*/
	GtkMessageDialog *message;
	GtkButton *toggle_button;
	GtkLevelBar *password_strength;
	GtkProgressBar *timer_progress;
}AppWidgets;

/*	function prototypes	*/
gboolean refresh_password(const AppWidgets *app);
void toggle_object_availability(const AppWidgets *app, bool isActive);

#endif