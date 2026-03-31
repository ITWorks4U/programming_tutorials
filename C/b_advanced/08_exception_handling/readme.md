#   "exception handling" in C
-   unlike to other programming languages in C an exception can't be handled in the usual way
    -   works with signals (attention: different behavior on the certain operating system)
    -   using any primitive way to "handle" an exception
    -   jump over that exception and continue with the workflow

>   **NOTE**:   It may happen, that the executable file may be threatened as a "virus", because these are very old implementations, which were able to bypass any system security in the last years.

####    example
```
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_exception(int exception_number) {
    puts("division by 0 is not allowed");
    exit(0);
}

int main(void) {
    //  NOTE: this may not work on every operating system
    signal(SIGFPE, handle_exception);

    int a = 100;
    for(int i = 10; i >= -10; i -= 2) {
        //  to make sure, that (i = 0) is handled correctly,
        //  combine a condition check and raise the signal instead 
        //  printf("%d / %d = %d\n", a, i, a/i);

        if (i == 0) {
            raise(SIGFPE);
        } else {
            printf("%d / %d = %d\n", a, i, a/i);
        }
    }

    return EXIT_SUCCESS;
}
```