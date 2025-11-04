// This sample shall be build with a C compiler only.

#include <stdio.h>
#include <stdlib.h>
#include "os_system_definitions.h"

/*
* Usually, your application is able to build in C++, but not in C.
* Even the function prototypes and their declarations are in C-style,
* it depends on the source file, where these functions are stored.
*
* If a C++ - file is in use, the functions will have a different
* expression for the linker. And that's the point, where your application
* can't be build in C.
*/

int main(void) {
	#ifndef APP_IS_UNABLE_TO_USE
		#ifdef _WIN32
		HMODULE lib = LoadLibraryA(LIBRARY_NAME);
		if (lib == NULL) {
			fprintf(stderr, "unable to load library \"%s\"...\n", LIBRARY_NAME);
			return EXIT_FAILURE;
		}

		addition_func addition = (addition_func)GetProcAddress(lib, FUNC_ADD);
		subtraction_func subtraction = (subtraction_func)GetProcAddress(lib, FUNC_SUBTRACT);
		multiply_func multiply = (multiply_func)GetProcAddress(lib, FUNC_MULTIPLY);
		divide_func divide = (divide_func)GetProcAddress(lib, FUNC_DIVIDE);

		if (!(addition && subtraction && multiply && divide)) {
			fprintf(stderr, "unable to locate one or more required function(s).\n");
			FreeLibrary(lib);
			return EXIT_FAILURE;
		}
		#else
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
			snprintf(full_library_path, sizeof(full_library_path), "%s/%s", dir, LIBRARY_NAME);

			void *library_handler = dlopen(full_library_path, RTLD_LAZY);
			if (library_handler == NULL) {
				fprintf(stderr, "unable to load library \"%s\": %s...", LIBRARY_NAME, dlerror());
				return EXIT_FAILURE;
			}

			char *error_message = NULL;

			// clear any existing error...
			dlerror();

			// get the pointers to the functions and check, if there was an error
			addition_func addition = (addition_func) dlsym(library_handler, FUNC_ADD);
			if ((error_message = dlerror()) != NULL) {
				fprintf(stderr, "dlsym(\"%s\") failed: %s\n", FUNC_ADD, error_message);
				dlclose(library_handler);
				return EXIT_FAILURE;
			}

			subtraction_func subtraction = (subtraction_func) dlsym(library_handler, FUNC_SUBTRACT);
			if ((error_message = dlerror()) != NULL) {
				fprintf(stderr, "dlsym(\"%s\") failed: %s\n", FUNC_SUBTRACT, error_message);
				dlclose(library_handler);
				return EXIT_FAILURE;
			}

			multiply_func multiply = (multiply_func) dlsym(library_handler, FUNC_MULTIPLY);
			if ((error_message = dlerror()) != NULL) {
				fprintf(stderr, "dlsym(\"%s\") failed: %s\n", FUNC_MULTIPLY, error_message);
				dlclose(library_handler);
				return EXIT_FAILURE;
			}

			divide_func divide = (divide_func) dlsym(library_handler, FUNC_DIVIDE);
			if ((error_message = dlerror()) != NULL) {
				fprintf(stderr, "dlsym(\"%s\") failed: %s\n", FUNC_DIVIDE, error_message);
				dlclose(library_handler);
				return EXIT_FAILURE;
			}
		#endif

		int a = 10;
		int b = 20;

		printf("running under C...\n\n");

		printf("%d + %d = %d\n", a, b, addition(a,b));
		printf("%d - %d = %d\n", a, b, subtraction(a,b));
		printf("%d * %d = %d\n", a, b, multiply(a,b));
		printf("%d / %d = %d\n", a, b, divide(a,b));

		#ifdef _WIN32
		FreeLibrary(lib);
		#else
		dlclose(library_handler);
		#endif

		return EXIT_SUCCESS;
	#else
	puts("ERROR: It was not clear on which OS this application is running. Nothing was made.");
	#endif

	return EXIT_FAILURE;
}