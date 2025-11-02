#   Print out to the console
-   C++ comes with two basic ways:
    -   cout
    -   cerr

| mode | meaning | additional informations |
| - | - | - |
| cout | default console output channel (stdout) | defaults to channel 1 |
| cerr | default console error output channel (stderr) | defaults to channel 2 |

### formatting output
-   required library: `iomanip`

| option | description | additional informations |
| - | - | - |
| `setw(x)` | set the with of free spaces before a messag is printed | x shall be a positive integer |
| `left` | print a text on the left side | works much better in combination with `setw(x)` |
| `right` | print a text on the right side (default way) | see above | 
| `internal` | a mix of left and right | when a signed number is in use, then the sign is on the left only |
| `setfill('*')` | fill free spaces with `'*'` | any other single character can also be used here |
| `fixed` | fix the number of floating points | in combination with `setprecision(x)` |
| `scientific` | format a floating point number into an exponential way | in combination with `setprecision(x)` |
|  `showpos` | show a positive sign for a number, which is not usually shown | - |
| `noshowpos` | disallow to show a positive sign for a number | does not affect negative numbers |
| `dec` | format an integer into a decimal number (default) | - |
| `hex` | format an integer into a hexadecimal number | can be combined with `showbase` to start with `0x` |
| `oct` | format an integer into an octal number | in combination with `showbase` it starts with `0` |

####    reset the output from the default state
-   `resetiosflags(ios::showbase | ios::hex | ios::showpos)`

### alternative ways with C
-   usually, `printf()` function works fine, but there's more

| function | effect | additional informations |
| - | - | - |
| `printf(const char *formatter, ...);` | print a formatted text to the console (stdout) | A newline character `\n` is required to "terminate" this output. A warning appears, if this function takes an empty C-string. Furthermore, the formatted placeholder **must** be set with the correct data types, otherwise an undefined behavior appears or the application is unable to build. |
| `puts(const char *str);` | same as printf | No need to add a newline character and the C-string can also be empty. This function does not comes with any formatting option. |
| `fprintf(const FILE *stream, const char *formatter, ...);` | similar to printf, puts, but a custom redirection channel or a file stream can be used | similar to printf |
| `perror(const char *str);` | print str as an "error message" followed by a reason for the certain error (internal handled) | No need to use a formatted text. A reason code, like "no such file or directory" or else can be determined internal. If no error has been detected, "SUCCESS" returns. |
| `fputs(const char *str, FILE *stream);` | similar to puts, where the direction can be set | - |
| `putc(int character, FILE *stream);` | put a single character to the stream's output | The character is handled as an integer, because it refers to the **ASCII** table position, e. g.: "A" <=> 65, "0" <=> 48, ... |
| `fputc(int character, FILE *stream);` | similar to putc | Has more secure handling for buffer storage. |
| `putchar(int character);` | similar to putc | Prints a single character to stdout by default. |