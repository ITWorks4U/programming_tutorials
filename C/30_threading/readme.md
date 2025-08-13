#   Using threads
-   Similar to sub processes threads allows you to work with many parallel tasks, because each CPU core can do a single action to speed up your application however, using threads are tricky and may also cause an undefined behavior or, worse, a deadlock.
-   On Windows you can't use **POSIX** threads by default. In that case you have to do an alternative way.
-   *Those thread functions are written in C and shall also be used for C only. C++ may also work with them, however, C++ comes with an own library to use threads and this may also cause an undefined behavior!*

### compiler flag to use

| OS | flag |
| - | - |
| Windows | -lws2_32 |
| Linux | -pthread |
| macOS | -pthread |

examples:
- Windows: ```gcc.exe -g3 -Wall [source_file(s)] -o [output_file.exe] -lws2_32```
- Linux: ```gcc -g3 -Wall [source_file(s)] -o [output] -pthread```

### When NOT to use threads?
-   by using any crititcal resource, like:
    -   file I/O
    -   any communication interface, like UART/I²C/SPI
    -   database connection
    -   ...
> Those examples may cause a SOFT-lock and your application gets stuck.

### What is a deadlock?
-   caused by two or more threads, which needs a resource from an another thread, whereas this thread also waits for a resource from an another thread
-   similar to **soft**locks your application gets stuck and you have to termiate the application on the hard way