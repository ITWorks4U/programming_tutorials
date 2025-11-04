/*
* All examples before told you how to learn the first steps with C, sometimes with C++, too,
* but now it's time to learn, how to manage memory on runtime.
*
* When memory on runtime is required, then you can easily create a buffer to use, if enough
* free space of RAM still exists. Make sure, that YOU MUST also release those memory, otherwise
* a memory leak appears.
*
* When the application terminates in the normal way, then all created memory for:
* - file operations
* - network streams
* - dynamic memory management
* - ...
* will be released automatically.
*
* But if the application terminates abnormally, then those clean up
* is not going to do.
*
* Memory management by using raw pointers is in C fundamental. In C++, this can be used,
* but the behavior is often different. In C++ you should use smart pointers instead.
*
* By the way, a pointer does not often mean, that this is caused by a dynamic memory management.
* It depends on, how that pointer has been used. Take a look to the sources files.
*
* What exactly is a pointer? A pointer points to a memory address, where the value of a variable,
* a structure, a function, ... has been placed on runtime to use it for the application.
*
* A pointer has a fixed size by default, where this "size" does not mean, that any data must
* have be compressed to that size. This size is in use for the computer to work with that
* pointer correctly.
*
* |-------------------|---------------------|
* |  OS architecture  |  size of a pointer  |
* |-------------------|---------------------|
* |  64 bit           |  8 bytes            |
* |  32 bit           |  4 bytes            |
* |  16 bit           |  2 bytes            |
* |  8 bit            |  1 byte             |
* |-------------------|---------------------|
*/

int main(void) {
	// nothing to do here
	return 0;
}