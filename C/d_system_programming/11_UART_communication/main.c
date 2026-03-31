/*
* System programming in C.
*
* Do a serial communication with a microcontroller, like an Arduino Uno.
* This microcontroller is configured with prefedined commands to listen and
* take a certain action. This application has been written in C only and runs
* with Windows and UNIX systems.
*
* The folder microcontroller contains a simple code snippet for the
* serial communication.
*
* author:   ITWorks4U
* created:  October 13th, 2025
* updated:  November 4rd, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serial_communication.h"

#define END_COMMAND     "q\n"

CommandsForMain check_start_command(const char *command) {
	if (strcmp(command, COMMAND_READ_ONLY) == 0) {
		return _READ_ONLY;
	}

	if (strcmp(command, COMMAND_WRITE_ONLY) == 0) {
		return _WRITE_ONLY;
	}

	if (strcmp(command, COMMAND_BOTH_WAYS) == 0) {
		return _BOTH_WAYS;
	}

	return _UNKNOWN_COMMAND;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		// get rid of \<application>.exe | /<application>
		// => only <application>.exe | <application> remains
		#ifdef _WIN32
		char *last_token = strrchr(argv[0], '\\');
		#else
		char *last_token = strrchr(argv[0], '/');
		#endif

		char *application_name = (last_token) ? last_token + 1 : argv[0];

		fprintf(stderr, "usage: %s <option>\noption could be:\n", application_name);
		fprintf(stderr, "%s := only read a message\n", COMMAND_READ_ONLY);
		fprintf(stderr, "%s := only write a message\n", COMMAND_WRITE_ONLY);
		fprintf(stderr, "%s := for both communication ways\n", COMMAND_BOTH_WAYS);

		return EXIT_FAILURE;
	}

	CommandsForMain cmf = check_start_command(argv[1]);

	if (cmf == _UNKNOWN_COMMAND) {
		fprintf(stderr, "Error: unknown command %s detected...\n", argv[1]);
		return EXIT_FAILURE;
	}

	setup_signal_handling();
	load_config_file();

	if (!initialize_serial_connection()) {
		fprintf(stderr, "ERROR: unable to use a serial communication...\n");
		return EXIT_FAILURE;
	}

	char response_buffer[BUFFER_COMMUNICATION];
	char command_to_use[BUFFER_COMMUNICATION];

	memset(response_buffer, '\0', BUFFER_COMMUNICATION);
	memset(command_to_use, '\0', BUFFER_COMMUNICATION);

	// NOTE: _UNKNOWN_COMMAND still exists to avoid "unhandled enumeration value"
	switch(cmf) {
		case _UNKNOWN_COMMAND:
			break;
		case _READ_ONLY: {
			puts("Terminate process with \"Ctrl + C\".");
			while(true) {
				puts("... waiting for next message ...\n\n");

				serial_read(response_buffer, sizeof(response_buffer) - 1);
				printf("response message: %s\n", response_buffer);
			}

			break;
		} case _WRITE_ONLY: {
			puts("enter \"q\" to terminate...");
			while(true) {
				printf("enter a command: ");
				memset(command_to_use, '\0', BUFFER_COMMUNICATION);
				fgets(command_to_use, BUFFER_COMMUNICATION - 1, stdin);

				if(strcmp(command_to_use, END_COMMAND) == 0) {
					break;
				}

				// write a message by serial communication
				//
				// NOTE: Usually, the message shall be termianted with
				//       \r\n, because some systems requres such
				//       termination characters.
				//       Some systems, however, may read a command until
				//       '\n' has been reached.
				serial_write(command_to_use);
			}

			break;
		} case _BOTH_WAYS: {
			// For both directions. Just start with a message to send,
			// followed by the response message.

			puts("enter \"q\" to terminate...");
			while(true) {
				printf("enter a command: ");
				memset(command_to_use, '\0', BUFFER_COMMUNICATION);
				fgets(command_to_use, BUFFER_COMMUNICATION - 1, stdin);

				if(strcmp(command_to_use, END_COMMAND) == 0) {
					break;
				}

				serial_exchange(command_to_use, response_buffer, sizeof(response_buffer));
				printf("response message: %s\n", response_buffer);
			}

			break;
		}
	}

	dispose_serial_connection();

	return EXIT_SUCCESS;
}