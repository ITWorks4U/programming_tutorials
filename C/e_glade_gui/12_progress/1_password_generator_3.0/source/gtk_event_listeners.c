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

#include <string.h>
#include <time.h>
#include "../header/gtk_full_tutorial.h"

static gfloat progress_bar_value = 0.0F;

gboolean refresh_password(const AppWidgets *app) {
	if (toggle_button_state) {
		static int ctr = 0;

		/*	generating each 500 ms a new password	*/
		if (ctr == 0) {
			gint spinNumber = gtk_spin_button_get_value_as_int(app->spin_button);
			gchar random_word[spinNumber + 1];
			memset(random_word, '\0', spinNumber + 1);

			gint counter = 0;
			srand(time(NULL));
			guint random_number = 0;

			while(counter != spinNumber) {
				bool next_step = false;
				random_number = rand() % strlen(WORD_POOL);

				if (random_number >= 0 && random_number <= 25 && with_capital_letters) {
					random_word[counter] = WORD_POOL[random_number];
					next_step = true;
				} else if (random_number >= 26 && random_number <= 51 && with_lower_letters) {
					random_word[counter] = WORD_POOL[random_number];
					next_step = true;
				} else if (random_number >= 52 && random_number <= 61 && with_numbers) {
					random_word[counter] = WORD_POOL[random_number];
					next_step = true;
				} else if (random_number >= 62 && with_bonus_characters) {
					random_word[counter] = WORD_POOL[random_number];
					next_step = true;
				}

				if (next_step) {
					counter++;
				}
			}

			gtk_entry_set_text(app->password_output, random_word);
		}

		/*	updating progress bar each 100ms	*/
		if (progress_bar_value < 0.1F) {
			progress_bar_value = 1.0F;
			gtk_progress_bar_set_fraction(app->timer_progress, progress_bar_value);
		} else {
			progress_bar_value -= 0.10F;
			gtk_progress_bar_set_fraction(app->timer_progress, progress_bar_value);
		}

		ctr++;
		if (ctr == 5) {
			ctr = 0;
		}
	} else {
		progress_bar_value = 0.0F;
		gtk_progress_bar_set_fraction(app->timer_progress, progress_bar_value);
		gtk_entry_set_text(app->password_output, "");
	}

	return TRUE;
}

void window_destroy(void) {
	gtk_main_quit();
}

void spin_value_changed(GtkSpinButton *spinBtn, AppWidgets *app) {
	static gdouble password_strength = 0.0;
	gint spinNumber = gtk_spin_button_get_value_as_int(app->spin_button);

	if (spinNumber < 8) {
		password_strength = 0.0;
	} else if (spinNumber >= 8 && spinNumber <= 14) {
		password_strength = 0.2;
	} else if (spinNumber >= 15 && spinNumber <= 23) {
		password_strength = 0.4;
	} else if (spinNumber >= 24 && spinNumber <= 31) {
		password_strength = 0.8;
	} else {
		password_strength = 1.0;
	}

	gtk_level_bar_set_value(app->password_strength, password_strength);
}

void toggle_object_availability(const AppWidgets *app, bool isActive) {
	gtk_widget_set_sensitive(GTK_WIDGET(app->spin_button), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_bonus), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_capital), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_lower), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_numbers), isActive);
}

void password_generation(GtkButton *btn, AppWidgets *app) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		bool onNoOptionIsGiven = !(with_capital_letters || with_lower_letters || with_numbers || with_bonus_characters);

		if (onNoOptionIsGiven) {
			/*	no option was given	*/
			gtk_widget_show(GTK_WIDGET(app->message));
			gtk_dialog_run(GTK_DIALOG(app->message));
			gtk_widget_hide(GTK_WIDGET(app->message));
			counter--;
		} else {
			toggle_object_availability(app, false);
			toggle_button_state = true;
			progress_bar_value = 1.0;
			gtk_progress_bar_set_fraction(app->timer_progress, progress_bar_value);
			gtk_button_set_label(app->toggle_button, "STOP!");
		}
	} else {
		toggle_object_availability(app, true);
		toggle_button_state = false;
		gtk_button_set_label(app->toggle_button, "START!");
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