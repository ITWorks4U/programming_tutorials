/*
* Unlike to the other source file, when a SIGFPE has been triggerd,
* then the loop shall be continued until the base condition does no
* longer be true.
*
* How to do this? By "jumping out" of that error.
* This is not a good practice, however, this shall be demonstrated here.
*/

#ifdef __cplusplus
#error "This source code can't be build with a C++ compiler. Use a C compiler instead."
#else
#include <stdio.h>
#include <stdlib.h>

//	allows to use jmp_buf structure, longjump() and setjump()
#include <setjmp.h>

//	our "handler" for division by 0
static jmp_buf division_zero_jumper;

void division_by_zero_handler(int demoninator) {
	fprintf(stderr, "demoninator: %d => not allowed for calculation\n", demoninator);

	/*
	* void longjmp(jmp_buf _buf, int value); (May be also differently defined.)
	*
	* continue the normal workflow by activating the jumper to
	* "jump off the current pitfall"
	*/
	longjmp(division_zero_jumper, 1);
}

int main(void) {
	int a = 100;

	for(int i = 10; i >= -10; i -= 2) {
		/*
		* While division_zero_jumper is still unset, we're trying to do our stuff.
		* At any point i == 0, we'll handle that issue and we can still continue
		* our workflow. When the jumper has been triggerd, a reset to the default state
		* on the next run shall be done.
		*/

		if(!setjmp(division_zero_jumper)) {
			if(i == 0) {
				division_by_zero_handler(i);
			} else {
				printf("%d / %d = %d\n", a, i, a/i);
			}
		}
	}

	return EXIT_SUCCESS;
}
#endif