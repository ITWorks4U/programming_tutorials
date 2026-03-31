/*
* The volatile keyword is a qualifier that is applied to
* a variable when it's declared. It tells the compiler
* that the value of the variable may change at any time.
*
* Without any action being taken by the code the compiler
* finds nearby. The implications of this are quite serious.
*
* However, a variable should be declared volatile whenever it's
* value could change unexpectedly. In practice, only three types of cases could appear:
* -	memory mapped peripheral registers
* -	global variables modified by an interrupt service routine (demonstraded here)
* -	global variables accessed by multiple tasks within a multi-threaded application
*
* To receive the signal, compile your application without optimizations,
* in that case with -O(1,2,3,...) flag.
*
* To see the difference, try to compile your application without
* the volatile keyword, but WITH -O flag. In that case you'll
* receive your signal, however, your infinite loop is still
* available and you'll never see the end of your application,
* unless you'll kill your current process.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

volatile static bool signal_flag = false;

// on Windows systems, the function strsignal() is not defined, so we need
// to manage an alternative way here
#ifdef _WIN32
char *strsignal_windows(int signum) {
	switch (signum) {
		case SIGINT:
			return "interrupt (SIGINT)";
		case SIGILL:
			return "illegal instruction - invalid function image (SIGILL)";
		case SIGFPE:
			return "floating-point exception (SIGFPE)";
		case SIGSEGV:
			return "segmentation violation (SIGSEGV)";
		case SIGABRT:
			return "Abnormal termination (SIGABRT)";
		case SIGTERM:
			return "Software termination signal from kill (SIGTERM)";
		case SIGBREAK:
			return "ctrl-break-sequence (SIGBREAK)";
		default:
			return "Unknown signal";
	}
}
#endif

// signal handling comes in chapter 23
void signal_handler(int signum) {
	printf("received signal: %d (", signum);

	#ifdef _WIN32
	printf("%s)\n", strsignal_windows(signum));
	#else
	printf("%s)\n", strsignal(signum));
	#endif

	// when SIGINT (Ctrl + C) has been detected on any time,
	// then the >>volatile<< signal_flag is going to update
	if (signum == SIGINT) {
		signal_flag = true;
	}
}

int main(void) {
	signal(SIGINT, signal_handler);
	puts("waiting patiently...");

	while(!signal_flag) {
		// nothing to do here
	}

	puts("Signal received. End of application.");
	return EXIT_SUCCESS;
}