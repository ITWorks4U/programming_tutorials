/*
* Handling signals allows you to react / interact, when
* a signal at any time on any event may appear. Some signals can
* be handled, however, not every signal is able to
* handle. It depends on your system, the compiler, etc.
*
* Depending on the OS you're working on not every signal is known.
*
* You also may block an incoming signal, whereas not every
* signal is able to block. It also depends on your system,
* compiler, etc.
*
* A signal handling can also be used for "exception handling", however,
* NEVER assume, that a signal handling is equal to an exception handling!
*
* | --------------------| ------------------------------|
* |  signal handling    |           effect              |
* | --------------------| ------------------------------|
* |    SIGDFL           | default signal handling;      |
* |                     | let the system handle the     |
* |                     | signal(s)                     |
* | --------------------| ------------------------------|
* |    SIGIGN           | ignore that signal; use this  |
* |                     | with care, because that       |
* |                     | certain signal can never be   |
* |                     | handled, whereas only a few   |
* |                     | signals, like SIGINT, can be  |
* |                     | ignored                       |
* | --------------------| ------------------------------|
* | any signal function | handle the certain signal in  |
* |                     | a customized function instead |
* | --------------------| ------------------------------|
*/

#include <stdio.h>
#include <stdlib.h>

// outside of Windows, this header file contains the
// strsignal() function
#include <string.h>

// contains signal types, functions, ...
#include <signal.h>

#define BUFFER_LENGTH	100

#ifdef _WIN32
// on a Windows machine, the function strsignal() is not defined,
// so we have to write our own signal string function instead
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

// handling a signal by using an own defined function
// this function MUST be a void function with a signle integer as an argument
//
// define signal functions can be used to determine non-critical and also
// critical signal(s) => you can use multiple functions to handle different
// signals
void signal_handler(int sig_number) {
	printf("received the current signal: %d <=> ", sig_number);

	#ifdef _WIN32
	printf("%s\n", strsignal_windows(sig_number));
	#else
	// strsignal is defined in <string.h>
	printf("%s\n", strsignal(sig_number));
	#endif

	// usually, when a signal has been triggerd and this has also been
	// handled, the application shall be terminated; it depends on you
	// if the application terminates normal or with the received signal
	// number instead
	exit(0);
}

int main(void) {
	// register some signals => SIGINT and SIGTERM will be handled here
	// => that does not mean, that only those signals may exist in your
	//    application only, the other signals left also may appear, depending
	//    on your used instructions
	//
	// NOTE:  On a Windows machine SIGTERM might not be able to handle, when
	//        the current process has been termianted in the task manager or
	//        by using taskkill /f /pid <pid to use>.
	//
	//        If you want to see, that also SIGTERM is able to "handle",
	//        use the function raise(int _signum).
	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);

	#ifndef _WIN32
	// SIGKILL, however, can't be handled or ignored
	// => not available on Windows
	// signal(SIGKILL, signal_handler);
	#endif

	// do something...
	char input_buffer[BUFFER_LENGTH];
	memset(input_buffer, '\0', BUFFER_LENGTH);

	// instead of entering anything, just press
	// Ctrl + C or terminate the application to
	// to trigger one of the registered signals
	printf("Enter something... ");
	fgets(input_buffer, BUFFER_LENGTH - 1, stdin);

	int c;
	while((c = getchar()) != '\n' && c != EOF);

	size_t length = strlen(input_buffer);
	if (length > 0 && input_buffer[length - 1] == '\n') {
		input_buffer[length - 1] = '\0';
	}

	printf("%s\n", input_buffer);

	return EXIT_SUCCESS;
}