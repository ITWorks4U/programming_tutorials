/*
* A primitive way to check, if you have higher access rights.
* Don't, honestly, don't write and use an application like this one.
* I already did it. :o)
*
* author:    ITWorks4U
* created:   July 1st, 2025
* updated:   Novemver 3rd, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
// for UNIX str(n)casecmp() are defined there
#include <strings.h>
#endif

#define USER_ROOT      "I am root!"

int main(int argc, char **argv) {
	/* defaults to a failure */
	int exit_state = EXIT_FAILURE;

	/* make sure to run your application with exactly 2 arguments */
	if (argc == 2) {
		/*
		* comparing the next argument with defined constant
		* and ignore case sensitive => much worse than case sensitive
		* string comparing
		*
		* by entering an expression like:
		* "i am root", "I aM rOoT", "i am ", ... this works well here => in your case it might work "well", too,
		* thus you don't need to write the full expression and that's NOT what you wanted!
		*/
		if (strncasecmp(USER_ROOT, argv[1], strlen(argv[1])) == 0) {
			puts("Yeah, you might have higher access rights to run this application...");
			exit_state = EXIT_SUCCESS;
		} else {
			puts("Nice try.");
		}
	} else {
		// get rid of the absolute path
		// the application name only is required here

		#ifdef _WIN32
		char *last_token = strrchr(argv[0], '\\');
		#else
		char *last_token = strrchr(argv[0], '/');
		#endif

		// without `\` (Windows) or `/` (UNIX)
		char *application_name = ++last_token;
		last_token = NULL;

		fprintf(stderr, "usage: %s <identification expression>\n", application_name);
	}

	return exit_state;
}