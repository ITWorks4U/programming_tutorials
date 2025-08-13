#ifdef __cplusplus
#warning "This code has been written in C. You should use a C compiler instead, otherwise it may cause an undefined behavior!"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH	30
static char email_address[BUFFER_LENGTH];

#ifndef _WIN32
	#define USE_POSIX_REGEX
	#include <regex.h>
#elif __has_include(<pcre2.h>)
	#define USE_PCRE2_REGEX
	#include <pcre2.h>
	#define ERROR_BUFFER	255
#else
	#warning "Unable to find a regular expression libary. You can't use regular expressions."
#endif

#if defined(USE_POSIX_REGEX) || defined(USE_PCRE2_REGEX)
	#define REGEX_PATTERN	"^[a-z]{1,10}@(gmail|gmx|hotmail)\\.(com|info|de)$"
#endif

int on_match(const char *expression) {
	int result = -1;

	#if defined(USE_POSIX_REGEX)
	regex_t reg;

	if (regcomp(&reg, REGEX_PATTERN, REG_EXTENDED) < 0) {
		return -1;
	}

	result = regexec(&reg, expression, 0, NULL, 0);
	regfree(&reg);
	#endif

	#if defined(USE_PCRE2_REGEX)
	pcre2_code* re = pcre2_compile((PCRE2_SPTR) REGEX_PATTERN, PCRE2_ZERO_TERMINATED, 0, NULL, NULL, NULL);
	if (re == NULL) {
		PCRE2_UCHAR buffer[ERROR_BUFFER];
		pcre2_get_error_message(errorcode, buffer, sizeof(buffer));
		fprintf(stderr, "PCRE2 compilation failed at offset %d: %s\n", (int)erroroffset, buffer);
		return -1;
	}

	pcre2_match_data* match_data = pcre2_match_data_create_from_pattern(re, NULL);
	int rc = pcre2_match(re, (PCRE2_SPTR) expression, strlen(expression), 0, 0, match_data, NULL);

	pcre2_match_data_free(match_data);
	pcre2_code_free(re);

	result = (rc >= 0) ? 0 : 1;
	#endif

	return result;
}

void remove_newline(void) {
	size_t length = strlen(email_address);
	if (length > 0 && email_address[length - 1] == '\n') {
		email_address[length - 1] = '\0';
	}
}

void clean_up_remaining_buffer(void) {
	//	NOTE: you're forced to hit enter again
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
	memset(email_address, '\0', BUFFER_LENGTH);

	printf("check e-mail address: ");
	fgets(email_address, BUFFER_LENGTH - 1, stdin);
	remove_newline();
	clean_up_remaining_buffer();

	printf("result: \"%s\" does ", email_address);

	switch(on_match(email_address)) {
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

	return EXIT_SUCCESS;
}