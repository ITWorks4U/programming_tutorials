/*
* Unlike to use the primitive way, let's use regular expressions.
* Depending on the OS you are working on, POSIX regex won't work everywhere.
*
* For Windows:
* - by using C++ or Visual Studio, use <regex> or <boost/regex.h>
* - outside of VS, you shall use an external libary, like PCRE2, ...,
*   or use a python script for regular expressions as a help
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check for any integer / floating point number;
// may leads with a signed / unsigned character, optionally followed
// by . or , with and amout of digits (at least 1)
#define REGEX_PATTERN   "^(-|\\+)?[0-9]+((\\.|,)[0-9]+)?$"

#ifndef _WIN32
// only for UNIX systems
#define USE_POSIX_REGEX
#include <regex.h>
#endif

// NOTE:  This might not work on every system.
//        Depending on the compiler version.
#if __has_include(<pcre2.h>)
// maybe PCRE2 library was found
// NOTE:  Even this library was unable to found,
//        the compiler may refuse to build your application,
//        because the definition "PCRE2_CODE_UNIT_WIDTH" with
//        a valid width of [0,8,16,32] is required. => for UTF-8, 16, 32
//
//        Furthermore the compiler needs an additional flag, like:
//        -lpcre2-8   <=> PCRE2_CODE_UNIT_WIDTH 8
//        -lpcre2-16  <=> PCRE2_CODE_UNIT_WIDTH 16
//        -lpcre2-32  <=> PCRE2_CODE_UNIT_WIDTH 32
//
// NOTE:  For more informations take a look to the official
//        page: https://www.pcre.org/current/doc/html/index.html,
//        https://www.pcre.org/current/doc/html/pcre2-config.html
#define USE_PCRE2_REGEX
#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>
#define ERROR_BUFFER    255
#endif

#if !(defined(USE_POSIX_REGEX) && defined(USE_PCRE2_REGEX))
// in case of USE_POSIX_REGEX or USE_PCRE2_REGEX is not
// defined, then a python script shall be used instead

// NOTE: Even POSIX or PCRE2 has been found, it may happen,
//       that this way may also be used and this will overwrite
//       your previous result(s). Just rename USE_PYTHON_SCRIPT to
//       any other expression for that case or in on_match() function
//       combine this preprocessing command with false.
#define USE_PYTHON_SCRIPT
#define MAX_PATH_LENGTH      4096
#define PYTHON_FILE_TO_USE   "check_on_valid_number.py"
#endif

/// @brief Check, if an expression passes trough the regular expression filter.
/// @param expression the expression to check
/// @return [-1 on error, 0 on match, 1 on mismatch]
int on_match(const char *expression) {
	int result = -1;

	#if defined(USE_POSIX_REGEX)
	regex_t reg;

	/*
	* int regcomp(regex_t *__restrict__ __preg, const char *__restrict__ __pattern, int __cflags);
	*
	* Compile your regular expression object on runtime.
	* It's required, otherwise you'll receive a segmentation fault.
	*
	* returns:
	* 0:    no error
	* -1:   error and ERRNO is set
	*/
	if (regcomp(&reg, REGEX_PATTERN, REG_EXTENDED) < 0) {
		return -1;
	}

	/*
	* int regexec(const regex_t *__restrict__ __preg, const char *__restrict__ __String, size_t __nmatch, regmatch_t *__restrict__ __pmatch, int __eflags);
	*
	* Execute the regular expression procedure.
	*
	* preg:     pointer to a compiled regular expression to compare against STRING
	* string:   pointer to a string to be matched
	* nmatch:   number of sub-expressions to match (optional) => 0: we don't care
	* pmatch:   array of offsets into STRING which matched the corresponding sub-expressions in preg => NULL: we don't care
	* eflags:   bit flag defining customizable behavior of regexec()
	*
	* REG_NOTBOL
	* - indicates that the first character of STRING is not the beginning of the line
	* REG_NOTEOL
	* - indicates that the first character of STRING is not the end of the line
	*
	* returns:
	* 0:    regular expression check was successful
	* 1:    regular expression check was not successful
	*/
	result = regexec(&reg, expression, 0, NULL, 0);

	/*
	* void regfree(regex_t *__preg);
	*
	* Release allocated memory for regular expression object.
	* The expression defined by preg is no longer a compiled
	* regular or extended expression.
	*/
	regfree(&reg);
	#endif

	#if defined(USE_PCRE2_REGEX)
	/*
	* regular expression compilation function
	*
	* pcre2_code *pcre2_compile(
	*   PCRE2_SPTR pattern,          // the regex pattern to compile
	*   PCRE2_SIZE length,           // length of the pattern, or PCRE2_ZERO_TERMINATED
	*   uint32_t options,            // compilation options (bit flags)
	*   int errorcode,               // OUT: error code (if compilation fails)
	*   PCRE2_SIZE *erroroffset,     // OUT: position of error in pattern
	*   pcre2_compile_context *cctx  // compilation context (advanced use, NULL for default)
	* );
	*
	* returns prce2_code pointer to work with, otherwise NULL returns
	*/
	int errorcode = -1;

	// NOTE: erroroffset MUST NOT be NULL, otherwise the function below
	//       returns NULL immediately. "If either of errorcode or erroroffset is NULL, the function returns NULL immediately."
	//       => https://www.pcre.org/current/doc/html/pcre2_compile.html
	PCRE2_SIZE *erroroffset = calloc(1, sizeof(PCRE2_SIZE));

	pcre2_code* re = pcre2_compile((PCRE2_SPTR) REGEX_PATTERN, PCRE2_ZERO_TERMINATED, PCRE2_MULTILINE, &errorcode, erroroffset, NULL);
	if (re == NULL) {
		PCRE2_UCHAR buffer[ERROR_BUFFER];
		memset(buffer, '\0', ERROR_BUFFER);

		pcre2_get_error_message(errorcode, buffer, sizeof(buffer));
		fprintf(stderr, "PCRE2 compilation failed at offset (%pH): %s    ", erroroffset, buffer);
		free(erroroffset);

		return -1;
	}

	/*
	* allocate a match structure that is sized appropriately for a given compiled regular expression
	*
	* pcre2_match_data *pcre2_match_data_create_from_pattern(const pcre2_code *code, pcre2_general_context *gcontext);
	*
	* returns pcre2_match_data structure (seems never been NULL)
	*/
	pcre2_match_data* match_data = pcre2_match_data_create_from_pattern(re, NULL);

	/*
	* try to match the known pattern with the given expression to figure out, if this
	* passes trough the regular expression filter
	*
	* int pcre2_match(
	* const pcre2_code *code,
	* PCRE2_SPTR subject,
	* PCRE2_SIZE length,
	* PCRE2_SIZE startoffset,
	* uint32_t options,
	* pcre2_match_data *match_data,
	* pcre2_match_context *mcontext
	* );
	*
	* returns:
	* >= 0,   on a match
	* -1,     on mismatch
	* <-1,    on other error, like bad UTF data, bad parameters, ...
	*/
	int rc = pcre2_match(re, (PCRE2_SPTR) expression, strlen(expression), 0, 0, match_data, NULL);

	// releasing allocated memory
	pcre2_match_data_free(match_data);
	pcre2_code_free(re);

	result = (rc >= 0) ? 0 : 1;
	#endif

	#if defined(USE_PYTHON_SCRIPT)
	char external_command[MAX_PATH_LENGTH];
	memset(external_command, '\0', MAX_PATH_LENGTH);

	#ifdef _WIN32
	snprintf(external_command, MAX_PATH_LENGTH - 1, "python.exe %s \"%s\" \"%s\"", PYTHON_FILE_TO_USE, REGEX_PATTERN, expression);
	#else
	// NOTE: On an UNIX system python3 shall be used to make sure to use
	//       the python 3 interpreter. Otherwise a python 2 interpreter,
	//       if existing, could be launched and this may not be able to
	//       handle the python 3 script. Moreover, depending on how "python"
	//       is defined with an alias, this could also lead to python3.
	snprintf(external_command, MAX_PATH_LENGTH - 1, "python3 %s \"%s\" \"%s\"", PYTHON_FILE_TO_USE, REGEX_PATTERN, expression);
	#endif

	// NOTE: using system(const char *command); is not a valid
	//       solution of all time, unless you know, what you do
	result = system(external_command);
	#endif

	return result;
}

int main(void) {
	char *expressions[] = {"A400g3333", "123", "hello world", "-123.456", "0,123"};
	size_t number_of_expressions = sizeof(expressions) / sizeof(expressions[0]);

	for (size_t i = 0; i < number_of_expressions; i++) {
		printf("expression \"%s\": ", expressions[i]);

		switch(on_match(expressions[i])) {
			case 0:
				puts("match!");
				break;
			case 1:
				puts("not match!");
				break;
			default:
				puts("not proceed, because there was an error...");
				break;
		}
	}

	return EXIT_SUCCESS;
}