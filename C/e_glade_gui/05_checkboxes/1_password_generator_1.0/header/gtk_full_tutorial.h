/*
	Wanna make a password generator?
	Here you can use this!

	In the first version the user needs to enter a valid password length
	between 1 and 30 characters. To handle each input correctly a regular
	expression is in use.

	This random generated password may contain capital letters, lower letters,
	numbers and or bonus characters. At least one option must be set.
	It doesn't matter which option.

	(C) 2024 ITWorks4U
*/

#ifndef GTK_FULL_TUTOIRAL
#define	GTK_FULL_TUTORIAL

/*	libaries	*/
#include <gtk/gtk.h>
#include <stdbool.h>

/*	constants	*/
#define	GLADE_SOURCE_PATH	"glade/gtk_window.glade"
#define	NO_ERROR			"no errors detected"
#define	ERR_NO_INPUT		"no input given"
#define	ERR_INVALID_INPUT	"invalid input"
#define	ERR_CRITICAL		"critical error"
#define	ERR_NO_OPTIONS		"no options set"
#define	REGEX_PATTERN		"^(30|[1-2][0-9]|[1-9])$"			/*	only:	30 or between 10 - 29 or 1 - 9	*/

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
	/*	for any errors	*/
	GtkLabel *lbl_error;

	/*	input / output fields	*/
	GtkEntry *password_length_input;
	GtkEntry *password_output;

	/*	check boxes	*/
	GtkCheckButton *chk_capital;
	GtkCheckButton *chk_lower;
	GtkCheckButton *chk_numbers;
	GtkCheckButton *chk_bonus;
}AppWidgets;

/*	function prototypes	*/
int on_match(const char *string_to_compare);

#endif