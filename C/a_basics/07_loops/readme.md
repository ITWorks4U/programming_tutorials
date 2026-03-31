#   repeat code over and over again
-   can be used to increment numbers or repeat code
-   different way to handle this:
    -   iteration (for, while, do-while)
    -   recursion (use this with care)
    -   goto (use this with more care than recursion)


### for:
-   initializing an index, often used `i` and modify i for the next step until an condition does no longer exist
    -   `i++ | i--` := modify i after the current operation
    -   `++i | --i` := modify i before the current operation takes action
```
for(int i = 0; i < 10; i++) {}

for(int i = 100; i >= 0; --i) {}
```

### while:
-   runs over and over again while a condition is set
    >   **NOTE**:   Make sure to toggle the condition from `true` (1) to `false` (0), otherwise an endless loop appears.

```
int counter = 0;
while(counter != 100) {
    // do something here
    counter++;
}
```

### do-while:
-   similar to while loop, where the instruction(s) in this loop runs at least once
-   the do-while statement must be termianted with a semicolon

```
int counter = 0;
do {
    // do something
    counter++;
} while (counter != 100);
```

### recursion
-   similar to a while loop, but it does not have a counter to handle
-   contains less code than any iteration
-   often used in math
    -   fibonacci series
    >   **NOTE**:   The higher the number the more time amount is required to calculate the next result until you're using an internal storage to reduce already handled numbers over and over again.
    -   factorial
    -   great common divider
    -   some sorting algorithms
    -   ...
-   takes more CPU / RAM
-   may be faster than an iteration
-   if an internal number of recursion depth has been reached, then the application crashes
 
 ```
 // bad example
 int fibonacci(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void) {
    for(int i = 0; i <= 30; i++) {
        printf("fib(%d) = %d\n", i, fibonacci(i));
    }
    return EXIT_SUCCESS;
}
 ```
>   **NOTE**:   In chapter 36 an optimization for the fibonacci series has been implemented there.

### goto
-   only in use, if you **really** needs to jump to a certain mark
    -   more in use for assembly instructions to speed up the execution process
    -   you **must** care about to use the goto statement(s)
-   causes "spaghetti-code"

```
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int counter = 0;
    mark:
    printf("counter = %d\n", counter);

    if (counter < 10) {
        goto mark;
    }

    return EXIT_SUCCESS;
}
```