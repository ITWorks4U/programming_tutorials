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
#include <string.h>
#include <limits.h>
#include "serial_communication.h"

// -------
// internal definitions
// -------

typedef struct {
	int baudrate;
	char port[BUFFER_PORT];
} SerialConnection;

static SerialConnection _serial_connection;

// the amount of time in ms to wait until the
// communication becomes "invalid"
static unsigned long _timeout_in_ms = 0;

#ifdef _WIN32
static HANDLE _h_serial = NULL;
#else
static int _serial_fd = -1;
#endif

// -------
// internal
// -------

/// @brief Waiting for incoming data response. This shall ensure to wait,
/// until a response message is able to send.
/// @param fd the file descriptor for the serial connection (only in use for UNIX)
/// @return true, if the data has been received within the certain
/// time amount, otherwise false
static bool _wait_for_incoming_data(int fd) {
	#ifdef _WIN32
		DWORD event_mask;

		// setup event mask to wait for received characters
		SetCommMask(_h_serial, EV_RXCHAR);

		// wait for the event (data received)
		BOOL result = WaitCommEvent(_h_serial, &event_mask, NULL);
		return (result && (event_mask & EV_RXCHAR));
	#else
		fd_set read_fds;
		struct timeval timeout;

		FD_ZERO(&read_fds);
		FD_SET(fd, &read_fds);

		timeout.tv_sec = _timeout_in_ms / 1000;
		timeout.tv_usec = (_timeout_in_ms % 1000) * 1000;

		int result = select(fd + 1, &read_fds, NULL, NULL, &timeout);
		return (result > 0 && FD_ISSET(fd, &read_fds));
	#endif
}

#ifndef _WIN32
/// @brief Helping function for an UNIX system. The BAUD rate (from connection.ini)
/// must be converted into B<baudrate>, otherwise the communication BAUD rate may be
/// invalid.
/// @param baudrate the known baudrate from connection.ini
/// @return converted BAUD rate with 'B' prefix.
static speed_t get_unix_baudrate(int baudrate) {
	switch (baudrate) {
		case 9600: return B9600;
		case 19200: return B19200;
		case 38400: return B38400;
		case 57600: return B57600;
		case 115200: return B115200;
		default:
			fprintf(stderr, "Unsupported baudrate %d, using 9600.\n", baudrate);
			return B9600;
	}
}
#endif

// -------
// public functions
// -------

void load_config_file(void) {
	bool config_file_valid = true;
	FILE *src = NULL;

	// Check, if the config file might not
	// exist. If true, then a serial communication
	// is unable to do.
	if (access(CONFIG_FILE_NAME, F_OK) < 0) {
		config_file_valid = false;
	}

	if (config_file_valid) {
		// Open the config file. On any failure
		// the communication is unable to do.
		src = fopen(CONFIG_FILE_NAME, "r");
		if (src == NULL) {
			perror("fopen()");
			config_file_valid = false;
		}
	}

	if (config_file_valid) {
		char current_line[BUFFER_FOR_CONFIG_READ];
		while(fgets(current_line, BUFFER_FOR_CONFIG_READ - 1, src) != NULL) {
			if (strstr(current_line, "baudrate=")) {
				_serial_connection.baudrate = (int) strtol(strchr(current_line, '=') + 1, NULL, 10);
			} else if (strstr(current_line, "portname=")) {
				memset(_serial_connection.port, '\0', BUFFER_PORT);
				strncpy(_serial_connection.port, strchr(current_line, '=') + 1, BUFFER_PORT);

				// also get rid of any newline, carriage return, ...
				_serial_connection.port[strcspn(_serial_connection.port, "\r\n")] = 0;
			} else if (strstr(current_line, "timeout_in_ms=")) {
				_timeout_in_ms = strtoul(strchr(current_line, '=') + 1,NULL, 10);

				if (_timeout_in_ms == 0) {
					fprintf(stderr, "WARNING: timeout for messages are set to infinite...\n");
					_timeout_in_ms = ULONG_MAX;
				}
			}
		}

		fclose(src);
	} else {
		_serial_connection.baudrate = 9600;

		memset(_serial_connection.port, '\0', BUFFER_PORT);
		#ifdef _WIN32
		strcpy(_serial_connection.port, "COM3");
		#else
		strcpy(_serial_connection.port, "/dev/ttyUSB0");
		#endif
	}

	// printf("==> baud=%d, port=%s\n", _serial_connection.baudrate, _serial_connection.port);
}

