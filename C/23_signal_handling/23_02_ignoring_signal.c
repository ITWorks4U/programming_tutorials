#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

#ifdef _WIN32
//	on a Windows machine, the function strsignal() is not defined,
//	so we have to write our own signal string function instead
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

//	handling a signal by using an own defined function
//	this function MUST be a void function with a signle integer as an argument
//
//	define signal functions can be used to determine non-critical and also
//	critical signal(s) => you can use multiple functions to handle different
//	signals
void signal_handler(int sig_number) {
	printf("received the current signal: %d <=> ", sig_number);

	#ifdef _WIN32
	printf("%s\n", strsignal_windows(sig_number));
	#else
	//	strsignal is defined in <string.h>
	printf("%s\n", strsignal(sig_number));
	#endif
	exit(0);
}

int main(void) {
	// register some signals
	signal(SIGTERM, signal_handler);

	//	ignore that signal
	// => since SIGINT is now ignored, you'll never be able
	//    to hit Ctrl + C and terminate the application
	signal(SIGINT, SIG_IGN);

	#ifndef _WIN32
	//	SIGKILL, however, can't be handled or ignored
	//	=> not available on Windows
	// signal(SIGKILL, signal_handler);
	#endif

	puts("Waiting patiently...");
	while(true) {
		//	do nothing here
	}

	puts("Oh, this shall not be happen here...");
	return EXIT_SUCCESS;
}