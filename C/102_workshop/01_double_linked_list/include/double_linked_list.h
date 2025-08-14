/*
* Simple linked list example by using C language.
*
* author:	ITWorks4U
* created:	July 14th, 2025
* updated:	July 22nd, 2025
*/

#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#ifdef __cplusplus
//	allowing to use a C++ compiler, which transfer the code
//	below into raw C functions
extern "C" {
#endif

#include <stdbool.h>

//	constant(s)
#define BUFFER_LENGTH     128
#define INVALID_CONTENT   "***content length too large***"
#define LIST_IS_EMPTY     "list is empty"
#define NODE_NOT_EXISTS   "***node does not exist***"
#define END_OF_INPUT      "q"
#define INVALID_NODE_ID   -1

//	check, if regular expressions can be used here
#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC) && __has_include(<regex.h>)
	//	for UNIX/Linux/macOS only
	#define POSIX_REGEX_AVAILABLE
	#include <regex.h>
#endif

#if defined(_WIN32) && __has_include(<pcre2.h>)
	//	for Windows with PCRE regex library
	#define PCRE_REGEX_AVAILABLE
	#include <pcre2.h>
#endif

//NOTE: For C++ <regex> or <boost/regex.h> exists, but those
// are not part of this application and also not handled

#if defined(POSIX_REGEX_AVAILABLE) || defined(PCRE_REGEX_AVAILABLE)
	#define	REGEX_PATTERN	"^[0-9]+$"
#endif

/// @brief Node for each double linked list.
struct double_linked_list {
	/*	node ID	*/
	int node_id;

	/*	content for the certain node	*/
	char content[BUFFER_LENGTH];

	/*	link to the previous node	*/
	struct double_linked_list *prev;

	/*	link to the next node	*/
	struct double_linked_list *next;
};

/*	function(s)		*/

/// @brief Print all list nodes to the console.
void print_list(void);

/// @brief Add a new content to the newly created list node.
/// @param new_content content for newly created list node
/// @return on success true, otherwise false
bool add_to_list(const char *new_content);

/// @brief Remove a node from list. If the list does not contain any data or
/// the ID is not found, a message is going to print to the console instead.
/// @param id_to_remove ID to remove from list
/// @return on success true, otherwise false
bool remove_from_list(unsigned int id_to_remove);

/// @brief Reversing the full list.
void reverse_list(void);

/// @brief Removing all created list nodes from memory.
void clean_up(void);

//	-------
//	for main() only
//	-------

/// @brief Print a separator block to the terminal.
/// @param message the message within the block
void print_separator(const char *message);

/// @brief Checks, if the input is valid. The input is valid only,
/// if, and only if, a number or a sequence of numbers in the valid range
/// between [0,9] has been typed in. Any other characters, like non alpha numeric
/// characters, spaces, ... are not going to pass to the regular expression check.
///
///	ATTENTION:
///
///	This is only available, if regular expressions for POSIX or PCRE2 has been found on your system.
///	If not, then a primitive and flaw implementation is in use by default.
/// @param input input to check for validity
/// @return true, if the input was valid, otherwise false, if the the regular expression
/// initializer has been failed or the input did not match
bool on_valid_input(const char *input);

#endif // idndef DOUBLE_LINKED_LIST

#ifdef __cplusplus
}
#endif