bool initialize_serial_connection(void) {
	#ifdef _WIN32
	// only for Windows
	_h_serial = CreateFileA(
		_serial_connection.port,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL
	);

	if (_h_serial == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "ERROR: opening serial port \"%s\" failed.\n", _serial_connection.port);
		return false;
	}

	DCB dcbSerialParams = { 0 };
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(_h_serial, &dcbSerialParams)) {
		fprintf(stderr, "ERROR: Failed to get COM state.\n");
		CloseHandle(_h_serial);
		return false;
	}

	dcbSerialParams.BaudRate = _serial_connection.baudrate;
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity   = NOPARITY;

	if (!SetCommState(_h_serial, &dcbSerialParams)) {
		fprintf(stderr, "ERROR: Failed to set COM state.\n");
		CloseHandle(_h_serial);
		return false;
	}

	// set timeouts
	COMMTIMEOUTS timeouts = {
		.ReadIntervalTimeout = _timeout_in_ms,
		.ReadTotalTimeoutConstant = _timeout_in_ms,
		.ReadTotalTimeoutMultiplier = 10,
		.WriteTotalTimeoutConstant = _timeout_in_ms,
		.WriteTotalTimeoutMultiplier = 10
	};

	SetCommTimeouts(_h_serial, &timeouts);
	#else
	puts("initializing...");
	// only for UNIX
	_serial_fd = open(_serial_connection.port, O_RDWR | O_NOCTTY);
	if (_serial_fd < 0) {
		perror("open()");
		return false;
	}

	usleep(2000000); // wait 2 seconds for the microcontroller to reboot
	tcflush(_serial_fd, TCIOFLUSH);
	puts("done...");

	// make sure to block the communication for one
	// direction flow, otherwise read() may return immediately,
	// even no data is ready
	fcntl(_serial_fd, F_SETFL, 0);

	struct termios t;
	if (tcgetattr(_serial_fd, &t) < 0) {
		perror("tcgetattr()");
		return false;
	}

	speed_t baudrate = get_unix_baudrate(_serial_connection.baudrate);

	cfsetispeed(&t, baudrate);
	cfsetospeed(&t, baudrate);

	t.c_cflag = (t.c_cflag & ~CSIZE) | CS8;
	t.c_iflag &= ~(IXON | IXOFF | IXANY | ICRNL | INLCR);
	t.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	t.c_oflag &= ~OPOST;
	t.c_cflag |= (CLOCAL | CREAD);

	if (tcsetattr(_serial_fd, TCSANOW, &t) < 0) {
		perror("tcsetattr()");
		return false;
	}
	#endif

	return true;
}

void serial_read(char *response_buffer, size_t buffer_size) {
	if (response_buffer == NULL || buffer_size == 0) {
		return;
	}

	bool data_ready = false;

	#ifdef _WIN32
		// NOTE: On Windows the argument is ignored.
		data_ready = _wait_for_incoming_data(0);
	#else
		data_ready = _wait_for_incoming_data(_serial_fd);
	#endif

	// If withing the given time amount no answer can be received,
	// then the current message communcation is marked as "invalid".
	if (!data_ready) {
		response_buffer[0] = '\0';
		return;
	}

	#ifdef _WIN32
	DWORD bytes_read = 0;
	if (!ReadFile(_h_serial, response_buffer, (DWORD)buffer_size - 1, &bytes_read, NULL)) {
		fprintf(stderr, "Failed to read from COM port\n");
		return;
	}
	response_buffer[bytes_read] = '\0';
	#else
	ssize_t n = read(_serial_fd, response_buffer, buffer_size - 1);
	if (n < 0) {
		perror("read()");
		return;
	}
	response_buffer[n] = '\0';
	#endif
}

void serial_write(const char *message_to_send) {
	if (message_to_send == NULL) {
		return;
	}

	#ifdef _WIN32
	DWORD bytes_written;
	if (!WriteFile(_h_serial, message_to_send, (DWORD)strlen(message_to_send), &bytes_written, NULL)) {
		fprintf(stderr, "Failed to write to COM port\n");
	}
	#else
	// always flush the buffers before the next message is going to write
	tcflush(_serial_fd, TCIOFLUSH);

	ssize_t written = write(_serial_fd, message_to_send, strlen(message_to_send));
	// printf("written: %u bytes from incoming message %s\n", written, message_to_send);
	if (written < 0) {
		perror("write()");
	}
	#endif
}

void serial_exchange(const char *message_to_send, char *response_buffer, size_t buffer_size) {
	serial_write(message_to_send);
	serial_read(response_buffer, buffer_size);
}

void dispose_serial_connection(void) {
	#ifdef _WIN32
	CloseHandle(_h_serial);
	_h_serial = NULL;
	#else
	close(_serial_fd);
	_serial_fd = -1;
	#endif
}