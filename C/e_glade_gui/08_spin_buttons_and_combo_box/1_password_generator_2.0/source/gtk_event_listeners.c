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

#include <string.h>
#include <time.h>
#include "../header/gtk_full_tutorial.h"

void window_destroy(void) {
	gtk_main_quit();
}

void spin_value_changed(GtkSpinButton *spinBtn, AppWidgets *app) {
	gint spinNumber = gtk_spin_button_get_value_as_int(app->spin_button);

	if (spinNumber < 8) {
		gtk_label_set_text(app->lbl_password_strength, TOO_WEAK);
	} else if (spinNumber >= 8 && spinNumber <= 14) {
		gtk_label_set_text(app->lbl_password_strength, MEDIUM);
	} else if (spinNumber >= 15 && spinNumber <= 23) {
		gtk_label_set_text(app->lbl_password_strength, STRONG);
	} else if (spinNumber >= 24 && spinNumber <= 31) {
		gtk_label_set_text(app->lbl_password_strength, MUCH_STRONGER);
	} else {
		gtk_label_set_text(app->lbl_password_strength, OVER_9000);
	}
}

void password_generation(GtkButton *btn, AppWidgets *app) {
	if (!(with_capital_letters || with_lower_letters || with_numbers || with_bonus_characters)) {
		/*	no option was given	*/
		gtk_widget_show(GTK_WIDGET(app->message));
		gtk_dialog_run(GTK_DIALOG(app->message));
		gtk_widget_hide(GTK_WIDGET(app->message));
	} else {
		/*	now it's time to do our thing	*/
		gint spinNumber = gtk_spin_button_get_value_as_int(app->spin_button);
		char word_pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789#'_-:.;,<>!\"$%&/()={}[]+*?";
		gchar random_word[spinNumber + 1];
		memset(random_word, '\0', spinNumber + 1);

		gint counter = 0;
		glong seconds;
		time(&seconds);
		srand(seconds);
		guint random_number = 0;

		while(counter != spinNumber) {
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