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

int main(void) {
	puts("Warning: This sample will BLOW UP your current RAM! Make sure, that you REALLY know what YOU do!");

	int ctr = 0;

	/* Don't, seriously, don't do this! */

	while(true) {
		/*
		* ptr will always been overwritten and the previous area is not going
		* to release or an another pointer refers to this => Extremely memory
		* leaks are incoming here!
		*/
		void *ptr = malloc(GIGABYTE);

		if (ptr == NULL) {
			fprintf(stderr, "malloc refused after %d GB, error message: %s\n", ctr, strerror(errno));
			return EXIT_FAILURE;
		}

		memset(ptr, 1, GIGABYTE);
		printf("allocated %d GB...\n", ++ctr);
	}

	return EXIT_SUCCESS;
}