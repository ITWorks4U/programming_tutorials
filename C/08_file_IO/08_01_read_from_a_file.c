/*
* Read from a file. This code snippet is supposed to use on
* C only. Of course, you can also use a C++ compiler, however, in general
* the behavior of C++ is sometimes different rather than C.
* This can also be in this source code.
*
* In that case if you want to use a C++ compiler this won't work here.
*/

//	this preprocessor condition check is in use, if a C++ compiler
//	is in use; => take a look to chapter 17 for more details
//
//	Since FILE *... is a (raw) pointer, this might be handled
//	different in C++ rather than in C. => take a look for chapter 26 for more details
#ifdef __cplusplus
#error "This source code is supposed to use with a C compiler only."
#else
//	assuming, that a line may hold up to 100 characters only
#define MAX_CHARS_PER_LINE 100

#include <stdio.h>
#include <stdlib.h>

//	alternatives:
#include <string.h>
#include <errno.h>
#include <stdbool.h>

int main(void) {
	FILE *source = fopen("test.txt", "r");

	if (source == NULL) {
		perror("fopen()");
		return EXIT_FAILURE;
	}

	char buffer[MAX_CHARS_PER_LINE];
	memset(buffer, '\0', MAX_CHARS_PER_LINE);

	//	reading the file line by line
	//	the loop stops, when no more data from source can be read
	//
	//	perhaps, this also happens, when the file stream is corrupted,
	//	suddenly deleted, ..., but this is not a 100% guarantee
	//
	//	MAX_CHARS_PER_LINE - 1 is recommended, because a C-string MUST end
	//	with a null termination character!
	while ((fgets(buffer, MAX_CHARS_PER_LINE - 1, source)) != NULL) {
		//	usually, in every loop the buffer must be reset, otherwise it may
		//	happen, that some characters left may also be exist for the next line
		//
		//	since fgets already appending "\n" to buffer, there's no need
		//	to add "\n" in printf function
		printf("%s", buffer);
	}

	//	if you're using that code snippet instead, where the code above does not
	//	exist or did not ran before, you'll see a different result rather than
	//	prining the result line by line => fread reads the maximum number of characters
	//	in the current line, then a pointer refers to the last known position in the file,
	//	where the next text will be transfer to buffer
	//
	//	in summary, your output will be different rather than the code above
	//
	//	If the code snippet above has been used, then the file pointer refers to the last
	//	position in the file, which means, that no more characters can be read from
	//	the file and fread returns 0 to leave that loop immediately.
	//
	//	fread is also in use, if a file contains a byte stream, which must be handled in a
	//	different way rather than fgets()
	while(true) {
		if (fread(buffer, (MAX_CHARS_PER_LINE - 1), 1, source) == 0) {
			break;
		}

		printf("%s\n", buffer);
	}

	fclose(source);
	return EXIT_SUCCESS;
}
#endif