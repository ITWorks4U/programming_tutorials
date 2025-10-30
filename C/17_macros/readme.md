#   macros in C / C++

### purpose
-   allows to define real (un)stable constants
-   using macro functions with side effects
-   using preprocessor instructions, like on which operating system (OS) an application is running

### known pitfalls
-   Macros are typeless. So you can also lead into an undefined behavior or a logical error in your application.
-   if a macro may exist anywhere, then may lead into an error on compile time or an undefined behavior
-   using an uncommonly or already known name, like BUF, BIFSIZ, ...