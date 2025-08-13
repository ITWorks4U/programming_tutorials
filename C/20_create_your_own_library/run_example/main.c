/*
* Using the created libary file for your own purpose.
*
* Simulates, that the libary only exists here, which contains the
* full functionality code for your purpose.
*/

#include <stdio.h>
#include <stdlib.h>

//	function names for our purpose
#define FUNC_ADD_ELEMENTS "add_elements"
#define FUNC_PRINT_ELEMENTS "print_all_elements"

//	linked references to the functions to work with
//	these functions return void and take no arguments
typedef void (*print_all_elements_func)(void);
typedef void (*add_elements_func)(void);

//	a special split between Windows and Linux (and possibly also for macOS)
//	this is required to handle the dynamic linked library

#ifdef _WIN32
	//	handles each 32 und 64 bit Windows machine
	//	perhaps __WIN32__, __WIN64__ might be used in your case
	#include <Windows.h>
	#define LIBRARY_NAME "library_maker.dll"
#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
	//	this shall be handled by any UNIX/Linux system, as well as, macOS
	#include <dlfcn.h>
	#include <unistd.h>
	#include <libgen.h>
	#include <string.h>
	#define FULL_PATH_LENGTH 1024

	//	for macOS:
	#if defined(__APPLE__) || defined(_MAC)
		#define LIBRARY_NAME "library_maker.dylib"
	#else
		#define LIBRARY_NAME "library_maker.so"
	#endif
#else
	#warning	"Unable to detect the operating system. Your application will be terminated immediately."
	#define APP_IS_UNABLE_TO_USE
#endif

int main(void) {
	#ifndef APP_IS_UNABLE_TO_USE
		#ifdef _WIN32
		//	for Windows the library is planned to load dynamically and the function names
		//	are in use to link with module pointers to work with them
		//
		//	the function names are required to spell here (defined as macro constant),
		//	otherwise those can't be used
		HMODULE lib = LoadLibraryA(LIBRARY_NAME);
		if (lib == NULL) {
			fprintf(stderr, "the library \"%s\" was unable to find.\n", LIBRARY_NAME);
			return EXIT_FAILURE;
		}

		print_all_elements_func print_all_elements = (print_all_elements_func)GetProcAddress(lib, FUNC_PRINT_ELEMENTS);
		add_elements_func add_elements = (add_elements_func)GetProcAddress(lib, FUNC_ADD_ELEMENTS);

		if (!(print_all_elements && add_elements)) {
			fprintf(stderr, "unable to locate function(s).\n");
			FreeLibrary(lib);
			return EXIT_FAILURE;
		}
		#else
			//	only for UNIX/Linux/macOS
			char path[FULL_PATH_LENGTH];
			char full_library_path[FULL_PATH_LENGTH];

			memset(path, '\0', FULL_PATH_LENGTH);
			memset(full_library_path, '\0', FULL_PATH_LENGTH);

			__ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
			if (len == -1) {
				perror("readlink()");
				return EXIT_FAILURE;
			}

			path[len] = '\0';
			char *dir = dirname(path);
			printf("==> %s\n", dir);
			snprintf(full_library_path, sizeof(full_library_path), "%s/%s", dir, LIBRARY_NAME);
			printf("===> full path: %s\n", full_library_path);

			//	loading shared library
			void *library_handler = dlopen(full_library_path, RTLD_LAZY);
			if (library_handler == NULL) {
				fprintf(stderr, "unable to find the library %s: %s\n", LIBRARY_NAME, dlerror());
				return EXIT_FAILURE;
			}

			char *error_message = NULL;

			// clear any existing error...
			dlerror();

			//	get the pointers to the functions and check, if there was an error
			add_elements_func add_elements = (add_elements_func) dlsym(library_handler, FUNC_ADD_ELEMENTS);
			if ((error_message = dlerror()) != NULL) {
				fprintf(stderr, "dlsym(\"%s\") failed: %s\n", FUNC_ADD_ELEMENTS, error_message);
				dlclose(library_handler);
				return EXIT_FAILURE;
			}

			print_all_elements_func print_all_elements = (print_all_elements_func) dlsym(library_handler, FUNC_PRINT_ELEMENTS);
			if ((error_message = dlerror()) != NULL) {
				fprintf(stderr, "dlsym(\"%s\") failed: %s\n", FUNC_PRINT_ELEMENTS, error_message);
				dlclose(library_handler);
				return EXIT_FAILURE;
			}
		#endif

		//	calling the functions to work with them
		add_elements();
		print_all_elements();

		#ifdef _WIN32
		if (lib != NULL) {
			FreeLibrary(lib);
		}
		
		#else
		if (library_handler != NULL) {
			dlclose(library_handler);
		}
		#endif
	#endif

	return EXIT_SUCCESS;
}