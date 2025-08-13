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

#include "../header/gtk_full_tutorial.h"

/*	boolean states are false by default	*/
bool with_capital_letters = false;
bool with_lower_letters = false;
bool with_numbers = false;
bool with_bonus_characters = false;