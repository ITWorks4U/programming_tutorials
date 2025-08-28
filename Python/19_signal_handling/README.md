#   Oops, I did it (again)!

-   Looks similar to an exception, right?
    -   well, an exception and an interrupt might have a similar behavior:
        -   it pauses / stops the current instruction to "handle" a special case, but these are __NOT__ the same

### Difference between an exception
| kind of error | when to appear | can be repeated
| - | - | - |
| exception | on a specific piece of code, e.g.: reading a file, which does not exist | yes |
| signal | anywhere at any time | not always |

### ways to react to a signal
-   use the default built-in behavior
-   ignore that signal (not recommended for each signal)
-   handle an incoming signal with an own function

### How to handle a signal

-   similar to an exception, you can try to use an exception handling, but you often don't see a positive result
-   unlike to an exception handling, you must define a handler function for all registered signals, which *may* appear

-   required steps:
    1.  import `signal` module
    2.  define a signal handler function
    3.  register your possible signal

-   example:
```
import signal

def signal_handler(signal, frame):
    #...

signal.signal(signal.SIGINT, signal_handler)
```

-   more clean version:
```
from sys import exit
from signal import signal, SIGINT, Signals

def signal_handler(signal, frame):
    print(f"got that signal: {signal}, identified as: {Signals(signal)}, located on: {frame}")

    # usually, when a signal has been detected,
    # the application shall be terminated to avoid
    # undefined behavior during runtime
    exit(0)

signal(SIGINT, signal_handler)
```

### different kind of signals

>   not every signal may be available on each OS

-   to figure out, which signals may exist on your OS, use:
```
import signal

for name in dir(signal):
    if name.startswith("SIG") and not name.startswith("SIG_"):
        print(name, getattr(signal, name))
```

### table of signals

| Signal           | Description                               | Typical Use                      |
| ---------------- | ----------------------------------------- | -------------------------------- |
| `signal.SIGINT`  | Interrupt from keyboard (Ctrl+C)          | Graceful shutdown                |
| `signal.SIGTERM` | Termination signal                        | Clean exit                       |
| `signal.SIGHUP`  | Hangup detected on controlling terminal   | Reload config or restart daemon  |
| `signal.SIGKILL` | Kill signal (cannot be caught or ignored) | Force kill a process (OS-level)  |
| `signal.SIGSTOP` | Stop the process (cannot be caught)       | Pausing execution (OS-level)     |
| `signal.SIGCONT` | Continue if stopped                       | Resume after stop                |
| `signal.SIGALRM` | Timer signal                              | Used with `alarm()`              |
| `signal.SIGCHLD` | Child stopped or terminated               | Reaping zombie processes         |
| `signal.SIGUSR1` | User-defined signal 1                     | Custom use                       |
| `signal.SIGUSR2` | User-defined signal 2                     | Custom use                       |
| `signal.SIGPIPE` | Broken pipe                               | Prevents crashing on pipe breaks |