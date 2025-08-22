    #	Lambda expressions C++

-   offers to use an anonymous function for a quick implementation without define a function itself
-   often used by mathematicians
-   in contrast to C programming, which doesn't comes with lambda expressions, but those can be simulated with macro expressions, in C++ the usage of lambda expressions are quite easy

### basic syntax for a lambda expression

`<type> <name> = [<capture clause>](<parameter list>) <mutable> [<noexcept> | <throw>] -> <type> {<code>}`
- attention: not every optional expression can be used everywhere or results to the same behavior

| required | what does that mean |
| - | - |
| `<type>` | often used with "auto", because lambda expressions might not have a known data type |
| `<name>` | the lambda expression to work with |
| `<code>` | the body of the lambda expression |

| optional | what does that mean |
| - | - |
| `<capture clause>` | using a (global) variable to work with this lambda expression; `&<variable>` := captured by reference; `=<variable>` := captured by value (default) |
| `<parameter list>` | variables / objects, which are in use only in the lambda body |
| `<mutable>` | Typically, a lambda's function call operator is const-by-value, but use of the mutable keyword cancels this out. It doesn't produce mutable data members. The mutable specification enables the body of a lambda expression to modify variables that are captured by value. |
| `<noexcept>` | promises, that this lambda expression shall not throw an exception; if an exception is going to throw here, then you lied to the compiler and the application terminates immediately |
| `<throw>` | old C++ 98 dynamic exception specification, which is **deprecated** in C++11 and newer; identical to `<noexcept>` |
| `-> <type>` | if trailing return type if set, then "auto" keyword is hardly in use, because you now know which type is required |

### examples

-   an empty lambda, which does and returns nothing; can't handle with variables
    -   *"func" is a replacement for any lambda function name*
```
    auto func = [](){};
```

-   lambda expression with an argument
```
    int argument = 5;
    auto func = [argument](){
        return argument * argument;
    };
```

-   lambda expression with multiple arguments and an expected return type
```
    auto func = [](float a, float b) -> float {
        return a * b;
    };
```

-   "promise", that this lambda expression won't throw an exception
    -   *attention: if you lied and any exception has been triggered here, then the application termiantes immediately*
    -   *any possible exception **must** be handled inside of the lambda expression*

```
    auto func = []() noexcept {
        return true;
    };
```

-   "promise", that this lambda expression will also **not** throw an exception
    -   *any possible exception **must** be handled inside of the lambda expression*
    -   *throw() is an old expression for noexcept and does have the same meaning*
    -   *if you lied (again), then the termiantes immediately*

```
    auto func = []() throw() {
        try {
            logic_error e("logic_error is going to throw here");
            throw e;
        } catch (logic_error &e) {
            cerr << e.what() << endl;
        }
    };
```

### terminates the application immediately

-   if you lied and the lambda expression throws an exception
```
    auto func = []() noexcept {
        throw runtime_error("Pinoccio would be jealous...");
    };

```

-   throw the exception again...
    -   **NOTE**: throw() is an old C++ implementation (C++98) and this is identical to *noexept*

```
    auto func = []() throw() {
        try {
            throw logic_error("logic_error is going to throw here");
        } catch (logic_error &e) {
            cerr << e.what() << endl;

            //  This will never be able to handle in
            //  another exception handling block.
            throw;
        }
    };
```

-   just throw an exception, which is **not** expected, because you gave a promise to: *"No, an exception is not going to throw here."*
    -   even in an own exception block this can't be handled, because the application terminates immediately

```
    auto func = []() throw() {
        logic_error e("logic_error is going to throw here");
        throw e;
    };
```