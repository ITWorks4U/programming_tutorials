# Reading from the keybord

-   C++ offers different ways to read anything from the keyboard
    -   you can also use C-functions, but those have nasty side effects

>   **NOTE**: Every input is a **word**, even a number has been typed in.


####    different ways for read from keyboard
>   **NOTE**:   Even in C++ not every way is flawless, but more stable than in C.

| used way | description | side effects | in use |
| - | - | - | - |
| `cin` | "console in" (reads something from the keyboard) | Reads until the first space or enter has been detected. Remaining input will be stored into an internal buffer the next input and will automatically be used. | yes, but with care |
| `getline(cin, str)` | read the full line | Unlike to raw cin multiple words can also be read until a newline has been detected. Can also be used to read line by line from a file. "str" must be a string, where the input is going to store. | yes |

####    alternatives to C
>   **NOTE**:   Almost every function, which reads from the keyboard or from a file stream has not a clear limitation for the input buffer. Use your mind to figure out, when a buffer has reached its limit!

>   **NOTE**: Furthermore every function may also store any left character from keyboard or file stream into an internal buffer and this leads to an **undefined behavior!**

| function | description | side effects | in use |
| - | - | - | - |
| `gets(void)` | read everything from the keyboard | does not care about buffer limitation and leads to a critical state | definitely: **no** |
| `scanf(const char *format, ...)` | read from keyboard until the first space or enter character has been detected | you must use a valid format for the input, otherwise this function leads to an undefinded behavior | not really |
| `fscanf(const FILE *stream, const char *format, ...)` | read from an input stream, like keyboard (**stdin**), but can also read from a file | same side effect to `scanf()` function | hardly |
| `getc(FILE * stream)` | read a single character only | it returns the integer position from the **ASCII** table, e. g.: "0" => 48 , "A" => 65, ... |  maybe |
| `fgetc(FILE *stream)` | better handling in contrast to `getc()` | same side effect to `getc()` function | maybe |
| `getchar(void)` | read the next character from the keyboard only | same side effect to `getc()` function | yes |
| `getch(void)` | identical to `getchar()` function | only in use on Windows and turbo C | hardly |
| `fgets(char *buffer, size_t length, FILE* stream)` | read any input including whitespace(s) from input stream, like keyboard (**stdin**) and store it to **buffer** | The newline character (`'\n'`) is also appended to your buffer and shall be handled. Furthermore only the amount of characters (length) are going to read. | yes |
| `atoi(const char *string)` | "argument to integer" => convert the given argument to an integer value | Any "invalid" input may return "0" or any undefined behavior appears. Same side effect with `atol()`, `atof()`, ... | definitely: **no** |
| `strtol(const char *string, char **endptr, int base)` | convert an argument to a long value | Read and convert every valid value into an integer until the first invalid character or end of string has been detected. Every other valid value after an invalid value won't be handled and can be redirected to endptr, if given. If endptr is set to `NULL`, then the remaining input will be deleted. The `base` tells how the number shall be converted: 0 or 10: decimal value, 2: binary value, 8: octal value, 16: hexadecimal value, but the result is always an integer value! | yes |

>   **NOTE**: Some functions, like `sscanf(const char *buffer, const char *format, ...)`, ... are not shown here.

### clear the input buffer (C++ only)
>   **NOTE**: In contrast to C programming it's not recommended to use the C-variant.

```
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    // input way before

    // clear input stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}
```

### clear the input buffer (C only)
-   it's high recommended to clear the input buffer for a next scan, otherwise any remaining character from the previous input will automatically be used

>   **NOTE**: This works only for C. In C++ this leads to an **undefined behavior**. Furthermore C++ uses an another way to clean up the remaining buffer mess.

-   typical way to clean up the remaining buffer:
```
int c;
while ((c = getchar()) != '\n' && c != EOF);
```

>   **NOTE**: Don't use the function `fflush(FILE *stream)` like: ```fflush(stdin)```. This won't clear the input buffer. It flushes the output stream only, like `stdout`, `stderr` or a file stream buffer.