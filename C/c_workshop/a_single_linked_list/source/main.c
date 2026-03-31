/*
* Simple linked list example by using C language.
*
* author:	ITWorks4U
* created:	July 14th, 2025
* updated:	July 22nd, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear_list.h"

int main(void) {
	char buffer[BUFFER_LENGTH];
	memset(buffer, '\0', BUFFER_LENGTH);
	printf("enter %s to stop adding elements to the linked list...\n", END_OF_INPUT);

	while(true) {
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			perror("fgets()");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, END_OF_INPUT) == 0) {
			break;
		}

		if (!add_to_list(buffer)) {
			fprintf(stderr, "Error adding \"%s\" to list.\n", buffer);
		}
	}

	//	------
	//	printing the full list
	//	------
	print_separator("print full list");
	print_list();

	//	------
	//	removing node
	//	------
	print_separator("remove node from list");

	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';

		if (on_valid_input(buffer)) {
			unsigned int id = (unsigned int) strtoul(buffer, NULL, 10);

			if (!remove_from_list(id)) {
				fprintf(stderr, "no element with ID %d found...\n", id);
			} else {
				printf("node with ID %d found; updating list...\n", id);
			}
		} else {
			fprintf(stderr, "invalid ID: %s\n", buffer);
		}
	} else {
		perror("fgets()");
	}

	//	------
	//	reversing list
	//	------
	print_separator("reversing list");
	reverse_list();
	print_list();

	//	------
	//	clean up
	//	------
	print_separator("clean up the mess");
	clean_up();

	return EXIT_SUCCESS;
}