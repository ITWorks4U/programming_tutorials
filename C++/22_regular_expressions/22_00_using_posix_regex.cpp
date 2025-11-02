/*
* In C++ it makes no sense to use POSIX regular expressions.
* If you really need to work with POSIX regular expressions,
* then you can use the C programming. Furthermore the POSIX
* regex is not available on all platforms.
*
* Usually, UNIX/Linux, macOS may use this. If you're using
* Windows and mingw, then it could be possible to use
* POSIX regex.
*
* Use <regex> library or an alternative library instead, like:
* - <boost/regex.h>
* - <pcre2.h>
*
* Attention:
* This sample below is almost 1:1 to C programming and hasn't
* been fully tested. Take a look to: C/27_regular_expressions
*/

#if __has_include(<regex.h>)
// using POSIX regex
#define POSIX_REGEX_AVAILABLE
#include <regex.h>
#endif

#if __has_include(<pcre2.h>)
#define PCRE2_REGEX_AVAILABLE
// using PCRE as alternative
// NOTE: It may happen, that this application can't be built, because
//       PCRE2_CODE_UNIT_WIDTH must be defined before pcre2.h can be
//       included. A width, like 0,8,16 or 32 is also required.
#define PCRE2_CODE_UNIT_WIDTH  32
#include <pcre2.h>
#endif

#include <iostream>

using namespace std;

int on_match(const char *expression) {
	const char regex_pattern[] = "^[A-Za-z0-9]+$";
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
	* 0:	no error
	* -1:	error and ERRNO is set
	*/
	if (regcomp(&reg, regex_pattern, REG_EXTENDED) < 0) {
		return -1;
	}

	/*
	* int regexec(const regex_t *__restrict__ __preg, const char *__restrict__ __String, size_t __nmatch, regmatch_t *__restrict__ __pmatch, int __eflags);
	*
	* Execute the regular expression procedure.
	*
	* preg:	pointer to a compiled regular expression to compare against STRING
	* string:	pointer to a string to be matched
	* nmatch:	number of sub-expressions to match (optional) => 0: we don't care
	* pmatch:	array of offsets into STRING which matched the corresponding sub-expressions in preg => NULL: we don't care
	* eflags:	bit flag defining customizable behavior of regexec()
	*
	* REG_NOTBOL
	* - indicates that the first character of STRING is not the beginning of the line
	* REG_NOTEOL
	* - indicates that the first character of STRING is not the end of the line
	*
	* returns:
	* 0:	regular expression check was successful
	* 1:	regular expression check was not successful
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
	* 	PCRE2_SPTR pattern,          // The regex pattern to compile
	* 	PCRE2_SIZE length,           // Length of the pattern, or PCRE2_ZERO_TERMINATED
	* 	uint32_t options,            // Compilation options (bit flags)
	* 	int *errorcode,              // OUT: Error code (if compilation fails)
	* 	PCRE2_SIZE *erroroffset,     // OUT: Position of error in pattern
	* 	pcre2_compile_context *cctx  // Compilation context (advanced use, NULL for default)
	* );
	*
	* returns prce2_code pointer to work with, otherwise NULL returns
	*/
	pcre2_code* re = pcre2_compile((PCRE2_SPTR) regex_pattern, PCRE2_ZERO_TERMINATED, 0, NULL, NULL, NULL);
	if (re == NULL) {
		PCRE2_UCHAR buffer[ERROR_BUFFER];
		pcre2_get_error_message(errorcode, buffer, sizeof(buffer));
		fprintf(stderr, "PCRE2 compilation failed at offset %d: %s\n", (int)erroroffset, buffer);
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
	*	const pcre2_code *code,
	*	PCRE2_SPTR subject,
	*	PCRE2_SIZE length,
	*	PCRE2_SIZE startoffset,
	*	uint32_t options,
	*	pcre2_match_data *match_data,
	*	pcre2_match_context *mcontext
	* );
	*
	* returns:
	* >= 0, on a match
	* -1, on mismatch
	* <-1, on other error, like bad UTF data, bad parameters, ...
	*/
	int rc = pcre2_match(re, (PCRE2_SPTR) expression, strlen(expression), 0, 0, match_data, NULL);

	//	releasing allocated memory
	pcre2_match_data_free(match_data);
	pcre2_code_free(re);

	result = (rc >= 0) ? 0 : 1;
	#endif

	return result;
}

int main() {
	#if !(defined(POSIX_REGEX_AVAILABLE) && defined(PCRE2_REGEX_AVAILABLE))
	cerr << endl <<
		"ERROR: No regular expressions by POSIX or PCRE2 has been found on your system." << endl <<
		"You can't use those regular expression libraries." << endl <<
	endl;
	#endif

	const char expression[] = "A400g3333";
	printf("result: \"%s\" does ", expression);

	switch(on_match(expression)) {
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

	return 0;
}