#ifdef __cplusplus
#error "This sample can be build with a C compiler only."
#else
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_LENGTH 100

/*
* There're different ways to allocate memory during runtime, like
* malloc, calloc, realloc, valloc, ...
*
* But what's the difference between these instructions?
*/

struct Person {
	int person_id;
	char f_name[BUFFER_LENGTH];
	char l_name[BUFFER_LENGTH];
	char *birth_date;
};

void use_malloc(void) {
	// --------------------------------------
	// Since you're using malloc, your members contains garbage!
	// Try to figure out, what happens here. Depending on your OS, the results differs.
	// --------------------------------------
	puts("--------------------\nmalloc\n--------------------");
	struct Person *p = (struct Person *) malloc(sizeof(struct Person));

	printf("size of person in bytes: ");
	#ifdef _WIN32
	printf("%u, ", sizeof(struct Person));
	#else
	printf("%lu, ", sizeof(struct Person));
	#endif
	printf("location: %pH\n", p);

	puts("members:");
	printf(
		"person-id => %pH (%d)\nf_name => %pH (%s)\nl_name => %pH (%s)\nbirth_date: %pH (%s)\n",
		&p->person_id, p->person_id, p->f_name, p->f_name, p->l_name, p->l_name, p->birth_date, p->birth_date
	);
	free(p);
}

void use_calloc(void) {
	// --------------------------------------
	// - "clean allocation"
	// - unlike to malloc() your members are going to
	//   initialize with a fixed value, like 0 for integer types,
	//   an empty word for C-Strings, NULL/nullptr for any pointer etc
	// --------------------------------------
	puts("--------------------\ncalloc\n--------------------");
	struct Person *p = (struct Person *) calloc(1, sizeof(struct Person));

	printf("size of person in bytes: ");
	#ifdef _WIN32
	printf("%u, ", sizeof(struct Person));
	#else
	printf("%lu, ", sizeof(struct Person));
	#endif
	printf("location: %pH\n", p);

	puts("members:");
	printf(
		"person-id => %pH (%d)\nf_name => %pH (%s)\nl_name => %pH (%s)\nbirth_date: %pH (%s)\n",
		&p->person_id, p->person_id, p->f_name, p->f_name, p->l_name, p->l_name, p->birth_date, p->birth_date
	);
	free(p);
}

void use_realloc(void) {
	puts("--------------------\nrealloc\n--------------------");
	const int additional_space = 50;

	// calloc also works here...
	struct Person *p = (struct Person *) malloc(sizeof(struct Person));

	// any operations here

	// --------------------------------------
	// - reallocation memory
	// - an already allocated memory can be expand by n additional bytes
	// - this function can also be used to create new memory, but this is hardly used
	// - realloc also don't care about the variable's / member's content and you'll
	//   receive garbage on runtime
	// --------------------------------------
	p = (struct Person *) realloc(p, additional_space);

	printf("size of person in bytes: ");
	#ifdef _WIN32
	printf("%u, ", sizeof(struct Person));
	#else
	printf("%lu, ", sizeof(struct Person));
	#endif
	printf("location: %pH\n", p);

	puts("members:");
	printf(
		"person-id => %pH (%d)\nf_name => %pH (%s)\nl_name => %pH (%s)\nbirth_date: %pH (%s)\n",
		&p->person_id, p->person_id, p->f_name, p->f_name, p->l_name, p->l_name, p->birth_date, p->birth_date
	);
	free(p);
}

void try_to_use_valloc(void) {
	// it may happen, that this does not work on your machine
	
	#ifdef _WIN32
	puts("Function valloc() is unknown. Use VirtualAlloc() (Windows.h), or _aligned_malloc() (malloc.h) instead.");
	#else
	// --------------------------------------
	// - page aligned memory allocating
	// - it has a similar effect like malloc(), but it's kept for
	//   historical reasons and it's also hardly used today
	// - valloc also don't care about the variable's / member's content and you'll
	//   receive garbage on runtime
	//
	// - more informations:
	//   https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-valloc-page-aligned-memory-allocator
	// --------------------------------------
	puts("--------------------\nvalloc\n--------------------");
	struct Person *p = (struct Person *) valloc(sizeof(struct Person));

	printf("size of person in bytes: %lu, location: %pH\n", sizeof(struct Person), p);

	puts("members:");
	printf(
		"person-id => %pH (%d)\nf_name => %pH (%s)\nl_name%pH (%s)\nbirth_date: %pH (%s)\n",
		&p->person_id, p->person_id, p->f_name, p->f_name, p->l_name, p->l_name, p->birth_date, p->birth_date
	);
	free(p);
	#endif
}

int main(void) {
	puts("Warning: Not every function may work on your machine.");

	use_malloc();
	use_calloc();
	use_realloc();

	// this may not work
	try_to_use_valloc();

	return EXIT_SUCCESS;
}
#endif