#	How to handle signals

-   signals are hardly handled in C++
-   a signal may appear at any time anywhere in your application
    -   this might have a similar behavior like exception handling, however, a signal is **never** an exception or vice versa

-   a signal may be:
    -   interrupt (Ctrl + C)
    -   termination (terminating the process)
    -   segmentation fault
    -   ...

-   this section, however, doesn't shows you an example, because it's identical to C programming
    -   take a look to: [signal handling in C](https://github.com/ITWorks4U/programming_tutorials/tree/main/C/23_signal_handling)