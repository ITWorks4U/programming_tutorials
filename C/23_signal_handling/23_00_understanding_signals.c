/*
* Handling signals allows you to react / interact, when
* a signal at any time on any event may appear. Some signals can
* be handled, however, not every signal is able to
* handle. It depends on your system, the compiler, etc.
*
* Depending on the OS you're working on not every signal is known.
*
* You also may block an incoming signal, whereas not every
* signal is able to block. It also depends on your system,
* compiler, etc.
*
* A signal handling can also be used for "exception handling", however,
* NEVER assume, that a signal handling is equal to an exception handling!
*
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | signal    | ID |                        description                            |                   example                      |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGINT    | 2  |  interrupt signal; caused by pressing Ctrl + C                | while(true) {...} <= hit Ctrl + C at any time  |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGILL    | 4  |  illegal instruction - invalid function image                 | [][0] <= try to access to an empty array       |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGFPE    | 8  |  floating point exception                                     | division by 0                                  |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGSEGV   | 11 |  segmentation violation; when you try to access to a memory   | char word[20] and transfer at least 20 chars   |
* |           |    |  sector, which shouldn't be accessed                          | without \0 to word, then this signal may raise |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGTERM   | 15 |  normal termination of your process                           | Windows: taskkill <app.exe> (without /F)       |
* |           |    |                                                               | Linux: kill <process-id> (without -9)          |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGBREAK  | 21 |  Ctrl-Break-sequence (only for Windows); similar to SIGINT    | while(true) {...} <= hit Ctrl + Pause/Break    |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGABRT   | 22 |  abnormal termination of your process; this is not the next   | assert(condition) results to false,            |
* |           |    |  level of SIGTERM                                             | call abort() function, ...                     |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* |           |    |             not available / known on Windows:                 |                                                |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGHUP    | 1  |  signal hang up; when a terminal line was disconnected        | a process is running in a SSH session and the  |
* |           |    |                                                               | session has suddenly been closed               |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGQUIT   | 3  | quit signal; similar to SIGINT, but causes core dump          | hit Ctrl + \ on runtime                        |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGTRAP   | 5  | trace / breakpoint trap                                       | - on gdb when b(break) is defined and on debug |
* |           |    |                                                               |   the certain breakpoint has been reached      |
* |           |    |                                                               | - raise(SIGTRAP) => terminates the application |
* |           |    |                                                               |   and generate a core dump (useful for gdb)    |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGBUS    | 7  | bus error (e. g. misaligned memory access);                   | - when a program tries to access to a memory   |
* |           |    | invalid memory access, but not idendical to SIGSEGV;          |   in a way that violates hardware constraints, |
* |           |    |                                                               |   such as unaligned access or non existent     |
* |           |    |                                                               |   physical address mapping, e. g.:             |
* |           |    |                                                               |   memory-mapped files                          |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGKILL   | 9  | killing process; a SIGKILL can't be handled on any system     | kill -9 <process-id>                           |
* |           |    | and terminates your application by using a brute-force-quit   |                                                |
* |           |    | without relasing memory, closing streams, flush data, ...     |                                                |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGUSR1   | 10 | user defined signals - reserved for application defined       | define that signal to handle and use any non   |
* |           |    | purposes; those does not have a predefined meaning, which     | critical signal instead, like:                 |
* |           |    | means: we can choose to do, whatever we want to do            | while(true) {...} and in another terminal hit: |
* |           |    |                                                               | kill -SIGUSR1 <pid>                            |
* |           |    | If SIGUSR1 / SIGUSR2 has been registered, but not handled,    |                                                |
* |           |    | then the application terminates instead.                      |                                                |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGUSR2   | 12 | like SIGUSR1                                                  |                                                |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGALRM   | 14 | alarm signal; when a timer set with alarm() expires, this     | alarm(10); => 10 seconds later the signal      |
* |           |    | signal will be triggered                                      | SIGALRM will be triggered                      |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGSTKFLT | 16 | stack fault; less common and architecture-specific signal     | using a recursion function without an exit     |
* |           |    | that indicates a stack fault on some Linux systems,           | condition or that exit condition never reaches |
* |           |    | especially on x86 architectures                               |                                                |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGCHLD   | 17 | child process terminated or stopped                           | when a child process terminates earlier than   |
* |           | 20 | Linux: 17, macOS: 20                                          | the parent process                             |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGCONT   | 18 | continue a stopped process                                    | run fg                                         |
* |           | 19 | Linux: 18, macOS: 19                                          |                                                |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
* | SIGTSTP   | 20 | terminal stop signal (sent by pressing Ctrl + Z)              | while(true) {sleep(x);}                        |
* |           | 18 | Linux: 20, macOS: 18                                          | by pressing Ctrl + Z SIGTSTP will be triggerd  |
* |           |    |                                                               | by pressing fg afterwards, SIGCONT will be     |
* |           |    |                                                               | triggered                                      |
* |-----------|----|---------------------------------------------------------------|------------------------------------------------|
*
* There might be another signals, which may be a redefinition of one of the previous signals or these does not
* exist everywhere.
*/

int main(void) {
	//	no example here...
	return 0;
}