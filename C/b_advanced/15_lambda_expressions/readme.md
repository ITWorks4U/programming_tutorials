#   Lambda expressions (C only)
-   usually you can't use any lambda expressions in C
    -   unless you define your own lambda function body by **macros**
    -   take care for unpredictable side effects

>   **NOTE**:   Since macros are still typeless, this leads to an undefined behavior by using a mixed set of data types.

### lambda definition
```
#define LAMBDA(lambda$_ret, lambda$_args, lambda$_body) ({\
	lambda$_ret lambda$__anon$ lambda$_args lambda$_body &lambda$__anon$;\
})
```
-   where:
    -   lambda$_ret => return type
    -   lambda$_args => arguments to work with
    -   lambda$_body => what that lambda function shall do