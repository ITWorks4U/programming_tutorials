/*
* Creating a client example.
*
* NOTE: This sample is supposed to build and run on an UNIX machine only, like Linux, macOS.
*       To use the Windows system, switch into the windows folder and compile the application(s) instead.
*
* NOTE: This sample has been written with C only. A C++ compiler might not
*       be able to compile the code or on runtime any undefined behavior might appear.
*/

#ifdef __cplusplus
// A C++ compiler shall not be used here.
#error "This sample shall be used with a C compiler only. C++ is not recommended to use."
#elif defined(_WIN32)
// Only for an UNIX system.
#error "This application is supposed to build and run on a Windows machine only."
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "socket.h"

int main(void) {
	detect_current_os();
	printf("Starting client on: %s\n", current_os_name);

	// register clean up operation
	atexit(close_sockets);

	// read config file
	Connection *conn = read_config_file();
	// printf("\n => host = %s, port = %d\n", conn->ip_address, conn->port);

	/*
	* int socket(int domain, int type, int protocol);
	*
	* domain   := communication domain, like AF_INET (IPv4), AF_INET6 (IPv6) by using TCP/UDP
	* type     := communication type, where SOCK_STREAM = TCP; SOCK_DGRAM = UDP
	* protocol := protocol value for IP; optional flag, by default protocol is 0
	*
	* Return 0 on success, otherwise -1.
	*/
	if ((so.client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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
	* int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	*
	* sockfd  := client socket file descriptor
	* addr    := address to use
	* addrlen := size of address
	*
	* On success 0 returns, otherwise perror contains more informations.
	*/
	if (connect(so.client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
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
	int bytes_received = read(so.client_socket, buffer, BUFFER_SIZE - 1);

	switch(bytes_received) {
		case -1:
			perror("read()");
			break;
		case 0:
			fprintf(stderr, "Unable to receive the server's message...\n");
			break;
		default: {
			buffer[bytes_received] = '\0';
			printf("Received from server: %s\n", buffer);
			break;
		}
	}

	return EXIT_SUCCESS;
}

#endif