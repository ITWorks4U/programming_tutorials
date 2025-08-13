/*
* Check it out, if a variable / field has been stored
* to the stack (static) or to the heap (dynamic) memory management.
*/

#ifndef _WIN32
//	required for pthread_getattr_np function
#define _GNU_SOURCE

//	Windows doesn't have the pthread library.
#include <pthread.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <Windows.h>

#define LOCATED_ON_STACK	1
#define LOCATED_ON_HEAP		0
#define FAILED_PROCEDURE	-1
#endif

struct S {
	int a;
	int b;
	//...
};

int on_heap(const void *ptr) {
	#ifdef _WIN32
	//	only for Windows
	MEMORY_BASIC_INFORMATION mbi;
	VirtualQuery(ptr, &mbi, sizeof(mbi));

	if (mbi.State != MEM_COMMIT) {
		// not committed memory
		return FAILED_PROCEDURE;
	}

	// check if the memory is located on the stack
	if (mbi.Type == MEM_PRIVATE && mbi.Protect == PAGE_READWRITE) {
		// stack allocations are MEM_PRIVATE with PAGE_READWRITE
		//	and the AllocationBase == StackBase
		DWORD_PTR stack_top;
		NT_TIB *tib = (NT_TIB *)NtCurrentTeb();
		stack_top = (DWORD_PTR)tib->StackBase;

		if ((DWORD_PTR)ptr < stack_top && (DWORD_PTR)ptr >= (DWORD_PTR)tib->StackLimit) {
			//	stored on the stack
			return LOCATED_ON_STACK;
		}
	}

	// Check if the memory is heap (typical heap allocs are MEM_PRIVATE)
	if (mbi.Type == MEM_PRIVATE) {
		return LOCATED_ON_HEAP;
	}

	//	otherwise this is still unknown
	return FAILED_PROCEDURE;

	#else
	//	only for the other OS instead (expected result and never fully tested)

	/*
	* We're using our own running thread to figure out,
	* if the given pointer ptr is stored on the stack or heap.
	*
	* pthread_attr_getstack() checks the previously set address for a stack to
	* figure out, if ptr is located on the stack or heap
	*
	* ATTENTION:
	* This will create pointers on runtime, which are NOT being released automatically!
	*/

	pthread_t self = pthread_self();
	pthread_attr_t attr;

	void *stack = NULL;
	size_t stacksize;
	pthread_getattr_np(self, &attr);
	pthread_attr_getstack(&attr, &stack, &stacksize);

	return ((uintptr_t) ptr >= (uintptr_t) stack && (uintptr_t) ptr < (uintptr_t) stack + stacksize);
	#endif
}

int main(void) {
	int x = 100;
	int array[] = {1,2,3,4,5};
	int *ptr = (int *) calloc(5, sizeof(int));
	int *help = ptr;
	struct S s0;
	struct S *s1 = (struct S*) malloc(sizeof(struct S));
	struct S *s2 = NULL;

	printf("'x'     => %s\n", on_heap(&x) == 0 ? "heap" : on_heap(&x) == 1 ? "stack" : "error");
	printf("'array' => %s\n", on_heap(array) == 0 ? "heap" : on_heap(array) == 1 ? "stack" : "error");
	printf("'ptr'   => %s\n", on_heap(ptr) == 0 ? "heap" : on_heap(ptr) == 1 ? "stack" : "error");
	printf("'help'  => %s\n", on_heap(help) == 0 ? "heap" : on_heap(help) == 1 ? "stack" : "error");
	printf("'s0 '   => %s\n", on_heap(&s0) == 0 ? "heap" : on_heap(&s0) == 1 ? "stack" : "error");
	printf("'s1'    => %s\n", on_heap(s1) == 0 ? "heap" : on_heap(s1) == 1 ? "stack" : "error");
	printf("'s2'    => %s\n", on_heap(s2) == 0 ? "heap" : on_heap(s2) == 1 ? "stack" : "error");

	//	since s2 is NULL, it can be used for free => free(NULL) doesn't do anything
	free(s2);
	free(s1);

	//	!!! double free for free(ptr);	!!!
	//free(help);
	free(ptr);

	return EXIT_SUCCESS;
}