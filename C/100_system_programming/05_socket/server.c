#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include "socket.h"

int main(void) {
	int server_fd = -1, new_socket = -1, val_read = -1;
	struct sockaddr_in address;
	int addr_length = sizeof(address);
	char buffer[LENGTH];
	memset(buffer, 0, sizeof(buffer));

	/*
	*	int socket(domain, type, protocol);
	*
	*	domain		:=	communication domain, like AF_INET (IPv4), AF_INET6 (IPv6)
	*	type		:=	communication type, where SOCK_STREAM = TCP; SOCK_DGRAM = UDP
	*	protocol	:=	protocol value for IP; optional flag, by default protocol is 0	->	man protocols
	*
	*/

	//	creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket()");
		return EXIT_FAILURE;
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT_NUMBER);

	/*
	*	int bind(sockfd, const struct sockaddr *addr, socklen_t addrlen);
	*
	*	sockfd		:=	socket file descriptor
	*	addr		:=	address struct to use, where a cast is required
	*	addrlen		:=	size of the used structure
	*/

	//	binding address
	if (bind(server_fd, (struct sockaddr *) &address, addr_length) < 0) {
		perror("bind()");
		return EXIT_FAILURE;
	}

	const int max_nbr_clients = 3;
	
	/*
	*	int listen(sockfd, backlog);
	*
	*	sockfd		:=	socket file descriptor
	*	backlog		:=	max. number of clients to listen
	*/

	//	offer a queue for up to three clients
	if (listen(server_fd, max_nbr_clients) < 0) {
		perror("listen()");
		return EXIT_FAILURE;
	}

	puts(" quit with \"CTRL+C\"");
	while (true) {

		/*
		*	int accept(sockfd, struct sockaddr *addr, socklen_t *addrlen);
		*
		*	sockfd	:=	socket file descriptor
		*	addr	:=	source address
		*	addrlen	:=	size of source address
		*/

		//	accepting client request
		if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t  *) &addr_length)) < 0) {
			perror("accept()");
			return EXIT_FAILURE;
		}

		/*
		*	int read(sockfd, void *buffer, size_t count);
		*
		*	sockfd	:=	socket file descriptor
		*	buffer	:=	text buffer
		*	count	:=	size of text buffer
		*/

		//	read the content from the client
		if ((val_read = read(new_socket, buffer, LENGTH)) < 0) {
			perror("read()");
			return EXIT_FAILURE;
		}

		puts(buffer);
		char answer[] = "Hello from server!";

		/*
		*	int send(sockfd, const void *buf, size_t len, int flags);
		*
		*	sockfd	:=	socket file descriptor
		*	buf		:=	text buffer
		*	len		:=	length of buf
		*	flags	:=	given flags, if required; default value: 0 -> man send
		*/

		//	sending welcome message to the client
		if (send(new_socket, answer, strlen(answer), 0) < 0) {
			perror("send()");
			return EXIT_FAILURE;
		}

		memset(buffer, 0, sizeof(buffer));
	}

	if (close(server_fd) < 0) {
		perror("close()");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

#endif