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
* ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "serial_communication.h"

/// @brief In case of an incoming signal, like Ctrl + C,
/// dispose the communication and terminate the application with
/// exit code 0.
/// @param signum incoming signal number
void _handle_signal(int signum) {
	dispose_serial_connection();
	exit(0);
}

#ifdef _WIN32
	// only for Windows
	BOOL WINAPI _windows_ctrl_handler(DWORD type) {
	switch (type) {
		case CTRL_C_EVENT:
		case CTRL_BREAK_EVENT:
			_handle_signal(SIGINT);
			return true;
	}

	return false;
}
#endif

void setup_signal_handling(void) {
	#ifdef _WIN32
	if (!SetConsoleCtrlHandler(_windows_ctrl_handler, TRUE)) {
		fprintf(stderr, "Failed to set control handler\n");
	}
	#else
	signal(SIGINT, _handle_signal);
	signal(SIGTERM, _handle_signal);
	#endif
}