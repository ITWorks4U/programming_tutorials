#ifdef __cplusplus
#error "By using a C++ compiler this application may be handled like a threat or it leads to an undefined behavior. Use a C compiler instead."
#else

/*
* Do you need a new password and you're tired to use an already, perhaps not good application?
* Then create your own application instead. ;-)
*
* - This application is written in C only.
* - It also works with C++.
* - tested with Linux (Mint 21.1), Raspberry OS Lite, Windows
*
* Have fun! :)
*
* PS:
* - macros were handled in chapter 17, but these are also implemented here
*/
#include <stdio.h>
#include <stdlib.h>

// for memset()
#include <string.h>

#include <time.h>

/* a pool of available characters => '%' must be marked with %% */
#define CHAR_POOL    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!\"$%%&/()=?;,:._-'#*+\\{}[]"
#define PASSWD_LEN   101

// ---------------
// ---------------
// ---------------

// The application can be used with a single argument only, where it must be an integer only.
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage %s <length for a random password in a range between 1 and 100>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// check, if the second argument is an integer
	// => at this moment, we don't have an idea how to reveal a real
	// number for argv[1]
	//
	// if strtol returns 0, then this has two possible results:
	// - input was a real 0, where a password of a length of 0 is not allowed
	// - input contained anything, which could have been stored to **_entptr or NULL for: "We don't care."
	long result = strtol(argv[1], NULL, 10);

	if (result == 0 || result > 100) {
		fprintf(stderr, "Input was either not in the range between [1,100] or it was not a number\n");
		return EXIT_FAILURE;
	}

	// HINT: usually, this instruction below might not work on every machine
	// char passwd[result + 1];

	// so we have to use an alternative way instead:
	char passwd[PASSWD_LEN];
	memset(passwd, '\0', PASSWD_LEN);

	srand(time(NULL));
	int counter = 0;

	while(counter != result) {
		int rand_nbr = rand() % strlen(CHAR_POOL);
		passwd[counter] = CHAR_POOL[rand_nbr];
		counter++;
	}

	printf("your random password: %s\n", passwd);

	return EXIT_SUCCESS;
}
#endif