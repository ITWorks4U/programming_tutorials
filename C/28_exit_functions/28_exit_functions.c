/*
* What happens, when your application code reaches EXIT_SUCCESS / EXIT_FAILURE?
*
* Have you ever thought about how the application is going to
* terminate after certain conditions?
* There're many ways to do this, however, the results differs!
*
* By reaching return 0 / return 1 / return EXIT_SUCCESS / return EXIT_FAILURE / return .... in the main
* your application returns to the shell, where you've launched the application or to the
* operating system, where you've (double) clicked your application. - The classic way.
*
* However, the main automatically calls the exit() function, which calls _exit() to
* clearly terminate your application.
*
* So you can terminate your application by calling exit() or _exit(), ..., but the results differs.
*
* Since you're reaching an exit way too early, almost every other code behind is not going to execute.
*
* in summary:
*
* |------------------|-------------------------------------------------|-------------------------------------------|
* |     function     |                   effect                        |         additional informations           |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | atexit           | register a clean up sequence before termination | register up to 32 different instructions  |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | exit(x)          | terminate the application by given x value      | calls the clean up function(s) first,     |
* |                  | => same effect by return (main only)            | then _exit(x) is called                   |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | _exit(x)         | real termination of the application             | does not clean up any resources           |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | abort()          | abnormal termination of the process             | does not clean up any resources           |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | assert(x)        | assuming, that condition x is true; if yes,     | on failure no clean up of any resources   |
* |                  | then the next instruction can be reached;       | is going to to; similar to abort()        |
* |                  | if false, the application terminates abormally  |                                           |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | at_quick_exit()  | same action like atexit()                       |                                           |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | quit_exit(x)     | same action like exit()                         | calls the clean up function(s) first,     |
* |                  |                                                 | which has been registered by              |
* |                  |                                                 | at_quick_exit() only; function(s) by used |
* |                  |                                                 | are not touched                           |
* |------------------|-------------------------------------------------|-------------------------------------------|
* | _Exit(x)         | same action like _exit(x)                       | same behavior to _exit(x)                 |
* |------------------|-------------------------------------------------|-------------------------------------------|
*/

#include <stdio.h>
#include <stdlib.h>

//	in Windows _exit() is defined in stdlib.h
#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
//	required to use _exit()
#include <unistd.h>
#endif

/*	for assert() function (C89) / assert() macro (C99 and newer)	*/
#include <assert.h>
#define NBR_OF_ELEMENTS	10

static int *field = NULL;

/// @brief Releases the allocated memory. But NOT on every situation!
void clean_up(void) {
	puts("clean up....");
	free(field);

	//	optional in that case
	field = NULL;
}

int main(void) {
	/*
	* Register a "clean up" sequence to ensure to release your allocated memory,
	* but it works only with exit() and return statement!
	*
	* You can register up to 32 different clean up instrcutions.
	*/
	atexit(clean_up);

	/*	normal instructions here...	*/
	field = (int *) malloc(sizeof(int *) * NBR_OF_ELEMENTS);

	if (field == NULL) {
		perror("malloc()");
		return EXIT_FAILURE;
	}

	//	-----------------
	//	Since you've decided to terminate your application earlier,
	//	every other code won't be executed by default.
	//	-----------------

	/*	Different ways to terminate your application:	*/

	/*
	* void exit(int exit_code); (until C11)
	* _Noreturn void exit(int exit_code); (C11-C23)
	* [[noreturn]] void exit( int exit_code ); (C23+)
	*
	* Terminate your application. This is automatically called by return
	* statement in your main. If you have registered any clean up functions
	* by using atexit(), then these functions are called before the application
	* is really terminated by _exit().
	*/
	exit(EXIT_SUCCESS);
	
	/*
	* void _exit(int __status);
	*
	* The real exit for your application. This function DOES NOT clean up
	* any resources! Make sure you've cleaned up it before.
	*
	* In UNIX/Linux the library <unistd.h> is required.
	* For Windows this function is defined in <stdlib.h> instead.
	*/
	_exit(EXIT_SUCCESS);

	/*
	* void abort(void);
	*
	* Terminate your application abnormally and create a >core dumped< expression on the terminal.
	* The abort() function first unblocks the SIGABRT signal, and then raises that signal
	* for the calling process. Does NOT clean up any resources.
	*
	* If the SIGABRT signal is ignored, or caught by a handler that returns, the abort() function will
	* still terminate the process. It does this by restoring the default disposition
	* for SIGABRT and then raising the signal for a second time.
	*
	* The return value for abort() is 134.
	*/
	abort();

	/*
	* up tp C-version C89:	void assert(int expression);
	* C99 and newer:			void assert(scalar expression);
	*
	* Assuming, that a condition is true. If so, then the application process continues.
	* If the condition is false, then an assert error is raised. This automatically calls
	* the abort() function and has the same behavior like abort() itself.
	*
	* In case of an assertion error, this function also returns 134.
	*
	* If the macro NDEBUG is defined at the moment <assert.h> was last included, then assert() generates no code,
	* and hence does nothing at all. It is not recommended  to  define NDEBUG if using assert()
	* to detect error conditions since the software may behave non-deterministically.
	*/
	assert(field != NULL);

	/*
	* int at_quick_exit(void (*__func)(void)); (C11+)
	*
	* Works like atexit() function to register at least 32 functions
	* to do a "clean up job" before the application is going to terminate.
	*
	* Works in combination with quick_exit();
	*
	* The registered functions will not be called on normal program termination, like return / exit().
	* If a function need to be called in that case, atexit must be used. 
	*/
	at_quick_exit(clean_up);

	/*
	* _Noreturn void quick_exit( int exit_code ); (C11 - C23)
	* [[noreturn]] void quick_exit( int exit_code ); (C23+)
	*
	* Calls all functions, which are registered by at_quick_exit() before.
	* Finally, the process is going to terminate by given status.
	*
	* Functions passed to atexit() or signal handlers passed to signal are not called.
	*/
	quick_exit(EXIT_SUCCESS);

	/*
	* void _Exit(int __status);
	*
	* Works like _exit() with the same behavior. This function is defined in <stdlib.h>.
	*/
	_Exit(EXIT_FAILURE);

	//	this is never been printed to stdout
	puts("What about this text here?");

	return EXIT_SUCCESS;
}