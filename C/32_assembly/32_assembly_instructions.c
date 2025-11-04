/*
* The C programming language is the closest "normal" human readable language to the hardware.
* Your application will be build on the certain hardware. We can also use some
* assembly instructions to speed up some instructions.
*
* However, not every assembly instruction can be used 1:1.
* It depends on the CPU, C-compiler, enviroment, ...
*
* If you want to see how an assembly file may looks like, compile your application with -S <name.s>
* You're also welcome to use more compiler flags, like:
* -O := remove optimizing <=> reduces your assembly instructions
* -fverbose-asm := forces to add useful commands for the assembly file as comments
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 10;
	int b = 15;
	int c;

	/*
	* To declare a block of instructions for assembly, write:
	* asm {}, __asm {}, __asm__ {}, asm ();, ... => depends on your used C compiler
	*/

	/* e. g. for an Intel 8086 CPU */
	// __asm__ {
	// 	// move "a" to AX register (AX = 16 bit register | AH, AL = 8 bit register)
	// 	mov ax, a

	// 	// move "b" to BX register
	// 	mov bx, b

	// 	// add to AX the content of BX
	// 	add ax, bx

	// 	// move to "c" the result from AX
	// 	mov c, ax
	// }

	/*
	* volatile: tells the compiler, that a variable may change on runtime to interact correctly;
	* can be used, but it's no guarantee to work correctly => depends on your C compiler
	*
	* for more informations, take a look to chapter 22
	*/

	// define what to do: "ADD from register EBX the content from EAX"
	asm /*volatile*/ ("addl %%ebx, %%eax;"

		// define an output to store a result to a certain variable
		// hint: on any IDE / OS it may happen, that you see an error here
		: "=a" (c)

		// define inputs to store to EBX and EAX
		: "a" (a), "b" (b)
	);

	printf("a (%d) + b (%d) = %d\n", a, b, c);

	return EXIT_SUCCESS;
}