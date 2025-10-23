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

#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

// -------
// constants
// -------

#define BUFFER_PORT            16
#define BUFFER_COMMUNICATION   128
#define CONFIG_FILE_NAME       "connection.ini"
#define BUFFER_FOR_CONFIG_READ 32

// commands for main
#define COMMAND_READ_ONLY  "read_only"
#define COMMAND_WRITE_ONLY "write_only"
#define COMMAND_BOTH_WAYS  "both_ways"

#include <stdbool.h>

#ifdef _WIN32
// only for Windows
#include <Windows.h>
#include <io.h>
#define access _access
#define F_OK 0
#else
// only for UNIX systems
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#endif

// -------
// structure(s)
// -------
typedef enum {
	_READ_ONLY,
	_WRITE_ONLY,
	_BOTH_WAYS,
	_UNKNOWN_COMMAND
} CommandsForMain;

// -------
// function prototypes
// -------

/// @brief Setup incoming signals.
void setup_signal_handling(void);

/// @brief Helping function to check, if a valid command has
/// been used for application launch. This can be "read_only",
/// "write_only" or "both_ways" only. Every other command leads
/// to an invalid command.
/// @param command command from argv[1]
/// @return command for main to handle in main only
CommandsForMain check_start_command(const char *command);

/// @brief Load the config file. If the config file does not exist,
/// or an error during read may appear, then a basic setup is in use.
///
/// However, this does not guarantee to have a valid communication interface.
void load_config_file(void);

/// @brief Initializing the serial communication.
/// @return true, if the initialization was successful, otherwise false
bool initialize_serial_connection(void);

/// @brief Read data via serial communication.
///
/// NOTE: Only for reading.
/// @param response_buffer a response message, if any, to return
/// @param buffer_size the response message's size in bytes, if not NULL
void serial_read(char *response_buffer, size_t buffer_size);

/// @brief Write data via serial communication.
/// @param message_to_send a message to send via serial communication
///
/// NOTE: Only for writing.
void serial_write(const char *message_to_send);

/// @brief Offers to do a bidirectional serial communication for reading, as well as,
/// writing via serial communication.
/// @param message_to_send a message to send via serial communication
/// @param response_buffer a response message, if any, to return
/// @param buffer_size the response message's size in bytes, if not NULL
void serial_exchange(const char *message_to_send, char *response_buffer, size_t buffer_size);

/// @brief Clean up the mess.
void dispose_serial_connection(void);

#endif