/*
* Hide the keyboard input for be able to enter anything until the switch
* has been toggled again, otherwise every other input during the current
* session will also be invisible.
*
* Depending on the used operating system the function toggle_input() is
* able to handle each case.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef _WIN32
// only for Windows systems
#include <windows.h>
#else
// only for UNIX systems
#include <unistd.h>
#include <termios.h>
#define FLAGS_FOR_ECHO (ECHO | ECHOE | ECHOK | ECHONL)
#endif

#define BUFFER_LENGTH          30

static char buffer[BUFFER_LENGTH];
static bool input_toggle = true;

// forced to define the function toggle_input with or without
// an argument depending on the used operating system

#ifdef _WIN32
void toggle_input(void) {
#else
void toggle_input(int fd) {
#endif
	#if _WIN32
	// for Windows only
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD option;

	/*	similar to tcgetattr()	*/
	GetConsoleMode(hStdin, &option);

	input_toggle = !input_toggle;

	if (input_toggle) {
		option |= ENABLE_ECHO_INPUT;
	} else {
		option &= ~ENABLE_ECHO_INPUT;
	}

	/*	similar to tcsetattr()	*/
	SetConsoleMode(hStdin, option);
	#else
	// for UNIX only
	struct termios t;

	if (tcgetattr(fd, &t) < 0) {
		perror("tcgetattr()");
		exit(EXIT_FAILURE);
	}

	input_toggle = !input_toggle;

	if (input_toggle) {
		t.c_lflag |= FLAGS_FOR_ECHO;
	} else {
		t.c_lflag &= ~FLAGS_FOR_ECHO;
	}

	/*
	* TCSANOW = 0, the change shall occur immediately
	*
	* TCSADRAIN = 1, the change shall occur after all output written to fildes is transmitted.
	* This function should be used when changing parameters that affect output.
	*
	* TCSAFLUSH = 2, the change shall occur after all output written to fildes is transmitted,
	* and all input so far received but not read shall be discarded before the change is made.
	*/
	if (tcsetattr(fd, TCSAFLUSH, &t) < 0) {
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
	#endif
}

void user_input(void) {
	memset(buffer, '\0', BUFFER_LENGTH);
	int c;
	int ctr = 0;

	printf("enter anything: ");

	// clean up any remaining characters during runtime, too
	do {
		c = getchar();
		if (c != '\n' || c!='\r') {
			buffer[ctr++] = c;
		}
	} while(c != '\n' && c !='\r' && ctr < (BUFFER_LENGTH - 1));

	buffer[ctr] = '\0';
}

int main(void) {
	/* --- normal usage --- */
	puts("\t---\tnormal\t---\t");
	user_input();
	printf("visible input: %s\n", buffer);

	/* --- hiding ---      */
	puts("\t---\thidden\t---\t");
	
	#ifdef _WIN32
	toggle_input();
	#else
	toggle_input(STDIN_FILENO);
	#endif

	user_input();
	printf("hidden input: %s\n", buffer);

	/* --- restore ---     */
	puts("\t---\trestored\t---\t");
	
	#ifdef _WIN32
	toggle_input();
	#else
	toggle_input(STDIN_FILENO);
	#endif

	user_input();
	printf("visible input: %s\n", buffer);

	return EXIT_SUCCESS;
}