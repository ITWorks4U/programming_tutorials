/*
* It makes no sense to define more than one main function. The main function represents the
* entry point of your application. You may also give the main function arguments to handle
* these input values.
*
* mostly used => attention: any function in C, which has "no arguments" has a different
* behavior in contrast to C++
*/
int main() {
	return 0;
}

/*
* in C this main can be used without accepting any argument
* in C++ this instruction makes no sense => see: 03_function_basics
*/
int main(void) {
	return 0;
}

/* used to handle n arguments for your application */
int main(int argc, char **argv) {
	return 0;
}

/*
* hardly used; in C you'll get a warning on compile time, because a main must be of type int
*
* in C++ you'll get an error instead, because C++ tries to overload this function,
* but those main(s) can't be overloaded, because the type itself differs: int != void
*/

/*
void main() {
}

void main(void) {
}

void main(int argc, char *argv[]) {
}
*/