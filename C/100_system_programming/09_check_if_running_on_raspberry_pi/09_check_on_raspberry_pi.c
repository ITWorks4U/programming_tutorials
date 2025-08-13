/**
*	Check, if this application runs on a Raspberry Pi.
*	At this point this shall run successfully on any known model.
*
*	author:		ITWorks4U
*	created:	July 4th, 2025
*	updated:	July 5th, 2025
*
*	youtube:	@itworks4u
*	github:		ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>

#define	RPI_MODEL_MAX_LENGTH	128
#define	RASPBERRY_PI_PATTERN	"Raspberry Pi"
#define	NEW_RASPBERRY_PI_PATH	"/proc/device-tree/model"
#define	OLD_RASPBERRY_PI_PATH	"/proc/cpuinfo"

static FILE *fp = NULL;

void clean_up(void) {
	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}
}

void handle_signals(int signum) {
	/*
	* by receiving incoming signals clean up the mess
	* to make sure, that the *fp will be set to NULL
	*
	* attention:
	* on a Windows machine, not every signal is known
	* => take a look to chapter 23
	*/
	//printf("incoming signal: %d (%s)...\n", signum, strsignal(signum));
	clean_up();

	//printf("*fp is NULL? => %s\n", fp == NULL ? "yes" : "no");
	exit(EXIT_SUCCESS);
}

bool on_running_with_raspberry_pi(void) {
	char model[RPI_MODEL_MAX_LENGTH];
	memset(model, '\0', RPI_MODEL_MAX_LENGTH);

	/* for modern Raspberry Pi only */
	fp = fopen(NEW_RASPBERRY_PI_PATH, "r");
	if (fp != NULL) {
		fread(model, 1, RPI_MODEL_MAX_LENGTH - 1, fp);
		return (strstr(model, RASPBERRY_PI_PATTERN) != NULL);
	}

	/* fallback to older systems */
	fp = fopen(OLD_RASPBERRY_PI_PATH, "r");
	if (fp != NULL) {
		while(fgets(model, RPI_MODEL_MAX_LENGTH - 1, fp) != NULL) {
			if (strstr(model,RASPBERRY_PI_PATTERN) != NULL) {
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	/*	possible incoming signals	*/
	signal(SIGINT, handle_signals);
	signal(SIGTERM, handle_signals);
	signal(SIGABRT, handle_signals);

	atexit(clean_up);

	printf("This application runs on a %s: %s\n", RASPBERRY_PI_PATTERN,
		on_running_with_raspberry_pi() ? "yes" : "no");

	return EXIT_SUCCESS;
}
