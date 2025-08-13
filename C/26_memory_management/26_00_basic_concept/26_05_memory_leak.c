/*
* Do you really think, that an allocated memory
* is automatically be freed, when an exception
* has been occurred?
*/

#warning	"Memory leak incoming!"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct Math {
	int a;
	int b;
};

void handle_exception(int signum) {
	printf("error code: %d => division by 0 is not allowed\n", signum);
	exit(signum);
}

int main(void) {
	signal(SIGSEGV, handle_exception);

	for(int i = 10; i >= -10; i -= 2) {
		struct Math *m = (struct Math *) calloc(1, sizeof(struct Math));
		m->a = 10;
		m->b = i;

		printf("%d / %d = %d\n", m->a, m->b, m->a / m->b);

		//	at this point m shall automatically be released, but what happens
		//	on an "exception"? It doesn't matter, if you're using C++ with a
		//	try-catch-block instead
		//
		//	when an "exception handling" has been done and the application terminated
		//	the last allocated memory for m is still not freed => memory leak
		free(m);
	}

	return EXIT_SUCCESS;
}