#   Reading from console
-   "just" use `input()` function

####    formatting input
-   can be used to inform the user, that an input is required here:
```
    input("Enter something here:")

```
-   *attention:*:
    -   the input function comes with an additional argument, named `promt`, but you're not allowed to use: `promt="any text"`
    -   the python interpreter might handle this like an error on runtime


######	attention
-   __EVERYTING__ will be "a word" when it's read from the keyboard or from a file
-   to format your given sub word into a correct type make sure, that this is possible
    -   throws an error on runtime, if an incorrect type is in use
    -   for numeric conversation: use *regular expressions* or an *exception block* instead