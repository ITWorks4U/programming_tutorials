// This sample shall be build with a C++ compiler only.

#include <iostream>
#include "os_system_definitions.h"
using namespace std;

int main(void) {
	#ifndef APP_IS_UNABLE_TO_USE
		#ifdef _WIN32
		HMODULE lib = LoadLibraryA(LIBRARY_NAME);
		if (lib == nullptr) {
			cerr << "unable to load library \"%s\"..." << LIBRARY_NAME << endl;
			return 1;
		}

		addition_func addition = (addition_func)GetProcAddress(lib, FUNC_ADD);
		subtraction_func subtraction = (subtraction_func)GetProcAddress(lib, FUNC_SUBTRACT);
		multiply_func multiply = (multiply_func)GetProcAddress(lib, FUNC_MULTIPLY);
		divide_func divide = (divide_func)GetProcAddress(lib, FUNC_DIVIDE);

		if (!(addition && subtraction && multiply && divide)) {
			cerr << "unable to locate one or more required function(s)." << endl;
			FreeLibrary(lib);
			return 1;
		}
		#else
		// NOTE: at this point a C style syntax is here given, because it's actually
		// unknown how to write this in C++ style
		char path[FULL_PATH_LENGTH];
		char full_library_path[FULL_PATH_LENGTH];

		memset(path, '\0', FULL_PATH_LENGTH);
		memset(full_library_path, '\0', FULL_PATH_LENGTH);

		__ssize_t len = readlink("/proc/self/exe", path, sizeof(path) - 1);
		if (len == -1) {
			perror("readlink()");
			return 1;
		}

		path[len] = '\0';
		char *dir = dirname(path);
		snprintf(full_library_path, sizeof(full_library_path), "%s/%s", dir, LIBRARY_NAME);

		void *library_handler = dlopen(full_library_path, RTLD_LAZY);
		if (library_handler == nullptr) {
			cerr << "unable to load library \"" << LIBRARY_NAME << "\": " << dlerror() << endl;
			return EXIT_FAILURE;
		}

		char *error_message = nullptr;

		// clear any existing error...
		dlerror();

		addition_func addition = reinterpret_cast<addition_func>(dlsym(library_handler, FUNC_ADD));

		if ((error_message = dlerror()) != nullptr) {
			cerr << "dlsym(\"" << FUNC_ADD << "\") failed: " << error_message << endl;
			dlclose(library_handler);
			return EXIT_FAILURE;
		}

		subtraction_func subtraction = reinterpret_cast<subtraction_func>(dlsym(library_handler, FUNC_SUBTRACT));

		if ((error_message = dlerror()) != nullptr) {
			cerr << "dlsym(\"" << FUNC_SUBTRACT << "\") failed: " << error_message << endl;
			dlclose(library_handler);
			return EXIT_FAILURE;
		}

		multiply_func multiply = reinterpret_cast<multiply_func>(dlsym(library_handler, FUNC_MULTIPLY));

		if ((error_message = dlerror()) != nullptr) {
			cerr << "dlsym(\"" << FUNC_MULTIPLY << "\") failed: " << error_message << endl;
			dlclose(library_handler);
			return EXIT_FAILURE;
		}

		divide_func divide = reinterpret_cast<divide_func>(dlsym(library_handler, FUNC_DIVIDE));

		if ((error_message = dlerror()) != nullptr) {
			cerr << "dlsym(\"" << FUNC_DIVIDE << "\") failed: " << error_message << endl;
			dlclose(library_handler);
			return EXIT_FAILURE;
		}
		#endif

		int a = 10;
		int b = 20;

		cout << "running under C++" << endl << endl;

		cout << a << " + " << b << " = " << addition(a,b) << endl;
		cout << a << " - " << b << " = " << subtraction(a,b) << endl;
		cout << a << " * " << b << " = " << multiply(a,b) << endl;
		cout << a << " / " << b << " = " << divide(a,b) << endl;

		#ifdef _WIN32
		FreeLibrary(lib);
		#else
		dlclose(library_handler);
		#endif

		return EXIT_SUCCESS;
	#else
	cerr << "ERROR: It was not able to detect on which OS this applcation is running. Nothing was made." << endl;
	#endif

	return EXIT_FAILURE;
}