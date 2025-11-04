/*
* System programming in C.
*
* Scan a folder recursively from any start path.
* This sample works for Windows, as well as, UNIX.
*
* NOTE: Depending on which path you're starting the amount of
*       used memory could be high or not all data can be displayed,
*       because every detected sub folder is also going to scan.
*
* NOTE: Typically a file can also be displayed as: "-|d|c|b|p|l|srwxrwxrwx",
*       however, on a Windows machine this is hard to display, unless using
*       Windows API with too much complexity and possibly limited informations.
*       In summary, such a display can be provided on an UNIX system only.
*       See: unix_only/scan_[relative|absolute]_path.c
*
* author:  ITWorks4U
* created: October 13th, 2025
* updated: November 3rd, 20257
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// using max maximum path length (MAX_PATH_LENGTH) of 4096 bytes
//
// NOTE:
//       On Windows an internal constant of MAX_PATH with 260 bytes
//       exists, however, on compile time a warning may appear,
//       when the MAX_PATH could be too small to handle the
//       current path and this may lead to an undefined behavior.
//
//       On an UNIX system PATH_MAX exists, however, this may be
//       not identically defined on every UNIX system. On a Linux
//       system this is typically given with a size of 4096 bytes,
//       whereas on a macOS PATH_MAX may have a size of 1024 bytes.
#define MAX_PATH_LENGTH 4096

/// @brief Contains a small summary for the scan(s).
typedef struct {
	int nbr_of_valid_paths;
	int nbr_of_invalid_paths;
} ScanSummary;

#ifdef _WIN32
// only for Windows
#include <Windows.h>
#include <io.h>
#define F_OK 0
#define access _access
#else
// only for UNIX systems
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

static ScanSummary _scan_summary = {0,0};

/// @brief Boolean flag, if each scanned file shall be displayed on stdout,
/// including every error. If set to false, no scan output unless the summary
/// will be printed to stdout.
static bool _with_output = false;

/// @brief Scan the current directory for all files inside, if possible.
/// If a sub directory has been found, then a recursive scan from this sub directory
/// is in use.
/// @param current_path the current path
void scan_directory(const char *current_path) {
	#ifdef _WIN32

	WIN32_FIND_DATA findData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	char search_path[MAX_PATH_LENGTH];
	memset(search_path, '\0', MAX_PATH_LENGTH);
	snprintf(search_path, MAX_PATH_LENGTH, "%s\\*", current_path);

	hFind = FindFirstFile(search_path, &findData);
	if (hFind == INVALID_HANDLE_VALUE) {
		if (_with_output) {
			fprintf(stderr, "Error opening directory: %s => The path is invalid.\n", current_path);
		}

		_scan_summary.nbr_of_invalid_paths++;
		return;
	}

	_scan_summary.nbr_of_valid_paths++;

	while (FindNextFile(hFind, &findData) != 0) {
		const char *name = findData.cFileName;

		// skip "." and ".."
		if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
			continue;
		}

		char full_path[MAX_PATH_LENGTH];
		memset(full_path, '\0', MAX_PATH_LENGTH);
		snprintf(full_path, MAX_PATH_LENGTH, "%s\\%s", current_path, name);

		if (_with_output) {
			printf("%s\n", full_path);
		}

		// if the current path is also a directory, then
		// go into this directory and scan all available files, if possible
		if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			scan_directory(full_path);
		}
	}

	FindClose(hFind);
	#else

	DIR *dir;
	struct dirent *entry;

	dir = opendir(current_path);
	if (dir == NULL) {
		if (_with_output) {
			perror("opendir()");
		}
		_scan_summary.nbr_of_invalid_paths++;

		return;
	}

	_scan_summary.nbr_of_valid_paths++;

	while ((entry = readdir(dir)) != NULL) {
		const char *name = entry->d_name;

		// skip "." and ".."
		if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) {
			continue;
		}

		char full_path[MAX_PATH_LENGTH];
		memset(full_path, '\0', MAX_PATH_LENGTH);
		snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", current_path, name);

		if (_with_output) {
			printf("%s\n", full_path);
		}

		struct stat st;

		// if the current path is also a directory, then
		// go into this directory and scan all available files, if possible
		if (stat(full_path, &st) == 0 && S_ISDIR(st.st_mode)) {
			scan_directory(full_path);
		}
	}

	closedir(dir);
	#endif
}

int main(int argc, char **argv) {
	// if one additional argument is given, use this as start point,
	// otherwise use the current folder structure
	//
	// NOTE: argv[0] is your own application itself
	char *path_to_start = (argc == 2)? argv[1] : ".";

	// To make sure to have a valid path, the path will
	// be checked by a python script, where the result value
	// determines, if the path was valid or not.
	// NOTE: If the certain python file does not exist, then
	//       the given path can't be checked, thus you can still
	//       use this path, however, without a (possible) valid
	//       path the application may lead into an undefined behavior.
	const char python_file[] = "check_on_valid_path.py";
	bool scan_path_available = true;

	if (access(python_file, F_OK) != 0) {
		fprintf(
			stderr,
			"Error: The expected python file \"%s\" was unable to find. Use the given path \"%s\" with care.\n",
			python_file, path_to_start
		);
	} else {
		// NOTE: using system(const char *command); is not a valid
		//       solution of all time, unless you know, what you do
		char external_command[MAX_PATH_LENGTH];
		memset(external_command, '\0', MAX_PATH_LENGTH);

		#ifdef _WIN32
		snprintf(external_command, MAX_PATH_LENGTH - 1, "python.exe %s \"%s\"", python_file, path_to_start);
		#else
		// NOTE: On an UNIX system python3 shall be used to make sure to use
		//       the python 3 interpreter. Otherwise a python 2 interpreter,
		//       if existing, could be launched and this may not be able to
		//       handle the python 3 script. Moreover, depending on how "python"
		//       is defined with an alias, this could also lead to python3.
		snprintf(external_command, MAX_PATH_LENGTH - 1, "python3 %s \"%s\"", python_file, path_to_start);
		#endif

		int exit_code = system(external_command);

		// NOTE: The system() function may not return 0|1, depending on the
		//       used platform. It may happen to receive any other value, like 256.
		//       For 256 the 8th bit is set with 1 and the result must be
		//       right shifted by 8 bits to reveal the real return value instead.
		// printf("exit_code: %d\n", exit_code);

		if (!(exit_code == 0 && exit_code == 1)) {
			exit_code = (exit_code >> 8);
		}

		if (exit_code != 0) {
			fprintf(stderr, "Error: The given path \"%s\" was invalid.\n", path_to_start);
			scan_path_available = false;
		}
	}

	if (scan_path_available) {
		printf("starting on path: \"%s\"...\n", path_to_start);
		scan_directory(path_to_start);

		char line_separator[] = "--------------";
		printf(
			"\n%s\nsummary:\nvalid paths / files detected:   %d\ninvalid paths / files detected: %d\n%s\n",
			line_separator, _scan_summary.nbr_of_valid_paths, _scan_summary.nbr_of_invalid_paths, line_separator
		);
	}

	return EXIT_SUCCESS;
}