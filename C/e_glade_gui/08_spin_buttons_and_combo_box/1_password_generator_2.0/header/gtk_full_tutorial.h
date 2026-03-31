/*
	Wanna make a password generator?
	Here you can use this!

	In the second version the user chooses a password length between 1 and 30 characters
	by using a spin button. So, a regular expression check is no longer required here.

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
#define	TOO_WEAK			"Too weak!"									/*	<8 character length	*/
#define	MEDIUM				"Could be better..."						/*	8-14	*/
#define	STRONG				"Yeah... \"strong\"."						/*	15-23	*/
#define	MUCH_STRONGER		"Yepp, THIS is strong!"						/*	24-31	*/
#define	OVER_9000			"Bro, even the universe ends earlier..."	/*	32-50	*/

/*
	global boolean values

	important:	must be defined with extern and in an external file
	these data types must be set, otherwise multiple definitions of
	boolean expressions or undefined reference for boolean expressions
	appears on compile time
*/
extern bool with_capital_letters;
extern bool with_lower_letters;
extern bool with_numbers;
extern bool with_bonus_characters;

/*	structures	*/
typedef struct GtkObjects {
	/*	strength for certain password	*/
	GtkLabel *lbl_password_strength;

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
}AppWidgets;

#endif