/*
* THIS IS FOR EDUCATIONAL PURPOSE ONLY!
* IT'S NOT A GUIDELINE FOR "How to programming a computer virus" OR ELSE!
* USE THIS AT YOUR OWN RISK!
*
* YOU SHOULD ALSO KNOW THAT YOUR RUNNING SYSTEM IS ALSO AFFECTED, WHEN NO MORE MEMORY
* IS AVAILABLE. SO YOU HAVE TO REBOOT YOUR SYSTEM! THIS MAY ALSO AFFECT YOUR HARDWARE ON RUNTIME!
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

// 1 << 30 is identical to 1024*1024*1024
#define GIGABYTE 1 << 30
#define COLOR_RED      "\x1b[31m"
#define NORMAL_COLOR   "\x1b[0m"

int main(void) {
	fprintf(
		stderr,
		"%sWARNING: This sample will BLOW UP your current RAM!!! Make sure, that you REALLY know what YOU do!!%s\n",
		COLOR_RED, NORMAL_COLOR
	);

	int ctr = 0;

	/* Don't, seriously, don't do this! */

	while(true) {
		/*
		* ptr will always been overwritten and the previous area is NEVER going
		* to release or an another pointer refers to this => Extremely memory
		* leaks are incoming here!
		*/
		void *ptr = malloc(GIGABYTE);

		if (ptr == NULL) {
			fprintf(stderr, "malloc refused after %d GB, error message: %s\n", ctr, strerror(errno));
			return EXIT_FAILURE;
		}

		// forces the system to keep the previoulsy allocated memory of 1 GB during runtime
		memset(ptr, 1, GIGABYTE);
		printf("allocated %d GB...\n", ++ctr);
	}

	return EXIT_SUCCESS;
}