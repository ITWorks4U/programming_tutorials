/*
* Write anything to a file. This code snippet is supposed to use on
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
#include <stdio.h>
#include <stdlib.h>

//	alternatives:
#include <errno.h>
#include <string.h>

int main(void) {
	/*
	* FILE *fopen(const char *__restrict__ __filename, const char *__restrict__ __modes);
	*
	* opens a stream to a file, whereas the given mode defines, how to open the file
	*
	* on success, a pointer to FILE returns,
	* on fail, NULL returns and errno (for any reason) is set
	*
	* | mode | action          | additional informations                                             |
	* |------|-----------------|---------------------------------------------------------------------|
	* |  "r" | read            | read a file, where this file MUST exist;                            |
	* |      |                 | furthermore, you must have access rights to that file,              |
	* |      |                 | it must not be a folder / directory, it must not be corrupted, ...  |
	* | "w"  | write           | write content to the file; this will overwrite the previous content |
	* | "w+" | write and read  | opens a file in both directions; "r+" and "a+" does the same action |
	* | "a"  | appending       | write content to the file; does not overwrite the previous content  |
	* | "rb" | read byte form  | reading a file in a byte format correctly                           |
	* | "wb" | write byte form | writing a file in a byte format correctly                           |
	*
	* => by using w, w+, a, a+ the file will be created, if this does not already exist
	*/
	FILE *destination = fopen("test.txt", "wb");

	//	destination may NULL in case of:
	//  - the path doesn't exist
	//  - insufficient permissions
	//  - path is a folder / directory
	//  - ...
	//
	//	By the way, in C++ this will be handled in a different and more secured way, because
	//	such kind of code may also result to memory leaks!
	if (destination == NULL) {
		//	sometimes just if (!destination) is also given, which has the same effect,
		//	but this is a bit faster than an addtional condition check in the if statement,
		//	but also harder to understand

		//	void perror(const char *error_message);
		//	in case of an error perror uses the internal handled errno variable
		//	to figure out, which error with its reason was caused
		//
		//	mostly the function name itself is given to show up where the error
		//	has been detected
		perror("fopen()");

		//	alternative way: use errno variable (not recommended, because errno
		//	can also be modified here; if you're using threads, then this is
		//	a horrible decision making)
		fprintf(stderr, "Error: %s\n", strerror(errno));

		return EXIT_FAILURE;
	}

	//	now the file stream exists, we can write anything to that file
	char simple_text[] = "This is a simple text.";
	// int number = 12345;

	for(int i = 0; i < 100; i++) {
		//	usually, fprintf is the way to go to write to the file stream
		// 
		//	we have also to make sure, that on any error
		//	the file stream automatically ends, however, in C this
		//	is often hard to realize
		if (fprintf(destination, "%d: %s\n", i+1, simple_text) < 0) {
			//	this may be a solution, however, this might not cover
			//	all error cases
			perror("fprintf()");

			//	in that case the opened file descriptor must be closed
			//	to avoid a memory leak
			fclose(destination);
			return EXIT_FAILURE;
		}

		//	for writing a byte stream, fwrite() is in use instead
		//	size_t fwrite(const void *buffer, size_t element_size, size_t element_count, FILE *_stream);
		//
		//	if you use simple_text the content itself is going to write to the file like above,
		//	however, no newline ("\n") is handled here, unless simple_text contains "\n"
		//
		//	if you're using any other value, like number in that case, the file might
		//	not be able to read with a default editor or you'll see anything inside there
		// fwrite(&number, sizeof(int), 1, destination);
	}

	//	finally, close the file descriptor to avoid a memory leaks,
	//	which may <<also>> fail °(^.^)
	if (fclose(destination) < 0) {
		//	in that case your file stream is still "alive"
		//	an can't be closed => memory leak
		perror("fclose()");
		return EXIT_FAILURE;
	}

	//	fun fact: by reaching EXIT_SUCCESS / EXIT_FAILURE / return n (n = any integer value) /
	//	exit(n) all streams are automatically closed, but this does not mean, that you don't
	//	have to close streams by your own
	return EXIT_SUCCESS;
}
#endif