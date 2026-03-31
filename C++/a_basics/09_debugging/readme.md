#   Debugging C / C++ application
-   use the command line for debugging
    -   since IDE's can also do this much easier for you, this shall be used only, if you're forced to use the command line
-   use `gdb(.exe) (your_application_name)`

### small breakdown for debugging:
| command | effect | additional information |
| - | - | - |
| (r or run) | run your application | shall be the last command to use |
| (b or break) | tells the debugger, where the application shall be halted | this can be a function (function name), a line number in the current file, line number in a foreign file, ... |
| (s or step) | do the next step | can go into a function, which was not marked with break => in IDE (typically) F11 |
| (n or next) | do the next step | runs to the next instruction or to the next break statement => in IDE (typically) F10 |
| (p or print) | print the current value | the value must be named here |
| (q or quit) | stops the debugger | on runtime you must confirm to leave the debugger |

####    example:

-   let's say, this application is named with "recursion_error(.exe)"

```
int recursion_function(int counter) {
    if (counter < 0) {
        return counter;
    }

    cout << "counter = " << counter << endl;
    counter++;
    return recursion_function(counter);
}

int main(void) {
    cout << recursion_function(0) << endl;
    return 0;
}
```
-   run with:
    1)  `gdb(.exe) recursion_error(.exe)`
    2)  `break recursion_function`
    3)  `run`

-   in the recursion function the application is halted to enable operations
-   leave the debugger with: `q` or `quit`