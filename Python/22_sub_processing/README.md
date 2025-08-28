#   Using sub processes
-   can emulate parallel operations
    -   similar to threads
-   when a new process has successfully been created:
    -   gets a new process-ID
    -   uses the same program counter, CPU registers, open files, ...

### difference between sub process and thread

| type | creation | module to use | characteristic mark(s) | communcation by | pitfall(s) |
| - | - | - | - | - | - |
| sub process | `fork()`, `Process()`| `os`, `multiprocessing` | separate memory spaces, safer to use, ... | pipes, queues, sockets, ... | high startup cost; a sub process and the main process may ends differently => causes ophran / zombie processes; ...
| thread | `Thread()` | `threading` | shared memory, file descriptors, ... | shared variables / data structures | missing to join that thread, unless this is a background thread (=daemon), causing deadlock, if you don't mind; ...

>   **NOTE:** On Windows `fork()` does not exist, because it's a **UNIX-only system call**.
>>  On Windows use `Process()`   instead.

### How to create a child process
-   use the fork() function to do this

### What kind of processes exists?
1.  orphan process
    -   the parent process terminates earlier than its child
2.  zombie process
    -   the child process terminates earlier than its parent

### Waiting for a child
use:
```
import os

# code behind...

# forces to wait to terminate the parent process
# until the child process has been terminated
os.wait()
```

### Where are these required?
-   to learn about how to use them
-   sometimes to control a specific piece of your code, e. g. a process shall read a file only, whereas an another process shall write to a file only
    -   has much more undefined behaviors than you expect at the moment