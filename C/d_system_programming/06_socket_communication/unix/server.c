/*
* Creating a server example.
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
#error "This application is supposed to build and run on an UNIX machine only, like Linux, macOS."
#else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"

int main(void) {
	detect_current_os();
	printf("Starting server on: %s\n", current_os_name);

	// register clean up operation
	atexit(close_sockets);

	// read config file
	Connection *conn = read_config_file();
	// printf("\n => host = %s, port = %d\n", conn->ip_address, conn->port);

	/*
	* Create a new socket object and assign it to server_socket.
	*
	* int socket(int domain, int type, int protocol);
	*
	* domain    := communication domain, like AF_INET (IPv4), AF_INET6 (IPv6)
	* type      := communication type, where SOCK_STREAM = TCP; SOCK_DGRAM = UDP
	* protocol  := protocol value for IP; optional flag, by default protocol is 0 (=> man protocols)
	*
	* Returns a valid socket descriptor on success, or on failure, an invalid socket
	* or a socket error.
	*/
	if ((so.server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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
	* int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	*
	* sockfd   := socket file descriptor
	* addr     := address struct to use, where a cast is required
	* addrlen  := size of the used structure
	*
	* On success 0 returns, otherwise perror prints the error message.
	*/
	if (bind(so.server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
		perror("bind()");
		return EXIT_FAILURE;
	}

	int max_nbr_clients = 1;

	/*
	* listening to the socket and handle an amount of clients at the same time
	*
	* int listen(int sockfd, int backlog);
	*
	* sockfd   := socket file descriptor
	* backlog  := max. number of clients to listen
	*
	* On success 0 returns, otherwise perror prints the error message.
	*/
	if (listen(so.server_socket, max_nbr_clients) < 0) {
		perror("listen()");
		return EXIT_FAILURE;
	}

	puts(" quit the server with \"CTRL+C\"");
	while (true) {
		struct sockaddr_in client_addr;
		socklen_t client_len = sizeof(client_addr);

		/*
		* accept a client request
		*
		* int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
		*
		* sockfd  := socket file descriptor
		* addr    := source address
		* addrlen := size of source address
		*
		* On success 0 returns. In contrast to the functions above the server is not
		* going to terminate.
		*/
		if ((so.client_socket = accept(so.server_socket, (struct sockaddr*)&client_addr, &client_len)) < 0) {
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
			* int read(int sockfd, void *buffer, size_t count);
			*
			* sockfd := socket file descriptor
			* buffer := text buffer
			* count  := size of text buffer
			*
			* Returns >0 for at least one received byte. 0 for no bytes received, <0 for any error.
			*/
			int bytes_received = read(so.client_socket, buffer, BUFFER_SIZE - 1);

			switch(bytes_received) {
				case -1:
					perror("read()");
					break;
				case 0:
					fprintf(stderr, "Unable to receive the client's message...\n");
					break;
				default: {
					buffer[bytes_received] = '\0';
					printf("Received from client: %s\n", buffer);

					char answer[] = "Hello from server!";

					/*
					* send a message back to the client
					*
					* int send(int sockfd, const void *buf, size_t len, int flags);
					*
					* sockfd := socket file descriptor
					* *buf   := text buffer
					* len    := length of buf
					* flags  := given flags, if required; default value: 0 (=> man send)
					*/
					if (send(so.client_socket, answer, strlen(answer), 0) < 0) {
						perror("send()");
					}
				}
			}
		}
	}

	return EXIT_SUCCESS;
}

#endif