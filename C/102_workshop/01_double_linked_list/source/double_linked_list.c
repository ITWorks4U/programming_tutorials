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
#include "double_linked_list.h"

/// @brief root node for linear list
static struct double_linked_list *root = NULL;

/// @brief number of elements in the linear list
static unsigned int node_count = 0;

static void assign_ids(void) {
	struct double_linked_list *current = root;
	unsigned int id = 0;
	while (current != NULL) {
		current->node_id = id++;
		current = current->next;
	}
}

void print_list(void) {
	int nbr_of_elements = 0;
	struct double_linked_list *current = root;

	while(current != NULL) {
		printf(
			"ID: %d\ncontent: %s\nprevious node ID: %d\nnext node ID: %d\n\n",
			current->node_id, current->content, current->prev != NULL ? current->prev->node_id : INVALID_NODE_ID,
			current->next != NULL ? current->next->node_id : INVALID_NODE_ID
		);
		current = current->next;
		nbr_of_elements++;
	}

	printf("\n> total number of nodes: %d\n", nbr_of_elements);
}

bool add_to_list(const char *new_content) {
	if (new_content == NULL || strlen(new_content) >= BUFFER_LENGTH) {
		fprintf(stderr, "ERROR: invalid content detected\n");
		return false;
	}

	struct double_linked_list *new_node = calloc(1, sizeof(struct double_linked_list));
	if (new_node == NULL) {
		perror("calloc(new_node)");
		return false;
	}

	strncpy(new_node->content, new_content, BUFFER_LENGTH - 1);
	new_node->content[BUFFER_LENGTH - 1] = '\0';
	new_node->next = NULL;

	if (root == NULL) {
		root = new_node;
	} else {
		struct double_linked_list *current = root;
		while (current->next) {
			current = current->next;
		}

		new_node->prev = current;
		current->next = new_node;
	}

	node_count++;
	assign_ids();
	return true;
}

bool remove_from_list(unsigned int id_to_remove) {
	if (root == NULL) {
		fprintf(stderr, "ERROR: list is empty\n");
		return false;
	}

	struct double_linked_list *current = root;

	while (current != NULL) {
		if (current->node_id == id_to_remove) {

			// removing root, if requested
			if (current == root) {
				root = current->next;
				if (root != NULL) {
					root->prev = NULL;
				}
			} else {
				if (current->prev) {
					current->prev->next = current->next;
				}
				if (current->next) {
					current->next->prev = current->prev;
				}
			}

			free(current);
			node_count--;
			assign_ids();
			return true;
		}
		current = current->next;
	}

	fprintf(stderr, "ERROR: node with ID %u not found\n", id_to_remove);
	return false;
}

void reverse_list(void) {
	// root = previous;
	struct double_linked_list *tmp = NULL;
	struct double_linked_list *current = root;

	while (current != NULL) {
		/*	swapping prev and next	*/
		tmp = current->prev;
		current->prev = current->next;
		current->next = tmp;

		/*	move to the next node in the original sequence	*/
		current = current->prev;
	}

	/*	finally, update root as well	*/
	if (tmp != NULL) {
		root = tmp->prev;
	}
	assign_ids();
}

void clean_up(void) {
	struct double_linked_list *current = root;
	struct double_linked_list *temp = NULL;

	while(current != NULL) {
		temp = current->next;
		free(current);
		current = temp;
	}

	root = NULL;
	node_count = 0;
}

void print_separator(const char *message) {
	puts("-------------------");
	printf("%s\n", message);
	puts("-------------------");
}

bool on_valid_input(const char *input) {
	#ifdef POSIX_REGEX_AVAILABLE
	/*	using POSIX regex.h	*/
	int result = -1;
	regex_t reg;

	if (regcomp(&reg, REGEX_PATTERN, REG_EXTENDED) < 0) {
		return false;
	}

	result = regexec(&reg, input, 0, NULL, 0);
	regfree(&reg);

	return result == 0;
	#endif

	#ifdef PCRE_REGEX_AVAILABLE
	/*	using PCRE2 instead	*/
	int result = -1;
	PCRE2_SIZE erroffset;
	int errorcode = -1;

	PCRE2_SPTR pattern = (PCRE2_SPTR)REGEX_PATTERN;
	PCRE2_SPTR subject = (PCRE2_SPTR)input;

	pcre2_code *re = pcre2_compile(
		pattern,               // the pattern
		PCRE2_ZERO_TERMINATED, // indicates pattern is zero-terminated
		0,                     // default options
		&errorcode,            // for error code
		&erroffset,            // for error offset
		NULL);                 // use default compile context

	if (re == NULL) {
		fprintf(stderr, "PCRE2 compilation failed at offset %d\n", (int)erroffset);
		return false;
	}

	pcre2_match_data *match_data = pcre2_match_data_create_from_pattern(re, NULL);
	result = pcre2_match(re, subject, strlen((char *)subject), 0, 0, match_data, NULL);

	pcre2_match_data_free(match_data);
	pcre2_code_free(re);

	return result >= 0;
	#endif

	#if !(defined(POSIX_REGEX_AVAILABLE) || defined(PCRE_REGEX_AVAILABLE))
	/*
	* otherwise no regular expression is able to do here
	* use a primitive and also flaw way to check for a "number"
	*/
	if (!input || !*input) {
		//	if input is NULL or the first character of input
		//	equals to \0 => an empty word
		return false;
	}

	for (size_t i = 0; i < strlen(input); i++) {
		if (input[i] < '0' || input[i] > '9') {
			return false;
		}
	}

	return true;
	#endif
}