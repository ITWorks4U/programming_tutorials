#   Debugging Python code
-   debugging code is the most spent time of programming
-   it helps you to understand, find and fix the tiniest logical error, which causes the huge problem
-   by using any IDE, a debugger is implemented automatically
    -   just set a breakpoint, run your code with F5 and you're early or later on your breakpoint
-   Python also comes with a debugger module, which can easy be used, too
    -   similar to `gdb`for C/C++


### How to debug
-   using `pdb` module
-   many ways to realize a console debugging

| function | effect | side effect |
| - | - | - |
| `set_trace()` | run the full script in debugger mode | Raises `BdbQuit`, when the debugger is still running and `'q'` has been pressed. |
| `run()` | run a certain statement, like a function | The function statement **must** be a string. Only the given function statement will be traced. When the function ends, the normal application run is going to do. |
| `runcall(<function_name>)` | Runs the certain function in the debugger only. | When `'q'` has been pressed, the debugger terminates without an error. Doesn't mean, that the application itself won't terminate without an error, if an error still exist. |

### debug commands

| command | effect |
| - | - |
| b | set a breakpoint, like: `b <line_number>` or `b <function_name>` |
| n | next single step, like `F10` in some IDE's |
| next | same as above |
| s | step into, like `F11` in some IDE's |
| step | same as above
| c | continue with the workflow, like `F5` in some IDE's |
| p | print the current value, e. g.: p data |
| print | same as above |
| r | run the debugger |
| q | stops the debugger |
| quit | same as above |