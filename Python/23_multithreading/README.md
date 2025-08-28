#   Using threads

-   allows to run procedures for each single core
-   when a new thread has been created:
    -   shares memory, variables, data structures, ...
    -   can be run in the background, no matter, what the main thread is doing
    -   thread is low level programming
        -   to use high level parallelism, use sub processes instead
        -   when a thread crashes, it may also crash the main application
        -   two or more threads may cause a deadlock
            -   means: a resource from thread A is not going to release for thread B, whereas thread B is not releasing a resource for thread A, ...

### difference between sub process and thread

| type | creation | module to use | characteristic mark(s) | communcation by | pitfall(s) |
| - | - | - | - | - | - |
| sub process | `fork()`, `Process()`| `os`, `multiprocessing` | separate memory spaces, safer to use, ... | pipes, queues, sockets, ... | high startup cost; a sub process and the main process may ends differently => causes ophran / zombie processes; ...
| thread | `Thread()` | `threading` | shared memory, file descriptors, ... | shared variables / data structures | missing to join that thread, unless this is a background thread (=daemon), causing deadlock, if you don't mind; ...


### How to create a thread

-   use:
```
from threading import Thread

# basic function with None as return only
t = Thread(target=<function for thread>)
t.start()
```

-   thread with arguments
    1.  using args, where the usage is a bit strange
    2.  using kwargs

-   with args:
```
from threading import Thread

# basic function with None as return only
# args must be given with a comma, otherwise an error appears on runtime
t = Thread(target=<function for thread>, args=(x,))
t.start()
```

-   with kwargs:
```
from threading import Thread

# basic function with None as return only
# kwargs is a dictionary with a key-value-pair, where:
# key = first argument of the function (must be identical to the argument name)
# value = the value for that argument
t = Thread(target=<function for thread>, kwargs={<key> : <value>})
t.start()
```

### terminate a thread
-   works for threads, which are not detached
    -   threads, who runs in the background (=detachted from main thread) are called: *daemon*

```
# without an argument the main thread waits until the thread has been
# finished; by using a number as argument, the main thread waits only
# n seconds for that thread => may cause an undefined behavior during runtime
t.join()
```

### using a semaphore
-   since threads are powerful, however, by using critical areas, like:
    -   file I/O access
    -   port I/O access
    -   ...
    -   only one thread shall be able to use that resource by its own, whereas the other threads have to wait
-   using semaphore:
```
from threading import Thread, Semaphore

# critical area
# sem: used semaphore => can also be used as a global object
# thread_id: more in use, to see which current thread is now working...
def critical_area(sem: Semaphore, thread_id: int) -> None:
	with sem:
        # any code to work with


# somewhere in the main
s: Semaphore = Semaphore(value=1)

for ctr in range(10):
	worker = Thread(target=critical_area, kwargs={"sem" : s, "thread_id" : ctr})
	worker.start()
```