#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "30_threading.h"

// global settings
bool coord_on_continue = true;
long test_array[MAX_BUFFER];

void time_amount(double seconds) {
	double hours = floor(seconds / 3600);
	double minutes = floor(fmod(seconds, 3600) / 60);
	double secs = floor(fmod(seconds, 60));

	// fractional part of the second
	double fractional = seconds - floor(seconds);
	double milliseconds = floor(fractional * 1000);
	double microseconds = floor(fmod(fractional * 1e6, 1000));
	double nanoseconds  = floor(fmod(fractional * 1e9, 1000));

	// it may happen, that the µ symbol can't be displayed correctly
	fprintf(
		stdout,
		"time amount: %.0lf h, %.0lf min, %.0lf s, %.0lf ms, %.0lf (micro)s, %.0lf ns\n",
		hours, minutes, secs, milliseconds, microseconds, nanoseconds
	);
}

void load_numbers_from_file(void) {
	char content_random_numbers[MAX_BUFFER];
	memset(content_random_numbers, '\0', sizeof(content_random_numbers));

	FILE *f = fopen(FILE_TO_USE, "r");
	if (f == NULL) {
		perror("fopen()");
		coord_on_continue = false;
		return;
	}

	// load the full content to the C-string
	while ((fgets(content_random_numbers, MAX_BUFFER - 1, f)) != NULL);
	fclose(f);

	// get each single element by tokenizing ',' and ' '
	char delimiter[] = ", ";
	char* token = strtok(content_random_numbers, delimiter);
	int ctr = 0;

	while (token != NULL) {
		test_array[ctr] = strtol(token, NULL, 0);
		ctr++;

		token = strtok(NULL, delimiter);
	}
}

void bubble_sort(void) {
	clock_t begin = clock();

	for(int i = 0; i < MAX_BUFFER - 1; i++) {
		for(int j = 0; j < MAX_BUFFER - i - 1; j++) {
			if (test_array[i] > test_array[j]) {
				long tmp = test_array[i];
				test_array[i] = test_array[j];
				test_array[j] = tmp;
			}
		}
	}

	clock_t end = clock();
	time_amount(((double)(end - begin) / CLOCKS_PER_SEC));
}

/*
* --------------
* thead function for any known OS
* --------------
*/

#ifdef THREADING_ON_WINDOWS
DWORD WINAPI bubble_thread(LPVOID arg) {
	bubble_sort();
	return 0;
}

void print_error_message(const char *message) {
	DWORD err = GetLastError();
	char* buf = NULL;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, err,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR)&buf, 0, NULL
	);

	fprintf(stderr, "%s failed with error %lu: %s", message, err, buf);
	LocalFree(buf);
}
#endif

#ifdef THREADING_ON_LINUX
void *bubble_thread(void *arg) {
	bubble_sort();
	return NULL;
}
#endif