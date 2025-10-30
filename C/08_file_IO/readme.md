#   I/O operations in C

-   allows to read from a file or write any content into a file
    -   this also works for **C++**, but in C++ this should **not** be used

### open a file stream
-   use this function: `fopen(FILE *stream, const char *mode)`
    -   stream = name of the file
    -   mode = how to use this file stream, like reading, writing, bidirectional

>   **NOTE**:   The function `fopen()` returns a pointer. This can be **NULL** for any error or refers to a memory address for the I/O operation. This file pointe **must** be closed by yourself, otherwise **memory leak(s)** or any other **undefined behavior** appears!

### close a file stream
-   use this function: `fclose(FILE *stream)`
    -   stream = linked reference of a file stream to close

>   **NOTE**:   The `stream` **must** not be **NULL**, otherwise an **undefined behavior** appears!

>   **NOTE**:   Even the file stream has been successfully closed, the stream itself still refers to the used memory address. To avoid side effects, set the file stream to **NULL**.

### file modes

| mode | action | additional informations |
| - | - | - |
| "r" | read | Read a file, where this file **MUST** exist. Furthermore, you must have access rights to that file, it must not be a folder / directory, it must not be corrupted, ... |
| "w"  | write           | write content to the file; this will overwrite the previous content |
| "w+" | write and read  | opens a file in both directions; "r+" and "a+" does the same action |
| "a"  | appending       | write content to the file; does not overwrite the previous content  |
| "rb" | read byte form  | reading a file in a byte format correctly |
| "wb" | write byte form | writing a file in a byte format correctly |

>   By the way, by using w, w+, a, a+ the file will be created, if this does not already exist.

### "handling" an error
-   unlike to modern languages, like C++, Java, C#, Python, ... in C an error can be "handled" by:
    -   condition check, if the filestream is not NULL
        -   use `perror(const char *message)` function to reveal a detailed message about the failure
            -   alternative: use `fprintf(FILE *stream, const char *message, ...)` to describe an error message
    -   using signals
        -   unable to use on every system
        -   not clear, which signal on which system may be raised 