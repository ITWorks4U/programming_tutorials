/*
* To define a dynamic refence, you have to use a function, like malloc, calloc, realloc.
* On some systems other functions, like valloc, kmalloc, aligned_malloc(C 11), dlmalloc, ...
* can also be used, however, mostly malloc is in use.
*
* Each of these functions returns void*. It looks like a "dynamic pointer", however, that's
* wrong. The type void* is a typeless pointer and it must refer to an object. The function
* itself returns a reference on which memory the amount of required bytes has been created
* to work with our object.
*
* Attention: Every allocated memory MUST be released by your own, before the application is going to terminate,
* otherwise memory leaks appears. In some cases it MAY ALSO AFFECT your whole machine!
*
* A memory leak is a block of n bytes, which is still available, but no pointer refers to this block.
* On a normal application termination every allocated memory is automatically released, however,
* it an abnormal application termination is in use or on application runtime itself
* it will "break your neck", when you don't mind that.
*
* There're different ways to allocate memory:
* -	malloc     (C/C++)
* -	calloc     (C/C++)
* -	realloc    (C/C++)
* -	valloc     (C/C++; may work, but it's not a guarantee)
* -	new        (C++ only)
*
* attention:
* - unlike to C, in C++ you MUST cast it to your specified data type, because every function (except new) returns void*
*
* there're two ways to releasing allocated memory:
* -	free       (C/C++)
* -	delete     (C++ only)
*
* fun fact:
* In C++ you might use new to allocate memory and use the C-function free()
* to release this memory, as well as, by using malloc() to allocate and
* delete to remove this allocated memory. But that's not recommented.
*
* ------------------------------
* >>   Allocate memory of n bytes. It returns an address, where n bytes are now
* >>   available, however, your variable(s), struct(s), field(s) contains
* >>   garbage and must be initialized later
* void *malloc(size_t __size);
*
* ------------------------------
* >>   Acts like malloc, however, your object is initialized with a
* >>   default value, depending on the data type:
* >>   - int, short, long, float, double = 0(.0(F))
* >>   - char = '\0'
* >>   - C-string = "\0\0...\0"
* >>   - pointer(s) = NULL
*
* >>   argument #0: how many times an object needs to be allocated
* >>   argument #1: the amount of bytes for each object
* void *calloc(size_t __nmemb, size_t __size);
*
* ------------------------------
* >>   Reallocating more memory for an already allocated pointer.
* >>   It can also be used to allocate memory for the first time.
* >>   argument #0: pointer to use (can be NULL / nullptr in C++)
* >>   argument #1: additional amount of bytes
* void *realloc(void *__ptr, size_t __size);
*
* ------------------------------
* >>   MAY work like malloc/calloc/realloc, may also cause
* >>   an error on compile or runtime. => Hardly used.
* void *valloc(size_t __size);
*
* ------------------------------
* >>   releasing memory in C/C++:
* void free(void* __ptr);
*
* ATTENTION:
* __ptr MUST be allocated by malloc, calloc, realloc (valloc), ... before,
* otherwise a segmentation fault occurs
*
* often misunderstood:
* By using a pointer it doesn't mean, that this is always going to store on the heap.
* Even the stack can also hold pointers, however, it depends on if the pointer
* has a fixed size or a dynamically size during the runime. So, if you're using
* a pointer with a fixed size, this is often stored on the stack and by
* using a function like free() or delete expression in C++ an undefined behavior,
* or segmentation fault occurs.
*
* ------------------------------
* >>	releasing memory in C++ only:
* delete ptr;
*
* hint (for C and C++):
* Even your pointer has been successfully freed/deleted from memory, your pointer
* STILL EXISTS to that address, which has been used before! But by using the pointer
* after free()/delete, you'll get a segmentation fault, because this address is no
* longer assigned to that pointer. Assigning with NULL (C) / nullptr (C++) helps you
* define this pointer as invalid.
*
* There're also programs, which helps you to reveal potentially memory leaks in your
* application. On Linux you can use the program "valgrind". Other applications, like
* DrMemory, PVS studio, ... are also very useful!
*/

#ifdef __cplusplus
#warning "This example is usually written in C and shall be build with a C compiler only. It may happen, that you'll receive warning(s), error(s) or undefined behavior(s)!"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH	100

struct Person {
	// just a normal member
	int person_id;

	// f_name and l_name are static C-strings
	char f_name[BUFFER_LENGTH];
	char l_name[BUFFER_LENGTH];

	// birth_date, however, is a dynamic C-string
	// and must be handled in a different way
	char *birth_date;
};

void use_static_reference(void) {
	struct Person p;
	p.person_id = 1;
	memset(p.f_name, '\0', BUFFER_LENGTH);
	memset(p.l_name, '\0', BUFFER_LENGTH);

	// since birth_date is a dynamic C-string,
	// often called "field", this must be initialized
	// with a function, like malloc, calloc, ...

	// you need the size of the data type first and multiply this
	// with a known number to let allow to store up to 99 characters
	// (p.birth_date[99] = '\0') for now

	// important: in C++ you MUST cast the pointer reference
	// to the known / expected data type, otherwise the application
	// can't be build
	p.birth_date = (char *) malloc(sizeof(char) * BUFFER_LENGTH);
	memset(p.birth_date, '\0', BUFFER_LENGTH);

	// do something here

	// usually, when this function has been left, the used storage of p
	// is autoamtically removed from the STACK, but since p.birth_date
	// has been initialized with malloc, calloc, ..., this MUST be
	// released, otherwise a memory leak results

	// for C / C++
	free(p.birth_date);

	// C++ only
	#ifdef __cplusplus
	delete p.birth_date;
	#endif

	// hint: never, really NEVER release an already released pointer,
	// otherwise it will crash your application
}

