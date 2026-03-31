/*
* Creating a server example.
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
	printf("Starting server on: %s\n", current_os_name);

	// register clean up operation(s)
	atexit(close_sockets);
	atexit(clean_up_WSA);

	// read config file
	Connection *conn = read_config_file();
	// printf("\n => host = %s, port = %d\n", conn->ip_address, conn->port);

	WSADATA wsa_data;

	/*
	* Initializes the Winsock library to use any socket-related functions.
	*
	* int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
	*
	* wVersionRequested := version of Winsock (here: Winsock version 2.2)
	* lpWSAData         := Pointer to a WSADATA struct that will be filled with details
	*                   about the implementation (e.g., version supported, description).
	*
	* Returns 0 on success, otherwise perror prints the reason.
	*/
	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) < 0) {
		perror("WSAStartup()");
		return EXIT_FAILURE;
	}
	so.on_wsa_initialized = true;

	/*
	* Create a new socket object and assign it to server_socket.
	*
	* SOCKET __stdcall socket(int af, int type, int protocol);
	*
	* af       := communication domain, like AF_INET (IPv4), AF_INET6 (IPv6) by using TCP/UDP
	* type     := communication type, where SOCK_STREAM = TCP; SOCK_DGRAM = UDP
	* protocol := protocol value for IP; optional flag, by default protocol is 0
	*
	* Returns a valid socket descriptor on success, or on failure, an invalid socket
	* or a socket error.
	*/
	if ((so.server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		perror("socket()");
		return EXIT_FAILURE;
	}
	so.on_server_socket_initialized = true;

	// create an IPv4 address communication with the settings
	// from the config file itself
	struct sockaddr_in server_addr = {
		.sin_family = AF_INET,
		.sin_addr.s_addr = inet_addr(conn->ip_address),
		.sin_port = htons(conn->port)
	};

	/*
	* bind the socket address to use the socket connection
	*
	* int __stdcall bind(SOCKET s, const struct sockaddr *name, int namelen);
	*
	* s        := the socket to use
	* *name    := use a sockaddrr structure => server_addr must be casted
	* namelen  := size of the used structure
	*
	* On success 0 returns, otherwise perror prints the error message.
	*/
	if (bind(so.server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
		perror("bind()");
		return EXIT_FAILURE;
	}

	int nbr_of_clients = 1;

	/*
	* listening to the socket and handle an amount of clients at the same time
	*
	* int __stdcall listen(SOCKET s, int backlog);
	*
	* s        := the socket to use
	* backlog  := number of client(s) to handle
	*
	* On success 0 returns, otherwise perror prints the error message.
	*/
	if (listen(so.server_socket, nbr_of_clients) < 0) {
		perror("listen()");
		return EXIT_FAILURE;
	}

	puts("quit the server with \"CTRL+C\"");
	while(true) {
		struct sockaddr_in client_addr;
		socklen_t client_len = sizeof(client_addr);

		/*
		* accept a client request
		*
		* SOCKET __stdcall accept(SOCKET s, struct sockaddr *addr, int *addrlen);
		*
		* s       := socket to use
		* addr    := client address for incoming client connection
		* addrlen := size of source address
		*
		* On success 0 returns. In contrast to the functions above the server is not
		* going to terminate.
		*/
		if ((so.client_socket = accept(so.server_socket, (struct sockaddr*)&client_addr, &client_len)) == INVALID_SOCKET) {
			perror("accept()");
			puts("Unable to accept a client connection. Try again...");
		} else {
			so.on_client_socket_initialized = true;
		}

		if (so.on_client_socket_initialized) {
			char buffer[BUFFER_SIZE];
			memset(buffer, '\0', BUFFER_SIZE);

			/*
			* Receive a length of bytes from the client.
			*
			* int __stdcall recv(SOCKET s, char *buf, int len, int flags);
			*
			* s     := the client socket
			* *buf  := a C-string to store the message from the client
			* len   := the length of characters to handle
			* flags := optional flags (not in use here => 0: "We don't care about optional flags.")
			*
			* Returns >0 for at least one received byte. 0 for no bytes received, <0 for any error.
			*/
			int bytes_received = recv(so.client_socket, buffer, BUFFER_SIZE - 1, 0);

			switch(bytes_received) {
				case -1:
					perror("recv()");
					break;
				case 0:
					fprintf(stderr, "Unable to receive the client's message...\n");
					break;
				default: {
					buffer[bytes_received] = '\0';
					printf("Received from client: %s\n", buffer);

					char response[] = "Hello from server!";

					/*
					* send a message back to the client
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

					if ((send(so.client_socket, response, (int)strlen(response), 0)) < 0) {
						perror("send()");
					}
					break;
				}
			}
		}
	}

	return EXIT_SUCCESS;
}
#endif