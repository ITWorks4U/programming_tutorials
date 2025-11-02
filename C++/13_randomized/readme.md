#   Have fun with random
-   use a (pseudo) random generated number on runtime
-   examples:
    -   "random" number on runtime
    -   lottery
    -   password generator
    -   ...

>   **IMPORTANT**:  *Don't use C functions, like `srand()` or else, otherwise the application might the handled like a **threat**.*

####    required implementations
-   libraries:
    -   `random`
    -   `ctime`
    -   `chrono`
-   data types / class instances:
    -   `random_device`
    -   `mt19937`