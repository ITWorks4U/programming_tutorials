/*
* What may happen, if you try to access to a member of 
* a structure / uninitialized field? That's right:
*
* You don't have any clue what comes next.
*/

#ifndef __cplusplus
	#include <stdio.h>
	#include <stdlib.h>
#else
	#include <iostream>
#endif

#define BUFFER_LENGTH   100

struct Person {
	int person_id;
	char f_name[BUFFER_LENGTH];
	char l_name[BUFFER_LENGTH];
	char *birth_date;
};

int main(void) {
	puts("Warning: This sample causes an undefined behavior during runtime!");

	#ifndef __cplusplus
	// usually, this code section can also be used with C++, IF a cast
	// to person is in use
	struct Person *p = (struct Person *) malloc(sizeof(struct Person));
	#else
	// for C++ only
	Person *p = new Person();
	#endif

	if (p == NULL) {
		perror("*p");

		#ifndef __cplusplus
		return EXIT_FAILURE;
		#else
		return 1;
		#endif
	}

	// without initializing the members, you don't know what's coming next

	#ifndef __cplusplus
	// C++ also handles this C usage
	printf(
		"[person_id: %d, f_name: %s, l_name: %s, birth_date: %s]\n",
		p->person_id, p->f_name, p->l_name, p->birth_date
	);
	#else
	std::cout << "[person_id: " << p->person_id << ", f_name: " << p->f_name <<
	", l_name: " << p->l_name << ", birth_date: " << p->birth_date << std::endl;
	#endif

	#ifndef __cplusplus
	// this can also be used for C++
	free(p);
	#else
	delete p;
	#endif

	#ifndef __cplusplus
	return EXIT_SUCCESS;
	#else
	return 0;
	#endif
}