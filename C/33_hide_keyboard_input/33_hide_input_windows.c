/*
* Hiding the user input from the keyboard.
* This is often used to enter a  password,
* which shall not be seen by anyone.
*/

#ifndef _WIN32
#error "This sample works on a Windows machine (32 bit / 64 bit) only."
#else
#ifdef __cplusplus
#warning "It's not clear, if this also works fine on C++."
#endif

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_LENGTH	30

static char buffer[BUFFER_LENGTH];
static bool input_toggle = true;

void toggle_input(void) {
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
	
	toggle_input();
	user_input();
	printf("hidden input: %s\n", buffer);

	/*	---		restore			---	*/
	puts("\t---\trestored\t---\t");
	
	toggle_input();
	user_input();
	printf("visible input: %s\n", buffer);

	return EXIT_SUCCESS;
}
#endif