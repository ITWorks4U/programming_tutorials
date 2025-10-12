/*
* Reading the config file "connection.ini" and provide the
* used settings for the communication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "socket.h"

#define LINE_LENGTH  128
#define KEY_SIZE     5
#define VALUE_SIZE   21
#define HOST_KEY     "host"
#define PORT_KEY     "port"

Connection *read_config_file(void) {
	// fallback values in case of the config file
	// was unable to find or read
	static Connection _conn = {
		"127.0.0.1",
		50000
	};

	FILE *src = fopen(PATH_CONFIG_FILE, "r");
	if (src == NULL) {
		perror("fopen(CONFIG_FILE)");
		return &_conn;
	}

	char current_line[LINE_LENGTH];
	while (fgets(current_line, LINE_LENGTH, src) != NULL) {
		bool on_invalid_line =
			current_line[0] == '[' ||
			current_line[0] == '#' ||
			current_line[0] == ';' ||
			current_line[0] == '\n';

		if (on_invalid_line) {
			continue;
		}

		char key[KEY_SIZE];
		char value[VALUE_SIZE];

		// check, if a line contains the format key=value,
		// where the key has a length of 4 bytes and the
		// value may have up to 20 bytes
		if (sscanf(current_line, "%4[^=]=%20s", key, value) == 2) {
			if (strcmp(key, HOST_KEY) == 0) {
				strncpy(_conn.ip_address, value, IP_ADDRESS_LENGTH - 1);
				_conn.ip_address[IP_ADDRESS_LENGTH] = '\0';
			} else if (strcmp(key, PORT_KEY) == 0) {
				_conn.port = (int) strtol(value, NULL, 10);
			}
		}
	}

	fclose(src);
	return &_conn;
}