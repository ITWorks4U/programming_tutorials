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


#include <string.h>
#include <regex.h>
#include <time.h>
#include <stdlib.h>
#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

int on_match(const char *string_to_compare) {
	int result = -1;
	regex_t reg;

	if (regcomp(&reg, REGEX_PATTERN, REG_EXTENDED) < 0) {
		return result;
	}

	result = regexec(&reg, string_to_compare, 0, NULL, 0);
	regfree(&reg);

	return result;
}

void password_generation(GtkButton *btn, AppWidgets *app) {
	char *input = (char *) gtk_entry_get_text(app->password_length_input);
	if (strlen(input) == 0) {
		/*	no input was given	*/
		gtk_label_set_text(app->lbl_error, ERR_NO_INPUT);
	} else {
		int ret_val = on_match(input);

		if (ret_val != 0) {
			/*	returned 1 or -1 only	*/
			if (ret_val == 1) {
				gtk_label_set_text(app->lbl_error, ERR_INVALID_INPUT);
			} else {
				gtk_label_set_text(app->lbl_error, ERR_CRITICAL);
			}
		} else {
			/*	everything is correct here (for that moment)*/
			if (!(with_capital_letters || with_lower_letters || with_numbers || with_bonus_characters)) {
				/*	no option was given	*/
				gtk_label_set_text(app->lbl_error, ERR_NO_OPTIONS);
			} else {
				gtk_label_set_text(app->lbl_error, NO_ERROR);

				/*	now it's time to do our thing	*/
				char word_pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789#'_-:.;,<>!\"$%&/()={}[]+*?";
				long pw_length = strtol(input, NULL, 10);
				gchar random_word[pw_length + 1];
				memset(random_word, '\0', pw_length + 1);

				long counter = 0;
				glong seconds;
				time(&seconds);
				srand(seconds);
				guint random_number = 0;

				while(counter != pw_length) {
					bool next_step = false;
					random_number = rand() % strlen(word_pool);

					if (random_number >= 0 && random_number <= 25 && with_capital_letters) {
						random_word[counter] = word_pool[random_number];
						next_step = true;
					} else if (random_number >= 26 && random_number <= 51 && with_lower_letters) {
						random_word[counter] = word_pool[random_number];
						next_step = true;
					} else if (random_number >= 52 && random_number <= 61 && with_numbers) {
						random_word[counter] = word_pool[random_number];
						next_step = true;
					} else if (random_number >= 62 && with_bonus_characters) {
						random_word[counter] = word_pool[random_number];
						next_step = true;
					}

					if (next_step) {
						counter++;
					}
				}

				gtk_entry_set_text(app->password_output, random_word);
			}
		}
	}
}

void capital_letters_toggled(void) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		/*	for each odd number => this check box is active	*/
		with_capital_letters = true;
	} else {
		with_capital_letters = false;
	}
}

void lower_characters_toggled(void) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		with_lower_letters = true;
	} else {
		with_lower_letters = false;
	}
}

void numbers_toggled(void) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		with_numbers = true;
	} else {
		with_numbers = false;
	}
}

void bonus_characters_toggled(void) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		with_bonus_characters = true;
	} else {
		with_bonus_characters = false;
	}
}