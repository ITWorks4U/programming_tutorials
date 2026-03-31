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

#include "../header/gtk_full_tutorial.h"

/*	boolean states are false by default	*/
bool with_capital_letters = false;
bool with_lower_letters = false;
bool with_numbers = false;
bool with_bonus_characters = false;
bool toggle_button_state = false;
bool with_excluding_characters = false;