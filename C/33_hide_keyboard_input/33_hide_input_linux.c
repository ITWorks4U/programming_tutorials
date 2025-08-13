/*	for Linux only => might also work on macOS	*/

#ifdef _WIN32
#error "This sample does not work on a Windows machine."
#else
#ifdef __cplusplus
#warning "It's not clear, if this also works fine on C++."
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <stdbool.h>

#define BUFFER_LENGTH	30
#define FLAGS_FOR_ECHO (ECHO | ECHOE | ECHOK | ECHONL)

static char buffer[BUFFER_LENGTH];
static bool input_toggle = true;

void toggle_input(int fd) {
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
}

void user_input(void) {
	memset(buffer, '\0', BUFFER_LENGTH);
	int c;
	int ctr = 0;

	printf("enter anything: ");

	do {
		c = getchar();
		if (c != '\n' || c!='\r') {
			buffer[ctr++] = c;
		}
	} while(c != '\n' && c !='\r' && ctr < (BUFFER_LENGTH - 1));

	buffer[ctr] = '\0';
}

int main(void) {
	/*	---		normal usage	---	*/
	puts("\t---\tnormal\t---\t");
	user_input();
	printf("visible input: %s\n", buffer);

	/*	---		hiding			---	*/
	puts("\t---\thidden\t---\t");
	
	toggle_input(STDIN_FILENO);
	user_input();
	printf("hidden input: %s\n", buffer);

	/*	---		restore			---	*/
	puts("\t---\trestored\t---\t");
	
	toggle_input(STDIN_FILENO);
	user_input();
	printf("visible input: %s\n", buffer);

	return EXIT_SUCCESS;
}
#endif