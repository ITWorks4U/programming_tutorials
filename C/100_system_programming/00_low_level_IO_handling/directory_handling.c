/*
* system programming in C
*
* Handle with directories. Check, if a file could be
* a regular file or a directory.
*
* This source code has been updated to work on
* UNIX, as well as, on Windows.
*
* NOTE:     PATH_MAX is not a common on all operating
*           systems. On Windows the size is set to 260,
*           on a macOS this is limited to 1,024 and on a
*           Linux machine this has a size of 4,096.
*
* author:   ITWorks4U
* created:  January 1st, 2022
* updated:  November 4th, 2025
*
* youtube:  @itworks4u
* github:   github.com/ITWorks4U
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>

#ifdef _WIN32
#include <Windows.h>
#define SEPARATOR '\\'
#else
#include <dirent.h>
#define SEPARATOR '/'
#endif

#ifndef MAX_PATH
#define MAX_PATH PATH_MAX
#endif

#include <stdbool.h>

bool on_directory(const char *full_file_path) {
	#ifdef _WIN32
	DWORD attr = GetFileAttributesA(full_file_path);
	if (attr == INVALID_FILE_ATTRIBUTES) {
		fprintf(stderr, "GetFileAttributes() failed for %s\n", full_file_path);
		return false;
	}

	WIN32_FILE_ATTRIBUTE_DATA fad;
	if (GetFileAttributesExA(full_file_path, GetFileExInfoStandard, &fad)) {
		LARGE_INTEGER size;
		size.HighPart = fad.nFileSizeHigh;
		size.LowPart = fad.nFileSizeLow;
		printf(" size: %lld bytes ", size.QuadPart);
	}

	return (attr & FILE_ATTRIBUTE_DIRECTORY);
	#else
	struct stat file_stat;

	/*
	* int stat(const char *path, struct stat *buf);
	*
	* lists properties of a file given by path and stores it to buf
	*/
	if (stat(full_file_path, &file_stat) < 0) {
		perror("stat()");
		return false;
	}

	// prints the size of the file
	printf(" size: %ld bytes ", file_stat.st_size);

	// returns true, if a directory has been found
	// false, otherwise
	return S_ISDIR(file_stat.st_mode);
	#endif
}

int main(int argc, char **argv) {
	if (argc != 2) {
		#ifdef _WIN32
		char *last_token = strrchr(argv[0], '\\');
		#else
		char *last_token = strrchr(argv[0], '/');
		#endif

		char *application_name = (last_token) ? last_token + 1 : argv[0];
		last_token = NULL;
		fprintf(stderr, "usage %s <path_to_use>\n", application_name);
		return EXIT_FAILURE;
	}

	#ifdef _WIN32
	char search_path[MAX_PATH];
	snprintf(search_path, sizeof(search_path), "%s\\*", argv[1]);

	WIN32_FIND_DATAA file_data;
	HANDLE hFind = FindFirstFileA(search_path, &file_data);

	if (hFind == INVALID_HANDLE_VALUE) {
		fprintf(stderr, "FindFirstFile() failed for %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	do {
		if (strcmp(file_data.cFileName, ".") == 0 || strcmp(file_data.cFileName, "..") == 0) {
			continue;
		}

		char full_path[MAX_PATH];

		// NOTE: The compiler might throw a warning, that the path limitation (Windows: 260)
		//       may be exceeded and this may leads into an undefined behavior. Even the given
		//       absolute path does not exceeds 259 + \0 characters.
		// snprintf(full_path, sizeof(full_path), "%s%c%s", argv[1], SEPARATOR, file_data.cFileName);

		// use this block instead
		// --------
		strncpy(full_path, argv[1], sizeof(full_path) - 1);
		full_path[sizeof(full_path) - 1] = '\0';

		size_t len = strlen(full_path);
		if (len + 1 < sizeof(full_path) - 1) {
			full_path[len++] = SEPARATOR;
			full_path[len] = '\0';
		}

		strncat(full_path, file_data.cFileName, sizeof(full_path) - strlen(full_path) - 1);
		// --------

		printf("file \"%s\" is a directory: %s\n", full_path, on_directory(full_path) ? "yes" : "no");
	} while (FindNextFileA(hFind, &file_data));

	FindClose(hFind);
	#else
	/*
	* DIR *opendir(const char *name);
	* Opens a directory stream corresponding to the directory name. On success,
	* it returns a function pointer to the directory stream, on fail, NULL returns
	* and errno is set.
	*/

	DIR *dir_ptr = opendir(argv[1]);
	if (dir_ptr == NULL) {
		perror("opendir()");
		return EXIT_FAILURE;
	}

	/*
	* struct dirent *readdir(DIR *dirp);
	* Reads the content of directory dirp, where the first found file
	* is read only, unless we're using a loop.
	*/
	struct dirent *entry = NULL;
	char absolute_path[MAX_PATH];

	while ((entry = readdir(dir_ptr))) {
		// skip . and ..
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
			continue;
		}

		bool already_contains_separator = argv[1][strlen(argv[1]) - 1] == SEPARATOR;

		if (already_contains_separator) {
			snprintf(absolute_path, sizeof(absolute_path), "%s%s", argv[1], entry->d_name);
		} else {
			snprintf(
				absolute_path, sizeof(absolute_path), "%s%c%s",
				argv[1], SEPARATOR, entry->d_name
			);
		}

		printf("file \"%s\" is a directory: %s\n", absolute_path, on_directory(absolute_path) ? "yes" : "no");
	}

	// closes a DIR* stream
	if (closedir(dir_ptr) < 0) {
		perror("closedir()");
		return EXIT_FAILURE;
	}
	#endif

	return EXIT_SUCCESS;
}