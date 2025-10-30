#   decision making
-   decide, if a condition us true or false (or a bunch of sub conditions are true or false)
-   usually, a statement like `true` or `false` are in use
    -   in raw C these does not exist and must be replaced with 0 (false), any other value, but often 1 (true)
    -   use `stdbool.h` to use `true` and `false` or define your own "true" and "false"
-   the condition must be true to allow to run an instruction
    -   can be combined with sub conditions, which **must** be true (logic and) or at least one sub condition must be true (logic or)
    >   **NOTE**:   Don't mix logical comparisons with bit comparisons. These are quite different.
-   can be extended with `else` block to run code, when the condition has not been satisfied

```
// single condition
if (condition is true) {
    do something
}

//  logic and
if (condition A is true as well as condition B is true (as well as condition n is true)) {
    do something
}

//  logic or
if (condition A is true or condition B is true (or condition n is true)) {
    do something
}

//  -------------
int a = 0;
int b = 1;

if (a == b) {
    printf("a and b are equal\n");
} else {
    printf("a and b are unequal\n);
}
```

### switch-statement
-   compare an integer value, often used for states, to decide what to do
    -   may also be in use for a "menu" with a single character
-   can only compare one state, but multiple states can be combined
-   each state **must** be terminated with a `break;` command, otherwise the next case will automatically be used

```
int a = 100;
switch(a) {
    case 0:
        //  do something, then a is 0
        break;
    case 10:
    case 20:
    case 30:
        //  do something, when a is 10, 20 or 30
        break;
    default:
        //  default statement for any other non matched cases
        //  can also be the first "statement" or a general handling
        break;
}
```

### menu example
```
char option = ' ';
printf("enter a single option, like: 'a', 'b', 'c', 'q': ");
scanf("%c", &option);

switch(option) {
    default:
        printf("unknown command detected\n);
        break;
    case 'a':
        break;
    case 'b':
        break;
    case 'c':
        break;
    case 'q':
        break;
}
```