#   main
-   compiler languages, like C, C++, Java, C#, (Visual) Basic, ... **must** have one main to have an entry point on startup
    -   if no main exists, then the application can't be build
    -   same effect of more than one main exists

-   typical usage: `int main() {}`
    -   sometimes you can find a main as: `void main()`
        -   may throw a warning / an error on compile time
    -   main in other languages, like:
        -   Java: `public static void main(String[] args)`
        -   C#: `static void Main(string[] s)`

-   a main (C/C++) can be extended with an argument counter (**argc**) and an argument vector (**argv**) to launch an application with any kind of arguments
```
// NOTE: **argv can also be used
int main(int argc, char *argv[]) {
    for(int i = 0; i < argc; i++) {
        printf("argument %d = %s\n", i, argv[i]);
    }

    return 0;
}
```
>   **NOTE**:   The first argument is always your own application name with the absolute path.