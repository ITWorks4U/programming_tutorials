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


#include "../header/gtk_full_tutorial.h"

/*	boolean states are false by default	*/
bool with_capital_letters = false;
bool with_lower_letters = false;
bool with_numbers = false;
bool with_bonus_characters = false;