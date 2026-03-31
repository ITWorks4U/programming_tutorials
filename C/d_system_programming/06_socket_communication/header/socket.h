#ifndef SOCKET_H
#define SOCKET_H

// ----------
// definitions
// ----------
#include <stdbool.h>

#if _WIN32
// Only for Windows.
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
typedef SOCKET _sock_server_t;
typedef SOCKET _sock_client_t;
#define UNSET_SOCKET_FD INVALID_SOCKET
#define FUNC_CLOSE_SOCKET closesocket
#else
// Only for UNIX.
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef int _sock_server_t;
typedef int _sock_client_t;
#define UNSET_SOCKET_FD 0
#define FUNC_CLOSE_SOCKET close
#endif

// www.xxx.yyy.zzz\0
#define IP_ADDRESS_LENGTH 17

// a (n expected) global available path for each operating system
#define PATH_CONFIG_FILE  "../config/connection.ini"

// a buffer for communications
#define BUFFER_SIZE       1025

// a buffer for the full OS name
#define BUFFER_OS_NAME    128

// ----------
// structures
// ----------

/// @brief Stores the connection data from the config file
/// or use a default setting.
/// @note If the config file doesn't exist or an error during
/// runtime may appear, a default setting of {127.0.0.1;50000}
/// is in use.
typedef struct {
	char ip_address[IP_ADDRESS_LENGTH];
	int port;
} Connection;

/// @brief Socket communication operations. Depending on which side is in use
/// (server / client), not all members are in use.
/// @note The member on_wsa_initialized is only required on a Windows machine.
typedef struct {
	_sock_server_t server_socket;
	_sock_client_t client_socket;

	bool on_server_socket_initialized;
	bool on_client_socket_initialized;
	bool on_wsa_initialized;
} SocketOperations;

extern SocketOperations so;

// ----------
// function prototypes
// ----------

/// @brief Try to read the config file for the socket communication.
///
/// @note In case of the file does not exist or any other error on runtime may
/// appear, a default setting will be used. (host => 127.0.0.1, port => 50000)
Connection *read_config_file(void);

/// @brief Clean up the socket connection on application.
/// Either on success or on failure.
void close_sockets(void);

/// @brief Clean up the WSA object.
/// @note Only for Windows machines.
void clean_up_WSA(void);

/// @brief Determine on which operating system (OS) this application is running.
/// This can be "Windows", "Linux", "macOS" or an unknown OS system.
///
/// Furthermore the full OS name with version is trying to receive.
void detect_current_os(void);

// ----------
// external usage
// ----------

/// @brief Contains the current OS name, where this application is going to run.
extern char current_os_name[BUFFER_OS_NAME];

#endif