void use_dynamic_reference(void) {
	// a dynamic reference may look like:
	struct Person *p0 = (struct Person *) malloc(sizeof(struct Person));

	// you COULD also use malloc(212), because your structure requires
	// a total amount of 212 bytes (4 bytes (int), 2x 100 bytes (C-string), 8 bytes (char*)),
	// but if this structure is going to update, you won't be happy with the fixed number

	// Unlike to p->birth_date, why is malloc be able to allocate the correct amount of bytes?
	// Any field must be written with its type, followed by how many additional bytes with the
	// size of the data type are required.
	//
	// To avoid such confusing, you could also use calloc() function:
	// void *calloc(size_t _count, size_t _size);
	// _count: how many elements are requested
	// _size: the size of the field

	// in C++ you may write:
	// Person *p0 = new Person();
	//

	// this is not required, but recommended
	// hint: in C++ use nullptr instead, because
	// NULL is different defined rather thant C
	if (p0 == NULL) {
		// there was not enough free space and we can skip
		// this process or do anything else
		perror("p0");
		return;
	}

	// How to access to p's members? Since p is now a pointer to an address
	// the members are unable to call on the direct way.
	// The pointer address must be dereferenced first to be able to access
	// to the members itself.

	// ERROR
	// p.person_id = 1;

	// you have to use one of these two methods instead:
	// (1) *(p.person_id) => can be used, but this causes misspelling at any time
	// (2) p->person_id => short form and tells you, that p "points" to person_id
	//
	// fun facts:
	// - in a data structure the pointer points to the first member
	// - in a field the pointer points to the first element
	p0->person_id = 1;

	memset(p0->f_name, '\0', BUFFER_LENGTH);
	// similar to the already used methods

	// IMPORTANT:
	// - if p->birth_date has been initialized with malloc, calloc, ... before,
	//   then this MUST also be released first, before p0 is going to release
	// - if p->birth_date, however, has never been touched, then you MUST NOT
	//   release this field

	// release p0 from memory
	free(p0);

	// for C++ only and remember in general:
	// if a pointer has been released (in any way), thus MUST NOT be released again
	//
	// delete p0;
	//

	// by the way, in C++ delete the command may also handle:
	// delete *pointer <= in that case this causes a memory leaks or an
	// undefined behavior => take a look to 26_20_delete_behavior.cpp

	// ------------
	// use calloc instead
	// ------------
	struct Person *p1 = (struct Person *) calloc(1, sizeof(struct Person));
	if (p1 == NULL) {
		perror("p1");
		return;
	}

	// do something here
	free(p1);
}

void use_file_stream(void) {
	// Do you remember to use file stream(s)?
	// This is just a pointer usage.

	// __FILE__ => your current file name
	FILE *source = fopen(__FILE__, "r");

	if (source == NULL) {
		perror("fopen()");
		return;
	}

	char temp_buffer[BUFFER_LENGTH];
	memset(temp_buffer, '\0', BUFFER_LENGTH);

	while((fgets(temp_buffer, (BUFFER_LENGTH - 1), source)) != NULL) {
		printf("%s", temp_buffer);
	}

	fclose(source);
}

struct Person *use_for_outside(void) {
	// this allows you to handle the person structure for outside
	// similar to FILE *source = fopen(...)
	//
	// that means, that this structure MUST also be released,
	// because when this function pointer has been left, the
	// allocated memory is still available
	//
	// you can use free() function as well as a customized function
	return (struct Person *) calloc(1, sizeof(struct Person));
}

void remove_person_from_memory(struct Person *p) {
	// this is not required, but you should know,
	// that this might be a mistake here
	if (p != NULL) {
		free(p);
	}
}

int main(void) {
	// simple example
	int data = 9;
	int *data_pointer = &data;

	printf("data = %d, address = %p\n", data, data_pointer);
	// data_pointer does not be removed from memory by using
	// free(), because this pointer has never been managed
	// with malloc(), calloc(), ... and it will be removed
	// automatically from the stack, when the function or the block ends, here: main

	// hint: there's also a difference for NULL
	// in C: NULL := ((void *)0)
	// in C++: NULL := 0

	// C++ also comes with nullptr, but this is not
	// identical to NULL; that's just a new data type instead

	use_static_reference();
	use_dynamic_reference();
	use_file_stream();

	struct Person *p = use_for_outside();
	// do whatever you want to do

	// either:
	// free(p);
	// or:
	remove_person_from_memory(p);

	// What might happen here? Since NULL argument or any NULL-pointer
	// is given, nothing happens. Luckily.
	free(NULL);

	// By the way, since you know, that uninitialized variables
	// contains garbage on runtime, guess what uninitialized
	// pointers may contain...? :D
	//
	// You should never use uninizalized pointers!

	return EXIT_SUCCESS;
}