#   Debugging Python code
-   debugging code is the most spent time of programming
-   it helps you to understand, find and fix the tiniest logical error, which causes the huge problem
-   by using any IDE, a debugger is implemented automatically
    -   just set a breakpoint, run your code with F5 and you're early or later on your breakpoint
-   Python also comes with a debugger module, which can easy be used, too
    -   similar to `gdb`for C/C++


### How to debug
-   using pdb module
-   two ways to realize:
    -   `pdb.set_trace()`
        -   run the full script in debugger mode
        -   raises BdbQuit, when the debugger is still running and 'q' has been pressed
    -   `pdb.runcall(<function_name>)`
        -   runs the certain function in the debugger only
        -   when 'q' has been pressed, the debugger terminates without an error

### debug commands

| command | effect |
| - | - |
| n | next single step, like `F10` in some IDE's |
| next | same as above |
| s | step into, like `F11` in some IDE's |
| step | same as above
| c | continue with the workflow, like `F5` in some IDE's |
| p | print the current value, e. g.: p data |
| print | same as above |
| q | stops the debugger |
| quit | same as above |