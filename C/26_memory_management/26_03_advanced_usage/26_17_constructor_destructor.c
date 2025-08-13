/*
* In C there's no constructor or destructor like in C++.
* This "way" >>may<< be used, however, this also causes
* an undefined behavior.
*/

#ifdef __cplusplus
#warning "This shall be build with a C compiler only!"
#else
#warning "This samples may contain undefined behaviors!"

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_ELEMENTS	100

void init_pointers(int *ptr);
void destroy_pointers(int *ptr);

//	"constructor" => What happens, if your "ptr" is NOT null
//	or you're using the NULL expression instead?
void init_pointers(int *ptr) {
	ptr = (int *) malloc(sizeof(int) * NUMBER_OF_ELEMENTS);

	if (ptr == NULL) {
		puts("Something was wrong... ¯\\_(ツ)_/¯");
		return;
	}

	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		ptr[i] = (i * i);
		printf("position %d, field value : %d\n", i, ptr[i]);
	}

	//	since ptr does "not return", because the return statement
	//	is not given (void function), but who says, that ptr is
	//	now unable to use outside?
	//
	//	Since "int *ptr" is given, this can also be modified. To avoid this
	//	leak, set *ptr to readonly by using "const int *ptr". In that case
	//	*ptr can be used inside the function, but this is not be able to
	//	modify in any way.
}

//	"destructor"
void destroy_pointers(int *ptr) {
	free(ptr);
}

int main(void) {
	int *ptr_to_use = NULL;
	init_pointers(ptr_to_use);
	destroy_pointers(ptr_to_use);

	//	Surprised, that this (may) work?
	//	Since NULL is given, the C compiler might interpret this to
	//	a valid field to work with.
	// init_pointers(NULL);
	// destroy_pointers(NULL);

	//	This, however, should not work. If this works on your machine,
	//	then this is not an useful example!
	// int *field = calloc(NUMBER_OF_ELEMENTS, sizeof(int));
	// init_pointers(field);
	// destroy_pointers(field);

	return EXIT_SUCCESS;
}

#endif