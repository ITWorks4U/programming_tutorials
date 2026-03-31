/*
* Creating a client example.
*
* NOTE: This sample is supposed to build and run on a Windows machine only.
*       To use an UNIX system, like Linux, macOS, ... switch into the
*       unix folder and compile the application(s) instead.
*
* NOTE: This sample has been written with C only. A C++ compiler might not
*       be able to compile the code or on runtime any undefined behavior might appear.
*/

#ifdef __cplusplus
// A C++ compiler shall not be used here.
#error "This sample shall be used with a C compiler only. C++ is not recommended to use."
#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
// Only for Windows.
#error "This application is supposed to build and run on a Windows machine only."
#else

// only for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

// NOTE: more in use for MS Visual Studio
#pragma comment(lib, "ws2_32.lib")

#include "socket.h"

int main(void) {
	detect_current_os();
	printf("Starting client on: %s\n", current_os_name);

	// register clean up operation(s)
	atexit(close_sockets);
	atexit(clean_up_WSA);

	// read config file
	Connection *conn = read_config_file();
	// printf("\n => host = %s, port = %d\n", conn->ip_address, conn->port);

	WSADATA wsa_data;
	int ret_val = 0;

	/*
	* Initializes the Winsock library to use any socket-related functions.
	*
	* int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
	*
	* wVersionRequested := version of Winsock (here: Winsock version 2.2)
	* lpWSAData := Pointer to a WSADATA struct that will be filled with details
	*              about the implementation (e.g., version supported, description).
	*
	* Returns 0 on success, otherwise perror prints the reason.
	*/
	if ((ret_val = WSAStartup(MAKEWORD(2, 2), &wsa_data)) != 0) {
		perror("WSAStartup()");
		return EXIT_FAILURE;
	}
	so.on_wsa_initialized = true;

	/*
	* SOCKET __stdcall socket(int af, int type, int protocol);
	*
	* af       := communication domain, like AF_INET (IPv4), AF_INET6 (IPv6) by using TCP/UDP
	* type     := communication type, where SOCK_STREAM = TCP; SOCK_DGRAM = UDP
	* protocol := protocol value for IP; optional flag, by default protocol is 0
	*
	* Returns a valid socket descriptor on success, or on failure, an invalid socket
	* or a socket error.
	*/
	if ((so.client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		perror("Socket creation failed");
		return EXIT_FAILURE;
	}
	so.on_client_socket_initialized = true;

	struct sockaddr_in server_addr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = inet_addr(conn->ip_address),
		.sin_port = htons(conn->port)
	};

	/*
	* try to connect to the given address and port
	*
	* int __stdcall connect(SOCKET s, const struct sockaddr *name, int namelen);
	*
	* s       := the socket to use
	* *name   := the socket address object
	* namelen := the amount of bytes
	*
	* On success 0 returns, otherwise perror contains more informations.
	*/
	if (connect(so.client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
		perror("Connection failed");
		return EXIT_FAILURE;
	}

	const char* message = "Hello from client!";

	/*
	* try to send a message back to the client
	*
	* int __stdcall send(SOCKET s, const char *buf, int len, int flags);
	*
	* s     := the client socket to use
	* buf   := a C-string for the client
	* len   := the length of the message
	* flags := optional flags (not in use here)
	*
	* Returns 0 on success, otherwise perror prints a detailed message.
	*/
	if (send(so.client_socket, message, (int)strlen(message), 0) < 0) {
		perror("send()");
		return EXIT_FAILURE;
	}

	char buffer[BUFFER_SIZE];
	memset(buffer, '\0', BUFFER_SIZE);

	/*
	* try to receive bytes from the server
	*
	* int __stdcall recv(SOCKET s, char *buf, int len, int flags);
	*
	* s     := the socket to use
	* *buf  := a C-string to store the message from the server
	* len   := the amount of characters for the C-string
	* flags := optional flags (not in use here)
	*/
	int bytes_received = recv(so.client_socket, buffer, BUFFER_SIZE - 1, 0);

	switch(bytes_received) {
		case -1:
			perror("recv()");
			break;
		case 0:
			fprintf(stderr, "Unable to receive a response from the server...\n");
			break;
		default:
			buffer[bytes_received] = '\0';
			printf("Received from server: %s\n", buffer);
			break;
	}

	return EXIT_SUCCESS;
}
#endif