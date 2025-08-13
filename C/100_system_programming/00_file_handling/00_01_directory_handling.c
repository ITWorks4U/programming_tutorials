/**	system programming in C
 *
 *	handle with directories
 *
 *	ITWorks4U
*/

#ifdef _WIN32
#error "These samples were written for UNIX/Linux/macOS only. Windows can't be used here."
#else

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>
#include <stdbool.h>

bool on_directory(const char *fileName) {
	bool is_directory = false;
	struct stat *file_stat = calloc(1, sizeof(struct stat));
	assert(file_stat != NULL);

	/*	int stat(const char *path, struct stat *buf);
	*	lists properties of a file given by path and stores it to buf
	*/
	stat(fileName, file_stat);

	//	prints the size of the file
	printf(" size: %ld bytes ", file_stat->st_size);

	//get the file type, where 'd' represents a directory
	mode_t file_type = file_stat->st_mode & S_IFMT;

	//	Have we found a directory?
	if (file_type == S_IFDIR) {
		is_directory = true;
	}

	free(file_stat);
	return is_directory;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage %s <file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	/*	DIR *opendir(const char *name);
	*	Opens a directory stream corresponding to the directory name. On success,
	*	it returns a function pointer to the directory stream, on fail, NULL returns
	*	and errno is set.
	*/

	DIR *dir_ptr = NULL;
	if ((dir_ptr = opendir(argv[1])) == NULL) {
		perror("opendir()");
		return EXIT_FAILURE;
	}

	/*	struct dirent *readdir(DIR *dirp);
	*	Reads the content of directory dirp, where the first found file
	*	is read only, unless we're using a loop.
	*/
	struct dirent *dir_content = NULL;
	while ((dir_content = readdir(dir_ptr))) {
		printf("file: %s -> ", dir_content->d_name);

		if (on_directory(dir_content->d_name)) {
			puts("is a directory");
		} else {
			puts("is not a directory");
		}
	}

	//	closes a DIR* stream
	if (closedir(dir_ptr) < 0) {
		perror("closedir()");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

#endif