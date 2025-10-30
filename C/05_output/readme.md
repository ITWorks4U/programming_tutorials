#   Print out to the console
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