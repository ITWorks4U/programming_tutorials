#   Signal handing in C

-   Handling signals allows you to react / interact, when a signal at any time on any event may appear.
-   Some signals can be handled, however, **not every signal** is able to handle. It depends on your system, the compiler, etc.
-   Depending on the OS you're working on not every signal is known.

### How to handle a signal

-   by default, when a signal has been raised, this will be handled automatically with a predefined instruction (**SIG_DFL**)
-   you can use a handler function to handle a specific amount of signals
-   you can also block (**SIG_BLK**) an incoming signal, however, this is **not** recommended, because by blocking a signal you can't no longer interact to that signal
    -   not every signal is able to handle / block, like **SIGKILL**
        -   on (very) old compilers this was able, however, this caused an undefined behavior

### Write your own signal function
-   definition: `void signal_handler(int signum);`
    -   you can use any name for your signal function
    -   you can also use different signal functions to handle different signals

### Difference between Windows and UNIX/Linux/macOS
-   on Windows, there're few signals known (see list below)
    -   by trying to use any other signal, this won't work, even you define them by yourself

### Get the detailed signal information
-   by default: use `strsignal(int signum);` (defined in `<string.h>`)
    -   on Windows this function does not exist
    -   you have to write your own instruction(s) there

### Is a signal handling equal to an exception handling?
-   Short answer: **NO! Never! Even, when the question of the answer 42 has been dropped!**
-   In C programming a signal handling are sometimes in use for an "exception handling", because C doesn't comes with any exception handling routine, however, a signal handling is not recommended for any kind of incoming exception and **shouldn't** be used.

### Difference between signal and exception

| type | may occour | is repeatable |
| - | - | - |
| signal | at any time anywhere in your application | not really |
| exception | on a specific critical block of instruction(s) | yes |

> A signal can also be raised by your hand. Use the raise() function, whereas a signal has been registered before.

### different kind of signals

| signal | ID | description | example | where available |
| - | - | - | - | - |
| SIGINT    | 2  |  interrupt signal; caused by pressing Ctrl + C                | `while(true) {...}` <= hit Ctrl + C at any time  | every system |
| SIGILL    | 4  |  illegal instruction - invalid function image                 | `[][0]` <= try to access to an empty array       | every system |
| SIGFPE    | 8  |  floating point exception                                     | division by 0                                  | every system |
| SIGSEGV   | 11 |  segmentation violation; when you try to access to a memory sector, which shouldn't be accessed   | `char word[20]` and transfer at least 20 chars; without \0 to word, then this signal may raise   | every system |
| SIGTERM   | 15 |  normal termination of your process                           | **Windows:** `taskkill /p [pid] [app.exe] /F` **Linux:** `kill <process-id>` (without -9)        | every system |
| SIGBREAK  | 21 |  Ctrl-Break-sequence; similar to SIGINT    | `while(true) {...}` <= hit `Ctrl + Pause/Break`    | Windows only |
| SIGABRT   | 22 |  abnormal termination of your process; this is not the next level of SIGTERM   | assert(condition) results to false, call abort() function, ...           | every system |
| SIGHUP    | 1  |  signal hang up; when a terminal line was disconnected        | a process is running in a **SSH session** and the session has suddenly been closed  | UNIX/Linux/macOS |
| SIGQUIT   | 3  | quit signal; similar to SIGINT, but causes core dump          | hit `Ctrl + \` on runtime                        | UNIX/Linux/macOS |
| SIGTRAP   | 5  | trace / breakpoint trap                                       | - on gdb when b(break) is defined and on debug the certain breakpoint has been reached; `raise(SIGTRAP)` => terminates the application and generate a core dump (useful for gdb)| UNIX/Linux/macOS |
| SIGBUS    | 7  | bus error (e. g. misaligned memory access); invalid memory access, but not idendical to SIGSEGV;                  | - when a program tries to access to a memory in a way that violates hardware constraints, such as unaligned access or non existent physical address mapping, e. g.: memory-mapped files | UNIX/Linux/macOS |
| SIGKILL   | 9  | killing process; a SIGKILL **can't** be handled on any system and terminates your application by using a brute-force-quit without relasing memory, closing streams, flush data, ...   | `kill -9 [process-id]`                           | UNIX/Linux/macOS |
| SIGUSR1   | 10 | user defined signals - reserved for application defined purposes; those does not have a predefined meaning, which means: we can choose to do, whatever we want to do If SIGUSR1 / SIGUSR2 has been registered, but not handled, then the application terminates instead. | define that signal to handle and use any non critical signal instead, like: `while(true) {...}` and in another terminal hit: `kill -SIGUSR1 [pid]` | UNIX/Linux/macOS |
| SIGUSR2   | 12 | like SIGUSR1                                                  |                                                | UNIX/Linux/macOS |
| SIGALRM   | 14 | alarm signal; when a timer set with `alarm()` expires, this signal will be triggered     | `alarm(10);` => 10 seconds later the signal SIGALRM will be triggered | UNIX/Linux/macOS |
| SIGSTKFLT | 16 | stack fault; less common and architecture-specific signal that indicates a stack fault on some Linux systems, especially on x86 architectures     | using a recursion function without an exit condition or that exit condition never reaches     | UNIX/Linux/macOS |
| SIGCHLD   | 17 / 20 | child process terminated or stopped (Linux: **17**, macOS: **20**) | when a child process terminates earlier than the parent process   | UNIX/Linux/macOS |
| SIGCONT   | 18 / 19 | continue a stopped process (Linux: **18**, macOS: **19**)                                    | run `fg`                                         | UNIX/Linux/macOS |
| SIGTSTP   | 20 / 18 | terminal stop signal (sent by pressing `Ctrl + Z`) (Linux: **20**, macOS: **18**)              | `while(true) {sleep(x);} ` by pressing Ctrl + Z SIGTSTP will be triggerd by pressing fg afterwards, **SIGCONT** will be triggered                       | UNIX/Linux/macOS |

####    Appendix:
> There might be another signals, which may be a redefinition of one of the previous signals or these does not exist everywhere.