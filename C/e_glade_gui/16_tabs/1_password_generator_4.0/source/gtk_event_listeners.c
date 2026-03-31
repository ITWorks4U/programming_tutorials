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

#include <string.h>
#include <time.h>
#include "../header/gtk_full_tutorial.h"

/// @brief Check, if this character is a excluding character
/// @param sign character to compare
/// @return true, if it's an excluding character; false, otherwise
bool onMatchForExludingCharacter(const char sign) {
	return sign == 'I' || sign == 'l' || sign == '1' || sign == 'O' || sign == '0';
}

/// @brief Create a new password when the time duration expires.
/// @param app control structure
/// @return true only (GTK timer)
gboolean refresh_password(const AppWidgets *app) {
	if (toggle_button_state) {
		static int ctr = 0;

		/*	generating a password every 5 seconds	*/
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
					char tmp = WORD_POOL[random_number];

					if (with_excluding_characters) {
						if (!onMatchForExludingCharacter(tmp)) {
							random_word[counter] = tmp;
							next_step = true;
						}
					} else {
						random_word[counter] = tmp;
						next_step = true;
					}
				} else if (random_number >= 26 && random_number <= 51 && with_lower_letters) {
					char tmp = WORD_POOL[random_number];

					if (with_excluding_characters) {
						if (!onMatchForExludingCharacter(tmp)) {
							random_word[counter] = tmp;
							next_step = true;
						}
					} else {
						random_word[counter] = tmp;
						next_step = true;
					}
				} else if (random_number >= 52 && random_number <= 61 && with_numbers) {
					char tmp = WORD_POOL[random_number];

					if (with_excluding_characters) {
						if (!onMatchForExludingCharacter(tmp)) {
							random_word[counter] = tmp;
							next_step = true;
						}
					} else {
						random_word[counter] = tmp;
						next_step = true;
					}
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

		/*	updating the label every one second	*/
		if (ctr % 4 == 0) {
			static int timer_number = 6;
			char str_timer[CONTENT_LENGTH];
			memset(str_timer, '\0', CONTENT_LENGTH);
			memcpy(str_timer, TIMER_START_STR, strlen(TIMER_START_STR));

			char str_number[NBR_LENGTH];
			memset(str_number, '\0', NBR_LENGTH);

			timer_number--;
			sprintf(str_number, "%d", timer_number);
			strcat(str_timer, str_number);

			if (timer_number == 1) {
				timer_number = 6;
				strcat(str_timer, TIMER_END_STR_2);
			} else {
				strcat(str_timer, TIMER_END_STR);
			}

			gtk_label_set_text(app->lbl_countdown, str_timer);
		}

		ctr++;

		if (ctr == 20) {
			ctr = 0;
		}
	} else {
		gtk_entry_set_text(app->password_output, "");
		gtk_label_set_text(app->lbl_countdown, "");
	}

	return TRUE;
}

/// @brief callback function when the value of the spin button has been changed (by mouse wheel only)
/// @param spinBtn no usage here
/// @param app control structure
void spin_value_changed(GtkSpinButton *spinBtn, AppWidgets *app) {
	gdouble password_strength = 0.0;
	gint spinNumber = gtk_spin_button_get_value_as_int(app->spin_button);

	if (spinNumber < 8) {
		password_strength = 0.0;
	} else if (spinNumber >= 8 && spinNumber <= 14) {
		password_strength = 0.2;
	} else if (spinNumber >= 15 && spinNumber <= 23) {
		password_strength = 0.4;
	} else if (spinNumber >= 24 && spinNumber <= 31) {
		password_strength = 0.6;
	} else if (spinNumber >= 32 && spinNumber <= 40) {
		password_strength = 0.8;
	} else {
		password_strength = 1.0;
	}

	gtk_level_bar_set_value(app->password_strength, password_strength);
}

/// @brief toggeling the availability of objects during process
/// @param app control structure
/// @param isActive toggle switch for certain elements
void toggle_object_availability(const AppWidgets *app, bool isActive) {
	gtk_widget_set_sensitive(GTK_WIDGET(app->spin_button), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_bonus), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_capital), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_lower), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_numbers), isActive);
	gtk_widget_set_sensitive(GTK_WIDGET(app->chk_excluding), isActive);
}

/// @brief callback function, when the button START/STOP has been pressed
/// @param btn no usage
/// @param app constrol structure
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
			gtk_button_set_label(app->toggle_button, BUTTON_STOP);
		}
	} else {
		toggle_object_availability(app, true);
		toggle_button_state = false;
		gtk_button_set_label(app->toggle_button, BUTTON_START);
	}
}

/*	event functions	*/
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

void toggle_excluded_characters(void) {
	static int counter = 0;
	counter++;

	if (counter % 2 == 1) {
		with_excluding_characters = true;
	} else {
		with_excluding_characters = false;
	}
}

void cleanUpTheMess() {
	gtk_main_quit();
}

void window_destroy(void) {
	cleanUpTheMess();
}

void close_application(void) {
	cleanUpTheMess();
}

void open_help_window(GtkImageMenuItem *imi, AppWidgets *app) {
	gtk_widget_show(GTK_WIDGET(app->about_window));
	gtk_dialog_run(GTK_DIALOG(app->about_window));
	gtk_widget_hide(GTK_WIDGET(app->about_window));
}