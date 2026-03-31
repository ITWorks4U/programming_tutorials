#   C++ strings

>   **NOTE**:   regular (C++) strings comes with a different behavior rather than C-strings. Never mix Strings with C-strings.

-   store any amount of characters into your string
    -   in contrast to C-strings, the string don't need a null termination character (`\0`)
    -   you hardly need an information how many characters can be stored into that string
-   strings, not even in C++, are immutable
    -   once defined, those can't be modified, like swap a character in position n with any other character
    -   strings comes with string methods to allow to modify a string, but those methods returns a **copy** of the modifed string, whereas the original string still exists => consumes more memory

### requires
-   `string`
    -   don't mix this library with `string.h`, `strings.h` (UNIX only) or `cstring`

>   **NOTE**: On some systems a mix of strings and C-strings may cause an **application crash**, an **undefined behavior** during runtime or a **"silently" application crash** without any message on the console or your application might be interpreted as a **threat**.

### methods, like:
-   `equals`
-   `length`
-   `append`
-   `replace`
-   ...


#   C-strings
>   **NOTE**:   C-strings are quite different to regular strings and these shall **never** be mixed. Furthermore C-strings have a different way to use.
-   store n bytes (characters) into a buffer, which can be used for anything
-   a C-string **must** be terminated with a null termination character: `\0`
    -   if you omit this requirement, then this leads to an undefined behavior
-   in contrast to a regular string a C-string is not immutable and can be changed during runtime
-   can be handled as an array, because it stores n elements of type `char` (n = 0,1,2,3,...)

### requirement(s)
-   `string.h` (C only)
-   `cstring` (C++ only)
-   `strings.h` (only for UNIX systems)
    -   on Windows this header file does not exist

### functions, like:
-   `strcmp(const char *str1, const char *str2);`
    -   compare str1 and str2, if these are equal
    -   returns `0`, if these are equal
    -   returns `<0`, if str1 has a **lower** ASCII value then str2
    -   returns `>0`, if str1 has a **higher** ASCII value then str2

-   `strlen(const char *str);`
    -   returns the number of elements for str until the first null termination character has been detected
    >   **NOTE**:   Don't mix strlen() with sizeof(), because those have different meanings.

-   `strcpy(char *dest, const char *src);`
    -   copy src to to dest character by character
    >   **NOTE**:   If src contains more characters, then dest can be store, then this leads to an undefined behavior! In that case use the function `strncpy(char *dest, const char *src, size_t len);` instead to copy up to n characters from src to dest.

-   `memset(void *ptr, int val, size_t size);`
    -   because C-strings, as well as other variables, contains garbage on runtime until those are initialized, it's highly recommended to set a C-string with a default value state
        -   example:
        ```
        char data[30];
        memset(data, \0, 30);
        ```

-   `strcat(char *dest, const char *src);`
    -   concatenate strings
        -   similar to strcpy make sure to copy not more characters from src to dest
        -   use `strncat(char *dest, const char *src, size_t len);`instead